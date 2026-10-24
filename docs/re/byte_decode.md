# The word decoder (SH-4 0x8C04538A)

A readable port of the fight engine's word decoder, and the evidence for it.

## The function

`0x8C04538A` reads a 32-bit word off the caller's stack and turns it into a
value. The engine calls it with a word on the caller's stack; the function pops
that word, pushes it on its own stack, and copies its four bytes into the
object at `+8..+11` - in the natural order, or turned around, depending on
what a table says.

The object's first byte (`+8`) then decides the answer, which the function
writes at the object's `+20`:

| the byte at `+8` | the answer at `+20` |
| --- | --- |
| equals the **mark** | `-1` (there is no value) |
| at or above the **limit** | the *next* word on the caller's stack |
| otherwise | zero |

* the **mark** and the **limit** are halfwords in the literal pool, at
  `0x8C045448` and `0x8C04544C`;
* the **table** is at `0x8C045454`: it points at a cell that holds the table's
  first word, and the pool's base at `0x8C04544A` (a *signed* halfword) is
  added to it. The entry behind that address says whether the bytes are turned
  around - the entry is `1` when they are.

The port: `src/fight/byte_decode.c`, registered in `src/fight/readable.c` as
`byte_decode`.

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine
translation of the ROM: one label per guest PC, one C statement per executed
opcode, and the original opcode word in a comment. That makes them a faithful
disassembly of the function they implement, so a readable port can be written
against them without the ROM.

* `tools/adapter_owner.py 0x0c04538a --all --body` - resolves which module the
  router actually serves for a PC. Three modules carry the copy
  (`eighth_adapter`, `motion_adapter`, `sweep_adapter`) and they agree; the
  chain serves `eighth_adapter`.
* `tools/adapter_dump.py 0x0c04538a` - prints the generated function as guest
  disassembly. Its own decoder is crude, so the mnemonics below come from
  `tools/sh4.py`, the repo's authoritative decoder, and the semantics come
  from the translator's emitted C.

The guest code, decoded:

```
0x0c04538a  6356  mov.l @r5+,r3         ; the caller's word
0x0c04538c  7ffc  add   #-4,r15
0x0c04538e  2f32  mov.l r3,@r15         ; ... pushed on our own stack
0x0c045390  d230  mov.l @(192,pc),r2    ; the table
0x0c045392  915a  mov.w @(180,pc),r1    ; the table's base
0x0c045394  6022  mov.l @r2,r0          ; the cell's word
0x0c045396  001e  mov.l @(r0,r1),r0     ; the entry
0x0c045398  8801  cmp/eq #1,r0          ; turned around?
0x0c04539a  8b09  bf    0x0c0453b0      ; no: the natural order
0x0c04539c  66f3  mov   r15,r6
0x0c04539e  6064  mov.b @r6+,r0
0x0c0453a0  804b  mov.b r0,@(11,r4)
0x0c0453a2  6064  mov.b @r6+,r0
0x0c0453a4  804a  mov.b r0,@(10,r4)
0x0c0453a6  6064  mov.b @r6+,r0
0x0c0453a8  8049  mov.b r0,@(9,r4)
0x0c0453aa  6060  mov.b @r6,r0
0x0c0453ac  a009  bra   0x0c0453c2      ; the delay slot writes @(8,r4)
0x0c0453c2  8448  mov.b @(8,r4),r0
0x0c0453c4  9340  mov.w @(128,pc),r3    ; the mark
0x0c0453c6  600c  extu.b r0,r0
0x0c0453c8  3030  cmp/eq r3,r0
0x0c0453ca  8b02  bf    0x0c0453d2      ; not the mark: the limit
0x0c0453cc  e1ff  mov   #-1,r1
0x0c0453ce  a008  bra   0x0c0453e2      ; the delay slot writes it
0x0c0453d2  923b  mov.w @(118,pc),r2    ; the limit
0x0c0453d4  3023  cmp/ge r2,r0
0x0c0453d6  8902  bt    0x0c0453de      ; at or above: the caller's word
0x0c0453d8  e000  mov   #0,r0
0x0c0453da  a002  bra   0x0c0453e2      ; the delay slot writes it
0x0c0453de  6152  mov.l @r5,r1          ; the caller's next word
0x0c0453e0  1415  mov.l r1,@(20,r4)
0x0c0453e2  e000  mov   #0,r0
0x0c0453e4  000b  rts
```

and the arm the branch skips, the natural order:

```
0x0c0453b0  66f3  mov   r15,r6
0x0c0453b2  6064  mov.b @r6+,r0
0x0c0453b4  8048  mov.b r0,@(8,r4)
0x0c0453b6  6064  mov.b @r6+,r0
0x0c0453b8  8049  mov.b r0,@(9,r4)
0x0c0453ba  6064  mov.b @r6+,r0
0x0c0453bc  804a  mov.b r0,@(10,r4)
0x0c0453be  6060  mov.b @r6,r0
0x0c0453c0  804b  mov.b r0,@(11,r4)
```

