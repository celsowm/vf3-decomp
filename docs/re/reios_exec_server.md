# REIOS GD-ROM EXEC_SERVER / GET_CMD_STAT investigation

## Status (2026-10-14)

Following the 70% milestone, a triage pass over unported owners with existing
capture corpora (145 entries / 23,706 bytes) re-ran the strict replay bench
(`tools/replay_scan.py --deep`, extract/analysis/replay_scan_r70.csv). One new
promotion resulted; the rest fail for clustered, recorded reasons.

## Promoted: 0x8c0434c8 (14 B) — via the GDROM_EXEC_SERVER stub

Owner `0x8c064246` (508 B, an SB_ISTNRM-driven interrupt/DMA-ack dispatcher:
tests bits 8/0x20/0x40/0x80/0x100/0x200/0x400/0x200000 of `0xa05f6900`,
acks per-driver flags, walks the G1-DMA descriptor table at
`0x0c197f6c+idx*256+sub*32`, starts channel DMA via `0xffa00020`.. and
`0xa05f6800`.., then runs the callback chain walker at `0x8c045f60`) failed
34–100% of cases across 22 corpora, always at one point: a jsr to the REIOS
vector `0x8C001006` with `r6=0, r7=2` — `GDROM_EXEC_SERVER`, registered by
the driver as the G1-DMA-end callback. The flycast REIOS HLE
(`core/reios/gdrom_hle.cpp`) makes EXEC_SERVER a pure no-op when the command
queue is idle, leaving every register untouched. The recorded captures agree
exactly (idle queue in all observed contexts).

`src/fight/vf3_aica_stub_adapter.c` now models both measured services:
`GDROM_GET_DRV_STAT` (r6=0, r7=4: r0=0, status=GD_STAT_PAUSE, disc=GdRom —
unchanged) and `GDROM_EXEC_SERVER` (r6=0, r7=2: immediate no-op return).
Everything else still fails closed.

With the stub extended, trampoline `0x8c0434c8` (14 B) replays strictly in
all **1,922 cases across 9 corpora** and was promoted
(`tools/promote_replay.py`; ledger + binding recorded). Owner `0x8c064246`
itself moved from ~66% to ~89% case-pass in its largest corpora but remains
blocked (below).

## Blocked: 0x8c064246 on GET_CMD_STAT (r7=1) transfer-size words

The remaining failures hit `0x8C001006` with `r6=0, r7=1`
(`GDROM_GET_CMD_STAT`, r4=request id, r5=out quad). Flycast unconditionally
writes the four stale `gd_hle_state.result[]` words; word 2 is the byte count
of the last completed GD transfer (`nsect*2048` — observed 0x7800…0x70800,
varying per captured history). The captured out-RAM windows contain those
words, so strict replay needs the HLE's internal transfer history, which no
case input determines. Per the observation-model rule this owner stays
excluded; a faithful model would require REIOS-internal dynamic state, not
C behavior of the owner. Same wall blocks `0x8c0a7f68` (r7=0
`GDROM_REQ_CMD DMAREAD` via the driver vtable).

## Blocked: inconsistent pointer canonicalization between capture runs

`0x8c035da6` (and the cluster `0x8c06c970`, `0x8c0614ac`, `0x8c0453fe`,
`0x8c04bd62`: `mem winN: got 0c want 8c` in two corpora) — same stored code
pointer (`0x8c035e34`, a saved PR) is recorded raw (`0x8c…`) in one corpus
case and sanitized (`0x0c…`) in another case of the same corpus. No single
model value can satisfy both; treat as mixed capture-convention evidence.
These entries stay unpromoted from their current corpora. The same applies
to the `device access mismatch W 1f000038` cluster (five entries) which
needs a hardware write the recorders only logged in part: diagnosis only.

## Sweep-batch outcome (2026-10-14)

After the raw-`pr` generator fix, a 79-root sweep
(`tools/watch/vf3_sweep1.txt`, entries whose replay failed at their own entry
PC) promoted **49 owners / 11,588 bytes** with strict zero-skip replays.
Remaining 30 fail for the named walls:

- REIOS `GET_CMD_STAT`/`REQ_CMD` HLE state (8 entries: `0x8c03523c`,
  `0x8c035518`, `0x8c035728`, `0x8c0357ca`, `0x8c0431ea`, `0x8c04326c`,
  `0x8c0349ac`, `0x8c034f8a`, …) — excluded as before.
