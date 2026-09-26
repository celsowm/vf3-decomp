# 0x8C0AF734 probe — CASCADE PLAN (revised 2026-09-26)

168 B, fight-hot. Full body disassembled (sh4full 100 insns): integer
flag-twiddle head/mid/tail + one FPU+jsr block (778-7B4) + `jsr @r2`
(r2 = literal 0x0C09553C).

## Revision: the callee is static gap code, not a RAM routine
RAM-dump/image cross-check proves 0x0C09553C = P1 0x8C09553C image bytes
(a real function ending `rts` at 0x8C095580). The "RAM-resident" verdict
below was alias confusion. Full static chain:
- af734 (baseline, 168 B) -> U2 0x8C09553C (gap, ~70 B, FPU
  fmul/fmac/fsub kernel, rts-terminated)
- U2 -> U1 entries 0x8C03A140 (tiny prologue, tail-merges) and 0x8C03A6E0
  (gap, ~300 B FPU fdiv/float/ftrc/fmac kernel, rts at 0x8C03A748)
- U1: no calls observed (straight FPU + branches)

## Orchestra (bottom-up)
1. U1 (needs `fdiv_tz`; `float`/`ftrc` are exact/truncate-always)
2. U2 (nested U1 calls + FPU chain)
3. af734 RUN path (SKIP 63/64 already understood: integer-only)
Gap-PC watching PROVEN (goldens_s8: 64 samples each for
9553C/3A6E0/3A140 in one fight run). Ported gap units count via
off-baseline decomp_status rows and clear closures through ported().

## Original probe notes (kept for the method)
Two-path structure (64 fight samples, goldens_s6b, 13 windows):
SKIP (63/64, flag bit 0x01000000 clear) vs RUN (1/64, flag 0x01400000):
spills fr3a/fr3b (`[r14+0x1D04]`/`[r14+0x1D0C]`) to `[F+4]`/`[F]`
(F = r15-12), call, transformed floats back (0x3cb67364/0xbc3ba2fc ->
0x3c8f099f/0x3c9312a0), fsub chain (RM=1) -> `[r14+16]`/`[r14+24]`.
80195C vector cells constant across samples (they are code addresses,
not data — same alias story).

## Superseded section (kept for the method, verdict revised above)
Two-path structure (64 fight samples, goldens_s6b, 13 windows):
- SKIP (63/64): `[r13+12] & 0x01000000 == 0` -> bt 7B6 over the FPU+jsr
  block. Pure integer flag ops; fully modelable (analysis only, not ported).
- RUN (1/64, flag 0x01400000): spills fr3a/fr3b (`[r14+0x1D04]`/
  `[r14+0x1D0C]`) to `[F+4]`/`[F]` (F = r15-12), calls 0x0C09553C with
  r5/r6 = spill pointers, reads back TRANSFORMED floats
  (spills 0x3cb67364/0xbc3ba2fc -> post-call 0x3c8f099f/0x3c9312a0),
  fsub chain (RM=1) -> `[r14+16]`/`[r14+24]` stores.
- OLD (wrong) conclusion was "RAM-resident callee, structurally
  unportable". The alias result overturns it: the callee is static image
  code, so the chain is portable bottom-up per the Orchestra above.
