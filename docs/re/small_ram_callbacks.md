# Small RAM callbacks for the 65% checkpoint

Four original callbacks add 556 marginal frozen bytes:

| True entry | Frozen owner | Behavior | Bytes |
|---|---|---|---|
| `0x8c0885c4` | `0x8c0885d8` | Motion settling, damping, angle and counter update | 294 |
| `0x8c07b6f4` | same | Command retirement with the high retirement flag | 40 |
| `0x8c08c054` | same | Event admission predicate | 124 |
| `0x8c0860c2` | `0x8c0860c6` | Clear and initialize a size profile | 98 |

Development in states 28/29 contains 2,023 distinct strict replay cases, with
zero skips. Each state's owner-body coverage is checked independently. The
retirement helper executes its original 120-record RAM scan; the motion
helper executes the original flat-floor fallback. Neither helper's result
is fabricated. The initializer's memory-clear dependency executes all 3,072
stores and preserves its pointer, count and condition bit.

Sixteen original caller windows establish the motion object's packed fields
and three actual pushed stack arguments, the retirement literal JSR, the
admission BSR and component row 10's immutable initializer callback. The
component loader executes its original index multiplication, table load,
phase selection, JSR and object argument. Caller mutation checks reject 112
altered specimens; the originals remain unchanged.

The initializer explicitly zero-extends unsigned selector bytes before its
table lookup. Inputs exercise byte boundaries through 255 without changing
the original table; all indexed reads remain inside the retail image. These
are selector-boundary tests, not evidence of natural gameplay character IDs.
Restricting the first pilot to values 0..25 missed the original negative clamp,
so that pilot received no credit.

A separate attempted resource-copy candidate `0x8c05e9b4` was rejected: its
argument denotes a VRAM offset, not a RAM pointer. The original helper adds
`0xa4000000`, producing non-RAM access for the attempted RAM fixture. Its
invalid specimens and incomplete valid-body union remain diagnostic only.
The interrupted scene-retirement pilot and unused float-widen leaf also
receive no credit.

Independent acceptance in states 45/46 passes all 2,020 strict cases with zero
skips. Both campaigns cover each owner's whole frozen body separately in each
state, with at least 64 distinct valid inputs and no device records. The 28
IRQ-invalid acceptance specimens remain excluded; no invocations are incomplete
and no entries are nondeterministic. Holdout generation followed the complete
1,422-binding and 39-native-suite gate and formal development qualification.
No C changes followed that freeze.

Qualification and promotion are
`tools/oracle/small_ram_qualification_v1.json` and
`small_ram_v1_manifest.json`. Captures, caller windows and the 409-input source
archive are under `D:/vf3-captures/coverage_65_small_ram_dev_v1/`;
acceptance is under `coverage_65_small_ram_accept_v1/`.
