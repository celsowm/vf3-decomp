#!/usr/bin/env python3
"""gen_translate.py — build a translate_adapters.py invocation for a root list.

The adapter translator (tools/oracle/translate_adapters.py) walks the CFG from
a set of watch roots and emits readable C.  It needs two things: the capture
directories that hold each root's executed-opcode map, and a watch file with
one `pc 0x8cXXXXXX` line per root.

This tool finds the capture directories for a root list and prints a ready-made
command line, so a new adapter module can be regenerated from the recorded
corpora alone.

    python tools/gen_translate.py 8c0492be 8c0853fe
    python tools/gen_translate.py --watch-file tools/watch/my_batch.txt \\
        --out src/fight/vf3_my_adapter.c --function vf3_my_adapter
"""
from __future__ import annotations

import argparse
import os
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[1]
ANALYSIS = REPO / "extract" / "analysis"


def capture_dirs(roots: list[str]) -> dict[str, list[str]]:
    """Map each root to the capture dirs that hold an executed-opcode map."""
    want = {r.lower().replace("0x", "") for r in roots}
    found: dict[str, list[str]] = {r: [] for r in want}
    for root, _dirs, files in os.walk(ANALYSIS):
        for name in files:
            if not (name.startswith("f_") and name.endswith(".ops.json")):
                continue
            entry = name[2:-len(".ops.json")]
            if entry in want:
                found[entry].append(Path(root).relative_to(REPO).as_posix())
    return found


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("roots", nargs="+", help="entry addresses, e.g. 8c0492be")
    ap.add_argument("--watch-file", default="", help="write the watch file here")
    ap.add_argument("--out", default="src/fight/vf3_new_adapter.c")
    ap.add_argument("--function", default="vf3_new_adapter")
    ap.add_argument("--reuse", default="src/fight/*.c")
    a = ap.parse_args()

    roots = [r.lower().replace("0x", "") for r in a.roots]
    watch = Path(a.watch_file) if a.watch_file else ANALYSIS / "gen_translate_watch.txt"
    watch.parent.mkdir(parents=True, exist_ok=True)
    watch.write_text("".join("pc 0x%s\n" % r for r in roots), encoding="ascii")

    found = capture_dirs(roots)
    dirs: list[str] = []
    for root in roots:
        hits = found.get(root, [])
        if not hits:
            print("# no executed-opcode map for %s (image CFG expansion only)" % root)
        for d in hits:
            if d not in dirs:
                dirs.append(d)

    try:
        watch_rel = watch.resolve().relative_to(REPO).as_posix()
    except ValueError:
        watch_rel = watch.as_posix()

    print("python tools/oracle/translate_adapters.py \\")
    for d in dirs:
        print("  %s \\" % d)
    print("  --watch %s \\" % watch_rel)
    print("  --out %s \\" % a.out)
    print("  --function %s \\" % a.function)
    print("  --reuse-adapter '%s'" % a.reuse)
    return 0


if __name__ == "__main__":
    sys.exit(main())
