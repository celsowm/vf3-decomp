# native_vec_lerp21 — 0x8C09F354 vec_lerp21

The native port is `src/native/vec_lerp21.c` (`vf3_native_vec_lerp21`), a
plain-C transcription of the readable guest port `src/fight/vec_lerp21.c`
(`vf3_vec_lerp21_entry`) onto the `vf3_native_aim` context (flat RAM, FR bank,
register file).

## Reading

A self-contained FP leaf (call-free, no stack frame).  `r4` = destination
array of 21 consecutive 3-float vectors (updated in place), `r5` = source
array, `fr4` = blend factor `t`.  For each vector, component-wise:

    dst = src + t * (dst - src)

with the engine's round-toward-zero + FTZ FPSCR (the `fmac` is one rounding).
The original unrolls the last three vectors; the loop parked its z pointer at
`sp-4` on every iteration, so that slot holds the **last loop** vector's z
address (vector 18, i.e. `dst + 12*17 + 8`).

The register/FR file it leaves is that of the final vector:

- `r4 = dst + 240`, `r5 = src + 240` (the last vector does not advance them),
- `r0 = 8`, `r3 =` the last loop vector's z address, `r6/r7 =` the last tail
  vector's z/y addresses,
- `T = 1` (from the loop counter's exit test),
- `fr0 = t`, `fr5 =` the z difference, `fr4/fr6 =` new z, `fr7/fr9 =` new y,
  `fr8/fr10 =` new x.

The `fmac` rounds **once** (fmaf), and the subtract is a single toward-zero
rounding, so the stored floats match the guest bit for bit when both run under
the corpus FPSCR `0x00024001`.  The native port uses the same `flz`/`fsub`/
`fmac` wrapper as `corner_fan.c`.

## Proof

`tests/vec_lerp21_native_replay.c` (`vf3nativeveclerp21`) seeds the same flat
RAM and FR/register file into both sides, runs the leaf, and compares:

- every register `r0..r15`, the FR bank, `SR.T` and `FPUL` against the guest;
- the whole destination array, byte for byte, against the guest;
- the source array untouched;
- the `sp-4` park slot against `dst + 12*17 + 8`;
- an **independent fixture model** of all 21 vectors: `dst = src + t*(dst-src)`
  computed in the test itself with toward-zero `fmaf`, compared bit for bit.

Six `t` values cover the blend: 0 (dst <- src), 1 (dst unchanged), 0.5, 0.1,
-0.25 and 2.5.

The mutation gate `tests/vec_lerp21_native_mutations.json` (8 mutations, run
via `tools/mutate.py --target vf3nativeveclerp21`) catches a wrong source in
the x/y/z difference, a wrong mac accumulator, misplaced y/z stores, and the
park slot's address / boundary.
