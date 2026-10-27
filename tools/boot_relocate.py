#!/usr/bin/env python3
"""boot_relocate.py - move a generated module's code addresses to where the
bootstrap runs them.

The retail image's first stub (0x8C010000) copies 0x0C010100..0x0C014000 down
to 0x0C004000, clears the source and runs the copy.  The translator walks the
image at its load address, so the module it writes names the *source* PCs.  The
code is position independent (mova + literal offsets), but its literal-pool
reads and its labels are absolute: left alone they read the cleared source.
This tool rewrites every code address in [src_lo, src_hi) by `delta`, keeps the
claim arrays sorted, and leaves addresses outside the window (data, callees in
the resident part of the image) as they are.

  python tools/boot_relocate.py raw.c out.c
"""
from __future__ import annotations

import re
import sys
from pathlib import Path

SRC_LO, SRC_HI, DST = 0x0C010100, 0x0C014000, 0x0C004000
DELTA = DST - SRC_LO


def shift(v: int) -> int:
    return v + DELTA if SRC_LO <= v < SRC_HI else v


def relocate(text: str) -> str:
    def full(m):
        return '0x%08xu' % shift(int(m.group(1), 16))
    text = re.sub(r'0x(0c01[0-3][0-9a-f]{3})u', full, text)
    # code_base|0x000104..u : the mova result, an address without the mirror byte
    text = re.sub(r'(code_base\|)0x(0001[0-3][0-9a-f]{3})u',
                  lambda m: m.group(1) + '0x%08xu' % (shift(int(m.group(2), 16) | 0x0C000000) & 0x00FFFFFF), text)
    text = re.sub(r'P_(0c01[0-3][0-9a-f]{3})\b', lambda m: 'P_%08x' % shift(int(m.group(1), 16)), text)

    def resort(m):
        vals = sorted(set(int(x, 16) for x in re.findall(r'0x([0-9a-f]{8})u', m.group(2))))
        return m.group(1) + ',\n'.join('0x%08xu' % v for v in vals) + m.group(3)
    return re.sub(r'(static const uint32_t (?:owned|claim)_pcs\[\]=\{\n)(.*?)(\n\};)', resort, text, flags=re.S)


if __name__ == '__main__':
    Path(sys.argv[2]).write_text(relocate(Path(sys.argv[1]).read_text()))
