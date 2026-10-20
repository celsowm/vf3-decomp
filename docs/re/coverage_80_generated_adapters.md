# Coverage 80% and beyond: the generated-adapter batches

Pure-C verified coverage crossed the 80% bar (347,725 B of the 434,656 B
frozen body denominator) and then some:

    78% bar   347,725 B
    batch 1+2 349,442 B  80.3951%   16 bodies, 5,084 B
    batch 3   352,776 B  81.1621%   17 bodies, 3,334 B
    total     352,776 B  81.1621%   33 bodies, 8,418 B

The 78% milestone had been crossed by promoting *ledger ghosts* — bodies whose
C already existed and replayed clean but had no `docs/decomp_status.csv` row.
That pool is finite and was mined out. The remaining gap needed **new C**, and
the lever for that turned out to be the repo's own adapter translator.

## The lever: `tools/oracle/translate_adapters.py`

Every large body in this game is SH-4 code in the identity image. The repo
already contains a translator that walks the CFG from a set of watch roots and
emits readable C with the FPU and memory helpers wired in:

    python tools/oracle/translate_adapters.py <capture dirs...> \
        --watch tools/watch/<batch>.txt \
        --out src/fight/vf3_<batch>_adapter.c \
        --function vf3_<batch>_adapter \
        --reuse-adapter 'src/fight/*.c'

Two inputs decide whether a body can be ported this way:

* the **capture directories**, which contribute the per-entry executed-opcode
  map (`f_<entry>.ops.json`) that seeds the CFG walk, and
* the **watch roots**, one `pc 0x8cXXXXXX` line per entry.

`--reuse-adapter` makes the generator skip every PC already owned by another
adapter, so a new module claims only the new territory. A root also pulls in
its own body ranges (`extract/analysis/function_body_ranges.csv`) and its
whole intraprocedural flow, which is what lets a root and its unported
callees land in one module.

The generator reports `0 unsupported instructions` for a batch, so a body that
the translator cannot express is a hard blocker, not a silent one.

## What was ported

Thirty-three bodies, in three generated modules. A root with an unported
callee is listed with that callee: the callee is a *gap* function (no body
range of its own, so no coverage credit) but the root's replay exercises it,
and the translator owns its flow.

### Batch 1+2 — `vf3_c80_adapter.c`, `vf3_c81_adapter.c` (16 bodies, 5,084 B)

| entry    | bytes | module             | evidence                                  |
|----------|-------|--------------------|-------------------------------------------|
| `0x8C0492BE` | 278 | `vf3_c80_adapter.c` | 3 corpora, 168 cases            |
| `0x8C0853FE` | 332 | `vf3_c80_adapter.c` | 3 corpora, 751 cases            |
| `0x8C083AA8` | 370 | `vf3_c80_adapter.c` | 1 corpus, 182 cases             |
| `0x8C046E66` | 470 | `vf3_c80_adapter.c` | 4 corpora, 1,084 cases          |
| `0x8C086B3A` | 384 | `vf3_c80_adapter.c` | 5 corpora, 1,040 cases          |
| `0x8C0889CC` | 322 | `vf3_c80_adapter.c` | 2 corpora, 735 cases            |
| `0x8C0C72E2` | 406 | `vf3_c80_adapter.c` | 1 corpus, 364 cases             |
| `0x8C0C7A88` | 348 | `vf3_c80_adapter.c` | 1 pruned corpus, 156 cases      |
| `0x8C04DDA8` | 388 | `vf3_c81_adapter.c` | 2 corpora, 162 cases            |
| `0x8C04F75E` | 276 | `vf3_c81_adapter.c` | 1 corpus, 256 cases             |
| `0x8C0BEF2E` | 258 | `vf3_c81_adapter.c` | 1 corpus, 384 cases             |
| `0x8C088DD4` | 246 | `vf3_c81_adapter.c` | 1 corpus, 253 cases             |
| `0x8C0993E8` | 250 | `vf3_c81_adapter.c` | 1 corpus, 320 cases             |
| `0x8C04F632` | 258 | `vf3_c81_adapter.c` | 1 corpus, 88 cases              |
| `0x8C04EA52` | 250 | `vf3_c81_adapter.c` | 1 pruned corpus, 126 cases      |
| `0x8C04ED8C` | 248 | `vf3_c81_adapter.c` | 1 pruned corpus, 125 cases      |

