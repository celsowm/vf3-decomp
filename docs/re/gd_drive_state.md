# The drive is not RAM: the REIOS GD-ROM state in the corpus

## What the REIOS GD service really is

`GDROM_REQ_CMD` (the REIOS vector `0x0c001006`, r7 = 0) does not read the
drive's state from memory.  In the reference (`reios/gdrom_hle.cpp`,
`GDROM_REQ_CMD`) the service keeps a 16-word drive state of its own:

```
last_request_id, next_request_id, status, command,
params[4], result[4], cur_sector, multi_read_sector, multi_read_offset,
multi_read_count
```

and the answer is decided by two of those words:

* `status` - the command is only accepted when the drive is idle
  (`GDC_OK`); while a transfer is in flight the call returns 0.
* `next_request_id` - the accepted command returns this counter and bumps it.

So `r0` after a `REQ_CMD` is **the drive's request counter**, not something the
guest can compute and not something that lives in SH-4 RAM.  The port's narrow
"the drive refuses everything" behaviour returned 0 where the reference
returned `0x12`, `0x32` or `0x8a` - the request id of that call.

## The corpus has to carry the drive state

The environment of a specimen is what the corpus records: the RAM windows, the
banked registers, XF/FPUL, GBR and the device tape.  The drive state belongs
to the same class of evidence, so the corpus now carries it:

* `tools/oracle/capsules.py` writes `f_<entry>.gd.bin`, 16 `uint32` words per
  case, in the order of the case rows.
* `tests/matrix_family_replay.c` reads that sidecar and seeds
  `vf3_matrix_state.gd_state` before the case.
* `src/fight/vf3_aica_stub_adapter.c` runs the *service model*
  (`src/sys/gdrom_hle.c`, `vf3_bios_gd_syscall`) forward from that state
  instead of assuming an idle drive, and `GDROM_REQ_CMD` now answers in `r0`
  exactly as the reference does (`GDROM_EXEC_SERVER` does not touch `r0`).

The model was already faithful (`src/sys/gdrom_hle.c:81` implements the counter
and the status rule); it was simply never fed the state.

## The observer has to record the state at the entry

The observer already wrote the drive state to `VF3_GDLOG`, but only for a
*naturally* reached watch entry.  A specimen reached through a synthetic
redirect (`VF3_ENTRY_PATCH`) - which is how the loader probes are captured -
only carried its **exit** state.  The exit state is not enough: it says what
the drive did, not what it was when the guest asked.

`docs/re/patches/oracle_drive_state.patch` adds the matching record to the
synthetic arm:

```c
logGd('S', c.id, c.entry);
```

`tools/oracle/build_extended_observer_v3.py` builds the observer that carries
it (the v2 recorder plus this one line; the main oracle and its objects are
left untouched).  `tools/golden_batch.py --gd-log` gives every run its own log
next to its capsule, and the extractor joins the `'S'` record with the case by
the invocation id.

## What is verified

`0x8c04326c` (the `GDROM_REQ_CMD` wrapper of the loader) replays clean on the
`tenpp_isolated_fight` corpus with the sidecar:

| case | drive state at the entry | `r0` the reference returned |
|---|---|---|
| 0 | `status = BUSY`, `next = 0x12` | `0x00000000` |
| 1 | `status = OK`, `next = 0x12` | `0x00000012` |

The re-capture is byte-identical to the corpus that is already in the tree
(`f_8c04326c.cases` hashes equal), so the sidecar does not change the
evidence - it completes it.

## What is still blocked

Four of the five corpora that hold a GD-family entry - `tenpp_isolated_seeded_*`,
`tenpp_leaf_dev_cases`, `tenpp_recovery_historical_cases` and
`tenpp_bounded_dev_cases` - predate the observer's device-read policy
(`docs/re/patches/oracle_device_reads.patch`).  Their capsules are gone, and the
current observer no longer produces their specimens: the original capsule
manifest records `started = 2, completed = 2` (state 21) and `started = 8,
completed = 8` (state 27), while a re-capture of the same recipe yields one
specimen per run.  The drive state of those cases therefore cannot be
recovered, and the promotion of the family waits for a re-capture that
reproduces them.

The same wall stands in front of the 215 entries that have no corpus at all
(27,750 B): the prologue survey that used to reach them
(`tools/oracle/tenpp_prologue_survey.patch`, trigger `0x8c048284`) no longer
fires - that trigger is not reached in any of the states `vf3_20` .. `vf3_41`.
