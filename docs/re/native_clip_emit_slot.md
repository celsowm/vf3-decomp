# Native clip_emit_slot (0x8C048C80)

## Reading

`clip_emit_slot` is a self-contained, call-free FP leaf in the fight engine's
strip-transform/store-queue geometry pipeline: it pushes ring slot `r0 & 3`
(the 4-slot ring of 32-byte transformed vertices at `RING_BASE` 0x0C1A5960)
to the store queue at r6, scaling its `y'` and `z'` by the reciprocal `1/x'`
first, and writes the strip's control word in the first slot word.

The readable authority `vf3_clip_emit_slot_entry` lives in
`src/fight/vertex_clip.c` (body 0x8C048C80).  It rejects the body up front
when the FPU is unsupported or FPSCR.SZ is already on (this path runs with SZ
clear).

### Contract

- r0  ring slot index (a 32-byte slot in the 4-slot ring at 0x0C1A5960),
- r6  the store-queue slot (advanced by 32 on return),
- r5  an input/block cursor (advanced by 32 on return),
- SR.T the strip-end flag: when set the control word is `0xF0000000` (strip
  end), otherwise it is the slot's **own** address.

The body loads the ring slot's eight words, scales `y'` and `z'` by the
reciprocal `1/x'` (a single fmul each, toward-zero rounding), copies all eight
words into the store-queue block (writing the control word first), and leaves
FR0..FR7 carrying the eight words (FR0 = the slot's `w'` word, FR1/FR2 the
scaled `y'`/`z'`, FR3..FR7 the rest copied through).

On return: r0 = `(r0 & 3) * 32`, r2 = the control word, r5 += 32,
r6 = base + 32, r10 = `src + 32`.

## The native port

`src/native/clip_emit_slot.c` (`vf3_native_clip_emit_slot`) is a direct
plain-C transcription of the readable authority using the established native
FP wrapper: `fmul` keyed on the `(fpscr & 1u)` rounding mode.  It runs only
with FPSCR.SZ clear and the FPU enabled, returning 0 when the entry FPSCR
would be rejected.  The ring slots and the output slot are read/written
through flat RAM (`vf3_aim_u32`/`vf3_aim_set_u32`), and the pref flush is a
store-queue device side effect, inert when r6 is a RAM pointer.

`src/native/clip_emit_slot.h` declares the single entry
`vf3_native_clip_emit_slot(vf3_native_aim *a)`.

## Proof

`tests/clip_emit_slot_native_replay.c` (`vf3nativeclipemitslot`) differentially
replays the native leaf against the readable authority
(`vf3_clip_emit_slot_entry` routed through `vf3_family_override =
vf3_readable_override`) on the same flat RAM and the same register/FR seed.

The fixture seeds the four ring slots and runs four cases: slots 0, 2 with T
clear and slots 1, 3 with T set (exercising both the address and the
strip-end control words, plus every ring index).  The scaled slot's
`y' = 10.1f` and `z' = 20.7f` with `1/x' = 0.33333334f` give **inexact**
products, so the toward-zero vs nearest rounding choice in `fmul` is genuinely
exercised (with exact products like `* 0.5f` the two roundings agree and the
rounding mode is a hole in the proof).

Each case compares, bit-exact: the 8 words of the emitted store-queue slot,
the register contract (r0, r2, r5, r6, r10), and FR0..FR7.  All four cases
PASS.

`tests/clip_emit_slot_native_mutations.json` - 9 mutations, **9/9 caught**:

- the y' and z' scaling dropped (both in the FR bank and in the store)
- the control-word address vs the strip-end flag (both directions)
- the exit r0 from the wrong ring register
- the exit r10 off by a slot
- the FR0 slot word read from the wrong ring offset
- the fmul **rounding** to nearest instead of toward-zero (pinned by the
  inexact-product seed)

## Milestone

Committed and pushed as `clip_emit_slot` (see git log).
