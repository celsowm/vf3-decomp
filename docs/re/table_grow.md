# The table grower (SH-4 0x8C044C7C)

A readable port of the fight engine's table grower, and the evidence for it.

## The function

`0x8C044C7C` adds **N** entries (`r4`) to two arrays that live behind one
header:

* the **first array** holds strided entries. Its pointer moves on by the
  stride, and the new entries get the fill value out of the literal pool;
* the **second array** holds plain entries. Its count becomes N and its
  pointer moves on by N words.

The header sits behind a global, and the global points at a word that holds
the base the slots are measured from. The three slots - the first array's, the
fill value and the second array's - are offsets in the literal pool:

| the pool slot | what it is |
|---|---|
| `0x8C044D16` | the offset of the first array's slot |
| `0x8C044D18` | the value the new entries get |
| `0x8C044D1A` | the offset of the second array's slot |

and the global at `0x8C044D44` holds the header's address.

The answer is 0. The function touches no stack.

The port: `src/fight/table_grow.c`, registered in `src/fight/readable.c` as
`table_grow`.

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine
translation of the ROM: one label per guest PC, one C statement per executed
opcode, and the original opcode word in a comment. That makes them a faithful
disassembly of the function they implement, so a readable port can be written
against them without the ROM.

* `tools/adapter_owner.py 0x0c044c7c` - resolves which module the router
  actually serves for a PC. The PC is carried by **four** modules
  (`seventh_c6_adapter`, `fifth_leaf_adapter`, `motion_adapter` and
  `sweep_adapter`) and the chain serves `seventh_c6_adapter`, the first of
  them in chain order. The four copies agree on this function.
* `tools/adapter_dump.py 0x0c044c7c` - prints the generated function as guest
  disassembly. Its own decoder is crude, so the mnemonics below come from
  `tools/sh4.py`, the repo's authoritative decoder, and the semantics come
  from the translator's emitted C.

The guest code, decoded:

```
0x0c044c7c  d531  mov.l @(196,pc),r5    ; the global: the header's address
0x0c044c7e  4415  cmp/gt r4,#0          ; the count is positive?
0x0c044c80  9049  mov.w @(146,pc),r0    ; the first array's slot
0x0c044c82  6352  mov.l @r5,r3          ; the base
0x0c044c84  6103  mov   r0,r1
0x0c044c86  710c  add   #12,r1
0x0c044c88  6233  mov   r3,r2
0x0c044c8a  312c  add   r2,r1
0x0c044c8c  6112  mov.l @r1,r1          ; the stride
0x0c044c8e  023e  mov.l @(r0,r3),r2     ; the first array's pointer
0x0c044c90  4108  shll2 r1              ; the stride in bytes
0x0c044c92  321c  add   r1,r2
0x0c044c94  0326  mov.l r2,@(r0,r3)     ; the pointer moves on
0x0c044c96  6152  mov.l @r5,r1
0x0c044c98  973e  mov.w @(124,pc),r7    ; the fill value
0x0c044c9a  011e  mov.l @(r0,r1),r1     ; the new pointer
0x0c044c9c  8f05  bf/s  +14             ; the delay slot zeroes r6
0x0c044c9e  e600  mov   #0,r6           ; <- the delay slot
0x0c044ca0  7601  add   #1,r6
0x0c044ca2  2172  mov.l r7,@r1          ; one new entry
0x0c044ca4  3643  cmp/ge r4,r6
0x0c044ca6  8ffb  bf/s  -6              ; the delay slot steps the pointer
0x0c044ca8  7104  add   #4,r1           ; <- the delay slot
0x0c044caa  9036  mov.w @(108,pc),r0    ; the second array's slot
0x0c044cac  6252  mov.l @r5,r2
0x0c044cae  0246  mov.l r4,@(r0,r2)     ; the count goes in
0x0c044cb0  7004  add   #4,r0
0x0c044cb2  6352  mov.l @r5,r3
0x0c044cb4  4408  shll2 r4              ; the count in bytes
0x0c044cb6  023e  mov.l @(r0,r3),r2     ; the second array's pointer
0x0c044cb8  324c  add   r4,r2
0x0c044cba  0326  mov.l r2,@(r0,r3)     ; the pointer moves on
0x0c044cbc  000b  rts
```

Four details of that listing are worth naming, because each one is easy to
lose in a readable port:

* **the delay slot runs before the branch.** The translator merges the slot
  into the branch block, so the counter is zeroed and the pointer stepped
  *before* the branch is resolved. The port writes the entry first and steps
  the pointer after it, which is the other way round - and the *order* of the
  two is what decides where the first entry lands.
* **the two indirections are not the same.** The global holds the header's
  address, and the word at that address holds the base the slots are
  measured from. Reading the base out of the *base* instead of out of the
  header's address is the same value but a different access, and the
  out-of-window counter sees the difference.
* **the loop's guard is the count, signed.** The guest compares the count
  with zero *before* the loop and compares the counter with the count inside
  it, so a negative count skips the loop but still moves the second array's
  pointer backwards.
* **`tst`/`cmp` set the T bit.** The T bit is part of the contract - the
  caller can read it - so the port sets it after the guard and after every
  turn of the loop.

## The evidence

`tests/table_grow_replay.c` runs the readable port and the retained
generated translation of the same function over five scenarios and compares
**the whole register file (SR and its T bit included), the return PC, the
failed PC, the out-of-window counter and every RAM byte**. The port runs
twice: once called directly and once through the readable override, which is
how the native tick reaches it.

```
table_grow: 5 differential cases - PASS
```

The test lays the header out the way the guest expects - the global, the word
it points at, the base with its four fields, and the first array - and seeds
the literal pool with the three offsets the guest reads. The scenarios cover
a count of zero (the loop does not run), one entry, several entries and a
negative count (the loop does not run either, but the second array's count
and pointer still move).

The test has teeth, and the mutations were checked:

* a loop that runs one time too often fails with the differing counter and
  pointer named (`v6` `00000001` != `00000002`);
* the stride read from the wrong offset fails with the differing pointer named
  (`v1` `0c500008` != `0c500000`);
* a guard that lets a count of zero into the loop fails with the differing
  counter, pointer and `SR` named;
* the second array advancing by twice the count fails with the differing
  pointer and `r4` named (`v4` `00000004` != `00000008`).

This is the pattern `tests/state_helpers_replay.c` established: the generated
translation stays in the tree as the reference, and the readable port is proved
against it. The generated translation of this function was itself proved
against the oracle when it was promoted, so the chain readable port ==
generated translation == oracle still holds.

**Caveat.** The oracle corpora live under `extract/`, and that tree is gone
from this checkout (see [artifact_gap](artifact_gap.md)). The oracle replay of
this entry could not be re-run, so the differential above stands on the
generated translation rather than on a fresh oracle run. The generated
translation is the one the oracle proved, so the chain is intact, but a
session that has the corpora back should re-run the replay gate for
`0x8C044C7C` before the port is trusted in the native tick.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* The two indirections: the global holds the header's address, and the word
  at that address holds the base.
* The stride is twelve bytes past the first array's slot, and it is
  multiplied by four.
* The loop writes the fill value at the *new* pointer - the pointer after the
  stride - and steps the pointer by four each turn.
* The loop runs only when the count is positive; the comparison is signed.
* The second array's count is written before its pointer moves on, and the
  pointer moves on by the count in bytes.
* The T bit is set after the guard and after every turn of the loop.

## The unknown

The three offsets in the literal pool and the global's address are not
recoverable offline: they live in the code image, which is under `extract/`.
The port therefore reads the same addresses the guest reads, and what the two
arrays really hold stays open until the image is back.
