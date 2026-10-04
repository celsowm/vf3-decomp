# Next ten-point campaign progress

The campaign starts at 206,062 unique C bytes and targets 249,528 bytes.
Eight accepted batches add **7,534 bytes**, reaching **213,596 / 434,656
(49.1414%)**. The remaining shortfall is **35,932 bytes**.

## Descriptor initializers

`0x8c037e6e`, `0x8c037f2e`, and `0x8c037ffe` initialize related object records.
The frozen seeds occur 14 bytes after their original prologues. Fixtures retain
the established R0=64 indexed offset, R3=8 selector, R4=0 field value, and
`0x03f3ffff` header already stored through R14. The port follows original field
writes and invokes existing helpers for subsequent setup and tail behavior.

All three bodies execute completely. Strict replay passes **1,530/1,530
development cases** across states 21/27 and **765/765 independent acceptance
cases** across states 23/29, with zero skips. Acceptance changes the finite
input palette and relocates fixture pointers by `0x100000`. No acceptance
results were used to change the implementation.

Source: `src/fight/advance_closure_adapters.c` (244 emitted statements, zero
unsupported instructions). Immutable replay binary:
`build/vf3matrixfamily_advance_initializers.exe`. Proof:
`tools/oracle/advance_initializers_milestone.json`. The full CMake build and
artifact-hash/union audit pass. Full repository regression passes, including
all 949 previously bound replays and native replay tests. The new bindings
pass their separate strict development and acceptance runs. The retained
regression log is `extract/analysis/advance_initializers_regression.log`.

## Scene workers and nested helpers

Six new worker bodies add 1,278 unique bytes: `0x8c03dad0`, `0x8c03ea22`,
`0x8c06c6d6`, `0x8c085666`, `0x8c0abcdc`, and `0x8c0ca0c6`.
Development passes 2,669 strict cases. Independent acceptance uses states
23/29, relocated fixtures and holdout inputs. The seventh implemented worker,
`0x8c04baf6`, passes replay but remains uncredited because its acceptance
capture includes an incomplete invocation.

The worker source is `src/fight/advance_worker_adapters.c`; the immutable proof
executable is `build/vf3matrixfamily_advance_workers.exe`. Three existing shared
helpers receive fresh whole-body proof and add another 222 bytes:
`0x8c06c398`, `0x8c06c5c8`, and `0x8c08583c`. Their development replay passes
1,485 cases and acceptance passes 1,376 cases, with zero skips. Ownership is
recorded per source in `tools/oracle/advance_helper_ports.json`.

Nested capture exposed an oracle rollback bug, fixed in `cb36f29`. See
`docs/re/nested_capture_boundary.md`. Only fresh corrected child observations
support the helper milestone. The campaign union and all three manifests pass
the artifact-hash audit. Repository regression passes; its retained
log is `extract/analysis/advance_workers_regression.log`.

## Completed recaptures and original gameplay

Longer development recaptures (150 frames per state) finish all invocations in
20 previously complete-body candidates. Nineteen pass strict development and
independent acceptance, adding 3,876 unique bytes. `0x8c047230` fails at an
external firmware dependency and remains uncredited. Eight one-call workers
add 984 bytes; two descriptor leaves add 192 bytes. Fresh probe-only acceptance
also clears the incomplete-invocation blocker on `0x8c04baf6`, adding 162 bytes.

The accepted expanded batch is implemented in `advance_worker_adapters.c`.
It passes all seven earlier parent replays again. The full CMake build passes.
The previous integration's regression passes all 952 bound replays plus native
tests; the expanded integration's regression is running separately in
`extract/analysis/advance_expanded_regression.log`.

Seven original-gameplay routines add 332 unique bytes, with 4,775 strict
development cases from states 10/20/25/40 and independent acceptance from
states 14/23/29/44. A filtered development corpus preserves provenance and
excludes an unrelated quarantined entry. New proof reports hash the immutable
executable `build/vf3matrixfamily_advance_natural_proof.exe`.

The original gameplay failures are retained. `0x8c03523c`, `0x8c045f62`, and
`0x8c062ec4` reach the emulator's GD-ROM firmware trap (`0x8c001006`, opcode
`0x085b`), which the current C dependency model cannot reproduce. `0x8c094242`
fails device/register replay. No partial successes from these entries are
counted. The larger gameplay bodies also retain missing body paths.

## Remaining queue execution

The first broad queue comprises 150 roots with 40,984 potential marginal bytes;
potential is not credit. Captures are serial and resumable with
`isolate_planned.py`; a `STOP` file pauses between roots for acceptance captures.
The next queue contains 150 roots with one unresolved dynamic call site each,
representing another 29,384 potential bytes before overlap and proof.
The next 500 previously unattempted zero-dynamic-call roots represent 32,840
potential unique bytes. They include smaller SDK-attributed routines needing
actual C invocation proof; attribution is not counted as C coverage.

`0x8c04a4c4` reaches 500/506 body bytes, but its entry path sets R11=1 before
the missing R11=0 exit. Keep it uncredited while the frozen boundary is reviewed.
The revised `0x8c0877ac` probe reaches 276/280 bytes; its remaining conditional
exit appears incompatible with the preceding squared-value comparison and
needs a reachability review. `0x8c0c8334` remains blocked on descriptor/table
state and incomplete variants. Failed or incomplete corpora remain uncredited.

Reusable preparation is committed as `a36d511`. The previous sixteen-milestone
chain was reaudited with all artifact hashes; all passed. Frozen original image,
inventory, body ranges, prior baseline, and prior manifests are preserved.
