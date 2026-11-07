# The pose postprocessor (SH-4 0x8C09F432) and its quantiser (0x8C09F500)

A readable port of the two functions that close the fight engine's motion
channel postprocessing, and the evidence for it.

## The functions

| entry | body | what it does |
|---|---|---|
| `0x8C09F432` | `0x0C09F432..0x0C09F4E6` (180 B) | the wrapper: five point clamps around two quantisations of the actor's channel block |
| `0x8C09F500` | `0x0C09F500..0x0C09F5E8` (232 B) | the quantiser: truncates one three-float vector, canonicalises the Euler angle and (conditionally) writes three halfwords |

Neither entry is in the baseline inventory
(`extract/analysis/funcs_1ST_READ.unsc.bin.csv` - in this neighbourhood the
inventory holds only `f_8c09f440` and `f_8c09f6dc`), so both are **off-baseline
leaves**.  Their ledger sizes are 180 and 232 bytes, but the verified C
address union only grows by **246 bytes** (437,464 -> **437,710**): the
wrapper's span `0x0C09F432..0x0C09F4E6` contains the whole baseline
`f_8c09f440` body (`0x0C09F440..0x0C09F4E6`, 166 B) that
`src/fight/motion_adapters.c` already covers, so only its first **14 bytes**
are new; the quantiser's 232 bytes are new.

The portable sources are `src/fight/pose_post.c` (both functions), registered
in `src/fight/readable.c` as `pose_post` and `pose_turns`.

**Where it sits.**  The retained s29 pose-chain run watches `0x8C09F036` as
it samples the 63 MT channels at `0x8C09D670` and then calls `0x8C09F432`
before returning.  Comparing the four complete calls with
`tools/mt_pose_capture_compare.py` shows **3 changed channel values in each
Akira call and 5 in each Jacky call**, while the 23 joint records, the 18
attachment rows, the 23 bone matrices and the cached-pose records stay equal
in all four (`docs/re/mt_fields.md`).  In those specimens the wrapper is a
**channel postprocessor**: it is not the stage that writes the joint records
or the matrices.

## The wrapper (0x8C09F432)

The wrapper is handed the actor in `r4` and runs seven guest calls in a fixed
order.  Every point clamp is a call to `0x8C09F5F8` (the readable
`point_wrap`); the two quantisations are calls to `0x8C09F500`.

