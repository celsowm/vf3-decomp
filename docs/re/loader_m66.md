# M66–M69 — loader/GDFS, CLI/MOTHEAD, CFG splitter, RELOAD (2026-09-25)

## GDFS runtime pointer (M66)

Name table `0x8C1069BC..0x8C106BCC` (132 ptrs, MTJACLAU entry 39 @0x8C106A58)
has zero static pool/mova refs (M33). Loader reaches it via runtime-populated
pointer (init relocation or manager object). Recipe: M36 mem-watch
`mem 0x8C5F0000+` MT pack + `mem 0x8C1069BC 0x210` table + VF3_WATCH pc on
loader suspects (`0x8C02DCEC mt_loader`, `0x8C04BDA2/0x8C08232E load_mt_*`,
`0x8C0360C8 _gdFsDaPlaySct`, `0x8C0CBC40 bjload_run`); trigger csel→round1
from vf3_6; catcher = fn reading 8880-slot table then scattering 64-B probes.
`src/sys/gdfs.c` stays name→tag only until then.

## CLI/MOTHEAD (M67)

`ST*.CLI` = `ST*_COLI.BIN` collision (`build_manifest_notes.md:11-23`),
`MOTHEAD.BIN` 168391 B, magic `18000000…` (INVENTORY). `gdfs_table.h:68`
indexes them. Next: `tools/cli_scan.py` (mirror pol_scan float-block scan
for collision tris) + model/animation linkage doc joining MT slot census.

## CFG splitter (M68)

2,258 junk fns (size≤8) + 2,268 thunks; `fight_f_*` are waypoint addrs not
heads (`bjload_run` mid-struct `mov.w;jsr @r14`); static jsr 2.8% (M43).
Split at every `fight_spawn_edges.csv` entry + `braf_tables.csv` targets
using DreamcastRecompiled `function_analysis.cpp` discoverers + thunk
recognizers, then re-run `Vf3Baseline.java`. `fight_loop.md:57` todo stays.

## RELOAD triage (M69)

`RELOAD.unsc.bin` 655360 B SH-4 reset/init (GDFS 0.53/syCache/syCbl/NAOMI
0.8/PowerVR), 335 fns unseeded, no ASCII; `SNDDRV.BIN` 53120 B ARM7. Scope:
SH4-mailbox peer + AICA map only
(`0x0-86E53` driver, `086E54+` kit, `A0B4-CF5D` ring). No ARM-side port.
