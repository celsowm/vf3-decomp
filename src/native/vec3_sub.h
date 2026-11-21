/* vec3_sub.h - native port of 0x8C03CEE0 (vec3_sub), operating on the
 * `vf3_native_aim` context.  See vec3_sub.c and docs/re/native_vec3_sub.md. */
#ifndef VF3_NATIVE_VEC3_SUB_H
#define VF3_NATIVE_VEC3_SUB_H

#include "aim_math.h"

/* Run 0x8C03CEE0 (vec3_sub).  A self-contained FP leaf (call-free, no stack
 * frame).  r4[0..2] = r5[0..2] - r6[0..2] (component-wise vector difference);
 * r4, r5, r6 each end 8 bytes advanced (only two of the three pointers
 * increments); the FR bank leaves the differences in fr0/fr1/fr2 and the
 * subtracted vector's components in fr4/fr5/fr6.  See
 * docs/re/native_vec3_sub.md. */
void vf3_native_vec3_sub(vf3_native_aim *a);

#endif /* VF3_NATIVE_VEC3_SUB_H */
