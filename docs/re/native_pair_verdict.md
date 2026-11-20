# native_pair_verdict (0x8C074E7C)

The fight engine's two-structure verdict, ported natively in
`src/native/pair_verdict.c` (`vf3_native_pair_verdict`) as a plain-C
transcription of the readable port `src/fight/pair_verdict.c`
(`vf3_pair_verdict_entry`).

## Why this leaf

The readable authority is a **self-contained integer leaf** - it calls nobody
and uses no FPU, but it keeps a **frame** in which it saves r13 at sp-4,
exactly the shape the native `clamp_pair` port already models.  It also reads
the literal pool (offsets and masks), the two structures the caller hands over
(r4 and r5), and writes a word into the first one following a decision tree
whose T-bit trail the caller observes.

## The body

The function is handed two structures - r4 and r5 - and writes a word into
the first one: zero, or minus one.

- Both structures keep a word at the same offset, 0x48.  The second
  structure's word has to share a bit with the first mask (0x0c074f60) and
  must *not* share a bit with the second (0x0c074f64) - that is the gate.
- The first structure's word is then masked with two more (0x0c074f68 and
  0x0c074f6c) and the byte the second structure holds at the pool's offset
  (0x0c074f50) decides the rest: the byte can be 2, 4 or 5, and the first
  structure has to have a field (the pool offset 0x0c074f52) for the answer
  to be anything but zero.  The last mask (0x0c074f70) has the last word.

The port follows the guest's own decision tree, because the tree is what the
T bit follows too: the guest's last test is the one the caller sees.

Three details the port keeps: the byte is read *signed* and then masked to
eight bits by the delay slot of the first branch, so the value the tree
compares is the unsigned one; the two masks are and-ed with the first
structure's word in the delay slot of a branch, so they are and-ed on both
paths; and the saved r13 comes back in the delay slot of the return.

## Evidence

The **differential** (`tests/pair_verdict_native_replay.c`, target
`vf3nativepair_verdict`) runs the native port against the readable guest port
from the same seed.  The pool, the stack and the two structures sit at the
game's own addresses, spanned by one flat buffer.  The whole region is
compared byte for byte, together with the registers (r0..r15, pr, fpul, the
FR bank and SR's T bit), and the written word against an independent
fixture-based model written in the test (mirrored from the readable test's own
`expect()`).  The scenarios cover every arm of the tree: both gates, both
arms, each byte value, a negative offset and a non-empty result word.
**19/19 PASS.**

The **mutation gate** (`tests/pair_verdict_native_mutations.json`) applies
fifteen mutations mapped onto the native lines: the three off-byte offsets
swap with each other, the two gate masks swap, the two structure masks swap,
the last mask becomes the first gate's, the word offset moves one word, the
two gates invert, the byte's post-read mask goes away, the second arm stops
writing minus one, the deep test picks the wrong arm, and the saved r13 is
never restored.  The differential catches **all 15**.

```text
build\vf3nativepair_verdict.exe ->
  pair_verdict_native_replay: PASS  (19/19)
python tools/mutate.py --port src/native/pair_verdict.c --exe build/vf3nativepair_verdict.exe \
    --mutations tests/pair_verdict_native_mutations.json --target vf3nativepair_verdict \
    --keep-going
  15/15 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated == oracle` is closed per the readable
authority (the readable port itself is oracle-replayed, `docs/re/pair_verdict.md`).

## Notes

* The flat buffer base equals the **pool's** base (`0x0c074f50`), and the
  buffer spans the pool, the stack (at `0x0c108000`, between the two) and the
  two structures (at `0x0c110000`) up to `0x0c110200`.
* The native `a.fpul` and FR bank are seeded from the guest's incoming v[19]
  and v[21..36] so that the untouched registers compare equal: the leaf
  preserves them, and the differential reads the same starting state on both
  sides.
* The native SR carries the corpus' value (`0x301`); the T bit the function
  leaves is set through `set_t` and compared against the model's expectation.
