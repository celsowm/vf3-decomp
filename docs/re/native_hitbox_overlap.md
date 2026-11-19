# Native fighter-vs-fighter capsule overlap scan (0x8C073AAC)

`src/native/hitbox_overlap.c` is a plain-C port of the fight engine's
`vf3_hitbox_overlap_entry` (SH-4 `0x8C073AAC`, readable authority
`src/fight/hitbox_overlap.c`) onto the `vf3_native_aim` context.  No guest
SH-4 code runs at runtime: the port reads and writes the flat matrix RAM
through `ram_base`, the FR bank and the register file.  Because the function
folds every capsule-pair decision into **integer** hit words and a **byte**
pair count that are decided by float comparisons, the float arithmetic has to
agree with the guest **bit for bit** - so the native port runs the same round-
toward-zero `vf3_fpu_*` helpers the readable uses, fed with `a->fpscr`, exactly
like the readable (the neighbouring capsule family used plain-C `sqrtf`/`fmaf`
and tolerated a float residual because all of *its* outputs are floats).

The contract registers (r8..r14, fr12..fr15, pr, sp) and the saved-register
stack match the guest bit for bit, and so do the radius arrays, the hit-word
arrays, the minimum distance and the pair count.

## What the function does

Given a result block (r4) and the two fighter objects A (r5) and B (r6), it
scans all 28 x 28 capsule pairs and fills the per-capsule hit words, the
minimum distance and the pair count:

1. **Pause / demo gate.**  Leave at once (out untouched) while
   `[0x0C29BCC0] & 0x00080001`.
2. **Participation.**  Per fighter, flag bit 23 of `+0x1A04` selects a
   per-character table (`0x0C110994`) that says which of the 28 capsules take
   part; `+0x1560` bit 1 switches off step 3.
3. **Radius rebuild.**  (Optional) rebuild both fighters' radius arrays from
   the shared radius tables at `0x0C10D390` (indexed by the byte at `+97`),
   growing masked entries by 1.2.
4. **Clear** fighter B's hit words.
5. **Pair scan.**  For every capsule *i* of A and every capsule *j* of B:
   reject early by interval overlap on the three axes (the boxes inflated by
   the two radii), then do the closest-approach test between the two
   segments.  On contact, set capsule *j*'s bit in A's hit word for capsule
   *i*, or into the shared hit word, and update the minimum distance.
6. Write the min distance (float) and the pair count (byte) to the result
   block.

## The native transcription

The readable port keeps the guest's 196-byte frame under the entry sp (44
saved bytes + a 152-byte working area) identical because it was written byte-
faithful against the oracle.  The native port follows the family convention
instead: the transient working area (`sp0-196 .. sp0-44`) is **not** compared,
so it keeps that as a local buffer (`nf[FRAME_BYTES]`); only the saved block
(`sp0-44 .. sp0`) and the caller frame (`sp0 .. sp0+32`) are written to the
flat RAM exactly where the guest writes them, so the proof's exact frame
comparison stays meaningful.

The FP wrappers (`ft0`/`fma0`/`sqrt0` with `flz`) reproduce `sh4_fpu`'s
begin/op/end locally - `fesetround(FE_TOWARDZERO)` around every operation plus
a subnormal flush to zero when the capture FPSCR's DN bit 0x40000 is set - so
the native library stays self-contained (no `vf3core` dependency).  Three
details the transcription had to get exactly right, found by the differential:

- **u's y-component folds through the subtraction target.**  The closest-
  approach builds `u = (fr10-fr13, fr7-fr1, fr14-fr8)`; the second component
  is a *mutating* `FSUB(10,13)` (result into `fr10`), not a fresh copy into a
  scratch register - writing the result into `fr1` instead left u's y at 0
  and the pair was rejected (disc `-20`).
- **The division copies `fr10 -> fr8` first, then divides `fr8/fr6`.**
  `fr10` at that point carries the *flipped sign* of the u.v value
  (`F(10) ^= SIGN`), so copying the wrong direction made the min distance
  minutes off.
- **The min-distance else branch is `fr4 = fr6; sqrt(fr4)`.**  `fr6` is the
  running candidate; the port had `fr6 = fr4` backwards at first, which made
  the sqrt read the epsilon instead of the candidate.

## Proof

`tests/hitbox_overlap_native_replay.c` (`vf3nativehitboxoverlap`) lays out the
result block, the two fighter objects (their +0x138C/+0x1390 segment-array
*pointers*, radius arrays and hit words), the shared radius tables and the
pause/demo flag, seeds the entry registers and the saved fr/pr words, and runs
the readable `vf3_hitbox_overlap_entry` and the native
`vf3_native_hitbox_overlap` from the same seed.  The fixture stores the
segment coordinates at dedicated storage addresses and writes the pointers into
the fighter slots (the +0x138C/+0x1390 slots hold *pointers*, and the shared
radius table holds *pointers* to per-character arrays picked by +97 - writing
floats directly there was the source of the original out-of-window counter).

The proof compares:

- the **object region** (both fighters' radius arrays at float tolerance, both
  fighters' hit-word arrays and the out block's min distance + pair count
  exactly);
- the **saved stack + caller frame** `[sp0-48, sp0+32)` bit for bit;
- the **contract registers**: r8..r14, r15, pr, fr12..fr15 and SR's T bit.

Four cases span the paths: a single direct hit, a clear miss, two overlapping
pairs (count = 2), and the pause/demo flag (out untouched, T cleared).  All
four match bit for bit.

The mutation gate `tests/hitbox_overlap_native_mutations.json` catches **9/9**
mutations: the u-y subtraction target, the closest-approach division
direction, the dropped sqrt, the hit-word `or` to `and`, the pair-count
increment, the min-distance store condition, SR's T bit, the saved-register
restore order, and the discriminant's `S_SQ` subtraction source.

## Run it

```
cmake --build build --target vf3nativehitboxoverlap
build/vf3nativehitboxoverlap           # (from the repo root; needs extract/exe)
python tools/mutate.py --port src/native/hitbox_overlap.c \
    --exe build/vf3nativehitboxoverlap.exe \
    --mutations tests/hitbox_overlap_native_mutations.json \
    --target vf3nativehitboxoverlap
```
