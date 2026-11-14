/* Replay the recovered native row 0 (src/native/motion_pose.c) two ways:
 *
 *   - a differential against an independent re-statement of the guest chain
 *     (root orientation, seven-pass translation, halfword frame, unit triple)
 *     over synthetic actor inputs;
 *   - the oracle leg: the four retained 0x8C09EAF2 specimens in
 *     extract/analysis/native_pose_orchestration_s29_v1, whose exit shadow
 *     carries the row the guest actually wrote.
 *
 * The oracle leg is skipped (not failed) when the corpus is absent. */
#include "motion_pose.h"
#include "motion_vectors.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int ok = 1;

static void check(int condition, const char *name)
{
    if (!condition) {
        fprintf(stderr, "native_motion_row0: %s failed\n", name);
        ok = 0;
    } else {
        printf("  %s: pass\n", name);
    }
}

/* ---- independent model (column-major, index = column * 4 + row) ---- */

static void model_mul(const float a[16], const float b[16], float out[16])
{
    float t[16];
    for (int c = 0; c < 4; ++c)
        for (int r = 0; r < 4; ++r) {
            float s = 0.0f;
            for (int k = 0; k < 4; ++k)
                s += a[k * 4 + r] * b[c * 4 + k];
            t[c * 4 + r] = s;
        }
    memcpy(out, t, sizeof t);
}

static void model_rot_y(float rad, float out[16])
{
    const float s = sinf(rad), c = cosf(rad);
    const float m[16] = { c, 0, -s, 0, 0, 1, 0, 0, s, 0, c, 0, 0, 0, 0, 1 };
    memcpy(out, m, sizeof m);
}

