# native vertex_writer (0x8C056AA0 / 0x8C056AE0)

`src/native/vertex_writer.c` (`vf3_native_vertex_writer0` /
`vf3_native_vertex_writer1`) is the plain-C port of the readable
`src/fight/vertex_writers.c` (`vf3_vertex_writer0_entry` /
`vf3_vertex_writer1_entry`), proved by `tests/vertex_writer_native_replay.c`
(6 differential cases) and the mutation gate
`tests/vertex_writer_native_mutations.json` (11/11 caught).

## The functions

Call-free FP leaves with no guest callees and no stack frame - the only
control transfer is the final tail transfer to `pr`.  They are the first two
writers of the TA (Tile Accelerator) triangle-strip builder; the third,
`push_offset` (0x8C056B20, `vf3_native_push_offset` in `src/native/push_offset.c`),
is already ported.  Each fills one 32-byte TA vertex slot from a register-
passed contract:

- `r8` -> the stream record of the strip's first vertex (three `s16` per
  vertex: index, u, v; writer n reads the (u, v) of vertex n),
- `r12` = the store-queue cursor, `r6` = the parameter control word,
- `FR3` = the texture scale, and the vertex itself in `FR4..FR7` (writer 0)
  or `FR8..FR11` (writer 1),

and writes the slot

```
+00 r6   +04 x  +08 y  +0C z   +10 u*scale  +14 v*scale  +18 w  +1C 0
```

Writer 0 leaves the cursor where it is (the slot is flushed later by the next
writer's PREF); writer 1 flushes the old slot (a store-queue write-back, a
no-op without SQ modeling) and moves the cursor on by one slot.  Both leave
`r0 = 0`; `r8` is unchanged.

## What the port has to keep

- **The two uv values are `s16`, sign-extended and converted to float, then
  scaled by `FR3`.**  The scale is the FPSCR-aware multiply (rounding
  `fpscr & 1`, FTZ when bit `0x40000`), same wrapper as `float_blend`.
- **The vertex coordinate stores use the FR bank**: writer 0 stores
  FR4/FR5/FR6/FR7 at slot +4/+8/+0C/+18, writer 1 the same with FR8..FR11.
  The `vertex_fr` base index is part of the contract.
- **The u/v scaled values are also left in FR2 (us) and FR1 (vs)** (the guest
  computes the texture address pair into the FR bank before storing), and the
  sign-extended `u` in `r3`, `v` in FPUL.
- **Writer 1's contract includes the cursor advancing by one slot** and its
  PREF of the previous slot being a no-op.

## Everything else

`vertex_writer` was a genuinely call-free, un-nativized pair (the address-
based sweep against `src/native` lists both entries as un-nativized, and
`vertex_writers.c` holds exactly these two entries with zero
`vf3_guest_call` sites), making it the natural partner of the already-ported
`push_offset`.  Its register values exercise exact `s16` -> float conversion
and the FPSCR-aware scale, proved by the differential and the mutation gate.
