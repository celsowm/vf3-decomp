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

## Where the port actually breaks (measured, frame by frame)

The port's table is *right* for a while - the reset is what kills it.  Dumping
the port's RAM at the end of each frame shows:

| frame | what the port did | table slot 0 at 0x0C1B34D8 |
|---|---|---|
| 22 | the mpdrv init and the fill | `+8 = 0`, `+0x34 = 0` |
| 23-31 | the device check (9 rounds) | `+8 = 1`, `+0x34 = 17` - **as the reference** |
| 32+ | the reset chain, 14 times | the whole table zeroed |

At frame 31 the port's slot 0 reads

```
+0x00 00 00 01 00 00 00 00   +0x08 01 01 00 00 00 00 01 00
+0x10 01 00 0d 00 20 00 00 00   +0x18 00 00 00 00 38 7f 1b 0c
+0x30 0a 00 00 00 11 00 00 00
```

against the reference's

```
+0x00 00 00 01 00 00 00 00   +0x08 01 01 01 01 01 00 01 00
+0x10 01 00 0d 00 20 00 00 00   +0x18 00 00 00 00 38 7f 1b 0c
+0x30 12 00 00 00 11 00 00 00
```

so the pointers, the device number (+0x34 = 17) and the lookup's gate
(+8 = 1) all match.  What is still missing is the attach.

### The attach never happens

The attach handler is `0x0C0370F0`; the queue processor that calls it is
`0x0C04C3A0`:

```
8c04c3a0  mov r4,r14 ; shll2 x3 ; shll        ; r14 = index * 0x80
8c04c3ae  mov #116,r0                        ; 0x74
8c04c3b0  add r3,r14                         ; r14 = 0x0c1b20c0 + index*0x80
8c04c3b2  mov.l @(r0,r14),r2                 ; r2 = queue[index]+0x74
8c04c3b4  tst r2,r2
8c04c3b6  bt 0x8c04c3c2                      ; no handler -> return
8c04c3b8  _mov.l @(r0,r14),r2
8c04c3ba  mov #124,r0                        ; 0x7c
8c04c3bc  mov.l @(r0,r14),r7                 ; r7 = queue[index]+0x7c
8c04c3be  jmp @r2                            ; tail call the attach handler
```

The handler only sets `record[+0] = 1` when `r5 == 1 && r6 == 0`, and
`record[+2] = 1` (the "usable" bit the card check reads) only when the
lookup `0x0C04667A` succeeds - and the lookup ends at

```
8c04d56c  mov.l 0x8c04d680,r3  # lit=0c1b34d8
8c04d56e  add r3,r2
8c04d570  mov.b @(8,r2),r0     ; the slot's +8
8c04d572  tst r0,r0
8c04d574  bf 0x8c04d57c        ; +8 == 0 -> "not found"
8c04d576  mov.w 0x8c04d676,r0  # lit.w=ff01
```

so the gate is `slot[+8] != 0`.

The port's router trace shows the handler is never entered:

```
$ VF3_TRACE_ONLY=0c04c3a0,0c0370f0,0c037190,0c04c3c6,0c046406,0c04be44
enter 0c04c3c6 ... r4 0 r5 1 r6 1 r7 0x11     (the store dispatcher)
enter 0c04be44 ... r5 0x0c1b7f38 r7 0x11     (the device check)
enter 0c04c3c6 ... r6 2 ...                   (and again, 3, 4, ...)
```

`0x0C0370F0` never appears.  The port's queue entry 0 still holds its
`+4 = 1` at frame 31 while the reference's queue is empty at frame 40 - the
port never consumes it.

The port's per-port probe is `0x0C046AEE`, and its answer is the queue
entry's `+4`:

```
8c046aee  sts.l pr,@-r15
8c046af0  mov.l 0x8c046cb0,r3  # lit=0c04c47c
8c046af2  jsr @r3
8c046af4  _nop
8c046af6  tst r0,r0
8c046af8  bt 0x8c046b00        ; present -> r0 = 0
8c046afa  lds.l @r15+,pr
8c046afc  rts
8c046afe  _mov #-1,r0          ; absent -> r0 = -1
```

and `0x0C04C47C` returns `queue[index]+4` from the **delay slot** of its own
`rts` (`0x0C04C48A: mov.l @(4,r4),r0`).

## Why the attach never happens (measured, 2026-10-27 evening)

Two independent things keep the attach handler from running, and both are
visible in one trace.

### 1. The queue is wiped after the handlers were registered

The Maple callback `0x0C0371AA` registers the two handlers in the request
queue (`0x0C1B20C0`, eight entries of `0x80` bytes):

```
8c0371aa  sts.l pr,@-r15
8c0371ac  mov.l r3 = 0x0c046576      ; the enqueue
8c0371ae  mov.l r4 = 0x0c0370f0      ; the attach handler
8c0371b0  jsr @r3
8c0371b4  mov.l r2 = 0x0c04657c      ; the enqueue
8c0371b6  mov.l r4 = 0x0c037190      ; the store handler
8c0371b8  jmp @r2
```

