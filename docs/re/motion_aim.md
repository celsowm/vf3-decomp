# Native aim-frame port (0x8C09E060 / 0x8C09E6B2)

State: the native re-implementations in `src/native/motion_aim.c` reproduce both
guest builders.  `tests/native_motion_aimframe_replay.c` is a differential
against the readable guest ports (`src/fight/aim_frame.c` and
`src/fight/aim_frame_b.c`) and runs two cases - one per builder - over the same
flat matrix RAM, comparing the whole caller-visible actor region:

```
== aim_frame (0x8C09E060)
  actor region: match (worst 2.38e-06 at 0c201008)
== aim_frame_b (0x8C09E6B2)
  actor region: match (worst 9.54e-07 at 0c201008)
== aim_frame_b (0x8C09E6B2, clearance sum)
  actor region: match (worst 9.54e-07 at 0c201008)
native_motion_aimframe_replay: PASS
```

`tests/native_motion_aimframe_mutations.json` is the mutation gate: 15 single
substitutions into the port's source, each of which the replay must notice -
`python tools/mutate.py --port src/native/motion_aim.c --exe
build/vf3nativemotionaimframe.exe --mutations
tests/native_motion_aimframe_mutations.json --target vf3nativemotionaimframe`
reports 15/15 caught.

The guest ports are the authority: they were promoted against the oracle, and
the replay harness leaves `vf3_family_override` NULL, so every helper call the
guest port makes is served by the generated translation - the ROM's own code,
not the readable helper ports.  The native port is a re-implementation, so the
residual is the FPU difference (the guest's `fsca` coefficient table and `fsrra`
against libm's `sinf`/`cosf`/`sqrtf`), which the replay tolerates at 2e-3 and
which measures 9.5e-7 here.

Native motion rows 0-1 (`2c42cc1`, `cc3ff27`) are unaffected.  The first
differential version of this port reported a 0.169 residual in the frame's
matrices; the three causes are below.

## What the guest builders do

0x8C09E060 (aim_frame) - three matrices into the block at actor+0x200 and
+0x300, built from XMTRX, the FR bank and the 0x40-byte matrix stack whose
control block lives at 0x0C19D2E4.  0x8C09E6B2 (aim_frame_b) - the same helper
chain writing a rotation block and a translated point pair instead, plus the
three-angle wrapper 0x8C09DA1E and the two literal offsets (-0.1 / -0.2 / 0.0).
The two builders differ in their registers: aim_frame keeps the record in r4,
the output block in r5 and the object in r6; aim_frame_b hands r4 a *pointer*
that it parks in its own frame at +20 (the wrapper's base), keeps the record in
r5 and reads one fewer caller stack word (its frame is 0x130 bytes, not 0x128).

The native port keeps the guest's shape: `vf3_native_aim` carries a flat matrix
RAM whose base lets every guest address resolve to the words the guest saw, plus
XMTRX, a local matrix stack, the FR bank and the register file.  The arithmetic
(fsca/fsrra/ftrv/fmac) is reproduced with sinf/cosf/sqrtf and fmaf.

## Cause 1 - the guest's address arithmetic is byte-exact

The euler angle triples sit at r4, r4+6 and r4+12, so the second euler of each
builder reads halfwords at an address that is **not** 4-aligned.
`vf3_native_aim_frame` resolved `aim_p(a, addr)` with `>> 2`, so
0x0C200506 aliased onto 0x0C200504 and the port rotated by the wrong angles.
The probe that found it printed the halfwords the guest actually read
(`angles: 4000 3f80 6000` for the second euler) next to the ones the fixture
had written (`3000 4000 5000` one slot later).

**Every guest address in a native port has to be byte-exact**, halfword
addresses included.  Both `aim_p`/`aim_adr` in the port and the fixture's `at`
now do byte arithmetic; the mutation list keeps the aliasing bug out again.

## Cause 2 - the fixture lied about the angles

The fixture wrote its ten angle halfwords through the same word-granular `at`,
so `w16(0x0C200502, 0x2000)` landed at 0x0C200500 and the *guest* read
`2000 3f80 4000` from the block the fixture thought held `1000 2000 3000`.  The
native side, reading the same (mis-written) RAM one slot lower, disagreed with
the guest: the differential was comparing two different inputs.  With the
fixture fixed both sides read the intended halfwords, and the euler results
agree.

## Cause 3 - the wrapper parks before it rebuilds

0x8C09DA1E keeps the caller's translation across the rotation it rebuilds from
the identity, and it does so through its own frame: `0x8C03B820` (xf_store)
parks XMTRX's translation at frame+4, the four rotations (Ry(base + 30),
Rz(record + 0), Ry(record + 2), Rx(*(int16 *)(base + 0x22E6) + record + 4))
rebuild the rotation, and `0x8C03CBD0` (set_translation) puts the parked words
back.  The first version of `aim_three_angles` read the parked words without
writing them, so it restored whatever the seed had left in the scratch area -
the guest's `1.00006` against the port's `-0.2693`.

## Details the port has to keep

- `GT(m, n)` in `src/fight/fr_ops.h` is `fl(m) < fl(n)`: the tiny-literal
  guards in aim_frame_b's clearance arm read the other way round from the way
  they look (`if (GT(5, 13)) F(14) = 0` means *when the literal is larger*).
- aim_frame_b's first clearance rotation is negated (`F(4) ^= SIGN` after the
  sqrt); aim_frame's is not.
- aim_frame_b clamps the ratio before the second ratio; aim_frame clamps the
  second first.
- 0x8C09D4E6 keeps the three words at dst+48/+52/+56, so a `store_keep`
  destination has to have its translation staged *before* the call - aim_frame
  stages the xform result at frame+0xC0 (which is the f+0x90 block's
  translation) and the triple's components at frame+0x100/+0x104/+0x108.
- 0x8C03B620 (matrix_store) writes the front bank to r4 (or to the stack top
  when r4 is 0) and advances r4 by 64; 0x8C03BD80 (matrix_load) does the same in
  reverse.  The rotations (0x8C03C940/0x8C03C880/0x8C03C6C0/0x8C03C8B0) rewrite
  two columns of XMTRX through `ftrv`, which is exactly `XMTRX * R`.
- 0x8C09D554 transforms the point (0, FR4, FR5); 0x8C09D52E transforms
  (FR4, 0, 0).

## Open lead

Both arms of both builders' clearance branch are covered: the second and third
cases take aim_frame_b's `else` and `if` arms respectively (the third fixture
gives the object a clearance sum of 1800 that the transformed length never
reaches), and the first case takes aim_frame's `else` arm.  aim_frame's `if` arm
- the branch that skips its three rotations - is the one combination the replay
does not reach; a fixture whose object words 3/4 are small enough that the
length always exceeds their sum would close it.

The `aim_frame_b` entry is not (yet) called by the native pose orchestration the
way `0x8C09EAF2` calls the first builder, so its native port is proved only by
this differential.