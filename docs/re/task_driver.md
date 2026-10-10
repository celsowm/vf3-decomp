# Resource task driver

The readable C entry at `0x8c04bd62` is in `src/fight/task_driver.c`.
The file-subsystem wrapper at `0x8c053d7c` tail-calls it with the context
registered at `0x0c1b9608`. These resource workers execute through the
uncached `0x0c` alias, although the capture inventory uses `0x8c` keys.
Interior entries continue to use the existing adapters.

The driver publishes its context at `0x0c1b2088`, remembers the previous
context at `0x0c1b208c`, saves a continuation at context +4, and walks
188-byte records starting at context +0x140. It publishes the current record
at context +0x18c0. Record status at +12 selects:

| Status | Behavior |
| --- | --- |
| 0 | Skip an inactive record. |
| 1 | Wait while the unsigned deadline at +20 exceeds context +0x134; otherwise restore the continuation at record +24. |
| 2 | Set status 3 and install the actual retirement continuation `0x0c04bc52` at +32. |
| 3 | Call the original cleanup helper `0x0c04bbc6`, which can tail-call the record's callback at +0xb0. |
| Other | Skip the record. |

The signed loop limit comes from context +0x138. An ordinary completion
increments context +0x134, restores the previous context, restores FPSCR
and the saved registers, and returns to the original caller.

A continuation restore is not an ordinary helper return. The two natural
driver captures from save 21 resume the real job at `0x0c04bd4a`, whose
return reaches `0x0c053858`. C dispatches the restored continuation rather
than applying the driver's epilogue to the job's stack. The previous failed
object probes supplied a context record without this stack relationship.

Loading FPSCR also switches the active FR/XF register banks when bit 21
changes. The original wrapper captures exposed a pre-existing adapter bug:
the previous implementation matches four of eight cases, failing the four
that enter with FPSCR `0x240001`. The readable implementation handles the
bank exchange on both entry and ordinary return and matches all eight.
Fresh wrapper holdouts explicitly exercise both banks on saves 28 and 29,
with relocated context/stack and different saved-register sentinels.

The final executable is the immutable `vf3matrixfamily_task_driver_dev_v7.exe`
with the matching `task_driver_dev_v7_complete_v2_sources` archive, including
C, headers and `.inc` dependencies, including the replay harness. Acceptance was recaptured after this
complete dependency freeze. Development uses
saves 21 and 26; acceptance was recaptured after that source freeze on saves
28 and 29. Each campaign supplies 128 distinct complete original cases and
passes strict native replay without skipped cases. The two natural resumes
and 16 initial pilots also pass. The owned normal-return fixtures exercise
inactive records, future deadlines, retirement, empty cleanup callbacks,
signed loop limits and ticks near `UINT32_MAX`. They do not invent a job error result
or replace the original context-save/restore helpers.

The frozen owner `0x8c04bd7a` has 142 bytes. The original campaigns observe
138 bytes; the branch at `0x8c04bdee` and its delay instruction at
`0x8c04bdf0` remain unobserved. These are the ordinary-return path following
the continuation-restore call. No whole-body promotion is made, and verified
C coverage remains **259,110 / 434,656 bytes (59.61%)**. The wrapper itself
has no independent frozen inventory interval to credit.

`tools/oracle/task_driver_audit.py` seals the original image checks, compiled
source hashes, final native reports, wrapper contracts and repository replay
gate. Raw failed native versions and the interrupted intermediate replay
run are retained as diagnostics and excluded from the final proof.

The next object-family step must preserve a real registered job's saved
stack and entry arguments while observing its resource lookup/error path.
Having the active-context pointer alone does not supply that contract.

Subsequent object experiments establish a bounded first-yield contract, with
no additional coverage. `task_driver_object_yield_v3` enters the actual driver
and restores a constructed job at the original object BSR `0x0c04ff2e`.
Its task context (`0x0c420000`), descriptor (`0x0c404000`) and job stack
(`0x0c413fd0`) are separate. The object invokes the real file lookup, SDK
save and SDK restore. Both save/restore helpers execute twice, and the driver
resumes at `0x0c04bd94` before returning normally at `0x0c04be26`.
Development on saves 21/26 and fresh holdout version 6 on saves 28/29 each
pass **2/2 strict native cases**, comparing all captured registers and RAM.
These are constructed original callers, not observed natural job startup
or the independent whole-caller qualification needed to promote an object.

The native implementation keeps a host-only driver continuation scope.
After the real SDK helper restores guest registers and stack, `longjmp`
unwinds host adapter calls to that scope. The match uses both the restored
PC and SP, and the previous scope is restored on completion or failure.
The file-yield C entry retains the original deadline, context save and
restore operations. A restore hook also handles other adapters that reach
the same SDK helper. No helper return value or guest instruction is replaced.

Two observation bugs explain the intermediate failures. The one-shot
capture tool's `entry` directive selects the cached alias by default;
a separate `target` directive now preserves the requested alias. The first
object pilot actually reached driver resume and normal return, but the
recorder continued into firmware because its call-depth tracking missed the
stack restore. Explicitly stopping after the original driver's RTS fixes
that first-tick capture. Native version 5 likewise continued beyond the
restored driver return; version 7's host continuation scope fixes it.
Intermediate version 2 also overlapped the descriptor and task context;
that layout is excluded from the final proof.

The second-tick experiment seeds owned context and stack bytes from an
actual first-tick original capture. Four flag-zero captures stop at the
resumed job's RTS, `0x0c0537de`, rather than the requested driver return.
Their expected-exit checks fail, so they are excluded. The recorder currently
applies its automatic RTS-depth rule even when an explicit transfer boundary
is requested. The next step is to make explicit boundaries authoritative
in a new frozen recorder, then observe job completion/retirement and the
object's negative-return branch without fabricating a result. A save-27
interrupt specimen and the earlier closed-file/live-descriptor failures
are also retained as excluded diagnostics in
`task_driver_rejected_object_pilots_v1_manifest.json`.

The final version passes **1,368/1,368 repository bindings**, all **39 native
suites** and all **104 tool tests**. The seal pins every executable used by
the binding run, the complete 362-file source/dependency archive, original
capture logs/patches and native replay reports. The already completed
`task_driver_v5_chain_audit.json` is reused for the unchanged percentage
ledger; this milestone adds zero entries or bytes to that chain. The gap to
65% remains **23,417 verified bytes** (and 1,684 bytes to 60%).
