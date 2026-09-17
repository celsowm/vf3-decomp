# VF3tb architecture state (M3 synthesis)

## Execution & dispatch model (high confidence)
- SHC-compiled C, struct-centric: calls cross modules via `mov.l @(disp,rN),rM; jsr @rM` (rN = object/table pointer).
  Static jsr resolution ceiling ≈ 3% is the fingerprint of this model, uniform across the image.
- ~80 "runner" functions each hosting ≥5 struct-dispatched jsr sites (see `disasm_*.dispatch.csv`).
  These iterate task/object tables and call per-tick handlers.
- Mode/state switches are C `switch`es: 146 jump tables found; hosts are dispatcher functions
  (see `fntables_1ST_READ.md`): biggest dispatchers f_8c07d368, f_8c063f58, f_8c0516a8,
  f_8c02d0a0(184B), f_8c071428, f_8c063f58(222B) etc.

## Boot region (0x8C010000-0x8C014000)
- DSGLH-style header: code interleaved with pointer blobs; Ghidra function
  modelling breaks here (baddata regions are data islands, not corrupt code).
- `_start` (0x8C010000) → tail-calls f_8c01064c-equivalent init path.
- 0x8C011E02: SYS_MISC vector trampoline (`mov.l @r0,r0; jmp @r0` → 0x8C0000BC slot).
- Manual boundary-by-boundary walk deferred: needs CFG-aware splitter
  (decompiler warnings sequence in boot_region_decomp.txt is the map of the damage).

## Loader chain (GDFS)
- GDROM access via GDFS (`_gdFsDaPlaySct` verified @ 0x8C0360C8).
- Per-asset loader functions reference file-name strings directly:
  load_mt_to_u_pai 0x8C04BDA2 (MTTOUPAI.BIN), load_mt_aki_jef 0x8C08232E,
  load_fx_akfx 0x8C05C0FA, load_cp_st0f 0x8C059E60, plus ~370 name-strings identified.
- Loader is positional (no direct pointers to the name-table) — file table resolved by index.
- String→function read map: extract/analysis/string_readers_1ST_READ.csv.

## Library bill-of-materials (static, banner-verified)
syInit/syCbl/syCache, pd 1.07, bu 1.03, kd 1.20, GDFS 0.53 (1998/08/28),
"NAOMI LIBRARY Ver 0.8 AM R&D" (AM2's NAOMI-derived PVR layer), NEC Kamui driver
parts (kmSet*Callback setter family, kmiWriteRegisters...) — no Kamui2 API.

## Open questions (next milestone inputs)
1. GBR-based model data pointer (ldc r3,GBR @ 0x8C013446) — pool resolve needs
   the real literal value; candidate: module globals base.
2. Main loop body: not yet positively located; expected near PVR flip + vblank
   wait + runner dispatch chain — hunt via `kdWait`-family syscalls in Phase C2.
3. DTPK sub-entry pointing table (see Phase D deliverable).
