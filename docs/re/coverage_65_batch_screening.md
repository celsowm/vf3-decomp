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

The prepared `coverage_65_selection_boundary_dev_v1` pilot crosses the
controller status, button, cursor, phase, timer and particle-age inputs for
four roots. It is pending until its original captures and report finish.
The initial 6,000-byte implementation batch has not yet passed the screening
requirements. Continue screening and then implement the batch; do not turn
these observed instruction bytes into a percentage claim.

## Reproduction and retention

Generators, watch lists and explicit typed input JSON are committed under
`tools/oracle/`; original captures and patches remain ignored local evidence.
The reports hash-pin the capsules, accounting summaries, original observer,
state files, input patches, logs, image and frozen body inventory. New reports
also pin their explicit input files, watch lists and owner maps.

`tools/oracle/coverage_65_screening_checkpoint.py` seals all four retained
reports together with the typed inputs, generators and prior accepted replay
callback seal. Its audit grants zero credit and refuses to overwrite evidence.
The next pilot's prepared inputs are pinned as inputs, not as completed
captures. No compiled C changed, so no native regression or holdout source
freeze is claimed for this screening checkpoint.
