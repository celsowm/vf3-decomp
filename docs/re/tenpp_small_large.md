# Small bodies and larger field-driven functions

Two cohorts add **4,690 unique C bytes**: 23 small functions (2,200 bytes)
and four larger functions (2,490 bytes). The frozen C address union reaches
**194,524 / 434,656 (44.75%)**, a **7.370 percentage point** gain from
162,490 bytes. The ten-point target still requires **11,432 bytes**.

Every credited root executes 100% of its frozen body in development, with
at least 64 distinct complete inputs and two fresh source states. The small
cohort binds 2,883 development cases and passes all 734 independent acceptance
cases. The larger cohort binds 7,665 development cases and passes all 570
independent acceptance cases. Acceptance relocates fixture pointers, changes
the finite floating point palette and varies input fields independently.
Both milestone manifests pass their artifact hash audits:
`tools/oracle/tenpp_small_milestone.json` and
`tools/oracle/tenpp_large_milestone.json`.

The translator now snapshots the source operand before predecrement stores.
For `MOV.L Rn,@-Rn`, the interpreter stores the original register value
before updating the address register. The previous emitter stored the
decremented value. Existing generated occurrences are corrected as well.
The two newly credited functions affected by this error pass all 255
development cases after correction.

Typed fixture generation preserves inferred pointers and varies scalar,
narrow integer, flag, count and floating point fields using deterministic
seeds. Inputs are executed by the original interpreter; C does not supply
expected results. Partial bodies and incomplete captures receive no credit.
The larger C module is included by the existing adapter translation unit.
Previously owned roots are preserved when regenerating shared modules.

A full regression runs against an immutable executable snapshot so further
capture and compilation cannot replace its tested executable. Local output:
`extract/analysis/tenpp_store_regression.log`.
