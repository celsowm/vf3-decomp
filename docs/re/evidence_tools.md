# Reusable evidence commands

Use these commands instead of temporary Python snippets when inspecting
captures, replay failures, caller contracts and coverage campaigns.
Run from the repository root. Set an output directory on the drive with space:

```powershell
$evidenceCache = 'C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence'
```

## Inspect existing evidence

`tools/oracle/evidence_inspect.py` has five read-only subcommands. Its optional
`--out` precedes the subcommand and refuses an existing report.

```powershell
python tools/oracle/evidence_inspect.py status extract/analysis/strip_parent_full_633_checkpoint_v1.log --suite portcheck

python tools/oracle/evidence_inspect.py capture --batch "$evidenceCache/coverage_65_selection_unlock_accept_v3_export/batch_manifest.json" --owners tools/oracle/coverage_65_selection_unlock_accept_v3_owners.json --image extract/gamedata/1ST_READ.BIN

python tools/oracle/evidence_inspect.py case "$evidenceCache/coverage_65_selection_unlock_combined_accept_v1_export" --entry 0x8c0c3210 --case 1117 --window 20

python tools/oracle/evidence_inspect.py case extract/analysis/coverage_65_motion_frame_dev_v3 --entry 0x8c0a94d0 --case 7 --address 0x0c5fa2c4 --bytes 4

python tools/oracle/evidence_inspect.py profile extract/analysis/coverage_65_motion_frame_dev_v3 --entry 0x8c0a94d0 --register r5 --offset 0x3c --offset 0x1a00 --bytes 2
```

`status` checks terminal log markers and the expected binding inventory. It
does not infer that a process is running from an unfinished log. Choose
`--suite verify_all` when checking the complete repository gate.

`capture` reads completed raw capsule files and reports invocation accounting,
excluded flags, distinct inputs, device events and owner instruction gaps per
original state. With `--image`, it checks original instructions and literal
pools. It also reports identical captured inputs with different outputs.
These diagnostics do not qualify a campaign or grant C coverage.

`case` uses one-based replay case numbers and zero-based RAM window indices.
It prints the original capsule/invocation references, all 16 GPRs, stack
pointer and before/expected bytes. Repeat `--address` to inspect additional
RAM addresses; mirrors are accepted, and `--bytes` selects a 1..16-byte read.
Addresses outside the captured windows are reported as `null`. To inspect
that original record, use the reported capsule path and invocation ID:

```powershell
python tools/oracle/evidence_inspect.py sample ORIGINAL_CAPSULE_PATH --id 142 --pc 0x8c040f4e
```

This reports selected instruction hits, final instructions, floating-point
store instructions, architectural-state size, device events and fingerprints.
It does not reconstruct every effective write address from opcodes.

`profile` reads little-endian values at repeated offsets from a selected GPR
across every case in a corpus. It reports value frequencies, uncaptured reads
and a few examples per offset. The command is useful for profiling actor
fields such as motion ID and cycle length, but its output is diagnostic and
does not establish the meaning of those fields or grant replay coverage.
Use `--width OFFSET:BYTES` when fields have different storage widths and
`--joint` to include a per-case cross-tab of all requested offsets. For
example, this keeps the actor kind byte separate from the motion ID and cycle
halfwords:

```text
python tools/oracle/evidence_inspect.py profile extract/analysis/coverage_65_motion_frame_dev_v3 --entry 0x8c0a94d0 --register r5 --offset 0x61 --offset 0x3c --offset 0x1a00 --bytes 2 --width 0x61:1 --joint
```

`tools/mt_pose_capture_compare.py` compares before/after MT channels, the 23
variable-stride joint records, the 18 selector attachment rows at actor
`+0x180`, the 23 bone matrices, and cached-pose records for selected retained
cases. It is diagnostic only and does not assign MT channels to a joint or POL
part. The attachment rows are reported by selector index because
`fighter_refresh.c` dispatches selector `i` with matrix row `i`. Details and
example output are in `docs/re/mt_fields.md`. `--summary --per-case` adds a
compact row per specimen with the actor pointer, motion ID, cycle, animation
record pointer, and changed-region counts. `--matrix-bin` exports the selected
case's 23 bone matrices for offline render experiments, and requires exactly
one case whose RAM windows contain the full matrix region. This replaces
manually reading each case when one watched update captures several fighters:

```text
python tools/mt_pose_capture_compare.py extract/analysis/native_pose_reobserve_next_s29_v1 --entry 0x8c0ae0ec --actor-register r14 --summary --per-case
```

Repeat `--actor-range OFFSET:SIZE` to compare arbitrary 4-byte-aligned spans
relative to the actor pointer. The summary reports availability and changed
word counts per case and for the corpus; add `--verbose` on a selected case to
include changed words and their float interpretations. For example, this
checks the stable vectors and mutable state used around the three
`0x8C09EAF2` aim-frame calls:

```powershell
python tools/mt_pose_capture_compare.py `
  extract/analysis/native_pose_orchestration_s29_v1 `
  --entry 0x8c09eaf2 --actor-register r4 --summary --per-case `
  --actor-range 0xcc:0x30 --actor-range 0xfc:0x40 `
  --actor-range 0x15c:0x24 --actor-range 0x640:0xc0 `
  --actor-range 0x740:0xc0 --actor-range 0x1f20:0x80 `
  --actor-range 0x1f60:0x24 --actor-range 0x22e8:0x10
```

The report remains diagnostic: a changed region does not by itself establish
that the watched entry owns pose generation or define the channel mapping.

For the `0x8c09eaf2` orchestration corpus, the new attachment-row counts show
that cases 1, 2, and 4 change all 18 selector rows; case 3 changes selector
row 1. All four cases leave the 63 MT channels, 23 output bone matrices, and
cached-pose records unchanged. This narrows the native pose producer to the
orchestration and its actor inputs, while leaving the action-to-motion and
MT-channel mapping open:

```powershell
python tools/mt_pose_capture_compare.py `
  extract/analysis/native_pose_orchestration_s29_v1 `
  --entry 0x8c09eaf2 --actor-register r4 --summary --per-case
```

The orchestration indexes a 108-byte fighter-kind record at `0x0c10d3c4` by
the actor's byte at `+0x61`. `tools/native_pose_type_table.py` prints the raw
record words and their finite float interpretations without naming unknown
fields. In the retained target-pair state, Akira and Jacky use kinds 0 and 7:

```powershell
python tools/native_pose_type_table.py extract/exe/1ST_READ.unsc.bin `
  --base 0x8c010000 --kind 0 --kind 7
```

Both selected records contain repeated segment-parameter values; their
semantic field meanings still need to be recovered before all constants can
feed the native pose builder. The three float3 bases at `+0x18`, `+0x24`, and
`+0x3c` are directly passed by `0x8C09EAF2` into its aim-frame calls. Those
records and vector accessors now live in `src/native/pose_data.c`; the other
record words remain unclassified.

`tools/pose_state_inventory.py` scans retained savestates for the two actor
records, summarizes their motion fields and matrix quality, and can export the
matrix and variable-stride joint rows for later comparisons. For example, the
six-state scan used by the native-port pose investigation is:

```powershell
python tools/pose_state_inventory.py `
  --state-dir tools/emu/flycast-build/data `
  --image extract/exe/1ST_READ.unsc.bin `
  --actor 0x0c1fefe4 --actor 0x0c20138c `
  --matrix-dir extract/analysis/native_pose_inventory_all6_v1/matrices `
  --joint-dir extract/analysis/native_pose_inventory_all6_v1/joints
```

`tools/native_pose_audit.py` bundles that inventory with slot/matrix candidate
reports. It retains matrix and joint dumps, writes the actor and basis summary
to `pose_audit.json`, and creates transformed-AABB CSVs only for actor/state
pairs with 23 usable matrices. Supply `--model ACTOR:KIND=POL` to select a
model and filter by the actor's `+0x61` kind byte; omit `:KIND` only when the
model mapping is valid across all scanned states. Repeat it for additional
actors. The output directory must be new and inside the repository.

```powershell
python tools/native_pose_audit.py `
  --image extract/exe/1ST_READ.unsc.bin `
  --state-dir tools/emu/flycast-build/data --pattern 'vf3_2[6-9].state' `
  --actor 0x0c1fefe4 --actor 0x0c20138c `
  --model 0x0c20138c:7=extract/gamedata/MKAO_JAC.POL `
  --out extract/analysis/native_pose_audit_s26_s29_v4
```

The bundle remains diagnostic: usable matrix bases and candidate bounds do not
identify a fighter, map a POL slot to a matrix row, or recover the MT channels.

To repeat the full retained-state scan for the fixed Akira/Jacky matchup, use
both actor-kind filters and the default `vf3_*.state` pattern. This directory
currently contains states 26, 27, 28, 29, 45, and 46:

```powershell
python tools/native_pose_audit.py `
  --image extract/exe/1ST_READ.unsc.bin `
  --state-dir tools/emu/flycast-build/data `
  --actor 0x0c1fefe4 --actor 0x0c20138c `
  --model 0x0c1fefe4:0=extract/gamedata/MKAO_AKI.POL `
  --model 0x0c20138c:7=extract/gamedata/MKAO_JAC.POL `
  --out extract/analysis/native_pose_audit_target_pair_s26_s46_v2
```

The report records all twelve actor/state combinations and produces candidate
CSVs only for states whose actor kind matches the selected model and whose
matrix rows have usable basis vectors. It does not infer slot-to-matrix
assignments.

`tools/pose_slot_matrix_report.py` exports every selected tagged POL slot paired
with each matrix row in a 1..64-row dump. It transforms the corners of each
slot's local bounding box using the same matrix convention as the offline SDL
preview, relative to row 0. The native pose audit still supplies the 23-row
bone table; a state export with `--matrix-offset 0x180 --matrix-count 18` can
instead inspect the attachment transforms used by the live fighter draw loop.
This replaces ad hoc candidate-coordinate calculations; the AABB report does
not identify the correct assignment.

```powershell
python tools/pose_slot_matrix_report.py `
  extract/gamedata/MKAO_JAC.POL `
  extract/analysis/native_pose_inventory_s26_s27_v2/matrices/vf3_27_actor_0c20138c.bin `
  --slot 17 --slot 18 --slot 19 --slot 20 --slot 21 --slot 22 `
  --csv extract/analysis/native_jacky_slot_matrix_candidates_s27_v1.csv
