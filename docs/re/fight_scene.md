# Fight-scene dispatcher — evidence ledger (M5-a)

Goal: identify the CD entry path into the fight round state-machine.

## Direct-driver bottom line
The binary's struct-dispatch model defeats full-local-call walking; probes of
candidates decompiled into corrupted regions (data interleaving) so structure
arguments must be used instead of code reading.

## Candidates (by switch-table size + adjacent evidence)
| fn | size | status |
|---|---|---|
| f_8c07d368 | 256B | leading switch host; TASK-core candidate |
| f_8c063f58 | 222B | calls unknown +4x via fns; frame-work candidate |
| f_8c0516a8 | 196B | unpacks params struct, unrecovered jumptable |
| f_8c02d0a0 | 184B | adjacent MT-string zone, stage candidate |

## Confirmed named engine fns (module-anchors, M4)
- mt_loader 0x8C02DCEC — pulls MTJACLAU.BIN-style names
- stage_load 0x8C0B7302 / stage_update 0x8C0B744C — stage
- coli_run 0x8C09AAE2 — collision
- texman_a..e 0x8C0F061C-740 — PVR texture memory
- bjload_run 0x8C0CBC40 — body-jacket loader runner (dispatch-rich)

## Next evidence steps (M6)
- eCAM hook: trace fn execution order under DemonCAST/redream, dump the
  live task-dispatch table from RAM (0x8C0CBCxx per our map) into the
  workflow, bridging static→dynamic decisively.
- Ghidra CFG-splitter rewrite for the DSGLH zones.
