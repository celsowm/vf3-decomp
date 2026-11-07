# M14 — MT motion record access trace (2026-09-22)

Tooling: `VF3_WATCH` mem mode (vf3trace.cpp): `mem <addr_hex> <len>` lines;
each tagged read/write emits `(pc<<16)|0xFA20, (size<<48)|(isWrite<<47),
addr, value`. Installed by wrapping the SH4-execution `ReadMem*`/`WriteMem*`
pointers after `mem_Reset` (winmain runs it after state load too — savestate
resume bounces the pointers via mem_Reset). Interpreter-only: dynarec inlines
its own memory ops.

## Capture
- Run: extract/analysis/m14_wide_vf3_7.bin (95 frames, fight attract state
  vf3_7), watch window 0x8C5F0000..0x8C810000 (covers the whole loaded MTJACLAU
  motion pack, which M8 established as resident at 0x8C5F4100+, 1,493,636 B).
- 4,817 mem hits, 22 unique reader PCs.
- Per-access rows: extract/analysis/mt_field_reads.csv.

## The reading engine
The whole MT-side reader is two functions:
- `fight_f_8c09d69a` (69 B) — short helper, reads a handful of u32 slots from
  linked/secondary records (`pc 0x8C09D6CA` hits).
- `fight_f_8c09d6e0` (263 B) — **the motion-frame evaluator hot loop**.
  Five sub-PCs produce 75% of all hits:
  - `0x8C09D6F6` byte-stream cursor: reads consecutive bytes walking DOWN the
    record from `record+0x736` (+736..+779 within record 5093) — this is the
    per-frame **opcode/command stream**.
  - `0x8C09D70C` byte-stream second cursor (alternative channel).
  - `0x8C09D77A/80/84/96` four u32 reads at `record+0x7A4..0x7B0`: the
    per-frame vector quartet (bone transform or angular params) — always
    read together; 4 states (one quat limb).
  - same four PCs also read `record2+0x194..0x1FC` inside record 5096 —
    proving **record-level linking**: the primary record (5093) pulls extra
    param tuple tables from a second linked record (5096). Stride = one
    tuple per frame-ish.

- A separate init path (`f_8c09d5xx..`): byte reads at file off 151872..151879
  + header walk 18340..18400 range = record **loading/activation** (seen once
  per observation window).

## What records 5093 / 5096 look like (MTJACLAU offsets)
- slot 5093 @ 0xCE154, size 2120 B — the active motion (frame replay source).
- slot 5096 @ 0xCEA1C, size 1448 B — referenced param pool.
- The evaluator's byte cursor tracks slot+736.. (byte-rate advance), and the
  four fp/u32 slots at slot+0x7A4-local sit within 5093 only when 5093 is the
  active record (i.e. big records are bytecode+quad tuples interleaved in one
  blob, not out-of-line).

## Port status
`src/fight/mt_play.c` mirrors the 63-channel evaluator when supplied with the
runtime-built header and its address map. `src/media/mt.c` now resolves the
three source-file stream offsets for a one-based motion ID, and
`src/native/motion.c` binds those bounded asset slices to the native evaluator.
This covers source decoding for representative IDs; it does not resolve the
5093-to-5096 linked-record reads or emit downstream per-part transforms.

## M53 — record stream-region map, float-sanity verified (2026-09-28)
Tool: `tools/mt_record_map.py` → `extract/analysis/mt_record_map.csv`
(CRC32 per region). Reads MTJACLAU.BIN slot bodies at the exact M14
evaluator-read addresses and checks float plausibility:

| slot | rec+delta | stream | floats sane? |
|---|---|---|---|
| 5093 | 0x736 (8 B) | counts cursor B | NO (byte stream, as expected: cnt values) |
| 5093 | 0x75B (33 B) | times cursor | NO (byte stream, key-time bytes) |
| 5093 | 0x7A4 (16 B) | tuple quartet | YES 4/4 (0.0, 0.0, 15377.75, -16384.0 = x, y·256, z·256 slope form) |
| 5096 | 0x194 (64 B) | linked tuples | YES 16/16 (-0.0153, 0.0, 0.71, 0.30 — genuine motion floats) |
| 1304 | 0x41C (32 B) | 2nd-instance tuples | YES 8/8 |

