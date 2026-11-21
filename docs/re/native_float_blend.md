# native float_blend (0x8C03E810)

`src/native/float_blend.c` (`vf3_native_float_blend`) is the plain-C port of
the readable `src/fight/float_blend.c` (`vf3_float_blend_entry`), proved by
`tests/float_blend_native_replay.c` (4 differential cases) and the mutation
gate `tests/float_blend_native_mutations.json` (10/10 caught).

## The function

A call-free FP leaf with no guest callees and only the final `rts`.  It takes
an array of four floats (`r4`), copies them into a structure of four slots and
then writes a weighted sum over three of the slots back into the first one:

```
slot0 = weight_a * slot2 + weight_b * slot1 + weight_c * slot3
```

The first source float is therefore dropped (it is copied into slot 0 and then
overwritten by the blend).  The structure's address is a word in the literal
pool (`0x0C03E8A4`) and the three weights are pool floats (`0x0C03E8A8`,
`0x0C03E8AC`, `0x0C03E8B0`), read at run time from RAM.

The blend is a multiply followed by two *fused* multiply-adds, so the port
cannot write it as an expression of C floats: each step rounds once (`fmaf`),
where a plain expression rounds three times.

## What the port has to keep

- **The literal pool is read at run time.**  The structure base and the three
  weights live in RAM; a replay has to supply the pool as a window.
- **The float pipeline is FPSCR-aware.**  Rounding is `fpscr & 1` (1 =
  toward-zero, 0 = nearest) and the result is FTZ-flushed when bit `0x40000`
  is set — the corpus FPSCR `0x00040001` is toward-zero + FTZ.  The port
  cannot hard-code `FE_TOWARDZERO` (the readable's own test also exercises a
  round-to-nearest FPSCR).
- **The array step and the load/store width follow the FPSCR's
  double-precision bit (`0x100000`).**  Evidenced behavior is single precision
  (step 4, width 4); the double-width pairing (odd registers through the XF
  half) is carried only for fidelity and is not evidenced by any captured
  state, exactly like `byte_color`.
- **The two slot addresses the blend reads back are pushed on an 8-byte
  frame** below `sp` (`sp-8` / `sp-4`), which is part of the contract — the
  frame words are compared as RAM.  The `r15` round trip is net zero, so the
  port leaves `r15` unchanged.
- **The register handoff**: the blend rides FR0 (the weights), FR2 (the slots
  at +4, +12) and FR3 (the running total), so the FR bank is part of the
  contract and the differential compares it whole.

## Everything else

`float_blend` is one of the last genuinely call-free, un-nativized leaves in
the registered readable set — the address-based sweep against `src/native`
(`tools/scan_native.py`, matching the full 8-hex-digit address across every
native `.c`/`.h`) finds no other registered entry with zero `vf3_guest_call`
sites that is not already ported.  It is a self-contained leaf under the
single-precision corpus FPSCR, proved by the differential and the mutation
gate.
