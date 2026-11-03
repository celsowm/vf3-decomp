/* tests/aica_live_replay.c - the host's live (non-replay) mix path against
 * the reference's audio.
 *
 * The replay tests (tests/aica_mixer_replay.c, tests/aica_native_replay.c)
 * apply the reference's *recorded* ARM7 writes.  This one runs the host's
 * real render loop - vf3_native_aica_mix's else branch, the one a normal
 * runtime takes - with the ARM7 interpreter seeded from the reference
 * savestate's CPU: the machine state (register file, sound RAM, channels)
 * from the mixer fixture, the ARM7 registers/timers/IRQ flags from
 * extract/analysis/aica_arm_seed.bin.  The replay is NOT armed, so the
 * native ARM7 re-executes the same firmware from the same PC.
 *
 *   build/vf3aicalive            (run from the repository root)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fight/native_tick.h"
#include "sys/aica_model.h"
#include "sys/aica_mixer.h"
#include "sys/aica_arm.h"

#define FIXTURE "extract/analysis/aica_mixer_fixture.bin"
#define SEED "extract/analysis/aica_arm_seed.bin"
#define WAV_OUT "build/native_live.wav"

static uint32_t read32(const uint8_t *p)
{
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

static uint8_t *read_file(const char *path, size_t *size)
{
    FILE *f = fopen(path, "rb");
    uint8_t *data;
    long length;
    if (!f) return NULL;
    if (fseek(f, 0, SEEK_END) != 0) { fclose(f); return NULL; }
    length = ftell(f);
    if (length <= 0) { fclose(f); return NULL; }
    rewind(f);
    data = (uint8_t *)malloc((size_t)length);
    if (!data) { fclose(f); return NULL; }
    if (fread(data, 1, (size_t)length, f) != (size_t)length) {
        free(data); fclose(f); return NULL;
    }
    fclose(f);
    *size = (size_t)length;
    return data;
}

int main(void)
{
    uint8_t *data, *seed;
    size_t size = 0, seed_size = 0, offset;
    uint32_t reg_bytes, ram_bytes, channel_bytes, write_count, frames;
    const uint8_t *registers, *ram, *channels, *pcm;
    const uint32_t *writes;
    int16_t *dst;
    unsigned long bad = 0, nz = 0;
    long peak = 0;
    uint32_t i;

    data = read_file(FIXTURE, &size);
    if (!data) {
        fprintf(stderr, "aica_live_replay: %s missing (run from the repo root)\n", FIXTURE);
        return 1;
    }
    seed = read_file(SEED, &seed_size);
    if (!seed) {
        fprintf(stderr, "aica_live_replay: %s missing\n", SEED);
        free(data);
        return 1;
    }
    if (size < 32 || memcmp(data, "VF3MIX1\0", 8) != 0) {
        fprintf(stderr, "aica_live_replay: %s is not the fixture\n", FIXTURE);
        free(data); free(seed);
        return 1;
    }
    reg_bytes = read32(data + 8);
    ram_bytes = read32(data + 12);
    channel_bytes = read32(data + 16);
    write_count = read32(data + 20);
    frames = read32(data + 24);

    offset = 32;
    registers = data + offset; offset += reg_bytes;
    ram = data + offset; offset += ram_bytes;
    channels = data + offset; offset += channel_bytes;
    offset += (size_t)write_count * 20u;
    pcm = data + offset;
    writes = (const uint32_t *)(data + 32 + reg_bytes + ram_bytes + channel_bytes);

    /* Seed the machine state (replay disarmed) and the live ARM7. */
    vf3_native_aica_replay_init(registers, ram, channels, NULL, 0);
    vf3_native_aica_live_seed(seed, (uint32_t)(seed_size / 4u));

    vf3_aica_arm_trace_begin(2000000u);

    dst = (int16_t *)malloc((size_t)frames * 2u * 2u);
    if (!dst) { free(data); free(seed); return 1; }
    vf3_native_aica_mix(dst, frames);

    /* compare the native write stream to the reference's writes */
    {
        const uint64_t *tr = vf3_aica_arm_trace_get();
        uint32_t tr_n = vf3_aica_arm_trace_count();
        uint32_t ri = 0, li = 0, mism = 0;
        const uint32_t *w = writes;
        long first_at = -1, first_samp = -1;
        uint32_t first_ga = 0, first_wa = 0, first_gv = 0, first_wv = 0;
        vf3_aica_arm_trace_end();
        while (ri < tr_n && li < write_count) {
            const uint64_t *rrec = &tr[ri * 5u];
            uint32_t rs = (uint32_t)rrec[0], ra = (uint32_t)rrec[1];
            uint32_t rv = (uint32_t)rrec[2];
            uint32_t lt = w[li * 5u], lk = w[li * 5u + 1u], la = w[li * 5u + 2u];
            uint32_t lv = w[li * 5u + 3u];
            /* reference form -> native form: register writes carry bit 31 */
            uint32_t wa = lk ? la : (0x80000000u | la);
            if (rs < lt) { ++ri; continue; }      /* native write ref has not yet made */
            if (rs > lt) { ++li; continue; }
            if (ra != wa || rv != lv) {
                ++mism;
                if (first_at < 0) {
                    first_at = (long)rs; first_samp = (long)rs;
                    first_ga = ra; first_wa = wa; first_gv = rv; first_wv = lv;
                }
            }
            ++ri; ++li;
        }
        printf("aica_live_replay: native %u vs reference %u writes; %u mismatched "
               "(first at sample %ld: got %08x=%08x want %08x=%08x)\n",
               tr_n, write_count, mism, first_samp, first_ga, first_gv, first_wa, first_wv);
        if (tr_n) {
            FILE *tf = fopen("build/native_trace.bin", "wb");
            if (tf) {
                fwrite(tr, 8, (size_t)tr_n * 5u, tf);
                fclose(tf);
                fprintf(stderr, "aica_live_replay: wrote build/native_trace.bin\n");
            }
        }
    }

    for (i = 0; i < frames; ++i) {
        const int16_t want_right = (int16_t)read32(pcm + i * 4u);
        const int16_t want_left = (int16_t)read32(pcm + i * 4u + 2u);
        const int16_t got_left = dst[2 * i + 0];
        const int16_t got_right = dst[2 * i + 1];
        if (got_left != want_left || got_right != want_right) {
            if (bad < 5)
                fprintf(stderr,
                        "aica_live_replay: frame %u: got (%d, %d), want (%d, %d)\n",
                        i, (int)got_left, (int)got_right, (int)want_left, (int)want_right);
            ++bad;
        }
        if (got_left) ++nz;
        if (got_right) ++nz;
        if (got_left < 0 ? -got_left > peak : got_left > peak) peak = got_left < 0 ? -got_left : got_left;
        if (got_right < 0 ? -got_right > peak : got_right > peak) peak = got_right < 0 ? -got_right : got_right;
    }

    /* write the live output as a WAV, whatever the match */
    {
        FILE *w = fopen(WAV_OUT, "wb");
        if (w) {
            unsigned char hdr[44];
            uint32_t sr = 44100u, datalen = frames * 4u, bps = sr * 4u;
            memset(hdr, 0, sizeof hdr);
            memcpy(hdr, "RIFF", 4);
            hdr[4] = (unsigned char)((36u + datalen) & 0xff);
            hdr[5] = (unsigned char)(((36u + datalen) >> 8) & 0xff);
            hdr[6] = (unsigned char)(((36u + datalen) >> 16) & 0xff);
            hdr[7] = (unsigned char)(((36u + datalen) >> 24) & 0xff);
            memcpy(hdr + 8, "WAVEfmt ", 8);
            hdr[16] = 16; hdr[20] = 1; hdr[22] = 2;
            hdr[24] = (unsigned char)(sr & 0xff); hdr[25] = (unsigned char)((sr >> 8) & 0xff);
            hdr[26] = (unsigned char)((sr >> 16) & 0xff); hdr[27] = (unsigned char)((sr >> 24) & 0xff);
            hdr[28] = (unsigned char)(bps & 0xff); hdr[29] = (unsigned char)((bps >> 8) & 0xff);
            hdr[30] = (unsigned char)((bps >> 16) & 0xff); hdr[31] = (unsigned char)((bps >> 24) & 0xff);
            hdr[32] = 4; hdr[34] = 16;
            memcpy(hdr + 36, "data", 4);
            hdr[40] = (unsigned char)(datalen & 0xff); hdr[41] = (unsigned char)((datalen >> 8) & 0xff);
            hdr[42] = (unsigned char)((datalen >> 16) & 0xff); hdr[43] = (unsigned char)((datalen >> 24) & 0xff);
            fwrite(hdr, 1, sizeof hdr, w);
            for (i = 0; i < frames; ++i) {   /* right,left to match the ref */
                int16_t lr[2];
                lr[0] = dst[2 * i + 1];
                lr[1] = dst[2 * i + 0];
                fwrite(lr, 2, 2, w);
            }
            fclose(w);
            fprintf(stderr, "aica_live_replay: wrote %s (%u frames)\n", WAV_OUT, frames);
        }
    }

    printf("aica_live_replay: %u frames, %lu differ from the reference, "
           "%lu nonzero samples, peak %ld, keyed %u\n",
           frames, bad, nz, peak, vf3_native_aica_keyed());

    {
        unsigned insns = 0, halted = 0, chw = 0, rw = 0, fiq = 0;
        uint64_t cyc = 0;
        uint32_t lpc = 0;
        vf3_native_aica_arm_stats(&insns, &cyc, &halted, &chw, &rw, &lpc, &fiq);
        printf("aica_live_replay: arm7 %u insns / %llu cycles, halted %u, "
               "chan-writes %u, reg-writes %u, fiq %u, last_pc %04x\n",
               insns, (unsigned long long)cyc, halted, chw, rw, fiq, lpc);
    }

    free(dst);
    free(data);
    free(seed);
    return 0;
}
