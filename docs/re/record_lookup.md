# The record lookup (SH-4 0x8C037788)

A readable port of the fight engine's record lookup, and the evidence for it.

## The function

`0x8C037788` is the record the engine looks up. The entry picks it: the index
`1` and the table behind the global at `0x8C0377A4`. The lookup then asks two
things:

* the record predicate (`0x8C03772A`, ported readably as `record_match`) gets
  the index and the table and answers whether the record fits;
* when it fits, the table's own getter - the function pointer in the literal
  pool at `0x8C037798` - answers the record itself.

The answer is `0` when the record was found, and the record's pointer is left
in `r4`. When the predicate says the record does not fit, the answer is `-1`.
When the getter answers a negative value, that value is the answer.

The guest keeps the index and the table in a two-word frame on the stack and
the getter's arguments in three words below it; the readable port keeps the
same words in the same places, so the stack traffic it leaves in RAM is the
one the original left.

The port: `src/fight/record_lookup.c`, registered in `src/fight/readable.c` as
`record_lookup`.

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
  `target_record_adapters.c` only, and so does its body (`0x8C0376E0` to
  `0x8C037726`), so there is no copy to compare.

The entry is a two-instruction stub that sets up the index and the table and
jumps into the body; the readable port does both in one function, because the
entry is what the engine calls.

**A note on the fragments.** The same guest code is also in
`advance_worker_adapters.c`, but only its tail - the true path of the
predicate, from `0x8C03777E` on. That fragment models the `rts` differently
from the complete copy in `vf3_fifth_leaf_unowned_adapter.c`: it does not
restore `r14` and leaves the stack four bytes off. The chain serves the
fragment only if something enters at `0x8C03777E` directly, and the captured
fight ticks never do - they reach the predicate through its own entry - so
nothing depends on it today. It is worth knowing when the fragment's entry
ever shows up in a capture.

## The evidence

`tests/record_lookup_replay.c` runs the readable port and the retained
generated translation of the same function over three scenarios and compares
**the whole register file (the FP registers included), the return PC, the
failed PC, the out-of-window counter and every RAM byte**. The port runs
twice: once called directly and once through the readable override, which is
how the native tick reaches it.

```
record_lookup: 3 differential cases - PASS
```

The scenarios cover the three answers: the predicate says the record does not
fit (`-1`), the record fits and the getter answers it (`0`), and the getter
answers a negative value (that value is the answer).

The three helpers the lookup reaches - the predicate's two and the table's
getter - are entries no ported code owns, so the test answers them through the
dispatcher's `missing` hook. What they answer is what makes the three answers
of the lookup observable; without them the lookup would always take the same
path and the test would prove nothing.

The test has teeth: looking up the index `2` instead of `1` makes it fail,
with the differing stack word named.

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
`0x8C037788` before the port is trusted in the native tick.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* The two-word frame (the index and the table) and the three words of the
  getter's arguments, in the order and at the depths the guest puts them:
  the frame is eight bytes under the entry's `sp` and the getter's
  arguments twelve bytes below that.
* The getter's arguments in the registers the SH-4 convention names:
  `r1` zero, `r2` the table, `r3` the size of a record (48), `r4` the index,
  `r5` four, `r6` and `r7` zero.
* `r0` holds the answer and `r4` the record the getter answered.
* The T flag says whether the predicate said no, and then whether the getter
  answered a non-negative value.
* The calls carry the guest's own continuation addresses (`0x0C0376EC` and
  `0x0C037710`), so the pushed `pr` is still in RAM when they return.
