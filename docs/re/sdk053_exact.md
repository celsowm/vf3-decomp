# Exact-version SDK: GDFS 0.53 sample ELFs (2026-09-25)

## Discovery
The **Dreamcast SDK for Sega Library Ver.1.00J** ISO
(`tools/katana_raw/DCSDK_100J.iso`, from sega-dreamcast-info.com) is a
Mode2/Form1 (2352/24) GD image whose SAMPLES directory ships 14 SH-4 **ELF
executables statically linked with the exact game libraries**:

- `GDFS Version 0.53  1998/08/28`
- `gdFs Ver 0.53 Build:Sep 07 1998 13:48:56`
- the game's own config strings nearby (`EnableTexture16MB`, `VSYNCCount`,
  `VertexTimeOut`, `BufferBase`, ...)

Unlike the Katana 0.40/1.0B2 drops (GDFS 0.46/0.49/1.00), this is the exact
version the game links.

## Method
- Parsed the GD image (Mode2/Form1, DATA_OFF=24) via `tools/iso_list.py`.
- Carved the ELF span `0x195d3ae8..0x1a000000` (14 ELFs) to
  `extract/analysis/sdk053_samples.bin` (gitignored).
- New `tools/sdk053_match.py`: for each baseline fn, build a mask + literal-pool
  -wildcard token stream (fidhash.mask_word + `mov.l/w @(disp,PC)` pool targets
  wildcarded), seed-6 and bidirectionally extend inside the carved blob.

## Result
- **142 full-body matches** (entire fn token stream found), **0 concrete-token
  mismatches**; +66 fns not already credited.
- Verified independently: `0x8C064DA0` (700 B VDP/vertex setup) is
  instruction-for-instruction identical to blob `0xe5208` (loads at
  `0x8C0F5208`) — `sts.l pr,@-r15; add #-16,r15; mov.l @r4,r3; ...`.
- Match regions: pages 0x05 (113) / 0x06 (69) = ninja/PVR rendering, plus a
  few in 0x03/0x04/0x07/0x0a/0x0c.

## Coverage impact (decomp_stats, new transparent bucket)
`SDK-attributed (GDFS 0.53 sample-ELF, exact version)` = **66 fns / 8210 B**.

| metric | before | after |
|---|---|---|
| rigorous fns | 143 (6.0%) | **209 (8.7%)** |
| rigorous bytes | 28,976 (6.7%) | **37,186 (8.6%)** |
| incl-trace fns | 301 (12.6%) | **367 (15.3%)** |
| incl-trace bytes | 92,048 (21.2%) | **100,258 (23.1%)** |

## Notes / next
- GDFS (page 0x03) matched only partially (6-word spans): the game's GDFS 0.53
  is register-allocated slightly differently from the sample build, so
  mask_word (which keeps register fields) diverges. High-coverage partials
  (cov>=0.9, 3 fns) are available but not credited to stay conservative.
- The 14 samples likely contain more libraries (sound/pd/kd/sy) further into
  each ELF; a per-ELF load-address-aware sweep could extend this.
- Artifacts: `extract/analysis/sdk053_matches.csv`, `sdk053_samples.bin`
  (both gitignored).