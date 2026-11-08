# The float division / reciprocal helper (SH-4 0x8C0533A4)

A readable port of the fight engine's software reciprocal helper, and the
evidence for it - the third SRP-cut under `src/fight/readable/` after
`vmu_cmd_name` and (in its own folder) the `readable/` directory.

## The function

| entry | body | what it does |
|---|---|---|
| `0x8C0533A4` | `0x0C0533A4..0x0C053418` (116 B) | a fixed-point software reciprocal: takes a float's bits in fr0 and writes a two-word answer into the caller's cell at sp+16 |

It is an **off-baseline leaf** - it is not in the baseline inventory
(`extract/analysis/funcs_1ST_READ.unsc.bin.csv`, which jumps from `f_8c0532ca`
to `f_8c0535a2`) - so its body span is worth its own credit: **116 bytes** of
new coverage.

The function is a **self-contained leaf**: it calls nobody and uses no FP
instruction (beyond reading fr0's bits), so the port needs no stub and no FP
context.

The port: `src/fight/readable/fdiv.c`, registered in `src/fight/readable.c`
as `fdiv`.

## What the function does

**The input.**  The dividend's bits arrive in fr0.  The entry stores fr0 on
the stack (`fmov.s fr0,@-r15`) and pops it into r0, so the input travels
through a transient stack slot - a store whose width follows FPSCR (single
here) and a reload.  That store/reload is part of the contract: it leaves the
input's bits at `sp-4`.

**The split.**  The body looks at the **exponent byte** - the top byte of
`2*r0`, masked with `0xff` from the pool at `0x0c053418`:

| exponent byte | the input | the answer |
|---|---|---|
| `0xff` and mantissa 0 | infinity | cell `= (0, 0x7ff00000)` |
| `0xff` and mantissa != 0 | NaN | cell `= (1, 0x7ff00000)` - straight to the tail, no pack |
| `0x00` and mantissa 0 | zero | cell `= (0, 0x00000000)` |
| `0x00` and mantissa != 0 | denormal | the mantissa is normalised up, the exponent counted down into the bias, then the ordinary pack |
| anything else | ordinary | the exponent is biased by `0x380` (the pool at `0x0c053428`), then the ordinary pack |

**The pack.**  The ordinary path (and infinity, zero and the normalised
denormal) all converge on one shared carry-rotate sequence: `r0` is shifted
eight, then a fixed ladder of `shlr`/`rotcr` steps folds the T bit in and out
of `r3` (the accumulator) and `r0`, `r2`'s top bit is fed in through `shll`,
and the exponent word (`r1`, shifted left twenty) is or-ed into `r0`.  The
whole guest register file is part of the answer, because every one of those
steps writes SR's T bit.

**The tail.**  Every path ends the same way: the result cell is read from the
caller's frame at `sp+16`, `r3` is written to `cell[0]` and `r0` to
`cell[1]`, the four caller-saved registers `r3 r2 r1 r0` are restored from
`sp+0/+4/+8/+12`, and the stack pointer ends at `sp+20`.

## The evidence

The three arms are the retained generated translation (`src/fight/vf3_c90e_adapter.c`,
which still serves the entry through the router), the readable port called
directly, and the readable port reached through the readable override.  All
three are compared **byte for byte**: the whole register file (including SR and
its T bit), the exit PC, the failed PC, the out-of-window counter and every RAM
byte, over nine scenarios that cover every branch - infinity, NaN, zero, two
denormals, 1.0, 2.0, -2.0 (the corpus' own input, `0xc0000000`, seen in
`percentage_loaded_states_dev`) and a normal with mantissa bits.  Plus the
outcome is checked against the fixture itself: the two words written to the
cell, the T bit, the four restored caller registers (distinct values at
`sp+0/+4/+8/+12`, so a port that pops them in the wrong order fails) and the
`sp+20` stack-advance.

```
build\vf3fdiv.exe -> fdiv: 9 differential cases - PASS
```

The mutation gate (`tests/fdiv_mutations.json`, `tools/mutate.py
--target vf3fdiv`) proves the differential has teeth: it breaks the port one
way at a time and requires the test to notice.  **15/15 caught.**

Two details worth recording:

* **The denormal normaliser's loop back-edge returns to the decrement, not to
  the leading shift.**  The lead-out shift/test (`0x53406/0x53408`) run once;
  the loop body is *decrement, shift, test* (`0x5340a/0x5340c/0x5340e`), and
  its `continue` jumps back to the decrement.  The first version of the port
  looped back to the leading shift, doing one extra shift per iteration; the
  differential caught it on the smallest denormal (the module wrote
  `0x36a00000`, the buggy port `0x37580000`).
* **The `r1 & 0xff` mask is an identity.**  `r1 = r0 >> 16 >> 8` is already a
  byte (0..255), so masking it with the pool's `0xff` never changes anything.
  A mutation that removes it is therefore **not** in the mutation list: the
  guest's own behaviour makes it unobservable for any input.

## The oracle leg

The retained generated translation replays all four of the entry's corpora
cleanly (`percentage_loaded_states_dev_8c062b06_8c0533a4` 40/40,
`percentage_static_dev_8c041794_8c0533a4` 220/220,
`tenpp_isolated_fight_8c0533a4` 3/3, `tenpp_isolated_seeded_8c0533a4` 6/6),
and the differential proves the readable port is **byte for byte** that
translation, so the chain `readable == generated == oracle` closes
transitively.

Now it also closes **directly**: `tests/fdiv_oracle.c` routes the readable port
itself (`vf3_fdiv_entry`) over the per-entry `.cases` corpus
(`tests/vf3fdivoracle`), the same corpus the generated adapter replays, and it
passes **40/40 cases** with the whole 37-register file and every byte of every
window compared:

```
build\vf3fdivoracle.exe ->
  fdiv_oracle: 40/40 cases match (0 skipped) - PASS
```

This corpus is the strongest of the four because it carries the literal pool in
its own window (`0x0c053000`, the four scratch constants the guest reads from
the image), so the readable port finds them as captured runtime state rather
than as constants the test supplies (as `record_kind`'s oracle test must).  The
guest touches no device register, so no sidecars are needed.
