# native color_unpack (0x8C0562E0)

`src/native/color_unpack.c` (`vf3_native_color_unpack`) is the plain-C port
of the readable `src/fight/color_unpack.c` (`vf3_color_unpack_entry`), proved
by `tests/color_unpack_native_replay.c` (5 differential cases) and the
mutation gate `tests/color_unpack_native_mutations.json` (10/10 caught).

## The function

A call-free FP leaf with no guest callees and no stack frame - the only
control transfer is the final tail transfer to `pr`.  It reads four halfwords
off the record (`r4`), scales the fixed 3-float vector at `0x0C19D5C8` by the
factor at `0x0C056508` (three FPSCR-aware multiplies), packs the first two
halfwords (halfword 2 over halfword 1) into `GBR + 0x60`, and converts each
halfword's two bytes to floats (via FPUL and the `FLOAT` conversion) and
scales them.  Six floats are stored at `0x0C16B82C` and downwards (three),
then 28 bytes back up for the last three.  Out: `r4 += 12`, `r1` = the last
store address, results in FR0..FR2, the scale in FR4..FR7.

## What the port has to keep

- **The FLOAT conversions and every multiply are FPSCR-aware** (rounding
  `fpscr & 1`, FTZ when bit `0x40000`), same wrapper as the other FP leaves.
  The `FLOAT` converts FPUL (a masked byte) via `(float)(int32_t)`, so a byte
  with the top bit set (`0x80`) becomes a *negative* float.
- **The halfwords are sign-extended** (`sext16`) and the byte splits use an
  arithmetic `>> 8` before masking with `& 0xFF`.
- **The packed word is `(hw2 << 16) | (hw1 & 0xFFFF)`** and is written to
  `GBR + 0x60`; GBR comes from the seed (a register, not a call or device).
- **The six output floats are stored pre-decrementing from `0x0C16B82C`**
  (three stores down, then `r1 += 28`, then the wrapped last three), which is
  part of the contract the RAM diff checks.

## Everything else

`color_unpack` was a genuinely call-free, un-nativized leaf.  Its only
register beyond the FR/FPUL bank is GBR, so porting it added one `gbr` field
to the shared `vf3_native_aim` struct (zeroed by the test seeds and unused by
the other leaves).
