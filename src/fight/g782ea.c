/* Machine-generated transliteration body parts: helpers + function head.
 * See gen782c.py; per-PC body is appended after the pools. */
#include "fight/g782ea.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static uint32_t c_rd32(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 4 <= w->base + w->len) {
            uint32_t v = 0;
            memcpy(&v, w->data + (canon - w->base), 4);
            return v;
        }
    }
    m->oob++;
    return 0;
}

static void c_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 4 <= w->base + w->len) {
            memcpy(w->data + (canon - w->base), &v, 4);
            return;
        }
    }
    m->oob++;
}

static uint16_t c_rd16(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 2 <= w->base + w->len) {
            uint16_t v = 0;
            memcpy(&v, w->data + (canon - w->base), 2);
            return v;
        }
    }
    m->oob++;
    return 0;
}

static int16_t c_rd16s(const vf3_ram_map *ram, uint32_t addr)
{
    return (int16_t)c_rd16(ram, addr);
}

static void c_wr16(const vf3_ram_map *ram, uint32_t addr, uint16_t v)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 2 <= w->base + w->len) {
            memcpy(w->data + (canon - w->base), &v, 2);
            return;
        }
    }
    m->oob++;
}

static uint8_t c_rd8(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 1 <= w->base + w->len) {
            return w->data[canon - w->base];
        }
    }
    m->oob++;
    return 0;
}

static int8_t c_rd8s(const vf3_ram_map *ram, uint32_t addr)
{
    return (int8_t)c_rd8(ram, addr);
}

static void c_wr8(const vf3_ram_map *ram, uint32_t addr, uint8_t v)
{
    uint32_t canon = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (canon >= w->base && canon + 1 <= w->base + w->len) {
            w->data[canon - w->base] = v;
            return;
        }
    }
    m->oob++;
}

static float f32(uint32_t bits)
{
    float f;
    memcpy(&f, &bits, 4);
    return f;
}

typedef struct { uint32_t addr; uint32_t val; } g782ea_lit_t;
static const g782ea_lit_t k782ea_lit16[] = {
    { 0x0c07839au, 0xf784u },
    { 0x0c07839cu, 0x0878u },
    { 0x0c07839eu, 0x0874u },
    { 0x0c0783a0u, 0x0870u },
    { 0x0c0783a2u, 0x086cu },
    { 0x0c0783a4u, 0x084cu },
    { 0x0c0783a6u, 0x1b83u },
    { 0x0c0783a8u, 0x08acu },
    { 0x0c0783aau, 0x08b0u },
    { 0x0c0783acu, 0x1bb6u },
    { 0x0c0783aeu, 0x0890u },
    { 0x0c0783b0u, 0x00c4u },
    { 0x0c0783b2u, 0x00cau },
    { 0x0c0783b4u, 0x00ceu },
    { 0x0c0783b6u, 0x00d2u },
    { 0x0c0783b8u, 0x0120u },
    { 0x0c0783bau, 0x0124u },
    { 0x0c0783bcu, 0x0128u },
    { 0x0c0783beu, 0x012cu },
    { 0x0c0783c0u, 0x0130u },
    { 0x0c0783c2u, 0x0134u },
    { 0x0c0783c4u, 0x0138u },
    { 0x0c0783c6u, 0x0152u },
    { 0x0c0783c8u, 0x0212u },
    { 0x0c0783cau, 0x0270u },
    { 0x0c0783ccu, 0x02d4u },
    { 0x0c0783ceu, 0x0326u },
    { 0x0c0783d0u, 0x032au },
    { 0x0c0783d2u, 0x032eu },
    { 0x0c0783d4u, 0x0332u },
    { 0x0c0783d6u, 0x0336u },
    { 0x0c0783d8u, 0x033au },
    { 0x0c0783dau, 0x033eu },
    { 0x0c0783dcu, 0x0342u },
    { 0x0c0783deu, 0x0346u },
    { 0x0c0783e0u, 0x034au },
    { 0x0c0783e2u, 0x034eu },
    { 0x0c0783e4u, 0x0352u },
    { 0x0c0783e6u, 0x0356u },
    { 0x0c0783e8u, 0x036eu },
    { 0x0c0783eau, 0x0372u },
    { 0x0c0783ecu, 0x0376u },
    { 0x0c0783eeu, 0x037au },
    { 0x0c0783f0u, 0x037eu },
    { 0x0c0783f2u, 0x0382u },
    { 0x0c0783f4u, 0x0386u },
    { 0x0c0783f6u, 0x038au },
    { 0x0c0783f8u, 0x038eu },
    { 0x0c0783fau, 0x0392u },
    { 0x0c0783fcu, 0x0396u },
    { 0x0c0783feu, 0x039au },
    { 0x0c078400u, 0x039eu },
    { 0x0c078402u, 0x03a2u },
    { 0x0c078404u, 0x03a6u },
    { 0x0c078406u, 0x03aau },
    { 0x0c078408u, 0x03aeu },
    { 0x0c07840au, 0x03b2u },
    { 0x0c07840cu, 0x03b6u },
    { 0x0c07840eu, 0x03bau },
    { 0x0c078410u, 0x03beu },
    { 0x0c078412u, 0x03c2u },
    { 0x0c078414u, 0x03c6u },
    { 0x0c078416u, 0x03ccu },
    { 0x0c078418u, 0x03d2u },
    { 0x0c07841au, 0x03d8u },
    { 0x0c07841cu, 0x03deu },
    { 0x0c07841eu, 0x03e4u },
    { 0x0c078420u, 0x03eau },
    { 0x0c078422u, 0x0406u },
    { 0x0c078424u, 0x040cu },
    { 0x0c078426u, 0x0412u },
    { 0x0c078428u, 0x0418u },
    { 0x0c07842au, 0x041eu },
    { 0x0c07842cu, 0x0424u },
    { 0x0c07842eu, 0x042au },
    { 0x0c078592u, 0x0890u },
    { 0x0c078594u, 0x08acu },
    { 0x0c078596u, 0x08b0u },
    { 0x0c0786f8u, 0x0890u },
    { 0x0c0786fau, 0x1b98u },
    { 0x0c078974u, 0x0890u },
    { 0x0c078976u, 0x1b90u },
    { 0x0c078978u, 0x0100u },
    { 0x0c07897au, 0x08a8u },
    { 0x0c07897cu, 0x0200u },
    { 0x0c07897eu, 0x08a4u },
    { 0x0c078980u, 0x08acu },
    { 0x0c078ae4u, 0x08acu },
    { 0x0c078ae6u, 0x0890u },
    { 0x0c078ae8u, 0x0100u },
    { 0x0c078aeau, 0x08a8u },
    { 0x0c078aecu, 0x0200u },
    { 0x0c078aeeu, 0x08a4u },
    { 0x0c078be0u, 0x0890u },
    { 0x0c078be2u, 0x08a8u },
    { 0x0c078be4u, 0x08a4u },
    { 0x0c078be6u, 0x08acu },
    { 0x0c078be8u, 0x08b0u },
    { 0x0c078beau, 0x0100u },
    { 0x0c078becu, 0x0200u },
    { 0x0c078cc2u, 0x0890u },
    { 0x0c078cccu, 0x1b90u },
    { 0x0c078e18u, 0x0890u },
    { 0x0c078e1cu, 0x1b98u },
    { 0x0c078fa6u, 0x0890u },
    { 0x0c078fa8u, 0x088cu },
    { 0x0c079250u, 0x0890u },
    { 0x0c079254u, 0x1c00u },
    { 0x0c079256u, 0x08a8u },
    { 0x0c079258u, 0x08a4u },
    { 0x0c0793b6u, 0x0890u },
    { 0x0c0793bau, 0x1ba2u },
    { 0x0c0793bcu, 0x1ba6u },
    { 0x0c0793beu, 0x1bacu },
    { 0x0c0793c4u, 0x0894u },
    { 0x0c079522u, 0x0890u },
    { 0x0c079524u, 0x089cu },
    { 0x0c0797e2u, 0x0890u },
    { 0x0c079f4eu, 0x0890u },
    { 0x0c07a33eu, 0x0890u },
    { 0x0c07a5b0u, 0x08acu },
    { 0x0c07a688u, 0x08acu },
    { 0x0c07a68au, 0x1c00u },
    { 0x0c07a68cu, 0x1bb6u },
    { 0x0c07a68eu, 0x08b0u },
    { 0x0c07a790u, 0x08b0u },
    { 0x0c07a792u, 0x08acu },
    { 0x0c07a794u, 0x0890u },
    { 0x0c07a796u, 0x086cu },
    { 0x0c07a798u, 0x1b83u },
    { 0x0c07a79au, 0x1b85u },
    { 0x0c07a79cu, 0x1b86u },
    { 0x0c07a79eu, 0x0898u },
    { 0x0c07a7a0u, 0x1b88u },
    { 0x0c07a7a2u, 0x087cu },
};
static const g782ea_lit_t k782ea_lit32[] = {
    { 0x0c078598u, 0x0c07a74eu },
    { 0x0c07859cu, 0xff000000u },
    { 0x0c0786fcu, 0xff000000u },
    { 0x0c078700u, 0x00ff0000u },
    { 0x0c078704u, 0x0000ff00u },
    { 0x0c0789c8u, 0xff000000u },
    { 0x0c0789ccu, 0x00ff0000u },
    { 0x0c0789d0u, 0x0000ff00u },
    { 0x0c0789d4u, 0x0c07a75au },
    { 0x0c078af0u, 0x0c07a5ccu },
    { 0x0c078af4u, 0x0c07a51au },
    { 0x0c078af8u, 0x0000ff00u },
    { 0x0c078bf0u, 0x0c07a5ccu },
    { 0x0c078bf8u, 0x0000ff00u },
    { 0x0c078bfcu, 0x0c07a6c4u },
    { 0x0c078cd4u, 0x0000ff00u },
    { 0x0c078e30u, 0x0c07a75au },
    { 0x0c078facu, 0x0000ff00u },
    { 0x0c078fb8u, 0xff000000u },
    { 0x0c078fbcu, 0x00ff0000u },
    { 0x0c078fc0u, 0x0c079f10u },
    { 0x0c07925cu, 0x0000ff00u },
    { 0x0c079260u, 0xff000000u },
    { 0x0c079264u, 0x00ff0000u },
    { 0x0c0793ccu, 0x0000ff00u },
    { 0x0c0793d0u, 0xff000000u },
    { 0x0c0793d4u, 0x00ff0000u },
    { 0x0c0793d8u, 0x0c07a336u },
    { 0x0c0793dcu, 0x80000000u },
    { 0x0c07952cu, 0x80000000u },
    { 0x0c079530u, 0x0c07a6c4u },
    { 0x0c0797e8u, 0xff000000u },
    { 0x0c0797ecu, 0x00ff0000u },
    { 0x0c0797f0u, 0x0000ff00u },
    { 0x0c0797f4u, 0x0c07a6c4u },
    { 0x0c079f64u, 0x0c078376u },
    { 0x0c07a35cu, 0x0c078376u },
    { 0x0c07a690u, 0x0f000000u },
    { 0x0c07a694u, 0x0c29b868u },
    { 0x0c07a698u, 0x0c078376u },
    { 0x0c07a7a4u, 0x0c078376u },
};


static uint32_t c_plook(const g782ea_lit_t *t, size_t n, uint32_t addr, int *gated, int id)
{
    uint32_t c = addr & 0x0FFFFFFFu;
    size_t i;
    for (i = 0; i < n; i++)
        if (t[i].addr == c)
            return t[i].val;
    *gated = id;
    return 0;
}

static int8_t c_p8s(const vf3_ram_map *ram, uint32_t addr, int *gated)
{
    uint32_t c = addr & 0x0FFFFFFFu;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (c >= w->base && c + 1 <= w->base + w->len)
            return (int8_t)w->data[c - w->base];
    }
    m->oob++;
    *gated = 911;
    return 0;
}

static uint32_t c_p16(const vf3_ram_map *ram, uint32_t addr, int *gated)
{
    uint32_t c = addr & 0x0FFFFFFFu;
    size_t k;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (k = 0; k < sizeof(k782ea_lit16) / sizeof(k782ea_lit16[0]); k++)
        if (k782ea_lit16[k].addr == c)
            return k782ea_lit16[k].val & 0xFFFFu;
    for (i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (c >= w->base && c + 2 <= w->base + w->len) {
            uint16_t v = 0;
            memcpy(&v, w->data + (c - w->base), 2);
            return v;
        }
    }
    m->oob++;
    *gated = 912;
    return 0;
}

static uint32_t c_p32(const vf3_ram_map *ram, uint32_t addr, int *gated)
{
    uint32_t c = addr & 0x0FFFFFFFu;
    size_t k;
    int i;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (k = 0; k < sizeof(k782ea_lit32) / sizeof(k782ea_lit32[0]); k++)
        if (k782ea_lit32[k].addr == c)
            return k782ea_lit32[k].val;
    for (i = 0; i < ram->n; i++) {
        const vf3_ram_win *w = &ram->wins[i];
        if (c >= w->base && c + 4 <= w->base + w->len) {
            uint32_t v = 0;
            memcpy(&v, w->data + (c - w->base), 4);
            return v;
        }
    }
    m->oob++;
    *gated = 913;
    return 0;
}

