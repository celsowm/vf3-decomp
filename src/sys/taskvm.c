/* sys/taskvm.c — task-VM node helpers (M34), true-image transliterations.
 *
 * Covered (extract/analysis/taskvm_helpers{,2}.txt):
 *   f_8c0355a0  node_finalize: clear busy word; unlink when state word==2
 *   f_8c035a4e  node_unlink_tail: link-wait + owner vtable call
 *   f_8c0355ca/5f4/60e  slot getters (return 1 + *out when busy)
 *   f_8c035628  mode dispatch getter (-10 bad node; mode 0/1/2 routes)
 *   f_8c035bf2 family = manager-singleton vtable thunk stubs:
 *     load *SINGLETON_CELL, tail-jump obj->vt[slot/4]  (slot 52 = alloc)
 *     slot-52 singleton cell 0x8C036198 -> ...0x8C0CC9E8 (verified)
 */
#include "mainloop.h"

/* node field offsets beyond mainloop.h */
#define N_VTBL     0x00   /* *node -> task class record                  */
#define N_F04      0x04
#define N_F08      0x08
#define N_F0C      0x0C
#define N_F0E      0x0E   /* w-list entry (getter f_8c0355ca target)     */
#define N_F10      0x10
#define N_F14      0x14
#define N_F18      0x18
#define N_F1C      0x1C
#define N_F28      0x28
#define N_F3C_     0x3C
#define N_F40_     0x40
#define N_W48_BUSY 0x48   /* busy/linked flag word                       */
#define N_W4C_ST   0x4C   /* state word (2 == pending-unlink)            */
#define N_F3C_DL   0x3C

static uint32_t rd32(gaddr a) { return vf3_sys_rd32(a); }
static void wr16(gaddr a, uint16_t v) { vf3_sys_wr16(a, v); }
static void wr32(gaddr a, uint32_t v) { vf3_sys_wr32(a, v); }

/* f_8c03550c — counterpart link op (paired with unlink; registry hook). */
static uint32_t (*link_op(gaddr node))(void) { (void)node; return 0; }

/* ---- f_8c035a4e ---- *//* f_8c035a4e: returns 0/-10/-13 or vcall result.
 * true flow: if klass->f28(40) == node: r1 = klass->f14->f14;
 * jsr @r1 with r4 = node->f3C; then bsr f_8c03550c(node). */
int vf3_node_unlink(gaddr node)
{
    if (!node || vf3_sys_rd16(node + N_W48_BUSY) == 0)
        return -10;
    if (vf3_sys_rd16(node + N_W4C_ST) != 2) {
        wr16(node + N_W4C_ST, 0);
        return 0;
    }
    uint32_t klass = rd32(node);
    if (rd32(klass + 0x28) != node)      /* owner->waiter must be node */
        return -13;
    uint32_t vt = rd32(klass + N_F14);
    uint32_t (*vcall)(uint32_t) =
        (uint32_t (*)(uint32_t))vf3_sys_lookup(rd32(vt + N_F14));
    if (vcall)
        (void)vcall(rd32(node + N_F3C_DL));
    wr16(node + N_W4C_ST, 0);
    return 0;
}

/* ---- f_8c0355a0 ---- */
void vf3_node_finalize(gaddr node)
{
    if (!node)
        return;
    if (vf3_sys_rd16(node + N_W48_BUSY) != 0) {
        if (vf3_sys_rd16(node + N_W4C_ST) == 2)
            (void)vf3_node_unlink(node);
        wr16(node + N_W48_BUSY, 0);
    }
}

/* ---- slot getters ---- */
static uint32_t getter(gaddr node, uint32_t field)
{
    if (!node || vf3_sys_rd16(node + N_W48_BUSY) == 0)
        return 0;
    return rd32(node + field);
}

uint32_t vf3_node_get_waiter(gaddr node) { return getter(node, 0x0C); }
uint32_t vf3_node_get_link16(gaddr node) { return getter(node, 0x10); }
uint32_t vf3_node_get_link08(gaddr node) { return getter(node, 0x08); }

/* ---- f_8c035628: cursor bump with bounds (verified 0x8c035628..72) ----
 * new = mode==0 ? delta : mode==1 ? cur+delta : mode==2 ? limit+delta;
 * reject (-17) when new < 0 or new > limit (node->f14 pre-read); else
 * node->f14 = new, return 0.  Bad/idle node -> -10. */
int vf3_node_cursor_bump(gaddr node, int32_t delta, uint32_t mode)
{
    if (!node || vf3_sys_rd16(node + N_W48_BUSY) == 0)
        return -10;
    const int32_t cur = (int32_t)rd32(node + N_F14);
    const int32_t limit = cur;            /* r7 = node->f14 (pre-write)  */
    int32_t newv;
    switch (mode) {
    case 0: newv = delta; break;
    case 1: newv = cur + delta; break;
    case 2: newv = limit + delta; break;  /* r6 = r5 + r7                */
    default: return -16;
    }
    if (newv < 0 || newv > limit)
        return -17;
    wr32(node + N_F14, (uint32_t)newv);
    return 0;
}

/* ---- manager thunk family (f_8c035bf2 etc.) --------------------------
 * Structural model only: read singleton cell, fetch vt slot, dispatch via
 * host registry (the real manager bodies are runtime-resolved).      */
uint32_t vf3_mgr_thunk(gaddr singleton_cell, uint32_t vt_slot_off,
                       uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3)
{
    uint32_t mgr = rd32(singleton_cell);
    if (!mgr)
        return 0;
    uint32_t (*fn)(uint32_t, uint32_t, uint32_t, uint32_t) =
        (uint32_t (*)(uint32_t, uint32_t, uint32_t, uint32_t))
            vf3_sys_lookup(rd32(mgr + vt_slot_off));
    return fn ? fn(a0, a1, a2, a3) : 0u;
}
