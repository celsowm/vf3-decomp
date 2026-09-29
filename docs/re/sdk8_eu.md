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

## Japanese SDK 1.0 follow-up

The local `DCSDK_100J.iso` image uses raw Mode-2 Form-1 sectors and a Joliet
supplementary volume descriptor. `rawcd_extract.py` now reads both sector
layouts and prefers the Joliet tree when present. The primary ISO tree only
contains a README; Joliet exposes the SDK libraries.

Selected 19 `.LIB`/`.OBJ` files from the SHINOBI and SHC library directories
yielded 3,608 extracted SYSROF objects. A recursive `sdk_sweep.py` pass found
193 baseline function matches, including 87 full-body matches (5,108 B).
Every full-body match was already credited in the SDK union ledger; this
revision adds **zero** rigorous functions. The raw image and extracted corpus
remain unchanged/ignored, respectively.
