# native_clamp_pair (0x8C08DCB0)

The fight engine's two-number clamp, ported natively in `src/native/clamp_pair.c`
(`vf3_native_clamp_pair`) as a plain-C transcription of the readable port
`src/fight/clamp_pair.c` (`vf3_clamp_pair_entry`).

## Why this leaf

The readable authority is a **self-contained integer leaf** - it calls nobody
and uses no FPU - but it keeps a **frame**: it saves r13/r14 at sp-4/-8 and
restores them.  It also reads the caller's frame for two of its destinations, so
it isolates the **caller-frame read** and the **low-bound-first clamp** together.

## The body

The function takes two numbers - r4 and r5 - and writes four limited values:

- r4 into the range [pool `0x0c08dd48`, pool `0x0c08dd4a`] -> r6 and the word
  the caller's frame slot 0 points at
- r5 into the range [pool `0x0c08dd4c`, pool `0x0c08dd4e`] -> r7
- r5 into the range [pool `0x0c08dd50`, pool `0x0c08dd52`] -> the word the
  caller's frame slot 1 points at

The last two destinations are not registers: the caller leaves two words in its
own frame (at the entry sp), and those words are the addresses to write the
limits to.  The limits themselves are **signed halfwords** in the literal pool,
so the port reads the same addresses the guest reads and sign extends them.

Three details the port keeps: the guest tests the *low* bound first and only
then the high one, so a value below the low bound is never tested against the
high one (a range whose bounds are the wrong way round tells the two apart - the
test's "inverted range" scenario leans on this); the T bit the caller sees is
the one of the **last** comparison, which is the fourth limit's; and the limited
values travel in r13, r14, r1 and r4, which the guest puts back from the stack.
The third limit repeats the first, and the fourth overwrites the T bit the
second leaves.

## Evidence

The **differential** (`tests/clamp_pair_native_replay.c`, target
`vf3nativeclamp_pair`) runs the native port against the readable guest port from
the same seed over the same fourteen scenarios as the readable test - both
numbers inside, below/above every range, at the low and high bounds, negative,
both outside, and an inverted range whose bounds are the wrong way round.  The
literal pool and the caller's frame sit at the game's own addresses in one flat
buffer.  The whole region is compared byte for byte, together with the
registers (r0..r15, with r15 back on the entry sp and r13/r14 restored), the T
bit and the four limited values plus r1/r4 and the last bounds in r0/r5 against
an independent model written in the test.  **14/14 PASS.**

The **mutation gate** (`tests/clamp_pair_native_mutations.json`) applies
fourteen mutations mapped onto the native lines: three bounds from the wrong
pool entries, the first destination and the first frame destination getting the
wrong number, the limit testing the high bound first and using strict
comparisons, each number not riding in its travelling register, the stack not
popped all the way, the saved words restored to the wrong registers, the frame
words read from the wrong offsets, and the high-branch T bit set backwards.  The
differential catches **all 14**.

```text
build\vf3nativeclamp_pair.exe ->
  clamp_pair_native_replay: PASS
python tools/mutate.py --port src/native/clamp_pair.c --exe build/vf3nativeclamp_pair.exe \
    --mutations tests/clamp_pair_native_mutations.json --target vf3nativeclamp_pair \
    --keep-going
  14/14 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated == oracle` is closed per the readable
authority.

## Notes

* The leaf keeps a **small frame** (r13/r14 at sp-4/-8), so the native test also
  checks that r15 returns to the entry sp and that the saved registers come
  back.  The last saved register is restored in the delay slot of the return.
* The third limit (r1) is **dead** in the register sense - it repeats the first
  and its destination is written normally - so the register result still
  matters (r1 must carry the first number's clamp).
* The flat buffer base equals the **pool's** base (`0x0c08dd48`, the lowest
  guest address), and the buffer spans the stack window ~500 KB above it, so the
  allocation covers from the pool to `0x0c108038`.
