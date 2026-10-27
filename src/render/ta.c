/* render/ta.c - the Tile Accelerator's command stream decoder.
 *
 * The TA consumes its input as a sequence of **32-byte blocks**, in the order
 * they arrive.  Every block starts with a parameter control word (PCW) whose
 * top three bits say what the block is, and the block's size follows from it:
 *
 *   end of list        1 block, ends the list that is being built
 *   user tile clip     1 block (a rectangle in tile units)
 *   object list set    1 block
 *   polygon            1 or 2 blocks (the primitive's parameter block)
 *   sprite             1 block (the parameter) + 2 blocks (the four corners)
 *   vertex parameter   1 or 2 blocks (one vertex), the size follows from the
 *                      layout the polygon's object control selected
 *
 * The end of a list does not end the stream: the hardware raises the list's
 * end interrupt and the next block starts the next list.  A decoder that stops
 * at the first end-of-list block therefore sees nothing at all - the game's
 * first blocks of a frame are the tail of the previous frame's list.
 *
 * The vertex layouts are the ones the Dreamcast's TA documents: the position
 * is three 32-bit floats (the third is 1/w), the texture coordinates are two
 * floats or two 16-bit TA floats, and the colour is either packed 0xAARRGGBB,
 * four floats, or a pair of intensities.
 */
#include "render/ta.h"

#include <stdlib.h>
#include <string.h>

/* The vertex layout the object control selects.
 *
 *   bit 3      textured
 *   bit 6      two volumes
 *   bits 4-5   the colour: 0 packed, 1 float, 2 intensity
 *   bit 0      the texture coordinates are 16 bit
 */
unsigned vf3_ta_vertex_type(uint32_t pcw)
{
    const int textured = vf3_ta_texture(pcw);
    const int two = vf3_ta_volume(pcw);
    const unsigned col = vf3_ta_coltype(pcw);
    const int uv16 = vf3_ta_uv16(pcw);

    if (textured) {
        if (!two) {
            if (col == 0) return uv16 ? VF3_TA_V_TEXT_PACKED_16 : VF3_TA_V_TEXT_PACKED;
            if (col == 1) return uv16 ? VF3_TA_V_TEXT_FLOAT_16 : VF3_TA_V_TEXT_FLOAT;
            return uv16 ? VF3_TA_V_TEXT_INTENSITY_16 : VF3_TA_V_TEXT_INTENSITY;
        }
        if (col == 0) return uv16 ? VF3_TA_V_TEXT_PACKED_2VOL_16 : VF3_TA_V_TEXT_PACKED_2VOL;
        if (col == 2) return uv16 ? VF3_TA_V_TEXT_INTENSITY_2VOL_16 : VF3_TA_V_TEXT_INTENSITY_2VOL;
        return 0xFFu;   /* two volumes with float colour: the hardware has none */
    }
    if (!two) {
        if (col == 0) return VF3_TA_V_PLAIN_PACKED;
        if (col == 1) return VF3_TA_V_PLAIN_FLOAT;
        return VF3_TA_V_PLAIN_INTENSITY;
    }
    if (col == 0) return VF3_TA_V_PLAIN_PACKED_2VOL;
    if (col == 2) return VF3_TA_V_PLAIN_INTENSITY_2VOL;
    return 0xFFu;
}

/* Whether the primitive's parameter block is 64 bytes.
 *
 *   one volume, packed or float colour: 32 bytes;
 *   one volume, intensity colour: 64 bytes when the primitive is textured
 *     and uses the offset colour, else 32;
 *   two volumes, packed colour: 32 bytes;
 *   two volumes, intensity colour: 64 bytes.
 */
int vf3_ta_param_is_64(uint32_t pcw)
{
    const unsigned col = vf3_ta_coltype(pcw);
    if (!vf3_ta_volume(pcw)) {
        if (col < 2) return 0;
        if (col == 2) return vf3_ta_texture(pcw) && vf3_ta_offset(pcw);
        return 0;
    }
    if (col == 0) return 0;
    if (col == 2) return 1;
    return 0;
}

/* Which of the five parameter blocks the object control selects.
 *
 * The words after the texture control word hold the face colour (the
 * intensity layouts) or the second volume's texture words; the packed colour
 * is in the vertices, so the parameter block has nothing there. */
