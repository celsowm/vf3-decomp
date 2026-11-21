# native aim_step (0x8C093768)

`src/native/aim_step.c` (`vf3_native_aim_step`) is the plain-C port of the
readable `src/fight/aim_step.c` (`vf3_aim_step_entry`), proved by
`tests/aim_step_native_replay.c` (10 differential cases) and the mutation gate
`tests/aim_step_native_mutations.json` (7/7 caught).

## The function

A self-contained FP leaf (call-free; keeps a frame for r14, r13 and FR15):

- `r4` -> a context whose float at `+36` is the step length,
- `r5` -> point A (vec3, updated in place),
- `r6` -> point B (vec3),
- `r7` -> a vec3 receiving the unit direction.

It computes `d = A - B`, stores `d` to `*r7`, then:

- the squared length of `d` comes from `fipr` (the SH-4 inner product,
  accumulated in double);
- the inverse length comes from `fsrra` (`1/sqrt`), and is **zero** when `sq`
  is zero **or** below the pool's epsilon (`0x33D6BF94` = ~1e-7);
- `A = d * (inverse length * step) + B` (written back to A);
- `*r7 = d * inverse length` (the unit direction from B to A).

So A ends up the step length away from B on the same line, and `*r7` is that
line's unit direction.

## What the port has to keep

- **The epsilon gate has two tests.**  The inverse length is zero when `sq ==
  0` *or* when the epsilon is **above** `sq`; otherwise it is `1/sqrt(sq)`.
  The `sq != 0` test and the `eps > sq` test are both observable (the "zero d"
  and "below eps" cases), so both have dedicated mutations.
- **`fsrra` is the *approximate* reciprocal square root**, so it is `1/sqrtf`,
  not a plain C expression that rounds differently.
- **`fipr` accumulates in double** (the SH-4 inner product), flushed once to
  float - a plain single-precision `dx*dx + dy*dy + dz*dz` differs on the
  inexact case.
- **The final A is the scaled `d` *plus* B** (B re-read from the frame slot),
  and the frame's stored B is what is re-read, not `r6` (the function itself
  writes `r6` into the frame, so that round-trip is unobservable - only the
  `+ B` is).
- **The epilogue leaves `r4 = A` and `r5 = B + 12`** (both checked).
- **Register-restore contract**: r14, r13 and FR15 are restored, `r15` returns
  to its entry value; the dead stack pushes are matched by the pops.

## One unobservable thing

- **Reading B back from the frame vs. from `r6` is unobservable.**  The
  function pushes `r6` into the frame at entry (`w32(ram, f, b)`), so by the
  time it reads the frame back the two are equal by construction - the
  frame round-trip never diverges from `r6`.  It was dropped from the mutation
  list for that reason and replaced by the observable `r5` epilogue mutation.

## The FP contract

This leaf runs under **round-to-nearest and no FTZ** (the readable test's
FPSCR is 0, exactly like its sibling `move_cap`), so the native uses plain C
float multiply/add, `1/sqrtf` and double accumulation for `fipr` - no
toward-zero/FTZ wrappers are needed.
