# native_poly_header_sq

Native port of **0x8C055E00** (`poly_header_sq`), the smallest of the three
remaining genuinely-unported *call-free* leaves in the readable registry —
the store-queue device family (`poly_header_sq`, `quad_strip`,
`clip_near_triangle`).  Written in `src/native/poly_header_sq.c`
(`vf3_native_poly_header_sq`) as a mirror of the readable authority
`src/fight/poly_header_sq.c` (`vf3_poly_header_sq_entry`).

## The leaf

It writes one polygon header (two 16-byte halves) into the store-queue slot the
GBR block points at, and leaves the next slot in r12:

- `r4` = the source record (its words +4/+8/+12/+16 are the first four header
  words); `GBR + 72` (plain) or `GBR + 80` (tagged) holds the destination
  pointer; `0x0C16CA08` -> the SQ state whose word +0 (or +8) supplies the
  QACR area byte; `0x0C16B820` is a shading template of two more 16-byte
  halves.
- `[0x0C055B80] == 0` = **plain** form: the four source words are stored as
  the first half; if bit 5 of the first word is clear that half is the whole
  header (the template's first half is stored at +16 of it), otherwise the
  destination moves on 32 bytes and holds both template halves.
- `[0x0C055B80] != 0` = **tagged** form: the first word gets bit 25 set, the
  third word is masked to 26 bits with `0x941000C0` or-ed in, and the second
  half is built from the word at `0x0C055B84` plus the template.
- Both forms end with `r4 += 20`, `r12 = destination + 32`, `r2` = a bank
  pointer (`0x0C16B8C8` plain, `0x0C16B8D0` tagged), `SR.T = 1` iff the header
  fits a single half, and a PREF of the finished slot.

## Why the flat-RAM pattern works here

The observable, flat-RAM contract is the RAM written at `dst`, the register
file (r0..r6, r12) and SR's T bit — all integer, no FR, so no FP tolerance is
needed.  The QACR0/QACR1 device writes (`0xFF000038/3C`) and the PREF flushes
are device side-effects that are inert in the differential:

- the fixture points `dst` at a RAM window, so PREF never fires (it only fires
  when the destination is in the `0xE0000000` store-queue region);
- the guest's QACR writes go to a no-op `device_write` hook so they do not trip
  the guest's out-of-window counter;
- the guest's bank-register write (`bank[3] = r2`) is unobservable in the
  native model (which carries no banked registers), but `r2` itself carries the
  same value and *is* compared.

The `SQ_STATE` read feeds only the (device) QACR area byte, so the native keeps
the read for fidelity but nothing consumes its value.

## Differential

`tests/poly_header_sq_native_replay.c` seeds the same flat RAM (the mode flag,
the tag word, the SQ state, the shading template, the GBR block — with distinct
plain/tagged destinations so the +72/+80 select is observable —, the source
record and the fixture region), the same GBR and the same entry registers, then
runs both sides.  The whole RAM region, r0..r6, r12 and SR's T bit are compared
byte/bit for bit — no tolerance.  pr is untouched by the body.

Cases: plain-single, plain-double, tagged-single, tagged-double, and a plain
single whose first word already carries bit 25.

## Mutation gate

`tests/poly_header_sq_native_mutations.json`, **13/13 caught**:

```
tagged_select_inverted, gbr_offset_swapped, tag_bit_skipped,
tag_or_skipped, keep_mask_dropped, single_test_inverted,
double_advance_wrong, tagged_double_tagword_skipped,
bank_pointer_swapped, sr_t_inverted, r4_not_advanced,
r12_wrong_next, plain_single_template_second_half
```

The first version of `plain_single_template_second_half` used `r4` (undeclared
in that scope) and failed to build rather than discriminate; rewritten with
`r6`, which is a live different value at that point.

## Run

```
cmake --build build --target vf3nativepolyheadersq
.\build\vf3nativepolyheadersq.exe            # differential: PASS
python tools/mutate.py --port src/native/poly_header_sq.c --exe build/vf3nativepolyheadersq.exe --mutations tests/poly_header_sq_native_mutations.json --target vf3nativepolyheadersq --keep-going
```
