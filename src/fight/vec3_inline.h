/* vec3_inline.h - the vec3 helpers the collision routines inline, written as the same FR-register sequences
 * as the original so FR0-FR12 and the pointer registers are left identical. Included by capsule_chain.c and
 * body_collide.c; each includes it once, after readable.h / readable_fp.h. */
#ifndef VF3_VEC3_INLINE_H
#define VF3_VEC3_INLINE_H

#include "fight/readable.h"
#include "fight/readable_fp.h"

#define R(n) (s->v[(n)])
#define F(n) VF3_FR(s, (n))
#define SIGN 0x80000000u


static inline uint32_t m32(const vf3_ram_map *ram, uint32_t a) { return vf3_mem_u32(ram, a); }
static inline void w32(const vf3_ram_map *ram, uint32_t a, uint32_t v) { vf3_mem_set_u32(ram, a, v); }
static inline float fl(const vf3_matrix_state *s, int n) { return vf3_fr_get(s, n); }
static inline void set_fl(vf3_matrix_state *s, int n, float v) { vf3_fr_set(s, n, v); }
static inline int fgt(const vf3_matrix_state *s, int a, int b) { return fl(s, a) > fl(s, b); }   /* fcmp/gt FRb,FRa */

/* dst = a - b */
static inline void v3_sub(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t d, uint32_t a, uint32_t b)
{
    R(4) = d; R(5) = a + 8; R(6) = b + 8;                 /* pointer registers as the inlined loop leaves them */
    F(0) = m32(ram, a); F(3) = m32(ram, b); F(1) = m32(ram, a + 4); F(4) = m32(ram, b + 4);
    set_fl(s, 0, vf3_f_sub(s, fl(s, 0), fl(s, 3)));
    F(2) = m32(ram, a + 8); F(5) = m32(ram, b + 8);
    set_fl(s, 1, vf3_f_sub(s, fl(s, 1), fl(s, 4)));
    set_fl(s, 2, vf3_f_sub(s, fl(s, 2), fl(s, 5)));
    w32(ram, d + 8, F(2)); w32(ram, d + 4, F(1)); w32(ram, d, F(0));
}

/* dst = a + b */
static inline void v3_add(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t d, uint32_t a, uint32_t b,
                   int in_place)
{
    R(4) = d; R(5) = in_place ? b + 12 : a + 12;
    if (!in_place) R(6) = b + 12;
    F(0) = m32(ram, a); F(3) = m32(ram, b); F(1) = m32(ram, a + 4); F(4) = m32(ram, b + 4);
    F(2) = m32(ram, a + 8); F(5) = m32(ram, b + 8);
    set_fl(s, 0, vf3_f_add(s, fl(s, 0), fl(s, 3)));
    set_fl(s, 2, vf3_f_add(s, fl(s, 2), fl(s, 5)));
    set_fl(s, 1, vf3_f_add(s, fl(s, 1), fl(s, 4)));
    w32(ram, d + 8, F(2)); w32(ram, d + 4, F(1)); w32(ram, d, F(0));
}

/* dst = a * FR4 */
static inline void v3_scale(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t d, uint32_t a)
{
    R(4) = d; R(5) = a + 12;
    F(0) = m32(ram, a); F(1) = m32(ram, a + 4); F(2) = m32(ram, a + 8);
    set_fl(s, 2, vf3_f_mul(s, fl(s, 2), fl(s, 4)));
    set_fl(s, 1, vf3_f_mul(s, fl(s, 1), fl(s, 4)));
    set_fl(s, 0, vf3_f_mul(s, fl(s, 0), fl(s, 4)));
    w32(ram, d + 8, F(2)); w32(ram, d + 4, F(1)); w32(ram, d, F(0));
}

/* dst = a / |a| * FR4  (fipr + fsrra) */
static inline int v3_normalize(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t d, uint32_t a)
{
    R(4) = d; R(5) = a + 12;
    F(0) = m32(ram, a); F(1) = m32(ram, a + 4); F(2) = m32(ram, a + 8);
    F(3) = 0;
    if (!vf3_fpu_fipr(&F(0), &F(0), R(VF3_REG_FPSCR), &F(3))) return 0;
    if (!vf3_fpu_fsrra(F(3), R(VF3_REG_FPSCR), &F(3))) return 0;
    set_fl(s, 3, vf3_f_mul(s, fl(s, 3), fl(s, 4)));
    set_fl(s, 2, vf3_f_mul(s, fl(s, 2), fl(s, 3)));
    set_fl(s, 1, vf3_f_mul(s, fl(s, 1), fl(s, 3)));
    set_fl(s, 0, vf3_f_mul(s, fl(s, 0), fl(s, 3)));
    w32(ram, d + 8, F(2)); w32(ram, d + 4, F(1)); w32(ram, d, F(0));
    return 1;
}

