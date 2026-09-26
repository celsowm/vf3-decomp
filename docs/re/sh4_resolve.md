# sh4 literal-resolver (2026-09-26)

`tools/sh4_resolve.py`: resolves `sh4_calls.csv` dyn sites by backward
intra-block simulation (`mov.l` u32 / `mov.w` signed / `mova`→R0 /
`mov #` / `mov` / `add` / `or` with exact SH-4 reg fields). Sound by
construction: aborts on any branch/call/return word crossed (no joins)
and on any second branch targeting inside (def, site]. Result on 12363
sites: **4226 STATIC / 3 FIXED / 8134 UNKNOWN**.

## Bugs found while validating (all fixed)
- `add`/`or`/`mov` dest fields: dest is bits 8-11 (was low nibble for
  add/or, low nibble is correct only for `mov`); `mova` always targets R0;
  stores (`mov.l @Rn`) misread as `or`. Validated against hand traces.
- `sh4_calls.py` missed `jsr @@(d8,Rn)` (+19 sites) and truncated loop
  bottoms (follow +256 / record +16 split).

## Alias result (the big one)
The game addresses image bytes through the 0x0C P0 alias (proven by
RAM-dump/image cross-check at 0x0C09553C: identical words). So any
0x8C/0xAC/0x0C-high value in image range is a STATIC edge even with no
Ghidra function containing it (gap code). `port_plan.py` consumes
`sh4_resolved.csv`: STATIC unions into edges, FIXED fails closure with
`ram@`, and in-image functionless targets fail with `gap@` (the old code
dropped them → vacuous closure, fixed).
Validation: resolver beats Ghidra twice — 0x8C01066E (mine: path-dependent
UNKNOWN, sound; Ghidra: nop-mid-function phantom) and 0x8C010F3C (mine:
prologue-shaped gap entry; Ghidra: same phantom).

## Impact
closure=- rows 1851 -> 1347 -> 1927 (honest: every remaining fail names
dyn@/gap@/ram@/unk@). Parked verdicts revised: af734/a71ac/a7750/09D480
"RAM vectors" are static gap calls; af734's chain (af734 -> 0x8C09553C ->
0x8C03A140/0x8C03A6E0) is fully static — see docs/re/af734_probe.md.
Gap-PC watching works (goldens_s8: 64 samples each for all three gap
units), so off-baseline units are portable (decomp_status already counts
off-baseline rows; ported() makes them accounted for closures).
