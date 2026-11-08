# scene_walk (0x8C06233E)

The scene list walk with an enable flag, ported readable in
`src/fight/readable/scene_walk.c` and registered as `scene_walk`.

## The body

A self-contained leaf (body 0x0C06233E..0x0C062378, 62 B), call-free and
integer-only (no FP, no gbr, no fipr).  It reads a threshold pointer from the
literal pool and a table base, writes a 16-bit enable flag, and walks a linked
list to find the node whose value equals the key:

```
p1      = [0x0c06238c]            a pointer
thr     = [p1]                    the threshold
enabled = (r4 >= thr)             signed comparison, SR.T
[r5]    = enabled ? 1 : 0         16-bit enable flag
byte    = (int8)[r5]              reads the flag back (0 or 1)
node    = [base + 20 * byte]      base = [0x0c062384]
```

A node is a record with `u32 value` at `+12` and `u32 next` at `+8`.  When
`node != 0` the body walks the list — recording in `r6` the first node whose
value equals `r4`, otherwise following `next` until null.  The answer is a
tail `jmp @r16`: `r0 = r6` (the found node, or 0) and the function neither
pushes `pr` nor touches `r15`/`r16`.

The registers the body leaves are `r0 = r6`, `r1 = 1` on an enabled empty
table (or the last value read by the walk otherwise, or its entry value on
the disabled path), `r2 = byte`, `r3 = 20 * byte` (the table stride it used),
`r5 = 0` (the walk's terminator), `r6` the found node and `SR.T = 1` (the
walk-exit test `(r5 == 0)` is the last comparison).  `r4` and `r15` are
untouched.

Details the port has to keep:

* **The enable flag is 16-bit and read back as a sign-extended byte.**  The
  `mov.w` write at 0x0C06234A/350 stores 1 or 0, and the `mov.b @r5` at
  0x0C062352 sign-extends the low byte to choose the table stride.
* **The stride is `20 * byte`, built by the guest as `(byte<<2) + byte)<<2`
  and sign-extended.**  With `byte` = 0 or 1 the stride is 0 or 20, so the
  table is looked up at `base + 0` or `base + 20` — the two table slots are
  distinct and the port must read the one `byte` selects.
* **`r1 = 1` is set on the enabled path *before* the walk (0x0C06234E).**  On
  an enabled empty table the body returns with `r1 = 1`, not the entry value.
* **The walk records the *first* match and then stops.**  On a hit at
  0x0C06236C `r6 = node`, `r5` is zeroed (0x0C06236E) and the walk-exit test
  ends the loop; a later node that would also match is never reached.
* **The found node rides in `r6` and `r0`.**  The tail's `r0 = r6` puts the
  same address in both output registers; a port that only wrote `r6` fails
  the register compare.
* **`SR.T` is 1 on every return.**  The last comparison the guest executes
  before the `rts` is always the walk-exit `(node == 0)`, so the flag is
  always set.

## Evidence

The **differential** (`tests/scene_walk_replay.c`) runs the three arms — the
generated chain, the readable port called directly, and the readable port
reached through `vf3_readable_override` — over nine list layouts (enable=1
first/second match, enable=1 not found, enable=1 empty table, enable=0
first/third match, enable=0 not found, the `r4 == thr` boundary, and an
enable=1 case proving the walk uses table slot 1 not slot 0) in four windows
mirroring the captured corpus (the pool `0x0c062000`, the pool's
table/threshold region `0x0c0ea000`, the node region `0x0c16d000`, the
caller's stack `0x0c31f000`), with every window byte patterned first, and
compares the whole register file, SR/T, the exit PC, the out-of-window counter
and every RAM byte.  It also checks the written flag (16-bit), `r2`/`r3`, the
found node against an independent fixture walk, `r0 == r6`, `r5 = 0` and
T = 1.  **9/9 PASS.**  The **mutation gate** (`tests/scene_walk_mutations.json`)
applies 14 mutations — the enable comparison inverted, enable forced to 1, the
flag written as a byte, the table stride/selection wrong, the found test
inverted, the walk stepping by value instead of next, the found node not
recorded, `r5` not zeroed on a hit, `r0` not copied from `r6`, the T bit left
clear, the empty table made to walk, `r1` not reloaded and the next pointer
offset wrong — and the differential catches all 14.

The **oracle** leg closes directly: `tests/scene_walk_oracle.c`
(`vf3scenewalkoracle`) routes the readable port itself over the per-entry
`.cases` corpus `target_retained_scene_final_dev/f_8c06233e.cases` and passes
**272/272 cases** (whole 37-register file, SR's T bit, every byte of the four
windows and the OOB counter):

```
build\vf3scenewalkoracle.exe ->
  scene_walk_oracle: 272/272 cases match (0 skipped) - PASS
```

The four windows carry the pool (with the threshold pointer at `0x0c06238c`
and the table base at `0x0c062384`), the pool's table/threshold region, the
node region and the caller's stack as captured runtime state, and the leaf
touches no device register, so no sidecars and no supplied pool are needed.
The three-arm chain `readable == generated == oracle` closes on all three
legs.  (All 272 captured cases are "found" ones, split evenly between enable
= 1 and enable = 0, so the empty-table and not-found arms are supplied by the
differential, not the oracle.)

## Notes

* The entry `8c06233e` is a baseline inventory row (`FUN_8c06233e`, 62 B), so
  the readable port's 62 B count directly against the coverage union.