```

For Jacky state 27, the 26 model slots 17–42 produce 598 slot/matrix candidate
rows. They retain local and transformed bounds for manual review. The sequential
slot-to-row hypothesis remains rejected, and the report does not replace that
missing rig evidence.

The state-27 actor's 18 attachment matrices at `0x0c20150c..0x0c20194c` are
all nondegenerate, with unit-length basis columns; rows 10 and 11 duplicate row
0. Export and inspect them with:

```powershell
python tools/flycast_pose_export.py tools/emu/flycast-build/data/vf3_27.state `
  --image extract/exe/1ST_READ.unsc.bin --actor 0x0c20138c `
  --matrix-offset 0x180 --matrix-count 18 `
  --matrix-bin extract/analysis/vf3_27_jacky_attach_matrices.bin
python tools/pose_matrix_inspect.py extract/analysis/vf3_27_jacky_attach_matrices.bin
python tools/pose_slot_matrix_report.py extract/gamedata/MKAO_JAC.POL `
  extract/analysis/vf3_27_jacky_attach_matrices.bin `
  --csv extract/analysis/vf3_27_jacky_attachment_slot_candidates.csv
```

The last command produces 558 candidates. These are candidate transforms from
the live attachment table, but they still do not assign model slots to rows.

`tools/oracle/native_motion_input_sweep.py` runs each 16-bit KEYF mask from the
same savestate in a separate corpus, pulses it for a selected frame interval,
and reports watched calls at `0x0C0AD1B8`. It writes each replay schedule and a
combined Markdown summary under a new output directory. The tool refuses to
replace an existing directory. Its captures have no frame timestamps, so a
reported ID is evidence for that replay only; no call means the tested replay
did not exercise the watched entry.

```powershell
python tools/oracle/native_motion_input_sweep.py `
  --state tools/emu/flycast-build/data/vf3_29.state `
  --emulator tools/emu/flycast-build/flycast_v3.exe `
  --out extract/analysis/native_motion_input_s29_v3 `
  --input 0x12 --input 0x21 --input 0x42 --input 0x81 `
  --frames 180 --press-frame 5 --release-frame 20
```

`--base-play` adds a clean baseline replay and injects each mask into a shared
control schedule. The tool compares the ordered actor/motion/return-PC samples
with the baseline; a matching sequence means that intervention did not change
those captured calls, without establishing broader input semantics. Pulses
that exactly match the base input for the entire interval are rejected.

```powershell
python tools/oracle/native_motion_input_sweep.py `
  --state tools/emu/flycast-build/data/vf3_29.state `
  --emulator tools/emu/flycast-build/flycast_v3.exe `
  --base-play tools/vf3_play_motion_strikes.txt `
  --out extract/analysis/native_motion_context_s29_new `
  --input 0x21 --frames 1800 --press-frame 75 --release-frame 90
```

The first s29 screens at `extract/analysis/native_motion_single_input_s29_v2`
and `native_motion_combo_input_s29_v1` completed without any watched calls.
They are negative screens, not evidence that those controls cannot select a
motion. A contextual run with the 1,800-frame strike script reproduced two
samples, `0x2A9` for actor `0x0C1FEFE4` and `0x953` for actor `0x0C20138C`. A
`0x21` pulse at frames 75–89 left that ordered sample sequence unchanged; the
`0x12` pulse at frames 15–29 also left it unchanged. Both comparisons are
scoped to those captured calls.

`tools/mem_watch.py` is the reusable Flycast RAM-access recorder. It keeps the
legacy `STATE ADDRESS LENGTH` form and also accepts a savestate path, repeated
`--watch-range ADDRESS:LENGTH`, a control script, and an explicit emulator. It
writes the watch specification, binary trace, and emulator log under
`extract/analysis` by default, and refuses to overwrite an existing output.
`--changes-only` reduces repeated values; `--limit 0` prints every matching
trace record. For the retained s29 strike-input sequence, the trace showed
actor 1 changing from motion `0x63E`/cycle 50 to `0x2A9`/cycle 160, and actor 2
from `0x3F5`/cycle 40 to `0x953`/cycle 64. The animation-record pointers stayed
at `0x0C226864` and `0x0C227064` respectively. The trace is ordered but has no
frame timestamp, so it proves the observed field transitions under that input
sequence, not the action labels.

```powershell
python tools/mem_watch.py tools/emu/flycast-build/data/vf3_29.state `
  --watch-range 0x0c1ff020:2 --watch-range 0x0c2009e4:2 `
  --watch-range 0x0c200ce4:4 --watch-range 0x0c2013c8:2 `
  --watch-range 0x0c202d8c:2 --watch-range 0x0c20308c:4 `
  --play tools/vf3_play_motion_strikes.txt --frames 1800 `
  --emulator tools/emu/flycast-build/flycast_v3.exe `
  --name native_mt_fields_both_s29_rerun --changes-only --limit 300
```

`tools/oracle/native_motion_eval_watch.txt` contains the nested evaluator
entry `0x0C09D6E0` for `tools/oracle/reobserve.py`. The sparse corpus omits
actor `+0x3C`, so `mt_capture_match.py --motion-id` accepts the independently
observed ID for exactly one selected case and labels it as explicit. Cases 1
(`0x2A9`) and 8 (`0x953`) each have 13 exact matches among 91 packs, including
`MTAIKJAC.BIN` and `MTJACKAG.BIN` respectively; duplicate matches mean these
are candidates, not unique character/action assignments.

`tools/mt_capture_eval_compare.py` places the native raw evaluator beside the
captured post-processed channel block. A sparse case may use `--motion-id` and
`--frame` when those fields are independently known. For s29, case 1 at motion
`0x2A9`/frame 1 with `MTAIKJAC.BIN` reports 30/63 channels unchanged; case 8 at
motion `0x953`/frame 1 with `MTJACKAG.BIN` reports 27/63. These values are
diagnostic only because the guest output has passed through `0x8C09F432`.

```text
python tools/mt_capture_eval_compare.py extract/analysis/native_motion_eval_s29_v1 --entry 0x8c09d6e0 --case 1 --motion-id 0x2a9 --frame 1 --asset MTAIKJAC.BIN --vfa build/vf3_assets.vfa
python tools/mt_capture_eval_compare.py extract/analysis/native_motion_eval_s29_v1 --entry 0x8c09d6e0 --case 8 --motion-id 0x953 --frame 1 --asset MTJACKAG.BIN --vfa build/vf3_assets.vfa
```

`tools/pol_model_inventory.py`, `tools/pol_model_headers.py`, and
`tools/pol_slot_inspect.py` are read-only POL inspectors used to replace ad hoc
geometry/slot dumps. The inventory reports tagged mesh bounds, textures
(including `none` for the ROB_WO2 all-ones untextured sentinel), and
vertex/index counts; the header tool prints the six raw model-header words and
the first mesh header's center, radius, flags, texture and data size; the slot
inspector displays bounded raw payloads and possible in-file references.
Header and geometry values do not establish rig or body-part semantics;
format details and examples are in `docs/formats/POL.md`.
Pass `--find-slot-references` to `pol_slot_inspect.py` to scan complete untagged
payloads for direct pointers to tagged geometry slots with or without the
low-bit tag, and `--before-bytes 0x34`
to include the bytes immediately preceding each selected slot target. The
context is raw evidence only; it does not assign a header or link meaning.
Use repeated `--file-range OFFSET:SIZE` to inspect exact candidate chain targets
as hex and little-endian dwords, bounded by the POL file size.

`tools/pol_index_map_scan.py` scans untagged spans for aligned little-endian
u8/u16/u32 runs that could be compact slot or bone indices. It defaults to
23 pose rows, the tagged-model count, and the POL slot count as candidate
lengths; `--max-index`, `--length`, `--min-unique`, and `--sentinel` make the
search bounds explicit. The Akira/Jacky scan found no qualifying Jacky run; its
only Akira run is a short unaligned record-like sequence and is not a rig map.
The scan is a filter for possible compact arrays, not proof of mapping.

```text
python tools/pol_index_map_scan.py extract/gamedata/MKAO_AKI.POL extract/gamedata/MKAO_JAC.POL
```

`tools/fighter_matrix_rows.py IMAGE --base 0x8c010000` dumps the raw
32-byte rows indexed by the matrix setup routine at `0x8C09132E` using a
selector byte at `0x0C29B880`. That routine reads halfwords at row offsets
`+8` and `+10` for two `FSCA`/`FTRV` matrix steps; other fields and the
selector's meaning remain unclassified. Use repeated `--row N` to inspect
selected rows:

```text
python tools/fighter_matrix_rows.py extract/exe/1ST_READ.unsc.bin --base 0x8c010000 --row 12
```

`tools/flycast_ram.py STATE --image IMAGE` extracts the serialized 16 MiB SH-4
RAM from a Flycast savestate for offline inspection. It locates RAM from a
unique image prefix or, when runtime changes have modified that prefix, from
three or more matching image chunks distributed across the loaded image.
Repeat `--read ADDRESS:SIZE` for bounded reads (including SH-4 aliases), or
use `--dump PATH` to write a raw RAM image; existing dump files are never
overwritten. This reads saved-state evidence only and is not part of the native
port's runtime path. For example:

```text
python tools/flycast_ram.py tools/emu/flycast-build/data/vf3_29.state --image extract/exe/1ST_READ.unsc.bin --read 0x0c095178:0x40 --read 0x0c404000:0x100
```

`tools/flycast_state_profile.py` reads the same bounded RAM fields from each
of several savestates. Use `ADDRESS+OFFSET:SIZE` for fields inside a known
record, or `ADDRESS:SIZE` for a direct range. It reuses the validated RAM
locator, prints the bytes for every state, and never modifies the files. This
helps distinguish stable actor fields from values that change across scenes;
the output is evidence only and does not establish a field's meaning or add a
runtime dependency to `vf3port`. `--summary` groups identical byte values per
field and lists the states carrying each value, replacing manual comparison
when profiling the same offsets across a state set.

