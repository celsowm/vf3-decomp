# Matrix clip dispatch continuation (2026-10-07)

The original callable helper starts at `0x8C04A320` (BSR callers at
`0x8C04A2C0` and `0x8C04A2F4`). The frozen `0x8C04A4C4` entry is inside
its first interpolation path. Completing the pending translations in
`matrix_adapters.c` and `tenpp_expanded_adapters.c` closes the BRAF path at
`0x8C04A446`. The expanded adapter's ownership list includes the new labels.
Unknown destinations retain the existing dispatch policy.

## Original control flow

Three transformed vertex groups occupy FR4..7, FR8..11 and FR12..15.
Comparisons at `0x8C04A3A4/A8/AC` build a three-bit mask from transformed
fourth components and the caller's threshold (R12 bits loaded into FR2).
Mask zero emits without intersection; mask seven skips the triangle.

| Mask | BRAF destination / direct branch | Vertex order | Intersection path |
| ---: | --- | --- | --- |
| 1 | direct `0x8C04A4F2` | A, B, C | two triangles |
| 2 | `0x8C04A44A` | C, A, B | two triangles |
| 3 | `0x8C04A45A` | B, C, A | one triangle |
| 4 | `0x8C04A46A` | B, C, A | two triangles |
| 5 | `0x8C04A47A` | C, A, B | one triangle |
| 6 | `0x8C04A48A` | A, B, C | one triangle |

The BRAF offset is `(mask - 2) * 16`, relative to `0x8C04A44A`.
Its delay slot copies the first vertex's second register pair to FR2/3.
Pair moves retain FPSCR.SZ behavior. Both interpolation paths preserve
arithmetic order, FPUL transfers and RAM writes.

`tools/oracle/matrix_clip_indirect_targets.json` records the five reviewed
targets. `translate_adapters.py --indirect-targets` closes their static
paths even when a development corpus did not execute them. It validates
jump sites, alignment and image bounds and supplies no expected outputs or
coverage credit. Reproduce the single-root translation with:

```powershell
Set-Content extract/analysis/target_matrix_braf_watch.txt 'pc 0x8c04a4c4'
python tools/oracle/translate_adapters.py extract/analysis/target_final_dev_04a4c4 --watch extract/analysis/target_matrix_braf_watch.txt --function vf3_clip_repro --out extract/analysis/target_matrix_repro.c --indirect-targets tools/oracle/matrix_clip_indirect_targets.json
```

## NaN payload mismatch

Completing the dispatch initially passes 844/852 strict development cases.
The first remaining mismatch is a stored NaN at `0x0C406184`, case 15
(zero-based ordinal 14, original state-21 capsule invocation 17). The
original stores `0xFFC00000`; the C model stores `0xFFFFFFFF`.

The local capture executable's scalar FMUL handler at host
`0x1401B79A0` loads FRm into XMM0, then multiplies by FRn. FADD at
`0x1401B78C0` has the same operand order. FSUB and FDIV instead load FRn
first. SSE selects the destination operand's NaN payload when both operands
are NaNs. The C model's `x * y` and `x + y` cannot guarantee this order.

`vf3_fpu_binary` explicitly selects and quiets that payload when both inputs
are NaNs, after arithmetic in the existing saved host environment. This
models the capture interpreter, not the real SH-4's reversed NaN convention.
Single-NaN and finite inputs retain their behavior. Sixty-four additional
checks exercise both operand orders, signs, signaling NaNs, rounding modes,
DN and restoration of the caller's rounding mode.
Compiling the previous model with the project's `-O3` release flags fails
32/64 new checks; the fixed model passes all 64. The old model happens to
pass at `-O0`, confirming the allocation-dependent behavior. The negative
control is `extract/analysis/target_matrix_braf_nan_negative_control.log`.

## Verification and remaining proof

The retained development corpus comes from original expanded-near
state-21/27 capsules. All **852/852** strict cases pass with **zero skips**,
comparing registers, XF, FPUL, exit PC and captured RAM. The native FPU suite
passes **213,056/213,056** cases; **41** campaign-tool tests pass. The complete
CMake build passes. The final snapshot and replay report are
`build/vf3matrixfamily_target_braf_final.exe` and
`extract/analysis/target_matrix_braf_final_dev_replay.json`.
The snapshot SHA-256 is
`f22f61e5c7be17c430fb843a2aa6c812e5e9123da513ca4334d1e6dbd3d69c63`.
All 61 added instruction-word annotations per adapter agree with the untouched
image (`extract/analysis/target_matrix_braf_image_audit.json`).

Body execution remains **500/506 bytes (98.8%)**. The missing PCs are
`0x8C04A432/434/436`, the return when no triangle has been emitted. The
interior entry at `0x8C04A4C4` reaches `mov #1,r11` at `0x8C04A4E4` before
the loop exit; later paths retain or set that flag. The real callable entry
initializes R11 to zero at `0x8C04A32A`. More blind inputs at the interior
entry do not resolve this missing exit contract. Further proof needs
original-helper captures through `0x8C04A320`, including an all-discarded
stream, plus independent acceptance.

No bytes are promoted. Verified coverage remains **248,248/434,656**;
**1,280 bytes** remain to the campaign target. Storage is below the existing
4 GiB capture reserve; no fresh capture or cache deletion was attempted.
The integrated regression uses frozen bindings in
`target_matrix_braf_bindings.json` and writes
`target_matrix_braf_regression.log` under `extract/analysis`.
It finishes with **`verify_all: PASS`**, **1,280/1,280 bound replays**, zero
replay failures, passing native tests and all 41 tool checks. Parsed terminal
status is `extract/analysis/target_matrix_braf_regression_status.json`.
