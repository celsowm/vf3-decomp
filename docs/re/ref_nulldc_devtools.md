# nullDC DevTools reference

Reviewed 2026-10-12: [official DevTools](https://nulldc.emudev.org/devtools/)
and [official build downloads](https://nulldc.emudev.org/builds/).
Local third-party files stay under gitignored `refs/`; nothing was copied into
the VF3 C port or counted as verified coverage.

## Available locally

| Location | Contents and provenance |
| --- | --- |
| `refs/nulldc-devtools/` | Published frontend HTML, JS, CSS, logo and AICA DSP WASM. `provenance.json` records retrieval URLs, sizes and SHA-256 hashes. This is a deployment snapshot, not an upstream source checkout. |
| `refs/sh4-sim/` | Shallow clone of [skmp/sh4-sim](https://gitlab.com/skmp/sh4-sim), commit `2bbd6b4813529bcceddb988a74c2a8bfb2729312`. Static HTML/JS, MIT license. |
| `refs/aica-dsp-playground/` | Shallow clone of [skmp/aica-dsp-playground](https://gitlab.com/skmp/aica-dsp-playground), commit `55a1f7ab837f1ba866f1968f6904cc5928a7945a`. DSP interpreter, register definitions, UI and AICA notes. |
| `refs/nulldc-build/` | Official Windows x64 archive `nullDC-v2.0.0-pre-388-g95a924b-x86_64-pc-windows-msvc.7z`, 5,904,262 bytes, SHA-256 `d79e7e43a7aff8e30423cdea8d1283993948e61e05de49d9c6b553ff399ba5cc`. Archive listing contains `nullDC.exe` and `nullDC.pdb`; executable not run. |

Verify the frontend with `python tools/nulldc_devtools.py --check`.
Run `python tools/nulldc_devtools.py`, then open `http://127.0.0.1:8766/`.
The launcher supports client-side routes and explicitly reports that no live
debugger backend is configured. Monaco's editor loader uses an external CDN;
the snapshot is not a complete offline distribution.

## Concrete uses and limits

The published frontend includes SH-4, ARM7, mixed CPU and audio workspaces,
TA and CORE log analyzers, a pipeline simulator and DSP playground.
Its documentation describes JSON-RPC over WebSocket, a mock server, and a
`debuggerSchema.ts` contract. Our instrumented Flycast captures do not supply
that debugger service. Downloading the frontend or nullDC executable does
not establish a working connection, support for our save states, or compatible
TA/CORE logs. Those integrations remain unverified.

The best immediate audio reference is the DSP interpreter and MPRO/register
layout. The playground does not replace ARM7 driver decompilation, ADPCM
verification or the BGM voice reset investigation. Its CMake build needs
Emscripten for WASM or SDL2 for a native UI; no third-party build scripts were run.
The DSP interpreter carries an Audio Overload SDK copyright/all-rights-reserved
notice and a compatibility TODO. Keep it as a reference; do not infer a blanket
MIT license from the separately licensed SH-4 simulator.

The SH-4 simulator can explain instruction dependencies and timing hypotheses.
Its own page identifies it as work in progress and flags inaccurate examples;
it is not an execution oracle or a substitute for our complete-state proofs.

TA/CORE inspection is a promising direction for device-dependent rendering
paths. A future adapter should first check exact input formats and preserve
the original device observations. These tools have not established the cause
of the equal-captured-input/different-original-output quarantines, and do not
justify reopening those owners or increasing coverage.