```powershell
python tools/flycast_state_profile.py `
  tools/emu/flycast-build/data/vf3_26.state `
  tools/emu/flycast-build/data/vf3_27.state `
  tools/emu/flycast-build/data/vf3_29.state `
  --image extract/exe/1ST_READ.unsc.bin `
  --read 0x0c1fefe4+0x61:1 --read 0x0c1fefe4+0x3c:2 --summary
```

`tools/mem_trace_decode.py TRACE` decodes an already-retained memory access
trace without launching Flycast. Repeat `--watch-range ADDRESS:LENGTH` to
focus on selected fields and `--pc GUEST_PC` to keep only accesses from chosen
guest instructions. The PC filter also works with `--summary`. `--writes`,
`--changes-only`, and `--limit 0` narrow or expand the output. Trace record
order has no frame timestamps. For example:

```text
python tools/mem_trace_decode.py extract/analysis/native_mt_fields_both_s29_v1.bin --watch-range 0x0c1ff020:2 --changes-only
```

Use `--summary` for counts of recorded memory-access events by access PC and
guest address; these are not instruction execution counts. The range and write
filters still apply:

```text
python tools/mem_trace_decode.py TRACE --watch-range 0x0c1ff020:2 --summary
```

To inspect a memory-to-memory matrix copy, filter its source-load and
destination-store PCs together:

```powershell
python tools/mem_trace_decode.py TRACE --pc 0x0c03b568 --pc 0x0c03b56c `
  --watch-range 0x0c201b4c:0x1000 --limit 0
```

`tools/pose_trace_report.py TRACE --actor ADDRESS` groups FA20 trace writes by
actor-relative fields and writer PC. Repeat `--field NAME:OFFSET:LENGTH` to
choose fields, and `--pc-label ADDRESS:LABEL` to name known instruction sites
that are missing from the Ghidra function CSV. `--values` prints each watched
address's last observed value. `--export-range OFFSET:COUNT --matrix-bin PATH`
exports consecutive 4x4 rows; repeat `--export-row OFFSET` with
`--matrix-bin PATH` to export sparse rows in the supplied order. Both use the
last-written word at each matrix address. Because the trace has no frame
timestamps, an export combines writes across the run and is not an atomic pose
snapshot. `--out PATH` writes a JSON report without replacing an existing file.
For the state-47 orchestration example, see
`docs/re/native_decomp_port.md`.

```powershell
python tools/pose_trace_report.py `
  extract/analysis/pose_orchestration_outputs_s47_600_v1.bin `
  --actor 0x0c20138c `
  --field row_0200:0x200:0x100 `
  --field row_0300:0x300:0x100 `
  --field row_0480:0x480:0x100 `
  --pc-label 0x0c03b56c:matrix_copy `
  --pc-label 0x0c03b62e:matrix_store `
  --values --top 2
```

`tools/motion_probe_report.py` prints the actor pointer and candidate motion
value from a retained golden PC-watch JSON or capsule-derived `.cases` file.
For `0x8C0AD1B8`, it reports the raw value and a configurable masked value
(default mask `0x1FFF`); `--show-pr` adds the saved return PC. A supplied
`KEYF` schedule is printed separately. These samples have no frame timestamps,
so the tool does not correlate them to individual input events or assign
action labels:

```text
python tools/motion_probe_report.py extract/analysis/goldens_actions2/f_0c0ad1b8.json `
  --play-script extract/analysis/vf3_play_actions2.txt
python tools/motion_probe_report.py extract/analysis/native_motion_action_probe_s29_v4/f_8c0ad1b8.cases --show-pr
```

The natural s29 capsule records actor `0x0C1FEFE4` with r5=`0x2A9` and actor
`0x0C20138C` with r5=`0x953`; both have PR=`0x0C0A995A`. Disassembly shows the
caller reads the current halfword from the descriptor pointer at actor `+0x58`
before calling the motion update. These samples confirm the current motion IDs
at that update; they do not identify the input action that selected them.

`tools/mem_watch.py --decode-trace TRACE` remains a convenience entry point
and uses the same decoder. Its capture mode is separate and is not needed to
inspect retained trace files.

`tools/mt_state_match.py STATE --image IMAGE --actor ACTOR` follows a live
actor's mounted motion record in a savestate and compares its bounded MT
streams with the extracted packs. It complements `mt_capture_match.py` when a
corpus shadow does not include the pages holding the motion record:

```text
python tools/mt_state_match.py tools/emu/flycast-build/data/vf3_29.state --image extract/exe/1ST_READ.unsc.bin --actor 0x0c1fefe4
```

Rows can be shared by many pairing packs; an exact stream match locates the
asset row but does not identify the fighter or action. Use `--verbose` to list
all exact pack matches.

`tools/flycast_pose_export.py STATE --image IMAGE --actor ACTOR` reports the
actor kind bytes, motion ID, cycle length, and the 23 bone matrices at
`actor+0x7C0`. `--matrix-bin PATH` writes the matrix span as 1,472 little-endian
bytes for an offline preview; `--json` includes every matrix word. A zero
matrix span is called out as unusable pose data, since the state may predate
the bone-pose pass. The output does not assign bones to POL slots or MT
channels. `--joint-bin PATH` separately exports the 23 64-byte prefixes at
the variable-stride joint records beginning at actor+0x180. It reads the
advance bytes from image address `0x0C119670`, preserving repeated rows where
the advance is zero; these joint records are distinct from the output
matrices.

`tools/native_motion_timeline_probe.py` can retain these fields across a replay.
Use `--include-joints` to write `joint_timeline.jsonl` with the 63 postprocessed
channels and 23 raw 64-byte prefixes from the variable-stride joint records.
`--sample-range START:END:STEP` adds sparse checkpoints in a half-open frame
range; set `--checkpoint` beyond the run length to capture only those frames.
The records preserve their bytes and offsets without assigning meanings to
their fields.

`tools/native_motion_window_rank.py TIMELINE` ranks contiguous windows with
changing motion phase and joint records, helping choose a capture interval
with useful motion. It does not assign meanings to the changing fields.

`tools/native_joint_channel_correlate.py TIMELINE [TIMELINE ...]` ranks same-motion,
same-cycle, same-descriptor, same-record-pointer phase pairs by linear
correlation between channel changes and float32 interpretations of joint-record
words. Use `--min-pairs` to set the minimum number of frame pairs, and `--out`
to retain JSON under `extract/analysis`. Multiple captures are kept as separate
tracks; `--consensus-min-tracks` reports candidate channel/word links that recur
across distinct capture, motion, and record tracks. Correlation is a lead only;
even a repeatable fit does not establish a channel mapping.

```text
python tools/native_motion_timeline_probe.py --state tools/emu/flycast-build/data/vf3_29.state --frames 1150 --checkpoint 1150 --sample-range 840:1115:5 --image extract/exe/1ST_READ.unsc.bin --actor 0x0c1fefe4 --actor 0x0c20138c --include-joints --out extract/analysis/native_motion_pose_s29_joint_dense_v1
python tools/native_joint_channel_correlate.py extract/analysis/native_motion_pose_s29_joint_dense_v1/joint_timeline.jsonl --max-gap 5 --min-pairs 10 --out extract/analysis/native_motion_pose_s29_joint_dense_v1/joint_channel_correlation_tracks.json
python tools/native_motion_timeline_probe.py --state extract/analysis/flycast_pose_capture_s26_v1/data/vf3_47.state --frames 600 --checkpoint 600 --sample-range 30:590:10 --image extract/exe/1ST_READ.unsc.bin --actor 0x0c1fefe4 --actor 0x0c20138c --include-joints --out extract/analysis/native_motion_pose_s47_joint_10f_30_600_v1
python tools/native_motion_timeline_probe.py --state extract/analysis/flycast_pose_capture_s26_v1/data/vf3_48.state --frames 600 --checkpoint 600 --sample-range 30:590:10 --image extract/exe/1ST_READ.unsc.bin --actor 0x0c1fefe4 --actor 0x0c20138c --include-joints --out extract/analysis/native_motion_pose_s48_joint_10f_30_600_v1
python tools/native_motion_window_rank.py extract/analysis/native_motion_pose_s47_joint_10f_30_600_v1/joint_timeline.jsonl --max-gap 10 --window-samples 12 --min-phase-pairs 5 --out extract/analysis/native_motion_pose_s47_joint_10f_30_600_v1/ranked_windows.json
python tools/native_joint_channel_correlate.py extract/analysis/native_motion_pose_s47_joint_10f_30_600_v1/joint_timeline.jsonl extract/analysis/native_motion_pose_s48_joint_10f_30_600_v1/joint_timeline.jsonl --actor 0x0c20138c --max-gap 10 --min-pairs 10 --consensus-min-tracks 3 --out extract/analysis/native_motion_pose_s47_s48_joint_correlation_v1.json
```

The state 47 and 48 runs each replayed 600 frames and sampled frames 30–580
every 10 frames. Their combined Jacky report found a repeatable lead from
channel 1 to word 13 at actor offsets `+0x180` and `+0x440` in four distinct
tracks spanning motion IDs `0x05C8`, `0x060F`, and `0x0B1C` (median absolute
correlation 0.9998; median normalized fit RMS 0.0207). Treat this as a field
correlation lead only; it does not show that either record is a joint transform
or provide the joint-to-POL mapping needed by the renderer.

`tools/pose_state_inventory.py --image IMAGE --state-dir DIR --actor ADDRESS`
repeats that inspection over retained states and reports how many rows have
three nonzero basis vectors. Repeat `--actor` for another actor address and
use `--matrix-dir DIR` to retain each matrix dump and `--joint-dir DIR` to
retain each variable-stride joint dump under a state-and-address name. It does
not label character IDs or choose a POL part map.

`tools/native_pose_timeline_extract.py` builds the same `pose_timeline.jsonl`
format from a probe's `motion_timeline.csv` and its saved checkpoint states.
It includes the 23 variable-stride joint records, 18 attachment matrices, and
23 bone matrices. This recovers pose data when an earlier capture used
`--include-joints` without `--include-pose`; it reads retained states offline
and does not replay Flycast. `native_pose_channel_correlate.py --table joints`
compares the packed angle groups to those intermediate joint matrices, while
`--table bones` and `--table attachments` inspect their later stages.

```text
python tools/flycast_pose_export.py tools/emu/flycast-build/data/vf3_26.state --image extract/exe/1ST_READ.unsc.bin --actor 0x0c20138c --matrix-bin extract/analysis/vf3_26_jacky_matrices.bin
python tools/flycast_pose_export.py tools/emu/flycast-build/data/vf3_28.state --image extract/exe/1ST_READ.unsc.bin --actor 0x0c1fefe4 --joint-bin extract/analysis/vf3_28_akira_joint_rows.bin
python tools/native_pose_timeline_extract.py --timeline extract/analysis/native_motion_pose_s48_joint_10f_30_600_v1/motion_timeline.csv --image extract/exe/1ST_READ.unsc.bin --actor 0x0c20138c --out extract/analysis/native_motion_pose_s48_joint_10f_30_600_v1/pose_timeline_joints_v1.jsonl
python tools/native_pose_channel_correlate.py extract/analysis/native_motion_pose_s48_joint_10f_30_600_v1/pose_timeline_joints_v1.jsonl --actor 0x0c20138c --table bones --feature rotations --max-gap 10 --output extract/analysis/native_motion_pose_s48_joint_10f_30_600_v1/pose_channel_correlation_bones_v1.json
python tools/native_pose_channel_correlate.py extract/analysis/native_motion_pose_s48_joint_10f_30_600_v1/pose_timeline_joints_v1.jsonl --actor 0x0c20138c --table joints --feature rotations --max-gap 10 --output extract/analysis/native_motion_pose_s48_joint_10f_30_600_v1/pose_channel_correlation_joints_v1.json
```

`tools/pose_matrix_inspect.py MATRIX.bin` reads either retained matrix dump
and prints each row's translation relative to bone 0 and the lengths of its
three basis columns, plus a count of rows with usable nonzero bases.
`--basis-epsilon` adjusts the minimum length threshold and `--json` includes all
16 words per row. `tools/pose_dump_diff.py LEFT.bin RIGHT.bin` reports exact
word changes per fixed-size row (64 bytes by default), useful for comparing
captured joint prefixes or matrices. These keep inspection reproducible without
hand-written binary-reading snippets; their output remains evidence only and
does not assign POL-part names.

`tools/pose_matrix_correspondence.py LEFT.bin RIGHT.bin` ranks row
correspondences between two captured matrix tables. It normalizes each basis
column before comparing its direction and compares translations relative to a
selected root row in each table. Use `--left-root`, `--right-root`, `--top`, and
`--json` to control the report. A close pair is a diagnostic lead, not proof
that the game maps one table to the other:

```powershell
python tools/flycast_attachment_matrices.py `
  extract/analysis/flycast_pose_capture_s26_v1/data/vf3_47.state `
  --image extract/exe/1ST_READ.unsc.bin --actor 0x0c20138c `
  --matrix-bin extract/analysis/jacky_s47_attachments_compare.bin
python tools/flycast_pose_export.py `
  extract/analysis/flycast_pose_capture_s26_v1/data/vf3_47.state `
  --image extract/exe/1ST_READ.unsc.bin --actor 0x0c20138c `
  --matrix-bin extract/analysis/jacky_s47_bones_compare.bin
