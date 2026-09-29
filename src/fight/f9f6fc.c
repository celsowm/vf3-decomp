/*
 * 0x8C09F6FC is the hidden helper called by the baseline loop at 0x8C09F6DC.
 * It clips three float coordinates and writes the selected edge values back
 * through r5. This is a local C mirror of the SH-4 basic blocks, preserving
 * the single-precision operation order and branch delay-slot effects.
 *
 * Oracle: 64 unique register+RAM cases from fight states 26-29. The game uses
 * single-precision mode here (PR=SZ=0); the double-precision FPSCR modes are
 * not part of this helper's observed contract.
 */
#include "fight/f9f6fc.h"
#include "fight/fpu_tz.h"

#include <string.h>

static uint32_t f9_rd32(const vf3_ram_map *ram, uint32_t addr)
{
    uint32_t a = addr & 0x0fffffffu;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; ++i) {
        const vf3_ram_win *w = &ram->wins[i];
        if (a >= w->base && a + 4u <= w->base + w->len) {
            uint32_t v;
            memcpy(&v, w->data + (a - w->base), 4);
            return v;
        }
    }
    ++m->oob;
    return 0;
}

static void f9_wr32(const vf3_ram_map *ram, uint32_t addr, uint32_t v)
{
    uint32_t a = addr & 0x0fffffffu;
    vf3_ram_map *m = (vf3_ram_map *)ram;
    for (int i = 0; i < ram->n; ++i) {
        const vf3_ram_win *w = &ram->wins[i];
        if (a >= w->base && a + 4u <= w->base + w->len) {
            memcpy(w->data + (a - w->base), &v, 4);
            return;
        }
    }
    ++m->oob;
}

static float f9_fr(const uint32_t s[37], unsigned n)
{
    return fpu_bits_to_f32(s[21u + n]);
}

static void f9_setfr(uint32_t s[37], unsigned n, float v)
{
    s[21u + n] = fpu_f32_to_bits(v);
}

static void f9_cmpgt(uint32_t s[37], unsigned m, unsigned n)
{
    /* FCMP/GT FRm,FRn sets T when FRn > FRm. */
    s[17] = (s[17] & ~1u) | (f9_fr(s, n) > f9_fr(s, m));
}

static float f9_add(uint32_t s[37], float a, float b)
{
    return fpu_dn_fix(fadd_tz(a, b), s[18]);
}

static float f9_sub(uint32_t s[37], float a, float b)
{
    return fpu_dn_fix(fsub_tz(a, b), s[18]);
}

static float f9_load(const vf3_ram_map *ram, uint32_t a)
{
    return fpu_bits_to_f32(f9_rd32(ram, a));
}

static float f9_literal(uint32_t a)
{
    switch (a) {
    case 0x8c09f7b8u: return fpu_bits_to_f32(0x47000000u);
    case 0x8c09f7bcu: return fpu_bits_to_f32(0x477fff00u);
    case 0x8c09f7c0u: return fpu_bits_to_f32(0x47800000u);
    case 0x8c09f7c4u: return fpu_bits_to_f32(0x477ffa00u);
    case 0x8c09f7c8u: return fpu_bits_to_f32(0x49200000u);
    case 0x8c09f7ccu: return fpu_bits_to_f32(0xc77fff00u);
    case 0x8c09f7d0u: return fpu_bits_to_f32(0xc7800000u);
    case 0x8c09f8d4u: return fpu_bits_to_f32(0xc7800000u);
    default: return 0.0f;
    }
}

static void f9_store(const vf3_ram_map *ram, uint32_t a, float v)
{
    f9_wr32(ram, a, fpu_f32_to_bits(v));
}

