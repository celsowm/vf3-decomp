#include "sys/maple_hle.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
    MAPLE_REQ_DEVINFO = 1, MAPLE_REQ_ALLSTATUS = 2, MAPLE_REQ_GETCOND = 9,
    MAPLE_RES_NONE = 0xFF, MAPLE_RES_DEVINFO = 5, MAPLE_RES_DEVSTATUSALL = 6, MAPLE_RES_DATATRF = 8,
    MAPLE_FUNC_CONTROLLER = 0x01000000u,
    MAPLE_FUNC_STORAGE = 0x02000000u, MAPLE_FUNC_LCD = 0x04000000u, MAPLE_FUNC_CLOCK = 0x08000000u,
    MAPLE_REQ_GETMEDIAINFO = 0x0A, MAPLE_REQ_BLOCKREAD = 0x0B, MAPLE_REQ_BLOCKWRITE = 0x0C,
    MAPLE_REQ_GETLASTERROR = 0x0D, MAPLE_REQ_SETCOND = 0x0E,
    MAPLE_RES_OK = 7
};

/* The two card slots of port A are occupied, so a reply to the main unit
 * carries the bitmask of the attached ports.  The reference's default
 * configuration puts the two VMUs at the *expansion* slots, which are ports
 * 0 and 1 of the bus (core/hw/maple/maple_cfg.cpp: createDreamcastDevices
 * creates MapleExpansionDevices[bus][0] at port 0 and [bus][1] at port 1),
 * and maple_GetAttachedDevices returns one bit per port - so the mask is
 * 0x03, and the recipient 0x01 selects the first card, 0x02 the second. */
#define MAPLE_ATTACHED_MASK 0x03u
#define MAPLE_SEGA_BRAND "Produced By or Under License From SEGA ENTERPRISES,LTD."
/* The extra text the reference appends to an "all status" answer (the device's
 * firmware banner): the controller's and the VMU's. */
#define MAPLE_CONTROLLER_EXTRA "Version 1.010,1998/09/28,315-6211-AB   ,Analog Module : The 4th Edition.5/8  +DF"
#define MAPLE_VMU_EXTRA "Version 1.005,1999/04/15,315-6208-03,SEGA Visual Memory System BIOS Produced by "

/* The recipient address picks the device the way the reference does
 * (core/hw/maple/maple_if.cpp, getPort): the first set bit is the port, and a
 * recipient with no bit set falls back to the main unit (5). */
static unsigned maple_port(uint32_t reci)
{
    for (unsigned i = 0; i < 6; ++i)
        if ((1u << i) & reci) return i;
    return 5u;
}

/* The memory card in slot 1 of port A: 256 blocks of 512 bytes, formatted the way the VMU's own file system lays it out
 * (root block 255, FAT block 254, directory blocks 253..241, 200 free user blocks).  The game's start-up asks for a card
 * with 12 free blocks and sits on a message screen without one. */
enum { VMU_BLOCKS = 256, VMU_BLOCK = 512 };
/* The media info the reference answers with (Flycast's maple_sega_vmu, the
 * MFID_1_Storage case of MDCF_GetMediaInfo): the card's own system area, the
 * 24 bytes the root block carries at +0x40 - total size - 1, partition,
 * system block, FAT block and size, directory block and size, icon shape, user
 * blocks, then the three words the card keeps behind them.  The reference
 * answers with those bytes because the card's first word there is 0x00FF,
 * which is not the 0xFFFF that marks an unformatted card, so it takes the
 * "read the card" branch.
 *
 * The values of the reference's *default* VMU image (the zlib blob in
 * maple_devs.cpp), which is the card the game sees there: tools/
 * maple_vmu_default.py writes it out and tools/maple_vmu_regions.py lists the
 * regions that are not zero. */
static uint8_t vmu[VMU_BLOCKS * VMU_BLOCK];
static int vmu_ready;

static const uint8_t vmu_root[0x57] = {
    0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
    0x01, 0xFF, 0xFF, 0xFF, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x19, 0x98, 0x11, 0x27, 0x00, 0x00, 0x59, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFE, 0x00, 0x01, 0x00, 0xFD, 0x00, 0x0D, 0x00, 0x05, 0x00,
    0xC8, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x80
};

static void put16(uint8_t *p, unsigned v) { p[0] = (uint8_t)v; p[1] = (uint8_t)(v >> 8); }

/* The Maple wire carries a word most significant byte first, but the guest
 * writes it into the DMA buffer the way the SH-4 stores it (little endian),
 * so the reference reads the request's words the other way round
 * (maple_base's SWAP32). */
