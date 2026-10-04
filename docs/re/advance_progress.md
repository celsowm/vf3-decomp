# Next ten-point campaign progress

The campaign starts at 206,062 unique C bytes and targets 249,528 bytes.
The first accepted batch adds **488 bytes**, reaching **206,550 / 434,656
(47.5203%)**. The remaining shortfall is **42,978 bytes**.

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

## Capture triage

The first broad queue comprises 150 roots with 40,984 potential marginal bytes;
potential is not credit. Captures are serial and resumable with
`isolate_planned.py`; a `STOP` file pauses between roots for acceptance captures.
The next queue contains 150 roots with one unresolved dynamic call site each,
representing another 29,384 potential bytes before overlap and proof.

`0x8c04a4c4` reaches 500/506 body bytes, but its entry path sets R11=1 before
the missing R11=0 exit. Keep it uncredited while the frozen boundary is reviewed.
The revised `0x8c0877ac` probe reaches 276/280 bytes; its remaining conditional
exit appears incompatible with the preceding squared-value comparison and
needs a reachability review. `0x8c0c8334` remains blocked on descriptor/table
state and incomplete variants. Failed or incomplete corpora remain uncredited.

Reusable preparation is committed as `a36d511`. The previous sixteen-milestone
chain was reaudited with all artifact hashes; all passed. Frozen original image,
inventory, body ranges, prior baseline, and prior manifests are preserved.
