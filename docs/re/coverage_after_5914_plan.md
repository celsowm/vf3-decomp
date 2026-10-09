# Coverage expansion from 59.14% — 2026-10-08

## Baseline and objectives

Continue from `40e5213`: **257,050 / 434,656 unique bytes (59.14%)**,
1,357 passing bindings, 39 passing native checks and 50 passing tool tests.
The previous campaign added 3,216 bytes across 41 bodies. Those bytes are
already in this baseline and must not be counted again. Its evidence and
retained failures are in [the execution ledger](next_coverage_execution.md)
and [triage CSV](next_coverage_triage.csv).

| Checkpoint | Required union | Additional verified bytes |
| --- | ---: | ---: |
| 60% | 260,794 | 3,744 |
| 62.5% | 271,660 | 14,610 |
| 65% — objective | 282,527 | 25,477 |
| Existing stretch, about 67.23% | 292,220 | 35,170 |

These are objectives, not estimates of qualifying work. Readable semantic
implementations remain the port's goal. Report their bytes separately from
static adapters and verification of existing C; quality rewrites of credited
bodies earn no additional coverage.

## Refreshed opportunity

Regenerate `port_plan.py` against the current ledger. Rank families using the
existing frozen image/body inventory and credited interval union, excluding
**104 retained percentage progress files** and **29 nonaccepted triage entries**.
The resulting queue starts at exactly 257,050 bytes.

| Research pool | Advisory marginal union |
| --- | ---: |
| First 10 families | 3,592 |
| First 25 | 9,674 |
| First 50 | 19,650 |
| First 100 | 35,726 |
| First 150 | 48,648 |
| First 200 | 61,016 |

Only three families in the first hundred have no unresolved dynamic sites,
offering 312 marginal bytes. In all two hundred, seven offer 744 bytes.
Neither set is qualified just because its static boundaries are resolved.
The 65% objective would require accepting about 71% of the first hundred's
potential, or 42% of the expanded pool. A larger pool alone does not establish
that yield. Root exclusions also do not remove blocked dependencies from new
families: join each selected closure back to the triage ledger before work.

Artifacts under `extract/analysis/`:

* `percentage_after_5914_port_plan.csv`
* `percentage_after_5914_families.json` and its watch file; SHA-256
  `cedb50e1f8f91402f13805ad7b911f0cc3fb7058d30425236aaaa8bd14715e87`
* `percentage_after_5914_families_200.json` and its watch file; SHA-256
  `2d3822ec98e9dec479576247e4ab6dfbf3bd195729a6c061b2bac0d38ffabbcb`
* `percentage_after_5914_queue_provenance.json`, recording exclusions and
  the exact first-hundred generation command; the expanded run changes only
  the limit and output/watch filenames.

## Execution order

### 1. Implement the commands with complete original captures

Start with frozen `0x8c0af44e` (60 bytes, original prefix `0x8c0af448`)
and `0x8c0af610` (182 bytes, prefix `0x8c0af608`). Both have **256 distinct
complete original inputs across two development states**, full frozen bodies
and no incomplete invocations. Their replay currently fails at the unsupported
entry. Evidence is `percentage_script_siblings_dev_report.json` and
`percentage_script_siblings_proof_dev`; preserve the failed replay.

Implement readable script-field operations, not generic returns. R4/R5 are
fighter records; R6 is the VM record and +8 is the script cursor. Preserve the
prefix-defined scratch registers, signed byte/word rules, SHAD behavior,
division helper effects, stack/MACL saves and the real dispatcher tail.
For `0x8c0af610`, reuse the proven model selector and test its relevant style
and flag branches, minimum decrement and saturation at zero.

After strict development passes, freeze the executable and capture fresh
acceptance in two disjoint states with relocated objects and changed inputs.
**242 bytes are implementation-ready potential, not accepted credit.**

Then inspect opcode 32, `0x8c0af0f6` (124 bytes, prefix `0x8c0af0f2`),
and opcode 34, `0x8c0af38c` (188 bytes, prefix `0x8c0af37c`). The former
reaches the command-submission boundary below; the latter uses the existing
trigonometric helpers and finite fighter vectors. They have no qualified
development corpus yet. Map the original table at `0x0c10f2e8` to frozen
entries and actual callable prefixes before expanding to other opcodes.
Do not treat table entries without frozen bodies as extra coverage.

### 2. Recover the shared command-submission contract

Inspect `0x8c0c5d86` and its continuation `0x8c0c5dba` before expanding
helper family `0x8c0ca05c` (**492 advisory bytes, six members, two unresolved
sites**) and the opcode-32 caller. Original disassembly identifies:

* scene byte `0x0c29b86c` and a configuration gate;
* command-ID bounds 0..476 and immutable mapping at `0x0c1025f0`;
* current-generation value `0x0c1fd758` and deduplication table `0x0c2cfa00`;
* the real `0x8c040f1e` AICA command-pool allocator;
* `0x8c0ca05c` selecting an ID through actor byte +97 and `0x0c11331c`.

Recover a valid pool from original runtime observations and test gate,
deduplication, invalid-ID and actual allocation paths. Prefer a readable shared
implementation. A shorter RAM-only submission path does not validate the
scheduler-crossing audio routines. Keep the existing scheduler rejection.
Pilot the smallest real caller before the six-member family.

