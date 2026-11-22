# Native quad_strip (0x8C048600)

`src/native/quad_strip.c` (`vf3_native_quad_strip`) ports the store-queue
emitter `quad_strip` natively, mirroring the readable authority
`src/fight/quad_strip.c` (`vf3_quad_strip_entry`) with the shared lighting
step of `src/fight/vertex_light.c` (`vf3_light_vertex`, `via_adder = 1`)
inlined, exactly as the guest inlines it.

## The body

Walks a list of groups of four inline vertex records and emits 32-byte
store-queue slots.

- `r4` = group list.  At `r4-8` the byte length of all groups (`units =
  that >> 1`, in halfwords), at `r4-4` a flags word, at `r4` a count; the
  first group starts at `r4+4`.  A group is
  `{ 4 inline vertex records (32 B each); u32 flags; u32 count }` = 136
  bytes, and the 8-byte tail is skipped between groups.
- `r5` = output cursor (advanced by 128 per quad, 0 per triangle),
  `r6` = store-queue slot (32 B per vertex), `r8` = specular selector,
  XMTRX (`a->xm`), FV12 (diffuse, ambient in FR15) and FV8 (specular)
  lights in the FR bank.
- Only vertex 0 is lit.  Vertices 1..3 carry no colour: their slots write
  only their first 24 bytes, and vertex 0's diffuse/specular pair is parked
  at `slot-8`/`slot-4` (the tail of the *other* store-queue buffer), so the
  other slots flush flat-shaded with that pair still sitting in the buffer.

The first three vertices decide the primitive:

    (y0 - y1)(z1 - z2) > (z0 - z1)(y1 - y2)

keeps the fourth (a quad, four slots, `r6` on by 128); otherwise a triangle
goes out: slot 2 is rewritten as the end-of-strip marker (`0xFFFFFFFF`) and
`r6` stays at the group's first slot.

Exit registers: `r0`, `r1 = w1`, `r2 = w2`, `r4 = end of last group`,
`r5`, `r6 = slot after output`, `r9 = 0`, `r14 = the slot the call started
with`.  FR/XF are all defined on exit but only the r-set is compared in the
flat-RAM differential.

## Native model

- The FPUSCR rejects when `& 0x00100000` (SZ): the routine's own `fschg`
  would have turned the pair moves off, so a faithful port refuses too.
- The FP math reuses the `project_verts` wrappers: `ft0` (round-toward-zero
  via `fesetround(FE_TOWARDZERO)` + FTZ flush off bit `0x40000`) and the
  `fmul`/`fadd`/`fsub`/`fdiv` shorthands, plus `ftrv` (4x4 matrix-vector)
  and `fipr` (dot).  The specular power selector maps to the same multiply
  chains as the guest's jump table (4..40).
- `light_vertex` reads the record's body at `BODY_POS`/`BODY_NORMAL`/
  `BODY_W1`/`BODY_W2`, applies the `via_adder` (`n0 = 0.0f + n0`), computes
  `N.L` against FV12 (`{n1,n2,n0,0}`) and `N.H` against FV8
  (`{F8,F9,F10,0}`), and folds the specular selector.
- `project` transforms the 2nd..4th records position-only (`depth`, `inv =
  1/depth`, `y/x'`, `z/x'`).
- `emit_position` writes the first 24 bytes of a slot in the guest's order,
  ending with the control word.

## Proof

`tests/quad_strip_native_replay.c` (`vf3nativequadstrip`) runs 6 differential
cases — quad, two groups, triangle (reversing winding so the EOS path runs),
no-spec selector, identity matrix, and a denormal-n0 quad — and compares the
whole emitted slot region **bit-exact** plus the register contract
(`r0/r1/r2/r4/r5/r6/r9/r14`) and XMTRX (unchanged).  A tolerance filter was
deliberately *not* used: this leaf has no `sqrt`/`fsrra` (only
`ftrv`/`fipr`/`fdiv`/`mul`/`add` chains), so a faithful port is bit-exact,
and a tolerance filter would let control words slide — the control words are
addresses stored as floats (their relative float diff is below any sane
tolerance), and the `0xFFFFFFFF` EOS marker is NaN, for which `fabsf > TOL`
never fires.  Bit-exact comparison proves the control words too.

The mutation gate (`tests/quad_strip_native_mutations.json`) catches **14/14**:

- units guard divisor (`units_guard_divisor_wrong`) — the `% GROUP_UNITS`
  guard is honored;
- group tail skip (`group_tail_not_skipped`);
- quad/triangle decision inverted;
- vertex-0 slot advance (+4 slots vs +3);
- triangle EOS writer offset (slot 2 vs slot 1);
- first-slot kept in `r14`;
- `r9` zeroed on exit;
- `r5` advance (2*64 per quad);
- v1 slot control word;
- specular source (intensity vs specular);
- triangle selector branch sense;
- intensity add condition (`ndl > 0`);
- diffuse lane order;
- vertex-0 control word.

The `via_adder` (`0.0 + n0`) is *not* in the gate: under round-toward-zero
with FTZ on `0.0 + n0` equals `n0` for every representable `n0` that reaches
the output — for a denormal it is flushed to zero, and for `-0.0` the sign
flip is discarded by the `> 0` N.L/N.H gates before any written value — so
dropping it changes nothing observable in the flat-RAM contract.  It is
still present in the source (it mirrors the guest's `via_adder = 1`).
