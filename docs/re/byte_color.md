# byte_color (0x8C0563AC)

The two-byte color scale into floats, ported readable in
`src/fight/readable/byte_color.c` and registered as `byte_color`.

## The body

A self-contained leaf, 80 B (0x0C0563AC..0x0C0563F8), call-free and
branch-free (straight-line; the only control transfer is the final `rts`).
It reads three floats through a pointer from the literal pool, scales them by
a fourth, unpacks two packed bytes into three byte channels, converts them to
floats, scales those by the first three, and writes three floats down a
descending run of the output pointer.

The data comes from the literal pool:

```
ptrA  = read32(0x0c056504)   the three source floats (fr4, fr5, fr6)
scale = [0x0c056508]          a constant float (fr7), about 1/255
out   = read32(0x0c056510)    the output base (fr0, fr1, fr2)
```

and the packed bytes from the caller's words:

```
lo = (int16)read16([r4 + 4]);   r5 = lo's high byte, r2 = lo's low byte
hi = (int16)read16([r4 + 6]);   r6 = hi's low byte
```

The float pipeline (the `w` below is FPSCR.PR ? 8 : 4, the single/double
width that gates every load and store):

```
fr4 = [ptrA+0]  * fr7     scaled source channels
fr5 = [ptrA+w]  * fr7
fr6 = [ptrA+2w] * fr7
fr0 = float(r2) * fr6     converted byte channels, scaled
fr1 = float(r5) * fr5
fr2 = float(r6) * fr4
```

The three outputs are stored down the output pointer:

```
store fr0 at [out]
store fr1 at [out - w]
store fr2 at [out - 2*w]
```

and there is one earlier store of the *entry* fr0 at `[r1_in - w]` (a scratch
the caller leaves the frame for).  Registers left: r0 = 0x0c056508, r1 = the
output pointer run down to `out-2w`, r2 = lo's low byte, r4 = r4 + 8, r5 =
lo's high byte, r6 = hi's low byte, and SR's T bit is untouched (this body
never compares).  FPUL (r53) is left holding hi's low byte - the last r53
write (the first three r53 writes carry r2, r5, r6 on their way into the
`fldi`/`float` conversions).

Details the port has to keep:

* **The FP results ride in the register bank, not in locals.**  The final
  three `fr` values are written back into the FR registers (fr4/5/6 scaled,
  fr0/1/2 the byte channels) before the `store`s read them out, because
  `vf3_matrix_store` emits the register bank.  A port that computes the
  floats into locals but never writes them back stores the fixture pattern,
  which the differential catches.
* **r1 is the running output pointer.**  It starts as the caller's r1 (the
  scratch store uses `r1_in - w`), then becomes `out` (0x0c0563c8) and walks
  down by `w` once per store, ending at `out - 2w`.  A port that keeps the
  entry r1 for the output run is wrong.
* **The packed bytes are read at `r4+4` and `r4+6`, and `r4 += 8`.**  The
  byte reads start four bytes into the caller's record and step by two, and
  r4 is left eight bytes past its entry value.  The two bytes are
  sign-extended to 32 bits before their low/high bytes are masked.
* **Byte channels vs. byte lanes.**  `lo`'s low byte is r2 and its high byte
  is r5; `hi`'s low byte is r6 (r6 also end-rides FPUL).  `hi`'s high byte is
  never used.  Getting a lane's *source* wrong shows up in both the byte
  register and the float it feeds.
* **The `w` (FPSCR width) ternary applies to every load/store stride and the
  output run.**  The corpus runs the body in single precision only
  (fpscr 0x00040001, PR clear), so the tests here are single-precision; the
  double-PR path is not exercised by any corpus and is not tested.

## Evidence

The **differential** (`tests/byte_color_replay.c`) runs the three arms - the
generated chain, the readable port called directly, and the readable port
reached through `vf3_readable_override` - over three single-precision channel
layouts (all channels, zero bytes, max bytes with packed 0xffff) in four
windows mirroring the captured corpus (the pool `0x0c056000`, the source
floats `0x0c16b000`, the output/bytes/scratch `0x0c19d000`, and the stack),
with every window byte patterned first, and compares the whole register
file, SR/T, the exit PC, the out-of-window counter and every RAM byte.  It
also recomputes the three FR outputs from the raw fixture inputs with the
same bit-exact FP helpers and checks the byte registers, FPUL and r1/r4
against the fixture.  **3/3 PASS.**  The **mutation gate**
(`tests/byte_color_mutations.json`) applies 15 single-line mutations - the
width stride, the skipped scratch store, the pool slots (ptrA/scale/out),
the byte read offsets, the three byte-channel sources, the FR lane map, the
three store offsets, and the r0/r1/r4/FPUL answers - and the differential
catches all 15.

The **oracle** leg closes directly: `tests/byte_color_oracle.c`
(`vf3bytecolororacle`) routes the readable port itself over the per-entry
`.cases` corpus `tenpp_arch_third_cases/f_8c0563ac.cases` and passes
**128/128 cases** (whole 37-register file, SR's T bit, every byte of the
windows and the OOB counter):

```
build\vf3bytecolororacle.exe ->
  byte_color_oracle: 128/128 cases match (0 skipped) - PASS
```

The windows carry the pool, the source floats, the output/bytes/scratch and
the rest of the captured state at runtime, and the leaf touches no device
register, so no sidecars and no supplied pool are needed.  The three-arm
chain `readable == generated == oracle` closes on all three legs.

## Notes

* The entry is `ported-invocation` in the ledger, not `ported`; this readable
  port is the first source-level C for it.  Its 80 B are worth their own
  body span.
* The 128-case corpus exercises only the single-precision path, so the proof
  is single-precision.  The double-PR path (the `(fpscr & 0x100000)` width
  ternary) is carried by the port for fidelity but is not evidenced by any
  captured state; see the in-repo reading rule: a corpus is evidence for the
  paths it covers, not for the body.
