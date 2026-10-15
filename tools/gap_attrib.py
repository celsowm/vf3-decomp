#!/usr/bin/env python3
"""gap_attrib.py - attribute uncatalogued executed code (census gap runs) to
its owning function by static control flow.

Input : extract/analysis/census/hits_<trace>.npy (from exec_census.py)
Method: decode every PC-relative branch in the image (bra/bt/bf/bt/s/bf/s;
        bsr is a CALL = new function entry, not an extent). A gap slot whose
        local-branch predecessor lies in a baseline function (or in an already
        attributed gap slot) belongs to that function ('extent'). Remaining
        gap slots that are bsr targets or literal-pool/table pointers are new
        function ENTRIES; the rest are 'orphan' (dynamic, e.g. dispatch table
        fall-ins) and are listed for manual review.
Output: extract/analysis/census/gap_attrib.csv  (slot_addr,kind,owner)
        extract/analysis/census/funcs_extended2.csv (owner,entry,size[,kind])
        and a summary on stdout.

Usage: python tools/gap_attrib.py trace_fight1 [trace_melee ...]
"""
from __future__ import annotations

import csv
import sys
from collections import Counter, defaultdict
from pathlib import Path

import numpy as np

REPO = Path(__file__).resolve().parent.parent
AN = REPO / 'extract' / 'analysis'
OUT = AN / 'census'
BASE = 0x8C010000
SZ = 0x100000
SLOTS = SZ // 2


