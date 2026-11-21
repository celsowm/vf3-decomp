# native queue_ops (0x8C038570 / 0x8C038590 / 0x8C0385C0)

`src/native/queue_ops.c` (`vf3_native_queue_reset` / `vf3_native_queue_push` /
`vf3_native_queue_pop`) is the plain-C port of the readable
`src/fight/queue_ops.c` (reset / push / pop), proved by
`tests/queue_ops_native_replay.c` (8 differential cases spanning the three
functions) against the readable ports **and** an independent fixture model,
plus the mutation gate `tests/queue_ops_native_mutations.json` (9/9 caught).

## The functions

Three call-free integer leaves (no FP, no stack) that share one struct and two
global arrays.  All three are **tail transfers** to pr, so the C ports leave
`pr` untouched and simply return.

The struct lives at a global's address: the literal pool at `0x0c0385f0` holds
the *address of* the struct, `0x0c0385f4` the first array's *address* (a
single pointer: `r5 = [pool]; r5 = [r5]` reads the array's first word), and
`0x0c0385f8` the second array's.  The struct's halfword at `+6` is the queue
counter; the words at `44/48` and `56/60` carry the pair the arrays hold; the
capacity is 48.

- **reset** zeroes the counter and seeds the struct's four words from the two
  arrays' first slots.
- **push** bumps the counter by one and writes the struct's words at 44 and 56
  into the two arrays at the counter's new value; refuses `-1` once the
  counter has *reached* the limit.
- **pop** takes the arrays' slots at the counter's old value back into the
  struct - **only** the words at 44 and 56; the duplicates at 48 and 60 keep
  their old values - and decrements the counter; refuses `-1` when the counter
  is not above zero.

## What the port has to keep

- **`cmp/ge r3,r5` sets `T = (r5 >= r3)`**, so the push's "full" test is
  `counter >= 48`: the queue is full once the counter has reached the limit,
  not once it has passed it.  `cmp/gt` on the pop tests `counter > 0`.
- **The delay slot runs on both paths**: the refusal's `-1` is spilled into
  r6 (push) / r5 (pop) whether the branch is taken or not, and the answer rides
  through r0 in the delay slot of the `rts`.
- **The counter is a sign-extended halfword** in and out.
- **The pop writes 44 and 56 only**; the duplicates 48 and 60 are left alone.
- **The pool is read at run time** (it is RAM, not a constant), with two levels
  of indirection for the arrays.
- The fixture keeps the two arrays **non-aliased** (the readable's own test
  models the game's real 48-word alignment; here a stray alias made the
  independent model disagree with the guest, and the fix belongs to the
  fixture, not the port).

## Everything else

The three are hot in the state-7 census (reset 10 calls/110 self-steps, push
4/76, pop 4/72) and all are off-baseline leaves; the readable ports were
promoted with oracle legs.  The native transcriptions follow them exactly.