So the byte-vs-float region split predicted by the evaluator read map holds on
file bytes across three records (5093 primary, 5096 linked pool, 1304 second
instance). Still open: the runtime-built ops[63] header, the loader's per-
record scatter/rewrite rules, and the 5093→5096 link encoding (which channels
use which tuple tables). The prior constant-relocation hypothesis was
falsified; see `mt_mount_m33.md`. The current readable evaluator is not evidence
that those file records have been assembled for playback.

## Retained motion-frame capsules do not contain the mounted records

The `coverage_65_motion_frame_dev_v3` capsules include pages `0x0C5F7000` and
`0x0C5FA000`, but these are pages of the loaded 8,880-entry MT slot-offset
table, not record bodies. In case 7, words at `0x0C5FA2C4` onward match
`MTAKIWOL.BIN` table slots 6321–6341 exactly (`0x00133BC8`, `0x00133BFE`,
`0x00133C5C`, ...). The tested actor's `+0x1D00` field is zero in that specimen,
so it does not expose an evaluator header either. These capsules cannot
establish the record scatter rules or the runtime `ops[63]` map.

## Native source-file stream row recovered

Static code at `0x8C09D5AE` resolves the one-based motion ID from actor `+0x3C`
as a 12-byte row in the loaded MT header: `row = base + (id - 1) * 12`.
Its three little-endian offsets point to the descriptor/opcode/count area,
key-time bytes, and float tuples. The first source area has a 16-bit descriptor
word at `+0`, then 16 packed opcode bytes at `+2`; each byte expands high bits
first into four 2-bit opcodes, with the 63-channel evaluator ignoring the final
decoded opcode. The selector stores the counts pointer as `offset0 + 17`, and
`0x8C09D6EE` increments it before reading; count bytes therefore start at
`offset0 + 18`.

The recovered source layouts were checked against two asset rows:

| Asset | Motion ID | Three source offsets | Counts | Key times | Tuples |
| --- | ---: | --- | ---: | ---: | ---: |
| MTAKIJAC | `0x41A` | `0x997F4`, `0x99810`, `0x99820` | 9 B | 13 B | 404 B |
| MTJACLAU | `0x956` | `0x148D74`, `0x148D90`, `0x148D9C` | 10 B | 12 B | 400 B |

Those sizes follow the unpacked opcode stream and each source component's next
greater table offset. The retained `0x8C0A94D0` case 0 also carries actor
`+0x3C = 0x956` and actor `+0x1A00 = 60`, while the MTJACLAU descriptor word
for row `0x956` is `80`. This proves the descriptor word is not the frame
cycle; native callers must supply the cycle from fighter runtime state.

The reusable `tools/mt_motion_find.py` scan also locates observed row `0x69F`
in MTJACLAU at `0x0CD164`, `0x0CD198`, and `0x0CD1E0`; its native bounded
stream lengths are 34 count bytes, 70 time bytes, and 1,404 tuple bytes. The
row is present in several other pairing packs as well. This confirms asset
availability only; the captures do not identify its action or map its channels
to POL parts.

## Motion-frame descriptor and caller

The `coverage_65_motion_frame_dev_v3` corpus watches the motion-frame routine
`0x8C0A94D0` directly. In its 109 cases, `r4` points at the selected descriptor
and `r5` at the actor. `tools/oracle/evidence_inspect.py profile` can summarize
descriptor fields across the corpus without an ad hoc Python probe:

```text
python tools/oracle/evidence_inspect.py profile extract/analysis/coverage_65_motion_frame_dev_v3 --entry 0x8c0a94d0 --register r4 --offset 0x14 --offset 0x18 --bytes 4
python tools/oracle/evidence_inspect.py profile extract/analysis/coverage_65_motion_frame_dev_v3 --entry 0x8c0a94d0 --register r4 --offset 0x20 --offset 0x22 --offset 0x24 --bytes 2
```

The halfword at descriptor `+0x22` is the motion ID: observed values are
`0x000`, `0x027`, `0x41A`, `0x69F`, and `0x956` (27, 19, 22, 20, and 21
cases respectively). Descriptor `+0x24` is a small selector with values 1,
2, and 3 (42, 34, and 33 cases); its meaning is not established. `+0x20` is
zero in all 109 cases. The dword at `+0x14` takes values 0, `0x10000`, and
`0x20000` (39, 36, and 34 cases), and `+0x18` is 0 or 1 (58 and 51 cases);
their semantics are also unknown. These are captured descriptor fields, not
action labels.

