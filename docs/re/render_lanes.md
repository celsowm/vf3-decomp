# Five-lane render commands (2026-10-11)

Callable `0x8c05d424`, frozen owner `0x8c05d436`, contributes **370
verified C bytes**. The 18-byte prefix receives no additional credit.
The readable port is `src/fight/render_lanes.c`.

The routine copies the original eight-word template at `0x0c0d2c34` to
the stack, then visits five lanes enabled by `0x0c16cee8`. Each enabled
lane checks the suppression flag at `0x0c16cdc4` and selector at
`0x0c16cea0`; selectors 32 through 36 suppress the corresponding lane.
Lanes one through four replace the first template word with
`0x81000000` through `0x84000000`. Each record supplies five destination
pointers in the 20-byte table at `0x0c16ca18`. The original signed-byte
record offset is retained. After replication, the corresponding status
word at `0x0c16ca74` becomes eight, including the zero-record path.

The existing original-copy adapters remain dependencies: `0x0c042efc`
copies the template and `0x0c062e7e` copies eight words to each destination.
Fixtures use owned RAM destinations and record counts zero through three.
This milestone grants no PVR or hardware coverage.

Development passes **128/128** strict native replays; independent holdout
passes **127/127**, with zero skips. Both execute all 370 frozen body
bytes. One interrupted holdout specimen is excluded and retained.
The unchanged executable and complete 384-file source freeze precede
holdout. The original observer contains no C replay implementation.

Eight original windows, across states 28 and 29, prove the BSR at
`0x8c05c75c`, its `R4=R11` delay slot, saved registers and stack slots,
untouched literal pools, restoration, and return to `0x8c05c760`.
Background AICA events receive no device coverage credit.

The affected-binding scan includes both real BSR sites (`0x8c05c75c`,
`0x8c05cfa6`) and their frozen parent owners. Neither parent is bound;
only the new root binding is affected, with no missing opcode ledgers.
That binding, **39 native suites**, and **221 tool tests** pass.
Seven mutation tests reject forged caller, save, pool and return evidence.

`tools/oracle/render_lanes_v1_manifest.json` seals the campaigns, strict
reports, original callers, source and executable freezes, regression
archives, inventory, denominator and previous settings-menu proof chain.
Verified C reaches **266,150 / 434,656 (61.23%)**; **16,377 bytes remain
to 65%**. The next full inventory gate remains required at 62.5%.
