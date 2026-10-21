#!/usr/bin/env python3
"""Write a VF3_RAM_PATCH fixture that fills the low RAM region with the image.

The game runs 1ST_READ from the RAM copy at 0x0C010000, but the loader only
places the part of the image the game actually reaches: the low region
(0x0C010000-0x0C030000) stays zero in every captured state, and a synthetic
probe that targets an entry there executes zeros until it reaches the erased
0xffff padding and the specimen is retired with flags=1.

The fixture writes the image's own bytes into that region, so the probe runs
the real code.  The lines use the oracle's two-field form ("addr value"),
which is applied once at start-up rather than per probe, so the same file
serves every entry of a sweep.
"""
import argparse
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
IMAGE = ROOT / 'extract/exe/1ST_READ.unsc.bin'
BASE = 0x8c010000
RAM_BASE = 0x0c010000


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--out', type=Path, required=True)
    ap.add_argument('--start', type=lambda s: int(s, 16), default=0x0c010000)
    ap.add_argument('--end', type=lambda s: int(s, 16), default=0x0c030000)
    a = ap.parse_args()
    image = IMAGE.read_bytes()
    start = a.start & ~3
    end = a.end & ~3
    lines = []
    for addr in range(start, end, 4):
        off = (addr | 0x80000000) - BASE
        if 0 <= off <= len(image) - 4:
            lines.append('%08x %08x' % (addr, struct.unpack_from('<I', image, off)[0]))
    a.out.write_text('\n'.join(lines) + '\n')
    print('wrote %d words to %s' % (len(lines), a.out))


if __name__ == '__main__':
    main()
