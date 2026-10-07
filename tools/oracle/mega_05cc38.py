"""Mega-sweep cloner: fr15 x r13 x [r14+40] x [0x0c05cce4].

Usage: mega_05cc38.py <src.patch> <dst.patch>
Cycles fr15 in {150,200,300}, r13 in {0,1,2,3,5,8},
[r14+40] in {negatives,0}, [0x0c05cce4] in {neg,0,1}.
216 variants.
"""
import sys

FR15 = ('0x43160000', '0x43480000', '0x43960000')
R13 = (0, 1, 2, 3, 5, 8)
M40 = ('0x80000000', '0xffffffff', '0x00000000')
CE4 = ('0x80000000', '0x00000000', '0x00000001')

src = open(sys.argv[1]).read().splitlines()
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
trig = '0x8c0432e2'
combos = [(f, r, m, c) for f in FR15 for r in R13 for m in M40 for c in CE4]
print(f'{len(combos)} combos')
out = [l for l in src if l.startswith('entry')][:1]
for i, (f, r, m, c) in enumerate(combos):
    if i:
        out.append(f'seed {trig}')
    seen_m40 = seen_ce4 = False
    for ln in blocks[(i * 7) % len(blocks)]:
        if ln.startswith('reg 0x8c0432e2 fr15 '):
            ln = f'reg 0x8c0432e2 fr15 {f}'
        elif ln.startswith('reg 0x8c0432e2 r13 '):
            ln = f'reg 0x8c0432e2 r13 0x{r:08x}'
        elif ln.startswith('ram '):
            p = ln.split()
            if p[2].lower() == '0x0c40e028':
                ln = f'{p[0]} {p[1]} {p[2]} {m}'
                seen_m40 = True
            elif p[2].lower() == '0x0c05cce4':
                ln = f'{p[0]} {p[1]} {p[2]} {c}'
                seen_ce4 = True
        out.append(ln)
    if not seen_m40:
        out.append(f'ram {trig} 0x0c40e028 {m}')
    if not seen_ce4:
        out.append(f'ram {trig} 0x0c05cce4 {c}')
open(sys.argv[2], 'w').write('\n'.join(out) + '\n')
print(f'wrote {len(combos)} variants -> {sys.argv[2]}')
