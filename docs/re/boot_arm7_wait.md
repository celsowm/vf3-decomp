# The boot stopped because the ARM7 never ran - and what it answers

Status: 2026-10-31.  The chain that led here: the disc was never missing
(`docs/re/boot_real_disc.md`), the GD-ROM service is faithful, and the loader
*does* finish its first file.  The stall is one level down: the game uploads the
ARM7 sound firmware into the AICA, releases the ARM7 and waits for the firmware
to report that it is up.  The port had no ARM7, so the wait never ended.

**The port now boots past that point.**  The model that does it is in
`src/fight/native_tick.c` (`aica_arm_boot()`), and the loader reads the files
in the reference's order.

## The summary

| step | port (before) | port (now) | reference (Flycast, real disc) |
|---|---|---|---|
| PVD + root directory | 11 one-sector reads (`0xb06e`, `0xb072..0xb07b`, `0xb070`) | the same | the same |
| `/SNDDRV.BIN` (26 sectors, FAD `0x85b12` → `0x0CAAE800`) | completes, byte-identical | the same | the same |
| ARM7 firmware upload | 53,120 bytes → sound RAM `0x00800000..0x0080CF7C` | the same | the same |
| ARM7 release | **dropped** (no `ARMRST` register) | `ARMRST = 0` boots the model | the ARM7 runs |
| ARM7 status (`+0x5C`) | stays `0` → the guest polls for ever | `"INIT"` | `"INIT"` |
| next file | **never requested** | `/COIN.BIN` (FAD `0x8226d`) | `/COIN.BIN` (FAD `0x8226d`) |
| files read (30 frames) | 1 | 10 | 367 (the whole boot) |

## The GD-ROM service is faithful

The port's model of the REIOS GD syscall (`src/sys/bios_syscall.c`,
`src/sys/gdrom_hle.c`) matches the emulator's HLE
(`tools/emu/flycast/core/reios/gdrom_hle.cpp`) instruction for instruction:

- `REQ_CMD` (r7 = 0) stores the parameter quad and goes `BUSY`;
- `EXEC_SERVER` (r7 = 2) arms the DMA read once
  (`GDROM_HLE_ReadDMA` sets `multi_read_{sector,offset,count,total}`);
- `GET_CMD_STAT` (r7 = 1) returns the status and writes the four result words
  (error, error1, **size**, wait state) to the guest's out-quad;
- the scheduler moves up to five sectors per tick and flips the state to
  `COMPLETE` on the last one.

The port's own trace of the loader's poll loop (`VF3_GDTRACE=1`):

```
gdsys r7 0 r4 00000011 r5 0c31f9d8 -> r0 0000000f st 1 left 0
  req cmd 17 params 00085b12 0000001a 0caae800 00000000
gdsys r7 2 r4 0c2a7390 r5 00000000 -> r0 00000000 st 1 left 26
gdsys r7 1 r4 0000000f r5 0c31f9b8 -> r0 00000001 st 1 left 21   <- 5 sectors moved by the poll
gdsys r7 2 r4 00000000 r5 00002800 -> r0 00000000 st 1 left 21
gdsys r7 1 r4 0000000f r5 0c31f9b8 -> r0 00000001 st 1 left 16
gdsys r7 2 r4 00000000 r5 00005000 -> r0 00000000 st 1 left 16
gdsys r7 1 r4 0000000f r5 0c31f9b8 -> r0 00000001 st 1 left 11
gdsys r7 2 r4 00000000 r5 00007800 -> r0 00000000 st 1 left 11
gdsys r7 1 r4 0000000f r5 0c31f9b8 -> r0 00000001 st 1 left 6
gdsys r7 2 r4 00000000 r5 0000a000 -> r0 00000000 st 1 left 6
gdsys r7 1 r4 0000000f r5 0c31f9b8 -> r0 00000001 st 1 left 1
gdsys r7 2 r4 00000000 r5 0000c800 -> r0 00000000 st 1 left 1
gdsys r7 1 r4 0000000f r5 0c31f9b8 -> r0 00000002 st 0 left 0    <- COMPLETE
```

The guest's `r5` on each `EXEC_SERVER` is the byte count it read out of the
result quad (`0x2800`, `0x5000`, … = 5, 10, … sectors × 2048), which is the
`result[2]` the model writes - the whole protocol lines up.