The caller at `0x8C0A91DA` selects a descriptor row from `0x0C22F864` using an
index derived from the global at `0x0C29BB84 + 0x54` and an actor-table count.
It calls `0x8C0A94D0` with that row, then with a descriptor 64 bytes later,
before calling `0x0C0AE0EC`. This confirms a table-driven path into the frame
routine, but the action-state-to-row mapping and the row fields' gameplay
meaning remain unknown. Captured actor cycles are 60 in all 109 cases; the
cycle comes from actor `+0x1A00`, not the descriptor word or selector.

The matching replay corpus can be profiled without an inline Python probe:

```text
python tools/oracle/evidence_inspect.py profile extract/analysis/coverage_65_motion_frame_dev_v3 --entry 0x8c0a94d0 --register r5 --offset 0x3c --offset 0x1a00 --bytes 2
```

In its 109 cases, actor `+0x3C` contains `0x956` in 34 cases, `0x27` in 28,
`0x41A` in 26, and `0x69F` in 21; actor `+0x1A00` is `60` in all 109. This
establishes the observed selector and cycle values for this corpus, not the
meaning of each motion ID.

The mixed-width joint profile (`--width 0x61:1 --joint`) shows all four motion
IDs paired with both captured fighter-kind bytes, `0` and `4`, while the cycle
stays `60`. This controlled descriptor corpus therefore does not establish a
fighter-kind-to-motion mapping either.

## Captured mounted streams match extracted MT rows

`tools/mt_capture_match.py` follows the actor's `+0x1D00` record pointer in a
retained RAM case, reads the expanded 63-opcode map and its count/time/tuple
streams, then compares those bytes with the row selected by actor `+0x3C` in
the extracted MT packs. Example:

```text
python tools/mt_capture_match.py extract/analysis/fifth_leaf_dev_v6_cases --entry 0x8c09f036 --case 1 --assets extract/gamedata
```

Case 1 carries motion `0x60F`, cycle 90, 29 keyed-channel counts, 99 key-time
bytes, and a bounded 1,688-byte tuple stream. All four captured streams match
exactly in 90 of the 91 MT packs. Scanning all 92 retained cases finds 71 with
complete stream pages; each matches one or more extracted MT rows. The other
21 cases lack part of the tuple stream in their captured RAM windows and are
reported as incomplete. Observed IDs include `0x6D`, `0x93`, `0x41A`, `0x5C8`,
and `0x60F`; the capture does not identify their actions or prove which pack
belongs to which fighter.

This closes an asset-boundary question: for these captured records, the
runtime-mounted streams are byte-identical to the clean-room source-row
decoder. It still does not validate evaluated output against a game-produced
pose, map channels to POL models, or provide the missing action-to-motion
table.

## Natural two-actor motion transitions

The reusable `tools/mem_watch.py` trace with
`tools/vf3_play_motion_strikes.txt` records both actors during the same s29
replay. Actor 1 begins at `0x0C1FEFE4` with motion `0x63E`, cycle 50, and record
pointer `0x0C226864`; it transitions to motion `0x2A9`, cycle 160. Actor 2
begins at `0x0C20138C` with motion `0x3F5`, cycle 40, and record pointer
`0x0C227064`; it transitions to motion `0x953`, cycle 64. Both record pointers
remain stable across the observed transition. The trace has no frame timestamp,
so the sequence demonstrates state change under the strike inputs but does
not label either motion as a specific attack or identify the transition frame.

A focused capsule reobserve watches the nested PC `0x0C0AD1B8` in that same
run. It records the same two motion IDs and the return PC `0x0C0A995A` for both
actors:

```text
python tools/oracle/reobserve.py --batch-dir extract/analysis/native_pose_chain_s29_v1 --children tools/oracle/native_motion_action_children.txt --run s29 --watch-mode children --emulator tools/emu/flycast-build/flycast_v3.exe --out extract/analysis/native_motion_action_probe_s29_v4
python tools/motion_probe_report.py extract/analysis/native_motion_action_probe_s29_v4/f_8c0ad1b8.cases --show-pr
```

The caller at `0x0C0A9956` reads the halfword at the descriptor pointer in
actor `+0x58`, then calls the motion update at `0x0C0AD178`. The watched PC is
inside that update, so r5 is the current motion ID there. This confirms the
IDs at the update point but does not recover which input action selected them;
the capsule preserves no frame timestamp.