| call | argument | destination | answer |
|---|---|---|---|
| point clamp 1 | `actor+0x1D58` (the pool's signed halfword) | - | the clamp's `r0` |
| point clamp 2 | the first answer | - | the clamp's `r0` |
| point clamp 3 | the second answer **+ 0x54** | - | the clamp's `r0` |
| point clamp 4 | the third answer | - | the clamp's `r0` |
| quantiser 1 | the fourth answer | `actor+0x233C` | source + 12 |
| point clamp 5 | the quantiser's answer | - | the clamp's `r0` |
| quantiser 2 | the fifth answer | `actor+0x2342` | source + 12 |

With the clamp's global gate **open** each clamp answers its argument plus
twelve (it stores the point back and advances `r4`), so the two quantiser
sources are `actor+0x1DDC` and `actor+0x1DF4`, and the wrapper returns
`actor+0x1E00`.  With the gate **shut** the clamp is a no-op and answers its
argument unchanged, so the sources are `actor+0x1DAC` / `actor+0x1DB8` and the
return is `actor+0x1DC4`.  The differential exercises both paths
(`the clamp's gate is open/shut`).

**The clamps' six floats.**  Every one of the five calls gets the same
argument registers: `fr4` 32768.0 (it travels in the `bsr` delay slot),
`fr5` 16384.0, `fr6` -32768.0, `fr7` 24576.0, `fr8` 0.0 and `fr9` 65536.0.
`fr12` holds 24576.0, `fr13` 0.0 and `fr14` 65536.0 across the calls; `fr15`
holds 32768.0.

**The frame.**  The prologue saves `r14`, `fr15`, `fr14`, `fr13`, `fr12` and
`pr`, then opens a **twelve-byte frame** under them.  The frame's first two
words hold 16384.0 and -32768.0 (the clamp's `fr5` / `fr6` come from there),
and its *third* word is where each destination pointer is stashed before the
quantiser call.  The `fmov` saves and restores go through
`vf3_matrix_store` / `vf3_matrix_load`, so they honour `FPSCR.SZ`.

**The literal pool is read at run time**, the way the guest reads it.  The
image's values are:

```
0x0C09F4E6  -> 0x1D58        the first point's offset in the actor
0x0C09F4E8  -> 0x233C        the first quantiser destination
0x0C09F4EA  -> 0x2342        the second quantiser destination
0x0C09F4EC  -> 16384.0       the frame's first float and the clamps' fr5
0x0C09F4F0  -> 32768.0       the clamps' fr4
0x0C09F4F4  -> -32768.0      the frame's second float and the clamps' fr6
0x0C09F4F8  -> 24576.0       the clamps' fr7
0x0C09F4FC  -> 65536.0       the clamps' fr9
```

The two destinations are **signed halfwords**, so the port applies them in
signed arithmetic; a negative offset would point below the actor.

## The quantiser (0x8C09F500)

The quantiser takes the actor in `r4`, one three-float vector in `r5` and a
three-halfword destination in `r6`.

**Truncation.**  It converts `x`, `y` and `z` with `ftrc` (round toward zero,
the result in FPUL), and keeps them in three different widths:

* `x` is read as an **unsigned** low halfword and then **sign-extended**:
  `x16 = (int16_t)((uint32_t)ftrc(x) & 0xFFFF)`;
* `y` keeps the whole 32-bit result of the truncation;
* `z` is read as an **unsigned** low halfword and stays that way until the
  destination is written; the sign extension happens later, after the
  canonicalisation.

**Canonicalisation.**  When the sign-extended `x` is above `0x5000` or below
`-0x5000` (both bounds are signed pool halfwords at `0x0C09F5E8` /
`0x0C09F5EA`), the guest folds the angle back:

```
y  = 0x8000 - y
x += 0x8000
z += 0x8000
```

The addend is the pool's **word** at `0x0C09F5F4` (0x00008000).  `x` and `z`
are masked back to sixteen bits, then sign-extended (`x''`, `z''`); `y`
is kept at full width.

**The band.**  The value the band tests use is the actor's own halfword at
**`+0x3E`**, not the quantised `x`.  Four fields take part:

| field | source | how it is read |
|---|---|---|
| band value | `actor+0x3E` | `mov.w`, then masked to 16 bits |
| high bound `hi` | `actor+0x1FB0` | `mov.w`, masked, **+ 1** |
| middle bound `mid` | `actor+0x1FAC` | `mov.w`, **signed**, **+ 1** |
| low bound `lo` | `actor+0x1A00` | `mov.w`, masked |

From `lo` the guest derives `lo8 = lo - 8` and `lo1 = lo + 1`.

**The destination is written on two edges only:**

```
band == hi   or   band == lo8
```

When it fires, the three halfwords are `x''`, `y''` (the canonicalised,
full-width value) and `z''` - in that order, at the destination's `+0`, `+2`
and `+4`.

**The kind gate** is reached from two places:

* directly, when `hi < band < mid`; or
* on the inside path, when `lo8 < band < lo1`.

When the actor's byte at **`+0x61`** is `3` and the magnitude of `z''` is
above `0x7530` (the signed pool halfword at `0x0C09F5F0`), the guest negates
`z''`.  The negation always **flips the sign**: a positive `z''` above the
limit becomes negative, and a negative `z''` below `-0x7530` becomes positive.
The magnitude is formed by `0 - z''` and tested with `cmp/gt`.

**The source vector is always written back**, whether or not the destination
was touched: `x''`, the canonicalised `y` and `z''` (possibly negated) go into
the source's `+0`, `+4` and `+8` as floats.  The guest leaves
`r0 = r5 = source + 12` and `r2 = r3 = source + 8`.

**The literal pool** (`0x0C09F5E8..0x0C09F5F4`):

```
0x0C09F5E8  -> 0x5000     the canonicalisation's high bound
0x0C09F5EA  -> 0xB000     its low bound (-0x5000, sign-extended)
0x0C09F5EC  -> 0x1FB0     the band's high word
0x0C09F5EE  -> 0x1A00     the band's low word
0x0C09F5F0  -> 0x7530     the kind-3 limit
0x0C09F5F4  -> 0x00008000 the canonicalisation addend
```

The middle word (`0x1FAC`) is `0x1FB0 - 4`; the guest computes it by
subtracting four from the high word's pool value.

## The details the port has to keep

* **The destination stores precede the kind gate.**  The quarter at
  `0x0C09F584` writes the three halfwords and only then falls into the band's
  inside tests, so a frame can do both and the destination keeps the
  **un-negated** `z''` while the source vector gets the negated one.  The
  overlap is not the obvious one: the high edge (`band == hi`) falls into the
  inside path, whose second test reaches the gate when `lo8 < hi < lo1`, and
  the low edge (`band == lo8`) reaches it through the middle path when
  `hi < lo8 < mid`.  The differential carries both -
  `the high edge inside the kind band` and `the low edge inside the kind
  band` (quantiser), and `the destinations are written inside the kind band`
  (wrapper).  The plain `the high edge, kind 3` scenario has `lo8` above the
  band value, so it returns before the gate and pins the destination write
  alone.
* **A `bt/s` delay slot runs on both paths.**  The first one spills `z`'s low
  halfword into the frame before the canonicalisation branch is resolved; the
  second writes `lo8`; the third bumps `hi`; the fourth negates `z` into `r6`
  even when `z` is positive.  A plain `bt`/`bf` has no delay slot, so the
  band's later tests do not run the instruction after them.
* **The frame's first word is written three times.**  The truncation stores
  `z`, the canonicalisation stores `z''`, and the band setup stores `lo8` -
  so the word the caller's RAM finally holds is **`lo8`**.  The differential
  compares every RAM byte, so the intermediate stores are observable.
* **The middle bound is signed; the high and low ones are masked.**  A
  `0xFFFF` in the middle word is `-1`, so `mid` is `0`; a `0xFFFF` high word
  is `65535`, so `hi` is `65536`; a `0xFFFF` low word gives `lo8 = 65527` and
  `lo1 = 65536`.  The differential carries all three wrapped cases.
* **`lo1` is not masked again** after `lo + 1`, so a low bound of 65535
  leaves `lo1 = 65536`, not zero.
* **The T bit is part of the contract.**  The wrapper inherits the last
  quantiser's T.  The quantiser's last test is the band/kind chain and its
  arms do not all leave the same value, so the port performs the tests in the
  guest's order.
* **FPUL carries the conversions.**  `ftrc` writes it for the three
  truncations, and the three `float FPUL,FRn` conversions at the end read
  `x''`, `y''` and `z''` after the guest reloads FPUL with `lds` from the
  register each value was kept in.
* **The prologue and epilogue are part of the contract.**  The wrapper saves
  `r14`, `fr15`..`fr12` and `pr`; the quantiser saves `r14`..`r8` and opens a
  twelve-byte frame.  The differential's stack is filled with garbage, not
  zeroes, and every byte of it is compared.

## The evidence

**The differential** (`tests/pose_post_replay.c`, **55 cases**: 40 for the
quantiser and 15 for the wrapper) compares three arms on the whole register
file (the FR registers and `SR` with its T bit included), the return PC, the
failed PC, the out-of-window counter and every RAM byte:

1. the generated chain - the reference;
2. the readable port called directly;
3. the readable port reached through the readable override, with
   `VF3_READABLE_ONLY` serving only the entry under test.

The wrapper's arm hands its two callees to `vf3_guest_call`, exactly as
`state_resolve.c` does, so the clamps and the quantiser remain the generated
bodies in both arms; the test is pinning the wrapper's own sequencing (which
point each call gets, which destination each quantiser writes, where the
frame and the saved registers end up).  The quantiser's arm compares its body
on its own.

On top of the differential, every case is checked against a **model of the
quantiser written from the fixture** (`expect_quant`): the three destination
halfwords, the three source floats and the answer registers.  The model does
not consult the translation, so a fixture laid out where the guest does not
look cannot make both sides agree on the same wrong bytes.  The destination
starts as `0xAA`, and the source's second triple deliberately sits 0x40 bytes
clear of the first - the first version of the test laid the second triple on
the same address, which let it overwrite the first and is the sort of fixture
fault the model exists to catch.

The scenarios cover both paths of the clamp gate, both quantiser
destinations, the band's high edge, its low edge, the `lo1` edge, the inside
band, the kind gate from both entrances, both edges *inside* the kind gate
(the destination/source split above), kind 3 above and below the limit,
wrapped high/middle/low words, fractional values, large values and negative
values.

**The oracle.**  `extract/analysis/native_pose_chain_s29_v1/f_8c09f432.cases`
holds four complete calls (two Akira and two Jacky specimens).  Four runs of
`build/vf3matrixfamily.exe` all match **4/4 cases (0 skipped) - PASS**:

| run | configuration | readable calls |
|---|---|---|
| generated chain | no `VF3_READABLE` | 0 |
| whole readable table | `VF3_READABLE=1` | 32 |
| wrapper only | `VF3_READABLE=1 VF3_READABLE_ONLY=0x8c09f432` | 4 |
| quantiser only | `VF3_READABLE=1 VF3_READABLE_ONLY=0x8c09f500` | 8 |

The whole-table run reaches 32 readable ports through the wrapper's call tree
(the clamps, the quantiser and their callees); the wrapper-only run serves
exactly the four wrapper entries, and the quantiser-only run serves it twice
per case.  The comparison covers every register, the XF registers, the FPUL,
the GBR, the banked registers, the exit PC and every byte of RAM.

**The mutations** (`tests/pose_post_mutations.json`, **88** of them) are run
by `tools/mutate.py`.  **83 are caught**; the five that are not are genuinely
unobservable in this guest:

* `the_third_points_continuation_is_the_fourth`,
  `the_first_quantisers_continuation_is_the_second` and
  `the_second_quantisers_continuation_is_the_first` - both callees are leaves
  that return through `pr` without saving it, and the wrapper restores its
  own `pr` from the stack in the epilogue.  `vf3_guest_call` sets `pr` to the
  same continuation it later checks, so a wrong continuation is
  self-consistent and never reaches RAM.
* `the_canonicalised_x_subtracts_the_addend` and
  `the_canonicalised_z_subtracts_the_addend` - the addend is `0x8000`, and
  both results are masked to sixteen bits (`x &= 0xFFFF` then `exts.w`;
  `z &= 0xFFFF` then `exts.w`) before anything reads them.  `+0x8000` and
  `-0x8000` are the same value mod 2^16.  The `y` addend is **not** masked,
  so its direction *is* observable and that mutation is in the caught list.

The caught list covers every pool entry and both destination offsets, the
frame's two floats, the actor's save in `r14`, the FR save order and the
`pr` slot, the twelve-byte frames, the point's `+0x54` stride, every
continuation that *is* observable, both destinations and their stash slot,
the source-vector addressing and truncation widths, the canonicalisation
bounds and direction, the band value's source, the high/middle/low reads and
their sign handling, every band edge and inside test, the destination's three
halfwords and their order, the kind byte and its comparison, the negation and
its limit, the source floats and their pointers, and every saved register and
stack slot.

## The tooling lessons

* **A second fixture triple laid on the first one hides the first.**  The
  quantiser reads one source vector, so the wrapper's test lays the two
  triples at different addresses.  The first version used the same address
  for both; the second triple (all zeroes) overwrote the first, and only the
  fixture-side model - not the differential - would have noticed.
* **The callee's continuation is not part of the callee's visible state.**
  `point_wrap` and the quantiser never push `pr`, so their continuation lives
  only in the register file for the duration of the call and is overwritten
  by the wrapper's own epilogue.  A mutation of the continuation constant is
  therefore invisible to a replay, and the documentation says so instead of
  pretending the mutation list is exhaustive.
* **`0x8000` is its own negative in sixteen bits.**  The canonicalisation
  folds `x` and `z` with `+= 0x8000`; because both are masked to sixteen bits
  immediately afterwards, `-= 0x8000` produces the identical value.  The `y`
  fold is the one that can tell the two directions apart.
