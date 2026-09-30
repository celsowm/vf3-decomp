# Fourth C coverage batch

Starting verified C address union: **69,300 / 434,656 bytes (15.94%)**.
Delivery target: **+25,000 unique C bytes**, or 94,300 total (21.70%).
Minimum delivery: **+20,000 bytes**, or 89,300 total (20.54%).
Only real baseline body intervals verified by complete invocation replay count.

## Discovery milestone

The old trace plan has 103 executed unported game entries and 26,606 unique
candidate bytes. It includes a 5,432-byte device-dependent worker and other
blocked or undersampled entries, so it cannot alone support the target.
There are 16 saved states unused by the earlier C batches: 1, 2, 3, 4, 5, 13,
15, 20, 21, 23, 27, 29, 31, 32, 34 and 38.

`VF3_HITS` counts every watched entry in the interpreter without capturing
registers or RAM. It writes a bounded CSV after a normal emulator shutdown.
`tools/oracle/survey_coverage.py` checks the batch exit codes and complete hit
rows, then computes an address union against the current verified C baseline.
Hit counts identify paths for complete capsule capture; they are never port
proof. The survey watch covers 918 unported, non-SDK-attributed baseline
entries of at least 96 bytes. Initial runs use the two recorded action
schedules for 1,800 frames per state. Alternate boot and mode paths follow if
the survey leaves the viable pool below 45–50 KB.

The first state reaches 93 unported entries and 31,016 unique candidate bytes.
Several of those bytes are in device-dependent or unsupported paths. The
remaining 15 states are surveyed before selecting expensive captures.

## Implementation and promotion gates

Choose complete invocation roots with a viable original-image call closure.
Development inputs alone may generate static caller adapters, reusing all three
existing adapter modules. Write shared algorithms in readable C and preserve
register, XF/FPUL/GBR, return-PC and touched-RAM effects. Unknown destinations
or processor state fail closed.

Promote an entry only after at least 64 distinct complete cases from at least
two state/input scenarios, held-out replay and fresh acceptance. All selected
cases must pass with zero skips and out-of-bounds accesses. Capture summaries
must account for unfinished invocations. SDK attribution and trace observations
remain separate from C credit. The final address-union audit uses the frozen
69,300-byte starting spans; the complete verification gate covers all older
bindings too.
