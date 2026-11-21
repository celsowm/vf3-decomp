# native_mem_fill — the memory-fill leaf (0x8C095604)

The readable port `src/fight/mem_fill.c` (`vf3_mem_fill_entry`) is rewritten
as plain C in `src/native/mem_fill.c` (`vf3_native_mem_fill`), proved against
it by `tests/mem_fill_native_replay.c` (8 differential cases) and by the
mutation gate (`tests/mem_fill_native_mutations.json`, 9/9 caught).

## The leaf

A `memset`: `r4` = destination, `r5` = value, `r6` = byte count, `r0` = end
pointer.  The count is split into `length / 4` whole words (which store r5 as
a whole 32-bit word) and `length & 3` tail bytes (which store value's low
byte).  The word count comes from the game's signed 32-bit divide helper
`0x8C042C20` (`r1 / r0 -> r0`); div-by-4 truncates, so the native inlines it
as C `length / 4`, which has the same signed-truncation semantics.

```
r0 = r1 = words  (the inlined quotient)
r3 = DIV_S32_LITERAL (0x0C042C20, the helper-entry literal the guest keeps in r3)
words-stores:  dst[i] = value, r4 = done, r7 = end of word region
tail (length&3):  low byte of value, r4 = tail, r6 = end
r0 = end;  SR.T = 1
```

## The call-frame detail

The readable port builds a two-word call frame under the entry sp (r14 and
pr), then lands inside the divide helper, which pushes its own two scratch
words (r2 and r3) — all four dead words sit under `sp` and are visible in
RAM, so the native leaf reproduces them byte-for-byte.  This required a new
byte setter `vf3_aim_set_u8` in `aim_math.{c,h}` (there was only a byte
*reader* before), following the existing `set_u16`/`set_u32` shape.

## The test

`tests/mem_fill_native_replay.c` seeds both sides with the same flat RAM and
the same r4/r5/r6, runs the leaf, and compares the whole low RAM region
(including the four dead stack words), every general register and SR.T against
the guest.  Eight cases: word-aligned, exact-word, odd and three-byte tails,
word+tail combos, zero bytes, and a 39-byte mixed count.  A fixture model
independently checks the words and tail bytes.

## The mutation gate

`tests/mem_fill_native_mutations.json` applies 9 single mutations: the tail
not written, the word stores corrupted, the word count halved, the tail byte
from the wrong lane, a wrong `r0`, `r6` not set on the tail path, SR.T not
set, a wrong `r7`, and the whole call frame omitted.  All 9 are caught.

## Authority

The readable port is the authority; the chain is *native == readable* (with
the DIV_S32 divide inlined as equivalent C).  No oracle corpus names this
exact entry as a watched specimen, so the proof stands on the differential
against the readable translation.

Result: **8/8 PASS**, **9/9 mutations caught**.
