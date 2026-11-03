#!/usr/bin/env python3
"""Dump native's store trace (build/native_trace.bin) around the melody burst
(samples 3536..3560) the same way we read the reference, to compare what the
firmware executes between melody key-ons in native vs reference."""
import struct

p = 'build/native_trace.bin'
d = open(p, 'rb').read()
n = len(d) // 40
recs = []
for i in range(n):
    s, at, v, sz, pcv = struct.unpack_from('<QQQQQ', d, i * 40)
    a = at & 0x7fffffff
    isram = (at >> 63) == 0
    if not isram:
        continue
    recs.append((int(s), pcv, a, v))
recs.sort()

for s, pcv, a, v in recs:
    if 3530 <= s <= 3570:
        note = '' 
        print('sample %5d pc %04x a %06x v %06x%s' % (s, pcv, a & 0xffffff, v & 0xffffff, note))
