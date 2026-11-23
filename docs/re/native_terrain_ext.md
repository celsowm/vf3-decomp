# Native stage-11 terrain correction

`vf3_native_terrain_ext` implements `0x8c087ace` using the native region
selector and matrix stack operations. When a region contains the input, it
pushes the current matrix, loads the region matrix, subtracts its translation
from the position, scales the third coordinate, transforms the position as a
point and the three supplied normal components as a vector, and restores the
matrix. The two transform wrappers retain their guest-visible stack frames.
When the region selector returns zero, the entry restores its frame and
returns without changing the matrix.

The point and vector transform destinations are pointers, so their writes
follow guest order even when pointers alias. The selector is documented in
`native_terrain_region.md`. The caller also accounts for the R1 value left by
the machine-code matrix-push routine; the pre-existing native matrix-push
helper does not reproduce that register effect itself.

`vf3nativeterrainext` compares the implementation to the retained translated
entry for both the empty and selected-region paths, identity and non-identity
matrices, an aliased output pointer, and both recorded FPSCR values. It compares
RAM, all general and FR registers, XMTRX, SR and return PC. All 12 cases pass. Its mutation list
checks eight changes to selection, inputs, point/vector distinction, scaling,
translation, push effects and restoration; all eight are detected. These are
synthetic differential cases against the translation, not a captured hardware
corpus; exceptional floating-point values and aliasing have not been fully
characterized. The native height lookup and both native terrain probes call
this entry for stage 11.
