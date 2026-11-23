# Native orientation and length helper

`vf3_native_unit_triple` implements `0x8c09dc34`. It transforms the input
through the inverse matrix, derives two lengths and reciprocal length, and
applies the native heading and pitch rotations. The pass-preparation helper
now uses the native matrix inverse and point-transform entries so their FR
and FPUL effects are retained for this caller.

`vf3nativeunittriple` compares 16 synthetic cases against the readable
entry, covering zero, one-, two- and three-component inputs under both
recorded FPSCR settings, with an identity matrix and with a rotated and
translated matrix. RAM, general registers, SR, FPUL and return PC are
compared exactly; FR and XMTRX values use a 0.002 tolerance, as in the native
rotation tests. All seven mutations are caught. The existing
`vf3nativepassprep` suite also passes. Hardware captures remain additional
work.
