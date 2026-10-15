# Plan: native fight slice (2026-10-15)

Goal: move from "verified recompiled-by-capture fragments" to a native build
that runs a fight tick, with readable C progressively replacing generated C.

## Phase 0 - measurement (DONE, docs/re/exec_census_findings.md)
34% of executed block entries are outside the frozen baseline; one wait loop
(`0x8c059aea`) is 44% of fight hits; the hottest uncatalogued code is the
`0x8c0487a0` FPU transform cluster.

## Phase 1/2 - whole-tick differential harness
* `tools/tick_capture.py` - emulator fork, full 16 MiB RAM + registers at the
  entry and exit of any function (VF3_FULL + `rampc`), 64 MiB per pair.
* `tests/tick_replay.c` (`vf3tick`) - run the ported dispatcher from the
  entry state and diff regs + all RAM against the exit pair.
* Scheduler: the real function is **`0x8c09616a`** (count=27 at
  `0x0c29bb84`, table `0x0c1fe864`, stride `@+8`, enable bit `@+0`, handler
  `@+12`, r4 = record). The ledger's `0x8c096174` is mid-body.
* First run (state vf3_7): scheduler executes natively; first unsupported
  call = task handler `0x0c08b7ea`.

## Scaffold - recompiled reference build (refs/dream-recomp, gitignored)
The ported dispatcher only covers ~46% of fight work, so the tick stops at
the first uncovered handler. A static recompile of the whole image
(dream-recomp, GPL, kept in refs/ only - never committed here) gives complete
code coverage and a deterministic native oracle: run the scheduler tick with
captured RAM, diff, then replace translated functions with readable C one at
a time. This is a verification scaffold, not coverage credit.

## Phase 3 - readable hot path
Rank by census weight; rewrite against the oracle; `readable` ledger column.

## Phase 4 - other scenes
Same harness, other states.
