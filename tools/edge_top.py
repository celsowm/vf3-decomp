#!/usr/bin/env python3
"""edge_top.py - summarise a VF3_EDGES call-edge log (16-byte records: kind, caller_pc, target, depth).

  python tools/edge_top.py extract/analysis/p4/e2.bin [--depth 2] [--top 25]

Prints, for call edges up to --depth, how often each (caller -> target) pair fired. Used to find the per-frame
entry of a scene whose savestate never reaches the fight scheduler (0x8c09616a).
"""
import argparse
import collections
import struct

ap = argparse.ArgumentParser()
ap.add_argument('edges')
ap.add_argument('--depth', type=int, default=2)
ap.add_argument('--top', type=int, default=25)
a = ap.parse_args()
d = open(a.edges, 'rb').read()
n = len(d) // 16
cnt = collections.Counter()
for i in range(n):
    kind, caller, target, depth = struct.unpack_from('<4I', d, 16 * i)
    if kind == 0 and depth <= a.depth:
        cnt[(depth, caller, target)] += 1
print(f'{n} records')
for (depth, caller, target), c in sorted(cnt.items(), key=lambda kv: (kv[0][0], -kv[1]))[:a.top * (a.depth + 1)]:
    print(f'depth {depth} {caller:08x} -> {target:08x} x{c}')
