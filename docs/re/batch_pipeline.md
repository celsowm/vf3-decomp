# Batch decompilation pipeline

## Starting point and acceptance rule

At `bb4bdd3`, the ledger has 44 baseline C ports plus 19 off-baseline
leaves: 17,158 summed bytes and **16,822 unique address bytes**. The frozen
inventory remains 2,398 functions / 434,656 body bytes. SDK attribution is
separate from executable source. The initial delivery target is at least
10,000 additional unique C bytes, with replay evidence for the batch.

`Vf3BodyRanges.java` exports the actual Ghidra address ranges. Their lengths
must agree with every frozen inventory row before `decomp_stats.py` computes
the union. Entry plus body size is insufficient for fragmented functions.
Off-baseline ledger leaves retain their explicitly bounded intervals.

## Invocation capture

Install the research observer into the existing ignored interpreter fork:

```powershell
python tools/oracle/install.py
cmake --build tools/emu/flycast-build -j8
```

The observer operates before instruction execution and memory accesses.
Each watched invocation has an independent ID, saved call depth, PR and SP.
Nested calls therefore cannot be paired using FIFO order. Exit snapshots
are taken after the return or configured transfer's delay slot.

VF3CAP4 records contain:

- Original entry/exit PC, invocation ID and invalidity flags.
- R0–R15, PR, SR, FPSCR, MACL/MACH, FR0–FR15, XF0–XF15, FPUL and GBR.
- Each first-touched 4 KiB RAM page before modification and at exit.
- Executed instruction PCs/words, checked against the untouched identity image.

All read/write widths are observed, including pages first reached by a
callee. Bounds are 128 pages, 64 simultaneous invocations and 100,000
instructions per invocation. Invalidity flags are interrupt/exception/RTE
(1), MMIO or MMU access (2), capture overflow (4), and asynchronous memory
copies (8). Invalid specimens receive no replay credit. A shutdown summary
accounts for every started invocation; unfinished records carry flag 16 and
are excluded. A missing summary is reported for older captures.

The converter checks lengths, page alignment, unique IDs and instruction
identity. Deduplication includes all input registers and initial RAM.
Identical inputs with contradictory outputs are an error. XF, FPUL, PC and
GBR sidecars remain aligned with each `.cases` row after deduplication.

```powershell
python tools/golden_batch.py --name matrix --watch tools/watch/vf3_matrix_batch.txt `
  --out extract/analysis/matrix_cases --max-samples 64 --capsule `
  --run fight:extract/analysis/vf3_fight_keep.state:extract/analysis/vf3_play_actions2.txt:600
```

Capsule runs omit redundant legacy instruction/snapshot logs. Timing, exit
status and capture byte counts are retained in `batch_manifest.json`; a
failed emulator run cannot export goldens. ROMs and captures stay ignored.

## Shared floating point semantics

`sh4_fpu.c` supplies FSCA, FSRRA, FIPR, FTRV, FLOAT, FTRC, basic arithmetic,
square root and multiply-add. Each arithmetic call restores the host floating
point environment. FPSCR.DN is bit 18; FR is bit 21. PR=1 and reserved rounding
modes are rejected. Single precision RM=nearest/truncate is modeled.

FSCA's coefficient ROM comes from executing all 65,536 angles in the isolated
opcode observer, rather than a game-input catalog. Its raw-pair SHA256 is
`6eb3507e019ffec26d0729441977fd2a29fc769185da896c6bd66df2991961c9`.
The half-table is generated only after all sine/cosine symmetry relations pass.

The additional suite exercises FSRRA, FIPR, FTRV, FLOAT, FTRC and FMAC with
edge values and deterministic randomized inputs under FPSCR values `0`, `1`,
`0x40000`, `0x40001`, `0x240000` and `0x240001`. **212,992/212,992** opcode
cases match, including host-environment restoration. This establishes agreement
with the local interpreter; it is not a hardware accuracy claim.

```powershell
$env:VF3_INTERPRETER='1'
$env:VF3_TRACE_FRAMES='240'
$env:VF3_OPCODE_ORACLE='E:/vf3-decomp/extract/analysis/fsca_modes.bin'
tools/emu/flycast-build/flycast.exe rom/vf3.gdi
Remove-Item Env:VF3_OPCODE_ORACLE
python tools/oracle/fsca_table.py extract/analysis/fsca_modes.bin
build/vf3fpu.exe extract/analysis/fsca_modes.bin
python -m unittest discover -s tests -p test_capsules.py
```

Five existing vector models now compute reciprocal-square-root scales through
the shared arithmetic rather than finite norm/scale catalogs. Their original
branch and boundary contracts remain documented in their individual notes;
the original replay bindings all pass.

## Source and evidence boundaries

The batch uses hand-written matrix/vector algorithms and static C adapters
for guest register, stack and caller control flow. The adapters contain no
runtime instruction decoder or ROM execution fallback. They are generated
from development instruction identities and the original binary's reachable
branches, including branches absent from the development trace. Unknown
destinations or unsupported architectural state return failure.

Generated adapters are an intermediate source representation. Their per-PC
labels preserve reviewable ABI behavior; further restructuring into named
caller algorithms is still work. Generated statements alone receive no
coverage credit. Only named, golden-bound entry points that pass complete
register, XF, FPUL, GBR, return-PC and RAM replay are promoted.

New bindings use `strict: true`: skipped cases fail. Historical bindings with
narrower boundaries retain their historical behavior and are not upgraded
by this batch. `verify_matrix.py` fails its default gate if any selected entry
fails; `--discover` is explicitly for finding remaining unsupported entries.

`port_plan.py` keeps the complete missing dependency list and separately
reports executable implementation closure. `batch_plan.py` ranks shared
dependencies by potential unique caller bytes relative to estimated closure
work. Its scores are planning estimates, not achieved coverage.
