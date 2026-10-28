/* host/sdl3_host.c - the SDL3 host for the native port.
 *
 *   vf3sdl --state FILE [--pair N] [--frames N] [--gbr ADDR] [--entry ADDR]
 *           [--gdi DISC] [--gd-state FILE] [--dump-frame FILE.ppm]
 *           [--headless] [--fps N] [--slice STEPS] [--ta-out FILE]
 *
 * Loads a machine state the port can run from, runs the game's frame loop,
 * hands the Tile Accelerator command stream to the PVR2 model and presents the
 * frame the model produced.
 *
 * Phase P2 of docs/re/plan_sdl3_port.md.  The frame loop needs three things
 * the port did not have before: a clock (the TMU's channel 0 counts the CPU
 * clock divided by 256, and drops 13,033 ticks per frame), the events that end
 * a frame (the vblank-in and the TA list ends) and the interrupt handlers that
 * serve them.  The model is src/sys/frame_events.c; the handlers are the
 * game's own code, run from the register file the guest had when the event
 * came.
 *
 * What is not real yet: the PVR2 model has no rasteriser (the frame is
 * black), the audio stream carries silence, and the gamepad is read but not
 * yet routed into the Maple bus (phase P6).
 *
 * The host owns no game logic: the game code keeps talking to the Dreamcast's
 * addresses and the models intercept the regions it writes to.
 */
#include <SDL3/SDL.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fight/matrix_family.h"
#include "fight/native_tick.h"
#include "render/pvr2.h"
#include "render/ta.h"
#include "render/ta_stream.h"
#include "sys/frame_events.h"
#include "sys/gdrom_hle.h"

#define DEFAULT_GBR 0x0C16B880u        /* the fight tasks' global-state block */
#define DEFAULT_FPS 60                 /* the NTSC field rate the DC ran at */
#define DEFAULT_SLICE 200000u          /* guest steps between two event slices */
#define TCNT0_SAMPLE 0x0C1981C8u       /* where the game keeps the TMU sample */

/* A PPM (P6) of the last frame: the diff tool and any image viewer read it.
 * The framebuffer holds RGB565, the way the hardware's framebuffer does. */
static int write_ppm(const char *path, const vf3_pvr2 *pvr, unsigned w, unsigned h)
{
    FILE *f = fopen(path, "wb");
    if (!f) { fprintf(stderr, "vf3sdl: cannot write %s\n", path); return 1; }
    fprintf(f, "P6\n%u %u\n255\n", w, h);
    unsigned char *row = malloc((size_t)w * 3);
    if (!row) { fclose(f); return 1; }
    for (unsigned y = 0; y < h; ++y) {
        for (unsigned x = 0; x < w; ++x) {
            const uint32_t px = vf3_pvr2_pixel(pvr, x, y);
            row[x * 3 + 0] = (unsigned char)(px >> 16);
            row[x * 3 + 1] = (unsigned char)(px >> 8);
            row[x * 3 + 2] = (unsigned char)(px);
        }
        if (fwrite(row, 3, w, f) != w) { free(row); fclose(f); return 1; }
    }
    free(row);
    fclose(f);
    return 0;
}

static void usage(void)
{
    fprintf(stderr,
            "usage: vf3sdl --state FILE [--pair N] [--frames N] [--gbr ADDR]\n"
            "              [--entry ADDR] [--gdi DISC] [--gd-state FILE]\n"
            "              [--dump-frame FILE.ppm] [--headless] [--fps N]\n"
            "              [--slice STEPS] [--ta-out FILE]\n");
}

/* ---------------------------------------------------------------- the frame loop */

static uint8_t *g_ram;                 /* the machine's RAM */
static uint32_t g_gbr;                  /* the global-state block */
static vf3_pvr2 *g_pvr2;                /* the PVR2 model */

/* The guest's own writes into the PVR2: the textures and the registers. */

/* VF3_VRAMLOG: where the guest's texture writes go.  Two sources reach the
 * VRAM - a plain store (the store queue's area 1 bursts and the guest's own
 * stores) and the store queue's own flush - and both are counted by the
 * megabyte of the address they used. */
