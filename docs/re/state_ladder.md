# The fight-state ladder (SH-4 0x8C08B89C)

A readable port of the fight engine's state ladder, and the evidence for it.

## The function

`0x8C08B89C` is the second half of the counter updater: `0x8C08B7EE`
(`src/fight/cntup.c`, which calls it *callee-1*) sets up a frame, calls this
entry and then calls `0x8C08BB14` (*callee-2*).  The entry itself is
**call-free** - 275 instructions, no call, no indirect jump, no loop - and it is
**off-baseline**: the baseline inventory jumps from `f_8c08b836` to
`f_8c08bb26`, so the ladder is in the gap between them.

It is not a leaf nobody runs.  The oracle's own census of the state-7 fight
tick (`extract/analysis/fxr_tick_s7_stats.csv`) has

```
0x0c08b89c,2,378,66
```

two calls and 378 self-steps - the biggest single step count in the
`0x8C08B7xx`-`0x8C08B8xx` neighbourhood (`0x0c08b7ea` is 33, `0x0c08b832` is
41).  The ladder is one of the hottest pieces of the fight tick.

The caller hands it two things: `r4` is the **task struct** (the caller's own
`r14`), and `r5` is the **caller's frame**.  The frame points at two more
structures - the *state struct* at `[F+72]` and the *fighter struct* at
`[F+76]`.  The guest opens a 52-byte frame of its own below the four
registers it saves, fills it from the three structures, and then:

* **folds the fight's flag words into one word**, the frame's word at `F+0`.
  Six bits are decided there, each from a different pair of the caller's
  words:

  | bit | what sets it |
  |---|---|
  | 1 | the state struct's flags (`F+12`) carry any of the mask `0x0003d000`, or the fighter's flags (`F+20`) carry `0x00100000` |
  | 2 | cleared while the state struct's flags carry neither `0x00020000` nor `0x00008000` |
  | 4 | the ladder's own counter in the state struct (the halfword at the pool's offset `0x1bce`) reaches one, and the state struct's flags carry `0x80000000` |
  | 3 | the fighter struct's byte at `+0x3b` is 26 |
  | 4 | the fighter struct's word at the pool's offset `0x1b98` is zero |
  | 5 | the value the two counters below leave behind reaches a threshold the task's burst byte picks (35, or 96 when the burst byte is exactly three) |

* **steps the task's counters**: the per-call counter at `A+36`, the pair at
  `A+28` and `A+38`, the countdown at `A+22` (which reloads from the task's
  byte at `+46` when it runs out), the rolling counter at `A+34` (which ticks
  the burst byte at `A+0x85` and, through it, the byte at `A+0x86`), and the
  three saturating counters at `A+30`, `A+24` and `A+20`.

The frame the guest builds is worth spelling out, because the caller reads it
back.  Its offsets are **decimal**: `F+0` the flag word (from `A[16]`),
`F+4` `C[56]`, `F+8` the byte `C[0x61]`, `F+12` `C[0x48]`, `F+16` `B[0x48]`,
`F+20` `C[0x4c]`, `F+24` `B[0x4c]`, `F+28` `C[0x50]`, `F+32` `C[0]`, `F+36`
the float at `C[0x5c]` (the `fr3` spill), `F+44` `A[0x40] & 0xff` and `F+48`
the mask the guest shifts out of the pool's top bit.

The port: `src/fight/state_ladder.c`, registered in `src/fight/readable.c` as
`state_ladder`.

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine translation
of the ROM: one label per guest PC, one C statement per executed opcode, and
the original opcode word in a comment.  That makes them a faithful disassembly
of the function they implement, so a readable port can be written against them
without the ROM.

* `tools/adapter_owner.py 0x8c08b89c --all` - the body is served by
  `vf3_fifth_leaf_unowned_adapter` (`src/fight/vf3_fifth_leaf_unowned_adapter.c`).
* `tools/adapter_body.py 0x0c08b89c --span 700` - the translation, one line
  per guest PC.
