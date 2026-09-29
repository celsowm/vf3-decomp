# Candidate review: 0x8C071668

`0x8C071668` is a 44-byte baseline fragment with 17K recorded hits and a
nominal `rts`. It looked attractive in the small-function queue, but its main
path ends in a tail jump to `0x8C071400`, which lies inside the neighboring
baseline entry `0x8C0713F0`. That shared path continues through FPU code in
`0x8C071428`; modeling the fragment alone would miss most of the observed
register effects.

The forced Ghidra body is at `extract/analysis/decomp_71668.txt`; the shared
FPU entry analysis is at `extract/analysis/decomp_71428.txt`. The fresh paired
capture gives evidence for the fragment and stack, but does not close the
shared FPU body.

Reproduce the capture with:

```powershell
$vf3Path='C:\msys64\ucrt64\bin;C:\msys64\usr\bin;'+$env:PATH
$env:PATH=$vf3Path
python tools/golden_batch.py --name port_71668_ram --watch tools/watch/vf3_71668_ram.txt --out extract/analysis/goldens_71668_ram --ramn 64 --max-samples 64 --run s26:tools/emu/flycast-build/data/vf3_26.state::120 --run s27:tools/emu/flycast-build/data/vf3_27.state::120 --run s28:tools/emu/flycast-build/data/vf3_28.state::120 --run s29:tools/emu/flycast-build/data/vf3_29.state::120
```

Result: 1,400 invocation pairs, 64 unique paired cases, and 0 unpaired cases.
RAM windows cover `0x0C2B2400..0x0C2B27D4` and
`0x0C31F840..0x0C31F9B0`. Observed stores are confined to stack memory, while
the data window remains unchanged. This capture is evidence for future work;
it is not a port or a coverage claim.
