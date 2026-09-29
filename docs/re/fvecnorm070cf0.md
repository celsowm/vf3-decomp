# 0x8C070CF0 vector fragment boundary

`0x8C070CF0` is a 208-byte FPU fragment. The watch
`tools/watch/vf3_070cf0_boundary.txt` samples its entry, transfer sites, and
three RAM windows. The first 128 calls reached `0x8C070D5E` 84 times,
`0x8C070D8C` 32 times, `0x8C070D98` twice, and the post-normalization transfer
at `0x8C070E7C` ten times. All 128 calls have paired entry and boundary RAM
snapshots.

The C model covers the cross product and dot-product branches, the `SP+28`
cross-length store, and the ten observed in-place normalization calls. Those
normalization norm-square results use a finite FSRRA scale catalog; unknown
inputs are rejected. The replay passes 128/128 register and full-window RAM
comparisons.
