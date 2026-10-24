# The mode index (SH-4 0x8C038990)

A readable port of the fight engine's mode-index switch, and the evidence for
it.

## The function

`0x8C038990` turns a flag into an index into some table. Eight flags are
known: four are constants and four live in the literal pool. A flag that is
none of them is left alone.

| flag                    | index |
| ----------------------- | ----- |
| `8`                     | 0     |
| `16`                    | 1     |
| `32`                    | 2     |
| `64`                    | 3     |
| the halfword at `0x8C038AF2` | 4 |
| the halfword at `0x8C038AF4` | 5 |
| the halfword at `0x8C038AF6` | 6 |
| the halfword at `0x8C038AF8` | 7 |

The pool's values are not recoverable offline, so the port reads the same
addresses the guest reads.

The port: `src/fight/mode_index.c`, registered in `src/fight/readable.c` as
`mode_index`.

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine translation
of the ROM: one label per guest PC, one C statement per executed opcode, and
the original opcode word in a comment. That makes them a faithful disassembly
of the function they implement, so a readable port can be written against them
without the ROM.

* `tools/adapter_body.py 0x0c038990 --span 140` - the body, in the module
  that carries it (`matrix_adapters`). `tools/adapter_owner.py` reports
  nothing for this PC, because that module is one of the legacy ones with no
  claim array - the router still serves it, and the test proves it.
* `tools/handwritten_entries.py 0x0c038990` - confirms that no hand-written
  module already serves this entry, so the port is not shadowed.
* The listing below is decoded with `tools/sh4.py`, the repo's authoritative
  decoder, from the opcode words the module carries; the semantics come from
  the translator's emitted C.

The guest code, decoded:

```
0x0c038990  6043  mov   r4,r0            ; a copy of the flag
0x0c038992  8808  cmp/eq #8,r0
0x0c038994  8b04  bf    0x0c0389a0       ; not eight: the next flag
0x0c038996  a03f  bra   0x0c038a18       ; eight: the answer is zero
0x0c038998  e400  mov   #0,r4            ; (the bra's delay slot)
0x0c0389a0  8810  cmp/eq #16,r0
0x0c0389a2  8b05  bf    0x0c0389b0
0x0c0389a4  a038  bra   0x0c038a18
0x0c0389a6  e401  mov   #1,r4
0x0c0389b0  6043  mov   r4,r0
0x0c0389b2  8820  cmp/eq #32,r0
0x0c0389b4  8b04  bf    0x0c0389c0
0x0c0389b6  a02f  bra   0x0c038a18
0x0c0389b8  e402  mov   #2,r4
0x0c0389c0  8840  cmp/eq #64,r0
0x0c0389c2  8b0d  bf    0x0c0389e0
0x0c0389c4  a028  bra   0x0c038a18
0x0c0389c6  e403  mov   #3,r4
0x0c0389e0  9387  mov.w @(270,pc),r3     ; the pool's first flag
0x0c0389e2  3430  cmp/eq r3,r4
0x0c0389e4  8b04  bf    0x0c0389f0
0x0c0389e6  a017  bra   0x0c038a18
0x0c0389e8  e404  mov   #4,r4
0x0c0389f0  9280  mov.w @(256,pc),r2     ; the pool's second flag
0x0c0389f2  3420  cmp/eq r2,r4
0x0c0389f4  8b04  bf    0x0c038a00
0x0c0389f6  a00f  bra   0x0c038a18
0x0c0389f8  e405  mov   #5,r4
0x0c038a00  9179  mov.w @(242,pc),r1     ; the pool's third flag
0x0c038a02  3410  cmp/eq r1,r4
0x0c038a04  8b04  bf    0x0c038a10
0x0c038a06  a007  bra   0x0c038a18
0x0c038a08  e406  mov   #6,r4
0x0c038a10  9372  mov.w @(228,pc),r3     ; the pool's fourth flag
0x0c038a12  3430  cmp/eq r3,r4
0x0c038a14  8b00  bf    0x0c038a18       ; not it: the flag is left alone
0x0c038a16  e407  mov   #7,r4
0x0c038a18  000b  rts                     ; and r0 gets the answer
```

