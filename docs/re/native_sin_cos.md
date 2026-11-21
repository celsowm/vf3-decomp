# native_sin_cos

Native ports of the 16-bit-angle trigonometric pair, **0x8C03A6E0** (sin)
and **0x8C03A140** (cos), as the plain-C leaves `vf3_native_sin_u16` and
`vf3_native_cos_u16` (`src/native/sin_cos.c`), in the same spirit as the
other `src/native/*` ports: transcriptions of the readable guest ports
`src/fight/geom_readable.c` (`vf3_sin_u16_entry` / `vf3_cos_u16_entry`) onto
the `vf3_native_aim` context (FR bank, register file; the leaves read nothing
from RAM).

## The functions

`65536 = one full turn`.  r4 = the angle (low 16 bits are used).

sin (0x8C03A6E0), a self-contained FP leaf: `theta = angle*2pi/65536`,
`h = theta/2`, the half angle is reduced to `y = h - n*pi/2` (n = nearest
quadrant), tan(y) comes from the continued fraction `y / (1 - y^2/(3 -
y^2/(5 - .../11)))`, and `sin(theta) = +-2t/(1 + t^2)` with `t = tan(y)`
(sign flips for odd n).  The result lands in **FR0**.  r4 is untouched.

cos (0x8C03A140): `cos(a) = sin(0x4000 - a')` where `a'` folds the angle
into the first half turn (`a' = 0x10000 - a` when `a > 0x8000`).  It
**tail-calls** the sine routine, so the result lands in FR0; r4 is left as
`0x4000 - a'`, and the original pushes r14 to sp-4 as a dead word.

## Proof

* **Differential** — `tests/sin_cos_native_replay.c` (the `vf3nativesincos`
  target) runs both native leaves against the readable guest ports on the
  same FR/register file for **20 cases** (10 angles x sin/cos, covering all
  four quadrant boundaries, the axes, small and large angles and the zero
  angle) and matches:
  * **FR0** (the sine/cosine), r4 for the cosine (the folded angle), and
    r4 untouched for the sine, against the guest;
  * every other register and FR untouched against its entry value;
  * an **independent fixture model** that recomputes the result from the
    defining formula with the same toward-zero + fused-mac rounding.
  The fixture seeds SR with T **clear**; the leaves do not touch it.
* **Mutation gate** — `tests/sin_cos_native_mutations.json`, **13/13
  caught** (`python tools/mutate.py --port src/native/sin_cos.c --exe
  build/vf3nativesincos.exe --mutations
  tests/sin_cos_native_mutations.json --target vf3nativesincos
  --keep-going`).

## Details the port keeps

* The FP arithmetic goes through the same round-toward-zero + FTZ wrappers
  the other FP native ports use; the single fused multiply-add (the `fmac` in
  `denom = t*t + 1`) uses `fmaf` so it **rounds once**.
* The `ftrc` (the quadrant's float-to-int) is the SH-4's **saturating**
  toward-zero truncation (NaN or < -2^31 -> 0x80000000, >= 2^31 ->
  0x7fffffff).
* The continued fraction runs `k = 11, 9, 7, 5, 3` (odd descending steps);
  the model must call the toward-zero wrappers per operation so the compiler
  cannot contract `h - quadrant*half_pi` into a single fused op that would
  round once where the guest rounds twice (this was the first model bug).
* cos folds with **unsigned 16-bit masking**: `a' = 0x10000 - a` when
  `a > 0x8000`, then r4 = `0x4000 - a'`; sin reads back `r4 & 0xFFFF`, so the
  model has to mask the folded result the same way (the `0x4000 - a'` can
  go negative when `a' > 0x4000`, and the mask brings it into range).
* cos also writes the dead r14 push to sp-4 (the readable port pushes r14
  and pops it again; the transient stack word is part of the contract).

## Files

* `src/native/sin_cos.h` — the `vf3_native_sin_u16` / `vf3_native_cos_u16`
  declarations.
* `src/native/sin_cos.c` — the ports.
* `tests/sin_cos_native_replay.c` — the differential test.
* `tests/sin_cos_native_mutations.json` — the mutation gate.
* `CMakeLists.txt` — `vf3nativesincos` target.
