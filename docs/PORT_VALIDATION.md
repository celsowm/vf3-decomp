# Local validation of the initial SDL port foundation

Date: 2026-10-20. Host: macOS arm64, AppleClang 21, Python 3.15, SDL 3.4.18. The CI recipe also builds against pinned SDL 3.2.10. This is a development milestone, not a gameplay/fidelity certification.

The maintainer's concurrent `c4c9de3` update was merged without discarding upstream changes. The recorded address-union metric is now 396,830 / 434,656 (91.30%). Its frozen inventory and replay fixtures are not present locally, so it has not been recomputed here.

## Reproduce

```sh
python3 tools/prepare_rom.py --zip /path/to/rom_compactado.zip
cmake -S . -B build -DVF3_BUILD_SDL3=ON -DCMAKE_BUILD_TYPE=Debug
cmake --build build --parallel
ctest --test-dir build --output-on-failure
python3 -m unittest discover -s tests -p 'test_*.py'
python3 tools/port_preflight.py
```

The supplied archive matches all three expected track SHA-1 values and the GDI identity. Extraction produced 412 game files and an exact match for the retail executable SHA-256. The original ZIP was retained. No game data is committed.

The local CTest suite covers seven Python groups, SDL input integration, SDL software/dummy presentation, synthetic GD-ROM CLI regressions and real-disc GD-ROM reads. SDL tests include virtual controllers, active-low mapping, stable hotplug slots and initial/unfocused input neutrality. A visible native-window diagnostic was also run on the Mac. These are host-platform tests, not game rendering tests.

The real-disc test transferred 75 sectors over 15 DMA steps and 7 sectors via the BIOS syscall path, with zero byte differences from the sector reader. Two optional saved-state resume checks were explicitly skipped because their dumps are unavailable.

The Python suite checks archive safety/conflicts/identity import, gate exit statuses, fixture availability and companions, binding selection, platform executable resolution, opcode classification and capsule integrity. Previously exported fixtures for a newly quarantined entry are preserved with non-consumable `.quarantined` extensions, preventing stale replay evidence from being reused.

## Evidence still missing

`tools/port_preflight.py` intentionally exits 1: the 2,231 golden fixtures, the frozen coverage inventory/ranges, 39 native-tick inputs/references, 17 boot captures and 15 GD states are absent. Required extended-state companions and referenced RAM must also accompany the fixtures. Four existing golden paths are absolute Windows paths and require documented relocation. Presence checks do not replace actual replay validation.

The original core has compiler warnings and placeholders documented in `PC_PORT_PLAN.md`; they are not covered up by this milestone. No cold-boot game, native PVR renderer, AICA mixer or completed two-player runtime has been certified. The next acceptance gates are in the completion plan.

Remote platform results are recorded by the `Native build and ROM-free tests` workflow attached to each pushed commit. CI deliberately skips the real-disc test when game assets are absent; that skip does not certify the disc path or gameplay.

The first remote run exposed a tracked GDI descriptor being mistaken for a complete local disc, plus two Windows path-separator assumptions. The gate now checks referenced tracks, skips only missing inputs and still fails on malformed/truncated inputs. Seven executable-level regressions cover those boundaries, explicit missing dump requests and a successful synthetic transfer. JSON paths are normalized to forward slashes across hosts.

The post-merge [translator review](re/translator_semantics_review.md) adds compiled C regression tests for signed MAC arithmetic and rejects incomplete SR-load handling. The entire c95 corpus still needs independent replay; no new byte coverage is claimed.
