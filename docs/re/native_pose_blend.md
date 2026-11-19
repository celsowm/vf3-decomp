# Native pose blend (0x8C091DE6)

The retail 26-field pose blend was landed as `src/native/pose_blend.c` but had
**no proof of its own**: it compiled into the native library yet no test, no
differential and no mutation gate drove it.  Its readable authority
`vf3_pose_blend_entry` is registered in the readable registry at `0x0c091de6`
(`src/fight/pose_blend.c`), so this milestone proved the native leaf against
it, the same way the rest of the aim/pose family is proved.

- `src/native/pose_blend.c` / `pose_blend.h` (the native leaf, now proved)
- `tests/pose_blend_native_replay.c` (the differential, target
  `vf3nativeposeblend`)
- `tests/pose_blend_native_mutations.json` (the gate, 13/13 caught)
- authority: `src/fight/pose_blend.c` (`vf3_pose_blend_entry`)

## The contract

The guest object (`r4`) carries a **weight** at `+0x9C`, a **step** at `+0xA0`,
pose A (26 signed halfwords) at `+0`, pose B at `+52`, and the result at
`+104`.  The body advances the weight by the step, clamps it to 1.0 and stores
it back; then with `w = trunc(weight * 16384)` each output halfword is the low
16 bits of `(A*(0x4000-w) + B*w) >> 14` (32-bit products, arithmetic shift).

The native leaf `vf3_native_pose_blend_step(float *weight, float step,
const int16_t A[26], const int16_t B[26], int16_t out[26])` is the same math in
plain C, plus defensive `-1` (null pointer) and `-2` (non-finite / out of
range) arms.  The test points the leaf at the **same RAM object** the readable
entry used (`wptr = at(OBJ + 0x9C)`, `pa = at(OBJ)`, `pb = at(OBJ + 52)`,
`pout = at(OBJ + 104)`), so its weight write-back and output land at exactly
the two places the guest writes, and the byte compare of the whole object
region reads the native's real output.

## The rounding lesson

Five of the six cases (four differential + the defensive block) matched
immediately, but the **mid blend** (`0.9f + 0.05f`) showed a one-ulp difference
in the *stored weight*: native `0x3F733333`, readable `0x3F733332`.

The readable folds the weight add through `vf3_f_add` → `vf3_fpu_binary`, and
with the captured FPSCR `0x00040001` (bits 0-1 = `01`) its `begin()` sets
`fesetround(FE_TOWARDZERO)` (plus FTZ).  The native's plain C `volatile float`
add was rounding to **nearest**, so the half-ulp sum `0.9f + 0.05f` landed one
ulp higher.  The reference (readable == oracle) rounds **toward zero**, and the
native is the one that has to move:

```c
{
    const int saved_round = fegetround();
    fesetround(FE_TOWARDZERO);
    updated_weight = *weight + step;
    if (updated_weight > 1.0f)
        updated_weight = 1.0f;
    scaled_weight = updated_weight * 16384.0f;
    fesetround(saved_round);
}
```

The add *and* the `16384.0f` scale both go through the guest FMUL/FADD, so both
are wrapped; the rounding mode is restored before the integer blend loop so the
rest of the port is ordinary C.  The mutation gate's `rounding_nearest_not_
toward_zero` (swapping to `FE_TONEAREST` and rebuilding) is the one that pins
it: round-to-nearest puts the stored weight at the upper ulp and the
differential fails.  (The first version of that mutation wrote the
non-existent `FE_NEAREST`, which failed to compile rather than discriminating;
`FE_TONEAREST` is the valid constant and it catches the wrong value cleanly.)

## Proof

`tests/pose_blend_native_replay.c` runs five differential cases, each seeding
the object, running the readable entry, snapshoting the object region, re-seeding,
running the native leaf, and comparing every byte of the region (`OBJ` through
`OBJ + 0xA4`) byte-exact:

- **quarter blend, spanning signs** (weight 0, step 0.25);
- **clamp to full blend** (0.9 + 0.5 → clamps to 1.0, out = B);
- **zero blend** (out = A);
- **negative sums / half-multiples** (large negative A, positive B, weight
  built up to 0.75) — exercises the two's-complement magnitude rounding of the
  negative arm;
- **mid blend, weight 0.95** (0.9 + 0.05) — the rounding case.

The defensive `-1`/`-2` arms are not differential-able (the readable entry has
no error path — the game never feeds it nulls or non-finite weights), so they
are checked by direct calls to the leaf.

`tools/mutate.py --port src/native/pose_blend.c --target vf3nativeposeblend`
catches **13/13** mutations:

| mutation | how the differential sees it |
|---|---|
| `step_omitted` | stored weight = seed, output = A-only arm |
| `clamp_removed` | the 1.4 case leaks through, output scatters |
| `scale_off_by_one` | w off by one Q14, outputs shift |
| `b_weight_rounding_off` | `+1` on the truncate, outputs off by a step |
| `a_weight_sign_flipped` | `0x4000+w` instead of `0x4000-w` |
| `b_cross_wired_to_a` | poses mixed, output collapses |
| `positive_shift_halved` | `>>13` halves positive sums |
| `negative_magnitude_shift_halved` | `>>13` almost doubles negative magnitudes |
| `negative_magnitude_rounding_removed` | drops the +0x3FFF, negatives off by 1 |
| `last_element_not_written` | out[25] keeps the seed |
| `weight_not_written_back` | stored weight stays the seed |
| `rounding_nearest_not_toward_zero` | stored weight at the upper ulp |
| `null_return_off` | null-pointer arm returns 45, not −1 |

The `negative_magnitude_rounding_removed` and `positive_shift_halved`
mutations are the two halves of `arithmetic_shift_q14`; both are observable
because the "negative sums" fixture guarantees big negative magnitudes that are
not exact multiples of 16384, so the +0x3FFF magnitude rounding actually moves
the result.  There is no unobservable mutation on the list — every arm the test
reaches is covered, and the defensive block is reached by the direct calls.

This closes the circle for 0x8C091DE6: the native leaf is now byte-exact with
its readable authority on the object region the guest writes, and the mutation
gate proves the differential has teeth.
