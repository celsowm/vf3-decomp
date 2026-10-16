/* display_list.c - walk a model display list: cull, light and submit it, SH-4 0x8C048260.
 *
 *   r4 = display list (24 header bytes are skipped), r5 = view/light block (9 words)
 *
 * The renderer front end. A list is a run of nodes, each starting with the four words of a TA
 * polygon header (parameter control word first, whose bits 24..26 pick one of eight output
 * lists), then a bounding sphere and a payload:
 *
 *   +00 pcw  +04 isp  +08 tsp  +0C tex        polygon header, kept as is
 *   +10 x  +14 y  +18 z  +1C radius            bounding sphere (model space)
 *   +20 word             byte +4 is the shininess index k (see below)
 *   +24 word             bit 0 set = no sprite; the whole word is also the ambient factor
 *   +28 .. +47           eight sprite vertex words, scaled by the tint triple at 0x0C0EA634
 *   +4C size, size bytes more payload that is skipped when the node is culled
 *   then the strips of the node: a descriptor word > 0 (bit 6/4/3/2 pick the strip
 *   transformer, bits 0..1 the blend selector) followed by the strip, repeated until a word <= 0:
 *   that is the next node's pcw, 0 ends the list.
 *
 * The block in r5 holds the lights: the diffuse direction (3 words) and the specular half vector
 * (3 words) end up in FV12 / FV8, the depth limit in r12, the ambient scale in r13; the three
 * direction words are scaled by 1 / (the model scale at 0x0C16B8A8, which is reset to 1.0).
 *
 * Per node the sphere centre goes through XMTRX. Against the depth limit:
 *   sphere entirely beyond it          -> culled: the node is skipped; if it has a sprite
 *                                          (and its header asks for one, bit 0x20) the sprite
 *                                          is still emitted on its own
 *   otherwise four side-plane tests (view factors at 0x0C19D598/9C, 0x0C0EA534/38)
 *                                      -> any failure culls as above
 *   visible: the sprite is staged in the second store-queue slot, the shininess index becomes the
 *   specular selector r8 (4k, or 36 / 40 for k = 16 / other) and the ambient factor in FR15, and
 *   each strip is handed to its transformer with a freshly written header slot.
 * The polygon header words of the current node are copied to the staging buffer at 0x0C1A5920
 * as the tests go; strip headers are patched from it (bit 1 = strip bit 6, bits 27..28 = blend).
 * Output goes to the store queue of the node's list; the per-list write cursors live in the table
 * pointed to by 0x0C16CA08 and are written back when a node ends.
 *
 * Strip transformers by descriptor: bit 3 -> 0x8C048F60, else bit 2 -> 0x8C048600 (quad strips),
 * else 0x8C0487A0 (lit strips); when the node straddled the depth limit (r12 bit 0 set) the
 * 0x8C0488E0 (bit 4) / 0x8C048D60 (bit 3) pair takes over instead. Shininess -2 / -3 call
 * 0x8C049080 / 0x8C0499E0, which consume the node themselves.
 *
 * The original saves FR12-15 and R8-R14, PR (48 bytes) and builds a 40 byte frame whose words are
 * the constants it walks with; the dead stack words are replayed because they are visible in RAM. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"

enum {
    MODEL_SCALE = 0x0C16B8A8, VIEW_A = 0x0C19D598, VIEW_B = 0x0C19D59C,
    VIEW_C = 0x0C0EA534, VIEW_D = 0x0C0EA538, TINT = 0x0C0EA634, STAGE = 0x0C1A5920,
    SQ_STATE = 0x0C16CA08, QACR0 = 0xFF000038, QACR1 = 0xFF00003C,
    SQ_REGION = 0xE0000000, SQ_ADDR_MASK = 0x03FFFFFF, SLOT = 32,
    SAVED_BYTES = 48, FRAME_BYTES = 40, LIST_HEADER = 24,
    ENTRY_LIT_STRIP = 0x0C0487A0, ENTRY_QUAD_STRIP = 0x0C048600, ENTRY_STRIP_F60 = 0x0C048F60,
    ENTRY_STRIP_8E0 = 0x0C0488E0, ENTRY_STRIP_D60 = 0x0C048D60,
    ENTRY_NODE_M2 = 0x0C049080, ENTRY_NODE_M3 = 0x0C0499E0,
    RET_LIT = 0x0C04855E, RET_QUAD = 0x0C048570, RET_F60 = 0x0C048578,
    RET_8E0 = 0x0C0485AC, RET_D60 = 0x0C0485B6, RET_M2 = 0x0C04849C, RET_M3 = 0x0C0484B2,
    PCW_LIST_SHIFT = 24, PCW_LIST_MASK = 7,
    NODE_BEYOND = 1,                 /* r12 bit 0: the sphere reaches in front of the depth limit */
    STRIP_BLEND_MASK = 3, STRIP_BLEND_SHIFT = 27, STRIP_NO_FOG = 0x40, STRIP_SELECT_8E0 = 0x10,
    STRIP_SELECT_BIT3 = 8, STRIP_SELECT_BIT2 = 4, STRIP_TEX_FLAG = 0x20,
    HDR_FOG_BIT = 2, HDR_SENT = 0x10
};

