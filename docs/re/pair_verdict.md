# The pair verdict (SH-4 0x8C074E7C)

A readable port of the fight engine's pair verdict, and the evidence for it.

## The function

`0x8C074E7C` is handed two structures - in `r4` and `r5` - and writes a word
into the first one: zero, or minus one.  Both callers pass the same pair of
structures in both orders, so the answer depends on which one is the first.

Both structures keep a word at the same offset, `0x48`.  The **gate** is two
tests on the *second* structure's word:

* it has to share a bit with the first mask in the pool (`0x8C074F60`), and
* it must **not** share a bit with the second one (`0x8C074F64`).

The two gates have opposite polarities, and that is the guest's own shape: the
first is a `bt/s` and the second a plain `bf`.

If the gate passes, the first structure's word is masked with two more masks
from the pool (`0x8C074F68` and `0x8C074F6C`), and the byte the second
structure holds at the offset in the pool (`0x8C074F50`) decides the rest.
The byte can be 2, 4 or 5, and the first structure has to have a field (the
offset in the pool is `0x8C074F52`) for the answer to be anything but zero.
The last mask in the pool (`0x8C074F70`) has the last word.

The port: `src/fight/pair_verdict.c`, registered in `src/fight/readable.c` as
`pair_verdict`.

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine translation
of the ROM: one label per guest PC, one C statement per executed opcode, and
the original opcode word in a comment.  That makes them a faithful disassembly
of the function they implement, so a readable port can be written against them
without the ROM.

* `tools/adapter_owner.py 0x0c074e7c --body` - the body, in the module that
  carries it (`eighth_adapters`; `motion_adapters` carries a copy of the same
  code, and the router serves the first module that owns the PC).
* `tools/handwritten_entries.py 0x0c074e7c` - confirms that no hand-written
  module already serves this entry, so the port is not shadowed.
* The listing below is decoded with `tools/sh4.py`, the repo's authoritative
  decoder, from the opcode words the module carries; the semantics come from
  the translator's emitted C.

The guest code, decoded:

```
0x0c074e7c  e048  mov   #72,r0
0x0c074e7e  2fd6  mov.l r13,@-r15
0x0c074e80  064e  mov.l @(r0,r4),r6        ; the first structure's word
0x0c074e82  ed00  mov   #0,r13
0x0c074e84  075e  mov.l @(r0,r5),r7        ; the second structure's word
0x0c074e86  9063  mov.w @(198,pc),r0       ; the byte's offset
0x0c074e88  d335  mov.l @(212,pc),r3       ; the first mask
0x0c074e8a  055c  mov.b @(r0,r5),r5       ; the byte, sign extended
0x0c074e8c  2378  tst   r7,r3
0x0c074e8e  8d23  bt/s  0x0c074ed8
0x0c074e90  655c  extu.b r5,r5             ; (the branch's delay slot)
0x0c074e92  d234  mov.l @(208,pc),r2       ; the second mask
0x0c074e94  2728  tst   r2,r7
0x0c074e96  8b1f  bf    0x0c074ed8
0x0c074e98  d733  mov.l @(204,pc),r7       ; the third mask
0x0c074e9a  d134  mov.l @(208,pc),r1       ; the fourth mask
0x0c074e9c  2769  and   r6,r7
0x0c074e9e  2778  tst   r7,r7
0x0c074ea0  8d08  bt/s  0x0c074eb4
0x0c074ea2  2169  and   r6,r1              ; (the branch's delay slot)
0x0c074ea4  2118  tst   r1,r1
0x0c074ea6  8b05  bf    0x0c074eb4
0x0c074ea8  6053  mov   r5,r0
0x0c074eaa  8804  cmp/eq #4,r0
0x0c074eac  8902  bt    0x0c074eb4
0x0c074eae  6053  mov   r5,r0
0x0c074eb0  8805  cmp/eq #5,r0
0x0c074eb2  8b10  bf    0x0c074ed6
0x0c074eb4  904d  mov.w @(154,pc),r0       ; the field's offset
0x0c074eb6  034e  mov.l @(r0,r4),r3
0x0c074eb8  2338  tst   r3,r3
0x0c074eba  8b0d  bf    0x8c074ed8
0x0c074ebc  2778  tst   r7,r7
0x0c074ebe  8b0b  bf    0x8c074ed8
0x0c074ec0  6053  mov   r5,r0
0x0c074ec2  8802  cmp/eq #2,r0
0x0c074ec4  8902  bt    0x8c074ecc
0x0c074ec6  6053  mov   r5,r0
0x0c074ec8  8805  cmp/eq #5,r0
0x0c074eca  8b05  bf    0x8c074ed8
0x0c074ecc  2118  tst   r1,r1
0x0c074ece  8b02  bf    0x8c074ed6
0x0c074ed0  d227  mov.l @(156,pc),r2       ; the last mask
0x0c074ed2  2628  tst   r2,r6
0x0c074ed4  8900  bt    0x8c074ed8
0x0c074ed6  edff  mov   #-1,r13
0x0c074ed8  903c  mov.w @(120,pc),r0       ; the result's offset
0x0c074eda  04d6  mov.l r13,@(r0,r4)
0x0c074edc  000b  rts                     ; (its delay slot puts r13 back)
0x0c074ede  6df6  mov.l @r15+,r13
```

