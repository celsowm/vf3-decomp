# Whole-tick oracle and mixed native harness (2026-10-15)

This is the verification scaffold behind `docs/re/plan_native_slice.md`. It lets
the ported C run a **whole scheduler tick** (`0x8c09616a`, 27 task handlers)
against a deterministic reference, even though the generated adapters only
cover part of the executed code.

Nothing here is coverage credit. The oracle exists to *verify* readable C; the
generated adapters and the readable replacements are the product.

## Pieces

| piece | where | role |
|---|---|---|
| flycast fork (`vf3trace.cpp`, `exitpc`, `rampc`) | `tools/emu/` (gitignored) | captures full 16 MiB RAM + registers at the entry and exit of one function |
| `tools/tick_capture.py` | repo | drives the fork; writes `extract/analysis/golden_<name>_<state>.bin` |
| `tick_oracle.cpp` | `tools/recomp/` (copy of `refs/dream-recomp/games/vf3tb/`) | dream-recomp driver: replays the entry RAM with the statically recompiled image, records every jsr/bsr/bsrf call (entry/exit registers + ordered stores), logs every non-RAM access |
| `tests/tick_mixed.c` (`vf3tickmix`) | repo | runs the readable scheduler + ported adapters natively, audits each native call against the oracle records, replays the oracle's effect for entries no ported code owns |
| `src/fight/task_sched.c`, `readable.c` | repo | the readable replacements (`vf3_readable_table`) |

`refs/dream-recomp` is GPL-2.0 third-party code. It stays in the gitignored
`refs/` tree and is never committed or redistributed with this repo. Only the
driver source (ours) and a three-line patch are kept in `tools/recomp/`.

## Reproduction

1. `refs/dream-recomp` configured for the game (`tools/recomp/vf3tb.toml`,
   `CMakeLists.game.txt` -> `games/vf3tb/`), built in `build-vf3`
   (gcc 16.2 ucrt64, ninja). `boot_main_no_renderer.patch` guards the
   `--present-mode` branch with `DREAM_WITH_RENDERER` so a renderer-less build
   links.
2. Rebuild the driver (must be *sourced*):
   `cd refs/dream-recomp/build-vf3; export PATH="/c/msys64/ucrt64/bin:/c/msys64/usr/bin:$PATH"; . ./link_tick.sh`
3. Capture one tick:
   `python tools/tick_capture.py 0x8c09616a --state tools/emu/flycast-build/data/vf3_7.state --frames 300 --pairs 4 --name tickx --exitpc 0x8c0961a0 --exitsp=-4`
   `--exitpc` is the exact `rts` of the function (the shared tail of the
   scheduler); without it the recorder picks a wrong exit.
4. Record the oracle run:
   ```
   A=extract/analysis
   TICK_GBR=0x0c16b880 TICK_INTERP=1 TICK_REC=$A/fxr_tick_s7.bin \
   TICK_STATS=$A/fxr_tick_s7_stats.csv TICK_DUMP=$A/oracle_tick_s7.bin \
   TICK_DEVLOG=$A/devlog_tick_s7.bin \
   refs/dream-recomp/build-vf3/games/vf3tb/vf3tb_tick.exe 0x8c09616a $A/golden_tickx_vf3_7.bin 0
   ```
5. Run the native side:
   `mingw32-make -C build -j8 vf3tickmix` then
   `TICK_DEVLOG=$A/devlog_tick_s7.bin ./build/vf3tickmix.exe 0x8c09616a $A/golden_tickx_vf3_7.bin $A/fxr_tick_s7.bin $A/oracle_tick_s7.bin 0`

### Environment variables

Oracle driver: `TICK_GBR` (**required**: GBR is per-task context and is not part
of the capture; `0x0c16b880` for state vf3_7), `TICK_INTERP`, `TICK_REC`,
`TICK_STATS`, `TICK_DUMP`, `TICK_DEVLOG`, `TICK_STEPS`, `TICK_REC_DEPTH`,
`TICK_WATCHW=<addr>` (print the first writers of a 256-byte window).

Native harness: `TICK_DEVLOG`, `TICK_GBR` (default `0x0c16b880`),
`TICK_TRACE_UNDER=<entry>` (print every dispatch and return beneath that entry),
`TICK_NOCOMPLETE=1` (turn off call completion, see below), `TICK_NATIVE_DUMP=<file>`
(final native regs+RAM in the oracle dump layout).

## What had to be learned (each cost a debugging round)

