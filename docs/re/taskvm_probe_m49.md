# M49 — task-VM field naming probe (2026-09-25)

Static map (`docs/re/task_vm.md`, 1196 sites → 26 offsets) promoted with
trace roles; `src/fight/task_vm.h` already carries hot names:

- `0x04 frame_stamp`, `0x08 scene_slot`, `0x12 strategy_flag`,
  `0x16 module_tick` (hottest rd), `0x20/0x24 strategy_a/b`,
  `0x28 packed_pair`, `0x30 timer`, `0x32 instr_slot` (highest wr),
  `0x40 back_ptr`, `0x44 callback_hook`, `0x48 ring_counter`,
  `0x52 part_counter` (`frame.c` `part & 7` cycles 8 parts),
  `0x56 stream_tag`.

Next probe (fight-vs-attract mem-watch around `r14=0x0CBEFBE0`):
`VF3_WATCH` `mem <base> <len>` from vf3_7 (fight-live) vs vf3_6 (pre-fight);
name each field via write-burst deltas. Savestate-first target `vf3.state`
per M19 plan. No struct change until bursts confirm.
