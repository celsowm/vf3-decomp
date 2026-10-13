# Options-menu development diagnostic

The new readable `src/fight/options_menu.c` models true entry `0x8c09bc1c`,
frozen owner `0x8c09bc2e` (664 bytes). It expresses menu navigation, the
eight option wrap ranges, reset actions and exits while retaining original
guest registers, stack, sound calls and value/configuration helpers.
It is routed only in a private development executable and is absent from
the normal CMake target. It adds **zero verified coverage**.

`options_menu_screen_inputs.py` generates 128 original input variants;
all 128 invocations complete in each of original states 28 and 29 with no
rejected specimens, incomplete records or nondeterminism. The untouched
original opcode/pool audit observes **650/664 body bytes separately in each
state**, with 128 distinct valid inputs in each. The immutable isolated
model passes **256/256 strict cases with zero skips**, and also passes all
171 older development cases. Private binary/source closure is retained in
`C:/Users/celso/AppData/Local/vf3-decomp/audio-evidence/options_menu_isolated_dev_v1/`.
Reports are `extract/analysis/options_menu_complete_isolated_dev_v1_native.json`
and `tools/oracle/options_menu_original_dev_v1_report.json`.

The old ledger already identifies the blocking nonzero reset branch.
Fresh disassembly confirms that `0x8c08e620` calls the byte setter with
R5=0 and its delay slot sets R4 to configuration base+14. The later byte
read cannot observe a nonzero initial value under this RAM protocol.
Missing PCs `0x8c09be92` through `0x8c09be9a` are therefore still blocked.
The other two missing PCs, `0x8c09bd30`/`0x8c09bd32`, correspond to a
reachable nonwrapping decrease, but filling them would not qualify the owner.
No passing subset is promoted and no helper or instruction was patched.

This owner should have been checked against the previous blocker ledger
before implementation. `coverage_65_candidate_blocks.json` now records
this and the known input-observation/device/IRQ blockers explicitly.
`refresh_candidate_pool.py` applies those exclusions and recomputes current
address-union margins, keeping advisory potential distinct from qualified C.
Reopen an excluded owner only with evidence that addresses its stated cause.
