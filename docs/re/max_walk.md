# max_walk (0x8C061910)

The four-list gated max walk, ported readable in
`src/fight/readable/max_walk.c` and registered as `max_walk`.

## The body

A self-contained leaf (body 0x0C061910..0x0C061994, 136 B), call-free and
integer-only (no FP, no gbr, no fipr).  It reads the fight structure's
address from the literal pool at `0x0c061a0c`, searches four linked lists and
writes two signed maxima out:

```
[r4] = r7  = max of (list A at struct+0x08, ungated)  over [node+16],
             then    (list B at struct+0x00, gated)    over [node+16]
[r5] = r14 = max of (list C at struct+0x1c, ungated)  over [node+16],
             then    (list D at struct+0x14, gated)    over [node+16]
```

A node is a 20-byte record: `u16 gate` at `+0`, `u32 next` at `+8`, `u32 value`
at `+16`.  A walk starts at a head field in the structure and steps a node via
its `next` word until null.  A "gated" list only lets a node's value compete
for the max when `(node.gate & 4) == 0` — the `bf` at 0x0C061940/978 skips the
update when the bit is set.  The two maxima start at 0 (`r14` is zeroed on
entry at 0x0C061912, and `r7` starts from that `r14` at 0x0C061920).

The guest's stack contract is part of what the harness compares: it pushes
`r14`, `r13`, `r12` (entry `r15` = SP0), allocates a 4-byte scratch slot at
SP0-16 that briefly holds `struct+0x14` on the way to list D, and pops
`r12`/`r13`/`r14` back at the tail, so `r15` is net back at SP0 and the three
saved registers are restored to their entry values.

Details the port has to keep:

* **`r7` starts from the zeroed `r14`, not from the entry `r14`.**  The `mov
  #0,r14` at 0x0C061912 runs before `r7 = r14` at 0x0C061920, so both maxima
  begin at 0.
* **Lists B and D are gated by `(node.gate & 4) == 0`; A and C are not.**  A
  node on a gated list only updates the max when the gate bit is clear; the
  two gated lists can hide their high value entirely.
* **The gate halfword is sign-extended then masked to 16 bits.**  `mov.w @r6`
  sign-extends into the 32-bit register, then `and #0xff, r0`-style masking at
  0x0C06193C/974 keeps the low 16 bits — so an entry with the gate bit set in
  the top halfword behaves just like one in the low halfword.
* **The comparisons are signed.**  `cmp/gt` at the max updates means a
  negative value never wins over 0, and a value of `0xfffffffe` loses to any
  positive one.
* **The scratch slot at SP0-16 is part of the captured RAM.**  It holds
  `struct+0x14` (the list D head's *location*) from 0x0C061954 until the end;
  the differential compares the stack byte for byte, so the port must write
  it.
* **The leftover `r1`/`r2`/`r6` are real outputs.**  `r1` is the last gated
  node's value read, `r2` the last node's gate halfword, `r6` the walk's 0
  terminator.  They sit in the saved data the harness compares, so the port
  keeps them in locals and writes them back.

## Evidence

The **differential** (`tests/max_walk_replay.c`) runs the three arms — the
generated chain, the readable port called directly, and the readable port
reached through `vf3_readable_override` — over six list layouts (four
populated lists mirroring the captured corpus case 0, gates hiding the high
values, negative values with open gates, all lists empty, only the gated lists
populated, and A empty with a longer C) in five windows mirroring the captured
corpus (the pool `0x0c061000`, the fight structure `0x0c0ea000`, the stack
`0x0c31f000`, the outputs `0x0c40d000`, the node region `0x0c40f000`), with
every window byte patterned first, and compares the whole register file,
SR/T, the exit PC, the out-of-window counter and every RAM byte.  It also
computes the two maxima with an independent fixture walk and checks them
against `[r4]`/`[r5]`, checks that no head field was clobbered, verifies the
three pushed words and the scratch slot on the stack, and verifies the
restored `r12`/`r13`/`r14`, r15 flat, `r0 = 0`, `r7`/`r6` and T = 1.
**6/6 PASS.**  The **mutation gate** (`tests/max_walk_mutations.json`) applies
16 mutations — both gated lists made ungated, both gate tests inverted, the
list-A max made a min, list C accumulating into `r7`, the two output words
swapped, `r7` starting at 1, the struct/head offsets off by 4, the walk
stepping by value instead of next, the T bit left clear and the restored
registers/r15 wrong — and the differential catches all 16.

The **oracle** leg closes directly: `tests/max_walk_oracle.c`
(`vf3maxwalkoracle`) routes the readable port itself over the per-entry
`.cases` corpus
`advance_resume_061910_dev/advance_resume_061910_dev_8c061910/f_8c061910.cases`
and passes **512/512 cases** (whole 37-register file, SR's T bit, every byte
of the five windows and the OOB counter):

```
build\vf3maxwalkoracle.exe ->
  max_walk_oracle: 512/512 cases match (0 skipped) - PASS
```

The five windows carry the pool (with the struct pointer at `0x0c061a0c`),
the fight structure, the stack, the output words and the node region as
captured runtime state, and the leaf touches no device register, so no
sidecars and no supplied pool are needed.  The three-arm chain
`readable == generated == oracle` closes on all three legs.

## Notes

* The entry `8c061910` is a baseline inventory row (`FUN_8c061910`, 136 B),
  so the readable port's 136 B count directly against the coverage union.
