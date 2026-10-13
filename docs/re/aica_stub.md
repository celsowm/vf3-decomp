# REIOS GD-ROM dependency investigation

## Current status (2026-10-13)

`0x8c09635a` is a naturally reached 616-byte candidate owner, but it is not a
qualified C model. The pinned original observer recorded 165 calls over nine
complete 14,400-frame development contexts (states 20–24 and 26–29). State 20
had no hit; all other screened states reached this entry. No other watched
pool owner was reached. The hashed audit is
[`coverage_65_pool_hits_nine_state_v1.json`](../../tools/oracle/coverage_65_pool_hits_nine_state_v1.json).

The narrow `GDROM_GET_DRV_STAT` adapter matches all **188/188** complete
natural captures in the expanded development corpus: state 25 contributes 73
cases, while states 26, 27, 28, 29, 40 and 41 contribute 14, 19, 16, 15, 25
and 26. The 73 new state-25 cases pass strict replay independently. The
combined seven-state PC union is still **140/616 body bytes**, with 70 unique
body PCs; state 25 adds no instructions. The strict replay report for the
earlier 115-case subset is
[`coverage_65_9635a_reios_dev_115_report.json`](../../tools/oracle/coverage_65_9635a_reios_dev_115_report.json).
The seven-state capture union is
[`coverage_65_9635a_reios_188_union.json`](../../extract/analysis/coverage_65_9635a_reios_188_union.json).
However, their instruction union remains **140/616 body bytes** across 230
executed PCs. The remaining paths include selector, global-state and device
branches, so the owner earns zero coverage credit until the complete body,
varied inputs, original callers and held-state checks are proven.

The v2 per-invocation REIOS trace shows one `GDROM_GET_DRV_STAT` call per
natural invocation (`r6=0`, `r7=4`). Every observed response is `r0=0`, status
`1` (`GD_STAT_PAUSE`) and disc type `128` (`GdRom`). The entry is the BIOS
service at normalized PC `0x0c001006`; the instruction `0x085b` is a trap, not
a copy loop. The adapter handles only this measured service contract. Its
source is [`vf3_aica_stub_adapter.c`](../../src/fight/vf3_aica_stub_adapter.c).

Two targeted branch probes were attempted. The first used eight broad variants
from state 26 and produced five invalid captures. The second preserved the
observed `r10=8` and global flag `0x10000000` while setting the two descriptor
slots needed to pass the first gate. It started 29 probes; none was valid, and
four reached the non-RAM TA FIFO at `0x80800000`. These probes add no replay
cases or body PCs. Their recipes are
[`coverage_65_9635a_probe_recipe_v1.json`](../../tools/oracle/coverage_65_9635a_probe_recipe_v1.json)
and
[`coverage_65_9635a_probe_recipe_v2.json`](../../tools/oracle/coverage_65_9635a_probe_recipe_v2.json).
Raw runs and probe accounting remain under the local temp trace directory;
the recipes and builder tests reproduce the patch inputs, not observer
outcomes.

The REIOS call log, per-invocation context report and probe artifacts live in
`extract/analysis/` or the configured local temp trace directory. The owner
remains at zero coverage credit; do not widen the adapter based on these
invalid probe paths.

## Historical adapter attempt

The earlier adapter revision treated PCs `0x0c001006–0x0c001014` as a
copy-and-jump sequence. It moved an unsupported-PC failure in the isolated
harness but did not establish correct behavior. The current narrow service
model supersedes that interpretation.

The unrelated failures at `0x8c04853a`, `0x8c048480`, `0x8c064246` and the
partial-fail entries remain separate investigations.