python tools/pose_matrix_correspondence.py `
  extract/analysis/jacky_s47_attachments_compare.bin `
  extract/analysis/jacky_s47_bones_compare.bin --top 12
```

```text
python tools/pose_state_inventory.py tools/emu/flycast-build/data/vf3_26.state tools/emu/flycast-build/data/vf3_27.state --image extract/exe/1ST_READ.unsc.bin --actor 0x0c1fefe4 --actor 0x0c20138c --matrix-dir extract/analysis/native_pose_inventory_s26_s27_v2/matrices --joint-dir extract/analysis/native_pose_inventory_s26_s27_v2/joints
python tools/pose_matrix_inspect.py extract/analysis/native_pose_inventory_s26_s27_v2/matrices/vf3_27_actor_0c20138c.bin
python tools/pose_dump_diff.py extract/analysis/native_pose_inventory_s26_s27_v2/joints/vf3_26_actor_0c20138c.bin extract/analysis/native_pose_inventory_s26_s27_v2/joints/vf3_27_actor_0c20138c.bin
python tools/pol_model_headers.py extract/gamedata/MKAO_JAC.POL --slot 17 --slot 42
```

The two Jacky joint exports above differ in 269 words across all 23 rows even
though both report motion `0x5C8` at cycle 48; the motion fields alone do not
fix the pose inputs.

`tools/pose_builder_probe.py` makes a controlled call to the original
`0x8C091438` bone-pose builder at a reached guest PC. It creates a watch list
and entry patch in a new output directory, then runs `golden_batch.py` with
capsule and probe accounting enabled. By default it opens the builder's draw
gate and rolls the call back before the saved game resumes. This captures a
completed call against that state, but does not establish that the saved render
context was naturally initialized; inspect the basis lengths before using any
output for a renderer experiment.

```text
python tools/pose_builder_probe.py --state tools/emu/flycast-build/data/vf3_26.state --actor 0x0c1fefe4 --actor 0x0c20138c --out extract/analysis/native_pose_builder_probe_s26_v2 --emulator tools/emu/flycast-build/flycast_v3.exe --frames 120
python tools/mt_pose_capture_compare.py extract/analysis/native_pose_builder_probe_s26_v2 --entry 0x8c091438 --case 1 --actor-register r4 --matrix-bin extract/analysis/native_pose_builder_probe_s26_v2/akira_matrices.bin
python tools/mt_pose_capture_compare.py extract/analysis/native_pose_builder_probe_s26_v2 --entry 0x8c091438 --case 2 --actor-register r4 --matrix-bin extract/analysis/native_pose_builder_probe_s26_v2/jacky_matrices.bin
python tools/pose_matrix_inspect.py extract/analysis/native_pose_builder_probe_s26_v2/jacky_matrices.bin
```

In the state-26 probe, five cases completed (three Akira, two Jacky) and all
23 matrix rows changed. The captured basis vectors are zero, so those
matrices are translation-only and cannot drive the Jacky preview. A natural
state-27 capture has usable bases for the Jacky actor, while the Akira actor
in that state is kind 4. This gives a valid Jacky fixture without closing the
part mapping or supplying the target Akira fixture.

`build/vf3nativeviewtest.exe --slot N ... --output IMAGE.bmp` renders the same
tagged POL slot IDs for Akira and Jacky over the two ST01 layers. The
character-specific `--aki-slot N` and `--jac-slot N` options render different
IDs per package, including Jacky-only slots 22–42; these cannot be requested
with shared `--slot`. The default is slot 3. This is a visual inspection aid
only: the image does not identify a slot's gameplay or rig role. Build it with
`cmake --build build --target vf3nativeviewtest`.
`--grid-aki` and `--grid-jac` write a contact sheet of every tagged slot in
ascending slot order; the tool prints each cell-to-slot mapping alongside the
output path. For a diagnostic pose experiment, `mt_pose_capture_compare.py
--matrix-bin` exports one captured actor matrix table and
`vf3nativeviewtest --jac-bone-candidate --pose-bin FILE` applies the candidate
mapping Jacky slots 17–39 → matrix indices 0–22 relative to the root
translation. State 27's Jacky matrices are a valid fixture, but that sequential
mapping still scatters parts and remains rejected. The state-26 target Akira
matrix span is zero, and a 1,800-frame natural reobserve did not enter the
matrix builder. States 47/48 later supply usable matrices for both target
actors (see the next section); none of these offline previews sets the runtime
mapping.
The state-27 comparison is reproducible with:

```text
build/vf3nativeviewtest.exe --jac-bone-candidate --pose-bin extract/analysis/native_pose_inventory_s26_s27_v2/matrices/vf3_27_actor_0c20138c.bin --output extract/analysis/vf3_jac_s27_candidate.bmp
```
Examples:

```text
build/vf3nativeviewtest.exe --slot 1 --output build/vf3_native_slot1.bmp
build/vf3nativeviewtest.exe --slot 3 --output build/vf3_native_slot3.bmp
build/vf3nativeviewtest.exe --slot 1 --slot 3 --output build/vf3_native_slots1_3.bmp
build/vf3nativeviewtest.exe --jac-slot 22 --output build/vf3_jacky_slot22.bmp
build/vf3nativeviewtest.exe --aki-slot 3 --jac-slot 22 --output build/vf3_parts_aki3_jac22.bmp
build/vf3nativeviewtest.exe --grid-jac --output build/vf3_jacky_slot_grid.bmp
build/vf3nativeviewtest.exe --jac-bone-candidate --pose-bin extract/analysis/native_pose_bones_s29_v1/case1_matrices.bin --output build/vf3_jacky_bone_candidate.bmp
```

`tools/oracle/reobserve.py` replays the original run specification from a
corpus manifest while watching already-executed nested entries. Use repeated
`--run NAME` options to select only available runs from a multi-run manifest;
omitting them preserves the whole original batch. Older manifests that do not
record the emulator can use the explicit `--emulator PATH` override. For
example:

```text
python tools/oracle/reobserve.py --batch-dir extract/analysis/next_dev_cases --children extract/analysis/native_pose_reobserve_children.txt --run s29 --watch-mode children --emulator tools/emu/flycast-build/flycast_v3.exe --out extract/analysis/native_pose_reobserve_next_s29_v1
```

## Build isolated readable candidates

`tools/oracle/build_isolated.py` copies the current static library, dispatcher,
runner and optional C candidates into a new directory, compiles there and
records the inputs, archived headers, compiler commands and executable hashes.
Candidate routes follow the existing FPSCR guard. The normal build is untouched.

```powershell
python tools/oracle/build_isolated.py --config tools/oracle/build_configs/scene_replay_development.json --out "$evidenceCache/scene_replay_example_v1"

