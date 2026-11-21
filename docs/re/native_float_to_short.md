# native_float_to_short

Native port of the float-to-short, **0x8C09D590**, as the plain-C leaf
`vf3_native_float_to_short` (`src/native/float_to_short.c`), in the same
spirit as the other `src/native/*` ports: a transcription of the readable
guest port `src/fight/small_leaves.c` (`vf3_float_to_short_entry`) onto the
`vf3_native_aim` context (flat RAM, register file, FR bank, FPUL).

## The function

A self-contained leaf (call-free, no stack frame).  It reads **42 floats** out
of the object at `r4+0x1D58` (stride 4), truncates each toward zero to a
32-bit integer (`ftrc`), narrows it to a signed 16-bit value and stores it as
a halfword at `r4+0x1F50` (stride 2).

The `ftrc` corner cases are the SH-4's: a NaN or a value less than `-2^31`
gives `0x80000000`, a value at or above `2^31` gives `0x7fffffff`, else the
truncated value.  The truncation rides in `FPUL` (and is copied into the
loop-local `r7`, narrowed to int16, for the store).

After the run: `r4` is 0 (the counter ran out), `r5` is `r4+0x1F50+84` (one
past the last halfword), `r6` is `r4+0x1D58+168` (one past the last float),
`r7` is the last truncated value narrowed to int16, and SR's T bit is set.
`r0`..`r3`, `r8`..`r15`, the stack pointer and `pr` are untouched.  The
return pops `pr`.

The readable's `plain_fpu` gate (which refuses to run when the FPU is not
usable in the harness) is a harness concern — the body only truncates — so the
native leaf always runs.

## Proof

* **Differential** — `tests/float_to_short_native_replay.c` (the
  `vf3nativefloattoshort` target) runs the native leaf against the readable
  guest port on the same flat RAM and register file for two object bases and
  matches:
  * the byte-for-byte RAM over the whole span (0x0c118000..0x0c11c000);
  * the output registers `r4`, `r5`, `r6`, `r7`, `FPUL` and SR's T bit
    against the guest;
  * every untouched register equal to its entry value, plus `pr`/`r15`;
  * an **independent fixture model** — each destination halfword checked equal
    to trunc(source float), narrowed to int16, computed straight from the
    source floats.
  The 42 source floats are a spread that exercises truncation, negatives,
  values that overflow int16 (so the narrow is observable), a NaN and a huge
  value.  The fixture seeds SR with T **clear** so the leaf must set it.
* **Mutation gate** — `tests/float_to_short_native_mutations.json`, **8/8
  caught** (`python tools/mutate.py --port src/native/float_to_short.c --exe
  build/vf3nativefloattoshort.exe --mutations
  tests/float_to_short_native_mutations.json --target vf3nativefloattoshort
  --keep-going`).

One mutation is **genuinely unobservable** and is left out, with the reason
documented: changing the loop's `r7` to skip the `(int16_t)` narrow
(`no_int16_narrow`).  The loop-local `r7` is only ever consumed by the
`(uint16_t)` halfword store, which keeps the low 16 bits whether the value was
narrowed first or not, so the two are bit-identical for every store.  The
final `r7` output is derived from `FPUL` separately and is gated by its own
`r7_from_wrong` mutation (which the overflowing last source float makes
observable).

## Details the port keeps

* The source run starts at **`r4 + 0x1D58`**, stride **4**, 42 floats.
* The destination run starts at **`r4 + 0x1F50`**, stride **2**, 42 halfwords.
* The count is **42**.
* The truncation is **toward zero** with the SH-4 corner cases, not C's
  undefined-conversion table and not a round.
* Each stored value is **narrowed to int16** (sign-extended) so values that
  overflow int16 wrap, which the corpus' `0x461c4000` (15000-ish) and the
  fixture's `0x4788c000` (70000) prove.
* `FPUL` carries the last truncated value; `r7` its int16 narrow; `r4 = 0`,
  `r5`/`r6` one past their runs; SR's T bit set.

## Files

* `src/native/float_to_short.h` — the `vf3_native_float_to_short`
  declaration.
* `src/native/float_to_short.c` — the port.
* `tests/float_to_short_native_replay.c` — the differential test.
* `tests/float_to_short_native_mutations.json` — the mutation gate.
* `CMakeLists.txt` — `vf3nativefloattoshort` target.
