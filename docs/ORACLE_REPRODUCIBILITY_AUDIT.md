# Oracle reproducibility audit — 2026-10-21

The supplied `vf3tb-evidencias` bundle preserves the oracle source changes,
but does **not** contain a self-contained rebuild of the instrumented Flycast
executables or the evidence needed to independently revalidate the v2 control
seal. This finding does not invalidate a separately executed C replay of the
included fixtures; it limits reproduction of the reference that recorded them.

## Scope and method

This audit read the extracted bundle, the repository, and their JSON/text files.
It computed SHA-256 over file bytes, resolved Windows manifest paths to the
bundle's relative paths and `external_capture_mirror/<drive>_drive/`, and checked
the explicitly preserved copies in `extract/analysis/oracle_revision/`.
References were deduplicated by `(path, sha256)`.

No bundle script, emulator, or executable was run. Original evidence and
manifests were not changed. Source transformations below were checked in memory.
This document contains metadata only; it does not include ROMs, snapshots,
recorded game data, proprietary binaries, or local user-directory paths.

`evidence_manifest.json` records inventory counts, not a cryptographic inventory
of every fixture. Its SHA-256 is
`ce04f7ee63297892d0e81462b029883fd1298e815a18301fae2ee3bee1c8c82c`.
The original bundle's `tools/golden_bindings.json` has SHA-256
`3d9457f49c7c11ee13ecb3f8c35201afc35791157c6a0e2cf289391aa8d7a16f`.
These identify the inputs examined, not a claim that every recorded outcome is
correct. Replay results are recorded separately.

## Preserved source evidence

Paths in this table are relative to the bundle's
`extract/analysis/oracle_revision/` directory. Hashes cover the original bytes,
including line endings.

| File | SHA-256 |
| --- | --- |
| `REBUILD.md` | `eacf922032f439c950038c17fbe8adc19a55f5a247d1b79f9be05917493c6363` |
| `vf3oracle_pristine.cpp` | `ebc017d7eb86f92c7d532f90bb3f068656130e06a8e809d178ce3eb01a380a7e` |
| `vf3oracle_patched.cpp` | `64619fb0d04d41d45b13a2ca218ac2ec029226545564983099dab6fb0cf56f57` |
| `vf3oracle_full.patch` | `e6c23dad56965193e31f8afbcb3ef71a3f943ef1718608651701446466646734` |
| `oracle_device_reads.patch` | `a068f4d7b06780a346c0fb05441203e7c49c8e2587eab25b27497d7b643c76b4` |
| `build_extended_observer_v2.py` | `81caa17e3acc7336ed2d35459b1c86b24ed72b6e1c154404ec6c34fdc5f79664` |
| `extended_observer_controls_audit_v2.py` | `18fc6206986e8ffb177051a11ec5f037d587d0ddde9d83d4be8247a30a301b26` |
| `capsule_extended_observer_v2_build_manifest.json` | `d523f419816be5f42e57014d3c60931e0cfa5c4d1698b0bcb956402aaafa8271` |
| `extended_observer_controls_v2.json` | `aad8e9502eee07642c6dc0402b2035799dfb7dc5f7784ba450a460c630e08ff9` |

Applying all unified-diff hunks from `vf3oracle_full.patch` to the pristine
source reproduced the patched source text exactly. Serializing that text with
CRLF reproduced the included patched file's SHA-256. The bundle's
`tools/oracle/vf3oracle.cpp` also matches the pristine source hash.

The v2 builder changes exactly these markers in the patched source:

```text
c.ops.size()<100000  ->  c.ops.size()<500000
"VF3CAP6\0"          ->  "VF3CAP7\0"
```

Performing those substitutions in memory and using CRLF produces SHA-256
`9526b351becdec9ec4ed8c407514336721a061f7c1630ef6b80f8596259258e6`,
which matches the generated-source digest in the build manifest. This verifies
the source transformation, not the generated object or executable.

The narrower device patch already expects `vf3GdSnapshot()` and GD logging in
its context. It is not the complete pristine-to-patched change. The full patch
adds the declaration/call of `vf3GdSnapshot()` from `reios/gdrom_hle.cpp`, but
the corresponding implementation is not included. It also adds the scheduler
header and GD logging at invocation boundaries.

## Build and control reference closure

| Manifest | Unique references | Included and exact | Not included |
| --- | ---: | ---: | ---: |
| `capsule_extended_observer_v2_build_manifest.json` | 353 | 4 | 349 |
| `extended_observer_controls_v2.json` | 150 | 3 | 147 |

The build's four matching references are the pristine source, patched source,
device patch, and v2 builder. The control seal's three matching references are
the build manifest, control-audit script, and pristine source. Renamed copies
inside `oracle_revision/` count as present only when their bytes match the
declared digest. The counts are bundle-only; repository files can supply some
additional inputs, but not the missing capture/build closure.

The missing build dependencies include the Flycast tree, prebuilt objects and
libraries, CMake flags/response files, the principal executable, the extended
executable, and a library from the Windows toolchain. The build dossier does
not pin a Flycast Git commit or submodule revisions. No Flycast source tree is
included in the bundle.

The named executables are absent; their manifest hashes are:

