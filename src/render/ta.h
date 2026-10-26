/* render/ta.h - the Tile Accelerator's command stream decoder.
 *
 * The PVR2's Tile Accelerator (TA) is fed a stream of 32-bit words: the
 * display list the game builds in the store queue.  The stream is a sequence
 * of 32-byte blocks; the first word of a block is its **parameter control
 * word** (PCW), whose top three bits say what the block is:
 *
 *   000  end of list
 *   001  user tile clip (a rectangle in tile units)
 *   010  object list set
 *   100  polygon or modifier volume (the primitive's parameter block)
 *   101  sprite (the primitive's parameter block)
 *   111  vertex parameter (one vertex of the primitive that is being built)
 *
 * The PCW's low seven bits are the *object control*: they say whether the
 * primitive is textured, how its colour is given, whether it has two volumes
 * and whether its texture coordinates are 16 bit.  Those bits select both the
 * size of the parameter block (32 or 64 bytes) and the layout of the vertices
 * that follow.
 *
 * This is our own decoder: it reads the hardware's format and hands the
 * primitives to the rasteriser (src/render/pvr2.c).
 */
#ifndef VF3_TA_H
#define VF3_TA_H

#include <stdint.h>

/* The parameter types (the PCW's top three bits). */
enum {
    VF3_TA_END_OF_LIST = 0,
    VF3_TA_USER_CLIP = 1,
    VF3_TA_OBJECT_LIST = 2,
    VF3_TA_POLYGON = 4,
    VF3_TA_SPRITE = 5,
    VF3_TA_VERTEX = 7
};

/* The list types (the PCW's bits 24-26). */
enum {
    VF3_TA_LIST_OPAQUE = 0,
    VF3_TA_LIST_OPAQUE_MODVOL = 1,
    VF3_TA_LIST_TRANSLUCENT = 2,
    VF3_TA_LIST_TRANSLUCENT_MODVOL = 3,
    VF3_TA_LIST_PUNCH_THROUGH = 4
};

/* The vertex layouts the object control selects. */
enum {
    VF3_TA_V_PLAIN_PACKED = 0,   /* xyz, packed colour */
    VF3_TA_V_PLAIN_FLOAT = 1,    /* xyz, four float colour components */
    VF3_TA_V_PLAIN_INTENSITY = 2,/* xyz, one float intensity */
    VF3_TA_V_TEXT_PACKED = 3,    /* xyz, uv, packed colour */
    VF3_TA_V_TEXT_PACKED_16 = 4, /* xyz, 16 bit uv, packed colour */
    VF3_TA_V_TEXT_FLOAT = 5,     /* xyz, uv, float colour (64 bit) */
    VF3_TA_V_TEXT_FLOAT_16 = 6,  /* xyz, 16 bit uv, float colour (64 bit) */
    VF3_TA_V_TEXT_INTENSITY = 7, /* xyz, uv, intensity */
    VF3_TA_V_TEXT_INTENSITY_16 = 8,
    VF3_TA_V_PLAIN_PACKED_2VOL = 9,
    VF3_TA_V_PLAIN_INTENSITY_2VOL = 10,
    VF3_TA_V_TEXT_PACKED_2VOL = 11,
    VF3_TA_V_TEXT_PACKED_2VOL_16 = 12,
    VF3_TA_V_TEXT_INTENSITY_2VOL = 13,
    VF3_TA_V_TEXT_INTENSITY_2VOL_16 = 14
};

#define VF3_TA_MAX_VERTS 4

typedef struct {
    float x, y;          /* the screen position, in the TA's own units */
    float z;             /* 1/w: the reciprocal the TA divides by */
    float u, v;          /* the texture coordinates */
    uint32_t colour;     /* 0xAARRGGBB (the packed colour layouts) */
    uint32_t offset_colour;
    float intensity;     /* the intensity layouts */
    float offset_intensity;
} vf3_ta_vertex;

/* The primitive's parameter block: the words after the PCW. */
typedef struct {
    uint32_t pcw;        /* the parameter control word */
    uint32_t isp_tsp;    /* the ISP/TSP instruction word */
    uint32_t tsp;        /* the TSP instruction word */
    uint32_t tcw;        /* the texture control word */
    uint32_t base_colour;
    uint32_t offset_colour;
    float face[4];       /* the face colour (the intensity layouts) */
    unsigned vertex_type;/* the vertex layout the object control selected */
    unsigned param_words;/* the size of the parameter block, in words */
} vf3_ta_param;

typedef struct {
    int is_sprite;       /* 0: a polygon, 1: a sprite */
    unsigned list_type;  /* the list the primitive belongs to */
    vf3_ta_param param;
    unsigned count;      /* the number of vertices */
    vf3_ta_vertex verts[VF3_TA_MAX_VERTS];
} vf3_ta_prim;

typedef struct {
    vf3_ta_prim *prims;
    unsigned count;
    unsigned capacity;
    unsigned words;      /* the words the decoder consumed */
    unsigned blocks;     /* the 32-byte blocks the decoder consumed */
    int error;           /* 1: the stream did not parse */
} vf3_ta_list;

/* Decode a TA command stream.  Returns 0 on success. */
int vf3_ta_decode(const uint32_t *words, unsigned count, vf3_ta_list *out);
/* Release the list's memory. */
void vf3_ta_free(vf3_ta_list *list);

/* The PCW's fields. */
static inline unsigned vf3_ta_paratype(uint32_t pcw) { return (pcw >> 29) & 7u; }
static inline unsigned vf3_ta_listtype(uint32_t pcw) { return (pcw >> 24) & 7u; }
static inline unsigned vf3_ta_objctrl(uint32_t pcw) { return pcw & 0x7Fu; }
static inline int vf3_ta_uv16(uint32_t pcw) { return pcw & 1u; }
static inline int vf3_ta_offset(uint32_t pcw) { return (pcw >> 2) & 1u; }
static inline int vf3_ta_texture(uint32_t pcw) { return (pcw >> 3) & 1u; }
static inline unsigned vf3_ta_coltype(uint32_t pcw) { return (pcw >> 4) & 3u; }
static inline int vf3_ta_volume(uint32_t pcw) { return (pcw >> 6) & 1u; }
static inline unsigned vf3_ta_userclip(uint32_t pcw) { return (pcw >> 16) & 3u; }
static inline int vf3_ta_endofstrip(uint32_t pcw) { return (pcw >> 28) & 1u; }

/* The vertex layout the object control selects, and whether the parameter
 * block is 64 bytes. */
unsigned vf3_ta_vertex_type(uint32_t pcw);
int vf3_ta_param_is_64(uint32_t pcw);

#endif
