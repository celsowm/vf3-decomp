# The fight-state resolver (SH-4 0x8C08E68C)

A readable port of the fight engine's record resolver, and the evidence for it.

## The function

`0x8C08E68C` resolves **the two fighters' records into one output struct**.  It is
237 instructions, its body is `0x0C08E68C..0x0C08E8FE` (626 bytes), and it is
called with `r4` = the output struct.

It is **off-baseline**: the inventory's `f_8c08e6a8` starts 28 bytes *after* this
entry, so the resolver is a gap leaf.  That is also why the ledger row is worth
only 82 bytes of new coverage - see *What the ledger row adds* below.

It is not cold either.  The oracle's own census of the state-7 fight tick
(`extract/analysis/fxr_tick_s7_stats.csv`) has

```
0x0c08e68c,1,171,41
```

one call and 171 self-steps, and its helper `0x0C09553C` has three calls and 99
self-steps of its own.

The port: `src/fight/state_resolve.c`, registered in `src/fight/readable.c` as
`state_resolve`.

## What it does

**The two records.**  The output struct's flag word (its word at 48) picks the
row.  The bit `0x40` picks the second table's row at 452, the bits `0x80` and
`0x100` pick the row at 456, and with none of them set the first table's entry
at 16 is used.  The second record follows the first: the row that was picked
becomes the first table's entry at 20 when the row *is* that entry, and the entry
at 16 otherwise.  With no flag set the pair is the entry at 16 and the entry at
20.

**The words the records share with the output struct.**  The word at 6340 (the
first record's goes to the output's word 52, the second record's to the output's
word 56), the words at `0x48` and `0x4c`, the word at 6660 and the halfword at
`0x3e` - the last two as halfwords, into the output's words 84, 88, 80 and 90.

**The vectors.**  Each vector comes from one of three places in its record: the
record's own words at `0x10`, the words at the pool's offset 1072, or the words
at the pool's offset 496.  The third component is always negated.

**The correction.**  A helper - the address is in the pool - may add a
correction to a vector.  It is called only when the record's count carries the
bit 8192 *and* the "both" word (the two counts that are neither equal nor
different) says so, and it is handed the record's word at 5268, negated.

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine translation
of the ROM: one label per guest PC, one C statement per executed opcode, and
the original opcode word in a comment.  That makes them a faithful disassembly
of the function they implement, so a readable port can be written against them
without the ROM.

* `tools/adapter_owner.py 0x8c08e68c --body` - the body is served by
  `fight_adapter` (`src/fight/fight_adapters_1.c`).
* `build/fn.py src/fight/fight_adapters_1.c 0x0c08e68c 0x0c08e8fa` - the
  translation, one line per guest PC.

**The literal pool is read at run time**, the way the guest reads it.  The table
addresses, the masks, the offsets into the records, the helper's address and the
float are the image's, and the port does not bake them in - it reads
`0x0C08E756..0x0C08E90C` from RAM.  (The float the image holds at `0x0C08E854`
is `0x3ECCCCCC` - the float just below the canonical `0.4f` - and the port uses
whatever the pool says.)  A replay therefore has to supply the pool as a
window; the oracle's capture does exactly that, and the differential test
supplies it itself with the image's values.

## The evidence

### The differential

`tests/state_resolve_replay.c` runs the readable port and the retained generated
translation of the same function over twenty scenarios and compares **the whole
register file (the FP registers and SR included), the return PC, the failed PC,
the out-of-window counter and every RAM byte**.  The port runs three ways: called
directly, through the readable override (which is how the native tick reaches
it), and as the reference - the generated chain - which is left in the tree as
the oracle of the translation.

```
state_resolve: 20 differential cases - PASS
```

The scenarios walk the tree: the three flag bits that pick a row (and the one
that wins over another), the flag bit that picks no row, the output struct's
flag bit 0, the "both" word's bit 2, the high mask and the low mask on either
record, the correction being wanted or not on either record, the `0.4`'s
negation, and the two records asking for a correction at once.

The test also checks the outcome **against the fixture itself**: the output
struct's bytes, the record the guest picked, the saved registers, the stack
pointer and the return address all have to be what the scenario says.  The
expected values come from a second implementation in the test, written from the
disassembly and not from the port.  A differential alone is not enough, because
a fixture that is not where the guest looks makes both sides read the same wrong
bytes and agree on them.

The helper's two leaves (`0x0C03A6E0` and `0x0C03A140`) are answered by a
**stub** in all three arms: the first leaf returns its argument as a float, so
the correction is a function of the argument the *port* passes, and a stub in
one arm only would compare two different things.

### The mutations were checked

The mutations are checked with `tools/mutate.py`, which applies one at a time
to the port's source, rebuilds and requires the test to fail.  The list lives
in `tests/state_resolve_mutations.json`, next to the test it guards.