static uint64_t g_vram_plain[64], g_vram_plain_nz[64];
static uint64_t g_vram_sq[64], g_vram_sq_nz[64];
static int g_vramlog;

static void host_vram_write(uint32_t dest, uint32_t value)
{
    if (g_vramlog) {
        const unsigned r = (dest >> 20) & 0x3Fu;
        ++g_vram_sq[r];
        if (value) ++g_vram_sq_nz[r];
    }
    if (g_pvr2) vf3_pvr2_vram_store(g_pvr2, dest, value);
}

/* A plain guest store into the texture memory, narrowed to the access size. */
static void host_vram_store(uint32_t dest, uint32_t value, unsigned size)
{
    if (g_vramlog) {
        const unsigned r = (dest >> 20) & 0x3Fu;
        ++g_vram_plain[r];
        if (value) ++g_vram_plain_nz[r];
    }
    if (g_pvr2) vf3_pvr2_vram_store_n(g_pvr2, dest, value, size);
}

static void host_reg_write(uint32_t off, uint32_t value)
{
    if (g_pvr2) vf3_pvr2_reg_store(g_pvr2, off, value);
}

/* The system bus' long mode bits: they pick the 32 bit or the 64 bit path of
 * the PVR2's texture memory window at 0x11000000. */
static void host_lmmode(uint32_t mode0, uint32_t mode1)
{
    if (g_pvr2) vf3_pvr2_set_lmmode(g_pvr2, mode0, mode1);
}
static FILE *g_ta_file;                 /* the display commands, as they arrive */
static vf3_frame_events g_events;       /* the clock and the frame events */
static unsigned g_slice = DEFAULT_SLICE; /* guest steps per event slice */
static unsigned g_budget_out = DEFAULT_SLICE; /* the budget the hook handed out */
static uint64_t g_skipped;   /* the guest steps the idle skip did not execute */
static unsigned g_vblanks, g_render_starts;  /* the frames the host has closed */
static uint64_t g_frame_insns;
static unsigned g_hook_insns;              /* the steps the hooks have charged */
static uint64_t g_insns;                   /* the guest instructions the clock has carried */

/* The watchdog: the guest can stop making progress (a wait that never ends,
 * an interrupt handler that spins), and then nothing in the main loop runs
 * again.  A second thread looks at the frame counter and, when it stands
 * still, says where the guest is. */
static volatile int g_watch_run;
static SDL_Thread *g_watch_thread;

static int SDLCALL watch_thread(void *ctx)
{
    (void)ctx;
    long last = -1;
    int still = 0;
    while (g_watch_run) {
        SDL_Delay(1000);
        const long frames = (long)vf3_frame_events_frames(&g_events);
        if (frames != last) { last = frames; still = 0; continue; }
        if (++still >= 5) {
            still = 0;
            const uint32_t pc = vf3_native_current_pc();
            fprintf(stderr, "vf3sdl: no progress: frame %ld, the guest is at %08x\n",
                    frames, pc);
            /* the literal pool of the function the guest is in: it names the
             * callees, so it says what the guest is waiting for */
            if (g_ram && pc >= 0x0C010000u && pc < 0x0C100000u) {
                const uint32_t off = (pc - 0x0C000000u) & ~3u;
                fprintf(stderr, "vf3sdl:   literals:");
                for (unsigned i = 0x100u; i < 0x200u; i += 4u)
                    fprintf(stderr, " %08x=%08x", pc + i, ((const uint32_t *)(g_ram + off + i))[0]);
                fprintf(stderr, "\n");
            }
        }
    }
    return 0;
}

/* The TA's input: the blocks the hardware receives, in the order it receives
 * them.
 *
 * The TA is a FIFO, not a memory: a burst that is written twice hands the TA
 * both copies, and the destination address only says which path the burst
 * takes (the polygon stream, the YUV converter or the VRAM).  So the port
 * keeps the blocks in the order they arrive and decodes them in that order. */
