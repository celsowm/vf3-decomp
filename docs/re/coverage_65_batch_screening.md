# Original execution screening for the 65% session

Baseline remains **267,230 / 434,656 bytes (61.48%)**. These experiments
grant **zero C coverage**. The target remains 282,527 bytes, with 15,297
verified bytes outstanding. The 62.5% and 65% full inventory gates remain
required by [the execution plan](coverage_65_one_session_plan.md).

## Captured evidence

All pilots execute the untouched original image in the fixed interpreter
observer, in save states 26 and 27. They vary typed controller records,
task descriptors, replay boundaries and owned RAM. Original instructions,
callback tables and architectural outputs are not fixture values.

| Pilot | Scope | Complete-body observations | Incomplete invocations | C credit |
| --- | --- | --- | ---: | ---: |
| `coverage_65_batch_screen_dev_v1` | 12 roots, 6,534 candidate bytes | initializer 94; geometry callback 750 | 1 | 0 |
| `coverage_65_batch_screen_dev_v2` | same roots; independent controller and selector dimensions | initializer 94; replay interpolation 158; geometry callback 750 | 1 | 0 |
| `coverage_65_batch_expand_dev_v1` | seven more roots, 6,714 candidate bytes | none | 0 | 0 |
| `coverage_65_batch_boundary_dev_v1` | four roots; crossed parameter limits, bounded history descriptor and circular lists | list interpolation 598 | 0 | 0 |

Whole-body observations above are unions of valid original specimens in
each pilot. They are research evidence, not development/holdout acceptance.
The first two campaigns are excluded from promotion because they contain
incomplete invocations. No routine has received a new binding or C credit.

The fourth pilot records 383 valid settings-menu invocations, 359 valid
list-interpolation invocations, 384 valid scene invocations and 384 valid
timed-effect invocations. It retains 24 rejected non-RAM list specimens
and two interrupted specimens. The circular-list fixture permits a stale
node to become detached in some combinations; those results stay excluded.
Its body observations are respectively 654/664, 598/598, 420/488 and
498/512 bytes. Neither a partial body nor a rejected invocation is waived.

The larger expansion completes both campaigns without incomplete
invocations. Its largest routines execute 698/2,084 bytes in the controller
menu and 876/1,574 bytes in character selection. They need further selector
and timer combinations before being eligible for promotion. The round-scene
candidate at `0x8c0996f4` also encounters SDK/BIOS exception and budget paths;
its 536/1,172-byte observation is not evidence that those dependencies work.

## Original callers and fixture findings

The original scene table at `0x0c10baa8` contains the menu/scene pointers
listed in each report. Their true callable entries precede the frozen owner
by their saved-register prologues. Pointer locations are static target
evidence; the reports explicitly mark executed callable proof as pending.

Two additional real transfers were checked in the untouched cached-address
disassembly:

- `0x8c090b76` loads the list-interpolation target from `0x8c090bc8`;
  `0x8c090b78` executes `JSR @r2`, with `R4 = R13` in its delay slot.
- `0x8c0c31de` branches to character selection at `0x8c0c3210`, after
  restoring the parent frame; its delay slot restores R14.

The list's interval test is **FR15 > FR14**, not the reversed comparison.
The replay-history index is loaded from the descriptor at global
`0x0c29bbd4`, offset 16. Bounding only the scene counter does not bound it.
The settings menu needs its decrement/increment boundaries crossed with
every selector; varying those fields with correlated strides misses paths.
The timed effect has separate words at offsets 16 and 18, and a mode-mask
case hidden by a correlated pause fixture.

The completed `coverage_65_selection_boundary_dev_v1` pilot crosses the
controller status, button, cursor, phase, timer and particle-age inputs for
four roots. Both states finish 1,024/1,024 invocations with no incomplete
specimens. Valid body observations are 1,682/2,084, 1,242/1,574, 472/504
and 210/210 bytes. Conversion finds 496-512 distinct valid specimens per
root; 31 interrupted specimens remain excluded. The round-count callback
is now a full-body development candidate, with caller/C/holdout still pending.

The large controller-menu owner has a likely unreachable branch at
`0x8c09c2cc`/`0x8c09c2ce`. R12 is initialized to 1. The flag tested at
`0x8c09c280` must have bit 0 clear to enter the later path. Before testing
it again at `0x8c09c2c8`, the intervening code can only OR bit 3 into the
same flag, with no intervening call. The second nonzero case therefore
cannot be reached in this original RAM model. Preserve the failed coverage
observation and park this owner unless new evidence changes that premise;
its 2,084 bytes are not reliable implementation-budget yield.