static uint32_t maple_wire(uint32_t word)
{
    return ((word & 0x000000FFu) << 24) | ((word & 0x0000FF00u) << 8) |
           ((word & 0x00FF0000u) >> 8) | ((word & 0xFF000000u) >> 24);
}

/* The block a storage request names (Flycast's maple_sega_vmu, MDCF_BlockRead
 * and MDCF_BlockWrite, MFID_1_Storage): the low sixteen bits of the word that
 * follows the function code, read the way the wire carries it, and a number
 * above 255 is truncated to its low byte.  The game asks for the last blocks
 * of the card as 0xFFFC..0xFFFF, so the truncation is what makes the request
 * mean the blocks 252..255. */
static unsigned maple_block(uint32_t word) { return (maple_wire(word) & 0xFFFFu) & 0xFFu; }

static void vmu_format(void)
{
    memset(vmu, 0, sizeof vmu);
    /* The reference's default image: the root block, the FAT (the free blocks
     * 0..240, the directory chain 241..253 and the two system blocks), and the
     * two free blocks that still carry the leftovers of the image. */
    memcpy(vmu + 255 * VMU_BLOCK, vmu_root, sizeof vmu_root);
    memcpy(vmu, "\xc4\x00\xa4\x00\x00\x4f\x97", 7);
    {
        static const uint8_t block11[31] = {
            0x04, 0x00, 0x00, 0x00, 0x1D, 0x8C, 0x06, 0x00, 0x90, 0x00, 0xA4, 0x00, 0x90, 0x00, 0xA4, 0x00,
            0x38, 0x00, 0x93, 0x00, 0x38, 0x00, 0x93, 0x00, 0x00, 0x60, 0x98, 0x00, 0x00, 0xA0, 0x0A
        };
        memcpy(vmu + 11 * VMU_BLOCK + 0x188, block11, sizeof block11);
    }
    /* VF3_VMU_ROOTINFO=a,b,.. (12 decimal words) overrides the media info the
     * card's root block carries - a diagnostic for the driver's block count. */
    {
        const char *e = getenv("VF3_VMU_ROOTINFO");
        if (e && *e) {
            uint8_t *root = vmu + 255 * VMU_BLOCK + 0x40;
            for (unsigned i = 0; i < 12; ++i) {
                unsigned long v = strtoul(e, (char **)&e, 10);
                put16(root + 2 * i, (unsigned)v);
                if (*e == ',') ++e;
            }
        }
    }
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
         * sub-devices (Flycast's maple_base::RawDma).
         *
         * The recipient selects the device the way the reference does
         * (core/hw/maple/maple_if.cpp, getPort): the first set bit of the
         * recipient is the port, and a recipient with no bit set falls back to
         * the main unit (5).  The reference has the pad at the main unit (port
         * 5) and a memory card in each of the two expansion slots, which are
         * ports 0 and 1 (maple_cfg.cpp), so the attached mask is 0x03.  The
         * other buses carry no device at all in the reference's default
         * configuration, so every request to them is answered with 0xFFFFFFFF. */
        const unsigned dev = maple_port(to);
        /* The reply's header carries the request's sender (Flycast's
         * maple_base::RawDma: the response word is the response code, the
         * sender in bits 8-15, the recipient (with the attached mask) in bits
         * 16-23 and the data length in words in bits 24-31). */
        const uint32_t sender = (frame >> 16) & 0xFFu;
        const int is_card = port == 0 && (dev == 0u || dev == 1u);
        const int present = port == 0 && dev == 5u;
        const uint32_t from = (to & 0x20u) ? (to | MAPLE_ATTACHED_MASK) : to;
        if (is_card) {
            if (!vmu_ready) vmu_format();
            const uint32_t vfrom = from;
            const uint32_t func = words > 1 ? rd(ram, ram_base, at + 12) : 0;
            const uint8_t *ra = ram + ((at + 16) & 0x1FFFFFFFu) - (ram_base & 0x1FFFFFFFu);
            uint8_t out[8 + VMU_BLOCK + 8];
            unsigned owords = 0;
            uint32_t code = MAPLE_RES_OK;
            memset(out, 0, sizeof out);
            if (command == MAPLE_REQ_DEVINFO || command == MAPLE_REQ_ALLSTATUS) {
                /* The reference answers both the device request and the "all
                 * status" request with the same 112 byte status; the second
                 * one adds the device's firmware banner and answers with the
                 * status-all code (maple_sega_vmu::dma). */
                const int all = command == MAPLE_REQ_ALLSTATUS;
                const unsigned extra_len = all ? (unsigned)strlen(MAPLE_VMU_EXTRA) : 0u;
                code = all ? MAPLE_RES_DEVSTATUSALL : MAPLE_RES_DEVINFO;
                uint32_t f = MAPLE_FUNC_STORAGE | MAPLE_FUNC_LCD | MAPLE_FUNC_CLOCK;
                uint32_t d0 = 0x403F7E7Eu, d1 = 0x00100500u, d2 = 0x00410F00u;   /* clock, LCD, storage */
                uint8_t body[112];
                memset(body, 0, sizeof body);
                memcpy(body, &f, 4); memcpy(body + 4, &d0, 4); memcpy(body + 8, &d1, 4); memcpy(body + 12, &d2, 4);
                body[16] = 0xFF;
                memset(body + 18, ' ', 30); memcpy(body + 18, "Visual Memory", 13);
                memset(body + 48, ' ', 60); memcpy(body + 48, MAPLE_SEGA_BRAND, (sizeof MAPLE_SEGA_BRAND) - 1);
                body[108] = 0x7C; body[109] = 0x00; body[110] = 0x82; body[111] = 0x00;
                if (in_ram(recv, 4 + 112 + extra_len, ram_base, ram_len)) {
                    uint32_t hdr = code | (sender << 8) | (vfrom << 16) | ((112u + extra_len) / 4u << 24);
                    /* VF3_MAPLE_HDR=<hex> forces the reply's header word - a
                     * diagnostic for the driver's answer check. */
                    const char *h = getenv("VF3_MAPLE_HDR");
                    if (h && *h) hdr = (uint32_t)strtoul(h, NULL, 16);
                    wr(ram, ram_base, recv, hdr);
                    memcpy(ram + ((recv & 0x1FFFFFFFu) - (ram_base & 0x1FFFFFFFu)) + 4, body, sizeof body);
                    if (all)
                        memcpy(ram + ((recv & 0x1FFFFFFFu) - (ram_base & 0x1FFFFFFFu)) + 4 + 112, MAPLE_VMU_EXTRA, extra_len);
                    if (getenv("VF3_MAPLELOG")) fprintf(stderr, "maple:   -> reply %08x at %08x (%u words)\n", hdr, recv, (112u + extra_len) / 4u);
                }
                goto vmu_done;
            } else if (command == MAPLE_REQ_GETMEDIAINFO) {
                code = MAPLE_RES_DATATRF;
                memcpy(out, &func, 4);
                {   /* The card's own system area; VF3_VMU_INFO=a,b,.. (12
                     * decimal words) overrides the answer. */
                    const uint8_t *area = vmu + 255 * VMU_BLOCK + 0x40;
                    uint16_t info[12];
                    for (unsigned i = 0; i < 12; ++i)
                        info[i] = (uint16_t)(area[2 * i] | (area[2 * i + 1] << 8));
                    const char *e = getenv("VF3_VMU_INFO");
                    for (unsigned i = 0; e && *e && i < 12; ++i) {
                        info[i] = (uint16_t)strtoul(e, (char **)&e, 10);
                        if (*e == ',') ++e;
                    }
                    for (unsigned i = 0; i < 12; ++i) put16(out + 4 + 2 * i, info[i]);
                }
                owords = 7;
            } else if (command == MAPLE_REQ_BLOCKREAD && func == MAPLE_FUNC_STORAGE) {
                /* The whole 512 byte block comes back in one transfer (the
                 * reference writes the block out in full and does not look at
                 * the phase).  The block number is in the word that follows
                 * the function code, read the way the wire carries it - the
                 * reference reads the whole word, not one byte of it. */
                const unsigned block = maple_block(rd(ram, ram_base, at + 16));
                code = MAPLE_RES_DATATRF;
                memcpy(out, &func, 4);
                memcpy(out + 4, ra, 4);        /* the reference echoes the word */
                memcpy(out + 8, vmu + block * VMU_BLOCK, VMU_BLOCK);
                owords = 2 + VMU_BLOCK / 4;
            } else if (command == MAPLE_REQ_BLOCKWRITE && func == MAPLE_FUNC_STORAGE) {
                /* The block and the phase share the word: the block is its low
                 * sixteen bits, the phase its bits 16-23, and the data follows
                 * the word. */
                const uint32_t word = rd(ram, ram_base, at + 16);
                const unsigned block = maple_block(word);
                const unsigned phase = (maple_wire(word) >> 16) & 3u;
                const unsigned off = block * VMU_BLOCK + phase * (VMU_BLOCK / 4);
                const unsigned len = words > 3 ? (words - 3) * 4 : 0;
                if (len && off + len <= sizeof vmu) memcpy(vmu + off, ra + 4, len);
            } else {
                /* The other commands the reference's VMU answers
                 * (maple_sega_vmu::dma): the "last error" request, the reset
                 * and the kill answer with a plain reply, the set-condition
                 * only understands the clock, and anything else is an
                 * unknown command. */
                switch (command) {
                case MAPLE_REQ_GETLASTERROR:
                case 0x03:   /* MDC_DeviceReset */
                case 0x04:   /* MDC_DeviceKill */
                    code = MAPLE_RES_OK;
                    break;
                case MAPLE_REQ_SETCOND:
                    code = (func == MAPLE_FUNC_CLOCK) ? MAPLE_RES_OK : 0xFEu;   /* MDRE_UnknownFunction */
                    break;
                default:
                    code = 0xFDu;   /* MDRE_UnknownCmd */
                    break;
                }
            }
            if (in_ram(recv, 4 + 4 * owords, ram_base, ram_len)) {
                const uint32_t hdr = code | (sender << 8) | (vfrom << 16) | (owords << 24);
                wr(ram, ram_base, recv, hdr);
                memcpy(ram + ((recv & 0x1FFFFFFFu) - (ram_base & 0x1FFFFFFFu)) + 4, out, 4 * owords);
                if (getenv("VF3_MAPLELOG")) fprintf(stderr, "maple:   -> reply %08x at %08x (%u words)\n", hdr, recv, owords);
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
            if (!present) {
                wr(ram, ram_base, recv, 0xFFFFFFFFu);
                if (getenv("VF3_MAPLELOG")) fprintf(stderr, "maple:   -> no device (ffffffff)\n");
            } else if ((command == MAPLE_REQ_DEVINFO || command == MAPLE_REQ_ALLSTATUS) &&
                       in_ram(recv, 4 + 112 + (command == MAPLE_REQ_ALLSTATUS ? (unsigned)strlen(MAPLE_CONTROLLER_EXTRA) : 0u), ram_base, ram_len)) {
                /* The "all status" request answers with the same status plus
                 * the pad's firmware banner (maple_sega_controller::dma). */
                const int all = command == MAPLE_REQ_ALLSTATUS;
                const unsigned extra_len = all ? (unsigned)strlen(MAPLE_CONTROLLER_EXTRA) : 0u;
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
                const uint32_t hdr = (all ? MAPLE_RES_DEVSTATUSALL : MAPLE_RES_DEVINFO) | (sender << 8) | (from << 16) | ((112u + extra_len) / 4u << 24);
                wr(ram, ram_base, recv, hdr);
                memcpy(ram + ((recv & 0x1FFFFFFFu) - (ram_base & 0x1FFFFFFFu)) + 4, body, sizeof body);
                if (all)
                    memcpy(ram + ((recv & 0x1FFFFFFFu) - (ram_base & 0x1FFFFFFFu)) + 4 + 112, MAPLE_CONTROLLER_EXTRA, extra_len);
                if (getenv("VF3_MAPLELOG")) fprintf(stderr, "maple:   -> reply %08x at %08x (%u words)\n", hdr, recv, (112u + extra_len) / 4u);
            } else if (command == MAPLE_REQ_GETCOND && in_ram(recv, 16, ram_base, ram_len)) {
                const uint32_t hdr = MAPLE_RES_DATATRF | (sender << 8) | (from << 16) | (3u << 24);
                wr(ram, ram_base, recv, hdr);
                wr(ram, ram_base, recv + 4, MAPLE_FUNC_CONTROLLER);
                wr(ram, ram_base, recv + 8, (uint32_t)pad->buttons | (uint32_t)pad->rtrig << 16 | (uint32_t)pad->ltrig << 24);
                wr(ram, ram_base, recv + 12, (uint32_t)pad->joyx | (uint32_t)pad->joyy << 8 | (uint32_t)pad->joy2x << 16 | (uint32_t)pad->joy2y << 24);
                if (getenv("VF3_MAPLELOG")) fprintf(stderr, "maple:   -> reply %08x at %08x (3 words)\n", hdr, recv);
            } else {
                /* The reference's controller answers the reset and the kill
                 * with a plain reply and anything else with the unknown
                 * command code (maple_sega_controller::dma). */
                const uint32_t code = (command == 0x03 || command == 0x04) ? MAPLE_RES_OK : 0xFDu;
                const uint32_t hdr = code | (sender << 8) | (from << 16) | (0u << 24);
                wr(ram, ram_base, recv, hdr);
                if (getenv("VF3_MAPLELOG")) fprintf(stderr, "maple:   -> reply %08x at %08x (0 words)\n", hdr, recv);
            }
        }
        if (head & 0x80000000u) { ++blocks; break; }
        at = next;
    }
    return blocks;
}
