/* vertex_light.h - the lighting step shared by the per-vertex routine (0x8C048B00)
 * and the strip transformer that has it inlined (0x8C0487A0). */
#ifndef VF3_VERTEX_LIGHT_H
#define VF3_VERTEX_LIGHT_H

#include "fight/readable.h"

/* Vertex record layout, at `body`: position, normal, then two words passed through. */
typedef struct {
    uint32_t depth, y, z, w;     /* XMTRX * (x, y, z, 1), raw float bits */
    uint32_t w1, w2;             /* trailing words of the record (texture coordinates) */
    float intensity;             /* ambient + max(N.L, 0), or 1.0 when selector < 0 */
    float specular;              /* v^k term, 0 when there is none */
    float inv_depth;             /* 1 / depth */
} vf3_lit_vertex;

/* Transform and light the vertex whose body starts at `body`. Reads XMTRX, FV12 (diffuse
 * direction, ambient in FR15), FV8 (specular direction) and FPSCR from `s`, writes nothing
 * to it. Returns 0 when the FPU mode or the specular selector is outside what the engine
 * ever uses.
 * The strip transformers load the normal's first component through a 0.0 + n0 addition
 * (it rides along in a register pair); `via_adder` reproduces that (it turns -0 into +0
 * and flushes denormals as the FPSCR says). */
int vf3_light_vertex(const vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t body,
                     int32_t selector, int via_adder, vf3_lit_vertex *out);

/* Records are either 32 bytes inline (word0 bit 0 set) or an 8-byte head that points
 * at the body: body = record + 8 + head.offset. Returns the body address, and
 * the address of the record after this one through `next`. */
uint32_t vf3_vertex_locate(const vf3_ram_map *ram, uint32_t record, uint32_t *next);

#endif
