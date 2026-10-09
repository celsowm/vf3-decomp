# Coverage campaign execution — 2026-10-08

Execution starts from the fixed **253,834 / 434,656-byte union (58.40%)**
at `ede49be`, following [the campaign plan](next_coverage_campaign.md).
The 65% objective remains open. Queue potential is not accepted coverage.

## Accepted checkpoint

| Tranche | Newly credited bodies | Union gain | Classification |
| --- | ---: | ---: | --- |
| Texture storage / size class | 2 | 236 | Readable C |
| Motion model-slot loop | 1 | 144 | Newly verified existing C |
| Weighted vertex emitters | 3 | 42 | Readable C, shared readable curve helper |
| Record pool callers | 19 | 1,194 | Static C adapters, one existing caller |
| Indexed vertex emitters | 9 | 522 | Static C adapters |
| Object-pool status caller | 1 | 260 | Newly verified existing C |
| Further object-pool callers | 2 | 308 | Static C adapters |
| Motion style wrapper | 1 | 18 | Readable C |
| Matrix-frame nested helper | 1 | 72 | Newly verified existing C |
| Fight-script damage command | 1 | 318 | Newly verified existing C |
| Fight-script style-scale clamp | 1 | 102 | Newly verified existing C |

This checkpoint is **257,050 bytes (59.14%)**, a gain of **3,216 bytes**
across 41 newly credited bodies. Of these bytes, 296 have new readable C,
896 verify existing C, and 2,024 use new static C adapters. The legacy
70-byte style selector also has a readable rewrite and stronger proof, with
zero additional credit. Remaining: 3,744 bytes to 60%, 14,610 to 62.5%,
and **25,477 to 65%**.
Readable model render-field helpers also pass original replay, but have no
separate frozen entries and earn no additional bytes. The curve helper has
the same limitation. All eleven tranches retain independent acceptance and
complete frozen-body checks in their `percentage_*_milestone.json` files.

The final integrated gate passes **all 1,357 current bindings** against
`vf3matrixfamily_next_models_v1_dev.exe`, SHA-256
`79dd7c7b77505a3a8439a7a3fb181433b91c01885930f0b1d1db8bb054df1d1f`.
The regular build executable has the same hash. This is the exact disjoint
union of a full **1,354 / 1,354** run frozen before the last three promotions
and a **3 / 3** delta run against that same executable. No C changed between
those runs. The scope check asserts every original binding is unchanged,
there is no overlap, and their union equals `tools/golden_bindings.json`.
Its hashes and source inventory are committed in
`tools/oracle/percentage_next_regression_scope.json`.

All **39 native checks** and **50 campaign/AICA tool tests** pass. The native
SH-4 FPU test includes 213,056 opcode cases. All twenty-seven milestone
metadata audits and the complete union chain pass. Artifact hashes passed
for the preceding twenty-four milestones; separate hash audits pass for the
matrix helper, damage command and scale command. The zero-credit legacy
selector quality manifest also passes its hash audit.

The first 1,322-binding run remains historical evidence; it predates the
record and indexed modules. A superseded intermediate 1,351-binding run was
stopped to free resources for the final gate, and is not claimed as passing.
Final logs and frozen inventories are under `extract/analysis/`:
`percentage_next_complete_integrated_regression.log`,
`percentage_next_complete_bindings.json`,
`percentage_next_final_delta_regression.log`, and
`percentage_next_final_delta_bindings.json`.

## Contracts, experiments and retained failures