python tools/oracle/build_isolated.py --memory-diagnostic --out "$evidenceCache/memory_diagnostic_example_v1"
```

The JSON config contains `sources` and `routes`; each route supplies `entries`,
a C `function` name and optional `entry_argument: true`. Entries are normalized
to physical addresses, and duplicate aliases are rejected.

`--memory-diagnostic` adds byte previews inside the existing RAM mismatch branch.
The strict comparisons and failure returns remain active. Run the executable
through `tools/oracle/verify_matrix.py --executable PATH`, which enables strict
replay. Existing output directories are refused.

This is a development builder, not a qualified compiled-source freeze: it pins
the copied static library binary rather than archiving its entire source closure.
Normal integration still requires `compiled_source_freeze.py` and the established
development, independent acceptance and full regression gates. Historical builders
remain intact because earlier proofs pin their exact bytes.

## Seal an authored caller contract

`tools/oracle/seal_callable.py` attaches hashed original caller manifests to an
authored owner-to-contract JSON and runs the existing callable validators against
every supplied corpus. It does not infer a caller contract from addresses.

```powershell
python tools/oracle/seal_callable.py --template tools/oracle/scene_input_transition_callable_v1.json --caller-manifest "$evidenceCache/scene_input_transition_original_dispatch_v1/manifest.json" --corpus "$evidenceCache/coverage_65_scene_input_transition_combined_dev_v1_export" --reference-key original_dispatch_manifests --out "$evidenceCache/scene_callable_example_v1.json"
```

Repeat `--caller-manifest` or `--corpus` as needed. The default reference key is
`original_caller_manifests`; scene table contracts use `original_dispatch_manifests`.
The command rejects an existing output and callers that change during validation.

## Freeze a fixed coverage target

`freeze_campaign.py` now accepts an exact byte-union target as well as its existing
percentage-point option:

```powershell
python tools/oracle/freeze_campaign.py --target-bytes 282527 --out "$evidenceCache/next_65_campaign_example_v1.json"
```

It verifies the frozen image/inventory/body hashes and that the coverage dashboard
agrees with the ledger. At the current checkpoint this records baseline 275,276,
target 282,527 and remaining gain 7,251. It preserves earlier campaign files.

## Verification of these tools

The reusable builder reproduced the known selection acceptance result exactly:
1,386/1,388 matches, zero skips, with failures at cases 1,117 and 1,353. The caller
sealer validated the existing scene dispatch proof, and the exact-target freezer
reproduced the 7,251-byte gap. The isolated scene build and replay results are
recorded in `extract/analysis/scene_replay_reusable_dev_v1_scene_native.json`.
Tool tests live in `tools/oracle/test_reusable_evidence_tools.py`; immutable earlier
335-test checkpoint logs remain preserved. The current oracle discovery run passes
all 346 tests. The reusable scene build also passes all 1,514 combined helper cases
with zero skips (`scene_replay_reusable_dev_v1_helpers_native.json`).

## Repeat an original counterexample

`capsule_repeat_recipe.py CAPSULE --id N --transfer RTS_ADDRESS --out NEW_JSON`
prepares a diagnostic recipe for `audio_one_shot.py`. It restores all captured
RAM words and the 55 architectural values supported by the unchanged observer,
setting FPSCR before FR/XF. The observer cannot assign the eight inactive GPR
bank values, so equality of all 63 captured words must be checked afterward.
The original explicit return boundary must appear in the source instruction trace.

`compare_original_samples.py LEFT RIGHT --left-id N --right-id M --out NEW_JSON`
compares two complete RAM-only records, including all 63 architectural values,
captured pages and outputs. It reports input differences separately from output
differences and never grants coverage or automatically quarantines an owner.
Original image, execution provenance and accounting still need their established
audits. `selection_unlock_observable_audit.py` applies those checks to the two
selection counterexamples and seals their owner-wide exclusion evidence.
Instruction comparisons normalize cached and physical address aliases. The
current oracle discovery run, including repeat-tool identity checks, passes
all 351 tests (`extract/analysis/original_repeat_tools_tests_v2.log`).

## Measure candidate coverage margins

`candidate_margin.py --owner OWNER --owner OWNER --target-bytes 282527 --out NEW_JSON`
subtracts the accepted address union from the selected frozen bodies and combines
overlapping candidate ranges once. It pins the dashboard, ledger and inventory
inputs but remains advisory: a candidate's potential bytes are not verified bytes.
An owner can have a substantial frozen body and zero marginal gain because its
addresses already appear in accepted spans. The current scene/helper pool offers
6,462 marginal bytes, leaving a 789-byte shortfall against the 7,251-byte gap.

## Merge original development campaigns

`merge_development.py --batch BATCH --batch BATCH --owners OWNER_MAP --image ORIGINAL_BIN --out NEW_CORPUS --proof NEW_JSON`
requires complete invocation and frame accounting, original instruction/pool
identity, all 63 architectural values, no device events in valid records,
complete owner bodies and 64 distinct inputs per original state by default.
It combines valid cases through the established capsule converter and rejects
nondeterministic entries. The resulting original-development proof grants no
C coverage and still needs strict native replay, caller proof and the full
independent acceptance workflow. The round-decision merge produces 1,003 cases
and independently covers its 882-byte owner in both original states.

## Preserve and qualify normal builds

`preserve_historical.py --proof PROOF --source-archive SOURCE_MANIFEST --out NEW_ARCHIVE --manifest NEW_JSON`
validates frozen hashes before copying mutable workspace dependencies into a
historical archive. Existing archives are preserved. This keeps an earlier
checkpoint reviewable when the normal build advances.

`qualify_development_batch.py --config CONFIG`
checks the normal compiled-source archive, per-owner whole original bodies,
strict native reports, original callers, full binding inventory, native suites
and tool-test gate before sealing a development freeze. Independent acceptance
inputs must be created after that freeze; this command grants no C coverage.
The scene configuration is `scene_batch_development_qualification_v1.json`.

`scene_batch_holdout_inputs.py` checks the qualified freeze and every pinned
dependency before creating four fresh scene input profiles. It preserves
original code and pools, changes typed counters and timers, relocates writable
objects and refuses to replace an existing input artifact.

`scene_batch_accept_capture.py` runs those profiles sequentially in original
states 45/46 using the unchanged observer. `scene_batch_acceptance_audit.py`
requires complete invocation accounting and frames, whole-body coverage with
at least 64 distinct valid inputs in each state, original caller contracts,
strict full-state native replay without skips, disjoint states and input
fingerprints, and original SAVEF state lineage. It preserves failed evidence
and grants no ledger credit itself.

`promote_tenpp_batch.py --evidence-root CACHE` explicitly permits immutable
corpora stored outside the workspace. Relative workspace artifact names and
hash formats remain unchanged; undeclared external paths and sibling-prefix
escapes are rejected. This avoids copying large evidence caches onto the
nearly full workspace drive without changing qualification gates.

`original_input_disagreement.py --frame BATCH --repeat ONE_SHOT --capsule RAW --invocation ID --owner OWNER --out NEW_JSON`
checks both original execution manifests, the unchanged observer, every
provenance hash, complete invocation accounting, all 63 input words, captured
RAM, original opcodes/pools and identical instruction traces. Differing final
RAM excludes the entire owner under the captured-input model. It establishes
an observation limit, without attributing a hidden cause or correcting C.

`pin_failed_campaign.py CORPUS --report STRICT_REPORT --out NEW_JSON` pins the
complete replay report, native executable, every corpus file and each raw run,
summary, log and input patch. It requires a failed report covering every corpus
entry and preserves all cases. The input-transition failure retains 1,849
dependencies in `scene_input_transition_failed_acceptance_v1.json`.

`replay_transition_caller_inputs.py` prepares four typed expired-clock inputs
through the immutable original scene-57 table. The resulting one-shot caller
captures retain the input predicate, paired reset callbacks, replay transition
and final RTS. The recipe grants no coverage credit.
`--force-pair-reset --out NEW_RECIPE` clears the original optional-reset input
byte for every variant. `replay_transition_caller_audit.py` verifies the eight
resulting original windows, including dispatcher slot, complete ordered save
prefixes, delayed transfers, callback tail and actual outer return. Its proof
is `replay_transition_original_callers_v2_proof.json`; the helpers remain uncredited.

`scene_round_acceptance_audit.py` audits the complete round campaign separately
from the failed input-transition campaign, using every run and valid specimen.
`scene_round_checkpoint.py` requires its historical hashes, original SAVEF
state lineage, compiled source freeze, expanded 1,415-binding regression,
39 native suites and 381 tool tests before sealing the final checkpoint.

## Capture longer original invocations

`build_extended_observer.py` creates a separate recorder and private object
archive in the evidence cache. It reuses and hashes the original linked
objects, libraries and source archive; only the recorder format tag and
instruction-vector bound change. The original observer remains available.
The resulting `VF3CAP7` layout is the `VF3CAP6` layout with a 500,000-opcode
bound. Older formats retain their 100,000-opcode bound, and every v7 record
still requires all 63 architectural words, bounded RAM pages and device tape.

`extended_observer_controls_audit.py` compares eight complete original caller
windows across both recorders. All architecture, RAM, instruction traces and
full audio checkpoints must match. The passing proof is
`extended_observer_controls_v1.json`; it grants no gameplay coverage.

`golden_batch.py --observer-controls tools/oracle/extended_observer_controls_v1.json --probe-ops 300000 ...`
validates that proof, its dependencies and the exact observer executable
before allowing a larger budget. Without explicit controls, the maximum
remains 100,000. The control path and hash are retained in each run's provenance.

`menu_reserve_inputs.py` prepares the original complete prefixes for owners
`0x8c07cbda` and `0x8c07cf50`. `--typed-actors` adds paired status-bit and
character metadata boundaries. The first screen covers only 104/670 bytes
of the first owner and no valid body of the second: its repeated descriptor
clears exceed the old record bound. The retained report is
`menu_reserve_original_dev_v1_report.json`. The extended v2 screen covers
606/622 selector bytes but contains an incomplete invocation in each state;
it remains diagnostic.

`menu_selector_inputs.py --complete-profile` places every character boundary
and the class-six branch within the first 128 probes. With 8,000 frames and
`--max-samples 128`, v4 completes both states with 73 distinct valid inputs and
whole 622-byte coverage in each. Its isolated C replay fails 144/146 cases;
the candidate remains uncredited.

`capsule_repeat_batch.py RAW --id ID --transfer PC --prefix NEW_PREFIX` prepares
exact-input rollback probes using the original executed PC alias. It emits
the supported `entry`/`target` directives and seeds every captured input page;
expected outputs are never seeded. Outputs include original code bytes and
must remain in ignored analysis storage. Original input equality still needs
all 63 words, including the unassignable inactive register bank, checked after
execution. This supports phase diagnostics when a one-shot repeat takes an IRQ.

`original_probe_disagreement.py --left BATCH --right BATCH --left-raw RAW --right-raw RAW --left-id ID --right-id ID --owner OWNER --observer-controls CONTROLS --out NEW_JSON`
checks complete frame/invocation accounting, the exact controlled recorder,
original opcodes and pools, input equality and identical instruction traces.
A final RAM disagreement excludes the entire owner. The selector proof records
161,420 identical original instructions and all 63 equal input words, with a
different word at `0x0c641800`. It establishes an observation limit, without
attributing a cache, timing or floating-point cause.

## Qualify the replay helpers

`replay_transition_callable_template_v1.json` declares the exact scene-57
transfer paths for three owners. `callable_replay_transition.py` checks their
original entry sequences, whole bodies, eight original caller windows and
native save/restore invariants. `seal_callable.py` produces the validated
`replay_transition_callable_v1.json`; it grants no byte credit.

`qualify_replay_transition_development.py` requires complete accounting and
whole-body coverage for all five helpers in each original state, all 1,514
strict native cases, the normal compiled-source closure, original callers,
full 1,415-binding/39-suite regression and 388 tool tests. It seals a development
freeze before `replay_transition_holdout_inputs.py` creates changed, relocated
input profiles. `replay_transition_accept_capture.py` then runs both profiles
against the unchanged original observer in states 45/46. Every held campaign
still needs a complete independent acceptance audit; the potential gain is
420 bytes because the two other helper bodies already lie in accepted spans.

`replay_transition_acceptance_audit.py` combines every held run, requires
complete accounting, whole bodies and 64 distinct inputs separately in each
state, original callers, zero-skip strict replay, disjoint states/inputs and
SAVEF lineage. It verifies all five helpers, including the two already
accepted dependencies, before permitting the 420-byte promotion.
`replay_transition_checkpoint.py` requires the expanded 1,418-binding gate,
39 native suites, 388 tool tests and preserved source/evidence hashes, then
archives the current inventory and suite executables as a final checkpoint.

`scene_retire_screen_inputs.py` screens a 512-byte scene reset through its true
seven-register save prefix. It retains original callback execution and uses
initialized fight states; a successful screen still needs whole-body, caller,
strict native and independent held qualification.
`--extended` retains the same reset inputs for a second screen with the
validated larger-record observer. The first screen stops inside a bounded
4,096-entry descriptor lookup; the flag-one and budget-limit specimens remain
diagnostic. Increasing the budget does not grant coverage or change the game.

## Scan binary pointer references

`tools/sh4_pointer_refs.py IMAGE_OR_RAM --base ADDRESS --target ADDRESS`
reports aligned 32-bit words matching one or more guest addresses. Add
`--physical-aliases` to match the 0x0c/0x8c/0xac mirrors by their 29-bit
physical address. This is a raw candidate scan: validate each result in its
disassembly or containing table, since adjacent SH-4 opcodes can coincidentally
form the same 32-bit word.

`tools/sh4_fn_table.py IMAGE_OR_RAM --base ADDRESS --table ADDRESS --count N`
prints an unsorted array of 32-bit code pointers with their guest and physical
addresses. Repeat `--index N` to select individual entries. It is for callback
tables; it does not infer entry count or validate that each target is code.

`tools/sh4_function_at.py FUNCS.csv --address ADDRESS` maps an address back to
every Ghidra function range that contains it. Repeat `--address` for multiple
queries; `--physical-aliases` compares the 0x0c/0x8c/0xac mirrors. This is
useful after a raw pointer scan finds a reference inside a function's literal
pool, where the reference address itself is data rather than a call site.

`tools/flycast_attachment_matrices.py STATE --image IMAGE --actor ADDRESS
--matrix-bin OUT.bin` exports the actor's 18 attachment rows as contiguous
little-endian column-major float32 matrices and prints each row's selector,
relative translation, and basis lengths. Add `--json` for all matrix words.
This is an offline preview input only; it does not produce native gameplay
pose data. For example:

```powershell
python tools/flycast_attachment_matrices.py `
  extract/analysis/flycast_pose_capture_s26_v1/data/vf3_47.state `
  --image extract/exe/1ST_READ.unsc.bin --actor 0x0c20138c `
  --matrix-bin extract/analysis/jacky_s47_attachments.bin `
  --scene-matrix-bin extract/analysis/jacky_s47_scene_matrix.bin
