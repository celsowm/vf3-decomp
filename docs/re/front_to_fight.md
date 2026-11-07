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

## Reusable capture and execution-trace tooling (2026-11-06)

`tools/front_to_fight_capture.py` creates an isolated cold-boot run with
alternating 15-frame Start/A taps and periodic savestates. The first version
used the wrong default bits: `0x10` is D-pad Up and `0x1` is C, which the
standard-pad mask forces released. Therefore the 5,400- and 54,000-frame runs
below are not Start/A navigation captures. The reusable tool now defaults to
Flycast/KOS Start `0x8` and A `0x4`; new captures must use those values.

The earlier 5,400-frame run saved states 1–8. State 7 carries fighter-like
actor records and usable 23-row matrix tables, but resuming it for 180 frames
executes BIOS PCs only; it does not enter the fight loop. The actor records in
that checkpoint are stale data, not proof of a live round.

`tools/flycast_capture.py --trace-instructions --trace-pc <address>` now records
the guest instruction trace and reports exact PC counts. `tools/trace_bin_sum.py`
recognizes both trace layouts: the legacy PC-first record and this build's
opcode-first record. Replaying the retained state 47 for 900 frames confirms
that it executes fight-loop workers and the 63-channel evaluator, but it does
not reach the watched action-update PC `0x0C0AD1B8`. The actors keep motion IDs
`0x83C` and `0x60F` under Start and attack-button pulses, and under the 1,791-
frame strike script; their phase fields advance. This is an active autonomous
fight/demo state, not a player-control capture. The action-to-motion mapping
therefore remains unresolved.

`front_to_fight_capture.py` accepts `--tap-until`, which ends the scripted
menu taps and leaves the rest of a long capture neutral. The old 54,000-frame
cold boot tapped the wrong bits from frames 900 through 2,400 and saved 14
checkpoints at 3,600-frame intervals. Checkpoint 3 (frame 10,800) contains a
usable autonomous Akira/Jacky pose: actor `0x0C1FEFE4` has kind bytes `0/0`
and motion `0x760`; actor `0x0C20138C` has kind bytes `20/7` and motion
`0x5A9`. Both have 23 usable matrices. This remains pose evidence only, not a
player-controlled round.

An 180-frame replay of checkpoint 3 applied masks `0x4` (A), `0x2` (B),
`0x1` (C, masked off by the standard-pad model), and `0x8` (Start). Both phase
fields advanced, but neither motion ID changed. Its trace
hit the fight workers (`0x0C073C2A`: 28, `0x0C068F86`: 65,
`0x0C069078`: 109) and MT evaluator (`0x0C09D6E0`: 114), but not the action
update (`0x0C0AD1B8`: 0). Checkpoint 10 (frame 36,000) showed the same pattern.
These are usable autonomous fight poses, not evidence of player control. The
fight-state input probe therefore still needs a user-started-round state.

Reproduce the corrected cold-boot checkpoint run with:

```powershell
python tools/front_to_fight_capture.py `
  --out extract/analysis/front_to_fight_probe_20261106_v4 `
  --frames 54000 --start-frame 900 --tap-interval 150 `
  --tap-length 15 --tap-until 2400 --checkpoint 3600 `
  --start-mask 0x8 --confirm-mask 0x4
```

Replay checkpoint 3 with the pulse sequence and compare its instruction
profile against a neutral replay with:

```powershell
python tools/native_motion_input_probe.py `
  --state extract/analysis/front_to_fight_probe_20261106_v2/data/vf3_3.state `
  --out extract/analysis/native_motion_input_probe_long_s3_v1 `
  --frames 180 --actor 0x0c1fefe4 --actor 0x0c20138c `
  --pulse 15:30:0x4 --pulse 45:60:0x2 `
  --pulse 75:90:0x1 --pulse 105:120:0x8

