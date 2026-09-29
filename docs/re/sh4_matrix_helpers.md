# SH-4 matrix helper family and 0x8C09D452

## Helper model

`src/fight/sh4_matrix.c` models the observed FSCA/FTRV helper kernels at
`0x0C03C940`, `0x0C03C880`, and `0x0C03C6C0`. FTRV uses the XF matrix, performs
four double-precision products/sums per output vector, then rounds once to a
single-precision result under the captured RM=truncate mode. The FSCA lookup
contains 245 exact sine/cosine bit pairs for angles present in the paired
09D4-family captures. Other angles fail closed.

The helper replay covers 64 rows each for C940 and C880. Both pass full
register, RAM, and XF comparison. C6C0 passes 61 rows; three captures close
after caller unwind has begun and are skipped for this helper-only test. The
wrapper test below closes before C6C0 executes and checks its own complete
entry-to-transfer behavior.

## 0x8C09D452 boundary

The 46-byte wrapper saves three halfwords, calls C940 and C880, restores the
first halfword, and tail-jumps to C6C0. `tools/watch/vf3_d452_tail.txt` closes
the capture after the `0x8C09D47C` jump delay slot, before the downstream
kernel runs. The capture has 1,088 pairs, 512 unique register vectors, zero
unpaired exits, one 8 KiB stack window, and 512 XF input/output pairs.

`tests/d452_replay.c` composes C940 and C880, verifies the wrapper's register
state and stack stores, and checks the XF bank at the transfer boundary. It
passes all 512 paired cases. The model is bounded by the 245 captured FSCA
angles and claims no coverage for other inputs.

Reproduce the capture with:

```powershell
python tools/golden_batch.py --name d452_tail `
  --watch tools/watch/vf3_d452_tail.txt `
  --out extract/analysis/goldens_d452_tail `
  --run fight:extract/analysis/vf3_fight_keep.state:extract/analysis/vf3_play_actions2.txt:600 `
  --ramn 512 --max-samples 512
python tools/golden_extract_xf.py extract/analysis/golden_d452_tail_fight.bin `
  --pc 0x0c09d452 --out extract/analysis/goldens_d452_tail --max-samples 512
```
