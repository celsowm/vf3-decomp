# The record kind (SH-4 0x8C078044)

A readable port of the fight engine's record-kind step, and the evidence for it.

## The function

`0x8C078044` is handed a record - `r5` is its base and `r7` an index into it -
and the flag word the caller left in its frame.  Three bytes of the record
matter:

| the byte | where | what it holds |
| ------- | ----- | ------------- |
| the **kind** | the pool's first offset (`0x1BB0`) plus the index | how many more times the record still has to be worked on; zero means "no kind yet" |
| the **state** | the pool's second offset (`0x1BB2`) plus the index | the low four bits of the flag word |
| the **source** | the pool's third offset (`0x1B83`) | the byte that gets copied around |

The pool's values, as the image holds them:

| the slot | the address | the value |
| ------- | ----------- | -------- |
| the kind offset | `0x8C07815A` | `0x1BB0` |
| the state offset | `0x8C07815C` | `0x1BB2` |
| the source offset | `0x8C07815E` | `0x1B83` |
| the destination offset | `0x8C078160` | `0x1BB4` |
| the extra flag bit | `0x8C078162` | `0x0100` |
| the gate mask | `0x8C07816C` | `0x40000000` |

The port reads all six at run time; only the gap unit (below) has them baked
in.

### When the record has no kind

The kind byte is zero.  The flag word's low four bits decide:

* **zero or fifteen** - the record is already complete.  The source byte is
  copied and nothing else happens.
* **anything else** - the record gets a kind: the kind byte becomes one, the
  state byte takes the four bits, and the flag word's low four bits are
  cleared.

Either way the source byte is copied afterwards, to two places: the
destination offset plus the index, and the source offset plus 51.

### When the record has a kind

The guest looks at the state byte and at two more words of the caller's
frame.  The **gate** mask is tested against the first of them:

* when the caller's word has one of the gate's bits, the guest gives up on
  the record and goes to the second block;
* when it has none of them, three further tests have to hold: the state byte
  is **four**, the caller's mode word has bit two **clear**, and the flag
  word's low four bits are **one**.  When they do, the source byte is copied
  and the kind byte is cleared.

### The second block

The state byte joins the flag word's low four bits.  If the state byte is six
*and* the mode word's low four bits are two, the extra flag bit (`0x0100`) is
added to the flag word.  Then:

* the merged value is fifteen, or the kind byte was one - the kind is cleared
  and the flag word keeps the merged value;
* otherwise the kind byte **counts down**, the state byte takes the merged
  value, and the flag word's low four bits are cleared.

The port: `src/fight/record_kind.c`, registered in `src/fight/readable.c` as
`record_kind`.

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine translation
of the ROM: one label per guest PC, one C statement per executed opcode, and
the original opcode word in a comment.  That makes them a faithful disassembly
of the function they implement, so a readable port can be written against them
without the ROM.

* `tools/adapter_owner.py 0x0c078044 --all` - the body, in the module that
  carries it (`vf3_fifth_leaf_extra_adapter.c`); it is carried twice there,
  and both copies agree.
* `tools/handwritten_entries.py 0x0c078044` - confirms that no hand-written
  module already serves this entry, so the port is not shadowed.
* The listing below is decoded with `tools/sh4.py`, the repo's authoritative
  decoder, from the opcode words the module carries; the semantics come from
  the translator's emitted C.

The guest code, decoded:

```
0x0c078044  2fe6  mov.l r14,@-r15       ; the saved r14
0x0c078046  e40f  mov #15,r4
0x0c078048  2fd6  mov.l r13,@-r15       ; the saved r13
0x0c07804a  9e86  mov.w @(268,pc),r14   ; the kind offset
0x0c07804c  56f2  mov.l @(8,r15),r6     ; the flag word
0x0c07804e  3e5c  add r5,r14
0x0c078050  3e7c  add r7,r14
0x0c078052  6ee0  mov.b @r14,r14         ; the kind byte
0x0c078054  6eec  extu.b r14,r14
0x0c078056  2ee8  tst r14,r14
0x0c078058  8f1a  bf/s 0x0c078090        ; (its delay slot masks r4 with r6)
0x0c07805a  2469  and r6,r4
0x0c07805c  2448  tst r4,r4
0x0c07805e  890d  bt 0x0c07807c         ; a plain bt: no delay slot
0x0c078060  6043  mov r4,r0
0x0c078062  880f  cmp/eq #15,r0
0x0c078064  890a  bt 0x0c07807c
0x0c078066  9278  mov.w @(240,pc),r2    ; the kind offset, again
0x0c078068  e301  mov #1,r3
0x0c07806a  325c  add r5,r2
0x0c07806c  327c  add r7,r2
0x0c07806e  2230  mov.b r3,@r2           ; the record gets a kind
0x0c078070  e3f0  mov #-16,r3
0x0c078072  9273  mov.w @(230,pc),r2    ; the state offset
0x0c078074  2639  and r3,r6             ; the flag word's low four bits go
0x0c078076  325c  add r5,r2
0x0c078078  327c  add r7,r2
0x0c07807a  2240  mov.b r4,@r2           ; the state byte
0x0c07807c  906f  mov.w @(222,pc),r0    ; the source offset
0x0c07807e  936f  mov.w @(222,pc),r3    ; the destination offset
0x0c078080  045c  mov.b @(r0,r5),r4      ; the byte that is copied
0x0c078082  7033  add #51,r0
0x0c078084  335c  add r5,r3
0x0c078086  373c  add r3,r7
0x0c078088  644c  extu.b r4,r4
0x0c07808a  2740  mov.b r4,@r7           ; the first copy
0x0c07808c  a03c  bra 0x0c078108          ; (its delay slot makes the second)
0x0c07808e  0544  mov.b r4,@(r0,r5)
0x0c078090  9d64  mov.w @(200,pc),r13   ; the state offset
0x0c078092  d336  mov.l @(216,pc),r3    ; the gate mask
0x0c078094  3d5c  add r5,r13
0x0c078096  52f3  mov.l @(12,r15),r2    ; the caller's gate word
0x0c078098  3d7c  add r7,r13
0x0c07809a  6dd0  mov.b @r13,r13         ; the state byte
0x0c07809c  2238  tst r3,r2
0x0c07809e  8f13  bf/s 0x0c0780c8        ; (its delay slot cuts r13 to eight bits)
0x0c0780a0  6ddc  extu.b r13,r13
0x0c0780a2  60d3  mov r13,r0
0x0c0780a4  8804  cmp/eq #4,r0
0x0c0780a6  8b0f  bf 0x0c0780c8
0x0c0780a8  50f4  mov.l @(16,r15),r0    ; the caller's mode word
0x0c0780aa  c804  tst #4,r0
0x0c0780ac  8b0c  bf 0x0c0780c8
0x0c0780ae  6043  mov r4,r0
0x0c0780b0  8801  cmp/eq #1,r0
0x0c0780b2  8b09  bf 0x0c0780c8
0x0c0780b4  9053  mov.w @(166,pc),r0    ; the source offset
0x0c0780b6  9353  mov.w @(166,pc),r3    ; the destination offset
0x0c0780b8  0e5c  mov.b @(r0,r5),r14     ; the byte that is copied
0x0c0780ba  7033  add #51,r0
0x0c0780bc  335c  add r5,r3
0x0c0780be  337c  add r7,r3
0x0c0780c0  6eec  extu.b r14,r14
0x0c0780c2  23e0  mov.b r14,@r3          ; the first copy
0x0c0780c4  a01a  bra 0x0c0780fc         ; (its delay slot makes the second)
0x0c0780c6  05e4  mov.b r14,@(r0,r5)
0x0c0780c8  60d3  mov r13,r0
0x0c0780ca  8806  cmp/eq #6,r0
0x0c0780cc  8b05  bf 0x0c0780da
0x0c0780ce  50f4  mov.l @(16,r15),r0    ; the caller's mode word
0x0c0780d0  c90f  and #15,r0
0x0c0780d2  8802  cmp/eq #2,r0
0x0c0780d4  8b01  bf 0x0c0780da
0x0c0780d6  9244  mov.w @(136,pc),r2    ; the extra flag bit
0x0c0780d8  262b  or r2,r6
0x0c0780da  24db  or r13,r4             ; the merged value
0x0c0780dc  6043  mov r4,r0
0x0c0780de  880f  cmp/eq #15,r0
0x0c0780e0  890c  bt 0x0c0780fc
0x0c0780e2  4e10  dec r14               ; the kind counts down
0x0c0780e4  890a  bt 0x0c0780fc
0x0c0780e6  9338  mov.w @(112,pc),r3    ; the kind offset
0x0c0780e8  335c  add r5,r3
0x0c0780ea  337c  add r7,r3
0x0c0780ec  23e0  mov.b r14,@r3          ; the kind goes back
0x0c0780ee  e3f0  mov #-16,r3
0x0c0780f0  9234  mov.w @(104,pc),r2    ; the state offset
0x0c0780f2  325c  add r5,r2
0x0c0780f4  372c  add r2,r7
0x0c0780f6  2740  mov.b r4,@r7           ; the merged value is the state
0x0c0780f8  a006  bra 0x0c078108         ; (its delay slot clears the flag word)
0x0c0780fa  2639  and r3,r6
0x0c0780fc  912d  mov.w @(90,pc),r1     ; the kind offset
0x0c0780fe  e300  mov #0,r3
0x0c078100  264b  or r4,r6
0x0c078102  315c  add r5,r1
0x0c078104  371c  add r1,r7
0x0c078106  2730  mov.b r3,@r7           ; the kind goes back to zero
0x0c078108  6df6  mov.l @r15+,r13        ; the saved r13
0x0c07810a  6063  mov r6,r0             ; the flag word is the answer
0x0c07810c  000b  rts                   ; (its delay slot puts r14 back)
```

