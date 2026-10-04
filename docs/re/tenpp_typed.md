# Typed input cohort toward the ten-point C milestone

Fifteen further functions add **3,298 unique C bytes**, raising the frozen C
address union to **189,834 / 434,656 (43.67%)**. The cumulative improvement
is **6.291 percentage points** from 162,490 bytes. The requested ten-point
milestone still requires **16,122 bytes**.

The cohort includes perspective matrix construction, matrix wrappers,
descriptor workers and vertex output routines. Static C control flow lives
in `src/fight/tenpp_planned_adapters.inc`, included by the vertex adapter
translation unit. Shared semantic helpers remain ordinary C calls, and
unknown destinations fail closed. The cohort translation reports 3,046
statements and zero unsupported instructions. Exploratory implementations
in the same modules receive no coverage credit without their own evidence.

Development uses fresh states 21 and 27 for each root, bounded integer
arguments, finite FR/XF values and alternating pointer fields. Every
credited root has at least 64 distinct complete inputs across both states
and executes 100% of its frozen body. There are **3,327 bound development
cases**. Independent acceptance uses relocated descriptors, another finite
floating point palette and a disjoint range of preserved register values;
all **480 acceptance cases** pass strict replay.

`tools/oracle/tenpp_typed_milestone.json` records the bindings, artifact
hashes, exact body intervals, union gain and ten explicit exclusions.
Its hash audit passes. Entries that execute in only one development scenario
remain excluded, even when their entire body and C replay pass.

Explicit FPSCR fixtures now invoke the interpreter's `UpdateFPSCR` so the
architectural register bank agrees with its internal bank bookkeeping.
The corrected perspective captures pass without changing the C matrix
kernel. Earlier captures with stale bookkeeping do not supply this cohort's
proofs. Fixture loading completes before frame counting starts, and probe
rollback preserves host CPU shutdown requests.

The full regression suite also passes using an immutable executable snapshot
of this cohort while additional captures continue. Its local output is
`extract/analysis/tenpp_arch_regression.log`.
