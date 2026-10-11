# Counted-vector aggregation frame: qualified C

Readable `src/fight/aggregate_frame.c` implements original uncached callable
`0x0c0a6dba` and frozen owner `0x8c0a6dc0`. The complete owner contributes
**518 marginal bytes**. Its six-byte R14/R13/FR15 save prefix contributes
no extra credit. The existing qualified vector-sum helper contributes no
additional bytes in this milestone.

The frame invokes vector aggregation with six stack/register output pointers,
adds the configuration's six bias values, updates triples at `+80` and `+92`,
and integrates the triple at `+64`. Zero, tiny and ordinary vector norms
select the original matrix-update paths. The nonzero path normalizes its
vector, uses the scale scalar at `+160`, adds signed angle deltas with
16-bit storage wraparound, invokes the original rotation helpers, and writes
the resulting matrix while preserving the separately integrated position.
The original matrix stack and callee GPR/FR/XF state are restored on return.

Final development uses original states 21/26 and passes **128/128 cases**.
Fresh independent acceptance uses changed finite values, relocated owned
objects, alternate floating banks and original states 28/29. It passes
**127/127 valid cases**, retaining and excluding one interruption. Both
campaigns cover every owner instruction and include zero/tiny/ordinary
norms, signed angles, and positive/negative angle-delta wraparound. Native
comparisons cover the full architecture, RAM and return state, without skips.

The final executable `vf3matrixfamily_aggregate_frame_dev_v1.exe` and all
**376 compiled dependencies** were frozen before acceptance. Preliminary
v1 zero-angle campaigns also pass 128/128 development and 127/127 valid
acceptance cases; these remain supplementary evidence. The final proof
uses `coverage_65_aggregate_frame_{dev,accept}_v2`. The C implementation
remained unchanged during the input expansion and fresh holdout capture.

The real caller loads the original literal at `0x0c0a0d88` from
`0x8c0a0cf8`, sets R5 from R10, invokes JSR at `0x8c0a0cfc`, and sets R4
from R14 in the delay slot. Eight original windows in states 28/29 qualify
that exact sequence, loaded target, save prefix, saved stack values and
actual RTS with R14 restoration in its delay slot. They return to
`0x8c0a0d00`. This proves the caller boundary, not the complete parent at
`0x8c0a0b00`, and does not qualify a cached callee entry.

The narrow contract is `vf3-aggregate-frame-literal-jsr-v1`. Seven mutation
tests reject forged literal targets, call/setup signatures, missing or
reordered saves/restores, changed saved architecture, corrupted stack saves
and incorrect returns. All **158 tool tests** and **39 native suites** pass.
The only observed/static affected binding also passes; no opcode ledgers
are missing. The unchanged original observer and its 102-file source
archive capture the original windows. Background AICA events do not prove
a live C/audio comparison.

Seal: `tools/oracle/aggregate_frame_v1_manifest.json`. Evidence includes
`extract/analysis/aggregate_frame_v1_final_audit.log`,
`aggregate_frame_v1_affected_portcheck.log`, the v2 native reports and the
pinned original caller manifest in cache `aggregate_frame_original_caller_v1`.
The seal pins the preceding wrapper/arena chain and full 60% checkpoint.

Verified C is **261,970 / 434,656 (60.27%)**. **20,557 bytes remain to
65%**. The denominator and original inventory are unchanged.

An adjacent fresh pilot at callable `0x8c0a6482` independently passes
128/128 cases and executes its complete 308-byte owner `0x8c0a6494`.
That owner and its 58-byte helper were already credited, so the pilot adds
**zero bytes** and has no new percentage milestone. Its native comparison
against the preceding wrapper executable is retained as regression evidence
in `point_response_v1_current_native_report.json`.