typedef struct {
    vf3_matrix_state *s;
    const vf3_ram_map *ram;
    uint32_t frame;                  /* sp after the prologue */
    uint32_t list, cursor, sq;       /* r4, r5, r6 */
    uint32_t pcw, hdr1, hdr2, hdr3;  /* current node's header words (r8, r1, FR2, FR3) */
    uint32_t selector;               /* r8 while strips run */
    uint32_t limit, tint_scale, table, spare;  /* r12, r13, r10, r7 */
    int32_t last_list;               /* r11 */
    float view_a, view_b, view_c, view_d, tint[3];
} walker;

static uint32_t rd(const walker *w, uint32_t a) { return vf3_mem_u32(w->ram, a); }
static float rdf(const walker *w, uint32_t a) { return vf3_mem_f32(w->ram, a); }
static void wr(const walker *w, uint32_t a, uint32_t v) { vf3_mem_set_u32(w->ram, a, v); }
static float fneg(float f) { return vf3_bits_f32(vf3_f32_bits(f) ^ 0x80000000u); }

static void read_header(walker *w)
{
    w->hdr1 = rd(w, w->list);
    w->hdr2 = rd(w, w->list + 4);
    w->hdr3 = rd(w, w->list + 8);
    w->list += 12;
}

/* Point r6 at the node's list slot; reprogram the store queue when the list changes. */
static void select_list(walker *w, int32_t slot)
{
    w->cursor = rd(w, w->table + (uint32_t)slot);
    if (slot != w->last_list) {
        wr(w, QACR0, w->cursor >> 24);
        wr(w, QACR1, w->cursor >> 24);
    }
    w->last_list = slot;
    w->sq = SQ_REGION | (w->cursor & SQ_ADDR_MASK);
}

/* The sprite's eight words at `src`, scaled by the tint triple (word 0 only by 1.0, word 4 not at
 * all) and written to the 32 bytes at `dst`. */
static void write_sprite(const walker *w, uint32_t src, uint32_t dst)
{
    const vf3_matrix_state *s = w->s;
    const float *t = w->tint;
    float v[8];
    for (int i = 0; i < 8; ++i) v[i] = rdf(w, src + 4u * (uint32_t)i);
    v[0] = vf3_f_mul(s, v[0], 1.0f);
    v[1] = vf3_f_mul(s, v[1], t[0]);
    v[2] = vf3_f_mul(s, v[2], t[1]);
    v[3] = vf3_f_mul(s, v[3], t[2]);
    v[5] = vf3_f_mul(s, v[5], t[0]);
    v[6] = vf3_f_mul(s, v[6], t[1]);
    v[7] = vf3_f_mul(s, v[7], t[2]);
    for (int i = 0; i < 8; ++i) vf3_mem_set_f32(w->ram, dst + 4u * (uint32_t)i, v[i]);
}

/* Put the registers the strip transformers look at into the state and call one. */
static int call_strip(walker *w, uint32_t entry, uint32_t ret, uint32_t strip, int t_flag)
{
    vf3_matrix_state *s = w->s;
    s->v[0] = strip;
    s->v[1] = strip;
    s->v[3] = w->frame + 36u;
    s->v[4] = w->list;
    s->v[5] = w->cursor;
    s->v[6] = w->sq;
    s->v[7] = w->spare;
    s->v[8] = w->selector;
    s->v[9] = STAGE + 16u;
    s->v[10] = w->table;
    s->v[11] = (uint32_t)w->last_list;
    s->v[12] = w->limit;
    s->v[13] = w->tint_scale;
    s->v[VF3_REG_SR] = (s->v[VF3_REG_SR] & ~1u) | (t_flag ? 1u : 0u);
    s->v[15] = w->frame;
    if (!vf3_guest_call(s, w->ram, entry, ret)) return 0;
    w->list = s->v[4];
    w->cursor = s->v[5];
    w->sq = s->v[6];
    w->selector = s->v[8];
    w->limit = s->v[12];
    return 1;
}

