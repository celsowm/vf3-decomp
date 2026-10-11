# Controller packet word +16 merge (2026-10-10)

Readable C for callable `0x8c09afc0` obtains the actual port packets through
`0x0c0a1282`. It returns packet word +16 from port 0, port 1, or their OR,
using the same selector at `0x0c29bccc` as the word +8 merge. Other selector
bits are ignored. This evidence establishes the field's merge behavior;
its interpretation as a particular input event remains unqualified.

The frozen owner is `0x8c09afc6`, after three register saves. The new
`vf3-controller-secondary-bsr-v1` attribution contract qualifies those
saves through original BSR sites `0x0c09b4ea`, `0x0c09b528`,
`0x0c09b614` and `0x0c09b624`. Six mutation checks reject altered targets
or delays, missing saves/restores, register/stack/PR/return corruption,
nonoriginal opcodes and modified literal pools. The earlier merge contract
keeps its existing fixed addresses and checks.

After freezing the native executable and all 365 compilation source files,
development and fresh independent acceptance each pass **128/128 complete
cases**, covering all selector branches and the entire 64-byte owner.
Acceptance changes saves, packet and selector values, writable stack
location and FPU bank. Sixteen independent original BSR observations,
across all four sites and two held-out saves, prove the prefix and ordered
return. These are call windows, not complete parent executions. No rejected
or quarantined specimens, device accesses or AICA events enter this proof.

The hashed milestone adds **64 marginal verified bytes**: **259,220 ->
259,284 / 434,656 (59.65%)**, with **1,371 bindings**. The three-save prefix
adds no bytes to the frozen inventory. The gap is **1,510 bytes to 60%**
and **23,243 bytes to 65%**; the 65% target remains unmet.

All 18 affected bindings, including all three qualified controller ports,
39 native suites and 116 tool checks pass against the new build. This is
an affected regression gate. The previous full repository gate is historical.
The immutable source/native/capture proofs and preceding complete chain
are sealed in `tools/oracle/controller_secondary_v1_manifest.json` by
`controller_secondary_audit.py`. The accepted byte-credit milestone is
`percentage_controller_secondary_v1_milestone.json`.
