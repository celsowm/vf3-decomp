/* Standalone native fight shell.  It loads extracted data from VFA and owns
 * input, presentation, and the frame clock directly through SDL3. */
#include <SDL3/SDL.h>

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "asset_pack.h"
#include "fighter_view.h"
#include "fight.h"
#include "pol.h"
#include "pose_data.h"
#include "pvr_texture.h"
#include "voice_sample.h"

#define WIDTH 960
#define HEIGHT 540
#define FPS 60
#define MAX_FRAME_LAG_DIVISOR 4u

static SDL_Gamepad *g_gamepad;
static SDL_JoystickID g_gamepad_id;
static uint8_t g_keys[SDL_SCANCODE_COUNT];
static uint8_t g_rematch_was_down;
static char g_asset_path[600];

typedef struct {
    SDL_AudioStream *stream;
    int16_t *akira;
    size_t akira_count;
    int16_t *jacky;
    size_t jacky_count;
} native_audio;

static int load_voice_sample(vf3_asset_pack *pack, const char *name,
                             int16_t **pcm, size_t *sample_count)
{
    size_t package_size = 0;
    uint8_t *package;
    int result;

    if (vf3_asset_pack_read(pack, name, NULL, 0, &package_size) != -2 ||
        !package_size || package_size > UINT32_MAX)
        return -1;
    package = (uint8_t *)malloc(package_size);
    if (!package)
        return -1;
    if (vf3_asset_pack_read(pack, name, package, package_size, NULL) != 0) {
        free(package);
        return -1;
    }
    result = vf3_native_voice_decode_sample(package, (uint32_t)package_size,
                                            1u, pcm, sample_count);
    free(package);
    return result;
}

static void native_audio_init(native_audio *audio, vf3_asset_pack *pack)
{
    SDL_AudioSpec spec = { .format = SDL_AUDIO_S16, .channels = 1, .freq = 22050 };

    if (!audio)
        return;
    memset(audio, 0, sizeof *audio);
    if (load_voice_sample(pack, "VO_AKI.BIN", &audio->akira,
                          &audio->akira_count) != 0)
        fprintf(stderr, "vf3port: cannot decode Akira VO sample 1\n");
    if (load_voice_sample(pack, "VO_JAC.BIN", &audio->jacky,
                          &audio->jacky_count) != 0)
        fprintf(stderr, "vf3port: cannot decode Jacky VO sample 1\n");
    if (!SDL_InitSubSystem(SDL_INIT_AUDIO)) {
        fprintf(stderr, "vf3port: audio subsystem unavailable: %s\n", SDL_GetError());
        return;
    }
    audio->stream = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK,
                                               &spec, NULL, NULL);
    if (!audio->stream) {
        fprintf(stderr, "vf3port: audio output unavailable: %s\n", SDL_GetError());
        return;
    }
    SDL_ResumeAudioStreamDevice(audio->stream);
}

static void native_audio_contact(native_audio *audio, uint8_t speaker_kind)
{
    const int16_t *pcm;
    size_t samples;
    if (!audio || !audio->stream)
        return;
    if (speaker_kind == 0u) {
        pcm = audio->akira;
        samples = audio->akira_count;
    } else if (speaker_kind == 7u) {
        pcm = audio->jacky;
        samples = audio->jacky_count;
    } else {
        return;
    }
    if (!pcm || !samples || samples > (size_t)INT_MAX / sizeof *pcm)
        return;
    SDL_PutAudioStreamData(audio->stream, pcm, (int)(samples * sizeof *pcm));
}

static void native_audio_close(native_audio *audio)
{
    if (!audio)
        return;
    if (audio->stream)
        SDL_DestroyAudioStream(audio->stream);
    free(audio->akira);
    free(audio->jacky);
    memset(audio, 0, sizeof *audio);
}

static vf3_fighter_view *fighter_view_for_kind(
    vf3_fighter_view views[4], const vf3_native_fighter *fighter)
{
    if (!views || !fighter || !vf3_native_pose_kind_words(fighter->fighter_kind))
        return NULL;
    if (fighter->fighter_kind == 0)
        return &views[0];
    if (fighter->fighter_kind == 7)
        return &views[1];
    return NULL;
}

