#!/usr/bin/env python3
"""fight_reach.py - scan an execution trace for unported-baseline body hits.

Reads a vf3trace u64 record stream (pc = rec>>16, op = rec&0xffff, bit16 =
exception marker, P2 alias 0x0C000000..0x0C1FFFFF folded to 0x8C......) and
count, per still-unported baseline function (docs/decomp_status.csv), how many
trace records land inside its frozen body range. A nonzero count is
reachability evidence only - it does not qualify the owner. Mid-body first
hits (dyn@ jumps) prove dispatched entries that entry-PC-only screens miss.

Usage: python tools/fight_reach.py [trace.bin] [--out report.json] [--csv out.csv]
Defaults to extract/analysis/trace_fight1.bin.
"""
from __future__ import annotations

import argparse
import bisect
import csv
import json
import struct
import sys
import time
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
AN = REPO / 'extract' / 'analysis'
FIELDS = ['entry', 'size', 'hits', 'first_record', 'first_pc']


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('trace', nargs='?', default=str(AN / 'trace_fight1.bin'))
    ap.add_argument('--out')
    ap.add_argument('--csv')
    a = ap.parse_args()

    ported = {r['entry'].lower().replace('0x', '')
              for r in csv.DictReader(open(REPO / 'docs' / 'decomp_status.csv'))
              if r.get('status', '').startswith('ported')}
    iv = []
    for r in csv.DictReader(open(AN / 'funcs_1ST_READ.unsc.bin.csv', newline='')):
        if r['entry'].lower().replace('0x', '') in ported:
            continue
        e = int(r['entry'], 16)
        s = int(r['size'])
        if s > 0:
            iv.append((e, s))
    iv.sort()
    los = [x[0] for x in iv]
    counts = [0] * len(iv)
    first: dict[int, tuple[int, int]] = {}

    n = Path(a.trace).stat().st_size // 8
    print(f'fight_reach: {len(iv)} unported owners against {n:,} records in {a.trace}', flush=True)
    CH = 1 << 22
    reci = 0
    t0 = time.time()
    with open(a.trace, 'rb') as f:
        while True:
            buf = f.read(CH * 8)
            if not buf:
                break
            cnt = len(buf) // 8
            base = reci
            for local_idx, (rec,) in enumerate(struct.iter_unpack('<Q', buf)):
                if rec & 0x10000:
                    continue
                pc = (rec >> 16) & 0xFFFFFFFF
                if 0x0C000000 <= pc < 0x0C200000:
                    pc |= 0x80000000
                _i = bisect.bisect_right(los, pc) - 1
                if _i >= 0:
                    e, s = iv[_i]
                    if pc < e + max(s, 4):
                        counts[_i] += 1
                        if e not in first:
                            first[e] = (base + local_idx, pc)
            reci += cnt
            print(f'  .. {reci/1e6:.0f}M records, {time.time()-t0:.0f}s', flush=True)

    out_rows = []
    for (e, s), c in zip(iv, counts):
        if c == 0:
            continue
        fr, fpc = first.get(e, (-1, 0))
        out_rows.append(dict(entry=f'0x{e:08x}', size=str(s), hits=str(c),
                             first_record=str(fr), first_pc=f'0x{fpc:08x}'))
    out_rows.sort(key=lambda r: -int(r['hits']))
    if a.csv:
        with open(a.csv, 'w', newline='') as f:
            w = csv.DictWriter(f, fieldnames=FIELDS)
            w.writeheader()
            w.writerows(out_rows)
    summary = dict(trace=a.trace, records=n, owners=len(out_rows),
                   covered_bytes=sum(int(r['size']) for r in out_rows),
                   rows=out_rows)
    if a.out:
        Path(a.out).write_text(json.dumps(summary, indent=1), encoding='utf-8')
    print(f'owners with hits: {len(out_rows)}, bytes: {summary["covered_bytes"]}', flush=True)
    for r in out_rows[:40]:
        print('  ', r['entry'], r['size'], 'B hits=', r['hits'], 'first@%s pc=%s' % (r['first_record'], r['first_pc']))
    return 0


if __name__ == '__main__':
    sys.exit(main())
