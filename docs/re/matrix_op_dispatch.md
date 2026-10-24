# The matrix-op dispatcher (SH-4 0x8C035CE8 and 0x8C035C60)

A readable port of the fight engine's matrix-op dispatcher, and the evidence
for it.

## The function

`0x8C035CE8` runs the matrix operation the current node asks for.

The engine keeps the current node behind a global: the word at `0x8C035D60`
points at the node *pointer*, so the node itself is the word behind it. The
node names the operation to run in its word at `+0x50` - a plain function
pointer. The guest jumps to that pointer with its own `pr`, so the operation
runs in the caller's frame and returns straight to the caller's caller; the
matrix the operation works on is the caller's `r4` and travels untouched.

A node that is not there - the word behind the global is null - has no
operation to run. The guest answers `0` and returns.

The guest saves `r14` around the work and restores it before it jumps, so the
word it leaves on the stack is the one the original left.

The port: `src/fight/matrix_op_dispatch.c`, registered in
`src/fight/readable.c` as `matrix_op_dispatch`.

## The operations a node may name

The pointer in the node's word at `+0x50` is one of the matrix operations the
engine has. The translator enumerated them when it translated the jump: the
generated code switches on the pointer and calls the chain for each of the
eighteen entries it found in the image.

| entry | operation | entry | operation |
|---|---|---|---|
| `0x0C03B450` | `xform_point` | `0x0C03C610` | `matrix_invert_rigid` |
| `0x0C03B4B0` | `xform_vector` | `0x0C03C6C0` | `rotate_x` |
| `0x0C03B530` | `matrix_copy` | `0x0C03C880` | `rotate_y` |
| `0x0C03B620` | `matrix_store` | `0x0C03C940` | `rotate_z` |
| `0x0C03B820` | `xf_store` | `0x0C03C970` | `matrix_rotate_sc` |
| `0x0C03BD80` | `matrix_load` | `0x0C03CBD0` | `matrix_set_translation` |
| `0x0C03C0E0` | `matrix_concat` | `0x0C03CC60` | `matrix_translate_by` |
| `0x0C03C4A0` | `matrix_pop` | `0x0C03CC90` | `vec3_load` |
| `0x0C03C4F0` | `matrix_push` | `0x0C03CCB0` | `matrix_identity` |

Every one of them is already ported readably (`src/fight/matrix_lib.c`,
`src/fight/leaf_math.c`, `src/fight/matrix_extra.c`,
`src/fight/small_leaves.c`), so the dispatcher is the last piece that was
still machine-generated between the fight engine and the matrix library.

## The family

The node has three such words, and each of them has its own dispatcher. The
three are the same function with a different slot:

| entry | the node's word | module | state |
|---|---|---|---|
| `0x8C035C60` | `+0x38` | `next_adapters_0` | ported here (`matrix_op_dispatch_38`) |
| `0x8C035CBA` | `+0x44` | `next_adapters_0` | already ported as `vtable_trampoline` |
| `0x8C035CE8` | `+0x50` | `matrix_adapters` | ported here (`matrix_op_dispatch`) |

The `+0x38` and `+0x50` members are the same code, so one readable body
(`dispatch_node_op`) serves both; the `+0x44` member differs in two details:
the operation lands in `r1` instead of `r0`, and the guest leaves `r0` alone
for a node that is not there instead of answering `0`.

**Open item: the `vtable_trampoline` port does not match the translation.**
Two differences, both visible in the sources:

* It reads the global `0x8C0EA314` directly, where the translation reads the
  literal pool slot at `0x8C035D60` and dereferences *that*. The pool slot
  holds `0x8C0EA314` in the image (the native tick's trace prints that
  address for the sibling entry `0x8C035C60`), so the two agree in the game;
  they differ only in a synthetic RAM image. This port follows the
  translation and reads the pool slot.
* It does not restore `r14` from the stack. The guest has to: the function
  pushes `r14` and the `rts` pops the return address, so the `r14` has to be
  gone before the `rts` runs. The translation restores it (the translator
  folds the restore into the `rts` block), the port does not, and the port's
  own comment says the restore happens "in the jump's delay slot" without
  doing it.

