# The fight queue family (SH-4 0x8C038570, 0x8C038590, 0x8C0385C0)

A readable port of the fight engine's queue of two parallel words - the reset,
the push and the pop - and the evidence for it.

## The three functions

They sit next to each other in the image and share one struct and two global
arrays:

| entry | guest | body | what it does |
|---|---|---|---|
| `0x8C038570` | `reset` | `0x0C038570..0x0C038588` (24 B) | empties the queue and seeds the struct from the arrays' first slots |
| `0x8C038590` | `push` | `0x0C038590..0x0C0385BA` (42 B) | appends the struct's two words to the arrays; refuses when the queue is full |
| `0x8C0385C0` | `pop` | `0x0C0385C0..0x0C0385E8` (40 B) | takes the arrays' last slots back into the struct; refuses when the queue is empty |

None of them is in the baseline inventory (`extract/analysis/funcs_1ST_READ.unsc.bin.csv`),
so all three are **off-baseline leaves** and their ledger rows are worth their
own body span: 24 + 42 + 40 = **106 bytes** of new coverage, which takes the
verified C address union from 406,454 to **406,560 bytes (93.5360%)**.

They are not cold either.  The oracle's census of the state-7 fight tick
(`extract/analysis/fxr_tick_s7_stats.csv`) has

```
0x0c038570,10,110,50
0x0c038590,4,76,12
0x0c0385c0,4,72,12
```

ten calls and 110 self-steps for the reset, four calls and 76 for the push, four
and 72 for the pop.

The port: `src/fight/queue_ops.c`, registered in `src/fight/readable.c` as
`queue_reset`, `queue_push` and `queue_pop`.

## What the queue is

**The addresses come out of the literal pool**, and the pool entries are read at
run time, the way the guest reads them.  The oracle's captured RAM gives the
game's own values:

```
0x0C0385F0 -> 0x0C16B880   the struct
0x0C0385F4 -> 0x0C1A5720   the first array
0x0C0385F8 -> 0x0C1A57E0   the second array
```

**The struct** at `0x0C16B880` carries the queue's state:

* the **counter** is the halfword at its offset 6 - how many entries the queue
  holds.  It is read *sign extended* and written back as a halfword;
* the **first word** is at offset 44 and its duplicate at 48;
* the **second word** is at offset 56 and its duplicate at 60.

**The arrays** hold 48 words each.  The push writes the struct's first word into
the first array and the second word into the second array, at the counter's
**new** value; the pop reads them back at the counter's **old** value.  So the
queue's slots are 1..48 and slot 0 holds the reset's seed.

**The capacity** is 48: the push's own immediate.

**The reset** zeroes the counter and seeds the struct from the arrays' first
slots - the first array's into the words at 44 and 48, the second array's into
the words at 56 and 60.  The last of those four stores is the delay slot of the
`rts`, so it happens before the function returns.

**The push** refuses when the counter has reached the limit and then answers
-1 without touching anything.  Otherwise the counter goes up by one, the
struct's two words go into the arrays at the counter's new value, and the
answer is 0.

**The pop** refuses when the counter is not above zero and then answers -1.
Otherwise the arrays' slots at the counter's value come back into the struct,
the counter goes down by one, and the answer is 0.

## The details the port has to keep

**`cmp/ge r3,r5` sets T = (r5 >= r3)** - the queue is full once the counter has
*reached* the limit, not once it has passed it.  The corpus settles the
direction on its own: a push out of an empty queue takes the corpus' SR from
`0x60000001` to `0x60000000`, so the comparison clears T on a counter of 0.
The first version of the port had the comparison the other way round
(`48 >= counter`), and the corpus' own SR caught it.

**The two arrays are 48 words apart, so the first array's slot 48 *is* the second
array's slot 0.**  The queue writes slot 48 when the counter goes from 47 to 48,
and that write lands on the second array's first slot.  The fixture models the
two arrays as the one contiguous space they are in the game, so the alias is
exercised rather than hidden.

**A `/s` branch runs its delay slot on both paths.**  The push's refusal
answer (-1) and the pop's are written by the delay slot of the `rts` - into r6
and into r5 respectively - so the port has to leave those two registers as the
guest left them, and has to write the answer even on the path the branch takes.

