/* tests/taskvm_replay.c — M34 task-VM helper checks. */
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "../src/sys/mainloop.h"

extern int      vf3_node_unlink(gaddr node);
extern void     vf3_node_finalize(gaddr node);
extern uint32_t vf3_node_get_waiter(gaddr node);
extern uint32_t vf3_node_get_link16(gaddr node);
extern uint32_t vf3_node_get_link08(gaddr node);
extern int      vf3_node_cursor_bump(gaddr node, int32_t delta, uint32_t mode);
extern uint32_t vf3_mgr_thunk(gaddr cell, uint32_t slot, uint32_t a0,
                              uint32_t a1, uint32_t a2, uint32_t a3);

#define GB      0x8C800000u
#define A_NODE  (GB + 0x100)
#define A_KLASS (GB + 0x200)
#define A_VT    (GB + 0x240)
#define A_MGR   (GB + 0x300)
#define A_CELL  (GB + 0x600)
#define A_FN    (GB + 0x900)

static uint8_t arena[4096];
static int fails = 0, g_call = 0;
static uint32_t g_call_arg;
static uint32_t owner_vcall(uint32_t arg) { g_call++; g_call_arg = arg; return 0; }
static uint32_t mgr_fn(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3)
    { g_call++; return a0 + a1 + a2 + a3; }

#define CHK(c) do { if (!(c)) { printf("  FAIL line %d: %s\n", __LINE__, #c); ++fails; } } while (0)

int main(void)
{
    memset(arena, 0, sizeof arena);
    vf3_sys_bind_ram(arena, GB);
    vf3_sys_register(A_FN, owner_vcall);
    vf3_sys_register(A_FN + 4, mgr_fn);

    /* finalize: null/idle no-crash, busy w/st=2 -> unlink path */
    vf3_node_finalize(0);
    vf3_sys_wr16(A_NODE + 0x48, 0);
    vf3_node_finalize(A_NODE);
    CHK(vf3_sys_rd16(A_NODE + 0x48) == 0);

    vf3_sys_wr32(A_NODE, A_KLASS);
    vf3_sys_wr32(A_KLASS + 0x28, A_NODE);     /* owner->waiter = node */
    vf3_sys_wr32(A_KLASS + 0x14, A_VT);
    vf3_sys_wr32(A_VT + 0x14, A_FN);
    vf3_sys_wr16(A_NODE + 0x48, 1);
    vf3_sys_wr16(A_NODE + 0x4C, 2);
    vf3_sys_wr32(A_NODE + 0x3C, 0xFEED);
    g_call = 0;
    vf3_node_finalize(A_NODE);
    CHK(vf3_sys_rd16(A_NODE + 0x4C) == 0);
    CHK(vf3_sys_rd16(A_NODE + 0x48) == 0);
    CHK(g_call == 1 && g_call_arg == 0xFEED);

    /* unlink guards */
    vf3_sys_wr16(A_NODE + 0x4C, 0);
    CHK(vf3_node_unlink(A_NODE) == -10);      /* not busy */
    vf3_sys_wr16(A_NODE + 0x48, 1);
    CHK(vf3_node_unlink(A_NODE) == 0);        /* idle: just clears st   */
    CHK(vf3_sys_rd16(A_NODE + 0x4C) == 0);
    vf3_sys_wr16(A_NODE + 0x4C, 2);
    vf3_sys_wr32(A_KLASS + 0x28, GB + 0xbeef);/* stale owner */
    CHK(vf3_node_unlink(A_NODE) == -13);

    /* getters */
    vf3_sys_wr32(A_NODE + 0x0C, 11);
    vf3_sys_wr32(A_NODE + 0x10, 22);
    vf3_sys_wr32(A_NODE + 0x08, 33);
    CHK(vf3_node_get_waiter(A_NODE) == 11);
    CHK(vf3_node_get_link16(A_NODE) == 22);
    CHK(vf3_node_get_link08(A_NODE) == 33);
    vf3_sys_wr16(A_NODE + 0x48, 0);
    CHK(vf3_node_get_waiter(A_NODE) == 0);

    /* cursor bump */
    vf3_sys_wr16(A_NODE + 0x48, 1);
    vf3_sys_wr32(A_NODE + 0x14, 100);         /* cur = limit = 100      */
    CHK(vf3_node_cursor_bump(A_NODE, 5, 1) == -17);    /* 105 > limit   */
    CHK(vf3_node_cursor_bump(A_NODE, -120, 1) == -17); /* negative      */
    CHK(vf3_node_cursor_bump(A_NODE, -40, 1) == 0);    /* 60 <= 100     */
    CHK((int32_t)vf3_sys_rd32(A_NODE + 0x14) == 60);
    CHK(vf3_node_cursor_bump(A_NODE, 0, 3) == -16);
    CHK(vf3_node_cursor_bump(A_NODE, 25, 0) == 0);     /* new = 25      */
    CHK((int32_t)vf3_sys_rd32(A_NODE + 0x14) == 25);

    /* mgr thunk: cell unset -> 0; set -> route */
    CHK(vf3_mgr_thunk(A_CELL, 0x34, 1, 2, 3, 4) == 0);
    vf3_sys_wr32(A_CELL, A_MGR);
    vf3_sys_wr32(A_MGR + 0x34, A_FN + 4);
    CHK(vf3_mgr_thunk(A_CELL, 0x34, 1, 2, 3, 4) == 10);

    printf("taskvm_replay: %s\n", fails ? "FAIL" : "PASS");
    return fails ? 1 : 0;
}
