# P2: the frame loop (2026-10-26)

Phase P2 of `docs/re/plan_sdl3_port.md`: the port runs a *whole frame* of the
game, with the clock and the events a frame needs, and the display commands
reach the PVR2 model.

## What the frame loop is

The game's per-frame code is the block at `0x8C059B48`, inside a function whose
prologue is further up (the reference hits it once per frame: 122,880 hits in
123,440 video frames of the reference run).  Its shape:

```
0x8C059B40  r5 = [0x8C059C24]      ; the TCNT0 pointer
0x8C059B42  r0 = [0x8C059C28]      ; 0xFFD8000C
0x8C059B44  r2 = [0x8C059C2C]
0x8C059B46  r3 = [r0]              ; the frame clock's sample
0x8C059B48  ...                    ; the frame's work
0x8C059B66  [0x8C16CDF4] = 1       ; the render wait is armed
0x8C059BE6  ...                    ; the wait: call the callback, then spin
0x8C059C0C  bf 0x8C059BE6         ;   while [0x0C16CDF4] == 0
```

The wait ends when the flag at `0x0C16CDF4` is cleared, and that happens in the
ASIC's list-end handler (`0x8C063F70`), which the PVR's list-end event raises.
So a frame only ends if the model delivers the events:

* the **vblank-in** (ASIC normal-interrupt bit `0x8`), which the handler at
  `0x8C06423A` turns into the vblank handler `0x8C063D1E` and `0x8C05FCC4`;
* the **DMA ends** and the **TA list ends** (ASIC bits `0x80/0x100/0x200/
  0x400/0x200000`), which the handler turns into the render stages;
* the **end of the render** (ASIC bit `0x4`, the EoR event).

The order inside a slice is the hardware's: the events the frame produced are
dispatched first, the vblank pair comes last (`docs/re/boot_asic_order.md`:
the other order makes the list-end handler see the previous frame's flag and
skip the release, so the frame loop never leaves its wait).

## The clock

The frame is 3,336,670 SH-4 clocks: the TMU's channel 0 counts the CPU clock
divided by 256 and drops 13,033 ticks per frame
(`docs/re/boot_frame_clock.md`).  The port models it: `vf3_native_tmu_set()`
seeds the counter from the sample the state carries at `0x0C1981C8`, and
`vf3_native_tmu_advance()` moves it as the guest runs.

**The clock runs on cycles, not on instructions.**  The port emulates one guest
instruction per step, but the Dreamcast's frame is a fixed number of *cycles*.
The reference run measured the fight scene: 5,441 frames, 9,481,693,829
instructions (`extract/analysis/p1/hits_fight.csv`), so **1,742,588 instructions
per 3,336,670 cycles - 1.9146 cycles per instruction**.  The model charges the
clock that much per step (`VF3_CYCLES_PER_INSN_Q16` in
`src/sys/frame_events.h`).  The factor is a frame average: the SH-4 spends one
cycle on most ALU work and two on a load, a store or a branch, and this code is
a mix of the two.  The exact cost per instruction is P3 work - the translator
would have to charge it per block.

The clock also has to carry *the work that was done*, not the budget that was
offered.  The host's slice hook charges the slice that just ended with the
budget it handed out (the generated code counts one step per instruction and the
budget runs out at zero), and the host charges the steps of a slice that ended
early because the guest returned to it.  Before that fix the clock advanced by
the full `--slice` budget per hook call, whatever the guest had done.

With the fix the port's per-frame guest work matches the reference's:

