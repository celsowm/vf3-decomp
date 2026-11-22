# From "boots + renders + readable cores" to "playable end-to-end"

Status call: the repo has a **100% body-range coverage ledger**, the port
**boots and renders** (ARM7 handshake solved, disc restored, request-for-request
load match), and the fight-engine's **state-7 tick is 101.1% readable
whole-tick-verified** (170 entries, `docs/readable_status.csv`).  All committed
native/readable leaves pass differential + full mutation gates.

That is real, but it is **not** "a fully playable VF3tb".  This document is the
precise, evidence-based gap list and roadmap between the two.  Written from the
verified artifacts in `docs/` and `src/`; it does not over-claim playability.

---

## 1. What is genuinely done (verified, not just covered)

- **Boot / render**: REIOS BIOS vectors, GD-ROM service (native_tick), ARM7
  firmware init ("INIT" handshake via `ARMRST`), ISO9660 disc reads in the
  reference's order, card/VMU check.  Attract fight ~95.48% frame match.
  (`docs/re/boot_*.md`, `native_tick.c`.)
- **Fight-engine scheduler tick (state-7)**: 170 entries `whole-tick` verified
  against the oracle = 101.1% of that tick's executed steps are readable ports.
  (`docs/readable_status.csv`.)
- **All native leaves**: 158 call-free FP/matrix leaves natively ported, each
  with a differential replay + a mutation gate that catches *every* observable
  mutation (`src/native/*`, `tests/*_native_*`).
- **Coverage**: 2398 baseline functions, 440,020 body bytes, 101.2%
  (`docs/coverage.md`).  **This is a ledger/body-range metric, not a
  playability metric.**

## 2. What "coverage" does NOT mean (the honesty section)

- **2557 of 2879 ported rows are `generated-adapter`** (`docs/decomp_status.csv`):
  faithful disassembly emitted by `tools/oracle/translate_adapters.py`, not
  hand-reviewed behavior.  They are byte-meaningful *to the oracle replay*, but
  they are not the readable/native quality the interesting cores have.
- **56 `unexercised` readable entries** — ported but never observed running (no
  oracle leg; proved only by differential == generated == "the same disasm").
  For these the readable == generated == oracle chain is missing the oracle.
- **The 100% body union counts overlapping/off-baseline leaves** and includes
  the `151 off-baseline` leaves the ledger also credits (`docs/coverage.md`,
  AGENTS.md).  The union number overstates how much of the *baseline* is
  meaningfully ported.

## 3. Known-failing gate cluster (things that still break)

From `docs/re/advance_progress.md` and `docs/re/reios_exec_server.md`:

- **GD-ROM firmware trap family**: e.g. `0x8c03523c`, `0x8c045f62` — the gate
  lists these as failing.
- **"device access mismatch" cluster** (`docs/re/reios_exec_server.md`): the
  port's address decode vs. the reference's own decode needs settling per the
  reference `sh4_mem.cpp`.
- **Corpus-blocked drives**: `docs/re/gd_drive_state.md` — the REIOS exec-server
  drive state model exists but four of five GD-family corpora predate the
  device-read observer and cannot be re-captured; the corner-block descriptor
  loop at `0x0c0510b6` depends on driver state the corpora don't carry.
- **`vtable_trampoline` (0x8C035CBA)** — untrustworthy, does not match the
  retained translation, `unexercised`; cannot be promoted.

These are the entries that make `tools/portcheck.py` non-green on logic today.

## 4. The real gap: "playable" = systems, not leaf count

The leaf/readable track covers the *engine math and the tick*.  A playable
game needs the **system layer**, which is largely generated-adapter or
unverified:

| System | State | What's needed |
|---|---|---|
| **Main loop / attract / demo** | boots, renders attract; demo fight ~95% | real play-loop verification vs a real-match oracle, not a savestate of a running game (`docs/re/boot_*.md`) |
| **Character select / menu / options** | not documented as verified | hand-port the UI/menu control flow (currently adapters) |
| **Input → move mapping** | `docs/re/offinv_and_pad.md`, `vf3sdlinput.exe` exists | verify the pad→fighter command path end-to-end in a match |
| **Stage selection & switch logic** | scene-0x0A predicate + walker known (`fight_dispatch_chain.md`) | verify stage progress across a real match |
| **BGM / sound / VMU** | ARM7 firmware boots; BGM voice-kit boundary known | full audio service + save/load of VMU blocks (boot does the card check, not a saved game load) |
| **The other 2,557 adapter bodies** | faithful disasm, replay-bounded | either hand-readable-port the behaviorally interesting ones, or accept adapter quality for the rest — a scope decision, not a bug |

The **attract fight is 95.48%**, not 100%, and the reference log is a
**save-state load**, not a boot — so no existing trace is an oracle for the
whole menu→fight→victory→menu loop (`docs/re/boot_data_blocked.md`).

## 5. Definition of "playable end-to-end" (proposed, testable)

We should agree *before* more work what counts as done.  A defensible bar:

1. `tools/portcheck.py` reaches **green on logic** (no failing *feature*
   entries; the corpus-availability exits are environmental, not feature).
2. A **real boot** (no savestate, `rom/vf3.gdi` + real disc) drives: title →
   menu → character select → a fight → stage switch → victory/menu return,
   **without a synthetic probe**, and the attract fight matches the reference
   at ≥99%.
3. **Input** (pad) drives a documented command path that lands in a verified
   readable move-selector/executor, covered by at least one whole-tick corpus.
4. The **56 `unexercised`** readable entries gain an oracle leg (a capture) or
   are explicitly downgraded to "differential-only" in the ledger so the status
   table is honest.

## 6. Suggested roadmap (in dependency order)

1. **Close the gate logic** — retire the GD-ROM trap + device-access-mismatch
   clusters (`docs/re/advance_progress.md`).  This is the single most concrete
   blocker and is already diagnosed.
2. **Get a real boot oracle** — capture a full boot→first-menu sequence with the
   working observer (the reference save-state log is insufficient, per
   `docs/re/boot_data_blocked.md`).  This unblocks verifying menus.
3. **Verify the play loop end-to-end** — one synthetic run that reaches the
   fight from a fresh boot; measure the match frame match vs the reference.
4. **Hand-port the user-facing systems** — menu select, pad→command, stage
   switch, save/VMU load, beyond the current adapters.
5. **Resolve the 56 `unexercised`** entries (capture or relabel).
6. **Decision on the 2,557 adapter bodies** — accept as "faithful but
   unreadable" or budget to hand-port the behaviorally significant ones.

---

### Bottom line

The native/readable leaf audit (the "all leaves" work) is **genuinely
complete** and each port is sound.  But "complete leaf audit" ≠ "playable
game".  The proven, hand-reviewed core is the boot + renderer + the fight
tick; the rest is adapter-covered and the system layer is unproven end-to-end.
The roadmap above is the concrete, evidence-backed path to a playable bar —
and step 1 (green gate on logic) is the immediate next milestone.
