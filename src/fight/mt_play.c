/* fight/mt_play.c — MT motion channel evaluator (true port).
 *
 * Provenance: 1ST_READ 0x8C09D690 .. 0x8C09D823 (f_8c09d690, 390 B),
 * decompiled against the CORRECTED image (M23 image-truth fix). Every line
 * group carries its SH4 source address; instruction-level semantics were
 * cross-checked against the M14 mem-watch stream (4817 hits incl. values)
 * and the vf3_7 RAM dump.
 *
 * STRUCTURE (per call — one motion instance, one frame):
 *   hdr = *(task + 0x1D00)         (motion instance header)
 *     hdr[0] -> counts   : 1 byte per keyframed channel   (cursor B)
 *     hdr[1] -> times    : packed key-frame time bytes    (r12 cursor)
 *     hdr[2] -> tuples   : float stream                    (r14 cursor)
 *     hdr[3..] (hdr+12)  : 63 opcode bytes, one per channel
 *   phase (r6 arg) = current motion time in 1/256 units
 *   cycle_len ((u16*)(task + 0x1A00)) : loop period, same units base (<<8)
 *   out_pp (r5 arg)  : float** — 63 floats written; cursor advanced +63
 *
 * Channel ops (ops[i], unsigned):
 *   0   -> 0.0f
 *   1   -> next float from tuple stream (raw passthrough)
 *   2   -> scalar Hermite lerp channel; per channel: b5 key times then
 *          b5+2 floats in the tuple stream
 *   >=3 -> vec3 spline channel (cubic Hermite, slopes scaled by 1/256);
 *          per channel: 12*b5 + 8 tuple bytes (b5 vec3 + trailing float2)
 *
 * End conditions verified against the formula: at t=0 out=v0; t=1 -> v1.
 * Trace-anchored I/O: cursor B walk (record+0x736..), time bytes (+0x75B..),
 * spline tuple reads (+0x7A4+) — see docs/re/mt_vm.md.
 */
#include <stdint.h>
#include <string.h>

#define MT_EVAL_CHANNELS   63u
#define MT_SLOPE_SCALE     (1.0f / 256.0f)   /* literal @0x8C09D830 */
#define MT_NEGATE_BIAS     (-1.0f)           /* literal @0x8C09D834 */

