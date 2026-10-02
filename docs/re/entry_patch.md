# Synthetic entry capture

`VF3_ENTRY_PATCH` extends the true image oracle for functions that no current
gameplay scenario reaches. The emulator still executes the original SH-4
instructions; the hook only redirects from a naturally executed trigger and
records the target invocation as a normal capsule.

Patch syntax:

```text
entry <trigger-pc> <target-pc>
seed <trigger-pc>                  # start the next seed variant for this trigger
reg <trigger-pc> r0|r1|...|r15|pr|gbr|fpul|fpscr|sr|pc <value>
ram <trigger-pc> <0x0cxxxxxx-address> <value>
```

The target must also appear as `pc <target-pc>` in `VF3_WATCH`. The target
capsule begins with the target instruction, carries the seeded register/RAM
state, and is rejected if it cannot return cleanly or touches invalid state.
`golden_batch.py --entry-patch` records the patch path and hash in its manifest.

## Seed variants (the lever that made this usable)

`seed` starts a new variant; the following `reg`/`ram` lines belong to it.
Variants are applied **round-robin across the trigger's firings**, so one hot
call site walks an entire input space instead of repeating a single input. For a
descriptor worker whose control flow is a function of two inputs (a flag word and
a few selector/payload words) this is a systematic branch sweep, not a guess.

`tools/oracle/seed_plan.py` generates the patch from a per-target recipe, and
`tools/oracle/gate_scan.py` extracts the gates and selector switches from a
disassembly so the recipe can pair every selector value with the guard bit that
opens its switch:

```text
python tools/oracle/gate_scan.py extract/analysis/tmp_8c05b20e.dis
python tools/oracle/seed_plan.py --target 0x8c05b20e --pr-offset 2 \
    --triggers 0x8c0aa446,0x8c04853a,... --out tools/oracle/phase3_packbits.patch
python tools/golden_batch.py --name phase3 --watch tools/watch/vf3_entry_patch_phase3_mt.txt \
    --out extract/analysis/phase3_cases --entry-patch tools/oracle/phase3_packbits.patch \
    --max-samples 400 --capsule --probe-debug --probe-offset 250 \
    --run dev:extract/analysis/vf3_fight_keep.state:extract/analysis/vf3_play_actions.txt:600
```

A 3258-variant plan covers only a slice per run, so campaigns step
`--probe-offset` across runs (`VF3_PROBE_CURSOR`) and merge the corpora.

## Trigger choice decides whether the run survives

**Substitution, not redirection.** The hook runs *before* `ExecuteOpcode`, so a
plain `ctx->pc = target` still lets the trigger instruction execute — and a
`jsr` then rewrites `pr` from the redirected PC, leaving the caller with a
broken return chain; an `rts` trigger simply never returns. `vf3OracleTakeSubstitute()`
fixes this at the fetch site in `ReadNexOp`: the target's first opcode *replaces*
the trigger's in the stream, so the trigger never runs at all. That single change
is what makes a probe invisible to the game:

- with substitution, a **prologue trigger** (`sts.l pr,@-r15`) becomes sound as
  well as a **JSR call site** — the target's own prologue push replaces the
  skipped one, so the frame stays balanced;
- before substitution, "hot" trigger addresses that produced 250+ probes per run
  were not hot at all: the broken return chain had put the game into a loop
  through the trigger region. Those corpora record real guest execution but a
  contaminated exit state, and they fail strict replay
  (`reg r8: got 0x65 want <seeded pr>`). Treat them as scenario evidence, not as
  promotion corpora.

The `pr` fixture follows from the trigger kind, and both values below are only
correct because substitution removes the trigger instruction from the stream:

- **JSR call site** — `pr = trigger+4`, skipping the call *and* its delay slot.
  A `jsr` pushes nothing, so the target returns straight into the caller's
  continuation. Use `--pr-offset 4`.
