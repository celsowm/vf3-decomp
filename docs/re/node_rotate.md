# The node rotation (SH-4 0x8C09F83C)

A readable port of the fight engine's node rotation, and the evidence for it.

## The function

`0x8C09F83C` turns a fighter's nodes around and then moves the fighter's root.

* **The nodes.** Seven twelve-byte records, in an array the caller points at
  with `r4`. Each record holds two floats, eight bytes apart - so the floats
  sit at `+0` and `+8` of the record, and the records are twelve bytes
  apart. Each pair is rotated by the angle the caller leaves in `FR4` (the
  cosine) and `FR5` (the sine):

  ```
  first  becomes  cos * first - sin * second
  second becomes  sin * first + cos * second
  ```

  That is the 2x2 matrix `[[cos, -sin], [sin, cos]]` - a turn around the Y
  axis.

* **The root.** The root's position is three floats: the first at the
  record's `+0x58`, the second at the offset the literal pool holds at
  `0x8C09F8D0`, and the third twenty-four bytes below that offset. All three
  move by the vector the caller leaves in `FR6`.

The port: `src/fight/node_rotate.c`, registered in `src/fight/readable.c` as
`node_rotate`.

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine
translation of the ROM: one label per guest PC, one C statement per executed
opcode, and the original opcode word in a comment. That makes them a faithful
disassembly of the function they implement, so a readable port can be written
against them without the ROM.

* `tools/adapter_owner.py 0x0c09f83c --all` - resolves which module the
  router actually serves for a PC. Two modules carry the copy
  (`fight_adapters_1` and `phase2_adapters_0`) and they agree.
* `tools/adapter_dump.py 0x0c09f83c` - prints the generated function as guest
  disassembly. Its own decoder is crude, so the mnemonics below come from
  `tools/sh4.py`, the repo's authoritative decoder, and the semantics come
  from the translator's emitted C.

The guest code is a loop over the seven records; the translator's C for one
iteration reads:

```
r[6]=7; r[5]=r[4];
loop:
  r[7]=r[5]; r[7]+=8;                       /* the record's second float */
  vf3_matrix_load(s,ram,8,r[7]);
  --r[6]; r[17]=(r[17]&~1u)|((r[6]==0)!=0);
  vf3_matrix_move(s,7,4);                   /* the cosine */
  vf3_matrix_load(s,ram,9,r[5]);            /* the record's first float */
  fr[7]=vf3_fpu_binary(fr[7],fr[8],r[18],'*');
  vf3_matrix_move(s,2,5);                   /* the sine */
  vf3_matrix_move(s,3,8);
  fr[2]=vf3_fpu_binary(fr[2],fr[9],r[18],'*');
  vf3_matrix_move(s,8,5);
  fr[8]=vf3_fpu_binary(fr[8],fr[3],r[18],'*');
  vf3_matrix_move(s,3,7);
  vf3_matrix_move(s,0,9);
  vf3_matrix_move(s,7,2);
  fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
  vf3_matrix_move(s,2,8);
  fr[2]=vf3_fpu_mac(fr[0],fr[4],fr[2],r[18]);
  vf3_matrix_move(s,8,2);
  vf3_matrix_store(s,ram,7,r[5]);
  vf3_matrix_store(s,ram,8,r[7]);
  r[5]+=12; if(!T) goto loop;
```

and the tail that moves the root:

```
r[0]=0x58;
vf3_matrix_move(s,7,6);                    /* the move */
vf3_matrix_load(s,ram,4,r[4]+r[0]);         /* the first coordinate */
r[0]=(int16)read(ram,0x0c09f8d0u,2);
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'+');
vf3_matrix_load(s,ram,5,r[4]+r[0]);         /* the second coordinate */
r[0]+=0xffffffe8u;                          /* twenty-four bytes lower */
vf3_matrix_load(s,ram,3,r[4]+r[0]);         /* the third coordinate */
r[0]=0x58;
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'+');
vf3_matrix_store(s,ram,4,r[4]+r[0]);
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'+');
r[0]=(int16)read(ram,0x0c09f8d0u,2);
vf3_matrix_store(s,ram,5,r[4]+r[0]);
r[0]+=0xffffffe8u;
vf3_matrix_store(s,ram,7,r[4]+r[0]);
```

