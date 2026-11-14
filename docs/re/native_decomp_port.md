# Native source-level port plan

## Product boundary

The shipped program is a native C port. It does not boot the Dreamcast image,
run guest instructions, dispatch generated instruction adapters, or emulate the
REIOS/GD-ROM loader. The physical disc is used offline to extract assets once.
The resulting asset pack is sufficient to run the program.

The executable image and reference emulator may be used only as offline
reverse-engineering evidence. Each shipped gameplay subsystem must be a
readable C reconstruction of recovered behavior; generated instruction
adapters, a guest CPU, and emulator state cannot provide runtime behavior. The
old `vf3sdl` boot/disc bundle is opt-in (`VF3_NATIVE_ASSETS=ON`) and is not
built by the default port workflow.

## Milestones

1. **Asset pack (done):** pack the once-extracted game data into a portable,
   deterministic archive. Exclude `1ST_READ.BIN`, `SNDDRV.BIN` and
   `RELOAD.BIN`. Preserve asset names and bytes so the native C readers load
   POL, TEX, MT, DTPK and other data. Runtime builds consume this archive.

2. **Native runtime shell (done):** `vf3port` is a separate SDL3 executable
   linked only to `vf3nativeview`, `vf3nativegame`, `vf3assetpack`, and SDL3.
   It loads the Akira preview and the proven Jacky selector-entry-1 POL/TEX
   source plus ST01/ST01_E stage from VFA, starts directly in the fixed
   matchup, and reads keyboard/gamepad input. Jacky still renders as one
   unposed attachment while the remaining selector sources and native pose
   generation are integrated. Its fight updates now use SDL's performance
   counter at a fixed 60 Hz cadence, independent of render rate; the host caps
   one elapsed interval at 250 ms after a pause and carries one-shot attacks,
   Start, and rematch presses until the next simulation tick. Start and
   rematch trigger once per press, even when held across ticks. Fighter
   positions interpolate between completed ticks for smoother rendering. The
   executable has no link to `vf3core`, `vf3sdl`, the SH-4 dispatcher, or
   device services.

