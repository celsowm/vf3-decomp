# Native port: vertex_lit (0x8C047EA0)

`src/native/vertex_lit.c` (`vf3_native_vertex_lit`) is the native port of the
strip vertex-lighting leaf, proved against the readable guest authority
`src/fight/vertex_lit.c` (`vf3_vertex_lit_entry`) by
`tests/vertex_lit_native_replay.c` and by the mutation gate
`tests/vertex_lit_native_mutations.json` (11/11 caught).

## What it does

A self-contained FP leaf (call-free, no stack frame).  It transforms one strip
vertex record (`r4`) through XMTRX as `(x, y, z, 1)`, folds its lighting
terms, and ends with `T = (r12 > the transformed w, as unsigned bits)` and
`r4 = record + 32`.  `r8` selects how many squarings the specular ladder runs.

The readable authority reads the record as:

- position `x, y, z` at `+0` (transformed by XMTRX),
- a vector at `+12`, stored in `FR2, FR0, FR1` order and used raw,
- two words at `+24` / `+28` that go to `r1` / `r2`,
- `FV12` and `FV8` — two vectors the caller left in the FP registers.

The lighting math (verbatim from the readable port):

```
FR3 = FV0 . FV12            (diffuse)
FR2 = FR15 + max(FR3, 0)
r8 > 0: FR11 = FV0 . FV8    (a cosine)
        FR11 squared; if positive, doubled (2c²); when above 1,
        reduced by 1 and squared again; FR3 collects the term and the
        power ladder runs from the r8-chosen slot (braf r8).
r8 < 0: FR2 = 1.0
r8 == 0: nothing more
T = (r12 > transformed w)
```

## What the port had to get right

- **`FMOV(2,15)` copies FR15 into FR2, not the reverse.**  The assembler
  operand order in `fr_ops.h` is `FMOV(d, m) = F(d) = F(m)`, so
  `FMOV(2, 15)` is `FR2 = FR15`.  The first version of the port had it the
  wrong way round (`FR15 = FR2`), which showed up as `fr[15]` and `fr[2]`
  mismatches.  (Mutation `fmov_direction_fr2_from_fr15_swapped`.)
- **ftrv/fipr accumulate in a `volatile double`, then round once.**  The
  guest's `vf3_fpu_ftrv` / `vf3_fpu_fipr` (`sh4_fpu.c`'s `dot`) accumulate the
  four products in a `volatile double`.  A plain `float` accumulate gives a
  transformed `w` that is off by one LSB, which shows up in `r0`/`FPUL`.
  `dot4` in the native port replicates the double accumulate.
- **The rounding mode has to follow `FPSCR.RM`.**  fpscr `0x00040001` has
  RM = 1 → round toward zero.  The `dot4` and the `1/x` division wrap their
  arithmetic in `fesetround((fpscr & 1u) ? FE_TOWARDZERO : FE_TONEAREST)`,
  the same wrapper the other native FP leaves use, and restore it after.
  Without it the `double → float` round is off by one LSB.
- **The braf power ladder is a switch on `sel`.**  The ladder is a chain of
  squarings of FR3 / FR11 chosen by `r8` (`LADDER + r8`, 4 bytes per slot),
  reproduced as the `switch` in the port.  The mutation gate's
  `ladder_squaring_hits_fr11` proves the `sel == 0x08` slot squares FR3, not
  FR11.

## Proof

- `tests/vertex_lit_native_replay.c` — 9 differential cases, all PASS:
  `sel=0`, `sel=-1`, `sel=8`, `sel=12`, `sel=20`, `sel=48`, `sel=80`, plus a
  negative-diffuse (`lit` false / `positive` false) case and a small-cosine
  (`above_one` false) case so all three conditionals in the specular fold are
  exercised.  Both sides seed the same flat RAM (the record), XMTRX, FR bank
  (including FV12 = FR12..FR15 and FV8 = FR8..FR11), `r4`, `r8` and `r12`.
  `r0/r1/r2/r4`, FPUL, SR's T bit and the preserved XMTRX / FR8..FR10 /
  FR12..FR14 are compared bit-exact; FR0..FR7, FR11 and FR15 at the 2e-3 FPU
  tolerance.  (FTZ is on via fpscr, but the values here are all normal, so
  the comparison is exact.)
- `python tools/mutate.py --port src/native/vertex_lit.c --exe
  build/vf3nativevertexlit.exe --mutations
  tests/vertex_lit_native_mutations.json --target vf3nativevertexlit
  --keep-going` → **11/11 CAUGHT**.

Ledger row: the entry `0x8C047EA0` sits inside `f_8c047e0e`'s already-ported
body (strip_vertex lit is a sibling of `vertex_classify`), so the row's
address-union contribution is `0` bytes — this is a *readable-quality* native
port of a leaf whose generated translation already served the entry, on the
same model as the aim/pose/matrix native family.