python tools/flycast_attachment_matrices.py `
  extract/analysis/flycast_pose_capture_s26_v1/data/vf3_47.state `
  --image extract/exe/1ST_READ.unsc.bin --actor 0x0c1fefe4 `
  --matrix-bin extract/analysis/akira_s47_attachments.bin `
  --scene-matrix-bin extract/analysis/akira_s47_scene_matrix.bin
```

Build `vf3nativeattachmentpreview` with the native-port CMake option. The
default composes the base model and all 15 Jacky `ROB_WO2` attachments. Use
`--fighter akira` to render Akira's recovered selector map, including the
seven-mesh `MKAO_AKI` entry and 25 `ROB_AKI` meshes:

```powershell
cmake --build build --target vf3nativeattachmentpreview
build\vf3nativeattachmentpreview.exe `
  --fighter akira `
  --assets build\vf3_assets.vfa `
  --matrix-bin extract\analysis\akira_s47_attachments.bin `
  --scene-matrix-bin extract\analysis\akira_s47_scene_matrix.bin `
  --scale 150 --ground-y 350 `
  --output extract\analysis\akira_s47_attachments_preview.bmp
```

Export the matching Akira matrix file from state 47 with
`--actor 0x0c1fefe4`; use actor `0x0c20138c` and the Jacky output names for
Jacky. Add `--scene-matrix-bin` with that same export's scene matrix to inspect
the captured scene composition. These captured matrices are offline preview
inputs and do not seed the runtime.

With both state-47 exports, the Akira preview draws the 32 meshes in the
recovered selector map and composes each attachment with the shared scene
matrix. This confirms the native draw path and asset selection; it does not
recover animation or provide a runtime pose source.

The transform relation is now established for all 16 populated entries. The
13 ordinary entries load row `i` in the refresh routine's second pass. For
entries 1, 14, and 17, `fighter_refresh.c` passes the same-index row pointer to
`scene_link.c`; that routine loads it before drawing the selector from actor
offset `+0x70`, `+0xA4`, or `+0xB0`. Entries 5 and 9 are empty. The draw
helper then pre-multiplies the row by the matrix at `0x0C2A5F60`; the exporter
can save that 64-byte scene matrix, and the offline preview composes it with
each attachment row in the same order. The native view can compose a supplied
scene matrix with an attachment row, but it does not load guest state. The preview uses row 1 for the base by
default; use `--base-at-root` for a root-only comparison, or `--base-entry N`
to select a different row. Repeat `--attachment ENTRY:SLOT` to supply a
different attachment list. Adjust the view with `--scale` and `--ground-y`.
The tool consumes diagnostic capture data and is not linked to `vf3port`.
The default preview calls `vf3_native_jacky_draw()` from
`src/native/jacky_parts.c`, or `vf3_native_akira_draw()` from
`src/native/akira_parts.c` for Akira. These ordinary-C renderers consume the
recovered selector maps, gather the live mesh ranges from both POL packages,
and painter-sort the selected meshes by transformed center depth. They are
ready for a native pose producer; the current host still has no runtime matrix
source. The
  current host does not provide such matrices. The preview's local view uses the
  matrix-driven fighter projection. Its scene-matrix option now applies the same
  low-camera basis and perspective distance as `vf3_stage_view_draw`, centered on
  the actor root. It still omits the actor's full world placement and is for
  checking matrix composition, not runtime-pose validation.

The actor update dispatcher at `0x8c0aa444` indexes `0x0c10f4b0` by the high
byte of the pointer at actor `+0x38`. For a `0x0c` pointer, row 12 selects
`0x0c0ac900`, which calls the motion-frame updater. This is address-domain
dispatch, not an action-to-motion table. Inspect the first 20 entries with:

```powershell
python tools/sh4_fn_table.py extract/exe/1ST_READ.unsc.bin `
  --base 0x0c010000 --table 0x0c10f4b0 --count 20
```

For the model-path investigation, scanning `1ST_READ.unsc.bin` for
`0x8c095040` and `0x8c0951d2` found no aligned references. The scan returned
seven raw matches for `0x8c0955b0`; inspection showed these are instruction
word pairs, not pointer-table entries. The constructor at `0x8c095040` indexes
a descriptor table using actor byte `+0x1561`, but these references do not
locate that table or establish a POL-slot-to-pose-row mapping.

`tools/sh4_literal_scan.py IMAGE --base ADDRESS --target VALUE [--width 2|4]`
searches PC-relative `mov.w`/`mov.l` loads and resolves their literal-pool
values. For `0x1561`, the aligned scan found loads at `0x8c094dfa` and
`0x8c095058`; the first is a style-7 flag check, and the second belongs to the
`0x8c095040` constructor, which has no reachable direct caller in the scan.
Other hits at `0x8c073b84`,
`0x8c0a964a`, and `0x8c0af538` fall in unrelated state-update code. This
narrows the search but still does not give the live fighter's part mapping.

`tools/sh4_branch_refs.py IMAGE --base ADDRESS --functions FUNCS.csv --target
ADDRESS` follows reachable direct branch flow from each inventory entry and
reports matching `bra`/`bsr`/conditional branches. It skips literal pools that
fall inside a function's byte range; indirect register targets and interior
entry points still require separate evidence. For this image, it found the
wrapper's direct call `0x8c0951c4 -> 0x8c0951d2`, but no reachable direct call
to `0x8c095040`. A raw branch-shaped word near `0x8c092174` was excluded because
the preceding unconditional branch skips that literal-pool region. This
further weakens the old constructor as a source for the live Akira/Jacky map;
the slot-to-pose-row relation remains unresolved.