unsigned vf3_ta_param_type(uint32_t pcw)
{
    const unsigned col = vf3_ta_coltype(pcw);
    if (!vf3_ta_volume(pcw)) {
        if (col < 2) return VF3_TA_PARAM_PACKED;
        if (col == 2) {
            if (vf3_ta_texture(pcw) && vf3_ta_offset(pcw))
                return VF3_TA_PARAM_FACE_OFFSET;
            return VF3_TA_PARAM_FACE;
        }
        return VF3_TA_PARAM_PACKED;
    }
    if (col == 0) return VF3_TA_PARAM_TWO_VOL_PACKED;
    if (col == 2) return VF3_TA_PARAM_TWO_VOL_FACE;
    return VF3_TA_PARAM_PACKED;
}

/* Whether a vertex of this layout takes 64 bytes (two blocks).
 *
 * The layouts that carry a float colour or a second volume do; the others
 * fit in the 28 bytes that follow the control word. */
int vf3_ta_vertex_is_64(unsigned vtype)
{
    switch (vtype) {
    case VF3_TA_V_TEXT_FLOAT:
    case VF3_TA_V_TEXT_FLOAT_16:
    case VF3_TA_V_TEXT_PACKED_2VOL:
    case VF3_TA_V_TEXT_PACKED_2VOL_16:
    case VF3_TA_V_TEXT_INTENSITY_2VOL:
    case VF3_TA_V_TEXT_INTENSITY_2VOL_16:
        return 1;
    default:
        return 0;
    }
}

/* The TA's 16-bit float: the high half of a 32-bit float, not the IEEE half
 * format.  The hardware keeps the sign, the exponent and seven mantissa bits
 * and drops the rest, so the value is the float32 with its low 16 bits
 * cleared. */
static float ta_f16(uint16_t h)
{
    const uint32_t bits = (uint32_t)h << 16;
    float f;
    memcpy(&f, &bits, 4);
    return f;
}

static float f32(uint32_t u)
{
    float f;
    memcpy(&f, &u, 4);
    return f;
}

static uint32_t f32bits(float f)
{
    uint32_t u;
    memcpy(&u, &f, 4);
    return u;
}

void vf3_ta_free(vf3_ta_list *list)
{
    free(list->prims);
    free(list->verts);
    list->prims = NULL;
    list->verts = NULL;
    list->count = list->capacity = 0;
    list->vcount = list->vcapacity = 0;
}

static vf3_ta_prim *push_prim(vf3_ta_list *list)
{
    if (list->count == list->capacity) {
        unsigned cap = list->capacity ? 2 * list->capacity : 256;
        vf3_ta_prim *p = realloc(list->prims, (size_t)cap * sizeof *p);
        if (!p) return NULL;
        list->prims = p;
        list->capacity = cap;
    }
    memset(&list->prims[list->count], 0, sizeof list->prims[list->count]);
    return &list->prims[list->count++];
}

/* Reserve one vertex in the list's arena and return its index. */
static unsigned push_vertex(vf3_ta_list *list)
{
    if (list->vcount == list->vcapacity) {
        unsigned cap = list->vcapacity ? 2 * list->vcapacity : 1024;
        vf3_ta_vertex *v = realloc(list->verts, (size_t)cap * sizeof *v);
        if (!v) { list->vcapacity = list->vcount = 0; return 0; }
        list->verts = v;
        list->vcapacity = cap;
    }
    return list->vcount++;
}

/* Decode one vertex from its words into a vertex.
 *
 * `w` points at the first word of the vertex (the position), and `words` is
 * how many words the vertex occupies.  The 64-byte layouts carry their colour
 * in the second block, which follows the first one in the stream. */
