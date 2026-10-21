# Native invocation and device lifetime

`vf3_native_tick_run` invokes a translated function on caller-owned RAM. It
replaces PR with the configured stop address or return sentinel. It remains
a function-level execution API, not an arbitrary-PC CPU resume API. The
resource-task driver can own `setjmp`/`longjmp` continuations on the live C
stack; copying registers after returning does not preserve those frames.

## Persistent devices, scoped invocations

The native runtime is one non-thread-safe session. ASIC pending status,
Maple/DMA/render queues, AICA RAM/mailbox state, TMU time and the attached GD
drive persist across function calls. A nested interrupt commits these same
device effects. Its invocation-specific counters, stop addresses, hooks and
XF seed do not replace the interrupted invocation's configuration.

The GD writer uses the active invocation's RAM, or the last top-level RAM
image when a caller advances the drive between invocations. The caller must
keep that RAM and an attached drive alive until detachment/reset. Attaching a
drive saves its previous writer/context; detaching restores them if the
runtime still owns the installed writer. Reattaching the same object does
not replace that saved callback.

TA words append to one stream in execution order: parent prefix, nested
interrupt output, parent suffix. A top-level invocation starts a fresh
stream; a nested result views only the words its invocation produced.
Top-level result storage remains borrowed until the next top-level run or
reset. A nested view can be invalidated as its parent continues and grows
the allocation. Allocation failure sets `ta_failed`, makes the invocation
fail, and preserves the already collected prefix.

Diagnostic counters include nested invocations. PC, failed PC and output
registers still describe the invocation itself. Any failed descendant makes
its ancestors fail, even if the poll callback ignores its return value. This
includes budget exhaustion and unsupported execution without an unowned-call
counter. An OOB or unowned access also fails an invocation whose dispatcher
otherwise returns success.

`nested_failures` counts each failed descendant invocation once, including
intermediate invocations that failed because of their children. The first
observed descendant failure is retained as `first_nested_entry` and
`first_nested_failed_pc`; the latter can be zero when the dispatcher did not
report a failing instruction. These fields never replace the parent's CPU
context. Failure diagnostics are scoped to the invocation and do not make a
later top-level call fail automatically.

Step counts include budget
refills and nested execution, exclude the failed zero-budget STEP attempt,
and saturate at `UINT_MAX`. They count the existing native step budget;
they are not instruction-accurate hardware cycle measurements.

## Session and import boundaries

`vf3_native_reset()` succeeds only outside an active invocation. It releases
TA storage, detaches borrowed GD/device-bus objects, forgets the caller RAM
binding, and clears device state, clocks, invocation configuration and XF
seed. It does not free caller RAM/disc objects or reset their own contents.
An attempt during execution returns 0 without changing the session. Reset
does not establish a Dreamcast BIOS/CPU handoff state.

`vf3_native_load_exit` only reads a comparison reference. It never changes
the next invocation's XF seed. `vf3_native_load_snapshot` imports XF only
after a complete entry/RAM load succeeds; failed loads leave the seed alone.

The optional caller-owned device bus reports handled, unhandled or error
for each delegated access. Unhandled accesses retain the existing built-in
device behavior. Errors set `device_errors` and `first_device_error`, are
included in the parent diagnostics, and fail the invocation. Bus attachment
changes are rejected while an invocation is active; reset detaches it.

## ROM-free regression

`tests/native_runtime_test.c` deliberately supplies a controlled dispatcher
double and links the real native runtime and GD model. Its operations are
unit-test scenarios, not captured console states or gameplay evidence.

It verifies nested ASIC acknowledgement/raising; persistent Maple, DMA,
render, AICA and TMU effects; TA ordering through buffer growth; nested and
top-level counters; hook/configuration restoration; step-budget refill
accounting; nested missing-code diagnostics; device-bus delegation,
pass-through, errors and detachment; rejected in-flight reset; fresh-session
reset; borrowed GD callback restoration; and transactional XF capture reads.
The generated capture-format fixture is synthetic and removed after use.

Standalone build and run, from the repository root:

```sh
cc -std=c99 -Wall -Wextra -Werror -Isrc \
  tests/native_runtime_test.c src/fight/native_tick.c \
  src/sys/gdrom_hle.c src/sys/bios_syscall.c -o build/vf3nativeruntime
build/vf3nativeruntime build/native-runtime-fixture
```

The test also passes with AddressSanitizer and UndefinedBehaviorSanitizer.
`tests/native_gdrom_test.c` remains the separate real-adapter GD regression;
these lifecycle tests do not replace captured whole-tick comparisons.