### 3. Expand object-pool callers through actual callback targets

Prioritize helper family `0x8c04fe9e`: **1,002 advisory bytes, twelve members,
eight unresolved sites**. It reuses the established 328-byte record array at
`0x0c1b34d8`, but adds a specific callback boundary: the table pointer at
`0x0c1b34d4`, target at +12, object field +36 and doubled R5 argument.

Extract that table and its real targets from natural calls in original states.
Implement the actual targets needed by the smallest caller subset. Never
substitute a fixture callback that just returns a desired value. Reuse the
proven slot/status contract only where disassembly confirms it applies.

Revisit parked `0x8c04cece` callers only when a named missing predicate or
callback has new evidence. For each, record the missing PCs, original branch,
required object field and the targeted pilot result. Do not repeat the generic
25-caller sweep. Recompute marginal union after every accepted subset.

### 4. Build larger motion-record families from valid assets

The next shared leads are `0x8c09d5ae` (**700 advisory bytes, five members,
nine unresolved sites**) and `0x8c09af6c` (**1,302, twelve, twenty-nine**).
The first reads a one-based actor field at +60, a global table base at
`0x0c29b9f8`, twelve-byte offset records and the VM pointer at actor +0x1d00.
Recover real records, packed-field lengths and indirect destinations from the
original image/runtime before constructing inputs. This is a new asset contract;
the previous model-slot loop is insufficient by itself.

Begin with one short, terminating record and one caller per helper. Implement
the shared decoder in readable C, preserving byte/bit ordering and state
publication. Expand record kinds and callers after the pilot passes. Treat
every unresolved target as work, not a closed edge. The ranking's byte values
are sequential marginal estimates; they are not independent allocations to add.

### 5. Recover original caller state where the queue stalls

After two families fail for missing context, stop synthetic-contract guessing.
First inspect existing natural-call capsules for usable inputs. If necessary,
add bounded passive entry recording with probes disabled: original prefix,
return PC, GPR/FR/MACL/GBR state, stack arguments, accessed object pages and
indirect destinations. Limit the first experiment to one family and 128 entries.
Use real front-to-fight/menu playback when the required scene is absent from
the existing fight states. Prove the observer leaves execution unchanged with
recording-disabled and recording-enabled controls.

Use this evidence to select larger closures from the expanded queue. Defer
`0x8c035920` despite its rank until its real callback is known. Diagnostic
family `0x8c04453a`, geometry `0x8c058a5c`, texture-transfer and scene-timeline
families require their recorded stack, GBR, transfer or callback contracts.
They are not automatic retries. Passive infrastructure itself earns zero bytes.

### 6. Keep the audio scheduler as a separate enabling experiment

Use the existing ARM7/DSP/timer/channel/DMA/scheduler inventory. Investigate a
fresh process per original state/input, one invocation, capture and exit,
rather than restoring only sound RAM after callbacks have advanced devices.
First establish whether the interpreter can safely finish and capture a
one-shot call across a scheduler event. Do not relax the rollback mode's guard.

Require three identical-run controls, a short known RAM-only control, and
negative controls changing input and relevant timer/ARM state. Observe full
relevant ARM7, DSP, timer, channel, interrupt and scheduler state, ordered
device interactions and audio output where applicable. A matching RAM journal
alone is insufficient. If this pilot cannot establish deterministic observation
and a viable C comparison, park it explicitly and continue the shared families.
`0x8c040fa4` stays uncredited until a real C body passes independent acceptance.

## Gates, reassessment and delivery

Use 64–128 variants in two development scenarios for a bounded contract pilot.
Expand only when it completes original calls and materially closes a named
body gap. Give a stalled contract one new hypothesis and one targeted pilot
per triage pass; retain failures and move on. Ninety-frame runs solved the
previous script shutdown truncation, but choose duration from completion
evidence, not by blindly lengthening every capture.

Every promotion still requires full frozen-body execution in both corpora,
at least 64 distinct complete inputs in each, two scenarios per corpus,
disjoint development/acceptance states, changed acceptance inputs and relocated
writable objects, an executable frozen before acceptance, strict architectural,
RAM and ordered-device replay, zero skips, artifact hashes and union audit.
Implementation corrections require fresh acceptance. Contradictory branches at
`0x8c0877ac`, `0x8c0853fe` and `0x8c0c15f8` get no dead-code exemption.

Commit accepted tranches with C, recipes, manifests, bindings and the ledger.
Run native checks and affected bindings, including known reverse dependencies,
per tranche. At 60%, 62.5%, and final delivery, run the entire current inventory
against the final executable plus the fifty tool tests and milestone-chain
audit. A prior executable's passing run cannot substitute for changed C.

At **60%**, reassess qualified opportunity for 65%. If most remaining gain is
still hypothetical, prioritize caller discovery and shared decoder/callback
work over expanding generic captures. At **62.5%**, reassess again before the
final 10,867 bytes to 65%. Pursue the 67.23% stretch only with further qualifying
families. Report accepted union, readable-C work, blockers and remaining bytes
at each checkpoint; planning and potential earn no credit.

Measured free space is **16.21 GiB** (17,404,387,328 bytes). Keep the 4 GiB
capture reserve, estimate expansion size from pilots and retain original failed
capsules. Never commit ROM, extract artifacts or build output.
