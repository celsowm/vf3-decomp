#!/usr/bin/env python3
"""boot_scope.py - which functions run in a savestate's call-edge log, and how many are ported.

Reads extract/analysis/p4/e<N>.bin (written by scene_survey.py; 16-byte records kind, from, to, depth; kind 0 = call)
and decomp_status.csv. Prints, per state, the executed callee set split into ported / unported, and the union over
all given states, so the size of a boot-chain port is known before starting.

  python tools/boot_scope.py 21 22 23 30 42 45
"""
import argparse
import csv
import struct
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
A = REPO / 'extract' / 'analysis'


def load_status():
    ported = set()
    with open(REPO / 'docs' / 'decomp_status.csv', newline='') as f:
        for r in csv.DictReader(f):
            if r['status'].startswith('ported') or r['status'].startswith('verified') or r['status'] == 'readable':
                ported.add(int(r['entry'], 16))
    return ported


def load_funcs():
    starts = []
    for r in csv.reader(open(A / 'funcs_1ST_READ.unsc.bin.csv')):
        try:
            starts.append(int(r[0], 16))
        except ValueError:
            pass
    return sorted(starts)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('states', nargs='+')
    a = ap.parse_args()
    ported = load_status()
    union = {}
    for n in a.states:
        p = A / 'p4' / f'e{n}.bin'
        if not p.exists():
            print(f'state {n}: no {p}')
            continue
        d = p.read_bytes()
        recs = [struct.unpack_from('<4I', d, 16 * i) for i in range(len(d) // 16)]
        calls = {}
        for k, frm, to, depth in recs:
            if k == 0:
                calls[to | 0x80000000] = calls.get(to | 0x80000000, 0) + 1
        un = {t: c for t, c in calls.items() if t not in ported}
        print(f'state {n}: {len(calls)} callees, {len(un)} unported')
        for t, c in sorted(un.items(), key=lambda x: -x[1])[:12]:
            print(f'    0x{t:08x} x{c}')
        for t, c in un.items():
            union[t] = union.get(t, 0) + c
    print(f'union unported callees: {len(union)}')
    return 0


if __name__ == '__main__':
    sys.exit(main())
