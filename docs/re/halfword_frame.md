# The halfword frame (SH-4 0x8C09D4B0)

A readable port of the fight engine's halfword frame, and the evidence for it.

## The function

`0x8C09D4B0` takes an object (`r4`) that holds three halfwords and an argument
(`r5`), puts the four of them in a frame, and then calls three things with
values derived from that frame:

* the **first handler** - the pointer in the literal pool at `0x8C09D580` -
  gets the object's *first* halfword;
* the **second handler** - the pointer at `0x8C09D584` - gets the *argument*
  plus the object's *second* halfword;
* the **third** - the pointer at `0x8C09D588` - gets the object's *third*
  halfword, and it is a **tail transfer**: the guest pops `pr` and jumps, so
  the third call runs in the caller's frame and returns to the caller's
  caller.

The port: `src/fight/halfword_frame.c`, registered in `src/fight/readable.c` as
`halfword_frame`.

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine
translation of the ROM: one label per guest PC, one C statement per executed
opcode, and the original opcode word in a comment. That makes them a faithful
disassembly of the function they implement, so a readable port can be written
against them without the ROM.

* `tools/adapter_owner.py 0x0c09d4b0` - resolves which module the router
  actually serves for a PC. The answer is `fifth_leaf_adapter` (the file
  `fifth_leaf_adapters_1.c`); `matrix_adapters` carries the same guest code
  and the two copies agree.
* `tools/adapter_dump.py 0x0c09d4b0` - prints the generated function as guest
  disassembly. Its own decoder is crude (it prints `mov.b` for a `mov.w`),
  so the mnemonics below come from `tools/sh4.py`, the repo's authoritative
  decoder, and the semantics come from the translator's emitted C.

The guest code, decoded:

```
0x0c09d4b0  4f22  sts.l   pr,@-r15
0x0c09d4b2  7ff0  add     #-16,r15
0x0c09d4b4  2f51  mov.w   r5,@r15
0x0c09d4b6  6041  mov.w   @r4,r0
0x0c09d4b8  81f4  mov.w   r0,@(8,r15)
0x0c09d4ba  8541  mov.w   @(2,r4),r0
0x0c09d4bc  81f2  mov.w   r0,@(4,r15)
0x0c09d4be  8542  mov.w   @(4,r4),r0
0x0c09d4c0  81f6  mov.w   r0,@(12,r15)
0x0c09d4c2  85f4  mov.w   @(8,r15),r0
0x0c09d4c4  d32e  mov.l   @(184,pc),r3
0x0c09d4c6  6403  mov     r0,r4
0x0c09d4c8  430b  jsr     @r3
0x0c09d4ca  644d  extu.w  r4,r4        <- delay slot
0x0c09d4cc  85f2  mov.w   @(4,r15),r0
0x0c09d4ce  64f1  mov.w   @r15,r4
0x0c09d4d0  d32c  mov.l   @(176,pc),r3
0x0c09d4d2  600d  extu.w  r0,r0
0x0c09d4d4  430b  jsr     @r3
0x0c09d4d6  340c  add     r0,r4        <- delay slot
0x0c09d4d8  85f6  mov.w   @(12,r15),r0
0x0c09d4da  7f10  add     #16,r15
0x0c09d4dc  d32a  mov.l   @(168,pc),r3
0x0c09d4de  6403  mov     r0,r4
0x0c09d4e0  644d  extu.w  r4,r4
0x0c09d4e2  432b  jmp     @r3
0x0c09d4e4  4f26  lds.l   @r15+,pr     <- delay slot
```

Two details of that listing are worth naming, because both are easy to lose:

* **the delay slot runs before the callee starts.** The translator merges the
  slot into the call block - `r[4]=r[4]&65535u;` for the first `jsr`,
  `r[4]+=r[0];` for the second - so the callee already sees the masked value.
  The port has to mask *before* the call, not after it.
* **the `mov.w` sign-extends.** `mov.w @r4,r0` puts a *sign*-extended halfword
  in `r0`; the `extu.w` then zeroes the top half before the value is handed
  over. So a halfword of `0xFFFF` reaches the first handler as `0x0000FFFF`,
  but `r0` still holds `0xFFFFFFFF` at that moment.

