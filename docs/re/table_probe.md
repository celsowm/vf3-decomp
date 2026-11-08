# table_probe (0x8C040378)

The indexed table probe, ported readable in `src/fight/readable/table_probe.c`
and registered as `table_probe`.

## The body

A small self-contained leaf, 62 B (0x0C040378..0x0C0403B6), call-free,
integer-only, no FP.  `r4` is an index.  The body pushes `r4` onto a
transient stack slot at `sp-4`, reads it back into `r2`, and returns a status
in `r0`:

| r4                | answer | T bit | registers                     |
|-------------------|--------|-------|-------------------------------|
| r4 < 0            | -1     | clear | r1, r3 preserved (entry)      |
| r4 >= 8           | -1     | set   | r1 = 8, r3 = r4               |
| in [0, 8), bad    | -2     | set   | r1 = table base, r3 = r4      |
| in [0, 8), good   | 0      | clear | r1 = table base, r3 = r4      |

`r2 = r4` on every path.  The "bad"/"good" split comes from the table: the
index selects a twelve-byte-stride entry

```
tbl = read32(0x0c0403bc)      the table's base pointer (a literal-pool slot)
val = read32(tbl + 12 * r4)   stride twelve
```

and `val == 0xffffffff` is the "bad"/unused marker (-2), any other entry is
"good" (0).  The guest builds `12*r4` by `add r0,r3` plus two left shifts and
sign-extends the byte, which for r4 in [0,8) leaves it as the positive
0..84 it is.

Two details the port has to keep:

* **The transient stack slot is part of the contract, even though r15 is net
  unchanged.**  The guest stores `r4` at `sp-4` on entry, reads it back for
  `r2`/`r3`/`r0`, and restores `sp` at the return (`r15 += 4` after the
  `r15 -= 4`), so r15 is flat - but the four bytes above the frame hold the
  entry value of r4 and are in any captured window that covers the stack,
  so the port mirrors the store with `vf3_mem_set_u32(ram, R(15)-4, r4)`.
* **`r1` and `r3` are path-dependent and some are *preserved*.**  On the
  below-range path (`r4 < 0`) the branch is taken before the body reads the
  slot into `r3`, so `r1` and `r3` keep their entry values; on every
  `r4 >= 0` path `r3 = r4`, while `r1` is 8 on the above-range path and the
  table base on the lookup path.  The T bit likewise follows the last
  comparison per path: clear below range, set above range, set on the miss,
  clear on the hit.

## Evidence

The **differential** (`tests/table_probe_replay.c`) runs the three arms - the
generated chain, the readable port called directly, and the readable port
reached through `vf3_readable_override` - over nine index layouts in three
windows mirroring the captured corpus (the pool `0x0c040000` holding the
table-base pointer, the table `0x0c19e310`, and the stack `0x0c31f000`),
with every window byte patterned first, and compares the whole register
file, SR/T, the exit PC, the out-of-window counter and every RAM byte.  It
also checks the outcome against the fixture itself: the stack slot, r15
flat, r2 = r4, and each of the four register/T patterns above.  **9/9 PASS.**
The **mutation gate** (`tests/table_probe_mutations.json`) applies 14
single-line mutations - the wrong stride, the shifted range bounds, the
wrong answers, the wrong T bits, r3/r2 + 1, the stack slot at sp instead of
sp-4, the wrong pool slot, r1 = the stride, and the return PC - and the
differential catches all 14.

The **oracle** leg closes directly: `tests/table_probe_oracle.c`
(`vf3tableprobeoracle`) routes the readable port itself over the per-entry
`.cases` corpus `seventh_c5_cases/f_8c040378.cases` and passes **8/8 cases**
(whole 37-register file, SR's T bit, every byte of the three windows and the
OOB counter):

```
build\vf3tableprobeoracle.exe ->
  table_probe_oracle: 8/8 cases match (0 skipped) - PASS
```

The captured cases all exercise the in-range path with a `0xffffffff` table
entry (giving -2), so the oracle leg directly pins that arm; the
out-of-range and live-entry arms are the differential's business.  The three
windows carry the pool, the table and the transient stack slot as captured
runtime state, and the leaf touches no device register, so no sidecars and
no supplied pool are needed - exactly like `fdiv` and `tenpp_fill`.  The
three-arm chain `readable == generated == oracle` closes on all three legs.

## Notes

* Nothing here is FP or even float read through `vf3_matrix_load/store` - the
  leaf is pure integer, so there is no FPSCR-width or FR-register subtlety.
* The entry is `ported-invocation` in the ledger, not `ported`: this readable
  port is the first source-level C for it.  It is not off-baseline (the
  inventory has it), so the 62 B are counted inside the baseline denominator.
