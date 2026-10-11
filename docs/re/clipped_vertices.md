# Clipped vertex output (2026-10-11)

Readable C at `src/fight/clipped_vertices.c` now implements exact entry and
frozen owner `0x8c058a5c`. The contiguous body is 254 bytes, ending at
`0x8c058b5a` after the RTS delay slot. Both locked inventory membership and
the marginal address union are checked before credit.

The renderer supplies three projected points in R6/R8/R9, packed texture
coordinates around R14, the output cursor in R12, a float scale in R10,
and clipping/header fields relative to GBR. The routine calls the qualified
packed-direction leaf at `0x8c05865c`, computes signed reciprocal depths
with the original square/FSRRA sequence, interpolates two edges against the
GBR clipping value, and writes two vertex records with their shared packed
direction. This interpretation follows arithmetic and output layout; no
gameplay or specific scene role is claimed.

The original rendering convention requires single precision and SZ=1 on
entry. Register bank toggles, FPUL, both floating banks, T, output cursor,
stack PR saves, scratch RAM, GBR, and the return-PC delay slot participate
in strict architectural comparisons. The C adapter requires captured GBR
and rejects unsupported floating modes. PREF occurs on ordinary captured
RAM in these specimens; no live AICA comparison is claimed or required.

Development uses 64 finite variants in each of original states 21/26,
covering all four sign combinations of the two varying depths. Acceptance
changes coordinates, depths, scale and clipping value, relocates owned
objects by `0x100000`, switches the floating bank, and uses states 28/29.
Both independently pass **128/128**, execute every **127 PCs / 254 bytes**
of the owner, and retain zero exclusions, native skips or quarantine.
The called 234-byte encoder is also executed. There are no patched
instructions or forced helper answers.

The final native executable `vf3matrixfamily_clipped_vertices_dev_v2.exe`
and **369 compilation files** were frozen before acceptance. The earlier
v1 native passed development but was superseded after explanatory comments
were added; v2 repeats development and supplies all final proofs. Both
files remain in the external evidence cache. The original emulator and its
102 linked sources remain unchanged.

The static BSR at `0x8c05849a` reaches this entry; its frozen parent
`0x8c058348` has no current matrix binding. All matrix opcode ledgers were
available, and only the new binding executes this entry. That binding,
**39 native suites**, and **124 tool tests** pass. The previously qualified
packed-direction development and acceptance corpora also pass **128/128
each** under the new executable. The full current inventory gate remains
due at 60%.

`tools/oracle/clipped_vertices_v1_manifest.json` pins raw original capsules,
input patches, state and emulator hashes, all compiled dependencies, strict
reports, the affected selection, archived native tests, and the percentage
chain. The prior packed-direction seal and chain are pinned as historical
proof rather than rerun against changed sources.

The milestone adds **254 unique C bytes**, taking verified readable C to
**260,176 / 434,656 (59.86%)**, with **1,375 bindings**. Remaining gaps are
**618 bytes to 60%** and **22,351 bytes to 65%**. Finite fixtures qualify the
documented input domains; broader production callers remain to be captured.
