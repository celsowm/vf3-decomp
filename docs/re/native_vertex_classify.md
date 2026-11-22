# Native vertex_classify (0x8C048EC0)

## Reading

`vertex_classify` is a self-contained FP leaf (call-free, no stack frame): it
transforms three consecutive strip point records through XMTRX as (x, y, z, 1)
and records, in r9's lowest three bits, which lie behind the clip plane.

The caller leaves r4 pointing at three consecutive point records, r12 = the
clip value (compared as an **unsigned bit pattern**, which orders non-negative
floats) and r9 = the outcode accumulator.

A point record starts with a flag word:

- with **bit 0 set** the record is inline: x, y, z are the three floats from
  its first word on (the flag's low word doubles as x), and the next record is
  32 bytes on;
- with **bit 0 clear** the second word is an offset (from record + 8) to
  out-of-line x, y, z, and the next record follows after 8 bytes.

Each point goes through XMTRX as (x, y, z, 1); the transformed w of the three
points is then compared against r12 (unsigned), one **rotcl** into r9 per
point - second first, then third, then first - so the bit shifted out of r9 by
the last rotcl ends up in the T bit (SR bit 0).

On return r4 and r1 are the original record pointer, r0 and FPUL hold the
first point's transformed w, and the three transformed vectors stay in FR0-FR3
(second point) and FR4-FR7 (first point).  XMTRX, FR8..FR15, r15 and SR
(other than the T bit) are untouched.

The readable authority `vf3_vertex_classify_entry` lives in
`src/fight/vertex_classify.c`; its registry row at `src/fight/readable.c:675`
names `B(0)|B(1)|B(4)|B(9)|B(17)|B(53)|FR(0..7)` as the out registers.

## The native port

`src/native/vertex_classify.c` (`vf3_native_vertex_classify`) is a direct
plain-C transcription onto `vf3_native_aim`.  The ftrv is reproduced the
established native way (column-major, `out[r] = sum_k xm[4k+r]*v[k]`, plain
float accumulate, w = 1.0f).  The rotcl is a shift-accumulate plus a T-bit
carry from the shifted-out bit.

## Proof

`tests/vertex_classify_native_replay.c` (`vf3nativevertexclassify`)
differentially replays the native leaf against the readable authority on the
same flat RAM, XMTRX, FR bank, r4, r12 and r9.  r9, r0/r1/r4, FPUL and SR's T
bit are compared bit-exact; FR0..FR7 at the 2e-3 FPU tolerance (the ftrv
accumulate difference).  Four cases PASS:

- three inline records, clip above all three w (all fronts -> r9 0);
- clip below all three w (all behind);
- a mixed inline/outline run with a real mixed outcode pattern (the transform
  `w = 1 + 0.1*y` straddles the clip on the middle point), with r9 seeded
  non-zero;
- a `w = z` matrix whose points (z = 2.0/0.5/1.0) put the **first** and
  **third** points on opposite sides of the clip - this is what pins the rotcl
  order, since the second/third/first outcodes come out (0, 1, 0) -> 0b010.

`tests/vertex_classify_native_mutations.json` - 7 mutations, **7/7 caught**:

- the oldest-w snapshot taken from the wrong point (fr[3] vs fr[7]);
- the rotcl T-bit comparison inverted (`<=` vs `>`);
- the second rotcl fed the wrong point's w (the mixed-outcode case pins it);
- the out-of-line offset missing its `+8`;
- the inline stride treated as 8 instead of 32;
- the point load order swapped (second vs first);
- r0/FPUL taken from the wrong w.

## Milestone

Committed and pushed as `vertex_classify` (see git log).
