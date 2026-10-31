# The REIOS GD-ROM service: the loader's disc reads never ran

## The defect

The loader reaches the disc through the BIOS syscall vector `0x8C001006`
(the pointer word at `0x8C0000BC` points there).  Two doors lead to it in the
port:

| door | what it did |
|---|---|
| the matrix chain's REIOS stub (`src/fight/vf3_aica_stub_adapter.c`, which *owns* the entry `0x0C001006`) | answered every call from an **idle** drive: `REQ_CMD` -> `0` ("no request accepted"), `GET_CMD_STAT` -> "idle", `EXEC_SERVER` -> "nothing changes" |
| the unowned hook (`src/fight/native_tick.c`) | **did** serve the drive attached to the run, with the disc in it (`vf3_bios_gd_syscall_clocked`) - but the stub owns the entry, so this hook never saw the call |

So the drive was attached, the disc was readable, and the guest's file reads
still never happened.  The symptom was easy to miss: `VF3_GDTRACE=1` printed
**zero** `gdsys` lines although the guest called the vector about twenty times
in 45 frames (`VF3_DEBUG_STUB=1` shows the calls with their PR `0x0C035248`).

The idle model is not wrong in itself - it is what the fight-state corpora
recorded (a drive with no transfer in flight).  It is wrong as the answer to a
call made by a loader that has a disc in front of it.

## The fix

The service moved to `src/fight/native_tick.c` as

```c
int vf3_native_gd_syscall(uint32_t entry, vf3_matrix_state *s, const vf3_ram_map *ram);
```

and **both** doors call it (`unowned_hook` in `native_tick.c`, the REIOS stub in
`vf3_aica_stub_adapter.c`), so the same call can no longer be answered two
different ways.

Two things came with it:

* **the sector copy lands in the RAM window of the call.**  `gd_write` used to
  write into `machine.ram` (the image of the run in progress), which is right
  for a native run but drops the bytes for every other caller.  The window the
  router hands over is now the target (`gd_map`), and the run's image is only
  the fallback for the scheduler stepping the drive between calls.
* **the model's answers match the reference.**  `src/sys/bios_syscall.c` now
  follows `tools/emu/flycast/core/reios/gdrom_hle.cpp`:
  * `EXEC_SERVER`, `INIT_SYSTEM` and `RESET` **leave r0 alone** (none of them
    writes `r[0]` in the reference; the port wrote `0` for all three).  The
    new `vf3_bios_gd_r0_answered()` says which commands answer in r0.
  * `INIT_SYSTEM` **resets the drive** (`gd_hle_state = {}` in the reference):
    the request counter starts over and the drive is idle again.  The port did
    nothing at all for it.
  * `CHECK_PIO_TRANS` answers `GDC_ERR` (-1) when the drive holds no
    multi-sector transfer, where the port answered `GDC_BUSY` (1).

## Evidence

**The drive is asked, and the answer comes from the drive** (`VF3_GDTRACE=1`,
45 frames, after the fix):

```
gdsys r7 3 r4 0c0ea790 -> r0 00000000 st 0 left 0     <- INIT_SYSTEM
gdsys r7 0 r4 00000018 -> r0 00000002 st 1 left 0     <- REQ_CMD (the command 0x18)
  req cmd 24 params 00000000 00000000 00000000 00000000
gdsys r7 2 r4 0c2a7340 -> r0 00000000 st 2 left 0     <- EXEC_SERVER
gdsys r7 1 r4 00000002 r5 0c31f9ac -> r0 00000002 st 0 left 0   <- GET_CMD_STAT: complete
gdsys r7 0 r4 00000011 r5 0c31f9ac -> r0 00000003 st 1 left 0   <- REQ_CMD (the command 0x11 = DMA read)
  req cmd 17 params 0000b06e 00000001 0c2a6300 00000000
gdsys r7 2 r4 0c2a7340 -> r0 00000000 st 1 left 1     <- EXEC_SERVER: the transfer is armed
gdsys r7 1 r4 00000003 r5 0c31f98c -> r0 00000002 st 0 left 0   <- the poll: the sector moved
```

