"""6f6f8 executed-path miner: FA30(entry)->FA32(exit) instr walk per call.

Seeks the 4GB instr trace (no full load). For the first K entries of
0x0C06F6F8, collects every instr pc in [0x0C06F6F8, 0x0C06FC00) until the
matching FA32 group, plus the exit rts pc (last in-range pc with op 0x000B).
Emits extract/analysis/ac6f6f8_paths.csv (call#, exit_rts, npcs, coverage...).
"""
import os
import struct
from collections import Counter

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TRACE = os.path.join(REPO, 'extract', 'analysis', 'golden_6f6f8instr_fight.bin')
OUT = os.path.join(REPO, 'extract', 'analysis', 'ac6f6f8_paths.csv')

ENTRY = 0x0C06F6F8
LO, HI = 0x0C06F6F8, 0x0C06FC00
FA30, FA32 = 0xFA30, 0xFA32
CHUNK = 1 << 26
MAXCALLS = 40


def scan_entries():
    offs = []
    with open(TRACE, 'rb') as f:
        base = 0
        while True:
            b = f.read(CHUNK)
            if not b:
                break
            # FA30 marker for ENTRY: u64 (ENTRY<<16)|FA30
            mark = struct.pack('<Q', (ENTRY << 16) | FA30)
            s = 0
            while True:
                i = b.find(mark, s)
                if i < 0:
                    break
                offs.append(base + i)
                if len(offs) >= 60000:
                    return offs
                s = i + 8
            base += len(b)
    return offs


def walk(f, off):
    pcs = []
    f.seek(off)
    for _ in range(300):  # 300*64 recs max per call
        raw = f.read(8 * 64)
        if len(raw) < 8:
            break
        for i in range(len(raw) // 8):
            v = struct.unpack('<Q', raw[8 * i:8 * i + 8])[0]
            op = v & 0xFFFF
            if op == FA32 and ((v >> 16) & 0xFFFFFFFF) == ENTRY and pcs:
                return pcs
            pc = (v >> 16) & 0xFFFFFFFF
            if LO <= pc < HI and op < 0xFA00:
                pcs.append((pc, op))
    return pcs


def main():
    entries = scan_entries()
    print('entries found:', len(entries))
    agg = Counter()
    exits = Counter()
    per = []
    with open(TRACE, 'rb') as f:
        for h in entries[:MAXCALLS]:
            pcs = walk(f, h)
            per.append(len(pcs))
            rts = [p for p, o in pcs if o == 0x000B]
            if rts:
                exits[rts[-1]] += 1
            agg.update(set(p for p, o in pcs))
    print('walked:', len(per), 'exit-rts:', [(hex(p), k) for p, k in exits.items()])
    print('body pcs covered:', len(agg), 'span:', hex(min(agg)), '..', hex(max(agg)))
    with open(OUT, 'w') as f:
        f.write('pc,hits\n')
        for pc in sorted(agg):
            f.write('%s,%d\n' % (hex(pc), agg[pc]))
    print('wrote', OUT)


if __name__ == '__main__':
    main()
