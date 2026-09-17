#!/usr/bin/env python3
"""AICA (Yamaha SCSP-derivative) 4-bit ADPCM decoder for VF3tb DTPK audio.

Algorithm 1:1 with MAME aica.cpp DecodeADPCM:
  x = (Quant * QMul[Delta & 7]) / 8;  if (Delta & 8) x = -x
  Signal = clip16(Signal + x)
  Quant  = clamp((Quant * TableQuant[Delta & 7]) >> 8, 0x7F, 0x6000)

Byte packing: LOW nibble first (curstep even -> shift 0), per MAME:
    shift1 = 4 & (curstep << 2)

Init: Signal = 0, Quant = 0x7F
"""
import math
import os
import struct
import sys
import wave

ADPCMSHIFT = 8


def _adfix(f):
    return int(f * (1 << ADPCMSHIFT))


TABLE_QUANT = [_adfix(0.8984375), _adfix(0.8984375), _adfix(0.8984375),
               _adfix(0.8984375), _adfix(1.19921875), _adfix(1.59765625),
               _adfix(2.0), _adfix(2.3984375)]
QUANT_MUL = [1, 3, 5, 7, 9, 11, 13, 15, -1, -3, -5, -7, -9, -11, -13, -15]


def decode(data, skip=0, max_n=None):
    signal = 0
    quant = 0x7F
    out = []
    cnt = 0
    for bi in range(skip, len(data)):
        b = data[bi]
        # low nibble first
        for nib in (b & 0xF, b >> 4):
            mul = QUANT_MUL[nib & 7 if False else nib]
            x = (quant * QUANT_MUL[nib]) >> 3
            signal += x
            if signal > 32767:
                signal = 32767
            elif signal < -32768:
                signal = -32768
            quant = (quant * TABLE_QUANT[nib & 7]) >> ADPCMSHIFT
            if quant < 0x7F:
                quant = 0x7F
            elif quant > 0x6000:
                quant = 0x6000
            out.append(signal)
            cnt += 1
            if max_n and cnt >= max_n:
                return out
    return out


def to_wav(path, samples, rate=22050):
    with wave.open(path, "wb") as w:
        w.setnchannels(1)
        w.setsampwidth(2)
        w.setframerate(rate)
        w.writeframes(struct.pack("<%dh" % len(samples), *samples))


def stats(samples):
    if not samples:
        return {}
    n = len(samples)
    rms = math.sqrt(sum(s * s for s in samples) / n)
    peak = max(abs(s) for s in samples)
    zc = sum(1 for a, b in zip(samples, samples[1:]) if (a >= 0) != (b >= 0))
    rail = sum(1 for s in samples if abs(s) > 30000) / n
    return dict(n=n, rms=int(rms), peak=peak, zcr=round(zc / n, 4),
                rail=round(rail, 3))


def main():
    payload_path = sys.argv[1]
    out_path = sys.argv[2]
    skip = int(sys.argv[3], 0) if len(sys.argv) > 3 else 0
    rate = int(sys.argv[4]) if len(sys.argv) > 4 else 22050
    os.makedirs(os.path.dirname(out_path), exist_ok=True)
    data = open(payload_path, "rb").read()
    samples = decode(data, skip)
    print("decoded:", stats(samples))
    to_wav(out_path, samples, rate)
    print("wrote", out_path)


if __name__ == "__main__":
    main()
