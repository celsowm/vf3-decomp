# The mpdrv's device table: two fills, and the one the port never runs

Measured on 2026-10-27 against the reference captures in
`extract/analysis/p1/frm_keep/` and the port's own boot
(`build/vf3sdl.exe --state build/boot2.state --entry 0x8c004000 --gdi rom/vf3.gdi`).

The memory card check never passes in the port because the mpdrv's *device
table* is empty when the game asks about it.  This note records what the
table is, who fills it, and which fill the port misses.

## What the table looks like

| address | size | what |
|---|---|---|
| `0x0C1B24C0` | `0x1000` | the mpdrv's scratch area; `memset(base,'0',0x1000)` at `0x0C04C11E` |
| `0x0C1B3400` | `0xC0` | four device descriptors, `0x30` bytes each |
| `0x0C1B34B0` | `0x28` | the tail struct: `+4` = attach callback, `+8` = queue, `+0xC` = the "0000" version |
| `0x0C1B34D4` | `4` | pointer to `0x0C1B34C0` |
| `0x0C1B34D8` | `0xA40` | the device table: eight slots of `0x148` bytes |

The reference at frame 40 (`st.bin.000040`) has slot 0 filled and slots 1..7
zero; the port has the same slot 0 **except** four fields, and the descriptor
block still holds the `'0'` fill:

```
slot 0 (0x0C1B34D8)   reference      port (frame 22)
+0x00  00 00 01 00    00 00 01 00   (same)
+0x08  01 01 01 01    00 00 00 00   <-- differs
+0x0C  01 00          00 00         <-- differs
+0x10  01 00 0D 00    01 00 0D 00  (same)
+0x1C  38 7F 1B 0C    38 7F 1B 0C  (same)
+0x30  12 00 00 00    00 00 00 00   <-- differs
+0x34  11 00 00 00    00 00 00 00   <-- differs
```

`+0x30` is the device count (18) and `+0x34` the current device number (17);
the driver's own record at `0x0C19C6A0` carries the same 17 at `+0x08`.

## Two different fills

The mpdrv has **two** functions that write the table, and they are not the
same code:

* `0x0C04C750` — the *per-device* fill.  It switches on the device type
  (`15`, `33`, `65`, `122`), writes the record's pointers (`+0x1C` ..
  `+0x2C`), and clears the slot with two `memset`s of its own
  (`0x0C04C882` clears 16 bytes, `0x0C04C88C` clears 256).
* `0x0C04C9A2` — the *enumeration* fill.  It multiplies the index by `0x148`
  and adds the base `0x0C1B34D8` (`0x0C04C9C4`, `0x0C04C9CE`), which is the
  stride and base the table actually has.  This is the one that writes the
  descriptor block and the `+0x30`/`+0x34` counters.

The reference runs both.  The port runs only the first:

```
$ VF3_TRACE_ENTRIES=1 VF3_TRACE_ONLY=0c04c9a2,0c046e14,0c04c750,0c0371bc \
  build/vf3sdl.exe ... --frames 60 --headless
enter 0c0371bc pr 0c09598a ...
enter 0c04c750 pr 0c04c686 r4 0000000f r5 00000001 r6 0c198880 r7 00000a40
leave 0c04c750 ok 1 r0 00000000 pc 0c04c686
leave 0c0371bc ok 1 r0 00000000 pc 0c09598a
```

`0x0C04C9A2` is entered through the stub `0x0C046E14`, and the reference's
own recorded trace proves the path:

```
extract/analysis/target_extended_a_dev/.../f_8c046e14.ops.json
  0c046e14..0c046e22   0c046e2c..0c046e32   0c04c9a2..0c04c9ba
  0c04ca24..0c04ca28   0c04cb2e..0c04cb3c
```

The stub is reached from `0x0C046E16` (`mov.l @(14,PC),r3` with the pool
value `0x0C04C9A2`), and `0x0C046E14` itself has **no literal reference and
no direct branch anywhere in the image** — it is called through an indirect
target the mpdrv computes at run time.  The port never gets there.

