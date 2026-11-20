# native_move_cap (0x8C08DD5C)

The capped move - a position moved by the difference from the old one, but
never by more than the longest movement the literal pool holds - ported
natively in `src/native/move_cap.c` (`vf3_native_move_cap`) as a plain-C
transcription of the readable port `src/fight/move_cap.c`
(`vf3_move_cap_entry`).

## Why this leaf

The readable authority is a **self-contained FP leaf**, the 2D sibling of the
already-ported `aim_step` (0x8C093768), and the first native port that stays
in *round-to-nearest with no FTZ* (the readable test's FPSCR is `0`).  Every
other FP leaf so far hardened toward-zero/FTZ; this one deliberately does not,
so its arithmetic runs on plain C float ops, `fmaf` for the fused
multiply-add, and `1/sqrtf` for the `fsrra`.  It is exactly the boundary the
native `aim_math` register file + FR bank + SR model is built for.

## The body

The function is handed two positions - the one the object had at the start of
the frame (r4, r5) and the one it has now (the two words r6 and r7 point at).
It moves the current position by the difference, but never by more than the
longest movement the literal pool holds.

- The differences `dx = cur - old` and `dy = cur - old` become two floats.
- The squared length `dx*dx + dy*dy` is a **fused** multiply-add (the `fmul`
  of the x term, then `fmac` of the y term over it), so it cannot be written
  as `a * a + b * b` in C: the two roundings differ on some values (for
  example `dx=1, dy=4269` the fused result is `0x4b8b0a75`, the plain sum
  `0x4b8b0a74`).
- The length comes from `fsrra`, the SH-4's *approximate* reciprocal of the
  square root, so the port uses `1/sqrtf` and not a Newton step.  When the
  squared length is below the pool's epsilon the inverse stays at zero.
- The factor `maxstep / len` decides the scale.  The guest compares the
  factor's **absolute value** (a mask over the sign bit) against one; when
  the factor is below one the difference is scaled down and the scaled pair
  is **truncated** to integers; otherwise the whole integer difference is
  kept.
- The new position - the old one plus the movement - is written back to the
  two words r6 and r7 point at, the saved r14 comes back from the stack, and
  the frame is released.

## Evidence

The **differential** (`tests/move_cap_native_replay.c`, target
`vf3nativemove_cap`) runs the native port against the readable guest port from
the same seed.  The literal pool and the frame sit at the game's own
addresses, spanned by one flat buffer.  The whole region is compared byte for
byte, together with the registers, the FR bank, FPUL, SR's T bit and an
independent fixture model that works the movement out from the pool's own
values with the same FPU primitives the guest uses.  The scenarios cover the
still case, movements shorter and longer than the cap, the cap boundary and
just over it, a diagonal, negative movement, a big movement, a fractional
scale, an inexact product whose fused rounding matters, and a negative
max-step.  **12/12 PASS.**

The **mutation gate** (`tests/move_cap_native_mutations.json`) applies
thirteen mutations mapped onto the native lines: the epsilon and max-step read
from the wrong pool slot, the squared length using the y term twice or a
plain multiply-and-add, the factor swapped, the length using `sqrtf` instead
of its inverse, the scale test dropping the `fabs`, comparing against the
epsilon instead of one, or using `>=` instead of `>`, the `ftrc` rounding to
nearest instead of toward zero, the wrong delta axis, the new x and y written
to each other's slots, and the scaled pair writing FPUL from the wrong term.
The differential catches **all 13**.

```text
build\vf3nativemove_cap.exe ->
  move_cap_native_replay: PASS  (12/12)
python tools/mutate.py --port src/native/move_cap.c --exe build/vf3nativemove_cap.exe \
    --mutations tests/move_cap_native_mutations.json --target vf3nativemove_cap \
    --keep-going
  13/13 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated == oracle` is closed per the readable
authority (the readable port itself is differential-and-oracle-replayed,
`docs/re/move_cap.md`).

## Notes

* The flat buffer base equals the **pool's** base (`0x0c08ddc8`), and the
  buffer spans the pool and the frame (at `0x0c108000`) up to `0x0c108040`.
* The T bit the caller sees is the **scale** test's, set when the factor is
  below one; the fixture model reproduces it from the pool's own arithmetic.
* The fused multiply-add mutation was at first unobservable because none of
  the natural scenarios land on a value where the fused and the plain sum
  round differently; a search found `dx=1, dy=4269` (`0x4b8b0a75` vs
  `0x4b8b0a74`), which pins it.
