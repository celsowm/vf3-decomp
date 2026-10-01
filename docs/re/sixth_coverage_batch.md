# Sixth C coverage campaign

Frozen starting verified C union: **99,760 / 434,656 bytes (22.95%)**.
The delivery target is **+25,000 unique C body bytes**. Credit uses the
frozen baseline body ranges and the address union, never source file size or
execution hits.

## Candidate pool

The previous survey and a new static scan identify 55 unported asset-table
initializer bodies in the `0x8C0B` region (37,600 raw bytes). They are real
SH-4 functions: each saves PR and calls a loader helper with literal asset
IDs. Twenty-eight execute in both states 20 and 21 (17,370 body bytes).
Two more execute in states 20 and 27 (1,628 bytes). The independently
captured `0x8C074B0E` and `0x8C0750BE` workers add 6,120 bytes. These 32
functions have a **25,118-byte frozen union ceiling** before verification.

The 5,432-byte `0x8C0750BE` worker had only 44 distinct development inputs
in the prior campaign. Opposite action schedules and more saved states raise
its corpus to 82; `0x8C074B0E` has 112. Both pass strict development replay
and existing independent held-out/fresh runs. Their C control flow was
already present in the fight adapters but had no previous coverage credit.

## Loader development capture

`loader_variants.py` reads literal asset IDs from the untouched identity
image. Seven IDs actually passed by each watched initializer are varied
between zero and `0xFFFFFFFF`, the two empty sentinels accepted by the
original table helper. Selected IDs are disjoint within each watched cohort.
Fixtures are applied to original Flycast interpreter RAM immediately before
each watched entry and before its before-state snapshot. State 21 fixtures
were applied at startup where the table persists unchanged until entry.
Every fixture path and SHA-256 digest is stored in the batch manifest.

The common 28 bodies use 32 fixtures in state 20 and 32 in state 21, with
64 or 128 distinct complete cases per body. Their 28 C adapters pass full
strict development replay. The remaining two use distinct fixtures in
state 27 plus an untouched boot-mix run from state 20, establishing two
state/input scenarios. No fixture capture is used as held-out or fresh
acceptance.

Four newly reached bodies lacked a C owner. `sixth_loader_adapters.c`
provides static C control flow from the original image for those roots and
delegates already owned helpers through `matrix_family`. The other 26
loader bodies reuse existing `next_adapters` C. Unknown destinations fail
closed.

## Acceptance and credit

Untouched held-out runs use states 38 and 30. Untouched fresh runs use state
41 and boot. Every promoted body must pass all observed cases in both groups,
have at least 64 distinct complete development cases across two scenarios,
and have no unfinished invocation, skip, out-of-bounds effect, or failed
strict comparison. Replay checks registers, inactive integer banks, XF,
FPUL, GBR, return PC, touched RAM, and ordered device accesses.

The final manifest `tools/oracle/sixth_batch.json` binds each credited body
to its exact C source, development cases, independent replay reports,
provenance, artifact hashes, frozen intervals, and measured union gain.
`tools/oracle/audit_sixth_batch.py --hashes` rechecks these records and the
development fixture hashes. The complete project gate is
`python tools/verify_all.py --no-build --jobs 4` after a full C build.

## Result

All 32 candidates passed the development, held-out, and fresh strict replay
gates with zero skipped cases. The frozen unique C address union increased
from 99,760 to **124,878 bytes**, a gain of **25,118 bytes** or 5.78 percentage
points of the 434,656-byte baseline. Verified C coverage is **28.73%**.
The audited batch contains 3,716 bound development cases across the 32
functions. The held-out and fresh loader runs used untouched RAM images.

The coverage ledger now reports 166,276 rigorously accounted C and SDK bytes
(38.3%). The ported-body sum is 125,718 bytes; it includes 840 overlapping
bytes, so the unique C address union is the appropriate C coverage figure.
These are verified invocation boundaries, not evidence that the whole game
has been translated into high-level source.
