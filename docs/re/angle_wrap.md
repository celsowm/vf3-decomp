# Structured three-component wrapping (2026-10-11)

The strict matrix route for `0x8c09f6fc` now uses `src/fight/angle_wrap.c`.
It loads three target floats, compares them with the current triple, and
adjusts each current value until the difference falls below the original
32768 threshold. It preserves the retail 65535/65536 increments, the
65530 decision boundary, both signs, repeated adjustment and the 655360
large-difference reset. The angle interpretation follows those constants;
the fields' gameplay roles remain unqualified.

The C expresses the shared operation as component and adjustment loops,
retaining guest scratch registers, exact FPU arithmetic, literal loads,
FR13 stack save and restore, full XF bank and return PC. It supports
single precision with FPSCR.SZ clear. The historical `f9f6fc.c` helper has
a separate 37-register harness; its callers remain unchanged and tested.

Development and acceptance each pass **128/128** complete original SH-4
cases with **zero skips, rejected specimens or quarantine**. Saves 21/26
provide development; saves 28/29 provide independent acceptance with changed
finite triples, relocated buffers and the other FPU bank. Both corpora
independently execute all **254 bytes** in the address-range table. The
final native executable and **367 compilation source files** were frozen
before acceptance. Expected state and RAM come from original execution.

Promotion rejected this helper because it is absent from the locked function
inventory, although the address-range table contains its full body. That
rejection is retained in `tools/oracle/angle_wrap_v1_rejected_credit.json`.
It earns **zero frozen percentage bytes**; the inventory and denominator
remain unchanged. `select_next.py` now checks both tables before reporting
percentage candidates, with two regression tests for hidden and inventoried
functions. Future static ranking must apply the same intersection.

The sealed proof is `tools/oracle/angle_wrap_v1_manifest.json`.
All **28 affected bindings**, **39 native suites** and **124 tool tests**
pass. Opcode ledgers are available for every matrix binding inspected;
the sole original BSR at `0x8c09f6e4` belongs to the separately tested
native caller `0x8c09f6dc`. The prior complete percentage chain and seal
are retained explicitly as historical evidence.

Current verified readable C remains **259,688 / 434,656 (59.75%)**, with
**1,373 bindings**. The gaps remain **1,106 bytes to 60%** and **22,839 to
65%**. This checkpoint improves the implementation and behavioral evidence,
and fixes candidate eligibility; it makes no percentage gain claim.