| | instructions per frame |
|---|---|
| the reference (fight scene) | 1,742,588 |
| the port (from the reference's fight state) | 1,724,558 |

and the display commands per frame stop depending on `--slice` (before: 41k to
155k words, and a different number for every slice size; after: 54.4k-55.0k for
every slice size, the spread being the granularity of the event dispatch).

## The model

`src/sys/frame_events.c` (new in P2) holds the clock and the events.  It is
the model `src/boot_sim.c` grew for the loader's wait, with the loader's own
bits (the GD-ROM cycle clock, the state peeking) left to the caller.  The
handlers are the game's own code: the model runs them with the register file
the guest had when the event came (the interrupt itself changes no register;
the handler pushes what it needs), so the stack pointer is the game's.

The host (`src/host/sdl3_host.c`) runs the guest in slices of `--slice` guest
steps.  When a slice's budget runs out, the model's hook lets time pass and
dispatches the events that came due, in place.  The host collects the display
commands of every slice (the outer run's and the handlers') and hands them to
the PVR2 model.

## The store queue is the only source of display commands

The Tile Accelerator's polygon stream is fed by the SH-4's store queue: a
`PREF` into the queue area (`0xE0000000-0xE3FFFFFF`) sends the queue's 32
bytes to the address the queue's area register (QACR) selects.  The hardware
splits that flush by its target:

| target | what it is |
|---|---|
| below 8 MB | the TA's polygon stream - the display commands |
| below 16 MB | the YUV converter |
| above that | the VRAM (a texture upload) |

**A plain store into `0x10000000-0x13FFFFFF` is a VRAM or a register write,
not a display command.**  The port used to count every such store as a TA
word, which put the texture uploads into the display list: the stream then
carried 1.4 million words per frame, most of them the same 32-byte block
repeated.  The flushes now go through `vf3_ta_flush_hook`
(`src/fight/matrix_family.c`), and only the ones that land in the polygon
range are collected.

## The reference capture

`tools/refemu/vf3dump.c` (ours) now takes a *list* of PCs, each with its own
options (`pc[:every[:skip[:noram]]]`), so one run can capture a series of
frame states and the entry state of an interrupt handler:

```
VF3_DUMP_STATE=.../frm/st.bin VF3_DUMP_PC=0x8c059b48:40 \
  flycast.exe rom/vf3.gdi
```

Every 40th hit of the frame loop is dumped with the 16 MiB RAM window (one
32-bit word per 64-bit record, the port's own recording format).  The run that
reached the demo fight produced 123,440 video frames; the fight is at frame
1330 (two fighters, the stage, the HUD and the Am2D logo - the same frame the
earlier `probe.raw` capture holds).

## The router could not serve the bodies the fight runs

The port stopped after 24 frames with "7 unowned calls at `0x0C0675D8`".  That
address is a **tail-call stub** - `mov.l @(80,pc),r3 ; jmp @r3`, the jump table
of a switch - and no module owned it: the body range of the ledger entry
`0x8C0673A8` covers it, but the *translation* stops at `0x0C0675D6` and hands
the address to the router, and no module claimed it.  A body that no module
*serves* is a hole even when the ledger credits it.

The ground truth for the hole is the reference's own hit list: the fight scene
executed 43,871 distinct PCs, and **1,210 of them the router could not serve**.
They are the leaves the translations stopped at (the stubs, and the functions
behind them).  The repo's own translator walks the CFG from a root and emits
the code, so the fix was to give it those 1,210 PCs as roots:

```
python tools/oracle/translate_adapters.py extract/analysis/_empty_caps \
  --watch tools/watch/vf3_gap_b07.txt --out src/fight/vf3_gap_b07_adapter.c \
  --function vf3_gap_b07_adapter --reuse-adapter "src/fight/*.c"
```

`src/fight/vf3_gap_b07_adapter.c` is the seventh gap module: 11,125 blocks,
3,098 claimed PCs, 54 unsupported instructions (16 addresses, all inside a data
table the walk fell into - `0x0C0A59EC` and its neighbours are offsets, not
code).  `tools/gap_fidelity.py` re-reads the image and checks every block:

```
vf3_gap_b07_adapter.c: 11125 blocks, 3098 claimed PCs
blocks whose opcode does not match the image: 0
body PCs with no block: 0
claimed PCs that no claiming module owns: 0
```

The module is placed in the router chain **after** the other gap modules and
**before** the fallback, so every PC an older module claims keeps its owner.
Its prototypes are declared in `src/fight/matrix_family.c` and not in
`matrix_family.h`: that header is included by every generated adapter and
touching it rebuilds the 1.8M-line adapter set (about 25 minutes).

After the module the router serves **every** PC the reference executed in the
fight scene (43,871 of 43,871), and the port runs the fight without an unowned
call.

## The port's run

From the reference's frame state the port runs the game: the frame loop
returns to its caller, the caller runs the next frame, and the display
commands arrive.  Two frames after the state the port emits a full display
list per frame, and it keeps running (41 frames in 16 s, no unowned call).

The RAM the port starts from is the reference's own (the state's 16 MiB window
is loaded verbatim: 0 bytes differ), so the comparison after N frames is a
comparison of the port's *work* against the reference's.  The reference dumps
its state every 40 hits of the frame loop, and the port's state after 20 frames
is closest to the state it started from - the port's frame is still inside the
gap the reference's dumps leave, so the frame alignment is not pinned yet.

## What is not done yet

* The PVR2 model has no rasteriser (phase P3): the frame is still black.
* The pixel diff against the reference frame (phase P4) is what will pin the
  frame alignment; the RAM comparison is the coarse check that the port and
  the emulator agree on the game's state.
