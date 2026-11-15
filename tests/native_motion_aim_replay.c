/* Prove the native aim-record table (src/native/motion_pose.c).
 *
 * The pose orchestration (0x8C09EAF2) selects its aim record with the actor
 * byte at +0x420B: r11 = *(u32 *)(0x0C10DABC + byte * 4), and the aim_frame
 * builders read their endpoints/ratios from the record r11 names.  The table
 * and its five records are 1ST_READ constants.
 *
 * Three legs:
 *   - the embedded table against the image bytes (0x0C10D940 + 0x4C * kind);
 *   - the selector's bounds (0..4 served, 5..255 refused);
 *   - the oracle leg: the four retained 0x8C09EAF2 specimens' exit shadows
 *     carry the first aim_frame's saved r11, which is the table pointer; it
 *     must be record 0 (the byte the specimens ran with), and record 0's
 *     translation is the measured row-2 offset (.28, 0, .12).
 *
 * The oracle leg is skipped (not failed) when the corpus is absent.
 */
#include "motion_pose.h"

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int ok = 1;

static void check(int condition, const char *name)
{
    if (!condition) {
        fprintf(stderr, "native_motion_aim: %s failed\n", name);
        ok = 0;
    } else {
        printf("  %s: pass\n", name);
    }
}

#define IMAGE_BASE 0x0C010000u
#define AIM_TABLE  0x0C10DABCu
#define AIM_REC0   0x0C10D940u
#define AIM_STRIDE 0x4Cu

/* ---- image leg ---- */

static int image_records(const char *path, float out[5][12], uint32_t ptrs[5])
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
    for (int k = 0; k < 5; ++k) {
        uint32_t off = AIM_TABLE - IMAGE_BASE + (uint32_t)k * 4u;
        uint32_t p;
        memcpy(&p, img + off, 4);
        ptrs[k] = p;
        uint32_t ro = p - IMAGE_BASE;
        if (ro + 48u > (uint32_t)size) {
            free(img);
            return 0;
        }
        memcpy(out[k], img + ro, 48u);
    }
    free(img);
    return 1;
}

/* ---- oracle corpus leg (minimal .cases reader) ---- */

#define MAXW 64
typedef struct { uint32_t base, len; uint8_t *data; } aim_win;

static uint32_t hexword(const char *s) { return (uint32_t)strtoul(s, NULL, 16); }

static int parse_case(char *line, uint32_t in[37], char *entry, int *nw,
                      aim_win w[MAXW], char *xexit, int *nx, aim_win x[MAXW])
{
    char *tok = strtok(line, " \t\r\n");
    for (int i = 0; i < 37 && tok; ++i) { in[i] = hexword(tok); tok = strtok(NULL, " \t\r\n"); }
    if (!tok) return 0;
    for (int i = 0; i < 37 && tok; ++i) { tok = strtok(NULL, " \t\r\n"); }  /* out regs */
    if (!tok) return 0;
    snprintf(entry, 256, "%s", tok);
    tok = strtok(NULL, " \t\r\n");
    *nw = tok ? atoi(tok) : 0;
    if (*nw < 0 || *nw > MAXW) return 0;
    for (int i = 0; i < *nw; ++i) {
        tok = strtok(NULL, " \t\r\n"); if (!tok) return 0;
        w[i].base = hexword(tok);
        tok = strtok(NULL, " \t\r\n"); if (!tok) return 0;
        w[i].len = hexword(tok);
        w[i].data = NULL;
    }
    tok = strtok(NULL, " \t\r\n"); if (!tok) return 0;
    snprintf(xexit, 256, "%s", tok);
    tok = strtok(NULL, " \t\r\n");
    *nx = tok ? atoi(tok) : 0;
    if (*nx < 0 || *nx > MAXW) return 0;
    for (int i = 0; i < *nx; ++i) {
        tok = strtok(NULL, " \t\r\n"); if (!tok) return 0;
        x[i].base = hexword(tok);
        tok = strtok(NULL, " \t\r\n"); if (!tok) return 0;
        x[i].len = hexword(tok);
        x[i].data = NULL;
    }
    return 1;
}

static int load_windows(const char *dir, const char *name, aim_win *w, int n)
{
    char path[1400];
    snprintf(path, sizeof path, "%s/%s", dir, name);
    FILE *f = fopen(path, "rb");
    if (!f) return 0;
    for (int i = 0; i < n; ++i) {
        w[i].data = (uint8_t *)malloc(w[i].len ? w[i].len : 1);
        if (!w[i].data || fread(w[i].data, 1, w[i].len, f) != w[i].len) {
            fclose(f);
            return 0;
        }
    }
    fclose(f);
    return 1;
}

