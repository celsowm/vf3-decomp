#!/usr/bin/env python3
"""adapter_body.py - print the raw generated source of one guest PC and its
neighbours, module by module.

The translator emits one label per guest PC.  Several modules can carry the
same PC (the same function was captured in more than one campaign), and the
router serves the first module in chain order that owns it.  When two copies
disagree, the router's choice is the one that runs, so the copies have to be
compared before a readable port is written against one of them.

Usage:
    python tools/adapter_body.py 0x0c03550c
    python tools/adapter_body.py 0x0c03550c --span 0x40
"""
from __future__ import annotations

import argparse
import re
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
SRC = REPO / "src" / "fight"

LABEL = re.compile(r"^P_([0-9a-f]{8}):")


def bodies() -> dict[str, dict[int, list[str]]]:
    out: dict[str, dict[int, list[str]]] = {}
    for path in sorted(SRC.glob("*adapter*.c")):
        text = path.read_text(encoding="utf-8", errors="replace")
        lines = text.splitlines()
        blocks: dict[int, list[str]] = {}
        cur: int | None = None
        for line in lines:
            m = LABEL.match(line)
            if m:
                cur = int(m.group(1), 16)
                blocks[cur] = []
                continue
            if cur is not None:
                s = line.strip()
                if s and not s.startswith("if(!s->budget--)"):
                    blocks[cur].append(s)
        out[path.stem] = blocks
    return out


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("entry")
    ap.add_argument("--span", type=lambda s: int(s, 0), default=0x40,
                    help="how many bytes of guest PC to show")
    args = ap.parse_args()

    want = int(args.entry, 16) & 0x1FFFFFFF
    lo, hi = want, want + args.span
    for stem, blocks in bodies().items():
        if want not in blocks:
            continue
        print(f"===== {stem}")
        for pc in sorted(p for p in blocks if lo <= p < hi):
            print(f"  {pc:08x}  {' '.join(blocks[pc])}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
