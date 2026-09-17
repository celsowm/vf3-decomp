#!/usr/bin/env python3
"""Decode the largest (audio) section of every DTPK package to WAV."""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import adpcm_decode as ad

SRC = r"E:\vf3-decomp\extract\dtpk"
OUT = r"E:\vf3-decomp\extract\assets\audio"


def main():
    os.makedirs(OUT, exist_ok=True)
    for pkg in sorted(os.listdir(SRC)):
        d = os.path.join(SRC, pkg)
        if not os.path.isdir(d):
            continue
        secs = [f for f in os.listdir(d) if f.startswith("sec")]
        if not secs:
            continue
        big = max(secs, key=lambda s: int(s.split("_")[2].split(".")[0], 16))
        raw = open(os.path.join(d, big), "rb").read()
        samples = ad.decode(raw)
        st = ad.stats(samples)
        ad.to_wav(os.path.join(OUT, pkg.lower() + ".wav"), samples, 22050)
        print(f"{pkg:18s} pay={len(raw)//1024:5d}KB zcr={st['zcr']:.3f} "
              f"rail={st['rail']:.3f} dur={len(samples)//22050}s")


if __name__ == "__main__":
    main()