The adjacent wrapper at `0x8C0AA444` is not an action-to-motion selector. It
indexes the callback table at `0x0C10F4B0` with the high byte of the pointer at
actor `+0x38`; a `0x0C` pointer selects row 12 (`0x0C0AC900`). That callback
forwards the current descriptor motion to `0x0C0AD178`. The new
`tools/sh4_fn_table.py` report makes this address-domain dispatch visible, but
it does not expose the caller that assigns the motion ID.

`tools/oracle/native_motion_input_sweep.py` screens isolated controls from
state 29. Neutral plus each power-of-two mask from `0x0001` through `0x0800`,
and the combined masks from the strike script (`0x0012`, `0x0021`, `0x0042`,
`0x0081`, `0x0102`,
`0x0201`, `0x0022`, `0x0011`, `0x0082`, `0x0041`) were each replayed from the
same state; the combined masks were held for 15 frames. All replays completed,
but none recorded a call at `0x0C0AD1B8`. These screens therefore do not
attribute the observed transitions to individual controls. With the reusable
context mode and the 1,800-frame strike script, the baseline records two calls:
`0x2A9` for actor `0x0C1FEFE4` and `0x953` for actor `0x0C20138C`. Replacing
the baseline input with `0x21` at frames 75–89, or with `0x12` at frames
15–29, preserves that same ordered sequence. The samples have no frame
timestamps and do not establish which control selects either motion;
action-to-motion IDs remain unresolved.

`tools/native_motion_timeline_probe.py` now adds frame-clock savestate
checkpoints to a `KEYF` schedule and records each actor's motion ID, cycle,
descriptor pointer, and MT record pointer with the input mask active at that
frame. `tools/native_motion_timeline_compare.py` compares those rows against
a second replay. Replaying state 29 with the strike schedule and with every
input mask cleared produced 22 matched actor/frame samples: 18 had the same
motion state and 4 differed. The `0x2A9` and `0x953` samples at frames 900 and
1050 were identical in both runs, so this schedule does not support assigning
those IDs to player attacks. The later differences are not attributed to a
specific input; repeated runs can also diverge even when their input is the
same before the intervention.

An earlier mask-`0x2` pulse comparison appeared to change actor
`0x0C1FEFE4` from `0x61A` to `0x61C` at frame 585. A repeated neutral replay
also reached `0x61C` at that frame, so the apparent change was not caused by
the pulse. A matched neutral/pulse pair using the same checkpoint schedule
already differed in both actors at frame 569, before the pulse began at 570;
the actors then matched again at frames 585 and 600. The comparer now accepts
`--intervention-frame` and flags this pre-intervention drift. Later differences
cannot be attributed to the pulse, and action-to-motion IDs remain unresolved.

Reproduce the paired captures and comparison with:

```powershell
python tools/native_motion_timeline_probe.py `
  --state tools/emu/flycast-build/data/vf3_29.state `
  --play tools/vf3_play_motion_strikes.txt `
  --image extract/exe/1ST_READ.unsc.bin `
  --actor 0x0c1fefe4 --actor 0x0c20138c --checkpoint 150 `
  --out extract/analysis/native_motion_timeline_s29_v1

python tools/native_motion_timeline_probe.py `
  --state tools/emu/flycast-build/data/vf3_29.state `
  --play tools/vf3_play_motion_strikes.txt `
  --image extract/exe/1ST_READ.unsc.bin `
  --actor 0x0c1fefe4 --actor 0x0c20138c --checkpoint 150 `
  --neutral-input --out extract/analysis/native_motion_timeline_s29_neutral_v1

python tools/native_motion_timeline_compare.py `
  extract/analysis/native_motion_timeline_s29_v1/motion_timeline.json `
  extract/analysis/native_motion_timeline_s29_neutral_v1/motion_timeline.json `
  --out extract/analysis/native_motion_timeline_s29_compare_v1.json

