# native vertex_emit_sq (0x8C048BE0)

`src/native/vertex_emit_sq.c` (`vf3_native_vertex_emit_sq`) is the plain-C
port of the readable `src/fight/vertex_emit.c`
(`vf3_vertex_emit_sq_entry`), proved by
`tests/vertex_emit_sq_native_replay.c` (5 differential cases) and the
mutation gate `tests/vertex_emit_sq_native_mutations.json` (12/12 caught).

## The function

A call-free FP leaf with no guest callees and no stack frame - the only
control transfer is the final tail transfer to `pr`.  It is the store-queue
emitter of the strip transformers, the sibling of the already-ported
clip-ring emitter (`vertex_emit_ring`, 0x8C048C20).  `vertex_light`
(0x8C048B00) leaves a lit, transformed vertex in registers

```
FR4 = w'  FR5 = y'  FR6 = z'  FR7 = 1/x'   FR2 = diffuse  FR3 = specular
r1, r2 = the record's two trailing words (w1, w2)
```

with `r6` = the store-queue slot start, `r5` = the input cursor and `r3` =
the vertices left in the strip.  The emitter perspective-scales y',z' by
1/x' (the FPSCR-aware multiply), packs the vertex into the 32-byte slot at
`r6`:

```
+00 ctrl  +04 FR5  +08 FR6  +0C FR7  +10 r1  +14 r2  +18 FR2  +1C FR3
```

and overwrites the control word with the slot address for an in-strip
vertex, or `(slot + 0x14) >> 1` (the end-of-strip flag) for the last one.
Out: `r3--` (SR.T set when it reaches 0), `r2` = the tail value, `r5 += 32`,
`r6` one slot on.  The final PREF of the flushed slot is a store-queue
write-back, a no-op without SQ modeling.

## What the port has to keep

- **The two perspective scales are FPSCR-aware multiplies** (rounding
  `fpscr & 1`, FTZ when bit `0x40000`), same wrapper as
  `vertex_writer`/`float_blend`; the scaled y',z' are written back to FR5
  and FR6 as well as into the slot.
- **The vertex coordinate stores use the FR bank** (FR4 at +00, FR5 at +04,
  FR6 at +08, FR7 at +0C) and the diffuse/specular terms (FR2 at +18, FR3
  at +1C); `r1`/`r2` at +10/+14 are pure copies.
- **The end-of-strip flag is `(slot + 0x14) >> 1`** stored at the slot's
  control word only for the last vertex (`(r3 - 1) == 0`); everything else
  gets the slot address, and `r2` always gets the tail value.
- **`r3--` sets SR.T = (the decrement reached 0)**, `r5` and `r6` advance by
  one slot, and `pr` is untouched (tail transfer).

## Everything else

`vertex_emit_sq` was a genuinely call-free, un-nativized leaf.  Together with
`vertex_emit_ring` and `vertex_writer` (0x8C056AA0 / 0x8C056AE0 / 0x8C056B20)
it completes the transformed-vertex emitter family in plain C.