* `build/listing.py 0x0c08b89c 0x0c08bb10 src/fight/vf3_fifth_leaf_unowned_adapter.c`
  - the guest's own instruction stream, decoded with `tools/sh4.py`.
* `tools/handwritten_entries.py 0x0c08b89c` - confirms that no hand-written
  module already serves this entry, so the port is not shadowed.
* `src/fight/cntup.c` - the caller models this entry as "callee-1" and
  documents what it saw of it; that model is the starting point for the
  semantics, and the port below is checked against the translation rather
  than against it.

The semantics come from the translator's emitted C, and the listing above is
what confirms the branch shapes (`bf` versus `bf/s`, the delay slots, the
`shld`).

## The evidence

`tests/state_ladder_replay.c` runs the readable port and the retained
generated translation of the same function over thirty-four scenarios and
compares **the whole register file (the FP registers and SR included), the
return PC, the failed PC, the out-of-window counter and every RAM byte**.
The port runs twice: once called directly and once through the readable
override, which is how the native tick reaches it.

```
state_ladder: 34 differential cases - PASS
```

The scenarios walk the tree: each of the six flag bits and the two masks that
gate it, the ladder's counter at one and above it, the fighter's stage byte,
the fighter's trigger word, the counter at `+32` ticking and not, the pair at
`+28`/`+38` in its three shapes, the countdown running down and reloading on
each of its two thresholds, the rolling counter rolling over, the long byte
ticking and not, the fighter being ready, the three saturating counters, and
the two shapes of the mask the guest shifts out of the task's byte at `+0x40`.
The last two scenarios put the value the level test sees exactly on the
threshold (35) and exactly one below the other threshold (96), because those
are the values a wrong threshold hides.

The test also checks the outcome **against the fixture itself**: the flag
word, the task's nine counters, the two bytes, the frame the guest builds, the
mask, the float, the saved registers, the stack pointer and the return
address all have to be what the scenario says.  The expected values come from
a second implementation of the ladder in the test, written from the listing
and not from the port.  A differential alone is not enough, because a fixture
that is not where the guest looks makes both sides read the same wrong bytes
and agree on them.

### The test has teeth, and the mutations were checked

The mutations are checked with `tools/mutate.py`, which applies one at a time
to the port's source, rebuilds and requires the test to fail.  The list lives
in `tests/state_ladder_mutations.json`, next to the test it guards.

<!--MUTATIONS-->

