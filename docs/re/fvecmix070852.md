# 0x8C070852 vector-add fragment

The 34-byte baseline slice at `0x8C070852` falls through to the next
inventory fragment at `0x8C070878`. Its paired capture stops at that boundary
and models only the entry slice: spill FR0 through `R4-4`, load the frame and
source triples, add them with the fight FPSCR's round-toward-zero mode, write
the destination triple, and preserve the resulting pointer and FR registers.
In the observed calls, `R4-4` aliases the first frame-vector lane, so the FR0
spill is an input to the first sum.

A fresh 600-frame fight capture found 469 entries and yielded nine distinct
paired register+RAM cases at `0x8C070878`. All nine pass, with no skipped rows.
The later `0x8C070888` and `0x8C0708B0` blocks are outside this slice; this
result does not claim the enclosing pipeline is modeled.

Reproduce the capture and pair the fragment boundary with:

```powershell
python tools/golden_batch.py --name golden_070852_boundary `
  --watch tools/watch/vf3_070852_boundary.txt `
  --out extract/analysis/goldens_070852_boundary `
  --ramn 64 --max-samples 64 --no-extract `
  --run fight:extract/analysis/vf3_fight_keep.state::600

python tools/pair_cases.py `
  extract/analysis/golden_golden_070852_boundary_fight.bin `
  --entry 0x8c070852 --at 0x8c070878 `
  --out extract/analysis/pairs_070852_boundary/f_0c070852_boundary `
  --max 64
```

Replay with `build/vf3fvecmix070852.exe` or run the full `tools/verify_all.py`
gate.
