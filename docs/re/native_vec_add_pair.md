# native_vec_add_pair

Native port of the vector-add leaf **0x8C092A70** (vec_add_pair), as the
plain-C leaf `vf3_native_vec_add_pair` (`src/native/vec_add_pair.c`), in the
same spirit as the other `src/native/*` ports: a transcription of the
readable guest port `src/fight/vec_add_pair.c` (`vf3_vec_add_pair_entry`) onto
the `vf3_native_aim` context (flat RAM, FR bank, register file).

## The function

A self-contained FP leaf (call-free, uses a 12-byte frame to spill r5/r6/r7):
`r4` = object, `r5` = vector A (a 12-byte-stride array), `r6` = vector B,
`r7` = destination vector D (all x, y, z floats).

* Unless the global word at `0x0C29B868` carries bit `0x04000000` **and** the
  byte at `r4 + 97` is 11, `D += A + 24` (the vector 24 bytes into A — the
  third of A's 12-byte-stride array), component by component.
* Then, **unconditionally**, `D.y += B.y`.

When the first add runs, `r4` ends = D and `r5` = A + 36; when it is skipped,
`r4`/`r5` stay as they came in.  `r0` = 4, `r1` = B + 4, `r2` = D, `r3` = B
on exit, and r15 is restored.  The FR bank leaves fr0/fr1/fr2 = the D vector,
fr3/fr4/fr5 = the (A+24) vector (when the add ran), then the final `D.y +=
B.y` overwrites fr2 with the combined y and fr3 with the y addend (B.y) on
every path.

## Proof

* **Differential** — `tests/vec_add_pair_native_replay.c` (the
  `vf3nativevecaddpair` target) runs the native leaf against the readable
  guest port across three modes — gate clear (add runs), gate set but byte
  ≠ 11 (add still runs), and gate set **and** byte 11 (the skip) — on the
  same flat RAM and FR/register file, and matches:
  * the final registers (r0..r7, r15) including the add/skip-dependent
    r4/r5;
  * every FR value and the SR T bit;
  * the written D RAM byte for byte against an **independent fixture model**
    computed under the same toward-zero rounding.
  The gate lives at `0x0C29B868`, so the fixture's RAM window has to reach it
  (the first version's small window made the gate read out of bounds and the
  guest failed).
* **Mutation gate** — `tests/vec_add_pair_native_mutations.json`, **7/7
  caught** (`python tools/mutate.py --port src/native/vec_add_pair.c --exe
  build/vf3nativevecaddpair.exe --mutations
  tests/vec_add_pair_native_mutations.json --target vf3nativevecaddpair
  --keep-going`).

## Details the port keeps

* The float adds go through the round-toward-zero + FTZ wrapper.
* The two conditions gate the first add with **different T semantics**:
  `tst` sets T when the gate bit is **clear** and the byte compare sets it
  when the byte **equals** 11 — the port keeps both the same way the guest
  does, so the add/skip decision and the caller-visible T bit line up.
* The first add overwrites r4 and r5 (`r4 = D`, `r5 = A + 36`) — a port that
  keeps the entry r4/r5 misses the register contract on the add path.
* The final `D.y += B.y` is **unconditional** and clobbers fr2/fr3, so even a
  skipped path leaves those FR values as the result of the y-add.
* The A array has a **12-byte stride**, so "the vector 24 bytes into A" is the
  *third* 12-byte row, not the address `A + 24` taken as two 12-byte rows of a
  different stride.

## Files

* `src/native/vec_add_pair.h` — the `vf3_native_vec_add_pair` declaration.
* `src/native/vec_add_pair.c` — the port.
* `tests/vec_add_pair_native_replay.c` — the differential test.
* `tests/vec_add_pair_native_mutations.json` — the mutation gate.
* `CMakeLists.txt` — `vf3nativevecaddpair` target.
