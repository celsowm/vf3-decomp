"""Verify and inspect the original state checksum table and its lookup stride.

This checks original-image metadata, not replay results or body coverage.
The routine reads words at a four-byte stride from a packed two-byte CRC table.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct

ROOT = Path(__file__).resolve().parents[2]
BASE = 0x8c010000


def crc_table(polynomial=0x1021):
    words = []
    for index in range(256):
        value = index << 8
        for _ in range(8):
            value = ((value << 1) ^ (polynomial if value & 0x8000 else 0)) & 0xffff
        words.append(value)
    return words


def inspect(image, preview=0):
    def word(address):
        offset = address - BASE
        if offset < 0 or offset + 2 > len(image):
            raise ValueError(f'original instruction missing at {address:#x}')
        return struct.unpack_from('<H', image, offset)[0]

    # Validate the literal load, two one-bit shifts, and indexed word read.
    pc = 0x8c076b4e
    op = word(pc)
    if op >> 12 != 0xd or (op >> 8) & 15 != 0 or any(
            word(address) != opcode for address, opcode in
            ((pc+2, 0x4700), (pc+4, 0x4700), (pc+6, 0x027d))):
        raise ValueError('original checksum lookup instruction pattern changed')
    literal = ((pc+4) & ~3) + (op & 255)*4
    if literal - BASE + 4 > len(image):
        raise ValueError('original table pointer missing')
    pointer = struct.unpack_from('<I', image, literal-BASE)[0]
    address = (pointer & 0x1fffffff) | 0x80000000
    offset = address - BASE
    if offset < 0 or offset + 1024 > len(image):
        raise ValueError('original checksum lookup region outside image')
    packed = image[offset:offset+512]
    table = list(struct.unpack('<256H', packed))
    expected = crc_table()
    original_words = [struct.unpack_from('<H', image, offset+4*i)[0] for i in range(256)]
    return dict(advisory=True, coverage_credit=False, address=f'0x{address:08x}',
                packed_entries=256, packed_stride=2, polynomial='0x1021',
                packed_table_match=table == expected, original_lookup_stride=4,
                generic_crc_replacement_equivalent=original_words == expected,
                table_sha256=hashlib.sha256(packed).hexdigest(),
                preview=[dict(index=i, packed_word=f'0x{table[i]:04x}',
                              original_lookup_word=f'0x{original_words[i]:04x}')
                         for i in range(preview)])


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--image', type=Path, default=ROOT / 'extract/gamedata/1ST_READ.BIN')
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--preview', type=int, choices=range(257), default=0,
                        metavar='0..256', help='inspect packed words and actual indexed reads')
    args = parser.parse_args()
    data = inspect(args.image.read_bytes(), args.preview)
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_text(json.dumps(data, indent=1) + '\n')
    print(f"{data['address']}: packed CRC table match={data['packed_table_match']}; "
          f"original stride={data['original_lookup_stride']}; "
          f"generic CRC equivalent={data['generic_crc_replacement_equivalent']}")
    for row in data['preview']:
        print(row['index'], row['packed_word'], row['original_lookup_word'])
    return int(not data['packed_table_match'])


if __name__ == '__main__':
    raise SystemExit(main())
