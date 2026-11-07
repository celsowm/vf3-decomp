/* Compare the asset-slice native evaluator with the retained readable VM port. */
#include "motion.h"
#include "../src/fight/mt_play.h"

#include <stdio.h>
#include <string.h>

#define RAM_BASE 0x8c600000u
static uint8_t ram_blob[12 + 63 + 2 + 2 + 9 * 4 + 64];

static void write_u32le(uint8_t *p, uint32_t value)
{
    p[0] = (uint8_t)value;
    p[1] = (uint8_t)(value >> 8);
    p[2] = (uint8_t)(value >> 16);
    p[3] = (uint8_t)(value >> 24);
}

static void write_float(uint8_t *p, float value)
{
    uint32_t bits;
    memcpy(&bits, &value, sizeof bits);
    write_u32le(p, bits);
}

static void wire_fixture(void)
{
    uint8_t *ops = ram_blob + 12;
    uint8_t *counts = ram_blob + 76;
    uint8_t *times = ram_blob + 78;
    uint8_t *tuples = ram_blob + 80;
    memset(ram_blob, 0, sizeof ram_blob);
    ops[0] = 1;
    ops[2] = 2;
    ops[3] = 3;
    counts[0] = counts[1] = 1;
    times[0] = times[1] = 4;
    write_float(tuples + 0, 7.5f);
    write_float(tuples + 4, 2.0f);
    write_float(tuples + 8, 6.0f);
    write_float(tuples + 12, 9.0f);
    write_float(tuples + 16, 1.0f);
    write_float(tuples + 20, 256.0f);
    write_float(tuples + 24, 512.0f);
    write_float(tuples + 28, 9.0f);
    write_float(tuples + 32, 0.0f);
    write_float(tuples + 36, 0.0f);
    write_u32le(ram_blob + 0, RAM_BASE + 76u);
    write_u32le(ram_blob + 4, RAM_BASE + 78u);
    write_u32le(ram_blob + 8, RAM_BASE + 80u);
}

static int compare_case(const char *name, uint16_t cycle, int32_t phase)
{
    vf3_native_motion_stream stream;
    VF3MtTask guest;
    float native_values[VF3_NATIVE_MOTION_CHANNELS];
    float guest_values[VF3_NATIVE_MOTION_CHANNELS];
    float *guest_cursor = guest_values;
    memset(&stream, 0, sizeof stream);
    stream.cycle = cycle;
    stream.ops = ram_blob + 12;
    stream.ops_size = VF3_NATIVE_MOTION_CHANNELS;
    stream.counts = ram_blob + 76;
    stream.counts_size = 2;
    stream.times = ram_blob + 78;
    stream.times_size = 2;
    stream.tuples = ram_blob + 80;
    stream.tuples_size = sizeof ram_blob - 80;
    guest.hdr = ram_blob;
    guest.cycle = cycle;
    guest.ram = ram_blob;
    guest.ram_base = RAM_BASE;
    if (vf3_native_motion_eval(&stream, phase, native_values) != 0 ||
        vf3_mt_eval_frame(&guest, phase, &guest_cursor) != 0 ||
        guest_cursor != guest_values + VF3_NATIVE_MOTION_CHANNELS ||
        memcmp(native_values, guest_values, sizeof native_values) != 0) {
        fprintf(stderr, "native_motion_replay: %s differs from MT port\n", name);
        for (size_t i = 0; i < VF3_NATIVE_MOTION_CHANNELS; ++i) {
            if (memcmp(&native_values[i], &guest_values[i], sizeof(float)) != 0)
                fprintf(stderr, "  channel %zu: native=%g guest=%g\n",
                        i, native_values[i], guest_values[i]);
        }
        return 0;
    }
    printf("  %s: pass\n", name);
    return 1;
}

int main(void)
{
    vf3_native_motion_stream bad;
    float output[VF3_NATIVE_MOTION_CHANNELS];
    int ok = 1;

    wire_fixture();
    ok &= compare_case("mid-key", 0, 0x200);
    wire_fixture();
    ok &= compare_case("exact-key", 0, 0x400);
    wire_fixture();
    ok &= compare_case("cycle-wrap", 8, 0x600);
    wire_fixture();
    ram_blob[76] = 0;
    ram_blob[12 + 3] = 0;
    ok &= compare_case("zero-key-cycle", 8, 0x200);

    wire_fixture();
    memset(&bad, 0, sizeof bad);
    bad.ops = ram_blob + 12;
    bad.ops_size = 62;
    if (vf3_native_motion_eval(&bad, 0, output) != -1) {
        fputs("native_motion_replay: accepted short opcode table\n", stderr);
        ok = 0;
    }
    bad.ops_size = 63;
    bad.counts = ram_blob + 76;
    bad.counts_size = 2;
    bad.times = ram_blob + 78;
    bad.times_size = 0;
    bad.tuples = ram_blob + 80;
    bad.tuples_size = sizeof ram_blob - 80;
    if (vf3_native_motion_eval(&bad, 0x200, output) != -2) {
        fputs("native_motion_replay: accepted truncated key-time stream\n", stderr);
        ok = 0;
    }

    wire_fixture();
    ram_blob[12] = 0;
    ram_blob[13] = 0;
    ram_blob[14] = 1;
    write_u32le(ram_blob + 80, 0x7fc12345u);
    ok &= compare_case("NaN-payload-sign-flip", 0, 0x200);

    if (!ok) return 1;
    puts("native_motion_replay: PASS");
    return 0;
}
