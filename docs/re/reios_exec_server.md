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

## Scope of a GDFS/REIOS model for the boot states (2026-10-17)

Target: states 20-35, 36, 38, 39 and 42-46, which sit in the boot/loader chain (0x8C035518, 0x8C034864, 0x8C03523C) and
never return to a per-frame function, so they cannot be captured as entry/exit pairs. Reference: the flycast HLE
(`tools/emu/flycast/core/reios/gdrom_hle.cpp`, 998 lines; local only, GPL, never committed).

What a faithful C model needs, and why it is a design project, not another entry port:
1. Command state: `gd_hle_state` (params[4], result[4] incl. the transfer byte count in result[2], status,
   multi_read_{sector,offset,count,total}, cur_sector). GET_CMD_STAT (r7=1) returns it; REQ_CMD (r7=0) fills params and
   starts a transfer; EXEC_SERVER (r7=2) advances `multi_read` in steps of up to 5 sectors.
2. Disc access: sectors come from the GDI image (`rom/vf3.gdi`, never committed); the model needs a read-only sector
   source under `--disc`, with DMA writes into guest RAM (`readSectors`) and the PIO path (`multi_xfer`).
3. Initial state: none of it is in guest RAM, so it must be added to the savestate-to-capture path (a `gd_hle_state` dump
   written next to `flycast_exit_*.bin` by the instrumented emulator) before any model can be checked against the oracle.
4. Timing: transfers complete on scheduler events and raise SB_ISTNRM bits (see 0x8C064246 above); the model has to
   say when, which means a cycle or frame budget model the harness does not have yet.
Verification gate for the first slice: replay state 21 from the dumped `gd_hle_state` for N frames and require RAM
equality with the oracle at the loader chain's next return, the same standard as the scene entries.

## gd_hle_state at every boot-state savestate (2026-10-18)

`tools/gd_state_dump.py` (needs the local flycast fork's `VF3_GDDUMP` hook in `reios_deserialize`; the fork is gitignored)
loads each `vf3_<N>.state` and writes the REIOS command state to `extract/analysis/gd_state/vf3_<N>.txt` + `summary.csv`.
Findings, which settle step 3 of the scope above:

- Every state after 20 sits inside the same command: `command = 0x11` (GDCC_DMAREAD) with `params = {start sector, sector
  count, destination RAM address, 0}`. State 20 is the idle initial state (all zero).
- States 21-30 and 42-46 are mid-transfer: `status = 1` (BUSY), `multi_read_count` sectors still outstanding of
  `multi_read_total`, and `result[2] = (total - count) * 2048` (e.g. state 21: 0x56 - 0x1f = 0x37 sectors = 0x1B800 bytes).
- States 31-39 are idle again (`status = 0`) with the previous request's stale params (sector 0x68EC9, 0x100 sectors,
  dest 0x0C828800) and `result[2] = 0x80000` = the full transfer; they wait on the loader, not on the drive.
- Destinations are the loader's staging areas 0x0C5F4000, 0x0C828800, 0x0CAAE800, 0x0CB6A800, 0x0CBA8000, 0x0C370800.
  Transfers are 0x4B-0x397 sectors (150 KB - 1.8 MB), so the sector source must cover whole files, not single sectors.

So the minimum viable model is: the initial `gd_hle_state` from this dump, a sector reader over the GDI (`rom/vf3.gdi`)
that streams the outstanding sectors into the destination, and an EXEC_SERVER step of up to 5 sectors per call; timing
(`xfer_end_time`) remains the open item.

## Functional GD-ROM model and boot-chain scope (2026-10-18)

`src/sys/gdrom_hle.{h,c}` models the BIOS GD-ROM syscall (vector 0x8C0000BC, r6 = 0) for the loader's DMA-read path:
`vf3_gd_req_cmd` (r7 = 0), `vf3_gd_get_cmd_stat` (r7 = 1), `vf3_gd_exec_server` (r7 = 2) and `vf3_gd_sched_step` (the
original's scheduler timer: up to 5 sectors per tick, COMPLETE on the last one), plus a GDI reader (track 3 is raw
2352-byte sectors, user data at +16). `tests/gdrom_hle_test.c` (`build2/vf3gdrom`) checks a full request cycle for the
0x4B-sector read that boot state 24 is inside (15 ticks, BUSY until the last, COMPLETE once, then idle) and resumes the
dumped command state of states 24 and 25 (70 and 739 remaining sectors): every sector equals the reader's, the final size
word is total * 2048. `tools/gd_verify_state.py` confirms the reader against the savestate: state 24's five transferred
sectors are found contiguously in its RAM at the dumped destination; in states whose transfer is further along the loader
has already consumed (overwritten) the buffer.

