#!/usr/bin/env python3
"""count_blocks.py - count the card block reads in a port Maple log.

The Maple log prints the transfer's data words in brackets; for a block read
the first is the recipient and the function code (0x02000000) and the second
carries the block number in its top byte (0xff000000 = block 255).

    python tools/count_blocks.py build/card90.log
"""
import re
import sys
from pathlib import Path


def main() -> int:
    path = Path(sys.argv[1])
    rows = []
    for line in path.read_text(errors="replace").splitlines():
        if "maple: block at" not in line:
            continue
        m = re.search(r"frame ([0-9a-fA-F]{8})(.*)$", line)
        if not m:
            continue
        frame = int(m.group(1), 16)
        cmd = frame & 0xFF
        to = (frame >> 8) & 0xFF
        if cmd != 0x0B:
            continue
        words = re.findall(r"\[([0-9a-fA-F]{8})\]", m.group(2))
        blk = ""
        if len(words) >= 2:
            w = int(words[1], 16)
            blk = "%02x" % ((w >> 24) & 0xFF)
        rows.append((to, blk))
    print("block reads: %d" % len(rows))
    for to, blk in rows:
        print("  to=0x%02x block=%s" % (to, blk))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
