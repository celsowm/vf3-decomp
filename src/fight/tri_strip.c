/* tri_strip.c - screen-space triangle strips: cull, wind and submit, SH-4 0x8C0568A0.
 *
 *   r4 = strip block, r13 = vertex table (16 bytes per vertex: x y z w, already transformed),
 *   r10 = z limit (bits, unsigned compare), r12 = store-queue cursor, bank-3 R3 = address that
 *   receives the final cursor.
 *
 * Block: { u32 ?; s16 strip count; strips... }, a strip being
 *   { s16 count; (s16 vertex, s16 u, s16 v) * |count| }
 * count < 0 flips the starting winding. Per triangle (v[n-2], v[n-1], v[n]):
 *   - each vertex gets an out-of-range bit (z bits >u limit: far, or negative) kept in a sliding
 *     3-bit window, and a "z >= 0" bit kept in r9; with the strip's winding bit r5 they decide the
 *     sign of the screen-space area  (x2-x0)(y2-y1) - (y2-y0)(x2-x1);
 *   - back-facing / degenerate triangles are dropped, a triangle with all three vertices out of
 *     range is dropped, one with only some out of range goes to the clipper 0x8C051F50
 *     (r4 = window bits), the rest is emitted;
 *   - emission is the three vertex writers of the table at 0x0C056A78 (0x0C056A84 when
 *     *0x0C055B8C is set): the first triangle writes v0, v1 and v2, later ones only the new vertex
 *     (and only while no earlier vertex of the strip was out of range - otherwise the strip is
 *     closed with an end-of-strip word and the clipper restarts it).
 * A strip that wrote anything is closed by an end-of-strip word (0xFFFFFFFF) in a fresh slot.
 *
 * The vertex writers address the (u, v) pair of "their" vertex relative to r8, which therefore
 * trails the stream by one vertex (6 bytes per vertex record). Result: r4 = stream end, the
 * cursor stored to *R3_bank. Saves r14 and PR. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"

enum {
    BASE_PTR = 0x0C16B8B8, ALT_WRITERS_FLAG = 0x0C055B8C,
    WRITERS = 0x0C056A78, WRITERS_ALT = 0x0C056A84, CLIPPER = 0x0C051F50,
    VERTEX_SHIFT = 4, VERTEX_STRIDE_IN_STREAM = 6, SLOT = 32,
    RET_WRITER0 = 0x0C0569A8, RET_WRITER1 = 0x0C0569B0, RET_WRITER2 = 0x0C0569B8,
    RET_WRITER2_LATER = 0x0C056A20, RET_CLIP_A = 0x0C056A2C, RET_CLIP_B = 0x0C056A3E
};

typedef struct {
    vf3_matrix_state *s;
    const vf3_ram_map *ram;
    uint32_t r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14;
    uint32_t writer[3];
} scan;

static int16_t stream_s16(const scan *c, uint32_t a) { return (int16_t)vf3_mem_u16(c->ram, a); }

/* Load vertex `index` into the register pair block starting at FR(first): (x y) and (z w).
 * Returns the z bits. */
static uint32_t load_vertex(scan *c, int32_t index, int first)
{
    const uint32_t v = c->r13 + ((uint32_t)index << VERTEX_SHIFT);
    for (int i = 0; i < 4; ++i) VF3_FR(c->s, first + i) = vf3_mem_u32(c->ram, v + 4u * (uint32_t)i);
    return vf3_mem_u32(c->ram, v + 8u);
}

static void shift_vertices_down(scan *c)      /* v0 <- v1 <- v2 (FR4..7, FR8..11, FR12..15) */
{
    for (int i = 0; i < 4; ++i) {
        VF3_FR(c->s, 4 + i) = VF3_FR(c->s, 8 + i);
        VF3_FR(c->s, 8 + i) = VF3_FR(c->s, 12 + i);
    }
}

/* Twice the signed screen area of (v0, v1, v2) with the winding bit applied; leaves the
 * intermediate values in FR0..FR2 as the original does. */