static uint32_t *g_ta_fifo;            /* the blocks (8 words each) */
static unsigned g_ta_fifo_words;       /* the words in the FIFO */
static unsigned g_ta_fifo_cap;         /* the capacity, in words */

static void ta_fifo_push(const uint32_t *words, unsigned n)
{
    if (!g_ta_fifo_words && !g_ta_fifo) {
        g_ta_fifo_cap = 4096;
        g_ta_fifo = malloc((size_t)g_ta_fifo_cap * 4u);
        if (!g_ta_fifo) { g_ta_fifo_cap = 0; return; }
    }
    if (g_ta_fifo_words + n > g_ta_fifo_cap) {
        unsigned cap = g_ta_fifo_cap ? g_ta_fifo_cap : 4096;
        while (g_ta_fifo_words + n > cap) cap *= 2;
        uint32_t *p = realloc(g_ta_fifo, (size_t)cap * 4u);
        if (!p) return;
        g_ta_fifo = p;
        g_ta_fifo_cap = cap;
    }
    memcpy(g_ta_fifo + g_ta_fifo_words, words, 4u * n);
    g_ta_fifo_words += n;
}

static void push_ta(const uint32_t *words, unsigned n)
{
    for (unsigned i = 0; i < n; ++i) {
        vf3_pvr2_ta_push(g_pvr2, words[i]);
        if (g_ta_file) fwrite(&words[i], 4, 1, g_ta_file);
    }
    ta_fifo_push(words, n);
}

/* An interrupt handler: the game's own code, run with the register file the
 * guest had when the event came (the interrupt itself changes no register;
 * the handler pushes what it needs).  The return address is the sentinel, so
 * the handler's rts ends the nested run. */
static int run_handler(uint32_t entry, const uint32_t regs[37], void *ctx)
{
    (void)ctx;
    uint32_t r[37];
    memcpy(r, regs, sizeof r);
    r[16] = 0xDEAD0000u;               /* the handler returns to the sentinel */
    vf3_native_tick_result hr;
    if (getenv("VF3_HANDLERLOG")) fprintf(stderr, "vf3sdl: handler %08x\n", entry);
    if (!vf3_native_tick_run(g_ram, r, entry, g_gbr, &hr)) {
        fprintf(stderr, "vf3sdl: the handler %08x failed at %08x (%u unowned, first %08x)\n",
                entry, hr.failed_pc, hr.unowned_calls, hr.first_unowned);
        return 0;
    }
    if (hr.unowned_calls) {
        fprintf(stderr, "vf3sdl: the handler %08x called unowned code (%u, first %08x)\n",
                entry, hr.unowned_calls, hr.first_unowned);
        return 0;
    }
    /* the handler's display commands belong to the frame */
    push_ta(hr.ta, hr.ta_words);
    return 1;
}

/* The guest's step budget ran out: time passes and the events that came due
 * are dispatched.
 *
 * The slice that just ended consumed exactly the budget this hook handed out
 * (the generated code counts one step per guest instruction and the budget
 * runs out at zero), so the clock is charged with that many instructions -
 * not with the budget, which would charge the time the slice did *not* use. */
/* The vblank ends the frame the PVR2 model is filling: the blocks the TA received are decoded with our own
 * TA decoder and drawn with our own rasteriser.  Called from the slice hook, so a long-running guest (the
 * boot) is cut into frames too. */
/* VF3_PRESS=<hex mask>,<from>,<hold>,<period>: hold the pad's buttons down for <hold> frames out of every <period>, from frame <from> */
static void press_script(unsigned frame)
{
    static int init;
    static unsigned mask, from, hold, period;
    if (!init) {
        init = 1;
        const char *s = getenv("VF3_PRESS");
        if (s) sscanf(s, "%x,%u,%u,%u", &mask, &from, &hold, &period);
    }
    if (!mask || !period || frame < from) return;
    vf3_frame_events_set_buttons((uint16_t)(((frame - from) % period) < hold ? ~mask : 0xFFFFu));
}

