/* tests/aica_mixer_replay.c - the AICA's mixer against the reference's PCM.
 *
 * The fixture (extract/analysis/aica_mixer_fixture.bin, built by
 * tools/aica_mixer_fixture.py) carries the reference's own AICA state at the
 * start of a window, the writes the ARM7 (the sound CPU) made during it, and
 * the PCM the chip produced frame by frame.
 *
 * The test replays the window: the ARM7's writes go into the register file
 * and the sound RAM at the tick they happened in, the mixer samples once per
 * tick, and every frame has to match the reference's sample for sample.
 *
 * The fixture needs the reference's oracle, which is not in the repository:
 *
 *   python tools/aica_mixer_fixture.py
 *
 *   build/vf3aicamixer
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sys/aica_mixer.h"
#include "sys/aica_model.h"

#define FIXTURE "extract/analysis/aica_mixer_fixture.bin"

/* The reference's per-channel serialization (flycast's sgc::serialize): 72
 * bytes per channel, in this order. */
struct channel_state {
    uint32_t sa;
    uint32_t ca;
    uint32_t step;
    int32_t  s0;
    int32_t  s1;
    uint8_t  looped;
    int32_t  adpcm_quant;
    int32_t  adpcm_loop_quant;
    int32_t  adpcm_loop_prev;
    uint8_t  adpcm_in_loop;
    uint32_t noise_state;
    int32_t  aeg_value;
    uint32_t aeg_state;
    uint32_t feg_value;
    uint32_t feg_state;
    int32_t  feg_prev1;
    int32_t  feg_prev2;
    int32_t  feg_fract;
    uint32_t lfo_counter;
    uint8_t  lfo_state;
    uint8_t  enabled;
};

static uint32_t read32(const uint8_t *p)
{
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) |
           ((uint32_t)p[3] << 24);
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
        free(data);
        fclose(f);
        return NULL;
    }
    fclose(f);
    *size = (size_t)length;
    return data;
}

/* The reference's channel state, as the mixer's own. */
static void load_channel(const uint8_t *p, vf3_aica_mixer_channel *c)
{
    memset(c, 0, sizeof *c);
    c->sa = read32(p + 0);
    c->ca = read32(p + 4);
    c->step = read32(p + 8);
    c->s0 = (int32_t)read32(p + 12);
    c->s1 = (int32_t)read32(p + 16);
    c->looped = p[20];
    c->adpcm_quant = (int32_t)read32(p + 21);
    c->adpcm_loop_quant = (int32_t)read32(p + 25);
    c->adpcm_loop_prev = (int32_t)read32(p + 29);
    c->adpcm_in_loop = p[33];
    c->noise_state = read32(p + 34);
    c->aeg_value = (int32_t)read32(p + 38);
    c->aeg_state = p[42];
    c->feg_value = read32(p + 46);
    c->feg_state = p[50];
    c->feg_prev1 = (int32_t)read32(p + 54);
    c->feg_prev2 = (int32_t)read32(p + 58);
    c->feg_fract = (int32_t)read32(p + 62);
    c->lfo_counter = read32(p + 66);
    c->lfo_state = p[70];
    c->enabled = p[71];
}

int main(void)
{
    static uint8_t ram[VF3_AICA_RAM_SIZE];
    vf3_aica_model model;
    vf3_aica_mixer mixer;
    uint8_t *data;
    size_t size = 0, offset;
    uint32_t reg_bytes, ram_bytes, channel_bytes, write_count, frames;
    const uint8_t *registers, *channels, *writes, *pcm;
    uint32_t i;
    unsigned long bad = 0;
    long first_bad = -1;

    data = read_file(FIXTURE, &size);
    if (!data) {
        fprintf(stderr, "aica_mixer_replay: %s missing - build it with\n"
                        "  python tools/aica_mixer_fixture.py\n", FIXTURE);
        return 1;
    }
    if (size < 32 || memcmp(data, "VF3MIX1\0", 8) != 0) {
        fprintf(stderr, "aica_mixer_replay: %s is not the fixture\n", FIXTURE);
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
    {
        const uint8_t *ram_image = data + offset; offset += ram_bytes;
        channels = data + offset; offset += channel_bytes;
        writes = data + offset; offset += (size_t)write_count * 20u;
        pcm = data + offset;

        if (reg_bytes != VF3_AICA_REG_SIZE || ram_bytes != VF3_AICA_RAM_SIZE ||
            channel_bytes != VF3_AICA_SLOT_COUNT * 72u ||
            offset + (size_t)frames * 4u > size) {
            fprintf(stderr, "aica_mixer_replay: the fixture's sizes do not match\n");
            free(data);
            return 1;
        }

        vf3_aica_init(&model, ram);
        memcpy(model.reg, registers, VF3_AICA_REG_SIZE);
        memcpy(ram, ram_image, VF3_AICA_RAM_SIZE);
        vf3_aica_mixer_init(&mixer, &model);
        /* the register file was filled in directly, so the channels'
         * parameters have to be decoded before the mixer uses them */
        vf3_aica_mixer_decode_all(&mixer);

        for (i = 0; i < VF3_AICA_SLOT_COUNT; ++i) {
            vf3_aica_mixer_channel state;
            load_channel(channels + (size_t)i * 72u, &state);
            vf3_aica_mixer_channel_load(&mixer, i, &state);
        }

        /* the window: the ARM7's writes, then the chip's frame */
        {
            uint32_t windex = 0;
            for (i = 0; i < frames; ++i) {
                int16_t right = 0, left = 0;

                while (windex < write_count && read32(writes + (size_t)windex * 20u) == i) {
                    const uint8_t *w = writes + (size_t)windex * 20u;
                    const uint32_t kind = read32(w + 4);
                    const uint32_t at = read32(w + 8);
                    const uint32_t value = read32(w + 12);
                    const uint32_t size = read32(w + 16);
                    unsigned b;
                    if (kind == 0) {
                        vf3_aica_mixer_write(&mixer, at, value, size);
                    } else {
                        /* the hardware's wide writes land on an aligned
                         * address (the reference's arm_mem.h) */
                        const uint32_t aligned = at & ~(size - 1u);
                        for (b = 0; b < size; ++b) {
                            if (aligned + b < VF3_AICA_RAM_SIZE)
                                ram[aligned + b] = (uint8_t)(value >> (8u * b));
                        }
                    }
                    ++windex;
                }

                vf3_aica_mixer_sample(&mixer, &right, &left);
                {
                    const int16_t want_right = (int16_t)read32(pcm);
                    const int16_t want_left = (int16_t)read32(pcm + 2);
                    if (right != want_right || left != want_left) {
                        if (first_bad < 0) {
                            first_bad = (long)i;
                            fprintf(stderr,
                                    "aica_mixer_replay: frame %u: got (%d, %d), want (%d, %d)\n",
                                    i, (int)right, (int)left, (int)want_right, (int)want_left);
                        }
                        ++bad;
                    }
                }
                pcm += 4;
            }
            if (windex != write_count) {
                fprintf(stderr, "aica_mixer_replay: %u writes were not replayed\n",
                        write_count - windex);
                free(data);
                return 1;
            }
        }
    }

    if (bad) {
        fprintf(stderr, "aica_mixer_replay: %lu of %u frames differ (the first at %ld)\n",
                bad, frames, first_bad);
        free(data);
        return 1;
    }
    printf("aica_mixer_replay: %u frames match the reference's PCM sample for sample\n",
           frames);
    free(data);
    return 0;
}
