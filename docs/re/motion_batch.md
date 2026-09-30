# Motion, task and callback batch

Starting verified C union: **48,220 bytes** of the frozen **434,656-byte**
baseline. Target gain: **20,000 unique bytes**; minimum delivery: **15,000**.
Candidate sizes and generated statements receive no coverage credit.

## Delivered coverage (2026-09-30)

| Measure | Before | After | Gain |
|---|---:|---:|---:|
| Verified C address union | 48,220 B | **69,300 B** | **21,080 B** |
| C union / frozen denominator | 11.09% | **15.94%** | 4.85 percentage points |
| Ported baseline entries | 116 | **172** | 56 |
| C + SDK accounted entries | 383 | **438** | 55 |

The gain exceeds the 20,000-byte target by 1,080 bytes. Newly credited bodies
sum to 21,080 bytes with no incremental overlap. Historical C bodies still
contain 772 overlapping bytes. A newly ported 602-byte body was already SDK
fragment attributed, so combined C+SDK accounting gains 20,478 bytes and one
fewer function than the C-port count. Combined accounting is now
**111,512 / 434,656 bytes (25.7%)**; trace observations are excluded.

The 57 strict bindings pass **28,501 distinct complete cases**: 56 new baseline
ports and one off-baseline helper registration (`0x8C039F50`) with no extra
byte credit. Each binding has at least 64 cases in at least two distinct
state/input scenarios, with full registers, XF/FPUL/GBR, exact return PC and
touched RAM, zero skips and zero out-of-bounds accesses.

The combined release replay passes 58/63 sufficiently sampled roots. One
passing entry has an unfinished invocation and is withheld. Fresh acceptance
passes 80/96 discovered entries, with **no failures among the selected release
ports**. Two selected ports (`0x8C06E536`, `0x8C0CB008`) are absent from the fresh
acceptance states; their earlier independent complete cases pass in full.
Other discovery failures are uncredited.

The motion-record initializer also passes 51/51 combined helper cases, in
addition to caller replays. Its standalone sample count is below the promotion
threshold; it receives no standalone binding or byte credit.

## Capture and evidence

Sixteen new runs take 795.931 seconds and produce 9,337,870,776 capsule bytes.
These totals exclude conversion, implementation and replay time. The release
and acceptance evidence uses 29 runs, including 13 reused fight-campaign runs.
All processes exit successfully. Shutdown summaries account for **101,105
started invocations: 101,083 completed and 22 unfinished**. Selected entries
with unfinished invocations in either corpus are excluded. Invalid specimens
remain recorded, including interrupt/device/overflow/asynchronous-copy flags.

Evidence is frozen in `tools/oracle/motion_batch.json`; raw capsules and replay
artifacts remain ignored under `extract/analysis/`. Final reports are
`motion_release_replay.json` and `motion_acceptance_replay.json`. Earlier replay
reports made before the anchor correction are not acceptance evidence.

The final complete verification gate passes: every historical and new bound
port, 212,992 isolated arithmetic cases, all three batch audits, SDK union
evidence and refreshed dependency planning. Corpus SHA-256 audit and exact
source regeneration also pass. The successful gate log is
`extract/analysis/motion_verify_parallel.log`.

```powershell
python tools/oracle/audit_matrix_batch.py --manifest tools/oracle/motion_batch.json --hashes
python tools/verify_all.py --no-build --jobs 4
```

## Remaining exclusions

`0x8C0352DA` and its caller `0x8C09635A` require foreign installed code.
`0x8C072B50` still reaches unsupported context restoration. `0x8C08B448` and
`0x8C0A99AA` have missing dynamic destinations. `0x8C06F3C2` has an unfinished
invocation. The device-dependent large worker `0x8C0750BE` remains uncredited.
Other insufficiently sampled or failed discovery entries are not promoted.

Previously blocked callers `0x8C08BB26`, `0x8C0926CC`, `0x8C0927FA`,
`0x8C0CB9F0` and `0x8C0CBB6A` now pass all combined cases. Shared algorithms
are readable C; callers retain the accepted static per-PC adapter form and
still need high-level restructuring. Evidence establishes interpreter agreement
for recorded scenarios, not all possible inputs or hardware accuracy.

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
shutdown counts and rejected specimens. Nine capture-integrity checks and seven
planning/opcode/ownership/parallel-binding checks pass. Both discovery replay
and the complete verification gate can run four independent bound replay
processes, with unchanged strict checks and a fixed executable throughout.

Five unsupported original instructions remain: two TRAPA instructions and
three banked-register instructions. Foreign installed code remains excluded.
Complete replay and byte audits determine the final selected entries.
