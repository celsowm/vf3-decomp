# native_state_ladder

Native port of the fight-state ladder, **0x8C08B89C**, as the self-contained
plain-C leaf `vf3_native_state_ladder` (`src/native/state_ladder.c`), in the
same spirit as the other `src/native/*` ports: a transcription of the readable
guest port `src/fight/state_ladder.c` (`vf3_state_ladder_entry`) onto the
`vf3_native_aim` context (flat RAM, register file, FR bank).

## The function

The second half of the counter updater (0x8C08B7EE, src/fight/cntup.c): the
caller hands it a task struct (r4) and a caller's frame (r5), and it does two
jobs.

* **Folds six flag bits into one word**, the caller's frame word at F+0.  Each
  bit comes from a different pair of the caller's words (the state struct and
  the fighter struct, fetched from the caller's frame at F+0x48 and F+0x4C).
* **Steps the task's counters** — the per-call counter at +36, the pair at
  +28/+38, the countdown at +22, the rolling counter at +34 (+ the burst and
  long bytes on the roll-over) and the three saturating counters at +30/+24/+20.

It is a self-contained integer leaf with a single float copying through FR3; it
makes no guest calls and no tail transfers.  It runs under single precision,
round-to-nearest, no FTZ (FPSCR 0).

The literal pool is read at run time, the way the guest reads it: the offsets
into the two structs and the six masks are the image's, and the port does not
bake them in.  A replay has to supply the pool as part of the flat RAM.

## Proof

* **Differential** — `tests/state_ladder_native_replay.c` (the
  `vf3nativestate_ladder` target) runs the native leaf against the readable
  guest port on the same flat RAM for 35 scenarios and matches:
  * the whole flat RAM span `[0x0c08b9b0..0x0c400100)` byte for byte (the
    native's writes against a snapshot of the guest's), which covers the pool,
    the task struct, the state struct, the fighter struct, the caller's frame
    and the stack;
  * the register file, the FR bank, SR's T bit and the final r15;
  * an **independent fixture model** that computes the flag word, the task's
    counters and the frame the guest builds straight from the fixture, without
    consulting the translation.
* **Mutation gate** — `tests/state_ladder_native_mutations.json`, **19/19
  caught** (`python tools/mutate.py --port src/native/state_ladder.c --exe
  build/vf3nativestate_ladder.exe --mutations
  tests/state_ladder_native_mutations.json --target vf3nativestate_ladder
  --keep-going`).

## Details the port keeps

* The **T bit** is the guest's branch condition (a plain `bf` branches when the
  T bit is clear).
* A **`/s` branch runs its delay slot on both paths**, so the value the delay
  slot spills into the guest's scratch word (at r15) is written whether the
  branch is taken or not — the port writes those words too.
* The **`shld`** at 0x8C08B8EE shifts the pool's top bit right by the task's
  byte at +0x40: a negative count is a right shift, and a count whose low five
  bits are zero gives **zero**, not the value itself.  The spilled mask lands
  in the caller's frame at F+0x30 (frame +48), which the fixture checks.
* The guest's **counter decrements saturate** (the three counters at +30, +24
  and +20 stay at zero once spent; the one at +24 hands over to the one at
  +20).
* The **return** pops the four saved registers, so the caller sees its own r11,
  r12, r13 and r14 back.
* The frame's **byte** store at F+8 keeps its eight-bit value (the sign
  extension of the kind byte is masked away before the store).

## Care points from the gate

The first version of the test had the **vacuous-fixture trap**: its RAM
comparison read the native's result out of the same buffer on both sides (via
`r32` and `vf3_aim_u32`, which are the same RAM), so it could never fail.  The
test now snapshots the guest's RAM after the guest run and compares the
native's writes against that snapshot instead.

The mutation list also had to target the *observable* gates: the level
threshold's `set_t` T bit is overwritten by the next comparison, so the
mutation flips the `if (r1 > r2)` that picks `r14`, not the T bit; and bit 3's
`set_t` T bit is overwritten too, so that mutation flips the `if (r0 == 26u)`
gate.

## Files

* `src/native/state_ladder.h` — the `vf3_native_state_ladder` declaration.
* `src/native/state_ladder.c` — the port.
* `tests/state_ladder_native_replay.c` — the differential test.
* `tests/state_ladder_native_mutations.json` — the mutation gate.
* `CMakeLists.txt` — `vf3nativestate_ladder` target.
