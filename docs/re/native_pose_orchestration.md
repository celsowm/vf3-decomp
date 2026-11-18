# Native pose orchestration — 0x8C09EAF2

The pose-orchestration driver, ported to plain C as
`src/native/pose_orchestration.c`, is the **top of the aim/pose family**.  It
chains every native callee — seven_pass, root_orientation, halfword_frame,
unit_triple, facing_update, aim_frame (x2), aim_midpoints, matrix_basis,
aim_frame_b (x2) and the shared aim_math matrix helpers — on a single actor,
so a fully posed fighter (the blocks at actor+0x200/+0x300/+0x480/+0x540, the
SEG records, the orientation matrix and the final XMTRX) comes out of native
code alone.  At runtime there is no guest SH-4 code, no adapter, no emulator
and no disc service: the whole driver is this one plain-C function.

The authority is the readable port `src/fight/readable/pose_orchestration.c`
(entry `vf3_pose_orchestration_entry`, entry registers R15=sp0, R14=obj,
R5=arg).  The native signature

```c
void vf3_native_pose_orchestration(vf3_native_aim *a, uint32_t sp0,
                                   uint32_t obj, uint32_t arg);
```

takes `sp0` = the entry stack pointer (r15), `obj` = the actor (r14), and
`arg` = the caller's argument (r5).  The differential test
`tests/pose_orchestration_native_replay.c` runs both sides on the same seeded
fixtures and compares the caller-visible RAM ranges plus the final XMTRX and
the restored caller registers.

## Stack trajectory

The driver's `sp` local only moves by pushes and the epilogue; the frame it
opens is fixed:

```
push pr   sp0-4
push macl sp0-8
frame     f = sp0 - 228        (FRAME_OFF -228)

5 pushes  -> f-20   (aim_frame #1)
5 pushes  -> f-40   (aim_frame #1)
6 pushes  -> f-64   (aim_frame_b #1)
6 pushes  -> f-88   (aim_frame_b #2)
epilogue  sp += 0x13C  -> sp0-8, restore macl/pr/r8..r14, r15 = sp0+28
```

Five pushes persist (they are never popped by the driver); the matrix
stack push/pop helpers restore r15 to the value at their call, so the net
driver trajectory is exactly the prologue pushes and the epilogue.

## Persistent guest registers

The readable driver keeps several values in registers across calls.  The
native port writes them into `a->r[]` at the same points, because the
frame-saving callees write and restore the saved-register words identically:

| reg | meaning                         |
|-----|---------------------------------|
| r9  | the XFORM helper, before the kind transforms |
| r8  | the PUSH helper, before kind xforms |
| r10 | the POP helper, after facing_update |
| r11 | the code pointer (kind==12 branch) |
| r12 | arg                               |
| r13 | the kind record                   |
| r14 | obj (the actor)                   |

The helper addresses are held in **0x0c form** (`0x0c03b450` xform,
`0x0c03c4f0` push, `0x0c03c4a0` pop), because the guest reads them out of the
literal pool, which stores the 0x0c mirror.  The pool dump of `0x0C09EC10..`
confirmed all of them:
`KIND_TABLE=0x0c10d3c4`, `KIND_TAB2=0x0c10dabc`, `XFORM=0x0c03b450`,
`PUSH=0x0c03c4f0`, `POP=0x0c03c4a0`.

## Hardcoded constants

The driver reads its offsets and addresses from the literal pool at run time;
the native port bakes them in as constants (verified against the image
`extract/exe/1ST_READ.unsc.bin`, which the test loads).

## The w3/w5 read-offset correction

The earlier summary claimed fixes #3 and #4 replaced two kind-float reads with
pointer reads of `mem[f+0]`.  Re-derivation against the real `push_word`
(which **decrements r15 each call**) shows the original reading was right and
the "fixes" were wrong:

- **aim_b#1 w3** (read at `R(15)+52`): three `push_word`s have already run, so
  `r15 = f-40 -> f-52` and `mem[R15+52] = mem[f+0]` — the `obj+D1` pointer just
  parked at frame+0, **not** `mem[f+12]`.
- **aim_b#2 w5** (read at `R(15)+84`): five `push_word`s have run, so
  `r15 = f-64 -> f-84` and `mem[R15+84] = mem[f+0]` — the `obj+E2` pointer,
  **not** `mem[f+20]`.

Both are `ld32(a, f)`.  The tooth was proven directly: breaking w3 (reading
`f+12`) fails case 1 of the differential, and the break is caught again by the
mutation gate (`aim_b1_w3_reads_f12`, `aim_b2_w5_reads_f20`).

## The kind==12 code branch

The driver reads a code pointer r11 two ways: for **kind 12** straight from
`TAB2+8`, otherwise from `TAB2 + u8(obj+0x420B)*4`.  The fixture makes this
observable by pointing `TAB2+8` at one code block (`CODEBLK`) and every other
selector at a different one (`CODEBLK2`), so the kind-12 scenario exercises a
genuinely different callee-side block.

## Frame/stack seeds

The matrix-stack control block `0x0C19D2E4` is seeded for the guest but **not
compared** — the native callees carry the matrix stack in the `a` context
(`a->stk`), so this RAM is guest-side-only.

Range A is `0x0C200000..0x0C20F000` (the actor + work region: actor fields to
+0x420C, pose blocks, arg struct, code blocks).  Range B is `SP-324..SP+32`
(the driver frame + the restored-register slots).  Sub-callee scratch below
the deepest pushed words (`SP-324`) and the callee-side frames are left out,
as the aimframe test does.

## The epilogue is caller-visible

The readable epilogue recovers macl, pr, r8..r14 and r15 **from the stack
above the frame** (`sp0-8 .. sp0+28`), so a shift in the exit offset changes
every one of them.  Early versions compared only RAM + XMTRX and the
`epilogue_exit_offset_wrong` mutation passed unnoticed (the epilogue only
*reads*, never writes, those slots).  The test now also compares the final
`r15`, `pr` and `r8..r14` as raw words — the same check that made the exit
offset observable.

## Proof

- Differential (`tests/pose_orchestration_native_replay.c`): **4/4 scenarios
  PASS** — kinds {3, 12, 21, 0}.  Four kinds cover the kind==12 code branch and
  the ordinary selector path.
- Mutation gate (`tests/pose_orchestration_native_mutations.json`):
  **14/14 mutations caught**: frame offset, snapshot store, kind-record stride,
  the kind==12 branch, the kind-48 float landing, the copy destination, the
  root-yaw offset, both aim-frame frame sizes (340/348), the epilogue exit
  offset, the D1 park, the w3/w5 read offsets, and the aim#1 block offset.

Run with:

```
python tools/mutate.py --port src/native/pose_orchestration.c \
  --exe build/vf3nativeposeorch.exe \
  --mutations tests/pose_orchestration_native_mutations.json \
  --target vf3nativeposeorch
```

The driver is registered in `vf3nativeview` and the harness target
`vf3nativeposeorch` builds from `tests/pose_orchestration_native_replay.c`.
