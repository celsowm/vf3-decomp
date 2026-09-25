/* tests/mtmount_replay.c — M52/M53 mount record + slot parse checks. */
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "../src/fight/mt_mount.h"

static int fails = 0;
#define CHK(c) do { if (!(c)) { printf("  FAIL line %d: %s\n", __LINE__, #c); ++fails; } } while (0)

static uint8_t file_img[0x10000];
static uint8_t resident[0x10000];

static void wr32(uint8_t *p, uint32_t v)
{
    p[0]=(uint8_t)v; p[1]=(uint8_t)(v>>8); p[2]=(uint8_t)(v>>16); p[3]=(uint8_t)(v>>24);
}

int main(void)
{
    memset(file_img, 0, sizeof file_img);
    memset(resident, 0, sizeof resident);
    /* slot table: slot 10 @0x8AC0 len 0x80, slot 11 @0x8B40 */
    wr32(file_img + 10*4, 0x8AC0);
    wr32(file_img + 11*4, 0x8B40);
    memset(file_img + 0x8AC0, 0xAB, 0x80);
    /* fake motion hdr at record start */
    wr32(file_img + 0x8AC0, 0x8AD0);
    wr32(file_img + 0x8AC0+4, 0x8AE0);
    wr32(file_img + 0x8AC0+8, 0x8AF0);

    VF3MtMount m;
    memset(&m, 0, sizeof m);
    m.file = file_img; m.file_len = sizeof file_img;
    m.resident = resident; m.resident_len = sizeof resident;
    m.ram_base = VF3_MT_BASE;

    uint32_t slots[VF3_MT_SLOTS];
    CHK(vf3_mt_parse_slots(file_img, sizeof file_img, slots, VF3_MT_SLOTS) == 0);
    CHK(slots[10] == 0x8AC0);

    int rl = vf3_mt_mount_record(&m, 10);
    CHK(rl == 0x80);
    CHK(m.slot_map[10] == 0x8AC0);
    CHK(resident[0x8AC0] == 0xD0 || resident[0x8AC0] == 0xAB ||
        resident[0x8AC0] != 0);
    /* hdr ptrs rewritten to resident-abs (ram_base + file_off) */
    uint32_t c0 = (uint32_t)resident[0x8AC0] |
                  ((uint32_t)resident[0x8AC0+1] << 8) |
                  ((uint32_t)resident[0x8AC0+2] << 16) |
                  ((uint32_t)resident[0x8AC0+3] << 24);
    CHK(c0 == VF3_MT_BASE + 0x8AD0);

    CHK(vf3_mt_mount_record(&m, 0) == -2); /* empty slot */
    CHK(vf3_mt_activate(&m, 10, resident + 0x8AC0, 256) == 0);
    CHK(m.task_cycle == 256);

    printf("mtmount_replay: %s\n", fails ? "FAIL" : "PASS");
    return fails ? 1 : 0;
}
