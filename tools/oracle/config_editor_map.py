"""Recover bounded scene configuration editor parameters from original words."""
import argparse
import json
from pathlib import Path
import struct
from campaign_io import read_watch

ROOT = Path(__file__).resolve().parents[2]
BASE = 0x0c010000


def decode(image, entry):
    entry &= 0x1fffffff
    words = list(struct.unpack_from('<27H', image, entry - BASE))
    pcs = [entry + 2*index for index in range(len(words))]
    short = words[5:7] == [0x430b, 0x64e3]
    if short:
        # The first field uses the base address and omits both offset adds.
        words.insert(5, 0x64e3)
        pcs.insert(5, None)
        words[7] = 0x7400
    if words[:3] != [0x4f22, 0x7ff8, 0x1f41]:
        raise ValueError(f'{entry:#x}: unsupported editor prologue')

    def literal(index):
        op = words[index]
        pc = pcs[index]
        if op >> 12 == 0xd:
            return struct.unpack_from('<I', image, (pc & ~3) + 4 + (op & 255) * 4 - BASE)[0]
        if op >> 12 == 0x9:
            return struct.unpack_from('<h', image, pc + 4 + (op & 255) * 2 - BASE)[0]
        if op >> 12 == 0xe:
            value = op & 255
            return value - 256 if value & 128 else value
        raise ValueError(f'{entry:#x}: unknown parameter instruction {op:04x}')

    if words[5:7] != [0x64e3, 0x430b] or words[7] >> 8 != 0x74:
        raise ValueError(f'{entry:#x}: unexpected getter sequence')
    width = {0x600c: 1, 0x600d: 2}.get(words[8])
    if width is None or words[16:18] != [0x420b, 0x54f1]:
        raise ValueError(f'{entry:#x}: unexpected editor ABI')
    if words[18:20] != [0x1f01, 0x7f0c] or words[20] != 0x4f26:
        raise ValueError(f'{entry:#x}: unexpected editor epilogue')
    parameters = {}
    for index in range(9, 17):
        op = words[index]
        if op >> 12 in (9, 0xe) and (op >> 8) & 15 in (3, 6, 7):
            parameters[(op >> 8) & 15] = literal(index)
        elif op == 0x6633:
            parameters[6] = parameters[3]
    if set(parameters) != {3, 6, 7}:
        raise ValueError(f'{entry:#x}: missing editor bounds')
    getter = 0x0c0c66b8 if width == 1 else 0x0c0c66c0
    setter = 0x0c0c66d0 if width == 1 else 0x0c0c66d4
    editor_calls = [literal(index) for index in range(9, 16)
                    if words[index] >> 8 == 0xd2]
    if (literal(3) != 0x0c11e504 or literal(4) != getter or
            literal(21) != setter or editor_calls != [0x0c072ec2]):
        raise ValueError(f'{entry:#x}: unexpected editor helper targets')
    return dict(entry=f'0x{entry:08x}', base=literal(3), getter=literal(4),
                offset=words[7] & 255, width=width, maximum=parameters[3],
                step=parameters[6], minimum=parameters[7], setter=literal(21),
                getter_return=entry+(14 if short else 16),
                editor_return=entry+(34 if short else 36))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--watch', type=Path, required=True)
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    image = (ROOT / 'extract/exe/1ST_READ.unsc.bin').read_bytes()
    rows = [decode(image, entry) for entry in sorted(read_watch(args.watch))
            if 0x8c08e1cc <= entry < 0x8c08e5b4]
    args.out.write_text(json.dumps(rows, indent=1) + '\n')
    for row in rows:
        print(f"{row['entry']} field+{row['offset']} width={row['width']} "
              f"min={row['minimum']} max={row['maximum']} step={row['step']}")


if __name__ == '__main__':
    main()
