#!/usr/bin/env python3
"""Analyze the native executed-PC stream around the melody key-ons.

build/arm_seq.bin is a sequence of uint32 PCs (one per retired ARM instruction).
Find the melody key-ons (pc 0x264c) and print what the ARM executes BETWEEN
successive key-ons: is the gap a dense config burst (CPU-work spacing) or does
it contain a polling/wait loop on a device flag (a few PCs repeated many times)?
"""
import struct
from collections import Counter

p = 'build/arm_seq.bin'
d = open(p, 'rb').read()
n = len(d) // 4
pcs = struct.unpack('<%dI' % n, d)

# find key-on instructions
keys = [i for i, pc in enumerate(pcs) if pc == 0x264c]
print('total instructions:', n)
print('key-on (0x264c) at instr index:', keys[:12])
print('first key-on sample context: key-ons are ~at samples 3538-3552')


def pair_stat(a, b):
    """PC distribution and instruction span between instr indices [a, b)."""
    seg = pcs[a:b]
    span = b - a
    cnt = Counter(seg)
    top = cnt.most_common(12)
    print('  span %7d insns  unique_pc %d' % (span, len(cnt)))
    for pc, c in top:
        print('      %04x : %d' % (pc, c))


for i in range(min(3, len(keys) - 1)):
    a, b = keys[i], keys[i + 1]
    print('\n--- gap key-on #%d (instr %d) to key-on #%d (instr %d) ---' % (i + 1, a, i + 2, b))
    pair_stat(a, b)

# the whole band: from first to last key-on
print('\n--- full melody band: first..last key-on (%d insns) ---' % (keys[-1] - keys[0]))
pair_stat(keys[0], keys[-1])
