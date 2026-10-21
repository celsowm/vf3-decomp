# Evidence import audit — 2026-10-21

The supplied evidence enables local fixture replay, but does not close the
native-tick, boot, or whole-game equivalence checks. Six boundary fixtures lack
all of their referenced RAM payloads. No exact recovery source for those
payloads was identified in the supplied package.

This audit examined manifests, case descriptors, the complete archive member
listing, and the replay/parser source. It did not change captured inputs,
expected outputs, or the canonical binding manifest. Oracle build and control
provenance are covered separately in
[ORACLE_REPRODUCIBILITY_AUDIT.md](ORACLE_REPRODUCIBILITY_AUDIT.md).

## Input identity and inventory

The supplied `vf3tb-evidencias.7z` has SHA-256
`54321df882df8b2153ab7cd1632890036b38ccecc29d1481c3b0c6685a85447e`.
Its binding specifications match all 2,250 canonical specifications except for
30 relocated `golden` paths. The local import records those relocations in
`extract/analysis/evidence_import/supplied_binding_relocations.json` and uses
`extract/analysis/evidence_import/golden_bindings.local.json` for replay.
Path relocation is not a change to expected results.

The initial `vf3-evidence-preflight.json` snapshot reports:

| Input | Required | Present | Missing |
| --- | ---: | ---: | ---: |
| Golden fixtures | 2,250 | 2,250 | 0 |
| Distinct named RAM payloads | 940,034 | 934,626 | 5,408 |
| Required XF/extra sidecars | 6,612 | 6,612 | 0 |
| Frozen coverage CSVs | 2 | 2 | 0 |
| Native-tick artifacts, across 13 states | 39 | 0 | 39 |
| Boot trace artifacts | 17 | 0 | 17 |
| GD state companions | 15 | 15 | 0 |

The bindings comprise 2,202 marked strict and 48 unmarked entries; 2,249 golden
files use `.cases`. The two imported executable paths match the expected retail
SHA-256 `37f38dd9a47b785f526157c4a1674ca75322f0de1342f64bbf33c88d128e4b32`.
The inventory checks file availability and minimum payload sizes. It executes
no replay and establishes no current coverage percentage or playability claim.

The initial native replay baseline was **2,162/2,250 PASS, 88 not-PASS** in
`vf3-evidence-bindings.log`. This is a **preliminary, pre-fix baseline**; code
repairs and a complete rerun are being recorded separately. It is not the final
validation result, and its denominator counts bindings rather than game states
or unique functions.

## Six unavailable RAM corpora

All directories below are relative to `extract/analysis/`. Their `.cases`
files are present and structurally valid. Each row names both entry and exit
RAM, and every such named payload in these six fixtures is absent. The C
harness therefore skips all rows and exits with `no RAM cases`.

| Directory / fixture | Rows | Missing payloads | Required bytes per payload |
| --- | ---: | ---: | ---: |
| `goldens_070120_boundary_cases/f_0c070120_boundary.cases` | 128 | 256 | 16,300 |
| `goldens_07030c_boundary_cases/f_0c07030c_boundary.cases` | 128 | 256 | 16,300 |
| `goldens_0706c4_narrow/f_0c0706c4_boundary.cases` | 2,128 | 4,256 | 216 |
| `goldens_070x_boundary_cases/f_0c0708b0_boundary.cases` | 64 | 128 | 23,420 |
| `goldens_070a84_boundary_cases/f_0c070a84_boundary.cases` | 128 | 256 | 16,300 |
| `goldens_070cf0_boundary_cases/f_0c070cf0_boundary.cases` | 128 | 256 | 16,300 |
| **Total** | **2,704** | **5,408** | |

This is also a compact, exact missing-file specification:

- The four 128-row directories need `e000.bin` through `e127.bin` and
  `x000.bin` through `x127.bin` in each directory.
- `goldens_070x_boundary_cases` needs `e00.bin` through `e63.bin` and
  `x00.bin` through `x63.bin`.
- `goldens_0706c4_narrow` needs both `_in.bin` and `_out.bin` for
  `8c070734_0000` through `8c070734_1094`, `8c070766_0000` through
  `8c070766_0468`, `8c070774_0000` through `8c070774_0026`, and
  `8c0707ae_0000` through `8c0707ae_0536`.

The complete archive listing contains none of these exact paths. Related
capture manifests refer to the following raw traces, also absent by exact
basename throughout the archive, including `external_capture_mirror/`:

| Capture manifest directory | Referenced trace basename |
| --- | --- |
| `goldens_070120_boundary128_ram` | `golden_golden_070120_boundary128_ram_fight.bin` |
| `goldens_07030c_boundary128` | `golden_golden_07030c_boundary128_fight.bin` |
| `goldens_0706c4_narrow` | `golden_golden_0706c4_narrow_fight.bin` |
| `goldens_070x_boundary` | `golden_070xboundary_fight.bin` |
| `goldens_070a84_boundary128` | `golden_070a84_boundary128_fight.bin` |
| `goldens_070cf0_boundary128` | `golden_golden_070cf0_boundary128_fight.bin` |

Their common source state, `vf3_fight_keep.state`, is absent as well. The
earlier `golden_golden_070120_boundary128_fight_fight.bin` trace is also absent.
These manifests record `runs[].trace`, not a capsule source. Five affected
fixture directories contain only the `.cases`; the narrow 0706c4 directory
also contains its batch manifest. Related JSON exports from other campaigns
do not establish the same invocation identity or missing payload bytes.

