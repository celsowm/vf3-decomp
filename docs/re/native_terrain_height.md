# Native terrain height lookup

`vf3_native_terrain_height` implements `0x8c068e0e`. It uses the native
coordinate wrapper and flat-ground helper, or clamps the wrapped coordinates
and interpolates four values in the 128-by-128 height map. For stage 11 it
calls `vf3_native_terrain_ext` with the original frame layout, so the region
correction is now part of this native lookup's call tree.

`vf3nativeterrainheight` compares the complete native lookup with the readable
entry, using the readable coordinate and flat helpers and the translated
stage-11 correction as the reference. Sixteen synthetic cases cover flat
ground inside and outside the boundary, interpolation, clamping, stages 2,
7 and 13, and stage 11 with and without a selected region, under both recorded
FPSCR values. The test compares the full register and FR banks, FPUL, XMTRX,
SR and RAM. All nine mutations in `terrain_height_native_mutations.json` are
caught. The stage-11 selected-region case uses an identity region matrix;
the separately tested correction also covers a non-identity matrix.

This establishes the height lookup's native call tree, not integration into
the SDL3 game loop. The separate terrain probes are documented in
`native_terrain_probe.md`.
