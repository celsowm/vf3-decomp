# native_scene_walk (0x8C06233E)

The scene list walk with an enable flag, ported natively in
`src/native/scene_walk.c` (`vf3_native_scene_walk`) as a plain-C
transcription of the readable port `src/fight/readable/scene_walk.c`
(`vf3_scene_walk_entry`).

## Why this leaf

The readable authority is a self-contained leaf (body 0x0C06233E..0x0C062378,
62 B), **call-free and integer-only** - no FP, no gbr, no fipr, no stack (it
tail-returns through r16 and never touches r15).  Like max_walk, this makes it
a clean native target: no guest callees to inline and no FPU round-toward-zero
wrappers.  It does carry one interesting width subtlety (the 16-bit enable
flag read back as a sign-extended byte), which is exactly the kind of detail
the mutation gate is there to pin.

## The body

It reads a threshold pointer from the literal pool and a table base, writes a
16-bit enable flag, and walks a linked list to find the node whose value
equals the key:

```
p1      = [0x0c06238c]            a pointer
thr     = [p1]                    the threshold
enabled = (r4 >= thr)             signed comparison, SR.T
[r5]    = enabled ? 1 : 0         16-bit enable flag
byte    = (int8)[r5]              reads the flag back (0 or 1)
node    = [base + 20 * byte]      base = [0x0c062384]
```

A node is a record with `u32 value` at `+12` and `u32 next` at `+8`.  When
`node != 0` the body walks the list - recording in `r6` the first node whose
value equals `r4`, otherwise following `next` until null.  The answer is a
tail `jmp @r16`: `r0 = r6` (the found node, or 0), and the function neither
pushes `pr` nor touches `r15`/`r16`.

The registers the body leaves are `r0 = r6`, `r1 = 1` on an enabled empty
table (or the last value read by the walk), `r2 = byte`, `r3 = 20 * byte`,
`r5 = 0` (the walk's terminator), `r6` the found node, and `SR.T = 1` (the
walk-exit test `(r5 == 0)` is the last comparison).  `r4` and `r15` are
untouched.

Details the native port keeps (unchanged from the readable authority):

* **The enable flag is 16-bit and read back as a sign-extended byte.**
* **The stride is `20 * byte`** - the table is looked up at `base + 0` or
  `base + 20`, the two slots are distinct.
* **`r1 = 1` is set on the enabled path *before* the walk** - an enabled empty
  table returns with `r1 = 1`.
* **The walk records the *first* match and then stops.**
* **The found node rides in `r6` and `r0`.**
* **`SR.T` is 1 on every return.**

## Evidence

The **differential** (`tests/scene_walk_native_replay.c`, target
`vf3nativescenewalk`) runs the native port against the readable guest port
from the same seed over nine list layouts (enable=1 first/second match,
enable=1 not found, enable=1 empty table, enable=0 first/third match, enable=0
not found, the `r4 == thr` boundary, and an enable=1 case proving the walk
uses table slot 1 not slot 0) and compares byte for byte the pool, the
threshold/table region, the node region and the flag/stack region, plus the
contract registers (r0 == r6, r1, r2, r3, r5 = 0, SR's T bit, r4 and r15
untouched).  It also checks the written 16-bit flag against the patterned
neighbouring bytes so a wrong-width store is visible.  **9/9 PASS.**  The
**mutation gate** (`tests/scene_walk_native_mutations.json`) applies the same
14 mutations the readable gate does (the enable comparison inverted, enable
forced to 1, the flag written as a **byte** instead of a halfword, the table
stride/selection wrong, the found test inverted, the walk stepping by value
instead of next, the found node not recorded, `r5` not zeroed on a hit, `r0`
not copied from `r6`, the T bit left clear, the empty table made to walk, `r1`
not reloaded and the next pointer offset wrong) and the differential catches
**all 14**.

```
build\vf3nativescenewalk.exe ->
  scene_walk_native_replay: PASS
python tools/mutate.py --port src/native/scene_walk.c --exe build/vf3nativescenewalk.exe \
    --mutations tests/scene_walk_native_mutations.json --target vf3nativescenewalk
  14/14 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated == oracle` is closed: the readable authority
already replays the oracle corpus `target_retained_scene_final_dev/f_8c06233e.cases` at
272/272 (see docs/re/scene_walk.md).

## Notes

* The **byte-width store** (`wr8`) exists only to give the
  `flag_written_as_byte` mutation a compilable target; the real port always
  writes the flag with `wr16`.  The fixture patterns the flag's neighbouring
  bytes (`0x22222222`/`0x33333333`) so a halfword store is distinguishable
  from a byte store in the byte-exact RAM compare - without the pattern, both
  writes would leave the surrounding zero bytes identical and the mutation
  would be unobservable.
* `rd8` mirrors the guest's `mov.b` sign-extension; with a stored value of 0
  or 1 the stride arithmetic is unaffected, but the width is still honoured.
