# native_negate_copy

Native port of the negate-copy, **0x8C072B02**, as the plain-C leaf
`vf3_native_negate_copy` (`src/native/negate_copy.c`), in the same spirit as
the other `src/native/*` ports: a transcription of the readable guest port
`src/fight/negate_copy.c` (`vf3_negate_copy_entry`) onto the `vf3_native_aim`
context (flat RAM, register file).

## The function

A self-contained leaf (call-free, no FPU, no stack frame).  `r5 -> { count,
src, dst }` — three words read from RAM.  Every entry copies six floats: the
first three as they are, the next three with the **sign flipped** (a `fneg`,
so a NaN keeps its payload and a zero becomes `-0`).

Although the readable routes each value through the FR bank, it only ever
holds the value as a **32-bit word**, so the sign flip is exactly the bitwise
xor `v ^ 0x80000000` and each stored word is the plain source byte (or its
negation).  In native form the whole body is **pure integer**.

After the loop the body leaves `r4 = src` (one past the last read), `r6 =
dst` (one past the last write), `r7 = count` (int32, `<= 0`), and SR's T bit
**clear** (the last `cmp/pl` was false).  `r5` and every other register are
untouched.  The return pops `pr` (the caller's return address).

## Proof

* **Differential** — `tests/negate_copy_native_replay.c` (the
  `vf3nativenegatecopy` target) runs the native leaf against the readable
  guest port on the same flat RAM and register file for 7 scenarios (1..5
  entries, zero, and a negative count) and matches:
  * the byte-for-byte RAM over the whole span
    (0x0c110000..0x0c160000, which covers the descriptor, the source and the
    destination);
  * the output registers `r4/r6/r7` and SR's T bit against the guest;
  * every untouched register equal to its entry value, plus `pr`/`r15`;
  * an **independent fixture model** that replays the copy straight from the
    source, with the second three words sign-flipped, and checks every
    destination word against it.
  The body reads/writes only in-bounds RAM and the OOB counter stays at zero.
* **Mutation gate** — `tests/negate_copy_native_mutations.json`, **9/9
  caught** (`python tools/mutate.py --port src/native/negate_copy.c --exe
  build/vf3nativenegatecopy.exe --mutations
  tests/negate_copy_native_mutations.json --target vf3nativenegatecopy
  --keep-going`).

## Details the port keeps

* The descriptor's three words are read from `[r5]`, `[r5+4]`, `[r5+8]` —
  count, src, dst respectively.
* The loop is **`while (count > 0)`** (signed): a zero or negative count
  copies nothing but still leaves `r7 = count`, `r4 = src`, `r6 = dst`.
* Each entry is exactly **six** words; the last three are sign-flipped with
  `^ 0x80000000`.
* `src`/`dst` advance by **4** bytes per word.
* `r7` is the (now `<= 0`) integer count, `r4`/`r6` are one past the last
  read/write.
* SR's T bit is **cleared** by the final comparison.

## Files

* `src/native/negate_copy.h` — the `vf3_native_negate_copy` declaration.
* `src/native/negate_copy.c` — the port.
* `tests/negate_copy_native_replay.c` — the differential test.
* `tests/negate_copy_native_mutations.json` — the mutation gate.
* `CMakeLists.txt` — `vf3nativenegatecopy` target.
