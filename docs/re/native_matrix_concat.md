# native_matrix_concat

`matrix_concat` (`0x8C03C0E0`) ported to plain C in `src/native/matrix_concat.c`
(`vf3_native_matrix_concat`), proved against the readable guest authority
(`src/fight/matrix_lib.c`, `vf3_matrix_concat_entry`) by
`tests/matrix_concat_native_replay.c` (differential) and by the mutation gate
(`tests/matrix_concat_native_mutations.json`, 9/9 caught).

## The leaf

`matrix_concat` is the post-multiply member of the column-major matrix family
`0x8C03B620..0x8C03C1FE` (`src/fight/matrix_lib.c`), the sibling of the
already-ported `matrix_premul` (0x8C03C1C0).  It loads the 16 floats at `r4`
as matrix M and computes

    XMTRX = XMTRX * M

by running each M column through `ftrv(XMTRX, ...)` — the column-major product
`out[4c+r] = sum_k xm[4k+r] * m[4c+k]`.  The guest's `frchg` bank swap puts the
**old** XMTRX into `FR0..FR11`, writes the product into XMTRX, and toggles
FPSCR.FR (`0x00200000`).  `FR12..FR15` travel through the stack (`FR15`,
`FR14`, `FR13` pushed at `sp0-4`, `-8`, `-12`, with `fr12` parked in FPUL) and
are restored, so `r15` is net flat.  `r4` advances by 64 bytes; SR is
untouched.

This is the *opposite side* of `matrix_premul`: there the loaded matrix
premultiplies (`XMTRX = M * XMTRX`), here it post-multiplies, and only here do
the banks end up swapped (FPSCR.FR toggles) and the old XMTRX land in the FR
bank.

## The port

`src/native/matrix_concat.c`:

- snapshots the old XMTRX (`old_xm`, a float copy of `a->xm[0..11]`) and the
  `FR12..FR15` bit patterns,
- writes the three pushed saved words onto the stack at `sp0-4..-12` and parks
  `fr12` in `a->fpul`,
- copies M out of the RAM at `r4`, advances `r4` by 64,
- computes `out[4c+r] = sum_k xm[4k+r] * m[4c+k]` (column-major, matching the
  guest `ftrv`),
- puts the old XMTRX into `fr[0..11]`, `out` into `xm`, toggles FPSCR.FR, and
  restores `fr[12..15]`.

`r15` and SR come back untouched.

## The proof

`tests/matrix_concat_native_replay.c` seeds the same flat RAM (M, the stack
region), the same XMTRX and the same `FR12..FR15`, runs the readable guest
entry and the native port, and compares the final XMTRX, `fr[0..11]` (the old
XMTRX), the preserved `FR12..FR15`, FPUL (= fr12), FPSCR.FR, the pushed stack
words, `r4` and `r15`.  The residual is the FPU difference (`ftrv` against the
native loop), tolerated at 2e-3.  Cases: base (rotation+translation M,
rotation XMTRX), zero XMTRX (XMTRX * M = 0, and the old XMTRX in fr is zero),
identity XMTRX (XMTRX * M = M), and negative `FR12..FR15` sentinels.

Two port/test care points surfaced:

- The `old_xm` snapshot has to be a **float** copy.  The first version held it
  in a `uint32_t[12]` initialised from `a->xm` values, so each float was
  truncated through the int (0.866 -> 0, 1.0 -> the denormal `0x00000001`),
  and the FR bank came out wrong even though the XMTRX product (which reads
  `a->xm` directly) matched.
- The stack bookkeeping reads `saved[j]` at `sp0-12 + 4*j` — the guest pushes
  `FR15` *first* (at `sp0-4`), so the lowest pushed word is `FR13`.

## The mutation gate

`tools/mutate.py --port src/native/matrix_concat.c --exe
build/vf3nativematrixconcat.exe --mutations
tests/matrix_concat_native_mutations.json --target vf3nativematrixconcat
--keep-going` catches **9/9**: multiply transposed, multiply row-major, `xm`
not updated, `fr` wrong source (old XMTRX replaced by the product), `r4` not
advanced, `fr` restored to the wrong slot, FPUL from the wrong saved word,
stack desc order, and FPSCR.FR not toggled.

No regression to the coverage union (`docs/coverage.md` left untreated).
