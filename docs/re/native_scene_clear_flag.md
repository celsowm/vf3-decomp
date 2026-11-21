# native_scene_clear_flag — the scene-table bit-clear (0x8C0624BA)

The readable port `src/fight/gd_syscall_stub.c`
(`vf3_scene_clear_flag_entry`) is rewritten as plain C in
`src/native/scene_clear_flag.c` (`vf3_native_scene_clear_flag`), proved
against it by `tests/scene_clear_flag_native_replay.c` (9 differential cases)
and by the mutation gate (`tests/scene_clear_flag_native_mutations.json`,
11/11 caught).

## The leaf

A self-contained, call-free, no-FPU, no-stack leaf:

```
r4 = the address of a scene record.
scan the 4096-record scene object table at 0x0C16CF6C (stride 24).
  when a record's address == r4:  clear bit 0 of that record's first
    halfword (& 0xFFFE) and stop scanning.
r1 = r7 = 0x1000
r5 = r6 = 0x0C16CF6C + 24 * 0x1000   (one past the last record)
```

The original always walks the whole table, so the four output registers are
left unconditionally — whether r4 was found or not.  r4 (the target) and
every other register are untouched; SR is untouched (no comparison writes the
T bit).  The return pops pr.

## The port

```c
const uint32_t base = 0x0C16CF6Cu;
const uint32_t target = R(4);
for (uint32_t i = 0; i < 0x1000u; ++i) {
    const uint32_t rec = base + 24u * i;
    if (rec == target) {
        vf3_aim_set_u16(a, rec, (uint16_t)(vf3_aim_h16(a, rec) & 0xFFFEu));
        break;
    }
}
R(1) = 0x1000u; R(5) = R(6) = base + 24u * 0x1000u; R(7) = 0x1000u;
```

The `& 0xFFFE` is an atomic mask of the record's first halfword, exactly the
guest's `vf3_mem_set_u16(rec, vf3_mem_u16(rec) & 0xFFFE)`.

## The test

`tests/scene_clear_flag_native_replay.c` seeds the flat RAM with the full
table (each record's first halfword distinct) and the register file, runs
both the readable guest port and the native port, and compares:

- the four output registers (r1, r5, r6, r7) against the guest;
- every other register against its entry value;
- the whole low table region's RAM byte-for-byte against the guest's (this
  catches the bit-0 clear of the found record);
- an independent fixture model that computes the expected word from `r4`.

The 9 cases cover: the first record, a middle record, the last record, a
record whose bit 0 is already clear, a record with only the high bits set,
three not-found targets (between records, below the table, one past the last
record) and a target of zero.

## The mutation gate

`tests/scene_clear_flag_native_mutations.json` applies 11 single mutations,
one at a time:

- `clear_bit1_not_bit0`, `no_clear_write` — the mask and the write;
- `inverted_match_test` — `rec == target` becomes `rec != target`;
- `wrong_stride`, `wrong_base` — the table layout;
- `loop_bound_short` — `i < 0x0FFF`, dropping the last record;
- `target_from_r5` — reading the target from the wrong register;
- `r1_constant_wrong`, `r7_constant_wrong` — the 0x1000 constants;
- `r5_end_wrong`, `r6_end_wrong` — the one-past-the-end addresses.

All 11 are caught by the differential (the RAM snapshot is what catches the
clear and the inverted test; distinct output registers catch the register
mutations).  Command:

```
python tools/mutate.py --keep-going --port src/native/scene_clear_flag.c \
  --exe build/vf3nativesceneclearflag.exe \
  --mutations tests/scene_clear_flag_native_mutations.json \
  --target vf3nativesceneclearflag
```

## Authority

The readable port is the authority; the chain is *native == readable*.  The
leaf is off the captured fight ticks' watch list in the sense that no oracle
corpus names this exact entry as a watched specimen, so the proof stands on
the differential against the readable translation (the same shape every
readable leaf uses).

Result: **9/9 PASS**, **11/11 mutations caught**.
