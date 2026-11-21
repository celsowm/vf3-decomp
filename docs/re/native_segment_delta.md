# native_segment_delta

Native port of the segment-delta leaf **0x8C092B4A** (segment_delta), as the
plain-C leaf `vf3_native_segment_delta` (`src/native/segment_delta.c`), in the
same spirit as the other `src/native/*` ports: a transcription of the readable
guest port `src/fight/segment_delta.c` (`vf3_segment_delta_entry`) onto the
`vf3_native_aim` context (flat RAM, FR bank, register file).

## The function

A self-contained FP leaf (call-free, uses a 28-byte frame, saves/restores
r14).  `r4` = destination record, `r5` = second record, `r6` = pointer to a
scale float, `r7` = pointer to a record whose float at `+0x14` gates the push.
The caller's stack holds, from `sp+0`: the two source vectors **A** / **B**
(words 0 and 1), a **third vector** (`+8`) and a **flag word** (`+C`).

1. `rec[+0x18..+0x20] = A - B` (component-wise);
2. `scale = *r6`, times **0.65** when the flag word carries bit `0x100`;
3. `rec[+0x18..+0x20] *= scale`;
4. unless the flag carries bit `0x2`, or `gating[+0x14]` is zero (its doubled
   value), or `r5` is null:
   * `frame[0xC..0x14] = third * (2 * gating[+0x14])`;
   * `r5.rec[+0x18..+0x20] += frame[0xC..0x14]`.

The frame `f = sp - 28` mirrors the original's scratch triple and register
file.  r14 is spilled to `[sp-4]` on entry and restored on exit.

## Proof

* **Differential** — `tests/segment_delta_native_replay.c` (the
  `vf3nativesegmentdelta` target) runs the native leaf against the readable
  guest port across **five** modes covering every branch — full push (flag 0),
  flag `0x100` (scale ×0.65), flag `0x2` (push skipped), gating-zero (push
  skipped), r5-null (push skipped) — and matches:
  * every register (r0..r15, with r14 restored), every FR value, the SR T bit
    and FPUL against the guest;
  * the destination record's `+0x18..+0x20` and the second record's
    `+0x18..+0x20` RAM byte for byte against the guest;
  * an **independent fixture model** (`(A-B)*scale`, then the conditional
    push) with each multiply/add/sub toward-zero.
* **Mutation gate** — `tests/segment_delta_native_mutations.json`, **9/9
  caught** (`python tools/mutate.py --port src/native/segment_delta.c --exe
  build/vf3nativesegmentdelta.exe --mutations
  tests/segment_delta_native_mutations.json --target vf3nativesegmentdelta
  --keep-going`).  The first `gating_double` mutation (change `F(4)+F(3)` to
  `F(4)+F(4)`) was a no-op — `F(3)` is already a copy of `F(4)`, so both are
  `2*gating` bit-for-bit — and was replaced by dropping the doubling
  (`F(3)=0`), which the push's scale sees.

## Details the port keeps

* The subtraction order matters (`A - B`, not `B - A`); the differential's
  swap mutation caught it.
* The source vectors are read from the **caller's stack words** `sp+0` / `sp+4`,
  i.e. `frame + 28` / `frame + 32` — the test seeds those pointer words.
* The scale float is read through `r6` (`frame + 8`), the flag word from
  `sp+0xC` (`frame + 40`), the gating record pointer from `r7` (`frame + 4`).
* The scale's 0.65 literal is exact bits `0x3F266666` (not C's `0.65f`).
* The push computes the scale as `2 * gating[+0x14]` (a `fadd` of the value
  to its own copy), and skips when that doubled value is zero, when the flag
  carries bit `0x2`, or when `r5` is null.
* The pushed triple goes into the frame's `0xC..0x14` and is then **added**
  into the second record's `+0x18..+0x20`.

## Files

* `src/native/segment_delta.h` — the `vf3_native_segment_delta` declaration.
* `src/native/segment_delta.c` — the port.
* `tests/segment_delta_native_replay.c` — the differential test.
* `tests/segment_delta_native_mutations.json` — the mutation gate.
* `CMakeLists.txt` — `vf3nativesegmentdelta` target.
