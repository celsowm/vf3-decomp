# native_vec_shift

Native port of the vec-shift, **0x8C0748E0**, as the plain-C leaf
`vf3_native_vec_shift` (`src/native/vec_shift.c`), in the same spirit as the
other `src/native/*` ports: a transcription of the readable guest port
`src/fight/vec_shift.c` (`vf3_vec_shift_entry`) onto the `vf3_native_aim`
context (flat RAM, FR bank, register file).

## The function

A self-contained FP leaf (call-free, no stack frame, no tail-transfer).
`r4 -> object`.  The offset `(x, y, z)` lives at `+0x13A8 / +0x13AC / +0x13B0`
and is added to the vec3 at `+0x1488`; the point-record pointer at `+0x138C`
then walks `0x150` bytes (28 vec3s, 12 bytes each) and every vec3 on the way
gets the same offset added.

No frame, nothing saved.  After the run: **r0 = 8**, **r5 = r6** = the end
pointer (one past the last point record), and SR's T bit is set.  `r1..r4`,
`r7..r15`, the stack pointer and `pr` are untouched.

The FP adds go through the round-toward-zero + FTZ wrappers the other FP
native ports use (the corpus FPSCR `0x00024001` sets RM=truncate and FTZ), so
the stored floats match the guest bit for bit.

## Proof

* **Differential** — `tests/vec_shift_native_replay.c` (the `vf3nativevecshift`
  target) runs the native leaf against the readable guest port on the same
  flat RAM and register file for two object bases and matches:
  * the byte-for-byte RAM over the whole span (0x0c118000..0x0c11c000);
  * the output registers `r0`, `r5`, `r6` and SR's T bit against the guest;
  * every untouched register equal to its entry value, plus `pr`/`r15`;
  * an **independent fixture model** — a pre-run snapshot, with the offset
    added (under the same round-toward-zero) to the position and to every
    one of the 28 point vec3s, checked against the post-run values.
  The fixture seeds SR with T **clear** so the leaf must set it.
* **Mutation gate** — `tests/vec_shift_native_mutations.json`, **10/10
  caught** (`python tools/mutate.py --port src/native/vec_shift.c --exe
  build/vf3nativevecshift.exe --mutations
  tests/vec_shift_native_mutations.json --target vf3nativevecshift
  --keep-going`).

## Details the port keeps

* The offset is read into **FR4/FR5/FR6** from `+0x13A8`; the same three
  registers drive every add (x -> FR4, y -> FR5, z -> FR6).
* The position gets the offset **first**, then the 28 point records walk from
  the pointer at `+0x138C` for `0x150` bytes with a **12-byte** stride.
* `r0 = 8`, `r5 = r6` = one past the last point, and SR's T bit set.
* The FP add is **round-toward-zero + FTZ**, not C's round-to-nearest — this
  is why the fixture model had to round the same way (the plain model missed
  on the values whose sum sits exactly between two floats).

## Files

* `src/native/vec_shift.h` — the `vf3_native_vec_shift` declaration.
* `src/native/vec_shift.c` — the port.
* `tests/vec_shift_native_replay.c` — the differential test.
* `tests/vec_shift_native_mutations.json` — the mutation gate.
* `CMakeLists.txt` — `vf3nativevecshift` target.