static float screen_area(scan *c)
{
    vf3_matrix_state *s = c->s;
    float x0 = vf3_fr_get(s, 4), y0 = vf3_fr_get(s, 5);
    float x1 = vf3_fr_get(s, 8), y1 = vf3_fr_get(s, 9);
    float x2 = vf3_fr_get(s, 12), y2 = vf3_fr_get(s, 13);
    float dy02 = vf3_f_sub(s, y2, y0), dx12 = vf3_f_sub(s, x2, x1);
    float a = vf3_f_sub(s, 0.0f, vf3_f_mul(s, dy02, dx12));
    float dy12 = vf3_f_sub(s, y2, y1), dx02 = vf3_f_sub(s, x2, x0);
    a = vf3_f_mac(s, dx02, dy12, a);
    if ((int32_t)c->r5 < 0) a = vf3_bits_f32(vf3_f32_bits(a) ^ 0x80000000u);
    vf3_fr_set(s, 0, 0.0f);
    vf3_fr_set(s, 1, dy12);
    vf3_fr_set(s, 2, a);
    return a;
}

static void to_state(const scan *c)
{
    vf3_matrix_state *s = c->s;
    s->v[0] = c->r0; s->v[1] = c->r1; s->v[2] = c->r2; s->v[4] = c->r4; s->v[5] = c->r5;
    s->v[6] = c->r6; s->v[7] = c->r7; s->v[8] = c->r8; s->v[9] = c->r9; s->v[10] = c->r10;
    s->v[11] = c->r11; s->v[12] = c->r12; s->v[13] = c->r13; s->v[14] = c->r14;
}

static void from_state(scan *c)
{
    const vf3_matrix_state *s = c->s;
    c->r4 = s->v[4]; c->r5 = s->v[5]; c->r6 = s->v[6]; c->r7 = s->v[7]; c->r8 = s->v[8];
    c->r9 = s->v[9]; c->r11 = s->v[11]; c->r12 = s->v[12]; c->r14 = s->v[14];
}

static int call(scan *c, uint32_t target, uint32_t ret)
{
    to_state(c);
    if (!vf3_guest_call(c->s, c->ram, target, ret)) return 0;
    from_state(c);
    return 1;
}

static int write_vertex(scan *c, int which)
{
    static const uint32_t ret[3] = { RET_WRITER0, RET_WRITER1, RET_WRITER2 };
    c->r1 = c->writer[which];
    return call(c, c->writer[which], ret[which]);
}

static void close_strip(scan *c)
{
    vf3_mem_set_u32(c->ram, c->r12, 0xFFFFFFFFu);
    vf3_matrix_pref(c->ram, c->r12);
    c->r12 += SLOT;
}

enum { RESTART, HEAD, LATER, STRIP_END, NEXT_STRIP, STRIP_TOP, FINISH };

