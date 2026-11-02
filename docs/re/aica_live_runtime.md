# The live runtime plays audio: the ARM7 interpreter, seeded, matches the reference for 80ms (2026-11-02)

The render path was already proven byte-exact (`docs/re/aica_native_host_path.md`,
commit `f624794`): `vf3_native_aica_mix()` with the reference's *recorded* ARM7
writes reproduces the reference PCM sample for sample, and the host's WAV is
byte-identical to `build/ref_audio.wav`.

What was missing was the **live** side - the `else` branch of the mix loop,
the one a normal runtime takes, which drives the ARM7 interpreter
(`vf3_aica_arm_sample`) instead of replaying recorded writes.  The fresh-boot
`vf3sdl --wav-out` run was silent (~300 fields, peak 0, no channel keyed)
because a fresh boot has not loaded the low song region the reference starts
from.  This note records the first *live, non-replay* audio from the native
port's own mix loop.

## How it is proved

The reference savestate `vf3_28.state` (a mid-fight state, equal to the mixer
fixture's start state) carries the ARM7 CPU.  `tools/aica_state.py`'s offsets
(`aica_if.cpp: serialize`) extract the flycast `arm_Reg[]` (49 u32, the
`Arm7Reg` enum order), the three timers' c_step/m_step and the four IRQ flags.
The blob is `extract/analysis/aica_arm_seed.bin` (236 bytes):

- PC `0x4dec`, CPSR `0x40000013` (SVC/ARM), SP `0xa0fc`, ARMRST released;
- all three timers c_step=m_step=1, CYCL_CNT `0xfffffffb` (the leftover count
  flycast keeps, not modelled natively);
- aica_reg_L=1, e68k_reg_L=1, aica_interr=0, e68k_out=0.

`vf3_native_aica_live_seed()` (src/fight/native_tick.c, header prototype in
native_tick.h) maps those into the native `vf3_arm7` (r[0..12], sp/lr/pc,
cpsr/spsr, the six banked r13/r14/spsr sets, the FIQ r8..r12 and the USR
r8..r12), the three timers and the IRQ/reg flags.

`tests/aica_live_replay.c` (target `vf3aicalive`) seeds the machine state from
the mixer fixture (register file + sound RAM + channels, **replay disarmed**)
and the ARM7 from the seed file, then calls the production
`vf3_native_aica_mix()` for the 14,446 frames and compares every frame to the
reference PCM.  It deliberately returns 0 and reports - this is the runtime
diagnostic, not a gate (the render path's exactness is the gate).

## Evidence

```
aica_live_replay: 14446 frames, 10894 differ from the reference,
                  28888 nonzero samples, peak 24387, keyed 9
```

- the live run **keys 9 channels** (the fresh boot keyed 0) - the game's audio
  state is genuinely reached and mixed, not silence;
- the first **3,552 frames (80 ms) match the reference byte for byte**, then
  drift into a plausible same-amplitude signal (peak 24387 vs reference peak
  22481).

Cross-correlation of the two left channels over the whole window peaks at
0.699 with no single strong lag, so after the 80 ms the content genuinely
diverges rather than shifting in time: this is a cadence/phase divergence in
the ARM7's real-time behaviour, not a render bug.

## Why it drifts (the open cadence gap)

`vf3_aica_arm_sample()` steps the ARM7 a fixed 512 cycles per sample, then
advances the timers and sets the SAMPLE interrupt.  Flycast schedules the
ARM7 against the cycle counter (`CYCL_CNT`, 0xfffffffb in this state) with
event-bucket timing, so an interrupt can land on a different cycle offset than
the fixed 512-cycle model.  The two executions agree for the first ~1.8M
cycles (3,552 samples x 512) and then the firmware's timing-sensitive loops
(sequencer tempo, timer B) slip out of phase; once the register writes
diverge, the (proven-correct) mixer mixes different data.

Closing that - making the live fun match the reference for the whole window -
needs cycle-accurate interrupt scheduling (modelling CYCL_CNT and the event
buckets), a separate, uncertain effort.  Its render half is already exact.

## Where this leaves the "audio 100% correctly plays" goal

- **Renderer:** 100% correct - bit-exact against the reference (`vf3aicanative`,
  `native_ref.wav` == `ref_audio.wav`).
- **Runtime:** now *plays* live audio (`vf3aicalive` - channels keyed, non-
  silent, first 80 ms bit-exact), where before the native runtime was silent.
- **Open:** full-window live byte-match (cadence) and the fresh-boot path that
  loads the song region itself.
