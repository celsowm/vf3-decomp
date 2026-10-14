# Fight scheduler loop - recovered structure (2026-10-14)

Evidence: `tools/fight_reach.py` over `extract/analysis/trace_fight1.bin`
(197,487,160 records) + PC-predecessor walks + `tools/sh4dump.py` disasm.
The trace capsule itself starts mid-frame, mid-iteration of the scheduler
loop, which is why entry-PC hit screens report zero for these bodies while
the instruction-level scan sees them - the bodies are front-called once
per tick and the visible hits are their *continuation* sites.

## The loop

`0x8c096170` - task-dispatch loop (helper):

```
8c096170  mov.l r12,@-r15 ; r12 = &0x0c29bb84  (remaining-count cell)
8c096174  sts.l pr,@-r15  ; r13 = 0x0c1fe864   (task-record table base)
loop:                     ; 0x8c09617a
   r14 = r13
   r0  = *r14
   if (r0 & 1) { r3 = *(r14+12); jsr @r3 (r4 = r14); }
   r3 = *r12;  r2 = *(r14+8); r3--; r13 += r2; *r12 = r3
   if (r3 > 0) goto loop   ; 0x8c096198 bt 0x8c09617a
   pop pr,r12,r13; rts
```

So a tick = walk a table of task records at `0x0c1fe864` (stride from
record+8, enable bit = record+0 bit0, entry fn = record+12), calling each
enabled task's handler with r4 = record pointer. r14 = task record while
handlers run - the same r14 task-struct convention documented in
docs/re/task_vm.md.

## Where the fight-26 owners sit

- `0x8c09575c` (1,780 B): called-site `0x8c095cfc` is a **return address**
  into it - i.e. it `bsr/jsr`s the dispatch loop (or a task that does).
  It is a scheduler *client*, a big scene-side body hit 4,627x in-fight.
- `0x8c06d3xx` wrapper: reached from a task slot; id 13 - `0x8c0c7fb6`,
  else chain `0x8c06eaa4` -> `0x8c0c7104`; gate: `(byte)*0x0c29bcc0 & 0x80`
  selects the `0x8c08b5da` call (r4 = 7).
- `0x8c08b5da` lives immediately past fight-26 owner `0x8c08b586` - that
  owner is on the scheduler path.
- `0x8c08b476..c4`: the **bytecode interpreter**: `r14` walks the byte
  stream, `r11 = *(r12 + r14)` picks the handler slot, `jsr @r11`, advance
  `r13 += *(r14+20)`, next op = `mov.b @r14,r14` - classic threaded VM.
  This is the engine underneath the task records; per docs/re/task_vm.md
  the stream drives the 8-part per-frame work.
- `0x8c0786c4`+: bra-trampoline table (VM op thunks); `0x8c0782e4`/
  `0x8c07829a` push/pop frames for it.
- `0x8c0ab870`: vtable trampoline (`r6` object, index `@(4,r6)` through the
  image table `0x0c10f414` -> `0x8c0ab8a0/8ea/ad0/b24/b82/bfc/c98/cae/cdc`
  or default `0x8c0aa114`). Method dispatch for scene objects.
- `0x8c059aea` (494 B, 86,134,985 hits): the polling owner the trace hits
  more than everything else combined; per docs/re/bigscreen_r72.md it
  rejects natural case capture (24/24 interrupted) - interrupt-coupled
  wait loop on the scheduler tick.

## Consequence for capture plans

Fixture probes must drive the *scheduler*, not the owner: a synthesized
task table at `0x0c1fe864` format + cursor cell `0x0c29bb84` + the RAM
state handlers expect (`r14`-relative fields per the M19 map), invoked
through a front-door tick entry. The M19 "wf-ranging probe" note already
planned the savestate-first version of exactly this. Until the scheduler
model lands, the 26 fight-trace owners stay at evidence level; no
coverage credit is claimed.
