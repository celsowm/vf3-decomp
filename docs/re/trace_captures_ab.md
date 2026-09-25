# (a) Trace captures — runnable recipes (2026-09-25)

Interpreter-only (VF3_WATCH mem lines need ReadMem wrappers).
Resume from pre-fight vf3_6 (not fight-live vf3_7 — loaders already done there).

## Runner (f_8c0796f4 dynamic entry)
Watch: tools/emu/vf3_watch_runner.txt (pc 8C0796F4/8C0B1A54/8C034864/8C0349AA + mem 8C5F4100 0x16D000).
Script: resume VF3_STATE=vf3_6, KEYF csel→fight (vf3_play_f2f pattern), MEMF both sides, EXITF.
Expect: runner 0 hits in boot (watchcount_boot3 confirms) → first hits here; r4 = task handle forwarded as r14; feeders 073d80/073952.

## Loader (MT scatter)
Watch: tools/emu/vf3_watch_loader.txt (mt_loader 8C02DCEC, load_mt 8C04BDA2/8C08232E, bjload 8C0CBC40, gdFsDaPlaySct 8C0360C8 + mem pack + mem table 8C1069BC 0x210).
Expect: writer PC to 8C5F4100 window that is not 09D69A/6E0 = loader; slot5093 file 0xCE154 → resident transition; ~1681 probes absent verbatim (rewrites).

## Sound (mpdrv owners + kit)
Watch: tools/emu/vf3_watch_snd.txt (sound block + per-frame AICA service 8C03EFFC).
AICAF ladder @600f per stage (26 BGM_ names, bin_names 161-191); consecutive-diff vs prior kit; base expect 0x086E54 or suffix ≥0x17EA00 (M26 prefix rule).
G2 filter: SH4 P4 0xA0080000..0xA0280000 + mailbox regs around fight_1→fight_2 reset; mailbox dreset PC = endpoint owner.

Cost: interpreter 30-60x realtime; frame-clock KEYF/AICAF/SAVEF/MEMF/EXITF immune to dynarec skew; EXITF required (quit-request flag).
