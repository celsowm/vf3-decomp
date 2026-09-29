# SDK 8 Europe corpus sweep

## Source and extraction

The local SDK 8 Europe image is a raw 2352-byte Mode-1 CD image. The
repository's `tools/rawcd_extract.py` reads ISO-9660 sectors directly and
extracts files without modifying the image. For this sweep, the extractor
selected `.LIB` and `.OBJ` files into the ignored `tools/katana_raw/` tree.

The official SHINOBI core library directory contains 15 libraries. `lbr.exe`
extracted 2,005 SYSROF objects from those libraries into ignored
`extract/analysis/sysrof/sdk8_eu/SHINOBI/`.

## Match results

- `libmask_match.py`: 659 candidate module windows, 24,146 matched bytes,
  across 13 libraries.
- `sdk_sweep.py` with `--min-words 2`: 64 matches, 30 full-body matches.
- All complete function bodies were already attributed by stronger SDK
  evidence. The only additional exact-byte interval found by direct comparison
  was `0x8C04C5A0`, a four-byte inventory fragment ending before the next
  function's entry at `0x8C04C5A4`; it has no return instruction and is not a
  complete function, so it is excluded from coverage.
- The sweep therefore adds **zero** rigorous functions. The verified total
  remains **293/2398 (12.2%)**.

Generated match tables and extracted objects stay under ignored analysis and
SDK directories; the raw image is unchanged.
