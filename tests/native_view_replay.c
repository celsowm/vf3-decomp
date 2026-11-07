/* Render the extracted fighters and their real POL textures offscreen. */
#include "fighter_view.h"
#include "asset_pack.h"

#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    uint8_t *data;
    size_t size;
} blob;

#define MAX_PREVIEW_SLOTS 64u

static int load(vf3_asset_pack *pack, const char *name, blob *out)
{
    size_t size = 0;
    if (vf3_asset_pack_read(pack, name, NULL, 0, &size) != -2 || !size)
        return -1;
    out->data = (uint8_t *)malloc(size);
    if (!out->data || vf3_asset_pack_read(pack, name, out->data, size, NULL) != 0) {
        free(out->data);
        out->data = NULL;
        return -1;
    }
    out->size = size;
    return 0;
}

static void release(blob *b)
{
    free(b->data);
    b->data = NULL;
    b->size = 0;
}

static int load_view(SDL_Renderer *renderer, vf3_asset_pack *pack,
                     const char *stem,
                     vf3_fighter_view *view)
{
    char pol_name[128], tex_name[128];
    blob pol = {0}, tex = {0};
    int rc = -1;
    snprintf(pol_name, sizeof pol_name, "%s.POL", stem);
    snprintf(tex_name, sizeof tex_name, "%s.TEX", stem);
    if (load(pack, pol_name, &pol) != 0 || load(pack, tex_name, &tex) != 0 ||
        pol.size > UINT32_MAX)
        goto done;
    rc = vf3_fighter_view_init(renderer, pol.data, (uint32_t)pol.size,
                               tex.data, tex.size, view);
done:
    release(&tex);
    release(&pol);
    return rc;
}

static int parse_u32(const char *text, uint32_t *out)
{
    char *end = NULL;
    unsigned long value;
    if (!text || !*text || !out)
        return -1;
    errno = 0;
    value = strtoul(text, &end, 0);
    if (errno == ERANGE || end == text || *end || value > UINT32_MAX)
        return -1;
    *out = (uint32_t)value;
    return 0;
}

