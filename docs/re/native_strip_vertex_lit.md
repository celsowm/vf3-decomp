# native_strip_vertex_lit — SH-4 0x8C048F60

Native port of the lit vertex-strip transformer, `src/native/strip_vertex_lit.c`
(`vf3_native_strip_vertex_lit`), a plain-C transcription of the readable port
`src/fight/strip_vertex_lit.c` (`vf3_strip_vertex_lit_entry`) onto the
`vf3_native_aim` context, following the `vertex_lit` (0x8C047EA0) precedent.

## The guest body

`strip_vertex_lit` is a software-pipelined store-queue emitter.  It reads a
strip of 32-byte vertex records (r4) — a count word then records, each with a
bit-0 inline flag and, when clear, a word-1 offset to out-of-line
coordinates — transforms each vertex through XMTRX, folds its lighting and
writes 32-byte store-queue vertex blocks at r6 (r5 advancing 32 per vertex).
It runs with `FPSCR.SZ = 1` for the whole body (set on entry, cleared in the
`rts` delay slot), so every FRn load (`fld_post14`) or store (`fst_pre6`,
`push6`) moves a pair.

Per vertex: FR4..FR7 (x, y, z, w) through XMTRX with w forced to 1, then
`FR7 = 1 / x'`, the diffuse term `FR3 = FV12 . FV0`, the cosine
`FR11 = FV0 . FV8`, and `FR2 = FR15 (+ diffuse when positive)`.  With r8 a
non-zero specular power (4..40, step 4) the cosine is squaring-laddered into
FR3 via `ladder` (a switch on r8 reproducing the guest's `braf` chain of
`FMUL` slots at 0x8C04903C + r8).  Three vertices are written per group (r3
counts them); the third closes the group with a `0xFFFFFFFF` word and r9
counts the groups down to the return.

## The native port

The FP chains reproduce the guest's rounding.  The `ftrv` transform and the
`fipr` dot products accumulate in a `volatile double` (exactly `sh4_fpu.c`'s
`dot`), rounded once, under `fesetround(FE_TOWARDZERO)` when `FPSCR.RM` is 1
(`fpscr 0x00040001`); the scalar `fdiv`/`fmul`/`fadd`/`fsub` helpers set the
same rounding around a volatile op.  This makes the final register and
store-queue results **bit-exact** against the oracle.

## Proof

- Differential: `tests/strip_vertex_lit_native_replay.c` (`vf3nativestripvertexlit`)
  runs the readable guest entry and the native port on the same flat RAM, XMTRX,
  FR bank (FV8 = FR8..11, FV12 = FR12..15, FR15 ambient), and registers
  (r4 = the strip, r5 = 0, r6 = the slot base, r8 = the ladder slot, sp/pr/sr/
  fpscr/fpul).  Five cases, one **9-record** strip each (three groups of three
  vertices) across r8 = 0 / 8 / 24 and positive / negative FV8 / FV12:
  all **PASS**.  The emitted store-queue region, the register contract
  (r0..r6, r9, r14), SR and XMTRX are compared bit-exact; the whole FR bank at
  the 2e-3 FPU tolerance.
- Mutation gate: `tests/strip_vertex_lit_native_mutations.json`, **10/10
  caught** (`python tools/mutate.py --port src/native/strip_vertex_lit.c
  --exe build/vf3nativestripvertexlit.exe --mutations
  tests/strip_vertex_lit_native_mutations.json --target vf3nativestripvertexlit
  --keep-going`).  The ten span: both `FDIV(7,4)` sites (third-vertex and the
  bf/s delay slot) by-FR5; the diffuse `fipr` to FR3 from FV8 on both the
  third-vertex and non-third-vertex lines; the `positive` (FR11 > FR3) and
  `above_one` (FR11 > 1) ladder gates inverted; the `fst_pre6(2)` emitter
  storing FR3's slot instead of FR2's; `push6(R2)` pushing R1; and the two
  `FMUL(6,7)`/`FMUL(5,7)` scale-by-FR4.  The remaining gate decisions follow
  the `vertex_lit` family's: no mutable `ladder` rewrite is gated directly
  (each ladder slot is individually reachable through a distinct r8 in the
  differential), and the out-of-line record redirect (`R(14) = [r14+4];
  R(4) -= 24; R(14) += R(4)`) is covered by construction since the
  differential seeds only inline records (the same fixture decision the
  `clip_near_triangle` and `clip_edge` natives make).

Registered in `src/native/` and as the `VF3NATIVESTRIPVERTEXLIT` target in
`CMakeLists.txt` after `vf3nativevertexlit`.
