# Two-axis geometry and angle publication (2026-10-11)

Readable C for callable `0x8c0ca8c0` qualifies the 404-byte frozen owner
`0x8c0ca8da`. The original routine uses the signed angle at object +1394
and two floating components at +430/+438. It negates the second component,
solves intersections with a circle whose squared radius is 64, and repeats
after a quarter-turn. It publishes distances at +140c/+1410 and
+1568/+1564, and reflected angles at +2074/+2076 and +207a/+2078.
Those geometric roles follow the arithmetic; the fields' gameplay meanings
remain unqualified.

The quadratic helper `0x0c0ca838` and near-vertical helper `0x0c0ca894`
are also readable C. Both clamp values below the original epsilon before
square root. The main routine preserves the original threshold decisions,
operation order, fused multiply-adds, fixed trigonometric/angle helpers,
scratch registers, guest stack writes and floating-point save sequence.
The supported ABI uses single precision with FPSCR.SZ clear.

The initial C candidate omitted the sign inversion and passed only 10/128
cases. Original partial captures stopped at the quadratic call to isolate
the wrong component and intercept. The failed executable, source changes,
report and partial captures remain explicit diagnostics. After correction,
the final source (including its clarified clamp comment) was rebuilt and
frozen as native v3 with all **366 compilation source files**. The earlier
holdout is retained outside the credited proof; fresh acceptance follows
this exact source/native freeze.

Development passes **128/128** complete original cases from saves 21/26.
Fresh acceptance passes **127/127** valid cases from saves 28/29, with
changed finite values and angles, a relocated object and the other FPU bank.
One interrupted specimen is retained and excluded. There are no skipped
native cases or quarantined entries. Each corpus independently executes
every frozen owner byte, the whole prefix and both entire intersection
helpers. Expected results come only from original SH-4 execution.

Eight independent original observations start at the literal load
`0x0c0b04ea`, execute JSR `0x0c0b04ec` with its `mov r14,r4` delay,
and return through the actual RTS to `0x0c0b04f0`. The original target is
read from immutable pool `0x0c0b0568`. The new fixed
`vf3-geometry-literal-jsr-v1` contract checks the ordered integer/FR
prefix, all original opcodes and literal/MOVA pools, ordered restoration,
PR, stack, callee saves, FPSCR and XF bank. Six mutation tests reject
corrupted calls, prefixes, restores, state or pools. These observations
establish the call window, not a complete parent execution. Capsule device
accesses are zero; the one-shot audio observer records a background AICA
event, which is not claimed as a live C/audio comparison.

The hashed milestone adds **404 marginal verified bytes**:
**259,284 -> 259,688 / 434,656 (59.75%)**, with **1,372 bindings**.
The 26-byte prefix and 136 helper bytes have no additional frozen inventory
credit. The gaps are **1,106 bytes to 60%** and **22,839 bytes to 65%**.
The 65% target remains unmet.

Current regression passes five bindings: the new geometry, its original
caller owner `0x8c0b011e`, and all three qualified controller routines.
All **39 native suites** and **122 tool checks** pass. Opcode-ledger
selection finds no other observed helper callers. Generated fallthroughs
from an RTS delay into `0x0c0ca838` are not executable call edges. This is
an affected gate; previous full repository gates remain historical.

Inputs are reproduced by `tools/oracle/geometry_angles_inputs.py`.
The accepted milestone is `percentage_geometry_angles_v1_milestone.json`;
`geometry_angles_audit.py` seals sources, native executable, original
captures, reports, caller attribution, diagnostics, affected tests and the
preceding complete chain into `geometry_angles_v1_manifest.json`.

`tools/sh4dump.py` now enables Capstone's SH FPU mode for both linear and
recursive disassembly. Floating-point instructions previously printed as
raw `.word` values now decode, including the negation that motivated the
native correction. ROM bytes and frozen function intervals are unchanged.
