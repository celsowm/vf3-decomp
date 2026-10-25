# The fighter-vector rotator (SH-4 0x8C06DEC6)

A readable port of the fight engine's vector rotator, and the evidence for it.

## The function

`0x8C06DEC6` takes the fighter's struct, **turns one of its vectors by an angle the
struct carries**, and writes two results back into the struct: the turned vector and
a normalised pair.

It is 99 instructions and its body is `0x0C06DEC6..0x0C06DF8C` (198 bytes).  It is
called with no arguments of its own - everything it needs it reaches through a
global.

It is **off-baseline**: the inventory has `f_8c06ddbc` (146 bytes) and `f_8c06dece`
(192 bytes), and the rotator sits in the gap between them.  That is also why the
ledger row is worth only 8 bytes of new coverage - see *What the ledger row adds*
below.

It is not cold either.  The oracle's own census of the state-7 fight tick
(`extract/analysis/fxr_tick_s7_stats.csv`) has

```
0x0c06dec6,1,89,25
0x0c09553c,3,99,27
0x0c03a140,91,8098,91
0x0c03a6e0,100,7912,0
```

one call and 89 self-steps of its own; its rotation helper `0x0C09553C` three calls
and 99 self-steps; and the helper's two trigonometry leaves are called 91 and 100
times in the tick.

The port: `src/fight/state_rotate.c`, registered in `src/fight/readable.c` as
`state_rotate`.

## What it does

**The struct.**  The literal pool holds the address of a global (`0x0C29BBA4` in the
image), and the global holds the pointer to the fighter's struct (`0x0C21B4B8` in the
capture).  Everything else is an offset into that struct.

**The angle** is the halfword at the struct's offset 30 - sign extended, and narrowed
to 16 bits before it is handed to the helper.

**The vector to turn** is the pair of floats at the struct's offset 256 and 264.
They are **eight bytes apart**, not four: the guest adds 8 to the offset for the
second one.

**The turn** is done by a helper - the address is in the pool (`0x0C09553C`) - that
rotates a two-float frame by the angle.  The guest hands it the frame `(-1.0, 0.0)`,
so after the call the frame holds `(-cos, -sin)`: the guest turns a vector by
rotating the *negative x axis*.  The helper is called with `r4` = the angle, `r5` =
the frame's second float and `r6` = its first - the `add #4,r5` is the delay slot of
the call.

**The turned vector** is the source vector plus the frame: `rot_x = src_x - cos`,
`rot_y = src_y - sin`.  It goes to the struct's offset 984 and 988.

**The normalised pair** comes from four more vectors - the ones at the struct's
offsets `0x70`, `0x78`, `0xb8` and `0xc0` - and from the turned vector.  The two
averages are the midpoints `(a + c) / 2` and `(b + d) / 2`, and the two fused
multiply-adds combine them with the turned vector into one scalar:

```
fr7 = (rot_y - b) * (a + c)/2 + (rot_x * b - rot_y * a)
fr2 = (a - rot_x) * (b + d)/2 + fr7
```

**The sign of that scalar picks the order** the four floats are written in: when it
is positive the pair goes in as `(c, d, a, b)`, and when it is not as `(a, b, c, d)`.
The test is the guest's **T bit**, and the bit is part of the contract - the guest
leaves it behind.

## How it was recovered

The generated modules under `src/fight/*adapter*.c` are the machine translation of
the ROM: one label per guest PC, one C statement per executed opcode, and the
original opcode word in a comment.  That makes them a faithful disassembly of the
function they implement, so a readable port can be written against them without the
ROM.

* `build/clean.py src/fight/fight_adapters_0.c 0x0c06dec6 0x0c06df8c` - the
  translation, one line per guest PC.  (The *claim* array for the module lives in
  `src/fight/fight_adapters.c`; the body lives in `fight_adapters_0.c`.)
* `python tools/adapter_dump.py 0x0c06dec6` - the body's extent: 89 blocks,
  `0x0C06DEC6..0x0C06DF8C`.

