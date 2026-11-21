# native tex_cell_load (0x8C07B4D4)

`src/native/tex_cell_load.c` (`vf3_native_tex_cell_load`) is the plain-C port
of the readable `src/fight/sprite_uv.c` (`vf3_tex_cell_load_entry`), proved by
`tests/tex_cell_load_native_replay.c` (5 differential cases incl. a signed-id
case) and the mutation gate `tests/tex_cell_load_native_mutations.json`
(10/10 caught).

## The function

A call-free leaf with no guest callees and no stack frame (only the final
`rts`): an integer field extraction plus a float from-int / fdiv / fmul
pipeline.  `r4` = cell id.  A cell id selects a record from one of two tables:

- ids with bit `0x4000` set index the six-byte records at `0x0C11ABB0`
  (u16 id, four byte fields x/y/w/h);
- others the pair table at `0x0C11AA60` (two u16 per entry, the w/h).

The cell's rectangle in texels (x8 as floats) lands at SCRATCH+0..+12, the
reciprocal-scaled UV extents at +0x30/+0x34 (and the scaled u/v at
+0x38/+0x3C), and the id at `0x0C1B9640`.  The reciprocal pair comes from the
*id's* pair-table entry.

Register contract: `r0 = SCRATCH`, `r1 = SCRATCH_RECIP_W`, `r2 =
SCRATCH_RECIP_H`, `r3 = SCRATCH_V`, `r4 = pw`, `r5 = ph`, `FPUL = ph`; FR2 =
v, FR3 = FR4 = recip_h.  SR's T bit reflects the id's kind (set for the pair
path, clear for the cell-flag path).  It is a **tail transfer** to pr, so
`pr` is untouched (r13/r14 are restored from their saved values).

## What the port has to keep

- **The two table paths are different record layouts**: the cell-flag path
  reads a u16 id and four bytes at a 6-byte stride; the pair path reads two
  u16 at a 4-byte stride.  The sign of the record's id and the pair table's
  width are sign-extended into 32-bit registers before use.
- **The scratches are floats**: the four fields are shifted left by three and
  converted (`(int32_t)v`), stored as float bits.  The recip and scaled words
  all land in distinct SCRATCH offsets.
- **The float pipeline**: the reciprocals and multiplies use the
  round-toward-zero + FTZ wrappers (`fdivv`/`fmul`/`flz`) so the stored
  floats match the guest bit for bit, under single-precision FPSCR RM 0.
- **The id stored at SCRATCH_ID is masked to 16 bits** (`first & 0xFFFF`);
  a record id with the high bit set sign-extends negative into `first` and
  the mutation that stored the unmasked `first` was the observable one.
- **The dead spills at `sp - 4` / `sp - 8`** hold the caller's r14/r13; they
  are written and never read (part of the captured RAM), and r13/r14 are
  restored on exit.

## Everything else

`sprite_rect_a` (0x8C07B35C) and `sprite_rect_b` (0x8C07B398) are the two
sprite-geometry siblings in the same file, all three inlined inside the
`glyph_cache` driver (`src/native/glyph_cache.c`, 0x8C0C1FBA).  This leaf is
the standalone served entry registered in the router.
