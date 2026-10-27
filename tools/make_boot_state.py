#!/usr/bin/env python3
"""make_boot_state.py - a machine state for "boot from the disc".

The port's loader (vf3_native_load_snapshot) reads the 64-bit-record state the
reference instrument writes: a register record (marker 0xFA30, the pc in the
high half), the XF bank (0xFA70) and one RAM window (0xFA50: count, base, len
and one record per 32-bit word).  This tool writes such a state straight from
the disc's 1ST_READ.BIN - the program at 0x8C010000 with the registers the
bootstrap leaves - so the port can start where the Dreamcast does, instead of
from a state the reference reached.

  python tools/make_boot_state.py extract/gamedata/1ST_READ.BIN boot.state
  build/vf3sdl --state boot.state --entry 0x8c010000 --gdi rom/vf3.gdi ...
"""
from __future__ import annotations

import argparse
import struct
import sys
from pathlib import Path

RAM_BASE = 0x0C000000
RAM_LEN = 0x01000000
LOAD_ADDR = 0x8C010000
MARK_REGS, MARK_XF, MARK_WINDOWS = 0xFA30, 0xFA70, 0xFA50


def marker(pc: int, tag: int) -> bytes:
    return struct.pack('<Q', (pc << 16) | tag)


def build(image: bytes, entry: int, sp: int, sr: int, fpscr: int, low: bytes = b'') -> bytes:
    out = bytearray()
    out += marker(entry, MARK_REGS)
    regs = [0] * 16
    regs[15] = sp
    for r in regs:
        out += struct.pack('<Q', r)
    # pr, sr, fpscr, macl, mach
    for v in (0, sr, fpscr, 0, 0):
        out += struct.pack('<Q', v)
    out += struct.pack('<16Q', *([0] * 16))          # fr0..fr15
    out += marker(entry, MARK_XF)
    out += struct.pack('<16Q', *([0] * 16))
    out += marker(entry, MARK_WINDOWS)
    out += struct.pack('<QQQ', 1, RAM_BASE, RAM_LEN)
    ram = bytearray(RAM_LEN)
    off = (LOAD_ADDR & 0x00FFFFFF)
    if off + len(image) > RAM_LEN:
        raise SystemExit('the image does not fit in the 16 MiB of RAM')
    ram[0:len(low)] = low
    ram[off:off + len(image)] = image
    # the image's first instructions are a copy stub (0x8C010000): it moves
    # 0x0C010100..0x0C014000 down to 0x0C004000 and jumps there
    if entry == LOAD_ADDR:
        ram[0x4000:0x4000 + 0x3F00] = ram[0x10100:0x14000]
        entry = 0x8C004000
    words = struct.unpack('<%dI' % (RAM_LEN // 4), ram)
    out += struct.pack('<%dQ' % len(words), *words)
    return bytes(out)


def read_low_ram(path: Path, length: int = 0x10000) -> bytes:
    """the first `length` bytes of the RAM window of a reference state"""
    f = path.read_bytes()
    off = 8 * (1 + 37 + 1 + 16 + 1 + 3)
    words = struct.unpack_from('<%dQ' % (length // 4), f, off)
    return struct.pack('<%dI' % len(words), *(w & 0xFFFFFFFF for w in words))


def main() -> int:
    ap = argparse.ArgumentParser(description=(__doc__ or '').split('\n')[0])
    ap.add_argument('image', type=Path, help='1ST_READ.BIN (the retail ships it unscrambled)')
    ap.add_argument('out', type=Path)
    ap.add_argument('--entry', type=lambda s: int(s, 0), default=LOAD_ADDR)
    ap.add_argument('--sp', type=lambda s: int(s, 0), default=0x8CFFFFE0)
    ap.add_argument('--sr', type=lambda s: int(s, 0), default=0x700000F0)
    ap.add_argument('--fpscr', type=lambda s: int(s, 0), default=0x00040001)
    ap.add_argument('--low-ram', type=Path, help='a reference state whose first 0x10000 bytes (the BIOS system area and syscall stubs) seed the boot')
    a = ap.parse_args()
    low = read_low_ram(a.low_ram) if a.low_ram else b''
    a.out.write_bytes(build(a.image.read_bytes(), a.entry, a.sp, a.sr, a.fpscr, low))
    print(f'wrote {a.out} ({a.out.stat().st_size} bytes)')
    return 0


if __name__ == '__main__':
    sys.exit(main())
