# native extent_flip (0x8C0CC3F0)

`src/native/extent_flip.c` (`vf3_native_extent_flip`) is the plain-C port of
the readable `src/fight/extent_flip.c` (`vf3_extent_flip_entry`), proved by
`tests/extent_flip_native_replay.c` and the mutation gate
`tests/extent_flip_native_mutations.json`.

## The function

A self-contained FP leaf (call-free, no stack frame).  `r4` points at six
floats `a0 a1 a2 b0 b1 b2`, `r5` at a flag word, and `fr4` is a limit.  It
rewrites the record, mirroring its y/z pair:

    a0 = a0 + b0
    a1 = a1 + b1
    a2 = -(-b2 - a2) = a2 + b2

(The third line is the signed double negation: the SH-4 flips `b2`'s sign
bit, subtracts `a2`, and flips the result's sign bit again - so the answer
is `a2 + b2` apart from the signs of zeros.)

Unless the flag word's bit 1 (`0x2`) is set, `a1 + b1` is floored at `fr4`:
when it is not above `fr4` it is replaced by `fr4` and the flag word's bit 0
is cleared.

## What the port has to keep

- **The adds go through the engine's rounding.**  The corpus FPSCR
  `0x00024001` (RM=truncate + FTZ) is in force, so the three float
  add/subtractions use the same round-toward-zero + FTZ wrappers the other
  FP native ports use; the stored floats match the guest bit for bit.
- **The `a2` answer is a signed double flip, not a plain add.**  `fr7` is
  `-b2`, then `fr7 - a2`, then the sign flipped again.  A port that wrote
  `a2 + b2` directly would get the zeros' signs wrong.
- **`fcmp/gt FR4,FR5` sets T = (fr5 > fr4).**  When `a1+b1` is *not above*
  the limit, T is clear and the clamp runs; when it is above, T is set and
  the sum is kept.
- **The clamp has two register writes.**  Only on the clamp arm does `r2`
  hold the masked flag word (bit 0 cleared) and `r3` hold `0xFFFFFFFE`; the
  other arms leave them untouched.  `r0` is `flags` on entry and `8` on
  exit.  `r4`/`r5` are preserved.

## FR-bank outputs

`fr2 = a2` (entry), `fr3 = -b2`, `fr5` = the `a1` result (sum or the clamp),
`fr6 = a0 + b0`, `fr7 = a2 + b2`.  `fr4` is the limit and is preserved;
everything else is preserved.

## Proof

`tests/extent_flip_native_replay.c` seeds the same RAM and FR bank on both
sides and runs the readable guest and the native port, comparing against an
independent fixture model: the three output floats, the flag word, `r0`,
`r2`/`r3` (on the clamp arm only), the T bit, the five FR-bank outputs, and
all untouched registers/FR.  Six cases cover the keep-as-is arm (bit 1 set),
the above-limit arm (T set), the clamp arm (bit 0 cleared + `r2`/`r3`
written), the exact `a1+b1 == fr4` boundary, single-precision rounding
visibility, and a negative-sum clamp.