| Executable | Declared SHA-256, not verified against an included binary |
| --- | --- |
| `tools/emu/flycast-build/flycast.exe` | `8dbf46ef29aeec2e128dcbb90c5c7816dc0bc0f1b53d568194ddaf49220a50b8` |
| `<capture-cache>/flycast_capsule_extended_v2.exe` | `d836abc4b0c8b42f0a32069051b367452a721195800958e2bbf9869a229e4b95` |

`build_extended_observer_v2.py` reads `flags.make`, `objects1.rsp`,
`includes_CXX.rsp`, and `linkLibs.rsp` from an existing Windows build. It compiles
only the changed oracle object, archives it with the other prebuilt objects,
and links with MSYS2 UCRT64 tools. It is not a complete source-build recipe;
the compiler itself is not hash-pinned by this manifest. Its imported Python
helpers and hardcoded Windows paths also require restoration/remapping.

`REBUILD.md` assumes `tools/emu/flycast-build` already exists. Its referenced
`extract/analysis/make_oracle_patch.py` is absent. Its builder/audit commands
name `tools/oracle/` paths, while the supplied copies live in
`extract/analysis/oracle_revision/` and depend on their intended installation
location. Executing them directly from the evidence directory would resolve
their repository root incorrectly.

The missing control dependencies include the original, main, and extended
control manifests and their eight windows of capsules/audio/logs, the original
`vf3_28.state` and `vf3_29.state`, and
`extract/analysis/extended_capsule_tool_tests_v2.log`. The seal's claim that
controls passed cannot be independently rerun from the bundle alone.

Some differing repository hashes are explained solely by LF versus CRLF,
including the device patch, `audio_actor_clear.c`, `audio_one_shot.py`,
`install.py`, and `replay_transition_original_dispatch_v2.json`. Such files are
text-equivalent but still fail a raw-byte hash check. Preserve original seals;
record any remapping or newline normalization in a separate derived manifest.

## The 128-to-1024 discrepancy

The preserved patched recorder raises the RAM page budget from 128 to 1024.
`REBUILD.md` also says `tools/oracle/capsules.py`,
`tools/oracle/prune_corpus.py`, and `tests/port_harness.h` were raised to 1024.
Those three files are not supplied in the bundle. The repository versions
examined still enforce 128 in the capsule parser, corpus-pruning parser, and
`VF3H_MAXWIN`, respectively.

The v2 seal pins `capsules.py` to
`3a40179c5a4fbd145e396ea10293578aa4679badb53837a846d33a38804fcd3f`.
The audited working file and seven locally available historical versions did
not match that digest, including LF/CRLF variants and the isolated
`npage > 128` to `npage > 1024` substitution. The exact sealed parser is missing.

A read-only structural scan covered all 2,250 original golden bindings:

| Descriptor property | Observed |
| --- | ---: |
| Rows containing RAM descriptors | 470,725 |
| Of those, rows with nonempty entry windows | 470,025 |
| Of those, rows with empty entry windows | 700 |
| Register-only rows with exactly 74 words and no RAM descriptors | 64 |
| Maximum windows in an entry/exit descriptor | 45 |
| Rows with more than 128 windows | 0 |
| Structural parsing errors | 0 |

The 700 empty-entry descriptors occur across 14 unmarked bindings and are
syntactically valid; they are distinct from the 64 rows with no RAM descriptors
at all. A descriptor's presence does not mean the harness has loadable RAM.

Thus the 128-window harness/pruning ceiling does not explain failures in these
golden descriptors. This scan did not execute their tests or verify every
shadow/sidecar payload. `capsules.py` merges adjacent pages into windows, so
window count is not raw capsule page count: 55 entry descriptors and 39 exit
descriptors span more than 128 pages.

For future inputs, the discrepancy remains material: the current capsule
parser rejects a raw record above 128 pages with `invalid record sizes`; the
pruner rejects descriptors above 128 windows. The harness skips unparseable
rows. Strict replay rejects skips, while an unmarked test can pass the remaining
subset. The inspected harness increments its sidecar ordinal only after a row
parses, so a rejected row can also misalign later sidecar selection.

## Limits of the v2 control seal

The seal sets `coverage_credit: false`. Its eight control windows are short,
original, non-rollback executions with no device accesses. They do not exercise
the 500,000-instruction boundary or synthetic device-write suppression.

The audit script compares architecture, RAM, and instruction trace between
pristine/main and pristine/extended. Its explicit audio comparison is only
pristine/extended, although its description/final message claims audio agreement
among all three. It hashes the tool-test log but does not establish that log's
test outcome by parsing it. The log itself is absent here.

The patched synthetic recorder suppresses device writes and records a tape for
replay. Agreement with that tape demonstrates agreement with the captured probe
contract; it does not by itself establish live device behavior or whole-game
equivalence. Successful control windows likewise do not prove playable 1:1 PC
behavior.

## Material needed to close the reproducibility gap

1. The exact Flycast commit/submodule revisions and all local modifications,
   including GD snapshot, trace, interpreter, and runner hooks.
2. A complete source-build recipe with compiler/dependency versions and build
   configuration; preserve the old pinned executables/build inputs if their
   historical hashes must be validated.
3. The three original control datasets and manifests, states 28/29, and the v2
   tool-test log.
4. The exact sealed `capsules.py` and the promised 1024-window consumer changes,
   with tests at and above each boundary.
5. A fresh independently recorded seal for a rebuilt oracle if the historical
   executable cannot be reproduced. Do not relabel newly generated evidence as
   the original pinned artifacts.
