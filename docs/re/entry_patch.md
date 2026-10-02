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

A 974-variant plan covers only a slice per run, so campaigns step
`--probe-offset` across runs (`VF3_PROBE_CURSOR`) and merge the corpora.

## Trigger choice decides whether the run survives

Skipping the trigger instruction corrupts whatever depended on it:

- **JSR call site — safe.** A `jsr` pushes nothing; running the target in its
  place and returning to `trigger+4` is exactly what the game would have done.
  Use `--pr-offset 4`.
- **Function prologue — unsafe.** Probes at `sts.l pr,@-r15` skip the frame
  push, so the function later pops a bogus return address and the run dies
  within a few hundred frames.

Two measurement traps that produced wrong trigger sets here:

- Hit surveys run faster than capture runs unless the memory hooks are
  installed, and the game then lands in a different fight phase; survey
  reachability with `--capsule --ramn 0` when the answer must match a capture.
- The image stores each 16-bit word byte-swapped relative to `sh4dump.py`
  (`word = img[a-base] | img[a-base+1] << 8`). Scanning with the wrong stride or
  the wrong byte order silently yields "hot" addresses that are ordinary
  instructions, and probing one of those corrupts control flow.

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
The campaign that followed drove the body from 47.8% to **94.9%** body-byte
coverage (1254/1322 B, `tools/body_cover.py`) across 14 capture corpora, but
the generated adapter passes only 4/204 strict replay cases: the deep arms
dereference descriptor words as pointers, so the seeds that reach them also
chase memory outside the captured windows. `0x8C05B20E` is parked, not ported —
see `docs/decomp_status.csv` and the Phase 3 section of `advance_plan.md`.
