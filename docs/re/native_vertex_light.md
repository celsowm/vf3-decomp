# Native strip-vertex lighting

`vf3_native_vertex_light` implements the readable `0x8c048b00` entry's
inline and indirect vertex-record handling using the existing native
`vertex_lit` calculation. It advances R4 according to the selected format
and preserves the scratch registers that the readable entry leaves unchanged.

`vf3nativevertexlight` compares 96 synthetic cases against the readable entry:
both record layouts, two matrices, selector values -1, 0 and 4 through 40,
and both recorded FPSCR settings. General registers, SR, FPUL and RAM are
compared exactly; FR values use a 0.00002 tolerance because the existing
lighting calculation uses host floating-point operations. All five wrapper
mutations are caught. This does not establish a hardware capture or SDL3
game-loop integration, and other selector values and exceptional floats need
separate evidence.