static uint32_t frame_delay_ms(uint64_t accumulator, uint64_t frequency)
{
    if (accumulator >= frequency)
        return 0;
    const uint64_t scaled_remaining = frequency - accumulator;
    const uint64_t scaled_frequency = frequency * FPS;
    const uint64_t delay = (scaled_remaining * 1000u) / scaled_frequency;
    return delay ? (uint32_t)delay : 1u;
}

static const char *asset_path(int argc, char **argv)
{
    if (argc > 1) return argv[1];
    const char *base = SDL_GetBasePath();
    if (base && *base) {
        const int written = snprintf(g_asset_path, sizeof g_asset_path,
                                     "%svf3_assets.vfa", base);
        SDL_free((void *)base);
        if (written > 0 && (size_t)written < sizeof g_asset_path) {
            FILE *f = fopen(g_asset_path, "rb");
            if (f) { fclose(f); return g_asset_path; }
        }
    } else if (base) {
        SDL_free((void *)base);
    }
    FILE *f = fopen("vf3_assets.vfa", "rb");
    if (f) { fclose(f); return "vf3_assets.vfa"; }
    return "build/vf3_assets.vfa";
}

static void open_gamepad(void)
{
    if (g_gamepad) return;
    int count = 0;
    SDL_JoystickID *ids = SDL_GetGamepads(&count);
    if (!ids) return;
    for (int i = 0; i < count; ++i) {
        g_gamepad = SDL_OpenGamepad(ids[i]);
        if (g_gamepad) {
            g_gamepad_id = ids[i];
            break;
        }
    }
    SDL_free(ids);
}

static uint32_t read_input(void)
{
    uint32_t input = 0;
    if (g_keys[SDL_SCANCODE_LEFT] || g_keys[SDL_SCANCODE_A]) input |= VF3_NATIVE_MOVE_LEFT;
    if (g_keys[SDL_SCANCODE_RIGHT] || g_keys[SDL_SCANCODE_D]) input |= VF3_NATIVE_MOVE_RIGHT;
    if (g_keys[SDL_SCANCODE_UP] || g_keys[SDL_SCANCODE_W]) input |= VF3_NATIVE_MOVE_BACK;
    if (g_keys[SDL_SCANCODE_DOWN] || g_keys[SDL_SCANCODE_S]) input |= VF3_NATIVE_MOVE_FWD;
    if (g_keys[SDL_SCANCODE_Z]) input |= VF3_NATIVE_PUNCH;
    if (g_keys[SDL_SCANCODE_X]) input |= VF3_NATIVE_KICK;
    if (g_keys[SDL_SCANCODE_V]) input |= VF3_NATIVE_THROW;
    if (g_keys[SDL_SCANCODE_C]) input |= VF3_NATIVE_GUARD;
    if (g_keys[SDL_SCANCODE_RETURN] || g_keys[SDL_SCANCODE_SPACE]) input |= VF3_NATIVE_START;
    int rematch_down = g_keys[SDL_SCANCODE_R] != 0;
    if (!g_gamepad) {
        if (rematch_down && !g_rematch_was_down) input |= VF3_NATIVE_REMATCH;
        g_rematch_was_down = (uint8_t)rematch_down;
        return input;
    }
    if (SDL_GetGamepadButton(g_gamepad, SDL_GAMEPAD_BUTTON_DPAD_LEFT) ||
        SDL_GetGamepadAxis(g_gamepad, SDL_GAMEPAD_AXIS_LEFTX) < -9000)
        input |= VF3_NATIVE_MOVE_LEFT;
    if (SDL_GetGamepadButton(g_gamepad, SDL_GAMEPAD_BUTTON_DPAD_RIGHT) ||
        SDL_GetGamepadAxis(g_gamepad, SDL_GAMEPAD_AXIS_LEFTX) > 9000)
        input |= VF3_NATIVE_MOVE_RIGHT;
    if (SDL_GetGamepadButton(g_gamepad, SDL_GAMEPAD_BUTTON_DPAD_UP) ||
        SDL_GetGamepadAxis(g_gamepad, SDL_GAMEPAD_AXIS_LEFTY) < -9000)
        input |= VF3_NATIVE_MOVE_BACK;
    if (SDL_GetGamepadButton(g_gamepad, SDL_GAMEPAD_BUTTON_DPAD_DOWN) ||
        SDL_GetGamepadAxis(g_gamepad, SDL_GAMEPAD_AXIS_LEFTY) > 9000)
        input |= VF3_NATIVE_MOVE_FWD;
    if (SDL_GetGamepadButton(g_gamepad, SDL_GAMEPAD_BUTTON_SOUTH)) input |= VF3_NATIVE_PUNCH;
    if (SDL_GetGamepadButton(g_gamepad, SDL_GAMEPAD_BUTTON_EAST)) input |= VF3_NATIVE_KICK;
    if (SDL_GetGamepadButton(g_gamepad, SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER)) input |= VF3_NATIVE_THROW;
    if (SDL_GetGamepadButton(g_gamepad, SDL_GAMEPAD_BUTTON_WEST)) input |= VF3_NATIVE_GUARD;
    if (SDL_GetGamepadButton(g_gamepad, SDL_GAMEPAD_BUTTON_START)) input |= VF3_NATIVE_START;
    rematch_down = rematch_down ||
                   SDL_GetGamepadButton(g_gamepad, SDL_GAMEPAD_BUTTON_NORTH);
    if (rematch_down && !g_rematch_was_down) input |= VF3_NATIVE_REMATCH;
    g_rematch_was_down = (uint8_t)rematch_down;
    return input;
}

