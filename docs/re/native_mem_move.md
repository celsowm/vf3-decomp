# native mem_move (0x8C043018)

`src/native/mem_move.c` (`vf3_native_mem_move`) is the plain-C port of the
readable `src/fight/leaf_math.c` (`vf3_mem_move_entry`), proved by
`tests/mem_move_native_replay.c` and the mutation gate
`tests/mem_move_native_mutations.json`.

## The function

A self-contained integer leaf (call-free, no stack frame): `r4` = destination,
`r5` = source, `r6` = byte count.  It copies `count` bytes from src to dst,
overlap-safe - forward when `dst < src`, backward otherwise, a no-op when
`dst == src`.  It leaves `r0 = dst` and `SR.T` set; nothing else in the
register file is read or written.

## What the port has to keep

- **Byte-exact guest-address arithmetic.**  The flat RAM is indexed by byte
  offset (`addr - a->ram_base`), so unaligned byte reads/writes are exact -
  there is no `>>2` word aliasing here.
- **The overlap direction.**  `dst < src` copies forward; `dst >= src`
  (overlap) copies backward so a destination write never clobbers a source
  byte a later read still needs.  `dst == src` is a no-op that still leaves
  `r0 = dst` and `SR.T` set.
- **`r0 = dst` and `SR.T` set** on every path.

## Two unobservable things

- **The `dst != src` guard is unobservable**: copying to the same location is
  a no-op either way, so a port that always copies (or never special-cases
  equality) produces the same bytes.  It is covered indirectly by the
  direction selection (which must not touch the result) and the doc, not by a
  dedicated mutation.
- **Forward vs backward when `dst < src` is unobservable**: with the source
  base strictly above the destination base and both advancing in the same
  direction, a given destination slot is always `src - dst` below its source
  slot, so neither a forward nor a backward byte walk can read an
  already-overwritten source byte - both give identical bytes.  The backward
  direction only *matters* (and is only provable) when `dst > src` with
  overlap, which the `mm_backward_*` and direction-flip mutations exercise.

## Proof

`tests/mem_move_native_replay.c` seeds the same RAM, runs the readable guest
on one copy and the native port on another, and checks each against an
independent reference (`memmove`) model of the destination region over nine
cases: forward non-overlap, backward overlap (both sizes), the
`dst == src` no-op, forward overlap, a single byte, zero bytes, a large
forward copy and a large backward-overlapping copy.  It also compares the
native's `r0` and `SR.T` against the guest's.

## Mutation gate

`tests/mem_move_native_mutations.json`: `8/8` caught - both wrong-destination
mutations (forward and backward offset by one), the count-minus-one loop,
the wrong-source offset, a wrong `r0` return, a cleared `SR.T`, the
forward-loop skipping its first byte, and the direction condition flipped.
