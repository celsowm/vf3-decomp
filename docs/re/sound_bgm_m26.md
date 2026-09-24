# M26 — BGM kit boundary re-measurement (2026-09-24)

Second independent AICA ladder (post-M23, resumed from pre-fight state
`vf3_6`, dynarec, VF3_PLAY script with 600-frame AICAF cadence, 25 dumps,
extract/analysis/shots/aica_m26_*).

## Result

- Steady fight/menu states: only the streaming ring
  `0x00A000..0x00D000` mutates (~20-330 B per 600-frame window) —
  reproduces M13's ring window exactly.
- Fight-entry kit write (frames 9000-10200 in this resume timeline):
  contiguous upper-region write `0x17EA00..0x1D1100` (~345 KB in two
  chunks: 333,312 B + 300,544 B). Lower region below 0x86E54 untouched
  (only the streaming ring).
- vs M13's menu→fight swap `0x086E54..0x1CC29D` (1.22 MB): the dreset
  kit region starts at the shared-voice prefix end; when the prior kit's
  prefix matches, only the suffix `0x17EA00..` is rewritten. The
  authoritative kit base remains **0x086E54**; kit tail ≤ 0x1D1100.

So the reset boundary protocol is confirmed bi-directionally: no
incremental voice updates EVER land below the streaming ring; song kits
are bulk suffix overwrites.

Artifacts: `extract/analysis/shots/aica_m26_*` (gitignored);
script: `tools/emu/vf3_play_m26.txt` (rtle off, frame-clock ladder).
