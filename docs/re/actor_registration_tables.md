# Actor resource registration callbacks

The original resource dispatcher loads the callback from an immutable 36-byte
record at `0x0c10def0 + 36 * index`. Its call window starts at `0x8c0a2f3c`;
the JSR at `0x8c0a2f40` passes the inherited descriptor in the delay slot.
Each callback saves R14, loads its object-field table from descriptor +16,
and registers a fixed list of command IDs and field pointers. The shared
`0x8c0a2e06` helper retains its real empty/sentinel/flag-dependent behavior.
The C implementations describe these lists as command/field data, without
interpreting SH-4 opcodes.

## Accepted first batch

| True entry | Frozen owner | Resource index | Marginal bytes |
|---|---|---|---|
| `0x8c0a3242` | `0x8c0a3246` | 11 | 408 |
| `0x8c0a3504` | `0x8c0a3508` | 24 | 370 |
| `0x8c0a38ae` | `0x8c0a38b2` | 13 | 144 |
| `0x8c0a3af2` | `0x8c0a3af6` | 1 | 314 |

The batch adds **1,236 unique bytes**, including the shared helper only once.
Accepted C address union becomes **277,814 / 434,656 = 63.9158%**;
the integer 65% threshold remains **282,527**, leaving **4,713 bytes**.
Development states 28/29 provided 2,040 distinct strict replay cases.
Independent acceptance states 45/46 provided 1,018, using changed payloads,
flags, owned-object addresses and the alternate floating bank. Every owner
covered its entire frozen body separately in each state, with at least 64
valid distinct inputs, original instructions/pools and zero device records.
IRQ-invalid samples remain in the raw captures and are excluded explicitly;
there are no incomplete invocations or nondeterministic entries.

Sixteen original caller windows prove all four callbacks in two states,
including their saves, real return and two original continuation instructions.
The immutable development executable passed all 1,418 existing bindings,
39 native suites and 417 oracle tests before holdout inputs were generated.
Its archive contains 407 compiler dependencies. The first acceptance attempt
in states 40/41 never hit the capture trigger and receives no acceptance
credit. No C correction was fitted to either acceptance campaign.

Proofs: `tools/oracle/actor_tables_v1_manifest.json`,
`actor_tables_qualification_v1.json`, `actor_tables_callable_v1.json`, and
`actor_tables_historical_v1.json`. Captures and compiler inputs are retained
under `D:/vf3-captures/coverage_65_actor_tables_dev_v1/` and
`coverage_65_actor_tables_accept_v2/`. Historical references preserve the
first tested source closure before subsequent normal-build changes.

## Accepted expanded batch

Eighteen additional immutable resource-table callbacks add 4,164 marginal
bytes. Their development campaigns in states 28/29 and independent acceptance
in states 45/46 cover every owner separately in each state. Their unchanged
readable C passes all 4,595 development and 4,597 acceptance cases with zero
skips. Seventy-two original
caller windows validate their fixed table slots, descriptor inputs and returns.
Two callbacks tail-call `0x8c095178`, which performs two actor-profile passes;
the current typed inputs exercise the ordinary actor type, while types 8/21
still depend on the unsupported downstream registration routine and fail
closed. These helper branches receive no new coverage credit.

The caller observer captures only RAM pages accessed by original instructions.
Resource row 7 crosses a page boundary: the validator proves its actual
descriptor/callback words at +24/+28, without claiming capture evidence for
the unused leading fields. The actor-profile tail legitimately reuses the
wrapper's popped save slots; the validator checks the resulting saved zero
argument and PR and the real wrapper save/restore sequence.

The 409-input normal-build archive passed all 1,422 existing bindings and
39 native suites before development qualification and holdout generation.
The 504 caller mutation checks also passed. Qualification and promotion are
`tools/oracle/actor_tables_expanded_qualification_v1.json` and
`actor_tables_expanded_v1_manifest.json`.