3. **Asset-to-scene C path (scene parser and render gate done):**
   `src/media/pol_mesh.c` resolves tagged AKI/JAC/ROB_WO2/ST01/ST01_E models into
   ordinary C vertices, triangle indices, mesh texture slots, bounds metadata,
   and per-model rows retaining the source POL slot, byte span, and mesh range.
   The POL reader also bounds every nonzero fighter slot, tagged or untagged;
   aliases share a byte span and untagged entries remain raw pending evidence
   for their part/rig meaning. Full-span scans found no exact direct pointers
   between the untagged records and tagged model starts; an encoded index map
   or external lookup table is still needed. `tools/pol_index_map_scan.py` also
   searched untagged spans for compact aligned u8/u16/u32 runs: Jacky has no
   qualifying run at lengths 23, 31, or 43; Akira has one short, unaligned
   record-like run, which does not identify a rig map. The search does not
   exclude compressed or indirect mappings. The adjacent matrix setup indexes
   a 32-byte row table with the live selector and applies the row's two angle
   fields through `FSCA`/`FTRV`; this identifies a matrix-building path but
   still does not map its output to any POL part.
   `src/media/pvr_texture.c` decodes twiddled and non-mipmapped VQ textures.
   `src/native/fighter_view.c` renders these scenes in SDL. Fighter meshes are
   submitted far-to-near by their local Y center because SDL's 2D renderer has
   no depth buffer. Parser tests check actual assets and malformed ranges;
   `vf3nativeviewtest` draws the stage and fighters from the VFA archive with an
   offscreen renderer. The source slot identities are available for later part
   selection. The stage renderer now projects X/Z floor depth through a low
   perspective camera. Camera framing, environment/background completion, and
    fighter part transforms still need visual correction. The preview accepts
    repeated `--slot` values for visual comparison and now has separate
    `--aki-slot` / `--jac-slot` selectors plus sorted slot contact sheets.
    The old contact-sheet previews use `MKAO_AKI.POL` and `MKAO_JAC.POL`;
    Jacky's slot overlays and the sequential slots-17–39-to-bones-0–22
    hypothesis remain rejected. The native host now uses `MKAO_WO2` slot 3
    for the exact source meshes found at live selector entry 1; it still lacks
    the other parts and transforms.

   The native blockout accepts Virtua Fighter's Punch+Guard throw chord and
   Punch+Kick+Guard low-throw chord, as well as the existing one-button throw
   shortcut. Both chords currently enter the same blockout throw action; the
   low-throw opponent-state check and separate VF3 throw tables are still part
   of the recovered fight-rules work. The native blockout interprets player
   left/right input toward or away from
    the opponent, converting it into stage X with the current facing. Controls
    therefore stay consistent after fighters cross. Up/down still move along
    stage depth. These control and movement rules remain provisional until the
    player-controlled fight path is captured.

    States 47 and 48 identify the actual draw data for the kind-7 actor at
    `0x0C20138C`: its 16 populated selector entries produce 44 live nodes, and
    every node matches POL positions, non-position attributes, center, and
    radius exactly. Entry 1 maps to `MKAO_WO2`/`MKAO_WOL` slot 3 meshes 0–4;
    the other entries map to `ROB_WO2` slots 35–62. The complete selector map
    and reproduction command are in `docs/re/evidence_tools.md`. The Akira
    control still matches `MKAO_AKI`/`MKAO_AK2` slot 3. The focused live
    texture-header comparison leaves both MKAO variants compatible. A new
    `tools/pvr_asset_match.py` scan finds exact copies of all five candidate
    texture payloads at the live VRAM addresses in the older P3 frame-300 dump.
    WO2 and WOL use different descriptor indices, but those payloads are
    byte-identical at the addresses used by this attachment. This supports
    WO2 as a content-equivalent source for these meshes; the captured dump does
    not identify which file the running game selected. Details are in
    `docs/re/evidence_tools.md`.

    The kind-0 Akira selector map is now retained in
    `src/native/akira_parts.c`. Comparing every live entry against the tagged
    POL set in states 47 and 48 finds the same source slots in both captures:
    entry 1 uses `MKAO_AKI` slot 3 (seven meshes), while the other 15 populated
    entries use `ROB_AKI` slots 35–62 (25 meshes total); entries 5 and 9 are
    empty. `tools/selector_asset_audit.py` makes the two-capture comparison
    repeatable. The map narrows which assets the native renderer must load,
    but it does not provide the live attachment transforms, so gameplay still
    draws the current unposed Akira preview. The command and evidence limits
    are recorded in `docs/re/evidence_tools.md`.

    `src/fight/fighter_refresh.c` and `src/fight/scene_link.c` prove the
    attachment transform relation for all 16 populated entries. The ordinary
    second pass loads matrix `actor + 0x180 + 64 * i` before dispatching its
    selector; the first pass loads that same row for special entries 1, 14,
    and 17 before dispatching their selector fields. Indices 5 and 9 are empty
    in these captures. The live `+0x180` rows therefore supply direct
    transforms for every mapped mesh, while the `+0x7c0` 23-bone table and the
    63 MT channels still need a proven connection to the native pose evaluator.

    The earlier matrix-to-vertex comparison applied captured matrices before
    comparing against the live node's raw vertices. `src/fight/display_list.c`
    applies XF during submission, after those raw nodes are read, so that test
    compared different pipeline stages and does not disprove the exact source
    matches. `src/native/fighter_view.c` now exposes
    `vf3_fighter_view_draw_model_attachment`, which applies one same-index row
    from an 18-row attachment table to a selected POL slot. The native view
    also exposes `vf3_fighter_view_draw_model_attachment_scene`, which composes
    a supplied scene matrix with the selected attachment row. It does not fetch
    the matrix at `0x0C2A5F60` from guest state. The offline tool
    `tools/native_attachment_preview.c` exercises that native composition path
    and renders the base plus all 15 mapped ROB_WO2 attachments from exported
    state-47 matrices. `src/native/jacky_parts.c` now owns the full 18-entry
    selector table and a reusable draw routine; the preview uses that same
    routine for its default composition. This removes the duplicate hardcoded
    attachment list from the diagnostic executable. The Jacky draw routine
    gathers the selected meshes from both POL packages and sorts all 44 by
    transformed mesh-center depth before submission. `src/native/akira_parts.c`
    now provides the same native draw path for Akira's 32 selected meshes from
    `MKAO_AKI` and `ROB_AKI`; the offline preview accepts `--fighter akira` to
    inspect that composition. Both APIs consume caller-supplied attachment
    matrices, and the host still has no native pose matrix source, so neither
    multipart path is wired into gameplay. Captured matrices remain offline
    preview inputs. The scene-matrix view now uses the stage renderer's
    low-camera basis and perspective distance, centered on the actor root; it
    still omits full world placement. This remains a renderer-path diagnostic,
    not a pose-playback gate.
    The scene reader now accepts ROB_WO2's `0xffffffff`
    untextured-mesh marker, and the SDL view submits those meshes without a
    texture. Its 64 tagged slots contain 122 meshes, ten of them untextured.
    Native pose generation remains open. No captured matrices or generated
    guest state are baked into gameplay.

    `tools/flycast_attachment_matrices.py` now exports an actor's 18 rows and,
    optionally, the scene matrix at `0x0c2a5f60` as reusable offline matrix
    files, alongside selector IDs and relative translations. The Jacky actor
    at `0x0c20138c` has unit-length matrix bases
    in both retained states 47 and 48, but its attachment translations differ
    substantially between them. These are live pose transforms, not static
    model offsets; the capture is useful for previewing the matrix path but
    cannot seed the native runtime. The export command and report are in
    `docs/re/evidence_tools.md`.

    The 18 attachment rows and 23 bone rows from state 47 are not identical
    transform tables: the attachment bases are unit length, while the bone
    bases vary in scale. `tools/pose_matrix_correspondence.py` makes a
    repeatable normalized comparison; its best direct row pair still differs
    by 36.3 degrees on at least one basis axis in state 47 and 47.5 degrees in
    state 48. A computed relationship between the tables remains open.

    A 600-frame write trace from state 47 narrows the producer chain. The
    helper `0x8C074854`, already readable as `vf3_vec_offset3_entry`, adds the
    actor vector at `+0x1488` to its position and to the translations in the
    25 matrix rows from `+0x180` through `+0x7C0`. The trace also shows writes
    to the actor's anchor vectors at `+0x1F14` from the existing point-transform
    helper `0x8C03B450`, and 42 float-to-halfword conversions from `+0x1D58` to
    `+0x1F50` at `0x8C09D590` (`small_leaves.c`). The unresolved orchestration
    body `0x8C09EAF2` calls the readable `aim_frame` twice with row bases at
    actor `+0x200` and `+0x300`, then calls `aim_frame_b` with an actor
    argument at `+0x480`. These are useful inputs to the attachment table,
    but the native runtime still lacks the action state and motion-to-part
    mapping needed to produce them.

    A clean SH-4 disassembly confirms that this orchestration selects a
    per-kind record from `0x0C10D3C4` using actor byte `+0x61`, with a 108-byte
    stride, before the three aim-frame calls. `tools/native_pose_type_table.py`
    exposes those records for offline review. The kind-0 and kind-7 rows used
    by the fixed native Akira/Jacky matchup contain repeated float parameters.
    The orchestration passes float3 bases at record offsets `+0x18`, `+0x24`,
    and `+0x3c` to the two `aim_frame` calls and `aim_frame_b`; these constants
    are now available in `src/native/pose_data.c`. Other record fields and
    their actor inputs remain unclassified, so the data module does not yet
    produce attachment matrices.

    `tools/mt_pose_capture_compare.py` compares actor-relative dword ranges as
    well as the 18 selector attachment rows. Its repeatable `--actor-range`
    option shows that the three endpoint spans passed to the aim-frame calls
    (`+0xCC`, `+0xFC`, `+0x15C`) do not change during any of the four retained
    `0x8C09EAF2` specimens. The builder's nearby state does change: cases 1, 2,
    and 4 update 31–32 words at `+0x640`, 12 words at `+0x740`, 4–12 words at
    `+0x1F20`, and 1–3 words at `+0x22E8`; case 3 leaves those ranges
    unchanged. The 63 MT channels, 23 output bone matrices, cached-pose records,
    and `+0x1F60` span stay unchanged in all four. This separates stable call
    inputs from state written during the orchestration but does not identify
    the fields' meanings or provide the action-to-motion relationship. The
    report is reproducible with the command in `docs/re/evidence_tools.md`.

    The attachment table starts at actor `+0x180` with a `0x40`-byte row
    stride, so the two `aim_frame` destinations begin at rows 2 and 6. Each
    `+0x100` watched region contains four rows. In the retained 600-frame
    trace, those regions each have 356 writes over 64 addresses; the `+0x480`
    region has 280 writes over 64 addresses. The main writer is the matrix
    copy/store sequence at `0x0C03B56C` and `0x0C03B62E`; the translation
    helper writes the final three words of each row. These are address and
    writer observations, not a recovered action-to-bone mapping.

    A 30-frame watch of the same state over actor `0x0C20138C` adds a sparse
    matrix view: 684 total memory records, with 96 writes at
    `0x0C03B56C` (`matrix_copy`) and three at `0x0C0B1A04`. The six complete
    4x4 outputs begin at actor offsets `+0x880`, `+0x900`, `+0x9C0`,
    `+0xA40`, `+0xB40`, and `+0xBC0`. `pose_trace_report.py` now accepts
    repeated `--export-row` offsets so this non-contiguous layout can be
    exported without an ad-hoc binary script.

    Comparing those rows with the same actor's frame-1 bone table gives
    zero-degree normalized basis candidates for sparse rows 0–5 against bone
    rows 2, 4, 7, 9, 13, and 15. Their X/Z translations agree; the Y values
    differ by 0.000–0.138. A longer trace also contains two complete matrices
    at `+0xC80` and `+0xD00`, with candidate matches to bone rows 18 and 20.
    Because FA20 records have no frame timestamps, that longer run cannot say
    which update emitted those two rows. This narrows the matrix-copy path to
    selected bone transforms but still does not map them to POL slots. Reports
    and raw exports are under
    `extract/analysis/pose_actor_writes_s47_*_v1*`.

    Filtering the 90-frame trace to the source-load/store PCs `0x0C03B568` and
    `0x0C03B56C` shows eight complete word-for-word copies within the 23-row
    matrix span: `+0x840 -> +0x880`, `+0x8C0 -> +0x900`, `+0x980 -> +0x9C0`,
    `+0xA00 -> +0xA40`, `+0xB00 -> +0xB40`, `+0xB80 -> +0xBC0`,
    `+0xC40 -> +0xC80`, and `+0xCC0 -> +0xD00`. Each destination is the
    following 64-byte row. This explains the matching basis candidates as
    copies of adjacent rows; it adds no selector-to-POL mapping. The decoder's
    repeatable `--pc` filter reproduces these accesses without a one-off trace
    parser:

    ```powershell
    python tools/mem_trace_decode.py `
      extract/analysis/pose_actor_writes_s47_90_v1.bin `
      --pc 0x0c03b568 --pc 0x0c03b56c `
      --watch-range 0x0c201b4c:0x1000 --limit 0
    ```

    `tools/pose_trace_report.py` now summarizes selected trace fields by
    writer PC, accepts explicit labels for readable source instructions,
    prints each address's last observed value with `--values`, and can export
    matrices from the last store to each word. The export is not an atomic
    snapshot because the trace has record order but no frame timestamps:

    ```powershell
    python tools/pose_trace_report.py `
      extract/analysis/pose_orchestration_outputs_s47_600_v1.bin `
      --actor 0x0c20138c `
      --field row_0200:0x200:0x100 `
      --field row_0300:0x300:0x100 `
      --field row_0480:0x480:0x100 `
      --pc-label 0x0c03b56c:matrix_copy `
      --pc-label 0x0c03b62e:matrix_store `
      --out extract/analysis/pose_orchestration_outputs_s47_600_v1_report.json
    ```

    Reproduce the field trace and summarize its writers with:

    ```powershell
    python tools/mem_watch.py `
      extract/analysis/flycast_pose_capture_s26_v1/data/vf3_47.state `
      --watch-range 0x0c2032a0:0xc8 `
      --watch-range 0x0c202734:0x10 `
      --watch-range 0x0c202814:0xc `
      --emulator tools/emu/flycast-build/flycast_v3.exe `
      --out-dir extract/analysis `
      --name pose_builder_fields_s47_600_v1 --frames 600
    python tools/mem_trace_decode.py `
      extract/analysis/pose_builder_fields_s47_600_v1.bin `
      --watch-range 0x0c2032a0:0xc8 `
      --watch-range 0x0c202734:0x10 `
      --watch-range 0x0c202814:0xc `
      --writes --summary --limit 0
    ```

4. **Character motion (stream decode landed; not playable yet):**
   `src/media/mt.c` reads the MT slot table and record spans; `tests/mt_asset_replay.c`
   checks all 91 MT assets from VFA (209,925 slot references). The native C
   path now resolves the runtime's one-based motion ID into packed opcodes,
   counts, key times, and bounded float tuples. Representative MTAKIJAC motion
   `0x41A` and MTJACLAU motion `0x956` are evaluated directly from VFA bytes.
   `src/fight/mt_play.c` remains the readable 63-channel reference evaluator;
   `src/native/motion.c` evaluates the same bounded slices without guest
   addresses. It also exposes the recovered `0x8C09D590` conversion from a
   42-float source span to the actor's 42 stored halfword fields, using SH-4
   truncation toward zero and the low 16 bits. The guest reads that span at
   `r4+0x1D58` and writes at `r4+0x1F50`. Disassembly shows `0x1D58` is 21
   floats after the evaluator's `r4+0x1D04` output, so these inputs are
   channels 21–62. `vf3_native_motion_eval_pose_fields()` now composes the
   native evaluator with this suffix conversion, and `vf3mtmotiondump` can
   print both through `--pose-fields`. This closes the evaluator-to-packed-
   field link; those fields are still not assigned to joints or POL parts.
   Inspect both outputs with:

   ```powershell
   build/vf3mtmotiondump.exe build/vf3_assets.vfa MTAKIJAC.BIN `
     0x41A 90 0 1 --pose-fields
   ```

   The capture comparator's `--pose-fields` mode in
   `tools/mt_capture_eval_compare.py` compares the native packed suffix with
   the captured halfwords and separately checks the captured source-to-
   destination FTRC conversion, which matches all 42 fields in the recorded
   case.
   The comparator passes the exact captured Q8 phase; use `--phase-q8` to
   override it. Reproduce the case with:

   ```powershell
   python tools/mt_capture_eval_compare.py `
     extract/analysis/fifth_leaf_dev_v6_cases `
     --entry 0x8c09f036 --case 1 --asset MTAKIJAC.BIN `
     --vfa build/vf3_assets.vfa --dump build/vf3mtmotiondump.exe --pose-fields
   ```
   The orchestration call `0x8C09EAF2` was also reobserved from the retained
   s29 pose-chain run using `tools/oracle/native_pose_orchestration_watch.txt`.
   Its four complete cases cover actors `0x0C1FEFE4` / `0x0C20138C` at motion
   IDs `0x2A9` / `0x953`. In all four, the 63-float block at `+0x1D04` is
   unchanged across the call, the joint-record area at `+0x180` changes, and
   the bone matrices at `+0x7C0` and cached records at `+0xE00` remain
   unchanged. The 42-float span at `+0x1D58` and its halfword destination at
   `+0x1F50` are unchanged too; each of the 42 destination words matches the
   same-index FTRC result. This locates a joint-record update stage between
   motion evaluation and the separate bone-matrix builder. It does not prove
   how the evaluator's 63 values map to that stage or to POL parts.

   The wrapper that closes this stage is readable C as well:
   `src/fight/pose_post.c` implements `0x8C09F432` and its quantiser
   `0x8C09F500` - five point clamps around two quantisations of the channel
   block. It reads the actor's band words at `+0x3E`, `+0x1FB0`, `+0x1FAC`
   and `+0x1A00`, the kind byte at `+0x61` and the literal pool at run time,
   and writes the two destination triples at `+0x233C` / `+0x2342`. The port
   is proved against the retained generated translation (55 differential
   cases) and against the four-case s29 corpus (`4/4`, including runs that
   serve only the wrapper and only the quantiser). See
   `docs/re/pose_post.md`.

   `tools/mt_pose_capture_compare.py --pose-fields` now reports those two
   42-field spans and their per-index FTRC agreement for a selected case or a
   corpus summary. Reproduce the captured result with:

   ```powershell
   python tools/oracle/reobserve.py `
     --batch-dir extract/analysis/native_pose_chain_s29_v1 `
     --children tools/oracle/native_pose_orchestration_watch.txt `
     --run s29 --watch-mode children `
     --emulator tools/emu/flycast-build/flycast_v3.exe `
     --out extract/analysis/native_pose_orchestration_s29_v1
   python tools/mt_pose_capture_compare.py `
     extract/analysis/native_pose_orchestration_s29_v1 `
     --entry 0x8c09eaf2 --actor-register r4 `
     --summary --per-case --pose-fields
   ```

   `src/native/motion.c` now also contains the native Z-Y-X Euler matrix
   primitive used by the readable engine's `0x8C09D480` path. It uses the
   recovered 65,536-units-per-turn convention and returns a column-major
   rotation matrix. The primitive is ready for pose reconstruction, but is not
   assigned to any field group or model part yet.

   Natural s29 strike-input tracing now observes two independent
   motion transitions (`0x63E` to `0x2A9` at cycle 160, and `0x3F5` to `0x953`
   at cycle 64); their captured mounted streams each match 13 extracted MT
   packs exactly. This confirms motion-row availability in the asset set, but
   duplicate pack matches do not identify the fighter/action, and the
   post-processed channels still lack a proven POL-part mapping. Differential
   and mutation gates cover interpolation, cycle wrap,
   zero-key streams and sign-bit behavior. Still open: action-to-motion IDs,
   the runtime cycle source for native actions, channel-to-POL part mapping,
   and pose updates. Minimum clips: idle, walk, guard, attack, hit, knockdown
   and recovery. Gate: those clips advance from VFA assets and both fighters
   face, approach and animate independently without guest memory or adapter
   dispatch. The evaluator also rejects a zero-duration keyframe interval
   with an explicit error and leaves the output array unchanged, so a bad
   cycle/phase pair cannot feed a non-finite value into a future pose path.

   The reusable `tools/oracle/native_motion_input_sweep.py` screens one input
   mask per replay and can inject it into the full strike-input schedule. The
   isolated masks did not reach the watched update. In contextual mode, the
   unmodified schedule reproduced motions `0x2A9` and `0x953`; replacing its
   input with `0x21` at frames 75–89 or `0x12` at frames 15–29 kept the same
   two captured samples. The result does not assign actions, so action-to-motion
   IDs remain open.

`tools/native_motion_corpus_audit.py` now inventories these retained run
manifests and watched `.cases` files without replaying the emulator. Its audit
of `native_motion_action_controls_v4` confirms all five 600-frame runs had
zero watched calls; the s29 baseline and `0x12` contextual replay each retain
the same two samples (`0x2A9`, `0x953`). This is a reusable evidence check,
not a motion/action mapping:

```powershell
python tools/native_motion_corpus_audit.py `
  extract/analysis/native_motion_action_controls_v4 `
  extract/analysis/native_motion_action_probe_s29_v4 `
  extract/analysis/native_motion_context_s29_v4 `
  --baseline extract/analysis/native_motion_context_s29_v4/baseline/f_8c0ad1b8.cases
