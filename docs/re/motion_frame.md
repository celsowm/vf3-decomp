# Motion descriptor frame caller — 2026-10-10

Readable `src/fight/motion_frame.c` implements full callable `0x8c0a94d0`,
attributed to frozen owner `0x8c0a94d4` (188 bytes). It copies descriptor flags,
three float bit patterns and packed fields into the actor, publishes the
requested motion, and selects zero, changed-motion, initial-frame or subsequent
frame behavior. Changed motion calls actual `0x0c0ad390` and `0x0c09d5ae`;
frame paths call `0x0c09f1ac` or `0x0c09f036`, then actual pose update
`0x0c09ea66`. No helper return or loaded motion table is fabricated.

The original BSR sites are `0x8c0a9208` and `0x8c0a921a`. Their delay is
**MOV R12,R4**, opcode `0x64c3`. The prefix is MOV #4,R0, push R14, push PR.
Eight process-owned original-only specimens across saves 26/28 execute both
original edges, prefix, zero-motion return, ordered PR/R14 restores and RTS
delay. These fixtures establish real image call edges; they are not natural
game playback observations. The narrow `vf3-motion-frame-bsr-v1` contract
leaves the legacy BSR gate unchanged.

Early synthetic IDs 1–4 gave invalid/incomplete probes and missed the changed
motion path. Natural retained `0x8c09d5ae` specimens establish actor
`0x0c1fefe4`, VM `0x0c226864`, runtime table `0x0c5f4000`, and motion IDs
`0x41a`, `0x956`, `0x27`, `0x69f`. New profiles use these observed records
and retain the real table and actor context. Full-entry C initially was
unsupported; the readable implementation fixes that entry. The existing
partial-owner adapter remains available for its consumers.

C was frozen before acceptance at
`C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence/`
`vf3matrixfamily_motion_frame_dev_v1.exe`, SHA-256
`effd34c4005c2532089b5ae83c4a6ec3338fd5a3d38bc711156a61c033e1bd07`.
The corresponding archive is `motion_frame_dev_v1_sources/`.

Development `coverage_65_motion_frame_dev_v3` passes **109/109** distinct
valid cases from saves 26/27. Acceptance `coverage_65_motion_frame_accept_v2`
passes **118/118** from saves 28/29, with descriptors relocated by `0x100000`,
different float bits and motion/frame ordering. Both independently execute
all 188 frozen bytes and preserve R8–R14/SP, with zero native replay skips
and no incomplete or nondeterministic retained invocations. The actor stays
at its actual loaded address; it is not claimed to be relocated.

Raw development retains **nine** rejected flag-1 specimens; acceptance
retains **ten**. These exception/interrupt probes are excluded by the existing
capsule gate, not counted as matching C cases. Development started/completed
64/64 and 54/54 probes; acceptance 64/64 and 64/64. All emulator runs completed
600/600 frames. Earlier 90/180-frame pilots with shutdown incompleteness are
retained and excluded. This is RAM-only motion replay, not live-C audio proof.

`percentage_motion_frame_milestone.json` grants exactly **188 new bytes**,
bringing the accepted union to **259,110 / 434,656 (59.61%)**. Prefix/helper
bytes outside the frozen owner earn no new credit. Six mutation tests cover
wrong BSR targets/delays, missing prefix/restores, changed saves/SP/PR,
modified literal pools and nonoriginal opcodes; all 104 tool tests pass.

Fresh regression is complete: **all 1,368 bindings**, **39 native suites**,
**104 tool tests**, the full percentage milestone hash chain, and the remaining
`verify_all.py` repository gates pass. Proof seal:
`tools/oracle/motion_frame_v1_manifest.json`. Compiled sources and all default
native executables are checked against their immutable archives.
