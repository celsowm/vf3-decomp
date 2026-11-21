# native div_helpers (0x8C042C20 / 0x8C042CD4 / 0x8C042E44 / 0x8C042D7C)

`src/native/div_helpers.c` (`vf3_native_div_s32` / `vf3_native_div_u32` /
`vf3_native_mod_u32` / `vf3_native_mod_s32`) are the plain-C ports of the
readable `src/fight/math_readable.c`, proved by
`tests/div_helpers_native_replay.c` and the mutation gate
`tests/div_helpers_native_mutations.json`.

## The functions

Four self-contained integer leaves (call-free, no FP):

- `0x8C042C20` signed 32-bit divide: `r1 / r0` -> `r0` and `r1` (both the
  quotient);
- `0x8C042CD4` unsigned 32-bit divide: `r1 / r0` -> `r0` and `r1`;
- `0x8C042E44` unsigned 32-bit remainder: `r1 / r0` -> `r0` = remainder,
  `r1` = dividend;
- `0x8C042D7C` signed 32-bit remainder: `r1 / r0` -> `r0` = remainder,
  `r1` = dividend.

All four reproduce the SH-4 non-restoring division idiom: prime the Q/M/T
flags (`div0s`/`div0u`), then rotate the dividend through T 32 times with one
`DIV1` step between rotations.  Dividing by zero stores the error code
`0x44E` at `0x0C1A5A60` and returns `r0 = 0`.

## What the port has to keep

- **The full DIV flag machine in SR.**  SR keeps `T = bit 0`, `Q = bit 8`,
  `M = bit 9`, and the `DIV1` steps plus the final carry/`div0s` recompute them
  exactly.  The test compares the whole SR word, not just T.
- **The exact number of rotations.**  The two divides rotate 33 times (a
  final `rotcl` after the 32 `DIV1` steps) and fold the final carry into the
  quotient with an `addc`; the two remainders rotate exactly 32.
- **The sign rules.**  A negative dividend loses 1 first (`subc`), the signed
  remainder restores the dividend's sign, and the signed remainder's
  correction adds one more `DIV1` step only when the remainder's sign
  mismatches the dividend's.
- **The dead stack pushes are part of the contract.**  The originals push
  their scratch registers (`r2`, `r3`, `r4`) below `sp` even though they are
  never read back; those stack words are visible in RAM, so the port writes
  them identically (div_s32 pushes r2 then r3, div_u32 pushes r2, mod_u32
  pushes r3 then r4, mod_s32 pushes r2 then r3 then r4 - each in the order
  the original does).
- **The divide-by-zero tails differ.**  The signed divide leaves `r1` = the
  error *address* `0x0C1A5A60`; the unsigned divide leaves `r1` = the error
  *code* `0x44E`.  Both remainders leave `r1` = the error address.

## Proof

`tests/div_helpers_native_replay.c` seeds `r0`/`r1`, distinctive scratch
registers `r2`/`r3`/`r4` and SR, runs the readable guest and the native port
on separate RAM copies, and compares `r0`/`r1`, the whole SR word, the dead
stack words below `sp`, and the error word at `0x0C1A5A60` across 24 cases
covering positive/negative/`INT_MIN` dividends, negative divisors, and zero
divisors for each of the four helpers.  For non-zero divisors the result is
also checked against plain C division/remainder.

## Mutation gate

`tests/div_helpers_native_mutations.json`: `9/9` caught - the divides' 33rd
rotation, the remainders' 32nd step, both sign-handling bugs, the divide-by-
zero `r1` error value, the unsigned remainder's negative-correction, the
signed remainder's mismatch gate, a displaced scratch push, and the error
path's T bit.
