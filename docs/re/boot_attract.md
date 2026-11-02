# The boot reaches the attract fight: the port renders the game

Date: 2026-10-31. Follows `docs/re/boot_arm7_wait.md` (the ARM7 model) and
`docs/re/boot_real_disc.md` (the real disc).

> **Correction (2026-11-01).**  The frame 343 this note reports was the boot
> with the pad read as *every button pressed* - the host published the pad
> only when a script was set, and the Maple model's default is the static
> field `machine.maple_buttons`, which starts at zero (the wire is active
> low).  The game therefore skipped the screens that wait for a press.  The
> host publishes the pad every frame now, so the boot plays the whole intro
> and the attract fight arrives at frame ~1,145 - and at frame 211 when the
> Start button is held down.  See
> [`boot_offinv_and_pad.md`](boot_offinv_and_pad.md).

## 1. Where the boot stood

With the ARM7 modelled (`src/fight/native_tick.c`: `AICA_REG_ARMRST`,
`aica_arm_boot()`), the loader stops waiting and walks the reference's file
ladder - 42 requests, the reference's 5..46, same FADs, same sizes, same
destinations (`tools/boot_reads.py`).  Then the port draws: 640x480, 176-248
Tile Accelerator words a frame, 8 lists, 10 primitives.

What was still missing was the *picture*.  The 150-frame frame was black
(0 of 307,200 pixels non-black) and the 210+ frame run was parked reading
`/BGM_VAN.BIN` (496 sectors, the reference's request 47).

## 2. The artifact

A 900-frame run, from the game's own entry (`--entry 0x8c004000`) with the
restored disc images and the boot state:

```
cd build
$env:PATH = "C:\msys64\ucrt64\bin;C:\Python\Scripts;" + $env:PATH
$env:VF3_GDTRACE="1"
& .\vf3sdl.exe --state .\boot_new.state --entry 0x8c004000 --gdi ..\rom\vf3.gdi \
    --frames 900 --headless --dump-frame .\boot900.ppm --dump-vram .\boot900.vram
```

The run stops at **frame 343** with `unowned call at 0c0ae97e` (the dispatch
hole of section 4), so `boot900.ppm` is the last frame it drew:

| property | value |
|---|---|
| size | 640 x 480 |
| non-black pixels | 305,496 / 307,200 (99.45%) |
| distinct colours | 6,111 |
| SHA-256 | `c218cc79ead6db5b5a161a9c1718279663d0d4ce8078e671ab3da982b471e316` |

The frame is the **attract fight**: the two fighters on the stone platform, the
mountain range and the pink sky behind them, the `AM2` logo bottom right and
the `SEGA 1997,1998` copyright bottom left.  The per-frame log says what the
Tile Accelerator was given:

```
frame 343: 148576 TA words ... 800530 pixels, 0 render starts, 1828618 guest instructions
  stream 148576 words (16370 blocks): parsed, 7 lists, 839 primitives
    (522 polygons, 7 sprites, 310 modvols, 527 textured), 0 skipped
```

## 3. The comparison with the reference

The reference recorded the same game in a raw RGB video
(`extract/analysis/p1/probe.raw`, 1,335 frames of 640x480).  The two are not
frame-aligned by construction, so the comparison searches for the frame that
matches:

```
python tools/port_frame_match.py --ours build/boot900.ppm \
    --ref extract/analysis/p1/probe.raw --tolerance 24 --out build/match900.ppm
```

```
extract\analysis\p1\probe.raw: 1335 frames of 640x480; scanning 0..1334
tolerance 24 levels
  frame   132:  87.28% of the pixels within 24, mean error  14.08, worst channel 255
  frame   133:  83.27% ...
  frame   131:  81.94% ...
```

**87.28%** of the pixels are within 24 levels of the reference's frame 132
(3,022 of 8,400 pixels of the `Press Start Button` box apart; 88.72% with
that box excluded - `tools/pvr2_frame_diff.py` for the per-pixel count,
`build/frame_diff_rows.py` for the per-row split).

The two frames are the **same camera shot**: the same two fighters, the same
postures, the same angle, the same stage.  The one visible difference is the
reference's `Press Start Button` overlay, which the port's frame does not
have - the port reached the attract loop a few frames earlier, before the
prompt was drawn.

For the record, the previous number on this axis was **95.48%**, measured
against the *saved-state* attract fight (`docs/re/boot_vram_traffic.md`,
`frame 154 of probe.raw`).  That is a different scenario (the reference's log
loads a save state of the already running game, not a boot), and it is not a
regression: 87.28% is the first measurement of the **boot** against the
reference, and the boot has to get from the memory-card screen through the
whole file ladder to the attract loop, where the reference's recording starts
in the middle of the fight.

## 4. The dispatch hole the boot found

The boot's last frame also produced the port's first **unowned call**:

```
vf3sdl: unowned call at 0c0ae97e (5 unowned, first 0c0ae97e)
```

`0x8C0AE97E` is a function the Ghidra inventory never named:

* it is **not** a baseline entry (the neighbours are `f_8c0ae6f6` and
  `f_8c0ae9f6`);
* **no `bsr` in the whole image points at it** (`build/find_callers_of.py`:
  0 direct call sites) - the guest reaches it through a **function pointer**, so
  the inventory's call graph never saw it;
* it is a real function: `mov.l @r6,r2; add #-8,r15; mov.l @(4,r6),r3;
  cmp/eq r3,r2` is a prologue that compares two words of the object at `r6`.

So the router had nowhere to send the call and the port stopped.  The fix is
the repo's own translator on a new root: `src/fight/vf3_offinv_adapter.c`
(73 guest statements, 0 unsupported instructions, one claimed PC:
`0x0c0ae97e`).

## 5. The tool that finds the holes

`tools/gap_holes.py` answers the general question - *which code the reference
executed does the port not implement?*  It takes the union of the capture
maps' PCs (13,374 maps, 191,004 distinct PCs), subtracts the PCs the router's
modules implement (the `P_` labels of the modules the chain calls, plus the
readable ports' entries) and prints the rest:

```
capture maps: 13374, distinct executed PCs: 191004
modules the router calls: 441, PCs they implement: 323089, of them dispatchable: 113084
  (not called by the router: fight26_mod.c)
  (not called by the router: seventh_final_adapters.c)
executed PCs the router cannot serve: 8437
```

8,437 PCs of the reference's executed code are still not implemented.  They are
not all dispatch holes - most are the two-byte-misaligned entries Ghidra
missed (a function whose real first instruction is two bytes before the
inventory's entry, so the inventory's body range starts inside it) and the
REIOS' own BIOS vectors (`0x0c001000..0x0c001006`, which the BIOS stub owns,
not the matrix router).  The list is the work list for the next dispatch
pass; `tools/gap_holes.py --watch-out <file>` writes it as a translator watch
file.

## 6. What is next

* The 8,437 PCs of section 5: the off-inventory entries have to be translated
  and wired in, the way `0x8C0AE97E` was.
* The `Press Start Button` overlay: the port's attract loop reaches the fight
  before the prompt is drawn; whether the prompt is a timing difference or a
  missing draw is open.
* The boot itself still starts at the game's own entry, not at the REIOS: the
  first five requests of the reference's ladder (the REIOS' own reads) are
  still not made by the port.
