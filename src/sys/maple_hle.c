#include "sys/maple_hle.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
    MAPLE_REQ_DEVINFO = 1, MAPLE_REQ_GETCOND = 9,
    MAPLE_RES_NONE = 0xFF, MAPLE_RES_DEVINFO = 5, MAPLE_RES_DATATRF = 8,
    MAPLE_FUNC_CONTROLLER = 0x01000000u,
    MAPLE_FUNC_STORAGE = 0x02000000u, MAPLE_FUNC_LCD = 0x04000000u, MAPLE_FUNC_CLOCK = 0x08000000u,
    MAPLE_REQ_GETMEDIAINFO = 0x0A, MAPLE_REQ_BLOCKREAD = 0x0B, MAPLE_REQ_BLOCKWRITE = 0x0C, MAPLE_REQ_SETCOND = 0x0E,
    MAPLE_RES_OK = 7
};

/* The two card slots of port A are occupied, so a reply to the main unit
 * carries the bitmask 0x03 (Flycast's maple_GetAttachedDevices). */
#define MAPLE_ATTACHED_MASK 0x03u
#define MAPLE_SEGA_BRAND "Produced By or Under License From SEGA ENTERPRISES,LTD."

/* The memory card in slot 1 of port A: 256 blocks of 512 bytes, formatted the way the VMU's own file system lays it out
 * (root block 255, FAT block 254, directory blocks 253..241, 200 free user blocks).  The game's start-up asks for a card
 * with 12 free blocks and sits on a message screen without one. */
enum { VMU_BLOCKS = 256, VMU_BLOCK = 512 };
/* The media info the reference answers with (Flycast's maple_sega_vmu, the
 * unformatted-card case): total size - 1, partition, system block, FAT block
 * and size, directory block and size, icon shape, user blocks, then the three
 * words the card keeps behind them. */
static const uint16_t vmu_media_info[12] = { 255, 0, 255, 254, 1, 253, 0, 0, 200, 31, 0, 0 };
static uint8_t vmu[VMU_BLOCKS * VMU_BLOCK];
static int vmu_ready;

static void put16(uint8_t *p, unsigned v) { p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8); }

