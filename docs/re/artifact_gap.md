# The artifact gap: extract/ is gone from this checkout

Everything the capture pipeline produced lives under `extract/`, and that
tree is **not** in this checkout. `extract/` is in `.gitignore` (it holds
copyrighted game data and the extracted analysis), so a fresh clone has
never had it, and a checkout that lost it cannot rebuild it from the
repository alone.

## What is missing

| path | what it held | what it blocks |
|---|---|---|
| `extract/exe/*.unsc.bin` | the descrambled ROM images (1ST_READ, VF3TBE3, RELOAD) | every disassembly, the Ghidra baseline, `tools/sh4dump.py` |
| `extract/gamedata/*.BIN` | the 412 ISO files as shipped | the DTPK/TEX/MT/POL formats, the audio corpora |
| `extract/ghidra_proj/VF3` | the Ghidra project | the function inventory (`funcs_1ST_READ.unsc.bin.csv`) |
| `extract/analysis/` | the capture directories, the corpora, the CSVs | the replay gate, the coverage audit, the census |
| `tools/emu/` | the patched oracle (flycast fork) | every new capture |
| `refs/dream-recomp` | the static recompiler used as a second oracle | the native tick's whole-image coverage |
| `rom/*.bin` | the disc tracks | carving the ISO again |
| `tools/ghidra_12.1.3_PUBLIC/` | Ghidra itself | re-analysing the image |
| `tools/katana_raw/`, `tools/katana/`, `tools/kamui/` | the SDK corpora | the SDK attribution buckets |

`rom/vf3.gdi` survives, but it is the 175-byte GDI descriptor; the three
`.bin` tracks it names are gone.

## What still works

The tracked tree is complete and builds (cmake + ninja, gcc):

```
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
ninja -C build
```

The self-contained test suites run and pass:

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
```

The rest of the replay suites print `cannot open extract/analysis/...` and
exit: they need the corpora, not a fix.

## What is possible without the artifacts

The generated adapters under `src/fight/*adapter*.c` are the machine
translation of the ROM and stay in the tree. They are a faithful
disassembly (one label per guest PC, one C statement per executed opcode,
the original opcode word in the comment), so:

* a readable port can be written against them (`tools/adapter_dump.py`,
  `tools/adapter_body.py`);
* it can be proved offline by differential execution against the
  translation it replaces, the pattern `tests/state_helpers_replay.c`
  established and `tests/record_state_walk_replay.c` follows.

That is the only decomp work the missing tree does not block. The coverage
bar (94% = 408,576 B) needs the baseline function inventory, the corpora
and the oracle, so it waits.

## How to restore it

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
