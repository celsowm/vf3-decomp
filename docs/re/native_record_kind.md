# native_record_kind (0x8C078044)

The fight engine's record-kind byte/flag-word updater, ported natively in
`src/native/record_kind.c` (`vf3_native_record_kind`) as a plain-C transcription
of the readable port `src/fight/record_kind.c` (`vf3_record_kind_entry`).

## Why this leaf

The readable authority is a **self-contained integer leaf** - it calls nobody
and uses no FPU - but it keeps a **frame**: it saves r13/r14 at sp-4/-8 and
restores them (r14 in the return's delay slot), and it reads the caller's three
frame words (the flag, the gate and the mode words) at the *entry* sp + 0/+4/+8.
It is the native target for the **caller-frame reads** and the **sign-extended
byte** conventions together.

## The body

The function is handed a record - r5 is its base and r7 an index into it - and
the flag word the caller left in its frame.  The record keeps three bytes that
matter:

- the **kind** byte, at the pool offset (0x0c07815A) plus the index.  It counts
  down: set to one when the record gets a kind, taken down to zero when
  finished.
- the **state** byte, at the pool offset (0x0c07815C) plus the index.
- the byte at the third offset (0x0c07815E), which the guest copies into two
  places: the fourth offset (0x0c078160) plus the index, and the third offset
  plus 51.

When the kind byte is still zero the record has no kind yet: the flag word's low
four bits decide (zero or fifteen mean complete; anything else starts a kind,
clearing the flag word's low nibble).  When the record has a kind, the gate mask
(0x0c07816C) is tested against the caller's gate word: when the caller's word
has none of the gate's bits, three tests have to hold - the state byte is four,
the mode word's bit two is clear, and the flag word's low nibble is one - and
then the byte is copied and the kind cleared.  Otherwise the state byte joins
the flag word; if the merged value is fifteen, or the kind was one, the kind is
cleared, else it counts down.

Details the port keeps: the `/s` branch's delay slot masks the flag word before
the branch is resolved; the two copies leave the write address in r7 (first) and
r3 (second); `dec r14` takes down the *kind* byte; and the return pops r14 in its
delay slot.

## Evidence

The **differential** (`tests/record_kind_native_replay.c`, target
`vf3nativerecord_kind`) runs the native port against the readable guest port
from the same seed over the same thirty scenarios as the readable test - the
record with no kind (no bits, all four, one, two, top, and extra bits), the
index zero and a high source byte, the record with a kind and the gate open or
closed, the three tests holding or failing (mode bit two set, nibble not one),
the state-six extra bit with the mode two, the merged value fifteen, the kind
one, the kind counting down (with the state six and a big kind), and the flags
carrying other bits.  The pool, the record and the caller's stack sit at the
game's own addresses in one flat buffer (~1.61 MB).  The whole region is
compared byte for byte, together with the registers (r0..r15, with r15 back on
the entry sp and r13/r14 restored), the T bit and the flag word, the record's
bytes and the copies against an independent model written in the test.  **30/30
PASS.**

The **mutation gate** (`tests/record_kind_native_mutations.json`) applies
eighteen mutations mapped onto the native lines: the five pool offsets and the
gate mask wrong, the second place of the copy off by one, the flag nibble
narrowed to three bits, the new kind written where the state goes, the new kind
set to two, the state-six mode shift wrong, the extra bit cleared instead of
set, the kind counting up, the mode bit tested at bit three, the kind-zero path
flipped, the delay slot not masking the flag word, the copy reading one past
the source, and the flag answer coming from the wrong register.  The
differential catches **all 18**.

```text
build\vf3nativerecord_kind.exe ->
  record_kind_native_replay: PASS
python tools/mutate.py --port src/native/record_kind.c --exe build/vf3nativerecord_kind.exe \
    --mutations tests/record_kind_native_mutations.json --target vf3nativerecord_kind \
    --keep-going
  18/18 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated == oracle` is closed per the readable authority
(which itself replays the captured fight states in tests/record_kind_oracle.c).

## Notes

* Two mutations had to flip the *branch*, not just the `set_t` line beside it.
  The state-six and the mode-bit tests each set the T bit and then `if` on the
  same comparison; a mutation that changed only the `set_t` value left the
  branch (and every following) behaviour intact and only the T bit - which the
  function overwrites before it returns - different.  The mutations now replace
  the two lines (the `set_t` *and* the `if`) together, and the differential
  catches them.
* The `kind_zero` mutation's JSON used the wrong indentation (four spaces where
  the source has eight) and so was never applied; it is corrected.
* The flat buffer base equals the **pool's** base (`0x0c078158`, the lowest
  guest address), and the buffer spans the pool and the whole 0x2000-byte record
  (up to `0x0c202000`), with the caller's stack window between them.
