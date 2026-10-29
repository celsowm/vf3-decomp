# The SDK service pointer: it is installed, and then the game tears the module down (2026-10-29)

`docs/re/mpdrv_device_table.md` recorded that the SDK's service pointer
`[0x0C0EA314]` is zero in the port's boot and `0x0C0EA284` in the reference,
and concluded that the mpdrv's thread was never created.  **That diagnosis was
wrong, and this note corrects it.**  The pointer *is* installed, with the
reference's exact values; what differs is what the game does afterwards.

Everything below was measured on the port's own boot
(`build/vf3sdl.exe --state build/boot2.state --entry 0x8c004000 --gdi rom/vf3.gdi
--bios tools/emu/flycast-ref-build/data/dc_boot.bin --frames 45 --headless`)
and on the reference's own capture (`extract/analysis/p1/frm_keep/st.bin.000040`).

## The writer and the reader of `[0x0C0EA314]`

The image's literal pool holds the address exactly twice:

| pool slot | value | loaded by |
|---|---|---|
| `0x0C035D60` | `0x0C0EA314` | 23 dispatchers in `0x0C035B1E..0x0C035D4A` and the register/unregister trampolines |
| `0x0C035D90` | `0x0C0EA314` | `0x0C035D78` |

The only *writer* is the trampoline at `0x0C035B60`:

```
0c035b6e  r14 = 0x0C0EA310                 ; the pool at 0x0C035D64
0c035b70  r3  = [r14]
0c035b74  if (r3 == 0) {                   ; not installed yet
0c035b76    r3  = 0x0C0462D4              ; the caps lookup
0c035b78    r4  = 0x0C0EA300              ; the 4-word key
0c035b7a    jsr @r3                       ; -> the lookup returns the descriptor
0c035b80    [r14] = r0                    ; [0x0C0EA310] = the descriptor
0c035b8e    r3  = 0x0C046310
0c035b90    jsr @r3                       ; delay slot: r4 = [0x0C0EA310]
0c035b94    r2  = 0x0C0EA314
0c035b96    [r2] = r0                     ; [0x0C0EA314] = the vtable
0c035b98    ...                           ; the normal path: [r3+12] is the service
```

The caps lookup (`0x0C0462D4`) walks one 32-byte entry at `0x0C0EA260` and
compares the entry's `+16..+28` (the four magic words at `0x0C0EA270`) with the
key at `0x0C0EA300`; on a match it returns the entry, `0x0C0EA260`.
`[0x0C0EA260]` is the vtable pointer `0x0C0EA284` - which is exactly what the
dispatchers need, because they call `[r3+12]`, `[r3+16]`, ... with
`r3 = [0x0C0EA314]`.

**The unregister trampoline is `0x0C035BC6`**, and it is the mirror image:

```
0c035bd6  jsr @r0                         ; the service's "close" slot
0c035be2  r2 = 0x0C0EA310
0c035be6  [r2] = 0                        ; [0x0C0EA310] = 0
0c035be8  r3 = 0x0C0EA314
0c035bea  [r3] = 0                        ; [0x0C0EA314] = 0
```

## The port installs the pointer, with the reference's values

`VF3_WATCHW=0c0ea310,8` logs every write to the two words.  The boot writes
**four** times, and only two of them are the installation:

```
watchw 0c0ea310/4 = 0c0ea260     ; the lookup's result (the descriptor)
watchw 0c0ea314/4 = 0c0ea284     ; the vtable
watchw 0c0ea310/4 = 00000000     ; the unregister
watchw 0c0ea314/4 = 00000000     ; the unregister
```

The reference's capture holds the same two values (`[0x0C0EA310] = 0x0C0EA260`,
`[0x0C0EA314] = 0x0C0EA284`), so **the port's installation is byte-identical to
the reference's**.  The earlier note measured the *end* of the boot, after the
game had already torn the module down, and read the zeros.

The frame-by-frame sweep (`--dump-ram` at 2, 3, 4, 6, 8, 12, 20, 30, 45 frames)
shows the whole life cycle:

| frame | `[0x0C0EA310]` | `[0x0C0EA314]` | `[0x0C0EA79C]` (the "busy" flag) |
|---|---|---|---|
| 2..20 | 0 | 0 | 0 |
| 22 | `0x0C0EA260` | `0x0C0EA284` | 1 |
| 30 | `0x0C0EA260` | `0x0C0EA284` | 1 |
| 45 | 0 | 0 | 0 |

At frame 30 the port's mpdrv is **alive and identical to the reference**: the
service pointer is installed, the "busy" flag says the driver is running, and
the per-unit entries at `0x0C1A1A90` are the reference's
(`00020005, 1, 1, 0, 0, 0x0C198880`).