Seven details of that listing are worth naming, because each one is easy to
lose in a readable port:

* **a plain `bf` branches when the T bit is *clear*.**  The `bf` at
  `0x8C0780AC` follows `tst #4,r0`, so it leaves for the second block when the
  mode word's bit two is **set** - the three tests above need it *clear*.
  The first version of this port read it the other way round, and the
  differential caught it.
* **the plain `bt` branches when the T bit is *set*.**  The `bt` at
  `0x8C0780E4` follows the `dec r14`, so the kind is cleared when the
  decremented kind byte is zero - that is, when the kind byte *was* one.
* **the `/s` branches run their delay slot on both paths.**  The `and r6,r4`
  at `0x8C07805A` runs whether the kind byte is zero or not, so the flag
  word's low four bits are masked before the branch is resolved.  The
  `extu.b r13,r13` at `0x8C0780A0` does the same for the state byte.
* **a plain `bf`/`bt` has no delay slot**, so the instruction after it is a
  block of its own (the repo's decoder says so: *"Only the /s conditional
  forms plus the unconditional control transfers have a delay slot.  Plain
  bf/bt are direct jumps (no delay slot)."*).
* **the two copies leave the address they write to in different registers.**
  The first copy (at `0x8C07807C`) leaves it in `r7` and the byte in `r4`;
  the second (at `0x8C0780B4`) leaves it in `r3` and the byte in `r14`.  The
  guest's own register file shows the difference, so the port has to keep it.
* **`add r7,r3` is `r3 += r7`.**  The SH-4's `add Rm,Rn` puts the result in
  `Rn` - the *second* operand.  The two countdown blocks at `0x8C0780BE` and
  `0x8C0780EA` use it, and getting it backwards moves the write address and
  the answer's `r7`.
* **the caller's frame words sit at the entry stack pointer + 0, + 4 and + 8.**
  The callee's prologue takes its own `r15` eight bytes below the entry, and
  it reads the words at `@(8,r15)`, `@(12,r15)` and `@(16,r15)` - so the
  *last* word the caller pushed is the first one the callee reads.  The
  caller (at `0x8C0770C2`) pushes the three words right to left, which is the
  usual convention.

One thing about this function **cannot** be observed, and the port says so in
its own comment: the **sign extension** of the bytes it reads.  The guest's
`mov.b` sign-extends, but every byte it reads is masked back to eight bits
(`extu.b`) before it is used, and the only place the mask is not applied
again is the second copy's `r14` - which the return overwrites and which
reaches the RAM only through a byte store.  So the sign extension of the
source byte, of the kind byte and of the state byte cannot change anything
observable.

Three more mutations are **not** in the list, for the same reason - the guest
overwrites the T bit before it returns, so the value those three tests leave
behind is never the caller's:

* the **T bit of the kind test** (`tst r14,r14` at `0x8C078056`): the guest
  writes the T bit again at `0x8C07805C`, on both paths;
* the **T bit of the gate test** (`tst r3,r2` at `0x8C07809C`): it is
  overwritten at `0x8C0780A4` or at `0x8C0780CA`, on both paths;
* the **T bit of the mode test** (`tst #4,r0` at `0x8C0780AA`): it is
  overwritten at `0x8C0780B0` or at `0x8C0780CA`, on both paths.

The T bit that the caller *does* see is the one from the last test on the
path the guest took, and the port reproduces it.

## The evidence

`tests/record_kind_replay.c` runs the readable port and the retained generated
translation of the same function over thirty scenarios and compares **the
whole register file (the FP registers and SR included), the return PC, the
failed PC, the out-of-window counter and every RAM byte**.  The port runs
twice: once called directly and once through the readable override, which is
how the native tick reaches it.

```
record_kind: 30 differential cases - PASS
```

The scenarios walk the record through every branch: no kind yet (with the
flag word empty, with all four bits, with one bit, with two bits, with the
top bit, with the bits and more, with the index zero and with a source byte
above `0x7F`), a kind (the gate open and closed, the state byte four, six and
a big byte, the kind byte one, three and a big one, the mode word's bit two
set and clear, the mode word's low nibble two and not two, the merged value
fifteen, the flag word with other bits).

The test also checks the result **against the fixture itself**: the flag
word, the record's three bytes, the T bit, the two saved registers, the stack
pointer, the two words the guest pushed and the return address all have to
be what the scenario says.  A differential alone is not enough, because a
fixture that is not where the guest looks makes both sides read the same wrong
bytes and agree on them.

### The fourth arm: the gap unit, and two bugs in it

`src/fight/g78044.c` is the tree's older hand-written port of *this same
function* - a "gap unit", proved against the oracle
(`docs/decomp_status.csv`: *"oracle-verified (RAM shadow diff)"*, eight cases
over five windows).  It is not wired into the dispatcher, and it bakes the
literal pool's values in, so the fixture here uses the values the real image
holds.

Running it against the same fixture showed that it did **not** agree with the
generated translation - and the reason was in the gap unit, not in the new
port.  Three faults, all of them in `g78044.c`:

1. **The six stack reads were eight bytes too high.**  The gap unit kept the
   caller's words at `X + 16`, `X + 20` and `X + 24` with `X = in_r15 - 8`.
   The guest reads them at `@(8,r15)`, `@(12,r15)` and `@(16,r15)` off the
   *live* stack pointer - so they sit at the **entry** stack pointer + 0, + 4
   and + 8.  `src/fight/af734.c`, another gap unit, reads its caller's words
   the same way (`o->r13 = g_rd32(ram, in_r15)`), and its 64 oracle cases
   confirmed that.  The reads are now relative to the live `r15`.
2. **The same eight bytes were wrong in the two pops.**  `mov.l @r15+,r13`
   and `mov.l @r15+,r14` read the callee's own two pushed words at the live
   `r15` and at `r15 + 4`; the gap unit read them eight bytes higher.
3. **Two `add` instructions had their operands the wrong way round.**  At
   `0x8C0780BE` and at `0x8C0780EA` the guest executes `add r7,r3`, which is
   `r3 += r7`; the gap unit did `r7 += r3`.  That moved the write address
   of the copied byte and the countdown's answer `r7`.

The gap unit's oracle cases cannot be re-run here (the cases file lives under
`extract/`, which is gone - see [artifact_gap](artifact_gap.md)), but the
fixes are *oracle preserving* for them: the old port matched the oracle's
recorded exit state, so the words it read and the words the guest reads
agreed in every bit the function looks at; the corrected port reads the
guest's words and therefore produces the same answers.

