# The node query (SH-4 0x8C053CA4)

A readable port of the fight engine's node query, and the evidence for it.

## The function

`0x8C053CA4` takes an index, looks the node up in the table behind the
literal pool at `0x8C053D44` and asks two handlers about it:

* the **first handler** - the function pointer at `0x8C053D48` - gets the
  node and answers a pointer to a status byte;
* the **second handler** - the function pointer at `0x8C053D4C` - gets the
  node and answers a pointer to a word of flags.

The answer is `1` when the status byte is not zero **and** the flags carry the
bit `1`; it is `0` in every other case.

The port: `src/fight/node_query.c`, registered in `src/fight/readable.c` as
`node_query`.

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine
translation of the ROM: one label per guest PC, one C statement per executed
opcode, and the original opcode word in a comment. That makes them a faithful
disassembly of the function they implement, so a readable port can be written
against them without the ROM.

* `tools/adapter_dump.py <entry>` - prints a generated function as guest
  disassembly: the PC, the opcode word, a decoded mnemonic and the C the
  translator emitted for it. Its decoder is crude; `tools/sh4.py` is the
  repo's authoritative decoder (`decode(word, pc)`), and the translator's
  emitted C is the semantics that matters.
* `tools/adapter_body.py <entry> --span N` - prints the raw generated source
  of a PC range, module by module.
* `tools/adapter_owner.py <entry>` - resolves which module the router
  actually serves for a PC: it reads the chain order out of
  `vf3_matrix_family_core` and each module's `owned_pcs[]`, and lists every
  module that carries the PC. `0x8C053CA4` is carried by five modules;
  the chain serves `vf3_c81_adapter`, and the copies differ - the
  `eighth_adapters` copy is only a fragment that tail-jumps into the next
  function.

The stack, with the entry's `sp` at `S`:

```
S-4   r14          (the prologue saves it)
S-8   pr           (the prologue saves it)
S-12  the first answer
```

The epilogue drops the answer, pops `pr` from `S-8` and `r14` from `S-4`.

## The code base

The module that serves this function writes its continuations with a code
base, and its `code_base` comes from **the caller's return address**:

```c
uint32_t code_base=((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u;
```

So a call through the `0x8c` mirror continues at `0x8C053CB8` and a call
through `0x0c` at `0x0C053CB8`. The port follows the caller's `pr`:

```c
static uint32_t code_base_of(const vf3_matrix_state *s)
{
    return ((s->v[16] & 0xff000000u) == 0x0c000000u) ? 0x0c000000u : 0x8c000000u;
}
```

Note that this is **not** the `vf3_matrix_call_alias` model of the
`vf3_c9x`/`vf3_c10x` modules, which derives the code base from the alias
words the caller hands over. The two rules live in different modules and
they do not agree; a readable port has to use the rule of the module it
replaces.

Because of this the port cannot use the shared `vf3_guest_call` helper: that
one forces the continuation into the `0x0C` form
(`0x0C000000 | (ret_addr & 0x0FFFFFFF)`), which would lose the mirror. The
port has its own `guest_call`, which sets `pr` to the continuation exactly as
the guest leaves it.

## The evidence

`tests/node_query_replay.c` runs the readable port and the retained generated
translation of the same function over five scenarios and compares **the whole
register file (the FP registers included), the return PC, the failed PC, the
out-of-window counter and every RAM byte**. The port runs twice: once called
directly and once through the readable override, which is how the native tick
reaches it.

```
node_query: 5 differential cases - PASS
```

The scenarios cover the answer: the status set and the flag present (the
node is active), the status set and the flag missing, the status clear, the
other bits of the flags, and another node of the table.

Both handlers are entries no ported code owns, so the test answers them
through the dispatcher's `missing` hook. Each handler answers a pointer that
depends on the node it was given - `node + 0x100` for the status and
`node + 0x200` for the flags - so a port that looked the wrong node up
would read the wrong status and the wrong flags.

The handlers also **record the return address they were called with**. That
is not decoration: with a stub that only answers, the continuation is
invisible in the final state (the epilogue restores `pr` from the stack, and
the continuation is never pushed), and a port that ignored the code base
would still pass. The recorded return address makes the mirror visible.

The test uses the `0x8c` form of the caller's return address, so the
continuation has to carry the `0x8c` code base.

The test has teeth, and the mutations were checked:

* asking for the wrong flag bit fails with the differing answer and T flag
  named (`v0`, `v17`);
* ignoring the code base fails with the differing recorded return address
  named (`ram ... 8c != 0c`).

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
`0x8C053CA4` before the port is trusted in the native tick.

## The family

`0x8C053CE4` is the same query with a third handler (the pointer at
`0x8C053D50`) and a bigger frame; it lives in another module and is not
ported yet. The two share the table at `0x8C053D44`.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* The frame: `r14` at `S-4`, `pr` at `S-8` and the first answer at `S-12`.
* The node is looked up as `table[index * 4]`, and it is passed to both
  handlers in `r4`.
* The first answer is kept in the frame while the second handler runs, so
  the second handler cannot change it.
* The status is read as a **signed** byte, and the test is against zero, so a
  negative status counts as "set".
* The flags are read as a word and only the bit `1` matters.
* The T flag says whether the status was clear - and in the other branch
  whether the flag was *missing*, so the T flag and the answer are
  opposites there.
* The calls carry the guest's own continuation addresses, with the code base
  the module uses.

## The unknown

The values in the literal pool are not recoverable offline: they live in the
code image, which is under `extract/`. The pool says *where* the table is
and *which* handlers to ask, not what the node is. The port therefore reads
the same addresses the guest reads, and what a node is stays open until the
image is back.
