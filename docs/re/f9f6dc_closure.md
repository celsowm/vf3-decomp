# 0x8C09F6DC helper closure

`0x8C09F6DC` is a 32-byte baseline loop. It calls `0x8C09F6FC` once per
element; the callee begins immediately after the caller's `rts` delay slot and
was not a baseline function entry. Treating `0x8C09F6DC` as a leaf would omit
the actual geometry/FPU work.

The callee was force-defined in the Ghidra project and decompiled to
`extract/analysis/decomp_9f6fc.txt`. The C mirror lives in
`src/fight/f9f6fc.c`; it models the observed single-precision clipping path,
FPU flags, helper stack save, and three output stores. Its 64 paired
register+RAM captures replay exactly. The helper is a closure unit and is not
counted as a baseline function.

Reproducible capture:

- Watch file: `tools/watch/vf3_9f6fc.txt`
- States: `vf3_26.state` through `vf3_29.state`, 120 frames each
- Ignored output: `extract/analysis/goldens_9f6fc_full/`
- Result: 252 invocation pairs, 64 unique paired cases, 0 unpaired; two RAM
  windows cover the geometry buffers (`0x0C1F0000..0x0C23FFFF`) and stack
  (`0x0C31F800..0x0C31FFFF`). The capture marks exit RAM trusted.

Caller capture:

- Watch file: `tools/watch/vf3_9f6dc.txt`
- Same four fight states and frame range
- Ignored output: `extract/analysis/goldens_9f6dc_full/`
- Result: 18 paired register+RAM cases, no unpaired cases; the loop calls the
  helper 14 times per case and captures the geometry plus stack windows.

`src/fight/f9f6dc.c` models pointer stepping, the `cmp/pl` T flag, delayed
branch increment, and saved-register restoration. Its 18 cases replay exactly.
The baseline caller is now bound in `tools/golden_bindings.json` and counted in
`docs/decomp_status.csv`; it raises rigorous coverage by one function.
