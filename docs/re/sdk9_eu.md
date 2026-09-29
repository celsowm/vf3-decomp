# SDK 9 Europe corpus sweep

## Recovery and extraction

The Internet Archive SDK9 Europe item contains two ISO images. The local
ignored copies were extracted with `tools/rawcd_extract.py`; Disc1 is a cooked
2048-byte ISO and Disc2 is also readable by the same sector reader.
Disc1 exposed SHINOBI ROFF libraries, SHC libraries, and packaged ELF library
archives. The `lbr.exe` extraction pass covered 27 release-format libraries
and produced 4,020 SYSROF module objects. Disc2 exposed a small DreamOn SDK
sample set; its Ginsu library yielded three SYSROF modules.

## Match results

- Sweeping the extracted Disc1 modules found 95 baseline function matches,
  including 35 complete bodies.
- Sweeping the full Disc1 file tree (including the ROFF and ELF archives)
  found 131 matches, including 48 complete bodies.
- All complete bodies were already attributed by stronger evidence. This
  archive adds **zero** rigorous functions.
- Disc2 and its extracted Ginsu modules produced six partial matches and no
  complete baseline bodies.

The ISO images, extracted files, and match tables remain in ignored SDK and
analysis directories. The current rigorous coverage remains 293/2398
functions; see `docs/coverage.md` for the generated ledger.
