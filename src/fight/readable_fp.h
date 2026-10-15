/* readable_fp.h - float arithmetic for readable ports.
 *
 * The SH-4 runs the fight engine with FPSCR.RM = round-toward-zero, which a
 * plain C `a * b` does not reproduce. These wrappers read the rounding mode
 * from the guest FPSCR (s->v[VF3_REG_FPSCR]) and go through the bit-exact
 * helpers in sh4_fpu.c, so readable bodies can be written as ordinary
 * expressions of named floats.
 */
#ifndef VF3_READABLE_FP_H
#define VF3_READABLE_FP_H

#include <stdint.h>
#include <string.h>
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"

/* indices into vf3_matrix_state.v[] */
enum {
    VF3_REG_PR = 16, VF3_REG_SR = 17, VF3_REG_FPSCR = 18,
    VF3_REG_MACL = 19, VF3_REG_MACH = 20,
    VF3_REG_FR0 = 21,                    /* FR0..FR15 = v[21..36] */
    VF3_REG_XF0 = 37,                    /* XF0..XF15 = v[37..52] */
    VF3_REG_FPUL = 53
};
#define VF3_FR(s, n) ((s)->v[VF3_REG_FR0 + (n)])

static inline float vf3_bits_f32(uint32_t b) { float f; memcpy(&f, &b, 4); return f; }
static inline uint32_t vf3_f32_bits(float f) { uint32_t b; memcpy(&b, &f, 4); return b; }

static inline float vf3_fr_get(const vf3_matrix_state *s, int n) { return vf3_bits_f32(VF3_FR(s, n)); }
static inline void vf3_fr_set(vf3_matrix_state *s, int n, float f) { VF3_FR(s, n) = vf3_f32_bits(f); }

static inline float vf3_f_add(const vf3_matrix_state *s, float a, float b)
{ return vf3_bits_f32(vf3_fpu_binary(vf3_f32_bits(a), vf3_f32_bits(b), s->v[VF3_REG_FPSCR], '+')); }
static inline float vf3_f_sub(const vf3_matrix_state *s, float a, float b)
{ return vf3_bits_f32(vf3_fpu_binary(vf3_f32_bits(a), vf3_f32_bits(b), s->v[VF3_REG_FPSCR], '-')); }
static inline float vf3_f_mul(const vf3_matrix_state *s, float a, float b)
{ return vf3_bits_f32(vf3_fpu_binary(vf3_f32_bits(a), vf3_f32_bits(b), s->v[VF3_REG_FPSCR], '*')); }
static inline float vf3_f_div(const vf3_matrix_state *s, float a, float b)
{ return vf3_bits_f32(vf3_fpu_binary(vf3_f32_bits(a), vf3_f32_bits(b), s->v[VF3_REG_FPSCR], '/')); }
/* acc + a*b with a single (fused) rounding, as fmac does */
static inline float vf3_f_mac(const vf3_matrix_state *s, float a, float b, float acc)
{ return vf3_bits_f32(vf3_fpu_mac(vf3_f32_bits(a), vf3_f32_bits(b), vf3_f32_bits(acc), s->v[VF3_REG_FPSCR])); }
/* float -> int32 with the SH-4 saturating truncation (ftrc) */
static inline int32_t vf3_f_trunc(float f) { return (int32_t)vf3_fpu_ftrc(vf3_f32_bits(f)); }
static inline float vf3_f_from_int(const vf3_matrix_state *s, int32_t v)
{ return vf3_bits_f32(vf3_fpu_float((uint32_t)v, s->v[VF3_REG_FPSCR])); }

#endif /* VF3_READABLE_FP_H */
