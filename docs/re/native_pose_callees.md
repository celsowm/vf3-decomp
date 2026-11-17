# Native pose-orchestration callees

State: four of the pose orchestration's callees are natively re-implemented in
`src/native/` on the shared `vf3_native_aim` context, and each is proved against
its readable guest authority by a differential replay plus a mutation gate:

| entry                | native port            | readable authority                 |
|----------------------|------------------------|------------------------------------|
| 0x8C09D4B0 halfword  | `halfword_frame.c`     | `src/fight/halfword_frame.c`       |
| 0x8C09E428 midpoints | `aim_midpoints.c`      | `src/fight/readable/aim_midpoints.c` |
| 0x8C09E4C8 basis     | `matrix_basis.c`       | `src/fight/matrix_basis.c`         |
| 0x8C09DCDC facing    | `facing_update.c`      | `src/fight/facing_update.c`        |

`tests/native_pose_callees_replay.c` (`vf3nativeposecallees`) runs six cases
against the same flat matrix RAM - two for halfword_frame, one each for the
others, plus the two extra facing_update shapes (the y-override path and the
special-kind path) - and compares the caller-visible output regions and the
final XMTRX:

```
== halfword_frame (0x8C09D4B0) c0   region: match
== halfword_frame (0x8C09D4B0) c1   region: match
== aim_midpoints (0x8C09E428)       region: match
== matrix_basis (0x8C09E4C8)        region: match
== facing_update (0x8C09DCDC)       region: match
== facing_update (0x8C09DCDC) y-override      region: match
== facing_update (0x8C09DCDC) special-kind    region: match
native_pose_callees_replay: PASS
```

The mutation gates are all green - halfword_frame 4/4, aim_midpoints 6/6,
matrix_basis 4/4, facing_update 5/5:

```
python tools/mutate.py --port src/native/facing_update.c --exe build/vf3nativeposecallees.exe \
  --mutations tests/pose_callees_facing_update_mutations.json --target vf3nativeposecallees
```

The guest ports are the authority (they were promoted against the oracle); the
native port is a re-implementation, so the residual is the FPU difference
(`fsca`/`fsrra`/`ftrv`/`fmac` against `sinf`/`cosf`/`sqrtf`/`fmaf`), tolerated
at 2e-3 in the differential.  The shared matrix helpers live in
`src/native/aim_math.c` (mirroring the `motion_aim` port); the public API is
`src/native/pose_callees.h`.

## Region scoping

The four callees call matrix helpers that push/pop an external matrix stack
(0x0C19D400) which the native context keeps in its own struct, and the frames
they reserve hold sub-callee scratch that is not part of the caller-visible
contract.  The differential therefore compares explicit caller-visible ranges -
the object/record/character region below 0x0C20D000 and each callee's own frame
- and deliberately excludes the sub-callee scratch below the frames, exactly as
the aimframe test does.

## Facing_update: the two fixture shapes

0x8C09DCDC is the largest of the four and has three fixture shapes, because one
fixture cannot reach every testable path with a *small* change in output:

- **base (seed_fu)**: r12 == 0 and r13 == 0, so both the outer heading/pitch
  clamps and the turn-table bias are live.  `obj+97 = 11` selects the
  turn-table row `TURN_TABLE + 22` (0x0000) whose +2 neighbour (0x0400) is the
  value the `ena_turn_table_bias_offset_wrong` mutation wrongly reads; at
  `pitch = 0` the local pitch angle is small (`atan = 0x15b`), so
  `-atan = -0x15b` sits just inside the ±0x100 pitch clamp and the +0x0400
  neighbour pushes `r5` to +0x2a5, clamping to +0x100 - a different result.
- **y-override (seed_fu2)**: `+72 = 0x20` hits the mask, so r13 != 0 and the
  mixed position adds the +0x2308 offset to `p84.y`; the outer clamps are
  skipped.
- **special-kind (seed_fu3)**: the kind halfword is 0x886, so `special = 1` and
  the `if (!special)` heading/pitch limits must be skipped.  `+72 = 0x20` makes
  r13 != 0, so the mixed position is (anchor.x, anchor.y + 0x2308, anchor.z) =
  (-1000, 0, 0), whose local-frame heading is near -0x8000 (`atan = -0x7fe2`).
  A mutation that stops recognising 0x886 takes the non-special branch, whose
  heading clamp (lim = 0x3800) bites on `SExt16(atan + 0xC000) ~ +0x401e` and
  changes the committed heading - observable only here, because the earlier
  fixture shapes left the clamp with nothing to bite.

## Details the ports have to keep

- **halfword_frame** carries the third call as a tail transfer via
  `vf3_guest_tail_call` (the guest pops pr and jumps), and its `jsr` delay slot
  runs before the callee.
- **aim_midpoints** computes the three midpoint halfword pairs as
  `(u16 second - u16 first)` then re-sign-extends from 16 bits; a difference
  with the top bit set (the `0xFFFF - 0x10` wrap on the +8 pair) is where the
  `(int16_t)` reinterpretation matters.  The +4 pair is the swap boundary
  (`mid(0, 0x8000)` differs from `mid(0x8000, 0)` by half a turn), which makes
  `midpoint_operands_swapped` observable.
- **matrix_basis** must publish the row at the pool's offset and keep the fused
  `mac` rounding (`fmaf`, not `a*b+c`), and negate the second xform column.
- **facing_update** reproduces the atan lookup from the table at 0x0C0EAF60
  scaled by 15000, keeps the two `OBJ+97 == 12 ?` ternary limits, and masks the
  heading/pitch exactly as the guest's sign-extended 16-bit arithmetic does.

## Excluded unobservable mutations

Math that is identical after the FPU truncation cannot be a mutation the test
can see; the mutation lists carry the reason and leave those out, following the
AGENTS precedent:

- **aim_midpoints**: `arithmetic_shift_not_logical` is dropped (a logical shift
  and an arithmetic shift of a 16-bit value agree after the 16-bit mask).

Every listed mutation is otherwise exercised by one of the fixtures, so a
mutation the test cannot see is a path the fixture never reaches.
