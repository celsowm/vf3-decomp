# The state advance (SH-4 0x8C06BEA4)

A readable port of the fight engine's state advance, and the evidence for it.

## The function

`0x8C06BEA4` is handed two words - `r4` and `r5` - and a kind in `r6`.

| the word | what it holds |
| ------- | ------------- |
| the one at `r4` | an **entry counter**, of which only the low four bits are used |
| the one at `r5` | a **count** |
| `r6` | the **kind** this call is about: zero for the first kind, anything else for the second |

The counter steps forward by one and wraps at sixteen, so the word holds the
sequence 1, 2, ... 15, 0, 1, ...  When the counter is at zero the guest does not
step it - it counts down instead:

* with a count left, the counter restarts at one and the count goes down by one;
* with the count at zero, the counter stays at zero and the count stays at zero.

So the count is spent once per lap of the counter.

The **kind flags** are a byte somewhere in memory; the pointer to it is a word
in the literal pool at `0x8C06BFBC`.  The byte holds one bit per kind - bit 0
for the first kind, bit 1 for the second.  A table in the pool (`0x8C06BFC0`)
says what kind the current entry is: the byte at the counter's position.  The
guest masks the flags with the mask of the kind it is about (`0x8C06BFAC` for
the first kind, `0x8C06BFAE` for the second), and then sets that kind's bit if
- and only if - the table has a non-zero byte there.  The other kind's bit
survives the mask, so the byte ends up saying which kinds have been seen.

The counter is only looked up when it is not zero, so on the counting path the
flags are left alone.

The port: `src/fight/state_advance.c`, registered in `src/fight/readable.c` as
`state_advance`.

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine translation
of the ROM: one label per guest PC, one C statement per executed opcode, and
the original opcode word in a comment.  That makes them a faithful disassembly
of the function they implement, so a readable port can be written against them
without the ROM.

* `tools/adapter_owner.py 0x0c06bea4 --body` - the body, in the module that
  carries it (`fifth_leaf_adapters_0.c`).
* `tools/handwritten_entries.py 0x0c06bea4` - confirms that no hand-written
  module already serves this entry, so the port is not shadowed.
* The listing below is decoded with `tools/sh4.py`, the repo's authoritative
  decoder, from the opcode words the module carries; the semantics come from
  the translator's emitted C.

The guest code, decoded:

```
0x0c06bea4  2fe6  mov.l r14,@-r15       ; the saved r14
0x0c06bea6  e20f  mov #15,r2
0x0c06bea8  2fd6  mov.l r13,@-r15       ; the saved r13
0x0c06beaa  2fc6  mov.l r12,@-r15       ; the saved r12
0x0c06beac  6742  mov.l @r4,r7          ; the entry counter
0x0c06beae  d343  mov.l @(268,pc),r3    ; the pointer to the flags byte
0x0c06beb0  2729  and r2,r7             ; only four bits of it
0x0c06beb2  6d52  mov.l @r5,r13         ; the count
0x0c06beb4  6e30  mov.b @r3,r14         ; the flags
0x0c06beb6  2778  tst r7,r7
0x0c06beb8  6c73  mov r7,r12
0x0c06beba  8f05  bf/s 0x0c06bec8       ; (its delay slot adds one to r12)
0x0c06bebc  7c01  add #1,r12
0x0c06bebe  2dd8  tst r13,r13
0x0c06bec0  8918  bt 0x0c06bef4         ; a plain bt: no delay slot
0x0c06bec2  7dff  add #-1,r13
0x0c06bec4  a016  bra 0x0c06bef4        ; (its delay slot puts r12 into r7)
0x0c06bec6  67c3  mov r12,r7
0x0c06bec8  d03d  mov.l @(244,pc),r0    ; the table
0x0c06beca  2668  tst r6,r6
0x0c06becc  027c  mov.b @(r0,r7),r2     ; the kind of the current entry
0x0c06bece  8f06  bf/s 0x0c06bede       ; (its delay slot cuts r2 to eight bits)
0x0c06bed0  672c  extu.b r2,r7
0x0c06bed2  926b  mov.w @(214,pc),r2    ; the mask of the first kind
0x0c06bed4  2778  tst r7,r7
0x0c06bed6  8d08  bt/s 0x0c06beea       ; (its delay slot masks the flags)
0x0c06bed8  2e29  and r2,r14
0x0c06beda  a005  bra 0x0c06bee8        ; (its delay slot sets r3)
0x0c06bedc  e301  mov #1,r3
0x0c06bede  9166  mov.w @(204,pc),r1    ; the mask of the second kind
0x0c06bee0  2778  tst r7,r7
0x0c06bee2  8d02  bt/s 0x0c06beea       ; (its delay slot masks the flags)
0x0c06bee4  2e19  and r1,r14
0x0c06bee6  e302  mov #2,r3
0x0c06bee8  2e3b  or r3,r14             ; the kind's bit
0x0c06beea  d234  mov.l @(208,pc),r2    ; the pointer to the flags byte, again
0x0c06beec  e30f  mov #15,r3
0x0c06beee  67c3  mov r12,r7
0x0c06bef0  2739  and r3,r7             ; the counter, wrapped at sixteen
0x0c06bef2  22e0  mov.b r14,@r2         ; the flags go back
0x0c06bef4  2472  mov.l r7,@r4          ; the counter goes back
0x0c06bef6  25d2  mov.l r13,@r5         ; the count goes back
0x0c06bef8  6cf6  mov.l @r15+,r12        ; the saved r12
0x0c06befa  6df6  mov.l @r15+,r13        ; the saved r13
0x0c06befc  000b  rts                   ; (its delay slot puts r14 back)
```