static int read_pose_matrices(const char *path,
                             float matrices[VF3_NATIVE_BONE_COUNT]
                                            [VF3_NATIVE_BONE_MATRIX_FLOATS])
{
    uint8_t bytes[VF3_NATIVE_BONE_COUNT * VF3_NATIVE_BONE_MATRIX_FLOATS * 4u];
    FILE *file = fopen(path, "rb");
    if (!file)
        return -1;
    const size_t expected = sizeof bytes;
    const size_t count = fread(bytes, 1, expected, file);
    const int extra = fgetc(file);
    const int failed = ferror(file);
    fclose(file);
    if (count != expected || extra != EOF || failed)
        return -1;
    for (size_t word = 0; word < expected / 4u; ++word) {
        const uint8_t *p = bytes + word * 4u;
        const uint32_t bits = (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
                              ((uint32_t)p[2] << 16) |
                              ((uint32_t)p[3] << 24);
        float *matrix_words = (float *)matrices;
        memcpy(&matrix_words[word], &bits, sizeof bits);
        if (!isfinite(matrix_words[word]))
            return -1;
    }
    return 0;
}

static int has_model_slot(const vf3_fighter_view *view, uint32_t slot)
{
    for (uint32_t i = 0; i < view->scene.model_count; ++i)
        if (view->scene.models[i].slot_index == slot)
            return 1;
    return 0;
}

static void draw_slots(SDL_Renderer *renderer, vf3_fighter_view *view,
                       const vf3_native_fighter *fighter,
                       const uint32_t *slots, size_t slot_count,
                       float center_x, float ground_y, float scale)
{
    for (size_t i = 0; i < slot_count; ++i)
        vf3_fighter_view_draw_model_slot(renderer, view, fighter, slots[i],
                                         center_x, ground_y, scale);
}

static size_t collect_model_slots(const vf3_fighter_view *view,
                                  uint32_t *slots, size_t capacity)
{
    size_t count = 0;
    for (uint32_t i = 0; i < view->scene.model_count; ++i) {
        const uint32_t slot = view->scene.models[i].slot_index;
        size_t at = 0;
        while (at < count && slots[at] < slot)
            ++at;
        if (at < count && slots[at] == slot)
            continue;
        if (count == capacity)
            return 0;
        memmove(&slots[at + 1], &slots[at], (count - at) * sizeof *slots);
        slots[at] = slot;
        ++count;
    }
    return count;
}

int main(int argc, char **argv)
{
    SDL_Surface *surface = NULL;
    SDL_Renderer *renderer = NULL;
    vf3_asset_pack pack;
    int pack_open = 0;
    vf3_fighter_view akira = {0}, jacky = {0}, stage = {0}, stage_ext = {0};
    vf3_native_fighter left = {0}, right = {0};
    const uint8_t bg_r = 13, bg_g = 24, bg_b = 43, bg_a = 255;
    uint32_t shared_slots[MAX_PREVIEW_SLOTS];
    uint32_t akira_slots[MAX_PREVIEW_SLOTS];
    uint32_t jacky_slots[MAX_PREVIEW_SLOTS];
    size_t shared_slot_count = 0, akira_slot_count = 0, jacky_slot_count = 0;
    size_t grid_slot_count = 0;
    int character_specific = 0;
    int grid_mode = 0, grid_jacky = 0;
    int jac_bone_candidate = 0, pose_loaded = 0;
    const char *pose_path = NULL;
    float pose_matrices[VF3_NATIVE_BONE_COUNT][VF3_NATIVE_BONE_MATRIX_FLOATS];
    const char *output_path = "build/vf3_native_preview.bmp";
    uint32_t bg_pixel;
    size_t changed = 0;
    int result = 1;

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "--slot") == 0 && i + 1 < argc) {
            if (shared_slot_count == MAX_PREVIEW_SLOTS ||
                parse_u32(argv[++i], &shared_slots[shared_slot_count]) != 0) {
                fprintf(stderr, "native_view_replay: invalid --slot value\n");
                return 2;
            }
            ++shared_slot_count;
        } else if (strcmp(argv[i], "--aki-slot") == 0 && i + 1 < argc) {
            character_specific = 1;
            if (akira_slot_count == MAX_PREVIEW_SLOTS ||
                parse_u32(argv[++i], &akira_slots[akira_slot_count]) != 0) {
                fprintf(stderr, "native_view_replay: invalid --aki-slot value\n");
                return 2;
            }
            ++akira_slot_count;
        } else if (strcmp(argv[i], "--jac-slot") == 0 && i + 1 < argc) {
            character_specific = 1;
            if (jacky_slot_count == MAX_PREVIEW_SLOTS ||
                parse_u32(argv[++i], &jacky_slots[jacky_slot_count]) != 0) {
                fprintf(stderr, "native_view_replay: invalid --jac-slot value\n");
                return 2;
            }
            ++jacky_slot_count;
        } else if (strcmp(argv[i], "--grid-aki") == 0) {
            grid_mode = 1;
        } else if (strcmp(argv[i], "--grid-jac") == 0) {
            grid_mode = 1;
            grid_jacky = 1;
        } else if (strcmp(argv[i], "--jac-bone-candidate") == 0) {
            jac_bone_candidate = 1;
        } else if (strcmp(argv[i], "--pose-bin") == 0 && i + 1 < argc) {
            pose_path = argv[++i];
        } else if (strcmp(argv[i], "--output") == 0 && i + 1 < argc) {
            output_path = argv[++i];
        } else if (strcmp(argv[i], "--help") == 0) {
            printf("usage: vf3nativeviewtest [--slot N ... | --aki-slot N ... --jac-slot N ... | --grid-aki | --grid-jac | --jac-bone-candidate --pose-bin FILE] [--output BMP]\n");
            return 0;
        } else {
            fprintf(stderr, "native_view_replay: unknown or incomplete argument: %s\n",
                    argv[i]);
            fprintf(stderr, "usage: vf3nativeviewtest [--slot N ... | --aki-slot N ... --jac-slot N ... | --grid-aki | --grid-jac | --jac-bone-candidate --pose-bin FILE] [--output BMP]\n");
            return 2;
        }
    }
    if ((character_specific && shared_slot_count) ||
        (grid_mode && (character_specific || shared_slot_count))) {
        fprintf(stderr, "native_view_replay: use one slot-selection mode at a time\n");
        return 2;
    }
    if ((jac_bone_candidate != 0) != (pose_path != NULL)) {
        fprintf(stderr, "native_view_replay: --jac-bone-candidate and --pose-bin must be used together\n");
        return 2;
    }
    if (!character_specific) {
        if (shared_slot_count == 0) {
            shared_slots[0] = 3u;
            shared_slot_count = 1;
        }
        memcpy(akira_slots, shared_slots, shared_slot_count * sizeof *shared_slots);
        memcpy(jacky_slots, shared_slots, shared_slot_count * sizeof *shared_slots);
        akira_slot_count = jacky_slot_count = shared_slot_count;
    }
    if (jac_bone_candidate) {
        if (grid_mode || character_specific || shared_slot_count != 1u ||
            shared_slots[0] != 3u || read_pose_matrices(pose_path, pose_matrices) != 0) {
            fprintf(stderr, "native_view_replay: candidate mode needs default slot 3 and a valid 1472-byte finite pose dump\n");
            goto done;
        }
        pose_loaded = 1;
    }

    if (vf3_asset_pack_open(&pack, "build/vf3_assets.vfa") != 0) {
        fprintf(stderr, "native_view_replay: cannot open build/vf3_assets.vfa\n");
        goto done;
    }
    pack_open = 1;
    surface = SDL_CreateSurface(960, grid_mode ? 840 : 540,
                                SDL_PIXELFORMAT_ARGB8888);
    if (!surface || !(renderer = SDL_CreateSoftwareRenderer(surface))) {
        fprintf(stderr, "native_view_replay: software renderer failed: %s\n",
                SDL_GetError());
        goto done;
    }
    SDL_SetRenderTextureAddressMode(renderer, SDL_TEXTURE_ADDRESS_WRAP,
                                    SDL_TEXTURE_ADDRESS_WRAP);
    if (load_view(renderer, &pack, "ST01", &stage) != 0 ||
        load_view(renderer, &pack, "ST01_E", &stage_ext) != 0 ||
        load_view(renderer, &pack, "MKAO_AKI", &akira) != 0 ||
        load_view(renderer, &pack, "MKAO_JAC", &jacky) != 0) {
        fprintf(stderr, "native_view_replay: could not load stage/fighter scenes: %s\n",
                SDL_GetError());
        goto done;
    }
    for (size_t i = 0; i < akira_slot_count; ++i) {
        if (!has_model_slot(&akira, akira_slots[i])) {
            fprintf(stderr, "native_view_replay: Akira slot %u is not present in MKAO_AKI.POL\n",
                    akira_slots[i]);
            goto done;
        }
    }
    for (size_t i = 0; i < jacky_slot_count; ++i) {
        if (!has_model_slot(&jacky, jacky_slots[i])) {
            fprintf(stderr, "native_view_replay: Jacky slot %u is not present in MKAO_JAC.POL\n",
                    jacky_slots[i]);
            goto done;
        }
    }
    left.facing = 1;
    left.depth = 0.58f;
    left.action = VF3_NATIVE_IDLE;
    right.facing = -1;
    right.depth = 0.42f;
    right.action = VF3_NATIVE_IDLE;
    SDL_SetRenderDrawColor(renderer, bg_r, bg_g, bg_b, bg_a);
    SDL_RenderClear(renderer);
    if (grid_mode) {
        uint32_t grid_slots[MAX_PREVIEW_SLOTS];
        vf3_fighter_view *view = grid_jacky ? &jacky : &akira;
        const vf3_native_fighter *fighter = grid_jacky ? &right : &left;
        const size_t count = collect_model_slots(view, grid_slots,
                                                 MAX_PREVIEW_SLOTS);
        if (!count) {
            fprintf(stderr, "native_view_replay: model slot grid exceeds capacity\n");
            goto done;
        }
        SDL_SetRenderDrawColor(renderer, bg_r, bg_g, bg_b, bg_a);
        SDL_RenderClear(renderer);
        for (size_t i = 0; i < count; ++i) {
            const int column = (int)(i % 6u);
            const int row = (int)(i / 6u);
            printf("grid cell %zu: slot %u\n", i, grid_slots[i]);
            draw_slots(renderer, view, fighter, &grid_slots[i], 1,
                       (float)(column * 160 + 80),
                       (float)(row * 140 + 124), 600.0f);
        }
        grid_slot_count = count;
    } else {
        vf3_stage_view_draw(renderer, &stage, 480.0f, 336.0f, 2.32f);
        vf3_stage_view_draw(renderer, &stage_ext, 480.0f, 336.0f, 2.32f);
        if (left.depth > right.depth) {
            draw_slots(renderer, &jacky, &right, jacky_slots, jacky_slot_count,
                       614.0f, 351.0f, 389.0f);
            draw_slots(renderer, &akira, &left, akira_slots, akira_slot_count,
                       346.0f, 370.0f, 406.0f);
        } else {
            draw_slots(renderer, &akira, &left, akira_slots, akira_slot_count,
                       346.0f, 370.0f, 406.0f);
            draw_slots(renderer, &jacky, &right, jacky_slots, jacky_slot_count,
                       614.0f, 351.0f, 389.0f);
        }
        if (pose_loaded) {
            for (uint32_t bone = 0; bone < VF3_NATIVE_BONE_COUNT; ++bone) {
                vf3_fighter_view_draw_model_bone(
                    renderer, &jacky, &right, 17u + bone, pose_matrices, bone,
                    614.0f, 351.0f, 389.0f);
            }
        }
    }
    SDL_RenderPresent(renderer);
    if (!SDL_SaveBMP(surface, output_path)) {
        fprintf(stderr, "native_view_replay: could not save %s: %s\n",
                output_path, SDL_GetError());
        goto done;
    }
    bg_pixel = SDL_MapSurfaceRGBA(surface, bg_r, bg_g, bg_b, bg_a);
    if (!SDL_LockSurface(surface)) {
        fprintf(stderr, "native_view_replay: surface lock failed: %s\n",
                SDL_GetError());
        goto done;
    }
    for (int y = 0; y < surface->h; ++y) {
        const uint32_t *row = (const uint32_t *)((const uint8_t *)surface->pixels +
                                                 y * surface->pitch);
        for (int x = 0; x < surface->w; ++x)
            changed += row[x] != bg_pixel;
    }
    SDL_UnlockSurface(surface);
    if (!grid_mode && changed < 5000u) {
        fprintf(stderr, "native_view_replay: too few fighter pixels rendered (%zu)\n",
                changed);
        goto done;
    }
    if (grid_mode)
        printf("native_view_replay: rendered %zu %s model slots in a grid (%zu textured pixels; %s)\n",
               grid_slot_count, grid_jacky ? "Jacky" : "Akira", changed,
               output_path);
    else
        printf("native_view_replay: rendered ST01/ST01_E and %zu Akira / %zu Jacky slot(s)%s (%zu textured pixels; %s)\n",
               akira_slot_count, jacky_slot_count,
               pose_loaded ? " plus Jacky candidate bone mapping 17..39 -> 0..22" : "",
               changed, output_path);
    result = 0;
done:
    vf3_fighter_view_free(&stage_ext);
    vf3_fighter_view_free(&stage);
    vf3_fighter_view_free(&jacky);
    vf3_fighter_view_free(&akira);
    if (renderer) SDL_DestroyRenderer(renderer);
    if (surface) SDL_DestroySurface(surface);
    if (pack_open) vf3_asset_pack_close(&pack);
    return result;
}
