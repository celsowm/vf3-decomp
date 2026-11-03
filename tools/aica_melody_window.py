#!/usr/bin/env python3
"""Dump the reference ARM trace records around the melody key-on burst, so we
can see what the firmware executes BETWEEN successive melody key-ons (what
paces them)."""
import struct

p = 'extract/analysis/audio_arm_observer_v4/vf3_28_traced.arm'
d = open(p, 'rb').read()
n = (len(d) - 8) // 40

# all key-ons (pc 0x264c)
keys = []
for i in range(n):
    seq, cyc, pcv, op, addr, val, sz, st = struct.unpack_from('<QQ6I', d, 8 + i * 40)
    if pcv == 0x264c:
        keys.append((seq, cyc))
print('melody key-on records at seq:', [k[0] for k in keys[:10]])

# dump the window around the first 6 melody key-ons
first_seq = keys[0][0]
for i in range(first_seq - 40, first_seq + 200):
    if i >= n:
        break
    seq, cyc, pcv, op, addr, val, sz, st = struct.unpack_from('<QQ6I', d, 8 + i * 40)
    note = '  <KEY' if pcv == 0x264c else ''
    print('seq %6d c%9d pc %04x a %06x v %06x%s' %
          (seq, cyc // 4535, pcv, addr & 0xffffff, val & 0xffffff, note))