static void decode_vertex(unsigned vtype, const uint32_t *w, int have_next, vf3_ta_vertex *v)
{
    memset(v, 0, sizeof *v);
    v->x = f32(w[0]);
    v->y = f32(w[1]);
    v->z = f32(w[2]);
    switch (vtype) {
    case VF3_TA_V_PLAIN_PACKED:
        v->colour = w[5];
        break;
    case VF3_TA_V_PLAIN_FLOAT:
        /* the colour's four floats follow the position in the same block:
         * alpha, red, green, blue */
        v->colour = 0xFF000000u | ((uint32_t)(f32(w[4]) * 255.0f) << 16) |
                                ((uint32_t)(f32(w[5]) * 255.0f) << 8) |
                                 (uint32_t)(f32(w[6]) * 255.0f);
        v->offset_colour = 0xFF000000u;
        break;
    case VF3_TA_V_PLAIN_INTENSITY:
        v->intensity = f32(w[5]);
        break;
    case VF3_TA_V_TEXT_PACKED:
        v->u = f32(w[3]);
        v->v = f32(w[4]);
        v->colour = w[5];
        v->offset_colour = w[6];
        break;
    case VF3_TA_V_TEXT_PACKED_16:
        v->v = ta_f16((uint16_t)w[3]);
        v->u = ta_f16((uint16_t)(w[3] >> 16));
        v->colour = w[5];
        v->offset_colour = w[6];
        break;
    case VF3_TA_V_TEXT_FLOAT:
        v->u = f32(w[3]);
        v->v = f32(w[4]);
        if (have_next) {
            /* the second block: the base colour's alpha, red, green, blue */
            v->colour = 0xFF000000u | ((uint32_t)(f32(w[8]) * 255.0f) << 16) |
                                    ((uint32_t)(f32(w[9]) * 255.0f) << 8) |
                                     (uint32_t)(f32(w[10]) * 255.0f);
            v->offset_colour = 0xFF000000u | ((uint32_t)(f32(w[12]) * 255.0f) << 16) |
                                          ((uint32_t)(f32(w[13]) * 255.0f) << 8) |
                                           (uint32_t)(f32(w[14]) * 255.0f);
        }
        break;
    case VF3_TA_V_TEXT_FLOAT_16:
        v->v = ta_f16((uint16_t)w[3]);
        v->u = ta_f16((uint16_t)(w[3] >> 16));
        if (have_next) {
            v->colour = 0xFF000000u | ((uint32_t)(f32(w[8]) * 255.0f) << 16) |
                                    ((uint32_t)(f32(w[9]) * 255.0f) << 8) |
                                     (uint32_t)(f32(w[10]) * 255.0f);
            v->offset_colour = 0xFF000000u | ((uint32_t)(f32(w[12]) * 255.0f) << 16) |
                                          ((uint32_t)(f32(w[13]) * 255.0f) << 8) |
                                           (uint32_t)(f32(w[14]) * 255.0f);
        }
        break;
    case VF3_TA_V_TEXT_INTENSITY:
        v->u = f32(w[3]);
        v->v = f32(w[4]);
        v->intensity = f32(w[5]);
        v->offset_intensity = f32(w[6]);
        break;
    case VF3_TA_V_TEXT_INTENSITY_16:
        v->v = ta_f16((uint16_t)w[3]);
        v->u = ta_f16((uint16_t)(w[3] >> 16));
        v->intensity = f32(w[5]);
        v->offset_intensity = f32(w[6]);
        break;
    case VF3_TA_V_PLAIN_PACKED_2VOL:
        v->colour = w[3];
        v->offset_colour = w[4];
        break;
    case VF3_TA_V_PLAIN_INTENSITY_2VOL:
        v->intensity = f32(w[3]);
        v->offset_intensity = f32(w[4]);
        break;
    case VF3_TA_V_TEXT_PACKED_2VOL:
        v->u = f32(w[3]);
        v->v = f32(w[4]);
        v->colour = w[5];
        v->offset_colour = w[6];
        break;
    case VF3_TA_V_TEXT_PACKED_2VOL_16:
        v->v = ta_f16((uint16_t)w[3]);
        v->u = ta_f16((uint16_t)(w[3] >> 16));
        v->colour = w[5];
        v->offset_colour = w[6];
        break;
    case VF3_TA_V_TEXT_INTENSITY_2VOL:
        v->u = f32(w[3]);
        v->v = f32(w[4]);
        v->intensity = f32(w[5]);
        v->offset_intensity = f32(w[6]);
        break;
    case VF3_TA_V_TEXT_INTENSITY_2VOL_16:
        v->v = ta_f16((uint16_t)w[3]);
        v->u = ta_f16((uint16_t)(w[3] >> 16));
        v->intensity = f32(w[5]);
        v->offset_intensity = f32(w[6]);
        break;
    default:
        break;
    }
}

/* The sprite's vertex data: the four corners of a plane.
 *
 * The first block carries the control word and the first seven floats
 * (x0,y0,z0 x1,y1,z1 x2); the second carries y2, z2, x3, y3, a padding word
 * and the three texture coordinate pairs (v,u), each a pair of 16-bit TA
 * floats. */