The enqueue (`0x0C04C434`, `0x0C04C44C`, `0x0C04C464`) writes the handler into
**all eight** entries, at `+0x74` (attach), `+0x78` (store) and `+0x7C` (the
device number) - the loop walks `r5 = 0x0C1B20C0 + i*0x80` and stops after
`r6 >= 8`.  The port does it correctly (`VF3_WATCHW=0C1B20C0,400` shows the
eight writes of `0x0C0370F0` and the eight of `0x0C037190`), and the reference
has exactly that at frame 40:

```
0C1B2130  00 00 00 00 f0 70 03 0c 90 71 03 0c 00 00 00 00   entry 0
0C1B21B0  00 00 00 00 f0 70 03 0c 90 71 03 0c 00 00 00 00   entry 1
...   (all eight entries carry the two handlers)
```

The mpdrv's **reset** wipes the queue, though:

```
8c04c14a  sts.l pr,@-r15
8c04c14c  mov.l r3 = 0x0c04b9e4      ; the byte fill
8c04c14e  mov.l r4 = 0x0c1b20c0      ; the queue
8c04c150  mov.w r6 = 0x0400
8c04c152  jsr @r3
8c04c154  _mov #0,r5                 ; the delay slot carries the value
8c04c156  lds.l @r15+,pr
```

and the reset chain `0x0C0463EA` calls it (`0x0C0463FA: mov.l r3 = 0x0c04c14a`)
right before the table reset `0x0C04CB3E`.  In the port that reset runs
**fourteen times** - the game resets the driver once per device it
enumerates - and it is the reason the port's queue is empty at frame 300
while the reference's still carries the handlers.  At the *device check*,
which happens before those resets, the handlers are still in place, so this
is not what blocks the attach (but it is why the port cannot recover once
the check has failed).

In the reference the handlers are still there at frame 1600, so its
registration is the last thing that touched the queue.

### 2. Neither dispatcher ever calls its handler

The two dispatchers are the only way into the two handlers (the image holds
exactly one pointer to `0x0C0370F0`, the pool word at `0x0C037210` of the
Maple callback, and one to `0x0C037190`).  In the port:

```
attach dispatcher 0x0c04c3a0   entered 0 times
store  dispatcher 0x0c04c3c6   entered 8 times
attach handler    0x0c0370f0   entered 0 times
store  handler    0x0c037190   entered 0 times
```

So the store dispatcher runs eight times and *still* leaves the queue's
`+0x78` (the store handler) untouched - it reads it and returns.  The state
at the dispatcher's own entry is

```
mpdrv mask prev 00000001 cur 00000001 new 00000000 retry 00000000
| slot +8 00 +30 00000003 +34 00000011
| queue +4 00000001 +8 00000001 +74 0c0370f0 +78 0c037190 +7c 00000000
```

so the handler *is* in the queue at that moment.  The dispatcher's own code
is faithful (it reads `queue[port]+0x78` and jumps to it when it is not
zero), so the jump is not taken - and the next question is why.

