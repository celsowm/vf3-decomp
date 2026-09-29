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

The `0x8C070832` and `0x8C070852` entries remain unported. The `0x8C0708B0`
entry has a verified direct-transfer path, described below, but its alternate
branches still continue into the enclosing vector routine. Keep all three
entries out of the coverage ledger. Capture artifacts remain under ignored
`extract/analysis/`.

## 0x8C0708B0 direct tail path

The direct path at `0x8C0708B0` now has a C model through the transfer at
`0x8C070920`. It spills FR0, stores the first vector length in the `0xD0`
delay slot, computes the ordered FMUL/FMAC cross product, and reproduces the
final FIPR/FSQRT state. The raw 64-case capture initially appeared to leave
only eight R0 mismatches; inspection showed those calls branch around
`0x8C070920` and pair with the enclosing routine's later RTS instead. Separate
captures at `0x8C070952` and `0x8C070960` resolve only two cases each; the
remaining cases still fall through to that enclosing RTS.

`tools/select_fvecnorm070x_direct.py` filters cases to the observed
`0x0C070A64` transfer with unchanged PR. The direct subset passes **56/56**
paired register+RAM replays using `vf3fvecnorm070x_direct`. This is a partial
path check only: alternate branches and the full 208-byte body boundary are
not closed, so `0x8C0708B0` earns **no** rigorous coverage credit and remains
outside `portcheck.py` and the coverage ledger. Reproduce after the full
capture with:

```powershell
python tools/select_fvecnorm070x_direct.py `
  extract/analysis/goldens_070x_0920ram2/f_0c0708b0.cases `
  extract/analysis/goldens_070x_0920_direct
build/vf3fvecnorm070x_direct.exe
```
