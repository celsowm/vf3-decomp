# native_counter_advance (0x8C08B338)

The fight engine's animation frame counters, ported natively in
`src/native/counter_advance.c` (`vf3_native_counter_advance`) as a plain-C
transcription of the readable port `src/fight/counter_advance.c`
(`vf3_counter_advance_entry`).

## Why this leaf

The readable authority is a **self-contained integer leaf** - it calls nobody,
uses no FPU and keeps **no stack frame at all**.  It advances three counters in
a record and one in a block, gated by a global, and it is the native target for
the **carried bit of the incremented counter** and the **signed block-wrap**
conventions together.

## The body

The engine keeps three counters in a record (r4): seven bits at +12, two at
+14, four at +16 - and one counter in a block.  The function advances them:

- the first counter steps by one and keeps seven bits;
- the low bit of that *incremented* counter is carried into the two narrow
  counters and into the block's counter - so the wide counter's own wrap (127
  to zero) carries nothing, and the narrow counters move on every other step;
- the block's counter (reached through the pool at `0x0c08b3f4`, at +0x54)
  wraps at 127.

A global says whether the counters move at all: the counters advance only when
the value the pool slot at `0x0c08b3f0` points at has **no** bit in common with
the mask at `0x0c08b3ec`.  On the gated path the T bit is set and nothing else
changes.

Two details the port keeps: the carried bit is the low bit of the *incremented*
wide counter (`R(6) = 1 & (R(5) + 1)`), so the wide counter's own wrap carries
nothing and the narrow counters move on every other step; and the block's wrap
test is a **signed** comparison on the sign-extended halfword, so a counter of
32767 that takes the carry becomes -32768 and **does not** wrap.  The block is
reached through **two** indirections (the pool slot, then a word that is the
block).

## Evidence

The **differential** (`tests/counter_advance_native_replay.c`, target
`vf3nativecounter_advance`) runs the native port against the readable guest port
from the same seed over eleven scenarios - the gate shut and open (the gate shut
leaves the counters untouched and the T bit clear, the gate open advances them),
the empty mask (lets everything through), the odd wide counter (nothing carried),
the wide wrap at 127, the block wrap at 127, the two narrow counters wrapping on
their own widths, over-width counters, the wide counter at bit 6 (which
distinguishes the seven-bit mask), the block past 127, and the block at 32767
with a carry (which distinguishes signed from unsigned wrap).  The pool, the
gate's value, the header, the block and the record sit at the game's own
addresses in one flat buffer (~3.36 MB).  The whole region is compared byte for
byte, together with the registers, the T bit and the three record counters plus
the block counter against an independent model written in the test.  **11/11
PASS.**

The **mutation gate** (`tests/counter_advance_native_mutations.json`) applies
fourteen mutations mapped onto the native lines: the three pool entries wrong,
the wide counter masked to six bits, the two narrow counters swapped widths, the
carry taken from the unincremented counter, the block counter at the wrong
offset, the block wrapping before 127, the block wrap comparison unsigned, the
record counters moved when the gate is shut, the record counter's second write
at the wrong offset, the wrap resetting to one, and the T bit inverted.  The
differential catches **all 14**.

```text
build\vf3nativecounter_advance.exe ->
  counter_advance_native_replay: PASS
python tools/mutate.py --port src/native/counter_advance.c --exe build/vf3nativecounter_advance.exe \
    --mutations tests/counter_advance_native_mutations.json --target vf3nativecounter_advance \
    --keep-going
  14/14 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated == oracle` is closed per the readable
authority.

## Notes

* Two mutations had to be fixed to be observable.  The seven-bit mask (0x7f vs
  0x3f) was invisible on the original scenarios because 300 and its neighbours
  happen to share their low 6 and low 7 bits; a `wide = 64` scenario separates
  them (64 & 0x7f = 64, 64 & 0x3f = 0).  The block input's sign extension is
  genuinely unobservable - the `(int16)` cast on the incremented value
  normalises it - so that mutation is instead the *comparison's* signedness,
  which the `wide bit 6`/`block at 32767` scenarios pin.
* The flat buffer base equals the **pool's** base (`0x0c08b3e0`, the lowest
  guest address), and the buffer spans the five far-apart windows up to the
  header's end at `0x0c3c0010` (~3.36 MB).
