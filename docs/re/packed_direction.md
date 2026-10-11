# Packed direction encoding (2026-10-11)

`src/fight/packed_direction.c` replaces the matrix route for exact callable
and frozen owner `0x8c05865c`. Its contiguous 234-byte body ends at
`0x8c058746`, including RTS and its output-OR delay slot. Both frozen
inventory membership and marginal address union are checked before credit.

The leaf reads three vectors represented by the high 16 bits of their
float components after a four-byte header. It transforms each through
XMTRX, transposes the transformed basis, transforms the direction in the
other floating register bank, and quantizes the resulting direction with
the original quadrant and byte tables. This interpretation follows the
arithmetic and format; a gameplay role is not yet established.

The entry contract requires single precision with **FPSCR.SZ=1**. Paired
register moves initially copy the other bank's direction into FR12–15.
FSCHG then permits single-register transposition. Later paired moves
retrieve the transformed direction and restore the original other-bank
direction. GPR scratch registers, FPUL, T, both floating banks, return PC,
and touched RAM participate in strict comparisons. Unsupported entry modes
return failure from the C adapter.

Two initial development campaigns used SZ=0 and reached a non-RAM lookup
at `0x00800170`. All 256 specimens are retained as flag-6 diagnostics and
earn no credit. The first also had a degenerate packed basis; the second
corrected the basis. No diagnostic specimen enters either passing corpus.

Final development uses an identity packed basis, 64 distinct finite
direction/input variants, FPSCR `0x140001`, and original states 21/26.
Independent acceptance changes directions, relocates the input object by
`0x100000`, uses FPSCR `0x340001`, and original states 28/29. Each campaign
passes **128/128**, without exclusions, quarantine, native skips, or forced
helper answers. Each independently executes all **117 PCs / 234 bytes**.
This proof covers those finite input domains; broader production contexts
remain to be discovered.

The native executable `vf3matrixfamily_packed_direction_dev_v2.exe` and all
**368** compilation sources were frozen before acceptance. The original
observer is the unchanged `flycast_task_return_boundary_v1.exe` with its
102 linked source dependencies. Source archives and raw captures live in
the external audio-evidence cache; hashes and regression evidence are
sealed in `tools/oracle/packed_direction_v1_manifest.json`.

Seven original BSR sites call the leaf: `0x8c05879a`, `0x8c0587d8`,
`0x8c058816`, `0x8c0588f0`, `0x8c05891c`, `0x8c058978`, and
`0x8c058a5e`. Their frozen parents are `0x8c058788`, `0x8c058790`, and
`0x8c058a5c`; none has a current matrix binding. All matrix opcode ledgers
were available, and no other bound invocation executed this helper.
The new affected binding, all **39 native suites**, and **124 tool tests**
pass. A full current inventory gate remains due at 60%.

The audited milestone adds **234 unique C bytes**, taking verified readable
C to **259,922 / 434,656 (59.80%)**, with **1,374 bindings**. The gaps are
**872 bytes to 60%** and **22,605 bytes to 65%**. The prior complete
geometry percentage chain and zero-credit wrapping seal remain historical
evidence, pinned explicitly rather than rerun against changed sources.