And the data is right: the 53,120 bytes of `/SNDDRV.BIN` are in the RAM at
`0x0CAAE800` byte-identical to `extract/gamedata/SNDDRV.BIN`.

## The directory parse is right too

The loader buffer at `0x0C2A6300` holds a *raw* ISO9660 record, and the name in
it is `VF3TBE3.BIN;1`.  That is **not** the next file the loader wants: the
guest streams the root directory sector by sector into the same buffer (ten
one-sector reads, `0xb072..0xb07b`), so the buffer's content is simply the
**last** sector it read - and the disc's sector `0xb07b` starts with the
`VF3TBE3.BIN` record (`build/sectcmp.py`).

The guest's parsed table (at `0x0C2ABDA0`, sorted by name) matches the disc
exactly:

| name | table LBA | ISO LBA | table size | ISO size |
|---|---|---|---|---|
| ST_PAI.BIN | `0x852E6` | 545510 | 21284 | 21284 |
| ST_WOL.BIN | `0x85318` | 545560 | 32412 | 32412 |
| VF3TBE3.BIN | `0x85C28` | 547624 | 1114112 | 1114112 |
| VOFAKIFX.BIN | `0x856FF` | 546559 | 147152 | 147152 |

## Where the image lives (and where it runs)

`1ST_READ.BIN` is in the RAM **twice**:

| placement | contents | matches the file at |
|---|---|---|
| `0x0C004000` | file + `0x100` … | `image+0x000100` (99.9 % over 4 KiB) |
| `0x0C010100` | file + `0x100` … | `image+0x000100` (100 %) |

The guest **executes** the second one: the stall is at `0x0C0C5C00` =
`0x0C010100 + 0xB5B00`, and the baseline function list agrees - its addresses
are the identity placement (`file offset + 0x8C010000`).

The file's first `0x100` bytes are the **canonical Dreamcast boot copy-loop**
(`docs/re/image_identity.md`): `0x06D0` = `mov.l @(24,pc),r0`, … `jmp @r0`,
with the literal slots at file `+0x54`, `+0x64`, `+0x74`, `+0x78` holding
`0xFFFDFFFD` in the shipped file.  Those are patched at runtime (the REIOS
fills the copy source, the copy end, the destination and the entry), so the
stub only works when the loader sets it up.  The port does not run the stub:
it starts the guest at `0x8C004000`, the SDK startup of the *first* copy, and
lets the program's own PC-relative literals resolve there.

## The stall: the ARM7

With `VF3_DEVLOG=1` the port's boot made **one** device read outside the RAM,
and it was read over and over:

```
devread 0080005c size 4 pc 0c0c5c00          (407,294 times in 30 frames)
```

`0x00800000` is the **AICA's RAM** (2 MiB, `0x00800000..0x009FFFFF`; the
port models it as `AICA_RAM_BASE` in `src/fight/native_tick.c`).  Right before
the poll, the device log shows the whole hand-over:

```
devwrite 0080cf1c size 4 value 00000000      <- the tail of the firmware upload
...
devwrite 00800050 size 4 value 00000000      <- the guest's own header fields
devwrite 00800060 size 4 value ffffffff
devwrite 00800064 size 4 value ffffffff
...
devwrite 0080007c size 4 value ffffffff
devread  00702c00 size 4 pc 0c0c5c00         <- the AICA's ARM reset register
devwrite 00702c00 size 4 value 00000000      <- 0 releases the ARM7
devread  0080005c size 4 pc 0c0c5c00         <- and the guest waits for the answer
```

The upload is the ARM7 firmware itself: 53,120 bytes from `0x00800000` to
`0x0080CF7C`, byte for byte `extract/gamedata/SNDDRV.BIN`.  The header the
guest writes afterwards (`+0x50` = 0, `+0x60..0x7C` = `0xFFFFFFFF`) is the
driver's status block.

`0x00702C00` is the AICA's `ARMRST` register (the emulator's map puts the AICA
registers in area 0, `0x00700000..0x00707FFF`; `aica_if.cpp` handles
`0x2C00` and calls `arm::enable(ARMRST == 0)`).  The port had no such
register, so the release was dropped on the floor, the ARM7 never ran, the
firmware's status field stayed `0` and the loader waited for ever.

In the reference the ARM7 really runs: Flycast emulates it
(`tools/emu/flycast/core/hw/arm7/arm7.cpp`; the boot log has 5,463 AICA/ARM7
lines from the first "AICA ARM Reset" on).

