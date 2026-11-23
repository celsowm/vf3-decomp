# Native matrix wrappers

`matrix_wrappers.c` implements six readable registry entries using native
matrix helpers:

- `xform_axis` (`0x8c09d52e`) builds `(FR4, 0, 0)` on the guest-visible frame
  and calls the native point transform.
- `store_keep_translation` (`0x8c09d4e6`) stores XMTRX while preserving the
  object's three translation words.
- `rotate_euler` (`0x8c09d480`) applies Z, Y and X rotations in that order.
- `vec3_load` (`0x8c03cc90`) loads a vector and tail-calls native matrix
  translation.
- `call_seq_da1e` (`0x8c09da1e`) preserves translation while applying four
  owner and pose rotations.
- `root_orientation` (`0x8c09d9ea`) resets XMTRX and applies the owner's
  yaw and three pose rotations.

The first two compare bitwise against readable implementations across eight
synthetic cases and catch six mutations. Euler rotation compares 32 cases and
catches five mutations; vector load compares 24 cases and catches five. The
rotation and translation comparisons use a 0.002 floating-point tolerance,
matching the existing native rotation and translation helper tests, because
those helpers use host trigonometry and float arithmetic. These checks are not
independent hardware captures or evidence that the SDL3 loop calls the entries.

The two owner-orientation callers each pass 64 differential cases within the
same tolerance and catch six mutations. `root_orientation` reads its field
offsets from the literal pool but directly calls the native implementations
identified by the original image's pool targets; a modified target is outside
the tested contract.
