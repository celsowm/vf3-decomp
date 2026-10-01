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