static void color(SDL_Renderer *r, uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
    SDL_SetRenderDrawColor(r, red, green, blue, alpha);
}

static void fill(SDL_Renderer *r, float x, float y, float w, float h)
{
    SDL_FRect rect = { x, y, w, h };
    SDL_RenderFillRect(r, &rect);
}

static void line(SDL_Renderer *r, float x0, float y0, float x1, float y1)
{
    SDL_RenderLine(r, x0, y0, x1, y1);
}

static void circle(SDL_Renderer *r, float cx, float cy, int radius)
{
    for (int y = -radius; y <= radius; ++y) {
        int x = radius;
        while (x * x + y * y > radius * radius) --x;
        fill(r, cx - (float)x, cy + (float)y, (float)(2 * x + 1), 1.0f);
    }
}

/* Compact 5x7 font for the fight HUD and controls. */
static const uint8_t font[40][5] = {
    {0x7e,0x11,0x11,0x11,0x7e}, {0x7f,0x49,0x49,0x49,0x36},
    {0x3e,0x41,0x41,0x41,0x22}, {0x7f,0x41,0x41,0x22,0x1c},
    {0x7f,0x49,0x49,0x49,0x41}, {0x7f,0x09,0x09,0x09,0x01},
    {0x3e,0x41,0x49,0x49,0x7a}, {0x7f,0x08,0x08,0x08,0x7f},
    {0x00,0x41,0x7f,0x41,0x00}, {0x20,0x40,0x41,0x3f,0x01},
    {0x7f,0x08,0x14,0x22,0x41}, {0x7f,0x40,0x40,0x40,0x40},
    {0x7f,0x02,0x0c,0x02,0x7f}, {0x7f,0x04,0x08,0x10,0x7f},
    {0x3e,0x41,0x41,0x41,0x3e}, {0x7f,0x09,0x09,0x09,0x06},
    {0x3e,0x41,0x51,0x21,0x5e}, {0x7f,0x09,0x19,0x29,0x46},
    {0x46,0x49,0x49,0x49,0x31}, {0x01,0x01,0x7f,0x01,0x01},
    {0x3f,0x40,0x40,0x40,0x3f}, {0x1f,0x20,0x40,0x20,0x1f},
    {0x3f,0x40,0x38,0x40,0x3f}, {0x63,0x14,0x08,0x14,0x63},
    {0x07,0x08,0x70,0x08,0x07}, {0x61,0x51,0x49,0x45,0x43},
    {0x3e,0x51,0x49,0x45,0x3e}, {0x00,0x42,0x7f,0x40,0x00},
    {0x42,0x61,0x51,0x49,0x46}, {0x21,0x41,0x45,0x4b,0x31},
    {0x18,0x14,0x12,0x7f,0x10}, {0x27,0x45,0x45,0x45,0x39},
    {0x3c,0x4a,0x49,0x49,0x30}, {0x01,0x71,0x09,0x05,0x03},
    {0x36,0x49,0x49,0x49,0x36}, {0x06,0x49,0x49,0x29,0x1e},
    {0x00,0x36,0x36,0x00,0x00}, {0x00,0x60,0x60,0x00,0x00},
    {0x08,0x08,0x08,0x08,0x08}, {0x00,0x08,0x3e,0x08,0x00}
};

