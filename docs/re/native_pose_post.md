# Native pose post-processor (0x8C09F432)

`src/native/pose_post.c` ports the pose post-processor wrapper natively, as a
plain-C `vf3_native_pose_post(a, sp, actor)` on the `vf3_native_aim` context,
in the same spirit as `pose_turns.c` and `point_wrap.c`.  It is the sibling
of the readable authority `vf3_pose_post_entry` (`src/fight/pose_post.c`) and
rides the two already-ported native leaves beneath it: `point_wrap`
(0x8C09F5F8) and `pose_turns` (0x8C09F500).

## What the wrapper does

The wrapper takes the actor (r4) and runs five point clamps around two
quantiser calls.  Every callee hands control back at *its input point/source
plus 12*, so the whole routing is a chain of `+12` jumps with one `+0x54`
step in the middle:

```
actor+0x1D58  -> wrap -> +12 = actor+0x1D64 -> wrap -> +0x54 + 12
  = actor+0x1DC4 -> wrap -> +12 = actor+0x1DD0 -> wrap -> +12
  = actor+0x1DDC                  (the first quantiser's source)
  -> quant(actor+0x233C)          (destination halfwords)
  -> r0 = +12 = actor+0x1DE8 -> wrap -> +12 = actor+0x1DF4
  -> quant(actor+0x2342)
  -> r0 = r5 = actor+0x1E00        (the wrapper's return)
```

Every point clamp gets the same six floats - fr4 32768, fr5 16384, fr6
-32768, fr7 24576, fr8 0, fr9 65536 - restored before each call.  The
wrapper saves r14, fr15, fr14, fr13, fr12 and pr on its stack (E-4 .. E-24)
with a twelve-byte frame under them (E-36..E-24: +0 = 16384, +4 = -32768,
+8 = the quantiser destination), and restores all of it before the return.
The epilogue also restores `a->pr` from the saved slot and leaves `r15` at
the entry `sp`, so the wrapper is stack-neutral.

## Why the wrapper tracks continuations itself

The quantiser's return contract is r0 = r5 = source+12 and r2 = r3 =
source+8, but the native `pose_turns` leaf restores every register it uses
and never writes r0/r2/r3/r5.  So the wrapper cannot read the continuation
out of the callee's registers; it computes each next source itself:

- after a point clamp, `src = a->r[0]` (the native `point_wrap` *does* set
  r0 = point+12 - or the point itself when the ring gate is shut);
- after a quantiser, `src = vec + 12` (the next point).

This matters most for the **gated** path: when the global at 0x0C29B864 has a
0x0C000000 bit set, every point clamp becomes a no-op that returns r0 = the
point (not the point+12), so the routing collapses and the destinations land
at shifted addresses.  The wrapper must follow the actual r0, not assume a
+12.

## The trap

The differential's stack range is meaningless unless it is re-seeded between
the two sides.  The first version of the test seeded only the actor region,
so the native run left the guest's just-written frame+8 word (the destination
pointer) in the stack and the "match" was the leftover, not a real
comparison.  `seed()` now paints the whole stack span with a per-address
pattern first, so every stored byte is checked for real.

## Proof

- `tests/pose_post_native_replay.c`: four differential cases against
  `vf3_pose_post_entry`, comparing the actor region, the wrapper's stack +
  callee scratch and the register contract (r0/r5 = last quantiser's return,
  r14 = entry value, r15 = entry sp, pr untouched), byte-exact:
  - **edge write (band==hi)**: both destinations written; the five points
    exercise in-range, fold-x, reflect-y, clamp and fold-negative wraps;
  - **band skip**: a band far outside the chain leaves both destinations
    junk;
  - **kind 3 negate**: a band inside the open band with kind 3 and a
    `z''` above 0x7530 negates the second destination's z;
  - **gated wraps, quantisers still run**: the ring gate freezes every point
    clamp but the two quantiser calls still run on the unwrapped sources.
- `tests/pose_post_native_mutations.json`: 8/8 mutations caught.  The list
  includes the two quantiser destinations, the first-point offset, the third
  point's +0x54 stride, the epilogue return register, the pr restore, the
  frame's 16384 float and - the one that needs the gated case - the fifth
  point source read against an assumed +12 (`fifth_point_uses_assumed_plus12`
  is caught only because the gated case collapses the routing).

One per-quantiser `R(0) = src + 12` assignment in the port is overwritten by
the epilogue's `R(0) = src` and is therefore unobservable; the gate covers the
final return with the epilogue mutation instead.
