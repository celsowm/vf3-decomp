/* Diagnostic MT-animation preview for the native fight shell.
 *
 * It reads an extracted MT*.BIN asset from the VFA, evaluates a motion at
 * several Q8 phases, feeds the 42 pose fields to the current inferred rig in
 * motion_pose.c, and renders through the same part renderer as the shell.
 * The evaluator and renderer path run end to end, but the inferred rig is not
 * a recovered VF3 skeleton; the output is diagnostic, not proof of correct
 * motion playback.
 *
 *   vf3nativemotionpreview --assets build/vf3_assets.vfa \
 *       --fighter akira --mt MTAKIAKI.BIN --motion 0x63e --cycle 50 \
 *       --frames 0 6 --out build/motion_frame_%02u.bmp
 */
#include "asset_pack.h"
#include "akira_parts.h"
#include "fighter_view.h"
#include "jacky_parts.h"
#include "matrix.h"
#include "motion_pose.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { VIEW_W = 960, VIEW_H = 540 };

typedef struct { uint8_t *data; size_t size; } blob;

static int load_asset(vf3_asset_pack *pack, const char *name, blob *out)
{
    size_t size = 0;
    if (vf3_asset_pack_read(pack, name, NULL, 0, &size) != -2 || !size ||
        size > UINT32_MAX)
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
        load_asset(pack, tex_name, &tex) != 0 ||
        pol.size > UINT32_MAX)
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