/* Cull path: skip the node, drawing only its sprite. Returns 1 at the end of the list. */
static int skip_node(walker *w)
{
    const uint32_t payload = w->list;
    wr(w, w->sq, w->pcw);
    const uint32_t size = rd(w, payload + 44u);
    w->list = payload + 48u + size;
    const uint32_t emit_pcw = w->pcw;
    w->pcw = rd(w, w->list);
    w->list += 4;
    if (w->pcw == 0) return 1;

    const uint32_t word = rd(w, payload + 8u);
    if (!(word & 1u) && (emit_pcw & STRIP_TEX_FLAG)) {   /* no sprite flag clear, header asks for one */
        wr(w, w->sq + 4u, 0);
        wr(w, w->sq + 8u, 0);
        wr(w, w->sq + 12u, 0);
        vf3_matrix_pref(w->ram, w->sq);
        write_sprite(w, payload + 12u, w->sq + SLOT);
        w->cursor += 2u * SLOT;
        vf3_matrix_pref(w->ram, w->sq + SLOT);
        w->sq += 2u * SLOT;
        wr(w, w->table + (uint32_t)w->last_list, w->cursor);
    }
    read_header(w);
    return 0;
}

/* Write the polygon header slot of one strip (patched from the staged node header) and flush it. */
static void write_strip_header(walker *w, uint32_t strip)
{
    uint32_t hdr0 = (rd(w, STAGE) & ~(uint32_t)HDR_FOG_BIT) | ((strip & STRIP_NO_FOG) >> 5);
    const int already_sent = (hdr0 & HDR_SENT) != 0;
    if (!already_sent) wr(w, STAGE, hdr0 | HDR_SENT);
    const uint32_t blend = (strip & STRIP_BLEND_MASK) << STRIP_BLEND_SHIFT;
    const uint32_t hdr1 = (rd(w, STAGE + 4u) & ~(STRIP_BLEND_MASK << STRIP_BLEND_SHIFT)) | blend;
    wr(w, w->sq + 8u, rd(w, STAGE + 8u));
    wr(w, w->sq + 12u, rd(w, STAGE + 12u));
    wr(w, w->sq, hdr0);
    wr(w, w->sq + 4u, hdr1);
    w->cursor += SLOT;
    vf3_matrix_pref(w->ram, w->sq);
    w->sq += SLOT;
    if (!already_sent) {                          /* the staged sprite slot goes out behind the first header */
        vf3_matrix_pref(w->ram, w->sq);
        w->sq += SLOT;
        w->cursor += SLOT;
    }
}

