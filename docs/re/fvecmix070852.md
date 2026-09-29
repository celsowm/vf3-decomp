# 0x8C070852 vector-add fragment

The 34-byte baseline slice at `0x8C070852` ends at `0x8C070874`. The paired
capture stops at that exact boundary: it spills FR0 through `R4-4`, loads the
frame and source triples, adds them with the fight FPSCR's round-toward-zero
mode, and completes the two stores at `R13+4` and `R13+8`. The third store at
`0x8C070874` belongs to the next inventory fragment. In the observed calls,
`R4-4` aliases the first frame-vector lane, so the FR0 spill is an input to the
first sum.

A fresh 600-frame fight capture found 469 entries and yielded 64 distinct
paired register+RAM cases at `0x8C070874`. All 64 pass, with no skipped rows.
The later `0x8C070874+` instructions and the `0x8C070888`/`0x8C0708B0` blocks
are outside this slice; this result does not claim the enclosing pipeline is
modeled.

Reproduce the capture and pair the fragment boundary with:

```powershell
python tools/golden_batch.py --name golden_070852_boundary_fix `
  --watch tools/watch/vf3_070852_boundary.txt `
  --out extract/analysis/goldens_070852_boundary `
  --ramn 64 --max-samples 64 --no-extract `
  --run fight:extract/analysis/vf3_fight_keep.state::600

python tools/pair_cases.py `
  extract/analysis/golden_golden_070852_boundary_fix_fight.bin `
  --entry 0x8c070852 --at 0x8c070874 `
  --out extract/analysis/pairs_070852_boundary/f_0c070852_boundary `
  --max 64
```

Replay with `build/vf3fvecmix070852.exe` or run the full `tools/verify_all.py`
gate.