void vf3_g782ea_8c0782ea(uint32_t in_r0, uint32_t in_r1, uint32_t in_r2,
                          uint32_t in_r3, uint32_t in_r4, uint32_t in_r5,
                          uint32_t in_r6, uint32_t in_r7, uint32_t in_r8,
                          uint32_t in_r9, uint32_t in_r10, uint32_t in_r11,
                          uint32_t in_r12, uint32_t in_r13, uint32_t in_r14,
                          uint32_t in_r15, uint32_t in_pr, uint32_t in_sr,
                          uint32_t in_fpscr,
                          uint32_t in_fr0, uint32_t in_fr1, uint32_t in_fr2,
                          uint32_t in_fr3, uint32_t in_fr4, uint32_t in_fr5,
                          uint32_t in_fr6, uint32_t in_fr7, uint32_t in_fr8,
                          uint32_t in_fr9, uint32_t in_fr10, uint32_t in_fr11,
                          uint32_t in_fr12, uint32_t in_fr13, uint32_t in_fr14,
                          uint32_t in_fr15,
                          vf3_g782ea_out *o, const vf3_ram_map *ram)
{
    uint32_t r0 = in_r0, r1 = in_r1, r2 = in_r2, r3 = in_r3;
    uint32_t r4 = in_r4, r5 = in_r5, r6 = in_r6, r7 = in_r7;
    uint32_t r8 = in_r8, r9 = in_r9, r10 = in_r10, r11 = in_r11;
    uint32_t r12 = in_r12, r13 = in_r13, r14 = in_r14, r15 = in_r15;
    uint32_t pr = in_pr;
    uint32_t mach = 0, macl = 0;
    int T = (in_sr & 1u) ? 1 : 0;
    uint32_t fr[16];
    int gated = 0;
    int bpath = (in_pr == 0x0C0782D0u);
    long c5de = 0, c891a = 0;
    fr[0] = in_fr0; fr[1] = in_fr1; fr[2] = in_fr2; fr[3] = in_fr3;
    fr[4] = in_fr4; fr[5] = in_fr5; fr[6] = in_fr6; fr[7] = in_fr7;
    fr[8] = in_fr8; fr[9] = in_fr9; fr[10] = in_fr10; fr[11] = in_fr11;
    fr[12] = in_fr12; fr[13] = in_fr13; fr[14] = in_fr14; fr[15] = in_fr15;
    (void)in_fpscr; (void)mach; (void)macl;
    goto L_8c0782ea;
L_8c0782ea: /* 4f22 */
    r15 -= 4; c_wr32(ram, r15, pr);
L_8c0782ec: /* 9055 */
    r0 = (uint32_t)(int32_t)(int16_t)0xf784; /* @(0x8c07839a,pc) */
L_8c0782ee: /* 9355 */
    r3 = (uint32_t)(int32_t)(int16_t)0x0878; /* @(0x8c07839c,pc) */
L_8c0782f0: /* 3f0c */
    r15 += r0;
L_8c0782f2: /* 33fc */
    r3 += r15;
L_8c0782f4: /* 2342 */
    c_wr32(ram, r3, r4);
L_8c0782f6: /* e068 */
    r0 = (uint32_t)(int32_t)104;
L_8c0782f8: /* 9251 */
    r2 = (uint32_t)(int32_t)(int16_t)0x0874; /* @(0x8c07839e,pc) */
L_8c0782fa: /* 32fc */
    r2 += r15;
L_8c0782fc: /* 2252 */
    c_wr32(ram, r2, r5);
L_8c0782fe: /* 934f */
    r3 = (uint32_t)(int32_t)(int16_t)0x0870; /* @(0x8c0783a0,pc) */
L_8c078300: /* 33fc */
    r3 += r15;
L_8c078302: /* 2362 */
    c_wr32(ram, r3, r6);
L_8c078304: /* 924d */
    r2 = (uint32_t)(int32_t)(int16_t)0x086c; /* @(0x8c0783a2,pc) */
L_8c078306: /* 32fc */
    r2 += r15;
L_8c078308: /* 2272 */
    c_wr32(ram, r2, r7);
L_8c07830a: /* 934b */
    r3 = (uint32_t)(int32_t)(int16_t)0x084c; /* @(0x8c0783a4,pc) */
L_8c07830c: /* 33fc */
    r3 += r15;
L_8c07830e: /* 0f36 */
    c_wr32(ram, (r15 + r0), r3);
L_8c078310: /* 9045 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0874; /* @(0x8c07839e,pc) */
L_8c078312: /* 0efe */
    r14 = c_p32(ram, (r15 + r0), &gated);
L_8c078314: /* 9044 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0870; /* @(0x8c0783a0,pc) */
L_8c078316: /* 0dfe */
    r13 = c_p32(ram, (r15 + r0), &gated);
L_8c078318: /* 9040 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0878; /* @(0x8c07839c,pc) */
L_8c07831a: /* 0cfe */
    r12 = c_p32(ram, (r15 + r0), &gated);
L_8c07831c: /* 1c35 */
    c_wr32(ram, r12 + 20, r3);
L_8c07831e: /* 9042 */
    r0 = (uint32_t)(int32_t)(int16_t)0x1b83; /* @(0x8c0783a6,pc) */
L_8c078320: /* 02ec */
    r2 = (uint32_t)(int32_t)c_p8s(ram, (r14 + r0), &gated);
L_8c078322: /* 622c */
    r2 = r2 & 0xFFu;
L_8c078324: /* 72ff */
    r2 -= 1u;
L_8c078326: /* 61f3 */
    r1 = r15;
L_8c078328: /* 6023 */
    r0 = r2;
L_8c07832a: /* 7164 */
    r1 += 100u;
L_8c07832c: /* c93f */
    r0 &= 0x3fu;
L_8c07832e: /* 2102 */
    c_wr32(ram, r1, r0);
L_8c078330: /* 903a */
    r0 = (uint32_t)(int32_t)(int16_t)0x08ac; /* @(0x8c0783a8,pc) */
L_8c078332: /* 9239 */
    r2 = (uint32_t)(int32_t)(int16_t)0x08ac; /* @(0x8c0783a8,pc) */
L_8c078334: /* 00fe */
    r0 = c_p32(ram, (r15 + r0), &gated);
L_8c078336: /* 32fc */
    r2 += r15;
L_8c078338: /* c9f0 */
    r0 &= 0xf0u;
L_8c07833a: /* 2202 */
    c_wr32(ram, r2, r0);
L_8c07833c: /* 9035 */
    r0 = (uint32_t)(int32_t)(int16_t)0x08b0; /* @(0x8c0783aa,pc) */
L_8c07833e: /* 9134 */
    r1 = (uint32_t)(int32_t)(int16_t)0x08b0; /* @(0x8c0783aa,pc) */
L_8c078340: /* 00fe */
    r0 = c_p32(ram, (r15 + r0), &gated);
L_8c078342: /* 31fc */
    r1 += r15;
L_8c078344: /* c9f0 */
    r0 &= 0xf0u;
L_8c078346: /* 2102 */
    c_wr32(ram, r1, r0);
L_8c078348: /* 61f3 */
    r1 = r15;
L_8c07834a: /* 902f */
    r0 = (uint32_t)(int32_t)(int16_t)0x1bb6; /* @(0x8c0783ac,pc) */
L_8c07834c: /* 7160 */
    r1 += 96u;
L_8c07834e: /* 03ec */
    r3 = (uint32_t)(int32_t)c_p8s(ram, (r14 + r0), &gated);
L_8c078350: /* e060 */
    r0 = (uint32_t)(int32_t)96;
L_8c078352: /* 633c */
    r3 = r3 & 0xFFu;
L_8c078354: /* 0f36 */
    c_wr32(ram, (r15 + r0), r3);
L_8c078356: /* e064 */
    r0 = (uint32_t)(int32_t)100;
L_8c078358: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c07835a: /* 3238 */
    r2 -= r3;
L_8c07835c: /* 6023 */
    r0 = r2;
L_8c07835e: /* c93f */
    r0 &= 0x3fu;
L_8c078360: /* 2102 */
    c_wr32(ram, r1, r0);
L_8c078362: /* 9021 */
    r0 = (uint32_t)(int32_t)(int16_t)0x08ac; /* @(0x8c0783a8,pc) */
L_8c078364: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c078366: /* e058 */
    r0 = (uint32_t)(int32_t)88;
L_8c078368: /* 0f36 */
    c_wr32(ram, (r15 + r0), r3);
L_8c07836a: /* e05c */
    r0 = (uint32_t)(int32_t)92;
L_8c07836c: /* e200 */
    r2 = (uint32_t)(int32_t)0;
L_8c07836e: /* 0f26 */
    c_wr32(ram, (r15 + r0), r2);
L_8c078370: /* e054 */
    r0 = (uint32_t)(int32_t)84;
L_8c078372: /* 6323 */
    r3 = r2;
L_8c078374: /* 0f36 */
    c_wr32(ram, (r15 + r0), r3);
L_8c078376: /* 901a */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c0783ae,pc) */
L_8c078378: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c07837a: /* e050 */
    r0 = (uint32_t)(int32_t)80;
L_8c07837c: /* 6320 */
    r3 = (uint32_t)(int32_t)c_p8s(ram, r2, &gated);
L_8c07837e: /* 633c */
    r3 = r3 & 0xFFu;
L_8c078380: /* 0f36 */
    c_wr32(ram, (r15 + r0), r3);
L_8c078382: /* 6033 */
    r0 = r3;
L_8c078384: /* e157 */
    r1 = (uint32_t)(int32_t)87;
L_8c078386: /* 3012 */
    T = (r0 >= r1);
L_8c078388: /* 8b01 */
    if (!T) goto L_8c07838e;
    o->gated = 903; return;
L_8c07838e: /* 4000 */
    T = (r0 >> 31) & 1u; r0 <<= 1;
L_8c078390: /* 6103 */
    r1 = r0;
L_8c078392: /* c707 */
    r0 = 0x8c0783b0; /* mova */
L_8c078394: /* 001d */
    r0 = (uint32_t)(int32_t)c_p16(ram, (r1 + r0), &gated);
L_8c078396: /* 0023 */
    /* nop */;
    switch (r0 & 0xFFFFu) {
    case 0xc4: goto L_8c07845e;
    case 0xce: goto L_8c078468;
    case 0x120: goto L_8c0784ba;
    case 0x124: goto L_8c0784be;
    case 0x128: goto L_8c0784c2;
    case 0x130: goto L_8c0784ca;
    case 0x138: goto L_8c0784d2;
    case 0x152: goto L_8c0784ec;
    case 0x270: goto L_8c07860a;
    case 0x2d4: goto L_8c07866e;
    case 0x326: goto L_8c0786c0;
    case 0x342: goto L_8c0786dc;
    case 0x382: goto L_8c07871c;
    case 0x38a: goto L_8c078724;
    case 0x392: goto L_8c07872c;
    case 0x396: goto L_8c078730;
    case 0x39a: goto L_8c078734;
    case 0x3a6: goto L_8c078740;
    case 0x3c2: goto L_8c07875c;
    default: o->gated = 901; return;
    }
L_8c07845e: /* d24e */
    r2 = 0x0c07a74e; /* @(0x8c078598,pc) */
L_8c078460: /* 422b */
    /* nop */;
    if ((r2 | 0x80000000u) == 0x8c07a74eu) goto L_8c07a74e;
    o->gated = 902; return;
L_8c078468: /* a22a */
    /* nop */;
    goto L_8c0788c0;
L_8c0784ba: /* a22a */
    /* nop */;
    goto L_8c078912;
L_8c0784be: /* a297 */
    /* nop */;
    goto L_8c0789f0;
L_8c0784c2: /* a2de */
    /* nop */;
    goto L_8c078a82;
L_8c0784ca: /* a346 */
    /* nop */;
    goto L_8c078b5a;
L_8c0784d2: /* 905e */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078592,pc) */
L_8c0784d4: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c0784d6: /* e060 */
    r0 = (uint32_t)(int32_t)96;
L_8c0784d8: /* 7301 */
    r3 += 1u;
L_8c0784da: /* 6230 */
    r2 = (uint32_t)(int32_t)c_p8s(ram, r3, &gated);
L_8c0784dc: /* 622c */
    r2 = r2 & 0xFFu;
L_8c0784de: /* 0f26 */
    c_wr32(ram, (r15 + r0), r2);
L_8c0784e0: /* 9057 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078592,pc) */
L_8c0784e2: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c0784e4: /* 9055 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078592,pc) */
L_8c0784e6: /* 7302 */
    r3 += 2u;
L_8c0784e8: /* af45 */
    c_wr32(ram, (r15 + r0), r3);
    goto L_8c078376;
L_8c0784ec: /* e068 */
    r0 = (uint32_t)(int32_t)104;
L_8c0784ee: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c0784f0: /* e068 */
    r0 = (uint32_t)(int32_t)104;
L_8c0784f2: /* 72e0 */
    r2 -= 32u;
L_8c0784f4: /* 0f26 */
    c_wr32(ram, (r15 + r0), r2);
L_8c0784f6: /* 904d */
    r0 = (uint32_t)(int32_t)(int16_t)0x08ac; /* @(0x8c078594,pc) */
L_8c0784f8: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c0784fa: /* e068 */
    r0 = (uint32_t)(int32_t)104;
L_8c0784fc: /* 1231 */
    c_wr32(ram, r2 + 4, r3);
L_8c0784fe: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c078500: /* 9049 */
    r0 = (uint32_t)(int32_t)(int16_t)0x08b0; /* @(0x8c078596,pc) */
L_8c078502: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c078504: /* e068 */
    r0 = (uint32_t)(int32_t)104;
L_8c078506: /* 2232 */
    c_wr32(ram, r2, r3);
L_8c078508: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c07850a: /* e058 */
    r0 = (uint32_t)(int32_t)88;
L_8c07850c: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c07850e: /* e068 */
    r0 = (uint32_t)(int32_t)104;
L_8c078510: /* 7208 */
    r2 += 8u;
L_8c078512: /* 2232 */
    c_wr32(ram, r2, r3);
L_8c078514: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c078516: /* e064 */
    r0 = (uint32_t)(int32_t)100;
L_8c078518: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c07851a: /* e068 */
    r0 = (uint32_t)(int32_t)104;
L_8c07851c: /* 720c */
    r2 += 12u;
L_8c07851e: /* 2232 */
    c_wr32(ram, r2, r3);
L_8c078520: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c078522: /* e054 */
    r0 = (uint32_t)(int32_t)84;
L_8c078524: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c078526: /* e068 */
    r0 = (uint32_t)(int32_t)104;
L_8c078528: /* 7210 */
    r2 += 16u;
L_8c07852a: /* 2232 */
    c_wr32(ram, r2, r3);
L_8c07852c: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c07852e: /* e05c */
    r0 = (uint32_t)(int32_t)92;
L_8c078530: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c078532: /* e068 */
    r0 = (uint32_t)(int32_t)104;
L_8c078534: /* 7214 */
    r2 += 20u;
L_8c078536: /* 2232 */
    c_wr32(ram, r2, r3);
L_8c078538: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c07853a: /* 902a */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078592,pc) */
L_8c07853c: /* 7218 */
    r2 += 24u;
L_8c07853e: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c078540: /* 9027 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078592,pc) */
L_8c078542: /* 7304 */
    r3 += 4u;
L_8c078544: /* 6130 */
    r1 = (uint32_t)(int32_t)c_p8s(ram, r3, &gated);
L_8c078546: /* 00fe */
    r0 = c_p32(ram, (r15 + r0), &gated);
L_8c078548: /* 611c */
    r1 = r1 & 0xFFu;
L_8c07854a: /* d314 */
    r3 = 0xff000000; /* @(0x8c07859c,pc) */
L_8c07854c: /* 8403 */
    r0 = (uint32_t)(int32_t)c_p8s(ram, r0 + 3, &gated);
L_8c07854e: /* 4128 */
    r1 <<= 16;
L_8c078550: /* 4118 */
    r1 <<= 8;
L_8c078552: /* 600c */
    r0 = r0 & 0xFFu;
L_8c078554: /* 2139 */
    r1 &= r3;
L_8c078556: /* 4028 */
    r0 <<= 16;
L_8c078558: /* 4319 */
    r3 >>= 8;
L_8c07855a: /* 2039 */
    r0 &= r3;
L_8c07855c: /* 210b */
    r1 |= r0;
L_8c07855e: /* 9018 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078592,pc) */
L_8c078560: /* 4319 */
    r3 >>= 8;
L_8c078562: /* 00fe */
    r0 = c_p32(ram, (r15 + r0), &gated);
L_8c078564: /* 8402 */
    r0 = (uint32_t)(int32_t)c_p8s(ram, r0 + 2, &gated);
L_8c078566: /* 600c */
    r0 = r0 & 0xFFu;
L_8c078568: /* 4018 */
    r0 <<= 8;