python tools/native_motion_input_probe.py `
  --state extract/analysis/front_to_fight_probe_20261106_v2/data/vf3_3.state `
  --out extract/analysis/native_motion_input_probe_long_s3_neutral_v1 `
  --frames 180 --actor 0x0c1fefe4 --actor 0x0c20138c

python tools/flycast_capture.py `
  --state extract/analysis/front_to_fight_probe_20261106_v2/data/vf3_3.state `
  --play extract/analysis/native_motion_input_probe_long_s3_v1/input_schedule.txt `
  --out extract/analysis/fight_pc_trace_long_s3_v1 `
  --trace-instructions --trace-pc 0x0c0ad1b8

python tools/flycast_capture.py `
  --state extract/analysis/front_to_fight_probe_20261106_v2/data/vf3_3.state `
  --play extract/analysis/native_motion_input_probe_long_s3_neutral_v1/input_schedule.txt `
  --out extract/analysis/fight_pc_trace_long_s3_neutral_v1 `
  --trace-instructions --trace-pc 0x0c0ad1b8

python tools/trace_bin_diff.py `
  extract/analysis/fight_pc_trace_long_s3_neutral_v1/instruction_trace.bin `
  extract/analysis/fight_pc_trace_long_s3_v1/instruction_trace.bin --top 40
```

The pulse and neutral traces each contain 27,526 distinct PCs. Their count
differences cluster in the repeated `0x0C0568xx` path; neither trace reaches
`0x0C0AD1B8`, and the watched motion IDs remain fixed. These captures do not
prove that menu or fight controls failed because their original Start/A script
used Up/C bit values.

## Corrected KOS-button capture and state scan (2026-11-06)

The capture tool defaults are now Start `0x8` and A `0x4`, matching
`core/input/gamepad.h` and `src/host/dc_wire.h`. The new cold boot's log shows
the expected active-low wire words (`0xFFFFFFF7` for Start and `0xFFFFFFFB`
for A). It saved 17 checkpoints at 300-frame intervals; later checkpoints
contain live actor motion changes, including `0x2A9/0x953` at checkpoint 14
and `0x7DF/0x162` at checkpoint 16.

`tools/front_to_fight_state_scan.py` replays each checkpoint for 90 frames
with Start/A pulses and counts the fight, motion, controller and action-update
PCs in both the `0x0C` and `0x8C` mirrors. Nine checkpoints execute fight
workers and the MT evaluator, but none of the 17 reaches controller merge
`0x0C09AF6C`, selected-port reader `0x0C09B006`, or action update
`0x0C0AD1B8`. The active states still look like autonomous attract
choreography; the corrected input bits alone have not produced a
player-controlled round.

Reproduce the corrected capture and state scan with:

```powershell
python tools/front_to_fight_capture.py `
  --out extract/analysis/front_to_fight_probe_20261106_v3 `
  --frames 5400 --start-frame 900 --tap-interval 150 `
  --tap-length 15 --tap-until 2400 --checkpoint 300 `
  --start-mask 0x8 --confirm-mask 0x4

python tools/front_to_fight_state_scan.py `
  --state-dir extract/analysis/front_to_fight_probe_20261106_v3/data `
  --out extract/analysis/front_to_fight_state_scan_corrected_v3_aliases `
  --frames 90 --pulse 15:30:0x8 --pulse 45:60:0x4
