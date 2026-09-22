/* fight/mt_play.c — MT (motion) in-engine playback port.
 *
 * Provenance: 1ST_READ 0x8C09D69A + 0x8C09D6E0 (fight_f_8c09d69a /
 * fight_f_8c09d6e0), observed live in extract/analysis/m14_wide_vf3_7.bin
 * under the M14 mem-watch capture.
 *
 * Behaviour traced at frame granularity (VF3tb attract fight, Jacky vs Lau):
 *   - the evaluator reads a 32-byte header per slot (slot table = first
 *     32-bit word of each record), then walks a byte-stream command window
 *     at record+0x736.. and pulls 4 x u32 (fr/u32) at record+0x7A4..0x7B0.
 *     Records reference secondary param records by relative offset chains
 *     (the 5093 -> 5096 pair, slot 5096 bytes 0x194..0x1FC).
 *
 * The port models the record as (bytecode stream + quad tuples). Opcode
 * vocabulary itself is not yet fully decoded; field-by-field validation via
 * the M13+ traces is the follow-up. Constants are exposed as named macros
 * so matching offsets are traceable in reviews.
 */
#include <stdint.h>

typedef struct MtRecordBody {
    /* Header region decoded from tools/mtmap.py — first 4 bytes = u32 count */
    const uint8_t *bytes;    /* record body start */
    uint32_t       size;     /* from mt_tables CSV */
    /* runtime */
    uint32_t       stream_pc;     /* hlilícia: record+0x736 cursor   */
    uint32_t       tuple_slot;    /* record+0x7A4..: 4 u32 quad      */
    const uint8_t *linked;        /* linked (second) record body     */
} MtRecordBody;

/* offsets extracted from mt_field_reads.csv */
#define MT_CURSOR_CMD_BASE    0x736   /* u8 opcode stream */
#define MT_CURSOR_CMD_END     0x779   /* cursor end (4 bytes / frame) */
#define MT_QUAD_BASE          0x7A4   /* first of the u32 quad */
#define MT_QUAD_LEN           16
#define MT_LINKED_PARAM_BASE  0x194   /* in linked record: 4-op table   */
#define MT_LINKED_PARAM_END   0x1FC

static uint32_t mt_r32(const uint8_t *p)
{
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) |
           ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

/* Advance one frame of the byte-stream cursor for the active record and
 * return the 4 u32 tuple that callers copy into the per-bone work area.
 * Trace: 0x8C09D6F6/0x8C09D70C -> byte advance; 0x8C09D77A/80/84/96 -> u32s.
 */
int mt_step_frame(MtRecordBody *rec, uint32_t out_quad[4])
{
    if (!rec || !rec->bytes || !rec->size)
        return -1;
    uint32_t c = rec->stream_pc;
    if (c < MT_CURSOR_CMD_BASE)
        c = MT_CURSOR_CMD_BASE;
    if (c + 4 > rec->size) {
        /* wrap: record loops (idle cycles) — restart at cmd base */
        rec->stream_pc = c = MT_CURSOR_CMD_BASE;
    }
    /* byte advance: 1 byte/opcode per frame iteration */
    ++rec->stream_pc;

    /* Quad fetch: direct from record+0x7A4 (subject) */
    uint32_t q0 = mt_r32(rec->bytes + MT_QUAD_BASE + 0);
    uint32_t q1 = mt_r32(rec->bytes + MT_QUAD_BASE + 4);
    uint32_t q2 = mt_r32(rec->bytes + MT_QUAD_BASE + 8);
    uint32_t q3 = mt_r32(rec->bytes + MT_QUAD_BASE + 12);
    /* When a secondary record is linked, its own param segment overrides
     * the primary (trace: 5096+0x194..0x1FC read AFTER 5093+0x7A4) */
    if (rec->linked) {
        q0 = mt_r32(rec->linked + MT_LINKED_PARAM_BASE + 0);
        q1 = mt_r32(rec->linked + MT_LINKED_PARAM_BASE + 4);
        q2 = mt_r32(rec->linked + MT_LINKED_PARAM_BASE + 8);
        q3 = mt_r32(rec->linked + MT_LINKED_PARAM_BASE + 12);
    }
    out_quad[0] = q0; out_quad[1] = q1; out_quad[2] = q2; out_quad[3] = q3;
    return 0;
}