* **Fight-script commands:** original opcode table `0x0c10f2e8` gives
  callable prefixes `0x8c0ae5a0` (damage, opcode 8) and `0x8c0ae9ec`
  (style scale, opcode 16). R4/R5 are fighter records; R6 is a VM record
  with a script pointer at +8. Signed scale changes clamp at 40. The damage
  body also owns shared dispatcher blocks, so a terminator alone reaches
  only 272/318 bytes. Follow it with original opcode 1 (flag toggle) and
  then a terminator to cover dispatch and its threshold comparison.
  Sixty-frame captures ended during the last invocation; fresh ninety-frame
  runs complete every observed call. Damage and scale each pass 256 strict
  development and 256 relocated independent acceptance inputs. The first
  damage acceptance missed the second statistics update; retain it and use
  a fresh varied counter/flag contract to cover that update.
  Neighboring `0x8c0af44e` and `0x8c0af610` have complete original captures
  but replay reports unsupported entry points: no implementation or credit yet.
  An early scale corpus continued into other unimplemented opcodes; preserve
  that failing replay and use a fresh bounded toggle/terminator script.

* **Matrix frame:** original prefix `0x8c08779c` establishes the register
  saves for frozen parent `0x8c0877ac`. Three adjacent 64-byte matrices
  and finite FR4/FR5 angles reach 276 of its 280 bytes. The missing path
  requires the unchanged squared magnitude to be both at least about 0.001
  and less than about 1e-7. Leave the parent uncredited; no dead-code
  exception. Nested helper `0x8c0875f0` covers all 72 frozen bytes in
  255 development and 255 independent relocated acceptance inputs,
  two states per corpus. Existing C passes both against the final executable.

* **Texture, `0x8c05f294`:** original callable prefix `0x8c05f28a`
  saves four registers and copies R4 into R11. Probe that prefix; observe
  the frozen entry naturally. Descriptor words +12/+16 are dimensions;
  bit zero at +24 enables mip levels. Dimensions 1..1024 and the fallback
  class input 3 exercise both complete bodies, including `0x8c05f0b8`.
  Development has 501 complete inputs, acceptance 435, each in two states.
  Outer observations that end at shutdown remain retained; the credited
  nested entries themselves have no incomplete invocations.
* **Geometry, `0x8c058a5c`:** explicit R14 input and R12 output buffers
  still produce zero complete calls (256 rollback rejections). This routine
  needs GBR/caller pipeline state, not just allocated objects. Parked; no credit.
* **Motion, `0x8c0951e4`:** invoke original `0x8c0951d2`, observe its
  frozen body after saved-register setup. Signed loop counts -1/0/15 and
  sixteen slots cover null, -1 sentinel and both nonnull model kinds.
  Development 256, acceptance 512; helper replay also passes. Descriptor
  chains terminate with a zero record. `model_render_fields.c` implements
  position/color RAM updates; these helpers do not submit hardware commands.
* **Weighted vertices:** all eleven original curve jump slots are backed by
  disassembly. The writable selector is at `0x0c058fdc`; no executable bytes
  are changed. The readable helper preserves float32 operation order.
  Corrected a reserved output word and a raw float bit-pack during development,
  then froze a new executable before capturing acceptance. Three callers have
  256 development and 511–512 acceptance inputs, each across two states.
* **Record pool:** recover original prefixes for all nineteen callers.
  R4 selects slots 0..7 in the 128-byte array at `0x0c1b20c0`. Vary free/busy
  status and supply valid 32-byte source buffers for copy paths. The third
  initial pilot failed its copy path until the pointer contract was supplied.
  All nineteen final bodies pass strict development and independent acceptance;
  acceptance changes indices, status values, source bytes and object locations.
* **Indexed vertices:** R8 points to packed short indices, R12 to output,
  and MACL carries the original vertex buffer pointer. The first three captures
  failed closed because the emulator parser did not support MACL. Retained
  under `percentage_indexed_vertex_dev`; stopped between roots. Add MACL/MACH
  input support to both generator and oracle, rebuild, and capture a fresh
  corpus. All nine callers have 256 development and 256 acceptance inputs.
  Acceptance changes both float palette and input/output locations. The static
  adapters use reviewed BRAF destinations from original disassembly.
