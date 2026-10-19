# Native title scene -> CP_LOGO (2026-10-19)

## The trigger

The title loop is the infinite body at `0x8C095CC2` (loop head `0x8C095CCC`, branch back at
`0x8C09612C`). Each iteration calls the scene dispatcher `0x8C0968CC` with the scene context
`0x0C29B864`:

| offset | meaning |
|---|---|
| `+0` | state mask (`0x80000000 >> state`) |
| `+8` | current state (byte) |
| `+10` | next state (byte) |
| `+11` | sub-state (byte) |
| `+12` | countdown (u32) |

The dispatcher decrements `+12`, copies `+10` to `+8`, indexes the main table `0x0C10BAA8`
and jumps. State 3 (`0x8C096D3C`) indexes the sub-table `0x0C10BBB8` by `+11`. Sub-state 2 is
`0x0C096E5C`, which falls into the setup at `0x8C096E62`.

The setup calls the resource loader `0x8C07AAAC` with `r4 = 0x414F` at `0x8C096F24`. The
loader calls the file loader `0x8C0A7F5A` with file index 5, i.e. `CP_LOGO.BIN`:

```
FAD 0x68ec9, 0x100 sectors (524288 bytes), destination 0x0C828800
```

## Emulator sequence

`entry_order.py 22` on `0x8C0A7F5A 0x8C07AAAC 0x8C0A28D4` (2,000 frames) opens:

| # | file loader call | caller |
|---|---|---|
| 1 | file 3 (`CP_GM_J`) | `0x0C07AADE` |
| 3-7 | files `0x40`-`0x43` (ROB) | `0x0C0A2916/0x0C0A294C` |
| 8 | `0x8C07AAAC(r4=0x414F)` | `0x0C096F28` |
| 9 | file 5 (`CP_LOGO`) | `0x0C07AADE` |

The setup itself is entered once, `0x8C096E62` with `pr=0x0C095CF2`, `r4=0x0C29B864`,
`r5=8`.

## Native proof

`tools/boot_cp_logo_probe.py` starts from `golden_bootV_vf3_25.bin`, forces the drive idle
(the inherited ROB read is complete in the emulator sequence) and enters `0x8C096E62` with
`r4=0x0C29B864`, `r5=8`, `pr=0x8C095CC2`:

```
python tools/boot_cp_logo_probe.py
  first GD reads:
    0: fad 00068ec9 sectors 00000100 dest 0c828800
    1: fad 0006b9fa sectors 00000081 dest 0c828800
    ...
  PASS: first read is CP_LOGO.BIN (FAD 0x68ec9, 0x100 sectors, dest 0x0C828800); unowned=0
```

The handler runs entirely through readable/adapted code (0 unowned) and issues the CP_LOGO
read, followed by the next title resources.

## Real frame-loop proof

`tick_capture.py 0x8C095CC2 --state tools/emu/flycast-build/data/vf3_22.state --frames 1000
--pairs 1 --name frame_entry_s22` captures the exact title frame-loop entry with the real caller
return (`pr=0x0C02007C`), stack (`sp=0x0C31FA80`) and registers (`r4=0x0DCE`,
`r5=0x0C33C1A8`). `entry_order.py 22` shows the order: frame loop `0x8C095CC2` -> loop head
`0x8C095CCC` -> dispatcher `0x8C0968CC` (`pr=0x0C095CF2`) -> setup `0x8C096E62` ->
`0x8C07AAAC(r4=0x414F)` (`pr=0x0C096F28`) -> file loader `0x8C0A7F5A(file 5)`.

`tools/boot_cp_logo_frame_probe.py` runs that capture free with `BS_KEEP_PR=1` and
`--slice 200000`:

```
python tools/boot_cp_logo_frame_probe.py
  first GD reads:
    0: fad 00068ec9 sectors 00000100 dest 0c828800
  PASS: frame loop ... CP_LOGO.BIN ...; unowned=0
```

The default 20,000-step slice stops inside the render callback `0x0C059BEE` before the
dispatcher; a larger slice is required for one full frame. The loader gate is the resource
state word at `0x0C2A620C + 2*0x0E = 0x0C2A6228` (resource `0x414F` maps through
`0x0C11ABB0 + 6*(0x414F & 0x3FFF)` to index `0x0E`); the frame-entry capture has state 0, i.e.
"load". The request is the first native GD read, and the run is 0 unowned.

## Remaining boot gap

The frame loop now issues CP_LOGO from the real captured entry. Reaching the next title
resource (or a scene transition) still needs the frame loop to run long enough for the
vblank-driven loader completion; the capture starts at the frame-loop entry with the ROB read
already complete, so the CP_LOGO request is the immediate next step. The 1,500-vblank boot
continuation reaches the frame loop after its cap and with sub-state 3, so it does not
re-enter the setup; that is a capture-length/state issue, not the handler.

`BS_KEEP_PR=1` keeps the capture's real return address at the start of a free run;
`BS_FRAME_POKE=0C29B86C:02030203` remains available for scene-state experiments.

## New readable port on this path

- `0x8C0624BA` (`scene_clear_flag`): scans the 4,096-record scene object table at
  `0x0C16CF6C` (stride 24) and clears bit 0 of the record whose address is `r4`. Before the
  port the setup stopped with an unowned call in this helper; with it the probe is clean.