The device check `0x0C046406` has two loops over the bus masks.  The first
one handles the devices that *appeared* (`(prev ^ cur) & cur`) and calls the
register-device function `0x0C046594`, which writes `queue[port]+8 = 1` and
then calls `0x0C04C49C`, the function that records the device (it writes
`queue[port]+4 = 1` in the delay slot of its `rts` and `+0x14 .. +0x28` with
the device's data).  The second loop handles the devices that *disappeared*
(`(cur ^ prev) & prev`) and calls the **attach** dispatcher with `r5 = 2`,
`r6 = 0`.

In the port that registration call carries **no data at all**:

```
enter 0c046594 pr 0c0464d6 r4 00000000 r5 0c19e998 r6 00000018 r7 00000018
enter 0c04c48c pr 0c0465b0 r4 00000000 r5 00000001 r6 00000018 r7 00000018
enter 0c04c49c pr 0c0465c4 r4 00000000 r5 00000000 r6 00000000 r7 00000000
```

`r5 = r6 = r7 = 0` and the three stack words are zero, so the table slot
keeps the reference's first two bytes (`01 01`) but not the three that follow
(`01 01 01` in the reference, `00 00 00` in the port).  The reference's queue
entry 0 is zero apart from the two handlers, so the reference never
registered a device in the queue at all - its table slot was filled by the
per-device fill `0x0C04C750` from the Maple answer.

The probe's polarity is worth spelling out, because `tst` sets T when the
result is **zero** and `bt` branches when T is 1:

```
8c046aee  sts.l pr,@-r15
8c046af0  mov.l r3 = 0x0c04c47c      ; queue[index]+4
8c046af2  jsr @r3
8c046af6  tst r0,r0                  ; T = (r0 == 0)
8c046af8  bt 0x8c046b00             ; taken when r0 == 0 -> "present"
8c046afa  lds.l @r15+,pr
8c046afc  rts
8c046afe  _mov #-1,r0                ; r0 != 0 -> "absent"
8c046b00  mov #0,r0
```

### The enumeration path the port never reaches

`0x0C046E14` is the stub that runs the enumeration fill `0x0C04C9A2` and then
registers the device it found (`bra 0x8c046594`):

```
8c046e14  sts.l pr,@-r15
8c046e16  mov.l r3 = 0x0c04c9a2
8c046e1a  jsr @r3
8c046e1c  _mov.l r4,@r15
8c046e1e  mov r0,r4
8c046e20  tst r4,r4
8c046e22  bf 0x8c046e2c
8c046e28  bra 0x8c046594
```

The stub has **no literal reference and no direct branch anywhere in the
image** (a scan of the image for the pointer `0x0C046E14` finds nothing), so
the mpdrv computes the target at run time - and the port never gets there.
The reference's own recorded trace shows that path
(`extract/analysis/target_extended_a_dev/.../f_8c046e14.ops.json`:
`0c046e14..0c046e22`, `0c046e2c..0c046e32`, `0c04c9a2..0c04c9ba`,
`0c04ca24..0c04ca28`, `0c04cb2e..0c04cb3c`).

### The Maple model is right (checked against the reference)

The port's framing matches Flycast's exactly.  `SB_MMSEL` is 1 after a reset
(`core/hw/maple/maple_if.cpp:374`), so `swap_msb` is false and nothing is byte
swapped; the reply header is built as
`resp | send << 8 | reci << 16 | (outlen/4) << 24`
(`core/hw/maple/maple_devs.h:292`), and the port builds the same word:

```
maple: block at 0c2c3820 head 00000000 recv 0c2b7800 frame 00002001
maple:   -> reply 1c230005 at 0c2b7800 (28 words)
```

`0x00002001` is the frame header (command `0x01` = DEVINFO, recipient `0x20` =
the main unit, sender `0x00`); the reply `0x1C230005` is code 5, sender 0,
recipient `0x20 | 0x03` (the main unit with the two attached cards) and 28
words of status.

The 112 bytes of status match Flycast's VMU answer byte for byte
(`core/hw/maple/maple_devs.cpp:490` - `MDC_DeviceRequest`/`MDC_AllStatusReq`):
the function mask `MFID_1_Storage|MFID_2_LCD|MFID_3_Clock`, the three
function words `0x403f7e7e / 0x00100500 / 0x00410f00`, the area byte `0xFF`,
the direction byte `0`, the 30-byte name, the 60-byte brand and the two
current words `0x007c / 0x0082`.  So the card's answers are right; what the
mpdrv does with them is not.

### The lookup has two gates

The lookup `0x0C04667A` (-> `0x0C04D50C`) checks the slot twice:

```
8c04d52a  add r3,r13              ; r13 = the slot (base + index * 0x148)
8c04d534  mov.b @(2,r13),r0       ; the slot's byte +2
8c04d536  tst r0,r0
8c04d538  bt/s 0x8c04d576         ; byte +2 != 0 -> found
...
8c04d56e  add r3,r2               ; r2 = the slot
8c04d570  mov.b @(8,r2),r0        ; the slot's byte +8
8c04d574  bf 0x8c04d57c           ; byte +8 == 0 -> "not found"
8c04d576  mov.w r0 = 0xff01       ; found
```

The reference's slot 0 has `01` at both `+2` and `+8`; the port's has `01` at
`+2` and `01` at `+8` from frame 31 on (before that `+8` is 0), so the lookup
itself is not what fails in the port - the attach handler is simply never
called.

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
* **`tst` sets T when the result is zero, and `bt` branches when T is 1.**
  The SH-4's T is the zero flag, not a "true" flag, so
  `tst r0,r0 ; bt label` branches when `r0 == 0`.  The probe's polarity
  depends on it.

## Tools

* `VF3_TRACE_ONLY=0c046406,0c04c3a0,0c04c3c6` with `VF3_TRACE_ENTRIES=1`
  prints the mpdrv's state at each of those entries: the two bus masks, the
  two "changed" sets, the first slot of the device table and the first entry of
  the request queue (`src/fight/native_tick.c`, `trace_mpdrv`).
* `tools/find_literal_ref.py` - fixed: the PC-relative base is
  `((pc+4) & ~3) + disp*4` with the 8-bit displacement signed, and the
  image loads at `0x0C010000`.
* `tools/state_ram.py` - pulls a 16 MiB RAM window out of the reference's
  `st.bin.*` captures (the `0xFA50` window list) so the reference's memory
  can be compared with the port's.
