/* poly_clip_walk.c - 0x8C0488E0  walk a polygon's vertex records and run the clip/emit helpers on them.
 *
 *   r4 -> a strip body: { u32 count; vertex records... } where a record is 8 bytes, or 32 bytes when bit 0
 *   of its second word is set (the long form carries 24 more bytes). Vertices are classified one at a
 *   time with vertex_light (0x8C048B00, answers in T: inside / outside) and the answers are shifted
 *   into r9 with rotcl, so after three or four vertices r9 holds the inside/outside pattern of the
 *   corner just passed. r11 is the index of the vertex being handled, r3 the vertices still to go
 *   and r12 the flags of the strip (bit 0 = leave the closing edge alone).
 *
 *   The pattern (r9 & 7) picks what to emit (vertex_emit_ring 0x8C048C20, vertex_emit_sq 0x8C048BE0,
 *   0x8C048C40/0x8C048C80 and clip_edge 0x8C048CC0, called with the vertex index in r0 minus 0..2):
 *     0, 1, 7  both edges at the corner     2  edge + shared edge      3  one edge, then loop
 *     4        two edges                    5  one edge                6  odd/even index pair
 *   After each corner the walk continues with the next vertex (back to 0x8C048A0E) or, when the
 *   strip is used up, reads the trailer word: a positive flags word with bit 0x80 set chains the next
 *   strip (r4 is advanced, r3 reloaded), anything else ends with r0 = 1 and r12 |= 1.
 *   With T set on entry the work is handed to 0x8C047CE0 untouched.
 *
 *   This is the original's state machine, kept as labels named by their address: the T bit that
 *   crosses every helper call is part of the helpers' contract, so it is carried in SR bit 0.
 *   Frame: r10, r11 and pr pushed (12 bytes); nothing else on the stack. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"

#define LIGHT 0x8C048B00u
#define EMIT_SQ 0x8C048BE0u
#define RING   0x8C048C20u
#define EMIT_A 0x8C048C40u
#define EMIT_B 0x8C048C80u
#define CLIP   0x8C048CC0u

#define T()      (R(VF3_REG_SR) & 1u)
#define SET_T(v) (R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | ((v) ? 1u : 0u))
#define CALL(target, ret) do { if (!vf3_guest_call(s, ram, (target), (ret))) return 0; } while (0)

static void rotcl_r9(vf3_matrix_state *s)
{
    const uint32_t carry = T();
    SET_T(R(9) >> 31);
    R(9) = (R(9) << 1) | carry;
}

static void dt_r3(vf3_matrix_state *s) { R(3) -= 1; SET_T(R(3) == 0); }

/* the record after the one r4 points at stepped back: 8 bytes, 32 when its second word has bit 0 */
static void step_back(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    R(4) -= 8;
    R(0) = m32(ram, R(4) + 4);
    SET_T(!(R(0) & 1u));
    if (!T()) R(4) -= 24;
}

/* r4 steps forward over the record it points at */
static void step_fwd(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    R(0) = m32(ram, R(4));
    SET_T(!(R(0) & 1u));
    R(4) += 8;
    if (!T()) R(4) += 24;
}

int vf3_poly_clip_walk_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15), pr0 = R(VF3_REG_PR), r10_0 = R(10), r11_0 = R(11), f = sp0 - 12;

    if (T()) {                                                  /* bf / bra: tail jump, nothing pushed */
        if (!vf3_guest_call(s, ram, 0x8C047CE0u, pr0)) return 0;
        return 1;
    }
    w32(ram, sp0 - 4, r10_0);
    w32(ram, sp0 - 8, r11_0);
    w32(ram, sp0 - 12, pr0);
    R(15) = f;


    R(3) = m32(ram, R(4)); R(4) += 4;
L8ee:
    R(11) = 0;
    R(9) = 0;
    CALL(LIGHT, 0x8C0488F4u);
    {   const int br = T(); rotcl_r9(s); if (br) goto L91a; }
    R(11) += 1; CALL(EMIT_SQ, 0x8C0488FCu);
    CALL(LIGHT, 0x8C048900u);
    {   const int br = T(); rotcl_r9(s); if (br) goto L94e; }
    R(11) += 1; CALL(EMIT_SQ, 0x8C048908u);
L908:
    CALL(LIGHT, 0x8C04890Cu);
    {   const int br = T(); rotcl_r9(s); if (br) goto L9c0; }
    R(11) += 1; CALL(EMIT_SQ, 0x8C048914u);
    if (!T()) goto L908;
    goto L932;

L91a:
    dt_r3(s); R(11) += 1; dt_r3(s);
    CALL(LIGHT, 0x8C048922u);
    {   const int br = !T(); rotcl_r9(s); if (br) goto L984; }
L926:
    R(11) += 1; CALL(LIGHT, 0x8C04892Au);
    {   const int br = !T(); rotcl_r9(s); if (br) goto L9c0; }
    dt_r3(s);
    if (!T()) goto L926;

L932:
    R(0) = m32(ram, R(4)); R(4) += 4;
    SET_T((int32_t)R(0) > 0);
    {   const int br = !T();
        SET_T(!(R(0) & 0x80u));
        if (br) goto L940;
    }
    {   const int br = !T();
        R(3) = m32(ram, R(4)); R(4) += 4;
        if (br) goto L8ee;
    }
    R(4) -= 4;