L_8c07856a: /* 2039 */
    r0 &= r3;
L_8c07856c: /* 210b */
    r1 |= r0;
L_8c07856e: /* 9010 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078592,pc) */
L_8c078570: /* 00fe */
    r0 = c_p32(ram, (r15 + r0), &gated);
L_8c078572: /* 8401 */
    r0 = (uint32_t)(int32_t)c_p8s(ram, r0 + 1, &gated);
L_8c078574: /* 600c */
    r0 = r0 & 0xFFu;
L_8c078576: /* 210b */
    r1 |= r0;
L_8c078578: /* e068 */
    r0 = (uint32_t)(int32_t)104;
L_8c07857a: /* 2212 */
    c_wr32(ram, r2, r1);
L_8c07857c: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c07857e: /* e060 */
    r0 = (uint32_t)(int32_t)96;
L_8c078580: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c078582: /* 721c */
    r2 += 28u;
L_8c078584: /* 2212 */
    c_wr32(ram, r2, r1);
L_8c078586: /* 9004 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078592,pc) */
L_8c078588: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c07858a: /* 9002 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078592,pc) */
L_8c07858c: /* 7205 */
    r2 += 5u;
L_8c07858e: /* aef2 */
    c_wr32(ram, (r15 + r0), r2);
    goto L_8c078376;
L_8c07860a: /* e068 */
    r0 = (uint32_t)(int32_t)104;
L_8c07860c: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c07860e: /* e068 */
    r0 = (uint32_t)(int32_t)104;
L_8c078610: /* 71e0 */
    r1 -= 32u;
L_8c078612: /* 0f16 */
    c_wr32(ram, (r15 + r0), r1);
L_8c078614: /* 9070 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c0786f8,pc) */
L_8c078616: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c078618: /* 906e */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c0786f8,pc) */
L_8c07861a: /* 7304 */
    r3 += 4u;
L_8c07861c: /* 6230 */
    r2 = (uint32_t)(int32_t)c_p8s(ram, r3, &gated);
L_8c07861e: /* 00fe */
    r0 = c_p32(ram, (r15 + r0), &gated);
L_8c078620: /* 622c */
    r2 = r2 & 0xFFu;
L_8c078622: /* d336 */
    r3 = 0xff000000; /* @(0x8c0786fc,pc) */
L_8c078624: /* 4228 */
    r2 <<= 16;
L_8c078626: /* 4218 */
    r2 <<= 8;
L_8c078628: /* 7003 */
    r0 += 3u;
L_8c07862a: /* 2239 */
    r2 &= r3;
L_8c07862c: /* 6300 */
    r3 = (uint32_t)(int32_t)c_p8s(ram, r0, &gated);
L_8c07862e: /* d034 */
    r0 = 0x00ff0000; /* @(0x8c078700,pc) */
L_8c078630: /* 633c */
    r3 = r3 & 0xFFu;
L_8c078632: /* 4328 */
    r3 <<= 16;
L_8c078634: /* 2309 */
    r3 &= r0;
L_8c078636: /* 905f */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c0786f8,pc) */
L_8c078638: /* 223b */
    r2 |= r3;
L_8c07863a: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c07863c: /* d031 */
    r0 = 0x0000ff00; /* @(0x8c078704,pc) */
L_8c07863e: /* 7302 */
    r3 += 2u;
L_8c078640: /* 6330 */
    r3 = (uint32_t)(int32_t)c_p8s(ram, r3, &gated);
L_8c078642: /* 633c */
    r3 = r3 & 0xFFu;
L_8c078644: /* 4318 */
    r3 <<= 8;
L_8c078646: /* 2309 */
    r3 &= r0;
L_8c078648: /* 223b */
    r2 |= r3;
L_8c07864a: /* 9055 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c0786f8,pc) */
L_8c07864c: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c07864e: /* e068 */
    r0 = (uint32_t)(int32_t)104;
L_8c078650: /* 7301 */
    r3 += 1u;
L_8c078652: /* 6330 */
    r3 = (uint32_t)(int32_t)c_p8s(ram, r3, &gated);
L_8c078654: /* 633c */
    r3 = r3 & 0xFFu;
L_8c078656: /* 223b */
    r2 |= r3;
L_8c078658: /* 1126 */
    c_wr32(ram, r1 + 24, r2);
L_8c07865a: /* e301 */
    r3 = (uint32_t)(int32_t)1;
L_8c07865c: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c07865e: /* 711e */
    r1 += 30u;
L_8c078660: /* 2131 */
    c_wr16(ram, r1, (uint16_t)r3);
L_8c078662: /* 9049 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c0786f8,pc) */
L_8c078664: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c078666: /* 9047 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c0786f8,pc) */
L_8c078668: /* 7205 */
    r2 += 5u;
L_8c07866a: /* ae84 */
    c_wr32(ram, (r15 + r0), r2);
    goto L_8c078376;
L_8c07866e: /* 9043 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c0786f8,pc) */
L_8c078670: /* d222 */
    r2 = 0xff000000; /* @(0x8c0786fc,pc) */
L_8c078672: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c078674: /* 9040 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c0786f8,pc) */
L_8c078676: /* 7104 */
    r1 += 4u;
L_8c078678: /* 6310 */
    r3 = (uint32_t)(int32_t)c_p8s(ram, r1, &gated);
L_8c07867a: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c07867c: /* d020 */
    r0 = 0x00ff0000; /* @(0x8c078700,pc) */
L_8c07867e: /* 633c */
    r3 = r3 & 0xFFu;
L_8c078680: /* 7103 */
    r1 += 3u;
L_8c078682: /* 6110 */
    r1 = (uint32_t)(int32_t)c_p8s(ram, r1, &gated);
L_8c078684: /* 4328 */
    r3 <<= 16;
L_8c078686: /* 4318 */
    r3 <<= 8;
L_8c078688: /* 611c */
    r1 = r1 & 0xFFu;
L_8c07868a: /* 4128 */
    r1 <<= 16;
L_8c07868c: /* 2109 */
    r1 &= r0;
L_8c07868e: /* 9033 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c0786f8,pc) */
L_8c078690: /* 2329 */
    r3 &= r2;
L_8c078692: /* 231b */
    r3 |= r1;
L_8c078694: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c078696: /* d01b */
    r0 = 0x0000ff00; /* @(0x8c078704,pc) */
L_8c078698: /* 7102 */
    r1 += 2u;
L_8c07869a: /* 6110 */
    r1 = (uint32_t)(int32_t)c_p8s(ram, r1, &gated);
L_8c07869c: /* 611c */
    r1 = r1 & 0xFFu;
L_8c07869e: /* 4118 */
    r1 <<= 8;
L_8c0786a0: /* 2109 */
    r1 &= r0;
L_8c0786a2: /* 9029 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c0786f8,pc) */
L_8c0786a4: /* 231b */
    r3 |= r1;
L_8c0786a6: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c0786a8: /* 7101 */
    r1 += 1u;
L_8c0786aa: /* 6110 */
    r1 = (uint32_t)(int32_t)c_p8s(ram, r1, &gated);
L_8c0786ac: /* 611c */
    r1 = r1 & 0xFFu;
L_8c0786ae: /* 9024 */
    r0 = (uint32_t)(int32_t)(int16_t)0x1b98; /* @(0x8c0786fa,pc) */
L_8c0786b0: /* 231b */
    r3 |= r1;
L_8c0786b2: /* 0e36 */
    c_wr32(ram, (r14 + r0), r3);
L_8c0786b4: /* 9020 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c0786f8,pc) */
L_8c0786b6: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c0786b8: /* 901e */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c0786f8,pc) */
L_8c0786ba: /* 7105 */
    r1 += 5u;
L_8c0786bc: /* ae5b */
    c_wr32(ram, (r15 + r0), r1);
    goto L_8c078376;
L_8c0786c0: /* a2c6 */
    /* nop */;
    goto L_8c078c50;
L_8c0786dc: /* a3d3 */
    /* nop */;
    goto L_8c078e86;
L_8c07871c: /* a51d */
    /* nop */;
    goto L_8c07915a;
L_8c078724: /* a5b8 */
    /* nop */;
    goto L_8c079298;
L_8c07872c: /* a62c */
    /* nop */;
    goto L_8c079388;
L_8c078730: /* a658 */
    /* nop */;
    goto L_8c0793e4;
L_8c078734: /* a66b */
    /* nop */;
    goto L_8c07940e;
L_8c078740: /* a6a4 */
    /* nop */;
    goto L_8c07948c;
L_8c07875c: /* a79c */
    /* nop */;
    goto L_8c079698;
L_8c0788c0: /* 9058 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078974,pc) */
L_8c0788c2: /* d241 */
    r2 = 0xff000000; /* @(0x8c0789c8,pc) */
L_8c0788c4: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c0788c6: /* 9055 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078974,pc) */
L_8c0788c8: /* 7104 */
    r1 += 4u;
L_8c0788ca: /* 6310 */
    r3 = (uint32_t)(int32_t)c_p8s(ram, r1, &gated);
L_8c0788cc: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c0788ce: /* d03f */
    r0 = 0x00ff0000; /* @(0x8c0789cc,pc) */
L_8c0788d0: /* 633c */
    r3 = r3 & 0xFFu;
L_8c0788d2: /* 7103 */
    r1 += 3u;
L_8c0788d4: /* 6110 */
    r1 = (uint32_t)(int32_t)c_p8s(ram, r1, &gated);
L_8c0788d6: /* 4328 */
    r3 <<= 16;
L_8c0788d8: /* 4318 */
    r3 <<= 8;
L_8c0788da: /* 611c */
    r1 = r1 & 0xFFu;
L_8c0788dc: /* 4128 */
    r1 <<= 16;
L_8c0788de: /* 2109 */
    r1 &= r0;
L_8c0788e0: /* 9048 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078974,pc) */
L_8c0788e2: /* 2329 */
    r3 &= r2;
L_8c0788e4: /* 231b */
    r3 |= r1;
L_8c0788e6: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c0788e8: /* d039 */
    r0 = 0x0000ff00; /* @(0x8c0789d0,pc) */
L_8c0788ea: /* 7102 */
    r1 += 2u;
L_8c0788ec: /* 6110 */
    r1 = (uint32_t)(int32_t)c_p8s(ram, r1, &gated);
L_8c0788ee: /* 611c */
    r1 = r1 & 0xFFu;
L_8c0788f0: /* 4118 */
    r1 <<= 8;
L_8c0788f2: /* 2109 */
    r1 &= r0;
L_8c0788f4: /* 903e */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078974,pc) */
L_8c0788f6: /* 231b */
    r3 |= r1;
L_8c0788f8: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c0788fa: /* 7101 */
    r1 += 1u;
L_8c0788fc: /* 6110 */
    r1 = (uint32_t)(int32_t)c_p8s(ram, r1, &gated);
L_8c0788fe: /* 611c */
    r1 = r1 & 0xFFu;
L_8c078900: /* 231b */
    r3 |= r1;
L_8c078902: /* 6133 */
    r1 = r3;
L_8c078904: /* 1f38 */
    c_wr32(ram, r15 + 32, r3);
L_8c078906: /* 1e3c */
    c_wr32(ram, r14 + 48, r3);
L_8c078908: /* d232 */
    r2 = 0x0c07a75a; /* @(0x8c0789d4,pc) */
L_8c07890a: /* e300 */
    r3 = (uint32_t)(int32_t)0;
L_8c07890c: /* 9033 */
    r0 = (uint32_t)(int32_t)(int16_t)0x1b90; /* @(0x8c078976,pc) */
L_8c07890e: /* 422b */
    c_wr16(ram, (r14 + r0), (uint16_t)r3);
    if ((r2 | 0x80000000u) == 0x8c07a75au) goto L_8c07a75a;
    o->gated = 902; return;
L_8c078912: /* 902f */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078974,pc) */
L_8c078914: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c078916: /* 902d */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078974,pc) */
L_8c078918: /* 7202 */
    r2 += 2u;
L_8c07891a: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
    if (bpath && ++c891a == 10 && c5de <= 10) {
        c_wr32(ram, r15 - 4, r0); c_wr32(ram, r15 - 8, r1);
    }
L_8c07891c: /* 6320 */
    r3 = (uint32_t)(int32_t)c_p8s(ram, r2, &gated);
L_8c07891e: /* 7101 */
    r1 += 1u;
L_8c078920: /* d22b */
    r2 = 0x0000ff00; /* @(0x8c0789d0,pc) */
L_8c078922: /* 6110 */
    r1 = (uint32_t)(int32_t)c_p8s(ram, r1, &gated);
L_8c078924: /* 633c */
    r3 = r3 & 0xFFu;
L_8c078926: /* 4318 */
    r3 <<= 8;
L_8c078928: /* 611c */
    r1 = r1 & 0xFFu;
L_8c07892a: /* 2329 */
    r3 &= r2;
L_8c07892c: /* 231b */
    r3 |= r1;
L_8c07892e: /* 1f33 */
    c_wr32(ram, r15 + 12, r3);
L_8c078930: /* 633c */
    r3 = r3 & 0xFFu;
L_8c078932: /* 1f32 */
    c_wr32(ram, r15 + 8, r3);
L_8c078934: /* 51f3 */
    r1 = c_p32(ram, r15 + 12, &gated);
L_8c078936: /* 931f */
    r3 = (uint32_t)(int32_t)(int16_t)0x0100; /* @(0x8c078978,pc) */
L_8c078938: /* 2138 */
    T = ((r1 & r3) == 0);
L_8c07893a: /* 8904 */
    if (T) goto L_8c078946; else goto L_8c07893c;
L_8c07893c: /* 901d */
    r0 = (uint32_t)(int32_t)(int16_t)0x08a8; /* @(0x8c07897a,pc) */
L_8c07893e: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c078940: /* 50f2 */
    r0 = c_p32(ram, r15 + 8, &gated);
L_8c078942: /* 201b */
    r0 |= r1;
L_8c078944: /* 1f02 */
    c_wr32(ram, r15 + 8, r0);
L_8c078946: /* 52f3 */
    r2 = c_p32(ram, r15 + 12, &gated);
L_8c078948: /* 9318 */
    r3 = (uint32_t)(int32_t)(int16_t)0x0200; /* @(0x8c07897c,pc) */
L_8c07894a: /* 2238 */
    T = ((r2 & r3) == 0);
L_8c07894c: /* 8904 */
    if (T) goto L_8c078958; else goto L_8c07894e;
L_8c07894e: /* 9016 */
    r0 = (uint32_t)(int32_t)(int16_t)0x08a4; /* @(0x8c07897e,pc) */
L_8c078950: /* 51f2 */
    r1 = c_p32(ram, r15 + 8, &gated);
L_8c078952: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c078954: /* 212b */
    r1 |= r2;
L_8c078956: /* 1f12 */
    c_wr32(ram, r15 + 8, r1);
L_8c078958: /* 9012 */
    r0 = (uint32_t)(int32_t)(int16_t)0x08ac; /* @(0x8c078980,pc) */
L_8c07895a: /* 53f2 */
    r3 = c_p32(ram, r15 + 8, &gated);
