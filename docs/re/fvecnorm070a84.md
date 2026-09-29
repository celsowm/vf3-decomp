# 0x8C070A84 vector normalization boundary

`0x8C070A84` is a 208-byte FPU routine. The watch
`tools/watch/vf3_070a84_boundary.txt` captures entry and transfer states at
`0x8C070AA8`, `0x8C070AF4`, `0x8C070B26`, `0x8C070B34`, and `0x8C070B6E`.
The 128-entry fight capture reached three destinations: 51 calls transferred
to `0x0C070B72`, 70 to `0x0C070C38`, and seven to `0x0C070C14`. The fifth
transfer site was not reached in this scenario.

The readable C model follows the initial vector length, the ordered cross
product and length comparison, then the dot-product branch and optional
in-place normalization. The replay checks all 37 register words and each
captured RAM window for all 128 chronological entry-to-transfer pairs.
`tests/fvecnorm070a84_replay.c` passes 128/128.

Normalization reaches `FSRRA` on seven captured inputs. Their observed
post-multiply scales are kept as a finite table; an unknown norm rejects the
model call. This avoids treating host reciprocal-square-root rounding as an
established SH-4 rule. The port is registered in CMake, `portcheck`, the golden
binding, and `docs/decomp_status.csv`.