- `PC 00000000 (N OOB)` — capture windows do not cover the executed pages
  (5 entries, e.g. `0x8c045cb2`, `0x8c04c024`, `0x8c04dcd4`).
- `got 8c want 0c` — the SAME stored-pointer value recorded in the sanitized
  form in these corpora (mixed-capture-convention; e.g. `0x8c04ba56`,
  `0x8c04c0fe`, `0x8c04c61e`, `0x8c05dbae`). Cannot be satisfied by the
  hardware-true model; excluded from these corpora.

## Image-backed read fallback (2026-10-14)

Corpus windows capture only the recorder's selected pages, so reads reaching
un-captured code pages (e.g. the two-instruction leaf `0x8c05da42` at
`0x0c05d000`, outside every survey corpus window) used to fail as OOB.
`vf3_matrix_read` now serves identity image bytes
(`extract/gamedata/1ST_READ.BIN`, range `0x0c010000..0x0c1300ff`) for
addresses outside every window; runtime state beyond the image end is still
OOB and the window compare stays authoritative (the fallback only fires for
reads that previously *failed*; all 1,664 bindings + 39 suites replay
unchanged and green).

Rescan (`replay_scan_r73.csv`): no new full-sweep promoters — every
remaining failure already carries a wall. The cluster ladder is clarified:
`0x8c0598a8`/`0x8c05d8ee` now pass 3+/4 corpora; `0x8c05d8ee` keeps one
corpus whose recorded shadow holds the *masked* stored-`pr` form
(corpus-era inconsistency, excluded). The remaining walls:

- REIOS HLE state (`0c001006`): 25 entries.
- `PC 00000000` first divergence (8 entries): model walks to an
  uninitialized function pointer — needs per-entry caller fix-up evidence,
  not image fallback.
- `stc vbr` at `0x8c0370a6` (4 entries: `0x8c0369d6`, `0x8c043ac6`,
  `0x8c046182`, `0x8c046220`): needs the game's VBR value in the model.
- REIOS SYS vector `0x8C001000` (4 entries).

## REIOS gate-chain modeling (2026-10-14, second pass)

The `0x8C001000..0x8C001008` gate bodies are reached via
`jmp @r0` after loading the gate pointer from the ROM vector table
(`*(0x8c0000b0 + slot)`). Studio-local evidence:

- `vf3_aica_stub_adapter.c` now models four measured REIOS services:
  `SYSINFO_INIT` (r7=0: writes the fixed 24-byte console record
  `e619f54e b8cf7bd4 fffe 313130` + zeros at `0x8c000068`; verified
  byte-invariant across 11 sampled corpora), `SYSINFO_ID` (r7=3),
  `SYSINFO_ICON` (r7=2), `FLASHROM_READ` (r7=1) narrowed to the observed
  2-byte console block at flash offset `0x1a05e`, and the existing
  `GDROM_GET_DRV_STAT` / `GDROM_EXEC_SERVER`.
- Legacy `matrix_adapters.c` dispatch escalates *only* REIOS-gate targets
  (`0x0c001000..0x0c00100f`) to the family dispatcher; every other unknown
  indirect target still fails closed. Unscoped escalation was tried and
  reverted: it traded fast structural fails for slow budget-burning
  recursion into garbage handlers, regressing green owners
  (`0x8c06f9ac` family) via runaway budget — the direct evidence that these
  paths expect REIOS gates, not generic SH-4 addresses.
- `ocbwb @r4` at `0x8c051104` (operand-cache write-back loop) is modeled
  as the RAM-transparent no-op it is.
- The owner cluster reaching these services (`0x8c0377a8`, `0x8c03780c`,
  `0x8c047230`, `0x8c0a1294` — config-editor/region-check family) now
  executes past both REIOS services but dies later in the corner-block
  descriptor flush loop at `0x8c0510b6` (dt/bf loop whose iteration count
  is driven by `0x0c16cdxx` driver state not carried in these corpora).
  It stays unpromoted; earlier in-session promotions of these four were
  intentionally backed out of the ledger after full-gate regression.

## Shadow-missing corpora not restorable

`tools/regen_ram_shadows.py --all` finds 14 corpora whose `.cases` survive
without RAM shadows, but every source capsule is missing from local storage
(raw captures remain on D:). The 27 affected owners (2,328 bytes) stay parked
until the capsules are available.