L_8c07895c: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c07895e: /* 3230 */
    T = (r2 == r3);
L_8c078960: /* 8b3a */
    if (!T) goto L_8c0789d8; else goto L_8c078962;
L_8c078962: /* 900d */
    r0 = (uint32_t)(int32_t)(int16_t)0x08ac; /* @(0x8c078980,pc) */
L_8c078964: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c078966: /* e058 */
    r0 = (uint32_t)(int32_t)88;
L_8c078968: /* 0f26 */
    c_wr32(ram, (r15 + r0), r2);
L_8c07896a: /* 9003 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078974,pc) */
L_8c07896c: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c07896e: /* a0aa */
    r1 += 3u;
    goto L_8c078ac6;
L_8c0789d8: /* e058 */
    r0 = (uint32_t)(int32_t)88;
L_8c0789da: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c0789dc: /* 9082 */
    r0 = (uint32_t)(int32_t)(int16_t)0x08ac; /* @(0x8c078ae4,pc) */
L_8c0789de: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c0789e0: /* 3230 */
    T = (r2 == r3);
L_8c0789e2: /* 8b02 */
    if (!T) goto L_8c0789ea; else goto L_8c0789e4;
L_8c0789e4: /* d142 */
    r1 = 0x0c07a5cc; /* @(0x8c078af0,pc) */
L_8c0789e6: /* 412b */
    /* nop */;
    if ((r1 | 0x80000000u) == 0x8c07a5ccu) goto L_8c07a5cc;
    o->gated = 902; return;
L_8c0789ea: /* d142 */
    r1 = 0x0c07a51a; /* @(0x8c078af4,pc) */
L_8c0789ec: /* 412b */
    /* nop */;
    if ((r1 | 0x80000000u) == 0x8c07a51au) goto L_8c07a51a;
    o->gated = 902; return;
L_8c0789f0: /* 9079 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078ae6,pc) */
L_8c0789f2: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c0789f4: /* 9077 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078ae6,pc) */
L_8c0789f6: /* 7302 */
    r3 += 2u;
L_8c0789f8: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c0789fa: /* e054 */
    r0 = (uint32_t)(int32_t)84;
L_8c0789fc: /* 6230 */
    r2 = (uint32_t)(int32_t)c_p8s(ram, r3, &gated);
L_8c0789fe: /* 7101 */
    r1 += 1u;
L_8c078a00: /* d33d */
    r3 = 0x0000ff00; /* @(0x8c078af8,pc) */
L_8c078a02: /* 622c */
    r2 = r2 & 0xFFu;
L_8c078a04: /* 6110 */
    r1 = (uint32_t)(int32_t)c_p8s(ram, r1, &gated);
L_8c078a06: /* 4218 */
    r2 <<= 8;
L_8c078a08: /* 611c */
    r1 = r1 & 0xFFu;
L_8c078a0a: /* 2239 */
    r2 &= r3;
L_8c078a0c: /* 221b */
    r2 |= r1;
L_8c078a0e: /* 1f27 */
    c_wr32(ram, r15 + 28, r2);
L_8c078a10: /* 622c */
    r2 = r2 & 0xFFu;
L_8c078a12: /* 0f26 */
    c_wr32(ram, (r15 + r0), r2);
L_8c078a14: /* 51f7 */
    r1 = c_p32(ram, r15 + 28, &gated);
L_8c078a16: /* 9267 */
    r2 = (uint32_t)(int32_t)(int16_t)0x0100; /* @(0x8c078ae8,pc) */
L_8c078a18: /* 2128 */
    T = ((r1 & r2) == 0);
L_8c078a1a: /* 8907 */
    if (T) goto L_8c078a2c; else goto L_8c078a1c;
L_8c078a1c: /* 9065 */
    r0 = (uint32_t)(int32_t)(int16_t)0x08a8; /* @(0x8c078aea,pc) */
L_8c078a1e: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c078a20: /* e054 */
    r0 = (uint32_t)(int32_t)84;
L_8c078a22: /* 00fe */
    r0 = c_p32(ram, (r15 + r0), &gated);
L_8c078a24: /* 201b */
    r0 |= r1;
L_8c078a26: /* 61f3 */
    r1 = r15;
L_8c078a28: /* 7154 */
    r1 += 84u;
L_8c078a2a: /* 2102 */
    c_wr32(ram, r1, r0);
L_8c078a2c: /* 52f7 */
    r2 = c_p32(ram, r15 + 28, &gated);
L_8c078a2e: /* 935d */
    r3 = (uint32_t)(int32_t)(int16_t)0x0200; /* @(0x8c078aec,pc) */
L_8c078a30: /* 2238 */
    T = ((r2 & r3) == 0);
L_8c078a32: /* 8906 */
    if (T) goto L_8c078a42; else goto L_8c078a34;
L_8c078a34: /* 905b */
    r0 = (uint32_t)(int32_t)(int16_t)0x08a4; /* @(0x8c078aee,pc) */
L_8c078a36: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c078a38: /* e054 */
    r0 = (uint32_t)(int32_t)84;
L_8c078a3a: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c078a3c: /* e054 */
    r0 = (uint32_t)(int32_t)84;
L_8c078a3e: /* 212b */
    r1 |= r2;
L_8c078a40: /* 0f16 */
    c_wr32(ram, (r15 + r0), r1);
L_8c078a42: /* 9050 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078ae6,pc) */
L_8c078a44: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c078a46: /* e05c */
    r0 = (uint32_t)(int32_t)92;
L_8c078a48: /* 7303 */
    r3 += 3u;
L_8c078a4a: /* 6230 */
    r2 = (uint32_t)(int32_t)c_p8s(ram, r3, &gated);
L_8c078a4c: /* 622c */
    r2 = r2 & 0xFFu;
L_8c078a4e: /* 0f26 */
    c_wr32(ram, (r15 + r0), r2);
L_8c078a50: /* 9049 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078ae6,pc) */
L_8c078a52: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c078a54: /* 9047 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078ae6,pc) */
L_8c078a56: /* 7304 */
    r3 += 4u;
L_8c078a58: /* 0f36 */
    c_wr32(ram, (r15 + r0), r3);
L_8c078a5a: /* e058 */
    r0 = (uint32_t)(int32_t)88;
L_8c078a5c: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c078a5e: /* 9041 */
    r0 = (uint32_t)(int32_t)(int16_t)0x08ac; /* @(0x8c078ae4,pc) */
L_8c078a60: /* 00fe */
    r0 = c_p32(ram, (r15 + r0), &gated);
L_8c078a62: /* 3010 */
    T = (r0 == r1);
L_8c078a64: /* 8b01 */
    if (!T) { o->gated = 904; return; }
    goto L_8c078a66;
L_8c078a66: /* ac86 */
    /* nop */;
    goto L_8c078376;
L_8c078a82: /* 9030 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078ae6,pc) */
L_8c078a84: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c078a86: /* 7301 */
    r3 += 1u;
L_8c078a88: /* 6230 */
    r2 = (uint32_t)(int32_t)c_p8s(ram, r3, &gated);
L_8c078a8a: /* 622c */
    r2 = r2 & 0xFFu;
L_8c078a8c: /* 1f23 */
    c_wr32(ram, r15 + 12, r2);
L_8c078a8e: /* 902c */
    r0 = (uint32_t)(int32_t)(int16_t)0x08a8; /* @(0x8c078aea,pc) */
L_8c078a90: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c078a92: /* 6023 */
    r0 = r2;
L_8c078a94: /* 8817 */
    T = (r0 == (uint32_t)(int32_t)23);
L_8c078a96: /* 1f32 */
    c_wr32(ram, r15 + 8, r3);
L_8c078a98: /* 8909 */
    if (T) { o->gated = 904; return; }
    goto L_8c078a9a;
L_8c078a9a: /* 9028 */
    r0 = (uint32_t)(int32_t)(int16_t)0x08a4; /* @(0x8c078aee,pc) */
L_8c078a9c: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c078a9e: /* 1f32 */
    c_wr32(ram, r15 + 8, r3);
L_8c078aa0: /* 50f3 */
    r0 = c_p32(ram, r15 + 12, &gated);
L_8c078aa2: /* 8816 */
    T = (r0 == (uint32_t)(int32_t)22);
L_8c078aa4: /* 8903 */
    if (T) { o->gated = 904; return; }
    goto L_8c078aa6;
L_8c078aa6: /* 53f3 */
    r3 = c_p32(ram, r15 + 12, &gated);
L_8c078aa8: /* e201 */
    r2 = (uint32_t)(int32_t)1;
L_8c078aaa: /* 423c */
    { int32_t sh = (int32_t)r3; int32_t v = (int32_t)r2; int32_t rr = (sh >= 0 ? (sh < 32 ? (v << sh) : 0) : (-sh < 32 ? (v >> (-sh)) : (v >= 0 ? 0 : -1))); r2 = (uint32_t)rr; }
L_8c078aac: /* 1f22 */
    c_wr32(ram, r15 + 8, r2);
L_8c078aae: /* 9019 */
    r0 = (uint32_t)(int32_t)(int16_t)0x08ac; /* @(0x8c078ae4,pc) */
L_8c078ab0: /* 53f2 */
    r3 = c_p32(ram, r15 + 8, &gated);
L_8c078ab2: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c078ab4: /* 2138 */
    T = ((r1 & r3) == 0);
L_8c078ab6: /* 8909 */
    if (T) goto L_8c078acc;
    o->gated = 903; return;
L_8c078ac6: /* 900e */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078ae6,pc) */
L_8c078ac8: /* ac4f */
    c_wr32(ram, (r15 + r0), r1);
    goto L_8c07836a;
L_8c078acc: /* e058 */
    r0 = (uint32_t)(int32_t)88;
L_8c078ace: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c078ad0: /* 9008 */
    r0 = (uint32_t)(int32_t)(int16_t)0x08ac; /* @(0x8c078ae4,pc) */
L_8c078ad2: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c078ad4: /* 3230 */
    T = (r2 == r3);
L_8c078ad6: /* 8b02 */
    if (!T) goto L_8c078ade; else goto L_8c078ad8;
L_8c078ad8: /* d105 */
    r1 = 0x0c07a5cc; /* @(0x8c078af0,pc) */
L_8c078ada: /* 412b */
    /* nop */;
    if ((r1 | 0x80000000u) == 0x8c07a5ccu) goto L_8c07a5cc;
    o->gated = 902; return;
L_8c078ade: /* d105 */
    r1 = 0x0c07a51a; /* @(0x8c078af4,pc) */
L_8c078ae0: /* 412b */
    /* nop */;
    if ((r1 | 0x80000000u) == 0x8c07a51au) goto L_8c07a51a;
    o->gated = 902; return;
L_8c078b5a: /* 9045 */
    r0 = (uint32_t)(int32_t)(int16_t)0x08b0; /* @(0x8c078be8,pc) */
L_8c078b5c: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c078b5e: /* 2338 */
    T = ((r3 & r3) == 0);
L_8c078b60: /* 8b02 */
    if (!T) goto L_8c078b68; else goto L_8c078b62;
L_8c078b62: /* d323 */
    r3 = 0x0c07a5cc; /* @(0x8c078bf0,pc) */
L_8c078b64: /* 432b */
    /* nop */;
    if ((r3 | 0x80000000u) == 0x8c07a5ccu) goto L_8c07a5cc;
    o->gated = 902; return;
L_8c078b68: /* 903a */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078be0,pc) */
L_8c078b6a: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c078b6c: /* 9038 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078be0,pc) */
L_8c078b6e: /* 7302 */
    r3 += 2u;
L_8c078b70: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c078b72: /* 6230 */
    r2 = (uint32_t)(int32_t)c_p8s(ram, r3, &gated);
L_8c078b74: /* 7101 */
    r1 += 1u;
L_8c078b76: /* d320 */
    r3 = 0x0000ff00; /* @(0x8c078bf8,pc) */
L_8c078b78: /* 6110 */
    r1 = (uint32_t)(int32_t)c_p8s(ram, r1, &gated);
L_8c078b7a: /* 622c */
    r2 = r2 & 0xFFu;
L_8c078b7c: /* 4218 */
    r2 <<= 8;
L_8c078b7e: /* 611c */
    r1 = r1 & 0xFFu;
L_8c078b80: /* 2239 */
    r2 &= r3;
L_8c078b82: /* 221b */
    r2 |= r1;
L_8c078b84: /* 1f27 */
    c_wr32(ram, r15 + 28, r2);
L_8c078b86: /* 622c */
    r2 = r2 & 0xFFu;
L_8c078b88: /* 1f23 */
    c_wr32(ram, r15 + 12, r2);
L_8c078b8a: /* 51f7 */
    r1 = c_p32(ram, r15 + 28, &gated);
L_8c078b8c: /* 922d */
    r2 = (uint32_t)(int32_t)(int16_t)0x0100; /* @(0x8c078bea,pc) */
L_8c078b8e: /* 2128 */
    T = ((r1 & r2) == 0);
L_8c078b90: /* 8904 */
    if (T) goto L_8c078b9c; else goto L_8c078b92;
L_8c078b92: /* 9026 */
    r0 = (uint32_t)(int32_t)(int16_t)0x08a8; /* @(0x8c078be2,pc) */
L_8c078b94: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c078b96: /* 50f3 */
    r0 = c_p32(ram, r15 + 12, &gated);
L_8c078b98: /* 201b */
    r0 |= r1;
L_8c078b9a: /* 1f03 */
    c_wr32(ram, r15 + 12, r0);
L_8c078b9c: /* 52f7 */
    r2 = c_p32(ram, r15 + 28, &gated);
L_8c078b9e: /* 9325 */
    r3 = (uint32_t)(int32_t)(int16_t)0x0200; /* @(0x8c078bec,pc) */
L_8c078ba0: /* 2238 */
    T = ((r2 & r3) == 0);
L_8c078ba2: /* 8904 */
    if (T) goto L_8c078bae; else goto L_8c078ba4;
L_8c078ba4: /* 901e */
    r0 = (uint32_t)(int32_t)(int16_t)0x08a4; /* @(0x8c078be4,pc) */
L_8c078ba6: /* 51f3 */
    r1 = c_p32(ram, r15 + 12, &gated);
L_8c078ba8: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c078baa: /* 212b */
    r1 |= r2;
L_8c078bac: /* 1f13 */
    c_wr32(ram, r15 + 12, r1);
L_8c078bae: /* 901b */
    r0 = (uint32_t)(int32_t)(int16_t)0x08b0; /* @(0x8c078be8,pc) */
L_8c078bb0: /* 53f3 */
    r3 = c_p32(ram, r15 + 12, &gated);
L_8c078bb2: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c078bb4: /* 3230 */
    T = (r2 == r3);
L_8c078bb6: /* 8902 */
    if (T) goto L_8c078bbe; else goto L_8c078bb8;
L_8c078bb8: /* d110 */
    r1 = 0x0c07a6c4; /* @(0x8c078bfc,pc) */
L_8c078bba: /* 412b */
    /* nop */;
    if ((r1 | 0x80000000u) == 0x8c07a6c4u) goto L_8c07a6c4;
    o->gated = 902; return;
