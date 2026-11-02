# The port reaches further: the off-inventory holes and the host's pad

Date: 2026-11-01. Follows `docs/re/boot_attract.md` (the boot reaches the
attract fight) and `docs/re/plan_sdl3_port.md` (the phases).

## 1. The hole that stopped the boot was not closed - it was never wired

`docs/re/boot_attract.md` reported the boot's first unowned call:

```
vf3sdl: unowned call at 0c0ae97e (5 unowned, first 0c0ae97e)
```

and named the fix: a new module, `src/fight/vf3_offinv_adapter.c`, carrying the
off-inventory entry `0x8C0AE97E` (the Ghidra inventory never named it and no
`bsr` in the image points at it, so the guest reaches it through a function
pointer).

**The module existed but was never wired.**  It was in the working tree, with
its `claim_pcs[]` and its `_contains`, but:

* it was not in `CMakeLists.txt`'s source list, so it was not compiled at all;
* the router chain in `src/fight/matrix_family.c` had no line for it, so even
  a compiled module would never be dispatched to.

Two lessons, both worth writing down:

* **a module that is not in the chain serves nothing.**  The repo's own note
  (`docs/re/gap_dispatch_audit.md`) says the chain's *last* module has no
  `_contains` symbol and a scan that only looks for those calls its PCs a
  hole - the same trap in the other direction: a module the chain never
  reaches is dead code, and the PCs it claims are holes.
* **`tools/gap_holes.py` already said so.**  Its report listed
  `vf3_offinv_adapter.c` under "(not called by the router: ...)".  The report
  was right; the boot's hole was the confirmation.

With the module in the build and in the chain, the boot passed the hole - and
found the next one, `0x0C07AC6A`, at frame 999.

## 2. The second hole, the same way

`0x8C07AC6A` is another off-inventory entry: no module owns it, and eight
modules call it (`fight_adapters_2.c`, `target_retained_scene_adapters.c` and
six `away_batch` modules all carry `vf3_matrix_family(0x0c07ac6au, ...)`).

The repo's own translator translated it in one step:

```
python tools/oracle/translate_adapters.py extract/analysis/_empty_caps \
    --watch tools/watch/vf3_offinv_b02.txt \
    --out src/fight/vf3_offinv_b02_adapter.c \
    --function vf3_offinv_b02_adapter --reuse-adapter "src/fight/*.c"
```

```
21 guest statements; 0 unsupported instructions
```

The module claims exactly the one PC it may route (`claim_pcs[]` =
`{0x0c07ac6a}`) and owns its 21 instructions.

### The third hole

With the second module wired, the boot ran past `0x0C07AC6A` and stopped at
`0x0C0AAEBA` - the same shape of problem: five modules call it
(`fifth_adapters_2.c` and four `away_batch` modules) and *no* module owns it.
The translator again did the whole body in one step:

```
python tools/oracle/translate_adapters.py extract/analysis/_empty_caps \
    --watch tools/watch/vf3_offinv_b03.txt \
    --out src/fight/vf3_offinv_b03_adapter.c \
    --function vf3_offinv_b03_adapter --reuse-adapter "src/fight/*.c"
```

```
129 guest statements; 0 unsupported instructions
```

`claim_pcs[]` = `{0x0c0aaeba}` (one PC), `owned_pcs[]` = 129 PCs.

### The fourth hole, and the scenario that finds it

The third module's hole was found by a run **with the pad's button held down**
(`VF3_PRESS=8,0,900,1000`): the boot leaves the "press start" screen and
walks into code the plain boot never reaches.  That run stopped at
`0x0C0597BA`, at frame 417 - an entry no module owns and no module calls.

The body is tiny - a trampoline:

```
129 guest statements ... (the third)
2 guest statements; 0 unsupported instructions   (the fourth)
```

```
P_0c0597ba: target=r[16]; s->pc=target; return ram->oob==0;
P_0c0597bc: ... vf3_matrix_family(0x0c0597beu, ...) ...
```

It claims the two PCs it serves (`0x0c0597ba` and `0x0c0597bc`) and owns
them.

### The fidelity gate

