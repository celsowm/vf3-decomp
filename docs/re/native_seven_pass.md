# Native seven_pass (0x8C09DA72)

`src/native/seven_pass.c`, registered as `seven_pass` on the native pose path,
proved against the readable guest port `src/fight/seven_pass.c` by
`tests/seven_pass_native_replay.c` (6 differential cases) and by the mutation
gate (14/14 caught, tests/seven_pass_mutations.json).

## What it is

`seven_pass` runs the seven-segment pass for one object.  It is the first
callee of the pose orchestration (0x8C09EAF2), and its SEG_B (+0x1EFC) outputs
feed `matrix_set_translation(actor+0x1EFC)` and the downstream
`xform_point` / `aim_frame` calls, so the orchestration differential can only
pass once seven_pass is byte-exact.  This is the missing large piece of the
native pose-orchestration host; the readable guest already covered it.

## The three undocumented matrix sub-ops

`seven_pass` calls several 0x8C03xxxx matrix operations through the router.
Three were undocumented in `aim_math.c`; they were reversed out of the
generated bodies in `matrix_adapters.c`:

- **0x8C03CCB0** = identity.  The generated body sets the identity via the FR
  bank (toggling the FPSCR PR bit twice, a net no-op).  `vf3_aim_identity`.
- **0x8C03CC90(r4)** = load the three floats at r4 into FR4/FR5/FR6, then a
  **tail call** to the pointer in the pool at `0x0C03CCA4`.  The image
  confirms that pool value is `0x8C03CC60` = `translate_by`, so the op is
  `vf3_aim_translate_by` with FR4/5/6 pre-loaded from r4.
- **0x8C03CEE0(r4, r5, r6)** = 3-vector subtract: writes `dst[i] = r5[i] -
  r6[i]` at r4, stepping registers by the FPSCR PR width (4 bytes here).
  Inlined.

The rest map directly: 0x8C03C4F0(0) = `vf3_aim_push(0)`, 0x8C03C880 =
`vf3_aim_rotate_y_angle`, 0x8C03B450 = `vf3_aim_xform_point`, 0x8C03C4A0(1) =
`vf3_aim_pop`.

## The algorithm (matching the readable port)

The object (r4) provides: word0 (FLAG_STAGE 0x20000000 decides the frame vec0),
the second vector at +16/+20/+24, the yaw halfword at +30, the flags at +72,
and the mode byte at +97.  A 48-byte frame is reserved under nine saved words
(f = sp0 - 84).

1. **Second vector** at frame +36 from obj+16/+20/+24.  Unless flags (+72)
   carry 0x29000, the mode byte lowers the y by a fixed amount: 6 -> 0.0300,
   8 -> 0.0600, 11 -> 0.0550, 12 -> 0.0200 (DROP_BITS, applied as
   `f+40 = f+40 - drop` via the FR bank).
2. **Frame vec0** at frame +0: the object's VEC (+0x1D04) when FLAG_STAGE is
   set, else zero.
3. **Matrix setup**: push(0) (saves the entry XMTRX), identity, translate_by
   (the second vector), rotate_y (the sign-extended halfword at obj+30).
4. **Seven segments** (records 12 bytes apart): each iteration subtracts the
   frame vec0 from a SEG_A (+0x1D04) record into frame +24, optionally zeroes
   frame +28 (the zero-y gate: stage word 0x0C29BCCC & 0x800, word0 has 0x40000
   and not 0x8000, flags carry 0x21000), then pushes frame +24 through XMTRX
   into the SEG_B (+0x1EFC) record.
5. **pop(1)** restores the entry XMTRX, so the net observable write is the
   SEG_B region plus the call frame on the stack.

**Drop and zero-y are mutually exclusive in the real logic**: zero-y needs
flags & 0x21000, and 0x21000 is a subset of the drop-skip mask 0x29000, so a
record that satisfies the zero-y gate never takes the drop.  The fixtures
encode this (the mutation that removes mode 12 from the table was initially
missed because the flags value I chose made the drop skip silently — the
proof itself surfaced the conflation).

## Differential

Both sides run on the same flat matrix RAM.  The fixture lays out the object
(word0, second vector, yaw, flags, mode, seven SEG_A records) and the stage
word, then both run and the whole object/SEG region, the call frame and the
final XMTRX are compared (FPU residual tolerated at 2e-3).  The final XMTRX
must equal the entry XMTRX, since push(0)/pop(1) restore it.  Cases cover the
four listed drop modes, a non-listed mode, FLAGS_SKIP, the FLAG_STAGE vec0,
and the zero-y gate (including the 0x1000-only flags mask discrimination).

Because seven_pass reads no literal pool from the image (the sub-ops are
inlined), the test has no image dependency and runs offline.

## Wiring

- `src/native/seven_pass.c` + the declaration in `src/native/pose_callees.h`
- added to the `vf3nativeview` static library in `CMakeLists.txt`
- test target `vf3sevenpass` (links `vf3core vf3nativeview`, includes
  `src/fight src/native`); mutation gate:
  `python tools/mutate.py --port src/native/seven_pass.c --exe
  build/vf3sevenpass.exe --mutations tests/seven_pass_mutations.json
  --target vf3sevenpass`
