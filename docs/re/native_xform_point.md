# Native point transform

`vf3_native_xform_point` implements `0x8c03b450`: it reads a three-component
point from R4, multiplies `(x,y,z,1)` by XMTRX, leaves all four components
in FR4–FR7 and writes the first three to R5. It reads the point before writing
the result, including when the two addresses are the same.

`vf3nativexformpoint` compares RAM, general and FR registers, SR and return
PC with the readable implementation for 24 synthetic cases: identity,
translation and varied matrices; overlapping and distinct buffers; a NaN and
a subnormal input; and both recorded FPSCR values. All five mutations in
`xform_point_native_mutations.json` are caught. The terrain correction now
calls this native function for its point transform. This is differential
evidence against the readable port, not an independent hardware capture.
