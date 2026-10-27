# Where the disc boot stalls (2026-10-27)

After the memory-card check passes, the boot from the disc stops making
progress: the same frame is submitted over and over and the game never asks
the drive for a file.  This note records what the port observes, so the next
step does not have to rediscover it.

## The stall

`VF3_HOST_TRACE=1` over a 180 frame run shows the guest in one place:

```
slice: 257800000 insns, 168 frames, pc 0c059bee pr 0c059bee
        r8-15 0c0a13a4 0c29b864 00000000 0c1fd758 00000000 00000001 00000000 0c31fa18
```

The PC does not move and the registers do not change: the frame counter
advances about one frame per four million instructions, so the guest is
spinning in a wait.

The wait itself (`tools/adapter_body.py 0x0c059bee --span 60`) is:

```
r0 = ram[0x0c059c78]; r3 = ram[r0]           /* r3 = *A           */
r1 = ram[ram[0x0c059c7c]]; r1 = r1 + r3 + 1   /* r1 = *A + *B + 1 */
r3 = ram[ram[0x0c059c70]]                     /* r3 = *C           */
if (r3 > r1) r14 = 1                          /* the deadline     */
r2 = ram[ram[0x0c059c80]]                     /* r2 = *D           */
if (r2 == 0) goto 0x0c059be6                  /* spin while *D = 0 */
```

So the loop waits for a flag (`*D`) to become non-zero, with a deadline
(`*C` against `*A + *B + 1`).  It is the SDK's "wait for the task that
loads the files" - the flag is set by the task that never runs.

## What the game does before it stalls

`VF3_DEVLOG=1` (the log prints the guest's PC now) shows, in order:

1. The system bus is set up: `SB_ISTNRM` is cleared and polled, and the G1
   bus timing registers are programmed (`0x005F7480`..`0x005F7494` =
   `0x400`, `0x400`, `0x400`, `0x400`, `0xD31`, `0xD31`, and `0x005F74B8` =
   `0x8843407F`).  That is the boot's hardware bring-up, and it succeeds.
2. The Maple devices are scanned (the card at 0x01 answers DEVINFO,
   GETMEDIAINFO, BLOCKREAD and BLOCKWRITE - the card check passes), and the
   scan is repeated every frame.
3. **The guest reads the whole system bus register area, word by word:**
   2047 words from `0x005F6000` to `0x005F7FFC`, from the function at
   `0x0C055C1A`.  Every one of those reads answers 0 in the port.
4. Nothing else.  The guest never writes a GD-ROM command.

## The GD-ROM's registers are not modelled

The port has a GD-ROM model, but it is the **BIOS syscall** model
(`src/sys/gdrom_hle.c`: REQ_CMD, EXEC_SERVER, GET_CMD_STAT - the door the
loader uses).  The game's own GDFS driver does not use that door: it drives
the drive through the drive's registers in the system bus area, which Flycast
maps in `core/hw/gdrom/gdromv3.h`:

```
0x005F7000 .. 0x005F7014   the impeded registers
0x005F7018                GD_DEVCTRL (write) / GD_ALTSTAT (read)
0x005F7080                GD_DATA
0x005F7084                GD_ERROR (read) / GD_FEATURES (write)
0x005F7088                GD_IREASON (read) / GD_SECTCNT (write)
0x005F708C                GD_SECTNUM
0x005F7090 / 0x005F7094   GD_BYCTLLO / GD_BYCTLHI
0x005F7098                GD_DRVSEL
0x005F709C                GD_STATUS (read) / GD_COMMAND (write)
```

With every register reading as zero the driver sees a drive that is neither
busy nor ready (`GDStatus.DRDY` is bit 6 of the status register, and Flycast
sets it when a disc is in the drive - `gd_setdisc()`), so it never issues a
command.

**First step taken**: the port now answers the status register with DRDY set
and the unit status with "standby" (`GD_UNIT_STANDBY`), so the drive looks
present and idle.  The command side (the ATA commands, the data register and
the SH-4's DMA channel 1, which the GD-ROM uses for its transfers) is still
to do.

## The disc itself is fine

`vf3_gdi_open` reads `rom/vf3.gdi` and the tracks (`track01.bin`,
`track02.raw`, `track03.bin`) are there, so a file read through the model
would find data.  The earlier boot work (from a reference state rather than
from the disc) issued the expected ladder - PLAYER.BIN, CP_ASC.BIN,
CP_GM_J.BIN, ROB_BALL.POL/TEX, ROB_ALP.POL/TEX - with the right FADs
(docs/re/boot_gd_ladder.md), so the disc and the FAD arithmetic are known
good; what is missing is the door the game's driver uses.
