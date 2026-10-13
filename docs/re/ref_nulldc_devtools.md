# nullDC DevTools reference

Reviewed 2026-10-12: [official DevTools](https://nulldc.emudev.org/devtools/)
and [official build downloads](https://nulldc.emudev.org/builds/).
Local third-party files stay under gitignored `refs/`; nothing was copied into
the VF3 C port or counted as verified coverage.

## Available locally

| Location | Contents and provenance |
| --- | --- |
| `refs/nulldc-devtools/` | Published frontend HTML, JS, CSS, logo and AICA DSP WASM. `provenance.json` records retrieval URLs, sizes and SHA-256 hashes. This is a deployment snapshot, not an upstream source checkout. |
| `refs/nullDC-rust/` | Source checkout, commit `6b76ff0`; `devtools/` includes the React frontend, debugger JSON-RPC schema, mock WebSocket server, SH-4 simulator and DSP panel. Root project license is MIT. The mock server deliberately emits synthetic state and is not connected to an emulator. |
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

## Fit with current VF3 audio captures

The local `refs/aica-dsp-playground/ui/index.html` accepts a text recipe of
`COEF`, `MADRS`, `MEMS` and `MPRO` register values and can export the same
representation. Our `AICA_DUMP` probe command currently saves the 2 MiB sound
RAM image; it does not serialize those DSP registers or the DSP's execution
state. The formats therefore do not connect directly today. A useful next
bridge would be a separately validated DSP-register/state export from the
instrumented emulator, followed by a converter into the playground recipe.
Until that exists, the playground can help inspect documented DSP programs,
but cannot replay the VF3 captures or explain BGM voice-reset boundaries.

The source checkout confirms that the mock WebSocket service is intended for
UI development and sends fabricated register/event updates. The React DSP
panel and its WASM wrapper are useful as an inspection UI/reference once DSP
state can be exported, but the broader debugger would need a substantial
Flycast adapter for pause/step, memory, registers, breakpoints and events.
That adapter does not currently exist in this repository.

The nullDC DevTools site snapshot itself verifies locally with
`python tools/nulldc_devtools.py --check`. Its frontend currently has no live
debugger backend configured, so it does not consume our Flycast watches,
capsules, or trace logs. Importing its backend contract would require a
protocol adapter and format-by-format validation; it is not a drop-in
replacement for the current oracle.

The SH-4 simulator can explain instruction dependencies and timing hypotheses.
Its own page identifies it as work in progress and flags inaccurate examples;
it is not an execution oracle or a substitute for our complete-state proofs.

TA/CORE inspection is a promising direction for device-dependent rendering
paths. A future adapter should first check exact input formats and preserve
the original device observations. These tools have not established the cause
of the equal-captured-input/different-original-output quarantines, and do not
justify reopening those owners or increasing coverage.
