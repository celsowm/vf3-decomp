# SDK inventory / acquisition status

## Kamui — EXTRACTED (tools/kamui/, git-ignored)
NEC Kamui2 (1997-1999): full C sources, headers, docs, sample .map files
(used for the fingerprint corpus in `tools/kamui_fingerprint.py`),
160 sample ELFs. Note: VF3tb does **not** link kamui2.lib (fingerprint
scan: ~0 matches); the game uses Sega's NAOMI/AM2 stack instead.

## Katana SDK 1.0B2 — EXTRACTED (tools/katana/, git-ignored)
Solution for the locked InstallShield 3 package (16-bit `setup.exe`,
unreadable `data.z`): extracted with **idecomp** (GPLv3,
github.com/lephilousophe/idecomp) which reads IS3 `.Z` (PKWARE DCL) —
checked out in `extract/cache/idecomp` (git-ignored), ran against
`tools/_katana_pkg/KATANA_1.0B2/data.z` → 2,173 files (~220 MB).

Key content:
| path | contents |
|---|---|
| `katana/shc/bin/shc.exe` | SH C Compiler **Ver 5.0 (Release 28)** (runs on 64-bit Windows; complains "Illegal environment variable" but executes) |
| `katana/shc/bin/lnk.exe` | Hitachi linkage editor (produced the H'8C map format we parse) |
| `katana/shinobi/` | **Shinobi system library**: `lib/shinobi.lib` (gd/bu/pd/sy…—symbols embedded: ~1,671 names visible), `ninja.lib`, `sh4nlfzz.lib`, bootstrap objects `strt1/2.obj`, `systemid.obj`, `toc.obj`, `sg_sec.obj`, `sg_are*.obj`, `aip.obj`, `zero.obj`; include headers under `shinobi/include` |
| `katana/doc/` | Katana/shinobi/segalib documentation (PDF/docs) |
| `katana/bootrom/` | boot-ROM diagnostics kit |

Version match note: SDK 1.0B2 is mid/late-1998; VF3tb retail is 1999-08-20.
Banners in the game (`GDFS Version 0.53 1998/08/28`, `pd Ver 1.07`,
`bu Ver 1.03`, `syCbl 1.10 Build Jan 26 1999`) will tell us per-library
whether the SDK binaries match the game's linked versions — the lib-level
`.map` fingerprints will confirm/refute during Phase 4 naming runs.

## Local reverse-engineering tools (installed)
- Ghidra 12.1.3 → `tools/ghidra_12.1.3_PUBLIC/` (JDK 21 present)
- otvdm 0.9.0 (scoop) — win16 runner, kept for any future 16-bit tooling
- UniExtract2 RC3 (scoop) — general extractor
