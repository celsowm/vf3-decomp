"""Seed live-stack window so [sp+8] steers r1 to a zero word.

r1 = ([sp+8]<<2) + 0x0c29bc00. Live sp ~0x0c31f9xx (varies); seed the whole
0x0c31f900..0x0c31f9f0 window with V cycling over 3 (Q,V) pairs, and seed
each Q with 0. Variants that land [r1]==0 take bt@8464 -> 846a.
Usage: stackwindow_0c8334.py <src.patch> <dst.patch> <n>
"""
import sys

TRIG = '0x8c0432e2'
C = 0x0c29bc00
QS = (0x0c47e000, 0x0c47d000, 0x0c47c000)
LOS = range(0x0c31f900, 0x0c31f9f4, 4)

src = open(sys.argv[1]).read().splitlines()
n = int(sys.argv[3])
blocks, cur = [], []
for ln in src:
    if ln.startswith('#') or ln.startswith('entry'):
        continue
    if ln.startswith('seed'):
        blocks.append(cur)
        cur = []
        continue
    cur.append(ln)
blocks.append(cur)
blocks = [b for b in blocks if b]
print(f'{len(blocks)} source variants')
out = [l for l in src if l.startswith('entry')][:1]
for i in range(n):
    if i:
        out.append(f'seed {TRIG}')
    out.extend(blocks[(i * 5) % len(blocks)])
    Q = QS[i % 3]
    V = ((Q - C) >> 2) & 0xFFFFFFFF
    out.append(f'ram {TRIG} 0x{Q:08x} 0x00000000')
    for a in LOS:
        out.append(f'ram {TRIG} 0x{a:08x} 0x{V:08x}')
open(sys.argv[2], 'w').write('\n'.join(out) + '\n')
print(f'wrote {n} variants -> {sys.argv[2]}')
