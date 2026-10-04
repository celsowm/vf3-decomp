# Nested observations at synthetic rollback

The oracle previously left natural child observations active when a synthetic
parent aborted or reached its rollback boundary. Those children could append
restored game instructions and close at an unrelated return with flags zero.
For example, an `0x8c085a16` record entered with PR `0x0c08581a` but exited at
`0x0c034888`, with its final instructions in the fight task walker. Standalone
strict replay failed even though the synthetic parent replay passed.

`finish()` now retires all still-active descendants with flag 4 before restoring
the parent's RAM and CPU context. Such records are rejected by `capsules.py`.
Both natural and synthetic observations also flush touched cache pages before
their first snapshot and at completion, so nested calls see cached parent stores.
The unchanged original executable remains the authority for emitted opcodes.

Fresh development: `extract/analysis/advance_nested_clean_dev`, states 21/27,
360 frames, 256 seed variants. All twelve selected entries pass strict replay
against `build/vf3matrixfamily_advance_workers.exe`. The suspect helper has
116 valid cases, all passing, but only one development scenario; it is uncredited.
The old nested development corpus is retained for diagnosis and must not supply
new child coverage credit. Previously accepted probe-only parent captures do not
contain natural child observations.

`tools/oracle/inspect_capsule.py` provides reusable register, RAM, stack and final
instruction inspection. Independent fresh acceptance uses states 23/29,
relocated pointers and a holdout value palette. Capture completion, body execution,
distinct inputs, scenario provenance and strict replay remain separate gates.
