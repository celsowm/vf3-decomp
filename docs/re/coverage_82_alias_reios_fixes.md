# PR-alias, REIOS GD-vector and null-dispatch fixes (coverage 81.16% → 81.66%)

## What was wrong

The pool of unported entries that already had a *complete* captured corpus was
61 entries / 7,420 B (`extract/analysis/u90_pool_body_complete.csv`). Only
**6 of them replayed clean**. The other 55 fell into three failure classes,
all of them C defects rather than missing captures:

| class | entries | bytes | symptom |
|---|---|---|---|
| `alias-8c-vs-0c` | 19 | 1,994 | `mem winN @+0xNNN: got 8c want 0c` |
| `helper-state` | 32 | 3,388 | `unsupported helper/state at <entry> PC <pc> (0 OOB)` |
| `other` / `fpu` | 4 | 894 | null-pointer chase, FPUL mismatch |

## Fix 1 — the PR alias was hardcoded to the wrong form

The guest runs in the P2 area: of the **14,138** recorded entry PRs in the
corpora, **13,583 (96%) carry the 0x0C form** and 555 (4%) the 0x8C form. The
reference stores the plain 29-bit address in memory, so the C has to keep the
*executing image's* alias rather than assume one.

The current translator already resolves this at run time:

```c
/* PR keeps the alias of the executing image: the capture alias is visible in
 * the caller return address. */
uint32_t code_base=((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u;
```

Five legacy generated modules still hardcoded the 0x8C form:

| module | PR assignments |
|---|---|
| `src/fight/tickgap_adapters.c` | 3,507 |
| `src/fight/vf3_sweep_adapters_1.c` | 580 |
| `src/fight/vf3_sweep_adapters_0.c` | 398 |
| `src/fight/vf3_sweep_adapters_2.c` | 392 |
| `src/fight/fight26_mod.c` | 173 |

All **5,050** call sites were rewritten to `r[16]=code_base|0x0c…u;` and each
module gained the same `code_base` definition. Every other generated module in
the tree (~19,700 call sites) already used the 0x0C form.

Effect: the `alias-8c-vs-0c` class drops from 19 entries / 1,994 B to
**1 entry / 54 B**.

## Fix 2 — the REIOS GD-ROM vector was closed for every command but one

The loader stubs reach the BIOS through the pointer word at `0x8C0000BC`.
`src/fight/vf3_aica_stub_adapter.c` modelled only `GDROM_GET_DRV_STAT`
(r7 = 4) and `GDROM_EXEC_SERVER` (r7 = 2) and failed closed on everything
else, so the vector answered "unsupported helper/state" for r7 = 6
(`GDROM_REQ_DMA_TRANS`).

`reios_gd_idle()` now answers the REIOS command set against an idle drive
with the reference semantics (`tools/emu/flycast/core/reios/gdrom_hle.cpp`):

* 6 `REQ_DMA_TRANS` / 12 `REQ_PIO_TRANS` — read the two parameter words, then
  refuse with `GDC_ERR` because no transfer is in flight;
* 7 `CHECK_DMA_TRANS` — write the remaining length (0), answer `GDC_BUSY`;
* 13 `CHECK_PIO_TRANS` — `GDC_ERR`;
* 3 `INIT_SYSTEM` / 9 `RESET` — reset the drive, leave r0 alone;
* 5 `G1_DMA_END` / 10 `CHANGE_DATA_TYPE` / 11 `SET_PIO_CALLBACK` — `GDC_OK`.

`VF3_GD_SET_PIO_CALLBACK = 11` was missing from `src/sys/gdrom_hle.h` and was
added.

## Fix 3 — the null-pointer dispatch (docs/re/remaining_work_plan.md, T1.5)

`jsr @r0` with `r0 = 0` traps on the SH-4; the emulator records the trap as
the end of the specimen. The C side treated the null target as an unimplemented
helper. `vf3_matrix_family_core()` now answers `entry == 0` with "the call
landed and nothing else happened".

## Verification

| gate | result |
|---|---|
| `tools/body_complete.py` | every promoted body fully emitted |
| `tools/binding_steal.py` | 2 pre-existing bindings shadowed by `vf3_c90_adapter.c` — both re-run and still PASS |
| `tools/promote_replay.py` (strict, zero skips) | 19 entries promoted, 2,156 B credited |
| random 500 pre-existing bindings, own test binaries | **500/500 PASS** |
| `tools/decomp_stats.py` → `tools/final_status.py` | 354,932 B = **81.6581%** |

## Capture recipe correction (for the next pool)

The synthetic-probe captures need a **hot trigger**. The default trigger
`0x8C063D36` has 15,179 recorded hits, while `0x8C0432E2` has 11,246,319 — and
the latter is the trigger every successful historical capture used. With the
cold trigger the emulator never reaches the entry and rejects every specimen
with `flags=1` ("synthetic probe superseded"): 119 attempts over three seed
modes produced **0** corpora. With `--trigger 0x8c0432e2 --states 21,27` the
same sweep immediately produced a corpus for `0x8C0831F8` — the largest
remaining unported body (1,964 B), which had been blocked on the oracle's
128-page RAM window.
