# Native clip_near_triangle (0x8C04A320)

## Reading

`clip_near_triangle` is a self-contained leaf in the fight engine's
store-queue geometry pipeline: it reads a stream of triangle point-records,
projects each point through XMTRX, clips each triangle against the near-plane
threshold (r12, kept in FR2 via `FSTS`) and writes 32-byte store-queue vertex
blocks at r6, counting 64-byte blocks in r5.

The readable authority `vf3_clip_near_triangle_entry` lives in
`src/fight/clip_near_triangle.c` (441 lines, body 0x8C04A320).  It rejects the
body up front when the FPU is unsupported (FPSCR bit 0x80000 or the precision
mode selects double beyond the pair stride) or when SZ is already ON (the body
spends most of its time with SZ=1, toggled by `FSCHG`).

### Stream layout

A point record starts with a flag word.  With **bit 0 set** the record is
inline: x, y, z are the three floats from its first word on and the next
record is 32 bytes on.  With bit 0 clear the second word is an offset (from
record + 8) to out-of-line x, y, z and the next record follows after 8 bytes.

- r4 -> the stream: `[word count][count triangles][terminator 0]`
- r5 = 64-byte store-queue block counter (starts 0, +64 per emitted pair)
- r6 = store-queue pointer (the emitted 32-byte vertex blocks land here; the
  `pref` flushes are inert when r6 is a RAM pointer)
- r7 = a constant word that goes into the last word of the second vertex block
- r12 = the near-plane threshold (bit pattern, kept in FR2)
- r11 = the "something was emitted" latch (0 -> the trailer pair is skipped
  and the last block undone)

### Per-triangle outcode

Each point goes through XMTRX as `(x, y, z, 1)`.  The transformed `w` of the
three points is then set against the threshold, one `rotcl r0` per point, so
the three low bits of r0 hold the outcodes.  `set_t((r0 & 7) == 0)` selects
the all-front write path (outcode 0) vs the `clipped:` block.

The permutation stubs at 0x8C04A44A rotate the point order for outcodes 2..6;
the two emitters `emit_two_behind` (0x8C04A48A) and `emit_one_behind`
(0x8C04A4F2) interpolate the clipped vertices against the near plane (a mix of
`fdiv`/`fmul`/**fused** `fmac`) and write the store-queue blocks.

### Trailer

After the stream, a trailer pair (a header word and the or-ed words from the
caller's frame at sp+20/24/28, with the header's bit 6 set on the second word)
is written once - but only if something was emitted (`r11 != 0`).  With
`r11 == 0` the last block is undone (`r6 -= 32`, `r5 -= 32`) and the function
returns without the trailer.

## The native port

`src/native/clip_near_triangle.c` (`vf3_native_clip_near_triangle`) is a
direct plain-C transcription of the readable authority: same stream walk, same
outcode computation (three `GT(FR2, FR…)` compares into `r0` via `rotcl`), same
two emitters with the fused `fmac`/`fmul`/`fdiv` chains in the same order, and
the same trailer gate on the `r11` latch.

FP primitives are the established native wrappers (`src/native/aim_math.h` +
the local `fmul`/`fadd`/`fsub`/`fdiv`/`fmac` helpers in `clip_near_triangle.c`
keyed on the `(fpscr & 1u)` rounding mode): `fmac(x,y,acc) = fmaf(x,y,acc)`
mirrors the guest's fused FR0-based FMAC, and the point transform is a
double-accumulate `ftrv` mirror of `vf3_fpu_ftrv`.  With the captured FPSCR
`0x00040001` (RM bit 0, toward zero) and this leaf's short FP chains, the
transcription is **bit-exact** against the readable authority - no tolerance
filter is needed, and the control words / `0xFFFFFFFF` markers match exactly.

`src/native/clip_near_triangle.h` declares the single entry
`vf3_native_clip_near_triangle(vf3_native_aim *a)`.

## Proof

`tests/clip_near_triangle_native_replay.c` (`vf3nativeclipneartriangle`)
differentially replays the native leaf against the readable authority
(`vf3_clip_near_triangle_entry` routed through `vf3_family_override =
vf3_readable_override`) on the same flat RAM and the same register/FP/XMTRX
seed.

The XMTRX is column-major with the `w' = z` row set (xm[11] = 1), so the
transformed depth equals z and the threshold 10.0 gates each point's outcode
bit directly; `x'=x, y'=y, z'=z` keep the emitted positions clean.

Two cases:

- **all-outcodes**: eight triangles, one per outcode 0..7.  Covers the
  all-front write, the all-behind skip, and both emitters through every
  point-order rotation (outcodes 1..6).
- **single-all-front**: a single all-front triangle.  Here the all-front
  path's `r11 = 1` write is the **last** emitter latch, so the exit r11 and the
  trailer write it gates are decided by that path alone - this is the case
  that makes a mutation of the all-front `R(11) = 1` observable.

Each case compares, bit-exact: the emitted store-queue region
(slot0-0x40 .. slot0+0x400), the register contract (r0..r6, r11, r14), and
XMTRX (unchanged).  All cases PASS.

`tests/clip_near_triangle_native_mutations.json` - 9 mutations, **9/9 caught**
(`python tools/mutate.py --port src/native/clip_near_triangle.c --exe
build/vf3nativeclipneartriangle.exe --mutations
tests/clip_near_triangle_native_mutations.json --target
vf3nativeclipneartriangle --keep-going`):

- the all-front/behind branch directions and the outcode-0 test
- the point-0 threshold compare flipped
- both emitters' fused-mac operand order wrong
- the trailer header word's bit wrong
- outcode 6 routed to the wrong emitter
- the all-front `r11` latch not set (observed via the single-all-front case)

The one mutation that needed a test change was the all-front `r11` latch: in
the 8-triangle stream every later emitter rewrites `r11 = 1`, so the exit
value was latched by the last emitter regardless and the change was invisible.
The single-all-front case makes the all-front latch the deciding one (it also
changes the trailer write through the `r11 == 0` undo at the end of the
stream walk), which pins the mutation.

## Milestone

Committed and pushed as `clip_near_triangle` (see git log).  This concludes
the final leaf of the store-queue audit.
