# Run 1 (trace_boot3, 1200 frames) 

- **IP.BIN (0x8C008000)**: 0..96.5M records, mostly spin waiting on vblank tick.
- **Game image (0x8C010200+)** kicks in at 96.6M.
- Within 427M instrs: 594 distinct functions reached. Boot/menu only.

# Run 2 (trace_long, 4000 frames —~66 s) 

- **1.48B instructions**, 686 distinct functions.
- stage_load (0x8C0B7302) first seen at 136.6M — attract/demo engage.
- fight-region functions 0x8C069xxx cluster dominate hits (
  FUN_8c069078 6.3M — top hit in game code).
- scene_mgr_B (0x8C063F58) enters at 100.6M, 299 K hits — main scene/state
  dispatcher candidate **elevated to "very likely"**.
- mt_loader (0x8C02DCEC) NOT seen — no new motion file loaded after initial.
- load_mt_to_u_pai (0x8C04BDA2) first at 100.6M, hit 117K times — MT pause
  sequencer; confirms scene_mgr_B vicinity is the fight/scene path because
  it chimes right when scene_mgr_B fires.

## What 0x8C063F58 probably is
First sees right at game-image start (+4M instr), close to
load_mt_to_u_pai presence (±110 K instrs) — matches hypothesis of being the
game scene drain. Its switch table hosts 3 jumptable entries at 0x8C063F58
(from fntables.csv), entry spacing equal to other mode dispatchers.
