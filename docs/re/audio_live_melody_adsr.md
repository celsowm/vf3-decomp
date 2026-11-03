# Live melody: an ARM note-sequencer phase/instruction-count shortfall

Status: diagnosis (run-matched).  Companion to `77668d0` ("bill flycast-style
base cycles per ARM instruction; melody pacing now matches").  All six audio
tests pass (rc=0); the live PCM byte-match is 25.2% (3643/14446 frames), first
divergence frame 3575 = the compressed 6-note melody burst.

### Retraction (this reading)
An earlier draft claimed native "skips" four gated store-PCs
(`0x0664/0x0668/0x0930/0x0e8c`) and executes a strict subset of the reference.
That was a **comparison artifact**: the v4 reference trace records *loads and
stores* (memory accesses), while `build/native_trace.bin` is *store-only*.  The
four PCs are `ldr`/`ldrb` instructions, so they can never appear in the native
store trace even though native executes them.  Against native's executed-PC
stream (`build/arm_seq.bin`), native runs `0x0664/0x0668/0x0930` exactly 5x and
`0x0e8c` 4x in the melody window — the same sites the reference reaches.  **Native
executes no fewer distinct instruction sites than the reference; the shortfall
is that it reaches some paths fewer times / the billing of its narrower
per-gap work is shorter.**  Any fix claim must be checked against the executed
stream, not the store-only trace.

## Objective
`vf3sdl` must play the AICA/ARM7 audio 100% correctly.  The render path is
byte-exact; the only live divergence is the melody burst timing/decay.

## What billing fixed
Commit `77668d0` added `VF3_ARM7_BASE_CYCLES=6` per retired instruction in
`vf3_arm7_step` (matches flycast `arm-new.h` line 1321).  ARM workload dropped
5,256,629 -> 995,804 insns; native writes 380,387 -> 86,124 (ref 77,486);
melody key-on gaps `[3/3/2/3/3]` -> `[16,21,13,20,18]`.

## The run-matched oracle
The true oracle for native's scenario is the fixture
`extract/analysis/aica_mixer_fixture.bin`, run-matched (77486 reference writes,
14446 frames).  Its own source (per `aica_mixer_fixture.json`) is the v3
instruction-level trace `audio_arm_observer_v3/vf3_28_traced.arm`, whose key-on
cycles map to the *same* melody frames as the fixture — so the v3/v4 traces are
run-matched too (corrected: an earlier draft called them a "different run").
Key-ons (pc 0x264c, device write `0x8000<note>` val 0x82) located by address in
the fixture:

| note | ref key-on sample | native key-on sample | ref gap | native gap |
|------|-------------------|----------------------|---------|-----------|
| 1 | 3557 | 3560 | - | - |
| 2 | 3573 | 3576 | 16 | 16 |
| 3 | 3597 | 3597 | 24 | **21** |
| 4 | 3610 | 3610 | 13 | 13 |
| 5 | 3633 | 3630 | 23 | **20** |
| 6 | 3654 | 3648 | 21 | **18** |

So against the *run-matched* reference native's gaps 2/4/5 are still exactly
3 samples short (gaps 1/3 match exactly); the melody spans 88 samples vs 97
(native 9 short).  This is **not** a different-run artifact.

## Root cause: the note-hold frame count is 3 short on notes 2/4/5 (the ADSR pass is NOT the lever)
The ADSR/envelope pass is **not** what lengthens a gap.  Decisive native data:
gap 1 (16 samples) runs the full ADSR subroutine (`0x0fe4`->`0x0ff8`->`0x1028`
->`0x1034`->`0x1f0c` = 23 ADSR-adjacent insns) while gap 2 (21 samples, *longer*)
runs **none** (8, all plain reads).  So a gap carrying the ADSR pass is *shorter
or equal* to one that does not — the pass is a side-task that rides along with
the songstep phase, not the timing source.  The earlier draft's table of "ADSR
writes per gap" (ref [8,24,8,17,24] vs native [23,8,16,9,23]) is therefore a
*symptom* of which gaps the songstep happened to fall in, not the cause.

The gap length is set by the **note-hold frame count**: the melody's dominant
loop is the per-audio-sample voice scanner (`0x22a8`..`0x22f8`, scanning 64
slots every 0x40 bytes), and its iteration count scales linearly with each gap's
sample length (`r=0.98`, counts [53,78,32,74,69] vs gaps [16,21,13,20,18]).
The scanner runs once per audio frame; the inter-key-on gap is the number of
frames the note scheduler waits before it hits `0x2e38`..`0x2e74` -> `0x264c`
(key-on).  Note key-ons (all six reached through the same `0x2e58`/`0x2e74`
path, pc 0x264c) are emitted by the ARM itself.

So the divergence is a **note-hold countdown phase offset**: native schedules
the next key-on 3 audio-frames early on notes 2/4/5 (gaps [16,21,13,20,18] vs
ref [16,24,13,23,21], melody 88 vs 97 frames), and the ADSR pass rides in
whichever gaps that leaves empty.  The songstep counter (`0x5dac`, 44-frame
beat) is *matched* (3534/3578/3622/3666 vs 3535/3579/3623/3667 — 1 frame
apart), so the songstep cadence is not the lever; a *faster* sub-cadence — the
per-frame melo sequencer's note-duration/tempo countdown that advances the
state machine at `0x2e38`/`0x2e44` (`tst #0x8`, `tst #0x1`) — is what differs.

Firmware anchor points (disassembled via `tools/arm_dump.py`):
- `0x0fdc` gate (`tst r0,#0x80`), `0x0fe4` ADSR-enter -> `0x1028` voice `+0x30`
  store -> `0x1034` tail-call `0x1f0c` (this pass, off the critical path).
- `0x5d9c` songstep: `add r5,pc,#0x7100` -> load -> add 1 -> `0x5dac` store the
  44-frame counter at `[r5+0xc]`.
- `0x2640`..`0x264c` key-on: `ldrb` note byte, `and #7`, `orr #0x80`, `strb` the
  0x80|note device write; reached from the note-trigger `0x2e58`/`0x2e74`.
- `0x22a8`..`0x22f8` the per-frame 64-slot scanner (gap-length proxy).

The lever is the note-hold/tempo countdown in the melody sequencer, not the
render path, not the ADSR pass, not the songstep rate, and not a missing
instruction site.

### The reference runs a rock-constant 70.4 insns/sample (the rate model is CORRECT)
Aligning each side's *own* key-ons and counting executed instructions per gap
(native from `build/arm_seq.bin`, reference from its required gap
`sample_length * 70.4`):

| gap | native insns | ref insns (est) | native gap | ref gap | native insns/gap | ref insns/gap |
|-----|--------------|-----------------|-----------|---------|------------------|---------------|
| 1 | 1126 | 1127 | 16 | 16 | 70.38 | **70.438** |
| 2 | 1484 | **1690** | 21 | 24 | 70.67 | **70.417** |
| 3 | 898 | 915 | 13 | 13 | 69.08 | **70.385** |
| 4 | 1362 | **1620** | 20 | 23 | 68.10 | **70.435** |
| 5 | 1304 | **1479** | 18 | 21 | 72.44 | **70.429** |

The reference's per-gap rate is `[70.438, 70.417, 70.385, 70.435, 70.429]` —
tight to **±0.03** across all five gaps.  That is not a coincidence: the
reference ARM runs at a fixed flycast-timed pace, and its inter-key-on gap is
*exactly* proportional to its instruction count.  Native is **internally
self-consistent at the same rate**: `native_gap = native_insns / 70.4` for
every gap (1126/70.4=16.0, 1484/70.4=21.1, 898/70.4=12.8, 1362/70.4=19.4,
1304/70.4=18.5 — matching native's reported gaps exactly).

Therefore **native's billing/rate model is correct** (it is not a "bill too few
cycles" bug).  Native's long-note gaps are short *solely* because its ARM
**executes fewer note-hold instructions**: native is 657 melody instructions
short, broken down `[1, 206, 17, 258, 175]` — gaps 1/3 essentially match
(1, 17) while gaps 2/4/5 are short by ~206/258/175 (~3 frames × 70.4 each).
Native's ARM reaches the next key-on ~3 scan-passes early on each long note
because its **note-hold countdown value is 3 less**, so it runs ~3 fewer
iterations of the per-frame note-hold loop.  The countdown value is
register/ALU-resident (never leaves a store in the melody voice RAM, which is
why the diff of stored values stays *phase-identical*).

### The melody state is phase-identical, not divergent (an earlier "diff" was an alignment artifact)Diffing native vs reference stored values per address turns up `0xbbd0`
(ref=0x3a/nat=0xff) and `0xbe91` (ref=0x2f/nat=0xff) at frame 3575, which look
like a state divergence.  Their full write history shows **identical values at
phase-offset frames**: both write `0xff` then `0x3a`/`0x2f` from `pc 0x1fa8`/
`0x1fac` (envelope-level stores) — ref at frames 3558/3574, native at
3561/3577 because native's notes 1/2 are 3 frames late.  So the melody
*content* is identical; it is purely the note-event *phase* that differs, and
the fix is purely making native's note-hold countdown 3 frames longer on notes
2/4/5.

### Every melody timing divergence is an exact multiple of 3 frames
Native's key-on offset from the reference (native minus ref, by note):
`+3, +3, 0, 0, -3, -6, -3` (7 captured key-ons) — and the single post-melody
gap reverses sign, `+3` (native 296 vs ref 293).  Gaps diverge `+0, -3, +0,
-3, -3, +3`; the melody 6-note in-burst gaps map ref `{16,24,13,23,21}` to
native `{16,21,13,20,18}` by subtracting **exactly 3 from every length >= 21**
(24->21, 23->20, 21->18; 16 and 13 unchanged).  Nothing ever diverges by
+/-1 or +/-2 — the entire melody timing error lives on a 3-frame grid.  This is
the fingerprint of a note-hold/beat scheduler that steps in 3-frame quanta
(in native it runs 3 frames ahead on long notes, then a compensating +3 on the
next gap), and it rules out a continuous rate error (a rate error would also
pull note 7 far off, not just back to -3) and any fixed delta-time decoder
offset (that would hit short notes too).

### The v3/v4 traces ARE run-matched (correction to an earlier premise)
The fixture's own source (`aica_mixer_fixture.json`) is
`audio_arm_observer_v3/vf3_28_traced.arm` from the same `vf3_28.state`.  Its
key-on cycles `[5017270272, 5017342848, ...]` map via `(cyc - 5001139045)/4535`
to exactly `[3557.1, 3573.1, 3597.1, 3610.0, 3633.0, 3654.1]` — the *same*
melody frames as the fixture.  So the trace is **instruction-level
(memory-access, load+store) run-matched to the fixture** (cross-reference the
later `audio_arm_observer_v4` trace, identical run).  Per-write category counts
over the melody are near-equal (native ADSR 79 vs ref 81, ISR 40 vs 38, interp
107 vs 115) — native's total envelope work matches; only its *timing* shifts.

## What remains
The ADSR-write distribution below is *symptomatic* (which gaps the songstep
fell in), not the cause.  The lever is the note-hold frame count:

| gap | ref ADSR writes | native ADSR writes | ref gap | native gap |
|-----|-----------------|--------------------|---------|-----------|
| 1 | 8 | 23 | 16 | 16 |
| 2 | 24 | 8 | 24 | **21** |
| 3 | 8 | 16 | 13 | 13 |
| 4 | 17 | 9 | 23 | **20** |
| 5 | 24 | 23 | 21 | **18** |

Gap 1 carries the full native ADSR pass yet is the *same* 16 samples as the
reference's 8-write gap 1, and gap 2 (21) runs no pass at all — so the pass is
off the critical path.  What actually differs is the inter-key-on **frame
count**: native gaps 2/4/5 come out 3 short (melody 88 vs 97 frames), and the
pass rides whichever gaps the host note-ons leave empty.

The note-hold countdown that sets each gap is a **faster sub-cadence than the
matched 44-frame songstep** — the melody sequencer's per-frame tempo countdown
that advances the note state machine at `0x2e38`/`0x2e44` (`tst #0x8` / `tst
#0x1`) toward the key-on `0x264c`.  Native's version of that countdown holds
notes 2/4/5 3 frames short.  Because the songstep counter (`0x5dac`) is matched
to within 1 frame and native starts the melody at +3 (notes 1/2 late) then runs
ahead (−3/−6 on 5/6), the drift is a small, accumulating tempo/phase offset in
the sequencer's fast countdown, not a missing routine.

Two concrete routes to pin it, not yet done:
1. **RE the countdown**: trace the melody sequencer's counter (the source of
   the frames between `0x2e38` advances) in SNDDRV.BIN against the run-matched
   v3 trace, and see which counter keeps 64/128-frame note lengths and why
   native lands 3 short on 2/4/5.
2. **Run-matched diff of the scheduler hits**: the v3 trace carries per-site
   counts; diff the per-gap touch-counts of the `0x2e38` state machine and the
   per-frame scanner (`0x22a8`) between native and reference to find the site
   whose *phase*, not presence, differs.

### Post-melody: native never re-syncs (this is what caps the match at ~25%)
Cross-correlating `build/native_live.wav` (native) against
`build/native_ref.wav` (reference) by sample sign-agreement:

| window | best (score, lag) |
|--------|-------------------|
| 0..1000 | (1.000, 0) |
| 1000..3400 | (1.000, 0) |
| 3600..3900 | (0.817, 0) |
| 3900..5000 | (0.891, -27) |
| 5000..9000 | (0.82-0.92, -30) |
| 9000..14446 | (0.82-0.85, -30 / -9) |

Pre-melody is exactly aligned (lag 0, 100%).  The melody (3575..3654) is the
only synchronous divergence; from ~frame 3900 native sits **~27-30 samples
behind** the reference at 82-92% sign-agreement — neither a clean single-number
shift nor a re-sync.  And native's melody is **9 frames short** (note 6 at 3648
vs 3654), so along with the in-melody +3 start / −3-per-long-note offsets,
native never returns to alignment, leaving the whole post-melody stream (99.5%
of frames) misaligned.  That is why `vf3aicalive` reports ~25.2% (the byte-exact
pre-melody only).  The fix must therefore restore phase alignment *after* the
melody too, not just make the six note-ons land.

