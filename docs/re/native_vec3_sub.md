# native_vec3_sub

Native port of the vector-difference leaf **0x8C03CEE0** (vec3_sub), as the
plain-C leaf `vf3_native_vec3_sub` (`src/native/vec3_sub.c`), in the same spirit
as the other `src/native/*` ports: a transcription of the readable guest port
`src/fight/small_leaves.c` (`vf3_vec3_sub_entry`) onto the `vf3_native_aim`
context (flat RAM, FR bank, register file).

## The function

A self-contained FP leaf (call-free, no stack frame) that computes
`r4[0..2] = r5[0..2] - r6[0..2]` component-wise.  It reads the two source
vectors (r5 and r6) and stores the three differences at r4.  r4, r5 and r6
each **advance 8 bytes** (only two of each pointer's three `mov.l @Rn+,` steps
increment, so the pointers finish two words on, not three).  The FR bank
finishes with the differences in **fr0/fr1/fr2** and the subtracted vector's
components in **fr4/fr5/fr6** — the SH-4's `fsub` takes `FRdest -= FRsrc` and
leaves both operands where they were.

## Proof

* **Differential** — `tests/vec3_sub_native_replay.c` (the `vf3nativevec3sub`
  target) runs the native leaf against the readable guest port on the same
  flat RAM and FR/register file and matches:
  * the three differences written to r4, byte for byte, against an
    **independent fixture model** (`1.25 - 0.5`, `-3.5 - 2.0`, `7.0 - -1.25`)
    computed under the same toward-zero rounding;
  * the output registers (r4/r5/r6 advanced by 8, all other registers
    untouched);
  * the FR-bank outputs (fr0/fr1/fr2 = the differences, fr4/fr5/fr6 = the
    source-2 components) and every untouched FR value.
  The sources at r5/r6 are checked untouched (the "99" seeds that would
  survive a mis-place store are caught by the RAM check).
* **Mutation gate** — `tests/vec3_sub_native_mutations.json`, **7/7 caught**
  (`python tools/mutate.py --port src/native/vec3_sub.c --exe
  build/vf3nativevec3sub.exe --mutations
  tests/vec3_sub_native_mutations.json --target vf3nativevec3sub
  --keep-going`).

## Details the port keeps

* The float subtractions go through the round-toward-zero + FTZ wrapper (the
  corpus FPSCR 0x00024001 is in force), so the stored floats match the guest
  bit for bit.
* `fsub` is **destructive** on its first operand: the guest's
  `FSUB(0,4)`/`FSUB(1,5)`/`FSUB(2,6)` each overwrite fr0/fr1/fr2 with the
  difference, while fr4/fr5/fr6 keep the source-2 components — the port models
  this exactly.
* The pointers advance by **8**, not 12: the third load of each source has no
  post-increment in the original, so r4/r5/r6 finish two words (not three) on.
  A port that advances by 12 writes the difference one word too high and r4
  ends wrong.

## Files

* `src/native/vec3_sub.h` — the `vf3_native_vec3_sub` declaration.
* `src/native/vec3_sub.c` — the port.
* `tests/vec3_sub_native_replay.c` — the differential test.
* `tests/vec3_sub_native_mutations.json` — the mutation gate.
* `CMakeLists.txt` — `vf3nativevec3sub` target.
