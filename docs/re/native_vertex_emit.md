# native vertex_emit (0x8C048C20)

`src/native/vertex_emit.c` (`vf3_native_vertex_emit_ring`) is the plain-C
port of the readable `src/fight/vertex_emit.c`
(`vf3_vertex_emit_ring_entry`), proved by
`tests/vertex_emit_native_replay.c` (6 differential cases) and the mutation
gate `tests/vertex_emit_native_mutations.json` (10/10 caught).

## The function

A call-free integer leaf with no FPU arithmetic, no guest callees, no stack
frame and no device access - the only control transfer is the final tail
transfer to `pr`.  It is the clip-ring emitter of the strip transformers:
`vertex_light` (0x8C048B00) leaves a lit, transformed vertex in registers

```
FR4 = w'  FR5 = y'  FR6 = z'  FR7 = 1/x'   FR2 = diffuse  FR3 = specular
r1, r2 = the record's two trailing words (w1, w2)
```

and this emitter packs it into one 32-byte slot of the 4-slot ring at
`0x0C1A5960`, chosen by `(r11 & 3)`:

```
+00 FR4  +04 FR5  +08 FR6  +0C FR7  +10 r1  +14 r2  +18 FR2  +1C FR3
```

It leaves `r0` = the slot offset (slot * 32) and `r10` = the slot's low
address.

## What the port has to keep

- **The ring slot is chosen by `(r11 & 3)`**, so large `r11` values (and a
  wrap like 7 -> 3) land in the same four slots.
- **The eight words are pure copies** of the live FR bank and of `r1`/`r2` -
  there is no arithmetic at all, so the exact bit patterns travel through.
- **`r0` is the offset, `r10` the slot address** (the guest computes both
  from the same base).
- **Tail-transfer to `pr`**: nothing writes it.  The readable's FPSCR-SZ
  guard (the code assumes SZ=0 on entry) is a dispatcher concern, not part of
  the leaf's arithmetic.

## Everything else

`vertex_emit_ring` was a genuinely call-free, un-nativized leaf (the
address-based sweep against `src/native` lists it as un-nativized).
`vertex_emit_sq` (0x8C048BE0), its store-queue sibling, scales `FR5`/`FR6`
by `FR7` and issues a store-queue PREF, so it is a separate, more involved
leaf; this port covers the pure-copy ring emitter.
