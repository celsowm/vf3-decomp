#!/usr/bin/env python3
"""Rank unported fight-tick entries by executed weight per instruction.

usage: tools/.venv/Scripts/python tools/rank_unported.py [--top N]
Weights come from extract/analysis/fxr_tick_s*_stats.csv (self steps summed over the captured states); an
entry counts as ported when src/fight/readable.c has a table row for it. Size is the instruction count up to
the first rts in sh4dump (200 max; '>' when none was found).
"""
import argparse, csv, glob, collections, re, subprocess, sys, os

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--top', type=int, default=60)
    a = ap.parse_args()
    own = set(re.findall(r'0x0c[0-9a-f]+(?=u,)', open('src/fight/readable.c').read()))
    tot = collections.Counter(); allsteps = 0
    for f in glob.glob('extract/analysis/fxr_tick_s*_stats.csv'):
        for r in csv.DictReader(open(f)):
            n = int(r['self_steps']); allsteps += n
            if r['entry'] not in own:
                tot[r['entry']] += n
    rows = []
    for e, n in tot.most_common(a.top):
        addr = '0x8c' + e[4:]
        lines = subprocess.run([sys.executable, 'tools/sh4dump.py', addr, '200'], capture_output=True, text=True).stdout.splitlines()
        size = next((i + 2 for i, l in enumerate(lines) if ' rts' in l), None)
        rows.append((e, n, size))
    rows.sort(key=lambda x: -(x[1] / (x[2] or 300)))
    print('unported %.2f%% of %d steps' % (100 * sum(tot.values()) / allsteps, allsteps))
    for e, n, size in rows:
        print('%s %7d %5.3f%%  insns %s' % (e, n, 100 * n / allsteps, size if size else '>200'))

if __name__ == '__main__':
    main()