## What the ARM7 answers: "INIT"

The wait is a poll of one word, the driver's status field at sound RAM
`+0x5C`:

```
0x0C040656  mov.l @(72,pc),r2     ; r2 = 0xA080005C  (the sound RAM's +0x5C)
0x0C040658  mov.l @r2,r3           ; r3 = the status word
0x0C04065A  tst r3,r3
0x0C04065C  bt  0x0c040656        ; while (status == 0) keep waiting
```

The value is **"INIT"**.  It is not in the shipped firmware image (the file has
`0` there), so the ARM7 writes it - and the reference's own sound RAM proves
it.  The AICA RAM is part of a Flycast savestate
(`aica_if.cpp`: `aica_ram.serialize(ser)`), and `tools/aica_state.py` reads it
out of the state file:

```
$ python tools/aica_state.py tools/emu/flycast-build/data/vf3_26.state --range 0x40:0x80
0040  00 00 00 00 38 00 00 00 a0 18 00 00 00 00 18 a0  |..............|
0050  00 00 00 00 80 cf 00 00 7d 0d 2b 4a 49 4e 49 54  |........}.+JINIT|
0060  52 00 00 00 44 00 00 00 4e 00 00 00 ff ff ff ff  |R...D...N.......|
0070  48 00 00 00 38 00 00 00 37 00 00 00 ff ff ff ff  |H...8...7.......|
```

`+0x5C` = `49 4E 49 54` = `"INIT"` in all six savestates of the reference
(`vf3_26..29`, `vf3_45`, `vf3_46`), while the file the guest uploads has `0`
there - the word is the ARM7's, not the game's.

The firmware agrees.  Its reset vector (file `+0x00` = `0xEA000142`) branches
to `0x510`, and the start-up there is a straight-line piece of ARM code:

```
00000510  mrs r0, apsr            ; the mode switch
00000514  orr r0, r0, #0xc0
00000518  msr cpsr_fc, r0
0000051C  mov r0, #0              ; the registers are cleared one by one ...
...
00000558  ldr ip, [pc, #0x61c]    ; ... and the work area comes from the pool
0000055C  ldr sp, [pc, #0x61c]
00000560  ldr r0, [pc, #0x61c]
00000564  mov r1, #0x10000
00000568  str r2, [r0], #4        ; the work area is cleared
0000056C  cmp r0, r1
00000570  bne #0x568
00000574  stmdb sp!, {pc}         ; and the main loop is entered
0000057C  b #0xb2c
```

The literal pool at file `+0xB7C` holds the driver's own constants, and the
four bytes right behind them are the answer:

```
+0xB7C  0000A200      ip  - the work area
+0xB80  0000A100      sp  - the stack
+0xB84  0000A000      r0  - the work area's base
+0xB88  54494E49      "INIT"
```

The main loop at `0x0B2C` sums the table the pool points at and stores the
negated sum in the driver's checksum field (`+0x58`, `str r2, [r1, #0x18]`
with `r1 = 0x40`); the reference's sound RAM carries `0x4A2B0D7D` there, which
is what that sum is.

## The model in the port

`src/fight/native_tick.c` now carries the ARM7's *boot*, next to the runtime
protocol it already modelled (the upload engine at `0x00800090/94/98` and the
mailbox at `0x008000B0/B4`):

- the AICA's `ARMRST` register at `0x00702C00` is read and written; writing 0
  releases the ARM7, writing 1 holds it in reset;
