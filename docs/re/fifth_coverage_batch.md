# Fifth C coverage campaign

Starting verified C union: **89,720 / 434,656 bytes (20.64%)**.
The campaign target is +20,000 unique bytes; only complete invocation replay
can establish the delivered gain.

## Discovery

The combined survey contains 43 complete scenarios and exposes 86,334 new
candidate bytes. State 32 is rejected because it exits after three frames.
The 25 additional saved states and three boot/menu scenarios did not expose
a sufficiently large frequently executed pool to guarantee the target.
75 roots have at least 64 observed hits across two scenarios. Hits guide
capture selection and provide no implementation credit.

## Banked register support

VF3CAP6 adds the eight inactive SH-4 integer registers to the before/after
state. The converter includes them in specimen fingerprints and emits a
`.bank.bin` sidecar. Replay compares all eight outputs. VF3CAP3/4/5 remain
readable; their absent bank state is unknown and bank instructions fail closed.
The source translator now implements STC, STC.L, LDC and LDC.L bank operands.
Existing adapters that previously rejected these instructions use the same
semantics. Device tape diagnostics report the first differing access.

## Verification boundaries

Development uses states 6 and 22 with the grapple schedule, plus states
7, 9, 11, 24, 25, 26, 28, 30, 33 and 37 with strikes. Additional development
scenarios and independent acceptance are recorded in the final manifest.
Each promoted body needs 64 distinct complete cases in two development
scenarios, successful held-out and fresh replay, no unfinished invocations,
no skips and no out-of-bounds accesses. Calls into uncaptured BIOS code and
any failing observed invocation prevent promotion. Interrupt-invalidated
specimens remain accounted for in capsule manifests and receive no proof.

Generated adapters are static C control flow from the untouched identity
image. Development observations may add dynamic destinations; acceptance
captures never feed generation. The byte union uses frozen body intervals,
subtracting all existing C spans and overlaps.

## Expanded small-body cohort

The initial watch excluded bodies smaller than 96 bytes. A second watch
covers 921 unported, non-SDK-attributed baseline entries of 16–94 bytes,
totalling 47,864 raw candidate bytes. Capture precedes selection: development
uses state 40 with strikes and state 26 with grapples; held-out uses states
29 and 41 with strikes; fresh uses states 43 and 44 with grapples. The expanded
watch also retains the original 75 roots so the additional development
observations can complete their sample counts.

These acceptance state/input pairs are distinct from every development pair.
The audit checks that separation in addition to separate capsule file paths.
Passing individual routines may be promoted before the aggregate 20 KB
campaign target is reached; the manifest records the actual gain and whether
the target was met. The per-routine proof gates are unchanged.

The first expanded capture exposed a recorder slot leak: watched interrupt
handlers ending in RTE could remain active indefinitely. Their invalid records
are now retired after RTE and its delay slot. They remain flagged as invalid
and cannot produce proof. Sorted watched-PC lookup and cached transfer PCs
remove repeated linear scans from broad captures. The affected leaf campaign
is recaptured with this fix, in separate `fifth_leaf_*_v6_cases` directories.

## Verified tranche (2026-10-01)

Independent acceptance promotes **147 new baseline bodies**: 20 from the
original cohort and 127 from the small-body cohort. Their 24,766 distinct
bound invocation cases all match full registers, inactive integer banks,
XF/FPUL/GBR, return PC, touched RAM and ordered device accesses, with zero
skips and out-of-bounds accesses. The final evidence uses 40 distinct
capture runs. All observed failing acceptance cases disqualify their entry.

The frozen address union adds **10,040 bytes**, after removing 68 overlapping
bytes: **89,720 -> 99,760 / 434,656 bytes**, or **20.64% -> 22.95% verified C**.
The 20,000-byte campaign target is not met; `target_met` is false in the
manifest. The 5,432-byte worker remains uncredited: it has only 44 distinct
complete development inputs across 20 scenarios. Other excluded entries lack
independent acceptance, disagree on memory effects, or reach unsupported code.

`fifth_adapters*.c` and `fifth_leaf_adapters*.c` contain static original-image
C control flow and reuse the shared matrix, FPU, fight and motion algorithms.
Only development capsules feed translation; held-out and fresh capsules
provide acceptance. The translator filters input opcode files to the chosen
roots so unrelated capture entries cannot add code to an adapter.

`tools/oracle/fifth_batch.json` freezes the starting spans, exact case bindings,
all replay reports, acceptance groups and corpus hashes. Recheck it with:

```
python tools/oracle/audit_next_batch.py --manifest tools/oracle/fifth_batch.json --hashes
python tools/verify_all.py --no-build --jobs 4
```

The final C build, full `verify_all` gate and SHA-256 corpus audit pass.
Rigorous C plus SDK attribution is **141,158 bytes (32.5%)**; trace-only
observations remain outside that figure. All existing bindings also pass
regression replay with the new ownership routes.
