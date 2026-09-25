# M30 — SDK/Katana library attribution sweep (true image)

Passes on the corrected image, `extract/analysis/sysrof/` module corpus
(expanded: +nindows 20, +sg_mw 23, +sg_mwwav 2, +sofdec 96 objs; total
corpus: shinobi 253, ninja 583, kamui2_flat 330, kamui2_mmu 330,
sh4nlfzz 273, nindows 20, sg_mw 23, sg_mwwav 2, sofdec 96).

- Byte-exact sweep (`sysrof.py match`)
  -> extract/analysis/katana_matches_true.csv (467 rows / 205 unique
  regions). Exact bytes break at literal pools → weak on its own.
- **Masked-word sweep (`tools/libmask_match.py`, new)**: fidhash masking
  (bra/bsr/mov.l-pc/mov.w-pc/#imm/disp fields zeroed, opcode+register grid
  kept) over module CODE windows vs the whole image
  → extract/analysis/libmask_matches.csv (596 module windows, ~44.6 KB).
  Baseline fn attribution: entries fully inside matched regions:
  **118 / 2,398 functions (4.9%), 25,694 B (5.9%)** — dominated by
  `ninja` (96 fns: libKAMUI-ish names), with sh4nlfzz (SH C runtime) 12,
  kamui2 5, shinobi 3, sg_mw 1, sofdec 1.

Interpretation: the title's bulk code is custom (game engine), but the
masked pass pins names + known semantics onto the lib perimeter for free.
The pipeline additionally feeds `tools/decomp_stats.py` (M31).
