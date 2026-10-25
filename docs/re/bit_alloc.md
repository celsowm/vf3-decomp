# The fight engine's first free bit (SH-4 0x8C038860)

A readable port of the fight engine's bit allocator, and the evidence for it.

## The function

| entry | body | what it does |
|---|---|---|
| `0x8C038860` | `0x0C038860..0x0C0388DE` (126 B) | takes the first free bit of a table of 32-bit words and answers with its number |

It is an **off-baseline leaf** - it is not in the baseline inventory
(`extract/analysis/funcs_1ST_READ.unsc.bin.csv`), which jumps straight from
`0x8C038810` to `0x8C038956` - and its ledger row carried a size of 0, so its
body span is worth its own credit: **126 bytes** of new coverage.

The function is a **self-contained leaf**: it calls nobody and it uses no FP
instruction, so the port needs no stub and no FP context.

The port: `src/fight/bit_alloc.c`, registered in `src/fight/readable.c` as
`bit_alloc`.

## What the function does

**The table.**  A list of 32-bit words.  The literal pool holds two pointers:

* the **count** of the words - the loop stops when the index reaches it.  The
  pool entry is the *address* of the count, so the count is read **through**
  the pointer, not out of the pool itself;
* the **table** - a pointer to an array whose *first entry* points at the words.
  The guest only ever uses that first entry: the word at index *i* lives at
  `*(table + i * 4)`.

**The end marker.**  A word of `0xFFFFFFFF` is not a free bit but an
**exhausted slot**: the guest moves on to the next word, and the answer's base
moves up by a whole word (32 bits) with it.

**The free bit.**  The **lowest clear bit** of the word.  The guest walks a
mask from 1 upwards - 1, 2, 4, ... - until the word's bit under the mask is
clear, and then sets that bit in the word.

**The answer.**  The bit's number in the whole table: the word's index times
32, plus the bit's number inside the word.  A table with no free bit at all -
every word exhausted, or the count reached - answers **-1** (`0xFFFFFFFF`) and
writes nothing.

## The literal pool

Every entry is read at run time, the way the guest reads it.  The oracle's
captured RAM gives the game's own values:

```
0x0C0389C8 -> 0x0C0EA38C   where the count lives
0x0C0389CC -> 0x0C19CC2C   the table
```

and behind them:

```
*(0x0C0EA38C) = 33          the count of the words
*(0x0C19CC2C) = 0x0C2E185C  the table's first entry: the words themselves
```

## The details the port has to keep

**The frame is six registers wide.**  The guest pushes r14, r13, r11, r10, r9
and r8 (r12 is the frame pointer and is never saved) and pops them back in the
mirror order.  The pushes happen **before** the registers are overwritten, so
the frame holds the caller's values - and the frame is visible in the corpus'
RAM, because the stack pointer is inside a captured window.

**The word is copied into r1 on *both* paths.**  The copy is the **delay slot**
of the branch that decides whether the slot is exhausted, so it happens whether
the branch is taken or not.  A table whose every slot is exhausted therefore
leaves **r1 holding `0xFFFFFFFF`**, and a port that only copies the word on the
free path leaves the caller's r1 there instead.

**Two byte offsets move together.**  r11 walks the table and r14 walks the
words; both advance by four per exhausted slot, so they always agree - a port
that uses one for the other is indistinguishable *in the answer* but not in the
word it writes.

**The T bit is always set at the exit.**  Both exits - the count reached and
the bit found - leave the T bit set: the count test sets it when the index has
reached the count, and the bit test sets it when the AND is zero.

**The mask's shift sets the T bit, and nobody reads it.**  The guest's shift
(`shll r4`) sets the T bit from the mask's top bit, but the bit scan's own test
overwrites it before anything looks at it.  The port leaves it out, and the
mutation that would flip it is therefore **unobservable** - see below.

## The registers the guest leaves

They differ per path, and the port reproduces them:

| path | r0 | r1 | r2 | r3 | r4 | r5 | r6 |
|---|---|---|---|---|---|---|---|
| the count is reached | -1 | the last word read | the caller's | the count | the caller's | 32 x the slots skipped | the caller's |
| a bit is found | the bit's number | the word | the word with the bit set | the count | the mask | 32 x the word's index | the bit's number |

r7 is zero, r8..r15 are the caller's (the frame comes back), and the T bit is
set.

## The evidence

**The differential** (`tests/bit_alloc_replay.c`, 8 scenarios) compares three
arms on the whole register file, the return PC, the failed PC, the
out-of-window counter and every RAM byte: the generated chain (the reference),
the readable port called directly, and the readable port reached through the
readable override (which is how the native tick reaches it).  It also checks
the outcome **against the fixture itself** - the eight registers, the T bit and
the word the guest writes - against a second implementation written from the
disassembly and reading the fixture's own bytes, so a fixture that is not
where the guest looks cannot make both sides agree on the same wrong bytes.

The fixture uses the game's own addresses but **moves every value the guest
follows**: the pool's two pointers, the count, the table's first entry and the
words themselves sit at scenario-dependent offsets.  The corpus always carries
the game's own numbers (the count 33, the table `0x0C19CC2C` and the words at
`0x0C2E185C`), so a port that hard-coded the capture would still replay the
corpus - and would fail here.

