# The AICA audio model: what P5 needs, measured (2026-11-01)

This is the design note for the plan's P5 ("AICA PCM output -> SDL3 audio
stream").  It states where the port stands, what the hardware looks like
according to the reference emulator, and how large the job really is.  Every
number below is measured, not estimated: the register set comes from the
reference's own ARM trace (`extract/analysis/audio_arm_state28_v2.json`), the
memory map from the reference's source, and the firmware's identity from the
repo's earlier audio work (`docs/re/audio_execution.md`).

## 1. Where the port stands

The port has:

* the **sound RAM**: 2 MiB, the AICA's own memory (`src/fight/native_tick.c`,
  `aica_ram[]`);
* the **SH-4 side of the audio**: the channel allocation
  (`src/fight/audio_channels.c`), the encoder, the submission, the request
  wrapper, the actor cleanup - all ported and replayed against the reference;
* the **SH-4 -> ARM7 handoff**: `src/media/driver_queue.c` recovers the exact
  bytes the ARM7 would read (the 256-byte ring, the byte reversal, bit 6, the
  1,024-byte internal ring at `0xa400`);
* the **ARM7's handshake**: the port models the release (`ARMRST`), the "INIT"
  signature and the free-size field, because the guest waits for them.

The port does **not** have:

* the ARM7 running, so the firmware never reads the command queue and never
  programs the AICA's channels;
* the AICA's mixer, so even a programmed channel would make no sound;
* an SDL3 audio stream.

## 2. The hardware, as the reference maps it

The AICA is one chip with two CPUs' worth of memory space and one register
file.  The reference's map (`tools/emu/flycast/core/hw/holly/sb_mem.cpp`,
`core/hw/arm7/arm_mem.h`, `core/hw/aica/aica_mem.cpp`):

| window | who | what |
|---|---|---|
| `0x00700000..0x00707FFF` | SH-4 | the register file (32 KiB window over an 8 KiB file) |
| `0x00800000..0x017FFFFF` | SH-4 | the sound RAM (2 MiB, `ARAM_MASK` = `0x1FFFFF`) |
| `0xA0000000..` | SH-4 | the same sound RAM, masked (`0xA0800000` -> offset `0`) |
| `0x00000000..0x007FFFFF` | ARM7 | the sound RAM (the same array) |
| `0x00800000..` | ARM7 | the register file (offset & `0x7FFF`) |

So the SH-4 and the ARM7 share one 2 MiB of memory, and the ARM7 is the only
one that can write the register file.

### The register file

`aica_reg[0x8000]`:

| offset | what |
|---|---|
| `0x0000..0x1FFF` | the SGC's channel slots, `0x80` bytes each (64 slots) |
| `0x2000..0x27FF` | the DSP's output volume |
| `0x2800..0x2817` | the common (SGC) registers |
| `0x2818..0x2FFF` | the timers and the interrupt registers (`TIMER_A` = `0x2890`) |
| `0x3000..0x7FFF` | the DSP's program and data |

