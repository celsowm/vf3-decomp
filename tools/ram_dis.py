#!/usr/bin/env python3
"""ram_dis.py - disassemble SH-4 code straight out of a tick-capture entry RAM (any address, not only 1ST_READ).

  tools/.venv/Scripts/python tools/ram_dis.py <capture.bin> <addr_hex> [n_instructions] [--pair N]

Reads the entry RAM window of the capture (same record stream as src/fight/native_tick.c) and prints a linear sweep.
"""
import struct
import sys

from capstone import CS_ARCH_SH, CS_MODE_LITTLE_ENDIAN, CS_MODE_SH4, CS_MODE_SHFPU, Cs

RAM_BASE, RAM_LEN = 0x0C000000, 0x01000000


def entry_ram(path, pair=0):
    with open(path, 'rb') as f:
        data = f.read()
    w = struct.unpack(f'<{len(data) // 8}Q', data)
    i, seen, stage = 0, 0, 0
    while i < len(w):
        v = w[i]
        i += 1
        tag = v & 0xFFFF
        if (v >> 16) == 0 or tag < 0xFA30:
            continue
        if tag == 0xFA30 and stage == 0:
            i += 37
            stage = 1 if seen == pair else 2
        elif tag == 0xFA50 and stage == 1:
            n = w[i]
            i += 1
            for _ in range(n):
                base, ln = w[i], w[i + 1]
                i += 2
                if (base & 0xFFFFFFFF) == RAM_BASE and (ln & 0xFFFFFFFF) == RAM_LEN:
                    return b''.join(struct.pack('<I', x & 0xFFFFFFFF) for x in w[i:i + ln // 4])
                i += ln // 4
        elif tag == 0xFA32 and stage == 2:
            seen += 1
            stage = 0
    raise SystemExit('no entry RAM in capture')


def main():
    a = [x for x in sys.argv[1:] if not x.startswith('--')]
    pair = int(sys.argv[sys.argv.index('--pair') + 1]) if '--pair' in sys.argv else 0
    ram = entry_ram(a[0], pair)
    addr = int(a[1], 16) & 0x1FFFFFFF
    n = int(a[2]) if len(a) > 2 else 40
    md = Cs(CS_ARCH_SH, CS_MODE_SH4 | CS_MODE_SHFPU | CS_MODE_LITTLE_ENDIAN)
    off = addr - RAM_BASE
    for ins in md.disasm(ram[off:off + n * 2 + 8], addr):
        print(f'{ins.address | 0x80000000:08x}  {ins.bytes.hex()}  {ins.mnemonic} {ins.op_str}')
        n -= 1
        if n <= 0:
            break


if __name__ == '__main__':
    main()
