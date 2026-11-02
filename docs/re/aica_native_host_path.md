# The host's own render path plays the reference audio (2026-11-02)

This note records the evidence that the *native SDL3 port's* audio render
function - `vf3_native_aica_mix()`, the exact function `src/host/sdl3_host.c`
(`audio_field()`) feeds to the SDL3 audio stream and to its `--wav-out`
tape - reproduces the game's reference audio byte for byte.

It is the "host loop correct" half of the audio proof.  The "mixer correct"
half was already carried by `tests/aica_mixer_replay.c` (the mixer tested on
its own); `tests/aica_native_replay.c` (new, target `vf3aicanative`) proves
the *host's* loop instead.

## How it is proved

The reference's own AICA state at the start of a window, the ARM7's writes
during it and the PCM the chip produced frame by frame live in one fixture,
`extract/analysis/aica_mixer_fixture.bin` (built by
`tools/aica_mixer_fixture.py` from the ARM observer's trace and the audio
capsule in `extract/analysis/audio_arm_observer_v3/`).

The native `vf3_native_aica_mix()` mixes by stepping the ARM7 interpreter
(`vf3_aica_arm_sample`).  For this proof the host's AICA state is seeded
from the fixture and a *replay* is armed, so each call applies the 
reference's own recorded ARM7 register/Sound-RAM writes at their tick and
samples the host's mixer - the same mixer object the SDL3 stream uses -
once per frame.  That way the exact production render function, not a copy,
is the code under test.

Mechanism added to `src/fight/native_tick.c` (+ header prototypes):

- `aica_replay_seed()` - loads the reference register file, Sound RAM and
  64 channel states into the host's `aica_model` / `aica_ram` / `aica_mixer`
  (the channel decode mirrors `tests/aica_mixer_replay.c`);
- `vf3_native_aica_replay_init()` - seeds and arms a recorded-write buffer.
  The buffer is `NULL` in a normal run, so `vf3_native_aica_mix`'s branch is
  one pointer check per frame; a replay is a diagnostic, not the default.

## Evidence

`tests/aica_native_replay.c` seeds the host from the fixture, calls
`vf3_native_aica_mix` for the fixture's 14,446 frames, compares every frame
to the reference PCM, and writes the host's own output to
`build/native_ref.wav` (channels swapped to the reference's right/left
order).  On the repo's current fixture:

```
aica_native_replay: 14446 frames match the reference's PCM sample for sample
aica_native_replay: wrote build/native_ref.wav (14446 frames)
```

and `build/native_ref.wav` is **byte-identical** to the ground-truth
`build/ref_audio.wav` (the PCM the reference savestate produced):

```
sha256 native_ref.wav : 24e4d78df219ae7ce8f4e0687f093b4b2a04076d45bfe8ff1c35e6d69c995f4c
sha256 ref_audio.wav  : 24e4d78df219ae7ce8f4e0687f093b4b2a04076d45bfe8ff1c35e6d69c995f4c
```

## The whole audio test suite

```
vf3aica        rc=0  aica_model_replay: the AICA's register file reads as the driver wrote it
vf3aicamixer   rc=0  aica_mixer_replay: 14446 frames match the reference's PCM sample for sample
vf3arm7        rc=0  arm7_replay: OK - the firmware runs to its INIT publication
vf3aicaarm     rc=0  aica_arm_replay: OK
vf3aicanative  rc=0  aica_native_replay: 14446 frames match the reference's PCM sample for sample
```

## What this does and does not cover

Covered: the port's audio renderer and its host render loop are correct -
given the AICA state the hardware reaches, the native port outputs exactly
the sound the reference makes.

Not covered (still open): the *fresh-boot runtime* path from an empty
machine.  A headless `vf3sdl --headless --wav-out ... --frames 1200` boot
was still silent ~200 fields in - no channel is keyed - because a fresh boot
has not loaded the low song region the reference starts from (the reference
PCM is a mid-fight savestate where that data is already resident).  That is
the "make the game itself reach a keyed channel on boot" gap, tracked
separately.