* **Generated adapters refuse `@(disp,gbr)` unless `s->gbr_known` and
  `ldc Rm,Rn_BANK` unless `s->bank_known`.** The capture format carries
  neither, so a missing GBR looked like an FPU failure. The harness sets both.
  GBR itself was found from the stores of three known pointers at
  `gbr+12/16/20` in the oracle's final RAM.
* **Link register alias.** Real hardware has `pr = 0x8C096188` (P1 alias).
  Comparisons mask with `0x1FFFFFFF`; the readable scheduler returns to the P1
  alias so stack stores match.
* **Per-call ordinal.** The oracle only records jsr/bsr/bsrf; functions
  entered by `jmp` (tail jumps such as `0x0c055646 -> 0x0c03c4a0`) and
  fragment seeds forwarded between adapter files are not calls. Native calls
  and oracle records are matched by `(entry, pr)` + running ordinal, and a
  call that tail-jumps is audited when its continuation reaches the real `rts`.
* **Call completion** (`vf3_family_complete_calls`, `family_hooks.h`). The
  generated chain returns to the caller adapter with `pc` still inside a
  callee fragment and the caller then runs the callee's tail *inline*, so the
  callee's `rts` is consumed by the wrong frame. With the flag set,
  `vf3_matrix_family` keeps dispatching until `pc == pr_at_entry`, but only for
  real call targets (`vf3_family_call_entry`; the harness uses the set of
  entries the oracle saw a call land on), because a fragment seed sees a stale
  `pr`.
* **Store queues.** `pref @Rn` with `Rn` in `0xE0000000..0xE3FFFFFF` bursts
  the 32-byte store queue to `(QACRn.AREA<<26)|(Rn&0x03FFFFE0)`. The generator
  used to drop every `pref`; it now emits `pref(ram,Rn)` for SQ addresses
  (`vf3_matrix_pref`, `matrix_family.c`), which accounts for ~30 KB of vertex
  output per tick (`0x0cc60550..0x0cc6c059`).

* **Delay-slot `pref`.** The generator inlines the delay slot of `bf/s`, `bt/s`,
  `bra`, `bsr`, `jsr`, `jmp`, `rts`. While `pref` was a no-op those slots were
  empty, so the 12 generated branch blocks whose slot is `pref @Rn` (e.g.
  `0x0c048854`: `bf/s ...; pref @r6`) never flushed the store queue even after
  the generator learned `pref`. `grep` for the `pref(ram,` line does not find
  this; the sites were patched into the generated files directly.
* **FPU quirks that only a whole tick exposes.**
  * With FPSCR.DN=1 the capture host (flycast built with mingw, `ldmxcsr`) sets
    **FTZ only, never DAZ**: denormal *inputs* are not flushed. Verified by tracing
    the live fr registers in flycast (`rampc` at `0x8c048d10..16`): `0x80000001 -
    0xbf7ef9db` under RZ gives `0x3f7ef9da`, and the fused-RZ `fmac` that follows
    gives `0xbe57ec4c`. The dream-recomp oracle instead flushes denormal inputs
    (it gives `0x3f7ef9db` / `0xbe57ec49`). An earlier DAZ experiment in
    `sh4_fpu.c` therefore chased the oracle's bug and broke the replay corpora;
    it is reverted. With plain FTZ the whole-tick vertex output is byte-identical
    to flycast's exit RAM.
  * `fmaf` under round-toward-zero is the correct FMAC model.
  * Where the oracle and flycast disagree (denormal inputs, denormal `fmac`
    addends: `0x0cc6b6b7`, `0x0cc6ba77` and a few siblings) flycast's exit RAM is
    the ground truth and the oracle is wrong; the audit counts those as expected
    oracle divergences.
* **Store-queue bursts in stubbed callees.** The oracle must log SQ bursts to RAM
  (`TICK_BURSTW=<addr>` prints them) or a stubbed callee's replay silently drops
  its vertex output.
* **The burst model is opt-in** (`vf3_sq_model`, `family_hooks.h`). The legacy
  per-function replay corpora (`extract/analysis/*_cases`, 1,678 bindings gated by
  `tools/portcheck.py`) predate it and their device tapes do not contain burst
  writes, so with the model on they fail at the first `pref`. Whole-tick runs set
  it (`tests/tick_mixed.c`); everything else sees the old behaviour.
