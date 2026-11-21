# native_xf_store — the shadow-bank store (0x8C03B820)

The readable port `src/fight/small_leaves.c` (`vf3_xf_store_entry`) is
rewritten as plain C in `src/native/xf_store.c` (`vf3_native_xf_store`),
proved against it by `tests/xf_store_native_replay.c` (3 differential cases)
and by the mutation gate (`tests/xf_store_native_mutations.json`, 5/5 caught).

## The leaf

A call-free, no-stack word copy: it stores three machine words out of the
XMTRX shadow bank into RAM:

```
XF12 -> r4+0
XF13 -> r4+4
XF14 -> r4+8
```

r4 ends unchanged.  In the guest the body is `r4 += 12`, then three
decrement-and-store steps that land back at the entry value; since each XF
word is copied as a raw 32-bit value there is no FPU arithmetic, and the
native leaf is a straight three-word copy.  XF0..15 are the XMTRX bank
(`a->xm[16]` in the native context).

The guest gates on `plain_fpu` (it models the fschg-adjacent pair moves that
read the shadow bank), but the leaf body performs no FPU operation, so a
plain-C transcription matches byte for byte under the corpus FPSCR
(`0x00040001`).

## The test

`tests/xf_store_native_replay.c` seeds both sides with the same flat RAM and
the same XMTRX / FR bank, runs the leaf, and compares the written region
(`dst-16 .. dst+8`), the whole XMTRX bank, the whole FR bank and every general
register against the guest.  Three cases: a plain shadow bank, one with signs
and extreme exponents (1e30 / 1e-30 / 1e12 / 1e-12), and one seeded with raw
bit patterns.  A fixture model independently checks that the three shadow
words land in order at `dst+0/+4/+8`.

## The mutation gate

`tests/xf_store_native_mutations.json` applies 5 single mutations:
XF12 written as XF13, XF13's sign flipped, XF14 written as XF12, a one-byte
offset destination, and the middle store dropped.  All 5 are caught.

## Authority

The readable port is the authority; the chain is *native == readable*.  No
oracle corpus names this exact entry as a watched specimen, so the proof
stands on the differential against the readable translation.

Result: **3/3 PASS**, **5/5 mutations caught**.
