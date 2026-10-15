#!/usr/bin/env python3
"""peek_call.py - look at one recorded call of the whole-tick oracle.

  python tools/recomp/peek_call.py 0x0c048600 [--state 7] [--n 0] [--words 40] [--reg r4]

Prints the call's input/output registers (those that differ) and the guest words
around a pointer register (default r4), read from the oracle's final RAM
(input data such as vertex records is not modified by the transformers, the
output area is). Used to work out record layouts before porting a function.
"""
import argparse
import struct
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent.parent
A = REPO / 'extract' / 'analysis'
NREG = 54
NAMES = [f'r{i}' for i in range(16)] + ['pr', 'sr', 'fpscr', 'macl', 'mach'] + \
        [f'fr{i}' for i in range(16)] + [f'xf{i}' for i in range(16)] + ['fpul']


def records(path):
    data = path.read_bytes()
    words = struct.unpack(f'<{len(data) // 4}I', data)
    assert words[0] == 0x31584656
    i = 1
    while i + 4 + 2 * NREG + 1 <= len(words):
        entry, seq, depth, steps = words[i:i + 4]
        inr = words[i + 4:i + 4 + NREG]
        outr = words[i + 4 + NREG:i + 4 + 2 * NREG]
        nw = words[i + 4 + 2 * NREG]
        wr = words[i + 5 + 2 * NREG:i + 5 + 2 * NREG + 3 * nw]
        yield entry, seq, depth, steps, inr, outr, wr
        i += 5 + 2 * NREG + 3 * nw


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('entry')
    ap.add_argument('--state', default='7')
    ap.add_argument('--n', type=int, default=0, help='ordinal among calls of this entry')
    ap.add_argument('--words', type=int, default=40)
    ap.add_argument('--reg', default='r4')
    ap.add_argument('--back', type=int, default=4, help='words to show before the pointer')
    a = ap.parse_args()
    entry = int(a.entry, 16) & 0x1FFFFFFF
    k = 0
    for e, seq, depth, steps, inr, outr, wr in records(A / f'fxr_tick_s{a.state}.bin'):
        if (e & 0x1FFFFFFF) != entry:
            continue
        if k != a.n:
            k += 1
            continue
        print(f'call #{a.n} seq {seq} depth {depth} steps {steps} stores {len(wr) // 3}')
        for i in range(NREG):
            if inr[i] != outr[i] or i in (4, 5, 6, 8, 12, 16):
                print(f'  {NAMES[i]:6s} in {inr[i]:08x} out {outr[i]:08x}')
        ram = (A / f'oracle_tick_s{a.state}.bin').read_bytes()[NREG * 4:]
        p = inr[NAMES.index(a.reg)] & 0x00FFFFFF
        print(f'words around {a.reg} = {inr[NAMES.index(a.reg)]:08x}:')
        for j in range(-a.back, a.words):
            off = p + 4 * j
            v = struct.unpack_from('<I', ram, off)[0]
            f = struct.unpack_from('<f', ram, off)[0]
            print(f'  {0x0c000000 + off:08x} ({j:+4d}) {v:08x} {f:14.6g}')
        return
    print('no such call')


if __name__ == '__main__':
    main()