```

   `tools/native_motion_input_probe.py` now watches the actor motion ID, phase,
   and loop length directly while applying timed frame-clock input pulses. On
   2026-11-06 it replayed state 47 for 180 frames with masks `0x4`, `0x2`,
   `0x1`, and `0x8` against actors `0x0C1FEFE4` and `0x0C20138C`. Flycast's
   log confirms each mask reached the pad as its active-low kcode. The actors'
   motion IDs stayed `0x83C` and `0x60F`; the watched fields show no writes to
   either motion-ID halfword during the replay. This did not yield a controlled
   action transition. A 900-frame instruction trace from the same state hit
   fight workers `0x0C073C2A` (84), `0x0C068F86` (192), `0x0C069078` (617), and
   the MT evaluator `0x0C09D6E0` (336), but never hit `0x0C0AD1B8` (0). A
   separate 1,791-frame strike-script replay also left both motion IDs
   unchanged while their phase fields advanced. State 47 is an active
   autonomous fight/demo path, not a player-control capture; this does not
   establish whether the controls work in a user-started round.
    The saved Jacky actor has motion `0x60F`, raw `+0x3E` frame field `15`, and
    cycle `90`. `tools/mt_state_match.py` now reports that frame field with the
    motion and cycle, resolves the mounted record, and finds exact
    opcode/count/time/tuple matches in 90 of 91 extracted MT packs (29 counts,
    99 key times, 1,688 tuple bytes). This validates the retained motion row,
    but the many aliases do not identify its character/action label or map its
    channels to parts. Reproduce the match with:

    ```powershell
    python tools/mt_state_match.py `
      extract/analysis/flycast_pose_capture_s26_v1/data/vf3_47.state `
      --image extract/exe/1ST_READ.unsc.bin `
      --actor 0x0c20138c --assets extract/gamedata
    ```

   The raw capture is retained under the ignored
   `extract/analysis/native_motion_input_probe_s47_v1/` directory. Reproduce
   it with:

   ```powershell
   python tools/native_motion_input_probe.py `
     --state extract/analysis/flycast_pose_capture_s26_v1/data/vf3_47.state `
     --emulator tools/emu/flycast-build/flycast_v3.exe `
     --out extract/analysis/native_motion_input_probe_s47_v2 `
     --frames 180 --actor 0x0c1fefe4 --actor 0x0c20138c `
     --pulse 15:30:0x4 --pulse 45:60:0x2 `
     --pulse 75:90:0x1 --pulse 105:120:0x8
   ```

   The new `tools/native_motion_timeline_probe.py` adds timestamped state
   samples to a saved-state input replay; `tools/native_motion_timeline_compare.py`
   compares the actor fields at matching frames. On state 29, the two `0x2A9` /
   `0x953` samples at frames 900 and 1050 also occur in the all-neutral replay.
   A repeated neutral run also reaches `0x61C` at frame 585. A matched pulse
   comparison diverged in both actors at frame 569, before its frame-570 input
   began; `--intervention-frame` now flags such drift. These replays do not
   support an input-to-motion assignment. Full report and commands:
   `docs/re/mt_fields.md`.

   The timeline probe also accepts `--include-pose`; it writes a
   `pose_timeline.jsonl` sample beside the ordinary report with all 63 raw
   channels, 42 packed pose fields, 18 attachment rows, and 23 bone rows for
   each actor at each checkpoint. Non-finite matrix values retain their raw
   float bits. This makes multi-frame channel-to-pose comparisons reproducible
   without assigning any channel or row to a named bone or model part.
   A 14-frame capture from state 47 on 2026-11-07 remained frozen: the motion
   phase, 63 channels, 42 packed fields, all 23 bone rows, and all 18
   attachment rows stayed unchanged across 13 same-motion frame pairs.
   `tools/native_pose_channel_correlate.py` confirmed there was no dynamic
   input to correlate. This is consistent with the missing action-update hit;
   it does not establish the channel-to-matrix mapping. Reproduce the report
   from the retained capture with:

   ```powershell
   python tools/native_pose_channel_correlate.py `
     extract/analysis/native_motion_pose_s47_dense_v2/pose_timeline.jsonl `
     --table both --feature both --minimum-dynamic-pairs 1 `
     --output extract/analysis/native_motion_pose_s47_dense_v2/channel_correlation.json
   ```

   The timeline probe now also accepts `--include-joints`, which writes a
   `joint_timeline.jsonl` containing the 23 variable-stride 64-byte record
   prefixes, their actor offsets, the 63 postprocessed channel values, and the
   motion fields at each checkpoint. `--sample-range START:END:STEP` adds
   sparse half-open frame ranges; setting `--checkpoint` beyond the run length
   keeps only those selected snapshots. The new reusable
   `tools/native_joint_channel_correlate.py` ranks channel-change versus
   float-word-change correlations while requiring motion ID, cycle, descriptor
   pointer, and mounted-record pointer to remain constant across each pair.

   On a 2026-11-07 neutral replay from state 29, five-frame samples across
   frames 840–1110 gave 6 dynamic phase pairs for Akira `0x2A9` and 11 for
   Jacky `0x953`. With a ten-pair minimum, neither actor had a candidate. At a
   three-pair minimum the report found exact-looking linear fits, but only over
   3–6 pairs and across several repeated joint offsets. Those are insufficient
   to assign channels to joints; repeated runs from this savestate also did
   not preserve the same later motion transitions. The evidence tool now
   prevents cross-motion aggregation from manufacturing the earlier high
   correlations, but pose playback is still blocked on a stable, sufficiently
   sampled channel-to-joint and joint-to-POL mapping.

   A follow-up resumed the saved state at frame 960 (Jacky `0x953`) for 60
   frames with one-frame checkpoints. All 59 snapshots retained the same
   motion, cycle, descriptor, and record pointer, but phase stayed at `10/256`;
   there were zero dynamic phase pairs and therefore no channel candidates.
   That checkpoint does not advance the animation when resumed, so its motion
   ID alone is not evidence of a live clip. The timeline and no-candidate
   report are retained under
   `extract/analysis/native_motion_pose_jacky_953_1f_v1/`.

   ```powershell
   python tools/native_motion_timeline_probe.py `
     --state tools/emu/flycast-build/data/vf3_29.state `
     --frames 1150 --checkpoint 1150 --sample-range 840:1115:5 `
     --image extract/exe/1ST_READ.unsc.bin `
     --actor 0x0c1fefe4 --actor 0x0c20138c `
     --include-joints --out extract/analysis/native_motion_pose_s29_joint_dense_v1
   python tools/native_joint_channel_correlate.py `
     extract/analysis/native_motion_pose_s29_joint_dense_v1/joint_timeline.jsonl `
     --max-gap 5 --min-pairs 10 `
     --out extract/analysis/native_motion_pose_s29_joint_dense_v1/joint_channel_correlation_tracks.json
   ```

   State 29's later checkpoint also stayed frozen when sampled every frame:
   across frames 840–899, Akira remained at phase `30/256` and Jacky at
   `29/256`. State 47 and state 48 provided advancing captures instead. Each
   was replayed for 600 frames and sampled every 10 frames from 30 through
   580; `native_motion_window_rank.py` selected windows with 8–11 changing
   phase pairs. Combining both captures in `native_joint_channel_correlate.py`
   found a repeatable Jacky lead from channel 1 to word 13 at actor offsets
   `+0x180` and `+0x440`: four distinct tracks across motion IDs `0x05C8`,
   `0x060F`, and `0x0B1C`, median absolute correlation `0.9998` and median
   normalized fit RMS `0.0207`. This is still only a correlation: the words'
   meanings, the record-to-bone relationship, and the joint-to-POL mapping are
   unknown. No runtime pose mapping was wired from this result, so the native
   renderer remains unposed pending those links. The capture timelines and
   combined report are retained under
   `extract/analysis/native_motion_pose_s47_joint_10f_30_600_v1/`,
   `extract/analysis/native_motion_pose_s48_joint_10f_30_600_v1/`, and
   `extract/analysis/native_motion_pose_s47_s48_joint_correlation_v1.json`.
   `tools/native_pose_timeline_extract.py` now rebuilds the pose timeline
   offline from an existing motion CSV and its saved checkpoint states. On
   the same Jacky captures, direct packed-field-to-bone rotation fits remained
   poor: state 47's best candidate had 50.103 degrees angle RMS and 71.936
   degrees orientation RMS; state 48's best had 43.844 and 74.487 degrees.
   This rejects the direct pose-field-to-world-bone interpretation for these
   samples, but does not rule out hierarchy composition or an intermediate
   joint-record transform. The offline pose timelines and reports are retained
   beside each capture as `pose_timeline_offline_jacky.jsonl`; the state 47
   bone report is `pose_channel_correlation_offline_jacky_bones.json`, and the
   state 48 full report is `pose_channel_correlation_offline_jacky.json`.

   A longer 1,799-frame replay from state 47 sampled both actors every 20
   frames and exposed six distinct Jacky motion tracks. Disassembly of
   `0x8C09DA72` shows a separate path before attachment construction: it walks
   seven vec3s from actor `+0x1D04`, writes seven vec3 outputs beginning at
   `+0x1EFC`, optionally subtracts the first input vec3 under actor flag
   `0x20000000`, and transforms each result by the actor yaw and translated
   position. It also applies a mode-specific Y offset (mode 11 subtracts
   `0.055`) and can zero a point's Y under the global/action flag condition.
   The `0x8C03C880` setup rebuilds the rotation from the actor's halfword at
   `+0x1E`; the matrix's prior orientation is not used. A targeted read of
   case 1 in `native_pose_orchestration_s29_v1` confirms all 21 output words
   change, while the 21 source words do not. Recomputing the yaw rotation and
   mode offset matches all seven captured output vectors to float rounding.
   `src/native/motion_vectors.c` now builds this affine transform directly
   from yaw, position, mode and the `+72` flags, then transforms the seven
   points with the actor-origin and Y-suppression conditions explicit. The
   timeline extractor retains the source channels and outputs.
   `tools/native_motion_vector_fit.py` remains useful for samples where the
   channel relation is less direct, but it is not evidence for attachment
   assignments. The helper is not yet wired into gameplay because the
   seven-point-to-attachment flow and the upstream motion-to-record mapping
   have not been recovered. Capture and analysis artifacts are under
   `extract/analysis/native_motion_pose_s47_dense1800_v2/`.

   Comparing those seven post-transform points with the 18 attachment-row
   translations gives a repeatable partial correspondence. Across the 89
   checkpoints, point 0 coincides with row 0 (also duplicated at rows 10/11);
   points 3, 4, 5, and 6 have nearest rows 5, 9, 14, and 17 for both fighters.
   Over the 60 same-motion consecutive pairs, root-relative point and row
   movement fits at scale 0.99–1.04 with normalized residuals 0.06–0.17 for
   those four pairs. Points 5/6 therefore track the two wrap rows, and points
   3/4 track the two empty selector rows that still carry transforms. Point 1
   stays near row 1, while point 2 has no stable direct row assignment. The
   row-0 X axis also follows the point-0-to-point-1 torso direction (mean
   absolute dot 1.000 for Jacky and Akira). This narrows the anchor hierarchy,
   but does not identify the other attachment rows or the 42-field rotation
   assignments; the inferred renderer rig remains visibly wrong.

   A parent-relative rotation fit then recovered four exact dynamic links.
   For each candidate, `R_parent^T * R_row` changes by the same Z-Y-X Euler
   delta as the assigned packed group: row 2 under row 0 uses group 3; row 5
   under row 4 uses group 5; row 6 under row 0 uses group 6; and row 9 under
   row 8 uses group 8. Jacky contributes 12–29 dynamic pairs over 3–7 motion
   tracks per link; Akira independently reproduces the same links with zero
   measured orientation error (2–28 pairs, 2–12 tracks). These mappings are
   now in `src/native/motion_pose.c`, including rows 5 and 9: their selector
   entries have no mesh, but their matrices are real pivots. The rest offsets
   and remaining row/group links are still inferred, so the update does not
   make the current preview a verified pose.

    `tools/native_attachment_parent_fit.py` now tests every attachment row
    against every possible parent and packed pose group, fitting a constant
    bind rotation over changing-phase pairs within each motion track. On the
    1,799-frame state-47 timeline it independently recovers rows 2/0 group 3,
    5/4 group 5, 6/0 group 6, and 9/8 group 8 with zero measured bind drift.
    It also finds root-relative candidates for rows 14/group 11 and 17/group
    13: median drift is below 0.00001 degrees across four/five tracks, but the
    worst track reaches 2.29/9.24 degrees. Those two wrap assignments are now
    wired as provisional links; the lower consistency means they need another
    independent capture before treating them as recovered. Full report:
    `extract/analysis/native_attachment_parent_fit_v2.json`. Reproduce it with:

    ```powershell
    python tools/native_attachment_parent_fit.py `
      extract/analysis/native_motion_pose_s47_dense1800_v2/pose_vectors_timeline.jsonl `
      --top 60 --out extract/analysis/native_attachment_parent_fit_v2.json
    ```

    The same analyzer now ranks parent candidates by how stable the captured
    parent-local translation stays across each track. That ranking does not
    identify a unique hierarchy for the remaining rows, so I have not used it
    to wire more guessed parents. It does confirm the specific pivot offsets
    already visible in the exact row-relative samples: rows 5/9 are +0.25 on
    their parent's local X axis for Akira; Jacky's median is +0.27 (0.015
    standard deviation). Those measured offsets replace the old zero-position
    pivots in `src/native/motion_pose.c`. The rendered preview is unchanged
    because rows 5/9 have no directly attached mesh; their matrices remain
    needed for the recovered selector pipeline. The extended rotation and
    translation report is `extract/analysis/native_attachment_parent_fit_v3.json`;
    regenerate it with the same command above, changing the output name to v3.

    The retail call body at `0x8C09EAF2` explains why row fitting alone cannot
    supply the full rig. It selects the 108-byte kind row, calls
    `0x8C09DA72` to transform the seven motion anchor points, then calls
    `aim_frame` for output blocks at actor `+0x200` and `+0x300`, and
    `aim_frame_b` at `+0x480` (with a conditional second block at `+0x540`).
    The builder also composes additional actor angles and copies its generated
    matrices into the selector table. The point transform is available in
    `src/native/motion_vectors.c`; the complete source-level orchestration and
    its slot copies still need to be ported. Use
    `python tools/sh4dump.py f 8c09eaf2 420` to inspect the retail body.

    The actor-input capture and point-transform checks are reusable tools:
    `native_pose_timeline_extract.py` records yaw, actor flags, pose flags,
    and position; `native_motion_points_audit.py` compares the seven-point
    calculation with the captured output. `native_motion_root_orientation_audit.py`
    checks whether captured anchor-pair directions explain each matrix axis.
    For a focused kind-0/7 comparison of axes 1 and 2, run:

    ```powershell
    python tools/native_motion_root_orientation_audit.py `
      extract/analysis/native_motion_pose_s47_dense1800_v2/pose_vectors_with_actor_inputs_v3.jsonl `
      --kind 0 --kind 7 --row-axis 1 --row-axis 2 --top 20
    ```

    The anchor direction is an incomplete explanation so far: row-0 axis 0
    matches point 0-to-1 exactly in both kinds, while the best remaining
    directions are weaker (Jacky row-0 axis 2 aligns with point 3-to-4 at
    median absolute dot 0.956). The direct `0x8C09D9EA` angle sequence does
    not match the final captured row-0 matrix and has not been wired in.

    I re-extracted actor inputs from the state-29 timeline, which actually
    contains the native preview clips `0x2A9` and `0x953`; the earlier state-47
    fit uses different motions and cannot justify changing those clips. The
    reusable root audit now ranks directed anchor-pair bases and tests a
    constant bind correction per actor kind and motion. For motion `0x2A9`,
    kind 1's best basis is X=point 0→1, Z=point 3→2 (17 samples, 2.00° raw
    median, 0.44° bind-corrected p95). For `0x953`, kind 8's best is X=0→1,
    Z=3→4 (12 samples, 1.76° raw median and 0° bind-corrected p95). The
    corresponding kind-3 segment has only four samples and does not share a
    stable bind correction. This is a stronger root-orientation candidate,
    but still needs another capture and the live `+0x61` mode mapping before
    it can replace the guessed rig. The matching state-29 point audit contains
    seven samples and reproduces the seven-point outputs to rounding except
    for two 0.0306-unit outliers. Reproduce the inputs and reports with:

    ```powershell
    python tools/native_pose_timeline_extract.py `
      --timeline extract/analysis/native_motion_pose_s29_dense1800_v1/motion_timeline.csv `
      --image extract/exe/1ST_READ.unsc.bin `
      --out extract/analysis/native_motion_pose_s29_dense1800_v2/pose_vectors_with_actor_inputs.jsonl
    python tools/native_motion_points_audit.py `
      extract/analysis/native_motion_pose_s29_dense1800_v2/pose_vectors_with_actor_inputs.jsonl `
      --motion-id 0x2a9 --motion-id 0x953 `
      --out extract/analysis/native_motion_points_audit_s29_2a9_953.json
    python tools/native_motion_root_orientation_audit.py `
      extract/analysis/native_motion_pose_s29_dense1800_v2/pose_vectors_with_actor_inputs.jsonl `
      --motion-id 0x2a9 --motion-id 0x953 --min-samples 1 `
      --out extract/analysis/native_motion_root_orientation_audit_s29_2a9_953.json
    ```

   The current preview confirms that the remaining defect is the inferred rig,
   not just the choice of animation phase: Jacky's `--zero-fields` bind image
   is already visibly disconnected, and the captured 0x953 pose changes only
   a few fields in the first nine frames. `tools/native_motion_preview.c` now
   labels these images as diagnostic output; they do not verify valid VF3
   articulation. The preview images are in `build/motion_bind_jacky.bmp` and
   `build/motion_check_jacky_08.bmp` for this worktree.

   The seven-point transform and the pose fold now have C regression tests.
   `vf3nativemotionvectors` (tests/native_motion_vectors_replay.c) checks the
   yaw rotation, the four mode Y drops (6/8/11/12, pool floats at
   0x0C09DBF0..FC) and their gate on actor +0x48 & 0x29000, the 0x20000000
   origin subtraction, the Y-suppression helper below, and argument
   validation, against values computed from the disassembly in the test.
   `vf3nativemotionpose` (tests/native_motion_pose_replay.c) checks that
   every matrix is finite at bind for both rigs, that each measured or
   provisional row/group link (2/3, 5/5, 6/6, 9/8, 14/11, 17/13) moves when
   its own group turns and that row 1, which is outside all six subtrees,
   does not. It deliberately does not assert the authored bind joints.

   The root row is no longer authored. `vf3_native_motion_row0()` /
   `vf3_native_motion_pose_actor()` in `src/native/motion_pose.c` rebuild
   row 0 from the recovered orchestration chain: root orientation from pose
   fields 0..2 and the actor yaw, the seven-pass point 0 as the translation,
   the halfword frame from fields 3..5 and the actor `+0x22E4` argument, and
   the unit-triple heading/pitch from the summed actor triple (point 1 plus
   the `+0x208C` floats). `vf3nativemotionrow0`
   (tests/native_motion_row0_replay.c) proves it against an independent
   re-statement of the chain and against the four retained `0x8C09EAF2`
   specimens (all match to 2e-4; 13/13 mutations caught). The runtime host
   still does not carry the actor inputs the chain reads, so `vf3port` keeps
   the authored bind row until the native fight state supplies them;
   `vf3nativemotionpreview --row0 ...` exercises the recovered chain with
   the inputs supplied explicitly. See `docs/re/motion_row0.md`.

   The Y-suppression condition in the audit was inverted for one test.
   At 0x0C09DB7E the guest uses a plain `bf` against actor & 0x8000: `bf`
   branches when T is clear, and `tst` leaves T clear exactly when the bit
   is set, so the suppression runs only when that bit is CLEAR. The other
   three tests are `bt`/`bt/s` and require their bits set (global 0x800,
   actor 0x40000, pose 0x21000). `tools/native_motion_points_audit.py` and
   the new `vf3_native_motion_zero_y_mask()` helper in
   src/native/motion_vectors.c now encode it that way. No retained timeline
   exercises the arm (the global bit is clear in every sample), so this
   rests on the disassembly, not a capture.

   Re-running the audit after that fix changes nothing in the captures, and
   the remaining mismatches are checkpoint-ordering artifacts, not transform
   errors: on the state-47 timeline 132 of 178 rows reproduce the captured
   outputs to under 1e-4 (median row-max error 8.6e-7 for both actors),
   and the other rows' outputs lag their inputs by a sampling step - e.g.
   frame 760's outputs equal frame 740's actor position plus the new
   channel, exactly as a checkpoint taken between the orchestration and the
   next motion evaluation would produce. The state-29 kind-8 segment
   (frames 1260-1590) is one frozen checkpoint repeated twelve times.
   The earlier note that the state-29 audit reproduced "except for two
   0.0306-unit outliers" understated this; the median and the exact rows
   are the evidence for the transform.

   `native_pose_timeline_extract.py` now includes the 23 variable-stride joint
   records in those timelines, and `native_pose_channel_correlate.py --table
   joints` compares their rotation matrices to packed pose groups. Across 56
   samples in each of states 47 and 48, all 23 joint rows changed. The best
   one-group candidate in both captures was packed group 11 against row 17 at
   actor `+0x500`; its local-orientation RMS was 14.479/15.186 degrees and its
   angle-magnitude RMS was 12.259/9.137 degrees. Group 13 against row 22 at
   `+0x5C0` was similarly weak. These fits do not support wiring a direct
   packed-group-to-joint transform; parent composition and the joint-update
   helper path remain unresolved. Reports are retained as
   `joint_rotation_fit_20261107.json` beside each pose timeline.

   A longer neutral replay from state 29 sampled both actors every 30 frames
   for 1,799 frames. The timeline contains 41 and 42 compatible same-motion
   matrix pairs, with 20 and 22 dynamic-phase pairs. Running
   `native_pose_channel_correlate.py` on this larger sample invalidated the
   short-window attachment candidate: the best direct rotation fits remain
   about 12 degrees RMS, while the leading bone fits exceed 47 degrees. The
   seven leading translation groups also do not fit a single matrix row
   consistently. This rejects direct channel-to-row application as a usable
   pose port; it does not rule out a mapping through the joint hierarchy or
   intermediate actor records. The raw samples and report are retained under
   `extract/analysis/native_motion_pose_s29_dense1800_v1/`.

   ```powershell
   python tools/native_motion_timeline_probe.py `
     --state tools/emu/flycast-build/data/vf3_29.state `
     --frames 1800 --image extract/exe/1ST_READ.unsc.bin `
     --actor 0x0c1fefe4 --actor 0x0c20138c --checkpoint 30 `
     --include-pose --out extract/analysis/native_motion_pose_s29_dense1800_v1
   python tools/native_pose_channel_correlate.py `
     extract/analysis/native_motion_pose_s29_dense1800_v1/pose_timeline.jsonl `
     --table both --feature both --minimum-dynamic-pairs 3 `
     --max-gap 30 --output extract/analysis/native_motion_pose_s29_dense1800_v1/channel_correlation.json
   ```

   `tools/front_to_fight_capture.py` provides a reusable cold-boot menu probe.
   Its first version mislabeled the Flycast/KOS button bits: `0x10` is D-pad
   Up and `0x1` is C (which the standard-pad model masks off), not Start/A.
   The tool now defaults to Start `0x8` and A `0x4`. The earlier 5,400-frame
   run on 2026-11-06 used the wrong bits and produced states 1–8. State 7 (frame 4,200)
   carries actor kinds `+0x60 = 1/21`, `+0x61 = 1/8`, motions `0x2A9/0x953`,
   cycles `160/64`, and usable basis vectors in all 23 matrices for both
   actors. State 8 (frame 4,800) has motions `0x7DF/0x162` and cycles `42/63`.
   These records provide more natural pose snapshots, but do not identify the
   fighters or actions. Replaying state 7 for 180 frames produced 1,116,783
   instructions in the BIOS address range and no fight-loop PCs. Its populated
   actor records and matrices are stale data, so it is not a fight or
   player-control seed.
   Capture data is retained under the ignored
   `extract/analysis/front_to_fight_probe_20261106_v1/` directory. Reproduce
   the corrected cold-boot probe with:

   ```powershell
   python tools/front_to_fight_capture.py `
     --out extract/analysis/front_to_fight_probe_20261106_v3 `
     --frames 5400 --start-frame 900 --tap-interval 150 `
     --tap-length 15 --tap-until 2400 --start-mask 0x8 `
     --confirm-mask 0x4 --checkpoint 300
   ```

   `front_to_fight_capture.py` supports `--tap-until` to stop scripted taps
   before a long neutral soak. The earlier 54,000-frame run saved 14
   checkpoints with the old Up/C defaults; checkpoint 3 (frame 10,800)
   contains an autonomous Akira/Jacky pose with kind bytes `0/0` and `20/7`,
   motion IDs `0x760/0x5A9`, and usable 23-row matrix tables for both. A
   180-frame pulse replay kept both motion IDs unchanged while their phase
   fields advanced. The fight workers ran, but action-update PC `0x0C0AD1B8`
   did not. The old replay's `0x10` pulse was D-pad Up, so it provides no
   evidence about Start. Re-run with the corrected masks before drawing
   conclusions about player control; details are in
   `docs/re/front_to_fight.md`.

   The corrected 5,400-frame capture uses Start `0x8` and A `0x4` and saves
   17 states at 300-frame intervals. `tools/front_to_fight_state_scan.py`
   replays each for 90 frames with instruction tracing in both RAM mirrors.
   Nine checkpoints run
   fight workers and the MT evaluator, but none reaches controller merge
   `0x0C09AF6C`, selected-port reader `0x0C09B006`, or action update
   `0x0C0AD1B8`; the active states still look like attract choreography.
   The capture and per-state trace summary are under the ignored
   `extract/analysis/front_to_fight_probe_20261106_v3/` and
   `extract/analysis/front_to_fight_state_scan_corrected_v3_aliases/`
   directories.
   A follow-up scan replayed all 19 checkpoints from the 2026-11-07 frontend
   ladder with Start/A pulses. Eleven entered fight-worker code; none reached
   controller merge, selected-port read, or action update in either RAM
   mirror. The captured actors therefore still do not provide player-control
   evidence. The report and command are in `docs/re/front_to_fight.md`.
   The capture tool now accepts existing KEYF timelines, and the repo's
   `vf3_play_boot_mix.txt` plus a Start-held-through-frame-900 schedule were
   scanned the same way. Neither reached the controller readers. One
   action-update hit at the latter's checkpoint 16 also occurred under
   neutral, Start-only, and A-only input, so it is not evidence of a controlled
   action. A full cold-boot interpreter trace recorded one selected-port read
   at `0x8C09B006` but no controller merge or action update; its code path
   differs from the recompiler-saved checkpoint replays. The BIOS P2 alias
   `0xA0000000` is now accepted by `tools/trace_bin_sum.py`, which lets it
   summarize cold-boot traces. Details and reproduction commands are in
   `docs/re/front_to_fight.md`.

   `tools/native_input_trace_compare.py` now compares selected PC counts
   across retained input and neutral traces using the same streaming trace
   reader. The state-3 pulse and neutral replays have equal counts at the
   sampled `0x0C09D*E2` sites and `0x0C09D6E0`, and both have zero hits at the
   cited input spooler `0x0C0B1AC0` and motion update `0x0C0AD1B8`. Their total
   instruction counts differ slightly, so this only narrows those traces as
   evidence; PC counts do not establish equal machine state:

   ```powershell
   python tools/native_input_trace_compare.py `
     extract/analysis/fight_pc_trace_long_s3_v1/instruction_trace.bin `
     --candidate neutral=extract/analysis/fight_pc_trace_long_s3_neutral_v1/instruction_trace.bin `
     --pc 0x0c0b1ac0 --pc 0x0c09d4e2 --pc 0x0c09d6e2 `
     --pc 0x0c09dbe2 --pc 0x0c09dce2 --pc 0x0c09dee2 `
     --pc 0x0c0ad1b8
   ```

   The retained state 26 is the correct Akira/Jacky matchup (fighter kinds
   `0` and `7`, actor addresses `0x0C1FEFE4` and `0x0C20138C`). Its current
   motion fields are `0x41A`/cycle 60 and `0x5C8`/cycle 48; each mounted stream
   matches 13 of 91 extracted MT packs. `tools/pose_state_inventory.py` scans
   retained states for actor metadata and matrix quality. In state 26 both
   matrix spans are zero despite nonzero variable-stride joint records. A
   controlled probe at the reached GD exec-server wait loop `0x0C0434D0`
   captured five complete builder calls across those actors (one probe was
   rejected); all 23 output rows changed, but each basis remained zero, so
   those synthetic matrices are translation-only.

   State 27 supplies a natural, usable pose for the Jacky actor at
   `0x0C20138C` (`+0x60 = 20`, `+0x61 = 7`, motion `0x5C8`, cycle 48); all 23
   rows have nonzero basis vectors. Its other actor is kind 4 rather than the
   target Akira kind 0, so this is not a complete target-pair pose. Applying
   the old sequential hypothesis, Jacky slots 17–39 to matrix rows 0–22, still
   scatters the small parts around the fighter. The earlier s29 preview used
   matrices from a different actor (`+0x60 = 11`, `+0x61 = 3`) and was a
   mismatched fixture; that result is superseded by the state-27 comparison.
   The matrices establish a usable Jacky pose, but the slot-to-bone mapping and
   the Akira pose mapping remain open. `tools/pose_matrix_inspect.py` reports
   translations relative to row 0 and basis lengths; the reports remain
   diagnostic and do not assign POL slots or MT channels. Although the Jacky
   actors in states 26 and 27 share motion `0x5C8` and cycle 48, their 23 joint
   records differ in 269 of 368 words; those fields alone do not determine the
   sampled pose.

   The reusable inventory was then run across all six retained fight states
   (26, 27, 28, 29, 45, 46) for both actor addresses. State 26 remains the only
   state with the target kind-byte pair `0`/`7`, and both matrix tables are
   zero there. State 27 has a usable kind-7 Jacky pose, but its other actor is
   kind `4`; the usable kind-0 Akira pose is absent from all six states. States
   28/45 and 29/46 have usable matrices but different kind-byte pairs. A
   120-frame memory-watch run from state 26 stayed at the GD wait PC
   `0x0C0434D0` and recorded no writes to either matrix table, so that state
   does not naturally advance into a rendered fight pose.

   `tools/pose_slot_matrix_report.py` now emits the transformed AABB for every
   slot/matrix pair as review data. The state-27 Jacky report has 598 candidates
   across slots 17–42 and rows 0–22. It supplies no semantic mapping; pose
   playback remains blocked on that evidence.

   `tools/native_pose_audit.py` now packages the state inventory, raw matrix and
   joint exports, and slot/matrix candidate reports into one reproducible
   bundle. The six-state target-pair run produced 12 actor/state rows. With
   filters `0x0c1fefe4:0=MKAO_AKI.POL` and
   `0x0c20138c:7=MKAO_JAC.POL`, it emitted one candidate report: the state-27
   Jacky pose (713 rows across all 31 tagged slots). State 26's target Akira
   and Jacky matrices are both degenerate; the other nine model/state pairs
   have different kind bytes. Within that six-state set, no capture contains
   usable poses for both target fighters. States 47 and 48 below later supply
   a target-pair pose, while the mesh source and transform work remains open.

   An isolated Flycast run resumed state 26 with the restored disc and saved
   frames 300 and 600 as states 47 and 48. Both states contain the target kind
   pair and 23/23 usable bone matrices for each actor. In both captures,
   Akira selector entry 1 (`0x242`) emits seven display-list nodes whose
   positions and non-position vertex attributes match MKAO_AKI slot 3 meshes
   0–6 exactly. Some of those meshes also occur through slot 21 aliases. This
   identifies the source meshes for this selector entry only. Jacky selector
   entry 1 (`0xe06`) emits five nodes; none has an exact tagged-mesh position
   or attribute match. The nearest candidates vary between slots 3 and 14.
   In state 47, an ordered affine fit also has no strong Jacky candidate; its
   only equal-count mesh match has a mesh-radius-normalized RMS residual of
   `0.935`.
   The later two-mesh search finds recurring shape candidates in states 47 and
   48, including an exact point-count pair for node 0, but its ordered affine
   fit has mesh-normalized RMS `0.646`. Trying pairs of the captured 18
   attachment rows gives normalized nearest-point RMS `0.38`–`0.57` for nodes
   0–3 and `1.12` for node 4; the winning row pairs vary by node. These
   rankings remain diagnostic and do not justify a renderer mapping.
   In state 47, applying either the 18-row attachment table at actor `+0x180`
   or the 23-row bone table at `+0x7c0` produces no exact vertex match. The
   sphere rankings do not support a bone assignment, so the native renderer
   remains unwired to these matrices. Reproduction and detailed tool output are in
   `docs/re/evidence_tools.md` and
   `extract/analysis/native_pose_audit_s26_after_disc_v1/pose_audit.json`.

   Static tracing of the shared motion setter `0x8C0AD178` found five direct
   branch callers and 32 PC-relative literal loads of its address. Several
   handlers call it indirectly after selecting a halfword from actor-specific
   state tables. In `f_8c0aa208`, for example, the selected value is compared
   with actor `+0x3C` and only published when it changes. This confirms that
   the setter is part of state-driven motion transitions; it does not expose a
   direct button-to-motion mapping. The address lookup is reusable through
   `tools/sh4_function_at.py`, alongside `tools/sh4_literal_scan.py` and
   `tools/sh4dump.py`:

   ```powershell
   python tools/sh4_literal_scan.py extract/exe/1ST_READ.unsc.bin `
     --base 0x8c010000 --target 0x0c0ad178 --width 4
   python tools/sh4_function_at.py extract/analysis/funcs_1ST_READ.unsc.bin.csv `
     --address 0x8c0aa2b4 --address 0x8c0aa37c --physical-aliases
   python tools/sh4dump.py 8c0aa208 436
   ```

