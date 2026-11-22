/* poly_header_sq.h - native port of 0x8C055E00.
 * See src/fight/poly_header_sq.c (the readable authority) and
 * docs/re/native_poly_header_sq.md. */
#ifndef VF3_NATIVE_POLY_HEADER_SQ_H
#define VF3_NATIVE_POLY_HEADER_SQ_H

#include "motion_aim.h"

/* Write one polygon header (two 16-byte halves) into the store-queue slot the
 * GBR block points at, and leave the next slot in r12.
 *
 *   r4 = the source record (its words +4/+8/+12/+16 are the first four header
 *        words), GBR + 72 (or +80 for the tagged form) holds the destination
 *        pointer, 0x0C16CA08 -> the SQ state whose word +0 (or +8) supplies the
 *        QACR area byte, 0x0C16B820 is a shading template of two more 16-byte
 *        halves.
 *
 *   [0x0C055B80] == 0:  plain form.  A lot of the contract is the flat RAM at
 *   `dst` (a pointer held in the GBR block), the register file (r0..r6, r12),
 *   SR's T bit (set iff the header fits a single half) and pr.  The QACR
 *   device writes (0xFF000038/3C) and the PREF flushes are device side-effects
 *   that are inert in the flat-RAM differential (a fixture points `dst` at a
 *   RAM window, so PREF never fires).
 *
 * Returns 0 when the GBR is not known (mirrors the guest's early return). */
int vf3_native_poly_header_sq(vf3_native_aim *a);

#endif
