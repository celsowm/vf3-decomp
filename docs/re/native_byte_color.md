# native_byte_color (0x8C0563AC)

The two-byte color scale into floats, ported natively in `src/native/byte_color.c`
(`vf3_native_byte_color`) as a plain-C transcription of the readable port
`src/fight/readable/byte_color.c` (`vf3_byte_color_entry`).

## Why this leaf

The readable authority is a self-contained 80 B leaf
(0x0C0563AC..0x0C0563F8), **call-free and branch-free** (straight-line; the
only control transfer is the final `rts`).  It is the first FP native leaf in
the current run: the float pipeline uses the same round-toward-zero + FTZ
wrappers (`fmul` / `flz`) the earlier FP native ports (glyph_cache,
hitbox_overlap) use, so the stored floats match the guest bit for bit.

## The body

It reads three floats through a pool pointer, scales them by a fourth,
unpacks two packed bytes into three byte channels, converts them to floats,
scales those by the first three, and writes three floats down a descending
run of the output pointer:

```
ptrA  = read32(0x0c056504)   the three source floats (fr4, fr5, fr6)
scale = [0x0c056508]          a constant float (fr7), about 1/255
out   = read32(0x0c056510)    the output base (fr0, fr1, fr2)
```

The `w` below is `FPSCR.PR ? 8 : 4` (single/double width that gates every
load and store).  The float pipeline:

```
fr4 = [ptrA+0]  * fr7     scaled source channels
fr5 = [ptrA+w]  * fr7
fr6 = [ptrA+2w] * fr7
fr0 = float(r2) * fr6     converted byte channels, scaled
fr1 = float(r5) * fr5
fr2 = float(r6) * fr4
```

The three outputs are stored down the output pointer (`fr0@out`,
`fr1@out-w`, `fr2@out-2w`), with one earlier store of the *entry* `fr0` at
`[r1_in - w]` (a scratch the caller leaves the frame for).

Details the native port keeps (unchanged from the readable authority):

* **The FP results ride in the FR bank, not in locals.**  The final three
  `fr` values go into the FR registers before the stores read them out,
  exactly as the guest's stores emit the bank.
* **The packed bytes are read at `r4+4` and `r4+6`, and `r4 += 8`.**  The two
  bytes are sign-extended to 32 bits before their low/high bytes are masked.
* **Byte channels vs. byte lanes.**  `lo`'s low byte is r2 and its high byte
  is r5; `hi`'s low byte is r6 (r6 also end-rides FPUL).  `hi`'s high byte is
  never used.
* **The `w` (FPSCR width) ternary applies to every load/store stride and the
  output run.**  The corpus runs single precision only (fpscr 0x00040001), so
  the tests here are single-precision; the double-PR path is not exercised by
  any corpus and is not tested.
* **FPUL is a new `vf3_native_aim` member** (`fpul`, guest r53), added so the
  differential can witness the byte_color exit register; it is left holding
  `hi`'s low byte.  Existing native ports zero it via `memset`, so adding the
  member is backward-compatible.

## Evidence

The **differential** (`tests/byte_color_native_replay.c`, target
`vf3nativebytecolor`) runs the native port against the readable guest port
from the same seed over the same three single-precision channel layouts as the
readable test (all channels, zero bytes, max bytes with packed 0xffff).  It
lays the pool, the source floats, the output/bytes/scratch and the stack into
one flat window, patterns every byte, runs both sides, and compares the whole
RAM region byte for byte plus the FR bank (fr0/1/2), the contract integer
registers (r0, r1, r2, r4, r5, r6), the FPUL, and SR's T bit (untouched,
clear).  The native FR bank is seeded from `0x76543225 + i` to match the
guest's `s->v[21+i]` so the scratch store of the entry `fr0` is meaningful.
**3/3 PASS.**

The **mutation gate** (`tests/byte_color_native_mutations.json`) applies 14
single-site mutations (the readable gate's list minus the width-stride
inversion, which is unobservable at single precision): the skipped initial
store, the pool slots (ptrA/scale/out), the byte read offsets, the three
byte-channel sources, the FR lane map, the two store offsets, the `r1` answer,
the FPUL answer, `r4 += 4` instead of 8, and the `r0` answer.  The
differential catches **all 14**.

```
build\vf3nativebytecolor.exe ->
  byte_color_native_replay: PASS
python tools/mutate.py --port src/native/byte_color.c --exe build/vf3nativebytecolor.exe \
    --mutations tests/byte_color_native_mutations.json --target vf3nativebytecolor
  14/14 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated == oracle` is closed: the readable authority
already replays the oracle corpus `tenpp_arch_third_cases/f_8c0563ac.cases` at
128/128 (see docs/re/byte_color.md).

## Notes

* The differential's RAM snapshot is taken **after** the guest run and before
  the native side re-seeds the shared flat buffer - comparing the native run
  against the *current* buffer (as an earlier draft did) compares native to
  native and silently misses every mutation that changes only RAM.
* The corpus exercises only single precision, so the proof is
  single-precision; the double-PR width ternary is carried for fidelity but is
  not evidenced by any captured state.