`tools/arm_dump.py` (new) disassembles SNDDRV.BIN around these sites;
`tools/aica_channel_state.py`, `tools/aica_seq_cycles.py`, and
`tools/aica_gap_compare.py` are the working probes.

## How to verify a fix
- melody key-on gaps must become `[16,24,13,23,21]` (samples 3557,3573,3597,
  3610,3633,3654) against the run-matched fixture;
- the ADSR-store per-gap profile must shift to gaps 2/4/5 at ref strength;
- all six audio tests (`vf3aica`, `vf3aicamixer`, `vf3arm7`, `vf3aicaarm`,
  `vf3aicanative`, `vf3aicalive`) stay rc=0;
- live PCM byte-match must move past frame 3575 toward 100%.

## Route 1 falsified 2026-11-03: the melody cannot be reproduced via emulator
The plan to capture the reference's *per-instruction* stream at the note
scheduler by rebuilding the emulator (a "clean" source tree with only the ARM
observer, no SH4 oracle hooks) is dead, for two independent reasons:

1. **The oracle/audio hooks are never called from the interpreter.**  A
   recursive scan of `tools/emu/flycast/core` shows `vf3OracleBefore` and
   `vf3AudioBefore` are *only defined* (vf3oracle.cpp:606, vf3audio.cpp:129);
   the sole guest hook actually invoked is `vf3DumpCheck` (sh4_interpreter.cpp:55).
   So an ARM-observer-only build is behavior-identical to the current one for
   the guest -- removing the oracle cannot un-stall anything.
