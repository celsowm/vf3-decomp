/* Diagnostic host program only. No game code, game data or emulation is run. */
#include "platform/sdl_platform.h"
#include <SDL3/SDL_main.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void usage(const char *program)
{
    fprintf(stderr, "Usage: %s [--frames N] [--hidden]\n"
            "SDL3 host diagnostic; displays a generated test pattern, not VF3 gameplay.\n", program);
}

int main(int argc, char **argv)
{
    vf3_platform_config config = {"VF3 SDL3 host diagnostic - not gameplay", 0, 0};
    vf3_platform *platform;
    vf3_maple_pad pads[VF3_HOST_PLAYERS];
    uint32_t *pixels;
    unsigned long frame, frames = 300;
    uint64_t start, deadline;
    int arg, result = 0;
    for (arg = 1; arg < argc; ++arg) {
        if (!strcmp(argv[arg], "--hidden")) config.hidden = 1;
        else if (!strcmp(argv[arg], "--frames") && arg + 1 < argc) {
            char *end;
            const char *value = argv[++arg];
            errno = 0;
            frames = strtoul(value, &end, 10);
            if (errno || end == value || *end || value[0] == '-' || !frames || frames > 10000000ul) {
                usage(argv[0]); return 2;
            }
        } else if (!strcmp(argv[arg], "--help")) { usage(argv[0]); return 0; }
        else { usage(argv[0]); return 2; }
    }
    fprintf(stderr, "SDL3 host diagnostic only: window, framebuffer, clock and input.\n"
            "No ROM boot, PVR rasterization, audio or game loop is implemented here.\n"
            "P1: arrows/Z/X/A/S/Enter; P2: I/K/J/L/V/B/F/G/Right Shift. Escape quits.\n");
    platform = vf3_platform_create(&config);
    if (!platform) { fprintf(stderr, "%s\n", vf3_platform_error()); return 1; }
    pixels = (uint32_t *)malloc(VF3_FRAME_WIDTH * VF3_FRAME_HEIGHT * sizeof *pixels);
    if (!pixels) { fprintf(stderr, "Framebuffer allocation failed\n"); vf3_platform_destroy(platform); return 1; }
    start = vf3_platform_time_ns();
    for (frame = 0; frame < frames && vf3_platform_poll(platform, pads); ++frame) {
        int x, y;
        for (y = 0; y < VF3_FRAME_HEIGHT; ++y) {
            for (x = 0; x < VF3_FRAME_WIDTH; ++x) {
                uint32_t color = 0xff000000u | ((uint32_t)x * 255u / (VF3_FRAME_WIDTH - 1) << 16) |
                    ((uint32_t)y * 255u / (VF3_FRAME_HEIGHT - 1) << 8) | 0x30u;
                if (x >= (int)(frame % VF3_FRAME_WIDTH) && x < (int)(frame % VF3_FRAME_WIDTH) + 4)
                    color = 0xffffffffu;
                if (y < 24 && x < 48) color = pads[0].buttons == 0xffffu ? 0xff303030u : 0xff00ff00u;
                if (y < 24 && x >= 48 && x < 96) color = pads[1].buttons == 0xffffu ? 0xff303030u : 0xff00ff00u;
                pixels[y * VF3_FRAME_WIDTH + x] = color;
            }
        }
        if (!vf3_platform_present(platform, pixels, VF3_FRAME_WIDTH * (int)sizeof *pixels)) {
            fprintf(stderr, "%s\n", vf3_platform_error()); result = 1; break;
        }
        /* Diagnostic cadence only; exact game timing belongs to the runtime. */
        deadline = start + (frame + 1) * UINT64_C(1000000000) / 60;
        {
            const uint64_t now = vf3_platform_time_ns();
            if (now < deadline) vf3_platform_sleep_ns(deadline - now);
        }
    }
    printf("host_diagnostic frames=%lu result=%s (not gameplay)\n", frame, result ? "fail" : "ok");
    free(pixels);
    vf3_platform_destroy(platform);
    return result;
}
