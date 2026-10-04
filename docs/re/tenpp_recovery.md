# Recovery of previously exercised bodies

Thirty-three functions add **2,134 unique C bytes**. The frozen union reaches
**196,658 / 434,656 (45.24%)**, a **7.861 percentage point** gain from the
162,490-byte baseline. The ten-point target still requires **9,298 bytes**.

Development recaptures use fresh states 21 and 28, bounded integer arguments,
finite floating point registers and typed pointer fields. Every credited
root executes 100% of its frozen body, has at least 64 distinct complete
inputs and appears in both source scenarios. The milestone binds **8,355
development cases**. All **1045 independent acceptance cases** pass strict
replay with relocated fixture pointers and another finite palette. One
additional root has no complete acceptance cases and receives no credit.

`tools/oracle/tenpp_recovery_milestone.json` records exact body intervals,
strict reports, exclusions, artifact hashes and the union gain. Its hash
audit passes. Static C is in `src/fight/tenpp_recovery_adapters.inc`; observed
original-image callee paths supplement statically reachable branches. The
cohort emits 9,072 statements with zero unsupported instructions. BIOS calls
and two floating point scratch-register mismatches remain excluded.

Replay uses the immutable local executable
`build/vf3matrixfamily_recovery_second.exe`. Exploratory code in the same
module receives no coverage credit without its own proof.
