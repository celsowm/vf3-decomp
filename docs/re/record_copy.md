# The record repack (SH-4 0x8C043A7C)

A readable port of the fight engine's record repack, and the evidence for it.

## The function

`0x8C043A7C` copies twenty-four records out of a table and into a destination
array, and the two records do not have the same shape: the source's fields are
spread out, the destination's are packed.

* the **table** and the **destination** are two words in the literal pool, at
  `0x8C043B78` and `0x8C043B74`. The table is read through *two* indirections:
  the pool gives the table, and the table's first cell gives the source's base;
* the first record is **forty bytes into** that base (`+0x28`), and the
  records are **forty-four bytes apart**;
* the destination's records are **twenty-four bytes apart**;
* **twenty-four** records are copied, and the destination's **last eight bytes
  of every record are left alone**.

Per record:

| source       | destination |
| ------------ | ----------- |
| byte  0.. 3  | byte  0.. 3 |
| byte  8..11  | byte  4.. 7 |
| word 16..19  | word  8..11 |
| word 20..23  | word 12..15 |

The port: `src/fight/record_copy.c`, registered in `src/fight/readable.c` as
`record_copy`.

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine translation
of the ROM: one label per guest PC, one C statement per executed opcode, and
the original opcode word in a comment. That makes them a faithful disassembly
of the function they implement, so a readable port can be written against them
without the ROM.

* `tools/adapter_owner.py 0x0c043a7c --body` - resolves which module the router
  actually serves for a PC. One module carries the copy (`eighth_adapter`); two
  others carry the same guest code (`next_adapter`, `sweep_adapter`), so the
  port has to match the one the chain serves.
* `tools/handwritten_entries.py 0x0c043a7c` - confirms that no hand-written
  module already serves this entry, so the port is not shadowed.
* The listing below is decoded with `tools/sh4.py`, the repo's authoritative
  decoder, from the opcode words the module carries; the semantics come from
  the translator's emitted C.

The guest code, decoded:

```
0x0c043a7c  d33e  mov.l @(248,pc),r3      ; the table
0x0c043a7e  e600  mov   #0,r6
0x0c043a80  d53c  mov.l @(240,pc),r5      ; the destination
0x0c043a82  e718  mov   #24,r7             ; twenty-four records
0x0c043a84  6432  mov.l @r3,r4             ; the table's cell: the source's base
0x0c043a86  7428  add   #40,r4             ; and the first record is +0x28 into it
0x0c043a88  6240  mov.b @r4,r2             ; the loop, and the first byte
0x0c043a8a  7601  add   #1,r6
0x0c043a8c  3673  cmp/ge r7,r6            ; T says whether the last record is done
0x0c043a8e  2520  mov.b r2,@r5
0x0c043a90  8441  mov.b @(1,r4),r0
0x0c043a92  8051  mov.b r0,@(1,r5)
0x0c043a94  8442  mov.b @(2,r4),r0
0x0c043a96  8052  mov.b r0,@(2,r5)
0x0c043a98  8443  mov.b @(3,r4),r0
0x0c043a9a  8053  mov.b r0,@(3,r5)
0x0c043a9c  5344  mov.l @(16,r4),r3        ; the record's first word
0x0c043a9e  1532  mov.l r3,@(8,r5)
0x0c043aa0  8448  mov.b @(8,r4),r0
0x0c043aa2  8054  mov.b r0,@(4,r5)
0x0c043aa4  8449  mov.b @(9,r4),r0
0x0c043aa6  8055  mov.b r0,@(5,r5)
0x0c043aa8  844a  mov.b @(10,r4),r0
0x0c043aaa  8056  mov.b r0,@(6,r5)
0x0c043aac  844b  mov.b @(11,r4),r0
0x0c043aae  8057  mov.b r0,@(7,r5)
0x0c043ab0  5345  mov.l @(20,r4),r3        ; and the record's second word
0x0c043ab2  1533  mov.l r3,@(12,r5)
0x0c043ab4  7518  add   #24,r5             ; the destination moves on
0x0c043ab6  8fe7  bf/s  0x0c043a88         ; and the branch's delay slot
0x0c043ab8  742c  add   #44,r4             ; moves the source on
0x0c043aba  000b  rts
```

Four details of that listing are worth naming, because each one is easy to lose
in a readable port:

* **the loop's exit test is the T bit of a compare, not a compare of its own.**
  `cmp/ge r7,r6` sets T, and the `bf/s` at the bottom reads it. The counter is
  bumped at the *top* of the body and the branch sits at the *bottom*, so the
  T bit the caller sees is the last iteration's.
* **the branch's delay slot is the source's advance.** `add #44,r4` runs before
  the branch is resolved, so the source moves on on the last iteration too, and
  the final `r4` is one stride past the last record.
* **the bytes are moved one at a time, and each one is sign-extended** into
  the register it travels through (`mov.b @r4,r2`). The byte that is written
  is the low byte of that register, so the sign extension shows in the register
  file and not in the destination.
* **the two words travel through `r3`**, which is also the register that holds
  the table. The last word read is the one left there.

## The evidence

