/* fdiv.h - native port of the float division / reciprocal helper
 * (0x8C0533A4), operating on the `vf3_native_aim` context.
 *
 * See fdiv.c and docs/re/native_fdiv.md. */
#ifndef VF3_NATIVE_FDIV_H
#define VF3_NATIVE_FDIV_H

#include "aim_math.h"

/* Run 0x8C0533A4.  An off-baseline leaf (116 B), call-free and FPU-free
 * (beyond reading fr0's bits).  The dividend's bits arrive in fr0, the entry
 * stores them through a transient stack slot (width follows FPSCR) and pops
 * them into r0, then a fixed-point software reciprocal turns them into a
 * two-word answer written to the caller's two-word cell at sp+16:
 *
 *     cell[0] <- r3   the exponent / status word
 *     cell[1] <- r0   the packed result word
 *
 * The four IEEE-754 scratch constants it needs are read from the literal pool
 * (0x0c053418/420/424/428).  The four caller-saved registers r3 r2 r1 r0 are
 * restored from sp+0/+4/+8/+12 and the stack pointer ends at sp+20.  The
 * branch is the input's exponent byte (the top byte of 2*r0 masked 0xff):
 * 0xff -> infinity/NaN, 0 -> zero/denormal, else ordinary.  SR's T bit is
 * part of the contract (the pack's carry-rotate).  See
 * docs/re/native_fdiv.md. */
void vf3_native_fdiv(vf3_native_aim *a, uint32_t sp0);

#endif /* VF3_NATIVE_FDIV_H */
