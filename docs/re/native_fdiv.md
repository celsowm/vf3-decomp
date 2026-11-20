# native_fdiv (0x8C0533A4)

The float division / reciprocal helper, ported natively in `src/native/fdiv.c`
(`vf3_native_fdiv`) as a plain-C transcription of the readable port
`src/fight/readable/fdiv.c` (`vf3_fdiv_entry`).

## Why this leaf

The readable authority is an off-baseline leaf (116 B,
0x0C0533A4..0x0C053418), **call-free and FPU-free** (it only reads fr0's bits).
It is the natural follow-on to byte_color and tenpp_fill in the native run, and
it is the first native port whose **SR T bit is part of the answer**: the
shared pack is carry-rotate arithmetic with the T bit as the rotate-through
bit, so the port keeps `a->sr`'s bit 0 in step through every shift.

## The body

The dividend's bits arrive in **fr0**.  The entry stores them through a
transient stack slot (store width follows FPSCR) and pops them into r0, so the
input travels through RAM exactly as the guest stores and reloads it.  A
fixed-point software reciprocal driven by four IEEE-754 scratch constants from
the literal pool (`0x0c053418` = 0xff the exponent mask, `0x0c053420` = 0x7ff
the infinity exponent, `0x0c053424` = 0x7ff00000 the quiet-NaN constant,
`0x0c053428` = 0x380 the bias) turns it into a two-word answer written to the
caller's two-word cell at sp+16:

```
cell[0] <- r3   the exponent / status word
cell[1] <- r0   the packed result word
```

The branch is the input's exponent byte (the top byte of `2*r0`, masked with
the pool's 0xff):

| exponent byte | the input | the answer |
|---|---|---|
| 0xff, mantissa 0 | infinity | cell = (0, 0x7ff00000) via the shared pack |
| 0xff, mantissa != 0 | NaN | cell = (1, 0x7ff00000), straight to the tail |
| 0x00, mantissa 0 | zero | cell = (0, 0x00000000) via the shared pack |
| 0x00, mantissa != 0 | denormal | mantissa normalised up, exponent counted down into the bias, then the shared pack |
| anything else | ordinary | exponent biased by 0x380, then the shared pack |

Every path that reaches the pack shares one carry-rotate ladder: `r0` shifted
eight, then a fixed ladder of `shlr`/`rotcr` steps folding the T bit in and out
of `r3` (the accumulator) and `r0`, `r2`'s top bit fed in through `shll`, and
the exponent word (`r1`, shifted left twenty) or-ed into `r0`.  The tail then
restores the four caller-saved registers `r3 r2 r1 r0` from sp+0/+4/+8/+12 and
leaves r15 at sp+20.

Details the native port keeps (unchanged from the readable authority):

* **The denormal normaliser's loop back-edge returns to the decrement, not to
  the leading shift.**  The lead-out shift/test (`0x53406/0x53408`) run once;
  the loop body is *decrement, shift, test* (`0x5340a/0x5340c/0x5340e`), and
  its `continue` jumps back to the decrement.  The differential's smallest
  denormal (`0x00000001`) is what pins it (module `0x36a00000`, a shifted-back
  port `0x37580000`).
* **SR's T bit is live across the whole pack.**  `rotcr` reads the incoming T
  bit from `a->sr & 1`, shifts it in at bit 31 and writes the shifted-out bit
  back.  The mutate run and the differential both compare the final T bit
  against the fixture's expected value.
* **The four caller-saved registers come back as the caller's saved values.**
  The fixture puts distinct values at sp+0/+4/+8/+12 so a port that pops them
  in the wrong order fails.
* **The transient store width follows FPSCR** (single 4, double 8); the corpus
  is single precision, so the proof here is single-precision, like byte_color.

## Evidence

The **differential** (`tests/fdiv_native_replay.c`, target `vf3nativefdiv`)
runs the native port against the readable guest port from the same seed over
the same nine scenarios as the readable test (infinity, NaN, zero, the
smallest denormal `0x1`, a mid-range denormal `0x7f`, 1.0, 2.0, -2.0 **0xc0000000**
the corpus' own input, and the mantissa-bearing normal `0x40a4a000`).  It lays
the pool, the stack frame and the result cell into one flat window, patterns
each region distinctly, runs both sides, and compares the whole RAM region byte
for byte plus the contract integer registers (r0..r3 restored to the caller's
saved values, r15 = the advanced sp), SR's T bit, and the outcome against the
fixture itself (the two cell words, the caller registers, the sp advance and
the transient fr0 slot at sp-4).  It needs no image and no device sidecars (the
pool constants are seeded like the readable test seeds them).  **9/9 PASS.**

The **mutation gate** (`tests/fdiv_native_mutations.json`) applies all 15 of the
readable gate's mutations, each mapping onto the native's own lines: the
exponent mask 4 bits, the dropped raw input, the exponent read one byte low,
NaN/infinity swapped, the NaN status, the infinity exponent, the denormal gate,
the normalize-loop early break, the ordinary bias constant, the pack's 4-bit
drop, the one-bit-narrow exponent pack, the cell skipping a word, the unrestored
caller r3, the sp three short, and the transient store in the wrong slot.  The
differential catches **all 15**.

```
build\vf3nativefdiv.exe ->
  fdiv_native_replay: PASS
python tools/mutate.py --port src/native/fdiv.c --exe build/vf3nativefdiv.exe \
    --mutations tests/fdiv_native_mutations.json --target vf3nativefdiv
  15/15 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated == oracle` is closed: the readable authority
already replays the per-entry `.cases` corpus `f_8c0533a4` at 40/40 directly
(see docs/re/fdiv.md), and the generated module replays all four of its corpora.

## Notes

* The native port's return is implicit (pr unchanged); the readable authority's
  explicit `s->pc = R(16)` is the guest's rts to the caller, which in the native
  port is just the normal C return.
* Like byte_color, the differential's RAM comparison snapshots the **guest's**
  RAM before the native side re-seeds the shared flat buffer - comparing the
  native run against the current buffer (an early draft's mistake) compares
  native to native and silently misses every RAM-only mutation.