/* FR0 = |a|, FR3 left at 0 for the caller's comparison */
static inline int v3_length(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t a)
{
    R(4) = a + 12;
    F(0) = m32(ram, a); F(1) = m32(ram, a + 4); F(2) = m32(ram, a + 8);
    F(3) = 0;
    if (!vf3_fpu_fipr(&F(0), &F(0), R(VF3_REG_FPSCR), &F(3))) return 0;
    F(0) = F(3);
    F(0) = vf3_fpu_sqrt(F(0), R(VF3_REG_FPSCR));
    F(3) = 0;
    return 1;
}

/* FR0 = |a x b| */
static inline int v3_cross_length(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t a, uint32_t b)
{
    R(4) = a + 8; R(5) = b + 8;
    F(0) = m32(ram, a); F(5) = m32(ram, a + 4); F(6) = m32(ram, a + 8);
    F(8) = m32(ram, b); F(9) = m32(ram, b + 4); F(10) = m32(ram, b + 8);
    F(3) = F(5); set_fl(s, 3, vf3_f_mul(s, fl(s, 3), fl(s, 8)));
    F(2) = F(0); set_fl(s, 2, vf3_f_mul(s, fl(s, 2), fl(s, 10)));
    F(1) = F(6); set_fl(s, 1, vf3_f_mul(s, fl(s, 1), fl(s, 9)));
    F(3) ^= SIGN; set_fl(s, 3, vf3_f_mac(s, fl(s, 0), fl(s, 9), fl(s, 3)));
    F(2) ^= SIGN; F(0) = F(6); set_fl(s, 2, vf3_f_mac(s, fl(s, 0), fl(s, 8), fl(s, 2)));
    F(1) ^= SIGN; F(0) = F(5); set_fl(s, 1, vf3_f_mac(s, fl(s, 0), fl(s, 10), fl(s, 1)));
    F(0) = 0;
    if (!vf3_fpu_fipr(&F(0), &F(0), R(VF3_REG_FPSCR), &F(3))) return 0;
    F(0) = F(3);
    F(0) = vf3_fpu_sqrt(F(0), R(VF3_REG_FPSCR));
    return 1;
}

/* FR4 = FR0 = a . b ; FR3 = 0 */
static inline int v3_dot(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t a, uint32_t b)
{
    R(4) = a + 12; R(5) = b + 12;
    F(0) = m32(ram, a); F(1) = m32(ram, a + 4); F(2) = m32(ram, a + 8); F(3) = 0;
    F(4) = m32(ram, b); F(5) = m32(ram, b + 4); F(6) = m32(ram, b + 8); F(7) = 0;
    if (!vf3_fpu_fipr(&F(0), &F(4), R(VF3_REG_FPSCR), &F(7))) return 0;
    F(0) = F(7);
    F(3) = 0;
    F(4) = F(0);
    return 1;
}

/* d = a x b, the cross product laid out the way the original's inline sequence does (leaves FR0 = a.y,
 * FR1..FR3 = x, y, z of the result and the pointer registers as the sequence ends) */
static inline void v3_cross(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t d, uint32_t a, uint32_t b)
{
    R(4) = a + 8; R(5) = b + 8; R(6) = d;
    F(0) = m32(ram, a); F(5) = m32(ram, a + 4); F(6) = m32(ram, a + 8);
    F(8) = m32(ram, b); F(9) = m32(ram, b + 4); F(10) = m32(ram, b + 8);
    F(3) = F(5); set_fl(s, 3, vf3_f_mul(s, fl(s, 3), fl(s, 8)));
    F(2) = F(0); set_fl(s, 2, vf3_f_mul(s, fl(s, 2), fl(s, 10)));
    F(1) = F(6); set_fl(s, 1, vf3_f_mul(s, fl(s, 1), fl(s, 9)));
    F(3) ^= SIGN; set_fl(s, 3, vf3_f_mac(s, fl(s, 0), fl(s, 9), fl(s, 3)));
    F(2) ^= SIGN; F(0) = F(6); set_fl(s, 2, vf3_f_mac(s, fl(s, 0), fl(s, 8), fl(s, 2)));
    F(1) ^= SIGN;
    w32(ram, d + 8, F(3));
    F(0) = F(5); set_fl(s, 1, vf3_f_mac(s, fl(s, 0), fl(s, 10), fl(s, 1)));
    w32(ram, d + 4, F(2)); w32(ram, d, F(1));
}

/* p = p / |p| in place (fipr + fsrra, no extra scale) */
static inline int v3_unit(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t p)
{
    R(4) = p;
    F(0) = m32(ram, p); F(1) = m32(ram, p + 4); F(2) = m32(ram, p + 8);
    F(3) = 0;
    if (!vf3_fpu_fipr(&F(0), &F(0), R(VF3_REG_FPSCR), &F(3))) return 0;
    if (!vf3_fpu_fsrra(F(3), R(VF3_REG_FPSCR), &F(3))) return 0;
    set_fl(s, 2, vf3_f_mul(s, fl(s, 2), fl(s, 3)));
    set_fl(s, 1, vf3_f_mul(s, fl(s, 1), fl(s, 3)));
    set_fl(s, 0, vf3_f_mul(s, fl(s, 0), fl(s, 3)));
    w32(ram, p + 8, F(2)); w32(ram, p + 4, F(1)); w32(ram, p, F(0));
    return 1;
}

#endif
