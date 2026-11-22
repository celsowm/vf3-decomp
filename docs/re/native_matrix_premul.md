# native_matrix_premul

`matrix_premul` (`0x8C03C1C0`) ported to plain C in `src/native/matrix_premul.c`
(`vf3_native_matrix_premul`), proved against the readable guest authority
(`src/fight/matrix_lib.c`, `vf3_matrix_premul_entry`) by
`tests/matrix_premul_native_replay.c` (differential) and by the mutation gate
(`tests/matrix_premul_native_mutations.json`, 9/9 caught).

## The leaf

`matrix_premul` is the pre-multiply member of the column-major matrix family
`0x8C03B620..0x8C03C1FE` (`src/fight/matrix_lib.c`).  It loads the 16 floats
at `r4` as matrix M and computes

    XMTRX = M * XMTRX

by running each old XMTRX column through `ftrv(m, ...)` — the column-major
product `out[4c+r] = sum_k m[4k+r] * xm[4c+k]`.  The `fr` (front FP) bank
ends with the first twelve floats of M (`fr[0..11] = m[0..11]`), and
`FR12..FR15` are preserved (they travel through the stack).  `r4` advances by
64 bytes; `r15` and SR are untouched.

This is *not* the `matrix_concat_pair` (0x8C03DD00) convention.  That leaf
reads its stored matrices **row-major** and concatenates `XMTRX * A * B`;
`matrix_premul` lives in the documented **column-major** family, and its
per-column `ftrv` is exactly the product the native `vf3_native_matrix_multiply`
shape computes (at 2e-3 native tolerance).  The two existing native matrix
helpers (`matrix_concat_pair.c`, `matrix.c`) cannot be reused: the former is
row-major for a different function, the latter is column-major but a different
leaf's shape — so the port writes its own 4x4 column-major loop.

## The port

`src/native/matrix_premul.c`:

- saves `FR12..FR15` bit patterns,
- writes the four saved words onto the stack at `sp0-4..-16` in the guest's
  push order (`FR15` at `sp0-4`, ... `FR12` at `sp0-16`),
- copies M out of the RAM at `r4`, advances `r4` by 64,
- computes `out[4c+r] = sum_k m[4k+r] * xm[4c+k]` (column-major, matching the
  row/col of the guest `ftrv`),
- puts the first twelve floats of M into `fr[0..11]`, `out` into `xm`, and the
  saved `FR12..FR15` back.

`r15` and SR come back untouched (the stack pointer's round trip is net-zero:
four pushes, four pops worth of address space).

## The proof

`tests/matrix_premul_native_replay.c` seeds the same flat RAM (M, the stack
region), the same XMTRX and the same `FR12..FR15`, runs the readable guest
entry and the native port, and compares the final XMTRX, `fr[0..11]` (= first
twelve floats of M), the preserved `FR12..FR15`, the pushed stack words, `r4`
and `r15`.  The residual is the FPU difference (`ftrv` against the native
loop), tolerated at 2e-3.  Cases: base (rotation+translation M, rotation
XMTRX), zero XMTRX (M * 0 = 0), identity XMTRX (M * I = M), and negative
`FR12..FR15` sentinels.

Two test-harness care points surfaced:

- The stack bookkeeping has to read `saved[j]` at `sp0-16 + 4*j` — the guest
  pushes `FR15` *first* (at `sp0-4`), so the lowest address holds `FR12`.
  An `order` array written the other way round flagged every stack word.
- The stack region must be cleared before the native run.  An unwritten slot
  inherits the *guest's* leftover (correct) value, so a mutation that shifts a
  push to a different address is invisible until the slot reads as zero.

## The mutation gate

`tools/mutate.py --port src/native/matrix_premul.c --exe
build/vf3nativematrixpremul.exe --mutations
tests/matrix_premul_native_mutations.json --target vf3nativematrixpremul
--keep-going` catches **9/9**: multiply transposed, multiply row-major,
`xm` not updated, `fr` wrong source, `r4` not advanced, `saved` taken from the
front bank, stack desc order, stack write to the wrong address, restored wrong
slot.

No regression to the coverage union (`docs/coverage.md` left untreated).
