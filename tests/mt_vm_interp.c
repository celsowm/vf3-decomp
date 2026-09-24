/* tests/mt_vm_interp.c — value-level parity for the MT channel evaluator.
 *
 * Synthetic channel layout reproducing each opcode class of f_8c09d690:
 *   ch0: op 1  (literal)          tuple: [7.5]
 *   ch1: op 0  (zero)
 *   ch2: op 2  scalar, count=1    times: [4]  tuples: [v0=2.0, v1=6.0, v2=9.0]
 *   ch3: op 3  spline, count=1    times: [4]  tuples: vec3[0]=(1,256,512)
 *                                        vec3[1]=(9,0,0), tail float2 {0,0}
 *   ch4..62: op 0
 *
 * Expected values derived by hand from the transliterated formulas,
 * incl. the 1/256 slope scale and the (t-1) Hermite basis.
 */
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include "../src/fight/mt_play.h"

/* one contiguous fake-RAM blob: [ hdr(12+63) | counts | times | tuples ] */
static uint8_t  ram_blob[12 + 63 + 2 + 2 + 9 * 4 + 64];
static float    outbuf[8 + 63 + 8];
#define RB 0x8C600000u    /* fake DC base for the blob */

static int fails = 0;
static void chk(const char *what, float got, float want)
{
    if (fabsf(got - want) > 1e-5f) {
        printf("  FAIL %s: got %.9g want %.9g\n", what, got, want);
        ++fails;
    } else {
        printf("  ok   %s = %.6g\n", what, got);
    }
}

static void wire(float literal0, float s_v0, float s_v1,
                 float q0x, float q0y, float q0z, float q1x)
{
    memset(ram_blob, 0, sizeof ram_blob);
    const unsigned hdrlen = 12 + 63;
    /* ops */
    uint8_t *ops = ram_blob + 12;
    ops[0] = 1;                 /* literal */
    ops[1] = 0;                 /* zero    */
    ops[2] = 2;                 /* scalar  */
    ops[3] = 3;                 /* spline  */
    /* streams (hdrlen=75 -> pad; counts@76, times@78, tuples@80) */
    uint8_t *counts = ram_blob + 76;             counts[0] = 1; counts[1] = 1;
    uint8_t *times  = ram_blob + 78;             times[0]  = 4; times[1]  = 4;
    float   *tup    = (float *)(ram_blob + 80);
    tup[0] = literal0;
    tup[1] = 2.0f; tup[2] = 6.0f; tup[3] = 9.0f;           /* scalar  */
    tup[4] = q0x;  tup[5] = q0y;  tup[6] = q0z;            /* spline v0 */
    tup[7] = q1x;  tup[8] = 0.0f;  tup[9] = 0.0f;          /* spline v1 + tail */
    /* header with absolute fake-RAM pointers */
    *(uint32_t *)(ram_blob + 0) = RB + 76;
    *(uint32_t *)(ram_blob + 4) = RB + 78;
    *(uint32_t *)(ram_blob + 8) = RB + 80;
    (void)s_v0; (void)s_v1;
}

int main(void)
{
    wire(7.5f, 2.0f, 6.0f, 1.0f, 256.0f, 512.0f, 9.0f);
    VF3MtTask task = { ram_blob, 0, ram_blob, RB };
    float *out = outbuf + 2;

    /* phase mid-span: t = (0x200-0x100)/(0x400-0x100) = 1/3 */
    int rc = vf3_mt_eval_frame(&task, 0x200, &out);
    if (rc != 0) { printf("FAIL rc=%d\n", rc); return 1; }

    const float t = 1.0f / 3.0f;
    chk("ch0 literal", outbuf[2 + 0], 7.5f);
    chk("ch1 zero",    outbuf[2 + 1], 0.0f);
    /* 0x8C09D408 flip negate z-channels: ch2 (idx 2) is flipped */
    chk("ch2 lerp",    outbuf[2 + 2], -(2.0f + (6.0f - 2.0f) * t));
    {
        /* true engine form: v0x + rel(t-1)/256*(t*z0 + (t-1)*y0)
         *                   + t*t*(2t-3)*(v0x - v1x)                    */
        float s0 = 256.0f, s1 = 512.0f, v0 = 1.0f, v1 = 9.0f;
        float want = v0 + 256.0f * (t - 1.0f) * (1 / 256.0f)
                        * (t * s1 + (t - 1.0f) * s0)
                   + t * t * (2 * t - 3) * (v0 - v1);
        chk("ch3 spline", outbuf[2 + 3], want);
    }
    printf("  out advanced by %ld floats (want 63)\n", (long)(out - (outbuf + 2)));
    if (out - (outbuf + 2) != 63) ++fails;

    /* exact-hit frame: phase == key time 0x400 */
    wire(7.5f, 2.0f, 6.0f, 1.0f, 256.0f, 512.0f, 9.0f);
    out = outbuf + 2;
    rc = vf3_mt_eval_frame(&task, 0x400, &out);
    chk("ch2 exact", outbuf[2 + 2], -6.0f);    /* tuple[idx+1], z-flipped */
    chk("ch3 exact", outbuf[2 + 3], 9.0f);     /* vec3[idx+1].x  */

    printf("mt_vm_interp: %s\n", fails ? "FAIL" : "PASS");
    return fails ? 1 : 0;
}