The loader's syscall stubs are 0x8C0430A0 (r7 = 1 GET_CMD_STAT) and 0x8C0430B4 (r7 = 2 EXEC_SERVER): `mov #0,r6; mov
#n,r7; jmp @[0x8C0000BC]`. They, 0x8C0432DE (the status wrapper, calls 0x8C0430A0) and 0x8C035CBA (an indirect call through
the object at 0x0C0EA314 + 0x44) account for ~75k calls per 300-frame window in every boot state.

What is still missing for a native run of states 20-46 (`tools/boot_scope.py` over the call-edge logs): 123 distinct
unported callees across the boot states (loader/GDFS library functions around 0x8C0354xx-0x8C0366xx and 0x8C0430xx-0x8C0460xx,
the 12 BIOS-area helpers at 0x98012b44-0x98012e2a, and 0x8C04C47C / 0x8C053CA4 / 0x8C0365EA), none of which has a capture
corpus, and no scheduler/timer model to decide when `vf3_gd_sched_step` fires relative to the guest's polling loop.

## Syscall front end and native-tick attachment (2026-10-18)

`src/sys/bios_syscall.{h,c}` turns the r4..r7 register convention of the BIOS vector into calls on the GD-ROM model:
`vf3_bios_gd_syscall` serves REQ_CMD (r4 = command, r5 = param quad), GET_CMD_STAT (r4 = id, r5 = result quad),
EXEC_SERVER and INIT with r6 = 0, and reports anything else unhandled. `vf3_native_attach_gdrom` (native_tick.c) makes a
call to `0x0C0000BC` in a native run go to that model instead of counting as an unowned call, and lands sector
transfers in the RAM image of the running tick. The 13 fight-state native ticks are unchanged (0 unowned, RAM equal).

Still open for a native boot run: the loader functions between the stubs have no readable ports or corpora (123 unported
callees across states 20-46), and the model has no hardware clock. `vf3_bios_gd_syscall_clocked` (used by the native attachment) substitutes a
deterministic one: every GET_CMD_STAT poll that finds the drive BUSY first runs one `vf3_gd_sched_step`, so a 7-sector read
completes on the second poll. Whether that cadence matches the loader's timing is unverified.

## First loader capture attempt (2026-10-18)

`tools/watch/vf3_loader_hot.txt` (0x8C062E8E, 0x8C035CBA, 0x8C0432DE) captured with `golden_batch.py --capsule` from boot
states 42 and 21 (120 frames each, no play file): only 0x8C0432DE produced cases - 2 distinct complete ones - and 128
specimens were rejected (flag 4 capture overflow: 93, flag 1 interrupt/exception: 28, flag 5: 7). The polling wrappers
run long enough to exceed the 100,000-instruction capture bound and take timer interrupts, so the hot loader
functions need either a raised capture bound / interrupt-free window or capture of the leaf callees instead. Output:
extract/analysis/goldens_loader_hot (ignored).

Follow-up on the rejections: the hot "functions" are tiny. 0x8C062E8E is `ocbwb @r4; rts` (a cache write-back, no
architectural effect; the callback wrapper proper starts at 0x8C062E94) and 0x8C035CBA is a vtable trampoline
(`r14 = [0x0C0EA314]; if r14 { jmp [r14+68] }`, returning through the callee). Neither can run long, so the 100k
overflow flags come from the observer's call/return pairing across these trampoline tail-jumps, not from long bodies;
raising the bound will not help. Next: fix the pairing in vf3oracle.cpp for `jmp`-ended watched entries, or watch the
callee targets of the trampoline instead.

Retry with transfer boundaries (`exitpc <entry> <jmp pc>` for the three jmp-ended stubs/trampolines, states 42, 21, 30):
the rejections vanish (`Rejected specimens: {}`), but only 0x8C0432DE yields cases (3 distinct, complete); the stub and
trampoline entries still export no `.cases`, so their exit snapshots are not being accepted by the converter (not yet
diagnosed - check the batch manifest / observer log for the jmp-ended entries).

