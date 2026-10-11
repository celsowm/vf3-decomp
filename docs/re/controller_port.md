# Selected-port button getter (2026-10-10)

Readable C for original `0x8c09b006` calls the actual `0x0c0a1282`
packet lookup with the incoming port selector. Packet status `0xfffffffe`
returns `0x80000000`; every other status returns the word at packet +8.
The original comparison's T bit, scratch registers, PR and guest stack are
preserved by the behavioral model. The supported input ports are 0 and 1.

Development and independent acceptance each match **128/128 complete
original-image invocations**, with no rejected or quarantined specimens.
Both ports and both return branches execute in each corpus. Acceptance
uses saves 28/29 instead of 21/26, changed packet values and statuses,
a relocated writable stack and the other FPU bank. Expected values come
from SH-4 execution. The frozen native executable and all 364 compilation
source files precede acceptance capture. Original opcodes, literal pools,
callee-save registers, PR, stack, return PC and touched RAM are checked.

The hashed milestone adds **32 marginal bytes**: **259,188 -> 259,220 /
434,656 (59.64%)**, with **1,370 bindings**. The gap to 65% is **23,307
bytes**; the target remains unmet. All 17 affected matrix bindings, 39
native suites and 110 tool checks pass. This is an affected regression
gate; the preceding full repository gate remains historical.

Reproduction inputs: `tools/oracle/controller_port_inputs.py`.
Accepted milestone: `tools/oracle/percentage_controller_port_v1_milestone.json`.
Source, captures, native reports, affected tests and preceding chain are
sealed by `tools/oracle/controller_port_audit.py` into
`tools/oracle/controller_port_v1_manifest.json`. Raw binaries and captures
stay outside git in the evidence cache.
