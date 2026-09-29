# 0x8C070120 vector fragment boundary

`0x8C070120` is a 206-byte FPU fragment. The reproducible watch is
`tools/watch/vf3_070120_boundary.txt`; it samples entry, the branch exits, the
end of the inventory fragment, and three RAM windows. The first 128 calls
reached `0x8C07018E` 86 times, `0x8C0701BE` 22 times, and the fragment boundary
at `0x8C0701EE` 20 times. Each call has one paired entry and boundary RAM
snapshot.

The C model covers the initial vector length, ordered cross product, threshold
store in the `0x8C07018A` delay slot, and the dot-product path. The 20 calls
that continue to `0x1EE` include the FR12/FR15 difference setup and the final
FIPR state at the fragment boundary. All 128 cases pass register and full
captured-window comparisons. The unobserved branch at `0x8C0701C8` is rejected
by the model.
