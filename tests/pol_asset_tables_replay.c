/* Validate the POL slot/texture tables against extracted model assets. */
#include "pol.h"
#include "pvr_texture.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int load(const char *path, uint8_t **data, uint32_t *size)
{
    FILE *f = fopen(path, "rb");
    long n;
    if (!f)
        return -1;
    if (fseek(f, 0, SEEK_END) != 0 || (n = ftell(f)) <= 0 ||
        (unsigned long)n > UINT32_MAX || fseek(f, 0, SEEK_SET) != 0) {
        fclose(f);
        return -1;
    }
    *data = (uint8_t *)malloc((size_t)n);
    if (!*data || fread(*data, 1, (size_t)n, f) != (size_t)n) {
        free(*data);
        *data = NULL;
        fclose(f);
        return -1;
    }
    fclose(f);
    *size = (uint32_t)n;
    return 0;
}

static void wr16(uint8_t *p, uint16_t value)
{
    p[0] = (uint8_t)value;
    p[1] = (uint8_t)(value >> 8);
}

static void wr32(uint8_t *p, uint32_t value)
{
    p[0] = (uint8_t)value;
    p[1] = (uint8_t)(value >> 8);
    p[2] = (uint8_t)(value >> 16);
    p[3] = (uint8_t)(value >> 24);
}

