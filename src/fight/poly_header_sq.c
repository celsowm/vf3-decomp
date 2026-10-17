/* poly_header_sq.c - 0x8C055E00  write one polygon header (two 16-byte halves) into the store-queue slot the
 * GBR block points at, and leave the next slot in r12.
 *
 *   r4 -> the source record (words +4 / +8 / +12 / +16 are the first four header words), GBR + 72 (or +80 for
 *   the second form) holds the destination pointer, 0x0C16CA08 -> the SQ state whose word +0 (or +8) supplies the
 *   QACR area byte, 0x0C16B820 is a shading template of two more 16-byte halves.
 *
 *   [0x0C055B80] == 0:  plain form. The four source words are stored as the first half; if bit 5 of the first
 *       word is clear that half is the whole header (the template's first half is stored at +16 of it),
 *       otherwise the destination moves on 32 bytes and holds both template halves.
 *   [0x0C055B80] != 0:  tagged form. The first word gets bit 25 set, the third word is masked to 26 bits with
 *       0x941000C0 or-ed in, and the second half is built from the word at 0x0C055B84 plus the template.
 *
 *   Both forms end with r4 += 20, r12 = destination + 32, bank register r3 = a pointer into the vertex area
 *   (0x0C16B8C8 plain, 0x0C16B8D0 tagged), and pref of the finished slot. */
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "fight/vec3_inline.h"

enum { MODE_FLAG = 0x0C055B80u, TAG_WORD = 0x0C055B84u, SQ_STATE = 0x0C16CA08u, TEMPLATE = 0x0C16B820u,
       QACR0 = 0xFF000038u, QACR1 = 0xFF00003Cu, TAG_BIT = 0x02000000u, KEEP_MASK = 0x03FFFFFFu,
       TAG_OR = 0x941000C0u, BIT5 = 32u, SQ_REGION_MASK = 0xFC000000u, SQ_REGION = 0xE0000000u };

static void pref_sq(const vf3_ram_map *ram, uint32_t a)
{
    if ((a & SQ_REGION_MASK) == SQ_REGION) vf3_matrix_pref(ram, a);
}

static void put4(const vf3_ram_map *ram, uint32_t at, uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    vf3_mem_set_u32(ram, at, a);
    vf3_mem_set_u32(ram, at + 4, b);
    vf3_mem_set_u32(ram, at + 8, c);
    vf3_mem_set_u32(ram, at + 12, d);
}

int vf3_poly_header_sq_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    if (!s->gbr_known) return 0;
    const int tagged = vf3_mem_u32(ram, MODE_FLAG) != 0;
    const uint32_t src = R(4);
    const uint32_t area = vf3_mem_u32(ram, vf3_mem_u32(ram, SQ_STATE) + (tagged ? 8 : 0)) >> 24;
    vf3_mem_set_u32(ram, QACR0, area);
    vf3_mem_set_u32(ram, QACR1, area);

    uint32_t dst = vf3_mem_u32(ram, s->gbr + (tagged ? 80 : 72));
    uint32_t w1 = vf3_mem_u32(ram, src + 4), w2 = vf3_mem_u32(ram, src + 8);
    uint32_t w3 = vf3_mem_u32(ram, src + 12), w5 = vf3_mem_u32(ram, src + 16);
    if (tagged) {
        w1 |= TAG_BIT;
        w3 = (w3 & KEEP_MASK) | TAG_OR;
    }
    put4(ram, dst, w1, w2, w3, w5);
    const int single = (w1 & BIT5) == 0;                  /* tst #32: the header fits one half */

    uint32_t t[8];
    for (uint32_t i = 0; i < 8; ++i) t[i] = vf3_mem_u32(ram, TEMPLATE + 4 * i);
    uint32_t r1 = t[0], r2 = t[1], r3 = t[2], r5 = t[3], r6 = R(6);

    if (!tagged) {
        if (!single) {
            pref_sq(ram, dst);
            dst += 32;
            put4(ram, dst, r1, r2, r3, r5);
            r1 = t[4]; r2 = t[5]; r3 = t[6]; r5 = t[7];
        }
        put4(ram, dst + 16, r1, r2, r3, r5);
    } else {
        pref_sq(ram, dst);
        if (!single) {
            r1 = TAG_WORD;
            r6 = vf3_mem_u32(ram, TAG_WORD);
            dst += 32;
            r2 = t[1]; r3 = t[2]; r5 = t[3];
            put4(ram, dst, r6, r2, r3, r5);
            r2 = t[5]; r3 = t[6]; r5 = t[7];
            put4(ram, dst + 16, r6, r2, r3, r5);
        } else {
            r1 = w1; r2 = w2; r3 = w3; r5 = w5;
        }
    }
    if (!tagged || !single) pref_sq(ram, dst);

    R(0) = dst;
    (void)r2;                                             /* r2 ends as the bank pointer loaded for ldc */
    R(1) = r1; R(3) = r3; R(5) = r5; R(6) = r6;
    R(4) = src + 20;
    R(12) = dst + 32;
    R(2) = tagged ? 0x0C16B8D0u : 0x0C16B8C8u;
    s->bank[3] = R(2);
    s->bank_known = 1;
    R(VF3_REG_SR) = (R(VF3_REG_SR) & ~1u) | (single ? 1u : 0u);
    s->pc = R(VF3_REG_PR);
    return 1;
}
