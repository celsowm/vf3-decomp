#!/usr/bin/env python3
"""Summarise the reference's binary execution trace (VF3_TRACE).

The headless reference writes one 8-byte record per executed instruction. This
tool recognizes both the legacy ``PC u32, opcode u32`` layout and the current
``opcode u16, PC u32, padding u16`` layout. The file can be very large, so the
summary streams it and never holds more than a chunk in memory. PC detection
includes the Dreamcast BIOS P2 alias at 0xA0000000 used by cold-boot traces.

Usage:
    python tools/trace_bin_sum.py <trace.bin> [--top N] [--after PC]
"""
import argparse
import struct
from collections import Counter


def guest_pc(value):
    # Cold boots begin in the Dreamcast BIOS mapped at the SH-4 P2 address
    # 0xA0000000; later game code is normally seen in one of the RAM mirrors.
    return value >> 24 in (0x0C, 0x8C, 0xAC, 0xA0)


def layout(path):
    with open(path, "rb") as f:
        first = f.read(8)
    if len(first) < 8:
        raise ValueError("trace is shorter than one instruction record")
    pc0 = struct.unpack_from("<I", first, 0)[0]
    pc2 = struct.unpack_from("<I", first, 2)[0]
    if guest_pc(pc0):
        return "pc-op"
    if guest_pc(pc2):
        return "op-pc-pad"
    raise ValueError("cannot identify a guest PC in the first trace record")


def stream(path, chunk=1 << 22):
    """Yield the (pc, op) pairs of the trace."""
    record_layout = layout(path)
    pending = b""
    with open(path, "rb") as f:
        while True:
            block = f.read(chunk)
            if not block:
                break
            d = pending + block
            n = len(d) // 8
            for i in range(n):
                offset = i * 8
                if record_layout == "pc-op":
                    pc, op = struct.unpack_from("<II", d, offset)
                else:
                    op = struct.unpack_from("<H", d, offset)[0]
                    pc = struct.unpack_from("<I", d, offset + 2)[0]
                yield pc, op
            pending = d[n * 8:]
    if pending:
        raise ValueError("trace ends with a partial instruction record")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("trace")
    ap.add_argument("--top", type=int, default=25)
    ap.add_argument("--after", type=lambda s: int(s, 0),
                    help="only count the PCs after this PC was seen")
    ap.add_argument("--pc", type=lambda s: int(s, 0), action="append", default=[],
                    help="also report the exact count for this PC; repeatable")
    a = ap.parse_args()

    record_layout = layout(a.trace)
    counts = Counter()
    total = 0
    seen_after = a.after is None
    first = {}
    for pc, op in stream(a.trace):
        total += 1
        if not seen_after:
            if pc == a.after:
                seen_after = True
            continue
        counts[pc] += 1
        if pc not in first:
            first[pc] = total

    print(f"instructions: {total}")
    print(f"record layout: {record_layout}")
    if a.after is not None:
        print(f"(counting from the first PC {a.after:#x})")
    print(f"distinct PCs: {len(counts)}")
    print(f"{'PC':>12} {'count':>12} {'first #':>12}")
    for pc, c in counts.most_common(a.top):
        print(f"{pc:>12x} {c:>12d} {first[pc]:>12d}")
    for pc in a.pc:
        print(f"PC {pc:#010x}: {counts.get(pc, 0)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
