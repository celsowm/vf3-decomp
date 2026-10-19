# Boot render wait: ASIC events before vblank (2026-10-19)

The title frame loop arms a render list, then waits on `0x0C16CDF4`. The
emulator's per-frame write sequence (state 22, `mem_watch.py` on
`0x0C16CDCC..0x0C16CDFC`) is:

| writer | word | value | meaning |
|---|---|---|---|
| `0x0C059B52` | `0x0C16CDE4` | list index | current list |
| `0x0C059B62` | `0x0C16CDE8` | `0x0000000F` | lists the frame expects |
| `0x0C059B66` | `0x0C16CDF4` | `1` | render wait armed |
| `0x0C06436A` | `0x0C16CDEC` | `1,3,7,F` | list-end bits `0x80,0x100,0x200,0x400` |
| `0x0C063FB2` | `0x0C16CDCC+4*i` | `3` | list ended |
| `0x0C063B80` | `0x0C16CDCC+4*i` | `4` | vblank display stage |
| `0x0C063F70` | `0x0C16CDF4` | `0` | wait released |
| `0x0C064322` | `0x0C16CDCC+4*i` | `5` | EoR stage |

The list-end bits are PVR events, not SH-4 DMAC channel 2 completions: a
120-frame watch on `0x1FA0002C` (CHCR2) saw **no writes**. The native model
raised the list-end bits only when `vf3_native_take_dma2()` was nonzero; the
GD-read DMA can produce one burst, but the render lists themselves are not
DMAC2-fed, so the cadence is wrong. The EoR bit `0x4` (raised on STARTRENDER)
still fired, which is why the run cycled a little and then timed out instead
of loading `CP_LOGO.BIN`.

There is a second ordering trap. The vblank handler at `0x8C063AF6` writes
`0x0C16CC90 = r14` (the emulator's `r14` is 1 at `0x8C063B74`). The list-end
handler at `0x8C063F4C` reads `0x0C16CC90` into `r8`; if it is nonzero it
returns without clearing `0x0C16CDF4`. The real hardware takes the list-end
ASIC interrupt **before** the vblank pair, when `0x0C16CC90` still holds the
previous frame's 0. The boot harness ran the vblank pair first and the ASIC
handler afterwards, so the list-end handler saw 1 and skipped the release.

## Model

`VF3_ASIC_FIRST=1` in `src/boot_sim.c` moves the vblank pair after the
DMA/render/Maple/ASIC dispatch in `slice_hook()`. It is opt-in so the
previously verified 300-vblank sweep is unchanged. Combined with `VF3_TMU=1`:

- state 21 reaches the resource-loader call site `0x8C07AADE` and the task
  lookup/return path, 0 unowned calls, ending at the sentinel at 87 vblanks
  with the cap active;
- state 25 cycles the render state (`0x0C16CDCC = 7`, `0x0C16CDF4 = 1`) and
  reaches the same frame-loop wait;
- the final GD sector after the state-21 continuation is `0x68cc9`, i.e. the
  end of the `CP_GM_J.BIN` read, not `CP_LOGO.BIN` (`0x68ec9`). The loader is
  being re-entered after the wait; the title timer has not yet reached the
  index-5 request.

## New readable ports on this path

- `0x8C0434C8` (`gd_exec_server_wrapper`): calls the EXEC_SERVER stub
  `0x8C0430B4`, then forces `r0 = 1` in the `rts` delay slot. The port makes
  the BIOS call as a guest call, restores `sp`/`pr`, and returns 1.
- `0x8C0597CA` (`render_callback_stub`): the empty callback in
  `[0x0C16CCF0]` (`rts`); it changes no register. Without it the frame-loop
  wait reports an unowned call at the cap.

Fight regression stays clean: states 7 and 13, 0 unowned, `ram 0 bytes
differ`.

## Open

The title timer/scheduler still has to request file index 5. The long
`VF3_ASIC_FIRST=1 VF3_TMU=1` state-25 run (`--vblank-cap 1500`) is the next
check. If it reaches `CP_LOGO`, make the ordering the default for the boot
harness and update the 15-state table.
