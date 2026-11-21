# native pointer_chase (0x8C035264)

`src/native/pointer_chase.c` (`vf3_native_pointer_chase`) is the plain-C port
of the readable `src/fight/pointer_chase.c` (`vf3_pointer_chase_entry`), proved
by `tests/pointer_chase_native_replay.c` (6 differential cases) and the
mutation gate `tests/pointer_chase_native_mutations.json` (4/4 caught).

## The function

A self-contained integer leaf (call-free, no FP, no stack frame).  It chases a
chain of pointers read out of the flat RAM:

- `r3 = [0x0c03548c]`  - the literal pool holds a pointer to an object,
- `r0 = [r3]`          - dereference it; the object's first word is itself a
  pointer,
- `r0 = [r0 + 40]`     - the field at offset 40 of the pointed-to object,
- tail-transfer to pr.

Every path is a **tail transfer** to pr (the caller's return address), so the
native port leaves `pr` untouched and simply returns.

## What the port has to keep

- **It is a three-level chase**, not a two-level one: the pool gives a
  pointer to an object whose *first word* is a second pointer, and the field
  is at `(second pointer) + 40`.  The first version of this test's fixture
  laid out only two levels, so the guest dereferenced a zero word and read at
  `0x28` (out of window) - the corrected fixture carries all three.
- **`r0` = the field, `r3` = the pool-loaded pointer**; `r4`, `r5`, `r15`,
  `SR` (no comparisons) and `pr` are all untouched.
- **Byte-exact reads** through `vf3_aim_u32`, with no `>>2` word aliasing.

## Everything else

The leaf has no comparisons, no FPU, no stack and no branches, so the only
observable variation is the field value; the mutation set covers the pool
address, the field offset, the second dereference and the final result.
