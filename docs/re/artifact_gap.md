# The artifact gap: what is still missing from this checkout

Everything the capture pipeline produced lives under `extract/`.  That tree is
in `.gitignore` (it holds copyrighted game data and the extracted analysis),
so a fresh clone has never had it, and a checkout that lost it cannot rebuild
it from the repository alone.

**Update (2026-10-24): the bundle came back.**  `extract/vf3tb-evidencias.7z`
(393 MiB, unpacked 31 GB / 1,008,409 files) carries the whole
`extract/analysis` tree: 984,385 files, 2,219 `.cases` corpora, 1,885 RAM
blobs, the baseline inventory, the census and the coverage snapshots.  Unpacked
with 7-Zip into `extract/`, the offline suite goes from **37 pass / 62 fail**
to **74 pass / 26 fail**, and the coverage tools run again.

What follows is what the bundle does **not** carry.

## What is still missing

| path | what it held | what it blocks |
|---|---|---|
| `extract/exe/*.unsc.bin` | the descrambled ROM images (1ST_READ, VF3TBE3, RELOAD) | every disassembly, the Ghidra baseline, `tools/sh4dump.py` |
| `extract/gamedata/*.BIN` | the 412 ISO files as shipped | the DTPK/TEX/MT/POL formats, the audio corpora, and the image fallback `vf3_matrix_read` serves truncated pool pages from |
| `extract/ghidra_proj/VF3` | the Ghidra project | the function inventory (`funcs_1ST_READ.unsc.bin.csv` is in the bundle, the project is not) |
| `tools/emu/` | the patched oracle (flycast fork) | every new capture, and `extract/analysis/fsca_modes.bin` (the FPU oracle table) |
| `refs/dream-recomp` | the static recompiler used as a second oracle | the native tick's whole-image coverage |
| `rom/*.bin` | the disc tracks | carving the ISO again |
| `tools/ghidra_12.1.3_PUBLIC/` | Ghidra itself | re-analysing the image |
| `tools/katana_raw/`, `tools/katana/`, `tools/kamui/` | the SDK corpora | the SDK attribution buckets (the two SDK zips are in the bundle) |
| the RAM blobs of the older `goldens_*` corpora | the `.cases` and `ram*.bin` files | the oracle replays that name them - the metadata (`*.json`, `*.txt`) is in the bundle, the blobs are not |

`rom/vf3.gdi` survives, but it is the 175-byte GDI descriptor; the three
`.bin` tracks it names are gone.

## What works now

The tracked tree is complete and builds (cmake + ninja, gcc):

```
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
ninja -C build
```

The self-contained test suites run and pass, and with the bundle unpacked the
corpus-backed ones do too:

```
build/vf3frame      frame_replay: PASS
build/vf3vm         (motion VM interpreter) PASS
build/vf3loop       mainloop_replay: PASS
build/vf3libutil    libutil_replay: PASS
build/vf3taskvm     taskvm_replay: PASS
build/vf3mtmount    mtmount_replay: PASS
build/vf3walker     walker_replay: PASS
build/vf3statehelpers  state_helpers: 8836 differential cases - PASS
build/vf3recordwalk    record_state_walk: 16 differential cases - PASS
build/vf3recordkind    record_kind: 30 differential cases - PASS
build/vf3recordkindoracle  record_kind_oracle: 8/8 cases match - PASS
build/vf3stateladder   state_ladder: 34 differential cases - PASS
build/vf3stateresolve  state_resolve: 20 differential cases - PASS
build/vf3stateresolveoracle  state_resolve_oracle: 192/192 cases match - PASS (and 256/256 on the fight_release_cases corpus)
```

Run the suite from the **repository root**: the harness resolves
`extract/analysis/...` relative to the working directory.  (Running it from
`build/` is what let the disc test skip, `rom/vf3.gdi` not being there - the
corpus tests need the root.)

The 26 remaining failures are: seven tests that want command-line arguments
(`vf3`, `vf3boot`, `vf3driverqueue`, `vf3matrixfamily`, `vf3tick`,
`vf3tickmix`, `vf3tool`), the disc test (the tracks are gone), the FPU replay
(it wants `extract/analysis/fsca_modes.bin`, which only the oracle writes), the
XF sidecars, one `shots/` dump, and the nine `goldens_*` corpora whose RAM
blobs the bundle does not carry.

The coverage tools run:

```
python tools/decomp_stats.py    # rigorous 410328/434656 bytes (94.4%)
python tools/final_status.py    # Pure C union: 406446 bytes (93.5098%)
```

The **verified C address union** is 406,446 B (93.51%), so the 94% bar
(408,576 B) is still 2,130 B away; `decomp_stats.py`'s "rigorous" figure of
410,328 B adds the SDK-attributed regions, which are not ports, and it sums the
ledger's sizes where the union merges the overlapping body ranges.

## What is possible without the artifacts

The generated adapters under `src/fight/*adapter*.c` are the machine
translation of the ROM and stay in the tree. They are a faithful
disassembly (one label per guest PC, one C statement per executed opcode,
the original opcode word in the comment), so:

* a readable port can be written against them (`tools/adapter_dump.py`,
  `tools/adapter_body.py`);
* it can be proved offline by differential execution against the
  translation it replaces, the pattern `tests/state_helpers_replay.c`
  established and `tests/record_state_walk_replay.c` follows;
* and where the bundle carries the corpus, it can be proved against the
  **oracle** as well - `tests/record_kind_oracle.c` replays the captured
  fight states of `0x8C078044` and matches the oracle's whole register file
  and every exit byte.

The coverage bar (94% = 408,576 B) is now measurable again (the baseline
inventory and the ledger are both here) and it is **2,832 B short**; closing
it needs more ports, not more artifacts.

## How to restore it

0. **The bundle.** `extract/vf3tb-evidencias.7z` unpacks into the tree:

   ```
   7z x extract/vf3tb-evidencias.7z -o<scratch> -y
   Move-Item <scratch>\vf3tb-evidencias\extract\analysis extract\analysis
   ```

   It carries `extract/analysis` in full; the repository snapshot inside it
   (`src/`, `tests/`, `tools/`, `docs/`) has nothing the tracked tree lacks,
   except two SDK zips and four oracle patches under `tools/`.

1. **The disc.** Put the three track files back into `rom/` (the names are
   in `rom/vf3.gdi`) and run `tools/iso_carve.py` / `tools/extract_iso.py`
   to rebuild `extract/gamedata/`. `tools/dc_scramble.py` is *not* to be
   run: the retail image is unscrambled (docs/re/image_identity.md).
2. **The images.** Carve `1ST_READ.unsc.bin`, `VF3TBE3.unsc.bin` and
   `RELOAD.unsc.bin` into `extract/exe/`.
3. **Ghidra.** Reinstall Ghidra 12.1.3 at `tools/ghidra_12.1.3_PUBLIC`
   (Java 21 is present) and re-run `tools/ghidra_run.py` with the
   baseline script to rebuild `extract/ghidra_proj/VF3` and
   `extract/analysis/funcs_1ST_READ.unsc.bin.csv`.
4. **The oracle.** Re-create the patched flycast fork at `tools/emu/` and
   apply `docs/re/patches/oracle_device_reads.patch`; the patch is kept in
   the repository because the oracle itself is not.
5. **The corpora.** Re-run the capture campaigns (`tools/oracle/`), or
   restore them from a backup of `extract/analysis/`.

Steps 3 and 5 are the expensive ones: the Ghidra project takes an
auto-analysis pass, and the corpora are the product of the capture
campaigns recorded in `docs/re/`.
