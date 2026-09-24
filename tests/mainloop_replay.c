/* tests/mainloop_replay.c — f_8c034852 dispatcher path coverage.
 *
 * Guest-arena model: all in-struct pointers are fake DC addresses into one
 * arena (sys-bound); host implementations registered by guest address.
 */
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "../src/sys/mainloop.h"

#define GB        0x8C400000u
static uint8_t arena[8192];

#define A_ROOT    (GB + 0x100)
#define A_SUB     (GB + 0x200)
#define A_API     (GB + 0x280)
#define A_NODE    (GB + 0x300)
#define A_FRAME   (GB + 0x400)
#define A_HANDLER (GB + 0x500)
#define A_EXIT    (GB + 0x504)
#define A_CBPROG  (GB + 0x508)
#define A_CBPHASE (GB + 0x50C)

static uint32_t g_result;
static int      g_handler_called, g_cbprog_called, g_cbphase_called;
static uint32_t g_got_payload, g_got_f0, g_got_f1;

static uint32_t handler(uint32_t payload, gaddr frame)
{
    g_handler_called++;
    g_got_payload = payload;
    g_got_f0 = vf3_sys_rd32(frame);
    g_got_f1 = vf3_sys_rd32(frame + 4);
    return g_result;
}

static uint32_t exit_handler(uint32_t payload, gaddr frame)
{
    (void)payload; (void)frame;
    return 1;
}

static void cb_prog(uint32_t arg)         { (void)arg; g_cbprog_called++; }
static void cb_phase(gaddr n, uint16_t v) { (void)n; (void)v; g_cbphase_called++; }

static void setup(uint32_t res)
{
    memset(arena, 0, sizeof arena);
    vf3_sys_bind_ram(arena, GB);
    vf3_sys_register(A_HANDLER, handler);
    vf3_sys_register(A_EXIT,    exit_handler);
    vf3_sys_register(A_CBPROG,  cb_prog);
    vf3_sys_register(A_CBPHASE, cb_phase);

    vf3_sys_wr32(A_ROOT + R_VTBLA, A_SUB);
    vf3_sys_wr32(A_SUB + 0x10,     A_HANDLER);
    vf3_sys_wr32(A_ROOT + R_API,   A_API);
    vf3_sys_wr32(A_API + 0x24,     A_EXIT);
    vf3_sys_wr32(A_ROOT + R_CHAIN, A_NODE);
    vf3_sys_wr32(A_NODE + N_PAYLOAD, 0xDEADBEEFu);
    vf3_sys_wr32(A_NODE + N_CBPROGRESS, A_CBPROG);
    vf3_sys_wr32(A_NODE + N_CBPHASE,    A_CBPHASE);
    g_result = res;
    g_handler_called = g_cbprog_called = g_cbphase_called = 0;

    vf3_sys_wr32(A_FRAME,     0xAAAABBBBu);
    vf3_sys_wr32(A_FRAME + 4, 0xCCCCDDDDu);
}

static int fails = 0;
#define CHK(c) do { if (!(c)) { printf("  FAIL line %d: %s\n", __LINE__, #c); ++fails; } } while (0)

int main(void)
{
    setup(0);
    {
        int r = vf3_frame_dispatch(A_ROOT, A_FRAME);
        CHK(r == 0);
        CHK(g_handler_called == 1 && g_got_payload == 0xDEADBEEFu);
        CHK(vf3_sys_rd32(A_ROOT + R_MARKER) == 0);
        CHK(vf3_sys_rd16(A_NODE + N_W68_STATE) == 0);
        CHK(vf3_sys_rd16(A_NODE + N_W76_RESULT) == 0);
        CHK(g_cbprog_called == 0);
    }

    setup(1);
    {
        vf3_sys_wr16(A_NODE + N_W68_STATE, 1);
        vf3_sys_wr32(A_NODE + N_STEP1C, 5);
        vf3_sys_wr32(A_NODE + N_ACCUM20, 100);
        vf3_sys_wr32(A_NODE + N_CBARG, 0x1234);
        int r = vf3_frame_dispatch(A_ROOT, A_FRAME);
        CHK(r == 1);
        CHK(vf3_sys_rd32(A_NODE + N_BASE18) == 0xAAAABBBBu);
        CHK(vf3_sys_rd32(A_NODE + N_ACCUM20) == 105);
        CHK(vf3_sys_rd16(A_NODE + N_W68_STATE) == 0);
        CHK(vf3_sys_rd16(A_NODE + N_W70) == 2);
        CHK(g_cbprog_called == 1);
    }

    setup(5);
    {
        int r = vf3_frame_dispatch(A_ROOT, A_FRAME);
        CHK(r == 5);
        CHK(vf3_sys_rd16(A_NODE + N_W78) == 0xBBBB);
        CHK(vf3_sys_rd32(A_NODE + N_CBARG) == 0xCCCCDDDDu);
        CHK(vf3_sys_rd32(A_NODE + N_PAYLOAD) == 0);
        CHK(vf3_sys_rd32(A_ROOT + R_CHAIN) == 0);
        CHK(g_cbphase_called == 1);
    }

    setup(7);
    {
        int r = vf3_frame_dispatch(A_ROOT, A_FRAME);
        CHK(r == 7);
        CHK(vf3_sys_rd32(A_NODE + N_BASE18) == 0xAAAABBBBu);
        CHK(vf3_sys_rd32(A_ROOT + R_MARKER) == 0);
    }

    setup(0x42);
    {
        int r = vf3_frame_dispatch(A_ROOT, A_FRAME);
        CHK(r == 0x42);
        CHK((vf3_sys_rd16(A_NODE + N_W76_RESULT) & 0xFF) == 0x42);
        CHK(vf3_sys_rd32(A_NODE + N_PAYLOAD) == 0);
    }

    setup(0);
    vf3_sys_wr32(A_ROOT + R_CHAIN, 0);   /* empty chain */
    {
        int r = vf3_frame_dispatch(A_ROOT, A_FRAME);
        CHK(r == 0);
        CHK(g_got_payload == 0);
    }

    printf("mainloop_replay: %s\n", fails ? "FAIL" : "PASS");
    return fails ? 1 : 0;
}
