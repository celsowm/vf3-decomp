# sh4 call-site cross-check (2026-09-26)

## Finding
`extract/analysis/disasm_1ST_READ.unsc.bin.calls.csv` (Ghidra) is unusable
for closure as-is:
- Of 2336 rows, only 125 have a real call word (`bsr` 33 / `jsr @Rn` 62 /
  `bsrf` 23 / `jmp @Rn` 7) at `call_site`. The rest are phantom: delay
  slots, `lds pr`/`rts` epilogue words, `nop`, literal-pool words (`0000`,
  `fffd`), even ASCII string bytes.
- Real `bsr` sites often sit in inter-function gaps (seed-fragmented bodies
  Ghidra never formed into functions), so `containing()` attribution fails
  from that side too.
- Missed real calls the other way: `0x8C08B7EE`'s bsr pair, `0x8C0AF734`'s
  `jsr @r2`, `0x8C0B1560`'s literal-vector `jsr @r3` are all absent.

Exonerated: nothing. `port_backlog.csv` leaf flags share the broken
provenance (leaf = no outgoing edges in calls.csv, vacuously true when the
edges are missed): 1416/1780 claimed leaves decode to real sh4 call sites
(verified by sampling, e.g. `0x8C010954`'s `jsr @r1` segment-bit call).
Backlog `leaf` is deprecated for triage; use `port_plan.csv`'s `leaf_sh4`.

## Tooling
- `tools/sh4_calls.py`: recursive descent per baseline function from the
  image (follows bf/bt + fallthrough; bra/jmp/rts/braf decode only their
  delay slot then stop; does NOT follow braf targets so switch-table data
  never decodes as code). Literal-pool fixpoint: PC-relative mov.l/mov.w
  slots are collected per pass and refused as code in later passes (kills
  pool-words-decoded-as-bsr phantoms like scalemap's `BF00`/`B880`).
  Emits `extract/analysis/sh4_calls.csv` (static bsr targets, dyn jsr/bsrf
  sites, jmp@Rn tail sites). 1343 static edges, 12150 dyn sites in 1656 fns.
- `tools/port_plan.py`: sh4 data is now the primary static source; only
  Ghidra rows with a real call word feed closure (rest counted in
  `g_phantom`); any unresolved dyn site forces `closure_ok` off with
  `dyn@<site>` in missing_callees. New columns: `leaf_sh4` (machine-decoded
  leaf: no static/dyn/tail sites), `sh4_static`, `sh4_dyn`, `sh4_tail`,
  `g_phantom`.

## Known limitations (safe direction)
- Dyn sites over-approximate: literal-vector jsr (resolvable, e.g. the
  `mova`/`or 0xA0000000` segment-bit idiom) still reports dyn. Clearing
  those needs literal tracking (future work).
- Descent is bounded to `[entry, entry+size+16)`; calls in unclaimed gap
  code or past tail-jmps are missed (no caller to attribute anyway).
- Switch-dispatched static calls inside the same body are missed (braf
  targets not followed).
