# Row 0 of the pose orchestration (0x8C09EAF2)

`src/native/motion_pose.c` now builds the actor's root attachment row from
the recovered guest chain instead of the authored bind constant.  The native
function is `vf3_native_motion_row0()`; `vf3_native_motion_pose_actor()`
substitutes it for row 0 and keeps the documented authored rig for rows 1..17.

## The chain

The guest builds row 0 (actor `+0x180`) in five stages:

1. **root orientation** (`0x8C09D9EA`): `R_root = Ry(yaw) * Rz(f0) *
   Ry(f1) * Rx(f2)`, where `yaw` is the actor halfword at `+0x1E`
   (sign-extended) and `f0..f2` are pose fields 0..2 (zero-extended).
2. **translation**: `matrix_set_translation(actor+0x1EFC)` sets the row's
   translation to seven_pass point 0.
3. **halfword frame** (`0x8C09D4B0`): `R_half = R_root * Rz(hw0) *
   Ry(arg + hw1) * Rx(hw2)`, where `hw0..hw2` are pose fields 3..5
   (zero-extended) and `arg` is the actor halfword at `+0x22E4`
   (sign-extended; the sum is masked to 16 bits).
4. **pass_prep** (`0x8C09DBC0`): inverts `R_half` and transforms the summed
   actor triple, so `d = R_half^T * (point1 + offset - t)`.  `point1` is
   seven_pass point 1 and `offset` is the three floats at
   `+0x208C/+0x2090/+0x2094`.
5. **unit_triple** (`0x8C09DC34`): `R_row0 = R_half * Rz(heading(d)) *
   Ry(pitch(d))`, with the translation left at `t`.

The row's translation is `t` because the frame's `+0xA4` object carries it:
the `xf_store` to frame `+0xD4` lands on that object's translation field
(`+0xA4 + 48`), and `store_keep_translation` preserves it.

## Evidence

`tests/native_motion_row0_replay.c` proves the native build two ways:

* a differential against an independent re-statement of the chain over six
  synthetic actor layouts (bind fields, root fields, halfword fields,
  arg + offsets, the `0x20000000` origin flag, a tiny triple);
* the oracle leg over the four retained `0x8C09EAF2` specimens in
  `extract/analysis/native_pose_orchestration_s29_v1`.  All four match the
  guest's exit row to 2e-4 (the residual is last-bit: the guest's `fsrra`
  and integer FSCA table against the native `1/sqrtf` and `sinf`/`cosf`).

13/13 mutations caught (`tests/native_motion_row0_mutations.json`): the
translation stores, both halfword ends, the dropped `arg`, the halfword
composition order, the unit_triple base, the inverse-transform indexing, the
yaw, the origin-flag bit, and both source-point components.

## Runtime wiring

The recovered row needs actor state the native fight shell does not carry
yet: the yaw/position/mode/flags words, the `+0x22E4` argument and the three
`+0x208C` floats.  `vf3port` therefore still draws row 0 from the authored
bind; `vf3nativemotionpreview --row0` exercises the recovered chain with
those inputs supplied explicitly, e.g.

```
build/vf3nativemotionpreview.exe --assets build/vf3_assets.vfa \
    --fighter akira --mt MTAKIJAC.BIN --motion 0x41A --cycle 60 \
    --frames 0 2 --row0 --yaw -16064 --pos -4.31287,8.99,-3.22019 \
    --mode 11 --flags 0x400000 --pose-flags 0x400000 --global-flags 0x8 \
    --out build/row0_%02u.bmp
```

Supplying the actor inputs from the native fight state (and recovering the
action-to-motion mapping) is the remaining work before the runtime draws the
recovered root row.

## The aim-record input (recovered)

The same orchestration body also selects the record its two `aim_frame`
builders (0x8C09E060, 0x8C09E6B2) read: when the actor byte at `+0x61` is not
12, `r11 = *(u32 *)(0x0C10DABC + byte * 4)` and the builders use `r11 + 4`
(first call) / `r11 + 24` (second) as their object.  The byte is the actor
`+0x420B`, and the table plus its five records are 1ST_READ constants, so the
native port carries them as data: `vf3_native_motion_aim_record()`
(`src/native/motion_pose.c`) serves the twelve leading floats of record
`kind` (0..4) and refuses anything else.  `vf3_native_motion_actor` gained
`aim_record` for the byte.

The recovered index is **0**: the four retained `0x8C09EAF2` specimens' exit
shadows carry the first `aim_frame`'s saved `r11` (the orchestration leaves
`r15 = sp0 - 236`, the call is after a 64-byte `matrix_push` and six argument
pushes, so the saved `r11` sits at `sp0 - 340`), and it is `0x0C10D940` -
record 0 - in all four.  Record 0's translation is `(.28, 0, .12)`, the
measured row-2 offset the authored rig already quotes.

`tests/native_motion_aim_replay.c` proves the embedded table against the
image bytes, the selector's bounds, and that oracle leg (4/4); 3/3 mutations
caught (`tests/native_motion_aim_mutations.json`).  The `aim_frame` builders
themselves are still the guest helpers, so rows 2..9 keep the authored rig
until those helpers are ported.
