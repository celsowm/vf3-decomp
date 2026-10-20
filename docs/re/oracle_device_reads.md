# Oracle device reads for synthetic probes

## Problem

The 383 unported baseline entries whose body range is not yet covered by the
coverage union had **no corpus at all**: every synthetic probe that reached
them was rejected.  The rejection was not a timing or budget problem — the
probe ran, and the oracle aborted it the moment it touched an address
outside the 16 MiB of main RAM.

`tools/emu/flycast/core/vf3oracle.cpp` guarded every device access of a
*synthetic* probe:

```c
/* Device state cannot be restored from RAM pages. Reject the specimen
 * before issuing an access, then restore at the next instruction. */
c.flags|=2; c.invalidAddress=addr;
c.aborted=true; c.skipFetched=true; c.countdown=1; blocked=true;
```

The reason was sound but the policy was too coarse.  A device **read** of a
register with no read side effect changes nothing: the value is journalled in
the capsule's device tape (`c.device`, exported as the `.dev.bin` sidecar) and
the C replay feeds it straight back through `ram->device_read`
(`tests/matrix_family_replay.c`).  The device keeps the value the game left,
so the rollback stays exact.

The measured failure distribution over the 383-entry pool confirmed the
coarse policy was the blocker:

| class | entries | bytes |
|---|---|---|
| `device:stack` (0xFFFFFFFC/FD/FE) | 174 | 25,162 |
| `device:unused` (null-ish pointers) | 55 | 8,010 |
| `device:stack,unused` | 14 | 3,622 |
| no device access at all | 136 | 12,486 |

4,203 specimens were rejected with `flags=6` (non-RAM address **and**
abort) against 1,518 with `flags=1` (the probe retired on an `RTE`).

## Change

`docs/re/patches/oracle_device_reads.patch` (regenerate with
`python extract/analysis/make_oracle_patch.py`):

1. `blockSyntheticDevice` takes the access direction and an out-parameter.
2. A **write** to a device address is *suppressed* instead of aborting the
   specimen.  The access is still journalled, so the C replay verifies the
   same sequence, but the device keeps the value the game left.  The probe
   therefore observes the pre-probe device state, which is exactly the state
   the game resumes with.
3. A **read** is allowed unless the register has a read side effect.  Two
   are denied:
   - `0xff000034` — the SCIF receive data register; reading it pops the
     receive FIFO.
   - `0xa05f8000..0xa05f8017` — the AICA common-data block;
     `sgc::ReadCommonReg` can start a DMA.

Everything else is a plain read in the emulator: SCBRR, the CCR, the AICA
timer levels, the interrupt status registers, the VRAM banks, the boot ROM
and the unknown P4 MMIO holes.

## The FPU-disabled exception

A second, separate policy cost the rest of the pool.  The probe inherits the
game's `SR`, and `SR.FD` (bit 12) disables the FPU: with it set, *every* FPU
instruction in the target raises `Sh4Ex_FpuDisabled`, the guest takes the
exception through the BIOS vector, and the oracle retires the specimen on the
`RTE` (`flags=1`).

`0x8C0115C2` shows the shape of the failure: the probe executed 5,408
instructions of `0x0000` starting at the entry address, because the game had
erased that code at run time.  The `RTE` was the *symptom*; the exception was
the cause.

The patch therefore clears `SR.FD` for the probe:

```c
mutableCtx->sr.setFull(mutableCtx->sr.getFull() & ~0x1000u);
```

The game itself only reaches FPU code with the FPU enabled, so this changes
nothing about the recorded behaviour - it only stops the probe from taking a
trap the game would never take.

## Why a suppressed write is faithful

The C replay does not apply device writes either.  `device_write` in
`tests/matrix_family_replay.c` only *verifies* that the port produced the
same address, size, direction and value; it never touches any device state.
So a suppressed write and a journalled write are indistinguishable on the C
side, and suppressing it is strictly safer: the emulator's device state after
the probe is bit-identical to the state before it.

The only observable difference is inside the probe itself: a probe that
writes a register and reads it back sees the old value instead of the new
one.  That difference is *recorded* in the trace and in the device tape, so
the C port reproduces it exactly.

## Effect

With the patch and the arena-seeded fixture
(`tools/oracle/isolated_probes.py --arena-seeds`), the first 33 entries of
the pool yielded 9 captured bodies worth 6,262 B — against 0 for the same
entries before the patch.

Two fixture changes were needed alongside it:

- `--arena-seeds` seeds every register the static inference could not
  classify with a RAM arena pointer.  Without it the probe runs with the
  game's live registers, and a live register holding a bogus pointer
  (`r4 = 0x11` in the 0x8c09575c capture) makes the target dereference a
  device address.
- `--probe-ops` was never passed through to `golden_batch.py`, so every
  probe ran with the 20,000-instruction default budget and was aborted
  (`flags=4`) even when it was about to return.

## Caveat

The emulator lives in `tools/emu/`, which is gitignored, so the patch cannot
be committed with the source it applies to.  `docs/re/patches/` and
`extract/analysis/make_oracle_patch.py` keep the change reproducible from
the repository alone.  The rebuild is an incremental one:

```
cd tools/emu/flycast-build
C:/msys64/ucrt64/bin/mingw32-make.exe flycast -j8
```
