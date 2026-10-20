# 78% milestone — ghost-entry promotion and the 0x8C06A35C FPUL defect

Date: 2026-10-20
Scope: the 78% pure-C coverage bar (339,032 B of 434,656 B).

## 1. The brief was stale

The task brief listed 0x8C097ABC (1,132 B) as "94/98 cases pass, 4 fail
FPUL/alias" and 0x8C09970A (1,172 B) as failing an "8c/0c alias value".
Both were already fixed by commit `87ae128` ("Port 0x8C09970A and
0x8C097ABC; fix sidecar row alignment and complete-corpus gate"), which
landed at 00:37 on 2026-10-20.

Measured against the current tree:

| entry  | corpus                                              | result                    |
|--------|-----------------------------------------------------|---------------------------|
| 0x8C097ABC | percentage_additional_families_dev_..._complete  | 98/98 cases, 0 skipped — PASS |
| 0x8C097ABC | tenpp_large_global_dev_...                         | 98/98 cases, 0 skipped — PASS |
| 0x8C09970A | coverage_65_09970a_nested_probe_v8_offset16       | 32/32 cases, 0 skipped — PASS |

The artifacts that still show the old failure are pre-fix debugging
leftovers and are **not** live corpora:

- `extract/analysis/trace_97abc.txt` (00:05) — shows
  `FPUL: 00000003 != 0000000f` for cases 52/54/69.
- `extract/analysis/dbg_97abc_case52/` (00:09) — a single-case capsule
  rebuilt by hand. Its sidecars are *not* the corpus sidecars: the
  `extra.bin` record for row 51 says expected FPUL `0x0000000f` where the
  corpus says `0x80000000`, and its `xfin`/`xfout` words differ from the
  corpus row. It still fails, as it should — it is a different case.

Side-by-side of the two capsules for ordinal 51:

```
extra.bin  dbg   : 03 00 00 00 | 0f 00 00 00 | bc 7a 09 8c | e4 32 04 0c
extra.bin  corpus: 03 00 00 00 | 00 00 00 80 | bc 7a 09 8c | e4 32 04 0c
                          ^^^^ expected FPUL differs
```

The real gap at the time the brief was written was **1,626 B**, not
7,358 B: the tree stood at 337,406 B (77.6260%).

## 2. The capture pool was not drained

`docs/re/replay_pool_discovery.md` and the brief both claim the replay
pool is exhausted. It is not:

- 805 unported baseline owners still own a **shadowed** corpus
  (33,486 B of unported bodies in total).
- The top 250 unported owners by size were swept with
  `tools/sweep_top.py` (new tool; same strict-replay probe as
  `tools/replay_scan.py`, restricted to the largest N owners that own a
  shadowed corpus).
- 23 of them already replay **clean** (0 skipped, exit 0) on real captured
  corpora, and each is owned by a router in `src/fight/*_adapters.c` —
  they were simply missing a `docs/decomp_status.csv` row, so the coverage
  union never credited them.

These are ledger ghosts, not code gaps. `tools/promote_replay.py` (with
the `corpus` column added in the in-flight diff) re-runs strict replay on
every listed corpus and refuses to write unless all of them pass.

Promoted: **23 entries, 5,764 B** → union **343,170 B = 78.9521%**.

A second sweep over the whole shadowed-corpora pool (`--top 700`, 607
remaining unported owners) found 19 more clean-but-unledgered owners worth
**1,188 B** — all leaves between 4 B and 130 B. Promoting those as well:

    42 entries, 6,952 B  ->  union 344,358 B = 79.2254%

Full list (size, corpora, owning router):

| entry | bytes | corpora | router |
|---|---|---|---|
| 0x8c064246 | 508 | 8 | device_adapters.c |
| 0x8c080e74 | 480 | 3 | motion_adapters.c |
| 0x8c0bed08 | 418 | 2 | motion_adapters.c |
| 0x8c05f768 | 364 | 2 | vf3_sweep_adapters.c |
| 0x8c08fe62 | 322 | 6 | tenpp_expanded_adapters.c |
| 0x8c06c970 | 318 | 1 | advance_worker_adapters.c |
| 0x8c05d8ee | 312 | 3 | tenpp_expanded_adapters.c |
| 0x8c05027a | 282 | 8 | device_adapters.c |
| 0x8c04279c | 254 | 5 | target_family_adapters.c |
| 0x8c0614ac | 234 | 1 | matrix_adapters.c |
| 0x8c035da6 | 234 | 3 | tenpp_survey_adapters.c |
| 0x8c0453fe | 228 | 1 | eighth_adapters.c |
| 0x8c06cb02 | 188 | 2 | advance_worker_adapters.c |
| 0x8c0a7f68 | 186 | 1 | fifth_adapters.c |
| 0x8c06c7f2 | 178 | 2 | advance_worker_adapters.c |
| 0x8c055420 | 172 | 3 | motion_adapters.c |
| 0x8c0357ca | 168 | 2 | motion_adapters.c |
| 0x8c043ac6 | 164 | 3 | tenpp_survey_adapters.c |
| 0x8c0c61b8 | 158 | 2 | vf3_9970a_adapter.c |
| 0x8c099c4c | 154 | 2 | vf3_9970a_adapter.c |
| 0x8c08bfa8 | 152 | 1 | fight_adapters.c |
| 0x8c035728 | 148 | 5 | target_extended_adapters.c |
| 0x8c03acf2 | 142 | 1 | vf3_03ae_adapter.c |

Caveat on 0x8C064246: a 9th corpus (`advance_natural_accept`) has 72 of
509 cases failing at `PC 0x0c001006` — the REIOS BIOS dispatch stub, not
the entry's own body. The 437 remaining cases pass. This is the same
"unsupported BIOS GD-ROM wrapper" exclusion the ledger already records for
0x8C0978EE.

## 3. 0x8C06A35C — a real FPUL defect, but not an FTRC bug

0x8C06A35C (570 B) replays 48/128. The 80 failures are all:

```
FPUL: 7fffffff != 80000000
```

### The FTRC semantics are already right

The repo's own FPU oracle (`extract/analysis/fsca_modes.bin.ops`, 147,456
records) pins the reference behaviour:

| input to FTRC | expected FPUL |
|---|---|
| NaN | 0x80000000 |
| -Inf | 0x80000000 |
| +Inf | 0x7fffffff |
| finite >= 2^31 | 0x7fffffff |
| finite < -2^31 | 0x80000000 |

`src/fight/sh4_fpu.c` (`vf3_fpu_ftrc`) and the generated
`truncate_float()` in the adapters both match that table exactly. Changing
the FTRC rule would break the 6 `+Inf` / 6 `big+` oracle rows and the
already-passing users in `clip_attributes.c`, `contact_frame.c`,
`fight_helpers.c` and `packed_direction.c`.

### The divergence is upstream of the FTRC

The body's FPU tail (guest 0x8c06a3b0):

```
lds r9,fpul          ; FPUL = R9
fmov @r0,fr5         ; FR5 = *(float*)0x0c06a478
float fpul,fr3       ; FR3 = (float)R9
lds r10,fpul         ; FPUL = R10
float fpul,fr2       ; FR2 = (float)R10
fmov fr3,fr6
fmov fr2,fr4
fmul fr5,fr4         ; FR4 = FR5 * FR4
fdiv fr6,fr4         ; FR4 = FR4 / FR6
ftrc fr4,fpul        ; FPUL = (int)FR4
```

Instrumented values at the `ftrc` site (temporary `VF3_DBG_FPUL` print,
since reverted):

```
[ftrc] fr4=ffc00000 (nan) r9=00000000 r10=00000000 -> 80000000   (8 cases,  PASS)
[ftrc] fr4=7f800000 (inf) r9=00000000 r10=00000001 -> 7fffffff   (120 cases, FAIL)
[ftrc] fr4=ff800000 (-inf) r9=00000000 r10=ffffffff -> 80000000  (passes)
```

All three corpora (`target_final_dev_06a35c`,
`tenpp_large_global_dev_...`, `tenpp_large_arch_dev_...`) record
exit FPUL = 0x80000000 for **every** row, and input FPUL = 3 for every
row. The reference's `FR4` at the `ftrc` was therefore always NaN, -Inf or
below -2^31 — never +Inf.

The only way to get that with `FR5 = 100.0` (the float at 0x0c06a478,
unchanged in the entry and exit RAM shadows) is for the reference's `R10`
to be **non-positive** (R10 = -1 gives -Inf; R10 = 0 gives NaN). Our port
has R10 = +1, which gives +Inf.

`R10` is produced by the REIOS dispatch stub at guest 0x0c0c66c8:

```
0c0c66c8: mov.l <table>,r0 ; mov.l <end>,r1 ; mov.l <dest>,r2
0c0c66ce: loop: r3 = *r0 ; *r2 = r3 ; r0 += 4 ; r2 += 4 ; until r0 == r1
0c0c66da: r0 = <dest> ; jmp @r0
```

`src/fight/matrix_adapters.c` models this as

```c
P_0c0c66c8: target = r[16];
             tmp = read(ram, r[4], 4);
             r[0] = tmp;
             s->pc = target; return ram->oob == 0;
```

i.e. `r0 = *(r4)` — an approximation of the BIOS service's return value.
`0x8C06A35C` then computes `R10 = r0 + R9`, and the approximation puts
`r0` one unit off the reference, flipping the sign of R10 and hence the
sign of the final quotient.

**Conclusion:** the fix is a faithful REIOS service model for the
0x0c0c66c8 / 0x0c0c66d8 dispatch family (the `docs/re/reios_exec_server.md`
cluster), not a change to float or FPU semantics. 570 B is not worth
hand-modelling one BIOS service for; it is worth doing as part of the
REIOS work, which also unblocks 0x8C064246's 72 failing cases and the
other GET_CMD_STAT/REQ_CMD owners.

## 4. What is left for 80%

80% is 347,725 B, i.e. 3,367 B beyond the current 344,358 B. The four
largest unported owners have **no** corpus at all
(0x8C0831F8 1,964 B, 0x8C08231C 1,892 B, 0x8C09575C 1,780 B,
0x8C0A1658 1,176 B), so the next step is a probe that reaches them, not
another ledger sweep — the shadowed-corpora pool is now mined out
(`tools/sweep_top.py --top 700` finds nothing above 130 B).

### 0x8C04D020 (888 B) — capsule gone, but re-capturable

Both of its corpora (`tenpp_large_global_dev_...`,
`tenpp_large_arch_dev_...`) keep a `capsule_manifest.json` but the
`capsule_*.bin` files themselves are deleted, so
`tools/regen_ram_shadows.py` has nothing to restore from and the corpus
replays as "no RAM cases". The `entry.patch` (828 KB) and
`batch_manifest.json` *do* survive, so the capture itself is re-runnable
with `tools/golden_batch.py` — that is the only route to these 888 B.

### 0x8C064246 (508 B) — 72 cases blocked on the REIOS stub

See section 3: the entry's own body is correct (437/509 in
`advance_natural_accept`, 64/64 + 384/384 + 192/192 in the other corpora);
the 72 failures are all `PC 0x0c001006`, the REIOS BIOS dispatch stub.