static void free_windows(aim_win *w, int n)
{
    for (int i = 0; i < n; ++i) free(w[i].data);
}

static int read_u32(const aim_win *w, int n, uint32_t addr, uint32_t *out)
{
    for (int i = 0; i < n; ++i)
        if (w[i].base <= addr && addr + 4u <= w[i].base + w[i].len) {
            memcpy(out, w[i].data + (addr - w[i].base), 4);
            return 1;
        }
    return 0;
}

/* The orchestration's frame: the prologue leaves r15 = sp0 - 236; the first
 * aim_frame is called after a 64-byte matrix_push and six argument pushes, so
 * its entry sp is body - 88 and its saved r11 sits at body - 104. */
static uint32_t first_aim_saved_r11(uint32_t sp0) { return sp0 - 236u - 104u; }

int main(int argc, char **argv)
{
    static const char image[] = "extract/exe/1ST_READ.unsc.bin";
    static const char corpus[] =
        "extract/analysis/native_pose_orchestration_s29_v1/f_8c09eaf2.cases";
    const char *image_path = argc > 1 ? argv[1] : image;
    const char *corpus_path = argc > 2 ? argv[2] : corpus;

    float img[5][12];
    uint32_t ptrs[5];
    if (!image_records(image_path, img, ptrs)) {
        printf("  image leg: skipped (cannot read %s)\n", image_path);
    } else {
        int same = 1, bounds = 1;
        for (int k = 0; k < 5; ++k) {
            float got[12];
            char name[64];
            snprintf(name, sizeof name, "record %d served", k);
            if (vf3_native_motion_aim_record((uint8_t)k, got) != 0) {
                check(0, name);
                same = 0;
                continue;
            }
            check(1, name);
            for (int i = 0; i < 12; ++i) {
                if (got[i] != img[k][i])
                    same = 0;
            }
        }
        check(same, "embedded table == image records");
        for (int k = 5; k < 256; k += 37) {
            float got[12];
            if (vf3_native_motion_aim_record((uint8_t)k, got) == 0)
                bounds = 0;
        }
        check(bounds, "selector refuses kinds outside 0..4");
        check(ptrs[0] == AIM_REC0, "record 0 pointer is 0x0C10D940");
    }

    {
        float rec[12];
        if (vf3_native_motion_aim_record(0, rec) == 0) {
            char name[96];
            snprintf(name, sizeof name, "record 0 translation is (.28, 0, .12)");
            check(fabsf(rec[1] - 0.28f) < 1e-6f && fabsf(rec[2] - 0.12f) < 1e-6f,
                  name);
        }
    }

    FILE *f = fopen(corpus_path, "r");
    if (!f) {
        printf("  oracle leg: skipped (cannot read %s)\n", corpus_path);
        printf("native_motion_aim: %s\n", ok ? "PASS" : "FAIL");
        return ok ? 0 : 1;
    }
    {
        char dir[1400];
        snprintf(dir, sizeof dir, "%s", corpus_path);
        char *slash = strrchr(dir, '/');
        if (!slash) slash = strrchr(dir, '\\');
        if (slash) *slash = '\0';
        else snprintf(dir, sizeof dir, ".");

        char line[65536];
        int cases = 0, matched = 0;
        while (fgets(line, sizeof line, f)) {
            uint32_t in[37];
            char entry[256], xexit[256];
            int nw, nx;
            aim_win w[MAXW], x[MAXW];
            if (!parse_case(line, in, entry, &nw, w, xexit, &nx, x))
                continue;
            cases++;
            if (!load_windows(dir, xexit, x, nx))
                continue;
            uint32_t r11 = 0;
            if (read_u32(x, nx, first_aim_saved_r11(in[15]), &r11)) {
                if (r11 == ptrs[0])
                    matched++;
                else
                    fprintf(stderr, "  case %d: first aim_frame saved r11=%08x "
                                    "(want %08x)\n", cases - 1, r11, ptrs[0]);
            }
            free_windows(x, nx);
        }
        fclose(f);
        if (cases == 0) {
            printf("  oracle leg: skipped (no cases parsed)\n");
        } else {
            char name[96];
            snprintf(name, sizeof name,
                     "oracle leg: %d/%d specimens select aim record 0", matched, cases);
            check(cases > 0 && matched == cases, name);
        }
    }

    printf("native_motion_aim: %s\n", ok ? "PASS" : "FAIL");
    return ok ? 0 : 1;
}
