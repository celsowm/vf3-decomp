# native extent_list (0x8C0CC432)

`src/native/extent_list.c` (`vf3_native_extent_list`) is the plain-C port of the
readable `src/fight/extent_list.c` (`vf3_extent_list_entry`): the driver that
walks the object's list of 32-byte extent records and steps every live one.

## Why it is self-contained

The readable leaf's **two** callees - `frame_counter_step` (0x8C0CC334) and
`extent_flip` (0x8C0CC3F0) - are both already natively ported
(`src/native/frame_counter_step.c`, `src/native/extent_flip.c`).  It is
therefore the same shape as `format_int` (0x8C04AF04) and `quad_node`
(0x8C068FE4): the guest calls become **direct native calls** into those two
leaves, and the port stays self-contained on `vf3nativeview` with no runtime
dependency on the readable/guest modules.

## What it is

```
r4 -> object:
    +0x10  float   -> FR14  (passed on as extent_flip's FR4 limit)
    +0x38  float   -> FR15  (passed on as frame_counter_step's FR4 speed)
    +0x3C  float   -> FR13  (passed on as frame_counter_step's FR5 speed)
    +0x34  count of records
    +0x1C / +0x24 / +0x28   -> the three halfword tables (tab_a, tab_b, tab_c)
    +0x200 records[] (32 bytes each)
        +0x1A  halfword flags (bit 0 set = live)
        (the rest is the record the two callees operate on: the counter at
         +0x1E, the table value at +0x1C, the floats at +0x10 / +0x0C / +0x14,
         and the six extent_flip floats at +0x00..+0x14)
```

For each record, the flag halfword is read through a sign-extend, parked in the
frame (sp0 - 44).  When bit 0 is set (live), the record is stepped:

1. the third table (tab_c) is pushed at `frame - 4` (frame_counter_step reads
   its third table from the caller's stack);
2. `frame_counter_step` is called with `r4 = record`, `r5 = frame`, `r6 =
   tab_a`, `r7 = tab_b`, FR4 = FR15, FR5 = FR13;
3. `extent_flip` is called with `r4 = record`, `r5 = frame`, FR4 = FR14;
4. the flag word is read back out of the frame and written to the record's
   `+0x1A` as a halfword.

The count (`r13` from object +0x34) and the record pointer are loop-carried in
`r13` / `r14`; `r9` / `r10` / `r11` hold the three tables.  The frame sits at
sp0 - 44, the third table at sp0 - 48.  Six registers (r9..r14), three FR
(FR13..FR15) and PR are saved and restored; the dead stack words are replayed
byte for byte because they are visible in RAM.  The observable contract (the
readable registry's mask) is `B(0)|B(17)` - r0 and the SR T bit (left set by
the final `tst r13,r13`).

## Proof

- `tests/extent_list_native_replay.c` (`vf3nativeextentlist`) runs eight
  differential scenarios against the readable guest port: two live records,
  one live + one dead, the flag-bit-2 stack-table path, a negative counter
  (the "clear live" fast path), three records, an empty list, the extent_flip
  skip-floor path (flag bit 1), and a zero FR4 speed.  Every scenario compares
  the whole 37-register file (incl. PR and SR), the whole FR bank, and the
  object / record / table / stack-frame RAM regions byte for byte.  All match.
- The mutation gate `tests/extent_list_native_mutations.json` (run with
  `python tools/mutate.py --keep-going --port src/native/extent_list.c --exe
  build/vf3nativeextentlist.exe --mutations
  tests/extent_list_native_mutations.json --target vf3nativeextentlist`)
  catches 9/9 mutations: the live test sense, the 32-byte record stride, the
  record base, the flag offset, the frame slot, the third-table push address,
  the SR T bit, the r6 = tab_a hand-off, and the write-back offset.
