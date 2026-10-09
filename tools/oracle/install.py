#!/usr/bin/env python3
"""Install the reproducible research hooks in the local, ignored Flycast fork."""
from pathlib import Path
import shutil

ROOT = Path(__file__).resolve().parents[2]
CORE = ROOT / "tools/emu/flycast/core"

def insert(path, anchor, replacement):
    p = CORE / path
    text = p.read_text(encoding="utf-8")
    if replacement in text:
        return
    if text.count(anchor) != 1:
        raise SystemExit(f"Expected one anchor in {p}: {anchor!r}")
    p.write_text(text.replace(anchor, replacement), encoding="utf-8")


def normalize_observer():
    """One pre-dispatch hook even when upgrading an already patched fork."""
    import re
    p = CORE / 'hw/sh4/interpr/sh4_interpreter.cpp'
    original = p.read_text(encoding='utf-8')
    text = re.sub(r'^\t(?:vf3OracleBefore\(addr, op, ctx\);|'
                  r'if \(vf3AudioBefore\(addr,op,ctx\)\) throw debugger::Stop\(\);|'
                  r'if \(vf3OracleOneShotDone\(\)\) throw debugger::Stop\(\);)\n',
                  '', original, flags=re.M)
    anchor = '\tvf3TraceInstr(addr, op);'
    if text.count(anchor) != 1:
        raise SystemExit('Expected one interpreter trace dispatch')
    text = text.replace(anchor,
        '\tif (vf3AudioBefore(addr,op,ctx)) throw debugger::Stop();\n'
        '\tvf3OracleBefore(addr, op, ctx);\n'
        '\tif (vf3OracleOneShotDone()) throw debugger::Stop();\n' + anchor)
    if text != original:
        p.write_text(text, encoding='utf-8')

