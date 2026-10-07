"""Clone an entry.patch, overriding given RAM addresses per variant.

Usage: ram_override.py <src.patch> <dst.patch> <n> <addrHex=csvHex,...> [--stride K]
Each variant i gets override value = list[i % len(list)] for each address.
Values cycle; variant source blocks round-robin stride 6 (as before).
"""
import sys

src = open(sys.argv[1]).read().splitlines()
n = int(sys.argv[3])
specs = []
for tok in sys.argv[4].split(','):
    addr, vals = tok.split('=')
    specs.append((addr.lower(), vals.split('|')))
stride = 6
for a in sys.argv[5:]:
    if a.startswith('--stride'):
        stride = int(a.split('=')[1])

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
out = [src[1] if src[1].startswith('entry') else f'entry {trig} 0x8c05cc38']
for i in range(n):
    if i:
        out.append(f'seed {trig}')
    oval = {a: v[i % len(v)] for a, v in specs}
    for ln in blocks[(i * stride) % len(blocks)]:
        if ln.startswith('ram '):
            parts = ln.split()
            if parts[2].lower() in oval:
                ln = f'{parts[0]} {parts[1]} {parts[2]} 0x{int(oval[parts[2].lower()], 0):08x}'
                del oval[parts[2].lower()]
        out.append(ln)
    for a, v in oval.items():
        out.append(f'ram {trig} 0x{int(a, 0):08x} 0x{int(v, 0):08x}')
open(sys.argv[2], 'w').write('\n'.join(out) + '\n')
print(f'wrote {n} variants -> {sys.argv[2]}')
