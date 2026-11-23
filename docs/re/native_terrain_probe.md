# Native terrain probes

`vf3_native_terrain_probe` (`0x8c06938c`) and
`vf3_native_terrain_probe_flip` (`0x8c06911c`) implement the regular and
mirrored-Z grid lookups. They call native coordinate wrapping, the flat-ground
fallback, the point-in-quad test and, for the regular probe, the plane solver.
Both pass stage-11 results through the native terrain correction. The mirrored
probe obtains its normal from the shape record.

`vf3nativeterrainprobe` compares both ports against their readable entries.
The 52 synthetic cases cover flat fallback, an empty cell, an empty list,
out-of-range positions, a found shape, nonzero Z, stage 13 and stage 11 with
and without a selected region, plus two geometric quad hits, using both recorded FPSCR values. The test
checks the full register and FR banks, FPUL, XMTRX, SR and RAM. Eight regular
probe mutations and six mirrored-probe mutations were caught. The shape
cases include both the quad's unconditional-match flag and actual geometric
matches; multiple-entry search paths need further integration cases. These probes are compiled into
`vf3nativeview`; their use by the SDL3 game loop is not established here.
