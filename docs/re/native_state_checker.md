# Native task-state check

`vf3_native_state_checker` implements `0x8c0355a0`. Its state-2 path calls
`0x8c035a4e` in the original, but only after establishing that the object's
busy halfword is zero. The helper immediately returns -10 under that
precondition; the native entry reproduces that reachable path and its stack
and register effects directly.

Four differential cases against the readable entry cover a null pointer,
busy state, ordinary state and the state-2 helper path. They compare RAM,
general registers, SR and return PC. All six mutations are caught. This is
synthetic differential evidence, not an independent capture.
