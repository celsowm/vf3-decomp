"""Create bounded save-record inputs, including the original uint32 length wrap.

04708c validates type fields, adds fixed section sizes to a uint32 payload
length and checks CRC-16/0x1021 over that computed length. Negative-looking
payload words exercise overflow; no instruction or size table is modified.
"""
import argparse
import json
from pathlib import Path


def crc16(data):
    value = 0
    for byte in data:
        value ^= byte << 8
        for _ in range(8):
            value = ((value << 1) ^ (0x1021 if value & 0x8000 else 0)) & 0xffff
    return value


def records():
    result = []
    # Original tables: type 1 contributes 512; optional sections contribute
    # 0, 8064, 4544 or 2048. Every addition wraps to a 640-byte CRC region.
    for pattern in range(8):
        for optional, size in enumerate((0, 8064, 4544, 2048)):
            data = bytearray(640)
            data[:16] = bytes((pattern + index) & 255 for index in range(16))
            data[64:66] = (1).to_bytes(2, 'little')
            data[68:70] = optional.to_bytes(2, 'little')
            data[72:76] = ((-size) & 0xffffffff).to_bytes(4, 'little')
            checksum = crc16(data)
            # Matching and mismatching records test both original returns.
            for corrupt in (0, 1):
                specimen = bytearray(data)
                specimen[70:72] = (checksum ^ corrupt).to_bytes(2, 'little')
                result.append(specimen)
    return result


def generate(record_address=0x0c405000):
    samples = records()
    fields = {
        f'0x{record_address + offset:08x}':
            [f'0x{int.from_bytes(data[offset:offset + 4], "little"):08x}' for data in samples]
        for offset in range(0, 640, 4)
    }
    return {'0x8c04708c': fields}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out', required=True, type=Path)
    args = parser.parse_args()
    args.out.write_text(json.dumps(generate(), indent=1) + '\n')
    print('64 save-record variants; 640 bytes each; original tables preserved')


if __name__ == '__main__':
    main()
