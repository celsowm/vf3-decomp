# MT motion VM — channel evaluator semantics (M24, 2026-09-23)

Port: `src/fight/mt_play.c` (`vf3_mt_eval_frame`), traced/true listing of
`f_8c09d690` (390 B) from the corrected image, 1:1 at the instruction level.
Tests: `tests/mt_vm_interp.c` (vf3vm) — value-level parity incl. endpoints.

## Inputs (per call = one fighter's active motion for one frame)

```
task+0x1D00 -> hdr (motion instance header, INSIDE the resident pack area)
   hdr[0] (u32) -> counts  stream  : 1 byte per keyframed channel
   hdr[1] (u32) -> times   stream  : packed key-time bytes (u8 << 8 units)
   hdr[2] (u32) -> tuples  stream  : float data (scalar / vec3 triples)
   hdr+12       -> ops[63]         : one opcode byte per channel
r5 arg  -> float **out_pp  (63 floats written, cursor advanced by 63)
r6 arg  -> phase           (current motion time, units of 1/256)
((u16*)(task+0x1A00)) -> cycle length (frame-wrap key time, <<8)
```

The streams are absolute u32 pointers inside the record data (positioned at
mount; see "mount-time relocation" below).

## Channel decode (asm anchor: the 63-iteration loop 0x8C09D6AC..0x8C09D80C)

| op | semantics | tuple advance |
|---|---|---|
| 0 | channel = 0.0f | none |
| 1 | channel = *(tuples++) (literal passthrough) | 4 B |
| 2 | scalar channel, keyframed (below) | 4*(cnt+2) B |
| >=3 | vec3 spline channel (below) | 12*cnt+8 B (12*cnt+16 on exact key hit)|

### Keyframed channel (op >= 2)

1. `cnt = *counts++` (cursor B; byte count of keys for this channel).
2. Scan key times `times[k] << 8` (k = 0..cnt-1) against `phase`:
   - first `kt > phase`: in-between → lerp between tuples `idx` and `idx+1`,
     span = `kt - prevT` (`prevT` = previous key time, initial 0x100).
   - `kt == phase`: exact → value = tuple[idx+1] directly.
   - exhausted (all `kt <= phase`): wrap — `nextT = cycle << 8`, i.e. the
     animation loops with the table word as period.
3. Scalar (op==2) in-between: `v = v0 + (t)*(v1-v0)`, `t = rel/span`,
   `rel = phase - prevT` (fmac form at 0x8C09D7F0).
4. Spline (op>=3) in-between: Hermite cubic with tuple = (x, y·256, z·256):
   `slo = t*z0 + (t-1)*y0; v = v0x + rel*(t-1)*(1/256)*slo + t*t*(2t-3)*(v0x - v1x)`
   (constants: 1/256 @ 0x8C09D830, -1.0 @ 0x8C09D834; endpoint-checked).
5. Post-pass (unconditional, 0x8C09D408): negate z-channel of all 21 vec3
   outputs (7 from out+8 stride 12, then 14 from out+84 stride 12).

Registers (entry): r4 = task, r5 = out_pp, r6 = phase.
Output order: channel i written to out[i]; then the negate pass runs over the
whole block and *out_pp advances to out+63.

## Verified

- tests/mt_vm_interp.c: literal/zero/scalar-lerp/spline channels, mid-span
  and exact-key phases, cursor advance count = 63. All PASS.
- Trace anchors (M14 stream): counts read via pc 0x8C09D6F4, times via
  0x8C09D70A, tuple floats via 0x8C09D778/77E/782/794 (interp pc = +2).

## Open threads

- **Mount-time relocation**: the resident pack is not an identity copy of the
  file: the record region shifts linearly (~+0x27B0 in the vf3_7 capture) and
  the 8880-entry slot table is rewritten (dump slot5093 = 0xFE1A4 vs file
  0xCE154). The loader (mt_loader family) must be characterized next:
  where the per-character window is cut from the file, and how header
  absolute pointers are fixed up. Candidates: GDFS read completion handlers
  around the M13 ladder's 1222 KB menu->load transition region.
- ops[63] *channel meaning* (which of the 63 = which DOF/bone) — from the
  POL model bone count + task struct consumers of the out array.
