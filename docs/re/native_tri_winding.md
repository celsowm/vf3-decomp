# native_tri_winding

Native port of the screen-space triangle winding test, **0x8C068F92**, as the
plain-C leaf `vf3_native_tri_winding` (`src/native/tri_winding.c`), in the
same spirit as the other `src/native/*` ports: a transcription of the readable
guest port `src/fight/geom_readable.c` (`vf3_tri_winding_entry`) onto the
`vf3_native_aim` context (FR bank, register file).

## The function

A **pure-FR, call-free, no-stack, no-RAM** leaf.  The three points arrive as
`(x,y)` pairs in `FR4/FR5`, `FR6/FR7` and `FR8/FR9`.  With
`d01 = p1-p0` and `d12 = p2-p1` it forms

    area = d01.y * d12.x - d01.x * d12.y

and returns **2** for area > 0 (counter-clockwise / positive), **1** for
area == 0 (degenerate, collinear) and **4** otherwise (negative or NaN).
Only **r0** is a result; every other caller-saved register (including the FR
bank) is scratch.  `pr` and the stack pointer are untouched, and SR's T bit
is **preserved** (the readable writes no comparison into it on this leaf).

The FP arithmetic goes through the round-toward-zero + FTZ wrappers the other
FP native ports use (the corpus FPSCR `0x00024001` sets RM=truncate and FTZ),
so the stored floats match the guest bit for bit.

## Proof

* **Differential** — `tests/tri_winding_native_replay.c` (the
  `vf3nativetriwinding` target) runs the native leaf against the readable
  guest port on the same FR bank and register file for six point sets and
  matches:
  * r0 against the guest, and against an **independent fixture model** (the
    same algebra at native float precision); the six sets cover a
    counter-clockwise triangle, a clockwise one, a collinear/degenerate one, a
    NaN input (negative arm) and two large-scale ones; a seventh
    **mutation-sensitive** set is included so every operand/op swap flips the
    classification;
  * every register other than r0 equal to its entry value, `pr`/`r15`
    preserved, and SR's T bit **unchanged**.
  The fixture seeds SR with T **clear** to prove the leaf preserves it.
* **Mutation gate** — `tests/tri_winding_native_mutations.json`, **9/9
  caught** (`python tools/mutate.py --port src/native/tri_winding.c --exe
  build/vf3nativetriwinding.exe --mutations
  tests/tri_winding_native_mutations.json --target vf3nativetriwinding
  --keep-going`).

## Details the port keeps

* The cross product is `d01.y*d12.x - d01.x*d12.y` — the *minus* is what
  decides the winding, and the operand order of both products matters.
* `area > 0` is **positive first** (`2`), `area == 0` comes next (`1`), and
  everything else (negative or NaN) is `4`.
* Only `r0` is a result; SR's T bit is not disturbed.

## Files

* `src/native/tri_winding.h` — the `vf3_native_tri_winding` declaration.
* `src/native/tri_winding.c` — the port.
* `tests/tri_winding_native_replay.c` — the differential test.
* `tests/tri_winding_native_mutations.json` — the mutation gate.
* `CMakeLists.txt` — `vf3nativetriwinding` target.
