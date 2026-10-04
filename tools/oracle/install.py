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

def main():
    for name in ("vf3oracle.cpp", "vf3oracle.h"):
        shutil.copyfile(Path(__file__).parent / name, CORE / name)
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
    insert(Path("hw/sh4/interpr/sh4_interpreter.cpp"), '#include "vf3trace.h"',
           '#include "vf3trace.h"\n#include "vf3oracle.h"')
    insert(Path("hw/sh4/interpr/sh4_interpreter.cpp"), "\tvf3TraceInstr(addr, op);",
           "\tvf3OracleBefore(addr, op, ctx);\n\tvf3TraceInstr(addr, op);")
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
    text = p.read_text(encoding="utf-8")
    for name in ("WriteMemBlock_nommu_ptr", "WriteMemBlock_nommu_sq", "WriteMemBlock_nommu_dma"):
        if re.search(rf'{name}\([^;]*?\)\s*\{{\s*vf3OracleInvalidate', text):
            continue
        text, count = re.subn(rf'({name}\([^;]*?\)\s*\{{)', r'\1\n\tvf3OracleInvalidate(8);', text, count=1)
        if count != 1:
            raise SystemExit(f"Missing asynchronous-copy hook: {name}")
    p.write_text(text, encoding="utf-8")
    print("Oracle hooks installed; rebuild tools/emu/flycast-build.")

if __name__ == "__main__":
    main()
