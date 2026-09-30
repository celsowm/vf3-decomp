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
    insert(Path("hw/sh4/CMakeLists.txt"), "target_sources(${PROJECT_NAME} PRIVATE",
           "target_sources(${PROJECT_NAME} PRIVATE\n        ../../vf3oracle.cpp")
    insert(Path("hw/sh4/interpr/sh4_interpreter.cpp"), '#include "vf3trace.h"',
           '#include "vf3trace.h"\n#include "vf3oracle.h"')
    insert(Path("hw/sh4/interpr/sh4_interpreter.cpp"), "\tvf3TraceInstr(addr, op);",
           "\tvf3OracleBefore(addr, op, ctx);\n\tvf3TraceInstr(addr, op);")
    p = CORE / "hw/sh4/sh4_interrupts.cpp"
    text = p.read_text(encoding="utf-8")
    if '#include "vf3oracle.h"' not in text:
        p.write_text('#include "vf3oracle.h"\n' + text, encoding="utf-8")
    for anchor in ("static void Do_Interrupt(Sh4ExceptionCode intEvn)\n{",
                   "void Do_Exception(u32 epc, Sh4ExceptionCode expEvn)\n{"):
        insert(Path("hw/sh4/sh4_interrupts.cpp"), anchor,
               anchor + "\n\tvf3OracleInvalidate(1);")
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
