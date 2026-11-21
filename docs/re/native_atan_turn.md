# native_atan_turn

Native port of the arctangent-turn, **0x8C039FD0**, as the plain-C leaf
`vf3_native_atan_turn` (`src/native/atan_turn.c`), in the same spirit as the
other `src/native/*` ports: a transcription of the readable guest port
`src/fight/atan_turn.c` (`vf3_atan_turn_entry`) onto the `vf3_native_aim`
context (FR bank, register file, FPUL).  A self-contained FP leaf (call-free,
no stack frame, no tail-transfer).

## The function

FR4 = x.  The argument is folded into [-1, 1] (u = 1/x when |x| > 1, else
u = x) and atan(u) is evaluated as a **13-term continued fraction** in u^2:

    t = 0;  for n = 13 .. 2:  t = (n^2 * u^2) / (2n + t + 1)
    atan = u / (1 + t)

scaled to turns as `(atan + 2pi) * 65536 / 2pi + 0.5`, truncated and masked
to 16 bits.  For x > 1 the result is `0x4000 - angle`, for x < -1 it is
`0xC000 - angle` (the quadrant fold), otherwise the angle itself, all
zero-extended from 16 bits.

Leaves r0 = the masked angle (folded), r3 = 0xFFFF, r4 = the angle, r5 = 1,
FPUL = the raw truncated angle, SR's **T bit** = the quadrant fold flag
(x > 1, or x < -1 afterward), and fr1 = 0.5, fr2 = 65536, fr3 = the scaled
value, fr5 = atan, fr6 = 1, fr7 = 2pi, fr8 = the last n^2 helper.  r1, r2,
r6..r15, the stack pointer and pr are untouched.

The constants (2pi = 0x40C90FDA, 65536 = 0x47800000, 0.5 = 0x3F000000) are
literal-pool constants in the image.

## Proof

* **Differential** — `tests/atan_turn_native_replay.c` (the
  `vf3nativeatanturn` target) runs the native leaf against the readable guest
  port for **15 scenarios** across the three fold regions (|x| < 1, x = ±1,
  x > 1, x < -1, large values) and matches:
  * the output registers r0/r3/r4/r5, FPUL and SR's T bit against the guest;
  * every FR-bank output the leaf writes (fr1..fr8) against the guest's, and
    every other FR register unchanged;
  * an **independent fixture model** that recomputes the 16-bit angle from
    the defining continued fraction with the same toward-zero rounding.
  The fixture seeds SR with T **clear** so the leaf must set it properly.
* **Mutation gate** — `tests/atan_turn_native_mutations.json`, **11/11
  caught** (`python tools/mutate.py --port src/native/atan_turn.c --exe
  build/vf3nativeatanturn.exe --mutations
  tests/atan_turn_native_mutations.json --target vf3nativeatanturn
  --keep-going`).

## Details the port keeps

* The fold test compares **|x| > 1** (the sign bit is masked off first), and
  the fold is u = **1/x** (not x/1).
* The continued fraction runs n = 13 down to 1 (13 iterations, the division
  executed on the last pass too — the delay slot of the loop's back-edge).
* The scramble `(atan + 2pi) * 65536 / 2pi + 0.5` folds the negative-
  quadrant angles into the 0..2pi range before the 16-bit truncation.
* The quadrant fold is `0x4000 - angle` for x > 1 and `0xC000 - angle` for
  x < -1, each **subtracted** (not added) and then masked to 16 bits.
* FPUL = the raw (pre-mask) truncated angle; r0 carries the folded+masked
  angle; SR's T bit records the fold flag even when the angle wraps.

Three candidate mutations are *unobservable* on any 16-bit outcome and are
**not** in the gate: toggling the fold's `>`/`>=` at exactly |x| = 1 (there
1/x == x, so the branch never changes u), changing the loop's start term
(n=13 vs 14 converges to the same 16-bit angle — a continued fraction's extra
term is below the turn quantum), and toggling the second-quadrant `>`/`>=`
at exactly x = -1 (0xC000 - ang aliases to ang mod 0x10000 on the fixed -pi/4
angle).  They are replaced by mutations on the fold's abs-mask, the
denominator's `+1`, and the second-quadrant constant, which are observable.

## Files

* `src/native/atan_turn.h` — the `vf3_native_atan_turn` declaration.
* `src/native/atan_turn.c` — the port.
* `tests/atan_turn_native_replay.c` — the differential test.
* `tests/atan_turn_native_mutations.json` — the mutation gate.
* `CMakeLists.txt` — `vf3nativeatanturn` target.