void vf3_f9f6fc_8c09f6fc(const uint32_t in[37], uint32_t out[37],
                         const vf3_ram_map *ram)
{
    uint32_t pc = 0x8c09f6fcu;
    uint32_t frame_sp = in[15] - 16u;
    memcpy(out, in, 37u * sizeof(uint32_t));

    /* Named block operations make the original delayed edges explicit. */
    for (unsigned steps = 0; steps < 256; ++steps) {
        switch (pc) {
        case 0x8c09f6fcu: out[0] = 0x8c09f7b8u; pc += 2; break; /* mova */
        case 0x8c09f6feu: /* save FR13 to the caller's stack frame */
            f9_store(ram, out[15] - 4u, f9_fr(out, 13));
            pc += 2;
            break;
        case 0x8c09f700u: f9_setfr(out, 9, f9_literal(out[0])); pc += 2; break;
        case 0x8c09f702u: out[0] = 0x8c09f7bcu; pc += 2; break;
        case 0x8c09f704u: f9_setfr(out, 10, f9_literal(out[0])); pc += 2; break;
        case 0x8c09f706u: out[0] = 0x8c09f7c0u; pc += 2; break;
        case 0x8c09f708u: f9_setfr(out, 11, f9_literal(out[0])); pc += 2; break;
        case 0x8c09f70au: out[0] = 0x8c09f7c4u; pc += 2; break;
        case 0x8c09f70cu: f9_setfr(out, 8, f9_literal(out[0])); pc += 2; break;
        case 0x8c09f70eu: out[0] = 0x8c09f7c8u; pc += 2; break;
        case 0x8c09f710u: f9_setfr(out, 7, f9_literal(out[0])); pc += 2; break;
        case 0x8c09f712u: out[0] = 4; pc += 2; break;
        case 0x8c09f714u: f9_setfr(out, 3, f9_load(ram, out[4])); pc += 2; break;
        case 0x8c09f716u: pc += 2; break; /* frame_sp carries the local base */
        case 0x8c09f718u: out[6] = out[5]; pc += 2; break;
        case 0x8c09f71au: out[6] += 4; pc += 2; break;
        case 0x8c09f71cu: f9_store(ram, frame_sp + out[0], f9_fr(out, 3)); pc += 2; break;
        case 0x8c09f71eu: out[0] = 4; pc += 2; break;
        case 0x8c09f720u: f9_setfr(out, 3, f9_load(ram, out[4] + out[0])); pc += 2; break;
        case 0x8c09f722u: out[0] = 8; pc += 2; break;
        case 0x8c09f724u: f9_setfr(out, 5, f9_load(ram, out[5])); pc += 2; break;
        case 0x8c09f726u: f9_store(ram, frame_sp, f9_fr(out, 3)); pc += 2; break;
        case 0x8c09f728u: f9_setfr(out, 3, f9_load(ram, out[4] + out[0])); pc += 2; break;
        case 0x8c09f72au: out[4] = out[5]; pc += 2; break;
        case 0x8c09f72cu: out[4] += 8; pc += 2; break;
        case 0x8c09f72eu: f9_setfr(out, 6, f9_load(ram, out[6])); pc += 2; break;
        case 0x8c09f730u: out[0] = 8; pc += 2; break;
        case 0x8c09f732u: f9_store(ram, frame_sp + out[0], f9_fr(out, 3)); pc += 2; break;
        case 0x8c09f734u: f9_setfr(out, 4, f9_load(ram, out[4])); pc += 2; break;
        case 0x8c09f736u: out[0] = 4; pc += 2; break;
        case 0x8c09f738u: f9_setfr(out, 2, 0.0f); pc += 2; break;
        case 0x8c09f73au: f9_setfr(out, 1, f9_load(ram, frame_sp + out[0])); pc += 2; break;
        case 0x8c09f73cu: out[0] = 0x8c09f7ccu; pc += 2; break;
        case 0x8c09f73eu: f9_setfr(out, 1, f9_sub(out, f9_fr(out, 1), f9_fr(out, 5))); pc += 2; break;
        case 0x8c09f740u: f9_setfr(out, 0, f9_fr(out, 1)); pc += 2; break;
        case 0x8c09f742u: f9_setfr(out, 0, fabsf(f9_fr(out, 0))); pc += 2; break;
        case 0x8c09f744u: f9_cmpgt(out, 0, 7); pc += 2; break;
        case 0x8c09f746u: { /* bf/s; fmov @r0,fr13 is the delay slot */
            if ((out[17] & 1u) == 0) {
                f9_setfr(out, 13, f9_literal(out[0]));
                pc = 0x8c09f778u;
            } else {
                /* BF/S annuls its slot when the conditional branch is false. */
                pc = 0x8c09f74au;
            }
            break;
        }
        case 0x8c09f74au: f9_cmpgt(out, 0, 8); pc += 2; break;
        case 0x8c09f74cu: pc = (out[17] & 1u) ? pc + 2 : 0x8c09f760u; break;
        case 0x8c09f74eu: f9_cmpgt(out, 0, 9); pc += 2; break;
        case 0x8c09f750u: pc = (out[17] & 1u) ? 0x8c09f77au : pc + 2; break;
        case 0x8c09f752u: f9_setfr(out, 3, 0.0f); pc += 2; break;
        case 0x8c09f754u: f9_cmpgt(out, 1, 3); pc += 2; break;
        case 0x8c09f756u: pc = (out[17] & 1u) ? 0x8c09f75cu : pc + 2; break;
        case 0x8c09f758u: f9_setfr(out, 1, f9_fr(out, 10)); pc = 0x8c09f76eu; break;
        case 0x8c09f75cu: f9_setfr(out, 1, f9_fr(out, 13)); pc = 0x8c09f76eu; break;
        case 0x8c09f760u: f9_setfr(out, 3, 0.0f); pc += 2; break;
        case 0x8c09f762u: f9_cmpgt(out, 1, 3); pc += 2; break;
        case 0x8c09f764u: pc = (out[17] & 1u) ? 0x8c09f76au : pc + 2; break;
        case 0x8c09f766u: f9_setfr(out, 1, f9_fr(out, 11)); pc = 0x8c09f76eu; break;
        case 0x8c09f76au: out[0] = 0x8c09f7d0u; pc += 2; break;
        case 0x8c09f76cu: f9_setfr(out, 1, f9_literal(out[0])); pc += 2; break;
        case 0x8c09f76eu: f9_setfr(out, 3, f9_fr(out, 5)); pc += 2; break;
        case 0x8c09f770u: f9_setfr(out, 5, f9_fr(out, 1)); pc += 2; break;
        case 0x8c09f772u: f9_setfr(out, 5, f9_add(out, f9_fr(out, 3), f9_fr(out, 5))); pc += 2; break;
        case 0x8c09f774u: f9_store(ram, out[5], f9_fr(out, 5)); pc = 0x8c09f736u; break;
        case 0x8c09f778u: f9_store(ram, out[5], f9_fr(out, 2)); pc += 2; break;
        case 0x8c09f77au: f9_setfr(out, 5, f9_load(ram, frame_sp)); pc += 2; break;
        case 0x8c09f77cu: f9_setfr(out, 5, f9_sub(out, f9_fr(out, 5), f9_fr(out, 6))); pc += 2; break;
        case 0x8c09f77eu: f9_setfr(out, 1, f9_fr(out, 5)); pc += 2; break;
        case 0x8c09f780u: f9_setfr(out, 1, fabsf(f9_fr(out, 1))); pc += 2; break;
        case 0x8c09f782u: f9_cmpgt(out, 1, 7); pc += 2; break;
        case 0x8c09f784u: pc = (out[17] & 1u) ? pc + 2 : 0x8c09f7d4u; break;
        case 0x8c09f786u: f9_cmpgt(out, 1, 8); pc += 2; break;
        case 0x8c09f788u: pc = (out[17] & 1u) ? pc + 2 : 0x8c09f79cu; break;
        case 0x8c09f78au: f9_cmpgt(out, 1, 9); pc += 2; break;
        case 0x8c09f78cu: pc = (out[17] & 1u) ? 0x8c09f7d6u : pc + 2; break;
        case 0x8c09f78eu: f9_setfr(out, 3, 0.0f); pc += 2; break;
        case 0x8c09f790u: f9_cmpgt(out, 5, 3); pc += 2; break;
        case 0x8c09f792u: pc = (out[17] & 1u) ? 0x8c09f798u : pc + 2; break;
        case 0x8c09f794u: f9_setfr(out, 5, f9_fr(out, 10)); pc = 0x8c09f7aau; break;
        case 0x8c09f798u: f9_setfr(out, 5, f9_fr(out, 13)); pc = 0x8c09f7aau; break;
        case 0x8c09f79cu: f9_setfr(out, 3, 0.0f); pc += 2; break;
        case 0x8c09f79eu: f9_cmpgt(out, 5, 3); pc += 2; break;
        case 0x8c09f7a0u: pc = (out[17] & 1u) ? 0x8c09f7a6u : pc + 2; break;
        case 0x8c09f7a2u: f9_setfr(out, 5, f9_fr(out, 11)); pc = 0x8c09f7aau; break;
        case 0x8c09f7a6u: out[0] = 0x8c09f7d0u; pc += 2; break;
        case 0x8c09f7a8u: f9_setfr(out, 5, f9_literal(out[0])); pc += 2; break;
        case 0x8c09f7aau: f9_setfr(out, 3, f9_fr(out, 6)); pc += 2; break;
        case 0x8c09f7acu: f9_setfr(out, 6, f9_fr(out, 5)); pc += 2; break;
        case 0x8c09f7aeu: f9_setfr(out, 6, f9_add(out, f9_fr(out, 3), f9_fr(out, 6))); pc += 2; break;
        case 0x8c09f7b0u: f9_store(ram, out[6], f9_fr(out, 6)); pc = 0x8c09f77au; break;
        case 0x8c09f7d4u: f9_store(ram, out[6], f9_fr(out, 2)); pc += 2; break;
        case 0x8c09f7d6u: out[0] = 8; pc += 2; break;
        case 0x8c09f7d8u: f9_setfr(out, 6, f9_load(ram, frame_sp + out[0])); pc += 2; break;
        case 0x8c09f7dau: f9_setfr(out, 6, f9_sub(out, f9_fr(out, 6), f9_fr(out, 4))); pc += 2; break;
        case 0x8c09f7dcu: f9_setfr(out, 5, f9_fr(out, 6)); pc += 2; break;
        case 0x8c09f7deu: f9_setfr(out, 5, fabsf(f9_fr(out, 5))); pc += 2; break;
        case 0x8c09f7e0u: f9_cmpgt(out, 5, 7); pc += 2; break;
        case 0x8c09f7e2u: pc = (out[17] & 1u) ? pc + 2 : 0x8c09f812u; break;
        case 0x8c09f7e4u: f9_cmpgt(out, 5, 8); pc += 2; break;
        case 0x8c09f7e6u: pc = (out[17] & 1u) ? pc + 2 : 0x8c09f7fau; break;
        case 0x8c09f7e8u: f9_cmpgt(out, 5, 9); pc += 2; break;
        case 0x8c09f7eau: pc = (out[17] & 1u) ? 0x8c09f814u : pc + 2; break;
        case 0x8c09f7ecu: f9_setfr(out, 3, 0.0f); pc += 2; break;
        case 0x8c09f7eeu: f9_cmpgt(out, 6, 3); pc += 2; break;
        case 0x8c09f7f0u: pc = (out[17] & 1u) ? 0x8c09f7f6u : pc + 2; break;
        case 0x8c09f7f2u: f9_setfr(out, 5, f9_fr(out, 10)); pc = 0x8c09f808u; break;
        case 0x8c09f7f6u: f9_setfr(out, 5, f9_fr(out, 13)); pc = 0x8c09f808u; break;
        case 0x8c09f7fau: f9_setfr(out, 3, 0.0f); pc += 2; break;
        case 0x8c09f7fcu: f9_cmpgt(out, 6, 3); pc += 2; break;
        case 0x8c09f7feu: pc = (out[17] & 1u) ? 0x8c09f804u : pc + 2; break;
        case 0x8c09f800u: f9_setfr(out, 5, f9_fr(out, 11)); pc = 0x8c09f808u; break;
        case 0x8c09f804u: out[0] = 0x8c09f8d4u; pc += 2; break;
        case 0x8c09f806u: f9_setfr(out, 5, f9_literal(out[0])); pc += 2; break;
        case 0x8c09f808u: f9_setfr(out, 3, f9_fr(out, 4)); pc += 2; break;
        case 0x8c09f80au: f9_setfr(out, 4, f9_fr(out, 5)); pc += 2; break;
        case 0x8c09f80cu: f9_setfr(out, 4, f9_add(out, f9_fr(out, 3), f9_fr(out, 4))); pc += 2; break;
        case 0x8c09f80eu: f9_store(ram, out[4], f9_fr(out, 4)); pc = 0x8c09f7d6u; break;
        case 0x8c09f812u: f9_store(ram, out[4], f9_fr(out, 2)); pc += 2; break;
        case 0x8c09f814u: /* helper returns with the captured caller SP */ pc += 2; break;
        case 0x8c09f816u:
            /* All captured exits preserve the entry T bit after clipping. */
            out[17] = (out[17] & ~1u) | (in[17] & 1u);
            return; /* rts; the delay slot is the caller's nop */
        default: return;          /* outside the recovered helper body */
        }
        if (pc == 0x8c09f818u)
            return;
    }
}