int vf3_tri_strip_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (!s->bank_known || (s->v[VF3_REG_FPSCR] & 0x00100000u)) return 0;
    scan c = { .s = s, .ram = ram };
    const uint32_t sp0 = s->v[15], pr = s->v[VF3_REG_PR], saved_r14 = s->v[14];
    vf3_mem_set_u32(ram, sp0 - 4u, saved_r14);
    vf3_mem_set_u32(ram, sp0 - 8u, pr);
    s->v[15] = sp0 - 8u;
    c.r10 = s->v[10];
    c.r12 = s->v[12];
    c.r13 = s->v[13];
    c.r14 = s->v[4] + 4u;

    s->v[VF3_REG_MACL] = vf3_mem_u32(ram, BASE_PTR) + 4u;
    const uint32_t writers = vf3_mem_u32(ram, ALT_WRITERS_FLAG) ? WRITERS_ALT : WRITERS;
    s->v[VF3_REG_MACH] = writers;
    for (int i = 0; i < 3; ++i) c.writer[i] = vf3_mem_u32(ram, writers + 4u * (uint32_t)i);

    c.r11 = (uint32_t)(int32_t)stream_s16(&c, c.r14);
    c.r14 += 2;

    int state = STRIP_TOP;
    while (state != FINISH) {
        switch (state) {
        case STRIP_TOP: {
            c.r8 = c.r14;
            const int32_t first = stream_s16(&c, c.r14 + 2u);
            c.r14 += 8;
            int32_t count = stream_s16(&c, c.r8);
            c.r8 += 2;
            const uint32_t z = load_vertex(&c, first, 8);
            if (count >= 0) c.r5 = 0xFFFFFFFFu;
            else { c.r5 = 0; count = -count; }
            const int far0 = z > c.r10, front0 = (int32_t)z >= 0;
            c.r4 = far0;
            c.r9 = front0;
            if (front0) c.r5 = ~c.r5;
            const int32_t second = stream_s16(&c, c.r14);
            c.r7 = (uint32_t)count - 1u;
            if (c.r7 == 0) { state = NEXT_STRIP; break; }

            const uint32_t z1 = load_vertex(&c, second, 12);
            c.r14 += VERTEX_STRIDE_IN_STREAM;
            c.r4 = (c.r4 << 1) | (z1 > c.r10);
            c.r8 -= VERTEX_STRIDE_IN_STREAM;
            if ((int32_t)z1 >= 0) c.r5 = ~c.r5;
            c.r9 = (c.r9 << 1) | ((int32_t)z1 >= 0);
            state = RESTART;
            break;
        }
        case RESTART:
            c.r6 = 0;
            c.r0 = c.r4;
            state = HEAD;
            break;
        case HEAD: {                         /* take the next vertex of the strip */
            c.r7 -= 1;
            const int32_t next = stream_s16(&c, c.r14);
            if (c.r7 == 0) { state = NEXT_STRIP; break; }
            c.r2 = (c.r9 & 4u) ? 0u : 0xFFFFFFFFu;
            shift_vertices_down(&c);
            c.r1 = (uint32_t)next;
            const uint32_t z = load_vertex(&c, next, 12);
            c.r14 += VERTEX_STRIDE_IN_STREAM;
            c.r5 ^= c.r2;
            c.r0 = ((c.r0 << 1) | (z > c.r10)) & 7u;
            if ((int32_t)z >= 0) c.r5 = ~c.r5;
            c.r9 = (c.r9 << 1) | ((int32_t)z >= 0);
            c.r8 += VERTEX_STRIDE_IN_STREAM;
            if (c.r0 == 7) break;            /* all three beyond the limit */
            if (!(screen_area(&c) > 0.0f)) break;

            c.r6 = c.r12;
            if (c.r0 != 0) {                 /* partly out of range: the clipper takes it */
                c.r4 = c.r0;
                if (!call(&c, CLIPPER, RET_CLIP_A)) return 0;
                state = RESTART;
                break;
            }
            c.r4 = c.r0;
            if (!write_vertex(&c, 0) || !write_vertex(&c, 1) || !write_vertex(&c, 2)) return 0;
            c.r2 = 4;
            state = LATER;
            break;
        }
        case LATER: {                        /* triangles that share two vertices with the last one */
            c.r7 -= 1;
            const int32_t next = stream_s16(&c, c.r14);
            c.r0 = (uint32_t)next;
            if (c.r7 == 0) { state = STRIP_END; break; }
            c.r2 = (c.r9 & 4u) ? 0u : 0xFFFFFFFFu;
            shift_vertices_down(&c);
            const uint32_t z = load_vertex(&c, next, 12);
            c.r14 += VERTEX_STRIDE_IN_STREAM;
            c.r5 ^= c.r2;
            const int front = (int32_t)z >= 0;
            c.r9 = (c.r9 << 1) | front;
            if (front) c.r5 = ~c.r5;
            const float area = screen_area(&c);
            c.r4 = (c.r4 << 1) | (z > c.r10);
            c.r8 += VERTEX_STRIDE_IN_STREAM;
            if (!(area > 0.0f)) {            /* dropped: close the strip, start over */
                c.r0 = 0xFFFFFFFFu;
                close_strip(&c);
                state = RESTART;
                break;
            }
            if (c.r4 != 0) {                 /* something earlier was out of range */
                close_strip(&c);
                c.r4 = 1;
                if (!call(&c, CLIPPER, RET_CLIP_B)) return 0;
                state = RESTART;
                break;
            }
            c.r1 = c.writer[2];
            if (!call(&c, c.writer[2], RET_WRITER2_LATER)) return 0;
            c.r2 = 4;
            c.r0 = (uint32_t)(int32_t)stream_s16(&c, c.r14);
            break;
        }
        case STRIP_END:
            if (c.r6 != 0) {
                c.r0 = 0xFFFFFFFFu;
                close_strip(&c);
            }
            state = NEXT_STRIP;
            break;
        case NEXT_STRIP:
            c.r11 -= 1;
            state = c.r11 == 0 ? FINISH : STRIP_TOP;
            break;
        default:
            return 0;
        }
    }

    const uint32_t sink = s->bank[3];
    vf3_mem_set_u32(ram, sink, c.r12);
    c.r4 = c.r14;
    to_state(&c);
    s->v[3] = sink;
    s->v[14] = saved_r14;
    s->v[15] = sp0;
    s->v[VF3_REG_PR] = pr;
    s->pc = pr;
    return 1;
}
