#include "sys/maple_hle.h"

#include <string.h>

enum {
    MAPLE_REQ_DEVINFO = 1, MAPLE_REQ_GETCOND = 9,
    MAPLE_RES_NONE = 0xFF, MAPLE_RES_DEVINFO = 5, MAPLE_RES_DATATRF = 8,
    MAPLE_FUNC_CONTROLLER = 0x01000000u
};

static int in_ram(uint32_t a, uint32_t n, uint32_t base, uint32_t len)
{
    a &= 0x1FFFFFFFu;
    return a >= (base & 0x1FFFFFFFu) && n <= len && a - (base & 0x1FFFFFFFu) <= len - n;
}

static uint32_t rd(const uint8_t *ram, uint32_t base, uint32_t a)
{
    uint32_t v;
    memcpy(&v, ram + ((a & 0x1FFFFFFFu) - (base & 0x1FFFFFFFu)), 4);
    return v;
}

static void wr(uint8_t *ram, uint32_t base, uint32_t a, uint32_t v)
{
    memcpy(ram + ((a & 0x1FFFFFFFu) - (base & 0x1FFFFFFFu)), &v, 4);
}

unsigned vf3_maple_dma(uint8_t *ram, uint32_t ram_base, uint32_t ram_len, uint32_t list_addr, const vf3_maple_pad *pad)
{
    unsigned blocks = 0;
    uint32_t at = list_addr;
    for (; blocks < 64; ++blocks) {
        if (!in_ram(at, 12, ram_base, ram_len)) break;
        const uint32_t head = rd(ram, ram_base, at), recv = rd(ram, ram_base, at + 4), frame = rd(ram, ram_base, at + 8);
        const unsigned port = (head >> 16) & 3u, words = (head & 0xFFu) + 1u;
        const unsigned command = frame & 0xFFu, to = (frame >> 8) & 0xFFu;
        if (words > 0 && !in_ram(at, 12 + 4 * (words - 1), ram_base, ram_len)) break;
        const uint32_t next = at + 8 + 4 * words;
        /* the host is address 0 of the port; the main unit answers from port << 6 | 0x20, a sub-unit bit would be 1..0x1F */
        const uint32_t from = (port << 6) | 0x20u, host = port << 6;
        const int present = port == 0 && (to & 0x3Fu) == 0x20u;
        if (in_ram(recv, 4, ram_base, ram_len)) {
            if (!present || (command != MAPLE_REQ_DEVINFO && command != MAPLE_REQ_GETCOND)) {
                wr(ram, ram_base, recv, 0xFFFFFFFFu);
            } else if (command == MAPLE_REQ_DEVINFO && in_ram(recv, 116, ram_base, ram_len)) {
                uint8_t body[112];
                memset(body, 0, sizeof body);
                const uint32_t func = MAPLE_FUNC_CONTROLLER, fdata = 0xFE060F00u;   /* the standard pad's button mask */
                memcpy(body, &func, 4);
                memcpy(body + 4, &fdata, 4);
                body[16] = 0xFF;   /* area: all regions */
                body[17] = 0;
                memset(body + 18, ' ', 30);
                memcpy(body + 18, "Dreamcast Controller", 20);
                memset(body + 48, ' ', 60);
                body[108] = 0xAE; body[109] = 0x01;   /* standby 430 */
                body[110] = 0xF4; body[111] = 0x01;   /* max 500 */
                wr(ram, ram_base, recv, MAPLE_RES_DEVINFO | (host << 8) | (from << 16) | (28u << 24));
                memcpy(ram + ((recv & 0x1FFFFFFFu) - (ram_base & 0x1FFFFFFFu)) + 4, body, sizeof body);
            } else if (command == MAPLE_REQ_GETCOND && in_ram(recv, 16, ram_base, ram_len)) {
                wr(ram, ram_base, recv, MAPLE_RES_DATATRF | (host << 8) | (from << 16) | (3u << 24));
                wr(ram, ram_base, recv + 4, MAPLE_FUNC_CONTROLLER);
                wr(ram, ram_base, recv + 8, (uint32_t)pad->buttons | (uint32_t)pad->rtrig << 16 | (uint32_t)pad->ltrig << 24);
                wr(ram, ram_base, recv + 12, (uint32_t)pad->joyx | (uint32_t)pad->joyy << 8 | (uint32_t)pad->joy2x << 16 | (uint32_t)pad->joy2y << 24);
            }
        }
        if (head & 0x80000000u) { ++blocks; break; }
        at = next;
    }
    return blocks;
}