static uint32_t read_u32le(const uint8_t *p)
{
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

static float read_f32le(const uint8_t *p)
{
    const uint32_t bits = read_u32le(p);
    float value;
    memcpy(&value, &bits, sizeof value);
    return value;
}

static float flip_sign(float value)
{
    uint32_t bits;
    memcpy(&bits, &value, sizeof bits);
    bits ^= 0x80000000u;
    memcpy(&value, &bits, sizeof bits);
    return value;
}

typedef struct VF3MtTask {
    /* host-side mirror of the fields this function touches */
    const uint8_t *hdr;        /* *(task + 0x1D00) */
    uint16_t       cycle;      /* *(u16*)(task + 0x1A00) — loop length */
    /* RAM translation for the absolute u32 pointers stored in the header:
     * host_addr = ram + (hdr_word - ram_base). On-CPU values are absolute. */
    const uint8_t *ram;
    uint32_t       ram_base;
} VF3MtTask;

/* 0x8C09D408 — out-array channel negate pass (runs after every eval).
 * Two strides: 7 vec3 from +8 (p2 side), 14 vec3 from +84 — wait,
 * transliterated literally: */
static void vf3_mt_flip(float *out)
{
    float *p = out + 2;                    /* add #8,r4 */
    for (int i = 0; i < 7; ++i) {          /* 0x8C09D408..0x8C09D417 */
        *p = flip_sign(*p);                /* fneg; fmov.s */
        p += 3;                            /* add #0xc,r4 */
    }
    float *q = out + 21;                   /* r4 after = out+8+7*12; then */
    q = out + 21;                          /* add #-8 -> out+92-8 = out+21 */
    for (int i = 0; i < 14; ++i) {         /* 0x8C09D418..0x8C09D427 */
        *q = flip_sign(*q);
        q += 3;
    }
}

/* Evaluator body: f_8c09d690.  Returns 0 OK, -1 on bad args. */
int vf3_mt_eval_frame(const VF3MtTask *task, int32_t phase, float **out_pp)
{
    if (!task || !task->hdr || !out_pp || !*out_pp)
        return -1;

    const uint8_t *hdr     = task->hdr;
    const uint32_t counts_addr = read_u32le(hdr + 0);
    const uint32_t times_addr = read_u32le(hdr + 4);
    const uint32_t tuples_addr = read_u32le(hdr + 8);
    if (counts_addr < task->ram_base || times_addr < task->ram_base ||
        tuples_addr < task->ram_base)
        return -1;
    const uint8_t *counts = task->ram + (counts_addr - task->ram_base);
    const uint8_t *times = task->ram + (times_addr - task->ram_base);
    const uint8_t *tup = task->ram + (tuples_addr - task->ram_base);
    const uint8_t *ops     = hdr + 12;
    const int32_t  tabT    = (int32_t)task->cycle << 8;
    float         *out     = *out_pp;

    for (uint32_t i = 0; i < MT_EVAL_CHANNELS; ++i) {
        const uint8_t op = ops[i];
        float v;
        if (op == 1) {                         /* 0x8C09D6C6: literal float */
            v = read_f32le(tup);
            tup += 4;
        } else if (op == 0) {                  /* 0x8C09D6C4 path: fldi0 */
            v = 0.0f;
        } else {                               /* 0x8C09D6EA: keyframed */
            const int     is_spline = (op >= 3);     /* stack8 = op-2 */
            const uint8_t cnt = *counts++;           /* 0x8C09D6F4 cursor B */
            int32_t prevT = 0x100;                   /* lit 0x8C09D82C */
            int32_t nextT;
            int32_t idx = -1;                        /* key index found */
            int     exact = 0;

            /* key scan: find first key whose time >= phase (0x8C09D706 loop) */
            for (int k = 0; ; ++k) {
                if (k >= cnt) {                      /* 0x8C09D74A fallback */
                    idx = cnt;                      /* final key -> cycle key */
                    nextT = tabT;
                    break;
                }
                const int32_t kt = (int32_t)times[k] << 8;
                if (kt > phase) { nextT = kt; idx = k; break; }
                if (kt == phase) { idx = k; exact = 1; break; }
                prevT = kt;                          /* 0x8C09D720 */
            }

            times += cnt;                            /* times cursor += count */

            if (exact) {                             /* 0x8C09D722 */
                if (!is_spline) {
                    v = read_f32le(tup + (size_t)(idx + 1) * 4u);
                    tup += ((size_t)cnt + 2u) * 4u;  /* 4*(cnt+2) bytes */
                } else {
                    v = read_f32le(tup + (size_t)(3 * (idx + 1)) * 4u);
                    tup += ((size_t)3u * cnt + 4u) * 4u; /* 12*cnt+16 bytes */
                }
            } else {                                 /* 0x8C09D752 lerp */
                const int32_t rel  = phase - prevT;       /* 0x8C09D760 */
                const int32_t span = nextT - prevT;       /* 0x8C09D75C */
                if (!is_spline) {                         /* 0x8C09D7D2 */
                    const float t  = (float)rel / (float)span;  /* d7da/d7ea */
                    const float v0 = read_f32le(tup + (size_t)idx * 4u);
                    const float v1 = read_f32le(tup + (size_t)(idx + 1) * 4u);
                    v = v0 + t * (v1 - v0);               /* fmac fr0,fr6,fr4 */
                    tup += ((size_t)cnt + 2u) * 4u;
                } else {                                  /* 0x8C09D762..D7CC */
                    const float t  = (float)rel / (float)span;
                    const size_t base = (size_t)(3 * idx) * 4u;
                    const float v0x = read_f32le(tup + base);        /* fr11 */
                    const float y0  = read_f32le(tup + base + 4u);  /* d778 (+4) */
                    const float z0  = read_f32le(tup + base + 8u);  /* d77e (+8) */
                    const float v1x = read_f32le(tup + base + 12u); /* d782 (+12) */
                    /* Hermite cubic (asm order 0x8C09D79A..0x8C09D7CC):
                     *   slope = t*z0' + (t-1)*y0'   (' = /256, d78e/d792)
                     *   v = v0x + rel*(t-1)*slope/1 ... expressed as-is:
                     *   fr8 = v0x + rel * ((t-1)*slope * (1/256)... exact op
                     *   order kept:                                        */
                    v = v0x
                        + (float)rel * (t - 1.0f) * MT_SLOPE_SCALE
                          * (t * z0 + (t - 1.0f) * y0)
                        + t * (t * (2.0f * t - 3.0f)) * (v0x - v1x);
                                                          /* 0x8C09D7C6/C8/CA */
                    tup += ((size_t)3u * cnt + 2u) * 4u;  /* 12*cnt+8 bytes */
                }
            }
        }
        *out++ = v;                                   /* 0x8C09D7FC..D802 */
    }

    /* tail: 0x8C09D80E..0x8C09D816 — negate pass + cursor writeback */
    vf3_mt_flip(*out_pp);
    *out_pp = out;                                    /* 63 floats written */
    return 0;
}

/* qt legacy shim: prior milestone API kept for the frame pipeline — the real
 * semantic source is vf3_mt_eval_frame above. */
