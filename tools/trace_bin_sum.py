#!/usr/bin/env python3
"""Summarise the reference's binary execution trace (VF3_TRACE).

The headless reference writes one 8-byte record per executed instruction:
the PC (u32) followed by the opcode word (u32), in the order they ran.  The
file is huge (gigabytes for a boot), so the summary streams it and never
holds more than a chunk in memory.

Usage:
    python tools/trace_bin_sum.py <trace.bin> [--top N] [--after PC]
"""
import argparse
import struct
from collections import Counter


def stream(path, chunk=1 << 22):
    """Yield the (pc, op) pairs of the trace."""
    with open(path, "rb") as f:
        while True:
            d = f.read(chunk)
            if not d:
                return
            n = len(d) // 8
            for i in range(n):
                pc, op = struct.unpack_from("<II", d, i * 8)
                yield pc, op
            tail = len(d) - n * 8
            if tail:
                f.seek(-tail, 1)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("trace")
    ap.add_argument("--top", type=int, default=25)
    ap.add_argument("--after", type=lambda s: int(s, 0),
                    help="only count the PCs after this PC was seen")
    a = ap.parse_args()

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
    if a.after is not None:
        print(f"(counting from the first PC {a.after:#x})")
    print(f"distinct PCs: {len(counts)}")
    print(f"{'PC':>12} {'count':>12} {'first #':>12}")
    for pc, c in counts.most_common(a.top):
        print(f"{pc:>12x} {c:>12d} {first[pc]:>12d}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
