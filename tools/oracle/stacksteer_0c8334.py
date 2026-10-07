"""Clone a patch forcing a synthetic stack to steer [sp+8] -> r1 -> [r1]==0.

r1 = ([sp+8]<<2) + 0x0c29bc00. Setting sp=0x0c47f000 (scratch),
[sp+8]=V makes r1 = (V<<2)+C. Pairs (Q,V):
  Q=0x0c47e000 V=0x78900 | Q=0x0c47d000 V=0x74900 | Q=0x0c47c000 V=0x70900
Seeds [Q]=0 and stack words around sp.
Usage: stacksteer_0c8334.py <src.patch> <dst.patch> <n>
"""
import sys

TRIG = '0x8c0432e2'
SP = 0x0c47f000
PAIRS = ((0x0c47e000, 0x78900), (0x0c47d000, 0x74900), (0x0c47c000, 0x70900))

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
    Q, V = PAIRS[i % 3]
    have_r15 = False
    for ln in blocks[(i * 5) % len(blocks)]:
        if ln.startswith(f'reg {TRIG} r15 '):
            ln = f'reg {TRIG} r15 0x{SP:08x}'
            have_r15 = True
        out.append(ln)
    if not have_r15:
        out.append(f'reg {TRIG} r15 0x{SP:08x}')
    out.append(f'ram {TRIG} 0x{Q:08x} 0x00000000')
    out.append(f'ram {TRIG} 0x{SP + 8:08x} 0x{V:08x}')
    for off in (0, 4, 12, 16, 20, 24, 28, 32):
        out.append(f'ram {TRIG} 0x{SP + off:08x} 0x{(i * 97 + off) & 0xFFFFFFFF:08x}')
    # re-assert SP+8 after the fill (off loop skips 8)
    out.append(f'ram {TRIG} 0x{SP + 8:08x} 0x{V:08x}')
open(sys.argv[2], 'w').write('\n'.join(out) + '\n')
print(f'wrote {n} variants -> {sys.argv[2]}')