L_8c078bbe: /* 9012 */
    r0 = (uint32_t)(int32_t)(int16_t)0x08ac; /* @(0x8c078be6,pc) */
L_8c078bc0: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c078bc2: /* 3230 */
    T = (r2 == r3);
L_8c078bc4: /* 8902 */
    if (T) goto L_8c078bcc;
    o->gated = 903; return;
L_8c078bcc: /* 900b */
    r0 = (uint32_t)(int32_t)(int16_t)0x08ac; /* @(0x8c078be6,pc) */
L_8c078bce: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c078bd0: /* e058 */
    r0 = (uint32_t)(int32_t)88;
L_8c078bd2: /* 0f16 */
    c_wr32(ram, (r15 + r0), r1);
L_8c078bd4: /* 9004 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078be0,pc) */
L_8c078bd6: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c078bd8: /* 9002 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078be0,pc) */
L_8c078bda: /* 7303 */
    r3 += 3u;
L_8c078bdc: /* abc5 */
    c_wr32(ram, (r15 + r0), r3);
    goto L_8c07836a;
L_8c078c50: /* 9037 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078cc2,pc) */
L_8c078c52: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c078c54: /* 9035 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078cc2,pc) */
L_8c078c56: /* 7202 */
    r2 += 2u;
L_8c078c58: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c078c5a: /* 6320 */
    r3 = (uint32_t)(int32_t)c_p8s(ram, r2, &gated);
L_8c078c5c: /* 7101 */
    r1 += 1u;
L_8c078c5e: /* d21d */
    r2 = 0x0000ff00; /* @(0x8c078cd4,pc) */
L_8c078c60: /* 633c */
    r3 = r3 & 0xFFu;
L_8c078c62: /* 6110 */
    r1 = (uint32_t)(int32_t)c_p8s(ram, r1, &gated);
L_8c078c64: /* 4318 */
    r3 <<= 8;
L_8c078c66: /* 611c */
    r1 = r1 & 0xFFu;
L_8c078c68: /* 2329 */
    r3 &= r2;
L_8c078c6a: /* 231b */
    r3 |= r1;
L_8c078c6c: /* 1f3e */
    c_wr32(ram, r15 + 56, r3);
L_8c078c6e: /* 33ec */
    r3 += r14;
L_8c078c70: /* 6131 */
    r1 = (uint32_t)(int32_t)c_p16(ram, r3, &gated);
L_8c078c72: /* 611d */
    r1 = r1 & 0xFFFFu;
L_8c078c74: /* 1f13 */
    c_wr32(ram, r15 + 12, r1);
L_8c078c76: /* 9024 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078cc2,pc) */
L_8c078c78: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c078c7a: /* 9022 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078cc2,pc) */
L_8c078c7c: /* 7304 */
    r3 += 4u;
L_8c078c7e: /* 6130 */
    r1 = (uint32_t)(int32_t)c_p8s(ram, r3, &gated);
L_8c078c80: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c078c82: /* 611c */
    r1 = r1 & 0xFFu;
L_8c078c84: /* 7303 */
    r3 += 3u;
L_8c078c86: /* 6330 */
    r3 = (uint32_t)(int32_t)c_p8s(ram, r3, &gated);
L_8c078c88: /* 4118 */
    r1 <<= 8;
L_8c078c8a: /* 2129 */
    r1 &= r2;
L_8c078c8c: /* 633c */
    r3 = r3 & 0xFFu;
L_8c078c8e: /* 213b */
    r1 |= r3;
L_8c078c90: /* 6313 */
    r3 = r1;
L_8c078c92: /* 1f12 */
    c_wr32(ram, r15 + 8, r1);
L_8c078c94: /* 51f3 */
    r1 = c_p32(ram, r15 + 12, &gated);
L_8c078c96: /* e03e */
    r0 = (uint32_t)(int32_t)62;
L_8c078c98: /* 313c */
    r1 += r3;
L_8c078c9a: /* 1f13 */
    c_wr32(ram, r15 + 12, r1);
L_8c078c9c: /* 03ed */
    r3 = (uint32_t)(int32_t)c_p16(ram, (r14 + r0), &gated);
L_8c078c9e: /* 633d */
    r3 = r3 & 0xFFFFu;
L_8c078ca0: /* 7301 */
    r3 += 1u;
L_8c078ca2: /* 1f31 */
    c_wr32(ram, r15 + 4, r3);
L_8c078ca4: /* 900d */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078cc2,pc) */
L_8c078ca6: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c078ca8: /* 900b */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078cc2,pc) */
L_8c078caa: /* 7105 */
    r1 += 5u;
L_8c078cac: /* 0f16 */
    c_wr32(ram, (r15 + r0), r1);
L_8c078cae: /* 52f3 */
    r2 = c_p32(ram, r15 + 12, &gated);
L_8c078cb0: /* 3322 */
    T = (r3 >= r2);
L_8c078cb2: /* 8b01 */
    if (!T) goto L_8c078cb8;
    o->gated = 903; return;
L_8c078cb8: /* 9008 */
    r0 = (uint32_t)(int32_t)(int16_t)0x1b90; /* @(0x8c078ccc,pc) */
L_8c078cba: /* 53f3 */
    r3 = c_p32(ram, r15 + 12, &gated);
L_8c078cbc: /* 0e35 */
    c_wr16(ram, (r14 + r0), (uint16_t)r3);
L_8c078cbe: /* a069 */
    /* nop */;
    goto L_8c078d94;
L_8c078d94: /* 9040 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078e18,pc) */
L_8c078d96: /* d326 */
    r3 = 0x0c07a75a; /* @(0x8c078e30,pc) */
L_8c078d98: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c078d9a: /* 903f */
    r0 = (uint32_t)(int32_t)(int16_t)0x1b98; /* @(0x8c078e1c,pc) */
L_8c078d9c: /* 432b */
    c_wr32(ram, (r14 + r0), r2);
    if ((r3 | 0x80000000u) == 0x8c07a75au) goto L_8c07a75a;
    o->gated = 902; return;
L_8c078e86: /* 908e */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078fa6,pc) */
L_8c078e88: /* d248 */
    r2 = 0x0000ff00; /* @(0x8c078fac,pc) */
L_8c078e8a: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c078e8c: /* 908b */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078fa6,pc) */
L_8c078e8e: /* 7102 */
    r1 += 2u;
L_8c078e90: /* 6310 */
    r3 = (uint32_t)(int32_t)c_p8s(ram, r1, &gated);
L_8c078e92: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c078e94: /* 633c */
    r3 = r3 & 0xFFu;
L_8c078e96: /* 7101 */
    r1 += 1u;
L_8c078e98: /* 6110 */
    r1 = (uint32_t)(int32_t)c_p8s(ram, r1, &gated);
L_8c078e9a: /* 4318 */
    r3 <<= 8;
L_8c078e9c: /* 2329 */
    r3 &= r2;
L_8c078e9e: /* 611c */
    r1 = r1 & 0xFFu;
L_8c078ea0: /* 231b */
    r3 |= r1;
L_8c078ea2: /* 1f33 */
    c_wr32(ram, r15 + 12, r3);
L_8c078ea4: /* 9080 */
    r0 = (uint32_t)(int32_t)(int16_t)0x088c; /* @(0x8c078fa8,pc) */
L_8c078ea6: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c078ea8: /* 3130 */
    T = (r1 == r3);
L_8c078eaa: /* 8b22 */
    if (!T) goto L_8c078ef2; else goto L_8c078eac;
L_8c078eac: /* 907b */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078fa6,pc) */
L_8c078eae: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c078eb0: /* d041 */
    r0 = 0xff000000; /* @(0x8c078fb8,pc) */
L_8c078eb2: /* 7106 */
    r1 += 6u;
L_8c078eb4: /* 6110 */
    r1 = (uint32_t)(int32_t)c_p8s(ram, r1, &gated);
L_8c078eb6: /* 611c */
    r1 = r1 & 0xFFu;
L_8c078eb8: /* 4128 */
    r1 <<= 16;
L_8c078eba: /* 4118 */
    r1 <<= 8;
L_8c078ebc: /* 2109 */
    r1 &= r0;
L_8c078ebe: /* 9072 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078fa6,pc) */
L_8c078ec0: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c078ec2: /* d03e */
    r0 = 0x00ff0000; /* @(0x8c078fbc,pc) */
L_8c078ec4: /* 7305 */
    r3 += 5u;
L_8c078ec6: /* 6330 */
    r3 = (uint32_t)(int32_t)c_p8s(ram, r3, &gated);
L_8c078ec8: /* 633c */
    r3 = r3 & 0xFFu;
L_8c078eca: /* 4328 */
    r3 <<= 16;
L_8c078ecc: /* 2309 */
    r3 &= r0;
L_8c078ece: /* 906a */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078fa6,pc) */
L_8c078ed0: /* 213b */
    r1 |= r3;
L_8c078ed2: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c078ed4: /* 9067 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078fa6,pc) */
L_8c078ed6: /* 7304 */
    r3 += 4u;
L_8c078ed8: /* 6330 */
    r3 = (uint32_t)(int32_t)c_p8s(ram, r3, &gated);
L_8c078eda: /* 00fe */
    r0 = c_p32(ram, (r15 + r0), &gated);
L_8c078edc: /* 633c */
    r3 = r3 & 0xFFu;
L_8c078ede: /* 4318 */
    r3 <<= 8;
L_8c078ee0: /* 2329 */
    r3 &= r2;
L_8c078ee2: /* 7003 */
    r0 += 3u;
L_8c078ee4: /* 213b */
    r1 |= r3;
L_8c078ee6: /* 6300 */
    r3 = (uint32_t)(int32_t)c_p8s(ram, r0, &gated);
L_8c078ee8: /* 633c */
    r3 = r3 & 0xFFu;
L_8c078eea: /* 213b */
    r1 |= r3;
L_8c078eec: /* d334 */
    r3 = 0x0c079f10; /* @(0x8c078fc0,pc) */
L_8c078eee: /* 432b */
    /* nop */;
    if ((r3 | 0x80000000u) == 0x8c079f10u) goto L_8c079f10;
    o->gated = 902; return;
L_8c078ef2: /* e01b */
    r0 = (uint32_t)(int32_t)27;
L_8c078ef4: /* 03cc */
    r3 = (uint32_t)(int32_t)c_p8s(ram, (r12 + r0), &gated);
L_8c078ef6: /* e050 */
    r0 = (uint32_t)(int32_t)80;
L_8c078ef8: /* 633c */
    r3 = r3 & 0xFFu;
L_8c078efa: /* 2338 */
    T = ((r3 & r3) == 0);
L_8c078efc: /* 8d03 */
    c_wr32(ram, (r15 + r0), r3);
    if (T) goto L_8c078f06;
    o->gated = 903; return;
L_8c078f06: /* 904e */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078fa6,pc) */
L_8c078f08: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c078f0a: /* 904c */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c078fa6,pc) */
L_8c078f0c: /* 7207 */
    r2 += 7u;
L_8c078f0e: /* aa32 */
    c_wr32(ram, (r15 + r0), r2);
    goto L_8c078376;
L_8c07915a: /* e064 */
    r0 = (uint32_t)(int32_t)100;
L_8c07915c: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c07915e: /* 4208 */
    r2 <<= 2;
L_8c079160: /* 6323 */
    r3 = r2;
L_8c079162: /* 1f23 */
    c_wr32(ram, r15 + 12, r2);
L_8c079164: /* 9176 */
    r1 = (uint32_t)(int32_t)(int16_t)0x1c00; /* @(0x8c079254,pc) */
L_8c079166: /* 31ec */
    r1 += r14;
L_8c079168: /* 313c */
    r1 += r3;
L_8c07916a: /* 8411 */
    r0 = (uint32_t)(int32_t)c_p8s(ram, r1 + 1, &gated);
L_8c07916c: /* 600c */
    r0 = r0 & 0xFFu;
L_8c07916e: /* 1f02 */
    c_wr32(ram, r15 + 8, r0);
L_8c079170: /* 9271 */
    r2 = (uint32_t)(int32_t)(int16_t)0x08a8; /* @(0x8c079256,pc) */
L_8c079172: /* 32fc */
    r2 += r15;
L_8c079174: /* 6222 */
    r2 = c_p32(ram, r2, &gated);
L_8c079176: /* 2028 */
    T = ((r0 & r2) == 0);
L_8c079178: /* 891e */
    if (T) goto L_8c0791b8; else goto L_8c07917a;
L_8c07917a: /* 9069 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c079250,pc) */
L_8c07917c: /* d339 */
    r3 = 0x00ff0000; /* @(0x8c079264,pc) */
L_8c07917e: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c079180: /* 9066 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c079250,pc) */
L_8c079182: /* 7204 */
    r2 += 4u;
L_8c079184: /* 00fe */
    r0 = c_p32(ram, (r15 + r0), &gated);
L_8c079186: /* 6120 */
    r1 = (uint32_t)(int32_t)c_p8s(ram, r2, &gated);
L_8c079188: /* 8403 */
    r0 = (uint32_t)(int32_t)c_p8s(ram, r0 + 3, &gated);
L_8c07918a: /* 611c */
    r1 = r1 & 0xFFu;
L_8c07918c: /* d234 */
    r2 = 0xff000000; /* @(0x8c079260,pc) */
L_8c07918e: /* 600c */
    r0 = r0 & 0xFFu;
L_8c079190: /* 4128 */
    r1 <<= 16;
L_8c079192: /* 4028 */
    r0 <<= 16;
L_8c079194: /* 4118 */
    r1 <<= 8;
L_8c079196: /* 2039 */
    r0 &= r3;
L_8c079198: /* 2129 */
    r1 &= r2;
L_8c07919a: /* 210b */
    r1 |= r0;
L_8c07919c: /* 9058 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c079250,pc) */
L_8c07919e: /* 4319 */
    r3 >>= 8;
L_8c0791a0: /* 00fe */
    r0 = c_p32(ram, (r15 + r0), &gated);
L_8c0791a2: /* 8402 */
    r0 = (uint32_t)(int32_t)c_p8s(ram, r0 + 2, &gated);
L_8c0791a4: /* 600c */
    r0 = r0 & 0xFFu;
L_8c0791a6: /* 4018 */
    r0 <<= 8;
L_8c0791a8: /* 2039 */
    r0 &= r3;
L_8c0791aa: /* 210b */
    r1 |= r0;
L_8c0791ac: /* 9050 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c079250,pc) */
L_8c0791ae: /* 00fe */
    r0 = c_p32(ram, (r15 + r0), &gated);
L_8c0791b0: /* 8401 */
    r0 = (uint32_t)(int32_t)c_p8s(ram, r0 + 1, &gated);
L_8c0791b2: /* 600c */
    r0 = r0 & 0xFFu;
L_8c0791b4: /* a6ac */
    r1 |= r0;
    goto L_8c079f10;
L_8c0791b8: /* 904e */
    r0 = (uint32_t)(int32_t)(int16_t)0x08a4; /* @(0x8c079258,pc) */
L_8c0791ba: /* 52f2 */
    r2 = c_p32(ram, r15 + 8, &gated);
