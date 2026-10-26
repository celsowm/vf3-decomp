/* render/ta.c - the Tile Accelerator's command stream decoder.
 *
 * The walk follows the hardware's state machine:
 *
 *   - a polygon parameter block (32 or 64 bytes) opens a polygon list; the
 *     object control says how big its vertices are;
 *   - a sprite parameter block (32 bytes) is followed by 64 bytes of vertex
 *     data;
 *   - the vertices arrive as vertex parameter blocks, one per vertex, and the
 *     list ends with an end-of-list block.
 *
 * The vertex layouts are the ones the Dreamcast's TA documents: the position
 * is three 32-bit floats (the third is 1/w), the texture coordinates are two
 * floats or two 16-bit halves, and the colour is either packed 0xAARRGGBB or
 * four floats or a pair of intensities.
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

/* A 16-bit half-precision float, as the 16 bit texture coordinates are. */
static float half(uint16_t h)
{
    const unsigned sign = (h >> 15) & 1u;
    const unsigned exp = (h >> 10) & 0x1Fu;
    const unsigned frac = h & 0x3FFu;
    float v;
    if (exp == 0) v = (float)frac / 1024.0f / 16384.0f;
    else if (exp == 31) v = frac ? 0.0f : 0.0f;
    else v = (float)(frac + 1024u) / 1024.0f * (float)(1u << (exp - 15));
    return sign ? -v : v;
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
    list->prims = NULL;
    list->count = list->capacity = 0;
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

/* Decode one vertex from its words into a vertex.
 *
 * `w` points at the first word of the vertex (the position), and `words` is
 * how many words the vertex occupies. */
static void decode_vertex(unsigned vtype, const uint32_t *w, vf3_ta_vertex *v)
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
        v->colour = 0xFF000000u | (f32bits(w[4]) & 0x00FFFFFFu);
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
        v->v = half((uint16_t)w[3]);
        v->u = half((uint16_t)(w[3] >> 16));
        v->colour = w[5];
        v->offset_colour = w[6];
        break;
    case VF3_TA_V_TEXT_FLOAT:
        v->u = f32(w[3]);
        v->v = f32(w[4]);
        v->colour = 0xFF000000u | (f32bits(w[7 + 0]) & 0x00FFFFFFu);
        break;
    case VF3_TA_V_TEXT_FLOAT_16:
        v->v = half((uint16_t)w[3]);
        v->u = half((uint16_t)(w[3] >> 16));
        v->colour = 0xFF000000u | (f32bits(w[7 + 0]) & 0x00FFFFFFu);
        break;
    case VF3_TA_V_TEXT_INTENSITY:
        v->u = f32(w[3]);
        v->v = f32(w[4]);
        v->intensity = f32(w[5]);
        v->offset_intensity = f32(w[6]);
        break;
    case VF3_TA_V_TEXT_INTENSITY_16:
        v->v = half((uint16_t)w[3]);
        v->u = half((uint16_t)(w[3] >> 16));
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
        v->v = half((uint16_t)w[3]);
        v->u = half((uint16_t)(w[3] >> 16));
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
        v->v = half((uint16_t)w[3]);
        v->u = half((uint16_t)(w[3] >> 16));
        v->intensity = f32(w[5]);
        v->offset_intensity = f32(w[6]);
        break;
    default:
        break;
    }
}

/* The sprite's vertex data: four corners of a plane.
 *
 * The first block carries the PCW and the first seven floats; the second
 * block carries the rest.  The texture coordinates are three pairs of 16-bit
 * halves at the end. */
static void decode_sprite(const uint32_t *w, vf3_ta_vertex *v)
{
    /* w points at the sprite's data (the block after the PCW). */
    v[0].x = f32(w[0]); v[0].y = f32(w[1]); v[0].z = f32(w[2]);
    v[1].x = f32(w[3]); v[1].y = f32(w[4]); v[1].z = f32(w[5]);
    v[2].x = f32(w[6]); v[2].y = f32(w[7]); v[2].z = f32(w[8]);
    v[3].x = f32(w[9]); v[3].y = f32(w[10]);
    /* the texture coordinates: v0,u0 v1,u1 v2,u2, as 16-bit halves */
    v[0].v = half((uint16_t)w[13]); v[0].u = half((uint16_t)(w[13] >> 16));
    v[1].v = half((uint16_t)w[14]); v[1].u = half((uint16_t)(w[14] >> 16));
    v[2].v = half((uint16_t)w[15]); v[2].u = half((uint16_t)(w[15] >> 16));
}

