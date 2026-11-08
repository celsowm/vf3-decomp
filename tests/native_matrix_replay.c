/* Native matrix primitives (src/native/matrix.c) against values computed
 * in the test from the 65536-units-per-turn convention and the guest's
 * column-major, post-multiply composition order:
 *
 *   rotate_y: column0 (cos,0,-sin), column2 (sin,0,cos)
 *   rotate_z: column0 (cos,sin,0), column1 (-sin,cos,0)
 *   rotate_x: column1 (0,cos,sin), column2 (0,-sin,cos)
 *
 * Expected matrices are built in the test with its own sinf/cosf and the
 * public vf3_native_matrix_multiply (which is itself pinned by the
 * identity/translation cases below), not by calling the private rotation
 * helpers.
 */
#include "matrix.h"

#include <math.h>
#include <stdio.h>
#include <string.h>

static int ok = 1;
static unsigned cases;

static void check_mat(const char *name, const float got[16],
                      const float want[16])
{
    ++cases;
    for (unsigned i = 0; i < 16; ++i) {
        if (fabsf(got[i] - want[i]) > 1e-5f) {
            fprintf(stderr, "native_matrix: %s [%u]: got %g want %g\n",
                    name, i, (double)got[i], (double)want[i]);
            ok = 0;
            return;
        }
    }
    printf("  %s: pass\n", name);
}

static void check(int condition, const char *name)
{
    ++cases;
    if (!condition) {
        fprintf(stderr, "native_matrix: %s failed\n", name);
        ok = 0;
    } else {
        printf("  %s: pass\n", name);
    }
}

static void ident(float out[16])
{
    memset(out, 0, 16u * sizeof *out);
    out[0] = out[5] = out[10] = out[15] = 1.0f;
}

static void rot_y(float sine, float cosine, float out[16])
{
    ident(out);
    out[0] = cosine; out[2] = -sine; out[8] = sine; out[10] = cosine;
}

static void rot_z(float sine, float cosine, float out[16])
{
    ident(out);
    out[0] = cosine; out[1] = sine; out[4] = -sine; out[5] = cosine;
}

static void rot_x(float sine, float cosine, float out[16])
{
    ident(out);
    out[5] = cosine; out[6] = sine; out[9] = -sine; out[10] = cosine;
}

static void compose4(const float a[16], const float b[16],
                     const float c[16], const float d[16], float out[16])
{
    float ab[16], abc[16];
    vf3_native_matrix_multiply(a, b, ab);
    vf3_native_matrix_multiply(ab, c, abc);
    vf3_native_matrix_multiply(abc, d, out);
}

static void angle_sincos(uint16_t angle, float *sine, float *cosine)
{
    const double radians = (double)angle * (3.14159265358979323846 / 32768.0);
    *sine = (float)sin(radians);
    *cosine = (float)cos(radians);
}

