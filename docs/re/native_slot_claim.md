# native_slot_claim (0x8C062490)

The slot-claim scan, ported natively in `src/native/slot_claim.c`
(`vf3_native_slot_claim`) as a plain-C transcription of the readable port
`src/fight/readable/slot_claim.c` (`vf3_slot_claim_entry`).

## Why this leaf

The readable authority is a self-contained leaf (body 0x0C062490..0x0C0624B6,
42 B), **call-free, integer-only (no FP) and no-stack** (it tail-returns
through r16 and never touches r15).  Like the two previous native leaves
(max_walk, scene_walk) this is the cleanest kind of native target: no guest
callees to inline and no FPU round-toward-zero wrappers.

## The body

It reads two parameters from the literal pool:

```
base  = [0x0c062590]      a pointer to the first slot
count = (int16)[0x0c06258a]   the number of slots (signed)
```

then scans `count` slots at stride 0x18:

```
for (r7 = 0, r4 = r6 = base; ; ) {
    v   = (int16)[r6] & 0xffff;    // the slot's 16-bit tag
    T   = ((v & 1) == 0);          // a clear low bit is a free slot
    if (T) { [r4] = 1 (u16); r0 = r4; return; }   // mark and answer
    r7++; r4 += 0x18; r6 += 0x18;  // next slot
    T = (r7 >= count); if (!T) continue;
    r0 = 0; return;                // none of the slots was free
}
```

The loop is a **do-while** (no pre-loop guard), so the first slot is always
tested even when `count <= 0`.  The mark (u16) and the tag read both go
through the slot pointer (r4 == r6 throughout), so a found slot is written
with 1 and its address is left in r0.

Details the native port keeps (unchanged from the readable authority):

* **The do-while entry** - the first slot is tested unconditionally.
* **The tag is masked to 16 bits** (`(int16)` sign-extend then `& 0xffff`).
* **A clear low bit is the free test**; the mark is a **u16** write of 1.
* **The stride is 0x18**; the exit test is `(r7 >= count)` (signed).
* **Left registers**: r0 = the found slot's address (or 0), r3 = the last tag
  read, r4/r6 = the found slot (or one past the run), r5 = 1, r7 = the scan
  index, and SR.T = 1 on both arms.  r1, r2, r8..r14, r15, r16 untouched.

## Evidence

The **differential** (`tests/slot_claim_native_replay.c`, target
`vf3nativeslotclaim`) runs the native port against the readable guest port
from the same seed over nine layouts (count 0 first slot free, first/second/
fourth slot free, high nibble set free, all occupied, negative count occupied
first, count 1 occupied, and count stopping before a free slot) and compares
byte for byte the pool and the slot array, plus the contract registers and
SR's T bit.  It also recomputes the expected answer with an independent
do-while walk over the fixture.  **9/9 PASS.**  The **mutation gate**
(`tests/slot_claim_native_mutations.json`) applies the same 13 mutations the
readable gate does (the found test inverted, the mark writing zero, the mark
written as a **byte** instead of a halfword, the tag masked to a byte, the
stride 0x10 instead of 0x18, the answer not the slot, the exit giving the last
slot, both T bits left clear, the do-while given a pre-loop guard, the exit
comparison's sense, r5 not left one and r3 not updated) and the differential
catches **all 13**.

```
build\vf3nativeslotclaim.exe ->
  slot_claim_native_replay: PASS
python tools/mutate.py --port src/native/slot_claim.c --exe build/vf3nativeslotclaim.exe \
    --mutations tests/slot_claim_native_mutations.json --target vf3nativeslotclaim
  13/13 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated == oracle` is closed: the readable authority
already replays the oracle corpus
`continuation_allocator_pool_long_dev/f_8c062490.cases` at 506/506 (see
docs/re/slot_claim.md).

## Notes

* The **byte-width store** (`wr8`) exists only to give the
  `mark_written_as_byte` mutation a compilable target; the real port always
  marks a slot with `wr16`.  The "high nibble set free" scenario gives the
  found slot a tag of `0x0100`, so a u8 mark leaves the high byte set while
  the u16 mark clears it - without it the write width would be invisible.
* `wr8` is referenced only by the mutation, so the release build never calls
  it; the build has no `-Wall`, so the unused static is not a warning.