With the three faults fixed, the gap unit and the readable port agree with
the generated translation on all thirty scenarios, and the chain for this
entry is **readable port == generated translation == gap unit == oracle**.

### The test has teeth, and the mutations were checked

The mutations are checked with `tools/mutate.py`, which applies one at a time
to the port's source, rebuilds and requires the test to fail.  The list lives
in `tests/record_kind_mutations.json`, next to the test it guards.

<!--MUTATIONS-->

```
49/49 mutations caught
```

* the kind and state offsets swapped fails with the differing register named
  (`v2 76543212` != `0c201bb0`);
* the source and destination offsets swapped fails with the differing register
  named (`v3 0c201bb4` != `0c201b83`);
* the extra bit taken from the source offset fails with the differing flag
  word named (`v0 00000100` != `00001b80`);
* the gate mask taken from the destination offset fails with the differing
  answer named (`v0 00000000` != `00000001`);
* the second place off by one fails with the differing RAM byte named
  (`ram 7126 22` != `ee`);
* the nibble cut to three bits fails with the differing answer named
  (`v0 00000000` != `00000008`);
* the flag word not masked to four bits fails with the differing answer named
  (`v0 00000000` != `00000001`);
* the delay slot replacing the mask fails with the differing RAM byte named
  (`ram 7123 02` != `12`);
