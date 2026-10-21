# Translator semantics review after the c95 merge

Review date: 2026-10-20. Reviewed upstream change: `c4c9de3`.

The initial SDL milestone integrated upstream rather than replacing it. Independent review then found three concrete issues in the newly added instruction translation. These findings illustrate why historical finite-corpus coverage must not be interpreted as universal equivalence.

## MAC.W and MAC.L

The added emitter cast each signed operand through `uint32_t` before widening to `int64_t`. Negative operands consequently became positive. For example, −1 multiplied by 2 accumulated `0x00000001fffffffe` instead of `0xfffffffffffffffe` in a zero 64-bit accumulator.

The special address adjustment also compared register contents. The condition is whether the encoded register indices are identical (`n == m`), not whether two registers happen to contain the same address. Distinct registers with identical pointers must not read a second element.

The fix preserves signed multiplication, modulo-64-bit accumulation and ordered reads. MAC.W reads RN then RM; MAC.L reads RM then RN. Postincrements follow the encoded registers, including two increments of one register when they alias. Saturating mode (`SR.S=1`) is explicitly rejected before touching memory or state until its semantics are implemented. This matches the oracle's unsupported-mode boundary; it does not claim saturation support.

Exactly three emitted MAC.L instances in `src/fight/vf3_c95_adapter.c` require corresponding changes: guest PCs `0x0c07350a`, `0x0c07350e` and `0x0c073512` (opcode `0x0c0f`). The original c95 capture corpus is unavailable locally; updating these statements is not a claim that the entire c95 corpus has been replayed.

## LDC.L @Rn+,SR

The new broad mask wrote the loaded value into Rn instead of SR and also accepted unrelated control-register forms. SR handling cannot be repaired by changing the destination alone: this project keeps T inside `r[17]`, whereas Flycast stores T separately, and an MD/RB change requires register-bank handling. The partial newly added decoder is therefore removed; unsupported loads remain explicit. There are no emitted LDC.L-to-SR instructions in c95.

The older direct `LDC Rn,SR` emitter also requires a separate audit of banking and interrupt semantics. It is recorded as follow-up work; this change does not silently regenerate all previously validated adapters without their corpora.

## Reference and verification

Reference implementation inspected at Flycast commit `34ad8c8262c82db237a8b9cee0d8046d9cdd6f78`:

- [Instruction implementation](https://github.com/flyinghead/flycast/blob/34ad8c8262c82db237a8b9cee0d8046d9cdd6f78/core/hw/sh4/interpr/sh4_opcodes.cpp)
- [SR representation](https://github.com/flyinghead/flycast/blob/34ad8c8262c82db237a8b9cee0d8046d9cdd6f78/core/hw/sh4/sh4_if.h)
- [Register-bank updates](https://github.com/flyinghead/flycast/blob/34ad8c8262c82db237a8b9cee0d8046d9cdd6f78/core/hw/sh4/sh4_core_regs.cpp)

`tests/test_translator_semantics.py` compiles emitted C and checks signed operands, limits, accumulator wrap, register aliasing, read order, increments and unsupported modes against independent expected values. It also checks the three generated statements stay in sync with the emitter. Re-run these tests and the missing strict oracle corpora before claiming any new coverage.

The instruction-family counts in the earlier c95 report predate this fail-closed correction and must not be reused as current support counts. The historical byte-union number remains labeled as the author's recorded result.
