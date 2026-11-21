# native_atan_table

Native port of the atan-through-table, **0x8C069624**, as the plain-C leaf
`vf3_native_atan_table` (`src/native/atan_table.c`), in the same spirit as
the other `src/native/*` ports: a transcription of the readable guest port
`src/fight/atan_table.c` (`vf3_atan_table_entry`) onto the `vf3_native_aim`
context (flat RAM — the halfword table —, FR bank, register file, FPUL).

## The function

A self-contained integer/FP leaf (call-free, no stack frame, no
tail-transfer).  FR4 = x, FR5 = y.  Returns r0 = 0 for the zero vector.
Otherwise the smaller absolute value is divided by the larger and scaled to
index the **halfword table at 0x0C0EAF60** (the angle of that slope, up to
0x2000).  The octant is then folded back: `0x4000 - angle` when |y| < |x| is
false, and by the signs of y and x the result is `-angle`, `0x8000 - angle`,
`angle - 0x8000` or the angle itself.

Leaves r4 = the signed angle, r0 = the same, **FPUL = the table index**, and
fr2 (the scaled slope), fr3 = 0, fr6 = |y|, fr7 = |x|, fr8 = the
smaller/larger ratio, as the original does.  r1..r3, all of r5..r15 except
those, the stack pointer and pr are untouched.  SR's T bit is untouched (the
leaf computes no comparison into T).

## Proof

* **Differential** — `tests/atan_table_native_replay.c` (the
  `vf3nativeatantable` target) runs the native leaf against the readable
  guest port on the same flat RAM (the atan table) for **12 scenarios**
  covering all four quadrants, both |y|<|x| and |y|>|x| folds, the axes, the
  diagonal and the zero vector, and matches:
  * the output registers r0/r4, FPUL and SR's T bit against the guest;
  * every FR-bank output the leaf writes (fr2, fr3, fr6, fr7, fr8) and every
    untouched register/FR value;
  * an **independent fixture model** that recomputes the angle straight from
    the ratio and octant (with the same toward-zero rounding on the ratio,
    the scale and the index).
  The fixture seeds SR with T **set** so the test proves the leaf leaves it
  alone.
* **Mutation gate** — `tests/atan_table_native_mutations.json`, **10/10
  caught** (`python tools/mutate.py --port src/native/atan_table.c --exe
  build/vf3nativeatantable.exe --mutations
  tests/atan_table_native_mutations.json --target vf3nativeatantable
  --keep-going`).

## Details the port keeps

* The two absolute values are computed by **sign-flipping the bits**
  (`^ 0x80000000`) when 0 > the value, not by fabsf — this is how the SH-4
  does it and it is observable in fr6/fr7.
* The ratio is the **smaller / larger** of |x| and |y| (always <= 1), chosen
  by an `if` on which absolute value is bigger; the divide rounds
  toward-zero.
* The table index is `ftrc(|ratio| * SCALE)` pinned in **FPUL**, and the
  table is read as a **sign-extended halfword** at `TABLE + index*2`.
* The octant fold: `0x4000 - angle` when |x| > |y|, then by signs — y < 0
  with x < 0 adds 0x8000, y < 0 with x >= 0 does `0x8000 - angle`, y >= 0
  with x < 0 negates, else the angle itself.
* The **zero vector returns r0 = 0 early**; r4 is *not* written on that path
  (the test checks r0 on it, not r4).

## Files

* `src/native/atan_table.h` — the `vf3_native_atan_table` declaration.
* `src/native/atan_table.c` — the port.
* `tests/atan_table_native_replay.c` — the differential test.
* `tests/atan_table_native_mutations.json` — the mutation gate.
* `CMakeLists.txt` — `vf3nativeatantable` target.
