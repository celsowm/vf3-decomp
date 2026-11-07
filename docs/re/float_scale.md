# The unsigned-32-to-float scale (SH-4 0x8C039C50 / 0x8C039C70)

A readable port of the fight engine's unsigned-32-to-float scale, and the
evidence for it.

## The functions

| entry | body | what it does |
|---|---|---|
| `0x8C039C50` | `0x0C039C50..0x0C039C6F` (32 B) | reads a 32-bit channel value, converts it to a float, folds the sign bit back in with a 2^32 addition, scales by 1.28 and returns the truncated integer |
| `0x8C039C70` | `0x0C039C70..0x0C039C8F` (32 B) | the same, with a different value pointer |

Both are **off-baseline leaves**: they are not in the baseline inventory
(`extract/analysis/funcs_1ST_READ.unsc.bin.csv`), which carries no
`0x8C039C50`/`0x8C039C70`/`0x8C039C90` row and jumps the region.  Because they
are off-baseline, their ledger rows are worth their own body span: **32 bytes
each** of new coverage.

Both are **true leaves**: they save no registers, open no frame, and call no
other function - the whole body is FP arithmetic on the one value.  The port
needs no stub and no stack frame.

The port: `src/fight/float_scale.c`, registered in `src/fight/readable.c` as
`float_scale` and `float_scale_b`.

## What the functions do

Each entry runs the same pipeline on one 32-bit value:

1. **read the value** - through a literal-pool pointer the entry owns.  The
   two entries differ only here: `0x8C039C50` reads through the pool slot at
   `0x0C039D4C`, `0x8C039C70` through the slot at `0x0C039D58`;
2. **`float FPUL,FR3`** - the value's signed integer becomes a float in `fr3`;
3. **`cmp/ge #0`** - sets the T bit to `(value >= 0)`.  This is the only SR
   write in the body, so the T bit the caller sees is this one;
4. **if the value is negative**, fold the sign bit back in: `lds r2,FPUL;
   fsts FPUL,FR2; fadd FR2,FR3` adds the pool's `4294967296.0f` (`0x4F800000`)
   to `fr3`.  This is the textbook **unsigned-wrapping** trick - the SH-4's
   integer-to-float converts as *signed*, so to get the float of the *unsigned*
   interpretation the guest loads the raw `0x4F800000` bits into FPUL (via
   `lds`, no conversion) and adds it as a float;
5. **scale** - `fmov.s @r0,FR2` loads the pool's `1.28f` (`0x3FA3D70A`) and
   `fmul FR2,FR3` multiplies;
6. **`ftrc FR3,FPUL`** - truncates toward zero; the integer lands in FPUL and
   the exit's delay slot copies it into `r0`, so both carry the answer.

So the result is `(int32)trunc((float)(int32)value + (value < 0 ? 4294967296.0f
: 0.0f)) * 1.28f)` - a `uint32` read as a signed word and rescaled to the range
`[0, 1.28 * 2^32)`-ish, which is how the engine turns packed channel bits into
a scaled float.

## The literal pool

Every entry is read at run time, the way the guest reads it:

```
0x0C039D4C -> the value's address   (the first entry's own global)
0x0C039D58 -> the value's address   (the second entry's own global)
0x0C039D50 -> 4294967296.0f (0x4F800000)   the 2^32 the sign bit folds in
0x0C039D54 -> 1.28f          (0x3FA3D70A)   the scale
```

The two constants were verified against the ROM image
(`extract/exe/1ST_READ.unsc.bin`): `0x0C039D50` holds `0x4F800000` and
`0x0C039D54` holds `0x3FA3D70A`.

## The details the port has to keep

**The `bt/s` delay slot runs on *both* paths.**  The `float FPUL,FR3` sits in
the delay slot of the branch that decides the sign fold, so `fr3` always holds
`float(value)` before the branch is resolved.  A port that only converts on the
not-negative path leaves `fr3` wrong for every negative value.

**The add's operand is the *raw bits* of the pool word.**  `lds r2,FPUL; fsts
FPUL,FR2` copies `0x4F800000` straight through without any conversion - the
port must reuse the pool word **as a float** (`vf3_bits_f32`), not some
C-computed `4294967296.0f` expression that might round differently.

**The multiplier overwrites `fr2` on every path.**  The `fmov.s @r0,FR2` that
loads `1.28f` runs after the add on the negative path too, so the final `fr2`
is the multiplier **either way** - the registered `out_regs` mask
`FR(2)|FR(3)` names both, and the test checks `fr2` equals the multiplier in
both arms.

**The T bit is `(value >= 0)`.**  The `cmp/ge #0` at the top is the body's only
SR write, so it is what the caller reads.  The `set_t` helper keeps the T bit
(`v[17]&1`) consistent with the guest.

**`ftrc` leaves the integer in *both* FPUL and r0.**  The exit's `rts` delay
slot copies FPUL into `r0`, so the truncation is visible in `v[53]` (FPUL) and
`v[0]`.

