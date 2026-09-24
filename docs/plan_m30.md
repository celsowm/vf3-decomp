# Decomp coverage plan (M30–M40, 2026-09-24)

Goal: move from "engine shapes understood" to a *measurable, considerable
percentage of the 2,398 baseline functions / ~435 KB of code body bytes*
attributed or ported, with a permanent metric dashboard.

## Measurement first (M31 dashboard)

`tools/decomp_stats.py` (to build): per-fn status table joining
`funcs_1ST_READ.unsc.bin.csv` (2398 fns) against:
  - `extract/analysis/katana_matches*.csv` (byte-exact SDK module hits; M30)
  - `src/**` ports (led via a status CSV: fn → C file → test)
Report: % fns attributed / % code bytes covered, committed each milestone
as `docs/coverage.md`. This turns "considerable %" into a checkable number.

## Milestone queue

| ID | Item | Why it moves % | Verification |
|---|---|---|---|
| M30 | Katana/SDK attribution sweep: `tools/sysrof.py` over the Katana .lib corpus vs the true image; regenerate on corrected image | The binary is SDK-heavy (GDFS, libk2/KAMUI, std C) — byte-exact module matches name large blocks for free | `katana_matches*.csv` row count + spot-disasm of a handful of matches |
| M31 | Batch headless decompile all 2,398 fns (Vf3Decompile loop) into `extract/analysis/decomp_all/` + stats tool | The full inventory makes bucketing/scheduling mechanical; small fns (<100 B) are bulk-attributable | decomp_all file count == 2398; coverage.md v1 |
| M32 | Leaf utility family port: memcpy/memset/set variants, string cmp (f_8c03482a = memcmp5-class), fixed-point math, rdiv helpers | Long tail of tiny hot fns = fast wins; several are directly unit-testable | `tests/libutil_replay.c` PASS; matches disasm |
| M33 | GDFS/loader layer: name table (0x8C106A48 + row 104 chain), sector read path, MT mount fixup (+0x27B0): the loader fn at the table's code xref | Loader = gate to all assets; mount-fixup unblocks full MT residency model | Loaded window byte-equal to `extract/gamedata/*.BIN` slices + RAM-dump window (shots/mem_mtdump_*) |
| M34 | Task VM helpers: f_8c035bf2 (alloc, size<<11), f_8c0356cc (init), f_8c0355a0 (register), f_8c0349aa (spawn) wired into mainloop.c hooks | Completes the spawn→dispatch→register loop already transcribed in M25/M28 | `tests/mainloop_replay.c` extended with spawn chain PASS |
| M35 | Scene walker f_8c0b1a54 + fight runner f_8c0796f4 transliteration; rebuild frame.c 6-slot ladder on the true image | Revives the stale frame pipeline onto verified ground | frame_replay stays green + ladder sites match true disasm |
| M36 | Differential harness: run ported boot+dispatch vs `trace_boot3.bin` (427M records): replay N frames, PC-sequence compare around dispatcher calls | Turns the giant trace into a regression oracle for the whole port | tolerances doc'd; pass count logged |
| M37 | SH4 sound command layer: drv_set_dreset/dkill/mailbox protocol endpoints (string-attributed clusters) | Closes the audio arc (AICA kit boundaries M13/M26 + ADPCM decoder already bit-exact) | mailbox write sequence matches captured fight-entry writes |
| M38 | Renderer: PVR/poly pipeline + KAMUI mapping layer, POL/TEX compositors on top of existing format knowledge | Render is a large remaining code mass | CRC of display lists vs RAM dumps (shots/fb) |
| M39 | Fight logic top-half: per-fight tasks, input sampling, hit/anim cue tables — incremental from fight-live traces | The actual game-specific payload | trace segment replays |
| M40 | Coverage gate: ≥50% fn attribution (lib + ported), coverage.md auto-updated in CI | The "considerable %" checkpoint | tools/decomp_stats.py output |

## Sequencing rationale

M30+M31 produce the map; M32–M34 are the cheap, high-certainty ports that
also *de-risk* the hard middle (M35–M36 core loop parity); M37–M39 are
subsystem sweeps that only make sense once the engine loop replays.
Everything is trace-verifiable because M23 gave us a trusted image and
flycast RE fork hooks (VF3_TRACE / VF3_WATCH / AICAF / MEMF).

## Budget notes

- Ghidra batch decompile (M31): ~2,400 headless fn decompiles — run
  chunked overnight if needed (resume by manifest).
- sysrof sweep (M30): existing corpus + lbr.exe — minutes.
