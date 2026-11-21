# native_scaled_vec_add

Native port of the scaled-vector-add leaf **0x8C09302A** (scaled_vec_add), as
the plain-C leaf `vf3_native_scaled_vec_add` (`src/native/scaled_vec_add.c`),
in the same spirit as the other `src/native/*` ports: a transcription of the
readable guest port `src/fight/scaled_vec_add.c`
(`vf3_scaled_vec_add_entry`) onto the `vf3_native_aim` context (flat RAM, FR
bank, register file).

## The function

A self-contained FP leaf (call-free, uses a 20-byte frame, saves/restores
fr15) that does `dest += w * owner_vector` where:

* `r4` = actor (its halfword at `+16` holds mode bits);
* `r5` = owner (flag word at `+72`);
* `r6` = source record (the weight `w`, a float at `+16`);
* `r7` = mode flags;
* `[sp0+0]` = destination vector pointer.

The weight `w = [r6+16]` (nothing happens when it is 0) is scaled by:
* **1.1** (literal `0x3F8CCCCC`) when `owner.flags & 0x04000000`;
* else **0.75** (literal `0x3F400000`), then — unless the actor's halfword at
  `+16` has bit 0 — **0.45** more (literal `0x3EE66666`) when `r7 & 0x100` is
  set, and the whole routine is **skipped** when `r7 & 0x1000` is set (with
  actor bit 0 clear).

The actual vector it works on is the source triple at **actor + 92** (the leaf
re-loads the actor from its frame and reads `actor + 92`), so the source is a
property of r4, not r5.  fr15 is callee-saved (spilled to `[sp0-4]` on entry,
restored on every leave); only fr0..fr5 carry results out.

## Proof

* **Differential** — `tests/scaled_vec_add_native_replay.c` (the
  `vf3nativescaledvecadd` target) runs the native leaf against the readable
  guest port across **six** modes covering every branch path — weight zero
  (skip), owner bit set (×1.1), actor bit 0 set (×0.75 then apply), r7&0x1000
  set (skip), r7&0x100 clear (×0.75), r7&0x100 set (×0.75×0.45) — and matches:
  * every register (r0..r15), every FR value (fr15 restored), the SR T bit and
    FPUL against the guest;
  * the written dest RAM byte for byte against the guest;
  * an **independent fixture model** (`dest += source * w`, with each multiply
    toward-zero) that uses the guest's **exact literal bits** (`0x3F8CCCCC`,
    not C's round-to-nearest `1.1f = 0x3F8CCCCD`).
* **Mutation gate** — `tests/scaled_vec_add_native_mutations.json`, **8/8
  caught** (`python tools/mutate.py --port src/native/scaled_vec_add.c --exe
  build/vf3nativescaledvecadd.exe --mutations
  tests/scaled_vec_add_native_mutations.json --target vf3nativescaledvecadd
  --keep-going`).

## Details the port keeps

* The weight literals are **exact bit patterns**, not C constants: assigning
  the integer `0x3F8CCCCC` to a C `float` first version stored the *integer
  value* 1.067e9 instead of the bit pattern (the differential caught it as
  garbage fr values).  They go through `vf3_aim_fbits`.
* The weight-zero and flag/bit tests use the guest's T semantics (`tst` sets T
  when the and-ed mask is zero; the equality compare sets it on match), so the
  add/skip decision and the caller-visible T bit line up.
* The source vector is read from **actor + 92** (via the frame), not from the
  owner at r5 — a port that reads `r5 + 92` gets the wrong source (modes 1-5
  all reached apply and all failed until the test seeded `ACTOR+92`).
* The two float steps (`w` scaling and `dest += source * w`) are each
  toward-zero rounding, and the multiply is rounded before the add, exactly as
  the guest's separate FMUL/FADD.
* fr15 is restored at leave even on the skip paths.

## Files

* `src/native/scaled_vec_add.h` — the `vf3_native_scaled_vec_add` declaration.
* `src/native/scaled_vec_add.c` — the port.
* `tests/scaled_vec_add_native_replay.c` — the differential test.
* `tests/scaled_vec_add_native_mutations.json` — the mutation gate.
* `CMakeLists.txt` — `vf3nativescaledvecadd` target.