* **Gap adapters.** 99.6% of the PCs a tick executes already have a generated
  adapter label; the remaining ~100 (the heads of 11 functions whose bodies are
  otherwise owned) made the native run fall back to oracle stubs for 44.6% of the
  steps. `tools/recomp/regen_tickgap.sh <TICK_PCS dumps...>` turns the oracle's
  executed-PC dump (`TICK_PCS=<file>`, also lists `jmp/braf` site->target pairs)
  into `src/fight/tickgap_adapters.c` through the normal generator. Re-run it with the
  dumps of every state you want covered.
* **Audit tolerance.** The recompiled oracle keeps return addresses in the `0x0C...`
  form, hardware (and the port) in `0x8C...`; the store audit treats
  `0x8Cxxxxxx == 0x0Cxxxxxx`.

## Result

Whole scheduler tick `0x8c09616a`, **100% native, zero oracle stubs**:

| state | oracle steps | recorded calls | calls audited | divergent | RAM native vs oracle |
|---|---|---|---|---|---|
| `vf3_7` pair 0 | 1,087,843 | 13,082 | 13,081 | 29 (oracle denormal handling, native agrees with flycast) | 8 bytes |
| `vf3_12` pair 0 | 997,832 | 12,615 | 12,614 | 32 (same) | 10 bytes |

* Final registers equal except `r0..r3` scratch (the rts path leaves them undefined
  in the capture) and the harness's `sr` bit.
