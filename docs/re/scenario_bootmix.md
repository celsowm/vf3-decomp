# Boot and action capture

This scenario diversifies the fight-state inputs with a clean boot, several
menu-confirm pulses, and a varied 1P action sequence. The checked-in input
recipe is `tools/vf3_play_boot_mix.txt`; the capture watches the existing
Campaign A/B PC list in `tools/watch/vf3_ab_reg.txt`.

Reproduce with the local retail image and a 4,800-frame cap:

```powershell
python tools/golden_batch.py --name bootmix `
  --watch tools/watch/vf3_ab_reg.txt `
  --out extract/analysis/goldens_bootmix `
  --run bootmix::tools/vf3_play_boot_mix.txt:4800 `
  --ramn 16 --max-samples 16
```

The 2026-09-29 capture ran 4,740 frames before the scripted exit and produced
71 paired register captures for baseline entries absent from the port/SDK
ledger. Eight of those entries were not present in either of the two
fight-state action captures: `0x8C0A77E2`, `0x8C068C72`, `0x8C039B1A`,
`0x8C09132E`, `0x8C08B204`, `0x8C0AC252`, `0x8C09575C`, and `0x8C0750BE`.
Four of these had only one or two samples; all are still leads, not coverage.

This pass captured registers only. It does not establish RAM effects, full
function boundaries, or complete input-path coverage. Keep the rigorous
baseline count unchanged until targeted RAM-window captures and readable C
replays pass the normal port gate. The binary capture and extracted goldens
remain under ignored `extract/analysis/`.

## Paired follow-up (2026-09-29)

`tools/watch/vf3_bootmix_new8.txt` repeats the same scenario for the eight
entries with a 16 KiB stack window and XF snapshots. Reproduce with:

```powershell
python tools/golden_batch.py --name bootmix_new8 `
  --watch tools/watch/vf3_bootmix_new8.txt `
  --out extract/analysis/goldens_bootmix_new8 `
  --run bootmix::tools/vf3_play_boot_mix.txt:4800 `
  --ramn 64 --max-samples 64
```

The 116-second run produced paired register, stack-RAM, and XF records for all
eight entries with zero unpaired exits. Unique cases were: `0x8C039B1A` 1,
`0x8C068C72` 1, `0x8C0750BE` 28, `0x8C08B204` 64, `0x8C09132E` 2,
`0x8C09575C` 1, `0x8C0A77E2` 64, and `0x8C0AC252` 64. The watched 16 KiB
window captures stack effects only; these records do not bound object or
global writes. The three broad cases remain helper-heavy and need targeted
data-window capture before they are useful for a counted port. No coverage
credit is added by this capture.