`tools/flycast_fighter_records.py STATE --image IMAGE --actor ADDRESS` reads a
retained Flycast state and reports the live fighter mode lookup, the 18
32-bit selectors at actor `+0x6c`, the 64-byte attachment records at `+0x180`,
and the raw records reached through `0x0c2a1c3c`. Use `--json` for every raw
word and its alternate float32 view; both output modes summarize the first two
descriptor words by frequency. The offsets/tables are configurable. It reuses
`flycast_ram.py`'s image-anchored RAM recovery and does not modify the state.
Repeat `--entry N` to show only selected selector/matrix pairs; for example,
`--entry 1 --entry 14` keeps the JSON focused while retaining the original
18-entry indexing.

For example, state 27 Jacky at `0x0c20138c` has mode 20, mode selector `0xef8`,
and mode record `0x0c3d14e0`. Sixteen of its 18 attachment selectors resolve;
the other two are `0xffffffff`. The first selector `0xe21` reads pointer
`0x0c3ec258` from table cell `0x0c2a54c0` in this state. Descriptor words are
intentionally left unlabeled: all 16 live descriptors start with words `1, 1`,
which selects the known `0x8c03ecb0` -> `0x8c03eff0` -> `0x8c048260` draw path.
The report establishes that lookup and dispatch chain, not a bone, POL slot,
or motion-channel mapping.

`tools/flycast_pol_node_match.py STATE --image IMAGE --actor ADDRESS --pol
PACKAGE.POL` walks each selected live descriptor's display-list nodes and
compares decoded vertex positions and bounding spheres with tagged POL mesh
geometry. It prints point-proximity, exact vertex-attribute overlap (excluding
the position fields), and a separate ranking by center/radius deltas.
`--affine-fit` tests equal-count POL/live vertex streams in their existing
record order with a least-squares 3x4 transform, and reports absolute and
mesh-radius-normalized residuals. It does not reorder vertices or infer a rig.
`--attachment-matches` also transforms each POL mesh
sphere through every captured matrix, relative to row 0; the default table is
the 18-row attachment table at actor `+0x180`. To inspect the 23-row bone
table used by `flycast_pose_export.py`, pass `--attachment-offset 0x7c0
--attachment-count 23`. Repeat `--matrix-row N` to test specific rows such as
the selector-index row.
`--top-per-matrix-row` ranks each selected row independently, so `--top 1`
shows the best slot/mesh candidate for every row rather than only the global
best row. `--attachment-geometry-matches` additionally transforms every POL
vertex with the same matrix and compares those points to the live node's
decoded vertex positions; use it with `--top-per-matrix-row` to inspect the
best geometry candidate for each row. `--summary --top 100` prints exact
source-mesh position and non-position attribute matches across every selected
descriptor entry, plus the best sphere row for exact slot-3 matches when
`--attachment-matches` is enabled. Add `--attachment-geometry-matches` to
include exact transformed-row matches. These remain diagnostic rankings.
Add `--scene-matrix-address 0x0c2a5f60` to pre-multiply the shared scene
matrix into each attachment row, matching the offline preview's matrix order.
The decoded live-node vertices are still read before hardware XF, so transformed
point comparisons remain rankings across different pipeline stages.
These are candidate rankings: proximity does not prove that a POL mesh
produced a display-list node. Use `--entry N` to restrict attachment indices
and `--top N` to control candidates per node. For example:

```powershell
python tools/flycast_pol_node_match.py `
  tools/emu/flycast-build/data/vf3_27.state `
  --image extract/exe/1ST_READ.unsc.bin --actor 0x0c20138c `
  --pol extract/gamedata/MKAO_JAC.POL --entry 1 --top 1 `
  --attachment-matches --attachment-geometry-matches `
  --scene-matrix-address 0x0c2a5f60 `
  --top-per-matrix-row --matrix-row 0 --matrix-row 10 --matrix-row 11
```

In state 27, selector entry 1 has five nodes. Raw sphere matching puts slot 3,
mesh 9 closest to node 0 (center delta `0.00894`, radius delta `0.00564`), but
the other nodes choose different meshes, including the aliased slot 1/14
payload. Ranking all 18 rows independently makes row 0 the best sphere
candidate for each of the five nodes; rows 10/11 are secondary for some nodes,
and most other rows have much larger center deltas. Comparing transformed
vertex clouds leaves zero exact matches for every row; the closest row varies
between 0, 10, and 11 across nodes. The results support only a bounds
hypothesis and do not establish an attachment-to-slot or row assignment.

`tools/flycast_pol_asset_search.py` searches every tagged mesh in the selected
POL packages. It uses exact position and attribute overlap plus mesh bounds to
shortlist candidates before doing the slower point-distance ranking. By
default it scans `extract/gamedata/*.POL`; use repeated `--pol` or `--pol-dir`
to choose a different package set. Supplying `--pol` alone searches only those
files; it no longer adds the default directory scan. `--exact-only` prints
only nodes with exact position or non-position attribute matches, and
`--json`/`--out` retain the machine-readable details. Reports include each
live node's ISP/TSP/TEX header words, decoded texture dimensions/format/VQ
flags, and each candidate mesh's POL texture descriptor. A header-compatible
descriptor narrows the possibilities but does not prove which package the
game loaded, because duplicate packages can carry the same dimensions and
format. An exact vertex match identifies shared geometry; it does not establish
how the mesh is transformed onto a bone.

```powershell
python tools/flycast_pol_asset_search.py `
  extract/analysis/flycast_pose_capture_s26_v1/data/vf3_47.state `
  --image extract/exe/1ST_READ.unsc.bin --actor 0x0c20138c `
  --entry 1 --pol extract/gamedata/MKAO_WO2.POL `
  --pol extract/gamedata/MKAO_WOL.POL --exact-only
```

## Target-pair mesh comparison from isolated states 47 and 48

