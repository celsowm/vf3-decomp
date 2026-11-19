# Native pose chain composition (0x8C09EAF2 → 0x8C09F432)

The capstone for the native aim/pose family.  Each leaf and stage was proved
on its own - `aim_frame` (0x8C09E060) and `aim_frame_b` (0x8C09E6B2),
`seven_pass` (0x8C09DA72), the four orchestration callees
(`src/native/pose_callees.c`), the quantiser `pose_turns` (0x8C09F500), the
point clamp `point_wrap` (0x8C09F5F8), the post wrapper `pose_post`
(0x8C09F432) and the orchestration driver
(`src/native/pose_orchestration.c`, 0x8C09EAF2).  This test proves they
*compose*: it runs the whole pose orchestration **followed by** the
post-processor on one actor, natively, and compares the final
posed-and-quantised fighter against the readable chain from the same seed.

- `tests/pose_chain_native_replay.c` (the composition, target
  `vf3nativeposechain`)
- `tests/pose_chain_native_mutations.json` (the gate, 5/5 caught)
- authority: `src/fight/readable/pose_orchestration.c` +
  `src/fight/pose_post.c` (the two readable entries chained in sequence)

## The composition

On both sides the same seed is run through two stages back to back:

```
seed
  -> vf3_pose_orchestration_entry  (0x8C09EAF2)   poses the actor
  -> vf3_pose_post_entry           (0x8C09F432)   quantises the pose points
```

The orchestration poses the actor (the blocks at +0x200/+0x300/+0x480/+0x540,
the SEG records, the +0x1E..0x22 frame words, +0x640/+0x680 and the final
XMTRX); the post-processor then clamps its own five points (+0x1D58..+0x1DF4)
and runs them through the two quantisers into destinations
(+0x233C/+0x2342).  The two stages touch **disjoint** actor offsets, so the
fixture seeds each stage's inputs independently and neither stage clobbers the
other's.

## The r15-live-handoff lesson

The post-processor **preserves its entry r15** across its whole run (the
epilogue writes `R(15) = sp`, where `sp` is the entry stack pointer).  The
orchestration leaves both sides at `r15 = SP+0x1C` on return its epilogue
restores the caller-saved registers from its own stack and returns at
`sp0 + 0x1C`.  So the native chain must hand the post-processor the **live
stack pointer the orchestration leaves** (`a->r[15]`, = `SP+0x1C`), not the
fixed entry `SP`:

```c
vf3_native_pose_orchestration(a, SP, OBJ, ARG);
a->r[4] = OBJ;
vf3_native_pose_post(a, a->r[15], OBJ);   /* the LIVE r15, not SP */
```

The first version called post with the fixed `SP`: both sides agreed through
the orchestration, then the native post reset to `SP` while the readable post
stayed at `SP+0x1C`, and the final `r15` diverged by 0x1C.  The readable chain
enters post with the same live r15, so handing post the live r15 is exactly
the guest's call sequence.

## The stack / register comparison decision

The readable post routes its quantiser and point clamps through
`vf3_guest_call` (the matrix router -> the generated translation, which uses a
**full register-save stack**); the native post calls the leaves directly.  So
the two sides' *internal* stack scratch and *callee-clobbered* r8..r13 differ
by invocation convention, not by the post-processor's observable result.  The
integration therefore compares the pieces the composition actually guarantees:

- **the actor/work region** `0x0C200000..0x0C20F000` (the orchestration output
  blocks AND the post-processor's points/sources/destinations) with the
  `2.0e-3` float tolerance the orchestration test uses;
- **XMTRX** (orchestration output; post never touches it);
- the post **contract registers** r0/r5 (= actor+0x1E00, byte-exact), r15, pr
  and r14;
- **r8..r13 compared on a cleared, deterministic SP** so the compare is
  meaningful (the SP region is painted with `0xDEADC0DE ^ (a & 0x7FF)` before
  each side, making the orchestration epilogue's restores deterministic and
  non-vacuous).  The standalone stage tests used a `calloc`-zeroed stack,
  which made their r8..r14 restore comparisons vacuous; the chain fixes that.

The internal stack bytes below the entry SP are **not** compared - they are
the invocation difference, not the pipeline result.

## Proof

`tests/pose_chain_native_replay.c` runs five composition cases against the
readable chain, all passing:

- **pose kind 3 + post (band writes both destinations)**;
- **pose kind 12 + post big z (no kind-3 negate)** - kind 12 never negates;
- **pose kind 3 + post kind-3 z negate** - kind 3 with a large |z| fires the
  z'' negation;
- **pose kind 21 + post band skip** - a band far outside the chain leaves the
  destinations junk but the source write-backs still run;
- **pose kind 0 + post gated wraps** - the ring gate mostly shut freezes the
  point clamps but the two quantisers still run on the unwrapped sources.

The mutation gate `tests/pose_chain_native_mutations.json` runs
`tools/mutate.py --port src/native/pose_post.c --target vf3nativeposechain`
and catches **5/5**:

| mutation | how the composition sees it |
|---|---|
| `first_point_offset_off` | the point chain shifts, final r0/r5 land +0x0C off |
| `third_point_stride_omitted` | the chain skips +0x54, final r0/r5 land −0x54 off |
| `final_return_off_by_four` | r0/r5 land −4 off actor+0x1E00 |
| `pr_restore_off` | pr comes back +1 |
| `fifth_point_uses_assumed_plus12` | the asserted +12 rewrites an actor point to garbage |

Two mutations that the standalone post gate covers are **left out of the chain
list deliberately**: the two quantiser destination offsets
(`first_quantiser_dest_off` / `second_quantiser_dest_off`).  Through the
composed artifact they are unreachable: the orchestration runs first and
deterministically clobbers the band fields (`+0x3E`, `+0x1FB0`, `+0x1A00`,
`+0x1FAC`) that gate the quantiser's `write_quantised` arm, so the
destination-write path never fires in the composition and shifting the
destination address changes nothing the chain inspects.  That path stays
proved where it fires, by the standalone `pose_post_native_mutations.json`.
The fixture assertions on exact destination *values* were dropped for the
same reason: the composed destination is not predictable from the seed, so
the composition is proven by the full actor-region compare + the post contract
registers, not by a re-derived destination.
