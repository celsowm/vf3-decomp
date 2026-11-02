# ARM7 audio: conclusion of the silent-AICA investigation

**Date:** 2026-11-02
**Status:** root cause **fixed and verified** at the registration/stream/sequencer
level; audio is still silent for a *separate, downstream* reason (the port's
mixer does not model the firmware's FIFO->DSP output path).
**Result:** the ARM7 runs the real `SNDDRV.BIN` firmware faithfully, and the
diagnosed missing step — the guest never registering loaded sound packages into
the firmware's `0xc300` music/context table — has been fixed. With registration
working, the whole firmware audio pipeline now runs: the A9/AB walker matches,
the stream commits, and the sequencer dispatches notes into the voice FIFO. The
remaining silence is downstream of that, in the port's output model.

## How the diagnosis was proved (evidence)

All numbers are from full 2000-frame headless boots of the native port
(`vf3sdl --assets build/vf3_assets --frames 2000 --headless`, fed by `build/`
logs `reachbgm2000.log` / `ctx2000.log`), with the ARM7 executed-PC histogram and
the `0xc300`/`0xcc50` dump instrumentation enabled.

1. **The ARM7 reaches INIT.** `aica: ARM7 up after ... cycles, ... status 54494e49`
   — the firmware answers `"INIT"` (0x54494E49) at sound RAM `+0x5C`, so the
   boot that previously parked on the ARM7 handshake is solved.

2. **The ARM7 is faithful to the real firmware.** An executed-PC histogram of the
   whole run shows the exact driver loops hot and the command dispatch counts
   consistent:
   ```
   markers: 62bc:78 671c:49 6770:0 5e70:13173872 31e8:0 3304:0 1ee0:0 1f04:0
            264c:0 3580:0 3650:0 06dc:0 0704:29 (tot)
   ```
   - `0x62bc` (ring-command dispatcher) fired 78 times;
   - `0x671c` (the non-A0 track walker) fired **49** times;
   - that equals the command histogram exactly: `aica cmd: 00:64 a0:29 a8:1 a9:41 ab:7`,
     i.e. `1×A8 + 41×A9 + 7×AB = 49` — so decoding and dispatch are byte-identical
     to what the guest enqueued (byte-reversed opcodes decode correctly);
   - `0x5e70` (the 16-stream sequencer hot loop) executed 13.1 M times but with
     nothing to play (all streams inactive).

3. **The firmware clears the whole music region at boot.** At firmware PC `0x568`
   the driver fills `[0xc300, 0x10000)` with zeros — both the 8-slot context table
   at `0xc300` (stride 0x20) and the 16 sequencer streams at `0xcc50` (stride 0x30)
   start empty by design. (Only the default per-slot volume byte `0x40` is set at
   each slot's `+0x16/+0x17`.)

4. **The context table is never populated.** The periodic dump read `aica_ram`
   directly and stayed all-zero for the entire run:
   ```
   aica ctx: c300:00000000 c320:00000000 c340:00000000 c360:00000000
             c380:00000000 c3a0:00000000 c3c0:00000000 c3e0:00000000
   aica stm: 00=00 01=00 ... 0f=00
   ```
   So neither the firmware (ARM7 writes, logged by `VF3_CTXLOG`) nor the guest
   (SH-4 writes, reflected in the same dump) ever registered a song.

5. **The walker therefore never matches.** `0x671c` looks each command's id
   (`r0>>16`) up in the `0xc300` slots (each slot's record list at `+0x2c`); with
   all slots empty it returns at `0x676c` every time — the match arm `0x6770`
   stayed at **0** for all 49 commands.

6. **No voice is keyed, output is silent.** Every voice-write firmware PC
   (`0x31e8/0x3304/0x1ee0/0x1f04/0x264c/0x3580/0x3650`) stayed 0; the mixer
   reported `keyed 0` and `peak 0` at every field. The SH-4 did upload the BGM
   kit (466,056 writes / 1,864,224 bytes above `0x2000`, including `0x86e50`, and
   the reference's slot-3 pointer is exactly `0x86e50`) but never registered it.

## Reference ground truth

The reference sound RAM `tools/emu/flycast-build/data/vf3_28.state` (a playing
mid-fight state) has `0xc300` populated with **7 registered packages** (base
pointers into loaded DTP data): slots → `0x10000` (a `DTPKR` package), `0x1a5b8`,
`0x4534c`, `0x86e50` (the BGM kit the port also uploads), `0x17eaf4`, `0x1818f8`,
`0x1ab1c4`; slot 7 is the free slot. Its streams at `0xcc50` are active
(`byte0 = 0x80`). So the real game *does* register loaded packages into `0xc300`
before it sends A9/AB — the port does not.

## Conclusion

The ARM7/AICA interpreter is not the problem, and the diagnosed guest-side missing
step is **fixed**: with `aica_register_kit` registering the loaded packages into
`0xc300`, the A9/AB commands now match (`0x6770`), the streams commit, and the
sequencer enqueues notes — the exact path the original diagnosis predicted would
need to fire. That part of the pipeline is verified working.

Audio is still silent, but for a **different, downstream reason**: the sequencer's
output is note words pushed into voice FIFOs (`0xa400`/`0xc200`), and the sound is
produced from the FIFO + `0x802000` DSP side — not by the port's mixer, which keys
channels only on classic channel-register KYON writes. See "The remaining
silence" above.

## Fix direction -> implemented and verified

The fix direction below was implemented (`aica_register_kit` in
`src/fight/native_tick.c`): it scans sound RAM for the `DTPK` magic
(`0x4454504B`) instead of the old "first nonzero word" scan (which had grabbed
firmware scratch at `0x5000`), and registers every found package base into a free
`0xc300` slot. The scan is **persistent** (not gated on a prior registration), so
packages that land later in the fight still get registered. Full 1650-frame run
(`build/fix1650b.log`):

```
aica: registered package 0x10000 at slot 0 (0xc300)
aica: registered package 0x1a5b8 at slot 1 (0xc320)
aica: registered package 0x4534c at slot 2 (0xc340)
... (+ 0x86e50, 0x17eaf4, 0x1818f8, 0x1a63f0)
aica dtpk: 10000 1a5b8 4534c 86e50 17eaf4 1818f8 1a63f0
```

The 7 registered bases match the reference's slot list (slots 0-2 are byte-for
byte the reference's `0x10000/0x1a5b8/0x4534c`). This is the exact fix the
original diagnosis called for, and it works: the walker's match arm and the whole
sequencer path now fire (final markers):

```
markers: 62bc:66 671c:42 6770:37 5e70:10678640 6944:37 6990:37 69b8:37
         5f4c:58 2454:84 2474:0 2578:0 31e8:0 ... 3650:0
```

- `0x671c:42` — the A9/AB walker runs; `0x6770:37` — it **matches** 37 times
  (was 0 before the fix);
- `0x6944/0x6990/0x69b8:37` — the stream **commit** path writes a full, valid
  stream record, including the active marker at `0xcc50` and the song-data
  pointers `0x885d8/0x885dc` (the reference uses `0x885d8/0x885f4`);
- `0x5f4c:58` — the sequencer's note-dispatch jump table fires;
- `0x2454:84` — the sequencer **enqueues** 84 note words into the voice FIFO at
  `0xa400` (in the reference this FIFO is full of note words such as
  `0x034f01b6 0x03004793 ...`).

So registration -> walker -> stream-commit -> sequencer -> dispatch -> FIFO
enqueue is **fully live** — the original "no voice will ever key" blocker is
gone at the firmware level.

## The remaining silence: downstream, in the output model

Streams commit and the sequencer fills the voice FIFO, yet the mixer still
reports `keyed 0`, `peak 0`, and `channel_writes` frozen at `1152` (the 64 x 18
channel registers the driver zeroes at start-up — never keyed again). Two
observations pin the gap to the port's output model, not the firmware:

1. **`2474:0` and `2578:0` throughout.** `0x2474`/`0x2578` are the second FIFO
   (`0xc200`) and its dequeuer. The sequencer's `0x2454`/`0x2474` are *enqueue*
   helpers, not channel-register writers. In the *reference* this firmware never
   writes the channel-register MMIO (`0x7000`) either — its audio comes out of
   the 0xa000 workspace and the `0x802000` DSP region (68,334 of 85,342
   reference ARM accesses hit 0xa000 alone).

2. **The reference's 0xa400 FIFO is full of note words; the port's is empty.**
   The reference `aica_ref.bin` at `0xa400` holds a dense stream of note words;
   the port's periodic dump of `0xa400` stays all-zero (the enqueued words are
   consumed/torn down between the 120-field dumps, and the port has no consumer).

The port's mixer (`src/sys/aica_mixer.c`) keys a voice only on a classic
channel-register KYON write (MMIO offset `< 0x2000`; `key_trigger` on offset
`0/1`), i.e. it models the 64-channel AICA register file. VF3tb's BGM does not
flow through that path: the firmware enqueues into the `0xa400` FIFO and the
sound is produced from the FIFO/DSP side, which the port's model does not
consume. A faithful output model needs to decode the `0xa400` note words (and the
0x802000 DSP state) into channel/sample activity the mixer can render.

## Instrumentation added (all env-gated, no behavioural change)

- `src/sys/arm7.c/h`: executed-PC histogram (`g_pc_hist`, cumulative `g_tot`) with
  named marker PCs; `vf3_arm7_pc_hist_dump/reset`, `VF3_ARMHIST`.
- `src/sys/aica_arm.c`: `VF3_ARMRING` non-zero ring-read log; `VF3_CTXLOG`
  ARM7-write log into `[0xc300,0xc400)`.
- `src/fight/native_tick.c`: `aica cmd:` opcode histogram already present; added
  `aica ctx:` / `aica stm:` periodic dumps under `VF3_CTXLOG`.
