# native_matrix_set_translation — the XMTRX set-translation leaf (0x8C03CBD0)

The readable port `src/fight/leaf_math.c` (`vf3_matrix_set_translation_entry`)
is rewritten as plain C in `src/native/matrix_set_translation.c`
(`vf3_native_matrix_set_translation`), proved against it by
`tests/matrix_set_translation_native_replay.c` (3 differential cases) and by
the mutation gate (`tests/matrix_set_translation_native_mutations.json`, 5/5
caught).

## The leaf

A call-free, no-stack, integer-only leaf: the three source floats at `r4`
travel as raw 32-bit words into the XMTRX translation words:

```
XMTRX[12] = r4[0]
XMTRX[13] = r4[1]
XMTRX[14] = r4[2]
r4 += 12
```

No other register, no SR bit and no FR bank cell is touched.  XF0..15 are the
XMTRX bank (`a->xm[16]`).  The existing `vf3_aim_set_translation` helper in
`aim_math.c` copies the same three words but is a pose-callee utility that
does not advance r4 and carries no register contract, so this leaf is written
out on its own for a self-contained port.

## The test

`tests/matrix_set_translation_native_replay.c` seeds both sides with the same
flat RAM (the three source floats at `SRC`) and the same XMTRX / FR bank,
runs the leaf, and compares the whole XMTRX bank, the whole FR bank and every
general register against the guest.  Three cases: an ordinary translation, one
with signs and extreme exponents (1e12 / 1e-12 / -1234.5), and one seeded with
raw bit patterns.  A fixture model independently checks that `xm[12..14]` took
the three source words and that `r4` advanced by 12.

## The mutation gate

`tests/matrix_set_translation_native_mutations.json` applies 5 single
mutations: a swapped source float into `xm[13]`, `xm[12]` sign-flipped, a wrong
`r4` advance, `xm[14]` dropped, and a shifted source base.  All 5 are caught.

## Authority

The readable port is the authority; the chain is *native == readable*.  No
oracle corpus names this exact entry as a watched specimen, so the proof
stands on the differential against the readable translation.

Result: **3/3 PASS**, **5/5 mutations caught**.
