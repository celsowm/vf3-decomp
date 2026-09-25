# L2 reloc-aware SDK matcher — measured NEGATIVE (2026-09-25)

Goal: raise rigorous (ported+SDK) coverage above 5.1%/6.3% by masking
PC-relative instructions and wildcarding literal-pool dwords, expecting full
module code windows to match across relocation.

## Result
- New tool `tools/libmask_match2.py` (mask fidhash + `mov.l/w @(disp,PC)`
  pool targets wildcards, seed-6 + bidirectional extend over a full code
  window of each obj).
- Ran over all 1910 objs (sh4nlfzz, shinobi, ninja, kamui2_flat/mmu,
  sofdec, sg_mw, nindows), min_words=12:
  139 windows matched, 16770 B, → `extract/analysis/libmask2_matches.csv`.
- Coverage of baseline fns: **54** (vs libmask 118). Union = 120 **(+2 vs
  libmask)**; 66 previously-covered fns are lost to the stricter window.
- Span ceiling observed: ~122 words ≈ 244 B per window even with pool
  wildcards — i.e. beyond ~120 words the game/SDK code genuinely differs
  (GDFS 0.53 vs 1.00, NAOMI 0.8 banner, kd 1.20 etc. are version-stamped
  drift, not relocation noise).

## Conclusion
The 246 B cap in the plain matchers is **not** relocation masking — it's
real SDK-vs-game divergence. L2 is a dead end for bulk attribution;
tool kept as `libmask_match2` for one-off unit test cases, not wired into
decomp_stats. Leaf-batch port-by-pattern was also measured: only 4/925
small (<64 B) bodies are truly trivial → does not scale to bulk rigorous
coverage either.

## Disposition (todo closure)
- 5 matches spot-verified with `tools/verify_libmask2.py`: all concrete
  tokens match, 0 concrete mismatches, wildcards only at pool slots
  (e.g. fballoc 115/119 concrete + 4 wildcards; kmsurfac 121/121 + 0).
- The verified regions are wired into `decomp_stats.py` as a **separate
  transparent bucket** `SDK-attributed (reloc-aware, L2 verified)`: +2
  baseline fns / +218 B (rigorous 122→124, 5.1%→5.2%). Not merged into the
  main SDK row, so the weak-matcher contribution stays visible.

## Where rigorous progress actually comes from
1. Trace-gated per-function ports (runner 0x8C0796F4, MT loader, mpdrv_*
   endpoints) — needs emulator captures (recipes committed under
   docs/re/trace_captures_ab.md + tools/watch/).
2. Structural transliteration of the top-10 unclaimed AI/engine bodies
   with replay tests — slow but correct.
3. Byte-level SDK pin-down against older JSRL/SDK versions — search art
   corpus (`tools/_katana_pkg` Saturn SGL) for an *era-correct* GDFS 0.53.

Recommendation: do NOT chase bulk fn attribution. Focus on per-function
ground-truth ports from trace + structural work, leaving the strict bucket
small but true.