- **Function prologue** — `pr = trigger+2`, so the return lands on the
  instruction after the `sts.l pr,@-r15`. Sound only with substitution: the
  target's own prologue push takes the place of the skipped one, so the frame is
  balanced. Without substitution the push is skipped and the function pops a
  bogus return address. Use `--pr-offset 2`.

Two measurement traps that produced wrong trigger sets here:

- Hit surveys must not be read past their sample cap. A survey with
  `--max-samples 60` reported "60 hits" for nine call sites that in fact fire
  **once per run**; the real probe rate was 3 per run, not 540.
- The image stores each 16-bit word byte-swapped relative to `sh4dump.py`
  (`word = img[a-base] | img[a-base+1] << 8`), and `jsr @Rn` (`0x4n0b`) shares its
  low-nibble mask with `rts` (`0x000b`). Scanning with the wrong stride, byte
  order, or a mask that does not exclude `rts` silently yields "hot" addresses
  that are ordinary instructions.

## Rollback has to be exact

The probe restores the pre-trigger register file, call depth and every RAM page
it dirtied, and that is not enough on this fork:

- The emulated operand cache (`ocache`) is write-back. Dirty lines are written
  back and invalidated per restored page (`ocache.WriteBack(addr, true, true)`);
  without it the game keeps reading the probe's values out of cache and diverges
  within a few hundred frames.
- The SH-4 rounding mode also lives in the host FP environment, so the rollback
  re-applies `restoreHostRoundingMode()`.
- An aborted probe must resume at the *game's* continuation, not at `ctx->pc`
  (which is still inside the probe). The return address seeded into `pr` is
  stored as `gameResume` and used for fault/budget aborts.
- `vf3OracleTakeSkip()` tells the interpreter to discard the opcode it already
  fetched after such a rollback and re-fetch at the restored PC; otherwise a
  branch inside the aborted probe overwrites the resume point.

## Seeds that fault or spin

- A seed that steers the target into unmapped memory faults. `Do_Exception`
  asks `vf3OracleAbortProbe()`; the specimen is recorded with flag 1 (no credit),
  the game state is rolled back and the exception is dropped rather than
  dispatched — dispatching it makes the emulator treat the handler's own state
  as a nested fault and kill the run.
- A seed that never returns is retired at the next instruction boundary once it
  exceeds `VF3_PROBE_OPS` (default 20000 instructions), flagged 4.
- Both mechanisms are why a poison seed costs one case instead of the run.

## Probe accounting

`--probe-debug` writes `extract/analysis/probe_<batch>_<run>.json` with
`probes`, `probe_busy` (trigger hit while a probe was in flight),
`restores`, and `per_trigger`. It is the difference between "the seed plan is
bad" and "the trigger is never reached", which look identical from the corpus
alone.

## State of the 0x8C05B20E campaign

The first probe redirects trigger `0x8C0AA446` into `0x8C05B20E` and produces
complete capsules; that is evidence the mechanism works, not a promoted port.

The campaign that followed reached 98.3% body-byte coverage (1300/1322 B) over
5843 cases — and that number is void. It was captured with the broken fixture
above, and every one of those corpora **fails strict replay** with a contaminated
exit state. `extract/analysis/phase3_all_cases` is kept only as scenario evidence
and must be excluded from any promotion argument.

With substitution in place the same sweep is clean: 24 runs, 72 cases,
**594/1322 B (44.9%)**, and **24/24 corpora pass strict replay**. The generated
adapter (`extract/analysis/phase3_final_regenerated.c`, 704 guest statements, 0
unsupported instructions) replays every clean case, but 44.9% is below the
`body_cover.py --min-cover 100 --strict` promotion gate.

Nine of the eleven remaining bytes are not seed-reachable at all: they sit behind
`0x8C05B63C mov.l @(24,r4),r7`, a dereference of a live game object that must
compare equal to `0x28000000` at `0x8C05B66E`. No register or RAM seed fabricates
that — the probe has to be handed the object the game would really have passed,
which is dispatch-table reconstruction, a different lever. `0x8C05B20E` is
parked, not ported — see `docs/decomp_status.csv` and the Phase 3 section of
`advance_plan.md`.