Root cause of the empty exports: `VF3_WATCH` needs a `pc <entry>` line for every watched entry; an `exitpc` line only sets
the transfer boundary of an already-listed one (vf3oracle.cpp, watch parsing). With `pc` lines added to
tools/watch/vf3_loader_hot.txt the stubs 0x8C0430A0 / 0x8C0430B4 and the trampoline 0x8C035CBA each export 3 distinct
complete cases (states 42 / 21 / 30, 120 frames), next to 0x8C0432DE's 3. Corpus: extract/analysis/goldens_loader_hot.

Strict replay of the new corpora (`VF3_STRICT_REPLAY=1 build/vf3matrixfamily.exe 0x<entry> goldens_loader_hot/f_<entry>.cases`):
all four entries fail 0/3. The captured exit of the stubs is the BIOS entry itself (`pc 0x8C001006`, the jmp boundary); the
generated routers either stop at the unmodelled helper (`unsupported helper/state ... PC 0c001006`) or run the AICA stub
adapter's EXEC_SERVER no-op through to the caller (`exit PC 0c0434d0 != 8c001006`). So replay needs the router to treat
the REIOS vector as the stub's exit boundary (or the corpus to be re-captured with the return as the boundary) before a
readable stub port can be promoted; `replay_scan.py` also only scans directories named `*cases`.

Re-capture with the return as the boundary (plain `pc` lines, no `exitpc`; states 42 / 21 / 30): the stubs
0x8C0430A0 / 0x8C0430B4 and the wrapper 0x8C0432DE export 3 complete cases each (0x8C035CBA is rejected, flag 4/5: 195
specimens). Strict replay still fails 0/3: the router stops at the unmodelled vector (`unsupported helper/state ... PC
0c001006`), and for EXEC_SERVER the no-op adapter returns r0 = 0x8C001006 where the recording wants 1. The recorded r0 of
GET_CMD_STAT / EXEC_SERVER is the REIOS command state, so replaying them needs the vf3_gd model seeded per case from the
dumped state (tools/gd_state_dump.py) - the router-side hook for that is the remaining piece. Corpus (ignored):
extract/analysis/goldens_loader_ret.

Per-invocation GD state logging (local flycast patch, tools/emu is gitignored): `VF3_GDLOG=<file>` makes the vf3oracle
observer append one line per watched invocation start (`S`) and exit (`E`): `kind id entry` then the 16-word REIOS command
state from `vf3GdSnapshot()` (reios/gdrom_hle.cpp: last_request_id, next_request_id, status, command, params[4],
result[4], cur_sector, multi_read_sector / offset / count). `id` is the capsule invocation id. Logs for the loader
watch set at states 42 / 21 / 30: extract/analysis/gdlog_s<N>.txt (ignored), e.g. the 0x8C0432DE entry of s42 starts in
status 1 (BUSY) with a DMA command in flight at multi_read_count 0xC9. Still to do: carry the S/E record into the case
metadata through golden_extract (join on invocation id), seed `vf3_gdrom` from it in the router adapter, and compare.

First oracle check of the GD model (tools/gd_model_check.py, capsules joined to the VF3_GDLOG records by invocation id):
all 566 recorded invocations of 0x8C0430A0 / 0x8C0430B4 / 0x8C0432DE in states 42 / 21 / 30 agree with the C model's
GET_CMD_STAT semantics - exit state identical, and the 0x8C0432DE wrapper's r0 equals the model's status mapped
(BUSY -> 4). Limits: every captured invocation is BUSY with a DMA read in flight (status 1), so COMPLETE / CONTINUE /
idle paths are not exercised by these captures, the EXEC_SERVER check only asserts "state unchanged or BUSY", and the
stub's own exit is the outer return (the jmp returns straight to the wrapper's caller).

