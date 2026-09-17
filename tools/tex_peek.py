#!/usr/bin/env python3
"""Try decoding VF3 .TEX assets as raw PVR images; write 24-bit BMPs for
visual verification.

Guesses tried: RGB565 / RGBA5551 / paletted8 (against companion .POL table
palette?) in plain row order and PVR twiddle (Morton) order.
"""
import os
import struct
import zlib


def write_png(path, w, h, rgb):
    def chunk(tag, payload):
        c = struct.pack(">I", len(payload)) + tag + payload
        c += struct.pack(">I", zlib.crc32(tag + payload) & 0xFFFFFFFF)
        return c
    raw = b"".join(b"\x00" + rgb[y * w * 3:(y + 1) * w * 3] for y in range(h))
    png = (b"\x89PNG\r\n\x1a\n"
           + chunk(b"IHDR", struct.pack(">IIBBBBB", w, h, 8, 2, 0, 0, 0))
           + chunk(b"IDAT", zlib.compress(raw, 6))
           + chunk(b"IEND", b""))
    with open(path, "wb") as f:
        f.write(png)

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GD = os.path.join(REPO, "extract", "gamedata")
OUT = os.path.join(REPO, "extract", "assets", "tex")


def write_bmp(path, w, h, rgb_bytes):
    row_size = (w * 3 + 3) & ~3
    img_size = row_size * h
    header = b"BM" + struct.pack("<6I", 54 + img_size, 0, 0, 54, 40,
                                 w)
    header += struct.pack("<i", -h)  # top-down
    header += struct.pack("<6I", h if False else 24, 0, img_size, 2835, 2835, 0)
    with open(path, "wb") as f:
        f.write(header)
        f.write(rgb_bytes)


def rgb565_to_rgb(data, w, h):
    out = bytearray()
    for i in range(w * h):
        p = struct.unpack_from("<H", data, i * 2)[0]
        r = ((p >> 11) & 31) << 3 | ((p >> 11) & 31) >> 2
        g = ((p >> 5) & 63) << 2 | ((p >> 5) & 63) >> 4
        b = (p & 31) << 3 | (p & 31) >> 2
        out += bytes((b, g, r))
    return bytes(out)


def rgba5551_to_rgb(data, w, h):
    out = bytearray()
    for i in range(w * h):
        p = struct.unpack_from("<H", data, i * 2)[0]
        r = ((p >> 11) & 31) << 3 | ((p >> 11) & 31) >> 2
        g = ((p >> 6) & 31) << 3 | ((p >> 6) & 31) >> 2
        b = (p & 31) << 3 | (p & 31) >> 2
        out += bytes((b, g, r))
    return bytes(out)


def detwiddle(data, w, h, bpp=2):
    tw = bytearray(len(data))
    ofs = 0
    wlog, hlog = w.bit_length() - 1, h.bit_length() - 1
    for y in range(h):
        for x in range(w):
            tw_idx = 0
            for b in range(hlog):
                tw_idx |= ((y >> b) & 1) << (2 * b + 1)
            for b in range(wlog):
                tw_idx |= ((x >> b) & 1) << (2 * b)
            src = tw_idx * bpp
            if src + bpp <= len(data):
                tw[ofs:ofs + bpp] = data[src:src + bpp]
            ofs += bpp
    return bytes(tw)


def try_tex(path, w, h, mode, twiddle=False):
    data = open(path, "rb").read()
    if len(data) < w * h * 2:
        return None
    body = data[: w * h * 2]
    if twiddle:
        body = detwiddle(body, w, h)
    rgb = rgb565_to_rgb(body, w, h) if mode == "565" else rgba5551_to_rgb(body, w, h)
    return rgb


def main():
    os.makedirs(OUT, exist_ok=True)
    trials = [
        ("ROB_ALP.TEX", 32, 32),
        ("MKAO_AKI.TEX", 256, 512),
        ("MKAO_AKI.TEX", 512, 512),
        ("MKAO_AKI.TEX", 256, 1024),
    ]
    for fn, w, h in trials:
        for tw in (False, True):
            rgb = try_tex(os.path.join(GD, fn), w, h, "565", tw)
            if rgb:
                out = os.path.join(OUT, f"{fn.split('.')[0]}_{w}x{h}{'_tw' if tw else ''}.png")
                write_png(out, w, h, rgb)
                print("wrote", out)


if __name__ == "__main__":
    main()