The tree, in words:

```
the gate: the second structure's word shares a bit with the first mask and
          none with the second one, or the answer is zero

c = the third mask and the first structure's word
d = the fourth mask and the first structure's word

if c is zero:                       the first arm
    the field of the first structure has to be *empty*, and c has to be clear
    of it - and c is zero, so the tree goes on
    if the byte is 2 or 5:
        if d is not zero -> the answer is minus one
        else if the last mask and the first structure's word share a bit
            -> the answer is minus one
else:                              the second arm
    the field of the first structure has to be empty, but c is not clear of
    it, so the tree stops there whatever the field says
    if d is zero and the byte is neither 4 nor 5 -> the answer is minus one
```

Five details of that listing are worth naming, because each one is easy to
lose in a readable port:

* **the two gates have opposite polarities.**  The first is a `bt/s`, so the
  tree goes on when the word *shares* a bit with the first mask; the second is
  a plain `bf`, so the tree goes on when the word shares *no* bit with the
  second mask.  A port that makes both of them the same way round answers the
  opposite of the guest on half the inputs.
* **the byte is read signed and then masked to eight bits.**  The `mov.b`
  sign extends it and the delay slot of the branch that follows masks it back
  to an unsigned byte, so the value the tree compares is the unsigned one.
* **the two masks are and-ed with the first structure's word in the delay
  slot of a branch,** so the and happens on both paths.
* **the answer is minus one or zero,** and the word it goes into is the one
  at the offset in the pool - the port writes the *result*, not the answer
  the function returns: the function returns nothing, and the saved `r13`
  comes back in the delay slot of the return.
* **the field of the first structure has to be *empty*.**  The test is
  `tst r3,r3` followed by a plain `bf`, and a plain `bf` branches when the T
  bit is *clear* - so a field that is not zero sends the tree away.  The
  first version of the port had this the other way round, and the
  differential caught it: the port read the last mask where the reference
  stopped at the field.
* **the T bit the caller sees is the one of the last test the guest made,**
  and the tree has several arms that end on different tests, so the port has
  to follow the tree's order rather than compute the answer and set the bit
  once.

## The evidence

`tests/pair_verdict_replay.c` runs the readable port and the retained
generated translation of the same function over nineteen scenarios and
compares **the whole register file (the FP registers and SR included), the
return PC, the failed PC, the out-of-window counter and every RAM byte**.
The port runs twice: once called directly and once through the readable
override, which is how the native tick reaches it.

```
pair_verdict: 19 differential cases - PASS
```

The scenarios walk the tree: both gates failing, each of the two arms, the
byte being 2, 3, 4 and 5, the field of the first structure being empty and
not, the fourth mask and the last mask with and without a bit in common, a
byte above 127 (so the sign extension and the mask that follows it show), a
negative offset in the pool and a result word that is not empty.

The test also checks the result **against the fixture itself**: the word the
guest wrote, the offset it wrote it to, the saved register, the stack pointer
and the T bit all have to be what the scenario says.  The expected word and
the expected T bit come from a second implementation of the tree in the test,
written from the listing and not from the port.  A differential alone is not
enough, because a fixture that is not where the guest looks makes both sides
read the same wrong bytes and agree on them.

### The test has teeth, and the mutations were checked

The mutations are checked with `tools/mutate.py`, which applies one at a time
to the port's source, rebuilds and requires the test to fail.  The list lives
in `tests/pair_verdict_mutations.json`, next to the test it guards.

<!--MUTATIONS-->

* the byte's offset read from the field's slot fails with the differing byte
  named (`v5 00000002` != `00000000`);
* the field's offset read from the result's slot fails with the differing mask
  named (`v2 00000002` != `00000010`);
* the result's offset read from the byte's slot fails with the differing
  offset named (`v0 00000018` != `00000010`);
