# native_byte_decode (0x8C04538A)

The fight engine's word decoder, ported natively in
`src/native/byte_decode.c` (`vf3_native_byte_decode`) as a plain-C transcription
of the readable port `src/fight/byte_decode.c` (`vf3_byte_decode_entry`).

## Why this leaf

The readable authority is a **self-contained integer leaf** - it calls nobody,
uses no FPU and keeps **no callee-saved frame**, but unlike the earlier native
leaves it **uses the stack**: it pops a word off the caller's stack, pushes it
on its own stack, and reads the bytes back *out of the stack*.  That makes it
the native target for the stack-window and byte-order conventions.

## The body

The engine calls this with a word on the caller's stack (r5).  The function
pops that word, pushes it on its own stack (r15), and copies its four bytes
into the object (r4) at +8..+11 - in the natural order, or turned around,
depending on what the table at `0x0c045454` (through the cell base signed
halfword at `0x0c04544a`) says.

The first byte of the object (+8) then decides the answer, written at +20:

- the byte equals the mark (`0x0c045448`): the answer is -1;
- the byte is at or above the limit (`0x0c04544c`): the answer is the *next*
  word on the caller's stack;
- otherwise the answer is zero.

Two details the port keeps: the bytes are read back **out of the stack** (the
push is part of the contract - the caller's words and this function's stack
window are separate), and each of the three answer arms ends in a branch whose
delay slot is the store.  r15 restores to the entry sp.

## Evidence

The **differential** (`tests/byte_decode_native_replay.c`, target
`vf3nativebytedecode`) runs the native port against the readable guest port
from the same seed over the same ten scenarios as the readable test - both byte
orders, the mark, at/above the limit, just below it, a limit of 255, a
**negative** limit (0x8000, so only the at-or-above arm treats large bytes as
in-range), and an entry that is not the turned-around one.  It also checks the
object's four bytes and the answer against an **independent model** written in
the test (which the earlier ports did not), so the fixture is exercised directly
and not merely mirrored by the translation.  **10/10 PASS.**

The **mutation gate** (`tests/byte_decode_native_mutations.json`) applies
nineteen mutations mapped onto the native lines: every pool entry wrong, the
turned-around table entry wrong, the natural/turned branches reversed, the pool
base read as a word, the table read through the wrong cell word, the object's
byte and answer offsets wrong, the bytes copied from the caller's stack instead
of the own one, the natural order written turned around, the push four bytes too
far, the mark read as a word, the mark answer not -1, the limit answer reading
the popped word, the zero answer not zero, the limit test `>` instead of `>=`,
and the classifier reading the limit as the mark.  The differential catches
**all 19**.

```text
build\vf3nativebytedecode.exe ->
  byte_decode_native_replay: PASS
python tools/mutate.py --port src/native/byte_decode.c --exe build/vf3nativebytedecode.exe \
    --mutations tests/byte_decode_native_mutations.json --target vf3nativebytedecode \
    --keep-going
  19/19 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated == oracle` is closed per the readable
authority.

## Notes

* This leaf pops the caller's word before the leaf's own push, so a fixture has
  to lay the caller's stack **and** the leaf's own stack window out separately -
  and, crucially, to **fill the stack before** writing the caller's words, or
  the stack fill pattern overwrites them (the first version of the test seeded
  the caller's words before the `memset` of the stack window and read 0x5a back).
* The flat buffer base equals the **table's** base (`0x0c030000`, the lowest
  guest address), not the object's.
* The pool-base "not sign-extended" mutation was **unobservable** (the fixture's
  base offset 0x10 is positive, so sign extension is a no-op) and was replaced
  by a word-read mutation, which changes the value read and is caught.
