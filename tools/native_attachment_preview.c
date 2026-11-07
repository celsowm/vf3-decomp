/* Offline preview for a fighter's live POL attachment table.
 *
 * This tool composes extracted POL slots with an exported 18-row attachment
 * matrix file. The matrices are captured guest evidence for review only; this
 * executable is not linked into vf3port and is not a runtime pose source.
 */
#include "asset_pack.h"
#include "akira_parts.h"
#include "fighter_view.h"
#include "jacky_parts.h"

#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
    DRAW_CAPACITY = 18,
    MATRIX_BYTES = 18 * 16 * 4,
    PREVIEW_SOURCE_MKAO = 0,
    PREVIEW_SOURCE_ROB = 1
};

typedef struct {
    uint8_t *data;
    size_t size;
} blob;

typedef struct {
    uint32_t entry;
    uint32_t slot;
    uint8_t source;
} attachment_draw;

typedef struct {
    uint8_t source;
    uint8_t slot;
} preview_selector;

static int load_asset(vf3_asset_pack *pack, const char *name, blob *out)
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

static void release_blob(blob *asset)
{
    free(asset->data);
    asset->data = NULL;
    asset->size = 0;
}

static int load_view(SDL_Renderer *renderer, vf3_asset_pack *pack,
                     const char *stem, vf3_fighter_view *view)
{
    char pol_name[96], tex_name[96];
    blob pol = { 0 }, tex = { 0 };
    int result = -1;
    if (snprintf(pol_name, sizeof pol_name, "%s.POL", stem) < 0 ||
        snprintf(tex_name, sizeof tex_name, "%s.TEX", stem) < 0)
        return -1;
    if (load_asset(pack, pol_name, &pol) != 0 ||
        load_asset(pack, tex_name, &tex) != 0 || pol.size > UINT32_MAX)
        goto done;
    result = vf3_fighter_view_init(renderer, pol.data, (uint32_t)pol.size,
                                   tex.data, tex.size, view);
done:
    release_blob(&tex);
    release_blob(&pol);
    return result;
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

static int parse_float(const char *text, float *out)
{
    char *end = NULL;
    float value;
    if (!text || !*text || !out)
        return -1;
    errno = 0;
    value = strtof(text, &end);
    if (errno == ERANGE || end == text || *end || !isfinite(value))
        return -1;
    *out = value;
    return 0;
}

static int parse_attachment(const char *text, attachment_draw *out)
{
    char *separator;
    char *end = NULL;
    unsigned long entry, slot;
    if (!text || !out)
        return -1;
    errno = 0;
    entry = strtoul(text, &end, 0);
    if (errno == ERANGE || end == text || *end != ':' || entry >= 18u)
        return -1;
    separator = end + 1;
    errno = 0;
    slot = strtoul(separator, &end, 0);
    if (errno == ERANGE || end == separator || *end || slot > UINT32_MAX)
        return -1;
    out->entry = (uint32_t)entry;
    out->slot = (uint32_t)slot;
    return 0;
}

static int read_matrices(const char *path,
                         float matrices[VF3_NATIVE_ATTACHMENT_COUNT]
                                      [VF3_NATIVE_ATTACHMENT_MATRIX_FLOATS])
{
    uint8_t bytes[MATRIX_BYTES];
    FILE *file = fopen(path, "rb");
    size_t count;
    int extra, failed;
    if (!file)
        return -1;
    count = fread(bytes, 1, sizeof bytes, file);
    extra = fgetc(file);
    failed = ferror(file);
    fclose(file);
    if (count != sizeof bytes || extra != EOF || failed)
        return -1;
    for (size_t word = 0; word < sizeof bytes / 4u; ++word) {
        const uint8_t *p = bytes + word * 4u;
        const uint32_t bits = (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
                              ((uint32_t)p[2] << 16) |
                              ((uint32_t)p[3] << 24);
        float *values = (float *)matrices;
        memcpy(&values[word], &bits, sizeof bits);
        if (!isfinite(values[word]))
            return -1;
    }
    return 0;
}

static int read_scene_matrix(const char *path, float matrix[16])
{
    uint8_t bytes[16u * 4u];
    FILE *file = fopen(path, "rb");
    size_t count;
    int extra, failed;
    if (!file)
        return -1;
    count = fread(bytes, 1, sizeof bytes, file);
    extra = fgetc(file);
    failed = ferror(file);
    fclose(file);
    if (count != sizeof bytes || extra != EOF || failed)
        return -1;
    for (size_t word = 0; word < 16u; ++word) {
        const uint8_t *p = bytes + word * 4u;
        const uint32_t bits = (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
                              ((uint32_t)p[2] << 16) |
                              ((uint32_t)p[3] << 24);
        memcpy(&matrix[word], &bits, sizeof bits);
        if (!isfinite(matrix[word]))
            return -1;
    }
    return 0;
}

static int has_slot(const vf3_fighter_view *view, uint32_t slot)
{
    for (uint32_t i = 0; i < view->scene.model_count; ++i)
        if (view->scene.models[i].slot_index == slot)
            return 1;
    return 0;
}

static void usage(FILE *stream)
{
    fprintf(stream,
            "usage: vf3nativeattachmentpreview --matrix-bin FILE "
            "[--fighter akira|jacky] "
            "[--scene-matrix-bin FILE] [--assets VFA] [--output BMP] [--base-slot N] "
            "[--base-entry N | --base-at-root] "
            "[--scale N] [--ground-y N] [--attachment ENTRY:SLOT ...]\n"
            "Default fighter: Jacky. Attachments default to the recovered selector map.\n");
}

int main(int argc, char **argv)
{
    const char *asset_path = "build/vf3_assets.vfa";
    const char *fighter_name = "jacky";
    const char *matrix_path = NULL;
    const char *scene_matrix_path = NULL;
    const char *output_path = "build/vf3_native_attachment_preview.bmp";
    attachment_draw draws[DRAW_CAPACITY];
    preview_selector selectors[18] = { 0 };
    size_t draw_count = 0;
    size_t selector_count = 0;
    uint32_t base_slot = 3u;
    uint32_t base_entry = 1u;
    float scale = 300.0f;
    float ground_y = 320.0f;
    float matrices[VF3_NATIVE_ATTACHMENT_COUNT]
                  [VF3_NATIVE_ATTACHMENT_MATRIX_FLOATS];
    float scene_matrix[16];
    int has_scene_matrix = 0;
    vf3_native_fighter fighter = { 0 };
    vf3_asset_pack pack;
    vf3_fighter_view base = { 0 }, attachments = { 0 };
    SDL_Surface *surface = NULL;
    SDL_Renderer *renderer = NULL;
    int pack_open = 0;
    int custom_draws = 0;
    int is_akira = 0;
    int base_root = 0;
    int base_entry_set = 0;
    int result = 1;

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "--fighter") == 0 && i + 1 < argc) {
            fighter_name = argv[++i];
            if (strcmp(fighter_name, "akira") != 0 &&
                strcmp(fighter_name, "jacky") != 0) {
                fprintf(stderr, "vf3nativeattachmentpreview: fighter must be akira or jacky\n");
                return 2;
            }
            is_akira = strcmp(fighter_name, "akira") == 0;
        } else if (strcmp(argv[i], "--assets") == 0 && i + 1 < argc) {
            asset_path = argv[++i];
        } else if (strcmp(argv[i], "--matrix-bin") == 0 && i + 1 < argc) {
            matrix_path = argv[++i];
        } else if (strcmp(argv[i], "--scene-matrix-bin") == 0 && i + 1 < argc) {
            scene_matrix_path = argv[++i];
        } else if (strcmp(argv[i], "--output") == 0 && i + 1 < argc) {
            output_path = argv[++i];
        } else if (strcmp(argv[i], "--base-slot") == 0 && i + 1 < argc) {
            if (parse_u32(argv[++i], &base_slot) != 0) {
                fprintf(stderr, "vf3nativeattachmentpreview: invalid base slot\n");
                return 2;
            }
        } else if (strcmp(argv[i], "--base-entry") == 0 && i + 1 < argc) {
            if (parse_u32(argv[++i], &base_entry) != 0 || base_entry >= 18u) {
                fprintf(stderr, "vf3nativeattachmentpreview: base entry must be 0..17\n");
                return 2;
            }
            base_entry_set = 1;
        } else if (strcmp(argv[i], "--base-at-root") == 0) {
            base_root = 1;
        } else if (strcmp(argv[i], "--scale") == 0 && i + 1 < argc) {
            if (parse_float(argv[++i], &scale) != 0 || scale <= 0.0f) {
                fprintf(stderr, "vf3nativeattachmentpreview: scale must be finite and positive\n");
                return 2;
            }
        } else if (strcmp(argv[i], "--ground-y") == 0 && i + 1 < argc) {
            if (parse_float(argv[++i], &ground_y) != 0) {
                fprintf(stderr, "vf3nativeattachmentpreview: ground-y must be finite\n");
                return 2;
            }
        } else if (strcmp(argv[i], "--attachment") == 0 && i + 1 < argc) {
            if (!custom_draws) {
                draw_count = 0;
                custom_draws = 1;
            }
            if (draw_count == DRAW_CAPACITY ||
                parse_attachment(argv[++i], &draws[draw_count]) != 0) {
                fprintf(stderr, "vf3nativeattachmentpreview: invalid attachment ENTRY:SLOT\n");
                return 2;
            }
            ++draw_count;
        } else if (strcmp(argv[i], "--help") == 0) {
            usage(stdout);
            return 0;
        } else {
            fprintf(stderr, "vf3nativeattachmentpreview: unknown or incomplete argument: %s\n",
                    argv[i]);
            usage(stderr);
            return 2;
        }
    }
    if (!matrix_path) {
        fprintf(stderr, "vf3nativeattachmentpreview: --matrix-bin is required\n");
        usage(stderr);
        return 2;
    }
    if (base_root && base_entry_set) {
        fprintf(stderr, "vf3nativeattachmentpreview: use either --base-entry or --base-at-root\n");
        return 2;
    }
    if (is_akira) {
        const vf3_native_akira_selector_entry *map =
            vf3_native_akira_selector_map(&selector_count);
        for (size_t i = 0; i < selector_count; ++i) {
            selectors[i].source = map[i].source == VF3_NATIVE_AKIRA_PART_MKAO_AKI
                ? PREVIEW_SOURCE_MKAO :
                  map[i].source == VF3_NATIVE_AKIRA_PART_ROB_AKI
                    ? PREVIEW_SOURCE_ROB : UINT8_MAX;
            selectors[i].slot = map[i].slot;
        }
    } else {
        const vf3_native_jacky_selector_entry *map =
            vf3_native_jacky_selector_map(&selector_count);
        for (size_t i = 0; i < selector_count; ++i) {
            selectors[i].source = map[i].source == VF3_NATIVE_JACKY_PART_MKAO_WO2
                ? PREVIEW_SOURCE_MKAO :
                  map[i].source == VF3_NATIVE_JACKY_PART_ROB_WO2
                    ? PREVIEW_SOURCE_ROB : UINT8_MAX;
            selectors[i].slot = map[i].slot;
        }
    }
    if (custom_draws) {
        for (size_t i = 0; i < draw_count; ++i) {
            if (draws[i].entry >= selector_count ||
                selectors[draws[i].entry].source == UINT8_MAX) {
                fprintf(stderr, "vf3nativeattachmentpreview: entry %u is empty or out of range\n",
                        draws[i].entry);
                return 2;
            }
            draws[i].source = selectors[draws[i].entry].source;
        }
    } else {
        for (size_t i = 0; i < selector_count; ++i) {
            if (selectors[i].source == PREVIEW_SOURCE_ROB) {
                draws[draw_count].entry = (uint32_t)i;
                draws[draw_count].slot = selectors[i].slot;
                draws[draw_count].source = PREVIEW_SOURCE_ROB;
                ++draw_count;
            }
        }
    }
    if (read_matrices(matrix_path, matrices) != 0) {
        fprintf(stderr, "vf3nativeattachmentpreview: cannot read 1152 finite matrix bytes from %s\n",
                matrix_path);
        goto done;
    }
    if (scene_matrix_path) {
        if (read_scene_matrix(scene_matrix_path, scene_matrix) != 0) {
            fprintf(stderr, "vf3nativeattachmentpreview: cannot read 64 finite scene-matrix bytes from %s\n",
                    scene_matrix_path);
            goto done;
        }
        has_scene_matrix = 1;
    }
    if (vf3_asset_pack_open(&pack, asset_path) != 0) {
        fprintf(stderr, "vf3nativeattachmentpreview: cannot open %s\n", asset_path);
        goto done;
    }
    pack_open = 1;
    surface = SDL_CreateSurface(960, 540, SDL_PIXELFORMAT_ARGB8888);
    if (!surface || !(renderer = SDL_CreateSoftwareRenderer(surface))) {
        fprintf(stderr, "vf3nativeattachmentpreview: SDL software renderer failed: %s\n",
                SDL_GetError());
        goto done;
    }
    SDL_SetRenderTextureAddressMode(renderer, SDL_TEXTURE_ADDRESS_WRAP,
                                    SDL_TEXTURE_ADDRESS_WRAP);
    const char *mkao_stem = is_akira ? "MKAO_AKI" : "MKAO_WO2";
    const char *rob_stem = is_akira ? "ROB_AKI" : "ROB_WO2";
    if (load_view(renderer, &pack, mkao_stem, &base) != 0 ||
        load_view(renderer, &pack, rob_stem, &attachments) != 0) {
        fprintf(stderr, "vf3nativeattachmentpreview: could not load %s POL/TEX assets: %s\n",
                is_akira ? "Akira" : "Jacky",
                SDL_GetError());
        goto done;
    }
    if (!has_slot(&base, base_slot)) {
        fprintf(stderr, "vf3nativeattachmentpreview: base slot %u is absent from %s\n",
                base_slot, mkao_stem);
        goto done;
    }
    for (size_t i = 0; i < draw_count; ++i) {
        vf3_fighter_view *view = draws[i].source == PREVIEW_SOURCE_MKAO
            ? &base : &attachments;
        const char *stem = draws[i].source == PREVIEW_SOURCE_MKAO
            ? mkao_stem : rob_stem;
        if (!has_slot(view, draws[i].slot)) {
            fprintf(stderr, "vf3nativeattachmentpreview: %s slot %u is absent\n",
                    stem, draws[i].slot);
            goto done;
        }
    }

    fighter.facing = 1;
    fighter.action = VF3_NATIVE_IDLE;
    SDL_SetRenderDrawColor(renderer, 13, 24, 43, 255);
    SDL_RenderClear(renderer);
    if (!custom_draws && !base_root && !base_entry_set && base_slot == 3u) {
        const int draw_status = is_akira
            ? vf3_native_akira_draw(renderer, &base, &attachments, &fighter,
                                    matrices,
                                    has_scene_matrix ? scene_matrix : NULL,
                                    480.0f, ground_y, scale)
            : vf3_native_jacky_draw(renderer, &base, &attachments, &fighter,
                                    matrices,
                                    has_scene_matrix ? scene_matrix : NULL,
                                    480.0f, ground_y, scale);
        if (draw_status != 0) {
            fprintf(stderr, "vf3nativeattachmentpreview: invalid %s selector assets\n",
                    is_akira ? "Akira" : "Jacky");
            goto done;
        }
    } else {
        if (base_root)
            vf3_fighter_view_draw_model_slot(renderer, &base, &fighter, base_slot,
                                             480.0f, ground_y, scale);
        else if (has_scene_matrix)
            vf3_fighter_view_draw_model_attachment_scene(
                renderer, &base, &fighter, base_slot, matrices, scene_matrix,
                base_entry, 480.0f, ground_y, scale);
        else
            vf3_fighter_view_draw_model_attachment(renderer, &base, &fighter,
                                                   base_slot, matrices, base_entry,
                                                   480.0f, ground_y, scale);
        for (size_t i = 0; i < draw_count; ++i) {
            vf3_fighter_view *view = draws[i].source == PREVIEW_SOURCE_MKAO
                ? &base : &attachments;
            if (has_scene_matrix)
                vf3_fighter_view_draw_model_attachment_scene(
                    renderer, view, &fighter, draws[i].slot, matrices,
                    scene_matrix, draws[i].entry, 480.0f, ground_y, scale);
            else
                vf3_fighter_view_draw_model_attachment(
                    renderer, view, &fighter, draws[i].slot, matrices,
                    draws[i].entry, 480.0f, ground_y, scale);
        }
    }
    SDL_RenderPresent(renderer);
    if (!SDL_SaveBMP(surface, output_path)) {
        fprintf(stderr, "vf3nativeattachmentpreview: could not save %s: %s\n",
                output_path, SDL_GetError());
        goto done;
    }
    printf("vf3nativeattachmentpreview: rendered %s slot %u%s and %zu "
           "ROB attachments from diagnostic matrix rows%s to %s\n",
           is_akira ? "MKAO_AKI" : "MKAO_WO2",
           base_slot, base_root ? " at the root" : " with its attachment row",
           draw_count, has_scene_matrix ? " with the shared scene matrix" : "",
           output_path);
    result = 0;
done:
    vf3_fighter_view_free(&attachments);
    vf3_fighter_view_free(&base);
    if (renderer) SDL_DestroyRenderer(renderer);
    if (surface) SDL_DestroySurface(surface);
    if (pack_open) vf3_asset_pack_close(&pack);
    return result;
}
