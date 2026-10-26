/* host/sdl3_host.c - the SDL3 host for the native port.
 *
 *   vf3sdl --state FILE [--pair N] [--frames N] [--gbr ADDR] [--gdi DISC]
 *           [--gd-state FILE] [--dump-frame FILE.ppm] [--headless] [--fps N]
 *
 * Loads a machine state the port can run from, runs the fight tick once per
 * frame, hands the Tile Accelerator command stream to the PVR2 model and
 * presents the frame the model produced.
 *
 * Phase P0 of docs/re/plan_sdl3_port.md.  What is real today: the host, the
 * frame loop over the native tick, the TA stream into the PVR2 model and the
 * frame out to SDL3.  What is not: the PVR2 model has no rasteriser yet (the
 * frame is black), the audio stream carries silence, and the gamepad is read
 * but not yet routed into the Maple bus (phase P6).
 *
 * The host owns no game logic: the game code keeps talking to the Dreamcast's
 * addresses and the models intercept the regions it writes to.
 */
#include <SDL3/SDL.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fight/native_tick.h"
#include "render/pvr2.h"
#include "sys/gdrom_hle.h"

#define DEFAULT_GBR 0x0C16B880u        /* the fight tasks' global-state block */
#define DEFAULT_FPS 60                 /* the NTSC field rate the DC ran at */

/* A PPM (P6) of the last frame: the diff tool and any image viewer read it. */
static int write_ppm(const char *path, const uint32_t *fb, unsigned w, unsigned h)
{
    FILE *f = fopen(path, "wb");
    if (!f) { fprintf(stderr, "vf3sdl: cannot write %s\n", path); return 1; }
    fprintf(f, "P6\n%u %u\n255\n", w, h);
    unsigned char *row = malloc((size_t)w * 3);
    if (!row) { fclose(f); return 1; }
    for (unsigned y = 0; y < h; ++y) {
        for (unsigned x = 0; x < w; ++x) {
            const uint32_t px = fb[(size_t)y * w + x];
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
            "              [--dump-frame FILE.ppm] [--headless] [--fps N]\n");
}

int main(int argc, char **argv)
{
    const char *state = NULL, *gdi_path = NULL, *gd_state = NULL, *dump = NULL;
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
        else if (!strcmp(argv[i], "--gdi") && i + 1 < argc) gdi_path = argv[++i];
        else if (!strcmp(argv[i], "--gd-state") && i + 1 < argc) gd_state = argv[++i];
        else if (!strcmp(argv[i], "--dump-frame") && i + 1 < argc) dump = argv[++i];
        else if (!strcmp(argv[i], "--fps") && i + 1 < argc) fps = (unsigned)strtoul(argv[++i], NULL, 0);
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

    /* The GD-ROM model: the loader polls it through the BIOS, so a tick that
     * touches the drive needs one attached. */
    vf3_gdi gdi;
    vf3_gdrom gd;
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

    vf3_pvr2 pvr2;
    vf3_pvr2_init(&pvr2);

    vf3_native_tick_result r;
    int status = 0;
    const Uint64 frame_us = fps ? 1000000ull / fps : 0;
    Uint64 next = SDL_GetTicksNS();
    for (unsigned frame = 0; frame < frames; ++frame) {
        vf3_pvr2_frame_begin(&pvr2);
        vf3_native_tick_run(ram, regs, entry, gbr, &r);
        if (!r.ok || r.unowned_calls) {
            fprintf(stderr, "vf3sdl: frame %u failed at %08x (%u unowned calls, first %08x)\n",
                    frame, r.failed_pc, r.unowned_calls, r.first_unowned);
            status = 1;
            break;
        }
        /* the next frame starts where this one ended */
        memcpy(regs, r.regs, 37 * sizeof regs[0]);
        for (unsigned i = 0; i < r.ta_words; ++i) vf3_pvr2_ta_push(&pvr2, r.ta[i]);
        vf3_pvr2_frame_end(&pvr2);
        fprintf(stderr, "vf3sdl: frame %u: %u TA words", frame, r.ta_words);
        for (unsigned c = 0; c < 8; ++c) fprintf(stderr, " %c%u", (char)('0' + c), pvr2.stats.classes[c]);
        fprintf(stderr, ", %u pixels\n", pvr2.stats.pixels);

        if (texture) {
            SDL_UpdateTexture(texture, NULL, vf3_pvr2_framebuffer(&pvr2), VF3_PVR2_WIDTH * (int)sizeof(uint32_t));
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            SDL_RenderTexture(renderer, texture, NULL, NULL);
            SDL_RenderPresent(renderer);
        }
        /* events: the window's close button and the keyboard's escape */
        SDL_Event ev;
        while (SDL_PollEvent(&ev)) {
            if (ev.type == SDL_EVENT_QUIT) { frames = frame + 1; status = 0; goto done; }
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
    if (dump) {
        if (write_ppm(dump, vf3_pvr2_framebuffer(&pvr2), VF3_PVR2_WIDTH, VF3_PVR2_HEIGHT)) status = 1;
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
