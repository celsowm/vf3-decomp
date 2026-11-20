# native_state_advance (0x8C06BEA4)

The fight engine's entry-counter/kind-flags updater, ported natively in
`src/native/state_advance.c` (`vf3_native_state_advance`) as a plain-C
transcription of the readable port `src/fight/state_advance.c`
(`vf3_state_advance_entry`).

## Why this leaf

The readable authority is a **self-contained integer leaf** - it calls nobody
and uses no FPU - but unlike the earlier native leaves it keeps a **frame**: it
saves r12/r13/r14 on the guest stack at sp-4/-8/-12 and restores them (r14 in
the delay slot of the return).  That makes it the native target for the
**saved-register frame** and the **count-down / wrap** conventions together.

## The body

The function is handed two words - r4 (an entry counter, of which only the low
four bits are used) and r5 (a count) - and a kind in r6.  The counter steps
forward by one and wraps at sixteen (1, 2, ... 15, 0, 1, ...).  When the counter
is at zero the guest does not step it: it counts down instead - the counter
restarts at one and the count goes down by one, or with the count at zero both
stay at zero.

A byte of kind flags (the pointer to it is in the pool at `0x0c06bfbc`) is told
about the entry: a table in the pool (`0x0c06bfc0`) says what kind the entry is,
the flags are masked with the mask of the kind in question (`0x0c06bfac` for the
first, `0x0c06bfae` for the second) and that kind's bit is set only when the
table says something.  On the counting path the flags are left alone.

Three details the port keeps: the counter is masked to four bits before it is
used but the value written back is the *masked* counter plus one, masked again
(so the word's high bits are dropped); the flags byte is read signed and the
mask is a signed halfword, so both are sign extended before the and; and the
saved r14 comes back in the delay slot of the return.  r15 returns to the entry
sp and the counter/count are written back through r4/r5.

## Evidence

The **differential** (`tests/state_advance_native_replay.c`, target
`vf3nativestateadvance`) runs the native port against the readable guest port
from the same seed over the same 23 scenarios as the readable test - both kinds,
the table knowing or not, the flags holding both kinds' bits, the second kind's
mask keeping the first bit, the counter at zero (count runs down, spent or
left), the count at one and at its biggest, the wrap at sixteen, the counter
carrying bits above the four (3, 4 and zero with bits above), and signed
flags/masks.  The whole region is compared byte for byte, together with the
registers r0..r15, the T bit, the three pushed stack words, the restored r14 and
r15, and the **answer** (counter, count, flags byte, T bit) against an
independent model written in the test.  **23/23 PASS.**

The **mutation gate** (`tests/state_advance_native_mutations.json`) applies
twenty-one mutations mapped onto the native lines: every pool entry wrong, both
kinds' bits swapped, the counter mask narrowed to three bits, the delay-slot
advance removed, the wrap re-mask dropped, the kinds swapped, the kind bit set
even when the table says nothing, the flags not masked, the wrong kind's bit
written, the count-down not restarting the counter, the count decrementing by
two, the counter and count written one word early, r14 restored from the wrong
stack slot, the stack not popped all the way, the known T bit inverted, and the
table byte read one past the entry.  The differential catches **all 21**.

```text
build\vf3nativestateadvance.exe ->
  state_advance_native_replay: PASS
python tools/mutate.py --port src/native/state_advance.c --exe build/vf3nativestateadvance.exe \
    --mutations tests/state_advance_native_mutations.json --target vf3nativestateadvance \
    --keep-going
  21/21 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated == oracle` is closed per the readable
authority.

## Notes

* The flat buffer base equals the **pool's** base (`0x0c06bf80`, the lowest
  guest address), and the buffer has to be large enough to span **all five**
  windows - the pool, the table, the flags, the slots and the stack - which are
  hundreds of kilobytes apart (the flags sit ~475 KB from the pool base).  The
  first version sized the buffer to the *pool-to-stack* span incorrectly and
  the flags-byte write ran past the end of the allocation.
