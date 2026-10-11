# Two-actor radial wrapper: qualified standalone C

Exact owner `0x8c0cb65a` is a 32-byte wrapper around
[radial correction](radial_bound.md). It saves PR and the second actor,
reads the original scene flags at `0x0c29bcc0`, and skips both calls when
mask `0x80001` has a set bit. Otherwise it invokes radial correction for
R4 and then for the saved R5 actor. Its actual BSRs are `0x8c0cb66a` and
`0x8c0cb66e`; the latter loads R4 from the stack in its delay slot.

Readable `src/fight/radial_wrapper.c` now implements the exact owner.
Original development and fresh independent acceptance each pass **128/128
valid cases**, with zero skips or exclusions. Both original campaigns cover
all 32 bytes, enabled/bypassed paths, two distinct actors and point tables,
and 64 configurations per state. Acceptance relocates owned objects,
changes finite inputs and masks, switches floating banks and uses states
28/29. All **375 compiled dependencies** and the final native executable
were frozen before acceptance.

The audit checks both actual BSRs on enabled paths, absence of those calls
on bypass, unchanged scene flags, original opcodes and pools, saved PR and
second-actor stack slots, callee state preservation and the real RTS/delay.
The affected binding, all 39 native suites and 151 tool tests pass. No
production callback invocation or cached entry is claimed. The original
literal target at `0x8c073980` remains a static reference; no direct BSR to
the wrapper appears in the original image.

Seal: `tools/oracle/radial_wrapper_v1_manifest.json`. This adds **32 bytes**,
bringing verified C to **261,452 / 434,656 (60.15%)** with **21,075 bytes
remaining to 65%**. The seal pins the preceding arena milestone and its
complete full 60% inventory checkpoint.

The first candidate incorrectly used the canonical cached label's alias
for the relative BSR return PCs, exposing wrong saved stack bytes in all
32 enabled specimens; all 96 bypass specimens passed. That executable,
source and failed report remain pinned in cache `radial_wrapper_candidate_v1`.
Candidate v2 uses the actual uncached invocation contract captured by the
original interpreter. Its sources, executable, radial dependency, base
library and passing report are pinned in `radial_wrapper_candidate_v2`.
This evidence does not qualify a cached execution entry.

Evidence: `extract/analysis/coverage_65_radial_wrapper_dev_v1`,
`radial_wrapper_candidate_v1_native_report.json` (excluded failed candidate),
and `radial_wrapper_candidate_v2_native_report.json`. The final development/acceptance reports are
`coverage_65_radial_wrapper_{dev,accept}_v1_native_report.json`; the
immutable native executable is `vf3matrixfamily_radial_wrapper_dev_v1.exe`
and its source archive is `radial_wrapper_dev_v1_complete_sources`.
