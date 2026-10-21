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
    const uint8_t *p = ram + ((a & 0x1FFFFFFFu) - (base & 0x1FFFFFFFu));
    return (uint32_t)p[0] | (uint32_t)p[1] << 8 | (uint32_t)p[2] << 16 | (uint32_t)p[3] << 24;
}

static void wr(uint8_t *ram, uint32_t base, uint32_t a, uint32_t v)
{
    uint8_t *p = ram + ((a & 0x1FFFFFFFu) - (base & 0x1FFFFFFFu));
    for (unsigned n = 0; n < 4; ++n) p[n] = (uint8_t)(v >> (n * 8));
}

void vf3_maple_bus_init(vf3_maple_bus *bus, unsigned connected)
{
    const vf3_maple_pad neutral = {0xFFFFu, 0, 0, 128, 128, 128, 128};
    for (unsigned p = 0; p < VF3_MAPLE_PORTS; ++p) bus->pads[p] = neutral;
    bus->connected = connected & 15u;
}

vf3_maple_dma_result vf3_maple_dma_bus(uint8_t *ram, uint32_t ram_base,
    uint32_t ram_len, uint32_t list_addr, const vf3_maple_bus *bus)
{
    vf3_maple_dma_result result = {VF3_MAPLE_DMA_OK, 0, 0};
    uint32_t at = list_addr;
    for (; result.blocks < 64; ++result.blocks) {
        if (!ram || !bus || (at & 3u) || !in_ram(at, 12, ram_base, ram_len)) {
            result.status = VF3_MAPLE_DMA_BAD_LIST; result.address = at; return result;
        }
        const uint32_t head = rd(ram, ram_base, at), recv = rd(ram, ram_base, at + 4), frame = rd(ram, ram_base, at + 8);
        const unsigned port = (head >> 16) & 3u, words = (head & 0xFFu) + 1u;
        const unsigned command = frame & 0xFFu, to = (frame >> 8) & 0xFFu;
        /* Patterns other than normal transmit are bus operations with a
         * different layout, not ordinary frames. Do not reinterpret them. */
        if (head & 0x700u) {
            result.status = VF3_MAPLE_DMA_UNSUPPORTED_PATTERN; result.address = at; return result;
        }
        if (!in_ram(at, 8 + 4 * words, ram_base, ram_len) || (frame >> 24) != words - 1u) {
            result.status = VF3_MAPLE_DMA_BAD_LIST; result.address = at; return result;
        }
        const uint32_t next = at + 8 + 4 * words;
        /* the host is address 0 of the port; the main unit answers from port << 6 | 0x20, a sub-unit bit would be 1..0x1F */
        const uint32_t from = (port << 6) | 0x20u, host = port << 6;
        const int present = (bus->connected & (1u << port)) && to == from;
        const vf3_maple_pad *pad = &bus->pads[port];
        unsigned response_size = 4;
        if (present && command == MAPLE_REQ_DEVINFO) response_size = 116;
        if (present && command == MAPLE_REQ_GETCOND) response_size = 16;
        if ((recv & 3u) || !in_ram(recv, response_size, ram_base, ram_len)) {
            result.status = VF3_MAPLE_DMA_BAD_RECEIVE; result.address = recv; return result;
        }
        {
            if (!present || (command != MAPLE_REQ_DEVINFO && command != MAPLE_REQ_GETCOND)) {
                wr(ram, ram_base, recv, 0xFFFFFFFFu);
            } else if (command == MAPLE_REQ_DEVINFO && in_ram(recv, 116, ram_base, ram_len)) {
                uint8_t body[112];
                memset(body, 0, sizeof body);
                body[3] = 1;       /* controller function 0x01000000, little endian */
                body[5] = 0x0F; body[6] = 0x06; body[7] = 0xFE; /* standard pad mask */
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
        if (head & 0x80000000u) { ++result.blocks; return result; }
        at = next;
    }
    result.status = VF3_MAPLE_DMA_BLOCK_LIMIT;
    result.address = at;
    return result;
}

unsigned vf3_maple_dma(uint8_t *ram, uint32_t ram_base, uint32_t ram_len, uint32_t list_addr, const vf3_maple_pad *pad)
{
    vf3_maple_bus bus;
    vf3_maple_bus_init(&bus, pad ? 1u : 0u);
    if (pad) bus.pads[0] = *pad;
    return vf3_maple_dma_bus(ram, ram_base, ram_len, list_addr, &bus).blocks;
}