L_8c0791bc: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c0791be: /* 2128 */
    T = ((r1 & r2) == 0);
L_8c0791c0: /* 8922 */
    if (T) { o->gated = 904; return; }
    goto L_8c0791c2;
L_8c0791c2: /* 9045 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c079250,pc) */
L_8c0791c4: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c0791c6: /* d026 */
    r0 = 0xff000000; /* @(0x8c079260,pc) */
L_8c0791c8: /* 7108 */
    r1 += 8u;
L_8c0791ca: /* 6110 */
    r1 = (uint32_t)(int32_t)c_p8s(ram, r1, &gated);
L_8c0791cc: /* 611c */
    r1 = r1 & 0xFFu;
L_8c0791ce: /* 4128 */
    r1 <<= 16;
L_8c0791d0: /* 4118 */
    r1 <<= 8;
L_8c0791d2: /* 2109 */
    r1 &= r0;
L_8c0791d4: /* 903c */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c079250,pc) */
L_8c0791d6: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c0791d8: /* d022 */
    r0 = 0x00ff0000; /* @(0x8c079264,pc) */
L_8c0791da: /* 7307 */
    r3 += 7u;
L_8c0791dc: /* 6330 */
    r3 = (uint32_t)(int32_t)c_p8s(ram, r3, &gated);
L_8c0791de: /* 633c */
    r3 = r3 & 0xFFu;
L_8c0791e0: /* 4328 */
    r3 <<= 16;
L_8c0791e2: /* 2309 */
    r3 &= r0;
L_8c0791e4: /* 9034 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c079250,pc) */
L_8c0791e6: /* 213b */
    r1 |= r3;
L_8c0791e8: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c0791ea: /* d01c */
    r0 = 0x0000ff00; /* @(0x8c07925c,pc) */
L_8c0791ec: /* 7306 */
    r3 += 6u;
L_8c0791ee: /* 6330 */
    r3 = (uint32_t)(int32_t)c_p8s(ram, r3, &gated);
L_8c0791f0: /* 633c */
    r3 = r3 & 0xFFu;
L_8c0791f2: /* 4318 */
    r3 <<= 8;
L_8c0791f4: /* 2309 */
    r3 &= r0;
L_8c0791f6: /* 902b */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c079250,pc) */
L_8c0791f8: /* 213b */
    r1 |= r3;
L_8c0791fa: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c0791fc: /* 7305 */
    r3 += 5u;
L_8c0791fe: /* 6330 */
    r3 = (uint32_t)(int32_t)c_p8s(ram, r3, &gated);
L_8c079200: /* 633c */
    r3 = r3 & 0xFFu;
L_8c079202: /* 213b */
    r1 |= r3;
L_8c079204: /* a021 */
    /* nop */;
    goto L_8c07924a;
L_8c07924a: /* 9001 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c079250,pc) */
L_8c07924c: /* a893 */
    c_wr32(ram, (r15 + r0), r1);
    goto L_8c078376;
L_8c079298: /* 908d */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c0793b6,pc) */
L_8c07929a: /* d24c */
    r2 = 0x0000ff00; /* @(0x8c0793cc,pc) */
L_8c07929c: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c07929e: /* 908a */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c0793b6,pc) */
L_8c0792a0: /* 7102 */
    r1 += 2u;
L_8c0792a2: /* 6310 */
    r3 = (uint32_t)(int32_t)c_p8s(ram, r1, &gated);
L_8c0792a4: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c0792a6: /* e050 */
    r0 = (uint32_t)(int32_t)80;
L_8c0792a8: /* 633c */
    r3 = r3 & 0xFFu;
L_8c0792aa: /* 7101 */
    r1 += 1u;
L_8c0792ac: /* 6110 */
    r1 = (uint32_t)(int32_t)c_p8s(ram, r1, &gated);
L_8c0792ae: /* 4318 */
    r3 <<= 8;
L_8c0792b0: /* 2329 */
    r3 &= r2;
L_8c0792b2: /* 611c */
    r1 = r1 & 0xFFu;
L_8c0792b4: /* 231b */
    r3 |= r1;
L_8c0792b6: /* 0f36 */
    c_wr32(ram, (r15 + r0), r3);
L_8c0792b8: /* 907d */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c0793b6,pc) */
L_8c0792ba: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c0792bc: /* 907b */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c0793b6,pc) */
L_8c0792be: /* 7104 */
    r1 += 4u;
L_8c0792c0: /* 00fe */
    r0 = c_p32(ram, (r15 + r0), &gated);
L_8c0792c2: /* 6110 */
    r1 = (uint32_t)(int32_t)c_p8s(ram, r1, &gated);
L_8c0792c4: /* 8403 */
    r0 = (uint32_t)(int32_t)c_p8s(ram, r0 + 3, &gated);
L_8c0792c6: /* 611c */
    r1 = r1 & 0xFFu;
L_8c0792c8: /* 4118 */
    r1 <<= 8;
L_8c0792ca: /* 600c */
    r0 = r0 & 0xFFu;
L_8c0792cc: /* 2129 */
    r1 &= r2;
L_8c0792ce: /* 210b */
    r1 |= r0;
L_8c0792d0: /* e04c */
    r0 = (uint32_t)(int32_t)76;
L_8c0792d2: /* 0f16 */
    c_wr32(ram, (r15 + r0), r1);
L_8c0792d4: /* 906f */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c0793b6,pc) */
L_8c0792d6: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c0792d8: /* 7108 */
    r1 += 8u;
L_8c0792da: /* d03d */
    r0 = 0xff000000; /* @(0x8c0793d0,pc) */
L_8c0792dc: /* 6110 */
    r1 = (uint32_t)(int32_t)c_p8s(ram, r1, &gated);
L_8c0792de: /* 611c */
    r1 = r1 & 0xFFu;
L_8c0792e0: /* 4128 */
    r1 <<= 16;
L_8c0792e2: /* 4118 */
    r1 <<= 8;
L_8c0792e4: /* 2109 */
    r1 &= r0;
L_8c0792e6: /* 9066 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c0793b6,pc) */
L_8c0792e8: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c0792ea: /* d03a */
    r0 = 0x00ff0000; /* @(0x8c0793d4,pc) */
L_8c0792ec: /* 7307 */
    r3 += 7u;
L_8c0792ee: /* 6330 */
    r3 = (uint32_t)(int32_t)c_p8s(ram, r3, &gated);
L_8c0792f0: /* 633c */
    r3 = r3 & 0xFFu;
L_8c0792f2: /* 4328 */
    r3 <<= 16;
L_8c0792f4: /* 2309 */
    r3 &= r0;
L_8c0792f6: /* 905e */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c0793b6,pc) */
L_8c0792f8: /* 213b */
    r1 |= r3;
L_8c0792fa: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c0792fc: /* 905b */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c0793b6,pc) */
L_8c0792fe: /* 7306 */
    r3 += 6u;
L_8c079300: /* 6330 */
    r3 = (uint32_t)(int32_t)c_p8s(ram, r3, &gated);
L_8c079302: /* 00fe */
    r0 = c_p32(ram, (r15 + r0), &gated);
L_8c079304: /* 633c */
    r3 = r3 & 0xFFu;
L_8c079306: /* 4318 */
    r3 <<= 8;
L_8c079308: /* 2329 */
    r3 &= r2;
L_8c07930a: /* 7005 */
    r0 += 5u;
L_8c07930c: /* 213b */
    r1 |= r3;
L_8c07930e: /* 6300 */
    r3 = (uint32_t)(int32_t)c_p8s(ram, r0, &gated);
L_8c079310: /* e048 */
    r0 = (uint32_t)(int32_t)72;
L_8c079312: /* 633c */
    r3 = r3 & 0xFFu;
L_8c079314: /* 213b */
    r1 |= r3;
L_8c079316: /* 0f16 */
    c_wr32(ram, (r15 + r0), r1);
L_8c079318: /* e050 */
    r0 = (uint32_t)(int32_t)80;
L_8c07931a: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c07931c: /* 2338 */
    T = ((r3 & r3) == 0);
L_8c07931e: /* 8910 */
    if (T) { o->gated = 904; return; }
    goto L_8c079320;
L_8c079320: /* e050 */
    r0 = (uint32_t)(int32_t)80;
L_8c079322: /* 02fd */
    r2 = (uint32_t)(int32_t)c_p16(ram, (r15 + r0), &gated);
L_8c079324: /* 9049 */
    r0 = (uint32_t)(int32_t)(int16_t)0x1ba2; /* @(0x8c0793ba,pc) */
L_8c079326: /* 0e25 */
    c_wr16(ram, (r14 + r0), (uint16_t)r2);
L_8c079328: /* e04c */
    r0 = (uint32_t)(int32_t)76;
L_8c07932a: /* 03fd */
    r3 = (uint32_t)(int32_t)c_p16(ram, (r15 + r0), &gated);
L_8c07932c: /* 9046 */
    r0 = (uint32_t)(int32_t)(int16_t)0x1ba6; /* @(0x8c0793bc,pc) */
L_8c07932e: /* 0e35 */
    c_wr16(ram, (r14 + r0), (uint16_t)r3);
L_8c079330: /* e048 */
    r0 = (uint32_t)(int32_t)72;
L_8c079332: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c079334: /* 9043 */
    r0 = (uint32_t)(int32_t)(int16_t)0x1bac; /* @(0x8c0793be,pc) */
L_8c079336: /* 0e26 */
    c_wr32(ram, (r14 + r0), r2);
L_8c079338: /* 903d */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c0793b6,pc) */
L_8c07933a: /* d227 */
    r2 = 0x0c07a336; /* @(0x8c0793d8,pc) */
L_8c07933c: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c07933e: /* 422b */
    r3 += 9u;
    if ((r2 | 0x80000000u) == 0x8c07a336u) goto L_8c07a336;
    o->gated = 902; return;
L_8c079388: /* 9015 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c0793b6,pc) */
L_8c07938a: /* d214 */
    r2 = 0x80000000; /* @(0x8c0793dc,pc) */
L_8c07938c: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c07938e: /* 7101 */
    r1 += 1u;
L_8c079390: /* 6310 */
    r3 = (uint32_t)(int32_t)c_p8s(ram, r1, &gated);
L_8c079392: /* 633c */
    r3 = r3 & 0xFFu;
L_8c079394: /* 633b */
    r3 = (uint32_t)(0u - r3);
L_8c079396: /* 423d */
    { int32_t sh = (int32_t)r3; uint32_t v = r2; r2 = (sh >= 0 ? (sh < 32 ? (v << (uint32_t)sh) : 0u) : (-sh < 32 ? (v >> (uint32_t)(-sh)) : 0u)); }
L_8c079398: /* 6323 */
    r3 = r2;
L_8c07939a: /* 1f23 */
    c_wr32(ram, r15 + 12, r2);
L_8c07939c: /* 9012 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0894; /* @(0x8c0793c4,pc) */
L_8c07939e: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c0793a0: /* 2138 */
    T = ((r1 & r3) == 0);
L_8c0793a2: /* 8902 */
    if (T) goto L_8c0793aa;
    o->gated = 903; return;
L_8c0793aa: /* 9004 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c0793b6,pc) */
L_8c0793ac: /* d20a */
    r2 = 0x0c07a336; /* @(0x8c0793d8,pc) */
L_8c0793ae: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c0793b0: /* 422b */
    r3 += 2u;
    if ((r2 | 0x80000000u) == 0x8c07a336u) goto L_8c07a336;
    o->gated = 902; return;
L_8c0793e4: /* 909d */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c079522,pc) */
L_8c0793e6: /* d251 */
    r2 = 0x80000000; /* @(0x8c07952c,pc) */
L_8c0793e8: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c0793ea: /* 7101 */
    r1 += 1u;
L_8c0793ec: /* 6310 */
    r3 = (uint32_t)(int32_t)c_p8s(ram, r1, &gated);
L_8c0793ee: /* 633c */
    r3 = r3 & 0xFFu;
L_8c0793f0: /* 633b */
    r3 = (uint32_t)(0u - r3);
L_8c0793f2: /* 423d */
    { int32_t sh = (int32_t)r3; uint32_t v = r2; r2 = (sh >= 0 ? (sh < 32 ? (v << (uint32_t)sh) : 0u) : (-sh < 32 ? (v >> (uint32_t)(-sh)) : 0u)); }
L_8c0793f4: /* 6323 */
    r3 = r2;
L_8c0793f6: /* 1f23 */
    c_wr32(ram, r15 + 12, r2);
L_8c0793f8: /* 9094 */
    r0 = (uint32_t)(int32_t)(int16_t)0x089c; /* @(0x8c079524,pc) */
L_8c0793fa: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c0793fc: /* 2138 */
    T = ((r1 & r3) == 0);
L_8c0793fe: /* 8b02 */
    if (!T) goto L_8c079406; else goto L_8c079400;
L_8c079400: /* d24b */
    r2 = 0x0c07a6c4; /* @(0x8c079530,pc) */
L_8c079402: /* 422b */
    /* nop */;
    if ((r2 | 0x80000000u) == 0x8c07a6c4u) goto L_8c07a6c4;
    o->gated = 902; return;
L_8c079406: /* 908c */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c079522,pc) */
L_8c079408: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c07940a: /* a794 */
    r3 += 2u;
    goto L_8c07a336;
L_8c07940e: /* 9088 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c079522,pc) */
L_8c079410: /* d246 */
    r2 = 0x80000000; /* @(0x8c07952c,pc) */
L_8c079412: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c079414: /* 7101 */
    r1 += 1u;
L_8c079416: /* 6310 */
    r3 = (uint32_t)(int32_t)c_p8s(ram, r1, &gated);
L_8c079418: /* 633c */
    r3 = r3 & 0xFFu;
L_8c07941a: /* 633b */
    r3 = (uint32_t)(0u - r3);
L_8c07941c: /* 423d */
    { int32_t sh = (int32_t)r3; uint32_t v = r2; r2 = (sh >= 0 ? (sh < 32 ? (v << (uint32_t)sh) : 0u) : (-sh < 32 ? (v >> (uint32_t)(-sh)) : 0u)); }
L_8c07941e: /* 6323 */
    r3 = r2;
L_8c079420: /* 1f23 */
    c_wr32(ram, r15 + 12, r2);
L_8c079422: /* 907f */
    r0 = (uint32_t)(int32_t)(int16_t)0x089c; /* @(0x8c079524,pc) */
L_8c079424: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c079426: /* 2138 */
    T = ((r1 & r3) == 0);
L_8c079428: /* 8902 */
    if (T) goto L_8c079430;
    o->gated = 903; return;
L_8c079430: /* 9077 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c079522,pc) */
L_8c079432: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c079434: /* a77f */
    r3 += 2u;
    goto L_8c07a336;
L_8c07948c: /* 9049 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c079522,pc) */
L_8c07948e: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c079490: /* e048 */
    r0 = (uint32_t)(int32_t)72;
L_8c079492: /* 7101 */
    r1 += 1u;
L_8c079494: /* 6310 */
    r3 = (uint32_t)(int32_t)c_p8s(ram, r1, &gated);
L_8c079496: /* 633c */
    r3 = r3 & 0xFFu;
