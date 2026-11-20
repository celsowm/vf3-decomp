# native_table_probe (0x8C040378)

The indexed table probe, ported natively in `src/native/table_probe.c`
(`vf3_native_table_probe`) as a plain-C transcription of the readable port
`src/fight/readable/table_probe.c` (`vf3_table_probe_entry`).

## Why this leaf

The readable authority is a self-contained 62 B leaf (0x0C040378..0x0C0403B6),
**call-free, integer-only (no FP)**.  Unlike the pure stack-free leaves
(max_walk, scene_walk, slot_claim) it does use a transient stack slot, so it
is the first native leaf whose contract includes a stack write that the
differential must witness.

## The body

`r4` is an index.  The body pushes `r4` onto a transient stack slot at `sp-4`,
reads it back into `r2`, and returns a status in `r0`:

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
"good" (0).

Two details the native port keeps (unchanged from the readable authority):

* **The transient stack slot is part of the contract, even though r15 is net
  unchanged.**  The guest stores `r4` at `sp-4` on entry and restores `sp` at
  the return, so r15 is flat - but the four bytes above the frame hold the
  entry value of r4 and are in any captured window that covers the stack, so
  the native port mirrors the store with `wr32(a, R(15) - 4, r4)`.
* **`r1` and `r3` are path-dependent and some are *preserved*.**  On the
  below-range path (`r4 < 0`) the branch is taken before the body reads the
  slot into `r3`, so `r1` and `r3` keep their entry values; on every
  `r4 >= 0` path `r3 = r4`, while `r1` is 8 on the above-range path and the
  table base on the lookup path.  The T bit likewise follows the last
  comparison per path.

## Evidence

The **differential** (`tests/table_probe_native_replay.c`, target
`vf3nativetableprobe`) runs the native port against the readable guest port
from the same seed over the same nine index layouts as the readable test
(indices 0,1,3,4,5,7 with -1 and live entries, index 8 above range, -1 and -3
below range).  It lays the pool (0x0c0403bc), the table (0x0c19e310) and the
stack (0x0c31f9c4) into one flat window, patterns every byte, runs both sides,
and compares the whole RAM region byte for byte plus the contract registers
(r0/r1/r2/r3), r15 flat, and SR's T bit.  It also recomputes the outcome
against the fixture itself (the stack slot holds r4, and each path's
answer/r1/r3/T pattern).  **9/9 PASS.**

The **mutation gate** (`tests/table_probe_native_mutations.json`) applies 13
single-site mutations (the readable gate's list minus its guest-PC-specific
`the_return_is_four_bytes_past`, which does not apply to the native port): the
wrong stride (4 instead of 12), the shifted range bounds (`< 1` / `>= 7`), the
wrong answers (-2 instead of -1 on both range arms, -1 instead of -2 on the
miss), the wrong T bits (below-range set, miss clear), `r3 = r4 + 1`, the
stack slot at `sp` instead of `sp-4`, `r2 = r4 + 1`, the pool read one word
high, and `r1` holding the stride instead of the table base.  The differential
catches **all 13**.

```
build\vf3nativetableprobe.exe ->
  table_probe_native_replay: PASS
python tools/mutate.py --port src/native/table_probe.c --exe build/vf3nativetableprobe.exe \
    --mutations tests/table_probe_native_mutations.json --target vf3nativetableprobe
  13/13 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated == oracle` is closed: the readable authority
already replays the oracle corpus `seventh_c5_cases/f_8c040378.cases` at 8/8
(see docs/re/table_probe.md).

## Notes

* Like the other native leaves this needs **no guest callees to inline and no
  FPU round-toward-zero wrappers** - it is pure integer, and the only
  register-file subtlety is the path-dependent r1/r3 and the preserved
  below-range path, which the differential's register comparison pins.