L940:
    R(0) = 1;
    R(4) -= 4;
    R(12) |= R(0);
    R(VF3_REG_PR) = m32(ram, f);
    R(11) = m32(ram, f + 4);
    R(10) = m32(ram, f + 8);
    R(15) = sp0;
    s->pc = R(VF3_REG_PR);
    return 1;

L94e:
    dt_r3(s); CALL(RING, 0x8C048952u);
    step_back(s, ram);
    step_back(s, ram);
    CALL(LIGHT, 0x8C04896Au);
    R(11) = 0; CALL(RING, 0x8C04896Eu);
    R(11) = 1; SET_T(0);
    R(0) = 0; CALL(CLIP, 0x8C048976u);
    step_fwd(s, ram);
    goto La0e;

L984:
    R(11) = 1; CALL(RING, 0x8C048988u);
    step_back(s, ram);
    step_back(s, ram);
    CALL(LIGHT, 0x8C0489A0u);
    R(11) = 0; CALL(RING, 0x8C0489A4u);
    R(11) = 1; SET_T(0);
    R(0) = 0; CALL(CLIP, 0x8C0489ACu);
    SET_T(0);
    R(0) = 1; CALL(EMIT_B, 0x8C0489B2u);
    step_fwd(s, ram);
    goto La0e;

L9c0:
    CALL(RING, 0x8C0489C4u);
    step_back(s, ram);
    step_back(s, ram);
    step_back(s, ram);
    CALL(LIGHT, 0x8C0489E6u);
    R(11) -= 2; CALL(RING, 0x8C0489EAu);
    CALL(LIGHT, 0x8C0489EEu);
    R(11) += 1; CALL(RING, 0x8C0489F2u);
    step_fwd(s, ram);
    R(11) += 1;
    R(0) = R(12);
    SET_T(!(R(0) & 1u));
    {   const int br = T(); R(0) = R(9); if (br) goto La24; }
    CALL(EMIT_A, 0x8C048A0Au);
    R(0) = R(9);
    goto La24;

La0e:
    R(11) += 1; CALL(LIGHT, 0x8C048A12u);
    rotcl_r9(s); CALL(RING, 0x8C048A16u);
    R(0) = R(12);
    SET_T(!(R(0) & 1u));
    {   const int br = T(); R(0) = R(9); if (br) goto La24; }
    CALL(EMIT_A, 0x8C048A22u);
    R(0) = R(9);

La24:
    switch (R(0) & 7u) {                                        /* braf r0 into the case table at 0x8C048A2C */
    default: goto La4c;                                         /* 0, 1, 7 */
    case 2: goto La6a;
    case 3: goto La84;
    case 4: goto La94;
    case 5: goto Lab4;
    case 6: goto Lac2;
    }

La4c:
    R(0) = R(11); SET_T(0); R(0) -= 2; CALL(CLIP, 0x8C048A54u);
    R(0) = R(11); SET_T(0); R(0) -= 1; CALL(EMIT_B, 0x8C048A5Cu);
    R(0) = R(11); dt_r3(s); R(0) -= 1; CALL(CLIP, 0x8C048A64u);
    if (!T()) goto La0e;
    goto L932;

La6a:
    SET_T(0); R(0) = R(11); CALL(EMIT_B, 0x8C048A70u);
    R(0) = R(11); SET_T(0); R(0) -= 1; CALL(CLIP, 0x8C048A78u);
    dt_r3(s); R(0) = R(11); CALL(EMIT_B, 0x8C048A7Eu);
    if (!T()) goto La0e;
    goto L932;

La84:
    R(0) = R(11); SET_T(1); R(0) -= 2; CALL(CLIP, 0x8C048A8Cu);
    dt_r3(s);
    if (T()) goto Lab0;
    goto L926;

La94:
    R(0) = R(11); SET_T(0); R(0) -= 2; CALL(CLIP, 0x8C048A9Cu);
    R(0) = R(11); SET_T(0); R(0) -= 1; CALL(EMIT_B, 0x8C048AA4u);
    dt_r3(s); R(0) = R(11); CALL(EMIT_B, 0x8C048AAAu);
    if (T()) goto Lab0;
    R(11) += 1;
    goto L908;
Lab0:
    goto L932;

Lab4:
    R(0) = R(11); dt_r3(s); R(0) -= 1; CALL(CLIP, 0x8C048ABCu);
    if (!T()) goto La0e;
    goto L932;

Lac2:
    R(0) = R(11);
    SET_T(!(R(0) & 1u));
    if (T()) {                                                  /* even index */
        R(0) = R(11); SET_T(0); R(0) -= 2; CALL(CLIP, 0x8C048AECu);
        R(0) = R(11); SET_T(0); R(0) -= 1; CALL(CLIP, 0x8C048AF4u);
    } else {                                                    /* odd index */
        R(0) = R(11); SET_T(0); R(0) -= 1; CALL(CLIP, 0x8C048AD0u);
        R(0) = R(11); SET_T(0); R(0) -= 2; CALL(CLIP, 0x8C048AD8u);
        R(0) = R(11); SET_T(0); R(0) -= 1; CALL(CLIP, 0x8C048AE0u);
    }
    dt_r3(s); R(0) = R(11); CALL(EMIT_B, 0x8C048AFAu);
    if (!T()) goto La0e;
    goto L932;
}
