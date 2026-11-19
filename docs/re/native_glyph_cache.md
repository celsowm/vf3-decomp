# Native HUD sprite pool (0x8C0C1FBA)

`src/native/glyph_cache.c` is a plain-C port of the HUD text layer's sprite
pool, SH-4 `0x8C0C1FBA`, readable authority `src/fight/glyph_cache.c`
(`vf3_glyph_cache_entry`), onto the `vf3_native_aim` context.  No guest SH-4
code runs at runtime.  The port transcribes the readable body and **inlines
its five guest callees** as static helpers:

| guest | nibble | helper |
|-------|--------|--------|
| `0x8C0C1FBA` | the retirement **self-call** (retire-key mode) | a direct loop that clears every matching pool entry |
| `0x8C07B2BE` | `pool_alloc` | `pool_alloc()` |
| `0x8C07B4D4` | `tex_cell_load` | `tex_cell_load()` |
| `0x8C07B35C` | `sprite_rect_a` | `sprite_rect_a()` |
| `0x8C07B398` | `sprite_rect_b` | `sprite_rect_b()` |

It is the native counterpart of the inlined `vf3_glyph_cache_entry` body and
the `vf3_pool_alloc_entry` that `src/fight/glyph_cache.c` exposes readably
(the three sprite/cell helpers live in `src/fight/sprite_uv.c`).

## What the function does

`glyph_cache(r4 = cursor word, r5 = key, r6 = layer, r7 = packed cell,
[sp0] = packed texel offsets, [sp0+4] = flag bits)` returns `r0` = the sprite
object inside the layer's pool entry (or `0`).  The layer keeps a pool of
120 entries of 68 bytes at `*(layer+12)` and a rotating allocation cursor
(`u16` at `layer+42`).  An entry is `{ u16 live+flags, u16 key, u16 sprite
cell, u16 column*8, u16 row*8, u16 width/8, u16 height/8, ... sprite object
at +16 }`.

Two modes:

- **Retire** (`key` bit `0x8000`): clear every entry drawn at this
  column/row with the same plain key, return `0`.
- **Allocate**: first **self-call in retire mode** (clear a previous glyph at
  the cell), then `pool_alloc` for a fresh entry, fill the cell rectangle,
  load the texture cell (`tex_cell_load`), overlay the optional packed texel
  offsets, and build the sprite object with `sprite_rect_a`/`sprite_rect_b`.
  The flag bits become the entry's flag word and the TA header handed to the
  object.

## The native transcription

The port follows the family convention: only the **saved block** - r8..r14
pushed at `sp0-28..sp0-4`, fr15..fr12 at `sp0-44..sp0-32`, pr at `sp0-48` -
is written to RAM and restored at the epilogue.  The function's own
20-byte frame sits at `sp0-68..sp0-49` and the dead spills the callees leave
below it (`sp0-72/-76`) are reproduced so the stack region compares
bit for bit.

The float geometry (the sprite object's position/UV words, the cell-load
scratch reciprocals) is produced by the same round-toward-zero + FTZ
wrappers `hitbox_overlap.c` uses (`ft0`/`fadd`/`fmul`/`fdivv` + `flz`), so
the stored floats agree with the guest **bit for bit** rather than just
within a tolerance - the cell widths and UV extents are integers in the
sprite path and must not drift.

The inlined callees keep the guest's register leftovers (r0..r7, FR0..FR11)
for the smoke of it, but the proof compares only the contract registers
(r0 as the result, r8..r14, r15, pr, SR's T bit and fr12..fr15), so those
leftovers are not load-bearing.

## Proof

`tests/glyph_cache_native_replay.c` (`vf3nativeglyphcache`) lays out the
layer, the 120-entry pool, both cell tables, the screen scale/offset
constants, the tint table and the sprite-cell table, seeds the entry
registers and the two caller stack words, and runs the readable
`vf3_glyph_cache_entry` (with `vf3_family_override = vf3_readable_override`
so the five nested calls route to the **readable** callees, not the
generated adapters) and the native `vf3_native_glyph_cache` from the same
seed.  It compares:

- the **pool** region (the allocated entry's u16 fields and the float sprite
  object) bit for bit;
- the **cell-load scratch** block, bit for bit;
- the **layer** object, bit for bit;
- the **stack** region `[sp0-76, sp0+16)`, bit for bit;
- the **contract registers**: r0 (the result), r8..r14, r15, pr, SR's T bit
  (as an equality) and fr12..fr15.

Five fixtures push the whole function:

1. **retire path** (key `0x8001`) with a matching prior glyph to clear;
2. **allocate pair-id** (`0x0042`, packed cell set, no texel offsets) with a
   prior glyph to retire;
3. **allocate record offsets** (cell-flag key `0x4005`, `offsets = 0x01020304`,
   flags `9`) - the record table, the texel-offset overlay and the LIT/blend
   header bits;
4. **allocate flags** (`flags = 0x2F`) - every live/flag bit;
5. **full pool** - every entry busy, so `pool_alloc` returns 0.

The mutation gate `tests/glyph_cache_native_mutations.json` catches **10/10**:
the retire column equality, the retire plain-key xor, `tex_cell_load`'s pair
T bit, the texel-offset x unpacking, the width/8 shift, the `bottom - 1`
fudge, the LIT-header flag guard, the flag-word bit-2 OR, the plain-header
constant and `sprite_rect_a`'s vh axis.

## Care points

- **A readable port's own guest calls route to the generated adapters by
  default.**  `glyph_cache` makes five nested `vf3_guest_call`s; without the
  readable override the matrix family serves them from the *generated*
  adapters, whose literal-pool/device behaviour is not what the fixture
  seeds, and the retirement self-call recursed until the C stack overflowed
  (`0xC00000FD`).  `tests/glyph_cache_native_replay.c` therefore sets
  `vf3_family_override = vf3_readable_override`, which routes all five to the
  readable implementations - exactly the chain the native port transcribes.
- **The `live = 1` write must precede the flag ORs.**  The readable sets
  `entry = 1` and *then* ors the flag bits in; the first native draft wrote
  `1` last and wiped the ORs, so the entry's live/flags word came out `1`
  instead of `1|flags`.  The `req_header` fixtures (flags `9`/`0x2F`) caught
  it.
- **The retire self-call is reached with `key | KEY_RETIRE`.**  In the
  allocate path the readable recurses with the retire bit added; the inlined
  helper computes `plain_key = key ^ KEY_RETIRE`, so it must be fed the
  *retire-form* key or it matches the wrong entries.  The fixture's prior
  glyph (`have_prior`) pins this.
- **SR's T bit ends as `tex_cell_load`'s.**  `pool_alloc` and `tex_cell_load`
  both set SR; `tex_cell_load` runs last and the sprite rects never touch SR,
  so the success path leaves `T = !(key has the cell flag)`, and the retire
  path (which never calls any SR-setting callee) leaves the entry SR
  unchanged.
