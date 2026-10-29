#!/usr/bin/env python3
"""Read a RAM window out of a captured reference state and dump a range.

The capture files under extract/analysis/p1/frm_keep/st.bin.* hold the
reference's SH-4 state in the oracle's format: a stream of 32 bit words, each
one a marker of the form (pc << 16) | tag.  The tag 0xFA30 introduces the 37
registers, 0xFA70 the 16 XF registers and 0xFA50 a list of RAM windows, each
one as (base, length) followed by the window's bytes.

The tool finds the window whose base is the Dreamcast's RAM (0x0C000000) and
prints a hex dump of the range asked for - the way to compare the reference's
memory with the port's.

Usage:
    python tools/state_ram.py extract/analysis/p1/frm_keep/st.bin.000280 0x0C19C6A0 0x60
"""
from __future__ import annotations

import struct
import sys
from pathlib import Path

RAM_BASE = 0x0C000000
RAM_LEN = 0x01000000


def entry_ram(path: Path, pair: int = 0) -> bytes:
    raw = path.read_bytes()
    w = struct.unpack("<%dQ" % (len(raw) // 8), raw[:len(raw) // 8 * 8])
    i, seen, stage = 0, 0, 0
    while i < len(w):
        v = w[i]
        i += 1
        tag = v & 0xFFFF
        if (v >> 16) == 0 or tag < 0xFA30:
            continue
        if tag == 0xFA30 and stage == 0:
            i += 37
            stage = 1 if seen == pair else 2
        elif tag == 0xFA50 and stage == 1:
            n = w[i]
            i += 1
            for _ in range(n):
                base, ln = w[i], w[i + 1]
                i += 2
                if (base & 0xFFFFFFFF) == RAM_BASE and (ln & 0xFFFFFFFF) == RAM_LEN:
                    return b"".join(struct.pack("<I", x & 0xFFFFFFFF) for x in w[i:i + ln // 4])
                i += ln // 4
        elif tag == 0xFA32 and stage == 2:
            seen += 1
            stage = 0
    raise SystemExit("no entry RAM in capture")


def main() -> int:
    path = Path(sys.argv[1])
    addr = int(sys.argv[2], 0) & 0x1FFFFFFF
    n = int(sys.argv[3], 0) if len(sys.argv) > 3 else 0x40
    pair = 0
    if "--pair" in sys.argv:
        pair = int(sys.argv[sys.argv.index("--pair") + 1])
    ram = entry_ram(path, pair)
    print("%08X  base %08X  %d bytes" % (addr, RAM_BASE, len(ram)))
    for off in range(0, n, 16):
        a = addr + off
        b = ram[(a - RAM_BASE) & 0xFFFFFF:][:16]
        print("%08X  %s  |%s|" % (a, " ".join("%02x" % x for x in b),
                                 "".join(chr(x) if 32 <= x < 127 else "." for x in b)))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
