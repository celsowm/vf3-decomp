# native_strip_light — 0x8C0487A0 (strip_light), natively

`src/fight/strip_light.c` is the readable guest port of the strip
transform–light–emit driver, SH-4 **0x8C0487A0** (`strip_light`).  This port,
`src/native/strip_light.c` (`vf3_native_strip_light`), transcribes it onto the
`vf3_native_aim` context from `src/native/aim_math.h`.

## What it does

The guest reads a strip of vertex records at `r4`, transforms and lights each
vertex through XMTRX (diffuse via FV12 + ambient FR15, specular via FV8 and the
power ladder selected by `r8`), and writes 32-byte store-queue vertex slots at
`r6` (`r5` advancing 32 per vertex), chaining strips through a trailer.

Layout, matching `docs/re/` and the guest source:

- `r4 -> strip`: `{ u32 count; vertex records... }` then a trailer
  `{ u32 flags; u32 count; }` with the next strip's first record right behind it
- `r5` = output cursor (advanced 32 per vertex); `r6` = start of the slot area
- `r8` = specular selector (0 = none; a ladder entry 4..40, step 4)

Slot layout: `+00` control word (the slot's own address for a vertex inside the
strip, `0xFFFFFFFF` for the last one), `+04 y'/x'`, `+08 z'/x'`, `+0C 1/x'`,
`+10 w1`, `+14 w2`, `+18 diffuse`, `+1C specular`.  The trailer's flags word
chains strips: `flags <= 0` (signed) or bit `0x80` clear stops, otherwise a new
strip starts at `trailer + 8`.

## FPU behaviour preserved

This is a self-contained FP leaf (call-free — `vf3_light_vertex`,
`vf3_vertex_locate` and `vf3_matrix_pref` are inlined, so there is no guest
dispatch).  The guest's `vf3_fpu_ftrv` / `fipr` accumulate the four products in
a `volatile double` and round once; the native `dot4` replicates that exactly.
`fadd` / `fmul` / `fsub` / `fdiv` wrap the C operator in
`fesetround((fpscr & 1u) ? FE_TOWARDZERO : FE_TONEAREST)` (the corpus' FPSCR is
`0x00040001`, RM = 1 → round toward zero).  Runs with FPSCR.SZ clear (the
readable guards it).

`vf3_matrix_pref` is the store-queue flush (`vf3_sq_model`); the process
variables are inert here (QACR/PREF), so it is not reproduced.

`vf3_light_vertex` is called with `via_adder = 1`, so the normal's `n0` rides
along a `0.0 + n0` adder (turns -0 → +0, flushes denormals) — reproduced.

## Proof

`tests/strip_light_native_replay.c` differentially replays both sides on the
same flat RAM and register file (10 cases):
- `r8 = 0`: no specular ladder
- `r8 = 8` (FR3 squared), reached and un-reached
- `r8 = 24` (four-step chain)
- `r8 = 40` (five-square end), entered from small and 6-record strips
- negative half-vector / negative diffuse
- `r8 = 8, 6 records` (more than one group)
- a chained pair (strip1 chain-flags into strip2, then stops)

The emitted slot region, the register contract (`r0..r6`, `r9`, `r14`, `r15`,
`pr`, SR's T bit) and FPUL are compared bit-exact; the EMIT and the float FR
results are compared at the 2e-3 FPU tolerance (worst ~1e-6).

`tests/strip_light_native_mutations.json`: **14/14 mutations caught** via
`tools/mutate.py` (protects the SZ guard, the selector guard, the r5 advance,
the count decrement, each slot store, the diffuse/specular bank selection, the
ladder arms `case 8`/`case 40`, the `n_dot_l > 0` branch, the chain flag and
`flags <= 0` stops, and the `r0`/`r2` outputs).

`strip_light` was the **last genuinely-unported call-free readable leaf**: the
name-based candidates (`float_scale_b` → `float_scale`, `pose_blend` →
`pose_blend_step`, `div_signed` → `div_s32`) are all already ported natively
under different names, and `vtable_trampoline` (0x8C035CBA) is rejected per
`AGENTS.md` (untrustworthy — does not match the retained translation, and
`unexercised`).