**The clobbered registers differ by path.**  The guest leaves `r2`/`r3` behind:
`r3` is the value on both paths, `r2` is the value's *pointer* on the
non-negative path and the **pool's plus-bits word** on the negative path (the
`lds r2,FPUL` that feeds the fold).  A port that leaves `r2` as the pointer on
the negative path fails the differential.

## The evidence

Because no corpus exists for either entry - `f_0c039c5*`/`f_0c039c7*` are
absent from `extract/analysis` - the proof is **differential plus a fixture
model**, not an oracle leg (the same shape as `state_advance`,
`docs/re/state_advance.md`).  There is no oracle corpus for either entry, so
the chain here is only *readable port == generated translation*, with the
fixture standing in for the reference's own RAM.

**The differential** (`tests/float_scale_replay.c`, 20 cases) compares three
arms on the whole register file (including FPUL and the FP registers), SR with
its T bit, the return PC, the failed PC, the out-of-window counter and every
RAM byte:

1. the generated chain - the reference (`vf3_matrix_family` on the tickgap
   adapter that owns the entry);
2. the readable port called directly;
3. the readable port reached through the readable **override** that serves only
   the entry under test (how the native tick reaches it).

Each fixture uses the game's own pool addresses (`0x0C039D4C..0x0C039D58`) and
a shadow data window holding the two value slots.  The 10 value scenarios
cover **every branch**: zero, small and mid positives, values near both int32
extremes, `int32 min`, small and large negatives, and a value with the sign bit
set plus a large mantissa - so both sides of the `cmp/ge` and the truncation's
clamp paths are exercised.

On top of the differential, **every case is checked against a model computed
straight from the fixture** through the SH-4 FPU helpers (`vf3_fpu_float`,
`vf3_fpu_binary`, `vf3_fpu_ftrc`) - the answer in r0 and FPUL, the T bit, and
the two FR registers - without consulting the translation.  This is what makes
a fixture that is not where the guest looks fail: both arms would read the same
wrong bytes, but the model reads the fixture's own slots.

**The mutations** (`tests/float_scale_mutations.json`, 20 of them) are all
caught by `tools/mutate.py` (**20/20**): both entries' pointers, the value's
width (halfword), the sign test's strictness and sense, the fold's own
existence, its operand, its sign, its result being dropped, the scale's operand
and existence, the truncation, the T bit, `r3` holding the pointer instead of
the value, `r2` holding the value instead of the pointer, the negative path
leaving the pointer in `r2`, `fr2`/`fr3` swapped, FPUL and r0, and the delay
slot dropped.

Two details are worth naming as **observed but intentionally not mutated**:

* **the dead sign fold dropped on the positive path is not a separate
  mutation** - it is covered by "the fold never runs" (which makes the negative
  value's answer wrong) and by the model, and the positive path has no fold to
  drop by construction;
* **`fr3` holding the pre-scale or post-truncate value** is owned by the
  `fr2`/`fr3` swap and the `r0` mutations; the FR registers are checked against
  the model, so the port cannot drift.

## The tooling lessons

* **A `cmp/ge #0` sets T = (Rn >= 0), not the reverse.**  The positive path
  leaves the T bit set; the negative path clears it.  `tools/adapter_dump.py`
  renders it as `(int32_t)r3>=0`, which is the start of the body's only SR
  write - a port that computes the T bit after the fold (which does **not**
  touch SR) still reads correctly here only because nothing after the
  `cmp/ge` touches SR.
* **An entry that is a true leaf needs no frame in the fixture.**  The two
  bodies push nothing, so the test's stack pointer is a caller value and the
  only RAM the guest touches is the pool and the value.  `ram->oob` stays zero
  on every case for the right reason - the guest really does read nothing
  outside the two windows.
* **A `float FPUL,FRn` runs the bit-exact convert, not a C cast.**  The port
  goes through `vf3_f_from_int` so that FPSCR rounding (round-toward-zero here)
  and the int32-edge cases match the SH-4 exactly; the model recomputes the
  same way with `vf3_fpu_float`/`vf3_fpu_ftrc`.
* **An off-baseline leaf's body ends at its `rts`'s delay slot.**  The first
  entry's `rts` is at `0x0C039C6C` and its delay slot (`mov FPUL,r0`) at
  `0x0C039C6E`, so the body is `0x0C039C50..0x0C039C6F` - 32 bytes - and the
  second entry starts at `0x0C039C70`.  The union credit is therefore the two
  full 32-byte spans (437,710 -> 437,774 B).
* **A sibling pair can share one port and one test.**  The two entries differ
  only in their pool pointer, so `float_scale()` is shared and the single test
  runs every scenario against both entries through their own registry rows.

## Coverage

The two rows take the verified C address union from **437,710** to **437,774**
bytes (both entries being off-baseline, their rows are worth their full body
span - 64 bytes total).  Both are marked `unexercised` in
`docs/readable_status.csv`: nothing in the captured oracle's tick calls them as
watched entries, so there is no per-entry oracle corpus - the readable ports
are proved against the generated translation they replace, exactly as the
AGENTS.md "readable track" contract describes.
