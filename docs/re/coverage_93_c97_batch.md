# Coverage 93% — the c97 batch and the two port fixes it forced

## What the 500,000-instruction budget bought

The corpus-less pool held 249 entries (32,000 B).  The v2 extended observer
(`tools/oracle/build_extended_observer_v2.py`, built from the *patched* oracle
source, so it inherits the device-read policy and the 1024-page budget) can
record 500,000 instructions per probe.  Re-sweeping the pool with
`--probe-ops 500000` captured **8 bodies**:

| entry | bytes | distinct PCs | corpus |
|---|---|---|---|
| 0x8c07caa8 | 234 | 11,132 | `extract/analysis/u98_sweep/u98_sweep_8c07caa8` |
| 0x8c053dda | 218 | 5,258 | `extract/analysis/u98_sweep/u98_sweep_8c053dda` |
| 0x8c08a942 | 180 | 298 | `extract/analysis/u98_sweep/u98_sweep_8c08a942` |
| 0x8c0c2706 | 164 | 6,114 | `extract/analysis/u98_sweep/u98_sweep_8c0c2706` |
| 0x8c037248 | 154 | 1,042 | `extract/analysis/u98_pilot/…`, `u98_sweep/…` |
| 0x8c046320 | 144 | 1,634 | `extract/analysis/u98_sweep/u98_sweep_8c046320` |
| 0x8c0371c2 | 36 | 1,803 | `extract/analysis/u98_pilot/…`, `u98_sweep/…` |
| 0x8c04ba30 | 32 | 28 | `extract/analysis/u98_sweep/u98_sweep_8c04ba30` |

The other 241 entries still yield no corpus.  The pilot shows why and it is
**not** a budget artefact: with the full 500,000 instructions recorded the
specimen is rejected with flags=4 while the SH-4 spins inside the REIOS BIOS
polling a device register (the device tape at 0x1f000038/0x1f00003c fills up
at 16,384 entries).  The wall is the REIOS drive-state model
(`docs/re/reios_exec_server.md`), not the recorder.

The 8 bodies were translated with the repo's own translator
(`tools/oracle/translate_adapters.py`, 1,026 guest statements, **0 unsupported
instructions**) into `src/fight/vf3_c97_adapter.c`, wired into
`src/fight/matrix_family.h`, `src/fight/matrix_family.c` (chain line 688, right
after c96) and both `CMakeLists.txt` source lists.

## Two port fixes the strict replay forced

Both were found by the gate, not by inspection, and both are *global* port
semantics — every ported body benefits.

### 1. The replay step budget was smaller than the reference's own step count

`tests/matrix_family_replay.c` gave every case 100,000 steps.  The port spends
one step per emulated instruction, exactly like the oracle, so a body with a
counted loop could not finish inside the budget and the harness reported it as
an unimplemented helper:

```
case 4: unsupported helper/state at 8c04ba30 PC 0c04b9ee (0 OOB)
```

`0x8c04ba30` loads `r6 = 0x0000c620` (50,464) and calls the byte-copy loop at
`0x0c04b9e4`, whose body is six instructions — about 350,000 steps, more than
three times the old ceiling.  The budget is now **4,000,000**
(`tests/matrix_family_replay.c`).  The same wall explained 0x8c046320,
0x8c0371c2, 0x8c037248 and 0x8c08a942.

### 2. A device store must narrow its value to the access size

The SH-4 store path takes the value already narrowed to the access width
(`WriteMemU8` → `w8(unsigned, u8)`), and the oracle journals the narrowed
value in the device tape.  `vf3_matrix_write` passed the raw register, so a
byte store of a sign-extended register reached the device hook as `0xffffffb0`
where the reference had `0x000000b0`:

```
case 3: device access mismatch at 0/8: got W 00060192/1=ffffffb0, expected W 00060192/1=000000b0
```

`src/fight/matrix_family.c::vf3_matrix_write` now masks the value to the
access size before the device hook sees it (1 byte → 0xff, 2 bytes → 0xffff).

## The promotion

`tools/promote_replay.py` promoted **10 entries, 1,652 B** (the 8 new bodies
plus two that the device-store fix unblocked: `0x8c09aa14`, the entry the
frontier had recorded as "a device write the reference did not make", and
`0x8c04fbec`):

| entry | bytes | note |
|---|---|---|
| 0x8c09aa14 | 336 | the device-write wall retired |
| 0x8c07caa8 | 234 | new (c97) |
| 0x8c053dda | 218 | new (c97) |
| 0x8c08a942 | 180 | new (c97) |
| 0x8c0c2706 | 164 | new (c97) |
| 0x8c037248 | 154 | new (c97) |
| 0x8c04fbec | 154 | new to the ledger |
| 0x8c046320 | 144 | new (c97) |
| 0x8c0371c2 | 36 | new (c97) |
| 0x8c04ba30 | 32 | new (c97) |

Coverage: **92.0493% → 92.4294%** (400,098 B → 401,750 B of 434,656 B),
2,253 ledger entries.  `tools/decomp_stats.py` reports 405,354 B (93.3%) when
the trace-covered bodies are credited.

## The regression this forced

Both fixes touch shared code, so the whole ledger was re-gated with
`tools/check_new_bindings.py` (2,250 bindings, strict replay): **2250/2250
PASS**.  The native tick (`build/vf3` on the 13 captured fight states) still
matches the reference oracle byte for byte, with 0 unowned calls and 0
out-of-window accesses.

The same two fixes also unblocked the 23 bodies that were held in
`extract/analysis/tenpp_arch_fixed_held_cases` — they all replay clean now,
which retires the "REIOS GD vector" failure class recorded in
`docs/re/coverage_92_translator_gaps.md` (the vector's device write carried
the un-narrowed value).  Their bodies sit inside already-ported bodies, so
they add no coverage bytes, but they close the held backlog.

## What is still missing

- 241 entries (30,838 B) have no corpus at all: the reference spins in the
  REIOS BIOS polling a device register.
- 7 entries (≈190 B) are blocked by the REIOS GD vector: the port answers
  `r0 = 0` where the reference answers the transfer size (`0x12`, `0x32`,
  `0x8a`).  The per-case drive state is the missing evidence, exactly as
  `docs/re/coverage_92_translator_gaps.md` describes.
- 3 entries (8 B) are the literal-pool family: their bodies run into a
  literal pool and execute data in the reference.

See `docs/re/coverage_92_translator_gaps.md` for the standing frontier and
`docs/re/reios_exec_server.md` for the REIOS service model that the 241 need.

