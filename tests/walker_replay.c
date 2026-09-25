/* tests/walker_replay.c — M45 walker slot + step checks. */
#include <stdio.h>
#include <stdint.h>
#include "../src/fight/walker.h"
#include "../src/sys/mainloop.h"

static int fails = 0;
static uint32_t last_arg = 0;
static uint32_t scene_fn(uint32_t a) { last_arg = a; return a + 1; }
static uint32_t helper_a(uint32_t a) { (void)a; return 7; }
static uint32_t helper_b(uint32_t a) { return a + 2; }

#define CHK(c) do { if (!(c)) { printf("  FAIL line %d: %s\n", __LINE__, #c); ++fails; } } while (0)

static uint8_t arena[4096];
#define GB 0x8C800000u

int main(void)
{
    int tail = -1;
    CHK(vf3_walker_slot(1, &tail) == 112 && tail == 0);
    CHK(vf3_walker_slot(5, &tail) == 0x756C && tail == 0);
    CHK(vf3_walker_slot(9, &tail) == 0x7662 && tail == 0);
    CHK(vf3_walker_slot(14, &tail) == 0x8570 && tail == 0);
    CHK(vf3_walker_slot(17, &tail) == 0xC4F0 && tail == 0);
    CHK(vf3_walker_slot(99, &tail) == 0 && tail == 1);

    for (int i = 0; i < (int)sizeof arena; i++) arena[i] = 0;
    vf3_sys_bind_ram(arena, GB);
    /* r13 base + word 112 holds handler arg 0x1234 */
    vf3_sys_wr32(GB + 112, 0x1234);
    VF3_Walker w = {helper_a, helper_b, scene_fn, GB, GB + 0x200};
    uint32_t arg = 0;
    uint32_t rc = vf3_walker_step(&w, 1, 10, &arg);
    CHK(arg == 0x1234 && last_arg == 0x1234 && rc == 0x1235);
    /* tail path: no scene_fn call arg, returns 0 when no fn */
    VF3_Walker w2 = {0, 0, 0, GB, GB};
    rc = vf3_walker_step(&w2, 99, 0, &arg);
    CHK(rc == 0 && arg == 0);

    printf("walker_replay: %s\n", fails ? "FAIL" : "PASS");
    return fails ? 1 : 0;
}