5. **Fight behavior (blockout only):** replace placeholder combat values with
   readable C mirroring recovered VF3 per-frame state, movement, attack phases,
   hitboxes, guard, damage, stun, knockdown, recovery, timer, rounds and KO.
   Add a basic CPU opponent that selects legal actions from the native fight
   state. Derive
   behavior from the existing offline captures, notes and original game data;
   keep runtime rules in `src/native` rather than routing through generated
   guest adapters. Gate: deterministic C cases cover movement, hit/guard,
   round transitions, timeout, KO and rematch.

6. **Native presentation and sound (in progress):** render both fighter
   packages and both ST01 stage layers. Movement, guard, punch, kick, and throw
   inputs are mapped to keyboard and gamepad. The offline DTPK reader now
   validates all 69 packed containers and section ranges. The native host now
   decodes candidate sample 1 from the Akira and Jacky VO packs and queues the
   attacker's voice when the blockout records a hit or blocked contact. This
   is the first audible contact cue sourced from VFA; both the span hypothesis
   and voice-to-event mapping remain provisional because DTPK sequence and
   event tables are still unmapped.
   Sequenced BGM and fighter sound effects are still open. Keep VFA as the only
   runtime data source. Part transforms and motion data are needed before the
   scene is visually playable.

7. **Minimum playable port (not done):** start directly in an Akira-versus-
   Jacky match on one stage, finish a full best-of-three match, and rematch.
   Include the model, motion, fight rules, controls and audio from milestones
   3–6. A title screen and character select are follow-up scope; the fixed
   matchup keeps this first playable slice small.

