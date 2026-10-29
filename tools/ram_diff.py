#!/usr/bin/env python3
"""ram_diff.py - the 32-bit words where the port's RAM differs from the reference's.

    python tools/ram_diff.py extract/analysis/p1/frm_keep/st.bin.000040 build/boot_f40.ram [max_rows]

The words are grouped by the 64 KiB page they live in, so a region's state
shows up as one block instead of thousands of rows.
"""
import struct
import sys

RAM_BASE = 0x0C000000
RAM_LEN = 0x01000000
PAGE = 0x10000


def parse_capture(path):
    raw = open(path, 'rb').read()
    n = len(raw) // 8
    w = struct.unpack("<%dQ" % n, raw)
    i, seen, stage = 0, 0, 0
    while i < n:
        v = w[i]; i += 1
        tag = v & 0xFFFF
        if (v >> 16) == 0 or tag < 0xFA30:
            continue
        if tag == 0xFA30 and stage == 0:
            i += 37
            stage = 1 if seen == 0 else 2
        elif tag == 0xFA50 and stage == 1:
            cnt = w[i]; i += 1
            for _ in range(cnt):
                base, ln = w[i], w[i + 1]; i += 2
                if (base & 0xFFFFFFFF) == RAM_BASE and (ln & 0xFFFFFFFF) == RAM_LEN:
                    return b"".join(struct.pack("<I", x & 0xFFFFFFFF) for x in w[i:i + ln // 4])
                i += ln // 4
        elif tag == 0xFA32 and stage == 2:
            seen += 1; stage = 0
    return None


def main():
    if len(sys.argv) < 3:
        print(__doc__)
        return 2
    limit = int(sys.argv[3], 0) if len(sys.argv) > 3 else 200
    ref = parse_capture(sys.argv[1])
    port = open(sys.argv[2], 'rb').read()
    port = port + b"\0" * (RAM_LEN - len(port))
    shown = 0
    pages = {}
    for off in range(0, RAM_LEN, 4):
        a = struct.unpack_from("<I", ref, off)[0]
        b = struct.unpack_from("<I", port, off)[0]
        if a == b:
            continue
        page = (RAM_BASE + off) & ~(PAGE - 1)
        pages[page] = pages.get(page, 0) + 1
    print("the differing pages (64 KiB each):")
    for page in sorted(pages):
        print("  %08x  %d words" % (page, pages[page]))
    print("\nthe first differences:")
    for off in range(0, RAM_LEN, 4):
        a = struct.unpack_from("<I", ref, off)[0]
        b = struct.unpack_from("<I", port, off)[0]
        if a == b:
            continue
        print("  %08x  ref %08x  port %08x" % (RAM_BASE + off, a, b))
        shown += 1
        if shown >= limit:
            print("  ...")
            break
    return 0


if __name__ == "__main__":
    sys.exit(main())
