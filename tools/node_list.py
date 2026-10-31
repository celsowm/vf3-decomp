#!/usr/bin/env python3
"""node_list.py - dump the SDK's service node list from a reference capture.

The list head array sits at 0x0C1A0D48; the nodes are 16 bytes each
{fn, next, pad, param}.
"""
from __future__ import annotations

import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from state_ram import entry_ram  # noqa: E402

HEAD = 0x0C1A0D48
NODE = 0x0C1A0D80
END = 0x0C1A0E60


def show(ram: bytes, label: str) -> None:
    print("== %s ==" % label)
    heads = []
    for i in range(8):
        v = struct.unpack_from("<I", ram, HEAD - 0x0C000000 + 4 * i)[0]
        heads.append(v)
    print("   heads: %s" % " ".join("%08x" % h for h in heads))
    for a in range(NODE, END, 0x10):
        o = a - 0x0C000000
        fn, nxt, p3, par = struct.unpack_from("<IIII", ram, o)
        if fn == 0 and nxt == 0 and p3 == 0 and par == 0:
            continue
        print("   %08x  fn %08x  next %08x  p3 %08x  param %08x" % (a, fn, nxt, p3, par))


def main() -> int:
    for arg in sys.argv[1:]:
        p = Path(arg)
        if p.suffix == ".ram":
            ram = p.read_bytes() + b"\0" * max(0, 0x01000000 - p.stat().st_size)
        else:
            ram = entry_ram(p)
        show(ram, p.name)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