8. **Standalone release:** launch the executable with only `vf3port` and the
   VFA archive present. Verify the process has no runtime dependency on the
   physical disc, `rom/`, `extract/gamedata/`, a savestate, emulator, BIOS,
   guest executable, firmware, or generated guest adapter.

## Current implementation

`tools/pack_assets.py` builds the asset-only VFA archive and manifest from
`extract/gamedata`, which is already the output of the one-time ISO extraction.
The current local pack contains 409 data files (674,389,053 bytes) and excludes
the retail and E3 SH-4 executables plus both firmware images. The standalone
Windows target links SDL3 and libiconv statically; `tools/native_port_audit.py`
checks its imports and VFA contents. Its C reader was built separately from
`vf3core` and read a packed DTPK asset successfully. The older `vf3sdl`
research host and its boot-state/disc bundle remain available for RE work; they
are not the architecture of the source-level port.

Build the standalone target with `cmake -S . -B build -DVF3_NATIVE_PORT=ON`
and `cmake --build build --target vf3port`. Audit its runtime boundary with
`python tools/native_port_audit.py --exe build/vf3port.exe --assets build/vf3_assets.vfa`.
Run `build/vf3port.exe`; it looks
for `vf3_assets.vfa` beside the executable, then in the current directory and
`build/`. Pass a VFA path as the first argument to select another archive.
This option is separate from `VF3_SDL3`, which controls the guest-based
research host.

