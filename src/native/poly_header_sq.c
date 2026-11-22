/* poly_header_sq.c - SH-4 0x8C055E00, natively.
 *
 * Writes one polygon header (two 16-byte halves) into the store-queue slot the
 * GBR block points at, and leaves the next slot in r12.  Mirror of the
 * readable authority src/fight/poly_header_sq.c (`vf3_poly_header_sq_entry`).
 *
 *   r4 = the source record (its words +4/+8/+12/+16 are the first four header
 *        words), GBR + 72 (or +80 for the tagged form) holds the destination
 *        pointer, 0x0C16CA08 -> the SQ state whose word +0 (or +8) supplies the
 *        QACR area byte, 0x0C16B820 is a shading template of two more 16-byte
 *        halves.
 *
 *   [0x0C055B80] == 0:  plain form; the four source words are stored as the
 *       first half, and if bit 5 of the first word is clear that half is the
 *       whole header (the template's first half is stored at +16 of it),
 *       otherwise the destination moves on 32 bytes and holds both template
 *       halves.
 *   [0x0C055B80] != 0:  tagged form; the first word gets bit 25 set, the third
 *       word is masked to 26 bits with 0x941000C0 or-ed in, and the second
 *       half is built from the word at 0x0C055B84 plus the template.
 *
 *   Both forms end with r4 += 20, r12 = destination + 32, r2 = a pointer into
 *   the vertex area (0x0C16B8C8 plain, 0x0C16B8D0 tagged), SR.T = 1 iff the
 *   header fits a single half, and a PREF of the finished slot.
 *
 * The observable, flat-RAM contract is the RAM written at `dst` (a pointer the
 * GBR block holds; the fixture points it at a RAM window), the register file
 * (r0..r6, r12), SR's T bit and pr.  The QACR0/QACR1 device writes (0xFF000038/
 * 3C) and the PREF flushes are device side-effects that are inert here: PREF
 * only fires when the destination is in the 0xE0000000 store-queue region,
 * which the fixture never uses.  The guest also writes a bank register
 * (bank[3] = r2); the native model carries no banked registers, so that write
 * is unobservable (r2 itself carries the same value and is compared).
 *
 * See docs/re/native_poly_header_sq.md. */
#include "poly_header_sq.h"

#include "aim_math.h"

enum {
    MODE_FLAG = 0x0C055B80u, TAG_WORD = 0x0C055B84u, SQ_STATE = 0x0C16CA08u,
    TEMPLATE = 0x0C16B820u,
    QACR0 = 0xFF000038u, QACR1 = 0xFF00003Cu,
    TAG_BIT = 0x02000000u, KEEP_MASK = 0x03FFFFFFu, TAG_OR = 0x941000C0u,
    BIT5 = 32u,
    BANK_PLAIN = 0x0C16B8C8u, BANK_TAGGED = 0x0C16B8D0u,
};

static void put4(vf3_native_aim *a, uint32_t at, uint32_t v0, uint32_t v1,
                 uint32_t v2, uint32_t v3)
{
    vf3_aim_set_u32(a, at, v0);
    vf3_aim_set_u32(a, at + 4u, v1);
    vf3_aim_set_u32(a, at + 8u, v2);
    vf3_aim_set_u32(a, at + 12u, v3);
}

int vf3_native_poly_header_sq(vf3_native_aim *a)
{
    const int tagged = vf3_aim_u32(a, MODE_FLAG) != 0;
    const uint32_t src = a->r[4];

    /* The SQ state feeds only the QACR area byte, which goes to the two device
     * (store-queue) registers - inert in the flat-RAM model.  Keep the read
     * for fidelity; nothing here consumes it. */
    (void)vf3_aim_u32(a, vf3_aim_u32(a, SQ_STATE) + (tagged ? 8u : 0u));

    uint32_t dst = vf3_aim_u32(a, a->gbr + (tagged ? 80u : 72u));
    uint32_t w1 = vf3_aim_u32(a, src + 4u), w2 = vf3_aim_u32(a, src + 8u);
    uint32_t w3 = vf3_aim_u32(a, src + 12u), w5 = vf3_aim_u32(a, src + 16u);
    if (tagged) {
        w1 |= TAG_BIT;
        w3 = (w3 & KEEP_MASK) | TAG_OR;
    }
    put4(a, dst, w1, w2, w3, w5);
    const int single = (w1 & BIT5) == 0;

    uint32_t t[8];
    for (uint32_t i = 0; i < 8; ++i) t[i] = vf3_aim_u32(a, TEMPLATE + 4u * i);
    uint32_t r1 = t[0], r2 = t[1], r3 = t[2], r5 = t[3], r6 = a->r[6];

    if (!tagged) {
        if (!single) {
            dst += 32u;
            put4(a, dst, r1, r2, r3, r5);
            r1 = t[4]; r2 = t[5]; r3 = t[6]; r5 = t[7];
        }
        put4(a, dst + 16u, r1, r2, r3, r5);
    } else {
        if (!single) {
            r1 = TAG_WORD;
            r6 = vf3_aim_u32(a, TAG_WORD);
            dst += 32u;
            r2 = t[1]; r3 = t[2]; r5 = t[3];
            put4(a, dst, r6, r2, r3, r5);
            r2 = t[5]; r3 = t[6]; r5 = t[7];
            put4(a, dst + 16u, r6, r2, r3, r5);
        } else {
            r1 = w1; r2 = w2; r3 = w3; r5 = w5;
        }
    }
    /* a final PREF of the finished slot would follow; it is a store-queue
     * device flush and is inert when `dst` is a RAM pointer. */

    a->r[0] = dst;
    (void)r2;                                             /* bank pointer, below */
    a->r[1] = r1; a->r[3] = r3; a->r[5] = r5; a->r[6] = r6;
    a->r[4] = src + 20u;
    a->r[12] = dst + 32u;
    a->r[2] = tagged ? BANK_TAGGED : BANK_PLAIN;
    a->sr = (a->sr & ~1u) | (single ? 1u : 0u);
    return 1;
}
