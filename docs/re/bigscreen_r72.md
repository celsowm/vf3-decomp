# Bigscreen r72 — natural reachability of the largest unported owners

## Status (2026-10-14)

After the 72.84% ledger point, the remaining unported large owners
(`0x8c0831f8` 1,964 B, `0x8c08231c` 1,892 B, `0x8c04b192` 1,864 B,
`0x8c09575c` 1,780 B, `0x8c05cc38` 1,290 B …) have no capture corpora, so
strict replay qualification cannot start. A hit-only screen measured natural
reachability for the top-96 unported baseline entries (49,536 bytes) in the
two replay states 45/46 (14,400 frames each, observer
`flycast_task_return_boundary_v1.exe`).

Result: **`0x8c059aea` (494 B) is naturally hit 24+24 times**; the previously
known REIOS caller `0x8c064246` is hit 385/399 times. All other 94 watched
owners score zero hits in these states. Audit (diagnostic-only):
`tools/oracle/bigscreen_r72w_hits_v1.json`, watch
`tools/watch/vf3_bigscreen_r72_wide.txt`, runs in
`extract/analysis/bigscreen_r72w/`.

## Case-capture attempt on 0x8c059aea

A natural case-capture run on state 45 (14,400 frames, `--capsule`)
rejected 24/24 specimens as interrupted (`flags=1`). The body is a polling
dispatcher (`0x8c059aea` waits on driver flags around `0x0c16cdc4/cddc/cdf4`,
call chain into `0x8c05fcc4` and the GD helpers): naturally reached
invocations do not terminate inside the record window. It needs a bounded
probe fixture or an instrumented exit-point capture before any replay corpus
can exist — not pursued in this pass; zero coverage credit.

## Consequences

- The corpus-drained conclusions of
  [reios_exec_server](reios_exec_server.md) stand unchanged: all other
  remaining unported-with-corpora owners keep their documented walls.
- Further coverage requires a fight-active state (the attract/replay states
  never reach the fight owners) or bounded probes for the two live owners
  above.
