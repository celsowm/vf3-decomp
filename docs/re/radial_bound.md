# Six-joint radial correction: qualified C owner

Readable `src/fight/radial_bound.c` is integrated and qualified. The final
combined native executable passes **252/252 valid development cases** and
**254/254 valid fresh acceptance cases**, retaining four development and
two acceptance interruptions as excluded specimens. Acceptance uses changed
finite values, relocated actors/point tables, alternate floating banks and
original states 28/29. All 374 compilation dependencies were frozen before
acceptance. Both complete owners add **424 bytes**; this owner contributes
**166**. All three observed/static affected bindings, including the
existing motion caller, 39 native suites and 151 tools pass.

Seal: `tools/oracle/arena_bounds_v1_manifest.json`; full gate evidence:
`extract/analysis/arena_bounds_v1_affected_portcheck.log`. This milestone
pins the preceding complete 1,378-binding 60% inventory checkpoint.
Coverage is **261,420 / 434,656 (60.14%)**, with **21,107 bytes remaining
to 65%**. The following sections describe the preserved preliminary pilots;
the final proof uses the combined `coverage_65_arena_bounds_*_v1` corpora
and `vf3matrixfamily_arena_bounds_dev_v1.exe`.


Callable `0x8c0cb67a` has frozen owner `0x8c0cb69e` with 166 eligible bytes
in two ranges. The preceding 36-byte setup/save prefix is absent from the
locked function inventory and earns no extra credit.

It reads the six joint points selected by the same immutable table and
division helper as [arena-bound correction](ring_bound.md). For each point
it computes squared distance in the first/third coordinates. The original
small-length threshold selects zero reciprocal length; otherwise the
routine uses SH-4 FSRRA. It normalizes the point to radius eight and writes
paired correction components into the actor arrays at `0x1618` and
`0x16f8`, clearing the opposite pair. Squared radius 64 selects the side.

Original development states 21/26 vary finite points inside, on and outside
radius eight, including zero vectors. Both complete 64 configurations,
with **128/128 valid specimens**. The isolated readable C candidate passes
every architectural-state and RAM comparison with zero skips, and the
original corpus covers all 166 owner bytes. The preliminary pilot alone received no
credit; the combined qualification above establishes fresh acceptance.

The development candidate was compiled outside the repository against the
frozen vector-aggregation base library, preserving compilation sources
during the full 60% gate. External cache
`audio-evidence/radial_bound_candidate_v1/manifest.json` pins both candidate
sources, the executable, base library, native report and base source
manifest. It was then integrated and frozen again before fresh acceptance.

The 32-byte wrapper at `0x8c0cb65a` has two real BSRs: `0x8c0cb66a` uses
a NOP delay, and `0x8c0cb66e` loads the actor from the caller stack. Four
configurations at each site in states 28/29 produce **16 successful original
caller windows**, without device accesses. `tools/callable_radial_bound.py`
checks the original branch targets/delays, full ordered setup/save prefix,
opcodes and pools, all six saved stack slots, preserved GPRs/FR12–15/XF,
FPSCR, and the actual RTS with R13 restoration in its delay slot. Seven
mutation tests pass. The wrapper itself is not implemented or credited.

Evidence: `extract/analysis/coverage_65_radial_bound_dev_v1`,
`radial_bound_candidate_v1_native_report.json`,
`radial_bound_v1_original_caller_validation.json`, and
`radial_bound_v1_callable_tests.log`. Original caller capsules and their
manifest are in cache `radial_bound_original_caller_v1`. Background AICA
events do not constitute a live C/audio comparison.