**The literal pool is read at run time**, the way the guest reads it.  The three
offsets, the pointer to the global and the helper's address are the image's, and the
port does not bake them in - it reads `0x0C06DFC4..0x0C06DFE8` from RAM.  The two
constants the guest reaches through a PC-relative address (`-1.0` at `0x0C06DFDC` and
`0.5` at `0x0C06DFE4`) are read from the image too.  What the image holds there, out
of the corpus:

| address | value | what it is |
|---|---|---|
| `0x0C06DFC4` | 256 | the source vector's offset |
| `0x0C06DFC6` | 984 | the turned vector's offset |
| `0x0C06DFC8` | 968 | the normalised pair's offset |
| `0x0C06DFCC` | `0x0C29BBA4` | the global |
| `0x0C06DFDC` | `0xBF800000` | `-1.0f` |
| `0x0C06DFE0` | `0x0C09553C` | the rotation helper |
| `0x0C06DFE4` | `0x3F000000` | `0.5f` |

The global holds `0x0C21B4B8` - the struct - and the helper's own pool holds its two
leaves, `0x0C03A6E0` and `0x0C03A140`.

## The evidence

### The differential

`tests/state_rotate_replay.c` runs the readable port and the retained generated
translation of the same function over ten scenarios and compares **the whole
register file (the FP registers and SR included), the return PC, the failed PC, the
out-of-window counter and every RAM byte**.  The port runs three ways: called
directly, through the readable override (which is how the native tick reaches it),
and as the reference - the generated chain - which is left in the tree as the oracle
of the translation.

```
state_rotate: 10 differential cases - PASS
```

The scenarios walk the tree: the angle zero, one, negative, big and very negative;
the pair coming out positive (twice) and negative; the vectors negative, tiny and
big.  The test checks that **both** store orders are exercised - the sign of the
normalised pair decides them, and a test that only ever sees one of them proves
half the function.

The test also checks the outcome **against the fixture itself**: the struct's bytes,
the T bit the guest leaves behind, the saved registers, the stack pointer and the
return address all have to be what the scenario says.  The expected values come from
a second implementation in the test, written from the disassembly and not from the
port.  A differential alone is not enough, because a fixture that is not where the
guest looks makes both sides read the same wrong bytes and agree on them.

The helper's two leaves (`0x0C03A6E0` and `0x0C03A140`) are answered by a **stub**
in all three arms: the first leaf returns its argument as a float, the second one
returns 1.0.  A stub in one arm only would compare two different things.

### The mutations were checked

The mutations are checked with `tools/mutate.py`, which applies one at a time to the
port's source, rebuilds and requires the test to fail.  The list lives in
`tests/state_rotate_mutations.json`, next to the test it guards.

The list holds 41 mutations and **every one of them is caught**.  They fall into four
groups: the **pool addresses** (the three offsets, the global, the helper and the two
floats), the **frame and the call** (the frame's size, the continuation address, the
two pointers the helper is given and the order the frame is read in), the **arithmetic**
(every offset into the struct, every add, subtract, multiply and the two fused
multiply-adds, and the sign test), and the **epilogue** (the saved registers, the
return address and the T bit).

Two of them are worth naming, because they are the ones a reading of the listing
would get wrong.  The **source vector's second float is eight bytes after the first**
(`+0x108`, not `+0x104`) - the guest adds 8 to the offset.  And the **turned vector is
stored before `fr15` is reused**, so the port has to hold it in its own variable: a
port that reuses `fr15` for the product overwrites the value it has already stored.

Two of the mutations in the list were **rewritten during the milestone** because the
first versions of them were no-ops, and that is worth recording:

* **toggling the FPSCR's bit 0 does not change the FPU's behaviour.**  The first
  version of "the pair is not multiplied in" flipped that bit, and the test could not
  see it - the FP helpers ignore it.  The mutation now drops the product instead.
* **the fixture's stack has to be dirty.**  The guest writes `0.0` into the second
  word of its private frame, and the first version of the fixture handed it a stack
  that was zero everywhere, so the store was redundant and the mutation that removed
  it was invisible.  The fixture now fills the stack with garbage, which is what the
  real game has there, and the guest's own store becomes observable.

