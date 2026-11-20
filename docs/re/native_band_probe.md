# native_band_probe (0x8C0B0F28)

The band probe - a point against a band, and the flags it writes - ported
natively in `src/native/band_probe.c` (`vf3_native_band_probe`) as a plain-C
transcription of the readable port `src/fight/band_probe.c`
(`vf3_band_probe_entry`).

## Why this leaf

The readable authority is a **self-contained integer leaf** - it calls nobody
and touches no FPU, but it keeps a two-word frame, restores r13 in the delay
slot of the return, and writes flags into a word the caller hands over in its
own frame.  It is exactly the boundary the native `aim_math` register file +
SR model.

## The body

The function is handed a point in three registers - r4, r5 and r6 - and a band
in the literal pool.  It takes the two differences the point makes with its
third coordinate, masks them, and asks whether they are inside the band.

- `r4 - r6` and `r5 - r6` are the two differences.  The mask from the pool
  (`0x0c0b0f90`) is xored into them and the low halfword is read back as a
  signed number, so the pool alone decides what a masked difference is.
- The band is two halfwords in the pool: the low one at `0x0c0b0f64` and the
  high one at `0x0c0b0f66`.  The guest tests the high bound **first** and the
  low one **second**, so a value below the low bound is never tested against
  the high one, and the T bit the caller sees is the one of the **last**
  comparison.
- When both differences are inside, the guest sets the inside bit
  (`0x0c0b0f68`) in the word it was handed and answers **one**.  When one is
  outside, the guest asks the seventh register about a word in the pool
  (`0x0c0b1088`): if the two have no bit in common the answer is **zero** and
  nothing is written.  Otherwise it looks at the second difference once as it
  is and once under the mask, and sets the first outside bit (`0x0c0b108c`) or
  the second one (`0x0c0b1090`) for the ones that are inside.
- The word the flags go into is not in a register: the caller hands it over in
  its own frame, under the two words the callee pushes.
- The saved r13 comes back in the **delay slot of the return**, after the
  return itself has started; the stack finishes back where it started.

## Evidence

The **differential** (`tests/band_probe_native_replay.c`, target
`vf3nativeband_probe`) runs the native port against the readable guest port
from the same seed.  The literal pool and the caller's frame sit at the game's
own addresses, spanned by one flat buffer.  The whole region is compared byte
for byte, together with the registers, SR's T bit and an independent
fixture-based model that computes the answer, the flag word and the T bit
straight from the fixture.  The scenarios cover the inside case, the two
bounds, the four outside ways, the open and closed gate, the mask flipping the
sign, the band inverted, the sixteen-bit cut and the non-empty flag word.
**20/20 PASS.**

The **mutation gate** (`tests/band_probe_native_mutations.json`) applies
twelve mutations mapped onto the native lines: the mask, high and low bounds,
inside bit, gate and outside bits read from the wrong pool slot, the first
difference taken from the second pair, the inside bit or-ed without the signed
extension, the band test running its two comparisons in the other order, the
gate test using the second difference, and the second difference not masked
before its test.  The differential catches **all 12**.

```text
build\vf3nativeband_probe.exe ->
  band_probe_native_replay: PASS  (20/20)
python tools/mutate.py --port src/native/band_probe.c --exe build/vf3nativeband_probe.exe \
    --mutations tests/band_probe_native_mutations.json --target vf3nativeband_probe \
    --keep-going
  12/12 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated == oracle` is closed per the readable
authority (the readable port itself is differential-and-oracle-replayed,
`docs/re/band_probe.md`).

## Notes

* The flat buffer base equals the **pool's** base (`0x0c0b0f60`), and the
  buffer spans the pool and the caller's frame (at `0x0c108000`) up to
  `0x0c108040`.
* The T bit is **bit 0** of SR, set/cleared by the band comparisons and the
  gate's `tst`; the fixture model reproduces which comparison answers last on
  each arm.
* The native `a.r15`/`a.pr` are seeded from the incoming guest values; the
  return leaves `r15` back at the entry value and `r13` restored, and both are
  checked.
