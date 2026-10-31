#!/usr/bin/env python3
"""gd_sectorscan.py - how much of a track file carries data.

The disc images in rom/ were dumped outside the repo (rom/ is gitignored), so
the question "does the disc actually hold the game?" has to be answered from
the bytes: this tool reports, per track file, the first and last non-zero
byte and the fraction of non-zero 32 KiB blocks.

    python tools/gd_sectorscan.py rom/track01.bin rom/track02.raw rom/track03.bin
"""
from __future__ import annotations

import sys
from pathlib import Path

CHUNK = 1 << 15


def main() -> int:
    for arg in sys.argv[1:]:
        p = Path(arg)
        size = p.stat().st_size
        first = None
        last = None
        blocks = 0
        used = 0
        with open(p, "rb") as f:
            off = 0
            while off < size:
                buf = f.read(CHUNK)
                if not buf:
                    break
                if any(buf):
                    used += 1
                    if first is None:
                        first = off + next(i for i, b in enumerate(buf) if b)
                    last = off + len(buf) - 1 - next(i for i, b in enumerate(reversed(buf)) if b)
                blocks += 1
                off += len(buf)
        print("%-14s %12d bytes  %6d/%6d chunks with data  first nz %s  last nz %s"
              % (p.name, size, used, blocks,
                 "none" if first is None else "0x%x" % first,
                 "none" if last is None else "0x%x" % last))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