int main(void)
{
    float m[16], want[16], tmp[16];

    /* identity and multiply */
    vf3_native_matrix_identity(m);
    ident(want);
    check_mat("identity", m, want);

    {
        float t[16], p[16], point[3] = { 1.0f, 2.0f, 3.0f }, out[3];
        ident(t);
        t[12] = 10.0f; t[13] = 20.0f; t[14] = 30.0f;
        vf3_native_matrix_multiply(t, t, p);       /* T * T */
        check(fabsf(p[12] - 20.0f) < 1e-6f && fabsf(p[13] - 40.0f) < 1e-6f &&
                  fabsf(p[14] - 60.0f) < 1e-6f,
              "multiply translations add");
        vf3_native_matrix_transform_point(t, point, out);
        check(fabsf(out[0] - 11.0f) < 1e-6f && fabsf(out[1] - 22.0f) < 1e-6f &&
                  fabsf(out[2] - 33.0f) < 1e-6f,
              "transform_point adds translation");
        /* translate_local: T(10,20,30) then local (+1,0,0) */
        {
            float shifted[16];
            const float off[3] = { 1.0f, 0.0f, 0.0f };
            vf3_native_matrix_translate_local(t, off, shifted);
            check(fabsf(shifted[12] - 11.0f) < 1e-6f &&
                      fabsf(shifted[13] - 20.0f) < 1e-6f,
                  "translate_local");
        }
        /* scale_axes: scale x by 2 -> column 0 doubles */
        {
            float scaled[16];
            vf3_native_matrix_scale_axes(t, 2.0f, 1.0f, 1.0f, scaled);
            check(fabsf(scaled[0] - 2.0f) < 1e-6f &&
                      fabsf(scaled[5] - 1.0f) < 1e-6f,
                  "scale_axes");
        }
    }

    /* euler z-y-x: zero is identity, single axes are the rotations */
    check(vf3_native_matrix_euler_z_y_x(0, 0, 0, m) == 0, "euler zero");
    ident(want);
    check_mat("euler zero = identity", m, want);
    {
        float s, c, r[16];
        angle_sincos(16384, &s, &c);               /* quarter turn */
        check(vf3_native_matrix_euler_z_y_x(16384, 0, 0, m) == 0, "euler z");
        rot_z(s, c, r);
        check_mat("euler z quarter = Rz", m, r);
        check(vf3_native_matrix_euler_z_y_x(0, 16384, 0, m) == 0, "euler y");
        rot_y(s, c, r);
        check_mat("euler y quarter = Ry", m, r);
        check(vf3_native_matrix_euler_z_y_x(0, 0, 16384, m) == 0, "euler x");
        rot_x(s, c, r);
        check_mat("euler x quarter = Rx", m, r);
        /* combined: Rz * Ry * Rx */
        {
            float rz[16], ry[16], rx[16], zy[16];
            float sz, cz, sy, cy, sx, cx;
            angle_sincos(8192, &sz, &cz);
            angle_sincos(16384, &sy, &cy);
            angle_sincos(24576, &sx, &cx);
            rot_z(sz, cz, rz);
            rot_y(sy, cy, ry);
            rot_x(sx, cx, rx);
            vf3_native_matrix_multiply(rz, ry, zy);
            vf3_native_matrix_multiply(zy, rx, want);
            check(vf3_native_matrix_euler_z_y_x(8192, 16384, 24576, m) == 0,
                  "euler combined");
            check_mat("euler combined = Rz*Ry*Rx", m, want);
        }
    }
    check(vf3_native_matrix_euler_z_y_x(0, 0, 0, NULL) == -1,
          "euler null rejected");

    /* pose_angles: owner Y, then Z, Y, X(owner_x + input_x), translation
     * preserved */
    {
        float base[16];
        ident(base);
        base[12] = 1.0f; base[13] = 2.0f; base[14] = 3.0f;
        uint16_t angles[3] = { 0, 0, 0 };
        check(vf3_native_matrix_pose_angles(base, 0, 0, angles, m) == 0,
              "pose_angles zero");
        check_mat("pose_angles zero keeps translation", m, base);

        uint16_t quarter[3] = { 16384, 0, 0 };
        check(vf3_native_matrix_pose_angles(base, 0, 0, quarter, m) == 0,
              "pose_angles z");
        {
            float s, c, r[16];
            float kept[16];
            angle_sincos(16384, &s, &c);
            rot_z(s, c, r);
            memcpy(kept, r, sizeof kept);
            kept[12] = 1.0f; kept[13] = 2.0f; kept[14] = 3.0f;
            check_mat("pose_angles Rz with translation", m, kept);
        }
        check(vf3_native_matrix_pose_angles(base, 0, 0, NULL, m) == -1,
              "pose_angles null angles rejected");
        check(vf3_native_matrix_pose_angles(NULL, 0, 0, angles, m) == -1,
              "pose_angles null base rejected");
    }

    /* root_orientation: identity, Ry(yaw), Rz(f0), Ry(f1), Rx(f2) */
    {
        uint16_t zero[3] = { 0, 0, 0 };
        check(vf3_native_root_orientation(0, zero, m) == 0, "root zero");
        ident(want);
        check_mat("root zero = identity", m, want);

        uint16_t fields[3] = { 0, 0, 0 };
        check(vf3_native_root_orientation(16384, fields, m) == 0,
              "root yaw quarter");
        {
            float s, c, r[16];
            angle_sincos(16384, &s, &c);
            rot_y(s, c, r);
            check_mat("root yaw quarter = Ry", m, r);
        }

        /* mixed angles against the hand composition */
        {
            uint16_t mixed[3] = { 8192, 16384, 4096 };
            float sy, cy, sz, cz, s1, c1, sx, cx;
            float ry1[16], rz[16], ry2[16], rx[16];
            angle_sincos(27577, &sy, &cy);
            angle_sincos(8192, &sz, &cz);
            angle_sincos(16384, &s1, &c1);
            angle_sincos(4096, &sx, &cx);
            rot_y(sy, cy, ry1);
            rot_z(sz, cz, rz);
            rot_y(s1, c1, ry2);
            rot_x(sx, cx, rx);
            compose4(ry1, rz, ry2, rx, want);
            check(vf3_native_root_orientation(27577, mixed, m) == 0,
                  "root mixed");
            check_mat("root mixed = Ry*Rz*Ry*Rx", m, want);
        }
        check(vf3_native_root_orientation(0, NULL, m) == -1,
              "root null fields rejected");
        check(vf3_native_root_orientation(0, fields, NULL) == -1,
              "root null out rejected");
        /* the same mixed angles against the guest's own FSCA table
         * (src/fight/sh4_sine.inc, post-multiply Ry*Rz*Ry*Rx): the native
         * libm path must land within 1e-6 of the guest table */
        {
            static const float guest[16] = {
                -0.477389038f, 0.0f, 0.878692031f, 0.0f,
                0.336260863f, 0.923879492f, 0.182688865f, 0.0f,
                -0.811805547f, 0.38268341f, -0.441049942f, 0.0f,
                0.0f, 0.0f, 0.0f, 1.0f
            };
            uint16_t mixed[3] = { 8192, 16384, 4096 };
            check(vf3_native_root_orientation(27577, mixed, m) == 0,
                  "root mixed guest table");
            for (unsigned i = 0; i < 16; ++i) {
                ++cases;
                if (fabsf(m[i] - guest[i]) > 1e-6f) {
                    fprintf(stderr,
                            "native_matrix: root guest-table [%u]: got %g "
                            "want %g\n", i, (double)m[i], (double)guest[i]);
                    ok = 0;
                    break;
                }
            }
            printf("  root mixed = guest FSCA table: pass\n");
        }
    }

    /* unit_triple */
    {
        float base[16], out[16], xz, inv;
        ident(base);
        const float zero_triple[3] = { 0.0f, 0.0f, 0.0f };
        check(vf3_native_matrix_unit_triple(base, zero_triple, out, &xz, &inv)
                  == 0,
              "unit_triple zero");
        check(xz == 0.0f && inv == 0.0f, "unit_triple zero lengths");
        const float triple[3] = { 1.0f, 0.0f, 0.0f };
        check(vf3_native_matrix_unit_triple(base, triple, out, &xz, &inv)
                  == 0,
              "unit_triple x");
        check(fabsf(xz - 1.0f) < 1e-6f && fabsf(inv - 1.0f) < 1e-6f,
              "unit_triple x lengths");
        const float triple_z[3] = { 0.0f, 0.0f, 1.0f };
        check(vf3_native_matrix_unit_triple(base, triple_z, out, &xz, &inv)
                  == 0,
              "unit_triple z");
        check(xz == 0.0f && fabsf(inv - 1.0f) < 1e-6f,
              "unit_triple z lengths");
        check(vf3_native_matrix_unit_triple(base, triple, out, NULL, &inv)
                  == -1,
              "unit_triple null rejected");
        (void)tmp;
    }

    if (!ok) return 1;
    printf("native_matrix: %u cases - PASS\n", cases);
    return 0;
}
