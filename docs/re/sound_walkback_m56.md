# M56 — sound endpoint walkback: negative result IS the result (2026-09-25)

`python tools/snd_walkback.py` (new, M56):

- libsnd strings verified present: `mpdrv_set_dreset_ns` @0x8C0CD8A8
  (file 0xBD8A8), `libsnd0.82` @0x8C0CD540.
- Literal-pool scan over full image for dwords in `0x8C0CD600..0x8C0CDA00`:
  **0 pool refs**. Owner scan in `0x8C035E00..0x8C036900`: **0 owners**.
- Output: `extract/analysis/snd_walkback.csv` (header only).

Confirms M37/mova hypothesis: sound.c uses mova/base+offset, so static
attribution is unreachable from byte patterns. Endpoint bodies must be
pinned via M36 trace windows (VF3_WATCH pc on `0x8C035Exx..0x8C0368xx`
pool-users + G2/AICA bus filter `0xA0080000..0xA0280000` + mailbox regs
around fight_1→fight_2 kit write). `src/sys/soundcmd.c` endpoints stay
0=unattributed until then — honest gate, not a miss.

Per-stage kit table skeleton: see Track E recon (26 BGM_ names,
`bin_names.csv:161-191`, INVENTORY sizes); method per row = resume vf3_6,
drive to stage, AICAF ladder @600f, consecutive-diff vs prior kit
(base expect 0x086E54 or suffix ≥0x17EA00 per M26 prefix-match rule).
