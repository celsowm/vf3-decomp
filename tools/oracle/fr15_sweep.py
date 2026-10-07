"""Clone an existing entry.patch, overriding fr15 per variant.

Usage: fr15_sweep.py <src.patch> <dst.patch> <n>
Takes variants round-robin from src, sets fr15 to {150,200,300} cycling.
"""
import sys

FR15 = ('0x43160000', '0x43480000', '0x43960000')  # 150.0, 200.0, 300.0

src = open(sys.argv[1]).read().splitlines()
n = int(sys.argv[3])
# Split into variants: first block (no seed) + seed-delimited blocks.
blocks, cur = [], []
for ln in src:
    if ln.startswith('#'):
        continue
    if ln.startswith('entry'):
        continue
    if ln.startswith('seed'):
        blocks.append(cur)
        cur = []
        continue
    cur.append(ln)
blocks.append(cur)
blocks = [b for b in blocks if b]
print(f'{len(blocks)} source variants')
out = [f'entry 0x8c0432e2 0x8c05cc38']
for i in range(n):
    if i:
        out.append('seed 0x8c0432e2')
    for ln in blocks[(i * 6) % len(blocks)]:
        if ln.startswith('reg 0x8c0432e2 fr15 '):
            ln = f'reg 0x8c0432e2 fr15 {FR15[i % 3]}'
        out.append(ln)
open(sys.argv[2], 'w').write('\n'.join(out) + '\n')
print(f'wrote {n} variants -> {sys.argv[2]}')
