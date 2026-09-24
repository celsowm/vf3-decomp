# Scene walker f_8c0b1a54 (M29 recon slice, 2026-09-24)

True-image decode (`extract/analysis/scene_walker_true.txt`).

```
f_8c0b1a54:
    push pr, locals
    jsr lit(0x8C0B1AC0)(r4 = 0)          # step A (helper A)
    jsr lit(0x8C0B1AB0)(r4 = saved r7)   # step B
    r0 = *(locals + 24)                  # scene/state word
    switch (r0):
      1  -> r0 = 112
      5  -> r0 = mov.w @+24
      9  -> r0 = mov.w @+20
      14 -> r0 = mov.w @+16
      17 -> r0 = mov.w @+12
      default -> 0x8c0b1ac4 tail: r2 = *(r14+4); if (r2) jsr lit(r14, ...)
    jsr @r12 (r4 = *(r0 + r13))          # state-indexed per-scene vcall
    0x8C0B1AA2..: compact word table + bsr/bsrf dispatch chain (the old
    pre-M23 "6 jsr site" citations 0x8C0B1AA8/0x8C0B1AC0 are TABLE WORDS
    + dispatch legs in this block, not function entries)
```

Relation to fight dispatch (`docs/re/fight_dispatch_chain.md`): the
scene-0x0A predicate at the fight runner is a DIFFERENT id space (fight
== scene 0x0A at the task-VM level, while this walker's switch keys
{1,5,9,14,17} gate the per-scene handler at the object level).

## fight runner f_8c0796f4 re-verify (true image)
- Decodes coherently from byte-identical image (fmov.s prologue, branch
  diamond at 0x8C0796F8..).
- NOT in the baseline funcs CSV = entered dynamically (jsr @rN), below
  Vf3Prologue's static call-graph ceiling — consistent with the doc's
  "task runner" role sitting under the dispatcher's vtable call.

## Open thread (M30+)
- Full walker transliteration + its helper pair (lit@0x8C0B1AC0,
  lit@0x8C0B1AB0 targets) naming.
- mt loader mount-fixup (+0x27B0) located via `MTJACLAU.BIN` string xref
  (recipe in docs/re/task_spawn_m28.md).
