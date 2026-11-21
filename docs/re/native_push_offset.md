# native push_offset (0x8C056B20)

`src/native/push_offset.c` (`vf3_native_push_offset`) is the plain-C port of
the readable `src/fight/geom_readable.c` (`vf3_push_offset_entry`), proved by
`tests/push_offset_native_replay.c` (4 differential cases) and the mutation
gate `tests/push_offset_native_mutations.json` (10/10 caught).

## The function

A call-free FP leaf with no stack frame (only the final `rts`; `fmul` and
`from-int`, no guest callees).  It is register-passed: `r8` = source (two
int16 at +0x0E, +0x10), `r12` = record cursor, `r6` and FR12..FR15 = values
to push, FR3 = scale.  It writes

```
[r12+30] = FR14, [r12+2C] = FR13, [r12+28] = FR12, [r12+24] = r6
[r12'+14] = float(s16 @ src+0x10) * scale    (y, -> FR1)
[r12'+10] = float(s16 @ src+0x0E) * scale    (x, -> FR2)
[r12'+18] = FR15, [r12'+1C] = 0
```

with `r12' = r12 + 0x20` on return; `r0 = 0`, `r8` unchanged.  It is a
**tail transfer** to pr, so `pr` is untouched.

## What the port has to keep

- **`r12' = r12 + 0x30 - 0x10 = r12 + 0x20`**: the "new top" is sixteen
  bytes under the `+0x30` cursor, so four sets of words overlap in the record
  (the scratch 0xbadf00d in the fixture witnesses the split).
- **The two source int16 are sign-extended** before the float multiply, so a
  negative src value produces a negative result float.
- **The float pipeline**: the multiplies use the round-toward-zero + FTZ
  wrapper (`fmul`) so the stored floats match the guest bit for bit, under
  single-precision FPSCR RM 0.
- **The carried FR words are raw-bit copies** of FR12..FR15 (via
  `vf3_aim_ubits`), while y/x are float stores; the two kinds land at
  distinct offsets.
- **`r0 = 0` and `r12` moves to `top`** on exit; `r8` is untouched.

## Everything else

`push_offset` is a sibling of `corner_fan` (0x8C03FB10, already native) in the
same `geom_readable.c` geometry family.  This leaf is the standalone served
entry registered in the router.