python tools/native_motion_timeline_probe.py `
  --state tools/emu/flycast-build/data/vf3_29.state `
  --play tools/vf3_play_motion_strikes.txt `
  --image extract/exe/1ST_READ.unsc.bin `
  --actor 0x0c1fefe4 --actor 0x0c20138c --checkpoint 500 `
  --neutral-input --sample-frame 540 --sample-frame 569 `
  --sample-frame 570 --sample-frame 585 --sample-frame 600 `
  --out extract/analysis/native_motion_timeline_s29_neutral_window_v1

python tools/native_motion_timeline_probe.py `
  --state tools/emu/flycast-build/data/vf3_29.state `
  --play tools/vf3_play_motion_strikes.txt `
  --image extract/exe/1ST_READ.unsc.bin `
  --actor 0x0c1fefe4 --actor 0x0c20138c --checkpoint 500 `
  --neutral-input --pulse 570:600:0x2 `
  --sample-frame 540 --sample-frame 569 --sample-frame 570 `
  --sample-frame 585 --sample-frame 600 `
  --out extract/analysis/native_motion_timeline_s29_pulse_b_window_v1

python tools/native_motion_timeline_compare.py `
  extract/analysis/native_motion_timeline_s29_neutral_window_v1/motion_timeline.json `
  extract/analysis/native_motion_timeline_s29_pulse_b_window_v1/motion_timeline.json `
  --intervention-frame 570 `
  --out extract/analysis/native_motion_timeline_s29_pulse_b_window_compare_v1.json
```

`tools/oracle/native_motion_eval_watch.txt` lets `reobserve.py` retain the
nested `0x8C09D6E0` evaluator cases. The actor motion field is outside those
sparse RAM windows, so `mt_capture_match.py --motion-id` uses the independently
observed IDs for exact source-row comparison:

```text
python tools/oracle/reobserve.py --batch-dir extract/analysis/native_pose_chain_s29_v1 --children tools/oracle/native_motion_eval_watch.txt --run s29 --watch-mode children --emulator tools/emu/flycast-build/flycast_v3.exe --out extract/analysis/native_motion_eval_s29_rerun_v1
python tools/mt_capture_match.py extract/analysis/native_motion_eval_s29_rerun_v1 --entry 0x8c09d6e0 --case 1 --motion-id 0x2a9 --assets extract/gamedata
python tools/mt_capture_match.py extract/analysis/native_motion_eval_s29_rerun_v1 --entry 0x8c09d6e0 --case 8 --motion-id 0x953 --assets extract/gamedata
```

Each case matches 13 of 91 packs exactly. The candidate matches include
`MTAIKJAC.BIN` for `0x2A9` and `MTJACKAG.BIN` for `0x953`, but 12 other packs
also share each exact row, so pack identity and action labels remain open.
`mt_capture_eval_compare.py` can use the same explicit IDs and frame 1 to
compare the native evaluator with each case's final channel block. It reports
30/63 unchanged channels for case 1 and 27/63 for case 8. Those counts are
diagnostic only: the guest block has already passed through `0x8C09F432`, and
the captured RAM windows do not include the mounted record bodies needed to
independently qualify this raw evaluator output. The MT-to-channel-to-POL pose
path remains unproven.

## Compare MT evaluator and pose snapshots

`tools/mt_pose_capture_compare.py` reads the before/after RAM shadows for one
or more retained replay cases. It reports the actor's motion ID, cycle and
record pointer, changed values in the 63-channel block, changed words in the
23 joint records, and changes in the matrix and cached-pose areas. Bone indices
use the joint-advance table recovered for `0x8C091438`; the report deliberately
does not assign channel or bone names and does not map either to a POL part.

```text
python tools/mt_pose_capture_compare.py extract/analysis/coverage_65_replay_record_dev_v3 --entry 0x8c0a9036 --case 4 --actor-register r5
python tools/mt_pose_capture_compare.py extract/analysis/coverage_65_replay_record_dev_v3 --entry 0x8c0a9036 --case 4 --case 5 --actor-register r5 --out extract/analysis/mt_pose_compare.json
python tools/mt_pose_capture_compare.py extract/analysis/coverage_65_replay_record_dev_v3 --entry 0x8c0a9036 --actor-register r5 --summary
```