Four details of that listing are worth naming, because each one is easy to lose
in a readable port:

* **the loop's counter is decremented at the *top*, and the branch that ends
  the loop is at the bottom.** The T bit the guest tests at the bottom is the
  one it wrote at the top of the same iteration, so the port has to set it in
  the same place - the T bit the caller sees is the last iteration's.
* **the second coordinate is a *fused* multiply-add.** `vf3_fpu_mac` rounds
  once, where a multiply and an add round twice, so the port has to use the
  fused helper and not write `a * b + c` in C. The test catches the
  difference (the mutation list below).
* **the pool's halfword is read twice**, once for the load and once for the
  store, and it is *signed*: the third coordinate is twenty-four bytes below
  it, so a negative offset puts the third coordinate below the array.
* **the loads and stores go through the shared helpers**, which size the
  transfer by the FPSCR's FPUL bit. The guest's own `fmov.s` is always four
  bytes wide, so the port inherits the helper's behaviour and the test has to
  set the FPSCR the way the reference sees it.

## The evidence

`tests/node_rotate_replay.c` runs the readable port and the retained
generated translation of the same function over six scenarios and compares
**the whole register file (the FP registers and SR included), the return PC,
the failed PC, the out-of-window counter and every RAM byte**. The port runs
twice: once called directly and once through the readable override, which is
how the native tick reaches it.

```
node_rotate: 6 differential cases - PASS
```

The test lays the seven records, the root's three coordinates and the literal
pool out the way the guest expects. The scenarios cover the identity, a
quarter turn, a half turn, a general angle and the root's move, on its own
and together.

The test has teeth, and the mutations were checked:

* the rotation's sign flipped fails with the differing record byte named
  (`ram 7 c1 != 41`);
* the record's stride widened fails with the differing `r5`, `r7` and four FP
  registers named;
* one record too few fails with the differing `r5`, `r6`, `r7` and four FP
  registers named (`v6 00000000` != `00000001`);
* the fused multiply-add turned into a plain multiply fails with the differing
  `FR2` and `FR8` named (`v23 41800000` != `00000000`);
* the root's first coordinate moved fails with the differing `FR4` named (`v25
  42c80000` != `43960000`);
* the root's third coordinate moved fails with the differing `r0`, `FR3` and
  `FR7` named (`v0 00000054` != `00000058`);
* the loop's exit test moved fails with the differing `r5`, `r6`, `r7`, `SR`
  and four FP registers named;
* the root's move taking the wrong vector fails with the differing `FR4` named
  (`v25 42c80000` != `42ca0000`).

This is the pattern `tests/state_helpers_replay.c` established: the generated
translation stays in the tree as the reference, and the readable port is proved
against it. The generated translation of this function was itself proved
against the oracle when it was promoted, so the chain readable port ==
generated translation == oracle still holds.

**Caveat.** The oracle corpora live under `extract/`, and that tree is gone
from this checkout (see [artifact_gap](artifact_gap.md)). The oracle replay of
this entry could not be re-run, so the differential above stands on the
generated translation rather than on a fresh oracle run. The generated
translation is the one the oracle proved, so the chain is intact, but a
session that has the corpora back should re-run the replay gate for
`0x8C09F83C` before the port is trusted in the native tick.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* Seven records, twelve bytes apart, each with its two floats eight bytes
  apart.
* The turn is `[[cos, -sin], [sin, cos]]`, and the second coordinate is a
  *fused* multiply-add.
* The counter is decremented at the top of the loop and the T bit is written
  there, so the caller sees the last iteration's.
* The root's three coordinates are at `+0x58`, at the pool's offset and
  twenty-four bytes below it, and all three move by `FR6`.
* The pool's halfword is read twice and it is signed.

## The unknown

The pool's halfword - the offset of the root's second coordinate - is not
recoverable offline: it lives in the code image, which is under `extract/`.
The port therefore reads the same address the guest reads, and the layout of
the structure the nodes live in stays open until the image is back.
