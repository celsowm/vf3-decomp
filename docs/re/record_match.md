# The record predicate (SH-4 0x8C03772A)

A readable port of the fight engine's record predicate, and the evidence for
it.

## The function

`0x8C03772A` answers one question: does the object the caller has fit the
record the engine expects? The answer is `1` or `0`.

It asks two helpers first:

* the first helper - the function pointer in the literal pool at
  `0x8C03779C` - gets the caller's `r4`, the object, and answers a pointer to
  a record;
* the second helper - the pointer at `0x8C0377A0` - gets a twelve-byte header
  on the stack and answers a status.

Then the function checks what they said, and the first check that fails ends
the chain:

| check | fails when |
|---|---|
| the status | it is negative |
| the record's first word | it is not 14 |
| the header's word at `+4` | it is not 1 |
| the header's word at `+6` | it is not the global halfword at `0x8C03778E` |
| the header's word at `+8` | it is not 1 |
| the header's byte at `+10` | it is not 0 |
| the header's byte at `+11` | it is not 0 |

Every check leaves its value in `r0` and sets the T flag, so the T flag says
whether the chain held.

The guest saves `r14` and `pr` around the work and keeps the twelve-byte
header below them on the stack; the first helper's delay slot saves the
caller's `r4` in the header's first word. The readable port does the same, so
the stack words it leaves in RAM are the ones the original left.

The port: `src/fight/record_match.c`, registered in `src/fight/readable.c` as
`record_match`.

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine
translation of the ROM: one label per guest PC, one C statement per executed
opcode, and the original opcode word in a comment. That makes them a faithful
disassembly of the function they implement, so a readable port can be written
against them without the ROM.

* `tools/adapter_dump.py <entry>` - prints a generated function as guest
  disassembly: the PC, the opcode word, a decoded mnemonic and the C the
  translator emitted for it.
* `tools/adapter_body.py <entry> --span N` - prints the raw generated source
  of a PC range, module by module. This entry lives in
  `vf3_fifth_leaf_unowned_adapter.c`; its true path (`0x8C03777E`) also lives
  in `advance_worker_adapters.c`, which comes first in the chain, so the two
  copies have to be compared before one is picked.
* `tools/readable_gap.py --leaf` - ranks the call-target functions that save
  their registers, which is where a function of its own can be told apart
  from the landing pad of a tail transfer.

The opcode words in the comments are the real ones, and `tools/sh4.py` (the
repo's complete SH-4 decoder) confirms the reading: `2fe6` is `mov.l
r14,@-r15`, `4f22` is `sts.l pr,@-r15`, `d31b` and `d21a` are the two
`mov.l @(disp,pc)` loads of the helper pointers, `890c` is the `bt` on the
status and `84fb` is the `mov.b @(disp,r15),r0` of the last check.

## The evidence

`tests/record_match_replay.c` runs the readable port and the retained
generated translation of the same function over eight scenarios and compares
**the whole register file (the FP registers included), the return PC, the
failed PC, the out-of-window counter and every RAM byte**. The port runs
twice: once called directly and once through the readable override, which is
how the native tick reaches it.

```
record_match: 8 differential cases - PASS
```

The scenarios cover the record the engine expects and one failure for every
check in the chain: a negative status, another record kind, and a header
whose first word, second word, third word and two flag bytes are all wrong
one at a time.

The two helpers are entries no ported code owns, so the test answers them
through the dispatcher's `missing` hook: the first one hands out a record,
the second one fills the header on the stack and answers the status. What
they answer is what makes every check observable - without them the
predicate would always fail the same way and the test would prove nothing.

The test has teeth: answering 13 instead of 14 for the record's kind makes
it fail, with the differing registers named.

This is the pattern `tests/state_helpers_replay.c` established: the generated
translation stays in the tree as the reference, and the readable port is proved
against it. The generated translation of this function was itself proved
against the oracle when it was promoted, so the chain readable port ==
generated translation == oracle still holds.

**Caveat.** The oracle corpora live under `extract/`, and that tree is gone
from this checkout (see [artifact_gap](artifact_gap.md)). The oracle replay
of this entry could not be re-run, so the differential above stands on the
generated translation rather than on a fresh oracle run. The generated
translation is the one the oracle proved, so the chain is intact, but a
session that has the corpora back should re-run the replay gate for
`0x8C03772A` before the port is trusted in the native tick.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* The three words the guest puts on the stack - `r14`, `pr` and the header's
  first word - and the order it takes them off in. They leave their values
  in RAM, so the stack traffic is visible in the RAM comparison.
* The header sits *below* the two saved registers, so it is twenty bytes
  under the entry's `sp`: the two pushes take it to `sp-8` and the header
  takes it to `sp-20`.
* `r2` holds the second helper, `r3` the first one and later the global
  halfword, `r4` the status the second helper answered, `r5` the record the
  first one answered.
* `r0` holds the answer, and the T flag says whether the chain of checks
  held.
* The calls carry the guest's own continuation addresses (`0x0C037736` and
  `0x0C037742`), so the pushed `pr` is still in RAM when they return.
