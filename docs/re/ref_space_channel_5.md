# Space Channel 5 native-port reference

Repository: [ZoomiesZaggy/Space-Channel-5](https://github.com/ZoomiesZaggy/Space-Channel-5).
Local checkout: `refs/Space-Channel-5` (gitignored).
Reviewed commit: `d8ffab5a3ecd4426386c746ceaa9b4cb75d09486`, cloned on 2026-10-12.
The checkout is shallow and uses Git's blob filter; the checked-out sources are present.

This project translates the USA Dreamcast executable ahead of time and drives
Flycast device, rendering and audio components from a native host. Its source
provenance pins Flycast `eddf2635867f0f16f64bebd3185db151c99c551c`; the Forge
decoder retains its MIT notice, while the host files carry their own notices.
The generated gameplay source is provided separately with release artifacts.
The README's platform and gameplay claims have not been reproduced for VF3.

## Concrete uses for VF3

| Source | Potential use |
| --- | --- |
| `tools/Sc5NativeDifferentialTest.cpp` | Original-interpreter versus native tests for startup/full RAM, register-bank and exception return, aliases/delay slots, floating arithmetic, matrix transforms, FTRC, FSCA and FSRRA. Several floating tests explicitly omit exception-flag comparisons; our existing complete-state gates remain required. |
| `tools/native_device_runtime.h` | Explicit CPU/context synchronization, BIOS/disc services, device-bus accesses, native module switching and complete emulator checkpoints. |
| `tools/native_cycle_model.h` and `generate_static_timing.py` | Scheduler integration using Flycast timing descriptors; useful when building a continuously running VF3 native host. |
| `tools/native_fp_control.h` | Host rounding control for x86 and ARM64. A portability reference, subject to our existing SH-4 FPU differential checks. |
| `tools/native_render_surface.h`, `native_input.h`, `native_audio_capture.h` | Later player frontend and end-to-end graphics, controller and audio validation. |
| `prototype/Dreamcast-Forge/forge/sh4.py` | Additional static-decoder reference alongside the two recompilers already available locally. |

The strongest immediate research lead is the complete-state checkpoint and
context synchronization design. VF3 selection currently has two pairs of
identical captured RAM/63-word inputs with differing original final RAM.
Reviewing which device, scheduler and CPU state the SC5 host preserves may
help identify missing observations. That is an inference and an investigation
direction; this repository has not established the cause or supplied a fix.

Its generated game translations do not add verified readable VF3 C coverage.
Use the reference for infrastructure and validation while keeping VF3's image,
fixed denominator, whole-owner gates and independent acceptance requirements.
No external scripts were executed during this initial review.
