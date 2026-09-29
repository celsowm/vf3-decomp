/* SH-4 0x8C08C788: gate a state update on flags and signed-field distance. */
#include "fight/c788.h"

#include <string.h>

static uint32_t canon(uint32_t a) { return a & 0x0FFFFFFFu; }

static uint32_t rd32(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t a = canon(addr);
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; ++i) {
        const vf3_ram_win *w = &ram->wins[i];
        if (a >= w->base && a + 4u <= w->base + w->len) {
            uint32_t v;
            memcpy(&v, w->data + a - w->base, 4);
            return v;
        }
    }
    ++m->oob;
    return 0;
}

static int16_t rd16s(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t a = canon(addr);
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; ++i) {
        const vf3_ram_win *w = &ram->wins[i];
        if (a >= w->base && a + 2u <= w->base + w->len) {
            int16_t v;
            memcpy(&v, w->data + a - w->base, 2);
            return v;
        }
    }
    ++m->oob;
    return 0;
}

static uint8_t rd8(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t a = canon(addr);
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; ++i) {
        const vf3_ram_win *w = &ram->wins[i];
        if (a >= w->base && a < w->base + w->len)
            return w->data[a - w->base];
    }
    ++m->oob;
    return 0;
}

static void wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t value)
{
    uint32_t a = canon(addr);
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; ++i) {
        const vf3_ram_win *w = &ram->wins[i];
        if (a >= w->base && a + 4u <= w->base + w->len) {
            memcpy(w->data + a - w->base, &value, 4);
            return;
        }
    }
    ++m->oob;
}

static void set_t(uint32_t out[37], int t)
{
    out[17] = (out[17] & ~1u) | (uint32_t)(t != 0);
}

int vf3_c788_guard(const uint32_t in[37], uint32_t out[37],
                   const vf3_ram_map *ram)
{
    uint32_t r0 = in[0], r1 = in[1], r2 = in[2], r3, r4 = in[4], r5 = in[4];
    uint32_t r6 = in[6], r14 = in[14], sp = in[15];
    uint32_t random, bound;
    int divided = 0;
    int t;

    memcpy(out, in, 37u * sizeof(uint32_t));
    /* sts.l pr,@-r15 */
    wr32(ram, sp - 4u, in[16]);

    r3 = 0x00800000u;
    r6 = rd32(ram, r14 + 16u);
    t = (r3 & r6) == 0;
    r4 = rd32(ram, r14);             /* delay slot of bf/s */
    if (!t)
        goto done;

    r3 = 4u;
    t = (r3 & r4) == 0;
    if (!t)
        goto done;
    r3 = 1u;
    t = (r3 & r4) == 0;
    if (!t)
        goto done;

    r3 = 0x80000000u;
    r6 = rd32(ram, r14 + 28u);
    t = (r3 & r6) == 0;
    r4 = rd32(ram, r14 + 48u);       /* delay slot of bf/s */
    if (!t)
        goto done;

    r3 = 0x20020000u;
    t = (r3 & r4) == 0;
    if (!t)
        goto done;

    r0 = 72u;
    r6 = rd32(ram, r14 + r0);
    r0 = (uint32_t)(int32_t)rd16s(ram, r6 + 30u);
    r4 = r0;
    r0 = 106u;
    r6 = (uint32_t)(int32_t)rd16s(ram, r6 + r0);
    r4 -= r6;
    t = (int32_t)r4 >= 0;            /* cmp/pz */
    if (!t)
        r4 = 0u - r4;

    r2 = 0x2000u;
    t = (int32_t)r4 >= (int32_t)r2; /* cmp/ge */
    if (!t)
        goto done;

    /* mov.b @(58,r5),r3; extu.b r3,r3; call RNG; delay stores the bound. */
    r0 = rd8(ram, r5 + 58u);
    wr32(ram, sp - 8u, r0);
    r2 = 0x0C0C9CE6u;

    /* 0x8C0C9CE6: state = state*0x5d588b65+1; return bits 16..30. */
    {
        const uint32_t state_addr = 0x0C29BD74u;
        uint32_t state = rd32(ram, state_addr);
        state = state * 0x5D588B65u + 1u;
        wr32(ram, state_addr, state);
        wr32(ram, sp - 12u, in[19]); /* helper saves/restores MACL */
        r5 = state >> 16;
        random = r5 & 0x7FFFu;
    }

    /* 0x8C042E44 returns unsigned r1 % bound (and quotient in r1).
       The division helper preserves r3/r4 through its stack saves. */
    r3 = 0x0C042E44u;
    r1 = random;
    bound = rd32(ram, sp - 8u);
    r4 = random;
    if (bound == 0) {
        wr32(ram, 0x0C1A5A60u, 0x44Eu);
        wr32(ram, sp - 12u, 0x0C0C9CE6u); /* div helper saves incoming r2 */
        r1 = 0x0C1A5A60u;
        r0 = 0;
    } else {
        /* The SDK's div1 loop returns its quotient in r1 and remainder r0. */
        wr32(ram, sp - 12u, r3);
        wr32(ram, sp - 16u, r4);
        r1 = (random / bound) >> 1;
        r0 = random % bound;
        divided = r0 == 0 ? 2 : 1; /* final helper Q follows exact remainder */
    }
    r4 = r0;
    t = r4 == 0;                    /* tst r4,r4; bt success */
    if (t) {
        r2 = 14u;
        wr32(ram, r14 + 44u, r2);
        r0 = 1;
        goto epilogue;
    }

done:
    r0 = 0;
epilogue:
    sp += 4u;                        /* epilogue pops caller's saved r14 */
    r14 = rd32(ram, in[15]);
    out[0] = r0; out[1] = r1; out[2] = r2; out[3] = r3; out[4] = r4;
    out[5] = r5; out[6] = r6; out[14] = r14; out[15] = sp;
    out[16] = in[16];
    set_t(out, t);
    if (divided)
        out[17] = (out[17] & ~0x100u) | (divided == 2 ? 0x100u : 0u);
    return 0;
}
