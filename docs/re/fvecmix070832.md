# 0x8C070832 vector-add fragment

The 32-byte baseline slice at `0x8C070832` ends at the next inventory entry,
`0x8C070852`. It spills FR0, loads two three-float vectors from the frame,
adds corresponding lanes using the fight FPSCR's round-toward-zero mode, and
reaches the boundary after the first two predecrement stores. The third store
is the first instruction of `0x8C070852` and is outside this port.

A 600-frame fight capture produced 469 entry/boundary pairs and 64 distinct
register+RAM cases. All 64 pass with zero skipped cases. The watch includes the
stack/vector regions touched by the slice.

Reproduce from the repository root:

```powershell
python tools/golden_batch.py --name golden_070832_boundary `
  --watch tools/watch/vf3_070832_boundary.txt `
  --out extract/analysis/goldens_070832_boundary `
  --ramn 64 --max-samples 64 --no-extract `
  --run fight:extract/analysis/vf3_fight_keep.state::600

python tools/pair_cases.py `
  extract/analysis/golden_golden_070832_boundary_fight.bin `
  --entry 0x8c070832 --at 0x8c070852 `
  --out extract/analysis/pairs_070832_boundary/f_0c070832_boundary `
  --max 64
```

Replay with `build/vf3fvecmix070832.exe` or run `python tools/verify_all.py`.
