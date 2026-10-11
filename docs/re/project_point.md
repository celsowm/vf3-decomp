# Homogeneous point projection (2026-10-11)

`src/fight/project_point.c` implements exact callable and frozen owner
`0x8c03d9b0`, a contiguous 126-byte body ending at `0x8c03da2e`.
The readable source calls the existing matrix save, homogeneous transform,
and restore helpers; divides transformed x/y by w; scales and offsets the
viewport coordinates; and reflects viewport y. Guest scratch assignments,
stack contents, FPUL, both floating banks, FPSCR, T, and return PC remain
part of the strict behavioral contract.

The input point is R4 and the two-component result is R5. The routine loads
its matrix from the original fixed matrix address `0x0c19d4d8`, preserving
the incoming XF matrix through the existing stack helper. The viewport
scale/offset fields are `0x0c0ea534`, `0x0c0ea538`, `0x0c0ea540`, and
`0x0c0ea53c`. Incoming XF fixtures vary the saved matrix; they do not replace
the matrix subsequently loaded by the original function.

Development uses 64 finite point variants in each original state 21/26,
with finite incoming XF matrices and viewport fields. Independent acceptance
changes points and viewport fields, relocates point/result objects by
`0x100000`, switches the incoming floating bank, and uses original states
28/29. Each campaign passes **128/128**, independently executes all
**63 PCs / 126 bytes** of the owner, and retains zero excluded specimens,
quarantine or native skips. Matrix helpers also execute in these complete
windows. All results come from original instructions, with no helper-answer
or instruction substitutions.

The final `vf3matrixfamily_project_point_dev_v1.exe` and all **370 compiled
dependencies** were frozen before acceptance. The unchanged original
observer remains `flycast_task_return_boundary_v1.exe` with 102 pinned
linked sources. `tools/oracle/project_point_v1_manifest.json` seals the
full dependency archive, native executable, raw original capsules, input
patches, state/emulator provenance, complete architectural reports, affected
regression, archived native suites, and cumulative percentage extension.

No direct BSR/BRA target or literal pointer to this exact entry was found in
the original image, and no prior matrix opcode ledger executes it. All
ledgers were available. The new affected binding, **39 native suites**,
and **124 tool tests** pass. This establishes standalone finite-domain
behavior; a production caller is not yet established. The full current
binding inventory gate remains due at 60%.

The milestone adds **126 unique readable C bytes**, taking verified C to
**260,302 / 434,656 (59.89%)**, with **1,376 bindings**. Remaining gaps are
**492 bytes to 60%** and **22,225 bytes to 65%**. Prior clipped-vertex
percentage and implementation seals remain explicitly pinned historical
evidence. Its caller documentation was corrected from BRA to BSR at
`0x8c05849a`; the opcode and immutable earlier selection evidence were
already correct.