The native executable now consumes `MKAO_AKI`, `MKAO_WO2`, `ST01`, and
`ST01_E` scenes from the VFA archive and renders their extracted meshes and
textures. The fight state advances on a fixed 60 Hz clock even when rendering
stalls or runs at a different rate; fighter positions interpolate between
those ticks. It starts in the fixed Akira-versus-Jacky match, and its current
blockout round/rematch loop passes a seeded native C gate. Those combat values
are not yet reconstructed from VF3 evidence. Motion playback, recovered fight
rules, sequenced DTPK music and effects, and a full user-played best-of-three/rematch
acceptance run are still required before calling it playable. `vf3sdl` and
the other guest-based tools remain offline research tools; they are not part
of `vf3port`.

`vf3_native_fighter` now carries the retail pose-kind selector for this fixed
pair (Akira 0, Jacky 7). The native host resolves its fighter view from that
selector, and `src/native/pose_data.c` supplies the corresponding kind records
without reading the game executable at runtime. This connects the recovered
type data to the standalone runtime; attachment generation and motion playback
are still separate work.

The recovered column-major matrix multiply is now shared by the native motion
math and attachment renderer in `src/native/matrix.c`. The same module exposes
the verified Z-Y-X angle order, local translation, point transform, and axis
scaling primitives needed by the native attachment builder. It keeps this
math independent of guest RAM and the SH-4 matrix bank.