Strict replay with a seeded model (2026-10-18): `src/fight/vf3_aica_stub_adapter.c` now answers GET_CMD_STAT (r7 = 1) and
EXEC_SERVER (r7 = 2) from `vf3_gdrom` when `VF3_GD_STATE` names a one-line file of the 16 state words
(the `S` record of the case's first invocation in the VF3_GDLOG file; see gd_model_check.py). The earlier 0/3 failures
were partly a capture-boundary artifact: with the plain `pc` watch the wrapper's capsule exit lies in its caller
(0x0C034888, r10 already reloaded), so no replay could match. Re-captured with `exitpc 0x8c0432de 0x8c0433b8`
(tools/watch/vf3_gd_wrapper.txt, the wrapper's `rts`), then
`VF3_GD_STATE=extract/analysis/gdstatew_s<N>.txt VF3_STRICT_REPLAY=1 build/vf3matrixfamily.exe 0x8c0432de
extract/analysis/goldens_gdw<N>/f_8c0432de.cases` is **1/1 PASS in states 42, 21 and 30**: the generated wrapper, the stub
and the C GD model together reproduce the oracle's registers and memory for the BUSY polling case. The stubs themselves
(0x8C0430A0 / 0x8C0430B4) still have no clean boundary - their recorded exit is the BIOS entry or the caller - so they
are verified only as part of the wrapper.

Readable port of the wrapper: `src/fight/gd_status_wrapper.c` (0x8C0432DE, translates the BIOS GET_CMD_STAT status and
error words into the loader's result codes). `tests/matrix_family_replay.c` gained `VF3_READABLE=1` (the readable ports
pre-empt the generated chain; it prints how many calls they served), so the same oracle cases check the readable C:
`VF3_READABLE=1 VF3_GD_STATE=extract/analysis/gdstatew_s<N>.txt VF3_STRICT_REPLAY=1 build/vf3matrixfamily.exe
0x8c0432de extract/analysis/goldens_gdw<N>/f_8c0432de.cases` passes 1/1 in states 42, 21 and 30 with 1 readable call.
Only the BUSY path (status 1) is covered by the cases; the other status branches and the error table are transcribed
from the disassembly (braf table at 0x8C043360) and not oracle-checked. Fight-state regression unchanged (155 entries).

Stub port: `src/fight/gd_syscall_stub.c` registers 0x8C0430A0 (GET_CMD_STAT: r6 = 0, r7 = 1, tail call through the pointer at
0x8C0000BC). It is verified as the callee inside the wrapper replay (`readable ports used: 2 calls`, 1/1 in states 42 /
21 / 30). 0x8C0430B4 (EXEC_SERVER, r7 = 2) is the same code but has no oracle case with a clean boundary, so it is not
registered. 156 readable entries.

Scope correction (tools/boot_scope.py over states 21..46): the union of unported executed callees is **489** functions,
not 122 (that figure was the union over three states). The polling hot path is now covered - 0x8C0432DE and 0x8C0430A0 are
readable and oracle-replayed; the rest of the hot set is 0x8C035CBA (vtable trampoline, no clean capture yet),
0x8C0430B4 (EXEC_SERVER stub, no clean boundary) and 0x8C062E8E (`ocbwb @r4; rts`, observer exports no case for the cache
op) - while the long tail (everything else runs <= ~110 times per 120 frames) is 480+ functions, each needing its own
capture boundary, replay and port. A native boot-state run is therefore a campaign of that size, not one more step.

Trampoline port: `src/fight/vtable_trampoline.c` (0x8C035CBA) ends in a true tail jump (pc = [obj+68], pr untouched), the
convention the jmp-boundary corpus records. `VF3_READABLE=1 VF3_STRICT_REPLAY=1 build/vf3matrixfamily.exe 0x8c035cba
extract/analysis/goldens_loader_hot/f_8c035cba.cases` is **3/3 PASS** (the generated chain fails the same cases on
out-of-window reads; the readable port needs none). The null-object branch is transcribed, not oracle-covered. A native
runner must treat a readable port that returns with pc != pr as a jump to that pc (native_tick does not yet - it only
needs this once the loader chain runs). 157 readable entries.

EXEC_SERVER stub: `vf3_gd_exec_server_stub_entry` (0x8C0430B4, in gd_syscall_stub.c) uses the tail-jump form (pc = the BIOS
entry read from 0x8C0000BC, r6 = 0, r7 = 2) and replays **3/3** against the jmp-boundary corpus
(`VF3_READABLE=1 ... 0x8c0430b4 extract/analysis/goldens_loader_hot/f_8c0430b4.cases`). Note the two stub ports use
different conventions: 0x8C0430A0 makes a guest call that returns to the caller's pr (verified through the wrapper
replay), 0x8C0430B4 and 0x8C035CBA end with pc at the jump target (verified against jmp-boundary corpora). A native
runner has to honor both. 158 readable entries.

Correction (read of `vf3_matrix_family`, src/fight/matrix_family.c:763): the walker already honors tail-jump ports. With
`vf3_family_complete_calls` set (native_tick sets it), a call whose pc comes back different from the caller's pr is
continued as a nested dispatch at that pc until control reaches the pr. So 0x8C0430B4 and 0x8C035CBA need no walker
change; what is still missing is a boot-state native harness (states 20-46) to exercise them.

## First native boot-state span (state 21, 0x8C034864)

`tools/tick_capture.py 0x8c034864 --state vf3_21.state --frames 300 --pairs 1 --name bootB` records the loader function
that calls the GD wrapper (0x8C0432DE); `build/vf3 golden_bootB_vf3_21.bin --entry 0x8c034864 --gdi rom/vf3.gdi
--gd-state extract/analysis/gdstate_s21_0c0432de.txt --vs-exit` runs it on C only (46 blocks, 2 readable ports, 1 BIOS
call served, 0 unowned) and diffs the whole 16 MiB against the recorded hardware exit (`vf3_native_load_exit`).

- Default (clocked) poll: 10189 bytes differ, in three clusters. The big one is the GD destination (0x0CACA000..): the
  model moves a sector batch on each busy poll, the drive had not moved them yet when the function returned. This is the
  timer-cadence question, now visible as a measurable diff.
- `VF3_GD_NOCLOCK=1` (a poll never advances the drive): 4 bytes differ, all at 0x0C31F9DC, the saved-return slot
  (native 0xDEAD0000 sentinel, hardware 0x0C035530). So everything else in the span is bit-exact.

States 30 and 42 give the identical result for the same function (captures bootB, seeds gdstate_s{30,42}_0c0432de.txt):
`VF3_GD_NOCLOCK=1` leaves 4 bytes, the saved-return slot (0x0C31F9C8 there), and nothing else. Three boot states, one
function: bit-exact modulo the return sentinel and the unmodelled drive cadence.

## State 21 idle loop: iteration capture attempt

The edge log of state 21 shows no function-level exit: each pass through 0x8C035530 returns from 0x8C0349A6 into the
middle of an outer function that never exits (depth grows). A span there has to be a loop iteration, not a function.
`tick_capture.py 0x8c035530 --exitpc 0x8c0349a6 --pairs 1` records one, and `build/vf3 ... --entry 0x8c035530
--stop 0x8c035530` (new `--stop`: end the run when control reaches that address) replays it. Result with
`VF3_GD_NOCLOCK=1`: 7 bytes differ (stack slots around 0x0C31F9F4..FA), and the native run ends at 0x0C035248 where the
recording ends at 0x0C035530, i.e. the entry state is mid-function (a return site) and the walker's fragment seed for
0x8C035530 does not follow the same path as the real rts. Open: define iteration spans from call/return edge pairs
instead of an arrival pc, then widen to states 20-46.

## 0x8C062E8E (ocbwb @r4; rts) closed

The earlier "no case" was a short capture window (120 frames of state 42 never reach it; 900 do) plus a missing `exitpc`
(`tools/watch/vf3_cache_stub.txt`). 64 cases recorded; the readable port (`src/fight/cache_wb_stub.c`, the cache is
not modelled so the op is a no-op) replays 64/64 with `VF3_READABLE=1 VF3_STRICT_REPLAY=1`. 159 readable entries; the hot
loader set is now complete.

## Drive cadence measured (timer model, first data)

The GD log of the three boot states shows the emulator's REIOS drive almost standing still while the loader polls: states 21
and 42 have one distinct command state over ~250 polls each, state 30 two (0xD8 -> 0xD3 sectors left, i.e. exactly one
5-sector scheduler step in 179 polls). The poll-driven stand-in ran a step on every busy poll, ~100x too fast, which is
the ~10,000-byte destination diff. `vf3_bios_gd_set_poll_divider(n)` / `--gd-polls-per-step n` runs a step every n-th busy
poll; with n = 179 the 0x8C034864 span in states 21, 30 and 42 is again bit-exact (4-byte return slot only) with the
clock RUNNING, no VF3_GD_NOCLOCK needed. A real model should be vblank/frame driven (one step per N frames); polls
per frame is not logged yet, so the divider is the stand-in until the observer records frame numbers.

## Idle-loop spans across the boot states

Most boot savestates are the same GD idle loop (edge logs: 0x8C035CBA / 0x8C0434C8 / 0x8C0430B4 / 0x8C0432DE at depth 1-3).
`tools/recomp/boot_span.sh <entry> <state...>` captures a function and replays it natively against the recorded exit.
0x8C0434C8 (the EXEC_SERVER caller) in states 21 23 24 27 28 29 44 45 46: 6 blocks, 1 readable port, 0 unowned, and 4 bytes
differ (the saved-return slot) in all nine. With 0x8C034864 in 21/30/42 that is 12 of the 27 boot states running bit-exact
spans. Not idle-loop states (different code, where the unported long tail lives): 20, 25, 31-36, 38, 39, 40.

## XF bank in entry snapshots; more states

The first state-40 span (0x8C03C4F0 matrix_push, `frchg` then stores the other bank) differed by 46 bytes because the native
run started with a zero XF bank: entry snapshots only carry XF when the watch has an `xfpc` line. `tick_capture.py` now
writes `xfpc <entry>` and `vf3_native_load_snapshot` loads the FA70 record into the run (zeros when absent, so the older fight
captures are unchanged: states 7 and 13 still 0 bytes differ). With it matrix_push, 0x8C048B00 and 0x8C048BE0 in state 40
and 0x8C03658C in state 32 are bit-exact (state 32: return slot only). States 20 and 36 start in the 0x8C008xxx-0x8C00Axxx
system area (IP.BIN / boot ROM, not part of 1ST_READ), which no ported code owns: one unowned call at entry. That area is
the remaining non-game boot code and needs its own decision (port or treat as a platform boundary).

## Boot-state coverage table (states 20-46)

Edge logs (extract/analysis/p4/e<N>.bin) and run PCs (p4/l<N>.log) classify every boot savestate:

- **Game code, native span bit-exact (saved-return slot only):** 21-30, 32, 39, 40, 42-46 (`boot_span.sh`): the GD wrapper
  chain 0x8C034864 in 21/30/42; the EXEC_SERVER caller 0x8C0434C8 in 21-26 (all of 21 22 23 24 25 26), 27 28 29 and 43-46;
  0x8C03658C / 0x8C0365EA / 0x8C053CA4 / 0x8C046AEE in 32 and 39 (0x8C0365EA is exactly 0 bytes); the state-40 matrix and
  0x8C048Bxx functions. States 37 and 41 are fight states, covered by the whole-tick native runs.
- **System-area bootstrap, not game code:** 20, 35, 36 run at 0x8C008xxx-0x8C00Axxx (IP.BIN, edge targets 0x8C0083C0, 0x8C009DEC...);
  31, 33, 34, 38 run the uncached system code at 0xAC0044D4 / 0xAC00479A / 0xAC005880 / 0xAC0059EA (edge `0x18012E2A` etc. are
  BIOS/flash addresses). 1ST_READ.BIN does not contain this code and the port does not own it. Decision: the platform boundary
  of the port. The native run starts at the first game-code entry (the 1ST_READ jump) and the system area is represented by
  the BIOS vector (0x8C001006, served by sys/bios_syscall) plus the snapshot RAM, not by ported C.

## Timer model: cycle-based drive clock (measured)

The local flycast patch now appends the SH-4 scheduler time to each GD log row when `VF3_GDLOG_TIME=1` (` @<cycles>`).
State 30, 900 frames, 3000 wrapper polls: successive polls are 2688 cycles apart, and the busy drive state changes exactly
once per 1,000,000 cycles (spacings 999936-1000384, i.e. 1 ms-quantised by the poll spacing): one 5-sector step per
5 ms (200 MHz), ~372 polls per step. The earlier 179-polls guess came from a window that happened to contain one step;
it was consistent with 250 polls (672k cycles) of no change in states 21/42 and is superseded.
`vf3_bios_gd_set_cycle_clock(per_poll, per_step)` / `--gd-cycles 2688 1000000` implements it (each busy poll costs
2688 cycles, a step per 1,000,000 accumulated cycles); `tools/recomp/boot_span.sh` uses it, and the 0x8C034864 spans in
states 21/30/42 stay bit-exact. What this is not: the poll cost is the idle loop's, a different caller loop would need its
own per-poll cost, so the real model is a cycle counter advanced by executed instructions (native_tick does not count
cycles yet).

## The loader's trampoline chain: 0x8C035CBA -> 0x8C035238 -> 0x8C0434C8 (state 21/30)

The state-21 "iteration" of the earlier section is really the vtable trampoline call at 0x8C03552C: it tail-jumps to
[[0x0C0EA314]+68] = 0x8C035238, a virtual-call prologue (`obj=[0x0C0EA2EC]; ([[obj+20]+64])()` -> falls into 0x8C035248),
whose slot is 0x8C0434C8 (the EXEC_SERVER caller). The span capture `tick_capture.py 0x8c035cba --exitpc 0x8c0349a6`
replays natively with 0x8C035238 now a readable port (`src/fight/loader_dispatch_5238.c`) and with readable ports counted
as call targets in native_tick (the oracle table only knew the fight ticks' entries, so a boot tail-jump chain stopped at
the first target). Result: with the GD seed (`--gd-state gdstate_s<N>_0c0432de.txt`; the first run lacked it, the drive then reads idle and
the loop takes another branch, which produced the "13 bytes" and the wrong async-work theory) and `--stop 0x0c035530` (the
return address the real iteration used) the iteration is **bit-exact: 0 bytes differ and the exit pc equals the recording**,
states 21 and 30 (68 blocks, 5 readable-port calls, 1 BIOS call served). Without `--stop` the only difference is the
sentinel in the saved-return slot. This closes the "7 bytes / wrong end address" item of the idle-loop section: it was the same
missing seed plus a mid-function entry. One whole idle-loop iteration of the loader is now a verified native run.
`--peek ADDR` and `VF3_TRACE_ENTRIES=1` (entry trace to stderr) were added to find this.
Not yet verified by replay: the port's own corpus (goldens_l238, 1 case) fails in the replay harness at the BIOS tail
jump (PC 0) even with VF3_COMPLETE_CALLS=1 (new harness switch) and the GD seed; the port is checked by the native span only.

### Consecutive iterations (state 21)

`build/vf3 golden_bootV3_vf3_21.bin --entry 0x8c035cba --stop 0x0c035530 --gdi rom/vf3.gdi --gd-state
extract/analysis/gdstate_s21_0c0432de.txt --gd-cycles 2688 1000000 --ticks N --vs-exit-after-ticks` (new flags;
`--exit-pair K` picks another recorded exit) runs N back-to-back iterations of the loader's wait loop and diffs the RAM
against the emulator's N-th recorded exit: N = 1, 2, 3, 6 all give **0 bytes differ, exit pc equal**. (`--ticks` restarts each
iteration from the entry registers, which for this loop is exactly what the real one does: the loop head's registers are
reloaded every pass.) Long runs (4000 iterations, ~10.7M cycles of drive time) complete with 0 unowned calls, so the loader
wait loop runs through the full 0x1F-sector transfer on the cycle clock; what follows completion is unported code and not yet
compared.
Verified: 100 iterations leave the GD model BUSY with 31 sectors to go (268k cycles, no step yet); 4000 iterations leave it idle with
0 left, i.e. the loop consumed the COMPLETE status; the executable prints this as "GD model at end".