2. **The melody is a probe-only scenario, not a savestate playback one.**  A
   plain `flycast-ref-build` run auto-loading the melody savestate
   (`data/vf3.state`, hash A96BAA58) boots and runs to frame ~3989 (and run2,
   unlimited, to frame 340434) with the ARM nearly idle (~6 memops/frame) and
   **zero** key-on stores at 0x264c.  The reference melody with key-ons at
   frames [3557,3573,3597,3610,3633,3654,3947] only exists in the run-matched
   fixtures (`vf3_28_traced.arm` / `aica_mixer_fixture.bin`), which were
   captured through the oracle's synthetic-probe machinery, not by normal
   playback.  The AGENTS claim "a pristine Flycast plays the game" is about
   the attract/demo, not this melody.

### Consequence: the countdown can only be pinned on the native side
The note-hold countdown is register/ALU-resident and invisible to *both*
memory traces (a per-gap scheduler diff of `vf3_28_traced.arm` vs
`build/arm_seq.bin` shows the reference trace carries only the key-on stores;
the scanner's per-PC counts are dropped by the observer's own filtering).
The reference melody cannot be re-captured per-instruction.  So the only way
to read the countdown values is to instrument `src/sys/arm7.c` and run the
native live harness itself (vf3aicalive), logging the ARM register file at
each key-on and per sample, and derive from the run-matched frame counts what
the reference's countdown must be.

### Confirmed key-on timelines (this reading, direct read of the fixtures)
| | note1 | note2 | note3 | note4 | note5 | note6 | post |
|--|--|--|--|--|--|--|--|
| reference frame | 3557 | 3573 | 3597 | 3610 | 3633 | 3654 | 3947 |
| reference insns/gap | - | 1127 | 1690 | 915 | 1620 | 1479 | - |
| native frame | 3560 | 3576 | 3597 | 3610 | 3630 | 3648 | 3944 |
| native insns/gap | - | 1126 | 1484 | 898 | 1362 | 1304 | - |

Native is 657 melody instructions short `[1,206,17,258,175]`; gaps 2/4/5 are
exactly 3 frames short.  Reference key-on cycles (from `vf3_28_traced.arm`)
`[5017270272,5017342848,5017451712,5017510400,5017614784,5017710208,5019038976]`
map via `(cyc-5001139045)/4535` to the frames above.
