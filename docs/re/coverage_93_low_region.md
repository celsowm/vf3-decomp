# The low image region: the probe was jumping into RAM the loader never filled

## The symptom

The 241 entries with no corpus were not blocked by a budget, a device policy
or a service model.  Their probes simply **executed zeros**.

The game runs 1ST_READ from the RAM copy at 0x0C010000, but the loader only
places the part of the image the game actually reaches.  In every captured
state the region 0x0C010000-0x0C030000 is still zero, and no entry below
0x8C030000 had ever been ported:

| image region | functions | bytes | ported before |
|---|---|---|---|
| 0x8C010000-0x8C020000 | 29 | 4,152 B | 0 |
| 0x8C020000-0x8C030000 | 48 | 376 B | 1 |
| 0x8C030000-0x8C040000 | 248 | 25,876 B | 215 |
| 0x8C040000+ | 2,073 | 404,252 B | 1,912 |

The synthetic probe redirects the next fetch to the target's RAM alias
(`entry & 0x1fffffff`).  For an entry in the low region that address holds
zeros, so the CPU ran a straight line of `0x0000` (`MOV R0,@R0`) through
5,408 halfwords until it reached the erased 0xFFFF padding, raised an
illegal instruction and the oracle retired the specimen with flags=1.  The
recorded trace shows it exactly:

```
0c0115c2 0000   0c0115c4 0000   0c0115c6 0000  ...  0c014000 ffff
```

## The fix

`tools/oracle/ram_image_seed.py` writes the image's own bytes into the dead
region, using the oracle's two-field `VF3_RAM_PATCH` form ("addr value"),
which is applied **once at start-up** instead of per probe.  One 700 KB file
therefore serves a whole sweep.  `tools/oracle/isolated_probes.py` gained
`--ram-patch`, which passes it to the capture run spec.

With the fixture in place the probe runs the real code: `0x8c0115c2` went
from 17 rejected specimens to **6 complete cases, 341 executed PCs, 0
rejected**.

## The second half: counters seeded as pointers

The low region also exposed a seed problem.  The static inference
(`tools/oracle/pointer_seeds.py`) classifies the registers the target
dereferences; the rest fall back to the RAM arena, whose pointers are large
numbers.  A register the target only *counts* with then never terminates —
`0x8c011090` does `dt r5` inside its loop, so a counter seeded with
0x0C425000 counts down for 200 million iterations and the probe spends its
whole 500,000-instruction budget there.

`isolated_probes.py` now adds `--counter-variants N` (default 4): the extra
seed variants give the unclassified registers small values, while the
original pointer-style variants still cover the registers that only a callee
dereferences.  The two kinds are additive, so nothing that used to capture
stops capturing.

## What it produced

Four bodies were captured, translated through the repo's own translator (825
guest statements, 0 unsupported instructions) into `src/fight/vf3_c98_adapter.c`
and promoted:

| entry | bytes | cases |
|---|---|---|
| 0x8c0115c2 | 648 | 23 |
| 0x8c0113c2 | 368 | 14 |
| 0x8c010f42 | 258 | 16 |
| 0x8c010c2e | 184 | 10 |

Coverage: **92.4294% → 92.7649%** (403,208 B of 434,656 B), 2,257 ledger
entries.  `tools/decomp_stats.py` reports 406,812 B (93.6%) when the
trace-covered bodies are credited.

## What is left

The same sweep is re-running over the whole 249-entry corpus-less pool with
both fixtures.  The remaining causes are unchanged:

- the REIOS BIOS wall (a probe that reaches 0x8C008xxx spins in the loader),
- the GD-vector class (the port answers `r0 = 0` where the reference answers
  the transfer size),
- the literal-pool family.

See `docs/re/coverage_92_translator_gaps.md` and
`docs/re/reios_exec_server.md`.