* the delay slot running on one path only fails with the differing register
  named (`v4 00000011` != `0000001f`);
* the kind test inverted fails with the differing register named
  (`v2 76543212` != `0c201bb2`);
* the T bit inverted on the empty test fails with the differing `SR` named
  (`v17 00000301` != `00000300`);
* the empty flag word taking the new-kind path fails with the differing
  register named (`v2 76543212` != `0c201bb3`);
* the T bit inverted on the fifteen test fails with the differing `SR` named
  (`v17 00000301` != `00000300`);
* the fifteen taking the new-kind path fails with the differing answer named
  (`v0 0000000f` != `00000000`);
* the new kind being two fails with the differing RAM byte named
  (`ram 7121 01` != `02`);
* the flag word not cleared fails with the differing answer named
  (`v0 00000000` != `00000001`);
* the gate test inverted fails with the differing answer named
  (`v0 00000001` != `00000000`);
* the state test inverted fails with the differing answer named
  (`v0 00000000` != `00000001`);
* the mode-bit test inverted fails with the differing answer named
  (`v0 00000001` != `00000000`);
* the one test inverted fails with the differing answer named
  (`v0 00000001` != `00000000`);
* the six test inverted fails with the differing flag word named
  (`v0 00000100` != `00000000`);
* the two test inverted fails with the differing flag word named
  (`v0 00000100` != `00000000`);
* the extra bit cleared instead of set fails with the differing flag word
  named (`v0 00000100` != `00000000`);
* the state joined with `and` fails with the differing register named
  (`v4 00000011` != `00000001`);
* the fifteen test inverted fails with the differing answer named
  (`v0 00000000` != `00000011`);