L_8c079498: /* 1f33 */
    c_wr32(ram, r15 + 12, r3);
L_8c07949a: /* 02de */
    r2 = c_p32(ram, (r13 + r0), &gated);
L_8c07949c: /* 1f22 */
    c_wr32(ram, r15 + 8, r2);
L_8c07949e: /* 53f3 */
    r3 = c_p32(ram, r15 + 12, &gated);
L_8c0794a0: /* d122 */
    r1 = 0x80000000; /* @(0x8c07952c,pc) */
L_8c0794a2: /* 633b */
    r3 = (uint32_t)(0u - r3);
L_8c0794a4: /* 413d */
    { int32_t sh = (int32_t)r3; uint32_t v = r1; r1 = (sh >= 0 ? (sh < 32 ? (v << (uint32_t)sh) : 0u) : (-sh < 32 ? (v >> (uint32_t)(-sh)) : 0u)); }
L_8c0794a6: /* 1f13 */
    c_wr32(ram, r15 + 12, r1);
L_8c0794a8: /* 53f2 */
    r3 = c_p32(ram, r15 + 8, &gated);
L_8c0794aa: /* 2138 */
    T = ((r1 & r3) == 0);
L_8c0794ac: /* 8b02 */
    if (!T) { o->gated = 904; return; }
    goto L_8c0794ae;
L_8c0794ae: /* d220 */
    r2 = 0x0c07a6c4; /* @(0x8c079530,pc) */
L_8c0794b0: /* 422b */
    /* nop */;
    if ((r2 | 0x80000000u) == 0x8c07a6c4u) goto L_8c07a6c4;
    o->gated = 902; return;
L_8c079698: /* e05c */
    r0 = (uint32_t)(int32_t)92;
L_8c07969a: /* 63f3 */
    r3 = r15;
L_8c07969c: /* f3e6 */
    fr[3] = c_rd32(ram, r0 + r14);
L_8c07969e: /* e00c */
    r0 = (uint32_t)(int32_t)12;
L_8c0796a0: /* 7304 */
    r3 += 4u;
L_8c0796a2: /* ff37 */
    c_wr32(ram, r0 + r15, fr[3]);
L_8c0796a4: /* 2f32 */
    c_wr32(ram, r15, r3);
L_8c0796a6: /* 909c */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c0797e2,pc) */
L_8c0796a8: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c0796aa: /* 909a */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c0797e2,pc) */
L_8c0796ac: /* 7204 */
    r2 += 4u;
L_8c0796ae: /* 6120 */
    r1 = (uint32_t)(int32_t)c_p8s(ram, r2, &gated);
L_8c0796b0: /* d24d */
    r2 = 0xff000000; /* @(0x8c0797e8,pc) */
L_8c0796b2: /* 611c */
    r1 = r1 & 0xFFu;
L_8c0796b4: /* 00fe */
    r0 = c_p32(ram, (r15 + r0), &gated);
L_8c0796b6: /* 4128 */
    r1 <<= 16;
L_8c0796b8: /* 4118 */
    r1 <<= 8;
L_8c0796ba: /* 7003 */
    r0 += 3u;
L_8c0796bc: /* 2129 */
    r1 &= r2;
L_8c0796be: /* 6200 */
    r2 = (uint32_t)(int32_t)c_p8s(ram, r0, &gated);
L_8c0796c0: /* d04a */
    r0 = 0x00ff0000; /* @(0x8c0797ec,pc) */
L_8c0796c2: /* 622c */
    r2 = r2 & 0xFFu;
L_8c0796c4: /* 4228 */
    r2 <<= 16;
L_8c0796c6: /* 2209 */
    r2 &= r0;
L_8c0796c8: /* 908b */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c0797e2,pc) */
L_8c0796ca: /* 212b */
    r1 |= r2;
L_8c0796cc: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c0796ce: /* d048 */
    r0 = 0x0000ff00; /* @(0x8c0797f0,pc) */
L_8c0796d0: /* 7202 */
    r2 += 2u;
L_8c0796d2: /* 6220 */
    r2 = (uint32_t)(int32_t)c_p8s(ram, r2, &gated);
L_8c0796d4: /* 622c */
    r2 = r2 & 0xFFu;
L_8c0796d6: /* 4218 */
    r2 <<= 8;
L_8c0796d8: /* 2209 */
    r2 &= r0;
L_8c0796da: /* 9082 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c0797e2,pc) */
L_8c0796dc: /* 212b */
    r1 |= r2;
L_8c0796de: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c0796e0: /* e004 */
    r0 = (uint32_t)(int32_t)4;
L_8c0796e2: /* 7201 */
    r2 += 1u;
L_8c0796e4: /* 6220 */
    r2 = (uint32_t)(int32_t)c_p8s(ram, r2, &gated);
L_8c0796e6: /* 622c */
    r2 = r2 & 0xFFu;
L_8c0796e8: /* 212b */
    r1 |= r2;
L_8c0796ea: /* 2312 */
    c_wr32(ram, r3, r1);
L_8c0796ec: /* f3f6 */
    fr[3] = c_rd32(ram, r0 + r15);
L_8c0796ee: /* e008 */
    r0 = (uint32_t)(int32_t)8;
L_8c0796f0: /* ff37 */
    c_wr32(ram, r0 + r15, fr[3]);
L_8c0796f2: /* e00c */
    r0 = (uint32_t)(int32_t)12;
L_8c0796f4: /* f2f6 */
    fr[2] = c_rd32(ram, r0 + r15);
L_8c0796f6: /* f235 */
    T = (f32(fr[2]) > f32(fr[3]));
L_8c0796f8: /* 8b02 */
    if (!T) { o->gated = 904; return; }
    goto L_8c0796fa;
L_8c0796fa: /* d33e */
    r3 = 0x0c07a6c4; /* @(0x8c0797f4,pc) */
L_8c0796fc: /* 432b */
    /* nop */;
    if ((r3 | 0x80000000u) == 0x8c07a6c4u) goto L_8c07a6c4;
    o->gated = 902; return;
L_8c079f10: /* d314 */
    r3 = 0x0c078376; /* @(0x8c079f64,pc) */
L_8c079f12: /* 901c */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c079f4e,pc) */
L_8c079f14: /* 432b */
    c_wr32(ram, (r15 + r0), r1);
    if ((r3 | 0x80000000u) == 0x8c078376u) goto L_8c078376;
    o->gated = 902; return;
L_8c07a336: /* d209 */
    r2 = 0x0c078376; /* @(0x8c07a35c,pc) */
L_8c07a338: /* 9001 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c07a33e,pc) */
L_8c07a33a: /* 422b */
    c_wr32(ram, (r15 + r0), r3);
    if ((r2 | 0x80000000u) == 0x8c078376u) goto L_8c078376;
    o->gated = 902; return;
L_8c07a51a: /* e054 */
    r0 = (uint32_t)(int32_t)84;
L_8c07a51c: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c07a51e: /* 9047 */
    r0 = (uint32_t)(int32_t)(int16_t)0x08ac; /* @(0x8c07a5b0,pc) */
L_8c07a520: /* 2338 */
    T = ((r3 & r3) == 0);
L_8c07a522: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c07a524: /* 2139 */
    r1 &= r3;
L_8c07a526: /* 1f1d */
    c_wr32(ram, r15 + 52, r1);
L_8c07a528: /* 9042 */
    r0 = (uint32_t)(int32_t)(int16_t)0x08ac; /* @(0x8c07a5b0,pc) */
L_8c07a52a: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c07a52c: /* e05c */
    r0 = (uint32_t)(int32_t)92;
L_8c07a52e: /* 3128 */
    r1 -= r2;
L_8c07a530: /* 1f12 */
    c_wr32(ram, r15 + 8, r1);
L_8c07a532: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c07a534: /* 8d42 */
    c_wr32(ram, r15 + 12, r2);
    if (T) goto L_8c07a5bc; else goto L_8c07a538;
L_8c07a538: /* e058 */
    r0 = (uint32_t)(int32_t)88;
L_8c07a53a: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c07a53c: /* e054 */
    r0 = (uint32_t)(int32_t)84;
L_8c07a53e: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c07a540: /* 3130 */
    T = (r1 == r3);
L_8c07a542: /* 891b */
    if (T) { o->gated = 904; return; }
    goto L_8c07a544;
L_8c07a544: /* e058 */
    r0 = (uint32_t)(int32_t)88;
L_8c07a546: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c07a548: /* 9032 */
    r0 = (uint32_t)(int32_t)(int16_t)0x08ac; /* @(0x8c07a5b0,pc) */
L_8c07a54a: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c07a54c: /* 3230 */
    T = (r2 == r3);
L_8c07a54e: /* 893d */
    if (T) { o->gated = 904; return; }
    goto L_8c07a550;
L_8c07a550: /* 902e */
    r0 = (uint32_t)(int32_t)(int16_t)0x08ac; /* @(0x8c07a5b0,pc) */
L_8c07a552: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c07a554: /* 2118 */
    T = ((r1 & r1) == 0);
L_8c07a556: /* 8924 */
    if (T) { o->gated = 904; return; }
    goto L_8c07a558;
L_8c07a558: /* 902a */
    r0 = (uint32_t)(int32_t)(int16_t)0x08ac; /* @(0x8c07a5b0,pc) */
L_8c07a55a: /* 51fd */
    r1 = c_p32(ram, r15 + 52, &gated);
L_8c07a55c: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c07a55e: /* 3130 */
    T = (r1 == r3);
L_8c07a560: /* 8901 */
    if (T) { o->gated = 904; return; }
    goto L_8c07a562;
L_8c07a562: /* a0af */
    /* nop */;
    goto L_8c07a6c4;
L_8c07a5bc: /* e058 */
    r0 = (uint32_t)(int32_t)88;
L_8c07a5be: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c07a5c0: /* 9062 */
    r0 = (uint32_t)(int32_t)(int16_t)0x08ac; /* @(0x8c07a688,pc) */
L_8c07a5c2: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c07a5c4: /* 3210 */
    T = (r2 == r1);
L_8c07a5c6: /* 8901 */
    if (T) { o->gated = 904; return; }
    goto L_8c07a5c8;
L_8c07a5c8: /* a07c */
    /* nop */;
    goto L_8c07a6c4;
L_8c07a5cc: /* e060 */
    r0 = (uint32_t)(int32_t)96;
L_8c07a5ce: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c07a5d0: /* e060 */
    r0 = (uint32_t)(int32_t)96;
L_8c07a5d2: /* 73ff */
    r3 -= 1u;
L_8c07a5d4: /* 4311 */
    T = ((int32_t)r3 >= 0);
L_8c07a5d6: /* 8f75 */
    c_wr32(ram, (r15 + r0), r3);
    if (!T) goto L_8c07a6c4; else goto L_8c07a5da;
L_8c07a5da: /* e018 */
    r0 = (uint32_t)(int32_t)24;
L_8c07a5dc: /* 03cc */
    r3 = (uint32_t)(int32_t)c_p8s(ram, (r12 + r0), &gated);
L_8c07a5de: /* e064 */
    r0 = (uint32_t)(int32_t)100;
    if (bpath && ++c5de == 7) {
        c_wr32(ram, r15 - 4, r0); c_wr32(ram, r15 - 8, r1);
    }
L_8c07a5e0: /* 633c */
    r3 = r3 & 0xFFu;
L_8c07a5e2: /* 1f36 */
    c_wr32(ram, r15 + 24, r3);
L_8c07a5e4: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c07a5e6: /* 3230 */
    T = (r2 == r3);
L_8c07a5e8: /* 896c */
    if (T) goto L_8c07a6c4; else goto L_8c07a5ea;
L_8c07a5ea: /* e064 */
    r0 = (uint32_t)(int32_t)100;
L_8c07a5ec: /* 61f3 */
    r1 = r15;
L_8c07a5ee: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c07a5f0: /* 7164 */
    r1 += 100u;
L_8c07a5f2: /* 73ff */
    r3 -= 1u;
L_8c07a5f4: /* 6033 */
    r0 = r3;
L_8c07a5f6: /* c93f */
    r0 &= 0x3fu;
L_8c07a5f8: /* 2102 */
    c_wr32(ram, r1, r0);
L_8c07a5fa: /* 4008 */
    r0 <<= 2;
L_8c07a5fc: /* 6303 */
    r3 = r0;
L_8c07a5fe: /* 1f05 */
    c_wr32(ram, r15 + 20, r0);
L_8c07a600: /* 9043 */
    r0 = (uint32_t)(int32_t)(int16_t)0x1c00; /* @(0x8c07a68a,pc) */
L_8c07a602: /* 9141 */
    r1 = (uint32_t)(int32_t)(int16_t)0x08ac; /* @(0x8c07a688,pc) */
L_8c07a604: /* 30ec */
    r0 += r14;
L_8c07a606: /* 003c */
    r0 = (uint32_t)(int32_t)c_p8s(ram, (r3 + r0), &gated);
L_8c07a608: /* 31fc */
    r1 += r15;
L_8c07a60a: /* 600c */
    r0 = r0 & 0xFFu;
L_8c07a60c: /* c9f0 */
    r0 &= 0xf0u;
L_8c07a60e: /* 2102 */
    c_wr32(ram, r1, r0);
L_8c07a610: /* 923b */
    r2 = (uint32_t)(int32_t)(int16_t)0x1c00; /* @(0x8c07a68a,pc) */
L_8c07a612: /* 53f5 */
    r3 = c_p32(ram, r15 + 20, &gated);
L_8c07a614: /* 32ec */
    r2 += r14;
L_8c07a616: /* 323c */
    r2 += r3;
L_8c07a618: /* 8422 */
    r0 = (uint32_t)(int32_t)c_p8s(ram, r2 + 2, &gated);
L_8c07a61a: /* 600c */
    r0 = r0 & 0xFFu;
L_8c07a61c: /* 1f04 */
    c_wr32(ram, r15 + 16, r0);
L_8c07a61e: /* d31d */
    r3 = 0x0c29b868; /* @(0x8c07a694,pc) */
L_8c07a620: /* d21b */
    r2 = 0x0f000000; /* @(0x8c07a690,pc) */
L_8c07a622: /* 6132 */
    r1 = c_p32(ram, r3, &gated);
L_8c07a624: /* 2128 */
    T = ((r1 & r2) == 0);
L_8c07a626: /* 8908 */
    if (T) goto L_8c07a63a;
    o->gated = 903; return;
L_8c07a63a: /* 9027 */
    r0 = (uint32_t)(int32_t)(int16_t)0x1bb6; /* @(0x8c07a68c,pc) */
L_8c07a63c: /* e300 */
    r3 = (uint32_t)(int32_t)0;
L_8c07a63e: /* 02ec */
    r2 = (uint32_t)(int32_t)c_p8s(ram, (r14 + r0), &gated);
L_8c07a640: /* e064 */
    r0 = (uint32_t)(int32_t)100;
L_8c07a642: /* 622c */
    r2 = r2 & 0xFFu;
L_8c07a644: /* 1f2c */
    c_wr32(ram, r15 + 48, r2);