static int glyph_index(char c)
{
    if (c >= 'A' && c <= 'Z') return c - 'A';
    if (c >= '0' && c <= '9') return 26 + c - '0';
    if (c == ':') return 36;
    if (c == '.') return 37;
    if (c == '-') return 38;
    if (c == '+') return 39;
    return -1;
}

static void text(SDL_Renderer *r, int x, int y, int scale, const char *s)
{
    for (; *s; ++s, x += 6 * scale) {
        const int index = glyph_index(*s);
        if (index < 0) continue;
        for (int col = 0; col < 5; ++col)
            for (int row = 0; row < 7; ++row)
                if ((font[index][col] >> row) & 1u)
                    fill(r, (float)(x + col * scale), (float)(y + row * scale),
                         (float)scale, (float)scale);
    }
}

static void draw_background(SDL_Renderer *r)
{
    color(r, 13, 24, 43, 255);
    fill(r, 0, 0, WIDTH, HEIGHT);
}

static void draw_bar(SDL_Renderer *r, int x, int y, int width, int health, int reverse)
{
    color(r, 17, 20, 25, 255); fill(r, (float)x, (float)y, (float)width, 19);
    const int fill_width = width * health / 100;
    color(r, health > 50 ? 65 : health > 25 ? 214 : 208,
          health > 50 ? 205 : health > 25 ? 173 : 72,
          health > 50 ? 114 : 52, 255);
    fill(r, reverse ? (float)(x + width - fill_width) : (float)x,
         (float)y + 3, (float)fill_width, 13);
    color(r, 237, 228, 202, 255);
    SDL_FRect border = { (float)x, (float)y, (float)width, 19 };
    SDL_RenderRect(r, &border);
}

static void draw_ui(SDL_Renderer *r, const vf3_native_fight *fight)
{
    char buf[32];
    color(r, 238, 222, 180, 255);
    text(r, 68, 36, 3, "AKIRA");
    text(r, 770, 36, 3, "JACKY");
    draw_bar(r, 68, 65, 345, fight->player.health, 0);
    draw_bar(r, 547, 65, 345, fight->cpu.health, 1);
    for (int i = 0; i < fight->player.rounds; ++i) {
        color(r, 239, 192, 92, 255); circle(r, 79.0f + i * 22.0f, 101, 6);
    }
    for (int i = 0; i < fight->cpu.rounds; ++i) {
        color(r, 239, 192, 92, 255); circle(r, 881.0f - i * 22.0f, 101, 6);
    }
    color(r, 247, 237, 207, 255);
    snprintf(buf, sizeof buf, "%02u", fight->timer_frames / FPS);
    text(r, 456, 47, 4, buf);
    if (fight->phase == VF3_NATIVE_TITLE) {
        color(r, 245, 217, 148, 255);
        text(r, 275, 180, 5, "VIRTUA FIGHTER 3TB");
        color(r, 241, 238, 222, 255);
        text(r, 265, 230, 2, "AKIRA VS JACKY - FIRST NATIVE FIGHT SLICE");
        text(r, 230, 455, 2, "ARROWS MOVE   Z PUNCH   X KICK   C GUARD");
        text(r, 300, 475, 2, "THROW: Z+C OR A+X OR V OR RB");
        text(r, 330, 495, 2, "LOW: Z+X+C OR A+B+X");
        text(r, 399, 515, 2, "ENTER TO START");
    } else if (fight->phase == VF3_NATIVE_ROUND_END) {
        color(r, 255, 222, 153, 255);
        if (fight->player.health == 0) text(r, 399, 224, 5, "KNOCK OUT");
        else if (fight->cpu.health == 0) text(r, 399, 224, 5, "YOU WIN");
        else text(r, 426, 224, 5, "TIME UP");
        color(r, 242, 238, 218, 255);
        text(r, 360, 269, 2, "ENTER OR WAIT FOR NEXT ROUND");
    } else if (fight->phase == VF3_NATIVE_MATCH_END) {
        color(r, 255, 222, 153, 255);
        text(r, fight->player.rounds > fight->cpu.rounds ? 359 : 365, 220, 5,
             fight->player.rounds > fight->cpu.rounds ? "YOU WIN MATCH" : "CPU WINS MATCH");
        color(r, 242, 238, 218, 255);
        text(r, 389, 275, 2, "ENTER REMATCH - R RESTART");
    } else {
        color(r, 221, 219, 202, 255);
        text(r, 20, 510, 1, "MOVE: ARROWS   PUNCH: Z/A   KICK: X/B   GUARD: C/X   THROW: Z+C OR A+X OR V OR RB   LOW: Z+X+C OR A+B+X");
    }
}

