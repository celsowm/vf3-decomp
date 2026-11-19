# Native pose quantiser — 0x8C09F500

The pose quantiser (the `pose_turns` leaf of the pose-post family), ported to
plain C as `src/native/pose_turns.c`, closes the fight engine's motion
channel: it is the function that runs right after the pose orchestration
(0x8C09EAF2, already native) turns the actor's pose, and it turns the final
three-float vector into the canonicalised halfword set.  At runtime there is
**no guest SH-4 code, no adapter, no emulator and no disc service** — the
whole function is this one plain-C leaf.

The authority is the readable port `src/fight/pose_post.c` (entry
`vf3_pose_turns_entry`, entry registers R4=actor, R5=vector, R6=destination).
The native signature

```c
void vf3_native_pose_turns(vf3_native_aim *a, uint32_t sp, uint32_t actor,
                           uint32_t vec, uint32_t dest);
```

takes `sp` = the entry stack pointer (r15), `actor` = the actor (r4), `vec` =
the three-float source (r5) and `dest` = the three-halfword destination (r6).
The differential test `tests/pose_turns_native_replay.c` runs both sides on
the same seeded fixtures and compares the **whole** caller-visible region
(actor, vector, destination and the leaf's 40-byte stack frame) plus the
restored caller registers (r8..r14, r15 and pr).

## What the function does

The three source floats are truncated to integers (SH-4 `ftrc`, toward
zero), then the Euler `x` is canonicalised into `[-0x5000, 0x5000]`:

```
|x| > 0x5000  ->  x += 0x8000, y = 0x8000 - y, z += 0x8000
```

The band value `(i16)[actor+0x3E]` decides when the destination is written:
only on the two edges `band == hi` (where `hi = ((i16)[actor+0x1FB0]&0xffff)
+ 1`) and `band == lo8` (where `lo8 = ((i16)[actor+0x1A00]&0xffff) - 8`) are
the three halfwords `x''/y''/z''` written to `dest[+0/+2/+4]`.  The kind gate
is reached from two places — `hi < band < mid` (mid = signed +1) or
`lo8 < band < lo1` — and when the actor byte `+0x61` is 3 and the magnitude
of `z''` is above the pool halfword `0x7530` (0x0C09F5F0), the guest negates
`z''`.  The source vector is **always** written back as the three floats
`float(x'')/float(y'')/float(z'')`.

The literal-pool constants the leaf reads (0x5000, -0x5000, 0x1FB0, 0x1FAC,
0x1A00, 0x7530, 0x8000) are **integer** (verified against `1ST_READ.unsc.bin`
at 0x0C09F5E8..0x0C09F5F4), so they are baked in as C constants rather than
read from RAM at run time.

## Registers and stack

The leaf is **call-free and never touches pr**.  Its prologue saves r8..r14
(seven words) and opens a 12-byte frame, so the frame base is 40 bytes under
the entry sp:

```
f      = sp - 40
f+0    written three times (z-trunc, z'', lo8) — the final word is lo8
f+4    = the z pointer (vec + 8)
f+8    = the y pointer (vec + 4)
f+12..f+36 = saved r8..r14
```

The epilogue restores r8..r13 from f+12..f+32, then r14 from f+36 in the
`rts`'s delay slot, leaving r15 back at the entry `sp`.  The final working
value of r13 (the canonicalised, full-width `y''`) is consumed by the source
write-back *before* the epilogue restores r13 from the stack — so the two y
values are separate and a port has to keep the working y separate from the
saved register.

## FPU, or lack of it

The guest uses FPUL (`R(53)`, the register index 53) to hold the truncated
and re-converted values, and routes the float conversions through the
bit-exact `sh4_fpu.c` helpers.  The native context `vf3_native_aim` has **no
FPUL field**, so the native port does not reproduce FPUL; instead, because
the arithmetic after the three truncations is pure integer math, the native
port uses plain C casts: `(int32_t)float` truncates toward zero (identical
to `ftrc` for in-range values) and `(float)int32_t` is exact for the 16-bit
magnitudes involved.  Every written value is therefore **exact**, which is
why the differential uses a strict byte-exact compare rather than a float
tolerance.

## Proof

* `tests/pose_turns_native_replay.c` — 13 differential cases against the
  readable chain: both band edge writes (hi and lo8), both canonicalisation
  directions, the kind-3 negation (positive and negative `z''`), the kind-
  gate with the wrong kind, the small-`z''` no-negation arm, the inside low
  band, in-range no-write paths, fractional truncation, large values and the
  wrapped `z''`.  All pass.
* `tests/pose_turns_native_mutations.json` + `tools/mutate.py` — **8/8
  mutations caught** (each rebuilds and requires the differential to fail):
  the canonicalisation addend changed, the band write condition turned from
  `||` to `&&`, the kind gate reading the wrong kind, the negation reduced
  to a no-op, the low band off by one, the y reflection sign flipped, the
  source `z''` write-back swapped to `x''`, and the frame's final word left
  as `lo` instead of `lo8`.

## A note for future ports

The pose-post family continues with the wrapper 0x8C09F432 (five point
clamps around two quantiser calls) and the point clamp 0x8C09F5F8
(`src/fight/point_wrap.c`), both of which are FR-bank and FPUL heavy and call
the quantiser/leaf.  The wrapper is the natural next native milestone once a
native rewrite of `point_wrap` (and a way to carry the FR bank / FPUL in the
native context) lands.
