# VF3tb executables

All loadable code files descrambled with `tools/dc_scramble.py`
(permutation verified by exact re-scramble of the original).

| file | size | loads at | ISA | role |
|---|---|---|---|---|
| `1ST_READ.BIN` | 1,179,648 | 0x8C010000 | SH-4 LE | main game binary (retail V1.002, 1999-08-20) |
| `VF3TBE3.BIN` | 1,114,112 | 0x8C010000 | SH-4 LE | **E3 demo build of the same game** — enables build-to-build diffing to separate library code from game code |
| `RELOAD.BIN` | 655,360 | 0x8C010000 | SH-4 LE | re-init/resident module; embeds Shinobi libs (`GDFS Version 0.53`, `syCache 1.07`/`syCbl 1.10 Build Jan 26 1999`) + NAOMI LIBRARY Ver 0.8 + NEC PowerVR code (`EnableTexture16MB`) |
| `SNDDRV.BIN` | 53,120 | AICA RAM (ARM exception-vector entry points: `b` at 0x00..) | ARM7 (LE) | AICA sound driver program uploaded by the SH-4 host |

## Library stack identified in `1ST_READ.BIN` (from version banners)

| banner | meaning |
|---|---|
| `NAOMI LIBRARY Ver 0.8 AM R&D` | Segamo NAOMI/AM-2 middleware rendering core |
| `GDFS Version 0.53  1998/08/28` | Shinobi GD-ROM filesystem driver |
| `syCache Ver 1.0` / `syCbl Ver 1.x` | Shinobi system library (cache control, cable checks) |
| `pd Ver 1.07` | Shinobi peripheral driver library (Maple/VMU) |
| `bu Ver 1.03` | Shinobi backup unit (VMU saves) |
| `kd Ver 1.20` | display/device driver component |
| NEC copyright block | NEC PowerVR code (Kamui-era PVR2 driver) |

Implication: VF3tb does **not** statically link NEC's `kamui2.lib` in a form
that matches the Kamui SDK samples (fingerprint corpus: 639 functions,
~0 hits). Rendering goes through the AM2 NAOMI library; PVR register-level
information can still be mined from the Kamui sources where it overlaps
with the NEC driver strings present in the binary.
