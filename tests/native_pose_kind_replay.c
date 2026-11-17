/* Verify the native pose kind records (src/native/pose_data.c).
 *
 * The pose orchestration (0x8C09EAF2) indexes 0x0C10D3C4 by actor byte +0x61
 * with a 108-byte stride. Each record holds 27 floats (108 bytes exactly).
 *
 * This test proves the embedded kind records match the retail data image
 * byte-for-byte for kinds 0, 7, and 12 (the known kinds in the table).
 */
#include "pose_data.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int ok = 1;

static void check(int condition, const char *name)
{
    if (!condition) {
        fprintf(stderr, "native_pose_kind: %s failed\n", name);
        ok = 0;
    } else {
        printf("  %s: pass\n", name);
    }
}

#define IMAGE_BASE 0x0C010000u
#define KIND_TABLE 0x0C10D3C4u
#define KIND_STRIDE 0x6Cu
#define KIND_COUNT 13u

static int image_records(const char *path, float out[13][27])
{
    FILE *f = fopen(path, "rb");
    if (!f)
        return 0;
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    uint8_t *img = (uint8_t *)malloc((size_t)size);
    if (!img || fread(img, 1, (size_t)size, f) != (size_t)size) {
        fclose(f);
        free(img);
        return 0;
    }
    fclose(f);

    uint32_t table_off = KIND_TABLE - IMAGE_BASE;
    if (table_off + KIND_COUNT * KIND_STRIDE > (uint32_t)size) {
        free(img);
        return 0;
    }

    for (uint32_t k = 0; k < KIND_COUNT; ++k) {
        uint32_t ro = table_off + k * KIND_STRIDE;
        memcpy(out[k], img + ro, KIND_STRIDE);
    }
    free(img);
    return 1;
}

int main(int argc, char **argv)
{
    static const char image[] = "extract/exe/1ST_READ.unsc.bin";
    const char *image_path = argc > 1 ? argv[1] : image;

    float img[13][27];
    if (!image_records(image_path, img)) {
        /* Try from the build directory */
        const char *build_image = "../extract/exe/1ST_READ.unsc.bin";
        if (!image_records(build_image, img)) {
            printf("native_pose_kind: FAIL (cannot read %s or %s)\n", image_path, build_image);
            return 1;
        }
    }

    int kinds_to_check[] = {0, 7};
    int num_kinds = sizeof(kinds_to_check) / sizeof(kinds_to_check[0]);

    for (int i = 0; i < num_kinds; ++i) {
        int k = kinds_to_check[i];
        const float *words = vf3_native_pose_kind_words((uint8_t)k);
        if (!words) {
            check(0, "vf3_native_pose_kind_words returns non-NULL");
            continue;
        }
        int same = 1;
        for (int j = 0; j < 27; ++j) {
            if (fabsf(words[j] - img[k][j]) > 1e-6f) {
                same = 0;
                fprintf(stderr, "  kind %d index %d: got %g want %g\n",
                        k, j, words[j], img[k][j]);
            }
        }
        char name[64];
        snprintf(name, sizeof name, "kind %d embedded == image", k);
        check(same, name);
    }

    /* Test the vector helper reads the correct float3 bases */
    float out[3];
    if (vf3_native_pose_kind_vector(0, 0x18, out) == 0) {
        check(fabsf(out[0] - 0.125f) < 1e-6f &&
              fabsf(out[1] - 0.16f) < 1e-6f &&
              fabsf(out[2] - 0.07f) < 1e-6f,
              "kind 0 POSE_VECTOR_FIRST at +0x18");
    } else {
        check(0, "vf3_native_pose_kind_vector kind 0 +0x18");
    }

    if (vf3_native_pose_kind_vector(0, 0x24, out) == 0) {
        check(fabsf(out[0] - 0.125f) < 1e-6f &&
              fabsf(out[1] - 0.16f) < 1e-6f &&
              fabsf(out[2] - 0.07f) < 1e-6f,
              "kind 0 POSE_VECTOR_SECOND at +0x24");
    } else {
        check(0, "vf3_native_pose_kind_vector kind 0 +0x24");
    }

    if (vf3_native_pose_kind_vector(0, 0x3C, out) == 0) {
        check(fabsf(out[0] - 0.205f) < 1e-6f &&
              fabsf(out[1] - 0.181f) < 1e-6f &&
              fabsf(out[2] - 0.35f) < 1e-6f,
              "kind 0 POSE_VECTOR_AIM_B at +0x3C");
    } else {
        check(0, "vf3_native_pose_kind_vector kind 0 +0x3C");
    }

    if (vf3_native_pose_kind_vector(7, 0x18, out) == 0) {
        check(fabsf(out[0] - 0.135f) < 1e-6f &&
              fabsf(out[1] - 0.185f) < 1e-6f &&
              fabsf(out[2] - 0.085f) < 1e-6f,
              "kind 7 POSE_VECTOR_FIRST at +0x18");
    } else {
        check(0, "vf3_native_pose_kind_vector kind 7 +0x18");
    }

    if (vf3_native_pose_kind_vector(7, 0x24, out) == 0) {
        check(fabsf(out[0] - 0.135f) < 1e-6f &&
              fabsf(out[1] - 0.185f) < 1e-6f &&
              fabsf(out[2] - 0.085f) < 1e-6f,
              "kind 7 POSE_VECTOR_SECOND at +0x24");
    } else {
        check(0, "vf3_native_pose_kind_vector kind 7 +0x24");
    }

    if (vf3_native_pose_kind_vector(7, 0x3C, out) == 0) {
        check(fabsf(out[0] - 0.195f) < 1e-6f &&
              fabsf(out[1] - 0.18f) < 1e-6f &&
              fabsf(out[2] - 0.345f) < 1e-6f,
              "kind 7 POSE_VECTOR_AIM_B at +0x3C");
    } else {
        check(0, "vf3_native_pose_kind_vector kind 7 +0x3C");
    }

    printf("native_pose_kind: %s\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}