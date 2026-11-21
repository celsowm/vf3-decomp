# native_vec_offset

Native ports of the two offset-adders, **0x8C074702** (vec_offset) and
**0x8C074854** (vec_offset3), as the plain-C leaves `vf3_native_vec_offset`
and `vf3_native_vec_offset3` (`src/native/vec_offset.c`), in the same spirit
as the other `src/native/*` ports: transcriptions of the readable guest ports
`src/fight/vec_offset.c` (`vf3_vec_offset_entry`) and `src/fight/vec_offset3.c`
(`vf3_vec_offset3_entry`) onto the `vf3_native_aim` context (flat RAM, FR
bank, register file).

## The functions

Self-contained FP leaves (call-free, no stack frame) that add a stored offset
to a record's own position and to every point of a list.

* **vec_offset** (0x8C074702): r4 = record.  The offset is the two floats at
  +0x13A8 (x) and +0x13B0 (z).  The record's own position at +0x1488 /
  +0x1490 gets it added, then the 0x150 bytes of 12-byte points that the
  pointer at +0x138C names each get the same offset on x (+0) and z (+8).
  Leaves r5 = one past the list, r6 = the same (the list end), r0 = 8 (a
  non-empty list), SR's **T bit set**.
* **vec_offset3** (0x8C074854): r4 = record.  The offset is the three floats
  at +0x1488 .. +0x1490.  The record's own vector at +0x10 .. +0x18 gets it
  added, then the 25 points of 64 bytes each at +0x180 get it added at
  +0x30 / +0x34 / +0x38.  Leaves r0 = 56, r5/r6 = one past the list, SR's
  T bit set.

## Proof

* **Differential** — `tests/vec_offset_native_replay.c` (the
  `vf3nativevecoffset` target) runs both native leaves against the readable
  guest ports on the same flat RAM (the record structures and the pointed-to
  lists) and matches:
  * the RAM the leaf wrote byte for byte (the record's own
    position/vector fields and the whole list);
  * the output registers r0/r5/r6, r4 preserved, SR's T bit, and every
    untouched register/FR value;
  * an **independent fixture model** that recomputes every point from the
    seed values plus the offset (the leaf modifies the RAM in place, so the
    model has to derive the expectation from the seed constants, not read the
    already-modified RAM back — the first version of the model added the
    offset a second time and "failed" even though the native was right).
  The fixture seeds SR with T **clear** so the leaves must set it.
* **Mutation gate** — `tests/vec_offset_native_mutations.json`, **10/10
  caught** (`python tools/mutate.py --port src/native/vec_offset.c --exe
  build/vf3nativevecoffset.exe --mutations
  tests/vec_offset_native_mutations.json --target vf3nativevecoffset
  --keep-going`).

## Details the port keeps

* The offset floats and the list pointers are read through the record at r4
  at the original's exact offsets (a wrong +4 flips which of two adjacent
  fields is read).
* The float adds go through the round-toward-zero + FTZ wrapper (the corpus
  FPSCR 0x00024001 is in force), so the stored floats match the guest bit for
  bit.
* The loop terminates by comparing each point's address against the list end
  (base + bytes) with **SR's T bit set** from the equality, exactly as the
  SH-4's `cmp/eq` leaves it — the test's fixtures make the loop non-empty so
  both the position and list writes are exercised.
* The leaves are **no-stack**: r4 and the untouched registers are preserved
  (the leaves read r15 nowhere).

## Files

* `src/native/vec_offset.h` — the `vf3_native_vec_offset` /
  `vf3_native_vec_offset3` declarations.
* `src/native/vec_offset.c` — the ports.
* `tests/vec_offset_native_replay.c` — the differential test.
* `tests/vec_offset_native_mutations.json` — the mutation gate.
* `CMakeLists.txt` — `vf3nativevecoffset` target.
