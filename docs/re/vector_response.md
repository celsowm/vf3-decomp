# Larger vector-response routine: original pilot only

Callable hypothesis `0x8c0a67b8` precedes frozen owner `0x8c0a67ce`
(640 bytes) by a 22-byte integer/FR save and setup prefix. The original
routine reads a configuration and two triples, uses the matrix helpers,
and publishes a third triple. Helper `0x8c0a647c` returns fixed scratch
address `0x0c2cf8f0`; it is not a general allocator. Configuration fields
include a matrix at `+16`, vectors at `+80`, `+92` and `+104`, and scalar
gain/limit inputs at `+116` and `+120`. Semantic naming remains provisional.

The original development pilot has **128 valid cases** across states 21/26,
without exclusions or quarantine. It varies finite configuration scalars,
positions and direction triples. Captures execute **632/640 owner bytes**.
Missing PCs are `0x8c0a6988`, `0x8c0a698a`, `0x8c0a69b0` and
`0x8c0a69b2`, associated with the small-residual and zero-length fallback.
Whole-body eligibility therefore remains unproven.

An exhaustive aligned original-image scan found no direct BSR or literal
target reference to any address from the proposed prefix start through the
frozen owner. This does not prove that no computed caller exists. It does
leave the callable boundary without an identified original caller, so the
existing attribution rules cannot yet qualify that prefix.

There is no new C implementation, native comparison, acceptance capture,
promotion, or coverage credit. Retain the pilot as research evidence;
finding a genuine computed caller and covering the missing original paths
must precede any attempt to count the complete owner.

Evidence: `extract/analysis/coverage_65_vector_response_dev_v1`,
`vector_response_v1_capture_dev.log`, and `vector_response_v1_triage.json`.
Original raw capsules remain in the external evidence cache. Holdout input
fixtures are prepared but unused. The observer is the unchanged original
interpreter; no live C/audio claim is made.
