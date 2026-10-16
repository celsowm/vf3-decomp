/* terrain_quad_test.c - 0x8C068FE4  is the point (FR4, FR5) = (x, z) inside a terrain quad?
 *
 *   r4 -> quad record: +0 flags (bit 0 = ignore the quad, returns 1), +4 offset of the shape record from the
 *   base at [0x0C113A0C]. The shape record has a flag word (bit 0 = single-sided), a float at +24 (zero =
 *   degenerate, returns 0) and four vertex offsets at +4 / +8 / +12 / +16 (A, B, C, D; x at +0, z at +8).
 *
 *   The point is tested against the five edges A-B, B-C, C-A, C-D and D-A with tri_winding (0x8C068F92,
 *   which answers 1 = on the edge, 2 = left, 4 = right). The answers are or-ed together per triangle
 *   (A-B-C from edges 1-3, C-D-A from edges 4-5 plus C-A). Returns 2 when triangle A-B-C has the point on
 *   exactly one side pair, and for a double-sided quad 4 when triangle C-D-A does; otherwise 0.
 *
 *   Frame (4 bytes under nine saved words): +0 the shape record's single-sided flag. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"

enum { SAVED = 36, FRAME = 4, LEFT = 2, RIGHT = 4, SIDES = 6 };

/* the answer of tri_winding for the edge u -> v, as the original sets up its FR registers */
static int winding(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t ret, uint32_t u, uint32_t v, uint32_t *out)
{
    F(4) = F(14); F(5) = F(15);
    F(6) = m32(ram, u); F(7) = m32(ram, u + 8);
    F(8) = m32(ram, v); F(9) = m32(ram, v + 8);
    if (!vf3_guest_call(s, ram, 0x8C068F92u, ret)) return 0;
    *out = R(0);
    return 1;
}

/* one of the two side bits set, not both (or neither is covered by the caller) */
static int one_side(uint32_t bits)
{
    return ((bits & RIGHT) != 0) != ((bits & LEFT) != 0);
}

int vf3_terrain_quad_test_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), f = sp0 - SAVED - FRAME;
    const uint32_t saved_r[6] = { R(14), R(13), R(12), R(11), R(10), R(9) };
    const uint32_t saved_f[2] = { F(15), F(14) };
    static const int pushed[6] = { 14, 13, 12, 11, 10, 9 };
    const uint32_t quad = R(4);
    uint32_t result = 0;

    for (int i = 0; i < 6; ++i) w32(ram, sp0 - 4u * (uint32_t)(i + 1), saved_r[i]);
    w32(ram, sp0 - 28, saved_f[0]);
    w32(ram, sp0 - 32, saved_f[1]);
    w32(ram, sp0 - 36, pr0);
    R(15) = f;

    const uint32_t base = m32(ram, 0x0C113A0Cu);
    const uint32_t shape = m32(ram, quad + 4) + base;
    R(4) = 1; R(6) = base; R(5) = shape; R(7) = m32(ram, quad);

    if (R(7) & 1u) { result = 1; goto done; }

    F(14) = F(4);
    const uint32_t single_sided = m32(ram, shape) & 1u;
    w32(ram, f, single_sided);
    R(7) = single_sided;
    F(4) = m32(ram, shape + 24);
    F(3) = 0;
    F(15) = F(5);
    if (fl(s, 4) == 0.0f) goto done;                        /* degenerate quad */

    const uint32_t a = m32(ram, shape + 4) + base, b = m32(ram, shape + 8) + base;
    const uint32_t c = m32(ram, shape + 12) + base, d = m32(ram, shape + 16) + base;
    uint32_t w1, w2, w3, w4, w5;
    R(13) = a; R(11) = b; R(12) = c; R(10) = d;

    if (!winding(s, ram, 0x8C069048u, a, b, &w1)) return 0;
    R(14) = w1;
    if (!winding(s, ram, 0x8C06905Au, b, c, &w2)) return 0;
    R(9) = w2;
    if (!winding(s, ram, 0x8C06906Cu, c, a, &w3)) return 0;
    R(11) = w3;
    if (!winding(s, ram, 0x8C06907Eu, c, d, &w4)) return 0;
    R(12) = w4;
    if (!winding(s, ram, 0x8C069090u, d, a, &w5)) return 0;
    R(15) = f;

    const uint32_t abc_ab = w1 | (w2 & SIDES);              /* edges A-B and B-C */
    const uint32_t abc = w3 | (abc_ab & SIDES);             /* ... and C-A */
    const uint32_t cda = w4 | (w5 & SIDES);                 /* edges C-D and D-A */

    if (one_side(abc)) { result = 2; goto done; }
    if (single_sided) goto done;
    {
        const uint32_t both = abc_ab | (cda & SIDES);
        if (one_side(both)) result = 4;
    }

done:
    R(0) = result;
    for (int i = 0; i < 6; ++i) R(pushed[i]) = saved_r[i];
    F(15) = saved_f[0]; F(14) = saved_f[1];
    R(15) = sp0;
    R(VF3_REG_PR) = pr0;
    s->pc = pr0;
    return 1;
}