int vf3_display_list_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (s->v[VF3_REG_FPSCR] & 0x00100000u) return 0;
    walker w = { .s = s, .ram = ram };
    const uint32_t sp0 = s->v[15], pr = s->v[VF3_REG_PR];
    const uint32_t macl = s->v[VF3_REG_MACL], mach = s->v[VF3_REG_MACH];  /* strip transformers may use them */
    uint32_t saved[16];
    for (int i = 0; i < 4; ++i) saved[i] = VF3_FR(s, 15 - i);
    for (int i = 0; i < 7; ++i) saved[4 + i] = s->v[14 - i];
    for (int i = 0; i < 4; ++i) vf3_mem_set_u32(ram, sp0 - 4u * (uint32_t)(i + 1), saved[i]);
    for (int i = 0; i < 7; ++i) vf3_mem_set_u32(ram, sp0 - 16u - 4u * (uint32_t)(i + 1), saved[4 + i]);
    vf3_mem_set_u32(ram, sp0 - 48u, pr);
    w.frame = sp0 - SAVED_BYTES - FRAME_BYTES;

    /* model scale: its reciprocal scales the light block, the magnitude the sphere radii; reset to 1 */
    w.list = s->v[4] + LIST_HEADER;
    const float model_scale = vf3_mem_f32(ram, MODEL_SCALE);
    const float inv_scale = vf3_f_div(s, 1.0f, model_scale);
    const float radius_scale = vf3_bits_f32(vf3_f32_bits(model_scale) & 0x7FFFFFFFu);
    vf3_mem_set_f32(ram, MODEL_SCALE, 1.0f);
    w.view_a = vf3_mem_f32(ram, VIEW_A);
    w.view_b = vf3_mem_f32(ram, VIEW_B);
    w.view_c = vf3_mem_f32(ram, VIEW_C);
    w.view_d = vf3_mem_f32(ram, VIEW_D);
    for (int i = 0; i < 3; ++i) w.tint[i] = vf3_mem_f32(ram, TINT + 4u * (uint32_t)i);
    vf3_mem_set_f32(ram, w.frame, 1.0f);
    vf3_mem_set_f32(ram, w.frame + 4u, radius_scale);
    vf3_mem_set_u32(ram, w.frame + 8u, vf3_f32_bits(w.view_a));
    vf3_mem_set_u32(ram, w.frame + 12u, vf3_f32_bits(w.view_b));
    vf3_mem_set_u32(ram, w.frame + 16u, vf3_f32_bits(w.view_c));
    vf3_mem_set_u32(ram, w.frame + 20u, vf3_f32_bits(w.view_d));
    for (int i = 0; i < 3; ++i) vf3_mem_set_u32(ram, w.frame + 24u + 4u * (uint32_t)i, vf3_f32_bits(w.tint[i]));
    vf3_mem_set_u32(ram, w.frame + 36u, STAGE);

    /* light block */
    const uint32_t blk = s->v[5];
    VF3_FR(s, 10) = vf3_mem_u32(ram, blk);
    VF3_FR(s, 8) = vf3_mem_u32(ram, blk + 4u);
    VF3_FR(s, 9) = vf3_mem_u32(ram, blk + 8u);
    w.limit = vf3_mem_u32(ram, blk + 12u);
    vf3_fr_set(s, 14, vf3_f_mul(s, vf3_mem_f32(ram, blk + 16u), inv_scale));
    vf3_fr_set(s, 12, vf3_f_mul(s, vf3_mem_f32(ram, blk + 20u), inv_scale));
    vf3_fr_set(s, 13, vf3_f_mul(s, vf3_mem_f32(ram, blk + 24u), inv_scale));
    w.tint_scale = vf3_mem_u32(ram, blk + 28u);
    w.spare = vf3_mem_u32(ram, blk + 32u);
    w.table = vf3_mem_u32(ram, SQ_STATE);
    w.last_list = -1;

    w.pcw = rd(&w, w.list);
    w.list += 4;
    read_header(&w);
    s->v[15] = w.frame;

    for (;;) {
        /* sphere centre and radius, centre through XMTRX */
        const uint32_t centre[4] = { rd(&w, w.list), rd(&w, w.list + 4u), rd(&w, w.list + 8u),
                                     vf3_f32_bits(1.0f) };
        uint32_t t[4];
        if (!vf3_fpu_ftrv(&s->v[VF3_REG_XF0], centre, s->v[VF3_REG_FPSCR], t)) return 0;
        const float x = vf3_bits_f32(t[0]), y = vf3_bits_f32(t[1]), z = vf3_bits_f32(t[2]);
        const float depth = vf3_bits_f32(t[3]);
        const float radius = vf3_f_mul(s, rdf(&w, w.list + 12u), radius_scale);
        w.list += 16u;
        select_list(&w, (int32_t)(((w.pcw >> PCW_LIST_SHIFT) & PCW_LIST_MASK) << 2));

        /* depth range against the limit */
        const float limit = vf3_bits_f32(w.limit);
        const float far_edge = vf3_f_add(s, depth, radius);
        const int reaches = far_edge > limit;
        const float near_edge = vf3_f_sub(s, vf3_f_sub(s, far_edge, radius), radius);
        w.limit &= ~(uint32_t)NODE_BEYOND;
        if (reaches) w.limit += NODE_BEYOND;
        int culled = reaches && near_edge > limit;

        const uint32_t payload = w.list;
        if (!culled) {
            /* the staged header tracks how far the tests got */
            const float neg_r = fneg(radius);
            const float low_y = vf3_f_mul(s, w.view_a, neg_r);
            const float low_z = vf3_f_mul(s, w.view_b, neg_r);
            wr(&w, STAGE + 12u, w.hdr3);
            wr(&w, STAGE + 8u, w.hdr2);
            if (!(y > low_y) || !(z > low_z)) {
                culled = 1;
            } else {
                const float high_y = vf3_f_sub(s, vf3_f_mul(s, w.view_c, x), low_y);
                wr(&w, STAGE + 4u, w.hdr1);
                if (y > high_y) {
                    culled = 1;
                } else {
                    const float high_z = vf3_f_sub(s, vf3_f_mul(s, w.view_d, x), low_z);
                    wr(&w, STAGE, w.pcw);
                    if (z > high_z) culled = 1;
                }
            }
        }
        if (culled) {
            if (skip_node(&w)) break;
            continue;
        }

        /* visible: stage the sprite, derive the lighting selector */
        const uint32_t sprite_word = rd(&w, payload + 8u);
        const int32_t k = (int8_t)vf3_mem_u8(ram, payload + 4u);
        VF3_FR(s, 15) = sprite_word;
        w.list = payload + 48u;
        if (!(sprite_word & 1u)) write_sprite(&w, payload + 12u, w.sq + SLOT);

        int reset = 0;
        if (k >= 0) {
            vf3_fr_set(s, 15, vf3_f_mul(s, vf3_bits_f32(sprite_word), vf3_bits_f32(w.tint_scale)));
            w.selector = (uint32_t)k << 2;
            if (k > 8) w.selector = (w.selector == 64u) ? 36u : 40u;
        } else if (k == -2 || k == -3) {
            w.selector = (uint32_t)k;
            if (!call_strip(&w, k == -2 ? ENTRY_NODE_M2 : ENTRY_NODE_M3, k == -2 ? RET_M2 : RET_M3,
                            (uint32_t)k, 0)) return 0;
            if (s->v[VF3_REG_SR] & 1u) break;
            w.pcw = w.selector;
            read_header(&w);
            continue;
        } else {
            reset = 1;
        }
        if (reset) { w.selector = 0; VF3_FR(s, 15) = vf3_f32_bits(1.0f); }

        /* the node's strips */
        for (;;) {
            const int32_t strip = (int32_t)rd(&w, w.list);
            w.list += 4;
            if (strip <= 0) {
                w.pcw = (uint32_t)strip;
                wr(&w, w.table + (uint32_t)w.last_list, w.cursor);
                if (strip == 0) goto done;
                read_header(&w);
                break;
            }
            write_strip_header(&w, (uint32_t)strip);

            const int beyond = (w.limit & NODE_BEYOND) != 0;
            w.limit &= ~(uint32_t)NODE_BEYOND;
            const uint32_t sv = (uint32_t)strip;
            if (beyond) {
                if (!(sv & STRIP_NO_FOG)) w.limit += 1;
                const int t_flag = !(sv & STRIP_TEX_FLAG);
                if (sv & STRIP_SELECT_8E0) {
                    if (!call_strip(&w, ENTRY_STRIP_8E0, RET_8E0, sv, t_flag)) return 0;
                } else if (sv & STRIP_SELECT_BIT3) {
                    if (!call_strip(&w, ENTRY_STRIP_D60, RET_D60, sv, t_flag)) return 0;
                } else {
                    return 0;               /* the original spins forever here */
                }
            } else if (sv & STRIP_SELECT_BIT3) {
                if (!call_strip(&w, ENTRY_STRIP_F60, RET_F60, sv, !(sv & STRIP_SELECT_BIT2))) return 0;
            } else if (sv & STRIP_SELECT_BIT2) {
                if (!call_strip(&w, ENTRY_QUAD_STRIP, RET_QUAD, sv, 0)) return 0;
            } else {
                if (!call_strip(&w, ENTRY_LIT_STRIP, RET_LIT, sv, 1)) return 0;
            }
        }
    }
done:
    for (int i = 0; i < 4; ++i) VF3_FR(s, 15 - i) = saved[i];
    for (int i = 0; i < 7; ++i) s->v[14 - i] = saved[4 + i];
    s->v[4] = w.list;
    s->v[5] = w.cursor;
    s->v[6] = w.sq;
    s->v[15] = sp0;
    s->v[VF3_REG_PR] = pr;
    s->v[VF3_REG_MACL] = macl;
    s->v[VF3_REG_MACH] = mach;
    s->pc = pr;
    return 1;
}
