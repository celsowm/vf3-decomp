# native_count_leading

Native port of the leading-zero count, **0x8C0769C6**, as the self-contained
plain-C leaf `vf3_native_count_leading` (`src/native/count_leading.c`), in the
same spirit as the other `src/native/*` ports: a transcription of the readable
guest port `src/fight/count_leading.c` (`vf3_count_leading_entry`) onto the
`vf3_native_aim` context (flat RAM, register file).

## The function

A self-contained leaf (call-free, no FPU, no stack frame, **no RAM**).  `r4` is
a word.  A probe bit starts at bit 31 and walks down; `r6` counts the bits
passed, `r5` is the probe left over and `r3` a copy of `r4`:

```
for (;;) {
    if (word & probe) { t = 0; break; }   // tst r5,r3 found a set bit
    probe >>= 1;  ++count;                // walk down one bit
    if (probe == 0) { t = 1; break; }     // tst r5,r5 ran off the end
}
```

The answer is `r0` (== `count`): the number of high bits clear before the
first set one, with **32 for an all-zero word**.  `r3 = word`, `r5 = the
leftover probe`, `r6 = count`, and SR's T bit is the loop's exit test (set
when the loop ran off the end, clear when a set bit was found).  `r4` and the
stack pointer and every other register are untouched.  The return pops `pr`
(the caller's return address).

## Proof

* **Differential** — `tests/count_leading_native_replay.c` (the
  `vf3nativecountleading` target) runs the native leaf against the readable
  guest port on the same register file for 9 scenarios (zero -> 32, top bit ->
  0, a mid bit, all-ones -> 0, one low bit -> 31, one middle bit, two high
  bits, many-zeros, and a random pattern) and matches:
  * the output registers `r0/r3/r5/r6` and SR's T bit against the guest;
  * every untouched register (`r1, r2, r4, r7..r14, r15`) equal to its entry
    value, and `pr`/`r15` unchanged;
  * an **independent fixture model** that computes `31 - highest_set_bit` (32
    for zero) straight from the word.
  The body reads no RAM and the fixture keeps the OOB counter at zero.
* **Mutation gate** — `tests/count_leading_native_mutations.json`, **8/8 caught**
  (`python tools/mutate.py --port src/native/count_leading.c --exe
  build/vf3nativecountleading.exe --mutations
  tests/count_leading_native_mutations.json --target vf3nativecountleading
  --keep-going`).

## Details the port keeps

* The probe starts at **bit 31** (`0x80000000`) and walks **right**, so the
  answer is the count of high bits clear before the first set one.
* **Zero** walks the probe all the way off the end (`probe == 0`), giving **32**
  and leaving SR's T bit **set**; a word with a set bit stops with T clear.
* `r3` is a **copy of r4's word**, not the count.
* `r6` and `r0` both carry the count.
* The T bit the guest leaves is the loop's exit test — observable because the
  test seeds SR with T set and checks it after the run.

## Files

* `src/native/count_leading.h` — the `vf3_native_count_leading` declaration.
* `src/native/count_leading.c` — the port.
* `tests/count_leading_native_replay.c` — the differential test.
* `tests/count_leading_native_mutations.json` — the mutation gate.
* `CMakeLists.txt` — `vf3nativecountleading` target.
