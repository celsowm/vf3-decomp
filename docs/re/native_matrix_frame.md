# native_matrix_frame

The matrix_frame leaves (0x8C03D260 `matrix_frame_a`, 0x8C03D280
`matrix_frame_b`, 0x8C03D2B0 `matrix_frame_c`) ported natively as
`src/native/matrix_frame.c` (`vf3_native_matrix_frame_a/b/c`), composed from
the already-proved native matrix-stack helpers.

## The function

These are "evaluate a child transform and remember it" sequences built from
the matrix-stack helpers (src/fight/matrix_lib.c `frame_chain`,
`vf3_matrix_frame_*_entry`).  Each pushes the current XMTRX on the matrix
stack, multiplies in a parent (and in B's case a second parent first), stores
the result as a flat matrix in a fixed slot, and pops the stack back:

    frame_A: push *(node+8);         concat_parent; store 0x0C19D4D8; pop
    frame_B: push *(node+8); concat *(parent+8); concat_parent; store
             0x0C19D4D8; pop
    frame_C: push *(parent+8);       concat_parent; store 0x0C19D498; pop

with `node = 0x0C19D308`, `parent = 0x0C19D2FC` (the `+8` fields are the stack
tops of those control blocks).  They are call-free in the router sense: every
callee is a direct helper call, no indirect jump, so they fit the native
flat-RAM leaf pattern.

## The port

`frame_chain` saves the caller's r15 and pr at `sp-4` (the guest's own frame;
the helpers all keep the stack pointer net-flat), runs
`matrix_push` (loading the pushed matrix as the new XMTRX), optionally
`matrix_concat` with the parent matrix, always `matrix_concat_parent` (the
matrix one slot below the stack top), `matrix_store` to the flat slot, and
`matrix_pop`, then restores r15 and pr.

## The proof

- **Differential**: `tests/matrix_frame_native_replay.c` runs the native port
  against the readable guest authority `vf3_matrix_frame_*_entry` on four
  cases (each frame with a rotated XMTRX, plus frame_a on the identity).  Both
  sides seed the same flat RAM (matrix-stack control block, node/parent tops
  and matrices, fixture region), the same XMTRX and FR12..FR15.  The final
  flat-slot matrix, the restored XMTRX, the matrix-stack control block, the
  stack words, r15/pr and the post-frame registers (r0/r4/r6/r7, FPUL,
  FPSCR.FR) are compared.  The flat matrix and XMTRX use the 2e-3 FPU
  residual; everything else is byte-exact (modulo the flat slot's low ulps,
  which differ because the native side multiplies with plain floats where the
  guest's ftrv rounds once - the two agree within tolerance).
- **Mutation gate**: `tests/matrix_frame_native_mutations.json`, 7/7 caught
  (`python tools/mutate.py --port src/native/matrix_frame.c --exe
  build/vf3nativematrixframe.exe --mutations
  tests/matrix_frame_native_mutations.json --target vf3nativematrixframe
  --keep-going`).  The mutations cover the three frames' dispatch (wrong
  push source, skipped concat, wrong flat slot), the concat_parent step
  replaced by a repeat push, the r15 restore dropped, the saved pr placed at
  the wrong stack offset, and the push_from read forced to the parent.
- **One mutation is unobservable and correctly dropped**: dropping the
  `a->pr = pr` restore (`pr_not_restored`) is not caught, because the native
  helpers are direct C calls that never modify `a->pr` - removing the restore
  leaves pr at its entry value either way.  The corresponding r15 restore
  *is* observable (the helpers move r15), so it stays in the list.

## Reading

- Source: `src/native/matrix_frame.c`, `src/native/matrix_frame.h`
- Authority: `src/fight/matrix_lib.c` (`frame_chain`,
  `vf3_matrix_frame_a/b/c_entry`)
- Test: `tests/matrix_frame_native_replay.c`
- Mutations: `tests/matrix_frame_native_mutations.json`
