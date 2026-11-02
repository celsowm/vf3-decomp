/* tests/aica_native_replay.c - the host's own render loop against the
 * reference's PCM.
 *
 * The mixer replay test (tests/aica_mixer_replay.c) proves the mixer by
 * itself.  This one proves the *host's* audio function, vf3_native_aica_mix
 * (the function the SDL3 port feeds its stream and its --wav-out tape),
 * renders the same reference PCM, by seeding the host's AICA state from the
 * fixture and stepping it through vf3_native_aica_mix with the replay armed.
 *
 * The fixture (extract/analysis/aica_mixer_fixture.bin) carries the
 * reference's AICA state at the start of a window, the ARM7's writes during
 * it and the PCM the chip produced frame by frame.
 *
 *   build/vf3aicanative            (run from the repository root)
 *
 * On success every mixed frame matches the reference sample for sample and a
 * copy of the host's output is written to build/native_ref.wav - a WAV that
 * the host itself produced.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fight/native_tick.h"
#include "sys/aica_model.h"
#include "sys/aica_mixer.h"

#define FIXTURE "extract/analysis/aica_mixer_fixture.bin"
#define WAV_OUT "build/native_ref.wav"

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
    uint8_t *data;
    size_t size = 0, offset;
    uint32_t reg_bytes, ram_bytes, channel_bytes, write_count, frames;
    const uint8_t *registers, *ram, *channels, *writes, *pcm;
    int16_t *dst;
    unsigned long bad = 0;
    long first_bad = -1;
    uint32_t i;

    data = read_file(FIXTURE, &size);
    if (!data) {
        fprintf(stderr, "aica_native_replay: %s missing (run from the repo root)\n", FIXTURE);
        return 1;
    }
    if (size < 32 || memcmp(data, "VF3MIX1\0", 8) != 0) {
        fprintf(stderr, "aica_native_replay: %s is not the fixture\n", FIXTURE);
        free(data);
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
    writes = data + offset; offset += (size_t)write_count * 20u;
    pcm = data + offset;

    if (reg_bytes != VF3_AICA_REG_SIZE || ram_bytes != VF3_AICA_RAM_SIZE ||
        channel_bytes != VF3_AICA_SLOT_COUNT * 72u ||
        offset + (size_t)frames * 4u > size) {
        fprintf(stderr, "aica_native_replay: the fixture's sizes do not match\n");
        free(data);
        return 1;
    }

    vf3_native_aica_replay_init(registers, ram, channels, writes, write_count);

    dst = (int16_t *)malloc((size_t)frames * 2u * 2u);
    if (!dst) { free(data); return 1; }
    vf3_native_aica_mix(dst, frames);
    vf3_native_aica_replay_init(NULL, NULL, NULL, NULL, 0); /* disarm */

    /* every frame has to match the reference's, sample for sample */
    for (i = 0; i < frames; ++i) {
        const int16_t want_right = (int16_t)read32(pcm + i * 4u);
        const int16_t want_left = (int16_t)read32(pcm + i * 4u + 2u);
        const int16_t got_left = dst[2 * i + 0];
        const int16_t got_right = dst[2 * i + 1];
        if (got_left != want_left || got_right != want_right) {
            if (first_bad < 0) {
                first_bad = (long)i;
                fprintf(stderr,
                        "aica_native_replay: frame %u: got (%d, %d), want (%d, %d)\n",
                        i, (int)got_left, (int)got_right, (int)want_left, (int)want_right);
            }
            ++bad;
        }
    }

    if (!bad) {
        /* write the host's own output as a WAV, for the record */
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
            hdr[16] = 16;                       /* fmt chunk size */
            hdr[20] = 1; hdr[21] = 0;           /* PCM */
            hdr[22] = 2; hdr[23] = 0;           /* 2 channels */
            hdr[24] = (unsigned char)(sr & 0xff); hdr[25] = (unsigned char)((sr >> 8) & 0xff);
            hdr[26] = (unsigned char)((sr >> 16) & 0xff); hdr[27] = (unsigned char)((sr >> 24) & 0xff);
            hdr[28] = (unsigned char)(bps & 0xff); hdr[29] = (unsigned char)((bps >> 8) & 0xff);
            hdr[30] = (unsigned char)((bps >> 16) & 0xff); hdr[31] = (unsigned char)((bps >> 24) & 0xff);
            hdr[32] = 4; hdr[33] = 0;           /* block align */
            hdr[34] = 16; hdr[35] = 0;          /* bits per sample */
            memcpy(hdr + 36, "data", 4);
            hdr[40] = (unsigned char)(datalen & 0xff); hdr[41] = (unsigned char)((datalen >> 8) & 0xff);
            hdr[42] = (unsigned char)((datalen >> 16) & 0xff); hdr[43] = (unsigned char)((datalen >> 24) & 0xff);
            fwrite(hdr, 1, sizeof hdr, w);
            /* the host renders left,right; the reference file (and flycast's
             * guest_pcm) stores right,left - swap so the artifact matches
             * the reference WAV byte for byte */
            for (i = 0; i < frames; ++i) {
                int16_t lr[2];
                lr[0] = dst[2 * i + 1];
                lr[1] = dst[2 * i + 0];
                fwrite(lr, 2, 2, w);
            }
            fclose(w);
            fprintf(stderr, "aica_native_replay: wrote %s (%u frames)\n", WAV_OUT, frames);
        }
        printf("aica_native_replay: %u frames match the reference's PCM sample for sample\n",
               frames);
    } else {
        fprintf(stderr, "aica_native_replay: %lu of %u frames differ (the first at %ld)\n",
                bad, frames, first_bad);
    }

    free(dst);
    free(data);
    return bad ? 1 : 0;
}
