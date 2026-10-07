"""Seed only the exact live [sp+8] words to steer r1 to a zero word.

s21 sp=0x0c31f9cc -> seed 0x0c31f9d4; s27 sps -> 0x0c31f910/0x0c31f934/0x0c31f91c.
V cycles (Q,V): Q in {0x0c47e000,0x0c47d000,0x0c47c000} seeded 0.
Usage: sp8_0c8334.py <src.patch> <dst.patch> <n>
"""
import sys

TRIG = '0x8c0432e2'
# Aim r1 at fixture-zero words 0x0c40e010/014/018 (pinned 0 below).
VS = (0x5c904, 0x5c905, 0x5c906)
# r15 at the 843a read = entry_sp-36, so [r15+8] = [entry_sp-28].
# Observed entry sps: s21 0x0c31f9cc; s27 0x0c31f908/914/92c.
SP8 = (0x0c31f9b0, 0x0c31f8ec, 0x0c31f8f8, 0x0c31f910)

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
    V = VS[i % 3]
    for a in SP8:
        out.append(f'ram {TRIG} 0x{a:08x} 0x{V:08x}')
    # Pin the fixture-zero targets (base blocks may randomize them).
    out.append(f'ram {TRIG} 0x0c40e010 0x00000000')
    out.append(f'ram {TRIG} 0x0c40e014 0x00000000')
    out.append(f'ram {TRIG} 0x0c40e018 0x00000000')
open(sys.argv[2], 'w').write('\n'.join(out) + '\n')
print(f'wrote {n} variants -> {sys.argv[2]}')
