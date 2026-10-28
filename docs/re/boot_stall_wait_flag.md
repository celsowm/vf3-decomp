# The boot's wait: what the disc boot is actually stuck on (2026-10-27)

`docs/re/boot_stall_sb_scan.md` recorded that the disc boot stops making
progress after the memory-card check passes.  This note names the instruction
the guest is parked on, the flag it is waiting for, and the three places in the
SDK kernel that can set that flag.

## Where the boot stops

The boot reaches the SDK's task scheduler and stops there.  The host's trace
(`VF3_HOST_TRACE=1`) shows the guest in one place from frame 19 on:

```
slice: 34200000 insns, 19 frames, pc 0c059bee pr 0c059bee r8-15 ... 0c31fa1c
slice: 34400000 insns, 19 frames, pc 0c059bee pr 0c059bee r8-15 ... 0c31fa1c
```

The frame counter does not move and the registers do not change: the guest is
spinning inside a wait.  (The "frame 169" of the earlier note was the host's
slice counter, not the frame count - the wait is already there at frame 19.)

## The wait itself

`tools/adapter_body.py 0x0c059bee --span 20` gives the translation; the
assembly (`0x8C059BEE` in `1ST_READ.unsc.bin`) is:

```
8c059bee  mov.l @(disp,PC),r0    ; r0 = &A        (0x0c16ccac)
8c059bf0  mov.l @r0,r3           ; r3 = *A
8c059bf2  mov.l @(disp,PC),r2    ; r2 = &B        (0x0c16ccb0)
8c059bf4  mov.l @r2,r1           ; r1 = *B
8c059bf6  add r3,r1
8c059bf8  mov.l @(disp,PC),r2    ; r2 = &C        (0x0c16cdf0)
8c059bfa  add #1,r1
8c059bfc  mov.l @r2,r3           ; r3 = *C
8c059bfe  cmp/hi r1,r3           ; T = (*C > *A + *B + 1)
8c059c00  bf 0x8c059c06         ; no timeout: check the flag
8c059c02  bra 0x8c059c0e        ; timeout
8c059c04  mov #1,r14            ; (delay slot) r14 = "timed out"
8c059c06  mov.l @(disp,PC),r3    ; r3 = &flag     (0x0c16cdf4)
8c059c08  mov.l @r3,r2           ; r2 = flag
8c059c0a  tst r2,r2
8c059c0c  bf 0x8c059be6         ; spin while the flag is 0
```

From the RAM dump of a 20-frame boot (`--dump-ram`):

| variable | address | value |
|---|---|---|
| *A | 0x0C16CCAC | 10 |
| *B | 0x0C16CCB0 | 10 |
| *C | 0x0C16CDF0 | 1 |
| flag | 0x0C16CDF4 | **0** |

So the deadline (`*C > *A + *B + 1` = `1 > 21`) has not passed: the guest is
waiting for the flag word at **0x0C16CDF4** to become non-zero, and nothing in
the port ever writes it.

## Who can set the flag

Six places in `1ST_READ.unsc.bin` mention the address; three of them write it:

| site | what it does |
|---|---|
| `0x8C05A518` | `mov.l @(disp,PC),r3` (r3 = 0x0C16CDF4); `mov #1,r4`; `mov.l r4,@r3` - sets the flag to 1, then clears 0x0C16CDFC and returns 0x0C0EA944 |
| `0x8C05D9B0` | `mov.l @(disp,PC),r1` (r1 = 0x0C16CDF4); `mov #1,r4`; `mov.l r4,@r1` - sets the flag to 1, then calls 0x8C060D14 twice |
| `0x8C063F6C` | `mov.l @(disp,PC),r2` (r2 = 0x0C16CDF4); `mov.l r13,@r2` - sets the flag to r13 |

The other three (`0x8C059B08`, `0x8C059C06`, `0x8C059C9C`) only *read* it -
they are the wait itself.

The scheduler that owns the wait walks the task table at 0x0C16CDDC and calls
each task's function through 0x0C062FC2 before it spins, so the flag is the
"this task finished" hand-off of the SDK's task switch.

## The decoder check that had to come first

While chasing the flag, the `mov.l @(disp,PC),Rn` displacement looked wrong:
`tools/sh4.py` decodes it with an **8-bit** displacement scaled by 4
(`d8*4`), while the SH-4 manual's `1101 nnn0 disp12` row suggests 12 bits.
A 12-bit reading would move every literal pool of the boot kernel - including
the BIOS system area at 0x8C000070 and the RTE stub at 0x8C00FA18 - and the
boot would then read garbage.

Flycast's own opcode table settles it
(`tools/emu/flycast/core/hw/sh4/sh4_opcode_list.cpp`):

```c
{0, i1101_nnnn_iiii_iiii, Mask_n_imm8, 0xD000, ReadsPC,
 "mov.l @(<PCdisp8d>),<REG_N>", 1,2,LS,2, dec_MRd(PRM_RN,PRM_PC_D8_x4,4)},
```

`i1101_nnnn_iiii_iiii` is `1101 | Rn(4) | disp8`, and the operand is
`PRM_PC_D8_x4` - an **8-bit** displacement times 4.  The repo's decoder and
the translator (`tools/oracle/translate_adapters.py`, `top==0xD` and the
`literal_jump` helper) are right; a 12-bit reading would be wrong.  Measured
over the whole image, the 8-bit formula lands on a RAM or code pointer at
12,768 of the 17,794 sites where the two formulas differ; the 12-bit one
manages 1,743 and produces garbage (0x88308946, 0x330cc700, ...) at the
rest.

## What this means for the port

The guest is not stuck on a missing device read; it is waiting for a task that
never completes.

The first suspicion was the GD-ROM: the guest's own driver would have to read
the files, and `docs/re/boot_stall_sb_scan.md` shows that the guest never
issues a GD-ROM command.  **That suspicion is wrong.**  A clean boot of the
same disc on the reference emulator never touches the GD-ROM either - it goes
straight into the VRAM clear and then into the render loop
(`docs/re/ref_clean_boot.md`).  So the boot's file ladder is read later, or by
another path, and the ATA register interface is not what the boot needs.

What is left is the pair the port actually shows: the rendered frame is black
(the VRAM is still empty where the TA samples), and the flag the scheduler
waits for is never set, so the game sits in the scheduler instead of in the
render loop.  The three writers of the flag are the places to look next.

## Diagnostics added

* `vf3_native_current_pc()` (`src/fight/native_tick.h`) - the PC of the
  function the guest is in.  A *readable* port does not write the guest PC
  while it runs, so the native tick keeps `machine.readable_entry` (the entry
  of the readable port that is running right now) and reports it instead.
* The host's watchdog thread (`src/host/sdl3_host.c`) prints "no progress:
  frame N, the guest is at X" every five seconds the frame counter stands
  still, together with the literal pool around that address.
* `VF3_NATIVE_NESTED_BUDGET` (`src/fight/native_tick.c`) caps a nested run
  (an interrupt handler) at 4,000,000 steps: a handler that waits for
  something that never comes then ends as a reportable failure instead of
  hanging the port silently.
