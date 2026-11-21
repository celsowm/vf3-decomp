# native record_state_get (0x8C035A20)

`src/native/record_state_get.c` (`vf3_native_record_state_get`) is the plain-C
port of the readable `src/fight/record_state_field.c`
(`vf3_record_state_get_entry`), proved by
`tests/record_state_get_native_replay.c` (7 differential cases) and the
mutation gate `tests/record_state_get_native_mutations.json` (8/8 caught).

## The function

A call-free integer leaf with no guest callees, no FP and no stack frame - the
only control transfer is the final tail transfer to `pr`.  It answers the
record's state word at `+0x4C`, but only when the busy word at `+0x48` says
the record carries one:

- a **null** record (`r4` = 0) answers `-10`;
- a record whose busy halfword at `+0x48` is zero answers `-10`;
- otherwise `r0` = the sign-extended state halfword at `+0x4C`.

It leaves the busy word (sign-extended) in `r2`, the state (or `-10`) in `r0`
and the T flag (SR bit 0) set when the record is empty, clear when it carried
a state.

## What the port has to keep

- **`r4` is the record, or zero.**  The null branch returns before any RAM
  read, so a null record leaves `r2` (and every other register) at its seed.
- **The two halfword reads are sign-extended** (`int16_t`), so a halfword
  with the high bit set lands in `r0`/`r2` as a negative 32-bit value.
- **The T bit is SR bit 0**, set to `(record == 0)` and then `(busy == 0)`;
  on the carried-state return it reads as clear.
- **Tail-transfer to `pr`**: nothing writes it.

## Everything else

`record_state_get` is one of the genuinely call-free, un-nativized leaves in
the registered readable set (the address-based sweep against `src/native` -
matching the full 8-hex-digit address, not file names - lists it as
un-nativized, and its file `record_state_field.c` holds a single entry with
zero `vf3_guest_call` sites).  It is a self-contained integer leaf, proved by
the differential and the mutation gate.
