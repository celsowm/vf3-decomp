# Readable audio request and selection callers

`src/fight/audio_request.c` models callable entry `0x8c0c5c94` and the previously
credited 162-byte fragment owner `0x8c0c5ca2`. The fragment consumes the register
saves established by its prefix. Arguments `ffffffff` and `04a0` return `-1`.
Commands `05a0`, `02a0` and `03a0` encode channels 4 then 3. Command `001000a0`
encodes channels 1 through 7 with `001100a0`, parameter zero; `003000a0` visits
1, 2, 4, 5, 6 and 7. Ordinary commands use channel zero and the supplied
parameter. Calls use the original physical encoder alias; wrapper continuation
PCs preserve their own alias.

`src/fight/audio_input.c` models true entry `0x8c0c9f54`, whose frozen owner
starts at `0x8c0c9f62`. It reads a signed selection word and scene control bits,
changes the index by one or ten, wraps once within 458 slots, and reads the
shipped eight-byte lookup records at `0x0c101708`. It stores the selected index
before applying the lookup's special index adjustment. ID 5 supplies parameter
96. Other branches request the selected ID, `000200a0` or `001000a0`; the style
branch submits `003000a0` and invokes both actors' existing style helpers,
including the original tail call. Lookup IDs are preserved without assigning
unproved voice/reset meanings.

Development and acceptance use different saved states, stack addresses,
parameters, actor addresses and styles. **32 request comparisons and 36 input
comparisons** pass strict live and native replay with zero skips. Every live
comparison crosses a real AICA event. Both corpora cover all 162 request bytes
and all 188 input-owner bytes, including its discontiguous style tail. The
auditor checks original opcodes, register saves and stack restoration, and
captured immutable lookup bytes against the retail image. The ROM tables are
never patched to create otherwise unreachable IDs. Evidence is sealed in
`tools/oracle/audio_callers_live_v1_manifest.json`.

Actor cleanup's shared-encoder regression passes eight fresh live comparisons
in states 26/28 and both existing 128-case native corpora. Submission/style
also pass their 32 native cases against the current immutable executable.
`tools/oracle/audio_callers_live_v1_regression_scope.json` seals these checks,
39 freshly linked native suites, 86 tool checks, the full milestone hash chain
and the explicitly reused 1,363-binding baseline. Focused default-runner checks
cover both historical fragments and all three callable acceptance corpora.

The request owner was already credited; replacing its generated adapter adds
zero bytes. The input model is an **uncredited callable pilot**. A real caller
loads its target at `0x8c0c9208`, calls at `0x8c0c920a`, and uses literal
`0x8c0c926c = 0x0c0c9f54`. This one constant JSR site does not meet the existing
two-caller frozen-owner promotion gate. The gate has not been weakened and a
second caller has not been invented. Readable coverage remains
**258,502 / 434,656 (59.47%)**.

The callback tail reached from `0x8c099060` has since passed complete readable
C/live verification; see [audio_fight_caller.md](audio_fight_caller.md).
Its table-dispatch and multi-save-prefix promotion remains pending. Further
fight/scene callers, attributed song and reset transitions, later ARM dispatch,
DSP semantics and standalone playback remain open.
