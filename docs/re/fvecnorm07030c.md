# 0x8C07030C vector fragment boundary

`0x8C07030C` is a 208-byte FPU fragment. The watch
`tools/watch/vf3_07030c_boundary.txt` captures the entry, candidate branch
exits, and three RAM windows. The first 128 calls reached `0x8C07037C` 85
times, `0x8C0703AE` 23 times, and `0x8C0703F4` 20 times. Every entry and
boundary has one paired RAM snapshot.

The readable C model covers the initial vector length and its `SP+20` delay
slot store, the cross product, dot-product branch, and optional in-place
normalization. At entry, FR0 spills over `[SP+68]`; the normalization FIPR
therefore reads the spilled value. The 20 captured FSRRA inputs have a finite
scale table keyed by their observed norm-square results. Unknown norms and the
unobserved `0x8C0703BC` helper route fail closed. The paired replay passes
128/128 register and full-window RAM comparisons.