Case 4 is a controlled descriptor probe, not a naturally labeled action
sequence. Its motion ID changes from `0x956` to `0x41A` while the cycle remains
60; nine channels and joint records change, but this specimen has no changes
in the matrix or cached-pose areas. The corresponding mounted streams do not
exactly match extracted asset rows (`mt_capture_match.py` reports no exact
match), so this observation is not enough to wire animation into the native
fighter. Use `--verbose` to include every changed word and all channel values.
Use `--summary` to scan every case in the corpus and report which regions were
captured separately from which ones changed. Non-finite channel values retain
their IEEE bit pattern in JSON output.
The optional `--out` writes a new JSON file and refuses to replace one already
present.
For a case that captures the full output matrix region, `--matrix-bin` writes
the 23 matrices from the after-shadow as 1,472 little-endian bytes (23 rows ×
16 float32 words). This supports offline render experiments; it does not add a
matrix-to-slot mapping or make the dump a runtime asset.

```text
python tools/mt_pose_capture_compare.py extract/analysis/native_pose_bones_s29_v1 --entry 0x8c091438 --case 1 --actor-register r4 --matrix-bin extract/analysis/native_pose_bones_s29_v1/case1_matrices.bin
```

`tools/mt_capture_eval_compare.py` puts the native raw evaluator beside the
captured `actor+0x1D04` channel block for a selected case:

```text
python tools/mt_capture_eval_compare.py extract/analysis/fifth_leaf_dev_v6_cases --entry 0x8c09f036 --case 1 --asset MTAKIJAC.BIN --vfa build/vf3_assets.vfa
```

The watched routine calls the 63-channel sampler at `0x8C09D670`, then calls
`0x8C09F432` before returning. The captured block is therefore downstream of
the game's channel postprocessing. The comparison reports unchanged channels
and per-channel differences as a diagnostic; inequality is expected and is not
a failure of MT stream decoding. Confirm the chosen pack with
`mt_capture_match.py` first, since multiple MT files can contain identical
rows. `vf3mtmotiondump` accepts an exact Q8 phase with `--phase-q8`; the
capture comparator forwards the actor's retained fractional phase directly.
Its optional `--phase-q8` argument overrides that captured phase.

The retained `fifth_leaf_dev_v6_cases` corpus has 92 complete invocations of
`0x8C09F036` with all four pose regions captured. A corpus-wide summary shows
the channel block changed in 87 calls (6–35 channels per call), while the 23
joint records, 23 bone matrices, and cached-pose records stayed unchanged in
all 92. In these specimens, the motion update ends at the channel stage; it
does not itself publish the later joint or matrix pose. Reproduce the boundary
check with:

```text
python tools/mt_pose_capture_compare.py extract/analysis/fifth_leaf_dev_v6_cases --entry 0x8c09f036 --summary --per-case --actor-register r4
```

## Bone-pose pointer advances

`tools/bone_pose_map.py` reads the 23-byte table at `0x0C119670` and prints
the cumulative joint offsets used by `bone_pose.c`, alongside the matrix and
cached-pose row offsets. For the retail image, run:

```text
python tools/bone_pose_map.py extract/exe/1ST_READ.unsc.bin --base 0x8c010000
```

The rows establish how the readable routine advances its joint-record pointer.
They do not establish a mapping from those records to tagged or untagged POL
models, nor from MT channels to joints.

`mt_motion_view()` in `src/media/mt.c` exposes these bounded source slices,
and `vf3_native_motion_load()` binds them to the ordinary-C evaluator without
guest addresses or record mounting. The all-asset VFA scan still validates
only table and record bounds; only the two rows above have a stream-layout
gate so far. Action labels for the recovered motion-ID lookup, cycle
progression, and mapping from 63 channels to POL parts remain open.

The random-row and fighter-kind motion-ID lookup at `0x8C0A93F8` has since
been recovered as a raw table path. See
[motion_state_table.md](motion_state_table.md) for the pointer maps and the
limits of what this proves; action labels and asset-row matches remain
unresolved.

## Natural bone-matrix capture

The retained s29 pose-chain reobservation did not watch the matrix builder,
even though it watched the channel sampler and two downstream helpers. A
focused replay from the same saved state and play script now watches
`0x8C091438` directly: `extract/analysis/native_pose_bones_s29_v1`. Its one
complete case has actor `0x0C1FEFE4`, motion ID `0x2A9`, and cycle 160.
`mt_pose_capture_compare.py` reports all **23 bone matrices changed**, while
the 63-channel values, 23 joint records, and cached-pose records stayed equal
across that invocation. The matrix builder is therefore a distinct stage after
the captured joint update; earlier “no matrix changes” results omitted this
entry.

Reproduce the focused capture with the existing run specification and the
single added watch entry:

```text
python tools/oracle/reobserve.py --batch-dir extract/analysis/native_pose_chain_s29_v1 --children extract/analysis/native_pose_bone_watch_s29.txt --run s29 --watch-mode children --emulator tools/emu/flycast-build/flycast_v3.exe --out extract/analysis/native_pose_bones_s29_v1
python tools/mt_pose_capture_compare.py extract/analysis/native_pose_bones_s29_v1 --entry 0x8c091438 --actor-register r4 --summary --per-case
```

This captures the natural matrices, but still does not assign a matrix to a
POL slot or identify the sampled motion as idle, walk, guard, attack, hit, or
recovery. Native pose playback remains open until those links are recovered.

The s29 run did not naturally enter the two style-specific model-selection
entries `0x8C09517A` and `0x8C0951E4` (0/2 nested entries captured). The loaded
state's actor at `0x0C1FEFE4` has byte `+0x60 = 11`; the readable selector only
populates the 16-slot table for values 8 and 21. That route therefore does not
explain this actor's POL composition. `mt_state_match.py` can inspect the
pre-playback saved state directly: this actor mounts motion `0x63E`, cycle 50,
whose streams match 90 of 91 pairing packs exactly. The shared matches locate
the source row but do not identify its character or action.

The adjacent setup routine at `0x8C09132E` indexes a 32-byte row table at
`0x0C110B88` with the unsigned byte at `0x0C29B880`, then passes the halfwords
at row offsets `+8` and `+10` to separate matrix helpers. `+10` reaches
`0x0C03C880`, and `+8` reaches `0x0C03C6C0`; each helper loads its argument
into FPUL, executes `FSCA`, and applies the generated vector through `FTRV`.
In the retained natural matrix-builder case, the global selector is `12`, so
the selected row has `+8 = 0xE000` and `+10 = 0x9F40`. The actor's separate
`+0x60` byte is `11` in that same case; it is not the row index used here. This
does not establish what the global selector represents or which scene/model
transform consumes the resulting matrix. `tools/fighter_matrix_rows.py`
preserves the raw rows for inspection without assigning meanings to the other
fields.

The two selector bytes in that captured case can be read directly from its
retained capsule:

```text
python tools/oracle/evidence_inspect.py case extract/analysis/native_pose_bones_s29_v1 --entry 0x8c091438 --case 1 --address 0x0c29b880 --address 0x0c1ff044 --bytes 1
```

## Front-to-fight states still do not expose player action clips

The `vf3_14.state` checkpoint from
`front_to_fight_capture_20261107_v1` has the target motion IDs
`0x2A9`/cycle 160 and `0x953`/cycle 64 at the two retained actor addresses.
A 300-frame replay with short `0x4`, `0x2`, `0x1`, and `0x8` pulses left both
IDs and their record pointers unchanged at every sampled pulse boundary. A
90-frame control-path scan of that checkpoint executed the input readers and
the MT sampler (`0x0C068F86`: 64 hits, `0x0C069078`: 456,
`0x0C09D6E0`: 38), but did not execute the watched action-update entry
`0x0C0AD1B8`. This checkpoint therefore cannot label the observed motion rows
as player actions.

`native_motion_timeline_probe.py` can now generate the neutral schedule
directly, avoiding a hand-authored schedule file for a pulse probe:

```text
python tools/native_motion_timeline_probe.py --state extract/analysis/front_to_fight_capture_20261107_v1/data/vf3_14.state --frames 300 --pulse 15:30:0x4 --pulse 45:60:0x2 --pulse 75:90:0x1 --pulse 105:120:0x8 --image extract/exe/1ST_READ.unsc.bin --actor 0x0c1fefe4 --actor 0x0c20138c --checkpoint 60 --sample-frame 15 --sample-frame 30 --sample-frame 45 --sample-frame 60 --sample-frame 75 --sample-frame 90 --sample-frame 105 --sample-frame 120 --sample-frame 150 --sample-frame 180 --sample-frame 240 --out extract/analysis/native_motion_frontfight_s14_pulses_repro_v1
python tools/front_to_fight_state_scan.py --state-dir extract/analysis/front_to_fight_capture_20261107_v1/data --pattern vf3_14.state --out extract/analysis/front_to_fight_state_scan_s14_controls_repro_v1 --frames 90 --pulse 15:30:0x4 --pulse 45:60:0x2
```
