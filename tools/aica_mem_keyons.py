#!/usr/bin/env python3
"""Read a VF3ARM1 memory trace and locate the melody key-on cycles (stores at
pc 0x264c), reporting each note's scheduler cycle and frame.  Also reports the
first/last record cycle so a histogram window can be aligned to the melody.
"""
import struct
import sys

ORIG = 5001139045  # reference cycle origin (frame 0 == this cycle)
A = 4535           # scheduler cycles per audio sample


def read_trace(path):
    d = open(path, "rb").read()
    assert d[:8] == b"VF3ARM1\x00", "not a VF3ARM1 trace"
    n = (len(d) - 8) // 40
    out = []
    for i in range(n):
        seq, cyc, pc, op, addr, val, sz, st = struct.unpack_from("<QQ6I", d, 8 + i * 40)
        if pc == 0x264c and st:  # key-on store
            out.append((cyc, addr, val & 0xff))
    return out, n


def main():
    path = sys.argv[1] if len(sys.argv) > 1 else \
        "extract/analysis/audio_arm_observer_v3/ref_scan_mem.arm"
    keys, n = read_trace(path)
    print("trace records: %d" % n)
    print("key-on stores (frame, cycle, addr, val):")
    for cyc, addr, val in keys:
        frame = (cyc - ORIG) / A
        print("  f%10.2f  cyc=%llu  %08x %02x" % (frame, cyc, addr, val))
    if keys:
        print()
        # Use a window spanning key1..last key (frames) with small padding.
        c0 = keys[0][0]
        c1 = keys[-1][0]
        # Recommend a window aligned to whole frames with 2-frame pad each side.
        ws = c0 - 2 * A
        we = c1 + 2 * A
        print("recommended VF3_ARM_WIN spanning key1..last:")
        print("  VF3_ARM_WIN=%d,%d" % (ws, we))
        print("  (frames %.1f .. %.1f)" % ((ws - ORIG) / A, (we - ORIG) / A))


if __name__ == "__main__":
    main()
