# Motion, task and callback batch

Starting verified C union: **48,220 bytes** of the frozen **434,656-byte**
baseline. Target gain: **20,000 unique bytes**; minimum delivery: **15,000**.
Candidate sizes and generated statements receive no coverage credit.

## Discovery and implementation

Watch complete invocations of unported game bodies of at least 128 bytes,
including bodies absent from earlier traces. Include original-image callbacks
from the tables at `0x8C0F7548` (16 entries) and `0x8C0F7588` (15 entries),
and missing helpers from the previous batch. No first-transfer exits are used.

Initial development captures use saved states 8, 28 and 40 with the two
existing action schedules. Additional scenarios are selected from actual
capture results. Held-out and fresh final scenarios stay separate from source
generation. Unsupported context switches and device-dependent specimens remain
excluded.

The source translator can reuse multiple existing adapter modules by source
glob. A watched root owns its complete original-image control flow even if
Ghidra gave it a fragmented seed. Other existing PCs dispatch to their current
owner. Ownership is selected before execution; failure never retries a module.

Promotion requires at least 64 distinct complete cases across two distinct
state/input scenarios, strict register/XF/FPUL/GBR/return-PC/RAM replay, no skips,
no out-of-bounds accesses, and no unfinished selected invocation. The byte
audit subtracts overlap against frozen starting spans. SDK attribution and
trace observations remain separate from verified C coverage.

## Implementation milestone

The development captures contain 102 distinct invocation entries. Generation
uses only states 8, 28, 40, 6, 16, 33 and 41, plus original-image callback
roots. The router and four bounded adapter sources contain 32,580 original
guest statements and regenerate byte-for-byte from those development corpora.
Existing matrix and fight adapters are reused.

`motion_helpers.c` implements the shared motion-record initializer at
`0x8C0CC2D6` as C: scale three deltas, add the anchor and set the packed record's
step counter. A held-out replay caught two reversed anchor addresses; the
correction passes all 30 held-out helper cases. Fresh states 14, 25 and 42
are captured after this correction. Earlier held-out states are 11, 26 and 39;
states 9, 22 and 36 provide additional independent evidence.

The combined release corpus also includes every earlier fight-campaign capture,
filtered for the new roots. Filtering preserves validation of all records,
shutdown counts and rejected specimens. Nine capture-integrity checks and six
planning/opcode/ownership checks pass. Independent replay processes can run
in parallel, with a fixed executable throughout each replay.

Five unsupported original instructions remain: two TRAPA instructions and
three banked-register instructions. Foreign installed code remains excluded.
Complete replay and byte audits determine the final selected entries.
