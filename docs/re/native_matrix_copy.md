# native_matrix_copy — the matrix copy leaf (0x8C03B530)

The readable port `src/fight/matrix_lib.c` (`vf3_matrix_copy_entry`) is
rewritten as plain C in `src/native/matrix_copy.c`
(`vf3_native_matrix_copy`), proved against it by
`tests/matrix_copy_native_replay.c` (5 differential cases) and by the
mutation gate (`tests/matrix_copy_native_mutations.json`, 11/11 caught).

## The leaf

A self-contained, call-free, no-stack leaf.  `dst = r4`, `src = r5`; the
current transform (XMTRX) is the guest's XF bank (`a->xm[16]` here).

```
A dead r14 push first: [sp-4] = r14   (writes sp-4 without moving sp)
if dst == 0:  if src == 0 -> nothing more;  else XMTRX = matrix(src), r4 = src+64
else if src == 0:  write XMTRX to dst, r0 = r4 = dst
else:              copy the 16 words src -> dst;
                   FR3 = the last copied word;
                   r4 = 0, r5 = dst + 64, r6 = src + 64
```

`r14` keeps its entry value and `r15` is never moved.  SR is untouched.  The
null-dst and null-src arms are exactly the `matrix_load` / `matrix_store`
behaviours already ported natively in `matrix_io.c`.

## The port

`src/native/matrix_copy.c` reuses `vf3_native_matrix_load` and
`vf3_native_matrix_store` for the two null arms (both proved by
`matrix_io_native_replay.c`), and otherwise does the direct 16-word copy with
the FR3 / r4 / r5 / r6 contract.

## The test

`tests/matrix_copy_native_replay.c` seeds both sides with the same flat RAM
(source matrix, destination, the stack-top pointer and `SP0 = 0x0C190000`)
and the same XMTRX / FR3, then runs the leaf and compares against the guest:
the whole XMTRX (`a->xm` vs `s->v[37..52]`), FR3 (`a->fr[3]` vs `s->v[24]`),
every general register, and a full RAM region that includes the source, the
destination **and the dead push at `SP0-4`**.  Five cases: both-null, null
dst (load), null src (store), a full copy, and a reverse-direction copy.

The both-null case exercises nothing but the dead push, which is why the
first run *missed* the two dead-push mutations: the comparison window began
at `0x0C190000`, one word above the push landing at `0x0C18FFFC`.  A RAM
write outside the compared window (or outside every window) is invisible to
the differential — dropping the window down to `0x0C18E000` made both
mutations observable.  This is the same shape of trap the AGENTS notes warn
about for fixtures that leave a path touching uncaptured RAM.

## The mutation gate

`tests/matrix_copy_native_mutations.json` applies 11 single mutations: the
dead push (removed, and one word too low), the load arm removed, the store
arm removed, the copy loop skipped / one word short / reversed direction, a
wrong FR3, and wrong r4 / r5 / r6 results.  All 11 are caught.  Command:

```
python tools/mutate.py --keep-going --port src/native/matrix_copy.c \
  --exe build/vf3nativematrixcopy.exe \
  --mutations tests/matrix_copy_native_mutations.json \
  --target vf3nativematrixcopy
```

## Authority

The readable port is the authority; the chain is *native == readable*, and
the two delegated arms reuse the already-proved `matrix_io` leaves.  No
oracle corpus names this exact entry as a watched specimen, so the proof
stands on the differential against the readable translation.

Result: **5/5 PASS**, **11/11 mutations caught**.
