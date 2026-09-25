/* vf3 orient2 — 2D orientation bit helper (SH-4 0x8C068F92).
 *
 * The hottest fight function (0x8C068FF6, ~1.4M hits / 120 frames) calls
 * this 54-byte FPU helper five times and ORs the results into a per-vertex
 * classification mask. Recovered semantics, validated 64/64 against golden
 * register snapshots (extract/analysis/goldens/f_0c068f92.json,
 * tools/golden_extract.py + tools/portcheck.py):
 *
 *     a = (fr7 - fr5) * (fr8 - fr6)
 *     b = (fr6 - fr4) * (fr9 - fr7)
 *     d = a - b
 *     return d > 0 ? 2 : (d == 0 ? 1 : 4)
 *
 * i.e. a 2x2 determinant sign test over six single-precision inputs with
 * bit-per-outcome results (1 = degenerate, 2 = positive, 4 = negative).
 */
#ifndef VF3_FIGHT_ORIENT2_H
#define VF3_FIGHT_ORIENT2_H

enum {
    VF3_ORIENT_ON  = 1, /* d == 0 */
    VF3_ORIENT_POS = 2, /* d >  0 */
    VF3_ORIENT_NEG = 4  /* d <  0 */
};

int vf3_orient2_bits(float fr4, float fr5, float fr6,
                     float fr7, float fr8, float fr9);

#endif /* VF3_FIGHT_ORIENT2_H */
