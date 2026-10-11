# History-ring scan (2026-10-11)

Callable `0x8c0a86ac`, frozen owner `0x8c0a86ba`, adds **176 verified
C bytes** through `src/fight/history_scan.c`. The 14-byte prefix and
off-inventory classification helper receive no separate credit.

The routine scans backward through the 320 paired actor records at
`0x0c22f864`, using the signed validity byte at offset 59. Empty records
return one. Active records are classified using the original flag masks
`0x00021000` and `0x08882000`, with the actor half selected by the supplied
comparison result. It preserves the original 30-record class-two run,
240-record outer limit, 160-record final scan and wrap from negative
indices to 319. The readable C retains scratch registers, condition T,
temporary stack writes, saves and original return values.

Both original callers initialize R7 to zero and pass `R4=R7` in the BSR
delay slot. Typed fixtures preserve those argument restrictions and vary
ring indices, actor-half selection, occupancy and flag classes. They
exercise the two instructions not observed by the earlier replay-packing
campaigns: the outer-limit return value at `0x8c0a872e` and final-scan
wrap at `0x8c0a8754`.

Development and independent holdout each pass **126/126** strict valid
cases with zero skips and complete 176-byte owner execution. All 64
inputs complete in each state; each campaign retains two interrupted
specimens without credit. The unchanged replay executable and complete
386-file compiled source freeze precede holdout. No C implementation is
linked into the original observer.

Eight original windows prove both BSR sites, `0x8c0a8610` and
`0x8c0a883a`, their zero-count argument and delay slot, the untouched
history-ring pool, saved stack slots, restoration and caller returns.
All eight have zero flags, device accesses and AICA events.

The three affected bindings are the new scan, replay-history packing,
and target configuration. Their frozen parent owners are `0x8c0a8582`
and `0x8c0a8808`; no opcode ledgers are missing. All three bindings,
**39 native suites**, and **235 tool tests** pass. Seven mutation tests
reject forged callers, prefix/body signatures, pools, saves and returns.
Only the 39 required native executables are archived.

`tools/oracle/history_scan_v1_manifest.json` seals original execution,
native comparisons, caller provenance, source and executable freezes,
regression evidence and the prior replay-history proof chain. Verified C
is **266,548 / 434,656 (61.32%)**; **15,979 bytes remain to 65%**. The
next full inventory gate remains required at 62.5%.
