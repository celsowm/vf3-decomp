# Native pose blend entry

`vf3_native_pose_blend` implements the register and stack contract of
`0x8c091de6`, in addition to the existing higher-level
`vf3_native_pose_blend_step` API. It advances the weight, clamps it to one,
blends 26 signed pose fields using Q14 arithmetic, and preserves the guest's
MACL value and stack traffic. The native context now carries MACL for this
purpose. The full entry is in a separate source file so users of the existing
standalone blend API do not acquire a dependency on the native RAM helpers.

`vf3nativeposeblendfull` compares the native entry to the readable entry in ten
synthetic cases spanning zero, fractional, negative and clamped weights and
both recorded FPSCR values. It checks RAM, all general and FR registers, SR,
FPUL, MACL and the return PC. All eight mutations in the accompanying list are
caught. This is differential evidence against the readable implementation,
not a per-entry hardware capture.
