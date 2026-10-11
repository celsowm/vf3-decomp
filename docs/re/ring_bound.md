# Six-joint arena correction: qualified C owner

Readable `src/fight/ring_bound.c` is integrated and qualified. The final
combined native executable passes **252/252 valid development cases** and
**254/254 valid fresh acceptance cases**, retaining four development and
two acceptance interruptions as excluded specimens. Acceptance uses changed
finite values, relocated actors/point tables, alternate floating banks and
original states 28/29. All 374 compilation dependencies were frozen before
acceptance. Both complete owners add **424 bytes**; this owner contributes
**258**. All three observed/static affected bindings, including the
existing motion caller, 39 native suites and 151 tools pass.

Seal: `tools/oracle/arena_bounds_v1_manifest.json`; full gate evidence:
`extract/analysis/arena_bounds_v1_affected_portcheck.log`. This milestone
pins the preceding complete 1,378-binding 60% inventory checkpoint.
Coverage is **261,420 / 434,656 (60.14%)**, with **21,107 bytes remaining
to 65%**. The following sections describe the preserved preliminary pilots;
the final proof uses the combined `coverage_65_arena_bounds_*_v1` corpora
and `vf3matrixfamily_arena_bounds_dev_v1.exe`.


Original callable `0x8c0cb51e` has frozen owner `0x8c0cb532`, with 258
eligible bytes in two body spans. Its preceding 20-byte save/setup prefix
is outside the locked function inventory and earns no extra credit.

The routine reads a point-table pointer at actor offset `0x138c` and six
joint radii at `0x12ac + joint*4`. Original immutable selector bytes
8/28/48/52/76/104 are divided by four by SDK helper `0x8c042c20`, producing
joint indices 2/7/12/13/19/26. Each point has three floats; the routine uses
the first and third. It inflates each point by its radius, computes squared
violations of the original bounds **-28/+28**, and retains the largest
violation. It publishes two correction components at `0x13a8` and
`0x13b0`, setting actor flag `0x20000` when a correction wins.

Development varies finite points and radii across 64 configurations in
original states 21/26. All **127 valid specimens** cover the complete
258-byte owner and pass the isolated readable C candidate with zero native
skips. One interrupted specimen remains retained and excluded. The preliminary pilot alone received no
coverage credit; the combined qualification above establishes fresh acceptance.

The C candidate and a replacement matrix dispatch were compiled outside
the repository against the frozen vector-aggregation base library. Cache
`audio-evidence/ring_bound_candidate_v1/manifest.json` pins these sources,
the executable, base library, native report and base source manifest.
Repository compilation sources remained unchanged during the full 60% gate.
The candidate was then integrated and frozen again before fresh acceptance.

The real BSR at `0x8c0cb028` has `mov r14,r4` in its delay slot and returns
to `0x8c0cb02c`. Four finite configurations in each of states 28/29 produce
**eight successful original caller windows**, with no device accesses.
`tools/callable_ring_bound.py` validates the exact BSR target and delay,
ordered R13/R12/R11/R10/R9/FR15/FR13/PR saves, original opcodes and literal
pools, saved stack values, unchanged callee registers/XF/FPSCR, and actual
RTS with its R13-pop delay slot. Seven mutation tests reject forged evidence.
These windows qualify the caller boundary, not complete parent behavior.
Background AICA events do not establish a live C/audio comparison.

Evidence is `extract/analysis/coverage_65_ring_bound_dev_v1`,
`ring_bound_candidate_v1_native_report.json`,
`ring_bound_v1_original_caller_validation.json`, and
`ring_bound_v1_callable_tests.log`, with original caller capsules in cache
`ring_bound_original_caller_v1`. All captures use the unchanged original
interpreter and its previously sealed 102-file source archive.

The adjacent callable `0x8c0cb67a`, frozen owner `0x8c0cb69e` (166 bytes),
is a separate [radial correction pilot](radial_bound.md), with 128/128
development C matches and 16 qualified original caller windows. Its six-joint inputs include zero
vectors and points inside, on and outside radius eight. Actual BSRs at
`0x8c0cb66a` and `0x8c0cb66e` call it from the 32-byte wrapper `0x8c0cb65a`.
Neither the radial owner nor wrapper has new coverage credit.
