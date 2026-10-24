# The node handler (SH-4 0x8C0AB870)

A readable port of the fight engine's node handler, and the evidence for it.

## The function

`0x8C0AB870` takes an object (`r4`) and a node (`r6`) and calls the handler
the node names:

* the **handler** is the table's entry at the node's second word: the table
  is behind the literal pool at `0x8C0AB9A0` and the index is `[r6+4]`;
* the handler gets a **five-word frame** on the stack - the handler itself,
  the object's first word, the node's two words, and the float that belongs
  to the object;
* the float is the one at the object's address plus the offset in the literal
  pool at `0x8C0AB990`, and it travels through the FPU (`FR3`) on the way;
* `r5` points at the frame's *second* word, so the handler's arguments start
  there.

The port: `src/fight/node_handler.c`, registered in `src/fight/readable.c` as
`node_handler`.

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine
translation of the ROM: one label per guest PC, one C statement per executed
opcode, and the original opcode word in a comment. That makes them a faithful
disassembly of the function they implement, so a readable port can be written
against them without the ROM.

* `tools/adapter_dump.py <entry>` - prints a generated function as guest
  disassembly. Its decoder is crude; `tools/sh4.py` is the repo's
  authoritative decoder (`decode(word, pc)`), and the translator's emitted C
  is the semantics that matters.
* `tools/adapter_body.py <entry> --span N` - prints the raw generated source
  of a PC range, module by module.
* `tools/adapter_owner.py <entry>` - resolves which module the router
  actually serves for a PC. `0x8C0AB870` is carried by `motion_adapters_3`
  and by `phase2_adapters_0`; the chain serves `phase2_adapter`, whose
  `vf3_phase2_adapter` hands the low half of its range to
  `vf3_phase2_adapter_0` - the file `phase2_adapters_0.c`. The two copies
  agree.

The frame, with the entry's `sp` at `S`:

```
S-4    pr
S-8    the float (FR3)
S-12   the node's second word
S-16   the node's first word
S-20   the object's first word
S-24   the handler
```

`r5` is `S-20` when the handler is called - the frame's second word.

## The FPU

The float moves through `FR3`: the guest loads it from the object and stores
it into the frame. The translator emits the shared helpers
`vf3_matrix_load`/`vf3_matrix_store`, which size the transfer by the FPUL
bit of the FPSCR (four bytes in single precision, eight in double). The port
calls the same helpers, so the transfer is identical by construction - but
that also means the port inherits their behaviour, and the test has to set
the FPSCR the way the reference sees it.

## The evidence

`tests/node_handler_replay.c` runs the readable port and the retained
generated translation of the same function over three scenarios and compares
**the whole register file (the FP registers included), the return PC, the
failed PC, the out-of-window counter and every RAM byte**. The port runs
twice: once called directly and once through the readable override, which is
how the native tick reaches it.

```
node_handler: 3 differential cases - PASS
```

The handler is an entry no ported code owns, so the test answers it through
the dispatcher's `missing` hook. The handler reads the frame it was given -
`r5` points at it - and answers a mix of its four argument words, so a port
that built the frame in the wrong order would answer something else and the
test would say so. The scenarios cover the plain case, a node that names
another handler and another float.

The test has teeth, and the mutations were checked:

* ignoring the float offset fails with the differing answer named (`v0`)
  **and** the differing `FR3` named (`v24`);
* swapping the object's and the node's words in the frame fails with the
  differing answer named (`v0`).

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
`0x8C0AB870` before the port is trusted in the native tick.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* The frame: `pr` at `S-4` and the five words from `S-24` to `S-8`, in the
  order the guest puts them.
* The float travels through `FR3`, so the FP registers are part of the
  contract.
* `r5` points at the frame's second word when the handler is called.
* The handler's address is the table's entry at the node's second word,
  scaled by four - and the node's second word is read *twice*: once for the
  frame and once for the table lookup.
* The calls carry the guest's own continuation address (`0x8C0AB898`). This
 * module does not use the `code_base` form, so the plain address is right
  and the shared `vf3_guest_call` helper can be used.

## The unknown

The values in the literal pool are not recoverable offline: they live in the
code image, which is under `extract/`. The pool says *where* the float sits
and *which* table the handlers come from, not what a node or an object is.
The port therefore reads the same addresses the guest reads, and what the
handler does with the frame stays open until the image is back.
