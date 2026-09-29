# Bootmix matrix-helper route at 0x8C0A77E2

## Captured boundaries

The 4,800-frame bootmix trace captures the 62-byte wrapper at
`0x8C0A77E2`, its 84-byte callee at `0x8C0955B0`, and the return/transfer
boundaries. It yields 64 paired register, RAM, and XF cases for each of the
wrapper routes and helper checkpoints. The wrapper's XF matrix is unchanged
across its return. The helper changes XF during its C880/C6C0 matrix calls.

The helper calls `0x0C03C4F0`, `0x0C03CCB0`, `0x0C03C940`, `0x0C03C880`,
`0x0C03C6C0`, and `0x0C03B620`, then tail-jumps to `0x0C03C4A0`. The captured
register and memory deltas are localized to the `0x0C19D2E4` queue state, the
helper stack frame, and the XF matrix. The existing C940/C880/C6C0 models are
relevant, but C4F0 and CCB0 setup behavior must be modeled before the complete
84-byte caller can pass replay. No coverage is credited for this route yet.

## Capture recipe

Capture the wrapper, its helper entry/return, and the wrapper's local return
path with:

```powershell
python tools/golden_batch.py --name closure_0a77e2 `
  --watch tools/watch/vf3_0a77e2_closure.txt `
  --out extract/analysis/goldens_0a77e2_closure `
  --run bootmix::tools/vf3_play_boot_mix.txt:4800 `
  --ramn 64 --max-samples 64 --no-extract
```

Capture the helper's internal steps with:

```powershell
python tools/golden_batch.py --name closure_0955b0 `
  --watch tools/watch/vf3_0955b0_steps.txt `
  --out extract/analysis/goldens_0955b0 `
  --run bootmix::tools/vf3_play_boot_mix.txt:4800 `
  --ramn 64 --max-samples 64 --no-extract
```

Pair the helper entry at `0x8C0955B0` with each step boundary
(`0x8C0955C2`, `0x8C0955C8`, `0x8C0955CE`, `0x8C0955D4`, `0x8C0955DA`,
`0x8C0955E0`, and `0x8C095600`) using `tools/pair_cases.py`. The current
capture yields 64 rows for each boundary.

`tools/pair_cases.py` now reads optional XF groups between the register and
RAM groups and writes aligned `.xfin.bin` / `.xfout.bin` sidecars. It was
checked against both this XF capture and the existing 070832 register/RAM
capture. The full `tools/verify_all.py` gate passes at 313/2398 rigorous
functions (13.1%), leaving 237 newly credited functions to reach 550/2398
(23.0%, a 10 percentage-point increase from the 310-function recalibration
baseline).