* the first mask read from the second one's slot fails with the differing
  mask named (`v3 00000001` != `00000002`);
* the second mask read from the first one's slot fails with the differing
  mask named (`v2 00000002` != `00000001`);
* the third mask read from the fourth one's slot fails with the differing
  mask named (`v7 00000000` != `00000008`);
* the fourth mask read from the third one's slot fails with the differing
  mask named (`v1 00000008` != `00000000`);
* the last mask read from the first one's slot fails with the differing mask
  named (`v2 00000010` != `00000001`);
* the word's offset not the guest's fails with the differing word named
  (`v6 00000004` != `00000000`);
* the pool's halfwords read unsigned fails outright
  (`pair verdict: a negative offset differs (ok 1/0/0)`);
* the first gate inverted fails with the differing mask named
  (`v1 76543211` != `00000000`);
* the second gate inverted fails with the differing mask named
  (`v1 76543211` != `00000000`);
* the T bit of the first gate fails with the differing `SR` named
  (`v17 00000301` != `00000300`);
* the T bit of the second gate fails with the differing `SR` named
  (`v17 00000300` != `00000301`);
* the byte not masked to eight bits fails with the differing byte named
  (`v5 000000c8` != `00000048`);
* the third mask not and-ed with the first structure's word fails with the
  differing mask named (`v2 00000010` != `00000002`);
* the fourth mask not and-ed with the first structure's word fails with the
  differing mask named (`v1 00000000` != `00000008`);
* the first structure's word read from the second structure fails with the
  differing word named (`v6 00000004` != `00000010`);
* the second structure's word read from the first structure fails with the
  differing word named (`v7 00000010` != `00000004`);
* the byte read from the first structure fails with the differing byte named
  (`v5 00000002` != `00000000`);
* the field read from the second structure fails outright
  (`pair verdict: the first arm, the byte is 2 differs (ok 1/0/0)`);
* the answer written to the second structure fails outright
  (`pair verdict: the first gate fails differs (ok 1/0/0)`);
* the deep test always answering zero fails with the differing RAM byte named
  (`ram 92 ff` != `00`);
* the last mask never answering minus one fails with the differing RAM byte
  named (`ram 92 ff` != `00`);
* the second arm never answering minus one fails with the differing RAM byte
  named (`ram 92 ff` != `00`);
* the byte 2 tested as 4 fails with the differing mask named
  (`v2 00000010` != `00000002`);
* the byte 5 tested as 4 fails with the differing `SR` named
  (`v17 00000300` != `00000301`);
* the byte 4 tested as 2 fails with the differing field named
  (`v3 00000000` != `00000001`);
* the field's test inverted fails with the differing mask named
  (`v2 00000010` != `00000002`);
* the field's test always passing fails with the differing mask named
  (`v2 00000002` != `00000010`);
* the saved `r13` not put back fails with the differing `r13` named
  (`v13 7654321d` != `00000000`);
* the saved `r13` not pushed fails with the differing `r13` named
  (`v13 7654321d` != `00000000`);
* the stack word not dropped fails with the differing stack pointer named
  (`v15 0c108000` != `0c107ffc`);
* the return address not set fails with the differing return address named
  (`pc 0c0abcde/00000000`).

One mutation is **not** in the list, because the guest's own behaviour makes
it unobservable: the second test of the field's block (`tst r7,r7`) sets the
T bit, and that bit is either overwritten by the test of the byte that
follows it (in the first arm) or is clear in both the guest's and the
mutated version (in the second arm, where `r7` and `r6` are both not zero).

This is the pattern `tests/state_helpers_replay.c` established: the generated
translation stays in the tree as the reference, and the readable port is proved
against it.

**Caveat.** The oracle corpora live under `extract/`, and that tree is gone
from this checkout (see [artifact_gap](artifact_gap.md)).  The oracle replay of
this entry could not be re-run, so the differential above stands on the
generated translation rather than on a fresh oracle run.  A session that has
the corpora back should re-run the replay gate for `0x8C074E7C` before the
port is trusted in the native tick.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* The gate is two tests with opposite polarities.
* The byte is the unsigned one.
* The two masks are and-ed with the first structure's word on both paths.
* The word the answer goes into is the one at the offset in the pool.
* The T bit is the one of the last test the guest made.

## The unknown

What the masks select, what the byte counts and what the word the answer goes
into means are not recoverable offline: the pool's values and the code live in
the game's own image, which is under `extract/`.  The port therefore reads the
same addresses the guest reads, and what the five masks and the byte stand for
stays open until the image is back.