### The oracle leg

The rotator has **two** real oracle captures, and both replay clean:

| corpus | specimens | windows |
|---|---|---|
| `extract/analysis/fight_all_cases/f_8c06dec6.cases` | 192 | `0x0C06D000..0x0C06E000` is the **literal pool**, the ROM the entry reads; `0x0C095000` is the helper's own pool; `0x0C21B000`, `0x0C29B000`, `0x0C31F000` and `0x0C03A000` are RAM and the leaves |
| `extract/analysis/fight_release_cases/f_8c06dec6.cases` | 256 | the same, from the release capture |

The XF registers, the FPUL, the exit PC and the GBR come in sidecars next to the
corpora.  So these legs read the *image's* constants out of the capture, exactly as
the guest does.

`tests/state_rotate_oracle.c` replays them:

```
state_rotate_oracle: 192/192 cases match (0 skipped) - PASS
state_rotate_oracle: 256/256 cases match (0 skipped) - PASS
```

The comparison covers the whole register file, the XF registers, the FPUL, the GBR,
the exit PC and every byte of RAM.

**The trap in this leg is the same one the resolver hit.**  The obvious way to run
the corpus - `build/vf3matrixfamily.exe 0x8c06dec6 <corpus>` with `VF3_READABLE=1` -
does not work, because the readable table *shadows the helper's leaves*: the tree's
readable `sin_u16` and `cos_u16` sit at `0x0C03A6E0` and `0x0C03A140`, the two
addresses the helper calls, and those readable ports leave a different `r4` behind
than the code the oracle ran.  The oracle leg therefore installs a hook that serves
**only** the entry under test and leaves the helper and its leaves on the generated
chain, exactly as they were when the oracle captured them.

### What the ledger row adds

The row's `size` is the function's own body span, 198 bytes - but coverage is a
**union of body ranges**, and the neighbouring entry `0x8C06DECE` (192 bytes,
already ported) covers 190 of them.  What the new row adds is the bytes no ported
body covers:

| range | bytes | why it was uncovered |
|---|---|---|
| `0x8C06DEC6..0x8C06DECE` | 8 | the gap leaf itself - the entry is below `f_8c06dece` |

8 bytes: `406,446 -> 406,454` (93.5098% -> 93.5117%).  The 94% bar at 408,576
bytes is 2,122 bytes away.

## What the readable port has to keep

The port is not free-form C: the guest's own side effects are part of the contract,
and the differential test checks them.

* The **T bit** is the guest's branch condition and the last thing the guest
  computes: it is the sign of the normalised pair, it picks the order the four floats
  are stored in, and the guest leaves it behind, so the port has to leave the same
  value behind.
* The **frame** is the guest's: the helper reads the two floats out of it and writes
  them back, so the port has to hand the helper the same frame - and the guest's own
  `0.0` into it has to be there, because the stack is not clean.
* The **register traffic** is the guest's too: the guest moves fr14 into fr7 and
  fr10, fr4 into fr11 and fr3, fr5 into fr2, fr10 into fr0 and fr11 into fr0 again,
  and it leaves all of that behind.
* The **return** pops the saved registers - r14 in the delay slot of the `rts` - so
  the caller sees its own r14 back, and the guest leaves its return address in pr.
* The **vectors** go through the same `vf3_matrix_load`/`vf3_matrix_store` helpers
  the translation uses, so the precision bit of the FPSCR decides the width on both
  sides.

## The unknown

What the struct's fields *are* - what the vectors at `0x70`, `0x78`, `0xb8` and
`0xc0` mean, what the angle at 30 is an angle *of*, and why the sign of the
normalised pair decides the order the pair is stored in - is not recoverable
offline: the code lives in the game's own image, which is not in this checkout (see
[artifact_gap](artifact_gap.md)).  The port therefore reads the same addresses the
guest reads - the literal pool at run time, the struct through its pointer - and what
the rotator *computes* stays open until the image is back.