The isolated capture described below resumes state 26 with the real disc.
States 47 and 48 retain the target actor kind bytes (`0/0` at Akira's actor,
`20/7` at Jacky's) and all 23 bone matrices pass the basis check. Selector
entry 1 is stable across both snapshots: Akira uses selector `0x242`, and its
seven live nodes match MKAO_AKI slot 3 meshes 0–6 by both position and
non-position vertex bytes. Slot 21 aliases duplicate some of these meshes.
Jacky's selector is `0xe06`; its five live nodes have no exact position or
non-position match in `MKAO_JAC.POL`, and the closest candidates within that
package alternate between slots 3 and 14.

Scanning all 18 Akira selector entries against the tagged POL assets in both
states gives a recurring source for every populated entry. The resulting map
is retained in `src/native/akira_parts.c`:

| Entry | Selector | Source slot | Meshes |
| ---: | ---: | --- | ---: |
| 0 | `0x25d` | `ROB_AKI` 50 | 3 |
| 1 | `0x242` | `MKAO_AKI` 3 | 7 |
| 2 | `0x282` | `ROB_AKI` 51 | 1 |
| 3 | `0x249` | `ROB_AKI` 52 | 1 |
| 4 | `0x278` | `ROB_AKI` 53 | 2 |
| 6 | `0x281` | `ROB_AKI` 54 | 1 |
| 7 | `0x248` | `ROB_AKI` 55 | 1 |
| 8 | `0x277` | `ROB_AKI` 56 | 2 |
| 10 | `0x227` | `ROB_AKI` 57 | 1 |
| 11 | `0x252` | `ROB_AKI` 58 | 1 |
| 12 | `0x254` | `ROB_AKI` 59 | 1 |
| 13 | `0x22f` | `ROB_AKI` 60 | 3 |
| 14 | `0x224` | `ROB_AKI` 36 | 2 |
| 15 | `0x253` | `ROB_AKI` 61 | 1 |
| 16 | `0x22e` | `ROB_AKI` 62 | 3 |
| 17 | `0x223` | `ROB_AKI` 35 | 2 |

Entries 5 and 9 are empty. Some MKAO_AKI geometry also appears through slot 21
aliases; slot 3 is the selected source because it holds the complete seven-mesh
selector-1 group. The asset match does not identify the attachment transforms
or establish native pose playback. Reproduce the cross-capture candidate check
with:

```powershell
python tools/flycast_pol_asset_search.py `
  extract/analysis/flycast_pose_capture_s26_v1/data/vf3_47.state `
  --image extract/exe/1ST_READ.unsc.bin --actor 0x0c1fefe4 `
  --all-entries --pol-dir extract/gamedata --exact-only --json `
  --out extract/analysis/native_aki_parts_s47_v1.json
python tools/flycast_pol_asset_search.py `
  extract/analysis/flycast_pose_capture_s26_v1/data/vf3_48.state `
  --image extract/exe/1ST_READ.unsc.bin --actor 0x0c1fefe4 `
  --all-entries --pol-dir extract/gamedata --exact-only --json `
  --out extract/analysis/native_aki_parts_s48_v1.json
python tools/selector_asset_audit.py `
  extract/analysis/native_aki_parts_s47_v1.json `
  extract/analysis/native_aki_parts_s48_v1.json --stable-only
```

The cross-package search changes the source-geometry result. In both states
47 and 48, all five nodes (117, 18, 84, 55, and 22 vertices) exactly match
slot 3 meshes 0–4 in both `MKAO_WO2.POL` and `MKAO_WOL.POL`, including
non-position vertex attributes. Their live center and radius also match those
mesh records exactly. An Akira control scan returns the established slot-3
matches in `MKAO_AKI.POL`/`MKAO_AK2.POL`. This proves the Jacky draw nodes share
geometry stored in those packages. The duplicate MKAO geometry leaves the
runtime texture-package choice open: the five matching meshes use different
POL texture indices in the two files (`7,0,2,6,8` in WO2; `5,6,1,4,7` in WOL).
The focused TSP/TEX comparison now checks the live dimensions, pixel format,
and raw/VQ storage flag against both packages' descriptors. Every one of the
five nodes is compatible with both variants in both states, so these headers
do not distinguish their package filenames. `tools/pvr_asset_match.py` then
found exact copies of the candidate payloads at the nodes' five VRAM addresses
in the older P3 frame-300 dump. The WO2 and WOL texture indices differ, but the
payload bytes match at each address; this supports WO2 as a content-equivalent
source for the native preview. The old dump does not establish which filename
the game loaded. The all-entry map below covers every populated selector, and
the retail refresh path ties 13 selectors directly to same-index attachment
matrices; three populated entries still use special paths. Reproduce the
focused header comparison with:

```powershell
python tools/flycast_pol_asset_search.py `
  extract/analysis/flycast_pose_capture_s26_v1/data/vf3_47.state `
  --image extract/exe/1ST_READ.unsc.bin --actor 0x0c20138c --entry 1 `
  --pol extract/gamedata/MKAO_WO2.POL `
  --pol extract/gamedata/MKAO_WOL.POL --exact-only
```

The PVR payload check uses:

```powershell
python tools/pvr_asset_match.py extract/analysis/p3/ref_pvr_f300.bin `
  --pol extract/gamedata/MKAO_WO2.POL --tex extract/gamedata/MKAO_WO2.TEX `
  --pol extract/gamedata/MKAO_WOL.POL --tex extract/gamedata/MKAO_WOL.TEX `
  --address 0x6e0c80 --address 0x2e9000 --address 0x6eac80 `
  --address 0x2df000 --address 0x2eb000
```

It reports exact matches for WO2 indices `7,0,2,6,8` and WOL indices
`5,6,1,4,7` at the five respective addresses.

The exact-only all-entry search resolves 44 live nodes across the 16 populated
selector entries in both states 47 and 48. Every node matches positions,
non-position attributes, center, and radius exactly in the raw POL coordinates:

| Entry | Selector | Source package and POL slot | Meshes |
| ---: | ---: | --- | --- |
| 0 | `0x0e21` | `ROB_WO2`, slot 50 | 0–6 |
| 1 | `0x0e06` | `MKAO_WO2` and `MKAO_WOL`, slot 3 | 0–4 |
| 2 | `0x0e44` | `ROB_WO2`, slot 51 | 0 |
| 3 | `0x0e0d` | `ROB_WO2`, slot 52 | 0 |
| 4 | `0x0e3a` | `ROB_WO2`, slot 53 | 0–1 |
| 5 | `0xffffffff` | empty | — |
| 6 | `0x0e43` | `ROB_WO2`, slot 54 | 0 |
| 7 | `0x0e0c` | `ROB_WO2`, slot 55 | 0 |
| 8 | `0x0e39` | `ROB_WO2`, slot 56 | 0–1 |
| 9 | `0xffffffff` | empty | — |
| 10 | `0x0dec` | `ROB_WO2`, slot 57 | 0 |
| 11 | `0x0e16` | `ROB_WO2`, slot 58 | 0–4 |
| 12 | `0x0e18` | `ROB_WO2`, slot 59 | 0 |
| 13 | `0x0df0` | `ROB_WO2`, slot 60 | 0–1 |
| 14 | `0x0de9` | `ROB_WO2`, slot 36 | 0–5 |
| 15 | `0x0e17` | `ROB_WO2`, slot 61 | 0 |
| 16 | `0x0def` | `ROB_WO2`, slot 62 | 0–1 |
| 17 | `0x0de8` | `ROB_WO2`, slot 35 | 0–5 |

The retail-readable reconstruction in `src/fight/fighter_refresh.c` gives the
transform relation for all 16 populated entries. Its second pass loads
attachment matrix `actor + 0x180 + 64 * i`, then dispatches selector
`actor + 0x6c + 4 * i` for the 13 ordinary entries. It skips indices 1, 5, 9,
14, and 17. The first pass calls `scene_link.c` with the same row pointer for
each index; modes 1, 14, and 17 load that matrix before dispatching their
special selectors from actor offsets `+0x70`, `+0xA4`, and `+0xB0`. Entries 5
and 9 are empty in these captures. Reproduce the complete package search with:

```powershell
python tools/flycast_pol_asset_search.py `
  extract/analysis/flycast_pose_capture_s26_v1/data/vf3_47.state `
  --image extract/exe/1ST_READ.unsc.bin --actor 0x0c20138c `
  --all-entries --pol-dir extract/gamedata --exact-only
```

In state 47, the earlier matrix experiment used both the 18-row table at
`+0x180` and the 23-row bone table at `+0x7c0`. Neither transformed vertex
comparison produced an exact match for either fighter. Akira's known source
meshes often rank row 11 first by sphere score, which is not enough to assign
those meshes to a bone. These captures narrow Akira's source-mesh map for
selector entry 1. The transformed-vertex comparison compares the captured
matrix result with raw display-list vertices; the optional
`--scene-matrix-address 0x0c2a5f60` includes the shared draw matrix. The run
still has zero exact transformed matches because `src/fight/display_list.c`
applies XF during submission, so those values are from different pipeline
stages. The zero matches do not override the exact raw source matches or the
now-proven same-index attachment dispatch for all 16 populated Jacky entries.
The link from attachment matrices to the 23-bone table and MT channels remains
open.

On state 47, the optional ordered affine fit also finds no strong Jacky
candidate: the only equal-count candidate for its five nodes is node 4 against
slot 21 mesh 0, with normalized RMS residual `0.935`. The mesh count/order
condition means this does not search arbitrary vertex correspondences; the
result is diagnostic.

`flycast_pol_node_match.py --unordered-shape` adds a complementary ranking for
vertex streams whose record order differs. It compares cumulative histograms of
all pairwise point distances after bounding-box normalization, so the signature
ignores vertex order, translation, rotation, and uniform scale. It does not
recover correspondences or a transform, and the ranking is not a part map:

```powershell
python tools/flycast_pol_node_match.py `
  extract/analysis/flycast_pose_capture_s26_v1/data/vf3_47.state `
  --image extract/exe/1ST_READ.unsc.bin --actor 0x0c20138c `
  --pol extract/gamedata/MKAO_JAC.POL --entry 1 --top 3 `
  --summary --unordered-shape
```

On Jacky's five nodes, the best candidates vary across slots 3, 14, and 33;
their POL point counts also differ from the live nodes. This does not provide a
consistent source-mesh assignment. Running the same option on Akira's selector
entry 1 returns zero signature error for the already established exact slot-3
matches, which is a sanity comparison for the diagnostic only.

`--composite-shape` ranks unions of two POL meshes for live nodes that may
combine parts. Exact-count unions also get an ordered affine fit in both mesh
orders. `--composite-attachment-fit` additionally tries pairs of captured
attachment rows on the best composite candidates and ranks the transformed
point clouds by symmetric nearest-point RMS. These options narrow hypotheses;
they do not infer vertex correspondence or establish a rig map:

```powershell
python tools/flycast_pol_node_match.py `
  extract/analysis/flycast_pose_capture_s26_v1/data/vf3_47.state `
  --image extract/exe/1ST_READ.unsc.bin --actor 0x0c20138c `
  --pol extract/gamedata/MKAO_JAC.POL --entry 1 --top 3 `
  --composite-shape --attachment-matches --composite-attachment-fit
```

On state 47, the shape rankings include slot 3 mesh 1 + slot 14 mesh 1 for
node 0 (117 points, exact count; CDF error `0.01992`), slot 33 mesh 0 + slot 35
mesh 0 for node 2 (86 versus 84 live points; `0.01654`), and slot 3 mesh 5 +
slot 35 mesh 0 for node 3 (60 versus 55; `0.02372`). Node 1 has no near-count
pair, and node 4's best pair has a much weaker `0.14085` error. The exact-count
node-0 pair's ordered affine RMS is `0.08854` (mesh-normalized `0.646`). The
best two-row attachment fits remain weak: normalized RMS is `0.565`, `0.421`,
`0.383`, and `1.119` for nodes 0, 2, 3, and 4, with different winning row
pairs. The same shape ranks on state 48, but the pose/geometry is stable across
those two snapshots, so this is not independent confirmation. No candidate
pair or row assignment is strong enough to wire into the native renderer.

Reproduce the Akira selector result with:

```powershell
python tools/flycast_pol_node_match.py `
  extract/analysis/flycast_pose_capture_s26_v1/data/vf3_47.state `
  --image extract/exe/1ST_READ.unsc.bin --actor 0x0c1fefe4 `
  --pol extract/gamedata/MKAO_AKI.POL --entry 1 --top 100 --summary
```

Compare Jacky's same selector and run the optional ordered fit with:

```powershell
python tools/flycast_pol_node_match.py `
  extract/analysis/flycast_pose_capture_s26_v1/data/vf3_47.state `
  --image extract/exe/1ST_READ.unsc.bin --actor 0x0c20138c `
  --pol extract/gamedata/MKAO_JAC.POL --entry 1 --top 100 --summary --affine-fit
```

## Inspect DTPK package sections

`tools/dtpk_peek.py [FILE_OR_DIRECTORY ...]` reports each DTPK package's
serial, group tag, and section offsets/sizes from the 16-slot directory. With
no paths it scans `extract/gamedata`; explicit paths are honored, and
directories are scanned recursively. Output goes to the console by default.
Use `--json` for machine-readable output or `--output PATH` to write a report
to an explicitly chosen file. It never rewrites `docs/formats/DTPK.md`.

For a single package:

```powershell
python tools/dtpk_peek.py extract/gamedata/BGM_AKI.BIN
```

The current package reports serial 52, group tag `0x0223ff0a`, and six
sections at directory slots 0, 1, 2, 3, 6, and 7. Zero directory slots are
allowed between sorted nonzero section offsets.

## Capture from a scripted Flycast state

`tools/flycast_capture.py` runs the local Flycast build with a frame-clock
script in a new isolated directory under `extract/analysis`. It copies the
executable, config, and non-savestate device files; a supplied `--state` is
staged only into that isolated copy. The script must contain one `EXITF`, and
the runner refuses an existing output directory. `SAVEF N` checkpoints stay
inside the isolated copy's `data` directory.

For example, resume state 26 with the real disc and capture three neutral
checkpoints:

```powershell
python tools/flycast_capture.py `
  --state tools/emu/flycast-build/data/vf3_26.state `
  --play tools/vf3_play_pose_capture.txt `
  --out extract/analysis/flycast_pose_capture_s26_v1
```

The retained source state and the normal Flycast data directory remain
untouched. Inspect the emitted `vf3_47.state` through `vf3_49.state` with
`tools/native_pose_audit.py` before using them as pose evidence.