The same native module now ports `0x8C09DC34` (`unit_triple`): it builds the
heading and pitch basis from the recovered three-component input, composes it
with a caller matrix, and returns the horizontal length and inverse total
length. This is one of the scalar/matrix steps used by `aim_frame`; the
attachment output routine is still being ported.

`vf3_native_matrix_apply_euler_keep_translation()` ports the paired
`0x8C09D480` / `0x8C09D4E6` operation used by both aim-frame builders: apply
the three 16-bit turns in Z-Y-X order, then copy the resulting matrix while
retaining the destination transform's three translation floats. It accepts
ordinary native arrays and does not depend on the guest matrix bank. The
builder still needs its full typed input/output mapping before this primitive
can generate runtime attachment rows.

`vf3_native_matrix_pose_angles()` now ports the native helper sequence from
`0x8C09DA1E`: owner Y, input Z, input Y, then owner X plus the final input
angle, with the destination translation retained. This is the angle-matrix
step `aim_frame_b` invokes before its final attachment composition. Its input
is ordinary native data; the full builder still needs the actor fields and
output mapping that feed it.

`src/native/pose_blend.c` ports the recovered `0x8C091DE6` pose blend over two
26-halfword poses. It advances the blend weight, caps it at 1.0, converts it to
Q14 with truncation toward zero, and preserves the guest's 32-bit multiply/add,
arithmetic shift, and low-halfword store behavior. This is a reusable native
pose operation; its action-record inputs still need to be connected to the
motion and attachment pipeline.

