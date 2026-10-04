# Expanded whole-body evidence

The frozen readable-C union is **200,612 / 434,656 (46.15%)**, up
**8.771 percentage points** from 162,490 bytes. Another **5,344 bytes**
are required for the requested ten-point gain.

The recovery-small milestone adds 19 functions and 552 unique bytes.
The expanded module adds the statistics body at `0x8c0698fc` (2,364 bytes),
two medium bodies (562 bytes), and a floating-point body (476 bytes).
Every credited body executes completely, has at least 64 distinct inputs
from two development scenarios, and passes independent strict acceptance.

Statistics replay passes **1,000/1,000** development and **249/249** acceptance
cases. The two medium bodies pass **1,018/1,018** development and
**509/509** acceptance cases. The floating-point body passes **766/766**
development and **255/255** acceptance cases. Acceptance relocates fixture
pointers by `0x100000` and changes the input palette and deterministic seed.

## Oracle conversion correction

The previous statistics capture failed 29 of 1,000 strict cases. In case 137,
the last FTRC instruction at `0x0c069fd6` consumed positive infinity in FR4.
The emulator produced `0x80000000`; the C port produced `0x7fffffff`.
The emulator cast an out-of-range floating value to a signed integer before
trying to correct overflow, which invokes undefined C++ behavior.

The [Renesas SH-4 Software Manual](https://www.renesas.com/en/document/mas/sh-4-software-manual),
section 9.46, specifies `0x7fffffff` for positive overflow and positive
infinity when the invalid-operation exception is disabled. Negative overflow
and NaN produce `0x80000000`. The installer now checks those bounds before
casting. The opcode correction uses the manual's conversion values; it does
not consult port results. Existing exception-flag behavior is unchanged.

Both statistics evidence sets were captured again with the corrected oracle.
The failing pre-correction capture and report remain under `extract/analysis`.
No replay gate or case comparison was relaxed.

The statistics fixture declares only the original mutable record
`0x0c11e540..0x0c11e860` writable within the loaded image. The frozen function
entry is inside its prologue, so its already-established R0 offset is supplied
as 120. Code and literal pools are not patched. Instruction inference now
tracks MOVA, masked flags, indexed stores, and simple original getter calls.

## Reproduction records

Four manifests record hashes, body intervals, strict reports and exclusions:

- `tools/oracle/tenpp_recovery_small_milestone.json`
- `tools/oracle/tenpp_statistics_milestone.json`
- `tools/oracle/tenpp_medium_expanded_milestone.json`
- `tools/oracle/tenpp_floating_milestone.json`

Expanded static C lives in `src/fight/tenpp_expanded_adapters.c` and emits
6,909 statements with zero unsupported instructions. Additional exploratory
roots in the module receive no credit. Strict replay used the immutable
`build/vf3matrixfamily_expanded.exe` snapshot. Full regression is being rerun
after the new dispatch ownership was installed.
