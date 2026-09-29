# 070x/071x FPU family sweep — partial closures (2026-09-29)

## Triage (machine-decoded, tools/sh4_calls.csv + tail-word audit)
90 true-leaf closure-ok fragments (8-140 B), all FPU stream ops
(`fmov.s` loads/stores, `fadd`/`fsub`, spill prologues). Verdict: EVERY one
ends mid-stream (`fmov.s @-r4` store, fall-through, no `rts`). Zero end
with `rts`; several successors contain branches and `jmp @Rn` tail jumps
(e.g. 0x8C070874: `bt/s` + `jmp @r2`).

## Why most of the family remains parked (structural)
Per the exit semantics (docs/re/sh4_calls.md addendum 2026-09-26: fork
exits fire on matching-depth `rts`, not at entry+size), a fall-through
fragment's oracle exit covers downstream code, so most fragments are not
standalone-verifiable. Demonstrated with 0x8C070832 (exit pr/r15/r4
post-date the 32 B body) and 0x8C070852/fvecmix2 (in-tree, test ungated).
Boundary captures have since closed `0x8C070120`, `0x8C0708B0`, and
`0x8C070A84` with paired register+RAM replays at observed transfer or
fragment-end boundaries. The remaining Campaign-A routines `07030C` and
`070CF0` contain
`fsqrt`/`fmul`/branches — combined-unit ports would inherit the tail
jumps, same hazard one level up.

## Secondary finding
Campaign-C "never executed" is unreliable for this family:
`trace_fn_hits.csv` attribution misses seed-fragmented bodies, but the
abreg batch (same fight scenario) captured 64-sample goldens for 070120,
07030C, 0706C4, 070852, 0708B0, 070A84, 070CF0, 071E3a. Execution-ID
attribution needs the same sh4-descent hardening as call edges.

## Future boundary
Further closures need path-split goldens (taken vs tail-jump exits diverge) or
fork-side mid-region snapshots. Reciprocal-square-root instructions remain
finite-cataloged until broader SH-4 accuracy is established.
