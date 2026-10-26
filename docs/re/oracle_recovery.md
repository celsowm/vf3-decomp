# Oracle recovery — the instrumented emulator is back (2026-10-25)

The oracle (the instrumented Flycast build that records the guest's SH-4
execution) went missing with the `tools/emu` tree, and with it the way to give
the 208 ROM-derived gap bodies a real per-entry oracle replay.  This note
records what was found, how the recovery is reproduced, and what it is good for.

## The oracle was in the local evidence cache

`C:\Users\celso\AppData\Local\vf3-decomp\audio-evidence` still held the
observer binaries and their build directories:

| file | sha256 | what it is |
|---|---|---|
| `flycast_task_return_boundary_v1.exe` | `b8411977…` | the main oracle (pristine recorder) |
| `flycast_capsule_extended_v1.exe` | `f6fdc268…` | pristine + 500,000-instruction bound |
| `flycast_capsule_extended_v2.exe` | `d836abc4…` | + the `VF3CAP7` capsule tag |
| `flycast_capsule_extended_v3.exe` | `143bb860…` | + the drive-state record at the synthetic arm |
| `capsule_extended_observer_v3_build/vf3oracle.cpp` | `eec546e0…` | the exact source the v3 observer was built from |

`D:\vf3-captures\coverage_65_09970a_entry_probe_v2\observer_build_v1\` held a
second lineage (`flycast_nested_entry_fixture.exe`, the pristine recorder plus
the nested-entry-fixture fix) and the savestates.

The v3 observer is the one the re-capture campaigns want: the device-read
policy, the 1024-page RAM budget, the 500,000-instruction record bound and the
drive state at the synthetic arm (the GD-family corpora need that one).

## The recipe is in the repository

```
python tools/oracle/recover_oracle.py stage     # stage the observer + its data
python tools/oracle/recover_oracle.py seal      # seal it against the original controls
python tools/oracle/recover_oracle.py verify    # re-run the control windows
```

* `stage` copies the observer into `tools/emu/flycast-build/flycast_v3.exe` and
  its data directory beside it (`dc_boot.bin`, `dc_flash.bin`, `dc_nvmem.bin`,
  the VMU saves and the savestates `vf3_26/27/28/29/45/46.state`).  Every input
  is pinned by digest, so a stage either reproduces the recorded oracle exactly
  or refuses to run.
* `seal` compares the eight original control windows — captured by the
  *pristine* oracle before it was lost — with the same eight windows captured
  by the v3 observer, and writes
  `tools/oracle/extended_observer_controls_v3.json`.  That is the seal
  `tools/golden_batch.py` reads to authorise `--probe-ops 500000`.
* `verify` re-runs the windows with the staged observer and compares the fresh
  capsule and the 37.9 MB audio checkpoint with the recorded ones, byte for
  byte.

### The proof

```
vf3_28_replay_scene57_0_1: capsule=match audio=match original=equal rc=0
vf3_28_replay_scene57_32_1: capsule=match audio=match original=equal rc=0
```

The fresh capsule is `e2e86bc2feac390f4daa4b28931ee3208ad59aba0da1aa44b34b637af0ed0aef`
and the fresh audio checkpoint is `2fdd6468acffb37f2ff896b967540d50ff0b9fa7064b102f4caa18c6edff1c78`
— identical to the recorded control, and semantically equal to the pristine
original.

## The observer's source is in the repository too

`tools/oracle/vf3oracle.cpp` is the *pristine* oracle.  The live changes (the
device-read policy, the 1024-page budget, the drive-state record, the FPU flag
clear, the 500,000-instruction bound and the `VF3CAP7` tag) are 178 lines, and
they are now tracked:

* `tools/oracle/vf3oracle_v3.cpp` — the exact source of the v3 observer.
* `docs/re/patches/oracle_v3_from_pristine.patch` — its delta against the
  pristine source.

The two older patch files (`oracle_device_reads.patch`,
`oracle_drive_state.patch`) describe parts of the same change, but their base
was the *live* `core/vf3oracle.cpp` of the lost fork, so they cannot be applied
to the tracked pristine source.  The new patch is the complete, applicable
delta.

## The disc descriptor in the repository was wrong

`rom/vf3.gdi` (tracked) named three files that were never present:

```
1 0 4 2048 "Virtua Fighter 3tb (USA) (Track 1).bin" 0
2 4500 0 2352 "Virtua Fighter 3tb (USA) (Track 2).bin" 0
3 45000 4 2352 "Virtua Fighter 3tb (USA) (Track 3).bin" 0
```

The user's own dump carries a different descriptor (2352-byte sectors, track 2
at LBA 450) and the matching `track01.bin` / `track02.raw` / `track03.bin`.
That descriptor is the one that loads, and with it the control windows
reproduce byte for byte, so the tracked descriptor is replaced by it.

The disc itself is copyrighted game data and is **not** uploaded; its digests
are pinned in `tools/oracle/oracle_recovery_v1.json` so a re-dump can be
verified.  The same applies to the Dreamcast BIOS.

## The start-up RAM fixture cannot seed the low region

The low RAM region (0x0C010000-0x0C030000) holds the image's boot and BSS
code; the game erases it after it has used it, so every captured state has it
zeroed.  A probe aimed there runs zeros until the erased 0xffff padding raises
an illegal instruction (`flags=1`) — exactly what the first sweep showed.

`tools/oracle/ram_image_seed.py` writes the image's own bytes into that region
as a *start-up* fixture (`VF3_RAM_PATCH`).  That does not work any more, and
the reason is visible in the emulator log:

```
[vf3] loading state .../vf3_27.state ...
[vf3oracle] loaded 32768 RAM fixture words from .../ram_image_seed.txt
[vf3] state loaded
```

The observer reads the fixture while the savestate is still being loaded, and
the state then writes the region back to zero.  The fixture has to be applied
*when the probe is armed*, i.e. after the load.

The observer already supports that: the entry patch's `ram` lines belong to a
seed variant, and the seed is written back and invalidated cache line by cache
line before the guest sees it (`ocache.WriteBack(0x8C000000u+line,true,true)`),
so the guest really executes the seeded code.

`tools/oracle/isolated_probes.py --ram-image-seed` therefore puts the image's
words into every seed variant of the probe's entry patch instead of into the
start-up fixture.  With it, a low-region probe executes the image's own
instructions:

```
0c0103ba 4f22     mov.l r2,@(24,pc)
0c0103bc 2232     mov.l r3,@(32,r2)
0c0103be d32e     mov.l r14,@r15
...
```

(the specimen still ends `flags=1` here, because the arena-seeded registers
send the boot copy loop into the arena — the seed plan, not the seeding, is
what remains to be solved for that family.)

## What the recovery is worth

* the gap bodies can be given a real per-entry oracle replay, one campaign at
  a time, instead of resting on the ROM translation alone;
* of the 71 bindings whose corpus files were lost with the artefact bundle,
  7 are back (below).  The remaining 64 are *not* recoverable with what
  survives: 16 of them still have their watch file, but the campaigns that
  produced them resumed from `vf3_23.state` and the other early states, and
  those savestates are gone.  A boot run or one of the six surviving states
  does not reach their call sites, so the game never enters the entries;
* the GD-family corpora can carry the drive state at the entry of a redirected
  specimen, which is what `docs/re/reios_exec_server.md` asks for.

The evidence chain is unchanged: a body is credited by a ledger row, and a row
that claims an oracle replay names the cases that back it.

## The gate after the recovery

`tools/portcheck.py --jobs 4` still ends in `FAIL`, and every cause is the
artefact gap rather than a regression:

* the 64 bindings whose corpus file is gone (down from 71: the seven the
  restored observer re-captured now replay);
* 11 of the 39 gated replay tests, each because the file it reads is gone -
  five FPU boundary corpora without their RAM shadows, five corpus files, and
  the `fsca_modes.bin` fixture.

Coverage itself did not move: `tools/final_status.py` still prints
`Pure C union: 436928 bytes (100.5227%)`, and `tools/gap_fidelity.py` still
reports 0 blocks whose opcode does not match the image.


## What was re-captured with it

The eight `u98` corpora - the ones the corpus-less pool sweep produced before
the oracle went missing - were re-captured with the restored observer, over
six savestates (`vf3_{26,27,28,29,45,46}.state`) instead of the two the old
campaign used:

| entry | old corpus | re-captured | verdict |
|---|---|---|---|
| 0x8c0371c2 | 4 cases | 10 cases | `10/10 cases match (0 skipped) - PASS` |
| 0x8c037248 | 2 cases | 4 cases | `4/4 cases match (0 skipped) - PASS` |
| 0x8c046320 | 4 cases | 10 cases | `10/10 cases match (0 skipped) - PASS` |
| 0x8c04ba30 | 4 cases | 14 cases | `14/14 cases match (0 skipped) - PASS` |
| 0x8c053dda | 5 cases | 11 cases | `11/11 cases match (0 skipped) - PASS` |
| 0x8c08a942 | 4 cases | 8 cases | `8/8 cases match (0 skipped) - PASS` |
| 0x8c0c2706 | 5 cases | 12 cases | `12/12 cases match (0 skipped) - PASS` |
| 0x8c07caa8 | 2 cases | *none* | every specimen ends `flags=4` |

69 cases in all, and every one of them replays clean against the port.  The
seventh row of the table is the exception: `0x8c07caa8` does not re-capture at
all, because every specimen spins in the REIOS BIOS polling a device register
until the 500,000-instruction budget runs out - the wall
`docs/re/coverage_93_c97_batch.md` describes.  Its ledger row now says so
instead of citing a corpus that is gone.

## What the campaign over the gap bodies measured

The 151 gap entries in the high region were swept with the restored observer
(six savestates, the arena and pointer seed plans, 500,000 instructions per
specimen).  **None of them yields a usable case.**  The failure modes are the
documented ones:

| flags | count | meaning |
|---|---|---|
| 1 | 342 | illegal instruction: the arena-seeded registers send the target into empty memory |
| 4 | 229 | the record budget ran out: the probe spins in the REIOS BIOS |
| 6 | 23 | budget *and* a device access |

So the oracle was never the binding constraint on that family.  The seed plan
is: a probe whose registers point at the arena reaches code that never
dereferences them, and a probe that does reach the device service spins in the
BIOS waiting for the drive.  Making those bodies replayable needs a per-entry
seed plan (the `tools/oracle/seed_plan.py` approach), not a working emulator.

The 58 gap entries in the low region (the image's boot and BSS code, which the
game erases after it has used it) are a separate problem: the image's own
bytes have to be seeded into RAM when the probe is armed, which is what
`--ram-image-seed` now does.  With it the probe executes the image's real
instructions, but the boot copy loop then branches through an arena-seeded
register into the arena, so the seed plan is still the open half.

## What the fresh capture says about the readable FPU ports

The six readable FPU ports whose boundary corpora lost their RAM shadows
(`0x8c070120`, `0x8c07030c`, `0x8c0706c4`, `0x8c0708b0`, `0x8c070a84`,
`0x8c070cf0`) were re-captured with the restored observer and replayed with
the matrix harness (the dedicated `fvecnorm*_boundary_replay` tests expect a
boundary corpus and are the wrong tool here).  Three replay clean; three
diverge on one case each:

```
0x8c070120: 2/2 cases match - PASS
0x8c07030c: 2/2 cases match - PASS
0x8c0706c4: 2/2 cases match - PASS
0x8c0708b0: 3/4 cases match - FAIL   case 1: mem win3 @+0x8243: got ff want 7f
0x8c070a84: 2/3 cases match - FAIL   case 1: mem win3 @+0x8243: got ff want 7f
0x8c070cf0: 1/2 cases match - FAIL   case 1: mem win4 @+0x5243: got ff want 7f
```

The divergence is a *path*, not the arithmetic.  The guest body at
`0x8C0708B0` sets `r0` with `mov #24,r0` (`0xE018`) and then branches on the
FPU comparison (`fcmp/gt fr3,fr0` at `0x8C0708CA`) to the continuation at
`0x8C0708D8`.  The readable ports implement the branch they were written for
and end with `r0 = 0x18`; on the path the fresh capture reaches, the reference
ends with `r0 = 0x20` or `0x24` - the continuation ran and changed `r0` - and
one RAM byte differs (the reference wrote `0x7f`, the port `0xff`).

So the readable FPU ports are **partial**: they cover the paths their corpus
exercised, and the boundary corpus - whose RAM shadows are gone, so it can no
longer be re-verified - did not cover the tail-transfer path.  The bindings
still point at the boundary corpora: swapping in the fresh corpus would turn
"no RAM cases" into a different failure without fixing the port.  The fresh
corpora are at `extract/analysis/fpu070_v1/` and are the reproduction recipe
for the finding.