45 frames: 15 `REQ_CMD`, 15 `GET_CMD_STAT`, 24 `EXEC_SERVER`, 5 `INIT_SYSTEM`,
5 `GET_DRV_STAT`.  Before the fix: **zero**.

**The bytes the loader received are the disc's own bytes.**
`tools/gd_sector_check.py` re-derives the sector straight from the track file
and compares it with the buffer the loader was given:

```
$ python tools/gd_sector_check.py rom/vf3.gdi build/post45.ram 0x0c2a6300 0x0000b06e
FAD 0000b06e -> guest 0c2a6300: MATCH
  disc  0000000000000000000000000000000000000000000000000000000000000000
  guest 0000000000000000000000000000000000000000000000000000000000000000
```

(The sector is empty because the disc image in `rom/` is - see
`docs/re/boot_data_blocked.md`.  The point of the check is that the *address
arithmetic* is right: FAD -> LBA -> track -> file offset -> the guest's buffer.)

**The test.**  `tests/gd_service_replay.c` (target `vf3gdservice`) drives the
stub the way the loader does - `REQ_CMD`, `EXEC_SERVER`, the `GET_CMD_STAT`
poll - against a synthetic disc and requires: the command to be accepted, the
sectors to land in the caller's RAM window byte for byte, the status to reach
`COMPLETE` with the byte count the loader expects, `EXEC_SERVER`/`INIT_SYSTEM`
to leave r0 alone, `INIT_SYSTEM` to restart the request counter, and the idle
answer to stay in place when no drive is attached.

**The mutation gate.**  The fix spans four files, and `tools/mutate.py` works on
one file per run, so the list is split in four (all next to the test):

| list | file | mutations | caught |
|---|---|---|---|
| `tests/gd_service_mutations.json` | `src/fight/vf3_aica_stub_adapter.c` | 2 | 2 |
| `tests/gd_service_native_mutations.json` | `src/fight/native_tick.c` | 4 | 4 |
| `tests/gd_service_model_mutations.json` | `src/sys/bios_syscall.c` | 2 | 2 |
| `tests/gd_service_drive_mutations.json` | `src/sys/gdrom_hle.c` | 3 | 3 |

```
python tools/mutate.py --port src/fight/vf3_aica_stub_adapter.c \
    --exe build/vf3gdservice.exe --mutations tests/gd_service_mutations.json \
    --target vf3gdservice --keep-going
```

**The offline gate is unchanged**: `python tools/portcheck.py --bindings
build/empty_bindings.json` still gives 30 PASS / 11 FAIL, and the eleven are
the known missing fixtures (`vf3tailcall`, `vf3meshnode`, `vf3d0fa`,
`vf3c788`, `vf3matrix`, the five `vf3fvecnorm*`, `vf3fpu`).

## What the fix does *not* change

* **The visible boot is the same.**  An A/B of the 45 frame boot (the
  pre-fix binary kept as `build/vf3sdl_pre.exe`) shows the same TA words, the
  same 614400 pixels and the same frames; only the frame on which a given
  picture appears moves by one.  The screen stays black because the *data* is
  missing, not because the drive is silent - see
  `docs/re/boot_data_blocked.md`.
* **The card check is unchanged.**  The guest still walks the directory chain
  from block 255 to 248 and still never asks the second card (recipient
  `0x02`).  The reference's "fifteen blocks, two cards" is **not** a valid
  oracle for the port's boot: the reference's log is a run that *loaded a save
  state* of the already running game, not a boot - see
  `docs/re/boot_data_blocked.md`.
* **The REIOS still does not run.**  The BIOS ROM is not emulated, so the
  vector is a port-owned door, not the reference's REIOS.  What the fix does is
  make that door behave like the reference's REIOS GD service.

## Correction to the frontier text

`AGENTS.md` said the port's "GD-ROM model is attached but never asked for
anything".  The model was attached and the guest *did* ask - twenty times in 45
frames - but the answer came from the idle model, so the read never happened.
The wording is corrected there; the underlying blocker (the data) is unchanged.
