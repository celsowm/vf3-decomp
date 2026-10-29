#!/usr/bin/env python3
"""mpdrv_state.py - the mpdrv's own state, reference against the port.

The reference's RAM comes out of the `st.bin.*` captures (the `0xFA50` window
list); the port's is a raw 16 MiB dump (`--dump-ram`).  Both are compared on
the structures the mpdrv keeps:

    0x0C1B9608   the mpdrv's handle (the core's state block)
    handle+0x134 the number of times the core's control ran
    handle+0x18C0  the per-port table (stride 0xBC; +0x0C is the port's state)
    0x0C1B20C0   the request queue (8 entries of 0x80: +4 pending, +8 state,
                 +0x74 attach handler, +0x78 store handler, +0x7C device)
    0x0C19C6A0   the driver's record per drive (+0 attached, +2 usable,
                 +8/+0xC the device number)
    0x0C1A1A90   the device masks
    0x0C0EA284   the SDK's service table (the slots and the object pointer
                 at 0x0C0EA314 that every dispatcher reads)

    python tools/mpdrv_state.py extract/analysis/p1/frm_keep/st.bin.000040 build/boot_f45.ram
"""
import struct
import sys

RAM_BASE = 0x0C000000
RAM_LEN = 0x01000000


def parse_capture(path):
    """The 16 MiB RAM window out of a reference `st.bin.*` capture."""
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


def u32(ram, a):
    return struct.unpack_from("<I", ram, (a - RAM_BASE) & 0xFFFFFF)[0]


def words(ram, base, count):
    return [u32(ram, base + 4 * i) for i in range(count)]


def dump(name, ram):
    print("== %s ==" % name)
    h = u32(ram, 0x0C1B9608)
    print("  handle %08x" % h)
    if h and RAM_BASE <= h < RAM_BASE + RAM_LEN:
        print("  the core's control ran %d times (handle+0x134)" % u32(ram, h + 0x134))
        for p in range(8):
            e = h + 0x18C0 + p * 0xBC
            vals = words(ram, e, 0xBC // 4)
            if not any(vals):
                continue
            print("    port %d @ %08x  state=%d retry=%d" % (p, e, vals[3], vals[5]))

    print("  the device masks 0x0C1A1A90: %s" %
          " ".join("%08x" % v for v in words(ram, 0x0C1A1A90, 5)))

    for p in range(8):
        b = 0x0C1B20C0 + p * 0x80
        vals = words(ram, b, 0x80 // 4)
        if not any(vals):
            continue
        print("    queue %d  +4=%08x +8=%08x +74=%08x +78=%08x +7c=%08x" %
              (p, vals[1], vals[2], vals[0x74 // 4], vals[0x78 // 4], vals[0x7C // 4]))

    print("  the driver record 0x0C19C6A0: %s" %
          " ".join("%08x" % v for v in words(ram, 0x0C19C6A0, 0x40 // 4)))

    obj = u32(ram, 0x0C0EA314)
    print("  the SDK service table: [0x0C0EA314] = %08x" % obj)
    base = obj if obj else 0x0C0EA284
    slots = [(off, u32(ram, base + off)) for off in range(40, 104, 4)]
    print("    slots: %s" % " ".join("%08x" % v for _, v in slots if v))
    print("    +0x60..+0x90: %s" %
          " ".join("%08x" % u32(ram, base + off) for off in range(0x60, 0x94, 4)))


def main():
    if len(sys.argv) < 3:
        print(__doc__)
        return 2
    ref = parse_capture(sys.argv[1])
    if ref is None:
        print("no RAM window in %s" % sys.argv[1])
        return 1
    port = open(sys.argv[2], 'rb').read()
    port = port + b"\0" * (RAM_LEN - len(port))
    dump("reference", ref)
    dump("port", port)
    return 0


if __name__ == "__main__":
    sys.exit(main())
