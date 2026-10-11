# Scene contact frame: qualified C

`src/fight/contact_frame.c` implements original uncached callable
`0x0c0a0aec`. Frozen owner `0x8c0a0b00` contributes **458 new bytes**.
The twenty-byte prefix saves R14 through R8 and FR15/FR14 and loads the
scene-global pointer; it earns no extra bytes.

The scene mask `0x80001` selects the bypass. Otherwise the routine chooses
one of two output objects and visits eighteen twelve-byte descriptors.
Enabled descriptors build position and direction triples, invoke the
existing point-response helper, damp contact velocities and signed angle
deltas, run the qualified aggregation frame, and store a matrix for the
slot. Actor records advance by `0x1d8` after enabled slots; output matrices
advance by 64 bytes after every slot. The signed angle comparisons cover
both half-turn boundaries before floating conversion and truncation.
Matrix state follows the original helpers, including the active path's XF
changes. Full architectural and RAM comparisons verify those changes.

Original development on states 21/26 passes **125/125 valid cases**;
fresh holdout on states 28/29 passes **126/126**. Both execute every frozen
owner instruction, with zero native skips. Three development interruptions
and two holdout interruptions remain in the raw evidence and are excluded.
Inputs vary the scene mask, object selection, enabled slots, counted
points, finite triples and signed angles. Holdout changes values, relocates
owned objects and uses the alternate floating bank.

The initial input pilot reached 438/458 bytes because the first signed
angle field remained zero. Expanded v2 inputs reach 458/458 independently
in both campaigns. The first C candidate matched 77/125 cases and exposed
an incorrect FPUL state index. Its executable, source and failed report
are preserved in `contact_frame_candidate_v1`; it earns no credit. The
corrected `vf3matrixfamily_contact_frame_dev_v2.exe` and **377 compiled
dependencies** were frozen before holdout capture and remained unchanged.

The genuine caller is BSR `0x8c0a115e` (`bcc5`) with its original NOP
delay and return at `0x8c0a1162`. Eight original-only windows on states
28/29 verify the complete save prefix, saved stack slots, callee registers,
original literal pools and ordered restoration through RTS `0x8c0a0d2e`.
These windows qualify this boundary, without claiming the complete caller
scene state machine. Background AICA events are retained as observer data
and confer no device credit.

The affected selection checks all matrix-binding opcode ledgers, the
changed callable, real BSR and its frozen parent owner `0x8c0a0f3a`.
All **four affected bindings**, **39 native suites** and **165 tool tests**
pass. All 190 default executables are archived. The final audit seals
`contact_frame_v1_manifest.json` and pins the preceding aggregation-frame
seal and full 60% checkpoint.

Verified readable C is **262,428 / 434,656 (60.38%)**. **20,099 bytes**
remain to reach 65%; the next full inventory gate is due at 62.5%.
