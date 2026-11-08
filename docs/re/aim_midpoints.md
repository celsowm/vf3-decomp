# Aim midpoints (0x8C09E428)

`src/fight/readable/aim_midpoints.c`, registered as `aim_midpoints`,
proved against the retained generated translation by
`tests/aim_midpoints_replay.c` (7 differential cases) and against the
**oracle** by `tests/aim_midpoints_oracle.c` (4/4 on the
native_pose_orchestration_s29_v1/f_8c09eaf2.cases corpus, served 4 times).
10/10 mutations caught (tests/aim_midpoints_mutations.json).

The function is the aim-frame half of the pose orchestration. r4 is the
actor, r5 is the caller's pointer, saved in a sixteen-byte frame under
the two saved words (r14, pr). The frame holds the saved r5 at +0 and
three midpoints of the actor's pose-field halfwords at +8, +12 and +4:

* frame +8  = mid(actor[0x1F86], actor[0x1F56])
* frame +12 = mid(actor[0x1F88], actor[0x1F58])
* frame +4  = mid(actor[0x1F8A], actor[0x1F5A])

where mid(second, first) is the guest's exact halfword arithmetic:
zero-extend both operands, sign-extend the difference from sixteen bits,
shift it right **logically** (`shlr`, leaving the shifted-out bit in
SR.T), add it to the second operand and mask back to sixteen bits. With
a negative difference that is not the signed average. The field offsets
come from the literal pool (0x0C09E4AA/AC/AE) at run time.

Then, in order: 0x8C09D452 (pool 0x0C09E4B8) with the three midpoints as
**values** (r4 = +4, r5 = +12, r6 = +8); `rotate_z` (0x8C03C940) with
the pool angle at 0x0C09E4B0 (0x4000); `store_keep_translation`
(0x8C09D4E6) with r4 = the saved r5 pointer; `matrix_copy`
(0x8C03B530) with r4 = actor + the pool offset at 0x0C09E4B2 (0x400)
and r5 = the saved r5 pointer again; and a **tail transfer** to
`matrix_pop` (0x8C03C4A0, pool 0x0C09E4C4) with r4 = 1, after popping
pr and restoring r14 in the jmp delay slot. The first call is
`matrix_push` (0x8C03C4F0) with r4 = 0.

Details the port has to keep:

* the midpoints are stored in the order +8, +12, +4, and the frame's +0
  word is the saved r5 - both are part of the captured RAM;
* the tail transfer needs `vf3_guest_tail_call` with the popped pr;
* the fixture needs a matrix-stack window (the control block at
  0x0C19D2E4, count 1 / limit 16) because the body opens with a push and
  closes with a pop, and the literal pool window has to carry
  store_keep_translation's own pool word at 0x0C09D58C (0x0C03B620) as
  well as this body's - a fixture that leaves that word patterned makes
  the *reference* jump to pattern RAM.

Two mutations are unobservable and are not in the gate:

* signed vs logical right shift of the midpoint difference: the
  difference is a sixteen-bit sign-extended value, so both shifts agree
  in the low sixteen bits that the result masks to, and both leave the
  same bit in T. Verified by hand-mutation: the test still passes.
* swapping the r5/r6 values handed to 0x8C09D452: the push at entry and
  the tail pop at exit restore XMTRX, so 09D452's rotations leave no
  trace in the final registers or RAM. Also verified by hand-mutation.

The oracle leg is indirect: 0x8C09E428 has no corpus of its own, so the
readable port is served inside the 0x8C09EAF2 orchestration corpus whose
call tree reaches it, and the test counts the hook hits (4 of 4 cases).