```

The scan writes `state_scan.csv` and `state_scan.json` plus per-state
instruction traces under `extract/analysis/`.

The capture wrapper also accepts `--input-script` for a reusable KEYF-only
timeline. Running the existing `tools/vf3_play_boot_mix.txt` through this path
saved 15 checkpoints across 4,800 frames. Replaying them with the alias-aware
PC scan again found fight workers and MT evaluation, but no controller merge,
selected-port reader, or action-update execution. The earlier register-only boot-mix
campaign therefore does not establish that its action masks were consumed by
a player-controlled round.

The documented boot procedure holds Start from frame 0 through frame 900, so
`tools/vf3_play_start_hold.txt` captures that prompt handling and follows it
with A taps. Its 5,400-frame run also stayed on autonomous paths: the 90-frame
scan found no controller merge or selected-port reads in any checkpoint, and
only one action-update hit at checkpoint 16. Neutral, Start-only, and A-only
replays of checkpoint 16 produced the same counts, so that single hit was not
caused by either button. A separate full cold-boot interpreter trace recorded
37,027,968 instructions and one selected-port read at `0x8C09B006`, but no
controller merge, action update, or fight-worker hits. Its PC stream starts in
the BIOS P2 alias `0xA0000000`; `trace_bin_sum.py` now recognizes that address
so the full-run summary can be read. The interpreter cold trace and the
replays of recompiler-saved checkpoints take different paths; that difference
remains unresolved. Reproduce with:

```powershell
python tools/front_to_fight_capture.py `
  --input-script tools/vf3_play_boot_mix.txt `
  --out extract/analysis/front_to_fight_bootmix_capture_v1 `
  --frames 4800 --checkpoint 300

python tools/front_to_fight_state_scan.py `
  --state-dir extract/analysis/front_to_fight_bootmix_capture_v1/data `
  --out extract/analysis/front_to_fight_bootmix_state_scan_aliases_v1 `
  --frames 90 --pulse 15:30:0x8 --pulse 45:60:0x4

python tools/front_to_fight_capture.py `
  --input-script tools/vf3_play_start_hold.txt `
  --out extract/analysis/front_to_fight_start_hold_capture_v1 `
  --frames 5400 --checkpoint 300

python tools/front_to_fight_state_scan.py `
  --state-dir extract/analysis/front_to_fight_start_hold_capture_v1/data `
  --out extract/analysis/front_to_fight_start_hold_state_scan_alias_v1 `
  --frames 90 --pulse 15:30:0x8 --pulse 45:60:0x4

python tools/flycast_capture.py `
  --play extract/analysis/front_to_fight_start_hold_capture_v1/front_to_fight.play.txt `
  --out extract/analysis/front_to_fight_start_hold_fulltrace_v1 `
  --trace-instructions --trace-pc 0x8c09af6c --trace-pc 0x8c09b006 `
  --trace-pc 0x8c0ad1b8 --trace-pc 0x8c073c2a

python tools/trace_bin_sum.py `
  extract/analysis/front_to_fight_start_hold_fulltrace_v1/instruction_trace.bin `
  --top 15 --pc 0x8c09af6c --pc 0x8c09b006 --pc 0x8c0ad1b8 `
  --pc 0x8c073c2a --pc 0x8c068f86 --pc 0x8c069078 --pc 0x8c09d6e0
```

A separate 240-frame replay pressed `0x10` (D-pad Up, not Start) followed by
two short control pulses. The actor motion IDs again stayed fixed. Its trace did not
execute selected-port reader `0x0C09B006`, controller merge `0x0C09AF6C`, or
action update `0x0C0AD1B8`; the fight worker still ran 28 times. A RAM watch of
the controller globals saw writes to `0x0C29B864` and `0x0C29BCCC`, but no
write to the merge result at `0x0C29BA50`. The remaining capture target is the
pre-fight/controller mode that enters those reader and merge functions.

The state inventory, motion-field replay, and instruction trace are retained
under the ignored `extract/analysis/front_to_fight_probe_20261106_v2/`,
`extract/analysis/native_motion_input_probe_long_s3_v1/`, and
`extract/analysis/fight_pc_trace_long_s3_v1/` directories.

## Frame-clock transition ladder (2026-11-06)

`tools/vf3_play_frontend_ladder.txt` converts the old Start/A transition
ladder into explicit frame-clock presses using the verified KOS masks (`0x8`
Start, `0x4` A), with a 15-frame release after each tap. The reusable capture
and state-scan tools ran it from a fresh boot through frame 8,400, saving six
20-second checkpoints. The Flycast log confirms the expected active-low Maple
words (`0xfffffff7` and `0xfffffffb`) at each scheduled input.

The 90-frame scans show fight workers and the MT evaluator only in checkpoints
3–5, matching the autonomous attract path. None of the six scans reaches
controller merge `0x0c09af6c`, selected-port reader `0x0c09b006`, or action
update `0x0c0ad1b8`. This verifies that the buttons reached Maple but does not
identify a user-controlled round. The menu-to-live-round transition remains
open; actor fields in these states are not enough to claim player control.

