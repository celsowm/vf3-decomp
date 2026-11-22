# Native vertex_emit_ring (0x8C048C20)

## Reading

`vertex_emit_ring` is a tiny, self-contained, call-free leaf in the fight
engine's strip-transform pipeline: it packs the lit, transformed vertex -
FR4..FR7, r1, r2, FR2, FR3 - into slot `r11 & 3` of the 4-slot clip ring at
`RING_BASE` 0x0C1A5960, and leaves r0 = slot*32, r10 = the slot's low address.

The readable authority `vf3_vertex_emit_ring_entry` lives in
`src/fight/vertex_emit.c` (body 0x8C048C20).  The vertex arrives from
`vertex_light` (0x8C048B00) in registers:

    FR4 = w'   FR5 = y'   FR6 = z'   FR7 = 1/x'   FR2 = diffuse   FR3 = specular
    r1, r2 = the record's two trailing words (w1, w2)

The emitter duplicates a shared slot writer that packs these into a 32-byte
slot.  The guest writes the slot backwards with pre-decrementing 64-bit moves
(FPSCR.SZ=1 for the duration), so the words land low-address-first:

    +00 FR4  +04 FR5  +08 FR6  +0C FR7  +10 r1  +14 r2  +18 FR2  +1C FR3

`vertex_emit_ring` writes that slot into the ring (not the store queue) and
advances the clip ring's bookkeeping registers.  It rejects the body when
FPSCR.SZ is already on (the code assumes SZ=0 on entry).

On return: r0 = `offset` (the slot's offset in the ring), r10 = the slot's low
address (`RING_BASE + offset`).

## The native port

`src/native/vertex_emit_ring.c` (`vf3_native_vertex_emit_ring`) is a direct
plain-C transcription of the readable authority.  It is a pure pack - it does
no arithmetic, so it needs none of the FP wrapper helpers; it copies the FR
bank words and r1/r2 into the ring slot through flat RAM
(`vf3_aim_ubits`/`vf3_aim_set_u32`).  It runs only with FPSCR.SZ clear and
the FPU enabled, returning 0 when the entry FPSCR would be rejected.

`src/native/vertex_emit_ring.h` declares the single entry
`vf3_native_vertex_emit_ring(vf3_native_aim *a)`.

## Proof

`tests/vertex_emit_ring_native_replay.c` (`vf3nativevertexemitring`)
differentially replays the native leaf against the readable authority
(`vf3_vertex_emit_ring_entry` routed through `vf3_family_override =
vf3_readable_override`) on the same FR bank, r1/r2/r11 and flat RAM.

The fixture runs four cases: ring slots 0, 1, 3, and the wraparound case
`r11 = 7` (so `7 & 3 == 3` but the raw r11 differs - proving the mask is
applied).  Each case compares, bit-exact: the 8 words of the emitted ring
slot and the register contract (r0, r10).  All four cases PASS.

`tests/vertex_emit_ring_native_mutations.json` - 7 mutations, **7/7 caught**:

- the ring index not masked to 3 bits (caught by the wraparound case)
- the diffuse/specular FR words swapped
- r1/r2 swapped
- a slot-size error moving the write target (r10 caught)
- the exit r0 off by a slot
- the exit r10 off by a slot
- the FR4 write dropped/overwritten

## Milestone

Committed and pushed as `vertex_emit_ring` (see git log).