The ledger marks `vtable_trampoline` as `unexercised`, so no differential
test covers it. This is worth checking against the oracle when the corpora
are back; nothing was changed here, because that port was verified against
the oracle once and the corpora that would settle it are gone (see
[artifact_gap](artifact_gap.md)).

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine
translation of the ROM: one label per guest PC, one C statement per executed
opcode, and the original opcode word in a comment. That makes them a faithful
disassembly of the function they implement, so a readable port can be written
against them without the ROM.

Three tools do the reading:

* `tools/adapter_dump.py <entry>` - prints a generated function as guest
  disassembly: the PC, the opcode word, a decoded mnemonic and the C the
  translator emitted for it.
* `tools/adapter_body.py <entry> --span N` - prints the raw generated source
  of a PC range, module by module. Several modules carry the same PC (the
  same function was captured in more than one campaign), and the router
  serves the first module in chain order that *owns* it, so the copies have
  to be compared before one is picked. This entry lives in `matrix_adapters.c`
  only.
* `tools/readable_gap.py --loops --overlap` - ranks the call-target entries
  that no readable port covers yet, and lists the readable ports that still
  have a generated twin.

The opcode words in the comments are the real ones, and `tools/sh4.py` (the
repo's complete SH-4 decoder) confirms the reading: `2fe6` is `mov.l
r14,@-r15`, `4f22` is `sts.l pr,@-r15`, `d439` is `mov.l @(228,pc),r4` (the
literal pool at `0x8C0369A4`), `2ee8` is `cmp/eq r14,r14`, `00ee` is `mov.l
@(r0,r14),r0` and `402b` is the jump to the operation.

`0x8C035CE8` was chosen from the call-target ranking: the captured fight
ticks really reach it, and its body is a single generated module.

## The evidence

`tests/matrix_op_dispatch_replay.c` runs the readable port and the retained
generated translation of the same function over five scenarios and compares
**the whole register file (the FP registers included), the return PC, the
failed PC, the out-of-window counter and every RAM byte**. The port runs
twice: once called directly and once through the readable override, which is
how the native tick reaches it. Both members of the family run the same
scenarios, so the test holds ten cases:

```
matrix_op_dispatch: 10 differential cases - PASS
```

The scenarios cover a node that is not there, a node that names the identity,
a node that names the load of a matrix, a node that names a transform of a
point, and a node that names a pointer no module owns.

The operation the node names is run by the chain in *both* runs, so its own
effect - the FP registers it writes, the point it stores - is part of the
comparison and not a free variable. The test matrix is a rotation about z, so
the transform raises no FP exception and the comparison stays about the
dispatcher.

The test has teeth: moving the node's operation field from `+0x50` to `+0x54`
and answering `1` instead of `0` for a missing node both make it fail, with
the differing registers named.

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
`0x8C035CE8` before the port is trusted in the native tick.

## One difference from the generated translation

The generated translation cannot know the pointer the node holds, so it
switches on it: the eighteen entries above call the chain, and anything else
goes to the module's own dispatch, which continues there if the module owns
the PC and fails with the pointer as the failed PC if it does not.

The readable port hands *every* pointer to the chain, which is what the guest
does - the guest jumps to the pointer, and the pointer is in another module's
range as easily as in this one's. The two agree for the eighteen operations,
for a pointer this module owns (the chain routes it to the same module) and
for a pointer nobody owns (both fail with the pointer as the failed PC).
They differ in one place only: a pointer that another module owns, where the
generated translation stops and the port runs it. That difference needs the
chain's `missing` hook to be visible, and that hook is a test-only construct
(`vf3_family_missing` is NULL outside tests).

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* The word `r14` is pushed on the stack and popped again, on both paths. It
  leaves its value in RAM, so the stack traffic is visible in the RAM
  comparison.
* `r3` holds the global that points at the node pointer when the dispatch
  ends.
* `r0` holds the operation pointer on the path that runs it, and `0` for a
  node that is not there.
* The T flag says whether the node was missing: set for a missing node, clear
  for a node that is there.
* The jump is a tail jump: the operation runs with the caller's `pr`, so it
  returns to the caller's caller and the dispatcher never comes back.