L_8c07a646: /* 1f3b */
    c_wr32(ram, r15 + 44, r3);
L_8c07a648: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c07a64a: /* 3216 */
    T = (r2 > r1);
L_8c07a64c: /* 8902 */
    if (T) goto L_8c07a654; else goto L_8c07a64e;
L_8c07a64e: /* 53fb */
    r3 = c_p32(ram, r15 + 44, &gated);
L_8c07a650: /* 7301 */
    r3 += 1u;
L_8c07a652: /* 1f3b */
    c_wr32(ram, r15 + 44, r3);
L_8c07a654: /* 51fc */
    r1 = c_p32(ram, r15 + 48, &gated);
L_8c07a656: /* 52f6 */
    r2 = c_p32(ram, r15 + 24, &gated);
L_8c07a658: /* 3122 */
    T = (r1 >= r2);
L_8c07a65a: /* 8b02 */
    if (!T) goto L_8c07a662; else goto L_8c07a65c;
L_8c07a65c: /* 53fb */
    r3 = c_p32(ram, r15 + 44, &gated);
L_8c07a65e: /* 7301 */
    r3 += 1u;
L_8c07a660: /* 1f3b */
    c_wr32(ram, r15 + 44, r3);
L_8c07a662: /* e064 */
    r0 = (uint32_t)(int32_t)100;
L_8c07a664: /* 51f6 */
    r1 = c_p32(ram, r15 + 24, &gated);
L_8c07a666: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c07a668: /* 3126 */
    T = (r1 > r2);
L_8c07a66a: /* 8d03 */
    r2 = (uint32_t)(int32_t)1;
    if (T) goto L_8c07a674; else goto L_8c07a66e;
L_8c07a66e: /* 53fb */
    r3 = c_p32(ram, r15 + 44, &gated);
L_8c07a670: /* 73ff */
    r3 -= 1u;
L_8c07a672: /* 1f3b */
    c_wr32(ram, r15 + 44, r3);
L_8c07a674: /* 51fb */
    r1 = c_p32(ram, r15 + 44, &gated);
L_8c07a676: /* 3122 */
    T = (r1 >= r2);
L_8c07a678: /* 8b10 */
    if (!T) goto L_8c07a69c; else goto L_8c07a67a;
L_8c07a67a: /* 9108 */
    r1 = (uint32_t)(int32_t)(int16_t)0x08b0; /* @(0x8c07a68e,pc) */
L_8c07a67c: /* 50f4 */
    r0 = c_p32(ram, r15 + 16, &gated);
L_8c07a67e: /* d306 */
    r3 = 0x0c078376; /* @(0x8c07a698,pc) */
L_8c07a680: /* 31fc */
    r1 += r15;
L_8c07a682: /* c9f0 */
    r0 &= 0xf0u;
L_8c07a684: /* 432b */
    c_wr32(ram, r1, r0);
    if ((r3 | 0x80000000u) == 0x8c078376u) goto L_8c078376;
    o->gated = 902; return;
L_8c07a69c: /* e019 */
    r0 = (uint32_t)(int32_t)25;
L_8c07a69e: /* 53f4 */
    r3 = c_p32(ram, r15 + 16, &gated);
L_8c07a6a0: /* 02cc */
    r2 = (uint32_t)(int32_t)c_p8s(ram, (r12 + r0), &gated);
L_8c07a6a2: /* 9075 */
    r0 = (uint32_t)(int32_t)(int16_t)0x08b0; /* @(0x8c07a790,pc) */
L_8c07a6a4: /* 622c */
    r2 = r2 & 0xFFu;
L_8c07a6a6: /* 2239 */
    r2 &= r3;
L_8c07a6a8: /* 0f26 */
    c_wr32(ram, (r15 + r0), r2);
L_8c07a6aa: /* e01a */
    r0 = (uint32_t)(int32_t)26;
L_8c07a6ac: /* 01cc */
    r1 = (uint32_t)(int32_t)c_p8s(ram, (r12 + r0), &gated);
L_8c07a6ae: /* 611c */
    r1 = r1 & 0xFFu;
L_8c07a6b0: /* 2319 */
    r3 &= r1;
L_8c07a6b2: /* 6133 */
    r1 = r3;
L_8c07a6b4: /* 1f3d */
    c_wr32(ram, r15 + 52, r3);
L_8c07a6b6: /* 906b */
    r0 = (uint32_t)(int32_t)(int16_t)0x08b0; /* @(0x8c07a790,pc) */
L_8c07a6b8: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c07a6ba: /* 3120 */
    T = (r1 == r2);
L_8c07a6bc: /* 8b02 */
    if (!T) { o->gated = 904; return; }
    goto L_8c07a6be;
L_8c07a6be: /* d339 */
    r3 = 0x0c078376; /* @(0x8c07a7a4,pc) */
L_8c07a6c0: /* 432b */
    /* nop */;
    if ((r3 | 0x80000000u) == 0x8c078376u) goto L_8c078376;
    o->gated = 902; return;
L_8c07a6c4: /* e068 */
    r0 = (uint32_t)(int32_t)104;
L_8c07a6c6: /* 53c5 */
    r3 = c_p32(ram, r12 + 20, &gated);
L_8c07a6c8: /* 6233 */
    r2 = r3;
L_8c07a6ca: /* 1f3d */
    c_wr32(ram, r15 + 52, r3);
L_8c07a6cc: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c07a6ce: /* 3122 */
    T = (r1 >= r2);
L_8c07a6d0: /* 893d */
    if (T) { o->gated = 904; return; }
    goto L_8c07a6d2;
L_8c07a6d2: /* e068 */
    r0 = (uint32_t)(int32_t)104;
L_8c07a6d4: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c07a6d6: /* 731e */
    r3 += 30u;
L_8c07a6d8: /* 6231 */
    r2 = (uint32_t)(int32_t)c_p16(ram, r3, &gated);
L_8c07a6da: /* 622d */
    r2 = r2 & 0xFFFFu;
L_8c07a6dc: /* 2228 */
    T = ((r2 & r2) == 0);
L_8c07a6de: /* 8f29 */
    c_wr32(ram, r15 + 52, r2);
    if (!T) goto L_8c07a734; else goto L_8c07a6e2;
L_8c07a6e2: /* e068 */
    r0 = (uint32_t)(int32_t)104;
L_8c07a6e4: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c07a6e6: /* 9054 */
    r0 = (uint32_t)(int32_t)(int16_t)0x08ac; /* @(0x8c07a792,pc) */
L_8c07a6e8: /* 7304 */
    r3 += 4u;
L_8c07a6ea: /* 6232 */
    r2 = c_p32(ram, r3, &gated);
L_8c07a6ec: /* 0f26 */
    c_wr32(ram, (r15 + r0), r2);
L_8c07a6ee: /* e068 */
    r0 = (uint32_t)(int32_t)104;
L_8c07a6f0: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c07a6f2: /* 904d */
    r0 = (uint32_t)(int32_t)(int16_t)0x08b0; /* @(0x8c07a790,pc) */
L_8c07a6f4: /* 6232 */
    r2 = c_p32(ram, r3, &gated);
L_8c07a6f6: /* 0f26 */
    c_wr32(ram, (r15 + r0), r2);
L_8c07a6f8: /* e068 */
    r0 = (uint32_t)(int32_t)104;
L_8c07a6fa: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c07a6fc: /* e058 */
    r0 = (uint32_t)(int32_t)88;
L_8c07a6fe: /* 7308 */
    r3 += 8u;
L_8c07a700: /* 6232 */
    r2 = c_p32(ram, r3, &gated);
L_8c07a702: /* 0f26 */
    c_wr32(ram, (r15 + r0), r2);
L_8c07a704: /* e068 */
    r0 = (uint32_t)(int32_t)104;
L_8c07a706: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c07a708: /* e064 */
    r0 = (uint32_t)(int32_t)100;
L_8c07a70a: /* 730c */
    r3 += 12u;
L_8c07a70c: /* 6232 */
    r2 = c_p32(ram, r3, &gated);
L_8c07a70e: /* 0f26 */
    c_wr32(ram, (r15 + r0), r2);
L_8c07a710: /* e068 */
    r0 = (uint32_t)(int32_t)104;
L_8c07a712: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c07a714: /* e054 */
    r0 = (uint32_t)(int32_t)84;
L_8c07a716: /* 7310 */
    r3 += 16u;
L_8c07a718: /* 6232 */
    r2 = c_p32(ram, r3, &gated);
L_8c07a71a: /* 0f26 */
    c_wr32(ram, (r15 + r0), r2);
L_8c07a71c: /* e068 */
    r0 = (uint32_t)(int32_t)104;
L_8c07a71e: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c07a720: /* 7314 */
    r3 += 20u;
L_8c07a722: /* 6232 */
    r2 = c_p32(ram, r3, &gated);
L_8c07a724: /* e05c */
    r0 = (uint32_t)(int32_t)92;
L_8c07a726: /* 0f26 */
    c_wr32(ram, (r15 + r0), r2);
L_8c07a728: /* e068 */
    r0 = (uint32_t)(int32_t)104;
L_8c07a72a: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c07a72c: /* e060 */
    r0 = (uint32_t)(int32_t)96;
L_8c07a72e: /* 731c */
    r3 += 28u;
L_8c07a730: /* 6232 */
    r2 = c_p32(ram, r3, &gated);
L_8c07a732: /* 0f26 */
    c_wr32(ram, (r15 + r0), r2);
L_8c07a734: /* e068 */
    r0 = (uint32_t)(int32_t)104;
L_8c07a736: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c07a738: /* 902c */
    r0 = (uint32_t)(int32_t)(int16_t)0x0890; /* @(0x8c07a794,pc) */
L_8c07a73a: /* 7318 */
    r3 += 24u;
L_8c07a73c: /* 6232 */
    r2 = c_p32(ram, r3, &gated);
L_8c07a73e: /* 0f26 */
    c_wr32(ram, (r15 + r0), r2);
L_8c07a740: /* e068 */
    r0 = (uint32_t)(int32_t)104;
L_8c07a742: /* 03fe */
    r3 = c_p32(ram, (r15 + r0), &gated);
L_8c07a744: /* e068 */
    r0 = (uint32_t)(int32_t)104;
L_8c07a746: /* d217 */
    r2 = 0x0c078376; /* @(0x8c07a7a4,pc) */
L_8c07a748: /* 7320 */
    r3 += 32u;
L_8c07a74a: /* 422b */
    c_wr32(ram, (r15 + r0), r3);
    if ((r2 | 0x80000000u) == 0x8c078376u) goto L_8c078376;
    o->gated = 902; return;
L_8c07a74e: /* 9022 */
    r0 = (uint32_t)(int32_t)(int16_t)0x086c; /* @(0x8c07a796,pc) */
L_8c07a750: /* e300 */
    r3 = (uint32_t)(int32_t)0;
L_8c07a752: /* 01fe */
    r1 = c_p32(ram, (r15 + r0), &gated);
L_8c07a754: /* 2132 */
    c_wr32(ram, r1, r3);
L_8c07a756: /* a014 */
    r0 = (uint32_t)(int32_t)0;
    goto L_8c07a782;
L_8c07a75a: /* 901d */
    r0 = (uint32_t)(int32_t)(int16_t)0x1b83; /* @(0x8c07a798,pc) */
L_8c07a75c: /* 02ec */
    r2 = (uint32_t)(int32_t)c_p8s(ram, (r14 + r0), &gated);
L_8c07a75e: /* 7001 */
    r0 += 1u;
L_8c07a760: /* 0e24 */
    c_wr8(ram, (r14 + r0), (uint8_t)r2);
L_8c07a762: /* 9019 */
    r0 = (uint32_t)(int32_t)(int16_t)0x1b83; /* @(0x8c07a798,pc) */
L_8c07a764: /* 03ec */
    r3 = (uint32_t)(int32_t)c_p8s(ram, (r14 + r0), &gated);
L_8c07a766: /* 633c */
    r3 = r3 & 0xFFu;
L_8c07a768: /* 6233 */
    r2 = r3;
L_8c07a76a: /* 1f3d */
    c_wr32(ram, r15 + 52, r3);
L_8c07a76c: /* 9015 */
    r0 = (uint32_t)(int32_t)(int16_t)0x1b85; /* @(0x8c07a79a,pc) */
L_8c07a76e: /* 0e24 */
    c_wr8(ram, (r14 + r0), (uint8_t)r2);
L_8c07a770: /* 9014 */
    r0 = (uint32_t)(int32_t)(int16_t)0x1b86; /* @(0x8c07a79c,pc) */
L_8c07a772: /* 53fd */
    r3 = c_p32(ram, r15 + 52, &gated);
L_8c07a774: /* 0e34 */
    c_wr8(ram, (r14 + r0), (uint8_t)r3);
L_8c07a776: /* 9012 */
    r0 = (uint32_t)(int32_t)(int16_t)0x0898; /* @(0x8c07a79e,pc) */
L_8c07a778: /* 02fe */
    r2 = c_p32(ram, (r15 + r0), &gated);
L_8c07a77a: /* 9011 */
    r0 = (uint32_t)(int32_t)(int16_t)0x1b88; /* @(0x8c07a7a0,pc) */
L_8c07a77c: /* 6322 */
    r3 = c_p32(ram, r2, &gated);
L_8c07a77e: /* 0e36 */
    c_wr32(ram, (r14 + r0), r3);
L_8c07a780: /* e001 */
    r0 = (uint32_t)(int32_t)1;
L_8c07a782: /* 910e */
    r1 = (uint32_t)(int32_t)(int16_t)0x087c; /* @(0x8c07a7a2,pc) */
L_8c07a784: /* 3f1c */
    r15 += r1;
L_8c07a786: /* 4f26 */
    pr = c_rd32(ram, r15); r15 += 4;
L_8c07a788: /* 6cf6 */
    r12 = c_p32(ram, r15, &gated); r15 += 4;
L_8c07a78a: /* 6df6 */
    r13 = c_p32(ram, r15, &gated); r15 += 4;
L_8c07a78c: /* 000b */
    r14 = c_p32(ram, r15, &gated); r15 += 4;
    o->r0 = r0; o->r1 = r1; o->r2 = r2; o->r3 = r3;
    o->r4 = r4; o->r5 = r5; o->r6 = r6; o->r7 = r7;
    o->r8 = r8; o->r9 = r9; o->r10 = r10; o->r11 = r11;
    o->r12 = r12; o->r13 = r13; o->r14 = r14; o->r15 = r15;
    o->pr = pr; o->sr = (in_sr & ~1u) | (T ? 1u : 0u);
    o->gated = gated;
    o->fr0 = fr[0]; o->fr1 = fr[1]; o->fr2 = fr[2]; o->fr3 = fr[3];
    o->fr4 = fr[4]; o->fr5 = fr[5]; o->fr6 = fr[6]; o->fr7 = fr[7];
    o->fr8 = fr[8]; o->fr9 = fr[9]; o->fr10 = fr[10]; o->fr11 = fr[11];
    o->fr12 = fr[12]; o->fr13 = fr[13]; o->fr14 = fr[14]; o->fr15 = fr[15];
    return;
}
