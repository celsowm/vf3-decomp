# slot_claim — SH-4 0x8C062490

The readable port of the slot-claim scan lives in
`src/fight/readable/slot_claim.c`, registered as `slot_claim`, and is proved
against the retained generated translation by `tests/slot_claim_replay.c`
(9 differential cases) and against the **oracle** by `tests/slot_claim_oracle.c`
(506/506 on the `continuation_allocator_pool_long_dev/f_8c062490.cases`
corpus).

## What it does

A self-contained leaf (body 0x0C062490..0x0C0624B6), call-free, integer-only
(no FP), no stack (it tail-returns through r16 and never touches r15).  It reads
its two parameters from the literal pool:

    base  = [0x0c062590]            a pointer to the first slot
    count = (int16)[0x0c06258a]     the number of slots (signed)

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

The loop is a **do-while**: there is no pre-loop guard, so the first slot is
always tested even when `count <= 0`.  The mark (u16) and the tag read both
happen through the slot pointer (r4 == r6 throughout), so a found slot is
written with 1 and its address is left in r0.

## Left-behind registers

- r0 = the found slot's address, or 0 when no slot was free inside `count`.
- r3 = the last tag read (masked to 16 bits).
- r4, r6 = the found slot (found arm), or the slot one past the scanned run
  (exit arm).
- r5 = 1 (the mark value / test mask).
- r7 = the scan index that answered (0-based).
- SR.T = 1 on both arms: the found test (`(v & 1) == 0`) on the found arm, the
  `(r7 >= count)` test on the exit arm.
- r1, r2, r8..r14, r15, r16 are untouched.

## Why it needs the mutations it does

The differential alone cannot see every arm.  The corpus (all 506 cases) is
entirely *found* cases — slot 0, 1, 2 or 3 — so the exit arm (`r0 = 0`) and the
`count`-boundary arithmetic are the differential's business, not the corpus's.
The thirteen mutations that the gate catches (`tests/slot_claim_mutations.json`)
pin the found test's sense, the write width and value, the tag masking, the
0x18 stride, the found/exit answers, both T bits, the do-while entry, the exit
comparison's sense, r5, and the r3 update.

One mutation needs a fixture that makes the write width observable: with an
*occupied-at-runtime* read the mark is a u16 write of 1, and a tag whose high
byte is 0 makes a u8 write of 1 agree in the low 16 bits.  The "high byte set
free" scenario gives the found slot a tag of `0x0100`, so a u8 mark leaves the
high byte set while the u16 mark clears it — without it, the write width is
invisible.

## Chain

The generated module `seventh_c_adapter` still serves the entry and replays all
506 oracle cases; the readable port is byte-for-byte that translation.  The
windows carry the pool (count and base) and the slot array, and the leaf touches
no device register and no stack, so the oracle leg needs no supplied pool and no
sidecars — the same shape as `fdiv` and `tenpp_fill`.
