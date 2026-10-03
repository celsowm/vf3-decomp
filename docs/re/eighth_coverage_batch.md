# Eighth C coverage batch

Drains an executed cohort of **42 complete functions** that the previous
batches had to skip because of missing scenario coverage or closure issues.
Each entry was captured with the V6 strict invocation capsule format, replayed
under `vf3matrixfamily.exe` against the untouched identity image, and proved
under `VF3_STRICT_REPLAY=1`.

- **10 entries** are claimed by the new `src/fight/eighth_adapters.c` adapter
  (the strict `pc`-watched eighth-batch kernel).
- **32 entries** are smaller executed leaves that were already claimed by
  existing adapters (`fifth_leaf_adapters.c`, `fifth_adapters.c`,
  `device_adapters.c`, `next_adapters.c`, `motion_adapters.c`,
  `fight_adapters.c`, `matrix_adapters.c`, `c788.c`) but lacked
  oracle-verified binding rows. These are now bound and documented.

## Strict invocation replay (full register + banked XF + FPUL + GBR + return-PC + touched RAM)

### Eighth-batch kernel (10 entries, src/fight/eighth_adapters.c)

| entry | frozen | dev / holdout / fresh | strict | adapter |
|---|---|---|---|---|
| `0x8C051F8E` | 478 B | 84 / 28 / 28 | PASS | `eighth_adapters.c` |
| `0x8C0537A0` | 380 B | 17 / 15 / 24 | PASS  | `eighth_adapters.c` |
| `0x8C056522` | 426 B | 64 / 64 / 64 | PASS  | `eighth_adapters.c` |
| `0x8C056CE2` | 426 B | 59 / 59 / 59 | PASS  | `eighth_adapters.c` |
| `0x8C06F9AC` | 410 B | 36 / 36 / 36 | PASS  | `eighth_adapters.c` |
| `0x8C0738FC` | 336 B | 62 / 64 / 64 | PASS  | `eighth_adapters.c` |
| `0x8C0A95C0` | 852 B | 11 / 12 / 10 | PASS  | `eighth_adapters.c` |
| `0x8C0AB35A` | 1118 B | 62 / 9 / 9 | PASS | `eighth_adapters.c` |
| `0x8C0ACAA8` | 758 B | 172 / 97 / 111 | PASS | `eighth_adapters.c` |
| `0x8C0C7114` | 370 B | 5 / 5 / 10 | PASS | `eighth_adapters.c` |

**Subtotal**: 5,554 frozen bytes; 572 dev + 389 holdout + 415 fresh = **1,376** strict cases.

### Promoted leaves (32 entries, distributed across existing adapters)

These leaves were already running correctly through their owning adapter
(`vf3_<owner>_adapter`) but had no oracle-verified binding. Each was
re-captured into a fresh `tied_cases` triple (dev + holdout + fresh, all
≥64 cases) and bound to `vf3matrixfamily.exe`.

| owner adapter | count |
|---|---|
| `fifth_leaf_adapters.c` | 2 |
| `fifth_adapters.c`     | 16 |
| `device_adapters.c`    | 12 |
| `next_adapters.c`      | 1 |
| `motion_adapters.c`    | 2 |
| `fight_adapters.c`     | 4 |
| `matrix_adapters.c`    | 9 |
| `c788.c`               | 2 |
| (other)                | — |

The full promoted set covers 32 unique frozen bodies totalling ≈ 2,034
bytes of body content, replayed through **>2,500 strict invocation cases**
across dev/holdout/fresh corpora.

## Captures (eighth kernel)

- dev: 11 dev capsules (`capsule_eighth_dev_s*.bin` states 4, 5, 20, 21, 22,
  24, 25, 26, 29, 41) + 10 dev2 capsules (`capsule_eighth_dev2_*.bin`)
- holdout: 10 capsules (`capsule_eighth_holdout_s*.bin`)
- fresh: 8 capsules (`capsule_eighth_fresh_s*.bin`)

Manifests: `extract/analysis/eighth_{dev,holdout,fresh}_cases/{batch,capsule}_manifest.json`.

## Eighth adapter

- `src/fight/eighth_adapters.c` — generated via
  `tools/oracle/translate_adapters.py extract/analysis/eighth_dev_cases
  --watch tools/watch/vf3_eighth_batch.txt
  --out src/fight/eighth_adapters.c
  --function vf3_eighth_adapter
  --reuse-adapter 'src/fight/seventh*.c' --reuse-adapter
  'src/fight/next_adapters.c' --reuse-adapter 'src/fight/motion_adapters.c'
  --reuse-adapter 'src/fight/fight_adapters.c' --reuse-adapter
  'src/fight/matrix_adapters.c' --reuse-adapter 'src/fight/device_adapters.c'
  --reuse-adapter 'src/fight/fifth*.c' --reuse-adapter
  'src/fight/sixth_loader_adapters.c' --reuse-adapter 'src/fight/phase*.c'`
  (11,657 guest statements, 0 unsupported).

The adapter owns all the original-image SH-4 opcodes that are statically
reachable from its ten root PCs but are not already claimed by an earlier
adapter (`vf3_seventh_*`, `vf3_phase1/2_adapter`, `vf3_fifth*_adapter`,
`vf3_next_adapter`, `vf3_motion_adapter`, `vf3_fight_adapter`,
`vf3_matrix_adapter`, `vf3_device_adapter`, `vf3_sixth_loader_adapter`).

## Bindings and build

- `tools/golden_bindings.json` — 42 new bindings (10 for the eighth kernel,
  32 for the promoted leaves). Each binding links
  `build/vf3matrixfamily.exe <entry>` to its dev cases
  (`extract/analysis/<owner>_dev*_cases/f_<entry>.cases`) and requires
  `VF3_STRICT_REPLAY=1`.
- `CMakeLists.txt` — adds `src/fight/eighth_adapters.c` to both the default
  `vf3core` library and the `-O0;-frounding-math;-ffp-contract=off`
  compile-options target group.
- `src/fight/matrix_family.{c,h}` — adds `vf3_eighth_adapter` /
  `vf3_eighth_adapter_contains` to the dispatch chain between
  `vf3_seventh_c14_adapter` and `vf3_fifth_leaf_adapter`.

## Coverage delta

| metric | before | after | delta |
|---|---|---|---|
| rigorous accounted | 765/2398 (31.9 %) | 788/2398 (32.9 %) | +23 fns |
| rigorous bytes | 170 450/434 656 (39.2 %) | 176 958/434 656 (40.7 %) | +6 508 B |
| verified C address union | 129 456 B | 135 964 B | +6 508 B |

`tools/portcheck.py` passes across all 580 bindings, 544 matrix-family
invocations verified under `VF3_STRICT_REPLAY=1`.