int main(int argc, char **argv)
{
    const char *asset_path = "build/vf3_assets.vfa";
    const char *fighter_name = "jacky";
    const char *mt_asset = "MTJACJAC.BIN";
    const char *output_fmt = "build/motion_frame_%02u.bmp";
    uint32_t motion_id = 0x63e;
    uint32_t cycle = 60;
    uint32_t start_frame = 0, frame_count = 8;
    int is_akira = 0;
    int dump_fields = 0;
    int zero_fields = 0;
    int dump_matrices = 0;
    int use_row0 = 0;
    vf3_native_motion_actor actor_state;
    memset(&actor_state, 0, sizeof actor_state);
    vf3_asset_pack pack;
    blob mt = { 0 };
    MtFile file;
    MtMotionView storage;
    vf3_native_motion_stream stream;
    float matrices[VF3_NATIVE_ATTACHMENT_COUNT]
                  [VF3_NATIVE_ATTACHMENT_MATRIX_FLOATS];
    vf3_fighter_view base = { 0 }, rob = { 0 };
    vf3_native_fighter fighter = { 0 };
    SDL_Surface *surface = NULL;
    SDL_Renderer *renderer = NULL;
    int pack_open = 0;
    int result = 1;

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "--assets") == 0 && i + 1 < argc)
            asset_path = argv[++i];
        else if (strcmp(argv[i], "--fighter") == 0 && i + 1 < argc) {
            fighter_name = argv[++i];
            if (strcmp(fighter_name, "akira") != 0 &&
                strcmp(fighter_name, "jacky") != 0) {
                fprintf(stderr, "fighter must be akira or jacky\n");
                return 2;
            }
            is_akira = strcmp(fighter_name, "akira") == 0;
        } else if (strcmp(argv[i], "--mt") == 0 && i + 1 < argc)
            mt_asset = argv[++i];
        else if (strcmp(argv[i], "--motion") == 0 && i + 1 < argc) {
            if (parse_u32(argv[++i], &motion_id) != 0) return 2;
        } else if (strcmp(argv[i], "--cycle") == 0 && i + 1 < argc) {
            if (parse_u32(argv[++i], &cycle) != 0 || cycle > UINT16_MAX) return 2;
        } else if (strcmp(argv[i], "--frames") == 0 && i + 2 < argc) {
            if (parse_u32(argv[++i], &start_frame) != 0 ||
                parse_u32(argv[++i], &frame_count) != 0 || frame_count == 0)
                return 2;
        } else if (strcmp(argv[i], "--out") == 0 && i + 1 < argc)
            output_fmt = argv[++i];
        else if (strcmp(argv[i], "--dump-fields") == 0)
            dump_fields = 1;
        else if (strcmp(argv[i], "--zero-fields") == 0)
            zero_fields = 1;
        else if (strcmp(argv[i], "--dump-matrices") == 0)
            dump_matrices = 1;
        else if (strcmp(argv[i], "--row0") == 0)
            use_row0 = 1;
        else if (strcmp(argv[i], "--yaw") == 0 && i + 1 < argc) {
            const long value = strtol(argv[++i], NULL, 0);
            actor_state.yaw = (uint16_t)(int16_t)value;
        } else if (strcmp(argv[i], "--pos") == 0 && i + 1 < argc) {
            if (sscanf(argv[++i], "%f,%f,%f", &actor_state.position[0],
                       &actor_state.position[1], &actor_state.position[2]) != 3)
                return 2;
        } else if (strcmp(argv[i], "--mode") == 0 && i + 1 < argc) {
            unsigned long value = strtoul(argv[++i], NULL, 0);
            actor_state.mode = (uint8_t)value;
        } else if (strcmp(argv[i], "--flags") == 0 && i + 1 < argc) {
            unsigned long value = strtoul(argv[++i], NULL, 0);
            actor_state.flags = (uint32_t)value;
        } else if (strcmp(argv[i], "--pose-flags") == 0 && i + 1 < argc) {
            unsigned long value = strtoul(argv[++i], NULL, 0);
            actor_state.pose_flags = (uint32_t)value;
        } else if (strcmp(argv[i], "--global-flags") == 0 && i + 1 < argc) {
            unsigned long value = strtoul(argv[++i], NULL, 0);
            actor_state.global_flags = (uint32_t)value;
        } else if (strcmp(argv[i], "--arg") == 0 && i + 1 < argc) {
            const long value = strtol(argv[++i], NULL, 0);
            actor_state.arg = (int16_t)value;
        } else if (strcmp(argv[i], "--offset") == 0 && i + 1 < argc) {
            if (sscanf(argv[++i], "%f,%f,%f", &actor_state.offset[0],
                       &actor_state.offset[1], &actor_state.offset[2]) != 3)
                return 2;
        } else if (strcmp(argv[i], "--help") == 0) {
            printf("usage: vf3nativemotionpreview [--assets VFA] "
                   "[--fighter akira|jacky] [--mt MT*.BIN] [--motion ID] "
                   "[--cycle N] [--frames START COUNT] [--out FMT] "
                   "[--row0 --yaw N --pos X,Y,Z --mode N --flags N "
                   "--pose-flags N --global-flags N --arg N "
                   "--offset X,Y,Z]\n");
            return 0;
        } else {
            fprintf(stderr, "unknown argument: %s\n", argv[i]);
            return 2;
        }
    }

    if (vf3_asset_pack_open(&pack, asset_path) != 0) {
        fprintf(stderr, "cannot open asset pack %s\n", asset_path);
        goto done;
    }
    pack_open = 1;
    if (load_asset(&pack, mt_asset, &mt) != 0 ||
        mt_parse(mt.data, (uint32_t)mt.size, &file) != 0) {
        fprintf(stderr, "cannot parse MT asset %s\n", mt_asset);
        goto done;
    }
    if (vf3_native_motion_load(&file, motion_id, (uint16_t)cycle,
                               &storage, &stream) != 0) {
        fprintf(stderr, "motion 0x%x absent/malformed in %s\n", motion_id,
                mt_asset);
        goto done;
    }
    if (cycle == 0) {
        fprintf(stderr, "motion cycle must be nonzero\n");
        goto done;
    }

    surface = SDL_CreateSurface(VIEW_W, VIEW_H, SDL_PIXELFORMAT_ARGB8888);
    if (!surface || !(renderer = SDL_CreateSoftwareRenderer(surface))) {
        fprintf(stderr, "SDL software renderer failed: %s\n", SDL_GetError());
        goto done;
    }
    SDL_SetRenderTextureAddressMode(renderer, SDL_TEXTURE_ADDRESS_WRAP,
                                    SDL_TEXTURE_ADDRESS_WRAP);
    const char *mkao_stem = is_akira ? "MKAO_AKI" : "MKAO_WO2";
    const char *rob_stem = is_akira ? "ROB_AKI" : "ROB_WO2";
    if (load_view(renderer, &pack, mkao_stem, &base) != 0 ||
        load_view(renderer, &pack, rob_stem, &rob) != 0) {
        fprintf(stderr, "cannot load %s POL/TEX assets\n",
                is_akira ? "Akira" : "Jacky");
        goto done;
    }
    fighter.facing = 1;
    fighter.fighter_kind = is_akira ? 0 : 7;
    fighter.action = VF3_NATIVE_IDLE;
    const vf3_native_motion_rig rig = is_akira
        ? VF3_NATIVE_MOTION_RIG_AKIRA : VF3_NATIVE_MOTION_RIG_JACKY;

    for (uint32_t frame = 0; frame < frame_count; ++frame) {
        const uint32_t frame_in_cycle = (uint32_t)(
            ((uint64_t)start_frame + frame) % cycle);
        const int32_t phase = (int32_t)((uint64_t)frame_in_cycle * 0x100u);
        char output[512];
        int status;
        if (zero_fields) {
            int16_t zeros[VF3_NATIVE_POSE_FIELDS] = { 0 };
            if (vf3_native_motion_pose_fields(zeros, rig, matrices) != 0) {
                fprintf(stderr, "bind pose failed at frame %u (cycle frame %u)\n",
                        start_frame + frame, frame_in_cycle);
                goto done;
            }
        } else if (use_row0) {
            if (vf3_native_motion_pose_actor(&stream, phase, rig,
                                             &actor_state, matrices) != 0) {
                fprintf(stderr, "motion_pose_actor failed at frame %u "
                                "(cycle frame %u)\n",
                        start_frame + frame, frame_in_cycle);
                goto done;
            }
        } else if (vf3_native_motion_pose(&stream, phase, rig, matrices) != 0) {
            fprintf(stderr, "motion_pose failed at frame %u (cycle frame %u)\n",
                    start_frame + frame, frame_in_cycle);
            goto done;
        }
        if (dump_matrices && frame == 0) {
            for (uint32_t row = 0; row < VF3_NATIVE_ATTACHMENT_COUNT; ++row)
                printf("row %2u t=(%8.4f,%8.4f,%8.4f)\n", row,
                       matrices[row][12], matrices[row][13],
                       matrices[row][14]);
        }
        if (dump_fields) {
            float channels[VF3_NATIVE_MOTION_CHANNELS];
            uint16_t fields[VF3_NATIVE_POSE_FIELDS];
            if (vf3_native_motion_eval_pose_fields(&stream, phase, channels,
                                                   fields) == 0) {
                printf("phase %d fields:", (int)phase);
                for (size_t f = 0; f < VF3_NATIVE_POSE_FIELDS; ++f)
                    printf(" %d", (int)(int16_t)fields[f]);
                printf("\n");
            }
        }
        if (snprintf(output, sizeof output, output_fmt, start_frame + frame) < 0)
            goto done;
        SDL_SetRenderDrawColor(renderer, 13, 24, 43, 255);
        SDL_RenderClear(renderer);
        status = is_akira
            ? vf3_native_akira_draw(renderer, &base, &rob, &fighter, matrices,
                                    NULL, 480.0f, 320.0f, 300.0f)
            : vf3_native_jacky_draw(renderer, &base, &rob, &fighter, matrices,
                                    NULL, 480.0f, 320.0f, 300.0f);
        if (status != 0) {
            fprintf(stderr, "%s draw failed at frame %u\n", fighter_name,
                    start_frame + frame);
            goto done;
        }
        SDL_RenderPresent(renderer);
        if (!SDL_SaveBMP(surface, output)) {
            fprintf(stderr, "could not save %s: %s\n", output, SDL_GetError());
            goto done;
        }
        printf("frame=%u phase_q8=%#x -> %s\n",
               start_frame + frame, (unsigned)phase, output);
    }
    result = 0;
done:
    release_blob(&mt);
    vf3_fighter_view_free(&rob);
    vf3_fighter_view_free(&base);
    if (renderer) SDL_DestroyRenderer(renderer);
    if (surface) SDL_DestroySurface(surface);
    if (pack_open) vf3_asset_pack_close(&pack);
    return result;
}