## The frame

With the entry's `sp` at `S`:

```
S-4    pr
S-8    the object's third halfword
S-12   the object's first halfword
S-16   the object's second halfword
S-20   the argument
```

The order is not the order the values are read in: the argument goes in first,
then the object's *first* halfword at `S-12`, then the second at `S-16`, then
the third at `S-8`. The port writes them in the same slots, because the RAM the
test compares is the frame.

## The three calls

* **first handler** (`pool 0x8C09D580`): `r0` is the object's first halfword
  (sign-extended), `r4` is the same value, and the delay slot's `extu.w` makes
  `r4` the zero-extended halfword. The continuation is `0x8C09D4CC`.
* **second handler** (`pool 0x8C09D584`): `r4` is the argument (sign-extended
  from the frame) and `r0` is the object's second halfword; the `extu.w` zeroes
  `r0` and the delay slot's `add` gives `r4 = argument + (halfword & 0xFFFF)`.
  The continuation is `0x8C09D4D8`.
* **third** (`pool 0x8C09D588`): `r4` is the object's third halfword, zero
  extended. The frame is dropped (`add #16,r15`), `pr` is popped off the
  stack (`lds.l @r15+,pr`) and control jumps. This is the tail transfer: the
  third call inherits the caller's `pr`, so it returns to the caller's caller.

The two `jsr`s carry a plain continuation address, so the shared
`vf3_guest_call` helper is the right tool for them. The `jmp` is a tail
transfer and needs `vf3_guest_tail_call`, which hands the callee the popped
`pr` verbatim - the shared helper would force the `0x0C` form and lose the
caller's own return address.

## The evidence

`tests/halfword_frame_replay.c` runs the readable port and the retained
generated translation of the same function over three scenarios and compares
**the whole register file, the return PC, the failed PC, the out-of-window
counter and every RAM byte**. The port runs twice: once called directly and
once through the readable override, which is how the native tick reaches it.

```
halfword_frame: 3 differential cases - PASS
```

The two handlers are entries no ported code owns, so the test answers them
through the dispatcher's `missing` hook. Each of them **records** the value it
was given *and* the return address it was called with, and answers the value.
Recording matters twice over:

* the value is what shows a frame built in the wrong order;
* the return address is what shows a wrong continuation - a stub that only
  answers returns to `pr`, so a port that put the wrong continuation in `pr`
  would come back to the wrong place and still look right.

The third target is a **tail transfer**, and the translation reaches it
through the switch of the eighteen matrix operations, so the test uses one of
them (`matrix_identity`, which needs no memory) as the third target.

The test has teeth, and the mutations were checked:

* dropping the second handler's `r4 += r0` fails with the differing recorded
  value named (`32` != `10` at the slot the second handler wrote);
* the first handler reading the wrong frame slot fails with the differing
  recorded value named (`11` != `22`);
* a normal call instead of the tail transfer fails with the differing `pr`
  named (`v16` `0c0abcde` != `0c09d4e6`);
* a wrong continuation address fails with the differing recorded return
  address named (`cc` != `d0`).

That is the pattern `tests/state_helpers_replay.c` established: the generated
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
`0x8C09D4B0` before the port is trusted in the native tick.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* The frame: `pr` at `S-4` and the four halfwords at `S-20`, `S-16`, `S-12`
  and `S-8`, in the guest's order.
* The sign/zero extensions: `mov.w` sign-extends, `extu.w` does not.
* The delay slot of each `jsr` runs before the callee, so the masking and the
  add happen before the call.
* The tail transfer: the frame is dropped, `pr` is popped, and the third
  handler runs with the caller's `pr`.
* The two continuations are the guest's own addresses (`0x8C09D4CC` and
  `0x8C09D4D8`). This module does not use the `code_base` form, so the plain
  address is right and the shared `vf3_guest_call` helper can be used.

## The unknown

The values in the literal pool are not recoverable offline: they live in the
code image, which is under `extract/`. The pool says *which* three handlers
the function calls, not what they do with the halfwords. The port therefore
reads the same addresses the guest reads, and what the three handlers do stays
open until the image is back.
