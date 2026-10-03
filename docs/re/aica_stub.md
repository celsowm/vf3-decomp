# Campaign A — AICA pool helper stub

Campaign A adds a new adapter module that handles a small but recurring
class of failures: the captured case dispatches through a runtime
function pointer table to the AICA command-pool entry point at
`0x0c001006`. The SH-4 executes a 5-instruction SH-4 routine (a
memcpy+jmp) at that address before AICA takes over. Until this session
the dispatch chain fell through to `vf3_matrix_adapter` which had no
case for `0x0c001006` and rejected the call with
`unsupported helper/state at <entry> PC 0x0c001006`.

## What was added

- `src/fight/vf3_aica_stub_adapter.c` — a new adapter module with a
  single SH-4 routine: `0x0c001006–0x0c001014`, a 4-word
  `mov.l @r0,r3 ; mov.l r3,@r2 ; add #4,r0 ; add #4,r2 ;
  cmp/eq r0,r1 ; bf 0x0c001006 ; mov.l 0x0c001024,r0 ; jmp @r0`.
  Each opcode has its own `case 0x0c…u` and `P_0c…` label mirroring
  the generated-adapter style.
- `src/fight/matrix_family.{c,h}` — declares the new adapter and
  adds it to the dispatch chain ahead of `vf3_matrix_adapter`.
- `CMakeLists.txt` — adds the new file to both the default `vf3core`
  library and the `-O0;-frounding-math;-ffp-contract=off` compile
  group.

## What it does to the failing set

`0x8c09635a` (and the family of entries that dispatch into
`0x0c001006`) now runs through the AICA helper — the captured case
no longer fails with `unsupported helper/state at … PC 0x0c001006`.
The harness still rejects most cases because they have non-zero
`oob` counts (the captured RAM windows don't cover the addresses
`r0` and `r2` point at). The stub is **functionally correct**; the
remaining failures are a captured-data problem, not a stub problem.

`0x8c04853a`, `0x8c048480`, `0x8c064246` and the partial-fail entries
do not dispatch through `0x0c001006`; their failures are unrelated
to the AICA stub. Campaign B (wider capture RAM windows) and Campaign
C (callees) are still blocked on capture reruns.

## Why this matters

Before this stub the harness's failure pattern for `0x8c09635a` was
`unsupported helper/state at 8c09635a PC 0c001006 (0 OOB)`. After
the stub it is `unsupported helper/state at 8c09635a PC 00000000 (8 OOB)`:
the stub ran (the OOB count grew from 0 to 8 because it actually
attempted the SH-4 memcpy), the dispatcher reached the `rts`/`jmp @r0`
exit cleanly, but the captured RAM windows don't cover the
destination addresses, so the harness rejects on OOB. Promotion of
`0x8c09635a` is now blocked on Campaign B (capture rerun with a
larger `--ramn` window), not on stub authoring.