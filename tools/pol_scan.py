#!/usr/bin/env python3
"""Find contiguous float-vector blocks in POL files and render point clouds.

Heuristic: u32 dwords that decode as IEEE floats in a sane range and align as
xyz (each rk triple in [-8,8]) form vertex data; image-space XY projection
renders them to a PNG for visual validation of a foot/limb silhouette.
"""
import os
import struct
import sys
import zlib

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def scan_float_blocks(data, min_len=64):
    """Return list of (offset, float triple count)."""
    n = len(data)
    blocks = []
    i = 0
    while i + 12 <= n:
        # read as 3 floats
        a, b, c = struct.unpack_from("<fff", data, i)
        if (-8 <= a <= 8 and -8 <= b <= 8 and -8 <= c <= 8
                and (a != 0.0 or b != 0.0 or c != 0.0)):
            j = i
            cnt = 0
            while j + 12 <= n:
                a, b, c = struct.unpack_from("<fff", data, j)
                if not (-8 <= a <= 8 and -8 <= b <= 8 and -8 <= c <= 8):
                    break
                j += 12
                cnt += 1
            if cnt >= min_len:
                blocks.append((i, cnt))
                i = j
        i += 4
    return blocks


def png(path, w, h, pix):
    def chunk(typ, d):
        c = struct.pack(">I", len(d)) + typ + d
        return c + struct.pack(">I", zlib.crc32(typ + d) & 0xFFFFFFFF)
    hdr = struct.pack(">IIBBBBB", w, h, 8, 2, 0, 0, 0)
    raw = b"".join(b"\x00" + b"".join(bytes(x) for x in row) for row in pix)
    open(path, "wb").write(b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR", hdr) +
                           chunk(b"IDAT", zlib.compress(raw, 9)) +
                           chunk(b"IEND", b""))


def render(proj, out, w=640, h=640):
    pix = [[(16, 16, 20) for _ in range(w)] for _ in range(h)]
    xs = [p[0] for p in proj]
    ys = [p[1] for p in proj]
    if not xs:
        return
    x0, x1 = min(xs), max(xs)
    y0, y1 = min(ys), max(ys)
    span = max(x1 - x0, y1 - y0, 1e-6)
    pad = 20
    for x, y in proj:
        px = pad + int((x - x0) / span * (w - 2 * pad))
        py = pad + int((y - y0) / span * (h - 2 * pad))
        pix[py][px] = (220, 240, 255)
        for dx, dy in ((1, 0), (0, 1), (-1, 0), (0, -1)):
            if 0 <= px + dx < w and 0 <= py + dy < h:
                pix[py + dy][px + dx] = (140, 170, 200)
    png(out, w, h, pix)


def main():
    path = sys.argv[1]
    out = sys.argv[2]
    if not os.path.exists(path):
        print("not found:", path)
        return
    data = open(path, "rb").read()
    blocks = scan_float_blocks(data)
    print(f"{os.path.basename(path)}: {len(blocks)} float blocks")
    tot = 0
    pts3 = []
    for off, cnt in blocks:
        print(f"  @0x{off:06X} {cnt:5d} triples")
        tot += cnt
        for k in range(cnt):
            pts3.append(struct.unpack_from("<fff", data, off + k * 12))
    print(f"  total points: {tot}")
    render([(x, y) for x, y, z in pts3], out)
    print("wrote", out)


if __name__ == "__main__":
    main()
