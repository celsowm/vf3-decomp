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

The `0x8C070832` and `0x8C070852` entries remain unported. The
`0x8C0708B0` entry was later closed at all four observed transfer boundaries;
it is now gated and credited in the coverage ledger. Capture artifacts remain
under ignored `extract/analysis/`.

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
paired register+RAM replays using `vf3fvecnorm070x_direct`. That direct-only
subset was not enough for credit; a chronological capture was needed to keep
all alternate routes paired with their own invocation.

```powershell
python tools/select_fvecnorm070x_direct.py `
  extract/analysis/goldens_070x_0920ram2/f_0c0708b0.cases `
  extract/analysis/goldens_070x_0920_direct
build/vf3fvecnorm070x_direct.exe
```

A raw chronological capture at `0x8C0708B0` entry resolves the route counts
without relying on `exitpc`'s persistent arm: the first 64 entry snapshots
reached `0x8C070920` 56 times, `0x8C070952` twice, `0x8C070960` twice, and
`0x8C07099A` four times. This confirms the alternate paths are real and that
some route snapshots previously combined by separate `exitpc` captures came
from different invocations. The watch recipe is `tools/watch/vf3_070x_chrono.txt`;
the raw trace is intentionally kept in ignored `extract/analysis/`. This is
route evidence only: the complete entry-to-return register/RAM pairs for the
alternate routes and the 208-byte body are still open, so coverage remains
unchanged.

## Transfer-site follow-up (2026-09-29)

`tools/watch/vf3_070x_boundary.txt` captures entry RAM plus the same six windows
at all four transfer PCs. Reproduce the raw chronological trace with:

```powershell
python tools/golden_batch.py --name 070xboundary `
  --watch tools/watch/vf3_070x_boundary.txt `
  --out extract/analysis/goldens_070x_boundary `
  --run fight:extract/analysis/vf3_fight_keep.state::180 `
  --ramn 64 --max-samples 64 --no-extract
```

Pairing each of the first 64 entry snapshots to its first transfer before the
next entry confirms 56 calls at `0x8C070920`, 2 at `0x8C070952`, 2 at
`0x8C070960`, and 4 at `0x8C07099A`. The raw trace was converted into
entry-to-transfer register/RAM cases under ignored `extract/analysis/`.

The expanded C model now passes **64/64** chronological register+RAM cases
across all six windows. The four routes are 56 transfers at `0x8C070920`, two
at `0x8C070952`, two at `0x8C070960`, and four normalized transfers at
`0x8C07099A`.

The remaining one-bit FR0 mismatch traced to the normalization route. Its
entry `fr0` spill overwrites `[SP+68]` before FIPR reads the vector. With that
store included, one FIPR result still needed FPSCR.RM=1 truncation rather than
round-to-nearest. The next FSRRA output then feeds a separate FMUL. The local
trace captured four input/output pairs across the normalized cases; the C
model uses those exact results and rejects any other FSRRA input so an
uncaptured case cannot silently pass. Reproduce the intermediate capture with:

```powershell
python tools/golden_batch.py --name fpu070x_fsrra `
  --watch tools/watch/vf3_070x_fsrra.txt `
  --out extract/analysis/goldens_070x_fsrra `
  --run fight:extract/analysis/vf3_fight_keep.state::180 `
  --ramn 64 --max-samples 64 --no-extract
```

`build/vf3fvecnorm070x.exe` replays the full
`extract/analysis/goldens_070x_boundary_cases/f_0c0708b0_boundary.cases` set.
This closes the observed 208-byte body boundary and earns one baseline
function in `docs/decomp_status.csv`.