static void vmu_format(void)
{
    memset(vmu, 0, sizeof vmu);
    uint8_t *root = vmu + 255 * VMU_BLOCK;
    memset(root, 0x55, 16);
    root[0x10] = 1; root[0x11] = root[0x12] = root[0x13] = 0xFF; root[0x14] = 0x64;   /* colour: custom, white */
    static const uint8_t date[8] = { 0x20, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00 };
    memcpy(root + 0x30, date, sizeof date);
    for (unsigned i = 0; i < 12; ++i) put16(root + 0x40 + 2 * i, vmu_media_info[i]);   /* the layout the media-info request returns */
    uint8_t *fat = vmu + 254 * VMU_BLOCK;
    for (unsigned b = 0; b < VMU_BLOCKS; ++b) put16(fat + 2 * b, 0xFFFC);   /* free */
    put16(fat + 2 * 255, 0xFFFA);
    put16(fat + 2 * 254, 0xFFFA);
    for (unsigned b = 241; b <= 253; ++b) put16(fat + 2 * b, b == 241 ? 0xFFFA : b - 1);   /* the directory chain */
    vmu_ready = 1;
}

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
        {   /* instruction 7 (bits 10:8) is a no-op: one word, no receive address and no frame */
            const uint32_t h = rd(ram, ram_base, at);
            if (((h >> 8) & 7u) == 7u) {
                if (h & 0x80000000u) { ++blocks; break; }
                at += 4;
                continue;
            }
        }
        const uint32_t head = rd(ram, ram_base, at), recv = rd(ram, ram_base, at + 4), frame = rd(ram, ram_base, at + 8);
        const unsigned port = (head >> 16) & 3u, words = (head & 0xFFu) + 1u;
        const unsigned command = frame & 0xFFu, to = (frame >> 8) & 0xFFu;
        if (words > 0 && !in_ram(at, 12 + 4 * (words - 1), ram_base, ram_len)) break;
        const uint32_t next = at + 8 + 4 * words;
        if (getenv("VF3_MAPLELOG")) {
            fprintf(stderr, "maple: block at %08x head %08x recv %08x frame %08x", at, head, recv, frame);
            for (unsigned w = 1; w < words; ++w)
                fprintf(stderr, " [%08x]", rd(ram, ram_base, at + 8 + 4 * w));
            fprintf(stderr, "\n");
        }
        /* The Dreamcast shows its Maple devices at (bus << 6) | (1 << port): the
         * main unit of a bus is at 0x20 and the expansion slots at 0x01, 0x02,
         * ...  The reply carries the address the request was addressed to, and
         * a reply to the main unit also carries the bitmask of the attached
         * sub-devices (Flycast's maple_base::RawDma).  The reference has the
         * pad at 0x20 and a memory card in each of the two card slots. */
        const uint32_t addr = to & 0x3Fu;
        const uint32_t host = port << 6;
        const int is_card = port == 0 && (addr == 0x01u || addr == 0x02u);
        const int present = port == 0 && addr == 0x20u;
        const uint32_t from = (addr & 0x20u) ? (to | MAPLE_ATTACHED_MASK) : to;
        if (is_card) {
            if (!vmu_ready) vmu_format();
            const uint32_t vfrom = from;
            const uint32_t func = words > 1 ? rd(ram, ram_base, at + 12) : 0;
            const uint8_t *ra = ram + ((at + 16) & 0x1FFFFFFFu) - (ram_base & 0x1FFFFFFFu);
            uint8_t out[8 + 128 + 8];
            unsigned owords = 0;
            uint32_t code = MAPLE_RES_OK;
            memset(out, 0, sizeof out);
            if (command == MAPLE_REQ_DEVINFO) {
                code = MAPLE_RES_DEVINFO;
                uint32_t f = MAPLE_FUNC_STORAGE | MAPLE_FUNC_LCD | MAPLE_FUNC_CLOCK;
                uint32_t d0 = 0x403F7E7Eu, d1 = 0x00100500u, d2 = 0x00410F00u;   /* clock, LCD, storage */
                uint8_t body[112];
                memset(body, 0, sizeof body);
                memcpy(body, &f, 4); memcpy(body + 4, &d0, 4); memcpy(body + 8, &d1, 4); memcpy(body + 12, &d2, 4);
                body[16] = 0xFF;
                memset(body + 18, ' ', 30); memcpy(body + 18, "Visual Memory", 13);
                memset(body + 48, ' ', 60); memcpy(body + 48, MAPLE_SEGA_BRAND, (sizeof MAPLE_SEGA_BRAND) - 1);
                body[108] = 0x7C; body[109] = 0x00; body[110] = 0x82; body[111] = 0x00;
                if (in_ram(recv, 116, ram_base, ram_len)) {
                    wr(ram, ram_base, recv, code | (host << 8) | (vfrom << 16) | (28u << 24));
                    memcpy(ram + ((recv & 0x1FFFFFFFu) - (ram_base & 0x1FFFFFFFu)) + 4, body, sizeof body);
                }
                goto vmu_done;
            } else if (command == MAPLE_REQ_GETMEDIAINFO) {
                code = MAPLE_RES_DATATRF;
                memcpy(out, &func, 4);
                {   /* VF3_VMU_INFO=a,b,..(12 decimal words) overrides the answer */
                    uint16_t info[12];
                    memcpy(info, vmu_media_info, sizeof info);
                    const char *e = getenv("VF3_VMU_INFO");
                    for (unsigned i = 0; e && i < 12; ++i) { info[i] = (uint16_t)strtoul(e, (char **)&e, 10); if (*e == ',') ++e; }
                    for (unsigned i = 0; i < 12; ++i) put16(out + 4 + 2 * i, info[i]);
                }
                owords = 7;
            } else if (command == MAPLE_REQ_BLOCKREAD && func == MAPLE_FUNC_STORAGE) {
                const unsigned phase = ra[1], block = ((unsigned)ra[2] << 8) | ra[3];
                code = MAPLE_RES_DATATRF;
                memcpy(out, &func, 4);
                memcpy(out + 4, ra, 4);
                if (block < VMU_BLOCKS && phase < 4) memcpy(out + 8, vmu + block * VMU_BLOCK + phase * 128, 128);
                owords = 34;
            } else if (command == MAPLE_REQ_BLOCKWRITE && func == MAPLE_FUNC_STORAGE) {
                const unsigned phase = ra[1], block = ((unsigned)ra[2] << 8) | ra[3];
                if (block < VMU_BLOCKS && phase < 4) memcpy(vmu + block * VMU_BLOCK + phase * 128, ra + 4, 128);
            }
            if (in_ram(recv, 4 + 4 * owords, ram_base, ram_len)) {
                wr(ram, ram_base, recv, code | (host << 8) | (vfrom << 16) | (owords << 24));
                memcpy(ram + ((recv & 0x1FFFFFFFu) - (ram_base & 0x1FFFFFFFu)) + 4, out, 4 * owords);
            }
        vmu_done:
            {   /* VF3_VMU_MIRROR=<hex delta>: also answer in the other receive bank (diagnostic) */
                const char *m = getenv("VF3_VMU_MIRROR");
                if (m) {
                    const uint32_t alt = recv - (uint32_t)strtoul(m, NULL, 16);
                    if (in_ram(recv, 140, ram_base, ram_len) && in_ram(alt, 140, ram_base, ram_len))
                        memmove(ram + ((alt & 0x1FFFFFFFu) - (ram_base & 0x1FFFFFFFu)), ram + ((recv & 0x1FFFFFFFu) - (ram_base & 0x1FFFFFFFu)), 140);
                }
            }
            if (head & 0x80000000u) { ++blocks; break; }
            at = next;
            continue;
        }
        if (in_ram(recv, 4, ram_base, ram_len)) {
            if (!present || (command != MAPLE_REQ_DEVINFO && command != MAPLE_REQ_GETCOND)) {
                wr(ram, ram_base, recv, 0xFFFFFFFFu);
                if (getenv("VF3_MAPLELOG")) fprintf(stderr, "maple:   -> no device (ffffffff)\n");
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
                memset(body + 48, ' ', 60); memcpy(body + 48, MAPLE_SEGA_BRAND, (sizeof MAPLE_SEGA_BRAND) - 1);
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
