# M13 — front-to-fight capture battery (2026-09-22)

## Method
Modified harness (`tools/emu/flycast`, RE fork):
- vf3script F-suffixed commands (`KEYF/SAVEF/AICAF/MEMF/EXITF`) run on the
  emulator *frame* clock — immune to dynarec vs wall-clock skew (the reason
  the first scripted navigation silently failed: ms-clock keys fired at 8×
  intended time).
- `EXIT(F)` now actually terminates the process (quit-request flag polled by
  winmain loop; root cause of the 9h zombie flycast).
- maxFrames default stays 1200 unless `VF3_PLAY` is set (72000).

## Runs
1. `vf3_play_f2f.txt` (fresh boot, dynarec): START/A ladder at f900–2400. The
   keys navigated the title→menu→arcade-select fine. States saved @
   f2700/3300/5400. **Never reached fight**: the interpreter probes on those
   states show loader/attract-region PCs only (0x8C03/0x8C04 segments).
2. `vf3_play_f2f2.txt`: long soak to f54000, dense `AICAF` ladder — the raw
   evidence this milestone wanted (see below). States vf3_20..vf3_29 on disk.
3. Classification (interpreter + watch `pc 0x8C073C2A` ring / `pc
   0x8C068F86` sd-lookup): **vf3_7 is fight-live** (28 ring + 67 sd-lookup
   probe hits / 12 frames), vf3_5/6/25/26/27/28 are not. Pre-fight state =
   vf3_6 retained for future probes.

## AICA ladder — the voice-reset boundary (THE evidence)
Consecutive-dump diff of the `aica_load_*` series (extract/analysis/shots/):

| window | changed | span | meaning |
|---|---|---|---|
| f3500→4400 | 301,717 B | 0x0..0x1FFFFF | menu→load full kit swap |
| f5000→5600 | 255,510 B | 0x44..0x86E4D | fight setup (voices sub-drive) |
| f12200–14600 | 2× ~147 KB | bounded | stage dynamics (attract/VS loops) |
| **f24200→25400** | **1,222,259 B** | **0x086E54..0x1CC29D** | **THE fight BGM kit write** |
| n/a | ~10–300 B/win | 0x44..0xCF5D | steady streaming window |

The 1.22 MB write is contiguous from 0x086E54 to ~0x1CC29D — a single block
write = `drv_set_dreset_ns`-class kit load: **AICA layout starts driver+
voices at 0x0; the rotatable song/sample kit region begins at 0x086E54**.
Steady-state streaming sits at ring buffer 0x00A0B4..0x00CF5D (~12 KB),
plus control regs at 0x44..0xF8. Song/voice "reset" = full-block overwrite,
not incremental updates.

## Answers handed to M17
- BGM voice-reset boundary offset = **0x86E54** (kit start; varies by stage,
  re-measure per stage).
- Steady-state SFX/music mixer activity never exits the low ~12 KB streaming
  window — the fight hot loop *streams continuously into AICA*; a per-frame
  codec handoff is plausible (see M17 RELOAD map).
- Next audio probe: pair `AICAF` dumps with a state-save on both sides of
  the kit write (f24xxx point) → MEMDUMP the SH-4 side queue holding the
  `BGM_*` name being streamed.

## Cost notes / lessons (for the next campaign runner)
- Interpreter probes are ~30–60× real time; captured states resume in
  0x0Cxxxxx alias — watch masked against `pc|0x80000000` already handles this.
- Fresh-boot navigation needs KEY sizing; `vf3_6` (pre-fight GUI state) plus
  probes is the cheapest "are we in fight yet?" oracle (ring-ring hit).
