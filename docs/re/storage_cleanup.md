# Generated artifact cleanup (2026-10-11)

The user authorized removal of old artifacts no longer needed. Reference
discovery searched all JSON documents in `tools/oracle`, `extract/analysis`
and the external evidence cache for native archive paths. The 32 matching
documents identified the executables required by existing proofs.

Cleanup removed **3,426 unreferenced executable copies** from old
`native_*` regression archives. **All 1,618 retained executable checksums
match their recorded hashes.** Captures, original executables, source
freezes, states and referenced regression binaries remain available.
The cache cleanup report is
`extract/analysis/obsolete_native_archive_cleanup_v1.json`.

Before deletion, transparent NTFS compression of two old native archives
reduced their combined physical storage from about 7.87 GiB to 1.41 GiB
without changing logical contents. The subsequent reference-aware
cleanup also removed unused binaries from those archives.

On the workspace drive, cleanup removed **128 generated build
executables** unused by the 1,392 current golden bindings and 39 native
suites. The **60 required executable targets** remain. CMake can rebuild
the parked outputs when needed. The report is
`extract/analysis/unused_build_executable_cleanup_v1.json`.

Free space after cleanup: approximately **91.1 GiB on C:** and
**6.6 GiB on E:**. Future milestone builds should use
`python tools/build_required.py --jobs 4` to build all current required
targets. A default build of every CMake target recreates the unused
outputs. `--list` prints the required target set without building.

New milestones archive only the 39 native suite executables that their
seals reference, together with the separate frozen replay executable.
The 65% goal and frozen coverage denominator are unchanged.
