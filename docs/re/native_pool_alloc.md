# native pool_alloc (0x8C07B2BE)

`src/native/pool_alloc.c` (`vf3_native_pool_alloc`) is the plain-C port of the
readable `src/fight/glyph_cache.c` (`vf3_pool_alloc_entry`), proved by
`tests/pool_alloc_native_replay.c` (8 differential cases) and the mutation
gate `tests/pool_alloc_native_mutations.json` (8/8 caught).

## The function

A self-contained integer leaf (call-free, no FP, no stack frame).  `r4` -> the
HUD layer, which keeps a pool of 120 entries of 68 bytes at `*(layer + 12)`
and a rotating allocation cursor (u16 at `layer + 42`).  An entry is *free*
when its first halfword is zero.

- if the cursor's entry is free it is handed out, and the cursor advances
  (wrapping to zero at 120);
- otherwise the pool is scanned from the base for the first free entry
  (`r0 = r5 = it`, `r1 = its index`);
- if the pool is exhausted, `r0 = 0` and the full-table registers are set.

Every path is a **tail transfer** to pr, so the native port leaves `pr`
untouched and simply returns.

## What the port has to keep

- **The two-stage match**: the cursor's own entry is checked first, then the
  whole pool is scanned; the two are different loops with different register
  outcomes.
- **The cursor advance is unconditional on the found path** (`cursor + 1`),
  and the wrap is a `>= 120` test on the *re-read* cursor (u16).
- **The full path's registers**: `r2 = r3 = FULL_TABLE + 44`, `r5 =
  FULL_TABLE + 0x84`, `r6 = FULL_TABLE`, `r7 = FULL_TABLE + 2*44`, and a
  dead stack spill of `FULL_TABLE + 44` at `sp - 4` that is part of the
  captured RAM.
- **`r0` on the full path is 0**; the hint `r1` is the scan's end index (120).
- The whole unit runs under FPSCR `0x00024001` (the dispatcher gate), but the
  leaf itself uses no FP.

## Everything else

The full-register/full-table constants (`FULL_TABLE = 0x0C29F2F0`,
`FULL_STRIDE = 44`, `FULL_EXTRA = 0x84`) come from the literal pool / checker
table of the 2D sprite path; the leaf leaves them in registers untouched.