The new `coverage_65_batch_resident_dev_v1` tests the original sound
wrappers' resident-kit predicates. Mutable current-kit globals receive
IDs read from the untouched request tables. Original helper calls execute
normally; neither their returns nor immutable tables are patched. It also
crosses mutable settings bytes, scene-history phases and the independent
timed-effect counters. Both captures are complete.

Its first state has completed all 1,920 invocations, with no incomplete
records. It observes all 488 scene-history bytes and all 512 timed-effect
bytes. The resident menus remain partial (684/726 and 598/764). Two sound
test specimens reach `0xa0800074` and remain excluded device paths.
The second state also completes its 1,920 invocations and independently
executes both complete owners. Conversion yields 765 distinct valid scene
cases and 768 distinct timed-effect cases across both states. The other
roots have 747-768 distinct valid cases. The sound test retains 16 exception,
four non-RAM and one interrupted specimens; five settings-menu and three
scene interruptions remain excluded. No incomplete records exist.

The reset-settings owner `0x8c09bc2e` has a second proven obstacle:
the reset helper `0x8c08e5c4` calls the original byte setter at
`0x8c08e620`/`0x8c08e622`, writing zero to configuration offset 14.
The menu then reads that byte at `0x8c09be80`/`0x8c09be82`.
The nonzero branch `0x8c09be92` through `0x8c09be9a` cannot be reached
by supplying a different initial configuration value. Park this owner
without patching the helper or waiving whole-body coverage.

The prepared resident-menu v2 pilot excludes that owner and crosses
equal alternate characters, player swapping and both secondary controller
buttons for `0x8c09b36c`. Its original stage/character tables contain byte
rows; bounded neighboring selectors are explicit RAM input cases.

The prepared `coverage_65_batch_expand_dev_v2` adds seven previously
unscreened true callable prefixes, offering 7,916 advisory owner bytes.
They cover pause/scene handling and scene/UI initialization. Their nested
SDK, rendering and callback dependencies remain conditional on execution.
The 1,780-byte initialization owner at `0x8c09575c` is not included: its
disassembly explicitly writes PVR registers `0xa05f7890`/`0xa05f7894`.

The prepared clipping pilot tests eight SDK variants using a typed RAM
output cursor in R12. Their original helpers issue PREF against that cursor;
this experiment claims RAM behavior only. Their true prefixes start with
two extra R10/R9 saves, matched by extra pops just before RTS. The packed
strip pointer is saved R8 at frame offset 100, not saved R1. Original caller
pools include `0x8c057288`, `0x8c0566cc`, `0x8c05762c`, `0x8c056a50`,
`0x8c057a10`, `0x8c056e8c`, `0x8c058148` and `0x8c057e08`.
For example, `0x8c05725e` loads the first target, `0x8c057260` calls it,
and the delay slot copies R0 into the clip selector R4. These static facts
are not a substitute for executed caller proof.

`coverage_65_batch_candidate_budget_v1.json` measures this conditional
implementation pool against the current accepted half-open byte ranges:
2,810 bytes with whole-body original observations and 3,266 uncredited
clipping bytes, totaling **6,076 marginal bytes**. Clipping owner
`0x8c051f8e` is already credited and contributes zero new bytes; it is a
control in the new pilot. The snapshot explicitly marks the pool unproven
until the pending captures and caller/dependency gates succeed.
The initial 6,000-byte implementation batch has not yet passed the screening
requirements. Continue screening and then implement the batch; do not turn
these observed instruction bytes into a percentage claim.

## Reproduction and retention

Generators, watch lists and explicit typed input JSON are committed under
`tools/oracle/`; original captures and patches remain ignored local evidence.
The reports hash-pin the capsules, accounting summaries, original observer,
state files, input patches, logs, image and frozen body inventory. New reports
also pin their explicit input files, watch lists and owner maps.

`tools/oracle/coverage_65_screening_checkpoint.py` seals the retained
reports together with the typed inputs, generators and prior accepted replay
callback seal. Its audit grants zero credit and refuses to overwrite evidence.
The next pilot's prepared inputs are pinned as inputs, not as completed
captures. No compiled C changed, so no native regression or holdout source
freeze is claimed for this screening checkpoint.