## What follows the final poll: it is the vblank interrupt (not a boot hand-off)

The edge log of state 30 (record 4782, 531 polls ~ 0.43 frame in) shows calls from 0x8C004C9E.. (decoded as `stc.l spc/ssr/vbr/gbr,@-r0`,
`sts.l pr` - the BIOS exception entry saving the context; the odd 0x18012xxx "callees" are the decoder following those `stc.l`
opcodes), then 0x8C004058: `INTEVT >> 3` indexes the vector table at RAM and jumps - the IRQ dispatcher. It enters the game's
two interrupt handlers 0x8C063D1E and 0x8C062E94 (17 distinct callees, 11 not marked ported though 6 of them replay 6/6 on the
generated chain: 0x8C035E90 0x8C036132 0x8C043964 0x8C043BB4 0x8C045EBE 0x8C045F0A 0x8C063D1E). So the "hand-off" is the
interrupt model, and one frame = 3.34M cycles = ~1240 idle polls.

`tools/ram_dis.py <capture> <addr>` disassembles any address out of a capture's entry RAM (BIOS/system code included).

Both handlers run natively from the state-30 capture (`boot_span.sh 0x8c063d1e 30`, `... 0x8c062e94 30`): 204 and 2028 blocks, 0
unowned, return slot only - once the one hardware read is modelled: the vblank handler (via 0x8C043BB4) stores
`PVR SPG_STATUS (0xA05F810C) & 0x3FF` into 0x0C19E9C6, recorded 0x104 (scanline 260); `device_read` now returns 0x104 for that register
(a constant standing for "the line the vblank-in interrupt is raised on"; no beam model). 0x8C062E94 is also bit-exact in states 21, 42 and 43.
So the interrupt side of the timer model is: raise the vblank handlers (0x8C063D1E then 0x8C062E94 after the BIOS dispatcher) every
~3.34M cycles on top of the polling loop; what's missing is the injection itself in the native runner.

