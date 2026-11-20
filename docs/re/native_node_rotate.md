# native_node_rotate (0x8C09F83C)

The fighter's nodes turned around - seven twelve-byte records rotated about
the Y axis and the root moved - ported natively in `src/native/node_rotate.c`
(`vf3_native_node_rotate`) as a plain-C transcription of the readable port
`src/fight/node_rotate.c` (`vf3_node_rotate_entry`).

## Why this leaf

The readable authority is a **self-contained FP leaf** that runs under
round-to-nearest with no FTZ (the FPSCR is 0), the same mode as the native
`fmaf`/plain-C-float approach, and it turns records via the FR bank and the
caller's cosine and sine.  It is exactly the boundary the native `aim_math`
register file + FR bank + SR model is built for.

## The body

The function is handed the object in r4 and an angle in FR4 (the cosine) and
FR5 (the sine).  It walks seven twelve-byte records and rotates each one's two
floats (eight bytes apart) about the Y axis, then moves the root's three
coordinates by the value the caller leaves in FR6.

- The seven records are walked from r4, twelve bytes apart; each holds two
  floats and is read through FR8 (the second float) and FR9 (the first).
- The rotation is expressed through the FR bank: the stored first float is
  `sin * first - cos * second` and the stored second is
  `sin * second + first * cos`, the second summed through a **fused**
  multiply-add (`fmaf`), which rounds once where a plain `a * b + c` rounds
  twice.
- The root's three coordinates sit at the record's `+0x58`, at the offset in
  the literal pool (`0x0c09f8d0` -> `0x6c`) and twenty-four bytes below that;
  each is moved by FR6 in turn.
- The loop's counter is decremented **at the top** while the branch that ends
  the loop is at the bottom, so the T bit the caller sees is the last
  iteration's (set, the counter reached zero).

## Evidence

The **differential** (`tests/node_rotate_native_replay.c`, target
`vf3nativenode_rotate`) runs the native port against the readable guest port
from the same seed.  The literal pool and the object (the seven records and
the root's coordinates) sit at the game's own addresses, spanned by one flat
buffer.  The whole region is compared byte for byte, together with the
registers, the FR bank, SR's T bit and an independent fixture model that
computes the record rotation and the root's move straight from the fixture.
The scenarios cover the identity, a quarter turn, a half turn, a general
angle, the root's move and both.  **6/6 PASS.**

The **mutation gate** (`tests/node_rotate_native_mutations.json`) applies
eleven mutations mapped onto the native lines: the rotation's signs and
sources (cos vs sin, first vs second), the fused multiply-add reading the
wrong factor, the first and second stored floats swapped, the node stride and
the second-float offset wrong, the root move subtracts, the third coordinate
read from the wrong offset, and the record's first float read from its second
slot.  The differential catches **all 11**.

```text
build\vf3nativenode_rotate.exe ->
  node_rotate_native_replay: PASS  (6/6)
python tools/mutate.py --port src/native/node_rotate.c --exe build/vf3nativenode_rotate.exe \
    --mutations tests/node_rotate_native_mutations.json --target vf3nativenode_rotate \
    --keep-going
  11/11 mutations caught
```

The native port is the readable port's logic, so the chain
`native == readable == generated == oracle` is closed per the readable
authority (the readable port itself is differential-replayed,
`docs/re/node_rotate.md`).

## Notes

* The flat buffer base equals the **pool's** base (`0x0c09f8d0`), and the
  buffer spans the pool and the object (at `0x0c120000`) up to `0x0c120080`.
* The port reads FR4/FR5/FR6 as the caller's cosine/sine/move; the differential
  seeds the native FR bank from the guest's **incoming** values.
* The readable's own doc comment phrases the rotation as
  `cos * first - sin * second`; the code stores `sin * first - cos * second`,
  and the fixture model reproduces the code.  The differential over the whole
  RAM region is the authority.