static uint32_t rd32(const uint8_t *p)
{
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

static int check_opaque_slot_chain(const char *stem, const uint8_t *data,
                                   uint32_t size)
{
    PolDataSpan *spans = NULL;
    const PolDataSpan *previous = NULL;
    uint32_t count = 0, untagged = 0;
    int fails = 0;
    if (pol_data_spans(data, size, NULL, 0, &count) != -2 || !count) {
        fprintf(stderr, "  %s: cannot query untagged slot chain\n", stem);
        return 1;
    }
    spans = (PolDataSpan *)calloc(count, sizeof *spans);
    if (!spans || pol_data_spans(data, size, spans, count, &count) != 0) {
        fprintf(stderr, "  %s: cannot read untagged slot chain\n", stem);
        free(spans);
        return 1;
    }
    for (uint32_t i = 0; i < count; ++i) {
        const PolDataSpan *span = &spans[i];
        uint32_t backref;
        if (span->tagged)
            continue;
        ++untagged;
        if (span->end - span->start < 8u || span->start < 0x34u ||
            rd32(data + span->start) != span->start - 0x34u) {
            fprintf(stderr,
                    "  %s: untagged slot %u lacks its observed header reference\n",
                    stem, span->slot_index);
            fails++;
            break;
        }
        backref = rd32(data + span->start + 4u);
        if (previous) {
            if (backref < previous->start || backref >= previous->end) {
                fprintf(stderr,
                        "  %s: untagged slot %u does not reference the prior slot span\n",
                        stem, span->slot_index);
                fails++;
                break;
            }
        } else if (backref < 0x30u || backref >= span->start) {
            fprintf(stderr,
                    "  %s: first untagged slot %u has an invalid root reference\n",
                    stem, span->slot_index);
            fails++;
            break;
        }
        previous = span;
    }
    if (!fails && untagged != 12u) {
        fprintf(stderr, "  %s: expected 12 untagged slot links, found %u\n",
                stem, untagged);
        fails++;
    }
    if (!fails)
        printf("  %s: %u untagged slots form a bounded backward-reference chain\n",
               stem, untagged);
    free(spans);
    return fails;
}

static int check_model(const char *stem, uint16_t expected_slots,
                       uint16_t expected_textures, uint32_t expected_tagged,
                       uint32_t expected_model_block)
{
    char pol_path[128], tex_path[128];
    uint8_t *pol = NULL, *tex = NULL;
    uint32_t pol_size = 0, tex_size = 0, count = 0;
    PolHeader header;
    PolSlot *slots = NULL;
    PolSlotSpan *spans = NULL;
    PolTextureDesc *textures = NULL;
    int fails = 0;
    snprintf(pol_path, sizeof pol_path, "extract/gamedata/%s.POL", stem);
    snprintf(tex_path, sizeof tex_path, "extract/gamedata/%s.TEX", stem);
    if (load(pol_path, &pol, &pol_size) != 0 ||
        load(tex_path, &tex, &tex_size) != 0) {
        fprintf(stderr, "pol_asset_tables_replay: missing %s POL/TEX asset\n", stem);
        fails++;
        goto done;
    }
    if (pol_header(pol, pol_size, &header) != 0 ||
        header.slot_count != expected_slots ||
        header.texture_count != expected_textures ||
        header.slot_table_offset != 0x30 ||
        header.model_block_offset != expected_model_block) {
        fprintf(stderr, "  %s: unexpected POL header/table offsets\n", stem);
        fails++;
        goto done;
    }
    if (pol_slots(pol, pol_size, NULL, 0, &count) != -2 ||
        count != expected_slots) {
        fprintf(stderr, "  %s: slot count query failed\n", stem);
        fails++;
        goto done;
    }
    slots = (PolSlot *)calloc(count, sizeof *slots);
    if (!slots || pol_slots(pol, pol_size, slots, count - 1, &count) != -2 ||
        count != expected_slots ||
        pol_slots(pol, pol_size, slots, count, &count) != 0) {
        fprintf(stderr, "  %s: slot table read/capacity check failed\n", stem);
        fails++;
        goto done;
    }
    uint32_t tagged = 0;
    for (uint32_t i = 0; i < count; ++i) {
        tagged += slots[i].tagged != 0;
        if (!slots[i].in_file) {
            fprintf(stderr, "  %s: slot %u candidate is outside POL\n", stem, i);
            fails++;
        }
    }
    if (tagged != expected_tagged)
        fails++;
    fails += check_opaque_slot_chain(stem, pol, pol_size);
    if (strcmp(stem, "MKAO_AKI") == 0 &&
        (slots[0].raw != 0x00035B19u ||
         slots[0].offset_candidate != 0x00035B18u || !slots[0].tagged)) {
        fprintf(stderr, "  AKI: first slot word mismatch\n");
        fails++;
    }

    if (pol_slot_spans(pol, pol_size, NULL, 0, &count) != -2 ||
        count != expected_tagged) {
        fprintf(stderr, "  %s: tagged slot span query failed\n", stem);
        fails++;
        goto done;
    }
    spans = (PolSlotSpan *)calloc(count, sizeof *spans);
    if (!spans || pol_slot_spans(pol, pol_size, spans, count - 1, &count) != -2 ||
        count != expected_tagged ||
        pol_slot_spans(pol, pol_size, spans, count, &count) != 0) {
        fprintf(stderr, "  %s: tagged slot span read/capacity check failed\n", stem);
        fails++;
        goto done;
    }
    for (uint32_t i = 0; i < count; ++i) {
        if (spans[i].start >= spans[i].end || spans[i].end > pol_size ||
            (i && spans[i - 1].end != spans[i].start)) {
            fprintf(stderr, "  %s: invalid tagged slot span %u\n", stem, i);
            fails++;
        }
    }
    if (strcmp(stem, "MKAO_AKI") == 0 &&
        (spans[0].slot_index != 0 || spans[0].start != 0x35B18u ||
         spans[0].end != 0x36598u || spans[count - 1].end != pol_size)) {
        fprintf(stderr, "  AKI: first/last tagged slot span mismatch\n");
        fails++;
    }

    if (pol_textures(pol, pol_size, NULL, 0, &count) != -2 ||
        count != expected_textures) {
        fprintf(stderr, "  %s: texture descriptor count query failed\n", stem);
        fails++;
        goto done;
    }
    textures = (PolTextureDesc *)calloc(count, sizeof *textures);
    if (!textures || pol_textures(pol, pol_size, textures, count - 1, &count) != -2 ||
        count != expected_textures ||
        pol_textures(pol, pol_size, textures, count, &count) != 0) {
        fprintf(stderr, "  %s: texture descriptor read/capacity check failed\n", stem);
        fails++;
        goto done;
    }
    for (uint32_t i = 0; i < count; ++i) {
        const uint64_t bytes = (uint64_t)textures[i].width * textures[i].height * 2u;
        const size_t pixels = (size_t)textures[i].width * textures[i].height;
        uint32_t *decoded = NULL;
        if (!textures[i].width || !textures[i].height ||
            (uint64_t)textures[i].data_offset + bytes > tex_size) {
            fprintf(stderr, "  %s: texture descriptor %u exceeds companion TEX\n",
                    stem, i);
            fails++;
            continue;
        }
        decoded = (uint32_t *)malloc(pixels * sizeof *decoded);
        if (!decoded || vf3_pvr_texture_decode(tex, tex_size, &textures[i],
                                                decoded, pixels) != 0) {
            fprintf(stderr, "  %s: texture descriptor %u did not decode\n",
                    stem, i);
            fails++;
        }
        free(decoded);
    }
    if (strcmp(stem, "MKAO_AKI") == 0 &&
        (textures[0].width != 64 || textures[0].height != 64 ||
         textures[0].data_offset != 0 || textures[1].data_offset != 0x2000 ||
         textures[3].width != 128 || textures[3].height != 128)) {
        fprintf(stderr, "  AKI: texture descriptor fields mismatch\n");
        fails++;
    }
    printf("  %s: %u slots (%u tagged), %u texture descriptors, TEX=%u bytes\n",
           stem, header.slot_count, tagged, header.texture_count, tex_size);

    if (pol_header(pol, 8, &header) == 0 ||
        pol_slots(pol, 0x30, NULL, 0, &count) != -1 ||
        pol_textures(pol, header.model_block_offset, NULL, 0, &count) != -1) {
        fprintf(stderr, "  %s: truncated table was accepted\n", stem);
        fails++;
    }
done:
    free(textures);
    free(spans);
    free(slots);
    free(tex);
    free(pol);
    return fails;
}

static int check_texture_decoder(void)
{
    const uint8_t morton_pixels[8] = {
        0x00, 0xF8, /* storage index 0: red */
        0xE0, 0x07, /* storage index 1: green */
        0x1F, 0x00, /* storage index 2: blue */
        0xFF, 0xFF  /* storage index 3: white */
    };
    const uint32_t expected[4] = {
        0xFFFF0000u, 0xFF0000FFu, 0xFF00FF00u, 0xFFFFFFFFu
    };
    const PolTextureDesc desc = { 2, 2, 0x0101u, 0, 0 };
    uint32_t decoded[4] = {0};
    if (vf3_pvr_texture_decode(morton_pixels, sizeof morton_pixels, &desc,
                               decoded, 4) != 0 ||
        memcmp(decoded, expected, sizeof expected) != 0 ||
        vf3_pvr_texture_decode(morton_pixels, sizeof morton_pixels, &desc,
                               decoded, 3) != -2) {
        fprintf(stderr, "  synthetic 2x2 PVR texture decode failed\n");
        return 1;
    }
    return 0;
}

static int check_slot_aliases(void)
{
    uint8_t data[0x60] = {0};
    PolSlotSpan tagged[3];
    PolDataSpan all[4];
    uint32_t count = 0;
    wr32(data, 0x200u);
    wr16(data + 0x0C, 5);
    wr32(data + 0x10, 0x30u);
    wr32(data + 0x30, 0x41u);
    wr32(data + 0x34, 0x41u);
    wr32(data + 0x38, 0x50u);
    wr32(data + 0x3C, 0x59u);
    wr32(data + 0x40, 0);

    if (pol_slot_spans(data, sizeof data, NULL, 0, &count) != -2 || count != 3 ||
        pol_slot_spans(data, sizeof data, tagged, 2, &count) != -2 ||
        pol_slot_spans(data, sizeof data, tagged, 3, &count) != 0 ||
        tagged[0].slot_index != 0 || tagged[1].slot_index != 1 ||
        tagged[0].start != 0x40u || tagged[0].end != 0x58u ||
        tagged[1].start != tagged[0].start || tagged[1].end != tagged[0].end ||
        tagged[2].slot_index != 3 || tagged[2].start != 0x58u ||
        tagged[2].end != sizeof data) {
        fprintf(stderr, "  synthetic tagged alias span check failed\n");
        return 1;
    }
    if (pol_data_spans(data, sizeof data, NULL, 0, &count) != -2 || count != 4 ||
        pol_data_spans(data, sizeof data, all, 3, &count) != -2 ||
        pol_data_spans(data, sizeof data, all, 4, &count) != 0 ||
        all[0].slot_index != 0 || all[1].slot_index != 1 ||
        all[0].start != 0x40u || all[0].end != 0x50u ||
        all[1].start != all[0].start || all[1].end != all[0].end ||
        all[2].slot_index != 2 || all[2].start != 0x50u ||
        all[2].end != 0x58u || all[2].tagged ||
        all[3].slot_index != 3 || all[3].start != 0x58u ||
        all[3].end != sizeof data || !all[3].tagged) {
        fprintf(stderr, "  synthetic all-slot span check failed\n");
        return 1;
    }
    wr32(data + 0x30, 0x01u);
    if (pol_slot_spans(data, sizeof data, tagged, 3, &count) != -1 ||
        pol_data_spans(data, sizeof data, all, 4, &count) != -1) {
        fprintf(stderr, "  synthetic invalid slot target was accepted\n");
        return 1;
    }
    return 0;
}

int main(void)
{
    int fails = check_texture_decoder() + check_slot_aliases();
    fails += check_model("MKAO_AKI", 22, 10, 10, 0x88);
    fails += check_model("MKAO_JAC", 43, 13, 31, 0xE0);
    puts(fails ? "pol_asset_tables_replay: FAIL" : "pol_asset_tables_replay: PASS");
    return fails ? 1 : 0;
}
