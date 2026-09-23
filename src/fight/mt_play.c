/* fight/mt_play.c — MT (motion) in-engine playback port.
 *
 * Provenance: 1ST_READ fight_f_8c09d69a (helper, 69B) and
 * fight_f_8c09d6e0 (evaluator, 263B). Trace-verified:
 * extract/analysis/mt_field_reads.csv + the synced mem dump
 * extract/analysis/shots/mem_mtdump_vf3_7_*.bin. Byte-parity vs this model:
 * tests/mt_oracle.c.
 *
 * Model (oracle-verified): the evaluator processes a CHAIN of slot records
 * per frame:
 *   primary (5093): stream A per-part mode bytes @+0x736 (8), stream B
 *                   per-part tags @+0x75B (window to +0x77B incl.), and the
 *                   per-frame quad of float32s @+0x7A4 (16 bytes).
 *   linked  (5096): 12 tuple groups spread at 0xE0..0x3B0 (mostly 13-17B
 *                   u32/f32 triplets & quads). Group at +0x194 supplies the
 *                   effective (front-to-fight-verified) output tuple.
 *   extra   (1304/1307/1313): chained continuation records for the same
 *                   move — header refs @+0x2C and tuple slots at 0x41C/4A8..
 *
 * Chain layout observed so far (only active slot 5093 understood);
 * byte-value semantics of the A/B streams not yet decoded (M18 item 2+).
 */
#include <stdint.h>

#define MT_STREAM_A_BASE   0x736u
#define MT_STREAM_B_BASE   0x75Bu
#define MT_QUAD_BASE       0x7A4u
#define MT_QUAD_LEN        16u
#define MT_LINK_FST_PARAM  0x194u

typedef struct MtRecordBody {
    const uint8_t *bytes;
    uint32_t       size;      /* record body size (from mt_tables CSV) */
} MtRecordBody;

typedef struct MtFrameOut {
    float   q[4];            /* last quad tuple (the 4 float fields) */
    uint8_t mode_a, tag_b;
} MtFrameOut;

static float mt_rf32(const uint8_t *p)
{
    union { uint32_t u; float f; } v;
    v.u = (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
          ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
    return v.f;
}

/* One frame of one part, per the trace order:
 *   f_8c09d6f6  reads  byte at stream A base+part (mode)
 *   f_8c09d70c  reads  byte at stream B base+part (tag), when active
 *   f_8c09d779/8C09D780/8C09D784/8C09D796  read the quad at +0x7A4
 *   linked record (if present) overrides from its +0x194 group */
int mt_step_frame(const MtRecordBody *rec, const MtRecordBody *linked,
                  uint32_t part, MtFrameOut *out)
{
    if (!rec || !rec->bytes || rec->size <= MT_QUAD_BASE + MT_QUAD_LEN)
        return -1;
    if (part >= 8)
        return -2;

    uint8_t mode_a = rec->bytes[MT_STREAM_A_BASE + part];
    uint8_t tag_b  = rec->bytes[MT_STREAM_B_BASE + part];

    const uint8_t *src = rec->bytes + MT_QUAD_BASE;
    if (linked && linked->bytes && linked->size >= MT_LINK_FST_PARAM + 16)
        src = linked->bytes + MT_LINK_FST_PARAM;
    for (unsigned i = 0; i < 4; ++i)
        out->q[i] = mt_rf32(src + i * 4);

    out->mode_a = mode_a;
    out->tag_b  = tag_b;
    return 0;
}