`src/native/collision.c` adds the finite segment-capsule geometry used by the
readable `hitbox_overlap` scan, including per-capsule hit masks and nearest
surface gap. `tools/native_collision_tables.py` extracts the retail 13-entry
mask table and all thirteen 28-radius profiles into the committed
`src/native/collision_tables.inc`; rerunning the tool against the identity
image reproduces the include. `vf3_native_capsule_apply_actor_profile()` uses
the retail actor-kind byte (`+97`) to select radii, the separate mask byte
(`+0x1a20`) to select the distance mask, the `+0x1a04` profile flag to apply
the recovered 1.2 scaling rules, the `+76` bit to gate that distance mask,
and the `+0x1560` byte to preserve already-built radii when requested. The
mask does not disable hit pairs; it only filters the nearest-gap accumulator.
The API consumes already-built segment endpoints. Their runtime producer is
still unresolved, so the native blockout's distance check remains in place
until the pose path supplies real capsule geometry.

## Next implementation order

1. Recover semantic names and uses for the kind-indexed records consumed by
   `0x8C09EAF2`, then port its attachment producer and `aim_frame` helpers to
   native C. Recover action-to-motion IDs and the native cycle source. The 18
   selector attachment rows are confirmed as its outputs, but the mapping
   from MT channels to source fields is still open. Prove idle, walk and guard
   playback from VFA assets. The MT stream slices themselves are decoded in
   native C. Row 0 of the 18 is recovered and verified against the retained
   specimens (`docs/re/motion_row0.md`); the remaining 17 rows, the runtime
   actor inputs and the action-to-motion mapping are still open.
2. Add attack, hit, knockdown and recovery clips; compare native per-frame
   state with retained readable-port evidence and captured fight states.
3. Replace the match blockout with recovered movement, hit/guard, damage,
   round and CPU decisions in `src/native`; keep generated guest modules out
   of the runtime.
4. Connect DTPK sequence and sample data to SDL audio, then run the full
   keyboard/gamepad best-of-three and rematch acceptance flow with only
   `vf3port` and the VFA archive present.

The existing `src/fight` coverage ledger describes translated/reconstructed
guest bodies. Readable source ports there are reverse-engineering evidence for
the native C port; generated instruction adapters do not count toward its
playable-runtime milestones. Guest body coverage does not count as completion
of the native game runtime.

## Minimum acceptance

- Launch `vf3port` with only the executable and VFA asset pack available.
- Run one full 1P-vs-CPU match and rematch using keyboard and gamepad input.
- Render actual fighter and stage assets with their native motion data.
- Play audible game audio sourced from the extracted assets.
- Keep all shipped game behavior in readable native C; the runtime must not
  execute SH-4 code, generated instruction adapters, emulator state, or disc
  services.
