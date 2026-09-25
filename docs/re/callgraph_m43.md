# M43 — callgraph v3 on true image (2026-09-25)

Re-ran `python tools/callgraph.py 1ST_READ` on corrected image:

- instructions: 149,545
- call edges: 2,336 (resolved)
- unresolved jsr sites: 4,947
- **jsr resolution 2.8%** (was ~3% pre-M23)

Top dispatch-heavy (task runners): `f_8c0782ea` (23), `f_8c076c00` (12),
`f_8c05f976`/`f_8c063446`/`f_8c09635a` (11 each).

Top callee targets are all `(not a fn start)` mid-body waypoints
(e.g. `0x8C01942C x8`, `0x8C0B3E0C x8`) — consistent with struct-task
indirect model + CFG-splitter need (M68).

Artifacts: `extract/analysis/disasm_1ST_READ.unsc.bin.calls.csv`,
`.dispatch.csv`, `.hotrefs.csv`, `docs/re/hotspots_1ST_READ.md` regenerated.
Ceiling holds: literal vcalls resolve better per-fn (M25) but global static
jsr % unchanged — trace-backed dispatch remains required.
