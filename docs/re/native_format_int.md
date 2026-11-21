# native format_int (0x8C04AF04)

`src/native/format_int.c` (`vf3_native_format_int`) is the plain-C port of the
readable `src/fight/format_int.c` (`vf3_format_int_entry`): the integer
conversion of the engine's printf.  It renders one number into the output
cursor and fills the conversion spec's start / zero-pad / space-pad fields.

## What it is

```
r4 = value, r5 = output cursor, r6 = conversion character (d i u o x X),
r7 = the conversion spec { u8 flags @0 (0x04 '#', 0x08 '+', 0x10 ' '),
      u8 pad char @1, width @4, precision @8, text start @20,
      zero pad count @32, space pad count @40 }
```

The digits are produced least significant first into a 16-byte stack scratch
with the engine's unsigned remainder (`mod_u32`, 0x8C042E44) and quotient
(`div_u32`, 0x8C042CD4) helpers (`r0 = base`, `r1 = value`), then copied out in
reverse.  The sign / "0x" prefix is written first, so the first character at
the original cursor tells the pad logic whether a sign was emitted.  The two
helpers are the only callees, and both are already natively ported
(`src/native/div_helpers.c`), so the guest calls become **direct native calls**
into `vf3_native_mod_u32` / `vf3_native_div_u32` - the leaf is self-contained.

## The register/stack contract

The register-ready registers (`r0`..`r14`) get several intermediate values
during the digit loop (the base, the magnitude, the scratch slot, the two
helper LITERAL constants in `r3`).  After the run they are restored: `r5` =
the end of the output (one past the copied digits, at the NUL), `r14..r8`
restored from the seven saved stack words, `r15` = the entry stack pointer,
`pr` restored, and SR's T bit cleared (the copy loop's final compare fails).

The **dead stack words** are real and checked: the seven saved registers and
`pr` are pushed on entry, and the digit scratch (16 bytes below the saved
block) plus a few frame words are written and read back.  A port that skips
any of them diverges from the guest's RAM.

## Proof

`tests/format_int_native_replay.c` (`vf3nativeformatint`) seeds both sides with
the same flat RAM and a junk register file, then compares the **whole register
file** (r0..r15, pr, sr), the **whole output buffer** (OUT..+48), the **whole
spec** (SPEC..+44, where the start / zero-pad / space-pad fields land) and the
**digit scratch + dead stack words** (frame-16 .. SP0+4) byte for byte.  The
digits at OUT are also checked against an independent decimal / hex / octal
conversion.

Scenarios cover every branch: positive / negative decimal, zero (with and
without precision), unsigned, the `+` and ` ` flags, hex `x` / `X` with the
`#` alternate form, octal `#`, zero-padding by a precision that exceeds the
digits, space-padding by a width that exceeds the total, a **negative number
with a zero pad char** (the `SPEC_ZEROS` sign-aware path) and the same with a
space pad char (the `SPEC_SPACES` path), the unknown-conversion fallback base,
and a precision smaller than the digit count (which never truncates).

All 15 scenarios replay clean, and the mutation gate
(`tests/format_int_native_mutations.json`, run with
`python tools/mutate.py --keep-going`) catches **15/15** mutations: the two
base decodes, the sign negation, the zero-with-precision digit, the hex letter
/ decimal digit offsets, the octal `#` digit, the `0x` prefix count, the `-`
sign's `used` count, the `+`/` ` swap, the two pad-count computations, the
zero-pad gate, the digit copy order, and the NUL terminator.

One naming note: the `sign_zero_pad_gate_off` mutation was initially *missed*
because no scenario combined a present sign with a non-`'0'` pad char - the
only path where that gate's `pad == '0'` test changes the choice between the
`SPEC_ZEROS` and `SPEC_SPACES` branches.  The `negative space pad` scenario
closes it: with a `-` sign, a width above the total and a space pad char, the
correct code writes the excess to `SPEC_SPACES` and leaves `SPEC_ZEROS` at 0,
while the mutated gate sends it to `SPEC_ZEROS` instead - the spec triple
witnesses the difference.
