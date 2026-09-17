# Game module map (source-anchored, M4-b)

Root authority: embedded dev paths `/pub/data3/vf3/naomi/c/*` in the binary:
`sound.c`, `stage.c`, `area_coli.c`, `rob_load.c`, `bj_load.c`, `pic_logic.c`,
`lrom.c` (bios-level), `vmsphys_.c` (VMU), plus the motion-file directory prefix
`/pub/data3/vf3/naomi/c/` immediately followed by MT*.BIN names.

## Named module anchors (applied in Ghidra)
| function | evidence | role |
|---|---|---|
| `mt_loader` 0x8C02DCEC | refs `#/MTJACLAU.BIN`-cluster strings | motion-file loader (jumptable tail) |
| `stage_load` 0x8C0B7302 | refs stage.c zone | stage init/load |
| `stage_update` 0x8C0B744C | refs stage.c zone | stage per-frame |
| `coli_run` 0x8C09AAE2 | refs area_coli.c zone | collision system runner |
| `texman_a..e` 0x8C0F061C-740 | refs "texture16MB" string | PVR texture pool manager |
| `bjload_run` 0x8C0CBC40 | refs bj_load.c + 5 struct-jsr sites | fighter-object loader/runner |
| `load_mt_*` 0x8C04BDA2.. | direct `.BIN` name reads | per-pair MT HUD loaders |

## Fight-engine landmarks (crosschecked by dispatch-topology)
- Switch-heavy dispatchers: f_8c07d368(256B), f_8c063f58(222B), f_8c02d0a0,
  f_8c071428, f_8c0516a8 → candidate scene/state managers.
- Task runners with 14-15 struct-dispatch sites: task_run_A/B/C.
- The fight scene flow (predicted): `bjload_run` -> `stage_update` per frame ->
  `coli_run` -> `texman_*` submits textures; motion via `mt_loader`.

## MT*.BIN motion files (91)
Structure: sparse offset table at +0, entries u32 ascending (first data at 0xE4
for MTJACLAU.BIN); zero entries = empty slots. Payload = keyframe/curve records
(placeholders until field-level parse).
