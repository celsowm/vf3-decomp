"""Directed tail-coverage inputs for 0x8c08d00e (156 B frozen body).

Tail 06a..084 executes iff at 068 T==0, i.e.:
  v1 = float([[r14+72]+0x140c]) > 2.0            (pass 058)
  v2 = float([r14+36]) in (2.0, 5.0]            (pass 05e/060, fall through 068)
  [r14+28] & 0x80000000 == 0  (bf/s@070 NOT taken: T=1)
  mem[[r14+76]+80] & 0x80000000 == 0  (bf@07e NOT taken: T=1)
  [r14+16] & 0x00800000 != 0  (bt@084 NOT taken: T=0) -> falls to 086
r0=0 takes the full store path (stores do not clobber the seeded words).
"""
import struct

TRIGGER = 0x8c0432e2
CHILD = 0x8c08d00e
R14 = 0x0c410000
R13 = 0x0c40d000
STACK = 0x0c413000
Q1 = 0x0c411000   # [r14+72] points here; Q1+0x140c holds v1
Q2 = 0x0c412000   # [r14+76] points here; Q2+80 holds sign word


def bits(f):
    return struct.unpack('<I', struct.pack('<f', f))[0]


V2 = [2.000001, 2.5, 3.0, 4.0, 4.999, 5.0]
V1 = [2.000001, 3.0, 4.0, 100.0]


def fixture(variant, base=0, salt=0):
    v2 = V2[((variant + salt) // 3) % len(V2)]
    v1 = V1[((variant + salt) // (3 * len(V2))) % len(V1)]
    r0 = ((variant + salt) % 3) * 2  # 0, 2, 4 -- never 1 (keeps full path)
    R14b = R14 + base
    R13b = R13 + base
    STACKb = STACK + base
    Q1b = Q1 + base
    Q2b = Q2 + base
    regs = {'r0': r0, 'r1': 5 + variant + salt, 'r2': 2, 'r3': 7,
            'r4': 4 + variant, 'r5': 0, 'r6': 0, 'r7': variant * 3 + salt,
            'r13': R13b, 'r14': R14b, 'r15': STACKb, 'fpscr': 0x40001}
    words = {
        R14b + 36: bits(v2),
        R14b + 72: Q1b,
        Q1b + 0x140c: bits(v1),
        R14b + 28: 0x3F800000,      # 1.0, high bit clear
        R14b + 76: Q2b,
        Q2b + 80: 0x00000000,        # high bit clear
        R14b + 16: 0x00800001,      # bit23 set
        R14b + 56: 0x11111111 * (((variant + salt) % 5) + 1) & 0xFFFFFFFF,
        R14b + 60: 0x22222222 * (((variant + salt) % 7) + 1) & 0xFFFFFFFF,
        R13b + 72: 0,
    }
    words.update({STACKb + off: ((variant + salt) * 97 + off) & 0xFFFFFFFF
                  for off in range(0, 64, 4)})
    return regs, words


def generate(path, variants=128, base=0, salt=0):
    lines = [f'entry 0x{TRIGGER:08x} 0x{CHILD:08x}']
    for v in range(variants):
        if v:
            lines.append(f'seed 0x{TRIGGER:08x}')
        lines.append(f'target 0x{TRIGGER:08x} 0x{CHILD & 0x1fffffff:08x}')
        lines.append(f'reg 0x{TRIGGER:08x} pr 0x{(TRIGGER + 2) & 0x1fffffff:08x}')
        regs, words = fixture(v, base, salt)
        lines.extend(f'reg 0x{TRIGGER:08x} {k} 0x{val:08x}'
                     for k, val in regs.items())
        lines.extend(f'ram 0x{TRIGGER:08x} 0x{a:08x} 0x{val:08x}'
                     for a, val in sorted(words.items()))
    open(path, 'w').write('\n'.join(lines) + '\n')
    print(f'wrote {variants} variants base={base:#x} salt={salt} -> {path}')


if __name__ == '__main__':
    import sys
    generate(sys.argv[1], int(sys.argv[2]) if len(sys.argv) > 2 else 128,
             int(sys.argv[3], 0) if len(sys.argv) > 3 else 0,
             int(sys.argv[4]) if len(sys.argv) > 4 else 0)
