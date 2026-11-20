# native_strlen

Native port of the string length, **0x8C05342C**, as the plain-C leaf
`vf3_native_strlen` (`src/native/strlen.c`), in the same spirit as the other
`src/native/*` ports: a transcription of the readable guest port
`src/fight/small_leaves.c` (`vf3_strlen_entry`) onto the `vf3_native_aim`
context (flat RAM, register file).

## The function

A self-contained leaf (call-free, no FPU, no stack frame).  `r4` is the
string.  The body walks its bytes (each read as a **sign-extended 8-bit**
value) until the first zero, so:

* `r4` ends **one past the NUL**;
* `r3` is the widened NUL byte (0);
* `r5` is the length (the number of non-zero bytes before the NUL);
* `r0 = r5`;
* SR's T bit is **set** (the loop's final `cmp/eq`).

`r1`, `r2`, `r6`..`r15`, the stack pointer and `pr` are untouched.  The
return pops `pr` (the caller's return address).  A NUL embedded in the middle
of the buffer terminates the walk there (it is a C-string length), which the
"embedded NUL" scenario exercises.

## Proof

* **Differential** — `tests/strlen_native_replay.c` (the `vf3nativestrlen`
  target) runs the native leaf against the readable guest port on the same
  flat RAM and register file for 7 strings (a phrase, the empty string, a
  single char, `abc`, a string with an **embedded NUL**, 26 `a`'s, and
  `VF3tb`) and matches:
  * the output registers `r0/r3/r4/r5` and SR's T bit against the guest;
  * every untouched register equal to its entry value, plus `pr`/`r15`;
  * an **independent fixture model** that computes the length straight from
    the bytes, checks `r4` is `start + len + 1`, and checks the NUL byte
    landed in `r3`.
  The fixture seeds SR with T **clear** so the leaf must set it; a port that
  forgets the T write is caught.
* **Mutation gate** — `tests/strlen_native_mutations.json`, **8/8 caught**
  (`python tools/mutate.py --port src/native/strlen.c --exe
  build/vf3nativestrlen.exe --mutations tests/strlen_native_mutations.json
  --target vf3nativestrlen --keep-going`).

## Details the port keeps

* `r5` starts at **0** and counts only non-zero bytes before the NUL.
* `r4` advances **one** byte per read and ends past the NUL.
* `r3` is recorded **every iteration** as the widened byte (0 at the NUL),
  not left untouched.
* The loop breaks on `c == 0`.
* `r0` is a copy of `r5` (the length), and SR's T bit is set.

## Files

* `src/native/strlen.h` — the `vf3_native_strlen` declaration.
* `src/native/strlen.c` — the port.
* `tests/strlen_native_replay.c` — the differential test.
* `tests/strlen_native_mutations.json` — the mutation gate.
* `CMakeLists.txt` — `vf3nativestrlen` target.
