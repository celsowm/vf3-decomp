# M10 — probe-mode trace extensions (2026-09-20)

## Patches (flycast fork at tools/emu/flycast)
- `core/vf3trace.{h,cpp}`: `VF3_WATCH=<file>` env; file lines `pc 0xADDR`
  (up to 128). When the SH4 interpreter executes a watched PCa a probe group
  is emitted into the same u64-record stream:
      rec0 = (pc<<16)|0xFA10               # group open
      rec1..6 = r13, r14, r4, r5, r6, r7   # raw u64 register values
      rec7 = (pc<<16)|0xFA11               # group close
- Alias handling: watch compare normalizes pc via `pc|0x80000000` (game runs
  in P2 0x0Cxxxx alias under interpreter).
- `core/vf3script.cpp`: new commands `AICA_DUMP <tag>` (2MB AICA wave RAM
  snapshot to extract/analysis/shots/aica_<tag>_<ts>.bin) and
  `MEMDUMP <off8C> <len> <tag>` (16MB RAM window dump).

## Verified: dispatch probe capture (probe_dispatch3.bin)
240-frame run from savestate; 42.3M records; probe hits on 2 of 5 watches:
- FUN_8c0597c2 (state-index helper), 22 samples, all with `r13=0x28 r14=5
  r4=r5=0` — confirmed *fixed-parameter* fn called once per frame cycle with
  the same companion struct fields (consistent with its 16B table-index body).
- cand_sd_slot_lookup, 1411 samples, `r14=0cBEFBE0` always — frame-struct
  arg-pointer confirmed (feed is the caller's task struct, not a singleton).
- The scene-0A walker/predicate (0x8C0B1AC0 / 0x8C0B24FA) and ring head
  (0x8C073C2A) never hit during this window — the played-out fight had settled
  into a stream state (attract BGM) by the capture instant.

## AICA_LONG captures (aica_w*.bin, 2×15-frame spaced, and w*-series)
Consecutive-dump diffs: tiny steady deltas only (18–260 B over 15 s). All
delta clusters live in the same two bands: `0x44..0xF8` (streaming BGM block
refill window) and `0xA0BC..0xCF5D` (voice turn-around area). No voice-reset
sweep crossed the window: the played scene never emitted a song-kit reset.
Interpretation: the fight-state we resumed was a steady attract/demo loop;
the BGM-reset moment needs to be caught across a game-state transition
(char select -> fight intro), i.e. requires a fresh front-to-fight state
capture with `VF3_STATE` staging + `AICA_DUMP` before/after.

## Files
- extract/analysis/probe_t*.bin / probe_dispatch3.bin (probe captures)
- extract/analysis/shots/aica_*.bin (12 + 15 AICA waves)
- docs/re/fight_dispatch_chain.md (unchanged chain source-of-truth)
