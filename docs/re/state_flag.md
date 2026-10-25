# The fight engine's state flag (SH-4 0x8C0B0FD2)

A readable port of the fight engine's state flag, and the evidence for it.

## The function

| entry | body | what it does |
|---|---|---|
| `0x8C0B0FD2` | `0x0C0B0FD2..0x0C0B1032` (96 B) | sets one of two bits in a word the caller hands over, or nothing at all |

It is an **off-baseline leaf** - it is not in the baseline inventory
(`extract/analysis/funcs_1ST_READ.unsc.bin.csv`) - and its ledger row carried a
size of 0, so its body span is worth its own credit: **96 bytes** of new
coverage.

The function is a **self-contained leaf**: it calls nobody and it uses no FP
instruction, so the port needs no stub and no FP context.

The port: `src/fight/state_flag.c`, registered in `src/fight/readable.c` as
`state_flag`.

## What the function does

**The gate.**  The word at `r7` is the fight engine's state word.  The pool's
mask names the bits the word may already carry; when it carries any of them the
function does **nothing** - it does not even write the word back, and it leaves
every register but r2, r3 and the T bit alone.

**The value.**  `r5` points at a structure that holds a halfword, at the offset
the pool names.  The guest reads that halfword signed, throws the sign away
again (`extu.w`), subtracts `r6` from it and flips the sign bit with the pool's
xor constant, and reads the low sixteen bits back signed (`exts.w`).  What is
left is a signed number - in the game's own numbers, roughly the negated
difference between the halfword and `r6`.

**The bands.**  The value falls into one of two bands, and they are mirror
images of each other:

| band | from | to |
|---|---|---|
| the middle band | the pool's middle bound | the pool's low bound |
| the high band | the pool's high bound | the pool's second high bound |

The pool's own numbers make them so: the middle band runs from **-27300** to
**-5460** and the high band from **5460** to **27300**.  A value between the
two bands is in neither, and so is a value outside both - the function leaves
the word alone.

**The parity bit.**  One bit decides which of the two flags is set.  It comes
out of two words the guest shifts out of the structure `r4` points at: the
first word shifted right by 25 and the second one - 72 bytes further on -
shifted right by 10, and the two exclusive-ored.  Only the low bit of the
result counts.

**The answer.**  In the **middle band** a clear parity bit sets the low bit
(`0x0800`) and a set one sets the high bit (`0x1000`); in the **high band** it
is the other way round.  The bit is or-ed into the state word.

## The literal pool

Every entry is read at run time, the way the guest reads it.  The oracle's
captured RAM gives the game's own values:

```
0x0C0B1070 -> 0x1494      the offset of the value's halfword
0x0C0B1072 -> 0xEAAC      the middle band's upper bound   (-5460)
0x0C0B1074 -> 0x955C      the middle band's lower bound   (-27300)
0x0C0B1076 -> 0x0800      the bit the low answer sets
0x0C0B1078 -> 0x1554      the high band's lower bound      (5460)
0x0C0B107A -> 0x6AA4      the high band's upper bound      (27300)
0x0C0B107C -> 0x1000      the bit the high answer sets
0x0C0B1094 -> 0x00A02000  the gate's mask
0x0C0B1098 -> 0x00008000  the xor constant
```

## The details the port has to keep

**The two bands answer the opposite way round.**  This is the trap of the
function.  In the middle band a *clear* parity bit sets the low bit; in the
high band a *clear* parity bit sets the high bit.  The corpus only ever
reaches the high band, so a port that read the middle band the high band's way
round would still replay the corpus - and the differential's fixture has to
carry both bands.

**The two `bf`s have different targets, and both branch when the T bit is
clear.**  The guest's `bf` at `0x0C0B100A` jumps to the *high bit* write and
the one at `0x0C0B1024` jumps to the *low bit* write; the same rule (branch
when the T bit is clear) gives both the right answer, but the two arms read
opposite.  A `bf` that branches when the T bit is *set* sends the tree the
wrong way at both of them.

**`tst` sets the T bit when the AND is zero.**  The guest's `tst r5,r5` at
`0x0C0B1022` and the one at `0x0C0B1008` therefore set the bit when the parity
bit is *clear* - which is what makes the two bands answer the opposite way
round.

**The guest's `shad` with a negative count shifts right.**  The count is the
count's two's complement masked to five bits, and the fill is the sign bit.
The corpus pins it: the word `0xA6000000`, shifted by the second count, comes
out as `0xFFE98000` - an arithmetic shift right by ten, not by twenty-two and
not by five.

**The registers the guest leaves** differ per path, and the port reproduces
them:

| path | r0 | r1 | r2 | r3 | T |
|---|---|---|---|---|---|
| the gate is closed | the caller's | the caller's | the state word | the mask | 0 |
| above the high band | the high bound | 1 | -10 | the second high bound | 1 |
| below the high band | the high bound | 1 | -10 | the low bound | 0 |
| the high band, the low bit | the high bound | the state word or the low bit | -10 | the low bit | 0 |
| the high band, the high bit | the high bound | 1 | the state word or the high bit | the high bit | 1 |
| the middle band, the low bit | 72 | the state word or the low bit | the middle bound | the low bit | 1 |
| the middle band, the high bit | 72 | 1 | the state word or the high bit | the high bit | 0 |

r4 is the second parity word after its shift, r5 the parity bit and r6 the
value.

## The evidence

**The differential** (`tests/state_flag_replay.c`, 14 cases) compares three arms
on the whole register file, the return PC, the failed PC, the out-of-window
counter and every RAM byte: the generated chain (the reference), the readable
port called directly, and the readable port reached through the readable
override (which is how the native tick reaches it).  It also checks the outcome
**against the fixture itself** - the eight registers, the T bit and the state
word - against a second implementation written from the disassembly and reading
the fixture's own bytes, so a fixture that is not where the guest looks cannot
make both sides agree on the same wrong bytes.

The fixture uses the game's own addresses but values the corpus does not carry:
**every one of the pool's nine entries is varied** (the corpus always carries
the game's own numbers), the scenario values cover **every branch of the
guest's tree** - the gate, the value between the bands, above the high band,
below the middle band, both bands with both answers - and **all four band
boundaries** are covered, because the corpus reaches none of them.

**The oracle** (`tests/state_flag_oracle.c`) runs two corpora:
`extract/analysis/fight_all_cases/f_8c0b0fd2.cases` - **277/277 cases match
(0 skipped) - PASS**, the readable port served the entry 277 times - and
`extract/analysis/fight_release_cases/f_8c0b0fd2.cases` - **341/341 cases match
(0 skipped) - PASS**, served 341 times.  The comparison covers every register,
the XF registers, the FPUL, the GBR, the banked registers, the exit PC and
every byte of RAM - and the state word the guest writes is one of those bytes.

**The mutations** (`tests/state_flag_mutations.json`, 39 of them) are all caught
by `tools/mutate.py`: every one of the pool's nine entries, the two shift
counts, the sign fill of the shift, the count's two's complement, the pool's
sign extension, the value's sign extension, the xor constant, the subtracted
offset, the two parity words and their offsets, the parity bit's mask, the
gate's test and its branch, all four band boundaries, both bands' answers, the
state word's read and its write in both bands, the T bit and the return
address.

Three mutations were **missed** on the first run and are therefore *not* in the
list:

* **the transient T bit of a comparison.**  The guest's comparisons set the T
  bit and the branch reads it, and the port writes the two as separate
  expressions.  Four of the comparisons' T bits are *overwritten* by the next
  test before the function returns, so they are **unobservable** - except at
  the band boundaries, and a value *at* a boundary takes the other path.  The
  mutations that flip the **branch** are the observable ones, and those are in
  the list.
* **the `extu.w` that throws the value's sign away.**  The guest truncates the
  halfword to sixteen bits before subtracting; the truncation only touches the
  high bits, and only the low sixteen bits of the result are read back, so the
  store is **unobservable**.  The port keeps it only to mirror the guest.
* **the out-of-window counter of the return.**  Every fixture the differential
  builds is inside the captured windows, so `ram->oob` is always zero and the
  function's own failure condition cannot be seen.  The oracle leg does see it:
  the corpus' windows are the reference's, and a read outside them is counted
  there.

## The tooling lessons

* **The generated translation's `shad` is a signed variable shift, and the
  corpus pins it.**  The translation models `shad Rm,Rn` as "a negative count
  shifts right by the count's two's complement masked to five bits", which is
  not what the SH-4 manual's "shift by half the count" rule says.  The
  corpus' exit register settles it for this image: the second parity word
  `0xA6000000` comes out as `0xFFE98000`, an arithmetic shift right by **ten**
  - the translation's model, not the manual's.  The port reproduces what the
  reference does and says so in its own source.
* **A filtered dump of the module can invert a branch.**  `build/fn.py` (and
  `tools/adapter_body.py`) print the blocks of a generated module, and reading
  a `bf`'s target out of that listing is easy to get wrong - the two `bf`s of
  this function point at *opposite* arms, and a listing that loses a block
  turns one of them into its mirror image.  The **raw module source** is the
  authority: `src/fight/fight_adapters_2.c`, blocks `P_0c0b0fd2`..
  `P_0c0b1030`.
* **The corpus' own `ops.json` is the executed path, not the body's
  instruction list.**  For this entry it lists 38 of the body's 48
  instructions: the eleven specimens that reach the tree all take the high
  band, and none of them ever sets the low bit.
* **A boundary the corpus does not reach is a hole in the proof.**  The
  corpus' values never land on a band boundary, so the comparisons' `<` and
  `<=` are interchangeable *in the corpus*.  The differential's fixture has to
  carry the four boundaries itself.