Six details of that listing are worth naming, because each one is easy to lose
in a readable port:

* **a plain `bt` has no delay slot.**  Only the `/s` forms have one.  So the
  `add #-1,r13` at `0x8C06BEC2` is the *next* instruction of the guest, not a
  delay slot: it runs only on the path that falls through - that is, only when
  the count is not zero.  The repo's own decoder says so (`tools/sh4.py`:
  *"Only the /s conditional forms plus the unconditional control transfers have
  a delay slot.  Plain bf/bt are direct jumps (no delay slot)."*), and the
  translator emits the branch that way.
* **a plain `bf` branches when the T bit is *clear*.**  The `bf/s` at
  `0x8C06BEBA` follows a `tst r7,r7`, so it leaves the guest for the table
  lookup when the counter is **not** zero - the opposite of what the `tst`
  reads like.  The same is true of the `bf/s` at `0x8C06BECE`: it goes to the
  second kind's mask when the sixth register is not zero.
* **the `/s` branches run their delay slot on both paths.**  The `add #1,r12`
  at `0x8C06BEBC` runs whether the counter is zero or not, so the counter the
  guest writes back is always one more than the masked counter.
* **the counter that goes back is masked again.**  The guest writes
  `(counter & 15) + 1`, masked to four bits, so the word's high bits are
  dropped and the counter wraps at sixteen.
* **the counting path writes one, not zero.**  The `bra` at `0x8C06BEC4` has
  `mov r12,r7` in its delay slot, and `r12` is one there - so the counter
  restarts at one.  The zero the counter held is simply dropped.
* **the saved `r14` comes back in the delay slot of the return,** after the
  return itself has started.  The guest pushes three words (`r14`, `r13`,
  `r12`) and pops three (`r12`, `r13`, and `r14` in the delay slot), so the
  stack is back where it was.

One thing about this function **cannot** be observed, and the port says so in
its own comment: the flags byte is read *signed* and the mask comes from the
pool as a *signed* halfword, but only the low byte of the and-ed value reaches
the RAM.  `&` and `|` are bitwise, so the sign extension of either operand
cannot change the byte that is written.  The port keeps the guest's own
signed reads anyway, because that is what the guest does.

Three mutations are therefore **not** in the list, because the guest's own
behaviour makes them unobservable:

* the **width of the counter's read** - the guest masks the counter to four
  bits on the very next instruction, so a halfword read gives the same counter
  as a word read;
* the **zero extension of the table byte** - the guest's `extu.b` turns the
  signed byte into an unsigned one, but the byte is only ever tested against
  zero, and a sign extension does not change whether a value is zero;
* the **sign extension of the flags byte and of the mask** - as above.

## The evidence

`tests/state_advance_replay.c` runs the readable port and the retained generated
translation of the same function over twenty-three scenarios and compares **the
whole register file (the FP registers and SR included), the return PC, the
failed PC, the out-of-window counter and every RAM byte**.  The port runs
twice: once called directly and once through the readable override, which is
how the native tick reaches it.

```
state_advance: 23 differential cases - PASS
```

The scenarios walk the counter through the table: the two kinds, a sixth
register that is neither zero nor one, a table that knows nothing about the
entry, flags that already hold the other kind's bit, flags that already hold
this kind's bit (the mask takes it away again), a counter at zero with the
count spent and with the count left, a count of one and the biggest count, a
counter that wraps at sixteen, a counter word that holds bits above the four
the guest uses (two of them, one with four bits above the four), a flags byte
that is negative and one that is all ones, a mask that is a negative halfword
and one that keeps everything, and the middle of the table.

The test also checks the result **against the fixture itself**: the counter,
the count, the flags byte, the T bit, the three saved registers, the stack
pointer, the three words the guest pushed and the return address all have to
be what the scenario says.  A differential alone is not enough, because a
fixture that is not where the guest looks makes both sides read the same wrong
bytes and agree on them.

### The test has teeth, and the mutations were checked

The mutations are checked with `tools/mutate.py`, which applies one at a time
to the port's source, rebuilds and requires the test to fail.  The list lives
in `tests/state_advance_mutations.json`, next to the test it guards.

<!--MUTATIONS-->

```
35/35 mutations caught
```

* the two masks swapped fails with the differing mask named
  (`v1 fffffffd` != `fffffffe`);
* the flags pointer read from the table's slot fails with the differing pointer
  named (`v2 0c0e0000` != `0c0d0000`);
* the table pointer read from the flags' slot fails with the differing pointer
  named (`v0 0c0d0000` != `0c0e0000`);
