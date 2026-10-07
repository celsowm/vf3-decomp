"""Generic synthetic-trigger fuzz inputs for leaf-ish roots.

Calls CHILD directly via trigger 0x8c0432e2 with pointer regs aimed at
seeded scratch and all other regs/words randomized (LCG, deterministic).
Crashing variants are simply rejected by capsule conversion; coverage of
the survivors is measured afterwards with body_cover.py.
"""
import sys

TRIGGER = 0x8c0432e2

BASES = {'r4': 0x0c420000, 'r5': 0x0c430000, 'r6': 0x0c440000,
         'r13': 0x0c450000, 'r14': 0x0c460000, 'r15': 0x0c47f000}


def lcg(state):
    return (state * 1103515245 + 12345) & 0xFFFFFFFF


def generate(path, child, variants=256, seed=1, base=0):
    st = seed
    lines = [f'entry 0x{TRIGGER:08x} 0x{child:08x}']
    for v in range(variants):
        if v:
            lines.append(f'seed 0x{TRIGGER:08x}')
        lines.append(f'target 0x{TRIGGER:08x} 0x{child & 0x1fffffff:08x}')
        lines.append(
            f'reg 0x{TRIGGER:08x} pr 0x{(TRIGGER + 2) & 0x1fffffff:08x}')
        regs = {}
        for rn, b in BASES.items():
            regs[rn] = b + base
        for rn in ('r0', 'r1', 'r2', 'r3', 'r7', 'r8', 'r9', 'r10', 'r11', 'r12'):
            st = lcg(st)
            regs[rn] = st
        st = lcg(st)
        regs['fpscr'] = 0x40001
        lines.extend(f'reg 0x{TRIGGER:08x} {k} 0x{val:08x}'
                     for k, val in regs.items())
        # Seed every scratch page sparsely: 64 words per base + stack.
        for b in BASES.values():
            bb = b + base
            for off in range(0, 256, 4):
                st = lcg(st)
                # Keep pointers plausible: every 8th word points at r4 base.
                val = (BASES['r4'] + base + (st % 128)) if (off % 32 == 0) else st
                lines.append(f'ram 0x{TRIGGER:08x} 0x{bb + off:08x} 0x{val:08x}')
    open(path, 'w').write('\n'.join(lines) + '\n')
    print(f'wrote {variants} variants child={child:#x} base={base:#x} -> {path}')


if __name__ == '__main__':
    generate(sys.argv[2], int(sys.argv[1], 0),
             int(sys.argv[3]) if len(sys.argv) > 3 else 256,
             int(sys.argv[4]) if len(sys.argv) > 4 else 1,
             int(sys.argv[5], 0) if len(sys.argv) > 5 else 0)