static void frame_boundary(void)
{
    const unsigned vblanks = g_vblanks;
            /* the blocks the TA received this frame, decoded with our own
             * TA decoder and drawn with our own rasteriser */
            const unsigned nw = g_ta_fifo_words;
            vf3_ta_list list;
            int have_list = 0;
            if (nw) have_list = vf3_ta_decode(g_ta_fifo, nw, &list) == 0;
            if (have_list) vf3_pvr2_rasterise(g_pvr2, &list);
            else vf3_pvr2_frame_end(g_pvr2);
            fprintf(stderr, "vf3sdl: frame %u: %u TA words", vblanks, g_pvr2->stats.words);
            for (unsigned c = 0; c < 8; ++c) fprintf(stderr, " %c%u", (char)('0' + c), g_pvr2->stats.classes[c]);
            fprintf(stderr, ", %u pixels, %u render starts, %llu guest instructions",
                    g_pvr2->stats.pixels, g_render_starts,
                    (unsigned long long)(g_insns - g_frame_insns));
            g_frame_insns = g_insns;
            fprintf(stderr, "\n");
            vf3_pvr2_frame_begin(g_pvr2);
            if (have_list) {
                unsigned polys = 0, sprites = 0, textured = 0, modvols = 0;
                float minx = 1e30f, maxx = -1e30f, miny = 1e30f, maxy = -1e30f;
                for (unsigned i = 0; i < list.count; ++i) {
                    const vf3_ta_prim *p = &list.prims[i];
                    if (p->is_sprite) sprites++;
                    else if (p->is_modvol) modvols++;
                    else polys++;
                    if (vf3_ta_texture(p->param.pcw)) textured++;
                    for (unsigned v = 0; v < p->count; ++v) {
                        const vf3_ta_vertex *q = &list.verts[p->vstart + v];
                        if (q->x < minx) minx = q->x;
                        if (q->x > maxx) maxx = q->x;
                        if (q->y < miny) miny = q->y;
                        if (q->y > maxy) maxy = q->y;
                    }
                }
                fprintf(stderr, "vf3sdl:   stream %u words (%u blocks): %s, %u lists, %u primitives"
                                " (%u polygons, %u sprites, %u modvols, %u textured), %u skipped\n",
                        nw, list.blocks, have_list ? "parsed" : "PARSE ERROR", list.lists, list.count,
                        polys, sprites, modvols, textured, list.invalid);
                if (getenv("VF3_TALOG")) {
                    fprintf(stderr, "vf3sdl:   stream head:");
                    for (unsigned i = 0; i < 8 && i < nw; ++i) fprintf(stderr, " %08x", g_ta_fifo[i]);
                    fprintf(stderr, "\n");
                }
                if (list.count)
                    fprintf(stderr, "vf3sdl:   vertex range x %g..%g y %g..%g\n", minx, maxx, miny, maxy);
                vf3_ta_free(&list);
            }
            g_ta_fifo_words = 0;
}

static uint32_t slice_hook(vf3_matrix_state *s)
{
    uint32_t regs[37];
    memcpy(regs, s->v, sizeof regs);
    g_hook_insns += g_budget_out;
    g_insns += g_budget_out;
    if (getenv("VF3_HOST_TRACE"))
        fprintf(stderr, "slice: %llu insns, %u frames, pc %08x pr %08x r8-15 %08x %08x %08x %08x %08x %08x %08x %08x\n", (unsigned long long)g_insns, vf3_frame_events_frames(&g_events), s->pc, s->v[16], s->v[8], s->v[9], s->v[10], s->v[11], s->v[12], s->v[13], s->v[14], s->v[15]);
    /* A slice that ends with the register file it started from is a spin wait (a frame counter, a flag): nothing the
     * guest does can change before the next event, so the clock runs on to the next vblank without executing the
     * instructions.  VF3_NO_IDLE_SKIP=1 turns it off. */
    static uint32_t idle_prev[37];
    static int idle_have;
    const int idle = idle_have && !memcmp(idle_prev, regs, sizeof regs) && !getenv("VF3_NO_IDLE_SKIP");
    memcpy(idle_prev, regs, sizeof regs);
    idle_have = 1;
    const uint32_t next = vf3_frame_events_slice(&g_events, g_budget_out, regs);
    if (idle && next && g_events.next > g_events.now && !g_events.failed) {
        const uint64_t cycles = g_events.next - g_events.now;
        const uint64_t steps = (cycles << 16) / (g_events.cyc_per_insn ? g_events.cyc_per_insn : 1) + 1;
        vf3_frame_events_slice(&g_events, (unsigned)(steps > 0x7FFFFFFFu ? 0x7FFFFFFFu : steps), regs);
        g_skipped += steps;
    }
    {   /* the display commands so far, and the frame the vblank just ended */
        const uint32_t *ta;
        const unsigned n = vf3_native_take_ta(&ta);
        if (n) push_ta(ta, n);
        if (vf3_frame_events_frames(&g_events) != g_vblanks) {
            g_vblanks = vf3_frame_events_frames(&g_events);
            frame_boundary();
            press_script(g_vblanks);
        }
    }
    return next;
}

