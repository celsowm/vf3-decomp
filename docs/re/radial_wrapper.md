# Two-actor radial wrapper: development candidate

Exact owner `0x8c0cb65a` is a 32-byte wrapper around
[radial correction](radial_bound.md). It saves PR and the second actor,
reads the original scene flags at `0x0c29bcc0`, and skips both calls when
mask `0x80001` has a set bit. Otherwise it invokes radial correction for
R4 and then for the saved R5 actor. Its actual BSRs are `0x8c0cb66a` and
`0x8c0cb66e`; the latter loads R4 from the stack in its delay slot.

An original development pilot executes the complete 32-byte body with
enabled and bypass paths, two separately allocated actors and point tables,
and 64 configurations in each of states 21/26. There are **128 valid
specimens**. The passing isolated C candidate reproduces all state and RAM
comparisons with **128/128 matches, zero skips**. It has no acceptance result,
repository integration, or new coverage credit yet.

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
and `radial_wrapper_candidate_v2_native_report.json`. The independent input
fixture is prepared but has not been captured. The current two-owner arena
batch remains separate; the wrapper is a following candidate toward 65%.
