# native_matrix_scale — the current-transform scale (0x8C03CB70)

The readable port `src/fight/leaf_math.c` (`vf3_matrix_scale_entry`) is
rewritten as plain C in `src/native/matrix_scale.c`
(`vf3_native_matrix_scale`), proved against it by
`tests/matrix_scale_native_replay.c` (3 differential cases) and by the
mutation gate (`tests/matrix_scale_native_mutations.json`, 7/7 caught).

## The leaf

A self-contained, call-free, no-stack leaf that scales the three axis
columns of XMTRX by (FR4, FR5, FR6), using XF15 as a scratch slot and FPUL
to park XF15's entry value.  The guest keeps XMTRX in the XF bank
(`s->v[37..52]`) and FR in `s->v[21..36]`; the native port maps them to
`a->xm[16]` and `a->fr[16]`.

```
push FR6, FR5, FR4 to sp-4, sp-8, sp-12;   FPUL = XF15 (entry value)
for each axis:  XF15 = FR(4+axis);
                multiply the column's four words by that scale
XF15 = FPUL  (restored to its entry value)
```

No general register or r15 moves; SR untouched.  The multiplies go through
an FPSCR-exact `fbin('*')` wrapper (`fesetround` FE_TOWARDZERO/FE_TONEAREST
per FPSCR bit 0, plus the FTZ flush of denormal results), so they match
`vf3_f_mul()` bit for bit.

## The test

`tests/matrix_scale_native_replay.c` seeds both sides with the same XMTRX
(16 floats), FR bank (distinct scales in FR4..6), FPUL and FPSCR
`0x00040001` (toward-zero + FTZ), runs the leaf, and compares against the
guest: the whole XMTRX (`a->xm` vs `s->v[37..52]`), FPUL (`a->fpul` vs
`s->v[53]`), the FR bank, every general register, and the pushed stack words
at sp-4/sp-8/sp-12 (window must reach `sp-12`).  Three cases: ordinary
scales, rounding-exercising scales (where toward-zero differs from nearest),
and a product that lands on a denormal to exercise the FTZ flush.

## The mutation gate

`tests/matrix_scale_native_mutations.json` applies 7 single mutations: the
FR pushes removed, a wrong FPUL value, a wrong scale source (flipped axis),
the axis/column loop counts one short, the FTZ flush removed, and the
rounding mode forced to nearest.  All 7 are caught — `round_nearest_not_toward`
and `no_ftz` are the two that isolate the FPU-exact wrappers.  One candidate
mutation (`xm15_not_restored`) was dropped as unobservable: the restore
writes FPUL back into XMTRX[15], and FPUL was parked to XMTRX[15]'s *entry*
value, so removing the restore leaves XMTRX[15] at its entry value either
way — the `fpul_wrong` mutation already pins that contract.  Command:

```
python tools/mutate.py --keep-going --port src/native/matrix_scale.c \
  --exe build/vf3nativematrixscale.exe \
  --mutations tests/matrix_scale_native_mutations.json \
  --target vf3nativematrixscale
```

## Authority

The readable port is the authority; the chain is *native == readable*, with
the FPU-exact multiply wrapper matching `vf3_f_mul()`'s semantics (the same
wrapper shape proved by the earlier FP leaves).  No oracle corpus names this
exact entry as a watched specimen, so the proof stands on the differential
against the readable translation.

Result: **3/3 PASS**, **7/7 mutations caught**.
