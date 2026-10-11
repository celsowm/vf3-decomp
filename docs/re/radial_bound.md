# Six-joint radial correction: development candidate

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
original corpus covers all 166 owner bytes. There is no acceptance result
or new coverage credit.

The development candidate was compiled outside the repository against the
frozen vector-aggregation base library, preserving compilation sources
during the full 60% gate. External cache
`audio-evidence/radial_bound_candidate_v1/manifest.json` pins both candidate
sources, the executable, base library, native report and base source
manifest. It requires integration and a new freeze before fresh acceptance.

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