def main():
    for name in ("vf3oracle.cpp", "vf3oracle.h", "vf3audio.cpp", "vf3audio.h",
                 "vf3audiobridge.cpp", "vf3audiobridge.h"):
        source, dest = Path(__file__).parent / name, CORE / name
        if not dest.exists() or source.read_bytes() != dest.read_bytes():
            shutil.copyfile(source, dest)
    insert(Path('windows/winmain.cpp'), '#include "build.h"',
           '#include "build.h"\n#include "vf3oracle.h"')
    runner = CORE / 'windows/winmain.cpp'
    if 'vf3OraclePrepare();' not in runner.read_text(encoding='utf-8'):
        insert(Path('windows/winmain.cpp'), '\t\t\t\tdc_loadstate(0);',
               '\t\t\t\tdc_loadstate(0);\n'
               '\t\t\t\t/* Fixture parsing must finish before the frame budget starts. */\n'
               '\t\t\t\tvf3OraclePrepare();')
    if '[vf3] guest stopped; closing capture' not in runner.read_text(encoding='utf-8'):
        insert(Path('windows/winmain.cpp'),
           '\t\tfprintf(stderr, "[vf3] ran %lld frames\\n", f);',
           '\t\tfprintf(stderr, "[vf3] ran %lld frames\\n", f);\n'
           '\t\t/* Stop and join guest execution before closing research captures.\n'
           '\t\t * GUI/input teardown can deadlock in unattended headless runs. */\n'
           '\t\tif (getenv("VF3_CAPSULE") || getenv("VF3_HITS")) {\n'
           '\t\t\temu.stop();\n'
           '\t\t\tfprintf(stderr, "[vf3] guest stopped; closing capture\\n");\n'
           '\t\t\tstd::exit(0);\n'
               '\t\t}')
    insert(Path("hw/sh4/CMakeLists.txt"), "target_sources(${PROJECT_NAME} PRIVATE",
           "target_sources(${PROJECT_NAME} PRIVATE\n        ../../vf3oracle.cpp")
    insert(Path('hw/sh4/CMakeLists.txt'), '../../vf3oracle.cpp',
           '../../vf3oracle.cpp\n        ../../vf3audio.cpp')
    insert(Path('hw/sh4/CMakeLists.txt'), '../../vf3audio.cpp',
           '../../vf3audio.cpp\n        ../../vf3audiobridge.cpp')
    p = CORE/'hw/sh4/CMakeLists.txt'
    marker = '# VF3 live-device C queue backend'
    source = (ROOT/'src/fight/command_encoders.c').as_posix()
    channels = (ROOT/'src/fight/audio_channels.c').as_posix()
    block = (f'{marker}\ntarget_sources(${{PROJECT_NAME}} PRIVATE "{source}")\n'
             f'set_source_files_properties("{source}" TARGET_DIRECTORY ${{PROJECT_NAME}} PROPERTIES COMPILE_DEFINITIONS VF3_AUDIO_BRIDGE=1)\n'
             f'target_sources(${{PROJECT_NAME}} PRIVATE "{channels}")\n'
             f'set_source_files_properties("{channels}" TARGET_DIRECTORY ${{PROJECT_NAME}} PROPERTIES COMPILE_DEFINITIONS VF3_AUDIO_BRIDGE=1)\n'
             f'target_include_directories(${{PROJECT_NAME}} PRIVATE "{(ROOT/"src").as_posix()}")\n')
    text = p.read_text(encoding='utf-8')
    if marker in text:
        prefix, previous = text.split(marker, 1)
        if any(line and not line.startswith(('target_sources(', 'set_source_files_properties(',
                                              'target_include_directories('))
               for line in previous.splitlines()):
            raise SystemExit('Unexpected text after research backend CMake block')
        fixed = prefix+block
    else:
        fixed = text+'\n'+block
    if fixed != text:
        p.write_text(fixed, encoding='utf-8')
    insert(Path('hw/sh4/sh4_interpreter.h'), '\tvoid ExecuteDelayslot();',
           '\t/* Research backend charges metadata, never executes guest opcodes. */\n'
           '\tvoid OracleChargeCycles(u16 op) { sh4cycles.executeCycles(op); }\n'
           '\tvoid ExecuteDelayslot();')
    insert(Path('hw/sh4/interpr/sh4_interpreter.cpp'), '#include "vf3audio.h"',
           '#include "vf3audio.h"\n#include "vf3audiobridge.h"')
    insert(Path('hw/sh4/interpr/sh4_interpreter.cpp'), '\t\t\t\t\tExecuteOpcode(op);',
           '\t\t\t\t\tif (vf3AudioReplayQueue(op,ctx)) continue;\n'
           '\t\t\t\t\tExecuteOpcode(op);')
    insert(Path('windows/winmain.cpp'), '#include "vf3oracle.h"',
           '#include "vf3oracle.h"\n#include "vf3audio.h"')
    insert(Path('windows/winmain.cpp'), '\t\tfprintf(stderr, "[vf3] emu.start...\\n");',
           '\t\t/* Diagnostic mode owns one synchronous guest execution stream. */\n'
           '\t\tif (getenv("VF3_AUDIO_CHECKPOINTS") && !getenv("VF3_AUDIO_THREADED"))\n'
           '\t\t\tconfig::ThreadedRendering.override(false);\n'
           '\t\tfprintf(stderr, "[vf3] emu.start...\\n");')
    insert(Path('windows/winmain.cpp'), '\t\t\t\tvf3OraclePrepare();',
           '\t\t\t\tvf3OraclePrepare();\n\t\t\t\tvf3AudioPrepare();')
    insert(Path('windows/winmain.cpp'), '\t\twhile (emu.running()) {',
           '\t\twhile (emu.running()) {\n\t\t\tif (vf3AudioDone()) break;')
    # Diagnostics must join execution before closing files just like capsules.
    insert(Path('windows/winmain.cpp'),
           'if (getenv("VF3_CAPSULE") || getenv("VF3_HITS")) {',
           'if (getenv("VF3_CAPSULE") || getenv("VF3_HITS") || getenv("VF3_AUDIO_CHECKPOINTS")) {')
    insert(Path("hw/sh4/interpr/sh4_interpreter.cpp"), '#include "vf3trace.h"',
           '#include "vf3trace.h"\n#include "vf3oracle.h"')
    insert(Path('hw/sh4/interpr/sh4_interpreter.cpp'), '#include "vf3oracle.h"',
           '#include "vf3oracle.h"\n#include "vf3audio.h"')
    insert(Path('hw/aica/sgc_if.cpp'), '#include "serialize.h"',
           '#include "serialize.h"\n#include "vf3audio.h"')
    insert(Path('hw/aica/sgc_if.cpp'), '\tWriteSample(mixr, mixl);',
           '\tvf3AudioSample(mixr,mixl);\n\tWriteSample(mixr, mixl);')
    insert(Path('hw/sh4/sh4_sched.cpp'), '#include "serialize.h"',
           '#include "serialize.h"\n#include "vf3audio.h"')
    insert(Path('hw/sh4/sh4_sched.cpp'), '\tint re_sch = sched.cb(sched.tag, remain, jitter, sched.arg);',
           '\tvf3AudioEvent((int)(&sched-&sch_list[0]),sched.tag,remain,jitter);\n'
           '\tint re_sch = sched.cb(sched.tag, remain, jitter, sched.arg);')
    insert(Path('hw/sh4/interpr/sh4_interpreter.cpp'),
           '\t\t\t\tctx->cycle_counter += SH4_TIMESLICE;',
           '\t\t\t\t/* Sound RAM probes must finish before any ARM7/device tick. */\n'
           '\t\t\t\tif (vf3OracleBeforeTimeslice()) continue;\n'
           '\t\t\t\tctx->cycle_counter += SH4_TIMESLICE;')
    insert(Path("hw/sh4/interpr/sh4_interpreter.cpp"), "\tvf3TraceDepthOp(addr, op, ctx);",
           "\tvf3TraceDepthOp(addr, op, ctx);\n"
           "\t/* A synthetic probe substitutes the target's first opcode for the\n"
           "\t * trigger's: redirecting the PC alone still lets ExecuteOpcode run the\n"
           "\t * trigger, and a jsr would then rewrite pr from the redirected PC and\n"
           "\t * leave the caller with a broken return chain. */\n"
           "\t{\n"
           "\t\tunsigned subPc=addr; unsigned short subOp=op;\n"
           "\t\tif (vf3OracleTakeSubstitute(&subPc,&subOp)) { addr=subPc; op=subOp; ctx->pc=addr+2; }\n"
           "\t}\n"
           "\t/* An aborted synthetic probe restores the game state after this opcode was\n"
           "\t * already fetched: re-fetch at the restored PC so nothing of the probe\n"
           "\t * leaks into the game's instruction stream. */\n"
           "\tif (vf3OracleTakeSkip()) {\n"
           "\t\tu32 resume=ctx->pc;\n"
           "\t\tctx->pc=resume+2;\n"
           "\t\treturn IReadMem16(resume);\n"
           "\t}")
    p = CORE / "hw/sh4/sh4_interrupts.cpp"
    text = p.read_text(encoding="utf-8")
    if '#include "vf3oracle.h"' not in text:
        p.write_text('#include "vf3oracle.h"\n' + text, encoding="utf-8")
    for anchor, extra in (
            ("static void Do_Interrupt(Sh4ExceptionCode intEvn)\n{\n\tvf3OracleInvalidate(1);",
             "\n\t/* An interrupt taken inside a synthetic probe is not dispatched: the\n"
             "\t * rollback would discard the handler entry and leave the CPU blocked,\n"
             "\t * which the emulator treats as a fatal nested exception. The oracle\n"
             "\t * rolls the probe back and the interrupt stays pending. */\n"
             "\n\tif (vf3OracleAbortProbe()) return;"),
            ("void Do_Exception(u32 epc, Sh4ExceptionCode expEvn)\n{\n\tvf3OracleInvalidate(1);",
             "\n\t/* A synthetic-entry probe that faulted is rolled back by the oracle;\n"
             "\t * dispatching its exception would fault again inside the handler. */\n"
             "\n\tif (vf3OracleAbortProbe()) return;")):
        insert(Path("hw/sh4/sh4_interrupts.cpp"), anchor, anchor + extra)
    p = CORE / "hw/sh4/sh4_mem.cpp"
    text = p.read_text(encoding="utf-8")
    if '#include "vf3oracle.h"' not in text:
        p.write_text('#include "vf3oracle.h"\n' + text, encoding="utf-8")
    import re
    p = CORE / "hw/sh4/interpr/sh4_fpu.cpp"
    text = p.read_text(encoding="utf-8")
    if "VF3 bounded FTRC conversion" not in text:
        replacement = '''//ftrc <FREG_N>, FPUL
sh4op(i1111_nnnn_0011_1101)
{
    // VF3 bounded FTRC conversion: the original positive-overflow correction
    // followed an undefined float-to-int cast and can be optimized away.
    // Check the range first, preserving the opcode's intended saturation.
    const double value = ctx->fpscr.PR ? getDRn(ctx, op) : ctx->fr[GetN(op)];
    if (std::isnan(value) || value < -2147483648.0)
        ctx->fpul = 0x80000000u;
    else if (value >= 2147483648.0)
        ctx->fpul = 0x7fffffffu;
    else
        ctx->fpul = static_cast<u32>(static_cast<s32>(value));
}


//fmac'''
        text, count = re.subn(r'//ftrc <FREG_N>, FPUL\nsh4op\(i1111_nnnn_0011_1101\).*?\n//fmac',
                             replacement, text, count=1, flags=re.S)
        if count != 1:
            raise SystemExit("Missing original FTRC opcode implementation")
        p.write_text(text, encoding="utf-8")
    p = CORE / "hw/sh4/sh4_mem.cpp"
    original = p.read_text(encoding="utf-8")
    text = original
    for name in ("WriteMemBlock_nommu_ptr", "WriteMemBlock_nommu_sq", "WriteMemBlock_nommu_dma"):
        if re.search(rf'{name}\([^;]*?\)\s*\{{\s*vf3OracleInvalidate', text):
            continue
        text, count = re.subn(rf'({name}\([^;]*?\)\s*\{{)', r'\1\n\tvf3OracleInvalidate(8);', text, count=1)
        if count != 1:
            raise SystemExit(f"Missing asynchronous-copy hook: {name}")
    if text != original:
        p.write_text(text, encoding="utf-8")
    normalize_observer()
    print("Oracle hooks installed; rebuild tools/emu/flycast-build.")

if __name__ == "__main__":
    main()
