# Stage-11 terrain region selector

`vf3_native_terrain_region` ports the selector at `0x8c087a40`, a dependency
of the stage-11 terrain correction at `0x8c087ace`. It reads a pointer through
the literal at `0x0c087b60`, then searches eight records for the first whose
strict horizontal and vertical bounds contain the point in FR4 and FR5. A null
record list or a search with no match returns zero in R0. The record layout,
stride and offsets come from the original literal pool, which the native
implementation reads from its flat RAM.

`vf3nativeterrainregion` compares the native selector against the retained
generated translation with the same RAM, register file and FR bank. Its 30
cases include a null list, each of the eight possible matches, no match,
four exact boundary points and an interior point, each under both corpus
FPSCR values. It compares all general and floating-point registers, SR,
return PC and RAM. This is a differential check against the translation,
not an independent per-entry hardware capture.

`tests/terrain_region_native_mutations.json` checks the null path, search
offset, stride and count, all four strict bounds, input coordinate, and
returned pointer. All 10 mutations are caught by the differential test.

This selector is one dependency of the correction; it does not implement the
correction entry or connect that entry to the SDL3 terrain path.
