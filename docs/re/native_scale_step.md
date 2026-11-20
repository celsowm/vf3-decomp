# native_scale_step (0x8C0CB8AC)

The motion VM's scale step, ported natively in `src/native/scale_step.c`
(`vf3_native_scale_step`) as a plain-C transcription of the readable port
`src/fight/scale_step.c` (`vf3_scale_step_entry`).

## Why this leaf

The readable authority is a **self-contained HP leaf** - it calls nobody and
keeps **no stack frame**, but it reads the literal pool, the mode byte, the
VM's structure and the caller's structure, uses the **FR bank** for the two
constants and the scale, and **FPUL** as a scratch word for the count.  It is
also one of the readable ports whose FP work rides the shared FR helpers, so
it is exactly the boundary the native `aim_math` FR bank + FPUL model.

## The body

The motion VM keeps a mode byte and two float constants.  When the mode byte
(masked to eight then to **four** bits) says 1, this function takes the step
count, makes it a positive number, and scales the two constants with it:

```
result = constant_two * count + constant_one
```

- The mode byte's pointer, the VM's structure pointer, the two constants and
  the destination offset are the literal pool's entries at 0x0c0cb9b8/bc/c0/c4
  and 0x0c0cb9b4, read at run time.
- The count is a sign-extended halfword reached through the VM structure at
  COUNT_SLOT (0x44) then COUNT_VALUE (0x54); it is biased by 60 and made
  positive, and the positive value is parked in **FPUL**.
- The scale is a **fused** multiply-add (the guest's `fmac` rounds once), so
  the port uses `fmaf`, not a multiply and an add.
- The result goes into the caller's structure (r4) at +16 and into the
  structure the pointer at +32 of the VM's structure names, at the pool's
  offset.
- When the mode byte is not 1 the function returns immediately.

## Evidence

The **differential** (`tests/scale_step_native_replay.c`, target
`vf3nativescale_step`) runs the native port against the readable guest port
from the same seed.  The pool, the mode byte, the VM structure and the
caller's structure sit at the game's own addresses, spanned by one flat
buffer.  The whole region is compared byte for byte, together with the
registers (r0..r15, pr), the FR bank, FPUL and SR's T bit, and the two stored
floats against an independent fixture-based model written in the test.  The
scenarios cover the modes that do not step (0, 2, and 9 kept out by the
four-bit mask), the masked mode 17, and counts above, below and exactly at
the bias.  **7/7 PASS.**

The **mutation gate** (`tests/scale_step_native_mutations.json`) applies
fourteen mutations mapped onto the native lines: the destination offset, mode
and VM pointers and the two constants read from the wrong pool slot, the step
mode becoming 2, the four-bit mode mask dropped, the count and value slots and
the bias changed, the count not made positive, the count not parked in FPUL,
the destination slot moved, and the first store going to +20 instead of +16.
The differential catches **all 14**.

```text
build\vf3nativescale_step.exe ->
  scale_step_native_replay: PASS  (7/7)
python tools/mutate.py --port src/native/scale_step.c --exe build/vf3nativescale_step.exe \
    --mutations tests/scale_step_native_mutations.json --target vf3nativescale_step \
    --keep-going
  14/14 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated == oracle` is closed per the readable
authority (the readable port itself is oracle-replayed, `docs/re/scale_step.md`).

## Notes

* The flat buffer base equals the **pool's** base (`0x0c0cb9b0`), and the
  buffer spans the pool, the mode byte (at `0x0c140000`), the VM structure
  (at `0x0c150000`) and the caller's structure (at `0x0c160000`) up to
  `0x0c160040`.
* The count is read at `COUNT_PTR + 0x54`, not at `COUNT_PTR` (the fixture
  seeds the word the guest actually reads).
* The native `a.fpul` is seeded from the guest's **incoming** value (captured
  before the guest runs), so the touch-it-on-the-step path distinguishes the
  port that parks the count from one that does not.
* The FPSCR is single precision round-to-nearest, so the fused multiply-add
  is `fmaf`; for the integer counts the result is exact in every rounding
  mode, which is why the separate `.c` reads match byte for byte.
