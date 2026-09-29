# 070x vector pipeline tail boundary

The earlier captures for `0x8C070832`, `0x8C070852`, and `0x8C0708B0` paired
at the later `0x8C06F948` return, after multiple downstream FPU blocks. A first
`exitpc` guess at `0x8C0708D4` produced the same late state because that transfer
site was not reached on this fight path.

`tools/watch/vf3_070x_exitpc.txt` now stops all three entries at the observed
indirect jump at `0x8C070920`, before its target `0x0C070A64` runs. Reproduce
with the saved fight state:

```powershell
python tools/golden_batch.py --name fpu070x_0920ram2 `
  --watch tools/watch/vf3_070x_exitpc.txt `
  --out extract/analysis/goldens_070x_0920ram2 `
  --run fight:extract/analysis/vf3_fight_keep.state::180 `
  --ramn 64 --max-samples 64
```

The capture yielded 64 unique paired cases for each entry, with zero unpaired
exits. For `0x8C070832`, `0x8C070852`, and `0x8C0708B0`, XF input and output
were identical in all 64 cases. The new windows cover the stack, vector source
arrays, and object memory touched before the transfer.

This is a useful boundary, but it is not a port yet. The existing
`fvecmix2_replay` still diverges from the captured object RAM writes on this
boundary (for example, object-window byte `+0x404` in case 1). The C skeleton
also skips FPU-produced stores, so neither the RAM nor register behavior is
closed. Keep all three entries out of the coverage ledger until the arithmetic
and writes are modeled and replayed. Capture artifacts remain under ignored
`extract/analysis/`.
