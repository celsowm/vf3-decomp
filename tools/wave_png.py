#!/usr/bin/env python3
"""Render a WAV file's waveform to PNG (call after adpcm_decode)."""
import struct
import sys
import wave
import zlib

def png_write(path, w, h, pix):  # pix: rows of bytes RGB
    def chunk(typ, data):
        c = struct.pack(">I", len(data)) + typ + data
        return c + struct.pack(">I", zlib.crc32(typ + data) & 0xFFFFFFFF)
    hdr = struct.pack(">IIBBBBB", w, h, 8, 2, 0, 0, 0)
    raw = b"".join(b"\x00" + row for row in pix)
    open(path, "wb").write(
        b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR", hdr)
        + chunk(b"IDAT", zlib.compress(raw, 9)) + chunk(b"IEND", b""))

def main():
    wav, out = sys.argv[1], sys.argv[2]
    w = wave.open(wav)
    raw = w.readframes(w.getnframes())
    s = struct.unpack("<%dh" % (len(raw) // 2), raw)
    W, H = 1600, 400
    step = max(1, len(s) // W)
    pix = [[24, 24, 28] * W for _ in range(H)]  # dark bg
    cols = []
    mid = H // 2
    sc = H // 2 - 8
    for x in range(W):
        seg = s[x * step:(x + 1) * step]
        if not seg:
            cols.append((0, 0))
            continue
        lo, hi = min(seg), max(seg)
        ya = mid - int((hi / 32768.0) * sc)
        yb = mid - int((lo / 32768.0) * sc)
        cols.append((ya, yb))
    for yy in range(H):
        row = bytearray()
        for x in range(W):
            lo, hi = cols[x]
            if lo <= yy <= hi:
                row += bytes((90, 220, 90))
            else:
                bg = 24 + (yy % 2) * 4
                row += bytes((bg, bg, bg + 4))
        pix[yy] = bytes(row)
    png_write(out, W, H, pix)
    print("wrote", out, "samples:", len(s), "colStep:", step)

if __name__ == "__main__":
    main()