## One native frame of the loader (vf3boot, state 30)

`build/vf3boot` (src/boot_sim.c) runs `polls` wait-loop iterations on the cycle-clocked GD model, then the two vblank handlers
with their recorded entry registers, and diffs the RAM with the emulator's RAM at the next recorded vblank entry
(`BS_REF=<pair>` picks the reference pair; the irqA capture's pairs are NOT consecutive frames - pair 1 already holds 446 more
sectors than pair 0, so pair 0 is the frame that follows loop pair 0).
State 30, 531 polls, reference irqA pair 0: **8312 bytes differ**, split as
- 8192 bytes at 0x0C83C000-0x0C83E000: the five sectors the first drive step moves. The emulator's copies are pure 0x00/0x80
  filler sectors (and so are its sectors for the whole 0x0C828800.. destination), while the disc image's FADs 0x68EC9.. carry
  ff-filled and mixed data. The content the emulator delivers is not the disc's data at those FADs, so this block is a
  data-fidelity question about the oracle, not a timing error of the model (the model's sector count agrees: 211 left).
- ~98 bytes in the BIOS work area 0x0C00E000/0x0C00F000 (BIOS interrupt-context saves; the BIOS is not modelled);
- ~20 bytes in game areas (0x0C0EA000, 0x0C16C000, 0x0C198000, 0x0C19E000-0x0C1A0000, 0x0C2A6000/7000, 0x0C31F000) - ordering
  noise from taking the interrupt between iterations instead of inside a BIOS poll.
`vf3_bios_gd_advance_cycles` lets time outside the polls (interrupt work) move the drive.

### Correct reference for the frame diff, and the interrupt inside the poll
The recorded irqA pair is the RAM *before* the handler ran, so the right native comparison runs the polls and stops
(`--irq-in-poll 2`, `BS_REF=0`): **8220 bytes differ** = the 8192-byte GD data block + 28 bytes; of those, 7 bytes are game
state (0x0C2A62E4, 0x0C2A73A9/A, 0x0C31F9AD/AE/C1/C2: a 0x0028-vs-0x0168 word and flags, no device read is involved) and ~21 bytes
are the BIOS work area. `--irq-in-poll 1` takes both vblank handlers inside the BIOS poll of the last iteration through a nested
`vf3_native_tick_run` (`vf3_native_set_poll_hook`; the interrupted run's machine and XF bank are saved and restored); it runs
clean, and the handlers' own writes are then the extra diff against the *pre*-IRQ reference, as expected. `VF3_DEVLOG=1` prints
every device-register read of a run.

### Free-running clock (vf3boot --cycle-frames N --gd-phase P)
Every served poll costs 2688 cycles; the vblank pair is taken inside the poll whose running count crosses the next 3,336,670-cycle
boundary (first boundary = `--first-polls` x 2688). `--gd-phase 565440` starts the drive part-way through a step (the emulator's
first step fell 434,560 cycles after the first poll). State 30, 2 vblanks (1773 iterations, 4,765,824 cycles): the model ends with
**191 sectors left, cur 0x68F0A, the same as the emulator's GD log at that cycle** (without the phase it is one step behind, 196).
The run completes with no failed handler or unowned call; the RAM diff against the emulator is not meaningful past frame 1 because the
recorded irqA pairs are not consecutive frames.

### 242 vblanks, states 21 and 30
An iteration that never reaches the BIOS (the drive is idle after the transfer) is charged one poll interval too, and moves the
drive. With that, `vf3boot --cycle-frames 300 --gd-phase 565440` runs 300,000 wait-loop iterations over **242 vblanks (806M cycles)**
in both state 21 and state 30 with no failed run and no unowned call; the transfers finish (state 30: cur 0x68FC9 = 0x68EC9 + 0x100,
status idle, 0 left; state 21: cur 0x822D8, idle). The loop head is then reached forever: whatever releases the loader from the wait
(the next state's first entry, captured as the next boot state) is outside this loop's closure - the same platform boundary as the
system-area states.
