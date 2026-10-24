# The table getter (SH-4 0x8C044068)

A readable port of the fight engine's table getter, and the evidence for it.

## The function

`0x8C044068` is the getter of a table entry. The engine asks a table for one
of its entries and the getter answers it:

1. it takes the caller's frame - the three words above the caller's `sp` -
   and hands them to the table's handler, the function pointer in the
   literal pool at `0x8C044144`;
2. the handler answers the entry;
3. the getter looks at the table's own slot: the table's pointer is in the
   literal pool at `0x8C044140` and the slot's offset in the table is the
   halfword at `0x8C04413A`;
4. when the slot is **taken** the getter asks the fallback (`0x8C043D04`),
   which lets the manager know. The fallback's own answer is dropped;
5. the handler's answer is the answer.

The branch in step 4 is worth stating plainly, because it is the opposite of
what the name suggests: the guest tests the slot with `tst` and branches
*over* the fallback when the slot is zero, so the fallback runs when the slot
is **not** empty. The port follows the machine.

The port: `src/fight/table_getter.c`, registered in `src/fight/readable.c` as
`table_getter`.

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine
translation of the ROM: one label per guest PC, one C statement per executed
opcode, and the original opcode word in a comment. That makes them a faithful
disassembly of the function they implement, so a readable port can be written
against them without the ROM.

* `tools/adapter_dump.py <entry>` - prints a generated function as guest
  disassembly: the PC, the opcode word, a decoded mnemonic and the C the
  translator emitted for it. Its decoder is crude: it prints `mov.b` for
  `mov.l`. `tools/sh4.py` is the repo's authoritative decoder
  (`decode(word, pc)`), and the translator's emitted C is the semantics that
  matters.
* `tools/adapter_body.py <entry> --span N` - prints the raw generated source
  of a PC range, module by module. Several modules carry the same PC and the
  chain serves the first one that owns it.
* `tools/adapter_owner.py <entry>` - **new in this milestone**. It resolves
  which module the router actually serves for a PC: it reads the chain order
  out of `vf3_matrix_family_core` and each module's `owned_pcs[]`, and lists
  every module that carries the PC. Several modules carry the same guest code
  and model it differently, so a readable port has to be written against the
  copy the chain serves. `0x8C044068` is carried by `target_record_adapters`
  and `vf3_sweep_adapters`; the chain serves `target_record_adapter`, and the
  two copies agree except for the alias-aware continuation of the second one.

The stack is the part that has to be got exactly right, because the
differential compares every RAM byte. With the entry's `sp` at `S`:

```
S-4   pr            (the prologue pushes it)
S-8   the local slot the answer waits in
S-12  the caller's third frame word   [S+8]
S-16  the caller's second frame word  [S+4]
S-20  the caller's first frame word   [S]
```

The three words are read with `mov.l @(16,r15),Rn` *after* each push, so the
guest reads them from the highest to the lowest and the handler sees them in
the order the caller passed them. The epilogue reads `pr` from `S-4`, not
from the local slot at `S-8` - the local slot holds the handler's answer and
is popped first.

## The evidence

`tests/table_getter_replay.c` runs the readable port and the retained
generated translation of the same function over three scenarios and compares
**the whole register file (the FP registers included), the return PC, the
failed PC, the out-of-window counter and every RAM byte**. The port runs
twice: once called directly and once through the readable override, which is
how the native tick reaches it.

```
table_getter: 3 differential cases - PASS
```

The scenarios cover the two branches and the order of the frame words: the
slot taken (the fallback runs), the slot clear (it does not), and a third
with the frame words in another order.

Both callees are entries no ported code owns, so the test answers them
through the dispatcher's `missing` hook:

* the table's handler gets the caller's three frame words on the stack and
  answers a mix of them, so a getter that forwarded them in the wrong order
  would answer something else and the test would say so;
* the fallback's own callee answers `-2`, which is the answer that sends the
  fallback down its short path (it sets a flag and returns). The fallback is
  a generated function that no port owns, so the test drives it through the
  chain and watches the words it writes.

The test has teeth, and the mutations were checked:

* asking the fallback on the other branch fails with the differing
  registers named (`v1`, `v2`, `v3` and the T flag);
* forwarding the wrong frame word fails with the differing answer named
  (`v0`).

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
`0x8C044068` before the port is trusted in the native tick.

## The family

`0x8C044068` is the first of a run of getters in the literal pool's
neighbourhood. They are the same function with another handler and another
number of frame words:

| entry | frame words | handler | module |
|---|---|---|---|
| `0x8C044068` | 3 | pool `0x8C044144` | `target_record_adapters` |
| `0x8C04409C` | 1 | pool `0x8C044148` | `vf3_c91_adapter` |
| `0x8C0440C8` | 0 | pool `0x8C04414C` | `vf3_c91_adapter` |
| `0x8C0440EE` | 0 | pool `0x8C044150` | `vf3_c91_adapter` |
| `0x8C044114` | 0 | pool `0x8C044154` | `vf3_c91_adapter` |

All of them share the tail: the same table pointer (`0x8C044140`), the same
slot offset (`0x8C04413A`), the same fallback (`0x8C043D04`) and the same
epilogue. The ones in `vf3_c91_adapter` write their continuation as
`code_base|0x8C0440AA` instead of the plain `0x8C04407E`, so they follow the
alias: their continuation carries the mirror the run came through
(`docs/re/coverage_93_alias_claim.md`). The port here is the one whose
module does not use `code_base`, so its continuation is the plain address.

Only `0x8C044068` is ported so far. The others are reached through the
literal pool, and the ported entry is the one the captured fight states
actually call.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* The frame: `pr` at `S-4`, the local slot at `S-8`, and the three frame
  words at `S-20`, `S-16` and `S-12` in that order.
* The handler's answer waits in the local slot while the slot is checked,
  and is read back afterwards - so the fallback, which changes `r0`, cannot
  change the answer.
* The T flag says whether the slot was clear.
* The calls carry the guest's own continuation addresses (`0x8C04407E` and
  `0x8C044092`), so the pushed `pr` is still in RAM when they return.
* `r1`, `r2` and `r3` keep the values the guest left in them: the slot, the
  table's pointer and the table itself - unless the fallback ran, in which
  case they are the fallback's own.

## The unknown

The values in the literal pool are not recoverable offline: they live in the
code image, which is under `extract/`. The pool says *where* the table is
and *which* slot the getter looks at, not what the slot means. The port
therefore reads the same addresses the guest reads, and the semantics of the
slot - a pointer, a count, a flag - stay open until the image is back.
