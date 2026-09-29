#!/usr/bin/env python3
"""Extract optional SH-4 XF-matrix sidecars from a VF3_FULL trace.

The trace hook emits XF groups only for PCs named with `xfpc` in VF3_WATCH.
Each file is a sequence of 16 little-endian float-bit words per golden case,
deduplicated in the same register-pair order as golden_extract.py.
"""
from __future__ import annotations

import argparse
import struct
from pathlib import Path

from golden_extract import NVALS, marker, read_records


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("trace")
    ap.add_argument("--pc", required=True, type=lambda s: int(s, 0))
    ap.add_argument("--out", required=True)
    ap.add_argument("--max-samples", type=int, default=64)
    a = ap.parse_args()
    pc = a.pc & 0xFFFFFFFF
    recs = read_records(Path(a.trace))
    pending = []
    pairs = []
    current = None
    current_xf_kind = None
    i = 0
    while i < len(recs):
        m = marker(recs[i])
        recpc = (recs[i] >> 16) & 0xFFFFFFFF
        if m == 0xFA30 and recpc == pc:
            vals = tuple(x & 0xFFFFFFFF for x in recs[i + 1:i + 1 + NVALS])
            current = {"in": vals, "out": None, "xfin": None, "xfout": None}
            pending.append(current)
            current_xf_kind = "xfin"
            i += NVALS + 2
            continue
        if m == 0xFA32 and recpc == pc and pending:
            sample = pending.pop(0)
            sample["out"] = tuple(x & 0xFFFFFFFF
                                  for x in recs[i + 1:i + 1 + NVALS])
            pairs.append(sample)
            current = sample
            current_xf_kind = "xfout"
            i += NVALS + 2
            continue
        if m == 0xFA70 and recpc == pc and current is not None:
            values = []
            j = i + 1
            while j < len(recs) and len(values) < 16:
                if (recs[j] & 0xFFFF) != 0xFA72:
                    break
                values.append((recs[j] >> 16) & 0xFFFFFFFF)
                j += 1
            if len(values) == 16 and j < len(recs) and marker(recs[j]) == 0xFA71:
                current[current_xf_kind] = tuple(values)
                i = j + 1
                continue
        i += 1

    unique = []
    seen = set()
    for p in pairs:
        key = (p["in"], p["out"])
        if key in seen:
            continue
        seen.add(key)
        unique.append(p)
        if len(unique) >= a.max_samples:
            break

    if not unique or any(p["xfin"] is None or p["xfout"] is None for p in unique):
        print(f"XF extraction incomplete: {len(unique)} register cases, "
              f"{sum(p['xfin'] is None or p['xfout'] is None for p in unique)} "
              "missing matrices")
        return 1

    out = Path(a.out)
    out.mkdir(parents=True, exist_ok=True)
    stem = f"f_{pc:08x}"
    for suffix, key in (("xfin", "xfin"), ("xfout", "xfout")):
        blob = b"".join(struct.pack("<16I", *p[key]) for p in unique)
        (out / f"{stem}.{suffix}.bin").write_bytes(blob)
    print(f"{stem}: {len(pairs)} entry/exit pairs, {len(unique)} unique XF pairs")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
