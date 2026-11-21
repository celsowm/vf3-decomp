# native terrain_plane_hit (0x8C0692A6)

`src/native/terrain_plane_hit.c` (`vf3_native_terrain_plane_hit`) is the
plain-C port of the readable `src/fight/terrain_plane_hit.c`
(`vf3_terrain_plane_hit_entry`), proved by
`tests/terrain_plane_hit_native_replay.c` (5 differential cases) and the
mutation gate `tests/terrain_plane_hit_native_mutations.json` (12/12
caught).

## The function

A call-free FP leaf with no guest callees and no device/FMTRX access.  It
reads a triangle's three vertex positions (P, Q, R; with the Q/R selection
depending on r7), crosses the edge vectors Q-P and R-P, solves the plane
through them for the height at (FR4 = x, FR5 = z), writes the height to r5's
float, copies the stored normal (shape+20/24/28) to r6, and returns
`(shape+0 << 1 & 0x1FFFC) | (shape+0 & 3)` in r0 (with r1 = the low two
bits).  It pushes r14 and FR14 below sp0 and restores them.

## What the port has to keep

- **The FSUB/FMUL/FDIV and every FMAC are FPSCR-aware** (rounding
  `fpscr & 1`, FTZ when bit `0x40000`); the FMACs are fused multiply-adds
  (`fmaf`, one rounding), so they cannot be written as an expression of C
  floats.
- **The Q/R vertex selection depends on r7** (`r7 == 4` picks the "second
  triple" offsets +16/+12; otherwise +8/+12), and the three vertex offsets
  (+4/+8/+12/+16) are signed offsets added to the base at `[0x0C113A0C]`.
- **FR14 and r14 are saved below sp0 and restored** (the saved FR14 is one
  of the two same-observed words, so the fixture must distinguish them).
- **The return value folds the record's first word**: low two bits into r1,
  and `(word << 1) & 0x1FFFC` or-ed with that - the record word is read back
  at the *end*, after the normal copy.

## Everything else

The first version of the test missed the `tph_mac2_src` mutation because
every fixture had `P.x == P.z` (so FR1 and FR14 held the same value at the
FMAC and a source swap was unobservable); the fixtures now use a P with
distinct x and z.  A differential case only exercises a value-dependent
behaviour when its inputs make that behaviour matter.