### Batch 3 — `vf3_c82_adapter.c` (17 bodies, 3,334 B)

| entry    | bytes | corpora | cases   | note                          |
|----------|-------|---------|---------|-------------------------------|
| `0x8C0871EE` | 294 | 2 | 529   | 2 further corpora pruned      |
| `0x8C03A07C` | 244 | 9 | 3,675 | shares a block with `motion_adapters_0.c` |
| `0x8C05E86A` | 228 | 3 | 688   |                               |
| `0x8C0C78E0` | 202 | 3 | 1,163 |                               |
| `0x8C08870A` | 196 | 4 | 998   |                               |
| `0x8C0884EA` | 190 | 5 | 783   |                               |
| `0x8C04EC8E` | 190 | 3 | 1,275 | 2 further corpora pruned      |
| `0x8C07B784` | 188 | 1 | 511   |                               |
| `0x8C0C3A26` | 188 | 2 | 885   |                               |
| `0x8C05961E` | 188 | 3 | 555   |                               |
| `0x8C0C7562` | 188 | 1 | 486   |                               |
| `0x8C0C8E7C` | 186 | 1 | 256   |                               |
| `0x8C08A7DE` | 184 | 4 | 474   |                               |
| `0x8C088B5C` | 182 | 1 | 254   |                               |
| `0x8C0C601C` | 164 | 3 | 804   |                               |
| `0x8C06AC7A` | 162 | 1 | 142   |                               |
| `0x8C08E028` | 160 | 1 | 238   | 1 corpus dropped, see below   |

Every one of these replays under `VF3_STRICT_REPLAY=1` with **zero skipped
cases** on a real captured corpus.

## Four checks that gate the credit

1. **Body completeness.** For each new entry, every PC of every Ghidra body
   range must be emitted by some adapter. The new modules own 3,083, 2,962
   and 3,830 PCs respectively; a body that is only *partly* translated would
   otherwise be credited for bytes it does not implement.
2. **No stolen routing.** A new adapter is inserted into the router chain
   ahead of the generic `matrix_adapters.c` fallback, so a new module can
   shadow an older owner. The pre-existing bindings whose entry is now owned
   by a new module were re-verified and all still pass: `0x8C04FE9E`,
   `0x8C0C66B8`, `0x8C068C72` (batch 1+2) and `0x8C0A2E8C`, `0x8C0A7F68`,
   `0x8C086B3A` (batch 3).
3. **Strict replay, zero skips.** A corpus whose per-row RAM shadows were
   pruned away replays as "N/N match, K skipped" and is *not* evidence.
   `tools/promote_replay.py` refuses such a corpus via `corpus_complete`.
   Three entries (`0x8C0C7A88`, `0x8C04EA52`, `0x8C04ED8C`) needed
   `tools/oracle/prune_corpus.py` to derive a complete subset: the pruned
   corpus keeps the original row ordinals and invents no state, it only drops
   the rows whose entry/exit RAM blobs are gone.
   The corpus list per entry is resolved by `tools/build_promote_csv.py`,
   which reuses `promote_replay`'s own `corpus_complete` so the two agree.
4. **Regression sample.** 400 random pre-existing bindings were re-run
   against their own test binaries: 400/400 PASS, after each batch.

### Two corpora dropped for a good reason

`0x8C08E028` also has a 3-row corpus in `percentage_loaded_states_dev` whose
row 2 has no RAM shadow. The harness compares that row against a stale image
and reports "mem win12 @+0x300: got 00 want 01" — a missing-blob artefact,
not a behavioural defect. `corpus_complete` excludes the corpus, and the
entry's remaining corpus (238 cases) passes with zero skips.

