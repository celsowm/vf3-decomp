#!/usr/bin/env python3
"""readable_ledger.py - the `readable` ledger: which entries have a hand-written C port.

Reads the registry in src/fight/readable.c and the oracle's per-entry census
(extract/analysis/fxr_tick_s7_stats.csv: entry,calls,self_steps,writes) and writes
docs/readable_status.csv:

  entry,name,file,out_regs,calls_s7,self_steps_s7,pct_of_tick_s7

Coverage in docs/decomp_status.csv is a different question (verified C of any style,
measured by replay) and is never edited from here.

  python tools/recomp/readable_ledger.py          # rewrite docs/readable_status.csv
"""
import csv
import re
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent.parent
TABLE = REPO / 'src' / 'fight' / 'readable.c'
STATS = REPO / 'extract' / 'analysis' / 'fxr_tick_s7_stats.csv'
OUT = REPO / 'docs' / 'readable_status.csv'

ROW = re.compile(r'\{\s*(0x[0-9a-fA-F]+)u,\s*"([^"]+)",\s*(\w+),\s*(.*?)\s*\}\s*,', re.S)


def mask_bits(expr):
    """Registers named in an out_regs expression like B(0) | FR(14) | B(16)."""
    regs = []
    for kind, n in re.findall(r'\b(B|FR)\((\d+)\)', expr):
        n = int(n)
        regs.append(n if kind == 'B' else 21 + n)
    return regs


def reg_name(i):
    names = {16: 'pr', 17: 'sr', 18: 'fpscr', 19: 'macl', 20: 'mach', 53: 'fpul'}
    if i in names:
        return names[i]
    return f'r{i}' if i < 16 else f'fr{i - 21}'


def source_of(fn):
    for path in sorted((REPO / 'src' / 'fight').glob('*.c')):
        if re.search(r'^int\s+' + re.escape(fn) + r'\s*\([^;{]*\)\s*\{', path.read_text(errors='replace'), re.M):
            return path.relative_to(REPO).as_posix()
    return ''


def main():
    text = TABLE.read_text()
    text = text[text.index('vf3_readable_table[]'):]
    census = {}
    total = 0
    if STATS.exists():
        for row in csv.DictReader(STATS.open()):
            census[int(row['entry'], 16)] = (int(row['calls']), int(row['self_steps']))
            total += int(row['self_steps'])
    rows = []
    for entry, name, fn, mask in ROW.findall(text):
        e = int(entry, 16)
        calls, steps = census.get(e, (0, 0))
        # the scheduler is the tick's root: the harness enters it, no oracle record calls it
        verified = 'whole-tick' if calls or name == 'task_sched' else 'unexercised'
        rows.append([f'0x{e | 0x80000000:08x}', name, source_of(fn),
                     ' '.join(reg_name(i) for i in sorted(set(mask_bits(mask)))),
                     calls, steps, f'{100.0 * steps / total:.2f}' if total else '', verified])
    rows.sort(key=lambda r: -r[5])
    with OUT.open('w', newline='') as f:
        w = csv.writer(f, lineterminator='\n')
        w.writerow(['entry', 'name', 'file', 'out_regs', 'calls_s7', 'self_steps_s7', 'pct_of_tick_s7', 'verified'])
        w.writerows(rows)
    covered = sum(r[5] for r in rows)
    print(f'{len(rows)} readable entries; {covered} of {total} oracle self steps '
          f'({100.0 * covered / total:.1f}%) in state vf3_7' if total else f'{len(rows)} readable entries')


if __name__ == '__main__':
    main()
