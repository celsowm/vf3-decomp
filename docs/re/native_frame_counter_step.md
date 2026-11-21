# native frame_counter_step (0x8C0CC334)

`src/native/frame_counter_step.c` (`vf3_native_frame_counter_step`) is the
plain-C port of the readable `src/fight/frame_counter_step.c`
(`vf3_frame_counter_step_entry`), proved by
`tests/frame_counter_step_native_replay.c` and the mutation gate
`tests/frame_counter_step_native_mutations.json`.

## The function

A self-contained FP leaf (call-free).  `r4` points at an object (word
counter at `+0x1E`, word table value at `+0x1C`, floats at `+0x10` /
`+0x0C` / `+0x14`), `r5` at a flag word, `r6` / `r7` at two halfword tables,
`[the caller's sp]` at a third (a pointer), and `fr4` / `fr5` are speeds.

It steps a looping frame counter and the two floats it drives:

1. The counter is decremented.  If that goes negative, the routine only
   clears flag bit 0 and stops.
2. Otherwise the counter is stored back, its low five bits index a halfword
   table (`r6` when flag bit 1 is set, `r7` when bit 2 is clear, else the
   stack-passed one, whose *pointer* sits at `[sp]`), and the entry goes to
   `+0x1C`.
3. The float at `+0x10` is advanced by `-0.0018` and floored at `-0.006`.
4. A non-zero `fr4` then also moves the floats at `+0x0C` and `+0x14` by
   `fr4` / `fr5` times `(31 - counter) * 0.032`.

## What the port has to keep

- **The float arithmetic goes through the engine's rounding.**  The corpus
  FPSCR `0x00024001` (RM=truncate + FTZ) is in force, so the add and multiply
  use the round-toward-zero + FTZ wrappers and the two fused multiply-adds
  (the `fmac`s) use `fmaf` (one round) - the stored floats match the guest
  bit for bit.
- **`[sp]` is a pointer to the table, not the table.**  The guest reads the
  word at `sp` and dereferences it as the table base; the flag-bit-2 arm is
  exercised by storing the third table's address there.
- **The counter check is signed on the decremented value.**  A counter of 1
  decrements to exactly 0 and takes the normal path; the negative path only
  fires below 0.
- **The floor is a `fcmp/gt` on the floored advance.**  `F(6)` after the
  `-0.0018` add is replaced by `F(7)` (the `-0.006` floor) when `F(7) > F(6)`.
- **The table index is the low five bits of the counter, left-shifted by one**
  (a halfword index), so entry counters with bits above 5 wrap.
- **The move is gated on `F(4) == 0`.**  A zero `fr4` (`still`) skips the
  `+0x0C` / `+0x14` move entirely, and the T bit reflects `still`.
- **r13 round-trips through the stack.**
- `r0` is 16 on the still path and 20 on the move path; `r1` is the counter
  (initial on the negative path, then counter&31); `r2` / `r3` and the flag
  word are written only by the negative path.

## FR / FPUL outputs

`fr6` = the floored advance (or the moved value on the still-skipped path),
`fr7` = the floor `-0.006` (later the moved float at `+0x14`), `fr8` =
`-0.0018` (later the moved float at `+0x0C`), `fr2` = 0.032, `fr0` = the
scale product, `fr3` = 0 on the move path.  `FPUL` = `31 - (counter & 31)`
on the move path.

## Proof

`tests/frame_counter_step_native_replay.c` seeds the same object, flag word
and three tables, runs both the readable guest and the native port, and
compares the written RAM (`+0x1C`, `+0x1E`, `+0x0C`, `+0x10`, `+0x14`, the
flag word), the output registers (`r0`/`r1`/`r2`/`r3`/`r5`/`r13`), the T
bit, `FPUL` and all 16 FR-bank words.  Ten cases cover the normal move, the
three table-select arms (bit 1, bit 2, neither), the `still` (fr4=0) skip,
the negative path, counters 0 / 31 / 63 (wrapping) / 33 (high bits) / 1
(the exact-0 boundary), and the `-0.006` floor of a large negative float.

## Mutation gate

`tests/frame_counter_step_native_mutations.json`: `8/8` caught - the counter
decrement, the floor's compared register, the `still` test's inversion, the
table-select flag bit, the `-0.0018` advance operand, the unmasked table
index, the `+0x14` store destination, and the negative-path comparison
bound.
