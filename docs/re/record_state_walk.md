# The record state walk (SH-4 0x8C03550C)

A readable port of the fight engine's record walk, and the evidence for it.

## The function

`0x8C03550C` walks a record's node chain and reports the state the node is
in. The record comes in `r4`; the guest keeps it in `r14` and saves `r14`,
`r13`, `r12`, `r11`, `r10` and `pr` around the work.

The record's first word is a vtable pointer, and slot 9 of that vtable
(offset 36) is the node's *kind*. A kind of 2 means "no callback"; every
other kind calls the node callback - the function pointer in the global at
`0x8C0355EC` - before the state is read.

The state itself comes from the helper at `0x8C035A20`, which reads the
record's field pair: a flag halfword at `+0x48` and a code halfword at
`+0x4C`. A record whose flag is clear has no code, and the helper answers
-10 for it. The walk reads the code like this:

| code | meaning | result |
|---|---|---|
| 0 | the node is empty | -32 (`0xFFFFFFE0`) |
| 1 | the walk is finished | 0 |
| 2, 3, 4 | the walk goes on | next round |
| 5, 6 | the node holds a value | the signed halfword at `+0x4E` |
| any other | a code the walk does not know | -25 (`0xFFFFFFE7`) |

Every round moves the walk cursor. The cursor lives behind the global
pointer at `0x8C0355E8` and its first word is the current position; the step
from the previous position has to stay inside the limit in the global
halfword at `0x8C0355E4`, or the walk ends with -21 (`0xFFFFFFEB`). The
previous position is the cursor's own value from the last time the record's
node pointer (its word at `+0x18`) moved, and the value the cursor carried
when the walk started. The comparison is the SH-4 `cmp/hi`, so it is
unsigned, while the limit is read as a *signed* short - a negative limit is
a huge unsigned one.

The port: `src/fight/record_state_walk.c`, registered in
`src/fight/readable.c` as `record_state_walk`.

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine
translation of the ROM: one label per guest PC, one C statement per
executed opcode, and the original opcode word in a comment. That makes
them a faithful disassembly of the function they implement, so a readable
port can be written against them without the ROM.

Three tools do the reading:

* `tools/adapter_dump.py <entry>` - prints a generated function as guest
  disassembly: the PC, the opcode word, a decoded mnemonic and the C the
  translator emitted for it.
* `tools/adapter_body.py <entry> --span N` - prints the raw generated
  source of a PC range, module by module. Several modules carry the same
  PC (the same function was captured in more than one campaign), and the
  router serves the first module in chain order that *owns* it, so the
  copies have to be compared before one is picked.
* `tools/readable_gap.py --loops --overlap` - ranks the call-target
  entries that no readable port covers yet, and lists the readable ports
  that still have a generated twin (160 of the 161 at the time of
  writing). After this port: 831 call-target functions are still served by
  generated code alone, 133 of them with a loop in them.

`0x8C03550C` was chosen from that ranking: it is a call target the captured
fight ticks really reach, it contains a loop, and its whole body lives in
one generated module, so a single readable port covers it.

## The evidence

`tests/record_state_walk_replay.c` runs the readable port and the retained
generated translation of the same function over eleven scenarios and
compares **the whole register file, the return PC, the failed PC, the
out-of-window counter, every RAM byte and the number of callback calls**.
The port runs twice: once called directly and once through the readable
override, which is how the native tick reaches it:

```
record_state_walk: 11 differential cases - PASS
```

The scenarios cover the empty record, the finished walk, both value codes,
the unknown code, a record whose flag is clear, the kind that asks for no
callback, a step past the limit, a walk that runs five rounds, a callback
that hands the record a value and a callback that moves the node.

The callback is a call into an entry no ported code owns, so the test
answers it through the dispatcher's `missing` hook. It advances the walk
cursor and may set the record's code, which is what makes the callback
observable: a callback that changed nothing would let the port skip the
call and still agree with the reference.

This is the pattern `tests/state_helpers_replay.c` established: the
generated translation stays in the tree as the reference, and the readable
port is proved against it. The generated translation of this function was
itself proved against the oracle when it was promoted, so the chain
readable port == generated translation == oracle still holds.

**Caveat.** The oracle corpora live under `extract/`, and that tree is
gone from this checkout (see [artifact_gap](artifact_gap.md)). The oracle
replay of this entry could not be re-run, so the differential above stands
on the generated translation rather than on a fresh oracle run. The
generated translation is the one the oracle proved, so the chain is intact,
but a session that has the corpora back should re-run the replay gate for
`0x8C03550C` before the port is trusted in the native tick.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* The six pushed words (r14, r13, r12, r11, r10, pr) and the six pops in
  the other order. They leave their values in RAM, so the stack traffic is
  visible in the RAM comparison.
* The two calls carry the guest's own continuation addresses
  (`0x0C035530` for the callback, `0x0C035534` for the state getter). The
  callee pushes `pr`, so the pushed word - and with it the continuation
  address - is still in RAM when the call returns.
* `r4` carries the code the getter returned, on every path out of the
  switch, including the two error codes.
* The T flag: the guest's `cmp/eq` chain leaves it set on the value and
  empty-code paths and clear on the unknown-code path, and the step
  comparison leaves it set when the walk gives up with -21.
* The step comparison is unsigned, and the limit is a signed short.
