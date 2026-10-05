"""Seed original allocator prologues with coherent acyclic block lists.

The original category headers use 20-byte strides, block records and the
descriptor pool use 24-byte strides. Scratch buffers are rollback fixtures;
outputs and branch evidence must come from original execution.
"""
import argparse
from pathlib import Path
import struct

ROOT = Path(__file__).resolve().parents[2]
POOL = 0x0c16cf6c
HEADERS = 0x0c0eae08
PARENTS = (0x8c061c04, 0x8c061e70, 0x8c061fca, 0x8c062390, 0x8c06288c,
           0x8c062490, 0x8c0624ba, 0x8c062524)


def fixture(parent, variant, relocation=0, holdout=False):
    if parent not in PARENTS:
        raise ValueError('unknown allocator prologue')
    if relocation < 0 or relocation > 0x700000 or relocation % 4096:
        raise ValueError('relocation must be page aligned within RAM')
    # Descriptor membership is checked against this fixed original pool by
    # the release helper. Relocate clients/storage, not the game's pool itself.
    first, second, third = (POOL + 24 * slot for slot in (8, 9, 10))
    output, region, stack = (address + relocation for address in
                             (0x0c420000, 0x0c430000, 0x0c47f000))
    registers = {f'r{i}': (variant * 17 + i + (513 if holdout else 0)) & 1023
                 for i in range(15)}
    registers.update(r15=stack, fpscr=0x40001)
    selector = (variant // 8) % 2
    header = HEADERS + selector * 20
    lengths = (64, 96, 160, 192) if holdout else (32, 64, 96, 128)
    requested = lengths[(variant // 16) % 4] + (variant % 2) * 7
    rounded = (requested + 31) & ~31
    layout = variant % 8
    address = region
    capacity = rounded
    if layout == 1:
        capacity += 64
    elif layout == 2:
        address += 64; capacity += 64
    elif layout == 3:
        address += 64; capacity += 128
    elif layout == 4:
        address -= 32
    elif layout == 5:
        address += 32; capacity = 32
    elif layout == 6:
        address += 2 * rounded; capacity = rounded
    words = {stack + offset: 0 for offset in range(-256, 32, 4)}
    words.update({output + offset: 0 for offset in range(0, 64, 4)})
    words[stack] = (variant // 8) & 1
    words[stack + 4] = (variant // 16) & 1
    for category in range(2):
        words.update({HEADERS + category * 20 + offset: 0 for offset in range(0, 20, 4)})
    for node in (first, second, third):
        words.update({node + offset: 0 for offset in range(0, 24, 4)})
        words[node] = 1
    # A rejected first candidate exercises list traversal; its successor is
    # either the chosen block or another disjoint block, never a cycle.
    prefix = bool(variant & 32)
    chosen = second if prefix else first
    words.update({chosen: 1, chosen + 4: first if prefix else 0,
                  chosen + 8: 0, chosen + 12: region, chosen + 16: capacity,
                  header + 8: first, header + 12: chosen, header + 16: capacity})
    if prefix:
        words.update({first + 8: second, first + 12: region + 0x2000,
                      first + 16: 32, header + 16: capacity + 32})
    if layout == 7:
        words[header + 8] = words[header + 12] = 0
    # Keep a small deterministic prefix occupied before the first free slot.
    # One variant in 32 supplies a full pool to reach genuine exhaustion.
    occupied = (4096 if variant % 32 == 3 else
                4095 if variant % 32 == 11 else (variant // 4) % 4)
    for slot in range(4096 if occupied >= 4095 else 8):
        base = POOL + slot * 24
        if base in (first, second, third):
            continue
        words.update({base + offset: 0 for offset in range(0, 24, 4)})
        # With one free descriptor, put it first: the ensuing failed second
        # allocation and cleanup stay within the oracle's 100,000-op record cap.
        words[base] = int(slot != 0) if occupied == 4095 else int(slot < occupied)
    registers.update(r4=selector, r5=address, r6=requested, r7=output)
    if parent in (0x8c061e70, 0x8c061fca):
        registers.update(r5=requested, r6=output,
                         r7=(0, 8, 0x2000, 8)[(variant // 8) % 4])
    elif parent == 0x8c062390:
        # Release an allocated block between zero, one or two adjacent free
        # blocks. Its allocated-list head/tail are separate from the free list.
        registers['r5'] = third
        words.update({third: 5, third + 12: region + rounded,
                      third + 16: rounded, header: third, header + 4: third,
                      first + 12: region, first + 16: rounded,
                      second + 12: region + 2 * rounded, second + 16: rounded})
        if layout == 0:
            words[header + 8] = words[header + 12] = 0
        elif layout == 1:
            words.update({header + 8: first, header + 12: first,
                          first + 4: 0, first + 8: 0})
        elif layout == 2:
            words.update({header + 8: second, header + 12: second,
                          second + 4: 0, second + 8: 0})
        else:
            words.update({header + 8: first, header + 12: second,
                          first + 4: 0, first + 8: second,
                          second + 4: first, second + 8: 0})
            if layout in (4, 6):
                words[first + 12] = region + 0x2000
            if layout in (6, 7):
                words[second + 12] = region + 0x3000
            if layout == 5:
                words.update({header + 8: second, header + 12: first,
                              second + 4: 0, second + 8: first,
                              first + 4: second, first + 8: 0})
    elif parent == 0x8c0624ba:
        registers['r4'] = POOL + 24 * ((variant // 4) % 4)
        words[registers['r4']] = 0x101 if variant & 1 else 1
    elif parent == 0x8c062524:
        registers.update(r4=header + 8, r5=header + 12, r6=second)
        prev = first if variant & 1 else 0
        following = third if variant & 2 else 0
        words.update({second + 4: prev, second + 8: following,
                      header + 8: prev or second, header + 12: following or second,
                      first + 8: second, third + 4: second})
    return registers, words


def generate(output, variants=256, relocation=0, holdout=False, trigger=0x8c0432e2, parents=PARENTS):
    if not 64 <= variants <= 1024:
        raise ValueError('variants must be 64..1024')
    if not parents or any(parent not in PARENTS for parent in parents):
        raise ValueError('unknown or empty allocator target list')
    image = (ROOT / 'extract/gamedata/1ST_READ.BIN').read_bytes()
    for pc, opcode in ((0x8c062490, 0xd53f), (0x8c0624ac, 0x7418),
                       (0x8c062524, 0x7ff8), (0x8c061c04, 0x2fe6)):
        if struct.unpack_from('<H', image, pc - 0x8c010000)[0] != opcode:
            raise ValueError(f'original allocator pattern changed at {pc:#x}')
    lines = ['# Coherent original allocator inputs; no expected-output patches.',
             f'entry 0x{trigger:08x} 0x{parents[0]:08x}']
    for variant in range(variants):
        for parent in parents:
            if variant or parent != parents[0]:
                lines.append(f'seed 0x{trigger:08x}')
            lines.extend((f'target 0x{trigger:08x} 0x{parent & 0x1fffffff:08x}',
                          f'reg 0x{trigger:08x} pr 0x{(trigger + 2) & 0x1fffffff:08x}'))
            registers, words = fixture(parent, variant, relocation, holdout)
            lines.extend(f'reg 0x{trigger:08x} {name} 0x{value:08x}' for name, value in registers.items())
            lines.extend(f'ram 0x{trigger:08x} 0x{address:08x} 0x{value:08x}' for address, value in sorted(words.items()))
    output = Path(output)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text('\n'.join(lines) + '\n', encoding='ascii')
    print(f'{len(parents)} allocator targets, {variants} variants -> {output}')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--variants', type=int, default=256)
    parser.add_argument('--relocation', type=lambda value: int(value, 0), default=0)
    parser.add_argument('--holdout', action='store_true')
    parser.add_argument('--parent', action='append', type=lambda value: int(value, 0),
                        help='restrict targets to an original allocator prologue; repeatable')
    args = parser.parse_args()
    generate(args.out, args.variants, args.relocation, args.holdout, parents=args.parent or PARENTS)