* **Object pool, `0x8c04cece` family:** the first three pilots reach substantial
  bodies but initially qualify none. A specific status-table hypothesis for
  `0x8c04d516` closes its final six bytes in development (475 inputs):
  `0x0c1b3f18` controls a negative result from `0x8c04f050`. Independent
  acceptance passes with 503 inputs. The other twenty-two callers were then
  inspected through their recovered prefixes; only `0x8c04d72e` (172 bytes)
  and `0x8c04f0e2` (136) qualified. Add 154 statically translated statements
  with zero unsupported instructions, then freeze before acceptance. Both
  pass independent relocated acceptance (344 / 386 inputs). Other callers'
  incomplete bodies, short corpora and rollback failures remain uncredited.
* **Motion style wrapper:** invoke `0x8c095178` and observe frozen
  `0x8c09517a`, using original actor globals and sixteen-slot tables at
  `0x0c2a4d90` / `0x0c2a4b30`. Styles 0/8/21 exercise both arrays and no-op
  selection. New readable C passes 254 development and 393 acceptance inputs.
  The old `0x8c09518c` ledger row was already credited from a four-case partial
  proof, despite the planning text saying it was uncredited. Correct that
  description without changing the baseline. Replace its stale `unknown.c`
  source and weak binding with the readable implementation, 510 full development
  inputs and 512 independent full acceptance inputs. The quality manifest
  audits both proof archives and records **zero** byte gain. A standalone
  acceptance corpus with an incomplete final invocation is retained and excluded;
  the accepted nested corpus has no incomplete invocations.
* **`0x8c04453a`:** its apparent shared boundary enters diagnostic varargs
  formatting at `0x8c03b250`. Original callers also use a TAS lock and callbacks.
  Park pending a real formatting/stack contract; no generic recapture or credit.

Raw failed capsules and immutable replay executables remain under ignored
`extract/` and `build/`. Space after the current pilot work is approximately
16.4 GiB; retain the 4 GiB reserve. No ROM, capsule or build file is committed.

The intermediate rerank at 256,232 bytes has 43,090 advisory potential bytes
in one hundred families (`percentage_next_checkpoint_families.json`), but
does not qualify that pool. It excludes retained capture roots, including this
campaign's experiments. New leading contracts require entry/ownership recovery
and original runtime evidence. The 65% objective remains open; this checkpoint
does not claim completion of the campaign or of the audio enabling work.

## Audio scheduler investigation

The current journal remains deliberately limited to sound RAM and rejects
scheduler crossings. Source inspection confirms why RAM restore alone is
insufficient:

| State | Local emulator evidence |
| --- | --- |
| ARM7 registers, mode, IRQ/FIQ, clock and DSP | `aica_if.cpp: aica::serialize/deserialize` |
| AICA timers, registers, RTC and RAM | same serializer; rollback serialization skips RAM |
| Channel sample positions, ADPCM, envelopes, filters, LFO and noise | `sgc_if.cpp: serialize/deserialize` |
| Audio/CDDA/MIDI progress | same SGC serializer |
| Scheduler reference time and device deadlines | `sh4_sched.cpp: sh4_sched_serialize/deserialize` |
| Timer/sample interrupts and audio mixing | `aica.cpp: AicaUpdate/timeStep` |

The AICA scheduler runs ARM7; timeStep advances timers and sample state and
updates ARM/SH4 interrupts. DMA also has its own scheduler entry. The general
save-state serializers provide an inventory, not proof of reversible execution
inside an active interpreter instruction or host audio callback. A candidate
enabling design is one original saved-state replay per input in a fresh process,
with a single invocation and process exit instead of pretending to restore all
device state. It still needs deterministic repetition, full ordered interaction
capture, negative controls and a C model before longer audio calls can qualify.
No scheduler-crossing restriction is relaxed and `0x8c040fa4` remains uncredited.

The next execution order is recorded in [coverage_after_5914_plan.md](coverage_after_5914_plan.md), starting from this accepted checkpoint.
