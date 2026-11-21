# native_terrain_flat

Native port of the flat-ground-height leaf **0x8C068DE4** (terrain_flat), as
the plain-C leaf `vf3_native_terrain_flat` (`src/native/terrain_flat.c`), in
the same spirit as the other `src/native/*` ports: a transcription of the
readable guest port `src/fight/terrain_height.c` (`vf3_terrain_flat_entry`)
onto the `vf3_native_aim` context (flat RAM, FR bank, register file).

## The function

A self-contained FP leaf (call-free, no stack frame): `r4` -> a 3-float normal
block, `fr4`/`fr5` = x/z.  It writes the up normal **(0, 1, 0)** to the block
and returns **0** in fr0 — or **-0.5** when |x| or |z| exceeds **6** (the
stage edge).  The two constants are read from the literal pool at
`0x8C068E5C` (6.0) and `0x8C068E60` (-0.5).

The fabs of fr4/fr5 is done by masking the sign bit off the float's bits
(and-imm style) exactly as the guest does.  The far-off compare (`|x| > 6 ||
|z| > 6`, short-circuiting) sets SR's **T bit** and, when true, loads the
-0.5 literal into fr4; otherwise fr4 = 0.

## Proof

* **Differential** — `tests/terrain_flat_native_replay.c` (the
  `vf3nativeterrainflat` target) runs the native leaf against the readable
  guest port over seven x/z pairs covering inside, exactly-on-edge and
  outside cases for each axis, on the same flat RAM and FR/register file, and
  matches:
  * the written normal block (0, 1, 0) byte for byte against the guest;
  * every FR value (fr0 = the result, fr3 = 1.0, fr4 = the result value,
    fr5 = `|z|`, fr6 = 6.0, fr7 = 0), the SR T bit, and the untouched
    registers;
  * an **independent fixture model** for the result (`-0.5` iff `|x|>6 ||
    |z|>6`).
  The literal pool is read by the guest at its 0x8C address (a ROM window)
  and by the native at its **0x0C mirror** inside the flat RAM — the same
  constants, as the other native ports do.
* **Mutation gate** — `tests/terrain_flat_native_mutations.json`, **7/7
  caught** (`python tools/mutate.py --port src/native/terrain_flat.c --exe
  build/vf3nativeterrainflat.exe --mutations
  tests/terrain_flat_native_mutations.json --target vf3nativeterrainflat
  --keep-going`).  The first `fabs` mutation (`& ~NEG_ZERO` -> `& 0x7FFFFFFF`)
  was a no-op — the two masks are bit-identical — and was replaced by a wrong-
  register swap that the inside/outside test can see.

## Details the port keeps

* `fabs` is done **on the float's bits**, not by calling fabsf — the guest
  and-masks the sign bit, and a port that used a different mask clears a
  different bit and flips a value across the 6.0 edge.
* The far-off test **short-circuits**: `|x| > 6` first, and only if false does
  it test `|z| > 6`.  A port that tested both unconditionally still gets the
  final boolean right in most cases but leaves a different **T bit** on the
  `|x| > 6` true path (the second comparison is never evaluated).
* The result value (0 or -0.5) travels in **fr4 and fr0** both; fr4 is fabs'd
  from the entry x first, so a port has to keep the copy before overwriting.
* The up normal writes are ordered x, y, z with the y = 1 store being the one
  a `1.0f` in fr3 feeds.

## Files

* `src/native/terrain_flat.h` — the `vf3_native_terrain_flat` declaration.
* `src/native/terrain_flat.c` — the port.
* `tests/terrain_flat_native_replay.c` — the differential test.
* `tests/terrain_flat_native_mutations.json` — the mutation gate.
* `CMakeLists.txt` — `vf3nativeterrainflat` target.
