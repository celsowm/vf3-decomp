# Boot GD request ladder (2026-10-19)

The savestates 21-29 are successive points of the same deterministic boot
sequence. Each was captured with one GD read in flight, so its `gdstate` file
names the read the sequence had reached. This is a stronger check than "the
run reaches the frame loop": it asks whether the native run issues the same
reads, in the same order, with the same FADs, counts and destinations.

## Method

`VF3_GDTRACE=1` prints every served BIOS GD call and the four REQ_CMD params
(`src/fight/native_tick.c`). `tools/boot_req_ladder.py` matches the
(FAD, sector count, destination) triple against states 21-29 and resolves the
FAD to a file name through `docs/files.md` (GD LBA = FAD - 150).

```sh
VF3_GDTRACE=1 build/vf3boot.exe golden_bootV_vf3_21.bin ... 2> native.log
python tools/boot_req_ladder.py native.log
```

## Result: state 21 matches through state 22

The state-21 run (300 vblanks, after the GD FAD and AICA fixes) issues:

| # | file | FAD | sectors | destination |
|---|---|---|---|---|
| 0 | PLAYER.BIN | `000852a0` | `0084` | `0caae800` |
| 1 | CP_ASC.BIN | `00068999` | `0130` | `0c828800` |
| 2 | CP_GM_J.BIN | `00068bc9` | `0100` | `0c828800` |
| 3 | ROB_BALL.POL | `0006c189` | `0010` | `0c320000` |
| 4 | ROB_BALL.TEX | `0006c199` | `000d` | `0cbc7000` |
| 5 | ROB_ALP.POL | `0006c1a6` | `002d` | `0c328000` |
| 6 | ROB_ALP.TEX | `0006c1d3` | `0001` | `0cbcd000` |

Read #1 is exactly the request state 22 was captured in flight
(`CP_ASC.BIN`, `0x130` sectors, `0x0C828800`). Reads #2-#6 are the five
requests the emulator itself issues in the first 900 frames from state 22
(`tools/entry_order.py 22 0x8C0357BC`): the same lengths `0x100, 0x10, 0xd,
0x2d, 1`, from the same request function and caller. So native takes the same
path, not just a plausible one.

Reads #0-#6 also match the request ids: starting from `next_request_id =
0x12` in the state-21 gdstate, they become `0x12`..`0x18`.

## Disc data check

State 22 was captured with `CP_ASC.BIN` partly transferred (`0xB9` sectors
done). The captured RAM at `0x0C828800` equals the track-3 sectors at FAD
`0x68999` for **209 of 304** sectors (it had progressed a little further
before the snapshot), and not the sectors 150 later. That confirms both the
drive's FAD addressing (LBA = FAD - 150) and the disc data itself.
`tools/gd_verify_state.py` now applies the same -150 conversion.

## Where the run stops

State 23 was captured in flight on `CP_LOGO.BIN` (`FAD 0x68ec9`, `0x100`
sectors, same destination), request id `0x19`. The native state-21 run at
300 vblanks has not issued it yet. This is not a divergence: the emulator
from state 22 does not issue it in 600 or 900 frames either. A 1500-frame
emulator run issues it as its sixth request (`0x100`), followed by `0x81`
and more, so the gap is a game-side wait after the ROB assets, not a missing
read. The wait is the frame clock (see `boot_frame_clock.md`).

## Where the file names and indices come from (2026-10-19)

The boot file list is the pointer table at `0x0C1068AC` (1ST_READ image).
Its entries are `char *` names; the indices the loader uses are:

| index | file |
|---|---|
| 0 | 1ST_READ.BIN |
| 1 | CP_ASC.BIN |
| 3 | CP_GM_J.BIN |
| 5 | CP_LOGO.BIN |
| 0x40-0x43 | ROB_BALL.POL, ROB_BALL.TEX, ROB_ALP.POL, ROB_ALP.TEX |

The emulator opens them in the order 3, 0x40, 0x41, 0x42, 0x43, 5. The
first and last (CP_GM_J, CP_LOGO) come through `0x8C0A7F5A` from the
resource loader at `0x8C07AAAC` (return address `0x0C07AADE`); the four ROB
files come through the pair loader at `0x0C0A28D4` (returns `0x0C0A294C` /
`0x0C0A2916`). The resource loader itself is entered from the task/scheduler
region (`pr 0x0C095B26` for resource 9 = CP_GM_J, and `pr 0x0C096F28` for a
second request).

The GDFS directory entry is 44 bytes: `+0` LBA, `+4` size in bytes, `+8`
flags, `+10` name. The drive request is `LBA + 0x96` (150), e.g. CP_GM_J LBA
`0x68b33` becomes FAD `0x68bc9`; the native GD model subtracts the same 150
before indexing track 3. This is the same pregap the FAD fix uses, seen from
inside the SDK.

Native issues indices 3 and 0x40-0x43 and then stops. Index 5 (CP_LOGO) is
the resource request the title code has not made yet; the GD layer itself is
not the blocker.
