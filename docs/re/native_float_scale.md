# native_float_scale (0x8C039C50 / 0x8C039C70)

The fight engine's unsigned-32-to-float scale, ported natively in
`src/native/float_scale.c` (`vf3_native_float_scale`) as a plain-C
transcription of the readable ports `src/fight/float_scale.c`
(`vf3_float_scale_a_entry` / `vf3_float_scale_b_entry`).

## Why this leaf

The readable authority is a **self-contained leaf** - it calls nobody and
keeps **no stack frame**, but it reads the literal pool, converts a 32-bit
value to a float, folds the sign bit back in, scales it, and returns the
truncated integer.  Its FP work rides the shared FR helpers, exactly the
boundary the native `aim_math` FR bank + FPUL model.

The two entries differ only in which pool pointer names the value
(`0x0c039d4c` for the first, `0x0c039d58` for the second), so the native entry
takes the pool pointer as a parameter.

## The body

Each entry reads one 32-bit value through a literal-pool pointer, converts it
to a float, folds the sign bit back in with the 2^32 addition when it is set,
scales by 1.28 (read from the pool at `0x0c039d54`) and returns the truncated
integer in `r0` and FPUL.

- The pool holds the value's pointer, `4294967296.0f` at `0x0c039d50` (the 2^32
  the sign bit folds in) and `1.28f` at `0x0c039d54`.
- The "add 2^32 when negative" is the unsigned-wrapping trick: the SH-4's
  `float FPUL,FRn` converts its 32-bit integer as signed, so to get the float
  of the unsigned interpretation the guest adds the pool's 2^32 as a float.
- The **T bit** the caller sees is the `cmp/ge #0` at the very start, so it is
  `(value >= 0)`.
- The `bt/s` **delay slot** (`float FPUL,FR3`) runs on **both** paths, so `fr3`
  always holds `float(value)` before the branch is resolved.
- The multiplier is loaded and overwrites `fr2` on every path, so the final
  `fr2` is the multiplier either way.

## Evidence

The **differential** (`tests/float_scale_native_replay.c`, target
`vf3nativefloat_scale`) runs the native port against both readable guest ports
from the same seed.  The pool and the data sit at the game's own addresses,
spanned by one flat buffer.  The whole region is compared byte for byte,
together with the registers, the FR bank, FPUL and SR's T bit, and the answer
against an independent fixture-based model.  The values cover zero, small and
mid unsigned magnitudes, int32 min/max, and the negative values that take the
sign-fold path.  Both entries run every value.  **20/20 PASS.**

The **mutation gate** (`tests/float_scale_native_mutations.json`) applies
twelve mutations mapped onto the native lines: the value pointer read from the
wrong pool slot, the sign fold omitted or using the scale constant, the scale
constant from the plus slot, the fold arm taken on non-negative, the int-float
conversion rounding to nearest instead of toward zero, the T bit from the mode
instead of the value's sign, the answer truncated instead of saturated, the
answer not written to FPUL or to r0, the value converted as unsigned, and the
multiplier not loaded into fr2.  The differential catches **all 12**.

```text
build\vf3nativefloat_scale.exe ->
  float_scale_native_replay: PASS  (20/20)
python tools/mutate.py --port src/native/float_scale.c --exe build/vf3nativefloat_scale.exe \
    --mutations tests/float_scale_native_mutations.json --target vf3nativefloat_scale \
    --keep-going
  12/12 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated == oracle` is closed per the readable
authority (the readable port itself is oracle-replayed,
`docs/re/float_scale.md`).

## Notes

* The flat buffer base equals the **pool's** base (`0x0c039000`), and the
  buffer spans the pool and the data region (at `0x0c300000`) up to the data
  region's end.
* The FPSCR is `0x00040001` (round toward zero + FTZ), so the int-float
  conversion, the fold add and the scale multiply all round **toward zero**.
  This matters: `(float)0x80000001` is `-2147483520` under toward-zero but
  `-2147483648` under round-to-nearest, and the fold propagates the difference
  to a 1-ULP shift in `fr3`.
* FTRC saturates at the int32 bounds: a value below -2^31 gives `0x80000000`,
  one at or above 2^31 gives `0x7fffffff` (so the scaled values near the top
  saturate, and the direct C cast would be UB - both the port and the model
  apply the saturation).
* The native `a.fpul` and the FR bank are seeded from the guest's **incoming**
  values (captured before the guest runs), so the untouched registers and the
  touch-it-on-the-path registers distinguish the correct port from one that
  leaves them alone.
