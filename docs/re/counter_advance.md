# The frame counters (SH-4 0x8C08B338)

A readable port of the fight engine's frame counters, and the evidence for it.

## The function

`0x8C08B338` advances the counters a fighter's animation state carries. The
record holds three of them and a block holds the fourth:

| counter | where | width | what it does |
| --- | --- | --- | --- |
| wide | record `+12` | seven bits | steps by one |
| narrow | record `+14` | two bits | steps by the carried bit |
| four | record `+16` | four bits | steps by the carried bit |
| block | block `+0x54` | seven bits | steps by the carried bit, wraps at 127 |

The **carried bit** is the low bit of the *incremented* wide counter - the guest
computes `r6 = 1 & (wide + 1)`. That is not the bit that falls out of the
seven-bit field: when the wide counter wraps (127 to zero) the carried bit is
*zero*, so the three other counters stand still on that step. On the other
steps the narrow counters move on every other step of the wide one.

A global decides whether the counters move at all. The guest tests the value
the global points at against a mask, and the counters advance only when the two
have **no bit in common**:

* `0x8C08B3EC` - the mask;
* `0x8C08B3F0` - a pointer to the value that is tested;
* `0x8C08B3F4` - a pointer to the header of the block.

The block needs **two** indirections: the global holds the *header's* address,
and the header's first word holds the block. The counter sits at `+0x54` in the
block itself.

The port: `src/fight/counter_advance.c`, registered in `src/fight/readable.c` as
`counter_advance`.

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine
translation of the ROM: one label per guest PC, one C statement per executed
opcode, and the original opcode word in a comment. That makes them a faithful
disassembly of the function they implement, so a readable port can be written
against them without the ROM.

* `tools/adapter_owner.py 0x0c08b338 --all` - resolves which module the router
  actually serves for a PC. A single module, `motion_adapter`, carries the copy
  in `src/fight/motion_adapters_2.c`.
* `tools/adapter_dump.py 0x0c08b338` - prints the generated function as guest
  disassembly. Its own decoder is crude, so the mnemonics below come from
  `tools/sh4.py`, the repo's authoritative decoder, and the semantics come
  from the translator's emitted C.

The guest code, decoded:

```
0x0c08b338  d12d  mov.l @(180,pc),r1     ; the pointer to the gate's value
0x0c08b33a  d32c  mov.l @(176,pc),r3     ; the mask
0x0c08b33c  6212  mov.l @r1,r2            ; the value
0x0c08b33e  2238  tst   r3,r2            ; T = (mask & value) == 0
0x0c08b340  8b21  bf    0x0c08b386       ; the gate is shut: nothing moves
0x0c08b342  8546  mov.w @(12,r4),r0      ; the wide counter
0x0c08b344  e601  mov   #1,r6
0x0c08b346  e37f  mov   #127,r3
0x0c08b348  6503  mov   r0,r5
0x0c08b34a  7501  add   #1,r5
0x0c08b34c  2659  and   r5,r6            ; the carried bit
0x0c08b34e  2539  and   r3,r5            ; the wide counter, seven bits
0x0c08b350  6053  mov   r5,r0
0x0c08b352  8146  mov.w r0,@(12,r4)
0x0c08b354  d227  mov.l @(156,pc),r2     ; the header of the block
0x0c08b356  e054  mov   #84,r0           ; the counter's slot
0x0c08b358  e17f  mov   #127,r1
0x0c08b35a  6722  mov.l @r2,r7            ; the block
0x0c08b35c  057d  mov.w @(r0,r7),r5      ; the block's counter
0x0c08b35e  356c  add   r6,r5
0x0c08b360  635f  exts.w r5,r3           ; sign-extended
0x0c08b362  3313  cmp/ge r1,r3           ; T = (counter >= 127)
0x0c08b364  8b00  bf    0x0c08b368       ; no wrap
0x0c08b366  e500  mov   #0,r5            ; wrap
0x0c08b368  0755  mov.w r5,@(r0,r7)
0x0c08b36a  e303  mov   #3,r3
0x0c08b36c  8547  mov.w @(14,r4),r0      ; the two-bit counter
0x0c08b36e  e20f  mov   #15,r2
0x0c08b370  6503  mov   r0,r5
0x0c08b372  356c  add   r6,r5
0x0c08b374  2539  and   r3,r5            ; two bits
0x0c08b376  6053  mov   r5,r0
0x0c08b378  8147  mov.w r0,@(14,r4)
0x0c08b37a  8548  mov.w @(16,r4),r0      ; the four-bit counter
0x0c08b37c  6503  mov   r0,r5
0x0c08b37e  356c  add   r6,r5
0x0c08b380  2529  and   r2,r5            ; four bits
0x0c08b382  6053  mov   r5,r0
0x0c08b384  8148  mov.w r0,@(16,r4)
0x0c08b386  000b  rts
```

