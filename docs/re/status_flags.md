# The status flags (SH-4 0x8C0961F4)

A readable port of the fight engine's status flags, and the evidence for it.

## The function

`0x8C0961F4` turns a record into a bitmask. It takes the **mask** (`r4`) and
the **record** (`r5`), reads eight fields of the record and puts one bit in the
answer for every field that has a bit in common with the mask:

| the field at | the bit |
|---|---|
| +8  | `0x04` |
| +12 | `0x08` |
| +0  | `0x01` |
| +4  | `0x02` |
| +24 | `0x10` |
| +20 | `0x20` |
| +28 | `0x40` |
| +32 | the mask in the literal pool at `0x8C09630A` |

The order is the guest's, and so are the gaps: the record has no field at
+16, and the eight fields are *not* in offset order. The answer is left in
`r0` (and in `r6`, which the guest builds it in).

The port: `src/fight/status_flags.c`, registered in `src/fight/readable.c` as
`status_flags`.

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine
translation of the ROM: one label per guest PC, one C statement per executed
opcode, and the original opcode word in a comment. That makes them a faithful
disassembly of the function they implement, so a readable port can be written
against them without the ROM.

* `tools/adapter_owner.py 0x0c0961f4` - resolves which module the router
  actually serves for a PC. The answer is **one** module, `matrix_adapters`:
  no other module carries the PC, so there is no second copy that could model
  it differently. (`matrix_adapters` is a legacy module and declares no
  `owned_pcs[]` array, which is why the tool reports no carrier at all - the
  labels were found by searching the modules for `P_0c0961f4:`.)
* `tools/adapter_dump.py 0x0c0961f4` - prints the generated function as guest
  disassembly. Its own decoder is crude, so the mnemonics below come from
  `tools/sh4.py`, the repo's authoritative decoder, and the semantics come
  from the translator's emitted C.

The guest code, decoded:

```
0x0c0961f4  5352  mov.l @(8,r5),r3
0x0c0961f6  2348  tst   r4,r3
0x0c0961f8  8d01  bt/s  +6              ; the delay slot zeroes r6
0x0c0961fa  e600  mov   #0,r6            ; <- the delay slot
0x0c0961fc  e604  mov   #4,r6
0x0c0961fe  5353  mov.l @(12,r5),r3
0x0c096200  2348  tst   r4,r3
0x0c096202  8d02  bt/s  +8              ; the delay slot loads the field at +0
0x0c096204  6352  mov.l @r5,r3          ; <- the delay slot
0x0c096206  e108  mov   #8,r1
0x0c096208  261b  or    r1,r6
0x0c09620a  2348  tst   r4,r3
0x0c09620c  8d02  bt/s  +8              ; the delay slot loads the field at +4
0x0c09620e  5351  mov.l @(4,r5),r3      ; <- the delay slot
0x0c096210  e101  mov   #1,r1
0x0c096212  261b  or    r1,r6
0x0c096214  2348  tst   r4,r3
0x0c096216  8d02  bt/s  +8              ; the delay slot loads the field at +24
0x0c096218  5356  mov.l @(24,r5),r3     ; <- the delay slot
0x0c09621a  e102  mov   #2,r1
0x0c09621c  261b  or    r1,r6
0x0c09621e  2348  tst   r4,r3
0x0c096220  8d02  bt/s  +8              ; the delay slot loads the field at +20
0x0c096222  5355  mov.l @(20,r5),r3     ; <- the delay slot
0x0c096224  e110  mov   #16,r1
0x0c096226  261b  or    r1,r6
0x0c096228  2348  tst   r4,r3
0x0c09622a  8d02  bt/s  +8              ; the delay slot loads the field at +28
0x0c09622c  5357  mov.l @(28,r5),r3     ; <- the delay slot
0x0c09622e  e120  mov   #32,r1
0x0c096230  261b  or    r1,r6
0x0c096232  2348  tst   r4,r3
0x0c096234  8d02  bt/s  +8              ; the delay slot loads the field at +32
0x0c096236  5358  mov.l @(32,r5),r3     ; <- the delay slot
0x0c096238  e140  mov   #64,r1
0x0c09623a  261b  or    r1,r6
0x0c09623c  2438  tst   r3,r4
0x0c09623e  8901  bt    +6
0x0c096240  9163  mov.w @(198,pc),r1    ; the pool at 0x8C09630A
0x0c096242  261b  or    r1,r6
0x0c096244  000b  rts
```

Three things in that listing are worth naming, because each one is easy to lose
in a readable port:

* **the delay slot runs before the branch.** The translator merges the slot
  into the branch block, so the *next* field is loaded before the test of the
  *current* one is resolved. The port reads the fields in the guest's order,
  which is the order the delay slots force.
* **`tst` sets the T bit, and the branch reads it.** The T bit is part of the
  contract: the guest leaves it holding the last test, and the caller can
  read it. The port sets it after every test, the last one included.
* **the first bit is assigned, the rest are or-ed.** The first `bt/s` has
  `mov #0,r6` in its delay slot, so the answer is zeroed before the first bit
  goes in and that bit is *assigned* (`mov #4,r6`) rather than or-ed. The
  difference only shows if a port or-ed into a register that already held
  something.

## The evidence

`tests/status_flags_replay.c` runs the readable port and the retained
generated translation of the same function over five scenarios and compares
**the whole register file (SR and its T bit included), the return PC, the
failed PC, the out-of-window counter and every RAM byte**. The port runs
twice: once called directly and once through the readable override, which is
how the native tick reaches it.

```
status_flags: 5 differential cases - PASS
```

The function calls nothing, so the test only has to give it a record and the
pool slot the last bit comes from. The scenarios cover the empty record (no
bit goes in, and the pool is *not* read), the full one (every bit goes in),
a mask that counts only the low bits (so the fields' high bits do not count),
a mixture, and a single field in the high bit.

The test has teeth, and the mutations were checked:

* inverting the test fails with the differing answer named (`v0` `00000000`
  != `00000001`);
* changing one bit fails with the differing answer named (`v0` `000000ff` !=
  `000000f7`);
* reading the pool outside the branch fails with the differing `r1` named
  (`76543211` != `00000080`);
* dropping the last T update fails with the differing `SR` named (`v17`
  `00000300` != `00000301`);
* reading the wrong field fails with the differing answer named (`v0`
  `000000ff` != `000000ef`).

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
`0x8C0961F4` before the port is trusted in the native tick.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* The eight fields are read in the guest's order: `+8`, `+12`, `+0`, `+4`,
  `+24`, `+20`, `+28`, `+32` - the gaps and the order are both the guest's.
* The test is `(field & mask) != 0`, and the T bit is set to the *negation*
  of it, because `tst` sets T when the AND is zero.
* The first bit is assigned into a zeroed answer; the rest are or-ed in.
* The pool slot is read **only** when the last bit goes in, so `r1` keeps its
  old value otherwise.
* The answer is left in `r0` *and* in `r6`; `r1` holds the last bit that was
  put in and `r3` holds the last field that was read.
* The function touches no stack: `sp` is where the caller left it.

## The unknown

The value in the literal pool at `0x8C09630A` is not recoverable offline: it
lives in the code image, which is under `extract/`. The pool says *which* bit
the last field puts in, not what it is. The port therefore reads the same
address the guest reads, and what that bit is stays open until the image is
back.