Four details of that listing are worth naming, because each one is easy to lose
in a readable port:

* **the four constants are compared against a copy of the flag**, made in `r0`
  at the top, while the four pool flags are compared against the flag itself.
  The copy is never changed, so the two are the same value - but the port has
  to make the copy, because `r0` is the answer register at the end.
* **the answer is written in the delay slot of the branch that leaves.** The
  `mov #N,r4` after each `bra` is that branch's delay slot, and it runs before
  the branch is taken.
* **the T bit the caller sees is the one of the comparison that answered.** A
  hit leaves T set; the path that matches nothing leaves it clear, because the
  last comparison - against the pool's fourth flag - failed.
* **the pool's flags are signed halfwords**, and the guest sign-extends them,
  so a flag above `0x7FFF` is a negative number in the comparison.

## The evidence

`tests/mode_index_replay.c` runs the readable port and the retained generated
translation of the same function over nine scenarios and compares **the whole
register file (the FP registers and SR included), the return PC, the failed PC,
the out-of-window counter and every RAM byte**. The port runs twice: once
called directly and once through the readable override, which is how the native
tick reaches it.

```
mode_index: 9 differential cases - PASS
```

The scenarios walk the flag through the four constants, through the four values
the pool holds and through a flag that is none of them. The pool's fourth
value is negative as a signed halfword, so the sign extension is observable.

The test also checks the result **against the fixture itself**: the answer has
to be the index the scenario names, and the T bit has to be set on a hit and
clear when nothing matched.

### The test has teeth, and the mutations were checked

The mutations are checked with `tools/mutate.py`, which applies one at a time
to the port's source, rebuilds and requires the test to fail. The list lives
in `tests/mode_index_mutations.json`, next to the test it guards.

* the constant eight changed fails with the differing `r0` named
  (`v0 00000000` != `00000008`);
* the constant thirty-two changed fails with the differing `r0` named
  (`v0 00000002` != `00000020`);
* the constant sixty-four changed fails with the differing `r0` named
  (`v0 00000003` != `00000040`);
* the first index off by one fails with the differing `r0` named
  (`v0 00000000` != `00000001`);
* the last index off by one fails with the differing `r0` named
  (`v0 00000007` != `00000006`);
* the T bit never set fails with the differing `SR` named
  (`v17 00000301` != `00000300`);
* the T bit never cleared fails with the differing `SR` named
  (`v17 00000300` != `00000301`);
* the pool's first slot wrong fails with the differing `r0` named
  (`v0 00000004` != `00000111`);
* the pool's last slot wrong fails with the differing `r0` named
  (`v0 00000007` != `ffff8444`);
* the pool's second flag read from the third slot fails with the differing
  `r0` named (`v0 00000005` != `00000222`);
* the pool's third flag read from the second slot fails with the differing
  `r0` named (`v0 00000006` != `00000333`);
* the pool's flag read as unsigned fails with the differing `r0` named
  (`v0 00000007` != `ffff8444`) - this is the scenario with the negative flag,
  and without it the mutation would not be seen;
* the copy of the flag not made fails with the differing `r0` named
  (`v0 00000000` != `00000008`);
* the answer left as the old flag fails with the differing `r0` named
  (`v0 00000000` != `00000008`).

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
`0x8C038990` before the port is trusted in the native tick.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* The four constants are compared against the copy of the flag in `r0`, and the
  four pool flags against the flag itself.
* The pool's flags are read in order and land in `r3`, `r2`, `r1` and `r3`
  again, so the register file on exit depends on the path.
* The T bit is set on a hit and cleared when no flag matched.
* The answer goes into `r0` as well as into `r4`.

## The unknown

What the table is and who calls this are not recoverable offline: the pool's
values and the code live in the game's own image, which is under `extract/`.
The port therefore reads the same addresses the guest reads, and what the
indexes mean stays open until the image is back.