Five details of that listing are worth naming, because each one is easy to
lose in a readable port:

* **the gate is the *absence* of a common bit.** `tst r3,r2` sets T when the
  two share nothing, and the `bf` skips the body when T is clear - so the
  counters advance when `(mask & value) == 0`. A port that reads the branch the
  other way round runs the body exactly when the gate is shut.
* **the carried bit is the low bit of the *incremented* counter.** The guest
  computes it with `and r5,r6` while `r6` is 1, so it is `(wide + 1) & 1`. A
  port that carries the bit that falls out of the seven-bit field (or the wide
  counter's old low bit) disagrees with the reference on every step.
* **the wrap test is a signed comparison on a sign-extended halfword.**
  `exts.w r5,r3` then `cmp/ge r1,r3` compares the *signed* value against 127,
  so a counter of 32767 that takes the carry becomes -32768 and does **not**
  wrap: the stored halfword is `0x8000`.
* **the T flag is written twice.** The `tst` writes it for the gate and the
  `cmp/ge` overwrites it with the wrap test, so when the body runs the caller
  sees the wrap test's answer, not the gate's.
* **there is no delay slot in this function.** Every branch is a plain `bf`, so
  the translator's "the delay slot runs first" rule does not apply here.

## The evidence

`tests/counter_advance_replay.c` runs the readable port and the retained
generated translation of the same function over eight scenarios and compares
**the whole register file (the FP registers and SR included), the return PC,
the failed PC, the out-of-window counter and every RAM byte**. The port runs
twice: once called directly and once through the readable override, which is
how the native tick reaches it.

```
counter_advance: 8 differential cases - PASS
```

The test seeds the literal pool with the mask and the two pointers, lays the
gate's value, the header, the block and the record out the way the guest
expects, and the scenarios cover the gate shut, the gate open, a mask of zero,
a wide counter that was odd (nothing carried), the wide counter wrapping, the
block's counter wrapping at 127, the two narrow counters wrapping on their own
widths and a counter that is already past its width.

The test has teeth, and the mutations were checked:

* the gate inverted fails with the differing `r0`, `r1`, `r2`, `r3`, `r5`, `r6`
  and `r7` named;
* the wide mask widened to `0xFF` fails with the differing record byte named
  (`ram 236 00 != 80`);
* the block's threshold moved to 128 fails with the differing `r1` named (`v1`
  `0000007f` != `00000080`);
* the wrap comparison turned exclusive fails with the differing `SR` named
  (`v17 00000301` != `00000300`);
* the block's counter slot moved fails with the differing RAM byte named
  (`ram 176 00 != 01`);
* the carried bit forced to one fails with the differing `r6` named (`v6`
  `00000000` != `00000001`);
* the two-bit counter widened to three bits fails with the differing `r3` named
  (`v3 00000003` != `00000007`);
* the carried bit dropped from the two-bit counter fails with the differing
  record byte named (`ram 238 02 != 01`);
* the T flag update dropped fails with the differing `SR` named (`v17 00000300`
  != `00000301`).

This is the pattern `tests/state_helpers_replay.c` established: the generated
translation stays in the tree as the reference, and the readable port is proved
against it. The generated translation of this function was itself proved
against the oracle when it was promoted, so the chain readable port ==
generated translation == oracle still holds.

**One trap the test itself walked into.** The first version of the fixture
pointed the block's global straight at the block, instead of at a header whose
first word is the block. The reference then read the counter from address
`0x54` - outside every window - and the differential *still passed*, because
both sides read the same uncaptured address and the out-of-window counter
matched. The block's counter was simply never exercised. The fixture now has
the header, and the wrap scenario is real.

**Caveat.** The oracle corpora live under `extract/`, and that tree is gone
from this checkout (see [artifact_gap](artifact_gap.md)). The oracle replay of
this entry could not be re-run, so the differential above stands on the
generated translation rather than on a fresh oracle run. The generated
translation is the one the oracle proved, so the chain is intact, but a
session that has the corpora back should re-run the replay gate for
`0x8C08B338` before the port is trusted in the native tick.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* The counters advance only when the gate's value has **no** bit in common
  with the mask; otherwise the function writes nothing at all.
* The carried bit is `(wide + 1) & 1`, and it is added to the two narrow
  counters and to the block's counter.
* The wide counter keeps seven bits, the narrow one two, the four-bit one four.
* The block's counter wraps to zero at 127, and the test is a signed comparison
  on the sign-extended halfword.
* The T flag is written by the gate's `tst` and overwritten by the wrap's
  `cmp/ge`.
* The block is reached through two indirections: global, then header.

## The unknown

The three globals and the mask are not recoverable offline: they live in the
code image, which is under `extract/`. The port therefore reads the same
addresses the guest reads, and what the counters count - and what the gate
gates - stays open until the image is back.
