# Runtime traces (flycast-derived)

Toolchain (added tools/emu/flycast = fork with VF3 hooks, git-ignored):
- `VF3_HEADLESS` build mode: `norend` graphics + headless main loop
  (`core/windows/winmain.cpp` branch), no UI, console-driven.
- `VF3_ALWAYS_INTERPRETER` forces the SH4 interpreter at emu init.
- `VF3_TRACE=<path>` env → per-PC trace records (u64: pc<<16|op) buffered,
  flushed via `core/vf3trace.cpp` + SEH printer (fault PC/module).
- `VF3_TRACE_FRAMES` frame cap.

Known traps encountered:
- `-config Dynarec.Enabled=false` colons required (`Dynarec:Enabled=false` form);
  otherwise the recompiler silently remains active (drives `bm_GetCodeByVAddr`).
- `mainui_init()` must be bypassed AND `rend_init_renderer()` called manually —
  otherwise `rend_single_frame` derefs the null `renderer`.
- `.gdi` track3 sector size must be 2352 (not 2048): wrong size breaks IP.BIN
  parse → reios reads date-string as boot filename.

## Artifacts
- `extract/analysis/trace_boot3.bin` — 3.4 GB, 427,781,658 instruction records,
  1200 frames, interpreter (clean exit 0)
- `extract/analysis/trace_functions_by_first_seen.csv` — first-time fn list order
- `extract/analysis/trace_fn_hits.csv` — per-fn exec hits
- `tools/trace_read.py`

## Findings
- IP.BIN ~96.5M instructions (incl. its delay-spin ~1.2M×14); at rec 96,574,470
  control passes to the game image at 0x8C020000
- 594 distinct functions touched in the slice; hottest: f_8c03482a (7.3M hits,
  per-frame scheduler?), f_8c035ca2, FUN_8c073cc6, f_8c06f720...
- Suspect `f_8c063f58` enters at ~131.9M — post-init context, consistent with
  mode-manager / scene switch candidate (see docs/re/fight_scene.md)
- Libk2 pipeline present (cand_kmiProcessVertex, _kmChangeContextFlipUV etc.) —
  all fdumping PVR vertex work
- Fight modules not yet reached within 1200 frames (attract/logo menu era);
  longer captures + JIT block-hook do capture live fight flow.