The list holds 66 mutations and **every one of them is caught**.  They fall into
three groups: the **pool addresses** (every constant the guest reads out of the
literal pool - the two flag masks, the two rows, the offsets 6340, 6660, 1072,
496, 6672, 5268 and 196, the bit 8192, the float and the helper's
address), the **decisions** (which flag picks which row, which record follows,
which source a vector comes from, the sign of the float, the negation of the
third component, whether the correction is wanted, which frame word it goes to
and which vector component it joins), and the **frame and the epilogue** (the
frame's size, the continuation address, the pop sequence and the return).

Two of them are worth naming, because they are the ones a reading of the listing
would get wrong.  The `0.4` is negated **only when the record's count carries the
high mask** - negating it always, or never, is a different function.  And the
helper's "both" word is read into **r3** on the first call and into **r2** on
the second; the port has to reproduce that traffic, because the guest leaves the
registers behind.

One thing about this function **cannot** be observed, and the port says so rather
than pretending otherwise:

* **the width of the first halfword store.**  The guest writes the halfword at
  the output's word 84 and the halfword at 86; a *word* store at 84 would spill
  into 86 and 87, which the next store overwrites anyway.  The final RAM is the
  same, so the width of that store cannot be observed at all.  The mutation list
  therefore breaks the **last** halfword store (the one at 90), whose spill into
  92 and 93 nothing overwrites - and the fixture fills that gap, which the guest
  never writes, so the spill shows up in the comparison.

### The oracle leg

The resolver has **two** real oracle captures, and both replay clean:

| corpus | specimens | windows |
|---|---|---|
| `extract/analysis/fight_all_cases/f_8c08e68c.cases` | 192 | `0x0C08E000..0x0C08F000` is the **literal pool**, the ROM the entry reads, and `0x0C1FF000`, `0x0C21B000`, `0x0C29B000`, `0x0C31F000` are RAM |
| `extract/analysis/fight_release_cases/f_8c08e68c.cases` | 256 | the same, plus the helper's own pool and its two leaves in the rows that call it |

The XF registers, the FPUL, the exit PC and the GBR come in sidecars next to the
corpora.  So these legs read the *image's* constants out of the capture, exactly
as the guest does.

`tests/state_resolve_oracle.c` replays them:

```
state_resolve_oracle: 192/192 cases match (0 skipped) - PASS
state_resolve_oracle: 256/256 cases match (0 skipped) - PASS
```

The comparison covers the whole register file, the XF registers, the FPUL, the
GBR, the exit PC and every byte of RAM.

**The trap in this leg is worth recording.**  The obvious way to run the corpus -
`build/vf3matrixfamily.exe 0x8c08e68c <corpus>` with `VF3_READABLE=1` - gives
**175/192**, and the 17 failures are exactly the rows in which the helper is
called.  The reason is that the readable table *shadows the helper's leaves*: the
tree's readable `sin_u16` and `cos_u16` sit at `0x0C03A6E0` and `0x0C03A140`,
the two addresses the helper calls, and those readable ports leave a different
`r4` behind than the code the oracle ran.  The oracle leg therefore installs a
hook that serves **only** the entry under test and leaves the helper and its
leaves on the generated chain, exactly as they were when the oracle captured
them.

That is a property of the *tree*, not of this port: any readable port of the
helper's leaves would need the same treatment.  It is the reason
`tests/state_resolve_oracle.c` does not simply call `vf3_readable_override`.

### What the ledger row adds

The row's `size` is the function's own body span, 626 bytes - but coverage is a
**union of body ranges**, and the inventory's `f_8c08e6a8` (already ported, 544
bytes in three ranges) already covers most of it.  What the new row adds is the
bytes no ported baseline body covers:

| range | bytes | why it was uncovered |
|---|---|---|
| `0x8C08E68C..0x8C08E6A8` | 28 | the gap leaf itself - the entry is below `f_8c08e6a8` |
| `0x8C08E756..0x8C08E774` | 30 | a gap in `f_8c08e6a8`'s first body range |
| `0x8C08E848..0x8C08E860` | 24 | a gap in `f_8c08e6a8`'s second body range |

82 bytes: `406,364 -> 406,446` (93.4909% -> 93.5098%).  The 94% bar at 408,576
bytes is 2,130 bytes away.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* The **T bit** is the guest's branch condition, and a plain `bf` branches when
  it is *clear*.  The T bit is also part of the contract - the guest leaves it
  behind, and the port has to leave the same value behind, so the order of the
  tests matters as much as their result.
* A **`/s` branch runs its delay slot on both paths**, so the word the delay
  slot spills into the guest's scratch frame is written whether the branch is
  taken or not.
* The **correction's `0.4` is negated only sometimes** - when the record's count
  carries the mask `0x08000000`.
* The **helper's frame words** are the guest's: the argument goes to the frame's
  word 32 on the first call and to its word 8 on the second, and the third float
  to the word 24 and the word 20.
* The **register traffic** is the guest's too: the first vector puts the bit-2
  mask into r3, the record's flags into r2 and the low mask into r3 again; the
  second one puts the bit-2 mask into r1, the record's flags into r3 and the low
  mask into r2.
* The **return** pops the saved registers - r14 in the delay slot of the `rts` -
  so the caller sees its own r8..r14 back, and the guest leaves its return
  address in pr.
* The **vectors** go through the same `vf3_matrix_load`/`vf3_matrix_store`
  helpers the translation uses, so the precision bit of the FPSCR decides the
  width on both sides.

## The unknown

What the two records *are*, what the words the guest copies mean to the fight
engine, and why a vector's third component is negated are not recoverable
offline: the code lives in the game's own image, which is not in this checkout
(see [artifact_gap](artifact_gap.md)).  The port therefore reads the same
addresses the guest reads - the literal pool at run time, the records and the
output struct through their pointers - and what the resolver *decides* stays
open until the image is back.
