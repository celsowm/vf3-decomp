#!/usr/bin/env python3
"""Generate the compact FSCA coefficient ROM from exhaustive opcode output."""
import argparse
import hashlib
import json
from pathlib import Path
import struct

def generate(path,out):
    raw=Path(path).read_bytes()
    if len(raw)!=65536*8:
        raise ValueError("Need all 65536 sine/cosine pairs")
    pairs=list(struct.iter_unpack("<2I",raw))
    half=[p[0] for p in pairs[:32768]]
    def sine(a):
        return half[a&32767] ^ ((a&32768)<<16)
    for a,(s,c) in enumerate(pairs):
        if (s,c)!=(sine(a),sine((a+16384)&65535)):
            raise ValueError(f"ROM symmetry differs at angle {a}")
    lines=["/* Exhaustive FSCA opcode experiment; see docs/re/batch_pipeline.md.",
           f" * SHA256 of 65536 raw pairs: {hashlib.sha256(raw).hexdigest()} */"]
    lines.extend(", ".join(f"0x{x:08X}u" for x in half[i:i+8])+"," for i in range(0,32768,8))
    Path(out).write_text("\n".join(lines)+"\n",encoding="ascii")
    report={"angles":65536,"bytes":len(raw),"sha256":hashlib.sha256(raw).hexdigest(),"source":"isolated Flycast interpreter FSCA opcode execution"}
    Path(str(path)+".json").write_text(json.dumps(report,indent=1))
    print(json.dumps(report))

if __name__=="__main__":
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument("input"); ap.add_argument("--out",default="src/fight/sh4_sine.inc")
    a=ap.parse_args(); generate(a.input,a.out)
