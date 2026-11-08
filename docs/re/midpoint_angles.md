# Midpoint angles (0x8C09D452)

`src/fight/readable/midpoint_angles.c`, registered as `midpoint_angles`,
proved against the retained generated translation by
`tests/midpoint_angles_replay.c` (7 differential cases) and against the
**oracle** by `tests/midpoint_angles_oracle.c` (4/4 on the
native_pose_orchestration_s29_v1/f_8c09eaf2.cases corpus, served 4 times).
9/9 mutations caught (tests/midpoint_angles_mutations.json).

The wrapper takes three angle values in r4, r5 and r6, saves them as
halfwords in a twelve-byte frame (r4 at the frame's first word, r5 at
+4, r6 at +8, under the saved pr), then:

* `rotate_z` (0x8C03C940, pool 0x0C09D580) with r6's halfword,
* `rotate_y` (0x8C03C880, pool 0x0C09D584) with r5's halfword,
* a **tail transfer** to `rotate_x` (0x8C03C6C0, pool 0x0C09D588) with
  r4's halfword.

Each halfword is read back sign-extended (`mov.w`) and zero-extended
(`extu.w` in the jsr/jmp delay slot), so the callee sees the low sixteen
bits - while r0 keeps the sign-extended second halfword. The tail
transfer pops pr in the jmp delay slot, so rotate_x runs in the caller's
frame; r14 is never touched. The handler pointers are read from the
literal pool at run time.

The oracle leg is indirect: the goldens_d452_tail specimen records its
exit at the tail-transfer boundary, *before* the final rotate_x runs
(the existing transliteration in src/fight/sh4_matrix.c models exactly
that boundary), so a full-body port cannot be routed at it directly.
Instead the test serves the readable port inside the 0x8C09EAF2
orchestration corpus, where 0x8C09D452 runs as a subroutine, and
counts the hook hits (4 of 4 cases).
