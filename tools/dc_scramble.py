#!/usr/bin/env python3
"""Dreamcast 1ST_READ.BIN scramble/descramble.

Python port of the algorithm published by Marcus Comstedt and used in
KallistiOS utils/scramble/scramble.c (BSD-licensed). No code is copied;
the permutation algorithm itself is reimplemented here.

A scrambled retail load file is split into 32-byte 'slices'. The file is
processed in chunks of at most 2 MiB (halving as needed); within each chunk
the slices are permuted with a fixed LCG-driven Fisher-Yates shuffle seeded
by the total file size. Descrambling performs the identical permutation
while reading.
"""

MAXCHUNK = 2048 * 1024
SLICE = 32


class _Rng:
    def __init__(self, n):
        self.state = n & 0xFFFF

    def next(self):
        self.state = (self.state * 2109 + 9273) & 0x7FFF
        return (self.state + 0xC000) & 0xFFFF


def _chunk_order(chunksz, rng):
    """Yield dst slice indices in scrambled-stream order."""
    n = chunksz // SLICE
    idx = list(range(n))
    order = []
    for i in range(n - 1, -1, -1):
        x = (rng.next() * i) >> 16
        idx[i], idx[x] = idx[x], idx[i]
        order.append(idx[i])
    return order


def descramble(data: bytes) -> bytes:
    filesz = len(data)
    rng = _Rng(filesz)
    out = bytearray(filesz)
    src = 0
    dst = 0
    chunksz = MAXCHUNK
    remaining = filesz
    while chunksz >= SLICE:
        while remaining >= chunksz:
            for slice_idx in _chunk_order(chunksz, rng):
                out[dst + slice_idx * SLICE: dst + slice_idx * SLICE + SLICE] = \
                    data[src: src + SLICE]
                src += SLICE
            dst += chunksz
            remaining -= chunksz
        chunksz >>= 1
    if remaining:
        out[dst: dst + remaining] = data[src: src + remaining]
    return bytes(out)


def scramble(data: bytes) -> bytes:
    filesz = len(data)
    rng = _Rng(filesz)
    out = bytearray(filesz)
    src = 0
    outpos = 0
    chunksz = MAXCHUNK
    remaining = filesz
    while chunksz >= SLICE:
        while remaining >= chunksz:
            for slice_idx in _chunk_order(chunksz, rng):
                out[outpos: outpos + SLICE] = \
                    data[src + slice_idx * SLICE: src + slice_idx * SLICE + SLICE]
                outpos += SLICE
            src += chunksz
            remaining -= chunksz
        chunksz >>= 1
    if remaining:
        out[outpos: outpos + remaining] = data[src: src + remaining]
    return bytes(out)


def main(argv):
    if len(argv) != 4 or argv[1] not in ("-d", "-s"):
        print("usage: dc_scramble.py -d|-s in out  (-d descramble, -s scramble)")
        return 1
    import os
    with open(argv[2], "rb") as f:
        data = f.read()
    outdir = os.path.dirname(os.path.abspath(argv[3]))
    os.makedirs(outdir, exist_ok=True)
    res = descramble(data) if argv[1] == "-d" else scramble(data)
    with open(argv[3], "wb") as f:
        f.write(res)
    print(f"{'descrambled' if argv[1] == '-d' else 'scrambled'} "
          f"{argv[2]} -> {argv[3]} ({len(res)} bytes)")
    return 0


if __name__ == "__main__":
    import sys
    sys.exit(main(sys.argv))
