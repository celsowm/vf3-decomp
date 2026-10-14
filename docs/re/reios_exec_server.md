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

## Shadow-missing corpora not restorable

`tools/regen_ram_shadows.py --all` finds 14 corpora whose `.cases` survive
without RAM shadows, but every source capsule is missing from local storage
(raw captures remain on D:). The 27 affected owners (2,328 bytes) stay parked
until the capsules are available.
