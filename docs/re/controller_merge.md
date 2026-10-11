# Controller packet merge (2026-10-10)

Readable C in `src/fight/controller_merge.c` implements full callable
`0x8c09af6c`, frozen owner `0x8c09af72`. It reads the actual packet lookup
at `0x0c0a1282`, selects packet zero, packet one, or their bitwise OR using
the selector at `0x0c29bccc`, and publishes the result at shared state +0x1ec.
The SDK lookup retains its real semantics. The original three nonvolatile
register saves, PR/local stack layout, condition flag and return are preserved.

Development and acceptance each pass **128/128 distinct complete cases**,
zero skips, and execute all **78 frozen bytes**. Development uses saves
21/26; acceptance uses saves 28/29 after freezing the native executable and
all 363 source/header/build dependencies. Acceptance changes selector and
packet values, relocates the writable stack by 0x100000, and uses the other
FPU register bank. The packet globals stay at their original literal-loaded
addresses. All original calls complete, both runs in each batch finish 180
frames, and no raw specimens are rejected or quarantined.

Eight fresh original observations establish BSR sites `0x0c09b92a` and
`0x0c09b988`, their NOP delay slots, the ordered R14/R13/R12/PR saves,
unchanged literal pools and balanced full callee return. These observations
start at each BSR and end after the callee's RTS/delay slot; they do not claim
complete parent execution. The nearby `0x0c09b924` entry tails into
`0x0c09b978` and is not an ordinary-return wrapper. Six mutation tests reject
altered call targets/delays, missing saves/restores, register/SP/return
corruption and modified literal pools.

The promotion and archive audit add **78 marginal verified bytes**:
**259,110 -> 259,188 / 434,656 (59.63%)**, with **1,369 bindings**.
The gap is **1,606 bytes to 60%** and **23,339 bytes to 65%**. The final
goal is 282,527 bytes; it remains unmet. The initial metadata draft inherited
an obsolete 205,956-byte campaign target. It was withdrawn before sealing,
its sole ledger addition/binding were restored, and promotion reran against
the correct target. The draft and its audit remain explicit diagnostics;
the C, executable, development and acceptance evidence did not change.

Current validation passes all **19 affected bindings**, including observed
reverse dependencies and static target/small-tail module bindings, all **39
native suites**, and all **110 tool checks**. The preceding task-completion
checkpoint's 1,368-binding full repository gate is historical and is not
described as a full gate for this changed C. The previous complete percentage
chain ending at 259,110 bytes is reused explicitly, followed by a fresh hashed
78-byte extension. The seal is `tools/oracle/controller_merge_v1_manifest.json`;
the accepted milestone is `percentage_controller_merge_v2_milestone.json`.
