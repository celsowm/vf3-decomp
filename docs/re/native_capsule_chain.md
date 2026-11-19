# Native capsule node-chain keeper (0x8C070008)

`src/native/capsule_chain.c` is a plain-C port of the fight engine's
`vf3_capsule_chain_entry` (SH-4 `0x8C070008`, readable authority
`src/fight/capsule_chain.c`) onto the `vf3_native_aim` context.  No guest
SH-4 code runs at runtime; the port reads and writes the flat matrix RAM
through `ram_base` and keeps the register file and FR bank in
`vf3_native_aim`, exactly like the rest of the native aim/pose family.

## What the function does

Given an owner object (r4, whose bytes `+96`/`+97` pick which of the first
nodes are skipped), a capsule record (r5), the end of a node array (r6) and
an int16 part number (r7), it keeps a chain of 24-byte nodes (a vec3 at the
node start) out of the capsule and re-applies the link lengths:

- The record's node count at `+0x58` and the division helper
  (`0x8C042D7C`, `vf3_mod_s32_entry`) decide the layout: an **even** count
  walks the array from both ends toward the middle with two walkers, an
  **odd** count walks one chain.
- Each node is tested against the capsule by two stages (A and B, differing
  in whether the node's distance or the cross length is kept in the frame
  slot) against the two end points / axes:
  - **behind** the end cap -> the node is pulled onto the sphere (the very
    first test pulls by `|d| - radius`);
  - **beside** the segment -> the node is moved radially out of the
    cylinder by `radius - |d x axis|`;
  - **beyond** the axis length -> untouched.
- After the stages each node is pulled back to its neighbour's link length
  (`rec + 0x60`) from its anchor.

The capsule structure's addresses: `+0x74`/`+0x80` the two axis unit
vectors, `+0x8C`/`+0x98` the two end points, `+0xA8` the axis length,
`+0xAC` the radius.

On exit the port restores r8..r14, fr12..fr15, pr and sp to their entry
values and clears SR's T bit, matching the guest's `cmp/pl` last test.

## The native transcription

The readable port keeps the FR-register leftovers and the frame slots
(`frame+8 .. +36`, `+44`, `+56`, `+68`) identical to the original, because it
was written byte-faithful against the oracle.  The native port follows the
family convention instead: it reproduces the **branch selection** (the
`behind`/`beside`/`beyond` arm and the walker/parity layout) and the **node
positions** (the function's real output) with plain-C `sqrtf` arithmetic,
and is proved against the readable at the native float tolerance.  It also
writes the frame's control words (`+0` pairs, `+4` anchor, `+40` flag) and
the saved-register stack, which match bit for bit.

## Proof

`tests/capsule_chain_native_replay.c` (`vf3nativecapsulechain`) seeds a
capsule and an array of nodes, runs the readable `vf3_capsule_chain_entry`
and the native `vf3_native_capsule_chain` from the same seed, and compares:

- the **node positions** (every vec3 word of the node array) at the 2e-3
  float tolerance (non-finite words must match exactly);
- the **frame + saved-register stack** (sp0-48..sp0) bit for bit;
- the **contract registers**: r8..r14, r15, pr, fr12..fr15 and SR's T bit
  (seeded set, must come out clear).

Five cases cover the even two-walker layout, the odd single chain,
`skip_first` through both owner-door conditions (`+97 == 4` with `part <= 4`
and `+96 == 8` with `part <= 3`), and a single-node degenerate.  The node
worst-case residual across cases is ~1.9e-6, well under the 2e-3 tolerance.

The mutation gate `tests/capsule_chain_native_mutations.json` catches **9/9**
mutations: the link-length scale, a zeroed link vector, the SR T-bit clear,
the saved-register restore order, the even/odd parity, the pr restore, the
stage-A side direction, a stage-B that wrongly reuses the second capsule, and
the `skip_first` owner-byte constant.

## Two care points the proof exposed

- **A native seed that puts the T bit in the wrong SR bit makes the "clear
  on exit" check vacuous.**  The first version seeded `sr = 0x60000100`
  (bit 8), so bit 0 was already clear and the T-clear mutation was "missed".
  The T bit is bit 0 of SR; the seed is `0x60000001`.
- **A boxed owner-byte seed that writes the byte at the wrong offset makes
  the skip_first cases pass without ever skipping.**  The first seeder packed
  `b96`/`b97` into the word at `+96`, landing them at `+98`/`+99`; the port
  reads the raw bytes at `+96`/`+97`, so neither skip condition fired.  The
  two skip gadgets are written as the two little-endian bytes at `+96`/`+97`.

## Run it

```
cmake --build build --target vf3nativecapsulechain
build/vf3nativecapsulechain            # (from the repo root; needs extract/exe)
python tools/mutate.py --port src/native/capsule_chain.c \
    --exe build/vf3nativecapsulechain.exe \
    --mutations tests/capsule_chain_native_mutations.json \
    --target vf3nativecapsulechain
```
