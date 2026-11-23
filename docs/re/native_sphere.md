# Native sphere resolver

`vf3_native_sphere_resolve` implements `0x8c093a9c`: it measures the distance
from the point to the anchor and, when that distance is strictly less than
the requested radius, projects the point outwards and sets the hit flag.
The routine preserves the guest's stack frame and register effects. The
no-contact jump at `0x8c093af4` loads its destination from `0x0c093b0c`; the
original image contains `0x0c093b4a`, the shared epilogue. The native code
assumes that image literal has not been changed at runtime.

The differential executable `vf3nativesphereresolve` compares it with the
routed generated translation for contact, no contact, an exact boundary,
zero displacement and both captured FPSCR values. It compares RAM, general
and floating-point registers, SR and the return PC. Its initial eight cases
pass all seven mutations in `tests/sphere_resolve_native_mutations.json`;
the expanded 12-case suite also passes. This is synthetic differential
evidence, not an independent capture, and does not establish behavior for
every exceptional floating-point input.

`vf3_native_sphere_segment` implements `0x8c09382a` and calls the resolver
directly. Its differential test compares the readable guest entry to the
native version for points before, within and beyond the segment, including an
out-of-range point and both recorded FPSCR values. All ten cases pass and all
eight segment mutations are caught. These tests exercise the readable port as
the reference rather than independently captured game states. The
point-contact caller is also native: `vf3_native_point_contact` handles the
height snap, the point and segment record types, empty lists, and the kind-6
remapping. Ten differential cases against the readable implementation pass,
as do all seven point-contact mutations. These synthetic tests do not establish
coverage of every possible list or exceptional floating-point input, and the
family is not yet wired into the higher-level native fight loop.
