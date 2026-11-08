/* byte_color.c - SH-4 0x8C0563AC: the two-byte color scale into floats.
 *
 * A self-contained leaf (80 B, 0x0C0563AC..0x0C0563F8), call-free and
 * branch-free (straight-line; the only control transfer is the final rts).
 * It reads three floats through a pointer from the literal pool, scales them
 * by a fourth, unpacks two packed bytes into three byte channels, converts
 * them to floats, scales those by the first three, and writes three floats
 * down a descending run of the output pointer.
 *
 * The data comes from the literal pool:
 *
 *   ptrA    = read32(0x0c056504)   the three source floats (fr4, fr5, fr6)
 *   scale   = [0x0c056508]          a constant float (fr7), about 1/255
 *   out     = read32(0x0c056510)    the output base (fr0, fr1, fr2)
 *
 * and the packed bytes from the caller's words:
 *
 *   lo = (int16)read16([r4 + 4]);   r5 = lo's low  byte,  r6b = lo's high byte
 *   hi = (int16)read16([r4 + 6]);   r2 = hi's low byte
 *
 * The float pipeline (the `w` below is FPSCR.PR ? 8 : 4, the single/double
 * width that gates every load and store):
 *
 *   fr4 = [ptrA+0] * fr7        scaled source channels
 *   fr5 = [ptrA+w] * fr7
 *   fr6 = [ptrA+2w] * fr7
 *   fr0 = float(r2) * fr6       converted byte channels, scaled
 *   fr1 = float(r5) * fr5
 *   fr2 = float(r6b) * fr4
 *
 * The three outputs are stored down the output pointer:
 *
 *   store fr0 at [out]
 *   store fr1 at [out - w]
 *   store fr2 at [out - 2*w]
 *
 * and there is one earlier store of the entry fr0 at [r1 - w] (a scratch the
 * caller leaves the frame for).  Registers left: r0 = 0x0c056508, r1 = the
 * output pointer run down to out-2w, r2 = hi's low byte, r4 = r4 + 8,
 * r5 = lo's high byte, r6 = hi's low byte, and SR's T bit is untouched (this
 * body never compares).  FPUL (r53) is left holding hi's low byte.
 */
#include "fight/readable.h"
#include "fight/readable_fp.h"

#define R(n) s->v[(n)]

int vf3_byte_color_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const unsigned w = (R(18) & 0x100000u) ? 8u : 4u;
    const uint32_t r1_in = R(1);
    const uint32_t r4_in = R(4);

    /* 0x0c0563ac: the entry fr0 is pushed out to [r1 - w] (scratch). */
    vf3_matrix_store(s, ram, 0, r1_in - w);

    /* 0x0c0563c0..c6: the pool pointer and the fixed scale location. */
    uint32_t r2 = vf3_mem_u32(ram, 0x0c056504u);
    uint32_t r4 = r4_in + 4u;
    vf3_matrix_load(s, ram, 7, 0x0c056508u);     /* fr7 = scale */
    uint32_t out = vf3_mem_u32(ram, 0x0c056510u);

    /* 0x0c0563ca..ce: fr4, fr5, fr6 = the three source floats at ptrA. */
    vf3_matrix_load(s, ram, 4, r2); r2 += w;
    vf3_matrix_load(s, ram, 5, r2); r2 += w;
    vf3_matrix_load(s, ram, 6, r2);

    /* 0x0c0563d0..e8: the packed bytes. */
    const uint32_t lo = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, r4);
    const uint32_t hi = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, r4 + 2u);
    r4 += 4u;

    /* 0x0c0563d2..da: scale the source channels by fr7 in the FP bank. */
    vf3_fr_set(s, 4, vf3_f_mul(s, vf3_fr_get(s, 4), vf3_fr_get(s, 7)));
    vf3_fr_set(s, 5, vf3_f_mul(s, vf3_fr_get(s, 5), vf3_fr_get(s, 7)));
    vf3_fr_set(s, 6, vf3_f_mul(s, vf3_fr_get(s, 6), vf3_fr_get(s, 7)));

    /* 0x0c0563d8..f0: the byte channels, as floats, scaled, into the bank. */
    const uint32_t c_r2 = lo & 0xffu;            /* lo's low byte */
    const uint32_t c_r5 = (lo >> 8u) & 0xffu;     /* lo's high byte */
    const uint32_t c_r6 = hi & 0xffu;            /* hi's low byte */
    vf3_fr_set(s, 0, vf3_f_mul(s, vf3_f_from_int(s, (int32_t)c_r2),
                                vf3_fr_get(s, 6)));
    vf3_fr_set(s, 1, vf3_f_mul(s, vf3_f_from_int(s, (int32_t)c_r5),
                                vf3_fr_get(s, 5)));
    vf3_fr_set(s, 2, vf3_f_mul(s, vf3_f_from_int(s, (int32_t)c_r6),
                                vf3_fr_get(s, 4)));

    /* 0x0c0563f2..f8: the three stores down the output run. */
    vf3_matrix_store(s, ram, 0, out);
    vf3_matrix_store(s, ram, 1, out - w);
    vf3_matrix_store(s, ram, 2, out - 2u * w);

    /* the visited registers. */
    R(0) = 0x0c056508u;
    R(1) = out - 2u * w;
    R(2) = c_r2;
    R(4) = r4_in + 8u;
    R(5) = c_r5;
    R(6) = c_r6;
    R(53) = c_r6;                        /* FPUL: the last r53 write */

    s->pc = R(16);
    return ram->oob == 0;
}
