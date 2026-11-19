# Native point clamp — 0x8C09F5F8

The pose-post point clamp (the `point_wrap` leaf), ported to plain C as
`src/native/point_wrap.c`, closes the fight engine's motion channel next to
the quantiser (0x8C09F500, `src/native/pose_turns.c`).  At runtime there is
**no guest SH-4 code, no adapter, no emulator and no disc service** — the
whole function is this one plain-C leaf.

The authority is the readable port `src/fight/point_wrap.c` (entry
`vf3_point_wrap_entry`, entry register R4 = the point).  The native signature

```c
void vf3_native_point_wrap(vf3_native_aim *a, uint32_t sp, uint32_t pt);
```

takes `sp` = the entry stack pointer (r15) and `pt` = the three-float point
(r4).  The six clamp inputs fr4..fr9 are read from `a->fr`, exactly as the
wrapper leaves them.  The differential test `tests/point_wrap_native_replay.c`
runs both sides on the same seeded fixtures and compares the **whole**
caller-visible region (the point and the two scratch words under the frame)
plus the restored caller registers (r0, r15, pr and the T bit).

## What the function does

The point `(x, y, z)` at `pt` is clamped and folded back into the ring's
period.  Nothing happens when the global word at `0x0C29B864` has any bit of
`0x0C000000` set — the point is left alone and r0 = pt.

Otherwise each component is clamped to `±655360.0` (fr1 / fr0 hold the
bounds), then `x` and `z` are folded into the period by adding or
subtracting the period fr9 (65536) until they sit in
`[fr6 .. fr4] = [-32768 .. 32768]`, and if either `|x|` or `|z|` is still
above fr7 (24576) the `y` component is reflected about fr5 and the folding
starts over.  The period-bounds arithmetic is add/sub, compare and
sign-masking on exactly representable floats, so plain C float operations
reproduce the guest bit for bit.

The three components are written back at `pt`, `pt+4` and `pt+8`, `r4`
advances by 12, and r0 = the advanced pointer.  The two `|component|` values
are left in the frame at `sp-8` (f+0, `|z|`) and `sp-4` (f+4, `|x|`) — part
of the caller-visible RAM the test checks.

## Registers and stack

The leaf is **call-free and never touches pr**.  It takes fr4..fr9 as inputs,
mirrors every float register it touches (fr0, fr1, fr2, fr3, fr10, fr11) and
restores the rest, so the register file it leaves is the original's.  Its
only integer writes are r4 (the point), r5/r6 (the y/z pointers) and r15,
which comes back to the entry sp.  There is no prologue/epilogue — r15 is
parked at `sp-8` (the frame) only while the `|x|`/`|z|` scratch words are
live and is restored to the entry sp at the return.

## FPU, or lack of it

The guest's clamp/fold arithmetic is pure add/sub and compare on values that
are exactly representable as floats (coordinates, the ±655360 bounds and the
65536 period), so the native port uses plain C `float` operations — no
`sh4_fpu` needed, the same decision as `pose_turns`.  Every written value is
**exact**, which is why the differential uses a strict byte-exact compare
(an integer stored in RAM interprets as a denormal float ~1e-40, which a
float-tolerance compare would treat as "close").

## Proof

* `tests/point_wrap_native_replay.c` — 8 differential cases against the
  readable chain: an in-range point (no clamp/fold/reflect), the +655360
  clamp, the −655360 clamp, a large point that folds down, a point that
  still reflects `y`, the negative folding direction, and the gate blocking
  the body (both the full mask and a partial `0x04000000`).  All pass.
* `tests/point_wrap_native_mutations.json` + `tools/mutate.py` — **8/8
  mutations caught** (each rebuilds and requires the differential to fail):
  the reflect check compared against the upper bound instead of fr7, the
  fold's upper threshold moved to the wrong bound, the fold's lower add
  turned into a subtract, the reflect `x`-adjustment sign flipped, the `y`
  reflection reduced to a no-op, and the two clamp bounds and the gate mask
  each off by one.

Two tempting mutations are **not** in the list because they turn the port
into a non-terminating loop, and `mutate.py`'s test run has no timeout — the
exact trap documented in AGENTS.md.  Flipping the reflect check (the `>` of
`fr7 > |x|` reversed) makes an in-range point reflect back and forth between
`-32668` and `100` forever, and changing the fold's upper subtract into an
add makes the value climb by the period without bound.  Each is instead
covered by a terminating mutation that changes the *threshold* or the
*sign* of the same decision, which a boundary case still catches.

## A note for future ports

The pose-post family's last piece is the wrapper 0x8C09F432
(`src/fight/pose_post.c` `vf3_pose_post_entry`), which chains five point
clamps around two quantiser calls with the six floats fr4..fr9
(32768/16384/−32768/24576/0/65536).  Point wrap and the quantiser are both
native leaves now, so the wrapper's native step is to establish those six
floats and the actor pointers and call them in the guest's order — the
natural next milestone.

## A note on the mutation gate's file state

`mutate.py` rebuilds and runs the test after each mutation, and restores the
source in its `finally` block **only if the process ends normally**.  When a
mutation hangs the test and the run is killed, the port's source is left in
the *mutated* state and the stale object can carry the wrong code if ninja
does not recompile it.  After any interrupted run, restore the port's source
from the clean copy, delete its `.obj` so ninja cannot keep a stale object,
and re-verify the differential before trusting the next result.
