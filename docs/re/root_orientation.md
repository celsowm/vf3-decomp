# Root orientation (0x8C09D9EA)

`src/fight/readable/root_orientation.c`, registered as `root_orientation`,
proved against the retained generated translation by
`tests/root_orientation_replay.c` (7 differential cases) and against the
**oracle** by `tests/root_orientation_oracle.c` (4/4 on the
native_pose_orchestration_s29_v1/f_8c09eaf2.cases corpus, served 4 times).
10/10 mutations caught (tests/root_orientation_mutations.json).

The function builds the actor's root orientation in XMTRX from the actor's
own angle fields. It resets the matrix bank to the identity
(0x8C03CCB0, pool 0x0C09DAD8) and composes, in order:

* `rotate_y` (0x8C03C880, pool 0x0C09DADC) with the actor's yaw halfword at
  +30 (+0x1E), **sign-extended** - a plain `mov.w`, no `extu` in the jsr
  delay slot;
* `rotate_z` (0x8C03C940, pool 0x0C09DAE0) with the first pose field, at
  the pool halfword offset 0x0C09DACC (0x1F50), **zero-extended** - the
  `extu.w` sits in the jsr delay slot;
* `rotate_y` again with the second pose field, at 0x0C09DACE (0x1F52),
  zero-extended;
* a **tail transfer** to `rotate_x` (0x8C03C6C0, pool 0x0C09DAE4) with the
  third pose field, at 0x0C09DAD0 (0x1F54), zero-extended. The guest pops
  pr at 0x0C09DA12 and restores r14 in the jmp delay slot, so rotate_x
  runs in the caller's frame and returns to the caller's caller.

Details the port has to keep:

* the three field offsets and the four call targets are read from the
  literal pool at run time, as the guest reads them - the test supplies
  the pool with the real image values;
* the yaw/field extension asymmetry above (only the caller-visible r4
  differs; the callees truncate the angle to 16 bits in FSCA, so the
  sign-vs-zero choice is unobservable in the result - the mutation gate
  does not carry it, and this is why);
* the tail transfer needs `vf3_guest_tail_call` with the popped pr, not
  the shared `vf3_guest_call`, which would force a 0x0C return address;
* r14, r15 and pr are restored, r0 ends as the last pool offset
  (0x1F54), r3 as the tail target and r4 as the third field; XMTRX is a
  pure rotation (translation elements 12..14 stay zero, element 15 is the
  w component).

The oracle leg is indirect: 0x8C09D9EA has no corpus of its own, so the
readable port is substituted into the 0x8C09EAF2 orchestration corpus
whose call tree reaches it (ops.json lists the whole 0x0C09D9EA body),
and the specimen's recorded exit state - the actor window, the XF bank,
FPUL, the exit PC and every RAM byte - is compared against the oracle.
The test counts the hook hits (4 of 4 cases) so the leg cannot pass
vacuously.

This is the orientation the native motion track was missing: the native
`motion_pose.c` rig builds row 0 from an authored REST_TORSO constant,
while the guest builds it from yaw and the first three pose fields through
this exact call chain. The native port can now mirror it with
`vf3_native_matrix_euler_z_y_x`-style composition instead of the guessed
bind rotation.
