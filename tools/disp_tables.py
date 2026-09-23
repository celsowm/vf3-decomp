#!/usr/bin/env python3
"""Resolve SH4 indirect-call literal pools.

Walks the disasm dump; for every `jsr @rN` / `jmp @rN`, backtracks up to 30
instructions for `mov.l @(disp,PC), rN` (EA = (PC & ~3) + 4 + disp*4), reads
the dword at that literal-pool slot from the original binary and records the
target. Output: dispatch_tables.csv — callsite,reg,literal_addr,target,kind.

Also emits `jsr_targets.csv`: unique targets with callsite count (the real
fight-band function heads hiding behind jsr @rN).
"""
import csv, re, struct, sys

DISASM = r'E:\vf3-decomp\extract\analysis\disasm_1ST_READ.unsc.bin.asm'
BIN = r'E:\vf3-decomp\extract\exe\1ST_READ.unsc.bin'
BASE = 0x8C010000

def load_disasm(path):
    rows = []
    for ln in open(path, encoding='utf-8', errors='replace'):
        parts = ln.rstrip('\n').split('\t')
        if len(parts) < 4:
            continue
        try:
            a = int(parts[0], 16)
        except ValueError:
            continue
        rows.append((a, parts[1].strip(), parts[2], parts[3]))
    return rows

def main():
    rows = load_disasm(DISASM)
    binimg = open(BIN, 'rb').read()

    def dword(addr):
        off = addr - BASE
        if 0 <= off <= len(binimg) - 4:
            return struct.unpack_from('<I', binimg, off)[0]
        return None

    # mov.l @(disp,PC),rN  pattern in normalized text: "mov.l 0x8cxxxxxx,rN"
    movel_pc = re.compile(r'^mov\.l 0x([0-9a-f]+),r(\d+)$')
    jsr_pat = re.compile(r'^(jsr|jmp) @r(\d+)$')

    out = []
    targets = {}
    for i, (a, raw, mne, txt) in enumerate(rows):
        m = jsr_pat.match(txt)
        if not m:
            continue
        kind, reg = m.group(1), int(m.group(2))
        lit_addr = None
        for j in range(i - 1, max(0, i - 30), -1):
            pa, praw, pmn, ptxt = rows[j]
            mm = movel_pc.match(ptxt)
            if mm and int(mm.group(2)) == reg:
                lit_addr = int(mm.group(1), 16)
                break
            # stop if the reg got overwritten by something else
            if re.search(rf',?r{reg}\b', ptxt) and not ptxt.startswith(f'mov'):
                break
            if pmn in ('jsr', 'jmp', 'bsr', 'bra', 'rts'):
                break
        if lit_addr is None:
            continue
        tgt = dword(lit_addr)
        # NAOMI-style physical pointers appear as 0x0cxxxxxx; normalize to 0x8c
        if tgt and 0x0C010000 <= tgt < 0x0C800000:
            tgt |= 0x80000000
        out.append((a, kind, reg, lit_addr, tgt))
        if tgt and 0x8C010000 <= tgt < 0x8C200000:
            targets[tgt] = targets.get(tgt, 0) + 1

    with open(r'E:\vf3-decomp\extract\analysis\dispatch_tables.csv', 'w', newline='') as f:
        w = csv.writer(f)
        w.writerow(['callsite', 'kind', 'reg', 'literal', 'target'])
        for a, kind, reg, lit, tgt in out:
            w.writerow([hex(a), kind, reg, hex(lit), hex(tgt) if tgt else ''])

    with open(r'E:\vf3-decomp\extract\analysis\jsr_targets.csv', 'w', newline='') as f:
        w = csv.writer(f)
        w.writerow(['target', 'refs'])
        for t, c in sorted(targets.items(), key=lambda kv: -kv[1]):
            w.writerow([hex(t), c])

    print(f'indirect sites resolved: {len(out)}, unique targets: {len(targets)}')
    bad = sum(1 for r in out if r[4] is None or not 0x8C010000 <= r[4] < 0x8C200000)
    print(f'suspicious targets: {bad}')

if __name__ == '__main__':
    main()
