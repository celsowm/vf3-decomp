# 0x8C0AF734 probe — PARKED (2026-09-26)

168 B, fight-hot. Full body disassembled (sh4full 100 insns): integer
flag-twiddle head/mid/tail + one FPU+jsr block (778-7B4) + RAM-vector
`jsr @r2` (r2 = literal 0x0C09553C).

## Two-path structure (64 fight samples, goldens_s6b, 12 windows)
- SKIP (63/64): `[r13+12] & 0x01000000 == 0` -> bt 7B6 over the FPU+jsr
  block. Pure integer flag ops; fully modelable (analysis only, not ported).
- RUN (1/64, flag 0x01400000): spills fr3a/fr3b (`[r14+0x1D04]`/
  `[r14+0x1D0C]`) to `[F+4]`/`[F]` (F = r15-12), calls 0x0C09553C with
  r5/r6 = spill pointers, reads back TRANSFORMED floats
  (spills 0x3cb67364/0xbc3ba2fc -> post-call 0x3c8f099f/0x3c9312a0),
  fsub chain (RM=1) -> `[r14+16]`/`[r14+24]` stores.

## Why parked (structural, not statistical)
- The callee is RAM-resident code (entry-RAM dump at 0x0C09553C decodes as
  SH-4 with its own nested `jsr @r3`), i.e. a compute callback, not a
  static routine. Its outputs are load-bearing (feed the fsubs/stores) and
  unobservable from entry state, so the RUN path is unverifiable as a pure
  function of the golden inputs. cntup-style delegation fails: the
  footprint is non-zero AND load-bearing (writing oracle values into the
  shadow would be circular).
- More RUN samples would not help: the blocker is the unmodelable callee,
  not sample count.

## Future boundary
A port needs a model of the 0x0C09553C RAM routine (capture its body across
scenarios; if it is a fixed trampoline into ROM code, resolve the true
callee and port it as a nested unit). SKIP path: integer-only, ready to
lift when RUN is solved.