* the two kind bits swapped fails with the differing flags byte named
  (`ram 128 01` != `02`);
* the counter using eight bits fails with the differing register named
  (`v3 0000000f` != `000000ff`);
* the counter not masked fails outright
  (`state advance: the counter has bits above the four differs (ok 1/0/0)`);
* the counter masked to three bits fails with the differing counter named
  (`v7 00000000` != `00000008`);
* the count read as a byte fails with the differing RAM byte named
  (`ram 149 ff` != `00`);
* the count dropping by two fails with the differing RAM byte named
  (`ram 148 02` != `01`);
* the count not dropping fails with the differing RAM byte named
  (`ram 148 02` != `03`);
* the counting path and the lookup path swapped fails with the differing
  register named (`v0 0c0d0000` != `76543210`);
* the zero test using the count fails with the differing register named
  (`v0 76543210` != `0c0d0000`);
* the count's test inverted fails with the differing `SR` named
  (`v17 00000301` != `00000300`);
* the count taken when it is zero fails with the differing counter named
  (`v7 00000000` != `00000001`);
* the counter not restarting fails with the differing counter named
  (`v7 00000001` != `00000000`);
* the delay slot running only on the lookup path fails with the differing
  counter named (`v7 00000002` != `00000001`);
* the counter stepping by two fails with the differing counter named
  (`v7 00000002` != `00000003`);
* the first kind taken for the second fails with the differing mask named
  (`v1 76543211` != `fffffffd`);
* the first kind taken for one fails with the differing mask named
  (`v1 76543211` != `fffffffd`);
* the first kind's mask coming from the wrong register fails with the
  differing flags byte named (`ram 128 03` != `01`);
* the second kind's mask coming from the wrong register fails with the
  differing flags byte named (`ram 128 03` != `02`);
* the table read at the next entry fails with the differing `SR` named
  (`v17 00000300` != `00000301`);
* the kind's test inverted fails with the differing `SR` named
  (`v17 00000300` != `00000301`);
* the T bit inverted on the table's test fails with the differing `SR` named
  (`v17 00000300` != `00000301`);
* the flags masked the other way fails with the differing flags byte named
  (`ram 128 01` != `ff`);
* the kind's bit not set fails with the differing flags byte named
  (`ram 128 01` != `00`);
* the counter written back unmasked fails with the differing counter named
  (`v7 00000000` != `00000010`);
* the flags byte not written fails with the differing flags byte named
  (`ram 128 01` != `fe`);
* the flags byte going to the wrong place fails outright
  (`state advance: the first kind differs (ok 1/0/0)`);
* the counter and the count swapped fails with the differing RAM byte named
  (`ram 144 02` != `05`);
* the saved `r14` not pushed fails with the differing `r14` named
  (`v14 7654321e` != `7654321c`);
* the saved `r12` not pushed fails with the differing `r12` named
  (`v12 7654321c` != `7654321d`);
* the frame of the wrong size fails with the differing `r12` named
  (`v12 7654321c` != `7654321d`);
* the saved `r14` not coming back fails with the differing `r14` named
  (`v14 7654321e` != `0c0abcde`);
* the return address not taken fails with the differing return address named
  (`pc 0c0abcde/0c108000 failed 00000000/00000000`).

This is the pattern `tests/state_helpers_replay.c` established: the generated
translation stays in the tree as the reference, and the readable port is proved
against it.

**Caveat.** Two things are missing here, and they are different.

* The oracle corpora live under `extract/`, and that tree is gone from this
  checkout (see [artifact_gap](artifact_gap.md)).  The oracle replay of this
  entry could not be re-run, so the differential above stands on the generated
  translation rather than on a fresh oracle run.
* `0x8C06BEA4` has **no row in `docs/decomp_status.csv`** - no corpus was ever
  captured for it, so unlike the band probe (`0x8C0B0F28`, six corpora and 1464
  cases) the generated translation of *this* function was never itself proved
  against the oracle.  The chain that holds here is **readable port == generated
  translation**; the third link, *== oracle*, is missing for this entry and
  cannot be closed offline.

A session that has the corpora back should capture a corpus for `0x8C06BEA4`
and run the replay gate for it before the port is trusted in the native tick.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* The mask, the table pointer and the flags pointer are read from the pool, at
  the addresses the guest reads them from.
* The counter is masked to four bits before it is used, and the value written
  back is `(masked + 1) & 15`.
* The plain `bt` at `0x8C06BEC0` has no delay slot, so the count is only
  decremented on the path that falls through.
* The `/s` branches run their delay slot on both paths.
* The flags byte is only written on the lookup path, and the kind's bit only
  goes in when the table has a non-zero byte at the counter's position.
* The saved `r14` comes back in the delay slot of the return, and the stack is
  back where it was.

## The unknown

What an "entry" is, what the table holds and who calls this are not recoverable
offline: the pool's values and the code live in the game's own image, which is
under `extract/`.  The port therefore reads the same addresses the guest reads,
and what the counter counts and what the two kind bits stand for stays open
until the image is back.
