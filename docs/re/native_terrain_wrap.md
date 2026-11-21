# native_terrain_wrap

Native port of the terrain-wrap leaf **0x8C068D54** (terrain_wrap), as the
plain-C leaf `vf3_native_terrain_wrap` (`src/native/terrain_wrap.c`), in the
same spirit as the other `src/native/*` ports: a transcription of the readable
guest port `src/fight/terrain_height.c` (`vf3_terrain_wrap_entry`) onto the
`vf3_native_aim` context (flat RAM, FR bank, register file).

## The function

A self-contained FP leaf (call-free, no stack frame): `r4` = stage type,
`r5` → x, `r6` → z (floats).

* **type 2/7** — `x *= 0.769`, `z *= 0.769` (LIT_SCALE `0x8C068E50`).
* **type 13** — `x` and `z` are folded into a 10-unit repeating cell: take
  `n = trunc(v * 0.1)`, round half-away to an *even* count of cells, then
  `v -= n * 10`.  The shared `fold_axis` step does it for the count in a
  register (r4 for x, r7 for z) against a stored float.
* **every other type** — `x`/`z` left alone.

The float arithmetic goes through the round-toward-zero + FTZ wrapper and the
trunc / int conversions use the SH-4's toward-zero float-to-int, matching the
corpus FPSCR 0x00024001 (RM = truncate).

## Proof

* **Differential** — `tests/terrain_wrap_native_replay.c` (the
  `vf3nativeterrainwrap` target) runs the native leaf against the readable
  guest port across ten cases covering all three stage families — scale
  (type 2/7), fold (type 13, including values inside/outside the unit cell and
  counts that truncate to zero), and leave-alone (types 1 and 0) — on the same
  flat RAM and FR/register file, and matches:
  * the written x/z RAM byte for byte against the guest;
  * every FR value, FPUL, the SR T bit and all of r0..r15 (the fold_axis step
    clobbers r1/r2/r3/r4/r7, so the register comparison is against the guest,
    which is the better oracle);
  * an **independent fixture model** for each family (toward-zero scale, and
    the half-away-to-even fold).
  The literal pool is read by the guest at its 0x8C address (a ROM window) and
  by the native at its **0x0C mirror** inside the flat RAM.
* **Mutation gate** — `tests/terrain_wrap_native_mutations.json`, **8/8
  caught** (`python tools/mutate.py --port src/native/terrain_wrap.c --exe
  build/vf3nativeterrainwrap.exe --mutations
  tests/terrain_wrap_native_mutations.json --target vf3nativeterrainwrap
  --keep-going`).

## Details the port keeps

* The two stage tests (`type == 2 || type == 7` and `type == 13`) decide
  between the three families; a port that misses type 7 silently leaves that
  stage unscaled.
* The truncation of `v * 0.1` and the int conversions are toward-zero, and the
  `v -= n * 10` subtraction is through the toward-zero wrapper — not C's
  default rounding.
* `fold_axis` makes the count **even** (adding or subtracting 1 when odd)
  before scaling by ten; a port that skips the evenization folds into the
  wrong cell for odd truncations.
* The fold's early return when the count is zero leaves F(2)/FR untouched for
  that axis.
* The x axis folds through r4, the z axis through r7; the two addresses are
  captured before the first fold modifies r4.

## Files

* `src/native/terrain_wrap.h` — the `vf3_native_terrain_wrap` declaration.
* `src/native/terrain_wrap.c` — the port.
* `tests/terrain_wrap_native_replay.c` — the differential test.
* `tests/terrain_wrap_native_mutations.json` — the mutation gate.
* `CMakeLists.txt` — `vf3nativeterrainwrap` target.
