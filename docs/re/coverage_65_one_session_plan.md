# One-session execution plan for 65% verified C

Baseline: pushed commit `5e9dd1c`, **267,230 / 434,656 bytes (61.48%)**.
The objective remains **282,527 bytes or more**, requiring **15,297 new
verified bytes**. Execute this plan as one continuous working session,
including checkpoint gates, commits and pushes. A session-length deadline
is not established, and qualification yield cannot be guaranteed in advance.

## Measured work budget

The current frozen body inventory and accepted address union produce this
advisory pool. Owner ranges are disjoint in this selection; their marginal
bytes were recomputed against the current ledger, rather than reused from
older rankings. These are unqualified research candidates.

| Pool | Remaining candidate bytes | Role |
| --- | ---: | --- |
| Adjacent replay/motion | 458 | Short opening work; reuse the new descriptor-callback contract |
| Scene flow | 8,314 | Primary batch work using original scene/callback contexts |
| Actor/fight routines | 11,370 | Primary batch work using loaded actors and existing motion/geometry helpers |
| UI reserve | 6,758 | Replace primary candidates that fail caller, RAM or whole-body gates |
| Total | **26,900** | About 1.76 times the required gain |

Reaching the target requires qualification of about 57% of this pool's
bytes, or 76% of the 20,142-byte primary pool. This is a required yield,
not an observed acceptance rate. The [candidate CSV](coverage_65_one_session_queue.csv)
lists all 40 owners and their current marginal bytes. The reproducible
snapshot `tools/oracle/coverage_65_one_session_queue_v1.json` pins the
baseline, image, inventory, body ranges and binding ledger.

## 1. Establish a viable batch before implementation

Inspect the selected routines' original cached-address disassembly,
true callable prefixes, actual callers, dynamic destinations and nested
RAM/device dependencies. Reuse the proven descriptor dispatcher at
`0x8c09617c`/`0x8c096182`/`0x8c096184`, the scene dispatcher at
`0x8c0968d0`, and existing literal-JSR/BSR contracts where the original
instructions and target evidence actually fit. A ranked owner is not
necessarily the callable entry; derive and prove that entry independently.

Start with replay initializer `0x8c0a8370` and interpolation owner
`0x8c0a8f98`; the remaining replay restore owner `0x8c0a89c2` is a
conditional candidate because its SDK setup paths need additional context.
Then pilot a mix of scene owners `0x8c0991a2`, `0x8c0993e8`,
`0x8c098c70`, `0x8c0972d2` and the larger scene owners in the queue.
Prioritize a candidate after observing terminating original execution,
not merely because its static size is large.

Build an initial implementation batch offering at least 6,000 marginal
bytes across original RAM paths. Record the callable, proven caller,
missing instructions, blocking PC and dependency for every candidate.
If that batch is not viable, screen more primary/reserve candidates
before spending the session on tiny isolated promotions.

Do not reopen the known blocked playback owner `0x8c0a8aca`, unknown-caller
loader `0x8c0c7a88`, unreachable-branch rendering owners `0x8c0609b8`/
`0x8c0607a2`, or direct PVR/MMU SDK candidates without evidence addressing
their specific blockers. The UI reserve remains conditional on proving
its nested rendering behavior; its potential is not guaranteed RAM work.

## 2. Implement and qualify batches of 4,000-6,000 bytes

Use named C operations, field semantics and reusable helpers. Keep every
whole-owner gate and the frozen denominator. Do not generate a generic
opcode interpreter, waive dead instructions, stub unknown callbacks,
fabricate helper returns, or count SDK identification as C coverage.

For each batch:

1. Capture development with at least 64 distinct complete valid inputs
   per owner across two scenarios. Vary the original selectors, boundary
   values, flags, wrap cases and callback targets needed for every branch.
   An entire campaign with an incomplete invocation remains unqualified.
2. Implement the related C routines and real shared dependencies, then
   run strict development replay across all architectural state and RAM.
   Device effects require the established device comparison protocol;
   RAM command queues establish RAM behavior only.
3. Freeze the complete compiled sources and native executable once the
   whole batch passes development. Capture holdout in disjoint states with
   changed typed inputs and relocated writable objects. Any subsequent C
   correction requires another freeze and fresh holdout for that batch.
4. Require complete frozen-body execution separately in development and
   holdout, zero replay skips, original opcode/pool checks, exact caller
   proof and marginal address-union audit. Preserve every failed specimen
   and its explicit exclusion reason.
5. Run all observed/static affected bindings, 39 native suites, current
   tool tests, and batch evidence/hash audits. Commit and push the qualified
   batch and its ledger. Never report planned bytes as accepted bytes.

Use one source freeze and one native build per passing batch instead of
rebuilding all required targets for every small helper. Emulator campaigns
remain sequential; independent read-only checks may run concurrently.
Use `python tools/build_required.py --jobs 4`; archive only referenced
native binaries and keep the capture tool's 4 GiB disk reserve.

## 3. Pass the full 62.5% checkpoint

The next full-inventory checkpoint is **271,660 bytes**, requiring at
least **4,430** accepted bytes from this baseline. At the first batch that
crosses it, freeze the current full binding inventory and run every binding
against the current executable, all 39 native suites, all current tool
checks and the complete milestone hash chain. Record the actual count,
immutable executable and source freeze. Resolve failures before expanding
further; a previous full 60% gate does not validate changed C at 62.5%.

## 4. Close the remaining gap in the same session

After the checkpoint, **10,867 bytes** remain if coverage is exactly
271,660; recompute the actual gap if the passing batch overshoots it.
Continue scene and actor/fight batches, including larger owners
`0x8c09575c`, `0x8c09970a`, `0x8c097abc`, `0x8c08231c` and
`0x8c0831f8` when their whole-body pilots and callers are proven.
Use the reserve immediately when a primary candidate fails qualification.

Give a blocked candidate one new hypothesis and one targeted pilot per
triage pass. Move to another candidate when that hypothesis fails; revisit
only after new evidence resolves the named blocker. Measure the remaining
union after every promotion and expand the research pool if its still-viable
bytes cannot cover the gap. Keep working toward 65%, without replacing the
objective with completion of the selected queue or a smaller percentage.

## 5. Final completion audit and delivery

At **282,527 verified bytes or more**, freeze the final compiled sources,
executable and entire current binding inventory. Run the full binding gate,
all native suites, all tool tests and the complete milestone hash-chain audit.
Recheck every new owner's independent whole-body/caller/strict-replay proof,
excluded specimens, source freeze and original image identity. Inspect the
actual ledger and verify that the fixed-denominator union is at least 65%.

Commit and push the final accepted state; verify the remote HEAD and clean
worktree. Report the measured percentage, accepted byte gain, full-gate
results and proof artifacts. Mark the 65% goal complete only after that
audited state exists. If an external blocker prevents completion, retain
accurate progress and evidence instead of declaring the session finished.