A 90-frame memory watch on checkpoint 5 also found no access to the controller
merge output at `0x0c29ba50`. Scene word `0x0c29b99c` (`scene +0x138`) remained
zero; `audio_fight_caller.md` identifies that word as an input to the audio
transition routine, not as the pad packet. Its unchanged value therefore does
not establish whether the menu consumed Start/A. The watch files are retained
under `extract/analysis/memwatch_frontend_ladder_s5_v1/`.

Reproduce the capture and scan with:

```powershell
python tools/front_to_fight_capture.py `
  --input-script tools/vf3_play_frontend_ladder.txt `
  --out extract/analysis/front_to_fight_probe_20261106_ladder_v1 `
  --frames 8400 --checkpoint 1200

python tools/front_to_fight_state_scan.py `
  --state-dir extract/analysis/front_to_fight_probe_20261106_ladder_v1/data `
  --out extract/analysis/front_to_fight_state_scan_ladder_v1 `
  --frames 90 --pulse 15:30:0x8 --pulse 45:60:0x4

python tools/mem_watch.py `
  extract/analysis/front_to_fight_probe_20261106_ladder_v1/data/vf3_5.state `
  --watch-range 0x0c29b99c:4 --watch-range 0x0c29bccc:4 `
  --watch-range 0x0c29ba50:4 `
  --play extract/analysis/front_to_fight_state_scan_ladder_v1/input_schedule.txt `
  --emulator extract/analysis/front_to_fight_probe_20261106_ladder_v1/flycast_v3.exe `
  --out-dir extract/analysis/memwatch_frontend_ladder_s5_v1 `
  --name frontend_ladder_s5_inputs --frames 90 --limit 200
```

The capture results and reproduction commands are recorded in
`docs/re/native_decomp_port.md` and `docs/re/mt_fields.md`.

## Repeated ladder capture (2026-11-07)

A fresh 6,000-frame run with 300-frame checkpoints again showed changing actor
motion IDs across checkpoints. A focused
90-frame instruction scan from checkpoint 14 recorded 546,381 guest
instructions but zero hits at the fight-worker, MT-evaluator, controller-merge,
selected-port, and action-update PCs watched by `front_to_fight_state_scan.py`.
The longer capture therefore did not provide a player-controlled motion/action
sample. Its log records Start and A as the expected active-low Maple words,
which proves delivery to the input path, not that a user-controlled round was
entered. Artifacts are under the ignored
`extract/analysis/front_to_fight_capture_20261107_ladder_v1/` and
`extract/analysis/front_to_fight_scan_ladder_s14_20261107_v1/` directories.

A complete follow-up scan replayed all **19** saved checkpoints from that
capture with Start (`0x8`) and A (`0x4`) pulses. All 19 runs completed; 11
entered fight-worker code, but none reached controller merge
`0x0c09af6c`, selected-port reader `0x0c09b006`, or action update
`0x0c0ad1b8` in either RAM mirror. The captures therefore still contain no
player-controlled round. The consolidated report is retained under
`extract/analysis/front_to_fight_scan_all_20261107_ladder_v1/`.

```powershell
python tools/front_to_fight_state_scan.py `
  --state-dir extract/analysis/front_to_fight_capture_20261107_ladder_v1/data `
  --out extract/analysis/front_to_fight_scan_all_20261107_ladder_v1 `
  --frames 90 --pulse 15:30:0x8 --pulse 45:60:0x4
```

Reproduce the focused run with:

```powershell
python tools/front_to_fight_capture.py `
  --input-script tools/vf3_play_frontend_ladder.txt `
  --out extract/analysis/front_to_fight_capture_20261107_ladder_v1 `
  --frames 6000 --checkpoint 300

python tools/front_to_fight_state_scan.py `
  --state-dir extract/analysis/front_to_fight_capture_20261107_ladder_v1/data `
  --pattern vf3_14.state `
  --out extract/analysis/front_to_fight_scan_ladder_s14_20261107_v1 `
  --frames 90
```

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
