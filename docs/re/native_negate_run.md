# native_negate_run

Native port of the negate-run, **0x8C09D408**, as the plain-C leaf
`vf3_native_negate_run` (`src/native/negate_run.c`), in the same spirit as
the other `src/native/*` ports: a transcription of the readable guest port
`src/fight/small_leaves.c` (`vf3_negate_run_entry`) onto the `vf3_native_aim`
context (flat RAM, register file).

## The function

A self-contained leaf (call-free, no stack frame).  It negates **7 + 14**
floats in place:

* the first run takes every float at `r4+8, r4+20, ...` — 7 floats, stride
  **12**;
* the second run restarts **8 bytes below the first run's end** — at
  `r4+84, r4+96, ...` (stride 12), 14 floats.

Each negation is a **sign-bit flip** (`fneg`, so a NaN keeps its payload and
a zero becomes `-0`), so the body is pure integer in native form.  After the
run: `r4` is one past the last written float, `r5` is 0 (the loop counter
ran out), and SR's T bit is set.  `r0`..`r3`, `r6`..`r15`, the stack pointer
and `pr` are untouched.  The return pops `pr`.

The readable's `plain_fpu` gate (which refuses to run when the FPU is not
usable in the harness) is a harness concern — the body is a pure sign flip
with no real float width — so the native leaf always runs.

## Proof

* **Differential** — `tests/negate_run_native_replay.c` (the
  `vf3nativenegaterun` target) runs the native leaf against the readable
  guest port on the same flat RAM and register file for two base offsets and
  matches:
  * the byte-for-byte RAM over the whole span (0x0c110000..0x0c11c000);
  * the output registers `r4`, `r5` and SR's T bit against the guest;
  * every untouched register equal to its entry value, plus `pr`/`r15`;
  * an **independent fixture model** — a pre-run snapshot of the RAM, with
    each touched word checked equal to its pre-run value sign-flipped, on
    both 12-stride grids.
  The fixture seeds SR with T **clear** and one seeded float already
  negative, to prove the leaf clears it.
* **Mutation gate** — `tests/negate_run_native_mutations.json`, **8/8 caught**
  (`python tools/mutate.py --port src/native/negate_run.c --exe
  build/vf3nativenegaterun.exe --mutations
  tests/negate_run_native_mutations.json --target vf3nativenegaterun
  --keep-going`).

## Details the port keeps

* The first run's start is **`r4 + 8`**, the stride is **12**.
* The second run starts **8 below** the first run's end (so its grid is
  offset 4 bytes from the first run's in the vec3 array) — this must not be
  skipped.
* The two run counts are **7** and **14**.
* `r4` ends **one past the last written float** (0x100 past the base), `r5`
  is 0, and SR's T bit is set.

## Files

* `src/native/negate_run.h` — the `vf3_native_negate_run` declaration.
* `src/native/negate_run.c` — the port.
* `tests/negate_run_native_replay.c` — the differential test.
* `tests/negate_run_native_mutations.json` — the mutation gate.
* `CMakeLists.txt` — `vf3nativenegaterun` target.
