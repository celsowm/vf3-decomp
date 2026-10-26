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
* the 71 bindings whose corpus files were lost with the artefact bundle can be
  re-captured;
* the GD-family corpora can carry the drive state at the entry of a redirected
  specimen, which is what `docs/re/reios_exec_server.md` asks for.

The evidence chain is unchanged: a body is credited by a ledger row, and a row
that claims an oracle replay names the cases that back it.
