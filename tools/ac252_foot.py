"""AC252 executed-footprint extractor (trace_long.bin seeks, no full load).

Finds all 0x0C0AC252-prologue hits (op 0x4F22 sts.l pr,@-r15) and walks the
instr stream forward collecting body PCs until rts (0x000B) or range exit.
Emits: extract/analysis/ac252_footprint.csv (pc,hits,ncalls) + summary.

Usage: python3 tools/ac252_foot.py
"""
import os
import struct
from collections import Counter

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TRACE = os.path.join(REPO, 'extract', 'analysis', 'trace_long.bin')
OUT = os.path.join(REPO, 'extract', 'analysis', 'ac252_footprint.csv')

ENTRY = 0x0C0AC252
PROLOGUE_OP = 0x4F22
RANGE_LO, RANGE_HI = 0x0C0AC252, 0x0C0AD800
CORE = b'\x52\xC2\x0A\x0C\x00\x00'
CHUNK = 1 << 26


def find_hits():
    offs = []
    with open(TRACE, 'rb') as f:
        base = 0
        while True:
            b = f.read(CHUNK)
            if not b:
                break
            s = 0
            while True:
                i = b.find(CORE, s)
                if i < 0:
                    break
                rec = base + i - 2
                if rec >= 0:
                    v = struct.unpack_from('<Q', b, i - 2)[0] \
                        if i >= 2 else None
                    if v is not None and v & 0xFFFF == PROLOGUE_OP \
                            and ((v >> 16) & 0xFFFFFFFF) == ENTRY:
                        offs.append(rec)
                s = i + 1
            base += len(b)
    return offs


def walk(f, off):
    pcs = []
    f.seek(off)
    for _ in range(400):  # 400 recs per call max (3200 B stream)
        raw = f.read(8 * 64)
        if len(raw) < 8:
            break
        for i in range(len(raw) // 8):
            v = struct.unpack('<Q', raw[8 * i:8 * i + 8])[0]
            pc, op = (v >> 16) & 0xFFFFFFFF, v & 0xFFFF
            if op == 0x000B and pcs:  # rts ends this call
                return pcs
            if RANGE_LO <= pc < RANGE_HI:
                pcs.append(pc)
            elif pcs and len(pcs) > 4:
                # left range into a callee; stop (nested call, not our body)
                return pcs
        if pcs and pcs[-1] == pcs[-2] if len(pcs) > 1 else False:
            break
    return pcs


def main():
    hits = find_hits()
    print('prologue hits:', len(hits))
    agg = Counter()
    per_call = []
    with open(TRACE, 'rb') as f:
        for h in hits:
            pcs = walk(f, h)
            per_call.append(len(pcs))
            agg.update(set(pcs))
    print('calls walked:', len(per_call), 'body pcs covered:', len(agg))
    print('pcs/call min/med/max:',
          min(per_call), sorted(per_call)[len(per_call) // 2], max(per_call))
    lo = min(agg)
    with open(OUT, 'w') as f:
        f.write('pc,hits\n')
        for pc in sorted(agg):
            f.write('%s,%d\n' % (hex(pc), agg[pc]))
    print('body span:', hex(lo), '..', hex(max(agg)), 'wrote', OUT)


if __name__ == '__main__':
    main()
