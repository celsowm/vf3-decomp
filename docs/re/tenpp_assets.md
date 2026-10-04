# Initializer family toward the ten-point C milestone

The frozen starting C address union is 162,490 / 434,656 bytes (37.38%).
This family adds **25 functions and 18,602 unique bytes**, reaching
**181,092 bytes (41.66%), a gain of 4.28 percentage points**.
The requested ten-point milestone still requires 24,864 additional bytes.
SDK attribution and execution surveys contribute no C credit here.

## Implementation and evidence

`src/fight/tenpp_asset_adapters.c` implements the original initializers as
static C control flow and delegates shared resource-table helpers to their
existing C owners. The source translator checks all emitted instructions
against the untouched retail image and reports 9,301 statements with zero
unsupported instructions. Unknown destinations fail closed.

These functions did not execute in the ordinary saved-state campaigns.
`tools/oracle/asset_probe_plan.py` supplies their descriptor contract explicitly:
two resource lists at descriptor offsets +16/+20, valid resource pointers,
the resource's +4 selection flag, and zero/-1 resource-table sentinels.
Acceptance relocates the descriptor and lists, alternates two resources, and
adds nonempty table entries. No fixture RAM page is assumed to be unused.

Development uses states 21, 35 and 36, yielding 236–240 distinct complete
invocations per function and **5,960 strict bound replays**. An earlier
development run and independent acceptance captures also pass for every entry.
Every frozen body instruction executes in the development corpus. Replay
compares registers, inactive banks, XF, FPUL, GBR, return PC, all captured RAM,
and ordered device accesses; it permits no skipped cases or out-of-bounds access.
Interrupted specimens are retained as rejected evidence and earn no credit.

The promotion manifest is `tools/oracle/tenpp_assets_milestone.json`.
Its hashes, bindings, exact body intervals and union gain pass:

```
python tools/oracle/audit_matrix_batch.py --manifest tools/oracle/tenpp_assets_milestone.json --hashes
```

The emulator captures and generated fixtures remain local research artifacts.
The reproducible fixture generator and C implementations are source artifacts.

## Probe corrections

The original probe resumed after a substituted trigger, dropping that
instruction's effects. Rollback now restores the pre-trigger context and
replays the original instruction. Exception rollback cannot arm another probe
before that replay. A full target sample budget prevents further redirects.

Dirty operand cache lines are flushed before RAM snapshots. Rollback restores
the full RAM image, including bulk writes outside scalar memory hooks.
Synthetic device accesses are rejected before issuing them because their
effects cannot be restored from RAM. Naturally captured device behavior still
uses the existing access tape. Seed variants may rotate targets, and explicit
target variants preserve the requested execution address alias.

Exploratory corpora recorded before these corrections were excluded from
the promoted bindings. Further survey adapters and menu probes remain
uncredited until their own complete-state replay and body coverage gates pass.
