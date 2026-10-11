# Five-entry contact history

Callable `0x8c0c0bf4`, frozen owner `0x8c0c0c04`, updates the actor's
five-entry contact history. Its 16-byte setup and save prefix precedes the
648-byte eligible body and receives no extra credit.

The updater gates work on scene flags, interprets the incoming contact
record, writes character IDs and packed actor/contact bits, computes frame
deltas, and maintains the history's frame keys. A full history either resets
when its first entry has a reset flag or shifts the retained character,
flag, frame-delta and contact-bit arrays. Upper-bit contact cases preserve
the existing lower half-word. The reset path restores its own frame and
branches to the existing history-clear helper.

`src/fight/contact_history.c` contains structured C for this update and its
previously unsupported pattern-search and fallback-row dependencies. The
pattern search compares five character bytes across at most 128 rows; the
fallback selector retains the original column/length tie rules. This
milestone grants those dependencies **no additional coverage bytes**.
Parent qualification exercises pattern search and the disabled fallback
path; enabled fallback behavior still needs separate qualification.

Four development campaigns refined the fixtures. The first exposed null
input-table pointers, and the second exposed unsupported native helpers.
The helper port then exposed a scratch-register difference on the disabled
fallback branch, which was corrected. The third campaign still missed two
reset-path instructions. All superseded captures, reports and failed
executables remain pinned without coverage credit.

The fourth development campaign passes **126/126** valid original/native
comparisons; independent holdout passes **127/127**, with no native skips.
Both execute every eligible owner instruction. Two development interruptions
and one holdout interruption remain excluded. The accepted executable and
all **380 compiled source dependencies** were frozen before holdout.

Eight genuine caller windows from saved states 28 and 29 prove BSR
`0x8c0c045c`, its `R4=R14` delay slot, the original setup/save prefix,
saved stack values and actual return to `0x8c0c0460`. A second original
BSR at `0x8c0c04bc` and both helper call sites are included in affected-port
selection. No opcode ledgers are missing. The affected binding, all **39
native suites**, and **186 tool tests** pass; 190 default-build executables
are archived.

`tools/oracle/contact_history_v1_manifest.json` seals the original/native
proofs, excluded development history and percentage chain through contact
initialization and the full 60% checkpoint. The gain is **648 bytes**,
reaching **264,086 / 434,656 (60.76%)**. **18,441 bytes** remain to 65%.
The next full frozen inventory gate is required at 62.5%.
