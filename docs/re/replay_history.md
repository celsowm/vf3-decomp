# Replay-history packing (2026-10-11)

Callable `0x8c0a87fc`, frozen owner `0x8c0a8808`, contributes **222
verified C bytes** through `src/fight/replay_history.c`. The 12-byte
prefix and off-inventory record copier receive no separate credit.

The routine starts at the previous entry in the 320-entry fight-history
ring at `0x0c22f864`. The existing scan helper `0x0c0a86ac` determines
how far to step backward. It then packs paired 64-byte actor records
into 32-byte replay records, beginning at `0x0c239864` plus the selected
round's `0x3400` stride. It records actor IDs and mode metadata, wraps
the source index after 319, and stops when it reaches the original index.

The original byte counter is sign-extended before comparison with 200.
The port preserves this behavior, including byte wraparound, instead of
adding an unsigned stopping condition. The record copier retains raw
floating-register loads/stores, signed word and byte loads, scratch
register values and temporary stack writes. No floating arithmetic or
device access is added.

The first 180-frame development pilot ended before all inputs completed:
71 valid cases matched, but the campaign remains unqualified and pinned.
The final 360-frame campaigns complete all 64 inputs in both states.
Development matches **118/118** valid strict cases and independent holdout
**120/120**, with zero skips and complete 222-byte owner execution in
both. Ten development and eight holdout interruptions remain excluded.
The unchanged executable and 385-file source freeze precede holdout.

Eight final original-caller windows prove the literal load at
`0x8c099206`, stack argument loads, JSR at `0x8c09920a`, untouched target
pool `0x0c099270`, saves including MACL, restoration and return to
`0x8c09920e`. An earlier eight-window caller pilot has three interrupted
specimens and remains entirely excluded. Final callers use short scans
and ring wrap boundaries. Background AICA events receive no device credit.

The affected scan includes the real call site and its frozen parent
`0x8c0991a2`; that parent is unbound. Only the new root binding is affected,
with no missing opcode ledgers. It, **39 native suites**, and **228 tool
tests** pass. Seven mutation tests reject forged caller/pool/save/return
evidence. Only the 39 required native regression executables are archived.

`tools/oracle/replay_history_v1_manifest.json` seals final and excluded
campaigns, original callers, dependency freezes, strict reports, regression
evidence and the preceding render-lanes proof chain. Verified C is
**266,372 / 434,656 (61.28%)**; **16,155 bytes remain to 65%**. A full
inventory gate remains required at 62.5%.