typedef struct {
    uint8_t *data;
    size_t size;
} loaded_asset;

static void release_assets(loaded_asset *assets, size_t count)
{
    for (size_t i = 0; i < count; ++i) {
        free(assets[i].data);
        assets[i].data = NULL;
        assets[i].size = 0;
    }
}

static int load_fight_assets(vf3_asset_pack *pack, loaded_asset *loaded)
{
    static const char *const required[] = {
        "MKAO_AKI.POL", "MKAO_AKI.TEX", "MKAO_WO2.POL", "MKAO_WO2.TEX",
        "ST01.POL", "ST01.TEX", "ST01_E.POL", "ST01_E.TEX"
    };
    for (size_t i = 0; i < sizeof required / sizeof required[0]; ++i) {
        size_t size = 0;
        if (vf3_asset_pack_read(pack, required[i], NULL, 0, &size) != -2 || !size) {
            fprintf(stderr, "vf3port: asset pack is missing %s\n", required[i]);
            release_assets(loaded, i);
            return -1;
        }
        loaded[i].data = (uint8_t *)malloc(size);
        loaded[i].size = size;
        if (!loaded[i].data || vf3_asset_pack_read(pack, required[i], loaded[i].data,
                                                    loaded[i].size, NULL) != 0) {
            fprintf(stderr, "vf3port: cannot read %s from asset pack\n", required[i]);
            release_assets(loaded, i + 1);
            return -1;
        }
    }
    static const char *const models[] = {
        "MKAO_AKI.POL", "MKAO_WO2.POL", "ST01.POL", "ST01_E.POL"
    };
    static const size_t model_assets[] = { 0u, 2u, 4u, 6u };
    static const size_t texture_assets[] = { 1u, 3u, 5u, 7u };
    for (size_t i = 0; i < sizeof models / sizeof models[0]; ++i) {
        const loaded_asset *asset = &loaded[model_assets[i]];
        const loaded_asset *tex = &loaded[texture_assets[i]];
        PolHeader header;
        uint32_t slot_count = 0, texture_count = 0;
        if (asset->size > UINT32_MAX ||
            pol_header(asset->data, (uint32_t)asset->size, &header) != 0 ||
            pol_slots(asset->data, (uint32_t)asset->size, NULL, 0,
                      &slot_count) != -2 ||
            pol_textures(asset->data, (uint32_t)asset->size, NULL, 0,
                         &texture_count) != -2) {
            fprintf(stderr, "vf3port: invalid POL package %s\n", models[i]);
            release_assets(loaded, 8);
            return -1;
        }
        PolSlot *slots = (PolSlot *)calloc(slot_count, sizeof *slots);
        PolTextureDesc *textures = (PolTextureDesc *)calloc(texture_count,
                                                            sizeof *textures);
        if (!slots || !textures ||
            pol_slots(asset->data, (uint32_t)asset->size, slots, slot_count,
                      &slot_count) != 0 ||
            pol_textures(asset->data, (uint32_t)asset->size, textures,
                         texture_count, &texture_count) != 0) {
            fprintf(stderr, "vf3port: cannot read POL tables %s\n", models[i]);
            free(slots);
            free(textures);
            release_assets(loaded, 8);
            return -1;
        }
        size_t tagged = 0, candidates = 0;
        for (uint32_t row = 0; row < slot_count; ++row) {
            tagged += slots[row].tagged != 0;
            candidates += slots[row].in_file != 0;
        }
        for (uint32_t row = 0; row < texture_count; ++row) {
            const PolTextureDesc *desc = &textures[row];
            size_t bytes = 0;
            if (!desc->width || !desc->height ||
                vf3_pvr_texture_payload_size(desc, &bytes) != 0 ||
                (uint64_t)desc->data_offset + bytes > tex->size) {
                fprintf(stderr, "vf3port: invalid texture descriptor %u in %s\n",
                        row, models[i]);
                free(slots);
                free(textures);
                release_assets(loaded, 8);
                return -1;
            }
        }
        fprintf(stderr,
                "vf3port: %s header valid; %u model slots, %u texture descriptors, %zu tagged slots, %zu in-file candidates\n",
                models[i], slot_count, texture_count, tagged, candidates);
        free(slots);
        free(textures);
    }
    return 0;
}

