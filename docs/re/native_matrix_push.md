# native_matrix_push — the matrix stack push leaf (0x8C03C4F0)

The readable port `src/fight/matrix_lib.c` (`vf3_matrix_push_entry`) is
rewritten as plain C in `src/native/matrix_push.c` (`vf3_native_matrix_push`),
proved against it by `tests/matrix_push_native_replay.c` (5 differential
cases) and by the mutation gate (`tests/matrix_push_native_mutations.json`,
9/9 caught).

## The leaf

A self-contained, call-free, FPU-free, no-stack leaf that pushes XMTRX on the
matrix stack and optionally loads a new one.  The guest keeps XMTRX in the XF
bank (`s->v[37..52]`); the native port maps it to `a->xm[16]`.

The stack's control block is at `0x0C19D2E4`: word 0 = `(limit << 16) | count`
(two int16), word 8 = the stack top.

```
write XMTRX at top (FR0 lowest);  top moves up by one matrix (64 B)
count += 1          (the u16 at the control block's low half)
r0 = (limit > count)
if r4 == 0:  SR.T = 1
else:        XMTRX = matrix at r4;  SR.T = (r4 & 4) == 0;  r4 += 64
```

The limit test only leaves its result in `r0` — it does not clamp the write or
the count.  SR.T ends as `r4 == 0`, or as "r4 is 8-byte aligned" (which picks
the pair-load path) when a matrix is loaded.  No FPU, no FR, no stack frame;
r15 and every register except r0/r4 and SR.T are untouched.

## The test

`tests/matrix_push_native_replay.c` seeds both sides with the same flat RAM
(the control block, the stack-top area and a distinct load-source matrix),
the same XMTRX and the same r4, then runs the leaf and compares against the
guest: the whole XMTRX (`a->xm` vs `s->v[37..52]`), r0, r4, SR.T, every other
general register, and the whole low RAM region byte-for-byte.  Five cases:
push with room, push past the limit, a push followed by a matrix load, a load
from an odd-aligned source (SR.T = 0), and a max count that wraps the u16.

## The mutation gate

`tests/matrix_push_native_mutations.json` applies 9 single mutations: the
push loop, the top advance, the count increment, the count written too wide
(u32 clobbering the limit), the inverted `r0` comparison, the load path
removed, SR.T forced, a wrong r4 advance, and the control-block offset.
All 9 are caught.

## Authority

The readable port is the authority; the chain is *native == readable*.  No
oracle corpus names this exact entry as a watched specimen, so the proof
stands on the differential against the readable translation.

Result: **5/5 PASS**, **9/9 mutations caught**.
