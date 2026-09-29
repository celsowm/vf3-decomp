# 0x8C09F6DC helper closure

`0x8C09F6DC` is a 32-byte baseline loop. It calls `0x8C09F6FC` once per
element; the callee begins immediately after the caller's `rts` delay slot and
was not a baseline function entry. Treating `0x8C09F6DC` as a leaf would omit
the actual geometry/FPU work.

The callee was force-defined in the Ghidra project and decompiled to
`extract/analysis/decomp_9f6fc.txt`. Its single-precision path is large and
branch-heavy, so it remains unported. This forced function is analysis state,
not a coverage claim.

Reproducible capture:

- Watch file: `tools/watch/vf3_9f6fc.txt`
- States: `vf3_26.state` through `vf3_29.state`, 120 frames each
- Ignored output: `extract/analysis/goldens_9f6fc/`
- Result: 252 invocation pairs, 64 unique paired cases, 0 unpaired; two RAM
  windows cover the geometry buffers (`0x0C1F0000..0x0C23FFFF`) and stack
  (`0x0C31F800..0x0C31FFFF`). The capture marks exit RAM trusted.

Next port work must model `0x8C09F6FC`'s single-precision path first, then
`0x8C09F6DC`'s pointer stepping/count loop. Bind and count the caller only
after the helper and caller pass the existing register-plus-RAM replay gate.
