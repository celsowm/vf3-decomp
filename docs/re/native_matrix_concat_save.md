# native_matrix_concat_save

`matrix_concat_save` (`0x8C03C140`) and its parent `matrix_concat_parent`
(`0x8C03C200`) ported to plain C in `src/native/matrix_concat_save.c`
(`vf3_native_matrix_concat_save` / `vf3_native_matrix_concat_parent`), proved
against the readable guest authorities (`src/fight/matrix_lib.c`,
`vf3_matrix_concat_save_entry` / `vf3_matrix_concat_parent_entry`) by
`tests/matrix_concat_save_native_replay.c` (differential) and by the mutation
gate (`tests/matrix_concat_save_native_mutations.json`, 9/9 caught).

## The leaves

`matrix_concat_save` is the sibling of `matrix_concat` (0x8C03C0E0) in the
column-major matrix family `0x8C03B620..0x8C03C1FE`
(`src/fight/matrix_lib.c`).  It loads the 16 floats at `r4` as matrix M and
computes

    XMTRX = XMTRX * M

by running each M column through `ftrv(XMTRX, ...)`, the column-major product
`out[4c+r] = sum_k xm[4k+r] * m[4c+k]`.  The banks end up swapped (`frchg`):
the old XMTRX shows in `FR0..FR11` and FPSCR.FR (`0x00200000`) toggles.

The difference from `matrix_concat` is *only* in how the caller's
`FR12..FR15` are protected.  `matrix_concat` parks `fr12` in FPUL and pushes
only `FR13..FR15`, then reads them back off the stack.  `matrix_concat_save`
pushes **all four** saved words (a 16-byte round trip on the stack pointer)
and puts them straight back into the new FR bank from the saved registers, so
**FPUL is untouched**.  `r4` advances by 64 bytes.  SR is untouched.

`matrix_concat_parent` is a thin wrapper: it derives `r4` as one matrix (64
bytes) below the matrix stack top (`*(0x0C19D2E4 + 8)`, i.e.
`*(0x0C19D2EC)`) and then runs `matrix_concat_save`.

## The port

`src/native/matrix_concat_save.c`:

- snapshots the `FR12..FR15` bit patterns and the old XMTRX
  (`old_xm`, a float copy of `a->xm[0..11]`),
- writes the four saved words onto the stack at `sp0-4..-16` (saved[3]=FR15 at
  `sp0-4`, ... saved[0]=FR12 at `sp0-16`),
- copies M out of the RAM at `r4`, advances `r4` by 64,
- computes `out[4c+r] = sum_k xm[4k+r] * m[4c+k]` (column-major, matching the
  guest `ftrv`),
- puts the old XMTRX into `fr[0..11]`, `out` into `xm`, toggles FPSCR.FR,
  restores `fr[12..15]` from the saved registers, and pops the 16-byte stack
  round trip back (`r15 = sp0`).

The parent function reads the matrix stack top out of the flat RAM, subtracts
64 into `r4`, and calls the save implementation.

## The proof

`tests/matrix_concat_save_native_replay.c` seeds the same flat RAM (M, the
stack region), the same XMTRX and the same `FR12..FR15`, runs the readable
guest entry and the native port, and compares the final XMTRX, `fr[0..11]`
(the old XMTRX), the preserved `FR12..FR15`, FPUL (**untouched** - seeded with
a sentinel that must survive), FPSCR.FR, the four pushed stack words, `r4` and
`r15`.  The residual is the FPU difference (`ftrv` against the native loop),
tolerated at 2e-3.  Cases: base (rotation+translation M, rotation XMTRX), zero
XMTRX, identity XMTRX, and negative `FR12..FR15` sentinels - plus a parent
case that plants M at 0x0C200000 and points the matrix stack top just past it,
so the derived `r4` lands on M, and compares the same contract through the
parent entry.

The one care point that surfaced: the stack bookkeeping reads `fr1215[j]` at
`sp0-16 + 4*j` - the guest pushes all four saved words (`FR15` at `sp0-4`,
`FR12` at `sp0-16`), so the lowest pushed word is `FR12`, and the test indexes
the `saved` array linearly (`saved[j] = fr[12+j]`), unlike `matrix_concat`
where only three words ride the stack.

## The mutation gate

`tools/mutate.py --port src/native/matrix_concat_save.c --exe
build/vf3nativematrixconcatsave.exe --mutations
tests/matrix_concat_save_native_mutations.json --target
vf3nativematrixconcatsave --keep-going` catches **9/9**: multiply transposed,
multiply row-major, `xm` not updated, `fr` wrong source (old XMTRX replaced
by the product), `r4` not advanced, `fr` restored to the wrong slot, stack
desc order, only three words pushed (the fourth stack slot goes unwritten),
and FPSCR.FR not toggled.

No regression to the coverage union (`docs/coverage.md` left untreated).
