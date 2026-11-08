# Pose orchestration (0x8C09EAF2)

`src/fight/readable/pose_orchestration.c`, registered as
`pose_orchestration`, proved against the retained generated translation
by `tests/pose_orchestration_replay.c` (4 differential cases).
12/12 mutations caught (tests/pose_orchestration_mutations.json).

The function is the pose orchestration. r14 is the actor (set by the
caller), r5 is the caller's argument kept in r12. It reserves a
228-byte frame under the saved pr/MACL, snapshots XMTRX into the frame
at +0xA4/+0x64/+0x24, then:

* seven_pass (0x8C09DA72) and root_orientation (0x8C09D9EA) on the
  actor;
* matrix_set_translation (0x8C03CBD0) with the pose-vectors base at
  actor+0x1EFC;
* three xf_store (0x8C03B820) copies of the XF translation into the
  frame at +0x94/+0xD4/+0x54;
* matrix_push (0x8C03C4F0) with 0;
* halfword_frame (0x8C09D4B0) with the field at actor+0x1F56 and the
  halfword at actor+0x22E4;
* three float sums of the actor's 0x208C/0x1F08, 0x2090/0x1F0C and
  0x2094/0x1F10 pairs into the frame at +24/+28/+32, then unit_triple
  (0x8C09DC34) on that triple;
* store_keep_translation (0x8C09D4E6) and matrix_copy (0x8C03B530)
  between the frame's +0xA4 snapshot and actor+0x180;
* the kind record's first floats (0x0C10D3C4 + kind*108, in r13) into
  the frame at +12/+16/+20, two xform_point (0x8C03B450) calls with
  the caller's r12 (+12 and +0) as destinations;
* matrix_push with 0 again;
* the kind==12 table branch: r11 is a code/object pointer from the
  table behind the pool at 0x0C09EC40 (entry +8 when the kind byte at
  actor+97 is 12, else the entry at actor byte +0x420B times four),
  then facing_update (0x8C09DCDC) on the actor;
* three more kind-record floats (+12/+16/+20) into the frame, an
  xform_point, matrix_pop with count 1 and matrix_push with 0;
* aim_frame (0x8C09E060) twice - with output blocks at actor+0x200
  and actor+0x300 - with the stack argument lists the guest builds at
  actor+0x640/0x1F62/0x680/0x1F74 and the kind record's +24/+36
  triples, each followed by matrix_pop with count 1;
* kind floats +48..+60 shuffled into the frame at +52..+60, an
  xform_point, aim_midpoints (0x8C09E428) and matrix_basis
  (0x8C09E4C8) on the actor, matrix_push with 0;
* aim_frame_b (0x8C09E6B2) twice - with the objects at actor+0x480
  and actor+0x540 - the first with its full stack list, each followed
  by matrix_pop with count 1 and matrix_push with 0;
* and the epilogue, which adds the pool offset 0x13C and pops macl, pr,
  r8..r13 and finally r14 in the rts delay slot - the guest's sp ends
  28 bytes above the entry sp, and the test checks that against the
  fixture.

Every pool offset and call target is read from the literal pool at run
time. All of the body's code callees are themselves readable ports, so
the differential exercises the readable chain end to end.

Two port bugs the differential caught while writing this: r7 in both
aim_frame sections is the pool halfword offset first and only *then*
has r14 added once (my first version added the actor twice, giving
0x18401F20 where the guest has actor+0x1F20 - caught by the OOB
counter in the fixture), and the pool window must carry the real
image bytes because the callees (facing_update, aim_frame,
aim_frame_b, unit_triple) read their own literal pools from the same
0x0C09E000 region - pattern bytes there shadow the values they
dispatch through, and the generated chain jumps to pattern RAM.

## Oracle leg

There is **no usable direct oracle leg** for this entry, and the
reason is a corpus limitation, not a port defect: the
native_pose_orchestration_s29_v1 corpus's actor windows end before
actor+0x420B, which the kind!=12 arm reads (kind 11 in the Akira cases,
kind 3 in the Jacky cases - both take that arm). Replaying the
*generated* body through the same harness misses the same byte
(2/4 cases fail with oob=1 at the first generated callee whose `rts`
returns `ram->oob==0`), so the corpus cannot replay this entry
through the C harness in either arm. A recapture with a wider actor
window (covering +0x420B) would close the direct leg; until then the
entry's oracle evidence is the three indirect legs through this same
corpus - root_orientation (0x8C09D9EA), aim_midpoints (0x8C09E428)
and midpoint_angles (0x8C09D452), each served 4 times with the whole
specimen compared - plus this differential. The earlier
matrix_family batch replay of the generated body (192/192, see
docs/decomp_status.csv) used a different harness whose shadows cover
the byte.
