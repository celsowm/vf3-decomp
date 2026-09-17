# DTPK container (M3-D, solved)

Dreamcast-era AM2 "Data TransPacK" used for all 69 BGM/VO/ST/PLAYER/LEVEL/
COIN/ANAUNCE packages in VF3tb.

## Container layout
```
0x00 'DTPK'
0x04 u32  package serial id (load-list ordinal 0..82 across the set)
0x08 u32  total file size
0x0C u32  0
0x10 u32  group tag (e.g. 0x02xxFF09/0A; low byte = package class:
          0x03 COIN, 0x09 VO/ST, 0x0A BGM/ANAUNCE/LEVEL, 0x00 PLAYER)
0x14 u32  ~0x00014D11 (format version constant)
0x18 u32  0x00200000 (bus/DMA size constant)
0x1C u32  0
0x20..    16 x u32 section-offset directory; slots sorted; unused = 0;
          first used slot always equals 0x60 (end of the directory)
```
Sections run from each directory offset to the next offset; the final
section runs to EOF.

## Section roles (deduced, consistent across the set)
| index | size | role |
|---|---|---|
| 0 | 312-368 | bank header (voice counts/params; starts 01 00 08 0x00 |
| 1 | 144-7152 | sequence/event table (BGM: big; voices: small) |
| 2 | 132 | constant amplitude/log ramp table (00 07 0e 15 1c 24 ...) |
| 3 | 40-22556 | per-voice pointer/param table (u32 strides visible) |
| 4 | 3112 | constant block **only in ST/VO/PLAYER/LEVEL/COIN/ANAUNCE packs** |
| 5..last | big | **AICA ADPCM payload** (4-bit packed, Yamaha) |

## Payload (#5) codec — SOLVED
AICA on-chip 4-bit ADPCM, algorithm identical to MAME aica.cpp:
```
signal = 0; quant = 0x7F
per byte: low nibble FIRST, then high nibble
  x = (quant * QUANT_MUL[nib]) >> 3          # QUANT_MUL = ±(1,3,5,7,9,11,13,15)
  signal = clip16(signal + x)
  quant  = clamp(quant * TableQuant[nib&7] >> 8, 0x7F, 0x6000)
  TableQuant = [230,230,230,230,307,409,512,614]  (0.8984|1.1992|1.6|2.0|2.4)
```
Tools: `tools/dtpk_extract.py`, `tools/adpcm_decode.py`, `tools/dump_audio.py`,
waveform preview in `tools/wave_png.py`.

Validation: decoded `VO_AKI` WAV shows two clean voice phrases
(waveform-verified; zcr≈0.10, rail<1%).

## Open items
- Sample rate not embedded visibly; play at ~22.05 kHz nominal
  (or AICA's 44.1k × FNS/OCT from the bank header).
- BGM_* payloads decode ~40% hot-clipped — they are SONG KITS
  (sequence+instruments): continuous stream would need note-level voice
  resets from sec1/sec3; decode per-voice next milestone.
- sec0/sec1/sec3/sec4 fine-grained fields unmapped.
- LV of VOF*FX packs differ from VO_* only by +1 dir slot (the 3112 table).