## The order matters as much as the fill

`0x0C04CB3E` is the mpdrv's reset:

```
8c04cb46  mov.l 0x8c04cbc0,r4  # lit=0c1b34d8
8c04cb4a  mov.l 0x8c04cba4,r3  # lit=0c04b9e4      (the byte fill)
8c04cb4c  mov.w 0x8c04cb9c,r6  # lit.w=0a40
8c04cb4e  jsr @r3                                  (memset(0x0c1b34d8, 0, 0xa40))
8c04cb50  _mov #0,r5                               (the delay slot sets the value)
```

It wipes the table.  The reference runs it too - `f_8c0463ee.ops.json` has
`0c04cb3e..0c04cb5c` - but **before** the fill, so the table survives to
frame 1600.  The port runs it **after** the fill, fourteen times, and the
table is empty at frame 300.

The reference's own timeline shows the switch happening inside the first
40 frames of the capture:

```
st.bin.000000  tab30=0  tab34=0  rec00=0 rec02=0
st.bin.000040  tab30=18 tab34=17 rec00=1 rec02=1
...  (stable to st.bin.001600)
```

so the reference's order is *reset → init → fill*, and the port's is
*init → fill → reset*.

## The attach path that depends on it

The Maple callback `0x0C0371AA` queues the attach handler (`0x0C0370F0`) and
the store handler (`0x0C037190`); the queue lives at `0x0C1B20C0`, eight
entries of `0x80` bytes, with the handlers at `+0x74` and `+0x78` and the
device number at `+0x7C`.  The queue processor `0x0C04C3A0` tail-calls
`queue[index]+0x74` with `r7 = queue[index]+0x7C`, and the attach handler
only sets `record[+0] = 1` when `r5 == 1 && r6 == 0`; `record[+2] = 1`
(the "usable" bit the card check reads) needs the lookup `0x0C04667A` to
succeed, and that lookup walks the table - so it fails while the table is
empty.

Reference record `0x0C19C6A0` at frame 40:
`+0=1 +2=1 +4=0 +8=17 +0xC=17 +0x10=0 +0x14=0xFFFFFF01 +0x18=100`.
Port at frame 300:
`+0=0 +2=0 +4=0 +8=8 +0xC=17 +0x10=1` - the store handler ran (with
`r6=8` instead of `17`), the attach handler's conditions never held.

## SH-4 facts this investigation turned up

* **The delay slot runs before the call takes effect, and it can change the
  arguments.**  `0x0C04C882` is `jsr @r12` with the delay slot
  `add #56,r4` at `0x0C04C884`, so the byte fill receives `r4 = r14+56`
  and not `r14`.  Reading the fill's source without the delay slot gives the
  wrong destination for two of its three clears.
* **`bf/s` branches when `T == 0`** (it is "branch if false"), and the
  translator's `bf`/`bt` naming follows the reference's own disassembly:
  `0x8F07` is `bf/s`, `0x8D34` is `bt/s` (see `tools/sh4.py`).
* **A call through a literal-pool register is a real call.**  The earlier
  claim that `0x0C04C60A` is unreachable was wrong: `0x8C046360` does
  `mov.l @(14,PC),r3` (pool value `0x0C04C60A`) and `0x8C046366` does
  `jsr @r3`.  A scan that only looks at direct `bra`/`bsr` misses it; use
  `tools/find_literal_ref.py` for the pool side and read the call site.
* **`mov.l Rm,@(disp,Rn)` has `EA = Rn + disp`** (no scale), so
  `mov.b r0,@(2,r14)` is `r14+2` and `mov.l r13,@(4,r5)` is `r5+4`.

## Tools

* `tools/find_literal_ref.py` - fixed: the PC-relative base is
  `((pc+4) & ~3) + disp*4` with the 8-bit displacement signed, and the
  image loads at `0x0C010000`.
* `tools/state_ram.py` - pulls a 16 MiB RAM window out of the reference's
  `st.bin.*` captures (the `0xFA50` window list) so the reference's memory
  can be compared with the port's.