* Native vs oracle now differs in 8 (`vf3_7`) / 10 (`vf3_12`) vertex bytes: all
  are the oracle's denormal handling (see FPU notes). `tools/recomp/ramdiff.py
  native.bin flycast_exit.bin oracle.bin` (`TICK_NATIVE_DUMP` / `TICK_EXITDUMP`)
  compares the port with captured hardware RAM: 447 bytes (`vf3_7`) / 476
  (`vf3_12`), **none in the vertex/output area** and all of them also differing
  in the oracle: timers, interrupt state and driver queue regions (`0c00e000`,
  `0c00fa30..`, `0c0ea2f8`, `0c16cc90..`, `0c19e998..`, `0c1a5a80..`, `0c31f6xx`)
  that lie outside the model.
* Only one pair per state could be captured (`--pairs` yields one complete tick
  per 300 frames); states 22 and 29 produced no tick.

## Readable tier (`src/fight/readable.c`)

Generated adapters are a faithful but unreadable tier; hand-written ports replace
them one entry at a time. `vf3_readable_table` maps an entry address to a C function
and to its **output-register contract** (bitmask over `s->v[]`: r0..r15 = 0..15,
PR=16, SR=17, FPSCR=18, MACL=19, MACH=20, FR0..FR15 = 21..36, XF0..XF15 = 37..52,
FPUL=53). A readable port is swapped in at the dispatcher, so the rest of the tick
keeps running generated code around it.

| entry | name | file | notes |
|---|---|---|---|
| `0x8c09616a` | task_sched | `task_sched.c` | scheduler loop, r12..r15 + pr |
| `0x8c068f92` | tri_winding | `geom_readable.c` | sign of 2D triangle area -> r0 = 2 / 1 / 4 |
| `0x8c068fe4` | quad_node | `geom_readable.c` | point in quad, five winding calls |
| `0x8c042c20` | div_s32 | `math_readable.c` | signed 32-bit divide r1/r0 (SH-4 div0s/div1 idiom, simulated step by step incl. SR Q/M/T); /0 stores 0x44E at 0x0C1A5A60 |
| `0x8c042cd4` | div_u32 | `math_readable.c` | unsigned 32-bit divide r1/r0, same idiom |
| `0x8c056b20` | push_offset | `geom_readable.c` | pushes FR12-15/r6 and a scaled int16 offset pair onto a descending record (r12 += 0x20) |
| `0x8c03a140` | cos_u16 | `geom_readable.c` | cos of a 16-bit angle: folds to the first half turn, tail-calls sin_u16(0x4000-a) |
| `0x8c03a6e0` | sin_u16 | `geom_readable.c` | 16-bit-angle sine (tan continued fraction) |
| `0x8c048b00` | vertex_light | `vertex_light.c` | ftrv + N.L / N.H, specular v^k table |
| `0x8c048be0` | vertex_emit_sq | `vertex_emit.c` | pack a lit vertex into the store queue (strip control word) |
| `0x8c048c20` | vertex_emit_ring | `vertex_emit.c` | same slot into the 4-slot clip ring at `0x0C1A5960` |
| `0x8c048c80` | clip_emit_slot | `vertex_clip.c` | ring slot -> store queue, y'/z' scaled by 1/x' |
| `0x8c048cc0` | clip_edge | `vertex_clip.c` | near-plane crossing: t = (plane-w0)/(w1-w0), lerp of every field |
| `0x8c0487a0` | strip_light | `strip_light.c` | strip transformer: light + emit each vertex, chained strips via the trailer |
| `0x8c048600` | quad_strip | `quad_strip.c` | groups of 4 vertices; only vertex 0 is lit (colour rides in the SQ buffer), quad or triangle by screen-space facing |
| `0x8c03b620` | matrix_store | `matrix_lib.c` | save XMTRX to the matrix slot (r4 = 0: the current-matrix cell) |
| `0x8c03c0e0` | matrix_concat | `matrix_lib.c` | XMTRX = XMTRX * M(r4) |
| `0x8c03c1c0` | matrix_premul | `matrix_lib.c` | XMTRX = M(r4) * XMTRX |
| `0x8c03c140` | matrix_concat_save | `matrix_lib.c` | XMTRX = XMTRX * M(r4), FR12-15 saved/restored on the stack (entered via c200) |
| `0x8c03c200` | matrix_concat_parent | `matrix_lib.c` | XMTRX = XMTRX * (matrix just below the stack top) |
| `0x8c03c4a0` | matrix_pop | `matrix_lib.c` | drop r4 (>=1) matrices from the matrix stack and load the new top into XMTRX |
| `0x8c03d260` | matrix_frame_a | `matrix_lib.c` | push(*(0x0C19D308+8)); concat with parent; store to 0x0C19D4D8; pop(1) |
| `0x8c03d280` | matrix_frame_b | `matrix_lib.c` | as frame_a, plus a concat with *(0x0C19D2FC+8) before the parent concat |
| `0x8c03d2b0` | matrix_frame_c | `matrix_lib.c` | push(*(0x0C19D2FC+8)); concat with parent; store to 0x0C19D498; pop(1) |
| `0x8c03fb10` | corner_fan | `geom_readable.c` | four-corner offset fan: out arrays from obj+4/+8 and (u,v) table 0x0C0EA670 with fmac terms skipped at zero |
| `0x8c03fb80` | color_pack | `geom_readable.c` | four 0..1 floats -> clamped ARGB byte word (ftrc with 2^32 wrap bias) |
| `0x8c03f830` | sprite_quad | `sprite_readable.c` | billboard quad: corner fan + header patch + store-queue submit (header + 4 vertices) |
| `0x8c0568a0` | tri_strip | `tri_strip.c` | screen-space triangle strips: z-range outcodes, winding/area cull, clipper hand-off (0x8c051f50), vertex writers via the table at 0x0c056a78, end-of-strip words |
| `0x8c048260` | display_list | `display_list.c` | model display-list walker: sphere cull (depth limit + 4 side planes), light block setup, per-strip TA header slots, dispatch to the strip transformers; sprite-only emit for culled nodes |
| `0x8c03cc90` | vec3_load | `chain_readable.c` | load a 3-vector into FR4..FR6, tail-jump to 0x8c03cc60 (writes XD12/XD14 through SZ=1 fmov) |
| `0x8c03c4f0` | matrix_push | `matrix_lib.c` | push XMTRX on the matrix stack (ctl 0x0C19D2E4), optionally XMTRX = M(r4) |
| `0x8c056aa0` | vertex_writer0 | `vertex_writers.c` | first strip vertex TA slot |
| `0x8c056ae0` | vertex_writer1 | `vertex_writers.c` | second strip vertex TA slot, flushes previous |
| `0x8c03bd80` | matrix_load | `matrix_lib.c` | XMTRX from r4 (or stack top) |
| `0x8c03ccb0` | matrix_identity | `matrix_lib.c` | XMTRX = identity |
| `0x8c03efb0` | matrix_load_wxyz | `matrix_lib.c` | XMTRX with columns rotated, negated w |
| `0x8c03b530` | matrix_copy | `matrix_lib.c` | 16-word copy or load/store dispatch |
| `0x8c095604` | mem_fill | `mem_fill.c` | word fill then tail bytes, count split by div_s32 |
| `0x8c07b4d4` | tex_cell_load | `sprite_uv.c` | texture cell record -> scratch block 0x0C1B9620 |
| `0x8c07b35c` | sprite_rect_a | `sprite_uv.c` | sprite vertex block position/UV extent |
| `0x8c07b398` | sprite_rect_b | `sprite_uv.c` | sprite far-corner UVs |
| `0x8c0c13c4` | glyph_quad | `glyph_quad.c` | one HUD font cell: cursor/size per font id, sprite rects, shade flags, sprite_quad |
| `0x8c07b2be` | pool_alloc | `glyph_cache.c` | next free 68-byte entry of the text layer's sprite pool |
| `0x8c0c1fba` | glyph_cache | `glyph_cache.c` | retire/allocate a text-layer glyph entry and build its sprite object |
| `0x8c058ea0` | project_verts | `project_verts.c` | XMTRX projection + light of a vertex run into 16-byte records (mode-bit-2 side-list variant unexercised) |
| `0x8c04af04` | format_int | `format_int.c` | printf integer conversion (d i u o x X): sign/prefix, digits via rem/quo helpers, pad fields in the spec |
| `0x8c03c880` | rotate_y | `leaf_math.c` | XMTRX rotation about Y from an fsca angle (r4) |
| `0x8c03c940` | rotate_z | `leaf_math.c` | XMTRX rotation about Z from an fsca angle (r4) |
| `0x8c03b450` | xform_point | `leaf_math.c` | (x,y,z,1) at r4 through XMTRX -> three floats at r5 |
| `0x8c043018` | mem_move | `leaf_math.c` | overlap-safe byte memmove (r4 dst, r5 src, r6 count) |
| `0x8c042e44` | mod_u32 | `math_readable.c` | unsigned remainder r1 % r0 (DIV1 chain, add-back fix) |
| `0x8c042d7c` | mod_s32 | `math_readable.c` | signed remainder r1 % r0 (sign-restoring correction step) |
| `0x8c03ee40` | axis_extract | `axis_extract.c` | axes from the 0x0C0EA624 table through XMTRX^T (row copy + normalised axis) into 0x0C1A58A0 |
| `0x8c09d4e6` | store_keep_translation | `leaf_math.c` | matrix_store into a transform object while preserving its translation floats (+48..+56) |
| `0x8c03cbd0` | matrix_set_translation | `leaf_math.c` | XMTRX elements 12..14 = three floats at r4 |
| `0x8c03cc60` | matrix_translate_by | `leaf_math.c` | XMTRX translation = XMTRX*(FR4,FR5,FR6,1) |
| `0x8c03c970` | matrix_rotate_sc | `leaf_math.c` | rotation about Z from ready sin/cos in FR4/FR5 |
| `0x8c03cb70` | matrix_scale | `leaf_math.c` | scale XMTRX axis columns by FR4..FR6 (through the stack) |
| `0x8c03c5b0` | matrix_invert_rigid | `leaf_math.c` | in-place inverse of a rigid XMTRX (R^T, -R^T t) |
| `0x8c03c6c0` | rotate_x | `leaf_math.c` | XMTRX rotation about X from an fsca angle (r4) |
| `0x8c09d52e` | xform_axis | `leaf_math.c` | transform (FR4,0,0) by XMTRX, store at r4 (calls xform_point) |
| `0x8c09d480` | rotate_euler | `leaf_math.c` | apply three s16 Euler angles at r4 (Z, Y, X) to XMTRX |
| `0x8c03b4b0` | xform_vector | `matrix_extra.c` | (x,y,z,0) at r4 through XMTRX, three floats to r5 |
| `0x8c03cc30` | matrix_transpose | `matrix_extra.c` | transpose XMTRX through FPUL |
| `0x8c03b5c0` | matrix_invert_scaled | `matrix_extra.c` | in-place inverse of a scaled rotation+translation XMTRX |
| `0x8c03e980` | world_reset | `matrix_extra.c` | transpose, transform two vectors, transpose back |
| `0x8c03e8c0` | bone_transforms | `matrix_extra.c` | push/invert matrix, transform vector+point of each in-use 0xB0 entry |
| `0x8c09d670` | anim_channels | `anim_channels.c` | sample the 63-channel animation record at a time (const/linear/Hermite keys) |
| `0x8c068d54` | terrain_wrap | `terrain_height.c` | stage-type coordinate scaling/folding of x,z |
| `0x8c068de4` | terrain_flat | `terrain_height.c` | flat-ground normal (0,1,0), -0.5 beyond +-6 |
| `0x8c068e0e` | terrain_height | `terrain_height.c` | ground height: clamp, 5 samples/unit bilinear blend over the 128-wide table |
| `0x8c04a6c8` | printf_core | `printf_core.c` | the engine's vfprintf: flags/width/precision/size parsing, d i u o x X c s p n %% and float conversions (only plain-int paths exercised) |
| `0x8c091438` | bone_pose | `bone_pose.c` | world matrices of a fighter's 23 bones (matrix push/pop around a per-bone concat chain, pose-record refresh/restore, ground-contact roll scale) |
| `0x8c070008` | capsule_chain | `capsule_chain.c` | chain of 24-byte nodes pushed out of a capsule (two end points, axis, radius) in two stage kinds, then clamped to link length from the previous node |
| `0x8c06f450` | body_capsule | `body_capsule.c` | fits the capsule record's end points / axes through two matrix blocks, builds the push-out vector, then per chain moves each node onto the capsule, transforms it back and runs capsule_chain; shared vec3 helpers in `vec3_inline.h` |
| `0x8c071694` | chain_frames | `chain_frames.c` | per-node side vector of a closed chain strip: edge vectors to the neighbours, two crosses normalised, summed and normalised into node+12, eight walk phases (calls nothing) |
| `0x8c073aac` | hitbox_overlap | `hitbox_overlap.c` | fighter-vs-fighter capsule overlap scan: optional radius-array rebuild, per-capsule-pair interval rejects + segment closest-approach, hit words / min distance / pair count into the result block (calls nothing) |
| `0x8c072b02` | negate_copy | `negate_copy.c` | copies pairs of vec3 lists, second vec3 negated (calls nothing) |

`python tools/recomp/readable_ledger.py` regenerates `docs/readable_status.csv`
(entry, file, contract, oracle census weight, verification status).
`0x8c048c40` (copies the shading pair into the two previous ring slots) never runs
in the captured ticks, so it is not ported rather than shipped unverified.

Floating-point goes through `readable_fp.h` (`vf3_f_add/sub/mul/div`, `VF3_FR`),
which uses the guest FPSCR, so rounding/flush behaviour is the same as the
generated tier.

### Register-contract checking (`tests/tick_mixed.c`)

A readable port is judged against the oracle records of every call it replaces
(inputs at entry, outputs at `rts`):

* **Outputs**: only the registers named in `out_regs` are compared. `pr` is compared
  modulo the `0x8C`/`0x0C` alias and `sr.T` is ignored (the oracle snapshots at `rts`,
  before the delay slot).
* **Clobber set**: `clobber_mask()` lists the registers whose in/out values differ in
  the oracle records of that entry. With fewer than 4 records it is "unknown" and
  defaults to r0-r7, macl/mach, fr0-fr15, fpul and the preservation check is skipped.
* **Scratch settling** (`TICK_SCRATCH`): registers the original clobbers but the port
  does not produce are refilled from the oracle record (`oracle`, default) or
  overwritten with `0xDEAD0000|i` (`poison`). `TICK_SCRATCH_ONLY=<entry>` and
  `TICK_SCRATCH_MASK=<hex>` restrict the poison to one entry / a register set.
* **Preservation**: a register outside `out_regs` and outside the clobber set must
  come back unchanged (`PRESERVE MISMATCH`).
* ABI "scratch" is **not** the clobber set: engine callers keep live values in
  r5-r7 and fr12-fr15 across calls, so only registers the original really writes are
  poisoned. `tools/recomp/scratch_deps.py <entry>` bisects per register and reports
  the ones whose poisoning changes the whole-tick RAM diff, i.e. undeclared outputs
  that the port still has to produce.

All ports pass in the four configurations (states 7/12 x `oracle`/`poison`):
0 output mismatches, 0 argument mismatches, 0 stubs, whole-tick RAM diff still 8/10
bytes. They account for 13.6% of the oracle's executed steps (state 7) plus the scheduler.

Stores are compared with the oracle's records. Where the oracle is the one that is wrong
(denormal handling, see above) pass the captured hardware RAM as
`TICK_HW_RAM=extract/analysis/flycast_exit_s7.bin`: a readable store that equals
hardware is accepted and counted as an "oracle-quirk store" (5 in state 7, 8 in state 12,
all lerp results of `clip_edge`).

### Next targets (oracle self steps, state 7)

`0c0487a0` 116k (strip transform, inlines the lighting), `0c06f450` 67k, `0c070008`
61k, `0c048600` 56k, `0c071694` 54k, `0c073aac` 46k, `0c048260` 41k (150 calls),
`0c0568a0` 36k, `0c03f830` 27k, the SQ vertex emitters `0c048be0/c20/c80/cc0`.
Stats: `extract/analysis/fxr_tick_s7_stats.csv`.
