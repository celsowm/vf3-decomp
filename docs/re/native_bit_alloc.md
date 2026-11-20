# native_bit_alloc (0x8C038860)

The fight engine's first-free-bit allocator, ported natively in
`src/native/bit_alloc.c` (`vf3_native_bit_alloc`) as a plain-C transcription of
the readable port `src/fight/bit_alloc.c` (`vf3_bit_alloc_entry`).

## Why this leaf

The readable authority is a **self-contained integer leaf** - it calls nobody
and uses no FPU - and it carries the guest's six-register callee-saved frame on
the stack, so it is a clean native target that exercises both the flat-RAM
helpers and the stack frame contract at once.

## The body

The function hands back **the index of the first free bit** of a table of
32-bit words, and takes that bit while it is there.  A word of `0xFFFFFFFF` is
the table's end marker (an exhausted slot), not a free bit.  The free bit is
the **lowest clear bit** of the word, and the answer is the bit's index in the
whole table: the word's index times 32, plus the bit's number inside the word.
A table with no free bit answers **-1** and writes nothing.

The literal pool holds two pointers read at run time: `POOL_COUNT`
(`0x0c0389c8`, the *address* of the count, so the count is read through it) and
`POOL_TABLE` (`0x0c0389cc`, the table, whose first entry points at the words).
The guest keeps a frame of six callee-saved registers (`r8..r11`, `r13`, `r14`)
on the stack, pushed in the order `14 13 11 10 9 8` and popped back in the
reverse `8 9 10 11 13 14`; the port reproduces both orders, and the frame bytes
are part of the contract (visible in the RAM the test compares).  The T bit the
guest leaves is the last test it made; the port's `set_t` writes `a->sr`.

## Evidence

The **differential** (`tests/bit_alloc_native_replay.c`, target
`vf3nativebitalloc`) runs the native port against the readable guest port from
the same seed over the same eight scenarios as the readable test: the first bit
free, a middle bit, the top bit (mask reaching its last step), one word
exhausted then free, three exhausted then free, every word exhausted (answer
-1, nothing written), a zero count, and one word with its top bit free.  The
literal pool, the count, the table, the words and the stack sit at the game's
own addresses, spanned by one flat buffer whose base matches the lowest guest
address.  It compares the whole region byte for byte, the eight output
registers (`r0..r7`), the T bit, the **restored** callee-saved frame
(`r8..r11`, `r13`, `r14` back to the caller's values) and r15 (back on the
entry sp), and the outcome against an independent model of the guest written
from the disassembly (not from the port) - so a fixture that is not where the
guest looks cannot make both sides agree on the wrong bytes.  **8/8 PASS.**

The **mutation gate** (`tests/bit_alloc_native_mutations.json`) applies
twenty-three mutations mapped onto the native lines: the pool's two pointers
swapped or read through each other, the exhausted marker not all ones, a
31-bit word, the frame push/pop orders swapped, eight-byte pushes, a frame word
one too big, the counter/offsets/mask not starting where the guest starts them,
the count test inverted, the exhausted answer zero instead of -1, the exhausted
slot's advances wrong, the bit number/scan start wrong, the taken bit replacing
the word, the mask moving two bits, the answer one too many, and the bit written
into the next word.  The differential catches **all 23**.  (The two frame-order
mutations need the test's callee-saved restore checks - the first version of the
test compared only `r0..r7`, so a pop-order swap was invisible until the
restored `r8..r14` were verified.)

```
build\vf3nativebitalloc.exe ->
  bit_alloc_native_replay: PASS
python tools/mutate.py --port src/native/bit_alloc.c --exe build/vf3nativebitalloc.exe \
    --mutations tests/bit_alloc_native_mutations.json --target vf3nativebitalloc \
    --keep-going
  23/23 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated == oracle` is closed per the readable
authority (which replays its 194-case oracle corpus).

## Notes

* The frame's six pushes happen **before** the registers are overwritten, so
  the frame holds the caller's values and the pops restore them - the test
  verifies both the frame RAM bytes and the restored registers.
* The pool is read at run time, exactly as the guest reads it; the flat buffer
  base must equal the pool's base (0x0c038000), or the offset arithmetic lands
  past the buffer.
