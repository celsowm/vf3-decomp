# Vector aggregation: full 60% checkpoint sealed

Readable `src/fight/vector_sum.c` implements callable `0x8c0a6ff8` and
frozen owner `0x8c0a700a`. The owner contributes 386 marginal bytes; the
18-byte integer/FR prefix contributes no extra credit. It sums the first
triple of each counted vector pair and their cross products, applies common
and per-axis weights, uses the original matrix helpers, and publishes six
float outputs. The caller provides a configuration, counted rows, and six
output pointers, four through the stack.

Empty input publishes the configuration's base position and zero cross
components. Nonempty input installs the configuration basis while retaining
the previous translation. The saved GPRs and FR12–15 are restored; XF basis
preservation would be an incorrect contract. The qualification explicitly
checks installed basis versus original configuration bytes and unchanged
translation, or unchanged XF for empty input.

Development passes **128/128**, independently exercising the full owner
with zero through three finite rows in states 21/26. Acceptance changes
rows, weights and base positions, relocates owned objects and caller stack
by `0x100000`, switches floating banks, and uses states 28/29. It passes
**127/127 valid cases**, retaining and excluding one interrupted specimen.
There are no native skips or quarantine. All 372 source dependencies and
`vf3matrixfamily_vector_sum_dev_v1.exe` were frozen before acceptance.

Eight original windows qualify the single real BSR at `0x8c0a6df2`, its
`mov.l @(40,r15),r4` delay slot, ordered R14/R13/R12/FR15–12/PR saves,
all saved stack slots, the real RTS with its R14-pop delay slot, and return
to `0x8c0a6df6`. They cover empty and one/two/three-row configurations in
two original states. This is one caller, not two fabricated caller edges,
and does not qualify the complete parent function.

The narrow attribution contract is `vf3-vector-sum-bsr-v1`. Seven new
mutation tests reject forged call/prefix signatures, missing saves or
restores, changed saved architecture, corrupted stack values, and incorrect
matrix basis or translation. All **151 current tool tests** pass, including
14 additional tests for the two following uncredited pilots. The observer and
its 102 linked dependencies remain the unchanged original interpreter.
Background AICA events in caller captures are not a live C/AICA comparison.

The audited body union is **260,996 / 434,656 (60.05%)**, with **1,378
bindings** and **21,531 bytes remaining to 65%**. The complete current
inventory and all **39 native suites** pass against the immutable native
executable and binding snapshot. The final audit validates the 372-file
compilation freeze, original development/acceptance and caller captures,
151 current tool tests, and the preceding polygon percentage chain.

Seal: `tools/oracle/vector_sum_v1_manifest.json`. Gate and audit evidence:
`extract/analysis/vector_sum_v1_full_portcheck.log` and
`extract/analysis/vector_sum_v1_final_audit.log`. This completes the 60%
checkpoint; the 65% objective remains active. Historical seals pin their
original compiled dependencies and are reused after later source changes.

The next original pilot at callable `0x8c0cb51e`,
owner `0x8c0cb532`, has 127 valid development specimens in states 21/26,
one retained interruption, and complete 258-byte owner execution. A C
candidate built outside the repository passes all 127 valid specimens;
its source, executable and base library are pinned in the external cache.
Eight original caller windows and seven mutation tests pass. It has no
acceptance campaign or coverage credit yet. Its actual BSR is
`0x8c0cb028`, with `mov r14,r4` in the delay slot; immutable selector bytes
8/28/48/52/76/104 feed the original signed division helper with divisor 4.