static uint32_t rd32(const uint8_t *ram, uint32_t a)
{
    uint32_t v;
    const uint32_t off = (a & 0x0FFFFFFFu) - 0x0C000000u;
    if (off + 4u > 0x01000000u) return 0;
    memcpy(&v, ram + off, 4);
    return v;
}

int main(int argc, char **argv)
{
    const char *state = NULL, *vram_out = NULL, *bios_path = NULL, *gdi_path = NULL, *gd_state = NULL, *dump = NULL, *ta_out = NULL, *ram_out = NULL;
    const char *pvr_state = NULL;
    unsigned pair = 0, frames = 1, fps = DEFAULT_FPS;
    uint32_t gbr = DEFAULT_GBR;
    uint32_t entry = VF3_NATIVE_SCHED_ENTRY;
    int headless = 0;

    for (int i = 1; i < argc; ++i) {
        if (!strcmp(argv[i], "--state") && i + 1 < argc) state = argv[++i];
        else if (!strcmp(argv[i], "--pair") && i + 1 < argc) pair = (unsigned)strtoul(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "--frames") && i + 1 < argc) frames = (unsigned)strtoul(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "--gbr") && i + 1 < argc) gbr = (uint32_t)strtoul(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "--entry") && i + 1 < argc) entry = (uint32_t)strtoul(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "--dump-vram") && i + 1 < argc) vram_out = argv[++i];
        else if (!strcmp(argv[i], "--gdi") && i + 1 < argc) gdi_path = argv[++i];
        else if (!strcmp(argv[i], "--bios") && i + 1 < argc) bios_path = argv[++i];
        else if (!strcmp(argv[i], "--gd-state") && i + 1 < argc) gd_state = argv[++i];
        else if (!strcmp(argv[i], "--dump-frame") && i + 1 < argc) dump = argv[++i];
        else if (!strcmp(argv[i], "--pvr-state") && i + 1 < argc) pvr_state = argv[++i];
        else if (!strcmp(argv[i], "--ta-out") && i + 1 < argc) ta_out = argv[++i];
        else if (!strcmp(argv[i], "--dump-ram") && i + 1 < argc) ram_out = argv[++i];
        else if (!strcmp(argv[i], "--fps") && i + 1 < argc) fps = (unsigned)strtoul(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "--slice") && i + 1 < argc) g_slice = (unsigned)strtoul(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "--headless")) headless = 1;
        else { usage(); return 2; }
    }
    if (!state) { usage(); return 2; }

    uint32_t regs[37];
    uint8_t *ram = NULL;
    if (!vf3_native_load_snapshot(state, pair, regs, &ram)) {
        fprintf(stderr, "vf3sdl: no entry state %u in %s\n", pair, state);
        return 2;
    }
    g_ram = ram;
    g_gbr = gbr;

    /* The GD-ROM model: the loader polls it through the BIOS, so a tick that
     * touches the drive needs one attached. */
    vf3_gdi gdi;
    vf3_gdrom gd;
    if (bios_path) {
        static uint8_t *bios; FILE *bf = fopen(bios_path, "rb");
        if (!bf) { fprintf(stderr, "vf3sdl: cannot open %s\n", bios_path); free(ram); return 2; }
        bios = malloc(0x200000u); size_t bl = bios ? fread(bios, 1, 0x200000u, bf) : 0; fclose(bf);
        vf3_native_set_bios(bios, bl);
    }
    if (gdi_path) {
        if (vf3_gdi_open(&gdi, gdi_path) != 0) { fprintf(stderr, "vf3sdl: cannot open %s\n", gdi_path); free(ram); return 2; }
        vf3_gd_init(&gd, &gdi, NULL, NULL);
        (void)gd_state;
        vf3_native_attach_gdrom(&gd);
    }

    /* SDL3: a window and a renderer unless we run headless (the diff runs
     * headless; a frame dump does not need a display). */
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *texture = NULL;
    if (!headless) {
        if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD)) {
            fprintf(stderr, "vf3sdl: SDL_Init failed: %s\n", SDL_GetError());
            free(ram);
            return 2;
        }
        window = SDL_CreateWindow("VF3tb (native port)", VF3_PVR2_WIDTH, VF3_PVR2_HEIGHT, 0);
        if (!window) {
            fprintf(stderr, "vf3sdl: cannot create a window: %s\n", SDL_GetError());
            SDL_Quit();
            free(ram);
            return 2;
        }
        renderer = SDL_CreateRenderer(window, NULL);
        if (!renderer) {
            fprintf(stderr, "vf3sdl: cannot create a renderer: %s\n", SDL_GetError());
            SDL_DestroyWindow(window);
            SDL_Quit();
            free(ram);
            return 2;
        }
        texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING,
                                    VF3_PVR2_WIDTH, VF3_PVR2_HEIGHT);
        if (!texture) {
            fprintf(stderr, "vf3sdl: cannot create the frame texture: %s\n", SDL_GetError());
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            SDL_Quit();
            free(ram);
            return 2;
        }
    }

    if (ta_out) {
        g_ta_file = fopen(ta_out, "wb");
        if (!g_ta_file) fprintf(stderr, "vf3sdl: cannot write %s\n", ta_out);
    }

    vf3_pvr2 pvr2;
    vf3_pvr2_init(&pvr2);
    g_pvr2 = &pvr2;
    g_vramlog = getenv("VF3_VRAMLOG") != NULL;
    vf3_vram_hook = host_vram_write;
    vf3_vram_store_hook = host_vram_store;
    vf3_pvr_lmmode_hook = host_lmmode;
    vf3_pvr_reg_hook = host_reg_write;
    /* The PVR2 is a stateful device: the game programmed its registers at
     * boot, before the port's entry point, so the state comes from the
     * reference (the register file and the VRAM). */
    if (pvr_state) {
        if (vf3_pvr2_load_state(&pvr2, pvr_state) != 0) {
            fprintf(stderr, "vf3sdl: cannot load the PVR2 state %s\n", pvr_state);
            free(ram);
            return 2;
        }
        fprintf(stderr, "vf3sdl: PVR2 state: %ux%u framebuffer, stride %u, pack %u, clip %u..%u %u..%u, %u VRAM bytes\n",
                pvr2.fb_width, pvr2.fb_height, pvr2.fb_stride, pvr2.pack_mode,
                pvr2.clip_x0, pvr2.clip_x1, pvr2.clip_y0, pvr2.clip_y1, pvr2.vram_bytes);
    }

    /* The clock and the frame events.  The TMU starts where the state left
     * it: the game keeps the counter's last sample at 0x0C1981C8. */
    vf3_native_enable_tmu();
    vf3_native_tmu_set(rd32(ram, TCNT0_SAMPLE));
    vf3_frame_events_init(&g_events, ram, gbr, run_handler, NULL);
    g_events.asic_first = 1;            /* the ASIC events before the vblank pair */
    g_events.vblank_through_asic = 1;   /* the vblank-in is ASIC normal-interrupt bit 0x8 */
    g_events.asic2_entry = 0x8C0460E8u; /* the SDK's handler for the bits the game routes through IML2 (the Maple end) */
    g_events.cap = frames;              /* a guest that never returns (the boot) still stops */
    vf3_native_set_budget_hook(slice_hook);
    /* the watchdog: it says where the guest is when the boot stops making
     * progress (the main loop cannot report that itself - it is stuck) */
    g_watch_run = 1;
    g_watch_thread = SDL_CreateThread(watch_thread, "vf3-watch", NULL);

    vf3_native_tick_result r;
    int status = 0;
    const Uint64 frame_us = fps ? 1000000ull / fps : 0;
    Uint64 next = SDL_GetTicksNS();
    uint32_t at = entry;
    uint32_t xf[16];
    vf3_native_get_xf(xf);
    vf3_pvr2_frame_begin(&pvr2);

    while (vf3_frame_events_frames(&g_events) < frames) {
        vf3_native_set_budget(g_slice);
        g_budget_out = g_slice;
        g_hook_insns = 0;
        vf3_native_tick_run(ram, regs, at, gbr, &r);
        vf3_native_set_budget(0);
        {   /* A run that stops making progress: the frame counter stands still
             * while the guest keeps running.  That is a stall (a wait that
             * never ends, or an interrupt handler that fails), and the port
             * says so instead of spinning quietly. */
            static unsigned last_frames, stall_slices;
            const unsigned now = vf3_frame_events_frames(&g_events);
            if (now != last_frames) { last_frames = now; stall_slices = 0; }
            else if (++stall_slices == 64u) {
                fprintf(stderr, "vf3sdl: the boot stalled at frame %u: the last slice ran %u steps,"
                                " ok %d, pc %08x, failed %08x, %u unowned calls\n",
                        now, r.steps_budget_used, r.ok, r.pc, r.failed_pc, r.unowned_calls);
                stall_slices = 0;
            }
        }
        /* The steps of the slice that ended early (the guest returned to the
         * host before its budget ran out): the clock has to carry them too. */
        if (r.ok && r.budget_left <= g_budget_out) {
            const unsigned left = g_budget_out - r.budget_left;
            if (left) {
                g_insns += left;
                vf3_frame_events_slice(&g_events, left, r.regs);
            }
        }
        /* the display commands of this slice */
        push_ta(r.ta, r.ta_words);
        if (r.unowned_calls) {
            fprintf(stderr, "vf3sdl: unowned call at %08x (%u unowned, first %08x)\n",
                    r.failed_pc, r.unowned_calls, r.first_unowned);
            status = 1;
            break;
        }
        if (!r.ok) {
            if (r.failed_pc) {
                /* the slice ran out: resume where it stopped */
                at = r.failed_pc;
            } else if (!r.unowned_calls && r.pc && r.pc != at) {
                /* A callee returned into a frame this run never entered (its pr
                 * came off the stack): that is a hand-back, so resume at the
                 * return address (the boot harness reads it the same way). */
                at = r.pc;
            } else {
                fprintf(stderr, "vf3sdl: the frame ended at %08x with no address\n", r.pc);
                status = 1;
                break;
            }
        } else {
            at = r.pc;
        }
        /* the next slice starts where this one ended */
        memcpy(regs, r.regs, 37 * sizeof regs[0]);
        memcpy(xf, r.regs + 37, 16 * sizeof xf[0]);
        vf3_native_set_xf(xf);
        /* the vblank ends the frame the PVR2 model is filling */
        if (vf3_frame_events_frames(&g_events) != g_vblanks) {
            g_vblanks = vf3_frame_events_frames(&g_events);
            g_render_starts = r.render_starts;
            frame_boundary();
        }
        if (getenv("VF3_VERBOSE")) {
            static const uint32_t watch[] = { 0x0C16CDF4u, 0x0C16CDE8u, 0x0C16CDECu, 0x0C16CDCCu,
                                             0x0C16CDDCu, 0x0C16CE00u, 0x0C1981C8u, 0x0C1981D0u };
            fprintf(stderr, "vf3sdl:   slice steps %u, pc %08x failed %08x ta %u, model %llu cycles %u frames:",
                    r.steps_budget_used, r.pc, r.failed_pc, r.ta_words,
                    (unsigned long long)vf3_frame_events_cycles(&g_events),
                    vf3_frame_events_frames(&g_events));
            for (unsigned i = 0; i < sizeof watch / sizeof *watch; ++i)
                fprintf(stderr, " %08x=%08x", watch[i], rd32(ram, watch[i]));
            fprintf(stderr, " idle-skipped %llu\n", (unsigned long long)g_skipped);
        }

        if (texture) {
            /* the framebuffer is RGB565; the screen wants 32 bit pixels */
            static uint32_t *argb = NULL;
            if (!argb) argb = malloc((size_t)VF3_PVR2_PIXELS * sizeof *argb);
            if (argb) {
                for (unsigned i = 0; i < VF3_PVR2_PIXELS; ++i) {
                    const uint32_t v = pvr2.fb[i];
                    const uint32_t r = ((v >> 11) & 0x1Fu) * 255u / 31u;
                    const uint32_t g = ((v >> 5) & 0x3Fu) * 255u / 63u;
                    const uint32_t b = (v & 0x1Fu) * 255u / 31u;
                    argb[i] = 0xFF000000u | (r << 16) | (g << 8) | b;
                }
                SDL_UpdateTexture(texture, NULL, argb, VF3_PVR2_WIDTH * (int)sizeof(uint32_t));
            }
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            SDL_RenderTexture(renderer, texture, NULL, NULL);
            SDL_RenderPresent(renderer);
        }
        /* events: the window's close button and the keyboard's escape */
        SDL_Event ev;
        while (SDL_PollEvent(&ev)) {
            if (ev.type == SDL_EVENT_QUIT) { status = 0; goto done; }
            if (ev.type == SDL_EVENT_KEY_DOWN && ev.key.key == SDLK_ESCAPE) { goto done; }
        }
        if (frame_us) {
            next += frame_us;
            const Uint64 now = SDL_GetTicksNS();
            if (next > now) SDL_Delay((Uint32)((next - now) / 1000000ull));
            else next = now;
        }
    }
