# native_midpoint_angles (0x8C09D452)

The three-angle wrapper, ported natively in `src/native/midpoint_angles.c`
(`vf3_native_midpoint_angles`) as a plain-C transcription of the readable port
`src/fight/readable/midpoint_angles.c` (`vf3_midpoint_angles_entry`).

## Why this leaf

The readable authority is a small wrapper that composes three matrix rotations
out of three angle values.  Its three callees - rotate_z / rotate_y / rotate_x
- are already native leaves in `aim_math.c`
(`vf3_aim_rotate_z/y/x_angle`, which left-multiply `a->xm` by the rotation),
so this is an inexpensive *compose* port: the wrapper's own logic is the
station-keeping (frame, pr, r15, the tail transfer) and the XMTRX prep.

## The body

r4, r5, r6 are three angle values.  The wrapper saves them as halfwords in a
twelve-byte frame (r4 at `f`, r5 at `+4`, r6 at `+8`, under the saved pr at
`sp0-SAVED`), then composes three rotations onto the current XMTRX (`a->xm`):

* `rotate_z` with r6's halfword (frame `+8`),
* `rotate_y` with r5's halfword (frame `+4`),
* a **tail transfer** to `rotate_x` with r4's halfword (frame), which pops pr
  and runs in the caller's frame.

Each halfword is read back sign-extended (`mov.w`) and then zero-extended
(`extu.w` in the jsr/jmp delay slot), so the callee sees the low sixteen bits.
r14 is never touched; r15 ends at the entry sp.  The three handler pointers
are read from the literal pool at run time (the test seeds `0x0c09d580/584/588`).

The register leftovers the guest leaves, reproduced here: r4 = the
zero-extended first halfword (the tail transfer), r3 = the rotate_x handler
pointer, r0 = the sign-extended second halfword, r15 = the entry sp,
r14/pr untouched.

## Evidence

The **differential** (`tests/midpoint_angles_native_replay.c`, target
`vf3nativemidpointangles`) runs the native port against the readable guest
port from the same seed over seven scenarios (identity, each single-axis
quarter turn, mixed, high-bit angles, and a capture-ish set).  XMTRX starts as
the identity on both sides.  It compares the whole RAM region (pool + stack,
covering the frame bytes the wrapper writes) byte for byte, the contract
integer registers (r0, r3, r4, r14, r15, pr, SR's T bit), the XMTRX with the
same `1e-4` tolerance as the readable test's own model (the native helper uses
`sinf`/`cosf`, the guest uses the game's rotation tables, so they are not
bit-identical), and the frame bytes directly against the fixture.  **7/7
PASS.**

The **mutation gate** (`tests/midpoint_angles_native_mutations.json`) applies
eight mutations mapped onto the native lines: the z/y angle sources swapped,
the y/x angle sources swapped, rotate_z replaced by rotate_y, the tail's
handler pointer the wrong pool slot, the frame's first halfword stored as a
full word, the r4/r5 frame stores swapped, the final r15 restore dropped (the
tail no longer restores the caller's sp), and the saved pr popped from the
wrong offset.  The differential catches **all 8** (the frame store width
mutation originally used a non-existent `set_u8` and failed to compile; the
`set_u32` word-store form is the observable equivalent).

```
build\vf3nativemidpointangles.exe ->
  midpoint_angles_native_replay: PASS
python tools/mutate.py --port src/native/midpoint_angles.c --exe build/vf3nativemidpointangles.exe \
    --mutations tests/midpoint_angles_native_mutations.json --target vf3nativemidpointangles
  8/8 mutations caught
```

The native port is the readable port's logic over the native rotation leaves,
so the chain `native == readable == generated` is closed per the readable
authority.

## Notes

* The tail transfer's pr is the **popped** value (which is the caller's own
  pr), so a redundant `pr = pr0` assignment after the pop was removed - it
  made the pop unobservable, and the `pr_popped_wrong` mutation would not have
  been caught.
* The frame bytes are part of the contract: the wrapper writes the three
  halfwords there and the test compares every RAM byte, so a port that skipped
  the frame would still be caught.
