# Fight dispatch chain (2026-09-19 — confirmed via trace_fight1.bin)

The M6 "fight dispatcher" question resolved by cross-correlating the 197M-record
branch-landing trace with the post-seeded function map. The switch-table
hypothesis was falsified (see dispatcher_falsify.md); the actual mechanism is a
scene-state predicate + frame pipeline.

## Chain structure (per frame)

```
FUN_8c0b24fa   cand_scene0A_frame_walker   # iterates scene state
      | bsr 0x8c0b1ac0 (sub-entry)
      v
f_8c0b1aa8     cand_is_scene0A             # tests byte [*(r13+8)+3] == 0x0A
      | (r0=1 if fight scene)
      v  fight pipeline, first-seen order in trace:
fight_pipeline_head_8c058e92  (trace#2)    # frame alloc / tick head
fight_f_8c091c42              (trace#9)
fight_frame_alloc_8c03effc    (trace#17)   # per-frame struct alloc
fight_f_8c091cf2              (trace#30)
fight_f_8c091d80              (trace#50)
```

## Evidence

1. First-seen list (`trace_fn_first_seen.csv`): record 0 already inside
   f_8c0b1aa8-class code; trace#2 = first fight fn. The first ~50 records
   enumerate the per-frame pipeline entry sequence.
2. f_8c0b1aa8 body: `mov.l @(0x8,r13),r4; mov.b @(3,r4)...; cmp/eq #0xA`;
   sub-entry at +0x18 (0x8c0b1ac0) is `bsr`-called (single xref from
   0x8c0b25d2 inside FUN_8c0b24fa); returns r0∈{1,4}. Scene root r13 =
   0x8C1D2D34 (known); scene-id field = *(r13+8)+3; **fight scene id = 0x0A**.
3. FUN_8c0b24fa contains a bounds-checked dispatch loop (~234B) with jsr @r3
   sites and the scene-0A predicate call.
4. trace_gate ground truth intersects: scene_mgr_B (0x8C063F58, 43,802 hits)
   runs during fight; task_run_A/B idle (0 hits); task_run_C only 6
   activations (all from fight_f_8c079684) — the per-frame fight path is NOT
   the M6 task_run_C ring.
5. Tight inner cluster during fight: fight_f_8c073c2a ↔ 8c073f08 ↔ 8c073cc6 ↔
   8c073d56 ring (~340K activations, ~3/frame); fed from outside via
   fight_f_8c073d80 and fight_f_8c073952 (mova-dispatcher family).

## Register conventions (fight region)

- r13 = scene/fight root 0x8C1D2D34 (frame-stable)
- r14 = per-task/work struct, argument-forwarded (`mov r4,r14` at function
  entries — e.g. fight_f_8c0796f4, cand_sd_slot_lookup), never global-magic
- jsr @r14 = call out to a helper with (r4)=task handle; jsr @r2/@r3 =
  literal-pool API calls.

## Fallout / notes

- FUN_8c0971c8 and FUN_8c09723a are bogus seed-boundary micro-fns (2 and 4
  bytes); do not trust spawn attribution to them (they're mid-body artifacts).
- Doc source-of-truth ids: fight scene = 0x0A; scene id field *(*(r13+8)+3).
- Names applied to Ghidra project: cand_is_scene0A, cand_scene0A_frame_walker,
  fight_pipeline_head_8c058e92, fight_frame_alloc_8c03effc.

## Artifacts

- extract/analysis/fight_spawn_edges.csv — full block-run spawn matrix
  (spawner fn → spawned fight fn → count), basis of the chain above.
- extract/analysis/trace_fn_first_seen.csv — per-fn first trace index.
