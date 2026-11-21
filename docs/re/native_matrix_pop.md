# native_matrix_pop — the matrix stack pop leaf (0x8C03C4A0)

The readable port `src/fight/matrix_lib.c` (`vf3_matrix_pop_entry`) is
rewritten as plain C in `src/native/matrix_pop.c` (`vf3_native_matrix_pop`),
proved against it by `tests/matrix_pop_native_replay.c` (7 differential
cases) and by the mutation gate (`tests/matrix_pop_native_mutations.json`,
9/9 caught).

## The leaf

A self-contained, call-free, FPU-free, no-stack leaf that drops `r4`
matrices (at least one, never below an empty stack) and loads the new top
into XMTRX.  The guest keeps XMTRX in the XF bank (`s->v[37..52]`); the
native port maps it to `a->xm[16]`.

The control block is at `0x0C19D2E4`: `{int16 count, int16 limit, u32 base,
u32 top}` — `base` at +4, `top` at +8.

```
drop = r4 > 0 ? r4 : 1
enough = (count >= drop)
new_count = enough ? count - drop : 0
addr = base + new_count*64
count (u16) = new_count
if new_count < limit:  top = addr
XMTRX = matrix at addr
r0 = enough;  r2 = limit;  r3 = MATRIX_STACK_CTL;  r4 = new_count<<6
r6 = new_count;  r7 = addr + 64;  SR.T = (new_count >= limit)
```

The top pointer is only rewritten while the new count is below the limit.
No FPU, no FR, no stack frame; r15 and every register except r0/r2/r3/r4/r6/r7
and SR.T are untouched.

## The test

`tests/matrix_pop_native_replay.c` seeds both sides with the same flat RAM
(the control block, its base, and four pre-populated stack matrices), the
same XMTRX and the same r4, then runs the leaf and compares against the guest:
the whole XMTRX, r0/r2/r3/r4/r6/r7, SR.T, every other general register, and
the whole low RAM region byte-for-byte.  Seven cases: pop one from three, pop
two, pop beyond the count, pop an empty stack, `r4 = 0`, a negative `r4`, and
pop exactly the count (which distinguishes `>=` from `>` in the enough test).

## The mutation gate

`tests/matrix_pop_native_mutations.json` applies 9 single mutations: the drop
floor, `new_count` not clamped, the `addr` shift, the top always rewritten,
the count written too wide, the `enough` comparison, a wrong r4, a wrong r7,
and an inverted SR.T.  All 9 are caught — the *pop exact count* case is what
makes the `enough` comparison observable.

## Authority

The readable port is the authority; the chain is *native == readable*.  No
oracle corpus names this exact entry as a watched specimen, so the proof
stands on the differential against the readable translation.

Result: **7/7 PASS**, **9/9 mutations caught**.