done:
    g_watch_run = 0;
    if (g_watch_thread) { SDL_WaitThread(g_watch_thread, NULL); g_watch_thread = NULL; }
    if (g_vramlog) {
        fprintf(stderr, "vf3sdl: VRAM writes by address megabyte\n");
        for (unsigned r = 0; r < 64u; ++r) {
            if (!g_vram_plain[r] && !g_vram_sq[r]) continue;
            fprintf(stderr, "  %02x000000: plain %llu (%llu nonzero), sq %llu (%llu nonzero)\n",
                    r, (unsigned long long)g_vram_plain[r], (unsigned long long)g_vram_plain_nz[r],
                    (unsigned long long)g_vram_sq[r], (unsigned long long)g_vram_sq_nz[r]);
        }
    }
    if (ram_out) {
        FILE *f = fopen(ram_out, "wb");
        if (f) {
            fwrite(ram, 1, 0x01000000u, f);
            fclose(f);
            fprintf(stderr, "vf3sdl: wrote %s\n", ram_out);
        }
    }
    if (ta_out) {
        if (g_ta_file) {
            fclose(g_ta_file);
            g_ta_file = NULL;
            fprintf(stderr, "vf3sdl: wrote %s\n", ta_out);
        }
    }
    if (vram_out && pvr2.vram) {
        FILE *vf = fopen(vram_out, "wb");
        if (vf) { fwrite(pvr2.vram, 1, pvr2.vram_bytes, vf); fclose(vf); fprintf(stderr, "vf3sdl: wrote %s\n", vram_out); }
    }
    if (dump) {
        if (write_ppm(dump, &pvr2, VF3_PVR2_WIDTH, VF3_PVR2_HEIGHT)) status = 1;
        else fprintf(stderr, "vf3sdl: wrote %s\n", dump);
    }
    vf3_pvr2_free(&pvr2);
    if (texture) SDL_DestroyTexture(texture);
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    if (!headless) SDL_Quit();
    free(ram);
    return status;
}
