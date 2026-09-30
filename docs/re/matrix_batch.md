# Matrix, pose and vector batch (2026-09-29)

## Delivered coverage

| Measure | Before | After | Gain |
|---|---:|---:|---:|
| Verified C address union | 16,822 B | 28,538 B | **11,716 B** |
| C union / frozen 434,656 B denominator | 3.87% | 6.57% | 2.70 percentage points |
| Ported baseline entries | 44 | 80 | 36 |
| Ported + SDK accounted entries | 313 | 348 | 35 |

This batch increases the C union by 69.6%. One new C entry was already SDK
attributed, so the combined accounted count increases by 35. SDK attribution
does not contribute to the new C-byte claim. Actual Ghidra body ranges define
the union; the existing 336-byte overlap is counted once.

The 36 newly credited entries are:

```
8c06939e 8c06e338 8c06f07a 8c06f46a 8c06f928
8c070022 8c0704f4 8c070ec0
8c07175e 8c07198a 8c071b1e 8c071c92 8c071ebe
8c08456e 8c0869c8 8c09132e 8c09144e 8c0955b0 8c09d480
8c09da86 8c09dc3c 8c09dcea 8c09e078 8c09e42c 8c09e4d0
8c09e6c8 8c09eaf2 8c09f076
8c0a71ac 8c0a7268 8c0a72a0 8c0a7866
8c0b011e 8c0b1376 8c0b1b8a 8c0bf16a
```

## Implementation and readability

`src/fight/matrix_family.c` implements affine point/direction transforms,
matrix multiplication, matrix-stack push/pop, reflection, rotation and
translation using C algorithms. The shared arithmetic milestone supplies
general FSCA, reciprocal square root, dot product and matrix-vector operations.
Twenty-one off-baseline helper entries are registered for dependency planning;
they receive **no additional byte credit** in this batch.

`src/fight/matrix_adapters.c` preserves caller register, stack and control-flow
behavior as generated static C. It contains no runtime opcode decoder or ROM
fallback. Its 27,903 guest statements include reachable dependencies and paths
absent from development captures. Only the named verified entries receive
credit. These adapters remain an intermediate representation with per-PC
labels; restructuring the caller bodies into named high-level algorithms is
still outstanding. The ledger calls this representation `ported-invocation`.

Original caller callbacks and jump tables are resolved from the identity image.
Calls preserve deliberate return-address rewrites. The generator checks
development instruction identities against that image, independently of
expected exit state. No captured output selects an implementation.

## Evidence and gates

There are 59 new strict replay bindings: 36 new baseline entries, 21 helpers,
and two previously credited entries tested at complete invocation boundaries.
Their selected corpora contain **9,314 cases**, all passing with zero skips and
zero out-of-bounds RAM accesses. Replay compares all integer/control registers,
FR/XF, FPUL, GBR, exact return PC, and every captured RAM byte.

Development used one fight capture. Independent validation included a boot
capture, five saved states, three shared-cohort states, and fresh held-out states
10, 24 and 44 with two input scripts. The final three captures took 44.486 seconds
total (13.864–15.879 seconds each), producing 947,179,740 capsule bytes. Capture
time alone excludes conversion, implementation and verification time.

The final fresh corpus passes 58/58 entry replays. The shared corpus passes
53/54; its sole failure is the uncredited caller described below. All selected
entries pass every archived final/shared/V4 proof in which they appear. Two
boot-only entries use independent V4 evidence; that older capture predates
shutdown summaries and retains successful emulator exit codes. Newer captures
account for every started invocation and contain no unfinished invocation.
Flagged interrupt, device, overflow and asynchronous-memory samples are excluded.

`tools/oracle/matrix_batch.json` records per-entry proofs, selected binding,
artifact count and SHA-256 corpus digest. Digests cover case descriptions,
register sidecars, opcode identities and RAM input/output files. The audit
checks strict bindings, complete proof counts, successful capture exits,
available summaries and the minimum 10,000-byte gain. `--hashes` rechecks every
archived artifact. The standard gate runs the audit and all bound replay tests.

```powershell
cmake --build build -j8
python -m unittest discover -s tests -p test_capsules.py
python tools/oracle/audit_matrix_batch.py --hashes
python tools/verify_all.py --no-build
```

Regeneration from the development corpus reproduces the adapter source exactly:

```powershell
python tools/oracle/translate_adapters.py extract/analysis/matrix_fight_cases --out extract/analysis/matrix_adapters.regenerated.c
Get-FileHash src/fight/matrix_adapters.c,extract/analysis/matrix_adapters.regenerated.c
```

Both SHA-256 values are
`f090b61ba8ddfc76d033aec40c2cc4a8001f92186c23fedd61ed2dd3c2f689cf`.

Build, eight capture-integrity checks, 212,992 arithmetic cases, existing
regression bindings, SDK verification and the complete verification gate pass.
Historical bindings retain their documented narrow boundaries and skips; this
batch does not reinterpret those historical results as complete invocations.

## Remaining limits

`0x8C072B50` is withheld despite passing the fresh final corpus: one shared-state
case reaches context-switch code at `0x0C0557E0` that needs unmodelled banked
architectural registers. `0x8C03B870` has only one complete boot invocation and
is not registered as an implemented helper. Unsupported instructions and
unmapped RAM fail closed. Supported arithmetic covers single precision with
nearest/truncate rounding; the oracle establishes interpreter agreement,
not hardware accuracy or proof over every possible input and branch.

The next batches can use `tools/batch_plan.py` to rank shared missing dependencies
by unique caller-byte benefit and closure cost. Those estimates receive no
coverage credit until the same strict replay and union checks pass.