def main() -> int:
    stems = sys.argv[1:] or ['trace_fight1']
    hits = np.zeros(SLOTS, np.int64)
    for s in stems:
        hits += np.load(OUT / f'hits_{s}.npy')
    img = (AN.parent / 'exe' / '1ST_READ.unsc.bin').read_bytes()
    n = len(img) // 2
    w = np.frombuffer(img[: n * 2], dtype='<u2').astype(np.int64)

    base = []
    for r in csv.DictReader(open(AN / 'funcs_1ST_READ.unsc.bin.csv', newline='')):
        e = int(r['entry'], 16); sz = int(r['size'])
        if sz > 0:
            base.append((e, sz))
    base.sort()
    owner = np.full(SLOTS, -1, np.int32)
    for i, (e, sz) in enumerate(base):
        owner[(e - BASE) // 2:(e + sz - BASE + 1) // 2] = i
    seen = np.zeros(SLOTS, bool)
    seen[:] = hits > 0

    # --- decode branches ---------------------------------------------------
    pos = np.arange(n, dtype=np.int64)
    hi4 = w >> 12
    hi8 = w >> 8
    disp8 = ((w & 0xFF) ^ 0x80) - 0x80
    disp12 = ((w & 0xFFF) ^ 0x800) - 0x800
    is_bra = hi4 == 0xA
    is_bsr = hi4 == 0xB
    is_cb = (hi8 == 0x89) | (hi8 == 0x8B) | (hi8 == 0x8D) | (hi8 == 0x8F)
    tgt_local = np.where(is_bra, pos + 2 + disp12, np.where(is_cb, pos + 2 + disp8, -1))
    tgt_call = np.where(is_bsr, pos + 2 + disp12, -1)
    lb = np.nonzero(tgt_local >= 0)[0]
    pred = defaultdict(list)
    for s in lb:
        t = int(tgt_local[s])
        if 0 <= t < n:
            pred[t].append(int(s))
    callt = set(int(t) for t in tgt_call[tgt_call >= 0] if 0 <= t < n)

    # literal-pool / table pointers into the image (32-bit aligned words)
    dw = np.frombuffer(img[: len(img) // 4 * 4], dtype='<u4')
    ptr = dw[(dw >= BASE) & (dw < BASE + len(img))]
    ptr = (ptr.astype(np.int64) & ~1)
    ptrset = set(int((p - BASE) // 2) for p in ptr)

    gap = seen & (owner < 0)
    attrib = {}  # slot -> ('extent', owner idx) | ('entry',) | ('orphan',)
    own = owner.copy()
    gslots = set(int(x) for x in np.nonzero(gap)[0])
    changed = True
    while changed:
        changed = False
        for s in sorted(gslots):
            if s in attrib:
                continue
            for src in pred.get(s, ()):
                if src < SLOTS and own[src] >= 0 and seen[src]:
                    attrib[s] = ('extent', int(own[src]))
                    own[s] = own[src]
                    changed = True
                    break
    # fall-through: gap slot right after an owned executed slot that is not
    # an unconditional transfer / delay slot end
    changed = True
    while changed:
        changed = False
        for s in sorted(gslots):
            if s in attrib or s == 0:
                continue
            p = s - 1
            if p in gslots or own[p] >= 0:
                if own[p] >= 0 and seen[p]:
                    prev = int(w[p]); prev2 = int(w[p - 1]) if p else 0
                    # previous op ends flow: rts delay slot / bra delay slot
                    uncond = (prev == 0x000B) or ((prev2 >> 12) == 0xA) or (prev2 == 0x000B)
                    if not uncond:
                        attrib[s] = ('extent', int(own[p])); own[s] = own[p]; changed = True
    for s in sorted(gslots):
        if s in attrib:
            continue
        if s in callt or s in ptrset:
            attrib[s] = ('entry', -1)
        else:
            attrib[s] = ('orphan', -1)

    c = Counter(); hc = Counter()
    for s, a in attrib.items():
        c[a[0]] += 1; hc[a[0]] += int(hits[s])
    tot = int(hits.sum())
    print(f'gap executed slots: {len(gslots)}  hits {int(hits[gap].sum()):,} / {tot:,}')
    for k in ('extent', 'entry', 'orphan'):
        print(f'  {k:7s} slots={c[k]:6d}  hits={hc[k]:>13,} ({100*hc[k]/tot:5.1f}%)')

    OUT.mkdir(parents=True, exist_ok=True)
    with open(OUT / 'gap_attrib.csv', 'w', newline='') as f:
        wr = csv.writer(f)
        wr.writerow(['slot_addr', 'kind', 'owner_entry', 'hits'])
        for s in sorted(attrib):
            k, o = attrib[s]
            wr.writerow([f'0x{BASE + s*2:08x}', k,
                         f'0x{base[o][0]:08x}' if o >= 0 else '', int(hits[s])])
    # extents per owning baseline function
    ext = defaultdict(list)
    for s, (k, o) in attrib.items():
        if k == 'extent':
            ext[o].append(s)
    rows = []
    for o, ss in ext.items():
        rows.append((base[o][0], base[o][1], len(ss), sum(int(hits[x]) for x in ss),
                     BASE + min(ss) * 2, BASE + max(ss) * 2 + 2))
    rows.sort(key=lambda r: -r[3])
    with open(OUT / 'funcs_extended2.csv', 'w', newline='') as f:
        wr = csv.writer(f)
        wr.writerow(['owner', 'owner_size', 'extra_slots', 'hits', 'lo', 'hi'])
        for r in rows:
            wr.writerow([f'0x{r[0]:08x}', r[1], r[2], r[3], f'0x{r[4]:08x}', f'0x{r[5]:08x}'])
    print('top owners with executed extents beyond their baseline body:')
    for r in rows[:12]:
        print(f'  0x{r[0]:08x} size={r[1]:5d} +{r[2]*2:5d}B hits={r[3]:>12,} span 0x{r[4]:08x}-0x{r[5]:08x}')
    # per-run verdict (runs = gap slots <=16 slots apart)
    sl = sorted(attrib)
    runs = []
    for x in sl:
        if runs and x - runs[-1][-1] <= 16: runs[-1].append(x)
        else: runs.append([x])
    verdict = Counter(); vh = Counter(); vb = Counter()
    run_rows = []
    for r in runs:
        ks = {attrib[x][0] for x in r}
        stub = all(int(w[x]) in (0x000B, 0x0009) for x in r)
        v = 'stub' if stub else 'extent' if 'extent' in ks else 'new-entry' if 'entry' in ks else 'orphan-only'
        h = sum(int(hits[x]) for x in r)
        verdict[v] += 1; vh[v] += h; vb[v] += (r[-1] - r[0] + 1) * 2
        run_rows.append((BASE + r[0] * 2, (r[-1] - r[0] + 1) * 2, v, h))
    print('per-run verdicts (runs, span B, hits):')
    for v in verdict:
        print(f'  {v:12s} runs={verdict[v]:5d} span={vb[v]:6d}B hits={vh[v]:>13,} ({100*vh[v]/tot:5.1f}%)')
    with open(OUT / 'gap_runs.csv', 'w', newline='') as f:
        wr = csv.writer(f); wr.writerow(['entry', 'span', 'verdict', 'hits'])
        for r in sorted(run_rows, key=lambda r: -r[3]):
            wr.writerow([f'0x{r[0]:08x}', r[1], r[2], r[3]])
    orph = sorted(((int(hits[s]), s) for s, a in attrib.items() if a[0] == 'orphan'), reverse=True)
    print('top orphan slots:')
    for h, s in orph[:10]:
        print(f'  0x{BASE+s*2:08x} hits={h:,}')
    ent = sorted(((int(hits[s]), s) for s, a in attrib.items() if a[0] == 'entry'), reverse=True)
    print('top new entries:')
    for h, s in ent[:10]:
        print(f'  0x{BASE+s*2:08x} hits={h:,}')
    return 0


if __name__ == '__main__':
    sys.exit(main())