`0x8C082E0E` (186 B) was translated but **not** promoted: its corpus reports
`case 8: unsupported helper/state at 8c082e0e PC 0c082f28 (0 OOB)` — a real
defect, so the entry stays unported until the helper is understood.

## Two bodies that stayed out

### `0x8C0831F8` (1,964 B) — the oracle's RAM-window limit

This is the largest remaining unported body and its full body range *is*
implemented in `vf3_c80_adapter.c`; it is also called by `0x8C083AA8`, whose
182-case corpus replays clean, so its observable behaviour is exercised. It
is deliberately **not** credited, because it has no corpus of its own.

The reason it has none is worth recording. The `tenpp_large_global_dev`
campaign watched `pc 0x8c0831f8` with a 256-variant synthetic entry patch and
the emulator reached the entry on all 256 invocations — every specimen was
then rejected with `flags=4`. In `tools/emu/flycast/core/vf3oracle.cpp` the
`flags=4` bit is set when a capture exceeds the oracle's RAM window:

    constexpr unsigned PAGE = 4096, LIMIT = 128;   // 128 pages = 512 KB
    if (c.pages.size()==LIMIT) { c.flags|=4; continue; }

`LIMIT` is a compile-time constant, and `--probe-ops` is capped at 100000 by
`tools/golden_batch.py`, so neither knob can be turned from the capture side.
The body touches more distinct 4 KB pages than the oracle will track. Closing
this one needs either an oracle rebuild with a larger window or a capture that
reaches the entry on a narrower RAM footprint — not a C change.

### `0x8C0A8ACA` (544 B) — shadows deleted with their capsules

Its C is in `vf3_c81_adapter.c` and its body range is complete, but its three
corpora (`advance_resume_family_probe_dev`, `tenpp_large_arch_dev`,
`tenpp_large_global_dev`) keep the sidecars (`bank`, `dev`, `extra`, `gbr`)
and the `.cases` index while the `f_<entry>_<row>.in.bin` / `.out.bin` RAM
shadows were deleted along with the `capsule_*.bin` files. The replay harness
correctly reports "no RAM cases", and `tools/regen_ram_shadows.py` has nothing
to restore from. A fresh capture is possible — the `entry.patch` survives —
but the same `flags=4` rejection applies to the synthetic probe.

`0x8C04C9AE` (362 B) is the same shape: sidecars and a `.cases` index with no
RAM shadows at all.

## Tooling added

Committed:

* `tools/gen_translate.py` — turns a root list into a ready-made translator
  invocation, resolving each root's capture directories from the recorded
  `f_<entry>.ops.json` maps.
* `tools/body_complete.py` — proves every PC of an entry's Ghidra body ranges
  is emitted by some adapter, so a partly translated body is never credited.
* `tools/binding_steal.py` — lists the pre-existing golden bindings a new
  adapter would shadow, so they can be re-verified before the change lands.
* `tools/build_promote_csv.py` — resolves each entry's complete corpora and
  writes the promote CSV, so the corpus column is never hand-typed and always
  agrees with `promote_replay.py`'s own completeness rule.
* `tools/watch/vf3_c80_batch.txt`, `tools/watch/vf3_c82_batch.txt` — the
  watch roots of the two batches.
* `tools/watch/vf3_c80_0831f8.txt` — the 0x8C0831F8 capture recipe.

Scratch (gitignored, under `extract/analysis/`): `gap_map.py`,
`credit_map.py`, `cand_deps.py`, `next_group.py`, `next_batch.py`,
`verify_batch.py`, `body_owners.py`, `sample_check.py`.

## Reproducing

    python tools/gen_translate.py <roots...> \
        --watch-file tools/watch/vf3_c80_batch.txt \
        --out src/fight/vf3_c80_adapter.c --function vf3_c80_adapter
    # ... run the printed command ...
    # wire the module into matrix_family.c / matrix_family.h / CMakeLists.txt
    cmake --build build
    python tools/body_complete.py <roots...>
    python tools/binding_steal.py
    python tools/build_promote_csv.py <roots...> --out scan.csv
    python tools/promote_replay.py --scan scan.csv
    python tools/decomp_stats.py && python tools/final_status.py