static void model_rot_z(float rad, float out[16])
{
    const float s = sinf(rad), c = cosf(rad);
    const float m[16] = { c, s, 0, 0, -s, c, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
    memcpy(out, m, sizeof m);
}

static void model_rot_x(float rad, float out[16])
{
    const float s = sinf(rad), c = cosf(rad);
    const float m[16] = { 1, 0, 0, 0, 0, c, s, 0, 0, -s, c, 0, 0, 0, 0, 1 };
    memcpy(out, m, sizeof m);
}

static float model_turn(uint16_t v)
{
    return (float)((double)v * (3.14159265358979323846 / 32768.0));
}

/* The row-0 chain, written from the disassembly.  points[0]/points[1] are
 * the seven-pass outputs. */
static void model_row0(const int16_t fields[VF3_NATIVE_POSE_FIELDS],
                       const vf3_native_motion_actor *actor,
                       const float points[7][3], float out[16])
{
    static const float identity[16] =
        { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
    const uint16_t f[3] = { (uint16_t)fields[0], (uint16_t)fields[1],
                            (uint16_t)fields[2] };
    const float *t = points[0];
    const float src[3] = { points[1][0] + actor->offset[0],
                           points[1][1] + actor->offset[1],
                           points[1][2] + actor->offset[2] };
    float root[16], rz[16], ry[16], rx[16], hw[16], half[16], d[3];

    model_mul(identity, identity, root);
    model_rot_y(model_turn((uint16_t)actor->yaw), rz);
    model_mul(root, rz, root);
    model_rot_z(model_turn(f[0]), rz);
    model_mul(root, rz, root);
    model_rot_y(model_turn(f[1]), ry);
    model_mul(root, ry, root);
    model_rot_x(model_turn(f[2]), rx);
    model_mul(root, rx, root);
    root[12] = t[0];
    root[13] = t[1];
    root[14] = t[2];

    model_rot_z(model_turn((uint16_t)fields[3]), rz);
    model_rot_y(model_turn((uint16_t)((uint32_t)actor->arg +
                                      (uint32_t)(uint16_t)fields[4])), ry);
    model_rot_x(model_turn((uint16_t)fields[5]), rx);
    model_mul(rz, ry, hw);
    model_mul(hw, rx, hw);
    model_mul(root, hw, half);

    for (int i = 0; i < 3; ++i)
        d[i] = half[i * 4 + 0] * (src[0] - t[0]) +
               half[i * 4 + 1] * (src[1] - t[1]) +
               half[i * 4 + 2] * (src[2] - t[2]);

    /* unit_triple: heading then pitch, both from an inverse square root. */
    {
        const float a = d[0], b = d[1], c = d[2];
        const float n = b * b + a * a;
        const float m = n + c * c;
        const float inv_n = n < 1.0e-7f ? 0.0f : 1.0f / sqrtf(n);
        const float inv_m = m < 1.0e-7f ? 0.0f : 1.0f / sqrtf(m);
        const float hs = inv_n * b, hc = inv_n * a;
        const float ps = -(inv_m * c);
        const float pc = (m < 1.0e-7f ? 0.0f : sqrtf(n) * inv_m);
        float heading[16], pitch[16], headed[16];
        model_rot_z(atan2f(hs, hc), heading);
        model_rot_y(atan2f(ps, pc), pitch);
        model_mul(half, heading, headed);
        model_mul(headed, pitch, out);
    }
}

static int close_matrix(const float a[16], const float b[16], float tol)
{
    for (int i = 0; i < 16; ++i)
        if (!isfinite(a[i]) || !isfinite(b[i]) || fabsf(a[i] - b[i]) > tol)
            return 0;
    return 1;
}

/* ---- synthetic differential ---- */

static const vf3_native_motion_actor base_actor = {
    49472u,                                   /* yaw */
    { -4.31287f, 9.96498f, -3.22019f },       /* position */
    7,                                        /* mode */
    0x00040000u,                              /* flags */
    0x00021000u,                              /* pose flags */
    0x00000800u,                              /* global flags */
    0,                                        /* arg */
    { 0.0f, 0.0f, 0.0f }                      /* offset */
};

static void synthetic_case(const char *name, int16_t fields[42],
                           const vf3_native_motion_actor *actor,
                           const float channels[21])
{
    float points[7][3], world[16], got[16], want[16];
    uint8_t mask = vf3_native_motion_zero_y_mask(actor->flags,
                                                 actor->pose_flags,
                                                 actor->global_flags);
    int use_origin = (actor->flags & 0x20000000u) != 0;
    if (vf3_native_motion_actor_transform(actor->yaw, actor->position,
                                          actor->mode, actor->flags,
                                          world) != 0 ||
        vf3_native_motion_points(channels, use_origin, mask, world,
                                 points) != 0) {
        check(0, name);
        return;
    }
    model_row0(fields, actor, points, want);
    if (vf3_native_motion_row0(fields, actor, channels, got) != 0) {
        check(0, name);
        return;
    }
    char label[96];
    snprintf(label, sizeof label, "%s native == model", name);
    check(close_matrix(got, want, 2.0e-5f), label);
}

/* ---- oracle corpus ---- */

#define MAXW 64
typedef struct { uint32_t base, len; uint8_t *data; } row0_win;
typedef struct {
    uint32_t in[37], out[37];
    char entry[256], xexit[256];
    int nw, nx;
    row0_win w[MAXW], x[MAXW];
} row0_case;

static uint32_t row0_hex(const char *s) { return (uint32_t)strtoul(s, NULL, 16); }

static int row0_parse(const char *path, row0_case **out, int *count)
{
    FILE *f = fopen(path, "r");
    char line[65536];
    row0_case *cases = NULL;
    int n = 0, cap = 0;
    if (!f)
        return 0;
    while (fgets(line, sizeof line, f)) {
        char *tok = strtok(line, " \t\r\n");
        int i;
        row0_case c;
        memset(&c, 0, sizeof c);
        for (i = 0; i < 37 && tok; ++i) { c.in[i] = row0_hex(tok); tok = strtok(NULL, " \t\r\n"); }
        if (i != 37 || !tok) continue;
        for (i = 0; i < 37 && tok; ++i) { c.out[i] = row0_hex(tok); tok = strtok(NULL, " \t\r\n"); }
        if (i != 37 || !tok) continue;
        snprintf(c.entry, sizeof c.entry, "%s", tok);
        tok = strtok(NULL, " \t\r\n");
        c.nw = tok ? atoi(tok) : 0;
        if (c.nw < 0 || c.nw > MAXW) continue;
        for (i = 0; i < c.nw; ++i) {
            tok = strtok(NULL, " \t\r\n"); if (!tok) break;
            c.w[i].base = row0_hex(tok);
            tok = strtok(NULL, " \t\r\n"); if (!tok) break;
            c.w[i].len = row0_hex(tok);
        }
        if (i != c.nw || !tok) continue;
        tok = strtok(NULL, " \t\r\n");
        if (!tok) continue;
        snprintf(c.xexit, sizeof c.xexit, "%s", tok);
        tok = strtok(NULL, " \t\r\n");
        c.nx = tok ? atoi(tok) : 0;
        if (c.nx < 0 || c.nx > MAXW) continue;
        for (i = 0; i < c.nx; ++i) {
            tok = strtok(NULL, " \t\r\n"); if (!tok) break;
            c.x[i].base = row0_hex(tok);
            tok = strtok(NULL, " \t\r\n"); if (!tok) break;
            c.x[i].len = row0_hex(tok);
        }
        if (i != c.nx) continue;
        if (n == cap) {
            cap = cap ? cap * 2 : 8;
            cases = (row0_case *)realloc(cases, (size_t)cap * sizeof *cases);
        }
        cases[n++] = c;
    }
    fclose(f);
    *out = cases;
    *count = n;
    return n > 0;
}

static int row0_load_blob(const char *dir, const char *name, row0_win *w,
                          int n)
{
    char path[1400];
    snprintf(path, sizeof path, "%s/%s", dir, name);
    FILE *f = fopen(path, "rb");
    if (!f)
        return 0;
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

static void row0_free(row0_case *c)
{
    for (int i = 0; i < c->nw; ++i) free(c->w[i].data);
    for (int i = 0; i < c->nx; ++i) free(c->x[i].data);
}

/* A window-searching float read (the window that contains addr). */
static int row0_read_float(const row0_win *w, int n, uint32_t addr, float *out)
{
    for (int i = 0; i < n; ++i)
        if (w[i].base <= addr && addr + 4u <= w[i].base + w[i].len) {
            memcpy(out, w[i].data + (addr - w[i].base), 4);
            return 1;
        }
    return 0;
}

static int row0_read_u16(const row0_win *w, int n, uint32_t addr, uint16_t *out)
{
    for (int i = 0; i < n; ++i)
        if (w[i].base <= addr && addr + 2u <= w[i].base + w[i].len) {
            memcpy(out, w[i].data + (addr - w[i].base), 2);
            return 1;
        }
    return 0;
}

static int row0_read_u32(const row0_win *w, int n, uint32_t addr, uint32_t *out)
{
    for (int i = 0; i < n; ++i)
        if (w[i].base <= addr && addr + 4u <= w[i].base + w[i].len) {
            memcpy(out, w[i].data + (addr - w[i].base), 4);
            return 1;
        }
    return 0;
}

static int oracle_leg(const char *path)
{
    row0_case *cases = NULL;
    int count = 0, passed = 0;
    char dir[1400];
    snprintf(dir, sizeof dir, "%s", path);
    char *slash = strrchr(dir, '/');
    if (!slash) slash = strrchr(dir, '\\');
    if (slash) *slash = '\0';
    else snprintf(dir, sizeof dir, ".");
    if (!row0_parse(path, &cases, &count)) {
        printf("  oracle corpus absent: %s (skipped)\n", path);
        return 1;
    }
    for (int ci = 0; ci < count; ++ci) {
        row0_case *c = &cases[ci];
        uint32_t actor;
        int16_t fields[VF3_NATIVE_POSE_FIELDS] = { 0 };
        vf3_native_motion_actor actor_state;
        float channels[21], got[16], want[16], model[16];
        int have = 1;
        if (!row0_load_blob(dir, c->entry, c->w, c->nw) ||
            !row0_load_blob(dir, c->xexit, c->x, c->nx)) {
            printf("  case %d: blobs unreadable (skipped) dir=%s entry=%s nw=%d xexit=%s nx=%d\n",
                   ci, dir, c->entry, c->nw, c->xexit, c->nx);
            row0_free(c);
            continue;
        }
        actor = c->in[14];
        memset(&actor_state, 0, sizeof actor_state);
        {
            uint16_t hw;
            if (row0_read_u16(c->w, c->nw, actor + 0x1E, &hw))
                actor_state.yaw = hw;
            for (int k = 0; k < 3; ++k) {
                uint16_t f;
                if (row0_read_u16(c->w, c->nw, actor + 0x1F50 + 2u * (uint32_t)k, &f))
                    fields[k] = (int16_t)f;
            }
            for (int k = 0; k < 3; ++k) {
                uint16_t f;
                if (row0_read_u16(c->w, c->nw, actor + 0x1F56 + 2u * (uint32_t)k, &f))
                    fields[3 + k] = (int16_t)f;
            }
            if (row0_read_u16(c->w, c->nw, actor + 0x22E4, &hw))
                actor_state.arg = (int16_t)hw;
            for (int k = 0; k < 3; ++k) {
                float v;
                if (row0_read_float(c->w, c->nw, actor + 0x10 + 4u * (uint32_t)k, &v))
                    actor_state.position[k] = v;
                if (row0_read_float(c->w, c->nw, actor + 0x208C + 4u * (uint32_t)k, &v))
                    actor_state.offset[k] = v;
            }
            for (int k = 0; k < 21; ++k) {
                float v;
                if (row0_read_float(c->w, c->nw, actor + 0x1D04 + 4u * (uint32_t)k, &v))
                    channels[k] = v;
            }
            {
                uint32_t u32;
                uint8_t u8;
                if (row0_read_u32(c->w, c->nw, actor + 72, &u32))
                    actor_state.flags = u32;
                if (row0_read_u32(c->w, c->nw, actor + 0x48, &u32))
                    actor_state.pose_flags = u32;
                if (row0_read_u32(c->w, c->nw, 0x0C29BCCCu, &u32))
                    actor_state.global_flags = u32;
                if (row0_read_u16(c->w, c->nw, actor + 97, &hw))
                    u8 = (uint8_t)hw;
                else if (row0_read_u32(c->w, c->nw, actor + 97, &u32))
                    u8 = (uint8_t)u32;
                else
                    u8 = 0;
                actor_state.mode = u8;
            }
        }
        for (int i = 0; i < 16; ++i) {
            float v;
            if (row0_read_float(c->x, c->nx, actor + 0x180 + 4u * (uint32_t)i, &v))
                want[i] = v;
            else
                have = 0;
        }
        if (!have) {
            printf("  case %d: row0 not in exit shadow (skipped)\n", ci);
            row0_free(c);
            continue;
        }
        if (vf3_native_motion_row0(fields, &actor_state, channels, got) != 0) {
            char name[64];
            snprintf(name, sizeof name, "oracle case %d native row0", ci);
            check(0, name);
            row0_free(c);
            continue;
        }
        {
            float points[7][3], world[16];
            uint8_t mask = vf3_native_motion_zero_y_mask(
                actor_state.flags, actor_state.pose_flags,
                actor_state.global_flags);
            int use_origin = (actor_state.flags & 0x20000000u) != 0;
            if (vf3_native_motion_actor_transform(
                    actor_state.yaw, actor_state.position, actor_state.mode,
                    actor_state.flags, world) == 0 &&
                vf3_native_motion_points(channels, use_origin, mask, world,
                                         points) == 0)
                model_row0(fields, &actor_state, points, model);
            else
                memset(model, 0, sizeof model);
        }
        {
            char name[96];
            snprintf(name, sizeof name, "oracle case %d native == guest", ci);
            check(close_matrix(got, want, 2.0e-4f), name);
            snprintf(name, sizeof name, "oracle case %d model == guest", ci);
            check(close_matrix(model, want, 2.0e-4f), name);
        }
        passed++;
        row0_free(c);
    }
    free(cases);
    printf("  oracle leg: %d case(s) replayed\n", passed);
    return ok;
}

int main(int argc, char **argv)
{
    static const char corpus[] =
        "extract/analysis/native_pose_orchestration_s29_v1/f_8c09eaf2.cases";
    const char *path = argc > 1 ? argv[1] : corpus;

    /* Synthetic differential: the native row0 against the independent model
     * over varied actor inputs. */
    {
        int16_t fields[VF3_NATIVE_POSE_FIELDS] = { 0 };
        float channels[21];
        for (int i = 0; i < 21; ++i)
            channels[i] = (float)((i * 37) % 11) * 0.25f - 1.5f;
        synthetic_case("bind fields", fields, &base_actor, channels);

        fields[0] = 4096; fields[1] = 8192; fields[2] = 16384;
        synthetic_case("root fields", fields, &base_actor, channels);

        fields[3] = 21845; fields[4] = 19842; fields[5] = 1024;
        synthetic_case("halfword fields", fields, &base_actor, channels);

        {
            vf3_native_motion_actor arged = base_actor;
            arged.arg = -1000;
            arged.offset[0] = 0.5f;
            arged.offset[1] = -0.25f;
            arged.offset[2] = 1.0f;
            synthetic_case("arg + offsets", fields, &arged, channels);
        }
        {
            vf3_native_motion_actor flip = base_actor;
            flip.yaw = 16703;
            flip.flags = 0x20000000u | 0x00040000u;
            synthetic_case("origin flag", fields, &flip, channels);
        }
        {
            vf3_native_motion_actor tiny = base_actor;
            channels[0] = 1.0e-9f;
            synthetic_case("tiny triple", fields, &tiny, channels);
        }
    }

    /* Argument validation. */
    {
        int16_t fields[VF3_NATIVE_POSE_FIELDS] = { 0 };
        float channels[21] = { 0 }, out[16];
        check(vf3_native_motion_row0(NULL, &base_actor, channels, out) == -1,
              "null fields rejected");
        check(vf3_native_motion_row0(fields, NULL, channels, out) == -1,
              "null actor rejected");
        check(vf3_native_motion_row0(fields, &base_actor, NULL, out) == -1,
              "null channels rejected");
        check(vf3_native_motion_row0(fields, &base_actor, channels, NULL) == -1,
              "null out rejected");
        {
            vf3_native_motion_actor bad = base_actor;
            bad.position[1] = NAN;
            check(vf3_native_motion_row0(fields, &bad, channels, out) == -2,
                  "non-finite position rejected");
        }
        check(vf3_native_motion_pose_actor(NULL, 0, VF3_NATIVE_MOTION_RIG_AKIRA,
                                           &base_actor, NULL) == -1,
              "pose_actor null rejected");
    }

    oracle_leg(path);

    if (!ok) return 1;
    puts("native_motion_row0_replay: PASS");
    return 0;
}
