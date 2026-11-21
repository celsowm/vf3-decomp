# native sprite_rect_a (0x8C07B35C)

`src/native/sprite_rect_a.c` (`vf3_native_sprite_rect_a`) is the plain-C port
of the readable `src/fight/sprite_uv.c` (`vf3_sprite_rect_a_entry`), proved by
`tests/sprite_rect_a_native_replay.c` (5 differential cases) and the mutation
gate `tests/sprite_rect_a_native_mutations.json` (10/10 caught).

## The function

A call-free, branch-free FP leaf with no stack frame (the only control
transfer is the final `rts`; the single dead spill below the entry `sp` is
part of the captured RAM).  It builds the vertex block's near-corner geometry:
FR4/FR5 are x/y, FR6/FR7 w/h, FR8 z, and the four screen constants are read
out of fixed data addresses.  It stores position (+4/+8), z (+12) and the UV
extent (+16/+20):

```
x  = x * SCALE_X + OFFSET_X
y  = y * SCALE_Y + OFFSET_Y
+12 = z (raw bits)
uw = w * SCALE_X
vh = h * SCALE_Y
```

Register contract: `r0 = 20`, `r2 = OFFSET_Y`, `r3 = OFFSET_X`,
`r5 = SCALE_X`, `r6 = SCALE_Y`; FR3 = vh, FR4 = x, FR5 = y, FR9 = sy,
FR10 = ox, FR11 = oy.  It is a **tail transfer** to pr, so `pr` is untouched.

## What the port has to keep

- **The four screen constants are four distinct data addresses** (SCALE_X/Y
  at 0x0C10B7FC/0x0C10B800, OFFSET_X/Y at 0x0C10B804/0x0C10B808) read at
  run time by the leaf.
- **z is stored as raw bits** (`block + 12`), a word copy of FR8, not a
  float conversion — the mutation that stored it as a float was a no-op and
  is replaced with a wrong-source one instead.
- **The float pipeline rounding**: the adds and multiplies are done with the
  round-toward-zero + FTZ wrappers (`fadd`/`fmul`/`flz`) so the stored floats
  match the guest bit for bit.  The leaf runs under single-precision FPSCR
  with RM bit 0 (toward zero).
- **The FR results ride in the bank** (FR3..FR5, FR9..FR11), exactly as the
  guest's final register stores emit.
- **The dead spill at `sp - 4`** holds `sx`'s bits; it is written and never
  read, but it is part of the captured RAM the differential compares.

## Everything else

The far-corner sibling `sprite_rect_b` (0x8C07B398) and `tex_cell_load`
(0x8C07B4D4) are separate bodies, and all three are inlined inside the
`glyph_cache` driver (`src/native/glyph_cache.c`, 0x8C0C1FBA).  This leaf is
the standalone served entry registered in the router.