int main(int argc, char **argv)
{
    vf3_asset_pack pack;
    loaded_asset fight_assets[8] = {{0}};
    vf3_fighter_view fighter_views[4] = {{0}};
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    native_audio audio = {0};
    vf3_native_fight fight;
    int result = 1;

    const char *assets = asset_path(argc, argv);
    if (vf3_asset_pack_open(&pack, assets) != 0) {
        fprintf(stderr, "vf3port: cannot open asset pack %s\n"
                        "Build it with: cmake --build build --target vf3_asset_bundle\n", assets);
        return 1;
    }
    if (load_fight_assets(&pack, fight_assets) != 0) goto done;
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD)) {
        fprintf(stderr, "vf3port: SDL init failed: %s\n", SDL_GetError());
        goto done;
    }
    native_audio_init(&audio, &pack);
    window = SDL_CreateWindow("VF3tb Native C Port", WIDTH, HEIGHT,
                              SDL_WINDOW_RESIZABLE);
    if (!window) {
        fprintf(stderr, "vf3port: window creation failed: %s\n", SDL_GetError());
        goto done_sdl;
    }
    renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer) {
        fprintf(stderr, "vf3port: renderer creation failed: %s\n", SDL_GetError());
        goto done_sdl;
    }
    SDL_SetRenderTextureAddressMode(renderer, SDL_TEXTURE_ADDRESS_WRAP,
                                    SDL_TEXTURE_ADDRESS_WRAP);
    if (vf3_fighter_view_init(renderer, fight_assets[4].data,
                              (uint32_t)fight_assets[4].size,
                              fight_assets[5].data, fight_assets[5].size,
                              &fighter_views[2]) != 0 ||
        vf3_fighter_view_init(renderer, fight_assets[6].data,
                              (uint32_t)fight_assets[6].size,
                              fight_assets[7].data, fight_assets[7].size,
                              &fighter_views[3]) != 0 ||
        vf3_fighter_view_init(renderer, fight_assets[0].data,
                              (uint32_t)fight_assets[0].size,
                              fight_assets[1].data, fight_assets[1].size,
                              &fighter_views[0]) != 0 ||
        vf3_fighter_view_init(renderer, fight_assets[2].data,
                              (uint32_t)fight_assets[2].size,
                              fight_assets[3].data, fight_assets[3].size,
                              &fighter_views[1]) != 0) {
        fprintf(stderr, "vf3port: cannot build textured fighter scenes: %s\n",
                SDL_GetError());
        goto done_sdl;
    }
    release_assets(fight_assets, 8);
    if (!SDL_SetRenderLogicalPresentation(renderer, WIDTH, HEIGHT,
                                          SDL_LOGICAL_PRESENTATION_LETTERBOX))
        fprintf(stderr, "vf3port: logical presentation unavailable: %s\n", SDL_GetError());
    open_gamepad();
    vf3_native_fight_init(&fight);
    const uint64_t clock_frequency = SDL_GetPerformanceFrequency();
    if (!clock_frequency) {
        fprintf(stderr, "vf3port: SDL performance clock is unavailable\n");
        goto done_sdl;
    }
    uint64_t previous_counter = SDL_GetPerformanceCounter();
    uint64_t tick_accumulator = 0;
    vf3_native_fighter previous_player = fight.player;
    vf3_native_fighter previous_cpu = fight.cpu;
    uint32_t pending_edges = 0;
    const uint32_t edge_mask = VF3_NATIVE_PUNCH | VF3_NATIVE_KICK |
                               VF3_NATIVE_THROW | VF3_NATIVE_START |
                               VF3_NATIVE_REMATCH;
    int running = 1;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) running = 0;
            else if ((event.type == SDL_EVENT_KEY_DOWN || event.type == SDL_EVENT_KEY_UP) &&
                     event.key.scancode < SDL_SCANCODE_COUNT)
                g_keys[event.key.scancode] = event.type == SDL_EVENT_KEY_DOWN;
            else if (event.type == SDL_EVENT_GAMEPAD_ADDED) open_gamepad();
            else if (event.type == SDL_EVENT_GAMEPAD_REMOVED && g_gamepad &&
                     event.gdevice.which == g_gamepad_id) {
                SDL_CloseGamepad(g_gamepad);
                g_gamepad = NULL;
            }
        }
        const uint32_t input = read_input();
        pending_edges |= input & edge_mask;
        const uint64_t now = SDL_GetPerformanceCounter();
        uint64_t elapsed = now - previous_counter;
        previous_counter = now;
        /* A debugger pause or window switch should not force the fight to
         * simulate minutes of unseen frames when the window resumes. */
        const uint64_t max_elapsed = clock_frequency / MAX_FRAME_LAG_DIVISOR;
        if (elapsed > max_elapsed)
            elapsed = max_elapsed;
        tick_accumulator += elapsed * FPS;
        while (tick_accumulator >= clock_frequency) {
            const uint32_t tick_input = input | pending_edges;
            pending_edges = 0;
            previous_player = fight.player;
            previous_cpu = fight.cpu;
            vf3_native_fight_step(&fight, tick_input);
            if (fight.sound_event)
                native_audio_contact(&audio, fight.sound_speaker_kind);
            tick_accumulator -= clock_frequency;
        }
        vf3_native_fighter render_player = fight.player;
        vf3_native_fighter render_cpu = fight.cpu;
        const float render_alpha = (float)tick_accumulator /
                                   (float)clock_frequency;
        render_player.x = previous_player.x +
                          (fight.player.x - previous_player.x) * render_alpha;
        render_player.depth = previous_player.depth +
                              (fight.player.depth - previous_player.depth) * render_alpha;
        render_cpu.x = previous_cpu.x +
                       (fight.cpu.x - previous_cpu.x) * render_alpha;
        render_cpu.depth = previous_cpu.depth +
                           (fight.cpu.depth - previous_cpu.depth) * render_alpha;
        vf3_fighter_view *player_view = fighter_view_for_kind(fighter_views,
                                                               &render_player);
        vf3_fighter_view *cpu_view = fighter_view_for_kind(fighter_views,
                                                            &render_cpu);
        color(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        draw_background(renderer);
        vf3_stage_view_draw(renderer, &fighter_views[2], 480.0f, 336.0f,
                            2.32f);
        vf3_stage_view_draw(renderer, &fighter_views[3], 480.0f, 336.0f,
                            2.32f);
        if (fight.phase != VF3_NATIVE_TITLE && player_view && cpu_view) {
            const float player_x = 145.0f + render_player.x * 670.0f;
            const float cpu_x = 145.0f + render_cpu.x * 670.0f;
            const float player_ground = 301.0f + render_player.depth * 119.0f;
            const float cpu_ground = 301.0f + render_cpu.depth * 119.0f;
            const float player_scale = 345.0f + render_player.depth * 105.0f;
            const float cpu_scale = 345.0f + render_cpu.depth * 105.0f;
            if (render_player.depth > render_cpu.depth) {
                vf3_fighter_view_draw_model_slot(renderer, cpu_view,
                                      &render_cpu, 3u,
                                      cpu_x, cpu_ground, cpu_scale);
                vf3_fighter_view_draw_model_slot(renderer, player_view,
                                      &render_player, 3u,
                                      player_x, player_ground, player_scale);
            } else {
                vf3_fighter_view_draw_model_slot(renderer, player_view,
                                      &render_player, 3u,
                                      player_x, player_ground, player_scale);
                vf3_fighter_view_draw_model_slot(renderer, cpu_view,
                                      &render_cpu, 3u,
                                      cpu_x, cpu_ground, cpu_scale);
            }
        }
        draw_ui(renderer, &fight);
        SDL_RenderPresent(renderer);
        SDL_Delay(frame_delay_ms(tick_accumulator, clock_frequency));
    }
    result = 0;
done_sdl:
    native_audio_close(&audio);
    if (g_gamepad) SDL_CloseGamepad(g_gamepad);
    vf3_fighter_view_free(&fighter_views[3]);
    vf3_fighter_view_free(&fighter_views[2]);
    vf3_fighter_view_free(&fighter_views[1]);
    vf3_fighter_view_free(&fighter_views[0]);
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
    SDL_Quit();
done:
    release_assets(fight_assets, sizeof fight_assets / sizeof fight_assets[0]);
    vf3_asset_pack_close(&pack);
    return result;
}
