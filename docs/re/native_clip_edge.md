# Native clip_edge (0x8C048CC0)

## Reading

`clip_edge` is a self-contained, call-free FP leaf in the fight engine's
strip-transform/store-queue geometry pipeline: it pushes the point where the
strip edge `ring[r0 & 3] -> ring[r11 & 3]` crosses the near clip plane
`w' = r12`, finishing a vertex in a 32-byte store-queue block at r6.

The readable authority `vf3_clip_edge_entry` lives in
`src/fight/vertex_clip.c` (body 0x8C048CC0).  It rejects the body up front
when the FPU is unsupported or FPSCR.SZ is already on (this path runs with
SZ clear, unlike the `clip_near_triangle`/`clip_emit_slot` siblings).

### Contract

- r0  ring slot index of the edge **start** (a 32-byte slot in the 4-slot
  ring at `RING_BASE` 0x0C1A5960),
- r11 ring slot index of the edge **end**,
- r12 the clip plane `w'` (a float),
- r7  a scale float (bits) applied to the interpolated `y'` and `z'`,
- r6  the store-queue slot (advanced by 32 on return),
- r5  an input/block cursor (advanced by 32 on return),
- SR.T the strip-end flag: when set the control word is `0xF0000000`
  (strip end), otherwise it is an address.

The body derives

    t = (plane - w0) / (w1 - w0)

and interpolates every attribute with a **fused** multiply-add

    lerp(a0, a1, t) = a0 + t * (a1 - a0)          (fmaf, one rounding)

then scales the interpolated `y'` and `z'` by the r7 float.  It writes the
32-byte block at r6 in the ring-slot word order (diffuse, specular, W1, W2,
INV_X, then Z, W, Y as the control word lands first), and leaves the exit
bank FR0..FR5 = (t, scale, y', z', d4, d5) where d4/d5 are the deltas of the
last pair of lerps.  The control-word store uses a pre-decrement in the
guest, so the address it records when T is clear is the slot's **y' field**
(`base + 4`), not the slot itself.

On return: r0 = `(r11 & 3) * 32`, r2 = the control word, r5 += 32,
r6 = base + 32, r10 = `p + Y`, fpul = r7.

## The native port

`src/native/clip_edge.c` (`vf3_native_clip_edge`) is a direct plain-C
transcription of the readable authority using the established native FP
wrappers: `fsub`/`fdiv`/`fmul` keyed on the `(fpscr & 1u)` rounding mode and
`fmac(x,y,acc) = fmaf(x,y,acc)` for the fused lerp (a plain `a + t*d` would
round twice and diverge in the low ulp - the mutation gate pins it).  It runs
only with FPSCR.SZ clear and the FPU enabled, returning 0 when the entry
FPSCR would be rejected.  The ring slots and the output slot are read/written
through flat RAM (`vf3_aim_u32`/`vf3_aim_set_u32`), and the pref flush is a
store-queue device side effect, inert when r6 is a RAM pointer.

`src/native/clip_edge.h` declares the single entry
`vf3_native_clip_edge(vf3_native_aim *a)`.

## Proof

`tests/clip_edge_native_replay.c` (`vf3nativeclipedge`) differentially replays
the native leaf against the readable authority
(`vf3_clip_edge_entry` routed through `vf3_family_override =
vf3_readable_override`) on the same flat RAM and the same register/FR seed.

The fixture seeds the four ring slots (the two edge slots with the real
attributes, the other two with garbage to prove only the addressed slots are
read), and runs four cases: edge 0->1, 0->1 with T set (strip-end control
word), 1->3 and 3->0 (ring wraparound).  The plane 10.0 with start w=8.0 /
end w=14.0 gives a clean `t = 1/3`.

Each case compares, bit-exact: the 8 words of the emitted store-queue slot,
the register contract (r0, r2, r5, r6, r10, fpul), and FR0..FR5.  All four
cases PASS.

`tests/clip_edge_native_mutations.json` - 9 mutations, **9/9 caught**:

- plane-gap and edge-gap operands flipped (both change `t`'s sign)
- the diffuse lerp's accumulator from the wrong endpoint
- the y'/z' fmul targets swapped
- the control-word address vs the strip-end flag (both directions)
- the exit r0 from the start index instead of the end index
- the fpul exit value from the wrong register
- the lerp **un-fused** (fmaf -> `x*y + acc`), pinned by the low ulp

## Milestone

Committed and pushed as `clip_edge` (see git log).
