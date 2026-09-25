# Katana SDK 0.40 sweep — version-adjacent SDK attribution (2026-09-25)

Goal: close the rigorous SDK gap toward 10% by acquiring an SDK whose component
versions bracket the game's build.

## Acquisition
Downloaded from sega-dreamcast-info.com (staged in gitignored
`tools/katana_raw/`):
- **Katana 0.40 Pre.2 (SET 4)** — 25 MB, 831 entries
- **Katana 0.40 Release.4 (SET 4)** — 137 MB, 1745 entries

## Version anchoring (the key finding)
The catalogued SDKs contain the game's own libraries INSIDE `shinobi.lib`:

| SDK | GDFS | Shinobi | other modules |
|---|---|---|---|
| 0.40 Pre.2 | **0.46 (1998-04-21)** | SET4 v0.41 | kdapi_, mpapi_, mpasm_, mpcach_, mpdrv_, mpgbl_, mpsmp_, pdmain_, gdfs*, syMalloc_, syhw_ |
| 0.40 Release.4 | **0.49 (1998-05-26)** | SET4 v0.42A | + syCache_, syChain_, syIntCtrl_, syIntIsr_, syMmu_, sySq_, sh4tmr_, g2read/write, gdctl_, njpad_ |
| Katana 1.0B2 (local) | 1.00 (1998-09-28) | SET5 | (prior corpus) |
| **VF3tb game** | **0.53 (1998-08-28)** | — | NAOMI 0.8, pd 1.07, bu 1.03, kd 1.20, syCache/syCbl 1.0, libsnd 0.82 |

So the game's build sits between Release.4 (0.49) and 1.0B2 (1.00). `shinobi.lib`
is the carrier of GDFS + the sound (`mpdrv_`/`mpapi_`/`mpsmp_`) + platform
(`pdmain_`/`kdapi_`/`syCache_`/`syMmu_`) modules.

## Sweep
- `sysrof.py extract` shinobi/ninja/nindows from both 0.40 drops
  (28+25 shinobi, 298+250 ninja, 19+19 nindows modules).
- `sysrof.py match` (exact) + `libmask_match.py` (masked) on the true image.

Exact matches (18 modules), highest coverage:
`kdapi_` 90%, `mpgbl_` 96%, `mpdrv_` 86–89%, `mpapi_` 86%,
`gdfshn_`/`gdfsdir_`/`pdmain_`/`gdfs_` 13–44%.

Masked matches: shinobi 48 windows / 2000 B, ninja 268 windows / 10058 B.

**Verification:** 7 sampled regions re-checked masked-word-exact → 0 mismatches
(kdapi_ 0x8c04416a/0x8c043f4a/0x8c043ec4, gdfsif_ 0x8c035b3e, gdfshn_
0x8c035912, mpapi_ 0x8c03665a).

## Coverage impact (decomp_stats)
New transparent bucket `SDK-attributed (Katana 0.40 adjacent)`:
**+19 fns / 1520 B** (after de-dup against masked/reloc/ported).

| metric | before | after |
|---|---|---|
| rigorous fns | 124 (5.2%) | **143 (6.0%)** |
| rigorous bytes | 27,456 (6.3%) | **28,976 (6.7%)** |
| incl-trace fns | 283 (11.8%) | **301 (12.6%)** |
| incl-trace bytes | 90,544 (20.8%) | **92,048 (21.2%)** |

## Naming artifact
`extract/analysis/v040_sdk_names.csv` — 60 game fns mapped to their v0.40 SDK
module (fballoc_ 16, kdapi_ 9, njModelS_ 7, kmtex_ 6, kmglobal_ 4, mpapi_ 2,
njLtSrcs2_/interupt_/njTexBmp_ 2, gdfshn_/gdfsif_/njGetMatrix_/njMotLinkF_/
njMotLinkS_/nwScrollBar_/njDrawLine3D_/njScroll_/kmutil_ 1). Useful to name
GDFS/platform/sound functions in Ghidra.

## Next
The exact 0.53 build is not public in this set; full GDFS/syCache attribution
needs either a 0.5x drop or structural transliteration using the 0.4x module
as reference. Remaining gap to 10% rigorous SDK (~240 fns) still requires more
version-adjacent libraries (SDK release 8/9, Sega Library 1.00J) or the
re-segmentation route.