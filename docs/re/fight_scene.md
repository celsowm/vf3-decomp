# Fight-scene dispatcher — evidence ledger (M5-a supplement, M6)

## Candidates re-scored from live traces

fntables_1ST_READ.csv reports these jump-table hosts in the 0x8C02-0x8C07 block.
Now overlaid with trace_fn_first_seen (run1+run2):

| function | size | first seen (run2) | hits | veredict |
|---|---|---|---|---|
| **f_8c063f58** | 222B | 100,665,172 | 299,055 | **likely the scene/state manager**: enters right at game-image start, hits continuously every ~4K instructions (== frame-rate) |
| f_8c0516a8 | 196B | — | 0 | unused in boot/menu |
| f_8c07d368 | 256B | — | 0 | unused in boot/menu |
| task_run_A (0x8C05E64E) | ? | 100,665,151 | 21 | fires once (scene init) |
| stage_load(0x8C0B7302) | ? | 136,608,074 | 58 | called at demo/attract phase start (fight views) |

## Next M6 goal
Dump the state machine by NOPing to step through each menubar item; or hook
the IP.BIN IPLoader+GDFS to let savestates at fight start. Manual analysis
shows the blocking region always runs f_8c063f58 in a loop, so it's the "tick".