static void decode_sprite(const uint32_t *w, vf3_ta_vertex *v)
{
    v[0].x = f32(w[0]); v[0].y = f32(w[1]); v[0].z = f32(w[2]);
    v[1].x = f32(w[3]); v[1].y = f32(w[4]); v[1].z = f32(w[5]);
    v[2].x = f32(w[6]); v[2].y = f32(w[7]); v[2].z = f32(w[8]);
    v[3].x = f32(w[9]); v[3].y = f32(w[10]);
    /* the texture coordinates: (v0,u0), (v1,u1), (v2,u2) */
    v[0].v = ta_f16((uint16_t)w[12]); v[0].u = ta_f16((uint16_t)(w[12] >> 16));
    v[1].v = ta_f16((uint16_t)w[13]); v[1].u = ta_f16((uint16_t)(w[13] >> 16));
    v[2].v = ta_f16((uint16_t)w[14]); v[2].u = ta_f16((uint16_t)(w[14] >> 16));
}

/* The modifier volume's vertex: the same four corners, no texture
 * coordinates. */
static void decode_modvol(const uint32_t *w, vf3_ta_vertex *v)
{
    v[0].x = f32(w[0]); v[0].y = f32(w[1]); v[0].z = f32(w[2]);
    v[1].x = f32(w[3]); v[1].y = f32(w[4]); v[1].z = f32(w[5]);
    v[2].x = f32(w[6]); v[2].y = f32(w[7]); v[2].z = f32(w[8]);
    v[3].x = f32(w[9]); v[3].y = f32(w[10]);
}

