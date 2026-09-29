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

## Standalone replay resolved (2026-09-29)

The apparently downstream exit is the fragment's real return state. Its
epilogue restores PR from the local save, then pops `r13` from the caller's
stack slot and `r14` from the next slot in the RTS delay slot. Thus its
contract has `r13 = [entry r15]`, `r14 = [entry r15+4]`, and `r15 = entry+8`.
The previous model omitted these caller-owned stack pops, so its replay could
not match the captured state. `src/fight/af734.c` now models them, and the
64 paired register+RAM cases pass.

The old same-PC exit pairing remains downstream-state evidence and is no
longer the replay source. `tools/golden_return_pair.py` pairs each `0x8C0AF734`
entry with the next watched PC named by its saved PR; watch file
`tools/watch/vf3_af734_return_sites.txt` covers the three observed return
sites. The resulting 64-case oracle is at
`extract/analysis/goldens_af734_pair/f_0c0af734.cases` (generated, ignored
analysis output). The four traces yielded 251 matched call/return events;
227 had both RAM snapshots before deduplication.

Regenerate the pairs after the watch capture with:

```powershell
python tools/golden_return_pair.py extract/analysis/golden_af734_return_sites_s26.bin extract/analysis/golden_af734_return_sites_s27.bin extract/analysis/golden_af734_return_sites_s28.bin extract/analysis/golden_af734_return_sites_s29.bin --entry-pc 0x0c0af734 --return-pc 0x0c0ae252,0x0c0ae500,0x0c0ae418 --scenario s26,s27,s28,s29 --out extract/analysis/goldens_af734_pair --max-samples 64
```

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
