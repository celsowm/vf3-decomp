# The capped move (SH-4 0x8C08DD5C)

A readable port of the fight engine's capped move, and the evidence for it.

## The function

`0x8C08DD5C` knows two positions: the one the object had at the start of the
frame (`r4` and `r5`) and the one it has now (the two words `r6` and `r7` point
at).  It moves the current position by the difference between the two - but
never by more than the longest movement the literal pool holds.

```
dx = current.x - old.x        dy = current.y - old.y
len = sqrt(dx*dx + dy*dy)
if len is shorter than the maximum step, the whole difference is used;
otherwise the difference is scaled down to the maximum step.
```

The scaled difference is truncated to integers, and the truncated pair is
added to the old position, so the new position is written back to the two
words `r6` and `r7` point at.

It is the two-dimensional sibling of `aim_step` (`0x8C093768`), which does the
same for three dimensions and takes its step length from a context instead of
from the pool.  The two even share the epsilon: `aim_step` bakes in `1e-7`
(`0x33D6BF94`), and this function reads the same constant from the pool.

The pool's two floats - the epsilon at `0x8C08DDC8` and the longest movement at
`0x8C08DDCC` - are not recoverable offline (the game's image is under
`extract/`), so the port reads the same addresses the guest reads.

The port: `src/fight/move_cap.c`, registered in `src/fight/readable.c` as
`move_cap`.

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine translation
of the ROM: one label per guest PC, one C statement per executed opcode, and
the original opcode word in a comment.  That makes them a faithful disassembly
of the function they implement, so a readable port can be written against them
without the ROM.

* `tools/adapter_owner.py 0x8c08dd5c --body` - the body, in the module that
  carries it (`motion_adapters_2`), and the module that serves it.
* `tools/handwritten_entries.py 0x8c08dd5c` - confirms that no hand-written
  module already serves this entry, so the port is not shadowed.
* The listing below is decoded with `tools/sh4.py`, the repo's authoritative
  decoder, from the opcode words the module carries; the semantics come from
  the translator's emitted C.

The guest code, decoded:

```
0x0c08dd5c  2fe6  mov.l r14,@-r15        ; the guest saves r14
0x0c08dd5e  c71a  mova @(104,pc),r0       ; the epsilon's address
0x0c08dd60  7ff8  add #-8,r15             ; and eight bytes of frame
0x0c08dd62  6362  mov.l @r6,r3            ; the current position
0x0c08dd64  1f31  mov.l r3,@(4,r15)
0x0c08dd66  6272  mov.l @r7,r2
0x0c08dd68  6123  mov   r2,r1
0x0c08dd6a  3158  sub   r5,r1             ; dy
0x0c08dd6c  2f22  mov.l r2,@r15
0x0c08dd6e  5ef1  mov.l @(4,r15),r14
0x0c08dd70  3e48  sub   r4,r14            ; dx
0x0c08dd72  4e5a  lds   r14,fpul
0x0c08dd74  f32d  float fpul,fr3         ; the difference as floats
0x0c08dd76  415a  lds   r1,fpul
0x0c08dd78  f22d  float fpul,fr2
0x0c08dd7a  f43c  fmov  fr3,fr4
0x0c08dd7c  f53c  fmov  fr3,fr5
0x0c08dd7e  f452  fmul  fr5,fr4          ; dx*dx
0x0c08dd80  f308  fmov.s @r0,fr3          ; the epsilon
0x0c08dd82  f02c  fmov  fr2,fr0
0x0c08dd84  f62c  fmov  fr2,fr6
0x0c08dd86  f46e  fmac  fr0,fr6,fr4      ; dy*dy + dx*dx
0x0c08dd88  f74c  fmov  fr4,fr7
0x0c08dd8a  f375  fcmp/gt fr7,fr3        ; the epsilon against the length
0x0c08dd8c  8b01  bf    0x0c08dd92
0x0c08dd8e  a001  bra  0x0c08dd94
0x0c08dd90  f78d  fldi0 fr7              ; too short to measure: zero
0x0c08dd92  f77d  fsra  fr7              ; otherwise 1/sqrt(the length)
0x0c08dd94  f472  fmul  fr7,fr4          ; the length
0x0c08dd96  c70d  mova @(52,pc),r0       ; the longest movement's address
0x0c08dd98  f708  fmov.s @r0,fr7
0x0c08dd9a  f34c  fmov  fr4,fr3
0x0c08dd9c  f47c  fmov  fr7,fr4
0x0c08dd9e  f433  fdiv  fr3,fr4          ; the step over the length
0x0c08dda0  f79d  fldi1 fr7              ; one
0x0c08dda2  f45d  fabs  fr4              ; the factor, without its sign
0x0c08dda4  f745  fcmp/gt fr4,fr7        ; is the factor below one?
0x0c08dda6  8b05  bf    0x0c08ddb4
0x0c08dda8  f542  fmul  fr4,fr5          ; scale the difference
0x0c08ddaa  f642  fmul  fr4,fr6
0x0c08ddac  f53d  ftrc  fr5,fpul         ; and truncate it
0x0c08ddae  0e5a  sts   fpul,r14
0x0c08ddb0  f63d  ftrc  fr6,fpul
0x0c08ddb2  015a  sts   fpul,r1
0x0c08ddb4  34ec  add   r14,r4           ; the new position
0x0c08ddb6  2f42  mov.l r4,@r15
0x0c08ddb8  6453  mov   r5,r4
0x0c08dba  63f2  mov.l @r15,r3
0x0c08ddbc  341c  add   r1,r4
0x0c08ddbe  7f08  add   #8,r15
0x0c08ddc0  2632  mov.l r3,@r6           ; and write it back
0x0c08ddc2  2742  mov.l r4,@r7
0x0c08ddc4  000b  rts
```