int vf3_ta_decode(const uint32_t *words, unsigned count, vf3_ta_list *out)
{
    unsigned i = 0;
    unsigned list_type = VF3_TA_LIST_NONE;  /* the list being built */
    vf3_ta_prim *cur = NULL;                /* the primitive being built */
    unsigned cur_vtype = 0;                 /* its vertex layout */

    memset(out, 0, sizeof *out);
    while (i + 8 <= count) {
        const uint32_t *blk = words + i;
        const uint32_t pcw = blk[0];
        const unsigned pt = vf3_ta_paratype(pcw);
        out->blocks++;

        switch (pt) {
        case VF3_TA_END_OF_LIST:
            /* The list ends here; the next block starts the next one. */
            if (list_type != VF3_TA_LIST_NONE) {
                out->lists++;
                list_type = VF3_TA_LIST_NONE;
            }
            cur = NULL;
            i += 8;
            break;
        case VF3_TA_USER_CLIP:
        case VF3_TA_OBJECT_LIST:
            i += 8;
            break;
        case VF3_TA_POLYGON: {
            const unsigned vtype = vf3_ta_vertex_type(pcw);
            const int p64 = vf3_ta_param_is_64(pcw);
            if (vtype == 0xFFu) {
                /* the hardware has no such type: it skips the block */
                out->invalid++;
                i += 8;
                break;
            }
            if (list_type == VF3_TA_LIST_NONE) {
                list_type = vf3_ta_listtype(pcw);
                if (list_type > VF3_TA_LIST_PUNCH_THROUGH) {
                    list_type = VF3_TA_LIST_NONE;
                    out->invalid++;
                    i += 8;
                    break;
                }
            }
            cur = push_prim(out);
            if (!cur) { out->error = 1; out->words = i; return -1; }
            cur->is_sprite = 0;
            cur->is_modvol = vf3_ta_list_is_modvol(list_type);
            cur->list_type = list_type;
            cur->param.pcw = pcw;
            cur->param.vertex_type = vtype;
            cur->param.param_words = p64 ? 16u : 8u;
            cur->param.param_type = vf3_ta_param_type(pcw);
            cur->param.isp_tsp = blk[1];
            cur->param.tsp = blk[2];
            cur->param.tcw = blk[3];
            cur->param.base_colour = blk[4];
            cur->param.offset_colour = blk[5];
            cur_vtype = vtype;
            cur->vstart = out->vcount;
            if (p64) {
                /* the parameter block's second half: the face colours */
                if (i + 16 > count) { out->error = 1; out->words = i; return -1; }
                for (unsigned k = 0; k < 8; ++k) cur->param.face[k] = f32(words[i + 8 + k]);
                i += 16;
            } else {
                if (cur->param.param_type == VF3_TA_PARAM_FACE) {
                    /* the face colour: alpha, red, green, blue */
                    for (unsigned k = 0; k < 4; ++k) cur->param.face[k] = f32(blk[4 + k]);
                }
                i += 8;
            }
            break;
        }
        case VF3_TA_SPRITE: {
            if (list_type == VF3_TA_LIST_NONE) {
                list_type = vf3_ta_listtype(pcw);
                if (list_type > VF3_TA_LIST_PUNCH_THROUGH) {
                    list_type = VF3_TA_LIST_NONE;
                    out->invalid++;
                    i += 8;
                    break;
                }
            }
            cur = push_prim(out);
            if (!cur) { out->error = 1; out->words = i; return -1; }
            cur->is_sprite = 1;
            cur->is_modvol = 0;
            cur->list_type = list_type;
            cur->param.pcw = pcw;
            cur->param.vertex_type = 0xFFu;
            cur->param.param_words = 8u;
            cur->param.param_type = VF3_TA_PARAM_PACKED;
            cur->param.isp_tsp = blk[1];
            cur->param.tsp = blk[2];
            cur->param.tcw = blk[3];
            cur->param.base_colour = blk[4];
            cur->param.offset_colour = blk[5];
            cur_vtype = 0xFFu;
            cur->vstart = out->vcount;
            i += 8;
            break;
        }
        case VF3_TA_VERTEX: {
            if (!cur) {                   /* a vertex without a primitive */
                out->invalid++;
                i += 8;
                break;
            }
            if (cur->is_sprite) {
                /* the sprite's vertex data: 60 bytes after the control word,
                 * which is the rest of this block plus the next one */
                if (i + 16 > count) { out->error = 1; out->words = i; return -1; }
                if (out->vcount + 4 > out->vcapacity) {
                    unsigned need = out->vcount + 4;
                    unsigned cap = out->vcapacity ? out->vcapacity : 1024;
                    while (cap < need) cap *= 2;
                    vf3_ta_vertex *v = realloc(out->verts, (size_t)cap * sizeof *v);
                    if (!v) { out->error = 1; out->words = i; return -1; }
                    out->verts = v;
                    out->vcapacity = cap;
                }
                decode_sprite(blk + 1, &out->verts[out->vcount]);
                /* A sprite has no colour of its own: the hardware gives every
                 * corner the face colour from the sprite's parameter block. */
                for (unsigned k = 0; k < 4; ++k) {
                    out->verts[out->vcount + k].colour = cur->param.base_colour;
                    out->verts[out->vcount + k].offset_colour = cur->param.offset_colour;
                }
                out->vcount += 4;
                cur->count = 4;
                i += 16;
                break;
            }
            if (cur->is_modvol) {
                if (i + 16 > count) { out->error = 1; out->words = i; return -1; }
                /* the modifier volume's vertex carries the four corners of
                 * the volume, so it takes four slots in the arena */
                if (out->vcount + 4 > out->vcapacity) {
                    unsigned need = out->vcount + 4;
                    unsigned cap = out->vcapacity ? out->vcapacity : 1024;
                    while (cap < need) cap *= 2;
                    vf3_ta_vertex *v = realloc(out->verts, (size_t)cap * sizeof *v);
                    if (!v) { out->error = 1; out->words = i; return -1; }
                    out->verts = v;
                    out->vcapacity = cap;
                }
                decode_modvol(blk + 1, &out->verts[out->vcount]);
                out->vcount += 4;
                cur->count++;
                i += 16;
                break;
            }
            {
                const int wide = vf3_ta_vertex_is_64(cur_vtype);
                const unsigned need = wide ? 16u : 8u;
                if (i + need > count) { out->error = 1; out->words = i; return -1; }
                {
                    const unsigned idx = push_vertex(out);
                    decode_vertex(cur_vtype, blk + 1, wide, &out->verts[idx]);
                    /* the vertex's own control word says where the strip ends:
                     * the TA's polygons are triangle strips */
                    out->verts[idx].end_strip = (uint8_t)((pcw >> 28) & 1u);
                    if (out->verts[idx].end_strip) ++cur->strips;
                }
                cur->count++;
                i += need;
            }
            break;
        }
        default:
            /* the hardware has no state for this parameter type */
            out->invalid++;
            i += 8;
            break;
        }
    }
    out->words = i;
    return out->error ? -1 : 0;
}
