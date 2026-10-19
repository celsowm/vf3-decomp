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

## Remaining gap in the natural boot run

The boot continuation's loader pass reaches the frame loop only after the vblank cap
(1,506/1,516 vblanks in the 1,500-cap runs); by then the scene context is state 3 /
sub-state 3 and the drive is idle. The setup (sub-state 2) is not re-entered, so the natural
run issues no CP_LOGO read. The direct probe demonstrates the handler; the next step is to
preserve the scene sub-state 2 across the loader pass (or dispatch the sub-state-2 handler at
the frame-loop entry) and verify the request inside the frame loop.

`BS_FRAME_POKE=0C29B86C:02030203` writes the scene word (state 3, sub-state 2) at the
frame-loop entry. The state-25 1,500-vblank run applies the poke at vblank 1516, but the
frame-loop body's first call chain still hands back to the sentinel before the scene
dispatcher; no GD read follows. The frame-loop entry needs the real caller stack (the
prologue is before `0x8C095CC2`), so the poke alone is not enough.

## New readable port on this path

- `0x8C0624BA` (`scene_clear_flag`): scans the 4,096-record scene object table at
  `0x0C16CF6C` (stride 24) and clears bit 0 of the record whose address is `r4`. Before the
  port the setup stopped with an unowned call in this helper; with it the probe is clean.