`tools/gap_fidelity.py` checks the *gap* modules; the off-inventory modules
needed the same check, so `tools/check_offinv_modules.py` does it:

```
$ python tools/check_offinv_modules.py
vf3_offinv_adapter.c: 73 blocks checked
vf3_offinv_b02_adapter.c: 21 blocks checked
vf3_offinv_b03_adapter.c: 129 blocks checked
vf3_offinv_b04_adapter.c: 2 blocks checked
blocks whose opcode does not match the image: 0
```

Every emitted block's recorded opcode is the identity image's word at that
PC.  (The offset base is `0x0C010000` - the image's load address in the
guest's RAM - the same base `tools/gap_fidelity.py` uses; the first version
of the tool used `0x8C010000` and reported every block as outside the image.)

## 3. Where the boot stands now

| run | stops at | frame |
|---|---|---|
| before the wiring | `0x0C0AE97E` | 343 |
| with `vf3_offinv_adapter` wired | `0x0C07AC6A` | 1,145 |
| with `vf3_offinv_b02_adapter` wired | `0x0C0AAEBA` | (the pad held down) |
| with `vf3_offinv_b03_adapter` wired | `0x0C0597BA` | 1,197 (the plain boot), 417 (the pad held down) |
| with `vf3_offinv_b04_adapter` wired | (the next hole) | past 1,206 (the plain boot), past 448 (the pad held down) |

The port now runs the boot for **more than 1,206 frames** (20 s of game
time) before it meets code no module serves, against the 343 it reached
before.  Each hole costs one translation and one wiring, and the translator
does the body in one step every time.

The two scenarios are worth running together: the plain boot walks the
"press start" screen and the demo, and the boot with the pad's button held
down walks past it into the game's menus - and the holes are not the same
ones.

### Finding the next hole faster

The boot is slow: the host's rasteriser draws 650,000 pixels a frame in
software, and a frame carries 200,000 TA words to decode.  The guest's
dispatch does not depend on the picture, so `VF3_NORENDER=1` skips the TA
decode and the rasterisation:

```
$ VF3_NORENDER=1 build/vf3sdl.exe --state build/boot_new.state --entry 0x8c004000 \
      --gdi rom/vf3.gdi --frames 300 --headless
```

300 frames take 52 s that way, against roughly 10 minutes with the picture -
and the run finds the same hole.

The switch reads an empty value as "off" (`VF3_NORENDER=0` and
`VF3_NORENDER=` both draw the picture).  The first version asked only whether
the variable was set, and a run that asked for the picture with
`VF3_NORENDER=` got a black frame - which is a confusing way to learn that.

## 4. The host's pad: phase P6

The plan's P6 says "SDL3 gamepad -> the Maple/ADX packet the game reads (the
Maple model exists)".  The Maple model was already there; what was missing was
the host's end - the gamepad and the keyboard.

### The wire format

The guest never sees the host's device.  It asks the Maple model for the
pad's state (a GET_CONDITION request) and the model answers with the bytes
the hardware would put on the bus.  The format (docs/re/maple.md):

* the buttons are **active low**: a *zero* bit means the button is pressed and
  `0xFFFF` means nothing is pressed;
* the bit positions are the KOS numbering the reference emulator uses
  (`core/input/gamepad.h`: `DC_BTN_C` is bit 0, `DC_BTN_X` is bit 10);
* the axes are a byte each with `0x80` at the centre, the triggers are 0 at
  rest, and the second D-pad's axes read `0x80` (the reference's standard pad
  has none).

The reference's own pad forces the bits a standard pad has no button for (the
C and D buttons, the Z button and the second D-pad) to "released":
`maple_sega_controller::getButtonState` returns `kcode | 0xF901`.  The port
applies the same mask, so the guest sees what the reference showed.

### The code

* `src/host/dc_wire.h` - the wire's format and the mask, in one place, with
  `vf3_dc_wire_buttons()` (the host's pressed mask -> the wire's word).  It
  has no SDL dependency, so the test can use it.
* `src/host/sdl3_input.c` - the SDL3 layer: the gamepad (buttons and axes) and
  the keyboard (the arrows, `Z`/`X`/`C`/`A` and Enter).  It publishes a
  `vf3_maple_pad`.