The list holds 46 mutations and **every one of them is caught**: the port's
source is broken one thing at a time, rebuilt, and the test has to fail.  A
few of them are worth naming, because they are the ones a reading of the
listing would get wrong: the `shld` zero case (the guest gives **zero** when
the count's low five bits are zero, not the value), the `A+32` gate (the
counter ticks when the fighter's word carries its bit **or** the state
struct's word carries the low bit - the other way round reads the same), the
rollover test (`(A+34 + 1) & 63`, and the stored value is *not* masked to
63), and the level threshold (35, or 96 when the burst byte is exactly
three - the `cmp/hi` on `A+0x85 - 3` wraps, so *any* burst byte but three
picks 35).

Three things about this function **cannot** be observed, and the port says so
rather than pretending otherwise:

* **the sign extension of the byte reads.**  The guest's `mov.b` sign extends,
  but every byte it reads is masked back to eight bits before it is used, so
  the `byte()` helper's sign extension never reaches a register the caller
  sees.  A mutation of that helper would change nothing, and it is not in the
  list.
* **the T bits that the guest overwrites before it returns.**  Only the last
  test's T bit - the level test at `0x8C08BABE` - reaches the caller.  The
  T bits of the ladder-counter test, the stage byte and the fighter's trigger
  are each overwritten by the next test, so they are dead inside the function.
  The mutation list therefore breaks the *branches* those tests feed, not the
  bits themselves.
* **the delay-slot spills that are overwritten.**  The guest's `/s` branches
  spill a value into the scratch word below its saved registers.  Only the
  last spill - the level block's, at `0x8C08BAB6` - and the one the long-byte
  block writes above it survive to the return; every other spill is
  overwritten by a later one.  The mutation list breaks the two that survive.

This is the pattern `tests/state_helpers_replay.c` established: the generated
translation stays in the tree as the reference, and the readable port is proved
against it.

### The oracle leg: closed through the caller

The ladder was never watched on its own, so it has no corpus.  It is,
however, reached from `0x8C08B7EE` - the counter updater that calls it as
*callee-1* - and **that** entry has a ten-window capture,
`extract/analysis/goldens_b7/f_0c08b7ee.nowin3.cases`, whose windows hold the
task struct (the window `0x0C1FE540..0x0C1FED64` covers the struct at
`0x0C1FE964`).  The corpus's own ROM window (`0x0C08B3C0..0x0C08BEBC`) even
carries the literal pool, so the port reads the *image's* constants and not
the test's.

`src/fight/cntup.c` used to model the ladder a second time, with a private
frame.  It now **calls the readable port** instead, with the private frame
handed over as one RAM window (the ladder's frame is at `F+4..F+52` and its
stack traffic at `[F-24, F)`, both inside the private frame's `[F-32, F+96)`).
So the replay of the caller is a replay of the readable ladder:

```
build/vf3cntup.exe extract/analysis/goldens_b7/f_0c08b7ee.nowin3.cases
cntup_replay: 8/8 cases match (56 skipped) - PASS
```

The corpus is a real witness, not a coincidence: with the ladder's per-call
counter deliberately broken, the same replay fails on every case -
`mem win1 @+0x448: got e1 want e2` - because `win1` is the task struct and
`A+36` is the word the ladder steps.  The corpus watches the countdown at
`A+22`, the per-call counter at `A+36`, the pair at `A+38` and the flag word
(the final store to `A+16`), so the oracle checks what the ladder writes.

Two things this leg does **not** cover, and they are stated rather than
hidden: the ladder's *frame* (the flag word it folds, the mask it shifts and
the float it spills) lives in the private frame and is in no checked window,
and the ladder's *register residue* is not the caller's to observe.  Those
are covered by the differential above instead.

The caller's own corpus (`goldens_b836*`, 64 strict cases) was tried as
well: with `VF3_READABLE=1` the readable ladder serves the call and the
corpus still passes 64/64 - but it also passes with the ladder deliberately
broken, so that corpus does not watch the ladder's outputs and proves
nothing about it.  The `goldens_b7` capture is the one that does.

The chain itself cannot serve `0x8C08B7EE` (it is a gap in the generated
chain, which is why the caller has a readable port of its own), so the
oracle leg had to be closed through `cntup.c` rather than by replaying the
chain from the caller.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* The **T bit** is the guest's branch condition, and a plain `bf` branches when
  it is *clear*.
* A **`/s` branch runs its delay slot on both paths**, so the scratch word
  below the saved registers is written whether the branch is taken or not.
* The **`shld`** at `0x8C08B8EE` shifts the pool's top bit *right* by the
  task's byte at `+0x40`, and a count whose low five bits are zero gives
  **zero**, not the value itself.
* The **counter decrements saturate**: a counter that is already zero stays
  zero (`A+30`) or is left alone (`A+24`, `A+20`).
* The **return** pops the four saved registers - `r14` in the delay slot of
  the `rts` - so the caller sees its own `r11`, `r12`, `r13` and `r14` back.
* The **float** at `C[0x5c]` is loaded into `fr3` and spilled into the frame
  at `F+36`; both are the guest's, and the port uses the same
  `vf3_matrix_load`/`vf3_matrix_store` helpers so the precision bit of the
  FPSCR decides the width on both sides.

## The unknown

What the six flag bits *mean* to the fight engine, what the task's counters
count and what the two structs hold is not recoverable offline: the code lives
in the game's own image, which is not in this checkout (see
[artifact_gap](artifact_gap.md)).  The port therefore reads the same addresses
the guest reads - the literal pool at run time, the two structs through the
caller's frame - and what the ladder *decides* stays open until the image is
back.
