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
