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
