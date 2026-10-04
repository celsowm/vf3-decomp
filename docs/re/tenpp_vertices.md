# Vertex packing toward the ten-point C milestone

The first accepted vertex batch adds **8 frozen functions and 4,004 unique
C bytes**. Together with the initializer milestone, the address union is
**185,096 / 434,656 bytes (42.58%)**, up **5.20 percentage points** from the
frozen 162,490-byte starting union. The ten-point target remains open.

## Behavior

The packers consume a descriptor containing vertex pointers, copy position
words into the shared output buffer, and pack color components through
floating point multiplication and integer conversion. The output index is
an explicit scalar argument. Static control flow and shared C helpers are in
`src/fight/tenpp_complex_adapters.c`; unknown code still fails closed.

`tools/oracle/pointer_seeds.py` tracks descriptor pointers passed through
stack locals. `tenpp_probe_plan.py` supplies bounded nested pages, varied
finite coordinates and output indices 0–7. The floating point contract uses
single-width transfers (`FPSCR=0x40001`). Exploratory captures with inherited
double-width transfers exposed out-of-range conversion differences and are
excluded from these bindings.

The RAM accessor now folds all four 16 MiB mirrors of area 3 onto the captured
RAM pages. This matches the interpreter's `IsOnRam` predicate and RAM mask;
addresses in the mirrors had previously been misclassified as devices.

## Evidence

Development: `tenpp_pack_fp2_cases`, two saved states, with at least 64
distinct complete inputs for each promoted entry. Every credited body has
100% execution of its frozen instruction ranges and strict register, extended
state, device tape and RAM replay. Independent acceptance uses relocated
descriptors, another trigger and saved states 35/41 in
`tenpp_pack_fp2_held_cases`. Invalid specimens remain rejected in the capsule
manifest. Three further packers passed replay but lacked a second development
scenario and are explicitly excluded from this milestone.

`tools/oracle/tenpp_pack_milestone.json` records source bindings, artifact
hashes, exact body credit and exclusions. It retains the frozen baseline's
off-inventory C leaves when calculating the union.

Headless capture shutdown now stops and joins guest execution before process
exit and capsule finalization. This avoids GUI teardown hangs after the frame
budget. Timed-out or incomplete runs receive no acceptance credit;
`successful_runs.py` records their exclusion when exporting successful runs
from a mixed survey.