int vf3_ta_decode(const uint32_t *words, unsigned count, vf3_ta_list *out)
{
    unsigned i = 0;
    int in_list = 0;          /* a polygon list is being built */
    unsigned list_vtype = 0;  /* its vertex layout */
    vf3_ta_prim *cur = NULL;  /* the primitive being built */

    memset(out, 0, sizeof *out);
    while (i + 8 <= count) {
        const uint32_t pcw = words[i];
        const unsigned pt = vf3_ta_paratype(pcw);
        out->blocks++;
        i += 8;
        switch (pt) {
        case VF3_TA_END_OF_LIST:
            out->words = i;
            return 0;
        case VF3_TA_USER_CLIP:
        case VF3_TA_OBJECT_LIST:
            break;
        case VF3_TA_POLYGON: {
            const unsigned vtype = vf3_ta_vertex_type(pcw);
            const int is64 = vf3_ta_param_is_64(pcw);
            if (vtype == 0xFFu) { out->error = 1; out->words = i; return -1; }
            cur = push_prim(out);
            if (!cur) { out->error = 1; out->words = i; return -1; }
            cur->is_sprite = 0;
            cur->list_type = vf3_ta_listtype(pcw);
            cur->param.pcw = pcw;
            cur->param.vertex_type = vtype;
            cur->param.param_words = is64 ? 16u : 8u;
            cur->param.isp_tsp = words[i + 1];
            cur->param.tsp = words[i + 2];
            cur->param.tcw = words[i + 3];
            cur->param.base_colour = words[i + 4];
            cur->param.offset_colour = words[i + 5];
            if (is64) {
                cur->param.face[0] = f32(words[i + 8]);
                cur->param.face[1] = f32(words[i + 9]);
                cur->param.face[2] = f32(words[i + 10]);
                cur->param.face[3] = f32(words[i + 11]);
                i += 8;      /* the second half of the parameter block */
            }
            list_vtype = vtype;
            in_list = 1;
            break;
        }
        case VF3_TA_SPRITE: {
            cur = push_prim(out);
            if (!cur) { out->error = 1; out->words = i; return -1; }
            cur->is_sprite = 1;
            cur->list_type = vf3_ta_listtype(pcw);
            cur->param.pcw = pcw;
            cur->param.vertex_type = 0xFFu;
            cur->param.param_words = 8u;
            cur->param.isp_tsp = words[i + 1];
            cur->param.tsp = words[i + 2];
            cur->param.tcw = words[i + 3];
            cur->param.base_colour = words[i + 4];
            cur->param.offset_colour = words[i + 5];
            /* the sprite's vertex data: 64 bytes, two blocks */
            if (i + 16 <= count) {
                decode_sprite(words + i + 1, cur->verts);
                cur->count = 4;
                i += 8;      /* the second block of the sprite's data */
            } else {
                out->error = 1;
                out->words = i;
                return -1;
            }
            cur = NULL;
            break;
        }
        case VF3_TA_VERTEX: {
            if (!cur || !in_list) break;    /* a vertex without a primitive */
            if (cur->is_sprite) break;       /* the sprite's data is inline */
            if (cur->count >= VF3_TA_MAX_VERTS) break;
            decode_vertex(list_vtype, words + i + 1, &cur->verts[cur->count]);
            cur->count++;
            /* the 64-bit vertex layouts have a second half */
            if (list_vtype == VF3_TA_V_TEXT_FLOAT || list_vtype == VF3_TA_V_TEXT_FLOAT_16 ||
                list_vtype == VF3_TA_V_TEXT_PACKED_2VOL || list_vtype == VF3_TA_V_TEXT_PACKED_2VOL_16 ||
                list_vtype == VF3_TA_V_TEXT_INTENSITY_2VOL || list_vtype == VF3_TA_V_TEXT_INTENSITY_2VOL_16) {
                if (i + 16 <= count) i += 8;
            }
            break;
        }
        default:
            out->error = 1;
            out->words = i;
            return -1;
        }
    }
    out->words = i;
    return out->error ? -1 : 0;
}
