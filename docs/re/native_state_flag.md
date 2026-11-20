# native_state_flag (0x8C0B0FD2)

The fight engine's state flag, ported natively in `src/native/state_flag.c`
(`vf3_native_state_flag`) as a plain-C transcription of the readable port
`src/fight/state_flag.c` (`vf3_state_flag_entry`).

## Why this leaf

The readable authority is a **self-contained integer leaf** - it calls nobody,
uses no FPU and keeps **no stack frame**, but it reads the literal pool, the
state word and the T bit.  It is the native target for the **guest's `shad`**
(the negative-count arithmetic shift) and for a function that sets bits in a
word the caller hands over by address (r7).

## The body

The caller hands over the state word (r7), the structure with the value (r5),
the offset the value is measured from (r6) and the structure with the two
parity words (r4).  The function sets **one of two bits** in the state word -
or nothing at all - depending on the band the signed value falls into and one
parity bit.

- The value is a halfword in the r5 structure at the offset the pool names
  (0x0c0b1070); the guest subtracts r6 and flips the sign bit with the pool's
  xor constant (0x0c0b1098).
- The **middle band** runs from the pool's middle bound (0x0c0b1074, -27300)
  up to the low bound (0x0c0b1072, -5460); the **high band** runs from the
  high bound (0x0c0b1078, 5460) up to the second high bound (0x0c0b107a,
  27300).  A value between or outside both bands leaves the word alone.
- The parity bit is the low bit of the first parity word shifted right by 25
  exclusive-ored with the second (72 bytes on) shifted right by 10.
- The two bands answer the **opposite way round**: in the middle band a clear
  parity bit sets the low bit, in the high band it sets the high one.
- The **gate** (the mask at 0x0c0b1094): when the state word already carries
  any of the mask's bits the function does nothing - it does not even write
  the word back.

All the pool's entries are read at run time, and the guest's `shad` with a
negative count shifts right by the count's two's complement masked to five
bits (the corpus pins it: 0xa6000000 comes out as 0xffe98000, an arithmetic
shift right by ten).

## Evidence

The **differential** (`tests/state_flag_native_replay.c`, target
`vf3nativestate_flag`) runs the native port against the readable guest port
from the same seed.  The pool, the two structures and the state word sit at
the game's own addresses in one flat buffer (~2.4 MB).  The whole region is
compared byte for byte, together with the registers (r0..r15) and the T bit,
and the outcome (the registers the guest leaves, the T bit and the state word
afterwards) against an independent fixture-based model written in the test.
The scenarios cover the gate, the value between the bands, above the high
band, below the middle band, inside both bands with both parity answers, the
corpus' own case, an all-different pool and all four band boundaries.
**14/14 PASS.**

The **mutation gate** (`tests/state_flag_native_mutations.json`) applies
fourteen mutations mapped onto the native lines: the nine pool entries read
from the wrong place, the second parity word read four bytes low, the value
added instead of subtracted, the xor constant and-ed in, the value truncated
to twelve bits instead of sixteen, and the middle band answering the high
band's way round.  The differential catches **all 14**.

```text
build\vf3nativestate_flag.exe ->
  state_flag_native_replay: PASS
python tools/mutate.py --port src/native/state_flag.c --exe build/vf3nativestate_flag.exe \
    --mutations tests/state_flag_native_mutations.json --target vf3nativestate_flag \
    --keep-going
  14/14 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated == oracle` is closed per the readable
authority (the readable port itself is oracle-replayed, `docs/re/state_flag.md`).

## Notes

* The flat buffer base equals the **pool's** base (`0x0c0b1000`), and the
  buffer spans the pool, the two structures and the state word (up to
  `0x0c320000`).
* The native SR carries the corpus' own value (`0x60000000`), so the T bit the
  function leaves is set through `set_t` (`sr & ~1u` width) and compared
  against the model's expectation.
* The `shad`/`asr` helpers reproduce the guest's arithmetic shift exactly; the
  mutation gate does not mutate their shift counts because the sign-extension
  keeps the parity bit stable for the corpus' words - it targets the pool
  entries and the arithmetic instead.
