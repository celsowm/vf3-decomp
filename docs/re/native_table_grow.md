# native_table_grow (0x8C044C7C)

The fight engine's table grower, ported natively in
`src/native/table_grow.c` (`vf3_native_table_grow`) as a plain-C transcription
of the readable port `src/fight/table_grow.c` (`vf3_table_grow_entry`).

## Why this leaf

The readable authority is a **self-contained integer leaf** - it calls nobody,
uses no FPU and keeps **no stack frame**.  Its header access is the classic
**two-indirection** pattern (the global holds the header's address, the
header's first word the base the slots are measured from), and its loop guard
is **signed**, so a negative count does something subtle - the first array is
left alone but the second array's pointer moves *backwards*.  That makes it a
good native target for the flat-RAM and signed-compare conventions.

## The body

The function adds N entries (r4) to two arrays behind one header.  The first
array holds strided entries: its pointer moves on by the stride (the header's
word twelve bytes past the slot, scaled by four) and the new entries get the
fill value out of the literal pool.  The second array holds plain entries: its
count becomes N and its pointer moves on by N words.  The header hangs off a
global (`0x0c044d44`); the three slots - the first array's (`0x0c044d16`), the
fill (`0x0c044d18`) and the second array's (`0x0c044d1a`) - are halfwords in
the literal pool, read at run time.

Two details the port keeps: the two indirections to the header are **distinct
accesses** (the global, then the header's first word), and the loop's guard is
**signed**, so a negative count leaves the first array alone but still moves
the second array's pointer backwards.  The answer is 0.

## Evidence

The **differential** (`tests/table_grow_native_replay.c`, target
`vf3nativetablegrow`) runs the native port against the readable guest port from
the same seed over the same five scenarios as the readable test - a zero count,
one entry, several, eight, and a **negative** count (which must still move the
second array's pointer backwards).  The literal pool, the header pointer, the
base and the arrays sit at the game's own addresses in one flat buffer, and the
test compares the whole region, the registers (r0, r4 - which the guest shifts
left by two - and the T bit) and the answer.  **5/5 PASS.**

The **mutation gate** (`tests/table_grow_native_mutations.json`) applies
nineteen mutations mapped onto the native lines: the global and every pool
entry wrong, the stride offset and scale wrong, the first array's pointer not
moved, the fill value narrowed and written one word early, the loop's guard and
boundary wrong, the counter incremented by two, the second array's count not
written or written at the wrong slot, the pointer not moved, the count's word
offset wrong, the answer not zero, the base read from the wrong header offset,
and the first slot read as a word instead of a halfword.  The differential
catches **all 19**.

```
build\vf3nativetablegrow.exe ->
  table_grow_native_replay: PASS
python tools/mutate.py --port src/native/table_grow.c --exe build/vf3nativetablegrow.exe \
    --mutations tests/table_grow_native_mutations.json --target vf3nativetablegrow \
    --keep-going
  19/19 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated == oracle` is closed per the readable
authority.

## Notes

* The leaf keeps **no stack frame and no callee-saved registers**, so the
  native test only checks the output registers, the T bit and the answer.
* The flat buffer base equals the **pool's** base (`0x0c044d10`, the lowest
  guest address) - not the header pointer window's base - or the offset
  arithmetic lands past the buffer.
* The multi-line mutation subs need **LF** line endings in `table_grow.c`.
