# Fight geometry: descriptor/quad/vertex layout (from oracle-verified ports)

Source functions: `0x8C068F92` (orient2), `0x8C068FF6` (poly_classify),
`0x8C071A76` head block (vecpush). Ports: `src/fight/orient2.c`,
`src/fight/poly_classify.c`, `src/fight/vecpush.c`.

## The vec3 idiom
Hot fight code is built from one unrolled idiom (single-precision FPU,
round-to-nearest, same as C float):

```
; sub family (0x8C071A76 block, 0x8C071ABC/ADE/AFE siblings)
f0 = A[0]; f3 = B[0]; f1 = A[1]; f4 = B[1];
f0 -= f3;  f2 = A[2]; f5 = B[2];
f1 -= f4;  f2 -= f5;
[r4+8] = f2; [r4+4] = f1; [r4] = f0;   ; high-to-low pre-decrement stores
; add family (0x8C070852): same shape with fadd
```

The three result stores land at `[dst+8], [dst+4], [dst]`, leaving the
pointer back at `dst`. Source triples are 12-byte `(x, y, z)` records.

## Register conventions (recovered)
- `r4`  caller scratch pointer. Every routine spills entry `fr0` to
  `*(r4-4)` first (callees clobber fr0-fr5); `r4` is then reused as the
  destination cursor.
- `r13` destination triple base (stack frame, `0x0C31Fxxx` in-fight).
- `r9/r10/r11/r14` source triple bases (model arena `0x0C2Bxxxx` in-fight).
- `r15` caller frame: `[r15]` cursor pointer (+24 per push), `[r15+4]`
  saved, `[r15+8]` saved, `[r15+20]` count.
- `fr4/fr5` sample point for the orientation tests.

## orient2 (0x8C068F92, 54 B)
2x2 determinant sign over six floats, bit-per-outcome:
`d = (p0y-Py)*(p1x-p0x) - (p0x-Px)*(p1y-p0y)` returns 2/1/4 for
`d > 0 / d == 0 / d < 0`. Called 5x per vertex by poly_classify.

## poly_classify (0x8C068FF6, 288 B)
Descriptor walk + quad edge classification:
```
flags = *r4;                    if (flags & 1) return 1;
rec   = *(r4+4) + *r3;          stored = *rec & 1;
if (*(float*)(rec+24) == 0)     return 0;
p0..p3 = *(rec+4..16) + *r3     ; four (x,y) points
h1..h5 = orient2(P, p0p1, p1p2, p2p0, p2p3, p3p0)
m  = h3 | (h1&6) | (h2&6);      if (bit2(m) != bit4(m)) return 2;
if (stored)                     return 0;
a  = h1 | (h2&6) | (h4&6) | (h5&6);
return (bit2(a) != bit4(a)) ? 4 : 0;
```
Pointers are absolute P1/P2 addresses; the replay map emulates the SH-4
address space (see `vf3_ram_map`).

## vecpush head block (0x8C071A76, 66 B of a ~1 KB pipeline)
Counter-gated single vec3-sub with caller-frame bookkeeping:
```
[r15+4] = r14; r14 = r11;
[r15]   = [r15] + 24;
r2 = [r15+20]; [r15+8] = r2;
if (!(r2 > r9 signed)) -> out-of-range handler jump 0x8C2A1C2A;
r8 += 24; r11 += 24;
dst[0..2] = A[0..2] - B[0..2] with A = in_r14, B = in_r11, dst = in_r13;
```
The pipeline continues for ~1 KB (cross products via `fmac`, normalizes via
`fldi0`+`fdiv`, blends) through the `f_8c071aXX` chunks and a per-vertex
loop (`jmp @r1` back to `0x8C071A96`, ~200 instructions/vertex). Because the
routine tail-transfers, it is validated piecewise at the interior point
`0x8C071ABE` (tools/pair_cases.py), not entry->exit.

## Oracle notes
- On SH-4 `bf`/`bt` are direct jumps (no delay slot); only the `/s` forms,
  `bra/bsr/jsr/jmp/rts/rte` are delayed. `tools/sh4.py` used to mislabel
  this (fixed).
- `jmp @Rn` (0x4n2B) is used both for computed loops and noreturn tails;
  the depth tracker must not count it as a call, and exit pairing only
  applies to returning functions.