- the release boots the firmware: the model checks that a driver image is in
  the sound RAM (the identification field at `+0x20` is not empty - the AM2
  driver carries `"AM2/AICAsoundDrv990708/Ver1.63a "` there), publishes the
  firmware's start-up state and leaves:
  - `+0x5C` = `"INIT"` (`0x54494E49`), the word the guest polls;
  - `+0x88` = `0x001E0000`, the free-size limit the driver publishes.  The
    loader checks the file it is about to upload against it (`0x0C0401D4`) and
    fails with `-4` when it does not fit; the value is the one the emulator's
    own trace carries (`docs/re/phase4_findings.md`).  The reference's sound
    RAM carries a different word there later in the run (`0x04001E00` in the
    savestates, the driver's own state after the game has used it), so this is
    the *start-up* value, not a constant of the driver.

The port still has no ARM7 interpreter: the driver keeps running as a model
(the mailbox and the upload engine are models too), and only its start-up is
modelled now.

## What the port does after the model

`tools/boot_reads.py` puts the two boots side by side, request for request:

```
$ python tools/boot_reads.py flycast.log build/boot_long.log --limit 45
=== reference: 382 requests ===
  17    caae800     53248    85b12  /SNDDRV.BIN + 0
  18    caae800     43008    8226d  /COIN.BIN + 0
  19    caae800    176128    82282  /ANAUNCE.BIN + 0
  ...
=== port: 42 requests ===
  12    caae800     53248    85b12  /SNDDRV.BIN + 0
  13    caae800     43008    8226d  /COIN.BIN + 0
  14    caae800    176128    82282  /ANAUNCE.BIN + 0
  ...
```

The port's requests are the reference's requests 5..46 - **the same FADs, the
same lengths and the same destinations**, one for one:

| # | file | FAD | destination |
|---|---|---|---|
| 12 | `/SNDDRV.BIN` | `0x85b12` | `0x0CAAE800` |
| 13 | `/COIN.BIN` | `0x8226d` | `0x0CAAE800` |
| 14 | `/ANAUNCE.BIN` | `0x82282` | `0x0CAAE800` |
| 15 | `/PLAYER.BIN` | `0x852a0` | `0x0CAAE800` |
| 16 | `/CP_ASC.BIN` | `0x68999` | `0x0C828800` |
| 17 | `/CP_GM_J.BIN` | `0x68bc9` | `0x0C828800` |
| 18-21 | `/ROB_BALL.POL`, `/ROB_BALL.TEX`, `/ROB_ALP.POL`, `/ROB_ALP.TEX` | `0x6c189`, `0x6c199`, `0x6c1a6`, `0x6c1d3` | `0x0C320000`, `0x0CBC7000`, `0x0C328000`, `0x0CBCD000` |
| 22-23 | `/CP_LOGO.BIN`, `/CP_SKY09.BIN` | `0x68ec9`, `0x6b9fa` | `0x0C828800` |
| 24-28 | `/ST0C.CLI`, `/ST0C_E.POL`, `/ST0C_E.TEX`, `/ST0C.POL`, `/ST0C.TEX` | `0x82183`, `0x81b26`, `0x81b6c`, `0x81a78`, `0x81adb` | `0x0CBCE800`, `0x0C451000`, `0x0CBBE000`, `0x0C474000`, `0x0CBA8000` |
| 29-39 | `/ST_ETC.BIN`, `/VO_AKI.BIN`, `/ROB_AKI.*`, `/MKAO_AKI.*`, `/VO_WOL.BIN`, `/ROB_WO2.*`, `/MKAO_WO2.*` | … | … |
| 40-41 | `/MOTHEAD.BIN`, `/MTAKIWOL.BIN` | `0x6c1d4`, `0x7133d` | `0x0C5CA800`, `0x0C5F4000` |

The reference's first five requests (`0xb05e`, `0xb065`, `0xb06e`, `0xb072`
and the 1,179,648-byte read of `/1ST_READ.BIN` at `0x85ede`) are the **REIOS's
own** boot reads; the port does not run the REIOS - it starts with the image
already in RAM - so its sequence begins at the reference's fifth request.  That
is the same difference the earlier notes recorded; what is new is that the
game's own ladder now runs to the end of the list the reference reads in the
same order.

The game starts to draw as well: at frame 150 the port renders 614,400
pixels (640x480) with 176 TA words, 8 lists and 10 primitives (4 polygons,
2 sprites, 4 modvols, 2 textured), where the stalled boot rendered nothing.


## Corrections to the earlier notes

* `docs/re/boot_real_disc.md`, "What is still open": the port does **not**
  stop with the loader holding the next file's name - the loader's first file
  loads completely and the name in the buffer is the last directory sector's
  record.  The divergence is after the load, in the ARM7 handshake.
* the same note's "the port loads one file and stops" is **superseded**: with
  the ARM7's boot modelled, the port reads the files in the reference's order.
* `AGENTS.md`, "the guest is parked at `0x0C0C5C00`": correct, and the park is
  the ARM7 wait, not a GD-ROM poll.
* the earlier reading of the device log - "the boot makes exactly one device
  read" - was wrong in the detail: the boot makes exactly one device read
  *address* (`0x0080005C`), over and over, and it does write the firmware
  upload and the `ARMRST` release before it.
