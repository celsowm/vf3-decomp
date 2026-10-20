"""Build an entry patch that seeds every register with a safe arena pointer.

`pointer_seeds.fixture()` only fills the registers its inference can tie to a
writable address; the rest keep the live register state of the trigger, and a
garbage pointer there makes the probe dereference a non-RAM address (the
oracle rejects the specimen with flags=2|4).  Seeding every argument register
with a page of the fixture arena keeps the probe inside the RAM the oracle
records.
"""
import argparse
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools' / 'oracle'))
from pointer_seeds import fixture  # noqa: E402

ARENA = 0x0c420000
PAGE = 0x1000


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--entry', type=lambda x: int(x, 16), required=True)
    ap.add_argument('--trigger', type=lambda x: int(x, 16), default=0x8c0432e2)
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--variants', type=int, default=8)
    ap.add_argument('--mode', choices=('zero', 'open', 'one'), default='zero')
    ap.add_argument('--global-fields', action='store_true')
    a = ap.parse_args()

    registers, words = fixture(a.entry, a.mode, a.global_fields)[:2]
    lines = ['# Typed original-image inputs; expected results come only from execution.',
             'entry 0x%08x 0x%08x' % (a.trigger, a.entry)]
    for variant in range(a.variants):
        if variant:
            lines.append('seed 0x%08x' % a.trigger)
        lines += ['target 0x%08x 0x%08x' % (a.trigger, a.entry & 0x1fffffff),
                  'reg 0x%08x pr 0x%08x' % (a.trigger, (a.trigger + 2) & 0x1fffffff)]
        # every argument register points into the arena, so a dereference of an
        # un-inferred argument stays inside the recorded RAM
        for reg in range(15):
            if reg in registers:
                value = registers[reg]
            else:
                value = ARENA + (reg + variant) * PAGE
            lines.append('reg 0x%08x r%d 0x%08x' % (a.trigger, reg, value & 0xffffffff))
        for addr, value in sorted(words.items()):
            lines.append('ram 0x%08x 0x%08x 0x%08x' % (a.trigger, addr, value & 0xffffffff))
    a.out.write_text('\n'.join(lines) + '\n')
    print('%d lines, %d fixture words, %d fixture registers'
          % (len(lines), len(words), len(registers)))


if __name__ == '__main__':
    main()