* `src/fight/native_tick.c` - `vf3_native_set_maple_pad()`: the whole pad
  (the buttons **and** the analog axes) reaches the Maple model.  Before this
  the axes were hard-coded to the centre, because only the buttons had a
  setter.
* `src/sys/frame_events.c` - `vf3_frame_events_set_pad()`: the same state, one
  layer up.
* `src/host/sdl3_host.c` - the host polls the devices once a frame and
  publishes the pad **before** the guest's slice runs (the Maple model answers
  the guest's request during the run).

The script `VF3_PRESS=<mask>,<from>,<hold>,<period>` still works and wins
over the device, so a run stays reproducible without a human at the pad.

### The test

`tests/maple_input_replay.c` (`build/vf3mapleinput`) drives the Maple model
the way the guest does - a GET_CONDITION request in a transfer list - and
requires:

1. nothing pressed -> the word is `0xFFFF`;
2. every button the standard pad has -> its bit is the only zero one;
3. the C, D and Z buttons and the second D-pad -> always "released";
4. two buttons at once -> both zero;
5. the axes and the triggers -> in the answer's own bytes.

```
$ build/vf3mapleinput
maple_input_replay: the pad reaches the guest in the wire's format
```

**The test earned its keep twice.**  Its first version sent the GET_CONDITION
request with the wrong command (1 = the device request, not 9) and to the
wrong recipient (0x01 = the first card's slot, not the main unit's 0x20), and
it expected the C button to reach the guest - which the reference's mask
forbids.  All three were the test's mistakes, and the model was right.

### The host's own layer, and the chain end to end

The test above drives the Maple model, so the layer *above* it - the SDL3
event, the key map, the publication into the pad - was untested.  It is now
`tests/sdl3_input_replay.c` (`build/vf3sdlinput`): it feeds the input layer
synthetic SDL events and reads the pad back.

```
$ build/vf3sdlinput
sdl3_input_replay: the keyboard reaches the guest in the wire's format
```

It checks the arrows (the D-pad), `Z`/`X`/`C`/`A` (the A, B, X and Y
buttons), Enter (Start), two keys at once, a key the map does not know, and
the axes (centred, the triggers at 0).

The whole chain - the host's publication point to the guest's buffer - is
proved by the boot itself.  With `VF3_PRESS=8,0,900,1000` (Start held down
from the first frame) the port dumps its RAM, and the Maple answer the guest
read carries the pressed button:

```
recv=0c2b7800 hdr=03230008 buttons/trig=0000fff7 axes=80808080
recv=0c2b8400 hdr=03230008 buttons/trig=0000fff7 axes=80808080
```

`0xFFF7` is `~0x0008` with the reference's mask applied: the Start button is
the only zero bit, and the axes read `0x80` (the centre), the way an
untouched standard pad reads.

### The pad used to read as "everything pressed"

Publishing the pad every frame changed the boot's timeline, and the reason is
worth writing down: **the old host published the pad only when a script was
set** (`press_script()` returned early otherwise), so the Maple model kept the
value its own default had - `machine.maple_buttons` is a static field, and a
static field starts at **zero**.  The wire is active low, so a zero word
means *every button pressed*.

The boot therefore told the game that the player was holding every button,
and the game skipped the screens that wait for a press: the attract fight
appeared at **frame 343**.  With the pad published every frame (nothing
pressed, `0xFFFF`) the game plays the whole intro - the "SEGA Presents"
logo and the attract screen - and the attract fight arrives at frame ~1,145.

The 900 frame lines of the run before and after the change are **identical**
(`vf3sdl: frame N: ... TA words ... pixels ... guest instructions`), so the
host's timing did not change; what changed is what the guest is told about
the pad.  The old timeline was the bug.

## 5. What is next

* the holes the boot finds, one at a time, the way this one was found;
* **P5, the audio**: the AICA's PCM output.  The port has the AICA's register
  file and the sound RAM, but no PCM generator and no SDL3 audio stream - and
  the ARM7 (the sound CPU) is a model, not an interpreter, so the driver that
  would program the AICA's channels never runs.  The scope is measured in
  [`aica_audio_model.md`](aica_audio_model.md).