`tests/record_copy_replay.c` runs the readable port and the retained generated
translation of the same function over four scenarios and compares **the whole
register file (the FP registers and SR included), the return PC, the failed PC,
the out-of-window counter and every RAM byte**. The port runs twice: once
called directly and once through the readable override, which is how the native
tick reaches it.

```
record_copy: 4 differential cases - PASS
```

The test lays the literal pool, the table, the source records and the
destination out the way the guest expects. The scenarios cover a plain table, a
destination that already holds something, a table whose every byte is high (so
the sign extension is observable) and a table whose bytes wrap past `0xFF`.

### The fixture was wrong, and the differential did not see it

The first version of this test laid the source's records at the *base* of the
source window, one stride too low. The guest reads the first record at
`base + 0x28`, so both sides read the zero gap between the records and
repacked zeros into the destination - and the test passed.

The out-of-window counter did not catch it either: the address the guest read
was still *inside* a captured window, just not the part of it the fixture had
filled. That is the third variant of the trap `AGENTS.md` warns about, and the
one the earlier two guards do not cover:

* the counter's fixture pointed the global straight at the block instead of at
  a header whose first word is the block - the read fell *outside* every
  window, and the out-of-window counter caught it;
* the word decoder's fixture laid the table's base out as a stride instead of
  a signed halfword - the read fell outside the window too;
* **this one fell inside the window**, so the counter stayed at zero and the
  differential agreed on nothing.

The fix is not another counter: the test now checks the repack **against the
fixture itself**, record by record, without consulting the generated
translation. The destination's bytes have to be the source's bytes where the
guest puts them, and the destination's untouched eight bytes have to still hold
the fill. A fixture that is not where the guest looks now fails the test
instead of passing it.

### The test has teeth, and the mutations were checked

Nineteen mutations of the port were applied one at a time; each one has to make
the test fail. All nineteen do:

* the record count moved to twenty-three fails with the differing `r0` named
  (`v0 00000032` != `00000031`) - the last byte read is one record short;
* the count moved to twenty-five fails outright (`ok 1/0/0`), because the
  twenty-fifth record is outside the source window;
* the source's stride moved fails outright;
* the destination's stride moved fails outright;
* the source's offset moved fails with the differing `r0` named
  (`v0 00000032` != `0000002a`);
* the loop's compare turned exclusive fails with the differing `SR` named
  (`v17 00000301` != `00000300`);
* the byte's sign extension dropped fails with the differing `r2` named
  (`v2 ffffffb0` != `000000b0`) - this is the scenario with the high bytes;
* the bytes eight to eleven read from twelve fails with the differing
  destination byte named (`ram 1156 18` != `00`);
* the word at sixteen read from twelve fails with the differing destination word
  named (`ram 1160 11` != `00`);
* the word at twenty read from sixteen fails with the differing `r3` named
  (`v3 33333330` != `99999998`);
* the two pool words swapped fails outright;
* the table's cell read without the indirection fails outright;
* the loop's exit compare turned exclusive fails outright;
* the destination's word at eight written to twelve fails with the differing
  destination word named (`ram 1160 11` != `00`);
* the last word read into a scratch register instead of `r3` fails with the
  differing `r3` named (`v3 33333330` != `99999998`) - the RAM is the same, so
  only the register half of the differential sees it;
* the counter started at one fails with the differing `r0` named
  (`v0 00000032` != `00000031`);
* the limit raised by one fails outright;
* the destination's word written as four bytes fails with the differing
  destination byte named (`ram 1165 22` != `00`);
* the third source byte read from the second fails with the differing
  destination byte named (`ram 1155 13` != `12`).

The last two of these - the sign extension and the third byte - were **missed**
before the fixture was fixed, and that is what gave the bug away: a mutation
that the test cannot see is a path the test never reaches.

This is the pattern `tests/state_helpers_replay.c` established: the generated
translation stays in the tree as the reference, and the readable port is proved
against it. The generated translation of this function was itself proved against
the oracle when it was promoted, so the chain readable port == generated
translation == oracle still holds.

**Caveat.** The oracle corpora live under `extract/`, and that tree is gone
from this checkout (see [artifact_gap](artifact_gap.md)). The oracle replay of
this entry could not be re-run, so the differential above stands on the
generated translation rather than on a fresh oracle run. The generated
translation is the one the oracle proved, so the chain is intact, but a
session that has the corpora back should re-run the replay gate for
`0x8C043A7C` before the port is trusted in the native tick.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* The table is read through two indirections: the pool gives the table, the
  table's first cell gives the source's base, and the first record is `+0x28`
  into that.
* The source's records are forty-four bytes apart and the destination's
  twenty-four.
* Twenty-four records are copied, and the counter is compared **after** it is
  bumped, so the T bit the caller sees is the last iteration's.
* The bytes are sign-extended into the register they travel through, and the
  word at sixteen and the word at twenty travel through `r3`.

## The unknown

What the twenty-four records *are* is not recoverable offline: the table and
the destination live in the game's own memory, and the image is under
`extract/`. The port therefore reads the same addresses the guest reads, and
what the records mean - and who calls this - stays open until the image is
back.
