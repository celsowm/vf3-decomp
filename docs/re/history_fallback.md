# Contact-history fallback selector

Callable `0x8c0c0f60`, frozen owner `0x8c0c0f70`, selects a fallback row
from a 128-row table. Its eligible body is 204 bytes; the setup/save prefix
receives no additional credit. The structured C implementation in
`src/fight/contact_history.c` was introduced with the parent updater and
requires no changes for this qualification.

Enabled selection examines up to five character bytes and associated
lengths in each row. Early sentinel and zero-length cases return immediately.
Otherwise the selector retains the original column and length tie rules.
If no row replaces the initial sentinel, it updates the scene seed and
uses the existing integer remainder helper to choose a row. The disabled
path returns zero. All paths restore MACL and the saved integer registers.

Development passes **122/122** valid original/native comparisons and fresh
holdout passes **121/121**, with no native skips. Both execute every eligible
owner instruction, including the enabled scan and seed fallback. Six
development and seven holdout interruptions remain retained and excluded.
An initial development campaign and an initial holdout campaign ended with
incomplete invocations; both are pinned without coverage credit. The final
holdout gives the unchanged fixtures 300 frames so every armed invocation
can finish. The executable and all **380 compiled source dependencies**
were frozen before holdout.

Eight genuine caller windows from saved states 28 and 29 prove BSR
`0x8c0c0d64`, its `R4=R14` delay slot, the save prefix, global setup, saved
stack values, MACL preservation and actual return to `0x8c0c0d68`.
Two affected bindings, all **39 native suites**, and **193 tool tests** pass;
the 190 default-build executables are archived. The final evidence seal is
`tools/oracle/history_fallback_v1_manifest.json`.

The adjacent 142-byte search owner remains uncredited. Original
`MOV.B @R11,R11` sign-extends its character byte; the intervening byte getter
preserves R11. Comparing that value with positive 255 can never succeed,
so two owner instructions cannot execute through the original entry.
`history_search_unreachable_v1.json` pins the relevant image bytes and the
exhaustive signed-byte-domain check. No body-range or qualification
exception is applied.

The gain is **204 bytes**, reaching **264,290 / 434,656 (60.80%)**.
**18,237 bytes** remain to 65%; the next full frozen inventory gate is
required at 62.5%. The sealed percentage chain includes the parent updater
and the preceding full 60% checkpoint.
