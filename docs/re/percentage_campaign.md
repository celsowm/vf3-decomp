# Percentage expansion campaign — 2026-10-08

Objective: the [coverage expansion plan](coverage_expansion_plan.md), with
65% as the main checkpoint and a ten-percentage-point stretch target. The
immutable starting union is 248,754 / 434,656 bytes. The stretch freeze is
`tools/oracle/percentage_coverage_baseline.json`; the main checkpoint is
282,527 bytes. Neither the frozen original image nor body ranges changed.

## Resource and callback milestone

Nine complete frozen bodies add **406 unique C bytes**, reaching
**249,160 / 434,656 (57.32%)**. All pass original development and independent
acceptance replay with zero skips. Development contains 1,368 distinct
complete cases; acceptance contains 4,400, in disjoint states 23/29 with
writable fixture relocation by `0x100000`. Each body is complete in both
corpora. The milestone hash audit passes.

New readable C replaces the static callback selector at `0x8c059400` and
implements resource acquisition/reset (`0x8c05cace`) and allocation range
lookup (`0x8c061ba8`). The selector installs nine original callback literals
at their task slots and preserves invalid-selector behavior. Acquisition
uses the original resource callee and clears five state words only after
success. Range lookup preserves the original signed comparisons, byte-sized
list index, exclusive start containment and inclusive requested end. These
three roots account for 262 bytes; six other roots use existing C owners.

Proofs: `percentage_static_complete_dev`, `percentage_resources_complete_accept`,
`percentage_resources_dev_replay.json`, and `percentage_resources_accept_replay.json`
under `extract/analysis`. Immutable executable:
`build/vf3matrixfamily_percentage_resources_dev.exe`, SHA-256
`1eefa3b3791ef15ba3bece3427af797a9cd84a4497745078b1d3da54570b7001`.
Manifest: `tools/oracle/percentage_resources_milestone.json`.
The full integrated regression remains due at the planned checkpoints.

## Packed motion-transition command

Readable `src/fight/motion_flag_command.c` adds **406 unique bytes**, reaching
**249,566 / 434,656 (57.42%)**. This completes the older 249,528-byte campaign
target by 38 bytes. The new 65% checkpoint still needs **32,961 bytes**.

The command decodes unaligned little-endian words, tests the record's selector
and object flags, applies the float threshold, selects one of two motion
pairs, checks the prior motion's flag combination, and advances the real
motion dispatcher by twelve bytes. Original scratch registers, stack stores,
callee and return behavior remain part of strict replay. Development caught
and corrected two reversed branch conditions before acceptance began.

Merged development executes **406/406 bytes** and passes **4,860/4,860 cases**
in states 21/27. Independent acceptance changes record ordering, unknown
selectors, prior motions, finite float values and object initialization, with
buffers relocated by `0x100000` in states 23/29. It executes **406/406 bytes**
and passes **3,783/3,783 cases**, zero skips. The milestone hash audit passes.
Invalid specimens are retained; neither final corpus has an incomplete
invocation or nondeterministic entry.

Input recipes are `tools/oracle/motion_flag_{registers,development_memory,
development_crosses,acceptance_memory}.json`. Use `isolate_planned.py` with
the register recipe and the corresponding memory recipe. Development merges
384 variants of the memory recipe (160 frames) and 2,048 variants of the
crosses recipe (600 frames), states 21/27, `--global-fields`. Acceptance uses
2,048 variants and 600 frames, states 23/29, `--holdout-inputs --relocation
0x100000`. The frozen watch is `pc 0x8c0af1a4`; record seeds supply no expected
outputs. An earlier 200-frame development pilot ended during an invocation
and was not used in the accepted proof.

Evidence: `percentage_motion_flags_complete_dev`,
`percentage_motion_flags_v3_replay.json`, `percentage_motion_flags_accept`,
and `percentage_motion_flags_accept_replay.json` under `extract/analysis`.
Immutable executable: `build/vf3matrixfamily_percentage_motion_v3_dev.exe`,
SHA-256 `bc3889b07e5df50172c69b6ff6599871357e2db660373b2c10f9f7e1bc8b8d47`.
Manifest: `tools/oracle/percentage_motion_flags_milestone.json`.
All **43** campaign-tool checks pass; integrated regression is still due.

## Development triage

The retained-report catalog has 40 uncredited full-body leads with 3,096
potential unique bytes, including previously blocked acceptance and BIOS
boundaries. Those leads have not been promoted from the advisory index.
Updated linked ownership identifies 134 implementation-closed roots with
12,090 potential bytes; ownership supplies no verification credit.

The bounded pilots cover 32 initial roots, 102 additional linked-closure
roots, and 100 shared-family callers. They use original interpreter execution
in states 21/27 with typed fields, finite float registers and independent
comparison-boundary dimensions. Invalid/incomplete specimens remain in raw
manifests and provide no proof. Raw evidence is retained under
`percentage_static_dev`, `percentage_static_extended_dev` and
`percentage_family_dev`. Repeating the queue without a new input hypothesis
is not a next step: most larger families need original caller contracts or
specific missing predicates.

Directed menu input work is ongoing and receives no partial-body credit.
Free space rose from about 4.9 to 50 GiB
during the session. The decoded-cache scan was stopped without applying any
deletion; captures retain a 4 GiB reserve.
