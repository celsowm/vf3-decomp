#!/usr/bin/env python3
"""scratch_deps.py - which scratch registers does anything downstream of a readable function read?

For one readable entry, poisons each non-contract register in turn (TICK_SCRATCH=poison,
TICK_SCRATCH_ONLY, TICK_SCRATCH_MASK of vf3tickmix) and reports the registers whose poisoning
changes the whole-tick outcome (final RAM diff vs the oracle, or the number of diverged
calls). Those registers are undeclared dependencies: add them to the entry's out_regs and
make the port produce them.

  python tools/recomp/scratch_deps.py 0x0c068f92 [--state 7] [--jobs 4]
"""
import argparse
import os
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent.parent
A = REPO / 'extract' / 'analysis'
EXE = REPO / 'build' / 'vf3tickmix.exe'
# v[] indices that can be clobbered; vf3tickmix itself intersects the mask with the
# registers the original function really changes (from the oracle records) and with
# everything outside the entry's out_regs
SCRATCH = list(range(8)) + [19, 20] + list(range(21, 37)) + [53]


def name(i):
    if i < 16:
        return f'r{i}'
    if i == 19:
        return 'macl'
    if i == 20:
        return 'mach'
    if i == 53:
        return 'fpul'
    return f'fr{i - 21}'


def run(entry, state, mask):
    env = dict(os.environ)
    env.update({'TICK_SCRATCH': 'poison', 'TICK_SCRATCH_ONLY': entry, 'TICK_SCRATCH_MASK': f'{mask:x}'})
    cmd = [str(EXE), '0x8c09616a', str(A / f'golden_tickx_vf3_{state}.bin'), str(A / f'fxr_tick_s{state}.bin'),
           str(A / f'oracle_tick_s{state}.bin'), '0']
    out = subprocess.run(cmd, env=env, capture_output=True, text=True, cwd=str(REPO)).stdout
    m = re.search(r'ram diff bytes: (\d+)', out)
    d = re.search(r'(\d+) diverged', out)
    return (int(m.group(1)) if m else -1), (int(d.group(1)) if d else -1)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('entry')
    ap.add_argument('--state', default='7')
    ap.add_argument('--jobs', type=int, default=4)
    ap.add_argument('--out-regs', default='', help='hex mask of the entry contract (skipped)')
    a = ap.parse_args()
    skip = int(a.out_regs, 16) if a.out_regs else 0
    base = run(a.entry, a.state, 0)
    print(f'baseline (nothing poisoned): ram diff bytes {base[0]}, diverged {base[1]}')
    regs = [i for i in SCRATCH if not (skip >> i) & 1]
    with ThreadPoolExecutor(a.jobs) as ex:
        res = list(ex.map(lambda i: (i, run(a.entry, a.state, 1 << i)), regs))
    dep = []
    for i, (rd, dv) in res:
        flag = rd != base[0]          # audit-in noise (dv) also moves when an unread register changes
        if flag:
            dep.append(name(i))
        print(f'  {name(i):5s} ram {rd:7d} diverged {dv:6d} {"<-- DEPENDS" if flag else ""}')
    print('dependencies:', ' '.join(dep) or 'none')
    return 0


if __name__ == '__main__':
    sys.exit(main())
