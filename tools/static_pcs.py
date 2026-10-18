#!/usr/bin/env python3
"""static_pcs.py - TICK_PCS-format dump of the code reachable from seed addresses (no oracle run needed).

  python tools/static_pcs.py --edges extract/analysis/p4 --out extract/analysis/tick_static_boot_pcs.txt
  python tools/static_pcs.py --seed 0x8c0c5c3a --out x.txt

A seed is a place where the native run enters code that no adapter owns: a call target, or the address a
returning function hands control back to (a frame that was already live when the capture began). The walk
is a recursive descent over the identity image: conditional branches both ways, bra followed, calls
(bsr/jsr/bsrf) continue after their delay slot, rts/rte/jmp/braf end a path. Callee bodies are not walked
(a call target is its own seed). Register-indirect jmp/braf are not resolved here; tools/braf_tables.py
rows are added as `ind` lines when --braf is given. The output feeds tools/recomp/regen_tickgap.sh, which
subtracts what already has an adapter label. Over-approximate by design: an unexecuted path costs a few
adapter labels, never a wrong answer, because the translator fails closed on what it cannot translate.
"""
import argparse
import csv
import glob
import re
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
BASE = 0x0C010000


def s(v, bits):
    return v - (1 << bits) if v & (1 << (bits - 1)) else v


def walk(image, seeds, limit=400000):
    seen, work = set(), [x & 0x1FFFFFFF for x in seeds]
    while work and len(seen) < limit:
        pc = work.pop()
        while True:
            off = pc - BASE
            if pc & 1 or off < 0 or off + 2 > len(image) or pc in seen:
                break
            op = struct.unpack_from('<H', image, off)[0]
            seen.add(pc)
            hi = op >> 12
            delay = False
            stop = False
            if op == 0x000B or op == 0x002B:            # rts, rte
                delay, stop = True, True
            elif hi == 0x4 and (op & 0xF0FF) in (0x402B,):    # jmp @Rn
                delay, stop = True, True
            elif hi == 0x4 and (op & 0xF0FF) == 0x400B:       # jsr @Rn
                delay = True
            elif hi == 0x0 and (op & 0xF0FF) == 0x0023:       # braf Rn
                delay, stop = True, True
            elif hi == 0x0 and (op & 0xF0FF) == 0x0003:       # bsrf Rn
                delay = True
            elif hi == 0xA:                                     # bra
                tgt = pc + 4 + 2 * s(op & 0xFFF, 12)
                work.append(tgt)
                delay, stop = True, True
            elif hi == 0xB:                                     # bsr
                delay = True
            elif (op & 0xFF00) in (0x8900, 0x8B00):           # bt, bf
                work.append(pc + 4 + 2 * s(op & 0xFF, 8))
            elif (op & 0xFF00) in (0x8D00, 0x8F00):           # bt/s, bf/s
                work.append(pc + 4 + 2 * s(op & 0xFF, 8))
                delay = True
            if delay:
                if pc + 2 - BASE + 2 <= len(image):
                    seen.add(pc + 2)
                pc += 4
                if stop:
                    break
                continue
            if stop:
                break
            pc += 2
    return seen


def owned_labels():
    pat = re.compile(r'^P_([0-9a-f]{8}):', re.M)
    owned = set()
    for p in (ROOT / 'src').rglob('*.c'):
        if p.name == 'tickgap_adapters.c':   # the module this dump regenerates: its own labels do not count as owned
            continue
        owned.update(int(a, 16) for a in pat.findall(p.read_text(encoding='ascii', errors='ignore')))
    return owned


def edge_seeds(edge_dir, owned):
    seeds = set()
    for f in glob.glob(str(Path(edge_dir) / 'e*.bin')):
        d = Path(f).read_bytes()
        for i in range(0, len(d), 16):
            kind, _frm, to, _depth = struct.unpack_from('<IIII', d, i)
            t = to & 0x1FFFFFFF
            if BASE <= t < 0x0D000000 and t not in owned:
                seeds.add(t)
    return sorted(seeds)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--seed', action='append', default=[], help='extra seed address')
    ap.add_argument('--seed-file', help='text file, one seed address per line (# comments)')
    ap.add_argument('--edges', help='directory of e<N>.bin edge logs; every unowned call/return target is a seed')
    ap.add_argument('--braf', help='braf_tables.csv: add resolved targets of reached jump sites')
    ap.add_argument('--is-entry', help='print 1 when the address follows a function end (rts/rte/jmp/bra + delay slot), else 0')
    ap.add_argument('--out')
    a = ap.parse_args()
    if a.is_entry:
        img = (ROOT / 'extract/exe/1ST_READ.unsc.bin').read_bytes()
        pc = int(a.is_entry, 0) & 0x1FFFFFFF
        op = struct.unpack_from('<H', img, pc - 4 - BASE)[0] if pc - 4 >= BASE else 0
        print(1 if op in (0x000B, 0x002B) or (op & 0xF0FF) == 0x402B or (op >> 12) == 0xA else 0)
        return
    image = (ROOT / 'extract/exe/1ST_READ.unsc.bin').read_bytes()
    owned = owned_labels()
    seeds = [int(x, 0) for x in a.seed]
    if a.seed_file and Path(a.seed_file).exists():
        for line in Path(a.seed_file).read_text().splitlines():
            line = line.split('#')[0].strip()
            if line:
                seeds.append(int(line, 0))
    if a.edges:
        seeds += edge_seeds(a.edges, owned)
    seeds = [x for x in seeds if (x & 0x1FFFFFFF) not in owned]
    pcs = walk(image, seeds)
    ind = {}
    if a.braf:
        for row in csv.DictReader(open(a.braf)):
            try:
                site = int(row.get('site', row.get('pc', '0')), 16) & 0x1FFFFFFF
                tg = [int(x, 16) & 0x1FFFFFFF for x in row.get('targets', '').split() if x]
            except ValueError:
                continue
            if site in pcs and tg:
                ind[site] = tg
    with open(a.out, 'w', newline='\n') as out:
        for p in sorted(pcs):
            out.write(f'pc {p:08x}\n')
        for site, tg in sorted(ind.items()):
            out.write(f'ind {site:08x} ' + ' '.join(f'{t:08x}' for t in tg) + '\n')
    unowned = [p for p in pcs if p not in owned]
    print(f'{len(seeds)} unowned seeds, {len(pcs)} instructions reached, {len(unowned)} without an adapter label -> {a.out}')


if __name__ == '__main__':
    main()