* the kind dropping by two fails with the differing answer named
  (`v0 00000000` != `00000011`);
* the kind not dropping fails with the differing RAM byte named
  (`ram 7121 01` != `02`);
* the kind test after the drop inverted fails with the differing answer named
  (`v0 00000000` != `00000011`);
* the T bit inverted on the kind drop fails with the differing `SR` named
  (`v17 00000300` != `00000301`);
* the first copy reading the destination fails with the differing register
  named (`v4 00000022` != `00000000`);
* the first copy masked to a nibble fails with the differing register named
  (`v4 00000022` != `00000002`);
* the first copy writing twice to the same place fails with the differing RAM
  byte named (`ram 7125 22` != `ee`);
* the first copy losing the index fails with the differing register named
  (`v7 0c201bb5` != `0c201bb4`);
* the second copy writing the flag word fails with the differing RAM byte
  named (`ram 7125 22` != `01`);
* the second copy losing the index fails with the differing RAM byte named
  (`ram 7124 00` != `22`);
* the kind byte masked to a nibble fails with the differing answer named
  (`v0 00000000` != `00000011`);
* the state byte masked to a nibble fails with the differing register named
  (`v4 00000011` != `00000001`);
* the countdown losing the index fails with the differing RAM byte named
  (`ram 7120 00` != `01`);
* the countdown writing the merged value as the kind fails with the differing
  RAM byte named (`ram 7121 01` != `11`);
* the kind cleared at the state offset fails with the differing register named
  (`v1 0c201bb0` != `0c201bb2`);
* the cleared kind losing the index fails with the differing register named
  (`v7 0c201bb1` != `0c201bb0`);
* the answer taken from the wrong register fails with the differing answer
  named (`v0 00000000` != `00000022`);
* the return address not taken fails with the differing return address named
  (`pc 0c0abcde/0c108000 failed 00000000/00000000`);
* the saved `r14` not pushed fails with the differing `r14` named
  (`v14 7654321e` != `7654321c`);
* the frame of the wrong size fails with the differing register named
  (`v13 7654321d` != `7654321e`);
* the flag word from the wrong frame word fails with the differing answer
  named (`v0 0000000f` != `00000000`);
* the gate word from the wrong frame word fails with the differing register
  named (`v2 00000000` != `00000001`);
* the mode word from the wrong frame word fails with the differing answer
  named (`v0 00000000` != `00000001`);
* the saved `r13` not coming back fails with the differing `r13` named
  (`v13 7654321d` != `0c0abcde`).

This is the pattern `tests/state_helpers_replay.c` established: the generated
translation stays in the tree as the reference, and the readable port is proved
against it.

**Caveat.** The oracle corpora live under `extract/`, and that tree is gone
from this checkout (see [artifact_gap](artifact_gap.md)), so the oracle replay
of this entry could not be re-run here.  What *is* in the tree is the gap
unit's proof - eight RAM cases over five windows, recorded when the corpora
were there - and the gap unit is now checked, byte for byte, against the
readable port and the generated translation.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* The six pool values are read from the addresses the guest reads them from.
* The flag word's low four bits are masked before the branch is resolved,
  and the mask runs on both paths of the `/s` branch.
* The three frame words are read at the *entry* stack pointer + 0, + 4 and + 8.
* The plain `bf`s branch when the T bit is clear, so the three tests fall
  through when they hold; the plain `bt`s branch when the T bit is set.
* The two copies leave the address they write to in `r7` and in `r3`.
* The `dec r14` decrements the *kind* byte, and its result is what the
  countdown writes back.
* The saved `r14` comes back in the delay slot of the return, and the stack is
  back where it was.

## The unknown

What a "record" is, what the kind byte counts and what the flag word's bits
stand for are not recoverable offline: the pool's values live in the game's
own image, which is under `extract/`.  The port therefore reads the same
addresses the guest reads, and what the three bytes mean stays open until the
image is back.
