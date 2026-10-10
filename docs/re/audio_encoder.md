# Readable general A0 encoder

Callable `0x8c040b7c` starts with the r14 save; the frozen 226-byte owner
`0x8c040b7e` starts with the PR save. `src/fight/audio_encoder.c` supports both
entries. The fragment restores the r14 word already placed on the caller's
stack. Its earlier generated adapter was credited in the seventh campaign;
this replacement adds **zero coverage bytes**.

The ordinary command word is the unsigned 32-bit sum of
`(channel & 15) << 24`, the entire command argument, and any parameter field.
The channel argument is first stored and reloaded as a 16-bit stack word.
Commands `01a0`, `04a0`, `09a0`, `0aa0`, and `10a0` add
`(parameter & 127) << 16`. Commands `05a0`, `06a0`, `07a0`, and `11a0` add
`((parameter + 64) & 127) << 16`. These comparisons test the complete command
argument: `123401a0` does not receive the `01a0` parameter treatment. Other
commands preserve their existing bits. Addition, rather than bitwise OR,
preserves the original overflow behavior.

Command `001f00a0` instead visits channels 1 through 7. A signed `-1` at
`0x0c19e310 + channel * 12` suppresses that channel. Every other table value
posts `(channel << 24) + 001100a0`, followed by `(channel << 24) + 04a0`, through
the real queue helper. Queue failure does not terminate the loop. When all
channels are suppressed, the final result register retains `ffffffff` from
the last table read. These observations do not establish voice/reset meaning.

The original-only pilot uses 64 controlled cases in each of saved states 26
and 28: nine parameter classes, unmatched full command values, parameter
wrapping, invalid command words, busy queues, and four channel-enable patterns.
The 128 complete captures yield 126 distinct native cases, all matching
readable C with zero skips. The two all-disabled busy/non-busy pairs have
identical observed inputs because no queue access occurs. All source captures
remain in the manifest. The native
runner compares all captured registers, stack/touched RAM, return PC, banked
and floating-point state, and the ordered device-access tape. All 226 frozen
body bytes execute across the pilot. Eight historical fragment cases also
match the same frozen native executable.

This initial pilot is **native differential evidence**, with observed device reads supplied
by the replay harness. It is not a live C/device comparison. The separate actor
cleanup path retains its previously accepted clocked startup specialization.
At that milestone the general encoder had not replaced that specialization or entered the live
audio bridge. Callable caller attribution, independently held-out inputs, and
live scheduling remain necessary for that next gate.

`tools/oracle/audio_encoder_pilot_v1_manifest.json` seals the pilot, immutable
native executable, archived sources and capture inputs. The accepted
1,363-binding baseline is reused; the changed fragment is verified separately.
An additional broad regression was stopped and supplies no new acceptance.
The 39 freshly linked native suites and 86 tool checks pass. Readable coverage
remains **258,502 / 434,656 (59.47%)**. Standalone ARM/DSP playback and attributed
song/reset transitions remain open.

## Live acceptance (2026-10-09)

The general encoder now executes in the live bridge. Each original instruction
boundary advances the device scheduler; readable C supplies the register and
memory operations. The bridge does not execute original SH-4 opcodes to obtain
those operations. Cached and physical call aliases retain their original PCs.

Two separate 64-case campaigns pass **128/128 strict original/C comparisons**
and **128/128 native replays**, with zero skips. Development uses states 26/27;
acceptance uses states 28/29, a relocated stack, different parameters and channel
arguments, and negative non-sentinel channel table values. Each campaign covers
all 226 frozen body bytes. All 128 comparisons cross real AICA events and compare
the complete checkpoint state, including original ARM/DSP execution and PCM.
A nine-case live pilot also passes. Deliberately corrupting a real C queue word
produces the expected strict mismatch, demonstrating that the comparison detects
an incorrect command. Evidence and immutable build/source references are sealed
in `tools/oracle/audio_encoder_live_v1_manifest.json`.

The actor-cleanup startup path now reuses this encoder. The separate general
request wrapper and sound-selection input caller also use it; their evidence and
remaining promotion requirements are described in [audio_callers.md](audio_callers.md).
The earlier native-only gate is therefore superseded for live scheduling and
held-out encoder acceptance. Song/reset attribution and standalone ARM/DSP
playback remain open. Existing encoder credit remains unchanged.