## What the game does at frame 31

The unregister comes from the game's **teardown** routine at `0x0C096864`:

```
0c09686c  r3 = 0x0C035CA4      ; the "create thread" service
0c09686e  jsr @r3
0c096872  r14 = r0              ; the thread handle
0c096874  if (r14 != 0) {
0c096878    r3 = 0x0C035A4E    ; "start the thread"
0c09687a    jsr @r3
0c09687e    r2 = 0x0C0355A0    ; "delete the thread"
0c096880    jsr @r2
            }
0c09688c  ldc r0,sr            ; the interrupts back on
0c09688e  r2 = 0x0C0371E6      ; the mpdrv's reset (0x0C0463EA)
0c096890  jsr @r2
0c096894  r1 = 0x0C035BC6      ; the unregister
0c096896  jsr @r1
```

The trace shows this routine **14 times** (seven `(name, 1)` pairs - the game's
module list), each with its own "create thread" and "reset", and then the
unregister that clears the two pointers.  In other words: **the game is
shutting the module down, not failing to start it.**

At frame 32 the port's display list goes empty (`0 TA words`), which is the
message screen the port has been showing - the "A Memory Card or enough free
blocks for saving could not be found" screen of `docs/re/card_check.md`.

So the chain is:

1. the boot reaches the game's runtime and registers the mpdrv service
   correctly (frame 22) - the port and the reference agree byte for byte;
2. the card check fails (the card is never attached: the driver's record at
   `0x0C19C6A0` keeps `+0 = 0`), the game decides it cannot continue;
3. the game tears the module down (frame 31) and shows the message screen.

**The service pointer was never the blocker.**  The card check is
(`docs/re/card_check.md`), and the mpdrv's teardown is its *consequence*.

## Two corrections to the record

* **The boot does reach the game's C runtime.**  The router sees the entry
  `0x0C020000` (the masked form of `0xAC020000`), which is the runtime's
  `_start`: it clears the bss, loads `VBR`/`SP` and zeroes the registers.  The
  port then calls the REIOS' system vector (`0x0C001000`) and the flashrom
  vector (`0x0C001004`) exactly as the game does.  The earlier note's
  "the port never executes the game's C runtime" was wrong: the addresses it
  used (`0x0C010000`, `0x0C010100`, `0x0C010170`) are the *copy stub* at the
  head of the image and the entry it jumps to, not the runtime.
* **The reference's boot never reads the disc** (`docs/re/ref_clean_boot.md`),
  so the file ladder is not what the boot needs.

## A lead in the translator: the `rts` block carries the next instruction

`tools/oracle/translate_adapters.py` emits an `rts` like this:

```python
elif w==0xB:
    lines.append('target=r[16];'); lines.extend(statements(a+2)); lines.append('s->pc=target; return ram->oob==0;')
```

`statements(a+2)` is the *next* instruction, and an `rts` has no delay slot -
the copy looks like a leftover from the branch handlers, where the delay slot
*is* the next instruction.  In the generated modules the block of an `rts`
therefore carries the next instruction's semantics:

```
P_0c046310: /* original 000b, guest PC 0x0c046310 */
target=r[16];
tmp=read(ram,r[4],4);      <-- the instruction at 0x0c046312
r[0]=tmp;
s->pc=target; return ram->oob==0;
```

The scope is wide: **2,395 of the image's 3,329 `rts` sites are followed by an
instruction that is not a `nop`**, so the merge is not invisible.

It is *not* yet a proven defect: at the one site where the reference's ground
truth is available (`0x0C046310`, the helper of the register trampoline) the
merged behaviour is exactly what the reference's RAM shows
(`[0x0C0EA314] = 0x0C0EA284`, the vtable), while a literal `rts` would leave
`0x0C0EA260` (the descriptor) and make every dispatcher call through
`[0x0C0EA26C] = 0`.  **So the image's `rts` at `0x0C046310` and the caller's
expectation disagree, and the translator's merge papers over it.**  Either the
SH-4's `rts` is not the only instruction of that function, or the caller's
target is off by one word.  That has to be settled against the hardware
before anything is regenerated - `docs/re/uncached_call.md` records the same
kind of question for the mirror.

## The tools this note needed

* `tools/ramdump.py` - SH-4 disassembly of a RAM range out of a raw dump (the
  1ST_READ image does not cover the whole RAM: the REIOS' bootstrap lives at
  `0x0C004000` and the BIOS' own copies at `0x8C000000`).
* `tools/ram_diff.py` - the 64 KiB pages where the reference's RAM and the
  port's differ.
