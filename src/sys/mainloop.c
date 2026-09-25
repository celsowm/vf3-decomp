/* sys/mainloop.c — per-frame task dispatcher port (f_8c034852).
 *
 * Faithful transliteration of the true-image listing; on-CPU registers map:
 *   r12 = root slot (&root_obj)      r14 = chain head node
 *   r10 = frame (r15+4 on-CPU)       r11 = handler result (r0)
 *   r13 = 0                          r9  = 2
 * vcall chain: root_obj->f14 -> sub ; sub->f10 -> handler ;
 *   r0 = handler(node->payload, frame)
 */
#include "mainloop.h"
#include <string.h>

static uint8_t *g_ram;
static gaddr    g_base;

void vf3_sys_bind_ram(void *host_base, gaddr guest_base)
{
    g_ram = (uint8_t *)host_base;
    g_base = guest_base;
}

static uint8_t *gp(gaddr a) { return g_ram + (a - g_base); }

uint32_t vf3_sys_rd32(gaddr a) { uint32_t v; memcpy(&v, gp(a), 4); return v; }
uint16_t vf3_sys_rd16(gaddr a) { uint16_t v; memcpy(&v, gp(a), 2); return v; }
void vf3_sys_wr32(gaddr a, uint32_t v) { memcpy(gp(a), &v, 4); }
void vf3_sys_wr16(gaddr a, uint16_t v) { memcpy(gp(a), &v, 2); }

/* ---- host registry ---- */
#define MAX_REG 64
static gaddr  reg_ga[MAX_REG];
static void  *reg_fn[MAX_REG];
static int    reg_n;

void vf3_sys_register(gaddr ga, void *hostfn)
{
    if (reg_n < MAX_REG) { reg_ga[reg_n] = ga; reg_fn[reg_n++] = hostfn; }
}

void *vf3_sys_lookup(gaddr ga)
{
    for (int i = 0; i < reg_n; ++i)
        if (reg_ga[i] == ga)
            return reg_fn[i];
    return 0;
}

int vf3_frame_dispatch(gaddr root_obj, gaddr frame)
{
    if (!root_obj)
        return -9;

    vf3_sys_wr32(root_obj + R_MARKER, 1);               /* 0x8c03486a    */
    const gaddr node = vf3_sys_rd32(root_obj + R_CHAIN);/* 0x8c03486c    */
    const uint32_t payload = node ? vf3_sys_rd32(node + N_PAYLOAD) : 0;

    const gaddr sub = vf3_sys_rd32(root_obj + R_VTBLA); /* 0x8c034880    */
    VF3NodeHandler handler =
        (VF3NodeHandler)vf3_sys_lookup(vf3_sys_rd32(sub + 0x10));
    if (!handler)
        return -2;
    const uint32_t r0 = handler(payload, frame);        /* jsr @r11      */
    const int result = (int)r0;

    if (!node)
        goto out_clear;                                 /* bra 0x8c034990 */

    switch (r0) {
    case 0:
    case 1:                                             /* 0x8c0348b6    */
        vf3_sys_wr32(root_obj + R_CHAIN, 0);            /* root->f40 = 0 */
        vf3_sys_wr16(node + N_W76_RESULT, (uint16_t)r0);
        vf3_sys_wr32(node + N_PAYLOAD, 0);              /* delay slot    */
        if (r0 == 1) {
            const uint16_t st = vf3_sys_rd16(node + N_W68_STATE);
            if (st == 1) {                              /* 0x8c0348c4.. */
                vf3_sys_wr32(node + N_BASE18, vf3_sys_rd32(frame));
                vf3_sys_wr32(node + N_ACCUM20,
                             vf3_sys_rd32(node + N_ACCUM20)
                             + vf3_sys_rd32(node + N_STEP1C));
                vf3_sys_wr16(node + N_W68_STATE, 0);
                vf3_sys_wr16(node + N_W70, 2);
                void (*cb)(uint32_t) = (void (*)(uint32_t))
                    vf3_sys_lookup(vf3_sys_rd32(node + N_CBPROGRESS));
                if (cb)                                 /* jsr @(24,r14) */
                    cb(vf3_sys_rd32(node + N_CBARG));
            } else if (st == 4) {                       /* 0x8c0348f0.. */
                vf3_sys_wr32(node + N_BASE18, vf3_sys_rd32(node + N_F20));
                vf3_sys_wr32(node + N_ACCUM20,
                             vf3_sys_rd32(node + N_ACCUM20)
                             + vf3_sys_rd32(node + N_STEP1C));
                vf3_sys_wr16(node + N_W70, 2);
            } else if (st == 6) {
                /* 0x8c03490e: jsr 0x8C0355A0(node) = node finalize/unlink
                 * (M34/M50: vf3_node_finalize clears busy, unlinks when
                 * state==2). Registry-free local call keeps replay exact. */
                extern void vf3_node_finalize(gaddr);
                vf3_node_finalize(node);
            }
            vf3_sys_wr16(node + N_W68_STATE, 0);        /* 0x8c034914..  */
        } else {
            vf3_sys_wr16(node + N_W68_STATE, 0);
        }
        break;
    case 4:
    case 5:
    case 6:                                             /* 0x8c03495a    */
        vf3_sys_wr16(node + N_W76_RESULT, (uint16_t)r0);
        vf3_sys_wr16(node + N_W78, (uint16_t)vf3_sys_rd32(frame));
        vf3_sys_wr32(node + N_CBARG, vf3_sys_rd32(frame + 4));
        vf3_sys_wr32(node + N_PAYLOAD, 0);
        vf3_sys_wr32(root_obj + R_CHAIN, 0);
        {
            void (*cb)(gaddr, uint16_t) = (void (*)(gaddr, uint16_t))
                vf3_sys_lookup(vf3_sys_rd32(node + N_CBPHASE));
            if (cb)
                cb(node, vf3_sys_rd16(node + N_W78));
        }
        break;
    case 7: {                                           /* 0x8c03491a    */
        const gaddr api = vf3_sys_rd32(root_obj + R_API);
        uint32_t (*exith)(uint32_t, gaddr) =
            (uint32_t (*)(uint32_t, gaddr))vf3_sys_lookup(
                vf3_sys_rd32(api + 0x24));
        if (exith) {
            const uint32_t er = exith(payload, frame);
            if (er == 1)
                vf3_sys_wr32(node + N_BASE18, vf3_sys_rd32(frame));
            /* er==0: removal path (0x8c03492a..) over a data island —
             * TODO from next trace; marker discipline kept below.       */
        }
        break;
    }
    default:                                            /* 0x8c034984    */
        vf3_sys_wr16(node + N_W76_RESULT, (uint16_t)(uint8_t)r0);
        vf3_sys_wr32(node + N_PAYLOAD, 0);
        vf3_sys_wr32(root_obj + R_CHAIN, 0);
        break;
    }

out_clear:                                              /* 0x8c034990    */
    vf3_sys_wr32(root_obj + R_MARKER, 0);
    return result;
}
