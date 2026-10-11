# Polygon intersection qualified (2026-10-11)

Readable `src/fight/polygon_hit.c` implements callable `0x8c06e056` and
frozen owner `0x8c06e066`. The locked owner has **308 bytes** in ranges
`[0x8c06e066,0x8c06e0aa)` and `[0x8c06e0b8,0x8c06e1a8)`.
The preceding 16-byte integer/FR save prefix earns no additional credit.

R4 supplies an actor whose `+0x3c4` points to a count followed by polygon
vertices. FR4–7 supply a segment's two endpoints. The function tests both
pairs of cross-product signs, accepts the first qualifying edge, solves
the intersection using the original arithmetic order, and calls the
existing angle helper `0x8c069624`. It publishes x through R7 and y,
indicator, and angle through three caller-stack pointers. On a miss it
retains the incoming indicator and angle, and publishes the first segment
endpoint. It does not report the polygon edge's index: the hit indicator is
one. Degenerate and edge-coincident arithmetic retains original behavior.

Development uses 64 finite segments against a closed four-edge polygon in
each original state 21/26, including crossing, outside and edge-coincident
examples. Acceptance changes the polygon extent, segment palette, incoming
indicator and angle, relocates owned actors/points/output/caller stack by
`0x100000`, switches the floating bank, and uses states 28/29. The explicit
caller stack is ordinary captured RAM; its three output pointers are input
fixtures, not forced helper answers.

Development passes **128/128**. Acceptance passes **127/127 valid cases**,
with one flag-1 interruption in state 28 retained and excluded. Each
campaign independently executes all **154 owner PCs / 308 bytes** and the
complete original save prefix. There are no native skips or quarantine.
The final native executable and **371 compilation files** were frozen
before acceptance; `polygon_hit_v1_manifest.json` pins their hashes.

The actual BSR sites `0x8c06dfb6` and `0x8c06e048` both load R4 from
`@(32,r15)` in their delay slot. Sixteen original one-shot windows cover
both sites, four finite cases, and states 28/29. The fixed attribution
validator checks original BSR targets and delay instructions, the ordered
R14/R13/FR15–12/PR saves, every saved stack value, restored architectural
state, actual RTS and its R14-pop delay slot, and return to each caller.
These windows prove caller edges, not complete parent functions.

`tools/callable_polygon_hit.py` supplies the narrow contract selected by
`vf3-polygon-hit-bsr-v1`. Six mutation tests reject forged signatures,
missing prefix/restores, altered saved architecture, damaged stack slots,
and wrong entry/return/actor input. The caller windows have zero device
accesses; state 29 also records background AICA events. No live C/AICA
comparison or zero-background-event claim is made.

All matrix opcode ledgers were available. The 11 selected bindings include
existing callers that execute this helper, and all pass with zero skips.
The **39 native suites** and **130 tool tests** also pass. Historical full
inventory verification remains historical; the full current inventory gate
is required at 60%.

The auditable milestone adds **308 unique readable C bytes**, taking
coverage to **260,610 / 434,656 (59.96%)**, with **1,377 bindings**. Gaps
are **184 bytes to 60%** and **21,917 bytes to 65%**. The previous projection
seal and percentage chain are pinned explicitly. Raw originals, archived
sources, and immutable native executables remain in the external evidence
cache. The older one-case binding for `0x8c06e056` is retained and passes;
new frozen-owner credit relies on the fresh complete proof.