Five details of that listing are worth naming, because each one is easy to lose
in a readable port:

* **the word is read back from the stack, not from a register.** The function
  pops the caller's word into `r3`, pushes it on its own stack, and then
  copies the bytes *out of the stack*. A port that copies out of `r3` gets the
  same bytes for the value - but the stack write is part of the contract, and
  the harness compares the RAM.
* **the table's base is a signed halfword added to a 32-bit word.** The entry
  sits at `base + cell`, where the cell holds an absolute address. A port that
  treats the base as a stride, or forgets the sign, reads a different address
  - and the difference shows up as an out-of-window read, not as a wrong value.
* **the two byte orders are mirror images.** The turned-around arm writes the
  first byte to `+11` and the last to `+8`; the natural arm writes the first
  to `+8` and the last to `+11`. Both arms leave the *last* byte's read
  without the pointer increment, so `r6` ends one byte short of the fourth.
* **the answer's three arms each end in a branch with a delay slot**, and the
  delay slot is the store: the `-1` store, the zero store and the caller's-word
  store all happen in the slot. The translator merges the slot into the branch
  block, so the port has to do the store itself in each arm.
* **the T flag is written three times**, and only the last one is visible: the
  byte-order test, the mark test and the limit test all set it, and the
  mark's `cmp/eq` overwrites the byte-order's. The byte order's T bit is
  therefore *unobservable* - a port may set it or not. The mark's and the
  limit's are not.

## The evidence

`tests/byte_decode_replay.c` runs the readable port and the retained
generated translation of the same function over ten scenarios and compares
**the whole register file (the FP registers and SR included), the return PC,
the failed PC, the out-of-window counter and every RAM byte**. The port runs
twice: once called directly and once through the readable override, which is
how the native tick reaches it.

```
byte_decode: 10 differential cases - PASS
```

The test lays the caller's stack, the literal pool, the table's cell, the
table and the object out the way the guest expects. The scenarios cover the
two byte orders, the mark in each of them, the limit, one below the limit, a
limit of 255, a limit that is negative (so every byte is at or above it) and
a table entry that is neither 1 nor 0.

The test has teeth, and the mutations were checked:

* the two byte orders swapped fails with the differing object byte named
  (`ram 377 30 != 22`);
* the mark's T flag flipped fails with the differing `SR` named (`v17 00000301`
  != `00000300`);
* the limit comparison turned exclusive fails with the differing `r1` and `SR`
  named (`v1 cafebabe` != `00000010`);
* the mark's answer changed fails with the differing `r1` named (`v1 ffffffff`
  != `00000000`);
* the answer's slot moved fails with the differing object word named (`ram 388
  be != 00`);
* the caller's word read one word too far fails with the differing `r1` named
  (`v1 cafebabe` != `00000000`);
* the table's base read from the wrong pool slot fails with the out-of-window
  counter named (`ok 1/0/0`);
* the frame grown by two words fails with the differing `r6` and `sp` named
  (`v15 0c110040` != `0c11003c`);
* the answer register left at one fails with the differing `r0` named (`v0
  00000000` != `00000001`).

One mutation is *not* caught, and correctly so: flipping the T bit of the
byte-order test changes nothing, because the mark's `cmp/eq` overwrites it
before the function returns. The bit is unobservable, so the port's choice
there is free.

**The test also guards the out-of-window counter on its own.** A case that
reads outside the windows passes the differential anyway - both sides read the
same uncaptured address, so the counters match - and the first version of this
fixture did exactly that: the table's base was laid out as a stride instead of
a signed halfword, the entry was read from the wrong address, and the test
was green while the table lookup was never exercised. Both this test and
`tests/counter_advance_replay.c` now fail on a non-zero counter.

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
`0x8C04538A` before the port is trusted in the native tick.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* The caller's word is popped from `r5` and pushed on the function's own stack,
  and the bytes are copied out of that stack.
* The entry that asks for the turned-around order is the word `1`; anything
  else takes the natural order.
* The bytes land at `+8..+11` of the object, in one order or the other.
* The mark is compared as a byte (`extu.b`), the limit as a signed halfword,
  and the comparison against it is a *signed* one.
* The answer goes to the object's `+20`, and the function leaves `r0` at zero.
* The stack is balanced: the frame grows by one word and the `rts` gives it
  back.

## The unknown

The mark, the limit, the table's base and the table itself are not recoverable
offline: they live in the code image, which is under `extract/`. The port
therefore reads the same addresses the guest reads, and what the byte actually
classifies - and what the table's entries mean - stays open until the image is
back.