**The counter is a halfword and it is sign extended.**  The captured fight never
shows a negative counter - in every corpus the counter is 0 and the push takes it
to 1 - so the sign extension is proved by the differential's negative-counter
cases rather than by the oracle.

**The reset computes no comparison at all, so it must not touch the T bit.**
The corpus' reset rows never change SR.

**The pop writes the struct's words at 44 and 56 only** - the copies at 48 and
60 keep the values they had.  So the fixture gives the struct's four words
distinct values: a port that reads the duplicate where the guest reads the
original, or that writes the duplicate as well, is caught.

**The dispatcher refuses to run anything when the FPU is unsupported**
(`FPSCR.RM` is 2 or 3, or the precision bit is set), and the gate stands
between the caller and the body.  A synthetic fixture therefore has to carry a
real FPSCR - the corpus' `0x240001` - or the chain returns before it reaches
the function and the case looks like a port failure.

## The evidence

**The differential** (`tests/queue_ops_replay.c`, 13 cases) compares three arms
on the whole register file, the return PC, the failed PC, the out-of-window
counter and every RAM byte: the generated chain (the reference), the readable
port called directly, and the readable port reached through the readable
override (which is how the native tick reaches it).  It also checks the outcome
**against the fixture itself** - the answer in r0, the T bit the guest leaves,
the counter, the struct's four words and the arrays' written slots - against a
second implementation written from the disassembly, so a fixture that is not
where the guest looks cannot make both sides agree on the same wrong bytes.

**The oracle**:

* the reset: `extract/analysis/fight_all_cases/f_8c038570.cases` (448) and
  `extract/analysis/fight_release_cases/f_8c038570.cases` (576) - 1,024 cases;
* the push: `extract/analysis/fight_all_cases/f_8c038590.cases` (396) and
  `extract/analysis/fight_release_cases/f_8c038590.cases` (484) - 880 cases;
* the pop has **no corpus of its own** - nothing in the captured fight reaches
  `0x8C0385C0` as a watched entry.  Its evidence is indirect: the readable pop
  was substituted into the two corpora whose call tree *does* contain it,
  `extract/analysis/next_device_dev_cases/f_8c06d46c.cases` (65 cases, the
  readable port served 55 times) and
  `extract/analysis/u90_sw2/u90_sw2_8c0b1ed4/f_8c0b1ed4.cases` (16 cases, 64
  times).  The recorded exit state of the whole specimen - the counter, the
  struct and the arrays - is then the oracle's own record of what the pop did.
  The test counts the calls, so a corpus that never reaches the pop cannot pass
  vacuously.

Both pop corpora touch a device register, so their specimens need the device
tape and the banked registers.  That machinery now lives in
`tests/oracle_sidecars.h`, shared with `tests/matrix_family_replay.c` (the
generated chain's own harness), so the chain and the readable ports are proved
by the same loader.  The chain's results are unchanged by the extraction: the
two corpora still replay 65/65 and 16/16, and six other corpora still replay
identically.

**The mutations** (`tests/queue_ops_mutations.json`, 51 of them) are all caught
by `tools/mutate.py`: every pool address, every field offset, the capacity, the
halfword's sign extension, both comparisons, the counter's increment and
decrement, the width of the counter's store, every array write and every index
arithmetic, both refusals, both answers, the T bit, and the return address of
each of the three.

One of them was missed on the first run: *the counter is not stored as a
halfword*.  The fixture's struct neighbourhood was zeroed, so a word-wide store
of a small counter wrote the same bytes.  The fixture now fills the struct's
window with garbage first, and the store width is visible.

## The tooling lessons

* **The oracle's merged RAM shadow holds several windows concatenated.**  The
  struct's counter is at file offset `0x1886` (the second window starts at
  `0x1000`), not at `0x886`; reading it at the naive offset gave a plausible
  but wrong value and made a RAM diff look empty.
* **`VF3_READABLE_ONLY=<entry>`** (added to `tests/matrix_family_replay.c`) lets
  one readable port be proved inside a corpus whose call tree reaches it.  The
  whole table pre-empts too much for a specimen whose other legs are not
  ported yet: with the whole table installed the two pop corpora fail at
  `0x8C0558A0`, far away from the queue.
* A corpus whose specimen touches a device register needs its `.dev.bin` tape;
  without it the specimen reads the device as zero and wanders off into 80
  out-of-window accesses.