The scenarios cover **every branch of the guest's tree**: the first bit, a bit
in the middle, the word's **top** bit (the mask's last step), an exhausted
first slot, three exhausted slots, **every** slot exhausted, and the count
being zero.

**The oracle** (`tests/bit_alloc_oracle.c`) runs the corpus
`extract/analysis/next_dev_cases/f_8c038860.cases` - **194/194 cases match (0
skipped) - PASS**, the readable port served the entry 194 times.  The
comparison covers every register, the XF registers, the FPUL, the GBR, the
banked registers, the exit PC and every byte of RAM - and the word the guest
writes into the table is one of those bytes.

The corpus walks the **whole bit space**: the answers run from 0 to `0x90`,
every bit number from 0 to 31 appears, and **149 of the 194 specimens skip at
least one exhausted slot**.

**The mutations** (`tests/bit_alloc_mutations.json`, 40 of them) are all caught
by `tools/mutate.py`: both pool entries, the end marker, the word's width, the
frame's size, its push and pop orders and its step, the four registers the
guest zeroes or points at the start, the count's read and its test and its
branch, the exhausted answer, the table's first entry, the copy into r1, the
three advances of an exhausted slot, the mask's start and its shift, the bit
number, the bit test's T bit and the branch's sense, the word's write and its
address, the answer's two halves and the exit PC.

Two mutations are **not** in the list, because the guest's own behaviour makes
them **unobservable**:

* **the T bit of the exhausted-slot test.**  The test's T bit is overwritten by
  the count test at the top of the next loop round - the exhausted path always
  continues - so the bit is gone before the function returns.  The *branch* is
  the observable part, and that mutation is in the list.
* **the copy of the word into r2.**  The bit scan's `mov r2,r1` copies the word
  the guest has just put into r1, and r0 still holds the same word, so `mov
  r2,r0` is the same instruction.  The port keeps r1 because the *other* copy
  - the delay slot's - is observable.

One more is left out for a different reason, and it is worth spelling out:

* **the bit test's polarity.**  Inverting the branch - "the bit is free when
  the AND is *not* zero" - is the obvious mutation to write, and it is the one
  that cannot be used: with the branch inverted, a word with **all its bits
  free** makes the scan walk the mask all the way down to zero, and from then
  on `word & 0` is zero again and again, so the port **never terminates**.
  The gate has no per-mutation timeout, so the mutation does not fail the
  test - it hangs it.  The branch's *sense* is covered instead by a mutation
  that makes the **highest** set bit the free one (the mask's own value, not
  its complement), which terminates and is caught.

* **the out-of-window counter of the return.**  Every fixture the differential
  builds is inside the captured windows, so `ram->oob` is always zero and the
  function's own failure condition cannot be seen.  The oracle leg does see it:
  the corpus' windows are the reference's, and a read outside them is counted
  there.

## The tooling lessons

* **A `.cases` row names the entry blob *before* the window descriptors.**  The
  row is `in*37 out*37 <entry blob> <nwin> <base len>* <exit blob> <nexit>
  <base len>*`, so the *entry* blob is the token right after the 74 register
  values and the *exit* blob is the one after the window pairs.  Reading the
  wrong token does not fail - it reads the **exit** shadow and calls it the
  entry state, and the words then look already-taken.
* **A window offset has to stay inside its window.**  The corpus' table sits
  at `0x0C19CC2C`, which is offset `0x0C2C` from the window's base
  `0x0C19C000` - **not** `0x0CC2C`.  The larger offset puts the address
  `0x1000` past the window's end, and the guest's read of the table's first
  entry falls out of the window: the reference then counts the read as
  out-of-window, answers from the garbage it got, and the differential fails
  with an oob count instead of a register mismatch.
* **The corpus' `ops.json` is the executed path, and it is complete here.**
  For this entry it lists **all 49** of the body's instructions - the
  194 specimens between them reach every block, including the skip path and
  the mask's last step.
* **A corpus with no free bit in it is a hole in the proof.**  All 194
  specimens either find a free bit or skip to one; the **-1** answer (the
  table exhausted, or the count zero) never happens in the corpus, so the
  differential's fixture has to carry it.
* **An off-baseline leaf's body ends at its `rts`'s delay slot.**  The `rts`
  is at `0x0C0388DA` and its delay slot at `0x0C0388DC`, so the body is
  `0x0C038860..0x0C0388DE` - 126 bytes.  The next entry in the module
  (`0x0C03B300`) is far away, and no module carries `0x0C0388DE` at all.
* **A mutation that turns the port into a non-terminating loop hangs the
  gate.**  `tools/mutate.py` runs the port's test with no timeout, so a
  mutation that makes the port spin forever does not fail the test - it stops
  the run, and it leaves the port's source **mutated** (the restore only
  happens when the run ends normally).  The fix is to pick a mutation that
  terminates: "the free bit is the highest one" says the same thing about the
  branch's sense without ever letting the mask reach zero.

