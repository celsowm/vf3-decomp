# native sprite_rect_b (0x8C07B398)

`src/native/sprite_rect_b.c` (`vf3_native_sprite_rect_b`) is the plain-C port
of the readable `src/fight/sprite_uv.c` (`vf3_sprite_rect_b_entry`), proved by
`tests/sprite_rect_b_native_replay.c` (5 differential cases) and the mutation
gate `tests/sprite_rect_b_native_mutations.json` (10/10 caught).

## The function

A call-free, branch-free FP leaf with no stack (the only control transfer is
the final `rts`).  It computes the sprite far corner's four UV values out of
the near corner (FR4/FR5), its extent (FR6/FR7) and the UV scales (FR8/FR9),
and stores `(corner + bias) * scale` at block +24/+28/+32/+36:

```
u0 = (x + BIAS_A) * su ;  v0 = (y + BIAS_B) * sv
u1 = (x + w + BIAS_C) * su ; v1 = (y + h + BIAS_D) * sv
```

Register contract: `r0 = 36`; FR1 = BIAS_C, FR2 = BIAS_B, FR3 = BIAS_D,
FR4 = u1, FR5 = v1.  It is a **tail transfer** to pr, so `pr` is untouched.

## What the port has to keep

- **The four exact bias bit patterns** (they are the code's constants, not
  runtime state): `BIAS_A = 0x3A8461F9`, `BIAS_B = 0x33D6BF94`,
  `BIAS_C = 0x80000000` (negative zero), `BIAS_D = 0xBED70A3D`.
- **The float pipeline rounding**: the adds and multiplies are done with the
  round-toward-zero + FTZ wrappers (`fadd`/`fmul`/`flz`) so the stored floats
  match the guest bit for bit.  The leaf runs under single-precision FPSCR
  with RM bit 0 (toward zero).
- **The FR results ride in the bank** (FR1..FR5), exactly as the guest's final
  register stores emit.
- **The store offsets** (+24/+28/+32/+36) are distinct for the four values,
  so swapping two of them changes which byte lands where.

## Everything else

`sprite_rect_a` (0x8C07B35C) is the near-corner sibling that writes the
position, z and the leading UV extent; `tex_cell_load` (0x8C07B4D4) fills the
cell scratch block.  Those are separate bodies and not part of this leaf.