Four details of that listing are worth naming, because each one is easy to lose
in a readable port:

* **the length comes from `fsra`, the SH-4's *approximate* reciprocal of the
  square root.**  It is not `1/sqrt(x)` in C: the instruction has its own
  rounding, and the port has to use the same helper (`vf3_fpu_fsrra`) or the
  length is a different number.
* **the factor is compared as an absolute value**, and the guest gets that by
  masking the sign bit off the float's *bits*, not by a floating-point
  operation.
* **the guest only truncates the difference when it scales it.**  A movement
  that is short enough keeps the *integer* difference, which is not the same
  thing once the coordinates are large.
* **the squared length is a fused multiply-add** (`fmac`), so the sum of the
  two squares is rounded once.  Writing it as two rounded operations gives a
  different length for some differences.

## The evidence

`tests/move_cap_replay.c` runs the readable port and the retained generated
translation of the same function over ten scenarios and compares **the whole
register file (the FP registers and SR included), the return PC, the failed PC,
the out-of-window counter and every RAM byte**.  The port runs twice: once
called directly and once through the readable override, which is how the native
tick reaches it.

```
move_cap: 10 differential cases - PASS
```

The scenarios walk the movement through the cap: no movement at all, a movement
shorter than the cap, one exactly at it, one just over it, a diagonal one, a
negative one, one big enough that the squares are not exact in a float, and one
where the pool's longest movement is negative - which is the only case where
the factor's absolute value tells the two ways of comparing it apart.

The test also checks the result **against the fixture itself**: the new
position is worked out again from the pool's values and the scenario's
coordinates, with the same FPU primitives the guest uses (but without the
generated translation), and the T bit has to be the one of the last comparison
the guest made.  A differential alone is not enough, because a fixture that is
not where the guest looks makes both sides read the same wrong bytes and agree
on them.

### The test has teeth, and the mutations were checked

The mutations are checked with `tools/mutate.py`, which applies one at a time
to the port's source, rebuilds and requires the test to fail.  The list lives
in `tests/move_cap_mutations.json`, next to the test it guards.

The ones worth naming:

* the epsilon or the longest movement read from the wrong pool slot fails with
  the differing `FR3` named (`v24 3f800000` != `00000000`);
* the difference taken the wrong way round fails with the differing `r3` and
  `r1` named (`v3 00000064` != `00000066`);
* the squared length not fused fails with the differing `FR3` named - it takes
  the scenario with the big coordinates to see it, because for small ones the
  two roundings agree;
* the epsilon test ignored, the wrong way round, or always taken fails with
  the differing `FR3` named (`v24 00000000` != `ffc00000`);
* the factor without its absolute value fails with the differing position
  named - it takes the scenario with the negative cap to see it, because a
  positive factor has no sign bit to mask off;
* the scaling test the wrong way round fails with the differing `r1` named
  (`v1 00000000` != `80000000`);
* the scaled y taken from the x fails with the differing `r1` named;
* the truncation dropped fails with the differing `r3` named
  (`v3 00000001` != `3f99999a`);
* the factor multiplied instead of divided fails with the differing `v17`
  named;
* the movement subtracted, and the new y added to the wrong base, fail with
  the differing `r3` and `r4` named;
* the new position written to the x fails with the differing RAM byte named
  (`ram 40 c8` != `64`);
* the frame not reserved, and the saved register not put back, fail with the
  differing `r14` named (`v14 7654321e` != `00000000`);
* the pool address not left behind fails with the differing `r0` named
  (`v0 0c08ddcc` != `76543210`);
* the first float not through the FPUL fails with the differing `FR3` named;
* the return address not set fails with the differing `pc` named
  (`pc 0c0abcde/00000000`).

**Caveat.** The oracle corpora live under `extract/`, and that tree is gone
from this checkout (see [artifact_gap](artifact_gap.md)).  The oracle replay of
this entry could not be re-run, so the differential above stands on the
generated translation rather than on a fresh oracle run.  The generated
translation is the one the oracle proved, so the chain is intact, but a
session that has the corpora back should re-run the replay gate for
`0x8C08DD5C` before the port is trusted in the native tick.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the
contract, and the differential test checks them.

* The length is the SH-4's approximate reciprocal, not `1/sqrt` in C.
* The squared length is a fused multiply-add.
* The factor is compared as an absolute value, by masking the float's bits.
* The difference is only truncated when it is scaled.
* The pool's epsilon and the longest movement are read from the pool.
* The FPUL carries the integers between the float conversions.

## The unknown

What the longest movement is, and who calls this, are not recoverable offline:
the pool's values and the code live in the game's own image, which is under
`extract/`.  The port therefore reads the same addresses the guest reads, and
what the two positions mean stays open until the image is back.
