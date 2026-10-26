/* vf3dump.c - the reference emulator's state dumper and hits probe.
 *
 * This file is ours; it is meant to be dropped into a Flycast checkout (see
 * docs/re/patches/reference_frame_dump.md for the two one-line hooks and the
 * build wiring).  It does two things:
 *
 * 1. It writes the SH-4 machine state in the *port's own recording format*,
 *    so a state captured from the emulator loads in the port unchanged.
 *    The port (src/fight/native_tick.c) reads a recording as a stream of
 *    64-bit records: a marker (low 16 bits 0xFA30 = entry registers,
 *    0xFA70 = the XF bank, 0xFA50 = RAM windows) followed by its payload.
 *
 *    The register file maps onto the port's state vector
 *    (src/fight/readable_fp.h):
 *      v[0..15]  r0..r15
 *      v[16]     pr
 *      v[17]     sr (T bit at bit 0)
 *      v[18]     fpscr
 *      v[19,20]  mac.l, mac.h
 *      v[21..36] fr0..fr15
 *      v[37..52] xf0..xf15   (the 0xFA70 record)
 *
 * 2. It counts how often each instruction of the game image is executed, so
 *    the game's own call structure can be measured instead of guessed.
 *
 * Environment:
 *   VF3_DUMP_STATE=<file>  where to write the recording
 *   VF3_DUMP_PC=<pc>       the guest PC to dump at (default 0x8c09616a, the
 *                          fight scheduler); compared with the 29-bit mask, so
 *                          0x8c.... and 0x0c.... are the same code
 *   VF3_DUMP_SKIP=<n>      skip the first n hits (default 0)
 *   VF3_HITS=<file>        write the hits table (pc,hits) as csv
 */
#include "vf3dump.h"

#include "hw/sh4/sh4_if.h"
#include "hw/sh4/sh4_mem.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

namespace {

constexpr u32 RAM_BASE = 0x0C000000;
constexpr u32 RAM_LEN = 0x01000000;      /* the Dreamcast's 16 MiB of main RAM */
constexpr u32 MARK_REGS = 0xFA30;
constexpr u32 MARK_XF = 0xFA70;
constexpr u32 MARK_WINDOWS = 0xFA50;

const char *statePath = nullptr;
u32 targetPc = 0x8C09616A;
u32 skipHits = 0;
u32 everyHits = 0;          /* dump every n hits (0: once) */
u32 hits = 0;
bool done = false;
bool initialized = false;

/* The hits probe: the game image is the RAM copy of 1ST_READ at 0x0C010000,
 * 0x120000 bytes; the table is indexed by the offset of the instruction. */
constexpr u32 IMAGE_BASE = 0x0C010000;
constexpr u32 IMAGE_SIZE = 0x120000;
const char *hitsPath = nullptr;
std::vector<u32> hitsTable;
u64 instrCount = 0;
u64 nextHitsDump = 0;

void put64(FILE *f, u64 v) {
    fwrite(&v, 8, 1, f);
}

void putMarker(FILE *f, u32 pc, u32 tag) {
    put64(f, ((u64)pc << 16) | tag);
}

void writeState(const Sh4Context *ctx, const char *path) {
    FILE *f = fopen(path, "wb");
    if (f == nullptr) {
        fprintf(stderr, "[vf3dump] cannot write %s\n", path);
        return;
    }
    putMarker(f, ctx->pc, MARK_REGS);
    for (int i = 0; i < 16; ++i)
        put64(f, ctx->r[i]);
    put64(f, ctx->pr);
    put64(f, ctx->sr.getFull());
    put64(f, ctx->fpscr.full);
    put64(f, ctx->mac.l);
    put64(f, ctx->mac.h);
    for (int i = 0; i < 16; ++i) {
        u32 bits;
        memcpy(&bits, &ctx->fr[i], sizeof bits);
        put64(f, bits);
    }
    putMarker(f, ctx->pc, MARK_XF);
    for (int i = 0; i < 16; ++i) {
        u32 bits;
        memcpy(&bits, &ctx->xf[i], sizeof bits);
        put64(f, (u64)bits << 16);
    }
    putMarker(f, ctx->pc, MARK_WINDOWS);
    put64(f, 1);                       /* one window */
    put64(f, RAM_BASE);
    put64(f, RAM_LEN);
    const u8 *ram = GetMemPtr(RAM_BASE, RAM_LEN);
    if (ram == nullptr) {
        fprintf(stderr, "[vf3dump] no main RAM at %08x\n", RAM_BASE);
        fclose(f);
        return;
    }
    for (u32 i = 0; i < RAM_LEN / 4; ++i) {
        u32 word;
        memcpy(&word, ram + 4 * i, 4);
        put64(f, word);
    }
    fclose(f);
    fprintf(stderr, "[vf3dump] wrote %s at pc %08x (r15 %08x pr %08x gbr %08x)\n",
            path, ctx->pc, ctx->r[15], ctx->pr, ctx->gbr);
}

} // namespace

void vf3DumpInit() {
    if (initialized)
        return;
    initialized = true;
    const char *hp = getenv("VF3_HITS");
    if (hp != nullptr && *hp != '\0') {
        hitsPath = hp;
        hitsTable.assign(IMAGE_SIZE / 4, 0);
    }
    const char *path = getenv("VF3_DUMP_STATE");
    if (path == nullptr || *path == '\0')
        return;
    statePath = path;
    const char *pc = getenv("VF3_DUMP_PC");
    if (pc != nullptr && *pc != '\0')
        targetPc = (u32)strtoul(pc, nullptr, 0);
    const char *skip = getenv("VF3_DUMP_SKIP");
    if (skip != nullptr && *skip != '\0')
        skipHits = (u32)strtoul(skip, nullptr, 0);
    const char *every = getenv("VF3_DUMP_EVERY");
    if (every != nullptr && *every != '\0')
        everyHits = (u32)strtoul(every, nullptr, 0);
    fprintf(stderr, "[vf3dump] state=%s pc=%08x skip=%u every=%u\n",
            statePath, targetPc, skipHits, everyHits);
}

void vf3DumpCheck(u32 pc) {
    if (!initialized)
        vf3DumpInit();
    if (hitsPath != nullptr) {
        if (pc >= IMAGE_BASE && pc < IMAGE_BASE + IMAGE_SIZE) {
            u32 off = pc - IMAGE_BASE;
            hitsTable[off >> 2]++;
        }
        if (++instrCount >= nextHitsDump) {
            nextHitsDump = instrCount + 100000000;
            FILE *h = fopen(hitsPath, "wb");
            if (h != nullptr) {
                fprintf(h, "pc,hits\n");
                for (u32 i = 0; i < hitsTable.size(); ++i)
                    if (hitsTable[i] != 0)
                        fprintf(h, "0x%08x,%u\n", IMAGE_BASE + 4 * i, hitsTable[i]);
                fclose(h);
            }
        }
    }
    if (done || statePath == nullptr)
        return;
    if ((pc & 0x1FFFFFFF) != (targetPc & 0x1FFFFFFF))
        return;
    if (hits++ < skipHits)
        return;
    if (everyHits == 0) {
        done = true;
        writeState(&Sh4cntx, statePath);
        return;
    }
    if ((hits - 1 - skipHits) % everyHits != 0)
        return;
    /* one file per dump, named after the hit count: the hit count is the
     * distance from the start of the run, so it maps the state onto the frame
     * the reference video shows. */
    char path[1024];
    snprintf(path, sizeof path, "%s.%06u", statePath, hits - 1);
    writeState(&Sh4cntx, path);
}
