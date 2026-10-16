/* fr_ops.h - the SH-4 single-precision register ops as statements on the matrix state, for ports that follow
 * the original's FR sequences one instruction at a time. Needs vec3_inline.h (F, fl, set_fl) first.
 * Operand order is the assembler's: FADD(d, m) is fadd FRm,FRd, i.e. FRd += FRm. */
#ifndef VF3_FR_OPS_H
#define VF3_FR_OPS_H

#define FMOV(d, m)  (F(d) = F(m))
#define FADD(d, m)  set_fl(s, (d), vf3_f_add(s, fl(s, (d)), fl(s, (m))))
#define FSUB(d, m)  set_fl(s, (d), vf3_f_sub(s, fl(s, (d)), fl(s, (m))))
#define FMUL(d, m)  set_fl(s, (d), vf3_f_mul(s, fl(s, (d)), fl(s, (m))))
#define FDIV(d, m)  set_fl(s, (d), vf3_f_div(s, fl(s, (d)), fl(s, (m))))
#define FMAC(n, m)  set_fl(s, (n), vf3_f_mac(s, fl(s, 0), fl(s, (m)), fl(s, (n))))   /* FRn += FR0 * FRm */
#define GT(m, n)    (fl(s, (n)) > fl(s, (m)))                                         /* fcmp/gt FRm,FRn */

#endif
