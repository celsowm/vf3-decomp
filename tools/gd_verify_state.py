#!/usr/bin/env python3
"""gd_verify_state.py - check the disc sector reader against the RAM stored in a flycast savestate.

Reads extract/analysis/gd_state/vf3_<N>.txt (tools/gd_state_dump.py), decodes the GDI track layout, and for the
outstanding DMA request compares the first sectors (already transferred) against the savestate's decompressed RAM:
the block read from the disc must occur in the state at the destination offset.

  python tools/gd_verify_state.py 21 22 23
"""
import struct
import sys
import zlib
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
DATA = REPO / 'tools' / 'emu' / 'flycast-build' / 'data'
GD = REPO / 'extract' / 'analysis' / 'gd_state'
ROMDIR = REPO / 'rom'
EXE = (REPO / 'extract' / 'exe' / '1ST_READ.unsc.bin').read_bytes()


def load_gdi():
    lines = (ROMDIR / 'vf3.gdi').read_text().splitlines()[1:]
    tracks = []
    for ln in lines:
        p = ln.replace('"', '|').split('|')
        a = p[0].split()
        tracks.append(dict(start=int(a[1]), ctrl=int(a[2]), size=int(a[3]), file=ROMDIR / p[1], off=int(p[2])))
    return tracks


def read_sector(tracks, fad):
    t = max((t for t in tracks if t['start'] <= fad), key=lambda t: t['start'])
    pos = (fad - t['start']) * t['size'] + t['off'] + (16 if t['size'] == 2352 else 0)
    with open(t['file'], 'rb') as f:
        f.seek(pos)
        return f.read(2048)


def inflate_state(path):
    d = path.read_bytes()
    assert d[0x18:0x20] == b'#RZIPv\x01#'
    total = struct.unpack_from('<Q', d, 0x24)[0]
    pos, out = 0x2C, bytearray()
    while pos + 4 <= len(d) and len(out) < total:
        n = struct.unpack_from('<I', d, pos)[0]
        out += zlib.decompress(d[pos + 4:pos + 4 + n])
        pos += 4 + n
    return bytes(out)


def main() -> int:
    tracks = load_gdi()
    for n in sys.argv[1:]:
        g = dict(l.split() for l in (GD / f'vf3_{n}.txt').read_text().splitlines())
        fad, cnt, dest = int(g['params0'], 16) & 0xFFFFFF, int(g['params1'], 16), int(g['params2'], 16)
        done = int(g['result2'], 16) // 2048
        ram = inflate_state(DATA / f'vf3_{n}.state')
        # the blob is not a flat RAM image; locate the transfer by the data itself. A transferred sector may
        # have been consumed (overwritten) by the loader since, so report how many survive at one common base.
        d0 = dest & 0x00FFFFFF
        sig = [read_sector(tracks, fad + i)[100:164] for i in range(min(done, 24))]
        bases = {}
        for i, sg in enumerate(sig):
            start = 0
            while True:
                h = ram.find(sg, start)
                if h < 0:
                    break
                bases[h - 100 - 2048 * i - d0] = bases.get(h - 100 - 2048 * i - d0, 0) + 1
                start = h + 1
        best = max(bases.items(), key=lambda kv: kv[1]) if bases else (0, 0)
        print(f'state {n}: fad {fad:#x} count {cnt:#x} done {done:#x} dest {dest:#x}: '
              f'{best[1]}/{len(sig)} transferred sectors found at one common RAM base ({best[0]:#x})'
              + ('' if best[1] else ' - consumed by the loader since'))
    return 0


if __name__ == '__main__':
    sys.exit(main())
