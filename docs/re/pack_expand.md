# The packed-attribute expansion (SH-4 0x8C09D5AE)

A readable port of the fight engine's packed-attribute expansion, and the
evidence for it.

## The function

| entry | body | what it does |
|---|---|---|
| `0x8C09D5AE` | `0x0C09D5AE..0x0C09D664` (182 B) | expands sixteen packed bytes into sixteen groups of four two-bit fields, and writes the result into a block the record carries |

It is not in the baseline inventory
(`extract/analysis/funcs_1ST_READ.unsc.bin.csv`), so it is an **off-baseline
leaf** and its ledger row is worth its own body span: **182 bytes** of new
coverage, which takes the verified C address union from 406,560 to
**406,742 bytes (93.5782%)**.

The function is a **self-contained leaf**: it calls nobody and it uses no FP
instruction, so the port needs no stub and no FP context.

The port: `src/fight/pack_expand.c`, registered in `src/fight/readable.c` as
`pack_expand`.

## What the expansion is

**The addresses come out of the literal pool**, and the pool entries are read at
run time, the way the guest reads them.  The oracle's captured RAM gives the
game's own values:

```
0x0C09D6DC -> 0x0C29B9F8   the address of the table's pointer
0x0C09D6CE -> 8127         the record's offset of the packed byte
0x0C09D6D0 -> 7424         the record's offset of the destination
```

**The table** is reached through two indirections: the pool holds the *address*
of a pointer, and the pointer holds the table's base (`0x0C5F4000` in the first
specimen).  Its entries are **twelve bytes**: three offsets from the table's
base.  The **first** points at the packed bytes, the **second** and the **third**
at two more places the record wants to remember.

**Which entry** the record uses is the halfword at its **offset 60**, counted
from one - so the first entry is the record's halfword 1.  The captured fight
names entries as high as 2390, so the table is a large one.

**The source** is the first entry's first offset: a halfword of head, then the
**sixteen packed bytes** at `first + 2`.  **The destination** is the pointer the
record carries at the pool's destination offset.

The expansion itself is a loop of **sixteen rounds**.  Each round reads one
packed byte and writes **four bytes** - the byte's four two-bit fields, most
significant first - at the destination's offset 12, one group every four bytes.

## The details the port has to keep

**The record's own byte is bit 14 of the source's head, and only that bit.**
The guest shifts the head halfword right by twelve and masks it with four, so
the byte the record ends up with is `0` or `4` - never any other value.

**The record's packed byte moves up by 29.**  The guest keeps the byte in two
places: the original byte is copied 29 bytes up, and the record's own byte is
replaced by the head's bit 14.

**The pool's two offsets are sign-extended halfwords.**  The guest reads them
with `mov.w`, so an offset of `0x8000` is *negative* and the record's fields
then sit *below* it.  The corpus never carries such an offset - it always has
8127 and 7424 - so the differential's fixture does.

**The loop's delay slot advances the stride on the last round too.**  The
branch is `bf/s`, so its delay slot (`add #4,r5`) runs whether the branch is
taken or not; the guest leaves r5 at 64, not 60.

**The guest leaves the T bit set.**  The loop's `cmp/hs` compares the counter
with 16 and the loop ends with the counter *at* 16, so the comparison is true
and the bit is set.  The corpus' own SR confirms it: every specimen exits with
`0x60000001`.

**The registers the guest leaves** are r0 = the last byte it wrote (`value & 3`),
r1 = 16, r2 = the source after the last read (`first + 18`), r3 = where the last
group went (`dest + 72`), r4 = the destination, r5 = 64, r6 = the last packed
byte, r7 = 16.

**The order of the memory accesses is reproduced.**  The corpus compares every
RAM byte, and the guest's order is: the two stack words, then the source's head,
then the record's packed byte, then the two bytes it writes into the record,
then the destination pointer, then the destination's three words, then the
sixteen groups.

## The evidence

**The differential** (`tests/pack_expand_replay.c`, 6 cases) compares three arms
on the whole register file, the return PC, the failed PC, the out-of-window
counter and every RAM byte: the generated chain (the reference), the readable
port called directly, and the readable port reached through the readable
override (which is how the native tick reaches it).  It also checks the outcome
**against the fixture itself** - the eight registers, the T bit, the record's
two bytes, the destination's three words, the sixteen groups and the two stack
words - against a second implementation written from the disassembly and reading
the fixture's own bytes, so a fixture that is not where the guest looks cannot
make both sides agree on the same wrong bytes.

The fixture uses the game's own addresses but values the corpus does not carry:
the pool's two offsets are varied (the corpus always has 8127 and 7424), the
entry index ranges from 1 to 2400, and one scenario makes both offsets
*negative*.

**The oracle** (`tests/pack_expand_oracle.c`) runs the eight specimens of
`extract/analysis/coverage_65_natural_contracts_v1_cases/f_8c09d5ae.cases`:
**8/8 cases match (0 skipped) - PASS**, and the readable port served the entry
8 times.  The comparison covers every register, the XF registers, the FPUL, the
GBR, the banked registers, the exit PC and every byte of RAM.

The function is also reached by **186 other corpora** - a scan of the 13,348
`f_*.ops.json` call trees finds 187 in total - so it is not cold.

It is **not** in the oracle's state-7 tick census
(`extract/analysis/fxr_tick_s7_stats.csv`), so `docs/readable_status.csv` marks
it `unexercised`.  That label is about the tick census - the entry was never a
*watched* entry there - and not about the proofs: its own corpus, the 186
corpora that reach it and the differential all exercise it.

**The mutations** (`tests/pack_expand_mutations.json`, 45 of them) are all
caught by `tools/mutate.py`: every pool entry and the sign extension of both
pool offsets, the entry's stride and its three offsets, the index's origin, the
head's shift and mask, the packed byte's step, the group's origin and width, the
round count, every field's two bits, the source's offset, the record's two
bytes, the destination's three words, both stack pushes, the stack pointer's
round trip, the T bit, the return address and every register the guest leaves.

One mutation was **missed** on the first run and is therefore *not* in the
list: *the dead push writes the wrong word*.  The guest pushes the record on
its stack and pops it again without using it - and the second push, of the two
words it remembers, writes over the very same address.  The corpus' own exit
RAM shows it in all eight specimens: the word at `sp - 4` ends as the second
push's value, never as the record.  The store is therefore **unobservable**,
and the port keeps it only to mirror the guest.  The stack pointer's round trip
around it *is* observable, and that one is in the list.

## The tooling lessons

* **The corpus' record-byte writes leave no trace.**  In all eight specimens the
  record's packed byte is `0` and the source's head halfword is below `0x1000`,
  so the two bytes the guest writes into the record are zero over zero.  The
  oracle leg therefore cannot see them, and the differential's fixture has to
  carry values for them - which it does.
* **A negative pool offset breaks a fixture that does its arithmetic in
  unsigned.**  The pool's offsets are sign-extended halfwords, so the record's
  fields can sit *below* the record; the fixture has to apply the offset in
  signed arithmetic, and its record window has to reach below the record.
* **The oracle's merged RAM shadow holds several windows concatenated.**  The
  record's packed byte is at file offset `0x2FA3` (the second window starts at
  `0x1000` and the byte is at `0x1FA3` inside it), not at the naive offset.
* **The stack pointer's round trip is observable even when the store is not.**
  The guest's dead push leaves no trace in RAM, but a port that skipped the pop
  would end with its stack pointer four bytes lower - and that the corpus does
  see.
