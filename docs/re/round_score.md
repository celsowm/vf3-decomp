# Round contact scoring

Callable `0x8c0a7be2`, frozen owner `0x8c0a7bec`, contributes **512 bytes**
of readable C in `src/fight/round_score.c`. The ten-byte save prefix has no
coverage credit. The frozen denominator remains 434,656 bytes.

The routine selects the active actor from the scene's player pointers and
checks scene and mode gates before scoring. Damage is normalized against
a capped 181-point actor scale. An optional contact identity lookup adds a
table bonus and increments the contact counter. The round path combines
remaining health, a perfect-health bonus, a time-derived bonus, participant
scaling, and round result bits. It clears the temporary score after adding
the round total, and always clears the opponent's pending damage word.
These field descriptions are inferred from the arithmetic and accesses;
the native oracle validates their behavior independently of the names.

The C model retains scratch-register results, T-bit updates, stack writes,
signed loads, division calls, and the original MACL/save/return contract.
Its only calls are to the existing integer division helper `0x8c042c20`.
It performs no device accesses in these captures.

## Verification

Development states 21/26 and final holdout states 28/29 each provide
**128/128 strict native matches, zero skips**, with every eligible owner
instruction executed. All 64 invocations complete in each state; there
are no rejected or interrupted specimens. The first holdout also matches
128/128 but misses `0x8c0a7da2`, the perfect-health bonus instruction. It
remains pinned without whole-body qualification. The corrected holdout
changes only typed input data, aligning its independently varied health
fields; the C and native executable are unchanged.

The immutable executable `round_score_dev_v1.exe` and its complete
381-file compiled-source archive precede both holdout captures. Eight
additional original-interpreter windows begin at the literal load
`0x8c0c04ce`, execute the stack load at `0x8c0c04d0`, the JSR at
`0x8c0c04d2`, and its `R4 = R13` delay slot. They return through the
routine's original RTS to `0x8c0c04d6`, preserving the saved registers,
stack, MACL, and floating-point state. These windows execute original
SH-4 instructions and grant no separate coverage credit. Background AICA
events in state 29 grant no C device coverage.

Seven attribution mutation tests reject modified call signatures,
literal targets, save prefixes, stack slots, architectural saves, and
return sequences. The affected binding, **39 native suites**, and
**200 tool tests** pass. Selection includes observed calls and the frozen
static caller owner `0x8c0c048c`; no opcode ledger is missing.

The milestone manifest is
`tools/oracle/percentage_round_score_v1_milestone.json`; the final seal is
`tools/oracle/round_score_v1_manifest.json`, produced by
`tools/oracle/round_score_audit.py`. They pin original-image provenance,
body coverage, caller evidence, immutable dependencies, the superseded
holdout, regression outputs, and the preceding percentage chain.

Verified readable C is **264,802 / 434,656 (60.92%)**. **17,725 bytes remain
to 65%**. The next full frozen-inventory gate remains required at 62.5%.
