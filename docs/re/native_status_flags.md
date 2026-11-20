# native_status_flags (0x8C0961F4)

The engine's record status-flags word, ported natively in
`src/native/status_flags.c` (`vf3_native_status_flags`) as a plain-C
transcription of the readable port `src/fight/status_flags.c`
(`vf3_status_flags_entry`).

## Why this leaf

The readable authority is a **self-contained integer leaf** - it calls nobody,
uses no FPU and keeps **no stack frame** - with a straight-line body: eight
record fields, each tested against the mask, no loops, no branches that come
back.  It is a native target for the **pool-at-run-time** convention (the last
field's mask comes out of the literal pool, read only when that field hits).

## The body

The engine keeps a record of a dozen words and asks this function for a bitmask
of the fields that are set.  The mask (r4) says which bits of a field count as
"set"; the record (r5) holds the fields.  The guest reads eight fields and puts
one bit in the answer for every field that has a bit in common with the mask:

| field | bit  | | field | bit  |
|-------|------|-|-------|------|
| +8    | 0x04 | | +24   | 0x10 |
| +12   | 0x08 | | +20   | 0x20 |
| +0    | 0x01 | | +28   | 0x40 |
| +4    | 0x02 | | +32   | pool 0x0c09630a |

The order is the guest's, and so are the gaps: the record has no field at +16.
The first bit is *assigned* (the guest zeroes the answer first), the rest are
or-ed in.  The T bit the caller sees is the **last** comparison's - so it is
set when the field at +32 has no bit in common with the mask; the earlier T
bits are overwritten before the function returns and are unobservable.

## Evidence

The **differential** (`tests/status_flags_native_replay.c`, target
`vf3nativestatus_flags`) runs the native port against the readable guest port
from the same seed.  The pool and the record sit at the game's own addresses in
one flat buffer (~2.4 MB).  The whole region is compared byte for byte,
together with the registers (r0..r15), the T bit and the flag word against an
independent model written in the test.  The scenarios cover the empty record,
the full one, masks that count only the low bits, a mixture with the field
order and the gap at +16, the high-bit-only mask, one single-field hit per bit
(to prove each of the eight bits maps to the right field), and a "last field
misses" case that proves the pool's mask is not smuggled in when the field does
not hit.  **14/14 PASS.**

The **mutation gate** (`tests/status_flags_native_mutations.json`) applies
twelve mutations mapped onto the native lines: the last-bit pool entry wrong,
each of the eight field reads wrong (their offsets swapped or the bit/offset
changed), the pool's last bit taken from a constant instead of the pool, the
first bit or-ed instead of assigned, a later bit assigned instead of or-ed, the
pool read even when the field misses, the answer's register wrong, and the
first field's value landing in the wrong register.  The differential catches
**all 12**.  Two mutations had to be reworked: reading the pool's slot as `0x80`
was identical to the seeded pool value (it is now `0x40`, a distinct wrong
value), and "or instead of assign" for the first field is unobservable by
design (the answer starts at zero, so the two are the same) - it was replaced
by a mutation that puts the first field's value in the wrong register, which
the register-file compare sees.

```text
build\vf3nativestatus_flags.exe ->
  status_flags_native_replay: PASS
python tools/mutate.py --port src/native/status_flags.c --exe build/vf3nativestatus_flags.exe \
    --mutations tests/status_flags_native_mutations.json --target vf3nativestatus_flags \
    --keep-going
  12/12 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated` is closed per the readable authority (which
is itself proved against the retained generated translation).

## Notes

* The flat buffer base equals the **pool's** base (`0x0c096300`, the lowest
  guest address), and the buffer spans the pool and the whole 0x100-byte record
  (up to `0x0c300100`).
* The answer rides in both r0 and r6; the model checks r0 and the full
  register file checks r6.