A channel slot (`0x80` bytes, the layout the reference reads in
`sgc_if.cpp`'s `ChannelCommonData`):

| offset | field |
|---|---|
| `+0x00` | `SA_hi:7`, `PCMS:2`, `LPCTL`, `SSCTL`, `KYONB`, `KYONEX` |
| `+0x04` | `SA_low:16` (the 22-bit sample address) |
| `+0x08` | `LSA:16` (the loop start) |
| `+0x0C` | `LEA:16` (the loop end) |
| `+0x10` | `AR:5`, `D1R:5`, `D2R:5` (the amplitude envelope) |
| `+0x14` | `RR:5`, `DL:5`, `KRS:4`, `LPSLNK` (the release and the key rate) |
| `+0x18` | `FNS:10`, `OCT:4` (the pitch) |
| `+0x1C` | the LFO registers (`ALFOS`, `ALFOWS`, `PLFOS`, `PLFOWS`, `LFOF`, `LFORE`) |
| `+0x20` | `ISEL:4`, `IMXL:4` (the input selector and the send level) |
| `+0x24` | `DIPAN:5`, `DISDL:4` (the digital pan and the direct send level) |
| `+0x28` | `Q:5`, `LPOFF`, `VOFF`, `TL:8` (the filter's Q and the total level) |
| `+0x2C..+0x3C` | `FLV0..FLV4` (the filter's cutoff levels) |
| `+0x40` | `FAR:5`, `FD1R:5` (the filter's envelope) |
| `+0x44` | `FD2R:5`, `FRR:5` |

### The sound RAM's layout

| offset | what |
|---|---|
| `0x00000..0x00050F` | the firmware's vector table |
| `0x00510..0x09FFF` | the firmware's code (`SNDDRV.BIN`, measured) |
| `0x0A0B4..0x0CF5D` | the ARM7's stack, the command queue and the work records |
| `0x0A400` | the firmware's internal 1,024-byte command ring |
| `0x086E50` | the `BGM_VAN` bank (1,014,948 bytes) |
| `+0x5C` / `+0x88` | the firmware's "INIT" signature and the free-size field |

The SH-4's channel descriptors (the 96-byte AICA records) are published by
`audio_channels.c` into the sound RAM's first bytes, and the ARM7 picks them
up from there.

## 3. The scope: what the game's driver actually touches

The reference's ARM observer recorded the ARM7's every memory access in the
fight states (`extract/analysis/audio_arm_state28_v2.json`).  From it:

* **277 writes to the register file**, in **18 channel slots**:
  `0, 6, 8, 11, 17, 18, 26, 28, 29, 39, 44, 45, 47, 56, 57, 58, 61, 63`;
* the registers written are `0x00, 0x01, 0x04, 0x08, 0x0C, 0x10, 0x14, 0x18,
  0x1C, 0x1D, 0x20, 0x24, 0x25, 0x28, 0x29, 0x40, 0x44` - that is, **every**
  register of the layout above except the five `FLV` levels (`0x2C..0x3C`);
* the ARM7 also *reads* the sound RAM: a status word at `0x438` (polled 2,400
  times in state 28) and the queue words at `0x668`, `0x674`, cleared at
  `0x688`.

Two things follow:

1. **the envelope is in scope** - the driver writes `AR`, `D1R`, `D2R`, `RR`
   and `DL`, so a mixer that ignores the envelope would not be the game's
   sound;
2. **the filter and the LFOs are programmed, but idle** - the driver writes
   `Q`, `LPOFF`, `FAR`, `FD1R`, `FD2R`, `FRR` and the whole `+0x1C` LFO word,
   so the mixer has to *read* them, but the values the driver writes turn
   both off (the measurement below says how).

The `FLV` levels are the exception: the driver never writes them, so they keep
their power-on value and the filter's cutoff is fixed.

### What the driver actually programs

`tools/aica_voice_regs.py` replays the trace's writes into the register file
and decodes the fields, the way the hardware does:

```
$ python tools/aica_voice_regs.py
277 register writes, 18 channel slots touched

slot  pcms    sa      lsa     lea     ar  d1r d2r  rr  dl   fns  oct  rate  hz     tl  dipan disdl
0       1   0x176660  0x4f64  0x8492   31    8   8   17  21   909   14   483  20801   20     0    10
6       1   0x176660  0x4f64  0x8492   31    8   8   17  21   266   15   645  27778   19     0    10
8       1   0x176660  0x4f64  0x8492   31    8   8   17  21    61   15   542  23342   19     0    10
11      1   0x0cead2  0x7df2  0xb216   31    5   6   18  29   801   14   456  19638   12    31    10
18      0   0x0ace34  0x0000  0xde7e   31    0   0   31   0    61    0  1085  46727   29    12    13
26      2   0x16d95e  0x23e4  0x35ce   31    0   0   31   0    92   14   279  12016   12     0    13
45      1   0x0cead2  0x7df2  0xb216   31    5   6   18  29   801   14   456  19638   12    15    10
57      1   0x090956  0x0000  0x31bf   31    0   0   31   0     0    0  1024  44100   12     0    13
63      1   0x176660  0x4f64  0x8492   31    8   8   17  21   698   14   430  18519   21     0    10
```

(the other nine slots are the ones the driver silences: the sample address 0
and the total level `0xFF`.)

That table is the mixer's specification:

* **three sample formats**: `PCMS` 1 (PCM8) for eight voices, 2 (ADPCM) for one
  and 0 (PCM16) for one.  The ADPCM decoder is already proven bit-exact in
  `src/media/aica_adpcm.c`;
* **the attack is always the fastest** (`AR` = 31), so the envelope reaches its
  level at once and only the decay and the release matter;
* **the filter is off**: the driver writes `LPOFF` = 1 in the level word, and
  the reference's `UpdateFEG` only runs the filter when `LPOFF` is 0.  The
  filter's own registers (`FAR`, `FD1R`, `FD2R`, `FRR`) are written only for
  the silenced channels, so the filter never touches the sound;
* **the volume is the total level** (`TL`): 0xFF is silence, the live voices
  sit between 12 and 29;
* **the pan is the digital pan** (`DIPAN`, 0 = left, 31 = right);
* **the LFOs are programmed but idle**: the driver writes the whole `+0x1C`
  word, but with `ALFOS` = `PLFOS` = 0 and both wave types sawtooth, which is
  the LFO's "off" setting;
* **the playback rate** is the reference's derivation: `1024 | FNS`, shifted by
  the octave (`oct & 8` divides).  The rates land between 12 and 23 kHz, which
  is what the samples in the bank were recorded for.

### The model in the port

`src/sys/aica_model.{c,h}` is that register file: the 8 KiB file, the 64
channel slots, the field decoding and the key-on trigger (the hardware clears
the trigger when it starts the channels).  `tests/aica_model_replay.c`
(`build/vf3aica`) replays the reference's own writes for four channels - a
PCM8, a PCM16, an ADPCM and a silenced one - and checks every field against
what the trace says:

```
$ build/vf3aica
aica_model_replay: the AICA's register file reads as the driver wrote it
```

The test earned its keep once: its first version expected the key word to keep
the trigger bit, and the hardware clears it (`0xC297` becomes `0x4297`).

The model is **not wired into the host yet**, and deliberately so: the ARM7 -
the only thing that writes the register file - does not run, so there would be
nothing to feed it.  It is the foundation the ARM7's output and the mixer
will sit on, and it is a standalone module so it can be proved against the
trace without the rest of the port.

## 4. The work, in three parts

### (a) The AICA's hardware model - our own C

`src/sys/aica_model.{c,h}`: the register file, the per-channel state machine
(`KEY_ON`/`KEY_OFF`, the envelope generator, the filter, the LFOs), the
sample fetch (PCM16, PCM8 and the 4-bit ADPCM - the ADPCM decoder is already
proven bit-exact in `src/media/aica_adpcm.c`), the volume and the pan, and the
mixer that produces the stereo stream at 44,100 Hz.

This is the part that is *hardware*, so it belongs in the port the way the PVR2
model does: our own implementation, checked against the reference.

### (b) The ARM7 - the wall

Without the ARM7 the register file is never written, so (a) would mix silence.
The ARM7 is the sound CPU, and the firmware that runs on it is the game's own
(`SNDDRV.BIN`, 53,120 bytes, uploaded by the SH-4 into the sound RAM).  Two
ways to get there:

1. **an ARM7TD4 interpreter** (our own, a machine model like the PVR2's): the
   firmware runs as it does on the hardware.  Roughly 1,200 lines of C for the
   instruction set, plus the exception model.  Its oracle is the reference's
   ARM trace - the same PCs, the same accesses, the same values.
2. **a C port of the firmware's command handling**: the repo's own method for
   the game's code (the SH-4's side is already ported this way).  It needs the
   ARM disassembly - `extract/analysis/snddrv_dispatch_arm.txt` is the
   dispatch area - and it carries the risk of a silent misreading.

The two are not exclusive: the interpreter is the smaller risk for the
*behaviour*, the C port is the better fit for the repo's "readable C mirror"
goal.  The trace gives the interpreter a precise acceptance test, which is
what makes it the safer first step.

### (c) The SDL3 stream

`SDL_OpenAudioDevice` with a callback that pulls from a ring the mixer fills.
Small, and independent of (a) and (b).

## 5. The verification

The reference is the oracle, and it is still here:

* `tools/emu/flycast-build/flycast_v3.exe` carries the observers
  (`VF3_ARM_TRACE`, the audio capsule writer), so the ARM trace and the PCM
  export can be regenerated;
* the manifests of the earlier campaigns survive
  (`tools/oracle/audio_arm_observer_v2_manifest.json`,
  `tools/oracle/audio_pcm_v1_manifest.json`), so the *expected* hashes are
  known even where the WAVs are gone;
* the PCM comparison tool is `tools/oracle/audio_pcm.py` (44,100 Hz, the
  recorder's right/left pairs, exact reconstruction checks).

The acceptance chain is therefore:

1. the ARM7 model reproduces the reference's ARM trace (the PC histogram and
   the ordered accesses) on the same scenario;
2. the AICA model reproduces the reference's PCM from the register state the
   trace ends in;
3. the SDL3 stream carries exactly that PCM to the speakers.

Steps 1 and 2 are the two that have to be proved; step 3 is plumbing.

### What is in the workspace to do it

| ingredient | where |
|---|---|
| the reference's states | `tools/emu/flycast-build/data/vf3_26.state`, `vf3_28.state`, `vf3_29.state` |
| the AICA RAM out of a state | `vf3_26.state.aica.bin` (and `tools/aica_state.py`) |
| the observers | `tools/oracle/vf3armtrace.cpp` (the ARM's accesses), `tools/oracle/vf3audio.cpp` (the PCM) |
| the installer | `tools/oracle/install_arm_trace.py` |
| the exporters | `tools/oracle/audio_pcm.py` (the PCM -> WAV), `tools/oracle/arm_trace.py` (the ARM's accesses) |
| the built emulator | `tools/emu/flycast-build/flycast_v3.exe` (it carries the observers; the strings `VF3_ARM_TRACE` and the audio capsule's are in the binary) |

What is **not** in the workspace: the campaigns' own outputs (the `.arm`
traces, the `.audio.gz` capsules and the WAVs) and the manifests' command
lines.  The manifests keep the *hashes* of the results, so the campaigns can
be re-run and checked - but the command lines have to be reconstructed from
the installers, and the port has to be able to run the same state (it reads
its own state format today; the reference's savestate is the P1 option 2 the
plan mentions).

## 6. What is *not* in scope

* the **DSP** (the CD-ROM audio path): the game's driver never writes the DSP
  registers in the observed states, so the model's DSP can stay a stub;
* the **CDDA**: the same;
* the **SSG** channels: the driver writes slot registers only, so the SSG's
  own registers stay at their power-on values;
* the **MIDI** port.

## 7. The open questions

These are the things the reference's evidence does not answer yet, and they are
the first things to measure when the work starts:

* **what drives the ARM7's tick.**  In the observed states the ARM7 polls the
  sound RAM's status word (`0x438`) 2,400 times and writes no timer register,
  so the tick comes from outside the ARM7: either the AICA's timer A (which
  then has to be programmed by the SH-4, through the SH-4's register window at
  `0x00700000`) or the reference's scheduler slice.  The port has no write to
  `0x00700000..` in its ported modules, so either the write is in a body that
  is not ported yet, or the ARM7 runs free.
* **the common and timer registers** (`0x2800..`) are never written in the
  observed states - they keep their power-on values, so the model's mixer does
  not have to reproduce a DAC level the driver never sets.
* **the SSG**: the slot registers (`+0x00..+0x44`) are written for 18 slots,
  but the SSG's own registers live in the common area, which is never written.
  The 18 slots are therefore PCM voices, not SSG voices.
