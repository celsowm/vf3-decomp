# Scene contact initialization

Callable `0x8c0a07e4` initializes contact records for eighteen scene slots.
Its frozen inventory owner `0x8c0a07fa` contains 636 eligible bytes; the
22-byte register-save prefix receives no additional credit.

The initializer selects an actor using the scene selection byte and derives
its heading from either the selected actor or the other actor's two angle
fields. Each enabled descriptor supplies a scale. The routine copies the
corresponding output matrix, sets reciprocal dimensions and contact weights,
rotates the next velocity triple, generates three random angles and three
random deltas, clears six bias fields, and builds eight scaled box corners.
Actor records advance by `0x1d8` and velocity triples by twelve bytes only
for enabled slots; output matrices advance by 64 bytes for every slot.
The final transfer restores the saved registers and jumps to the matrix-pop
helper, which returns to the original caller.

`src/fight/contact_init.c` uses structured loops and the existing qualified
matrix, trigonometric, random and division helpers. It never decodes or
executes original opcodes. The qualification uses finite positive scales,
both actor choices, both heading paths, varied enable masks, signed angle
boundaries, relocated owned RAM, different random seeds and both FR banks
with single-width transfers. These fixtures establish the tested domain;
they do not establish exceptional floating-point behavior.

Development passes **125/125** valid original/native comparisons and fresh
holdout passes **127/127**, with zero skips and complete owner execution in
both campaigns. Three development interruptions and one holdout interruption
remain retained and excluded. The executable and all **379 compiled source
dependencies** were frozen before holdout.

Eight genuine caller windows from saved states 28 and 29 verify BSR
`0x8c0a1156`, its `R4=R14` delay slot, the complete save prefix, stack
contents, ordered restoration, matrix-pop tail transfer and actual return
to `0x8c0a115a`. An earlier caller campaign had one interruption during its
long all-eighteen-enabled case; that entire campaign is excluded from
attribution and pinned by `contact_init_v1_excluded_caller.json`.

Four affected bindings, all **39 native suites**, and **179 tool tests**
pass. The default build's 190 executables are archived. Fixed caller-proof
mutation tests reject missing instructions, forged signatures, corrupted
stack saves, changed saved architecture, changed literals and wrong returns.

`tools/oracle/contact_init_v1_manifest.json` seals the complete evidence and
the preceding scene-insertion percentage chain, including the full 60%
checkpoint. The gain is **636 bytes**, reaching **263,438 / 434,656
(60.61%)**. **19,089 bytes** remain to 65%; the next complete frozen
inventory gate is required at 62.5%.
