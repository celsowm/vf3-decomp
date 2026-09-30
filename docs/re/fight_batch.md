# Fight worker and shared-helper batch

## Target and starting point

Starting verified C union: **28,538 bytes**, frozen denominator **434,656 bytes**.
Delivery requires at least **15,000 newly verified unique bytes** (43,538 total).
Candidate body ranges contain 16,964 primary bytes and 24,390 with reserves;
these forecasts are not coverage credit.

## Pipeline milestone

The previous matrix audit now stores its starting address spans. Future ledger
growth cannot change that historical comparison. Verification and dependency
planning load all tracked `*_batch.json` manifests.

Dependency cost follows original-image control flow beyond fragmented Ghidra
seeds, includes transitive static calls and tails, and charges for unresolved
destinations. Three synthetic checks cover long helpers, tail boundaries and
unresolved indirect calls. Eight existing capture-integrity checks still pass.

Adapter generation accepts explicit roots and a named output module. Matrix
generation retains its defaults and reproduces the prior source SHA-256 exactly:
`f090b61ba8ddfc76d033aec40c2cc4a8001f92186c23fedd61ed2dd3c2f689cf`.
Separate modules reuse known matrix code; ownership is chosen before execution.

Development watches primary callers, reserve callers and required helpers.
Runs use states 7, 30 and 37 plus the 4,800-frame boot-mix input. Held-out runs
use states 10, 24 and 44 and a boot schedule shifted by 240 frames.
No first-transfer exits are configured. Interrupted, device-dependent and
overflow specimens are excluded; unfinished invocations are accounted separately.

No new C-byte credit is claimed by this enabling milestone.

## Worker and helper implementation milestone

Added static caller adapters for original-image code and hand-written angle
lookup and mesh-cell algorithms. The mesh worker reads the real cell table,
walks linked records and calls the classifier; it uses no stubbed node values.
The angle kernel reads the game's complete atan ramp from mapped RAM.

The new adapters are split into four source files at return boundaries.
Whole root control flow takes precedence over fragmented Ghidra seeds, fixing
a copy helper whose jump table previously crossed adapter ownership.
Architecture-specific banked-register code and foreign dynamically installed
code remain unsupported. Failed execution never retries another module.

Build and all existing port regressions pass. The combined nine-run discovery
corpus passes 54/61 entries with at least 64 cases. The seven failing entries
are withheld, along with smaller corpora that do not meet promotion thresholds.
Fresh states 12, 35 and 43 are reserved for the final acceptance check.

The 5,432-byte `0x8C0750BE` worker has only one eligible invocation across the
first four development runs; fifteen other samples touch device memory.
Its body receives no credit. Captures therefore also watch the 65 executed,
unported baseline entries of at least 200 bytes, extending the reserve pool.
Final ledger promotion waits for the complete release replay and byte audit.
