# native_word_copy

Native port of the word copy, **0x8C042F08**, as the plain-C leaf
`vf3_native_word_copy` (`src/native/word_copy.c`), in the same spirit as the
other `src/native/*` ports: a transcription of the readable guest port
`src/fight/word_copy.c` (`vf3_word_copy_entry`) onto the `vf3_native_aim`
context (flat RAM, register file).

## The function

A self-contained, call-free, no-FPU leaf.  It copies `r0` bytes (a multiple
of 4, at most 64) from `r2` to `r1`, one word at a time, and returns 0
(refusing, writing nothing) when the byte count is not a multiple of 4 or is
more than 64.

The original is an **unrolled chain** entered through a jump table indexed by
the byte count; it **software-pipelines** the copy through two registers
(`r3` and `r0`).  The chain assumes the word waiting in the pipeline is in
`r3` when the number of words is odd; when it is even the word waiting is
`r0` itself, which still holds the count *minus 4* (the jump leaves `r0`
decremented).  That quirk is kept: **for an even word count the highest
destination word receives `r0`, not the source word.**

`r3` is saved to `[sp-4]` and restored; `r0` ends as the last word loaded
into it.  `r1` (dst), `r2` (src), `r4`..`r15` and `pr` are untouched.  The
return pops `pr` (the caller's return address).

## Proof

* **Differential** — `tests/word_copy_native_replay.c` (the
  `vf3nativewordcopy` target) runs the native leaf against the readable guest
  port on the same flat RAM and register file for 10 scenarios (1, 2, 3, 4,
  5, 16, 28 bytes — the odd/even pipeline shapes — plus the three refusals:
  not a multiple of 4, too big, zero) and matches:
  * the byte-for-byte RAM over the whole span the two could touch
    (0x0c1f0000..0x0c230000);
  * the output registers `r0` and `r3` against the guest, and every untouched
    register equal to its entry value, plus `pr`/`r15` unchanged;
  * the stack frame — `r3` pushed to `[sp0-4]`;
  * an **independent fixture model** that computes the copied words straight
    from the source, including the even-count "highest word is `r0`" quirk,
    and, for the refusal cases, verifies nothing was written and no `r3` push
    happened.
  The body reads/writes only in-bounds RAM and the fixture keeps the OOB
  counter at zero (except for the `r3` push at `sp0-4`, which is inside the
  window).
* **Mutation gate** — `tests/word_copy_native_mutations.json`, **8/8 caught**
  (`python tools/mutate.py --port src/native/word_copy.c --exe
  build/vf3nativewordcopy.exe --mutations
  tests/word_copy_native_mutations.json --target vf3nativewordcopy
  --keep-going`).

## Details the port keeps

* The refusal test is `!(bytes % 4) && words <= 16`, applied **before** any
  write or `r3` push.
* The pipeline starts by loading the **last** source word into `r3` (the jump
  table's delay slot) and leaves `r0 = bytes - 4`.
* The word that lands in the highest destination slot depends on the parity
  of the word count: `r3` for odd, `r0` for even — the even case is **not** a
  copy of the source's last word.
* `r3` is saved to `[sp0-4]` and **restored**, regardless of the copy.
* `r0` ends as the last word loaded into the pipeline, not the count.

## Files

* `src/native/word_copy.h` — the `vf3_native_word_copy` declaration.
* `src/native/word_copy.c` — the port.
* `tests/word_copy_native_replay.c` — the differential test.
* `tests/word_copy_native_mutations.json` — the mutation gate.
* `CMakeLists.txt` — `vf3nativewordcopy` target.