`tools/regen_ram_shadows.py` is not a recovery source for these fixtures. It
requires an original capsule, generates `f_<PC>_<n>.in.bin`/`.out.bin`, and
accepts regenerated payloads only after byte-identical `.cases` comparison.
No supplied manifest identifies an exact capsule for these boundary rows.
The 0706c4 reproduction recipe instead uses `pair_cases.py` on the original
trace followed by `merge_case_sets.py`; the trace and intermediate route
corpora are not supplied. Registers, window addresses, and lengths alone do
not determine the missing RAM contents.

Recovery therefore remains **unavailable from the identified evidence**.
Closing it requires the original payloads, or the exact source capture and
pairing provenance sufficient to reproduce the existing descriptors and RAM
bytes. A fresh capture would be new evidence. Copying same-name payloads from
another campaign, inventing zero-filled RAM, or changing expected outputs
would not restore these historical cases.

## The 700 no-RAM rows are valid but skipped

All 700 entries under preflight's `case_evidence.parse_errors` have the message
`no entry RAM shadow; C harness would skip this row`. They are not malformed
case syntax. Of these, 652 use the valid v2 tail `- 0 - 0`; 48 use the legacy
two-window form with zero bases and lengths. The current JSON key groups this
replay-completeness gap with parsing failures.

These rows occur in 14 unmarked bindings. Paths below are relative to
`extract/analysis/`; the final column counts rows that actually declare RAM,
not an independent replay result.

| Fixture | Total rows | No-RAM rows skipped | RAM-bearing rows |
| --- | ---: | ---: | ---: |
| `goldens/f_0c068ff6.cases` | 64 | 48 | 16 |
| `goldens_73fb4/f_0c073fb4.cases` | 64 | 56 | 8 |
| `goldens_78044/f_0c078044.cases` | 64 | 56 | 8 |
| `goldens_ab/f_0c0748c0.cases` | 20 | 12 | 8 |
| `goldens_ab/f_0c092abe.cases` | 64 | 56 | 8 |
| `goldens_ab/f_0c092f12.cases` | 64 | 56 | 8 |
| `goldens_ab/f_0c0c2b80.cases` | 20 | 12 | 8 |
| `goldens_afb76/f_0c0afb76.cases` | 64 | 56 | 8 |
| `goldens_b7/f_0c08b7ee.nowin3.cases` | 64 | 56 | 8 |
| `goldens_c788_force4/f_0c08c788.cases` | 156 | 92 | 64 |
| `goldens_cascade/f_0c076c00.cases` | 64 | 56 | 8 |
| `goldens_cascade/f_0c077e4e.cases` | 64 | 56 | 8 |
| `goldens_e16/f_0c068e16.cases` | 64 | 32 | 32 |
| `goldens_s2b/f_0c0930b6.cases` | 64 | 56 | 8 |
| **Total** | **900** | **700** | **200** |

All associated runners use `vf3h_harness_main` in `tests/port_harness.h`.
Its parser accepts these descriptors; `vf3h_mem_load` rejects the absent
entry mapping, and the harness increments `skipped`. Without strict replay,
PASS requires every executed row to match and at least one row to execute,
but permits skips. With `VF3_STRICT_REPLAY`, any skipped row prevents PASS.
Thus a PASS for one of these unmarked fixtures validates its executed
RAM-bearing subset under that runner's comparisons; it does not validate the
700 omitted register snapshots or the complete original capture.

The skipped rows do not name missing files and are separate from the 5,408
missing payloads above. Both are completeness limits, but their remedies
differ: restore exact missing payloads for the six boundary fixtures; obtain
suitable RAM captures or a justified register-only replay contract for the
explicit no-RAM rows.

## Repairs established by the imported evidence

- `c6ec4.c` wrote SR/FPSCR outside a 16-word register array. Returning the two
  scalars directly changes the fixture result from process abort to 64/64
  matches, with zero skips. ASan/UBSan also pass on those cases.
- `sh4_fpu.c` now pins NaNs generated by invalid operations to the frozen x86
  oracle's negative quiet NaN. FMAC explicitly selects the first NaN in
  FR0/FRm/FRn order, preserving its sign/payload and quieting signaling NaNs.
  This avoids Apple ARM `fmaf` selecting a different operand or overriding
  an input NaN when the product is zero times infinity. The x86 priority is
  documented in [Intel SDM volume 1, table 14-17, printed page 14-23](https://cdrdv2-public.intel.com/671436/253665-sdm-vol-1.pdf).
  The mapping to guest operands is supported by the captured fixture traces;
  it is not a claim of hardware-certified SH-4 NaN behavior.
- The ROM-free FPU suite exercises 432 checks across rounding/denormal modes,
  invalid arithmetic, supplied NaNs, payload selection and host rounding-mode
  preservation. The suite also passes with ASan/UBSan.
- An attached GD-ROM now handles live BIOS requests before capture-only REIOS
  adapters. The ROM-free regression fails 19 assertions against the prior
  implementation and passes with the fix. Captured no-drive behavior is kept.
  The real-disc test also passes the 75-sector DMA cycle, seven syscall reads,
  and resumptions of 70 and 739 sectors for states 24 and 25, with no differing
  bytes and no skipped optional resume checks.

These repairs do not add coverage credit or close cold boot, rendering, audio,
or whole-game acceptance. Captures and comparison strictness were unchanged.
