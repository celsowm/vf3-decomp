#!/usr/bin/env python3
"""Decisive apples-to-apples comparison of ARM work rate:

Both the reference ARM trace (extract/.../vf3_28_traced.arm) and the native
run's write trace (build/native_trace.bin) log STORE instructions
(reference: every record is a store, st==1; native: RAM/reg writes).  Compare
stores per sample.  If native does ~20x the stores per sample, its ARM is
roughly 20x busier than the reference, which is what lets it fire the whole
6-note melody in 14 samples where the reference takes 98.
"""
import struct

# --- reference ---
p = 'extract/analysis/audio_arm_observer_v4/vf3_28_traced.arm'
d = open(p, 'rb').read()
n = (len(d) - 8) // 40
c0 = cl = None
for i in range(n):
    seq, cyc, pcv, op, addr, val, sz, st = struct.unpack_from('<QQ6I', d, 8 + i * 40)
    if c0 is None:
        c0 = cyc
    cl = cyc
samp = (cl - c0) / 4535.0
print('REFERENCE stores=%d samples=%.0f stores/sample=%.3f' % (n, samp, n / samp))

# --- native ---
d2 = open('build/native_trace.bin', 'rb').read()
n2 = len(d2) // 40
ram = reg = 0
for i in range(n2):
    s, at, v, sz, pcv = struct.unpack_from('<QQQQQ', d2, i * 40)
    if (at >> 63) == 0:
        ram += 1
    else:
        reg += 1
print('NATIVE trace records=%d (RAM=%d reg=%d)' % (n2, ram, reg))
frames = 14446
print('NATIVE all-writes/sample=%.3f  RAM-only/sample=%.3f' %
      ((ram + reg) / frames, ram / frames))
