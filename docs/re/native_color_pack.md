# native_color_pack

Native port of the color-pack, **0x8C03FB80**, as the plain-C leaf
`vf3_native_color_pack` (`src/native/color_pack.c`), in the same spirit as the
other `src/native/*` ports: a transcription of the readable guest port
`src/fight/geom_readable.c` (`vf3_color_pack_entry`) onto the `vf3_native_aim`
context (flat RAM, FR bank, register file, FPUL).

## The function

A self-contained FP leaf (call-free, no stack frame, no tail-transfer).
FR4..FR7 (`a, r, g, b`) are scaled by **255** (the constant read from the
literal pool at `0x0C03FC38`), converted to unsigned integers, clamped to 255
as unsigned, and packed `a:r:g:b` into **r0** (also left in **r4**).  r5..r7
keep the clamped r, g, b; **r1 = 0**, FPUL = the raw b-truncation, and SR's
**T bit = (raw[3] > 0xFF)**.  r2, r3, r8..r15, the stack pointer and pr are
untouched.

The float-to-int step is the SH-4's **`ftrc`** (toward-zero), and a value in
`[2^31, 2^32)` wraps through a **-2^32 bias** (read at `0x0C03FC40`) when the
scaled value exceeds the half range **2^31** (read at `0x0C03FC3C`).  The
native keeps the `ftrc` corner cases: NaN or `< -2^31` -> `0x80000000`,
`>= 2^31` -> `0x7fffffff`.

## Proof

* **Differential** — `tests/color_pack_native_replay.c` (the
  `vf3nativecolorpack` target) runs the native leaf against the readable
  guest port on the same flat RAM (the three pool constants) and FR bank for
  **8 scenarios** (plain, all-zero, all-one, negative channel, over-range,
  huge, **wrap boundary** at exactly 2^31, and **deep wrap** into the bias
  region) and matches:
  * the output registers `r0/r4/r5/r6/r7`, `r1`, FPUL and SR's T bit against
    the guest;
  * every FR-bank output the leaf writes (fr3..fr9) against the guest's;
  * every untouched register against its entry value;
  * an **independent fixture model** that recomputes the pack straight from
    the four channel floats with the same toward-zero scale and truncation.
  The fixture seeds SR with T **clear** so the leaf must set it properly, and
  seeds every scratch FR register (so an unintended FR write is caught).
* **Mutation gate** — `tests/color_pack_native_mutations.json`, **10/10
  caught** (`python tools/mutate.py --port src/native/color_pack.c --exe
  build/vf3nativecolorpack.exe --mutations
  tests/color_pack_native_mutations.json --target vf3nativecolorpack
  --keep-going`).  The two wrap-path mutations (`>` vs `>=` boundary, and the
  bias' sign) are only observable once a scenario drives the scaled value to
  exactly 2^31 / into the wrap region — that is why the "wrap boundary" and
  "deep wrap" scenarios exist.

## Details the port keeps

* The scale, half-range and bias are **read from the literal pool at run
  time** (`0x0C03FC38 / 3C / 40`), not baked in.
* The wrap condition is strictly **`>`** — a scaled value at exactly 2^31 is
  **not** wrapped (it truncates to `0x7fffffff`); `>=` would wrap it to
  `-2^31` (`0x80000000`), a different FPUL and T result.
* The pack runs **most-significant byte first** (`a:r:g:b` from bits 31 down
  to 0); an LSB-first accumulation reverses the word.
* FPUL = the **raw** (pre-clamp) b-truncation, and SR's T bit records the
  last `cmp/hi` (`raw[3] > 0xFF`).

## Files

* `src/native/color_pack.h` — the `vf3_native_color_pack` declaration.
* `src/native/color_pack.c` — the port.
* `tests/color_pack_native_replay.c` — the differential test.
* `tests/color_pack_native_mutations.json` — the mutation gate.
* `CMakeLists.txt` — `vf3nativecolorpack` target.
