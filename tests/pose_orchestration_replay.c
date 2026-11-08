/* pose_orchestration_replay.c - the readable pose orchestration
 * (SH-4 0x8C09EAF2) against the retained generated translation.
 *
 * The body reserves a 228-byte frame, snapshots XMTRX into it, runs
 * seven_pass, root_orientation, matrix_set_translation, three xf_store
 * copies and matrix_push, calls halfword_frame, builds three float sums
 * and runs unit_triple, then store_keep_translation, matrix_copy, the
 * kind-record float shuffles and two xform_point calls, matrix_push,
 * the kind==12 table branch and facing_update, another xform_point,
 * matrix_pop and matrix_push, two aim_frame calls (output blocks at
 * actor+0x200 and actor+0x300) each followed by matrix_pop, the kind
 * floats at +48..+60, an xform_point, aim_midpoints, matrix_basis,
 * matrix_push, two aim_frame_b calls (objects at actor+0x480 and
 * actor+0x540) each followed by matrix_pop and matrix_push, and an
 * epilogue that pops macl, pr, r8..r13 and finally r14.
 *
 * Every callee is a readable or generated matrix helper, so the test
 * needs no stub: the three arms are the generated chain (the
 * reference), the readable port called directly, and the readable port
 * reached through the readable override.
 *
 * Five windows: the literal pool at 0x0c09e000 (every call target,
 * field offset and the kind==12 byte offset, with the values the real
 * image holds), the actor at 0x0c200000 (kind byte, pose fields, the
 * 0x420B selector byte), the kind-record table at 0x0c10d000, the
 * stack, and the matrix-stack control block at 0x0c19d2e4 (count 1 /
 * limit 16).  The epilogue pops r8..r14 from the caller's stack
 * above the entry sp, so those slots are seeded with distinct saved
 * values and checked on the way out - the guest's sp ends 28 bytes
 * above the entry sp, and the fixture model checks that.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_pose_orchestration_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY 0x0c09eaf2u
#define RETURN_PC 0x0c0abcdeu

#define WIN1_BASE 0x0c09e000u        /* literal pool */
#define WIN1_LEN  0x1000u
#define WIN2_BASE 0x0c200000u        /* the actor */
#define WIN2_LEN  0x8000u
#define WIN3_BASE 0x0c10d000u        /* the kind-record table */
#define WIN3_LEN  0x8000u
#define WIN4_BASE 0x0c100000u        /* the stack */
#define WIN4_LEN  0x10000u
#define WIN5_BASE 0x0c19d000u        /* the matrix stack */
#define WIN5_LEN  0x2000u
#define WIN6_BASE 0x0c29b000u        /* the stage global */
#define WIN6_LEN  0x2000u
#define ACTOR 0x0c200000u
#define STACK_TOP 0x0c108000u
#define STACK_CTL 0x0c19d2e4u
#define STACK_BASE 0x0c19d400u
#define KIND_TABLE 0x0c10d3c4u
#define KIND_TAB2 0x0c10dabcu

#define MAXWIN 6u
struct run {
    uint8_t *shadow[MAXWIN];
    vf3_matrix_state state;
    vf3_ram_win wins[MAXWIN];
    vf3_ram_map map;
};

struct scenario {
    const char *name;
    uint8_t kind;                   /* at actor+97 */
    uint8_t selector;               /* at actor+0x420B (kind != 12 arm) */
};

static uint32_t r32(const uint8_t *p, uint32_t off)
{
    return (uint32_t)p[off] | ((uint32_t)p[off + 1] << 8) |
           ((uint32_t)p[off + 2] << 16) | ((uint32_t)p[off + 3] << 24);
}

static void w32(uint8_t *p, uint32_t off, uint32_t v)
{
    p[off + 0] = (uint8_t)v;
    p[off + 1] = (uint8_t)(v >> 8);
    p[off + 2] = (uint8_t)(v >> 16);
    p[off + 3] = (uint8_t)(v >> 24);
}

static void w16(uint8_t *p, uint32_t off, uint16_t v)
{
    p[off + 0] = (uint8_t)v;
    p[off + 1] = (uint8_t)(v >> 8);
}

static unsigned win_len(unsigned w)
{
    static const unsigned L[MAXWIN] = { WIN1_LEN, WIN2_LEN, WIN3_LEN,
                                        WIN4_LEN, WIN5_LEN, WIN6_LEN };
    return L[w];
}

static uint32_t saved_reg(unsigned r)
{
    return 0x0c0c0000u + 0x1111u * r;
}

static void setup(struct run *r, const struct scenario *sc)
{
    memset(r, 0, sizeof *r);
    /* the stack is zeroed, not patterned: facing_update's atan path
     * reads two frame floats that nothing wrote yet, and the guest
     * takes its zero-vector early return there; pattern garbage made
     * the generated chain jump to pattern RAM instead */
    for (unsigned w = 0; w < MAXWIN; ++w) {
        r->shadow[w] = malloc(win_len(w));
        if (w == 3u)
            memset(r->shadow[w], 0, win_len(w));
        else
            for (unsigned i = 0; i < win_len(w); i += 4)
                w32(r->shadow[w], i, 0x22222222u + (i & 0xff));
    }

    /* the pool window is filled with the real image bytes, not pattern:
     * the callees (facing_update, aim_frame, aim_frame_b, unit_triple)
     * read their own literal pools from this same region, and pattern
     * bytes there would shadow the image values they dispatch through */
    uint8_t *pool = r->shadow[0];
    {
        const char *paths[] = { "extract/gamedata/1ST_READ.BIN",
                                "extract/exe/1ST_READ.unsc.bin", NULL };
        FILE *f = NULL;
        for (int i = 0; paths[i] && !f; ++i) f = fopen(paths[i], "rb");
        if (f) {
            const uint32_t base_off = WIN1_BASE - 0x0c010000u;
            fseek(f, (long)base_off, SEEK_SET);
            if (fread(pool, 1, WIN1_LEN, f) != WIN1_LEN) {
                fprintf(stderr, "pose_orchestration: short pool image\n");
                exit(1);
            }
            fclose(f);
        } else {
            for (unsigned i = 0; i < WIN1_LEN; i += 4)
                w32(pool, i, 0x22222222u + (i & 0xff));
        }
    }
    /* call targets */
    w32(pool, 0x0c09ec10u - WIN1_BASE, 0x0c03ccb0u);
    w32(pool, 0x0c09ec14u - WIN1_BASE, 0x0c03b620u);
    w32(pool, 0x0c09ec18u - WIN1_BASE, KIND_TABLE);
    w32(pool, 0x0c09ec1cu - WIN1_BASE, 0x0c09da72u);
    w32(pool, 0x0c09ec20u - WIN1_BASE, 0x0c09d9eau);
    w32(pool, 0x0c09ec24u - WIN1_BASE, 0x0c03cbd0u);
    w32(pool, 0x0c09ec28u - WIN1_BASE, 0x0c03b820u);
    w32(pool, 0x0c09ec2cu - WIN1_BASE, 0x0c03c4f0u);
    w32(pool, 0x0c09ec30u - WIN1_BASE, 0x0c09d4b0u);
    w32(pool, 0x0c09ec34u - WIN1_BASE, 0x0c09d4e6u);
    w32(pool, 0x0c09ec38u - WIN1_BASE, 0x0c03b530u);
    w32(pool, 0x0c09ec3cu - WIN1_BASE, 0x0c03b450u);
    w32(pool, 0x0c09ec40u - WIN1_BASE, KIND_TAB2);
    w32(pool, 0x0c09edf4u - WIN1_BASE, 0x0c03c4a0u);
    /* field offsets */
    static const struct { uint32_t at; uint16_t value; } offs[] = {
        { 0x0c09ebf4u, (uint16_t)-228 }, { 0x0c09ebf6u, 0x00a4 },
        { 0x0c09ebf8u, 0x1efc }, { 0x0c09ebfau, 0x0094 },
        { 0x0c09ebfcu, 0x00d4 }, { 0x0c09ebfeu, 0x22e4 },
        { 0x0c09ec00u, 0x1f56 }, { 0x0c09ec02u, 0x208c },
        { 0x0c09ec04u, 0x1f08 }, { 0x0c09ec06u, 0x2090 },
        { 0x0c09ec08u, 0x1f0c }, { 0x0c09ec0au, 0x2094 },
        { 0x0c09ec0cu, 0x1f10 }, { 0x0c09ec0eu, 0x0180 },
        { 0x0c09edb8u, 0x2098 }, { 0x0c09edb4u, 0x1f62 },
        { 0x0c09edb6u, 0x1f20 }, { 0x0c09edbau, 0x0640 },
        { 0x0c09edbcu, 0x0200 }, { 0x0c09edbeu, 0x00cc },
        { 0x0c09edc4u, 0x20a4 }, { 0x0c09edc0u, 0x1f74 },
        { 0x0c09edc2u, 0x1f2c }, { 0x0c09edc6u, 0x0680 },
        { 0x0c09edc8u, 0x0300 }, { 0x0c09edcau, 0x00fc },
        { 0x0c09edccu, 0x009c }, { 0x0c09edceu, 0x008c },
        { 0x0c09edd2u, 0x1f8c }, { 0x0c09edd0u, 0x0138 },
        { 0x0c09edd8u, 0x22e8 }, { 0x0c09edd4u, 0x06c0 },
        { 0x0c09edd6u, 0x1f38 }, { 0x0c09eddau, 0x22ec },
        { 0x0c09eddcu, 0x00a8 }, { 0x0c09eddeu, 0x20b4 },
        { 0x0c09ede0u, 0x0480 },
        { 0x0c09ede8u, 0x1f44 }, { 0x0c09ede4u, 0x1f98 },
        { 0x0c09ede6u, 0x0740 }, { 0x0c09ede2u, 0x015c },
        { 0x0c09edeau, 0x22ea }, { 0x0c09edecu, 0x22f8 },
        { 0x0c09edeeu, 0x20c0 }, { 0x0c09edf0u, 0x0540 },
        { 0x0c09ef2au, 0x013c }, { 0x0c09ef1cu, 0x420b },
    };
    for (unsigned i = 0; i < sizeof offs / sizeof offs[0]; ++i)
        w16(pool, offs[i].at - WIN1_BASE, offs[i].value);

    /* the actor: kind byte, selector byte, and distinct field words */
    r->shadow[1][97] = sc->kind;
    r->shadow[1][0x420b] = sc->selector;
    r->shadow[1][4] = 1;    /* facing_update's byte at actor+4: non-zero,
                             * so it keeps r11 (the table pointer) */
    for (unsigned i = 0; i < 0x3000u; i += 4)
        w32(r->shadow[1], 0x100u + i, 0x30000000u + i);

    /* the kind==12 table and every selector entry point at a scratch
     * object in the kind-table window, past the records below the body
     * dereferences them; the global facing_update reads through
     * (0x0C29BB84) points at the same object */
    w32(r->shadow[5], 0x0c29bb84u - WIN6_BASE + 20u, 0x0c10f000u);

    /* the kind-record table: distinct floats in each record */
    for (unsigned rec = 0; rec < 32; ++rec) {
        uint8_t *p = r->shadow[2] + (KIND_TABLE - WIN3_BASE) + rec * 108u;
        for (unsigned i = 0; i < 27; ++i) {
            uint32_t bits = 0x3f000000u + rec * 0x10000u + i * 0x101u;
            w32(p, i * 4u, bits);
        }
    }
    /* the kind table entries, written after the records (the records
     * stride over the table's addresses).  Entry +8 (the kind==12 arm)
     * points at a different object than the selector entries, with
     * different float contents, so the two arms are distinguishable. */
    for (unsigned i = 0; i < 256; ++i)
        w32(r->shadow[2], KIND_TAB2 - WIN3_BASE + 4u * i, 0x0c10f000u);
    w32(r->shadow[2], KIND_TAB2 - WIN3_BASE + 8u, 0x0c10f100u);
    for (unsigned i = 0; i < 64; ++i) {
        w32(r->shadow[2], 0x0c10f100u - WIN3_BASE + 4u * i,
            0x3f800000u + 0x1000u * i);
    }

    /* the matrix stack: count 1, limit 16, top one matrix up */
    w32(r->shadow[4], STACK_CTL - WIN5_BASE, (16u << 16) | 1u);
    w32(r->shadow[4], STACK_CTL - WIN5_BASE + 4u, STACK_BASE);
    w32(r->shadow[4], STACK_CTL - WIN5_BASE + 8u, STACK_BASE + 64u);

    /* the caller's saved r8..r13 and r14 above the entry sp, in the
     * order the epilogue pops them */
    for (unsigned i = 0; i < 6; ++i)
        w32(r->shadow[3], STACK_TOP - WIN4_BASE + 4u * i,
            saved_reg(8u + i));
    w32(r->shadow[3], STACK_TOP - WIN4_BASE + 24u, ACTOR);
    w32(r->shadow[3], STACK_TOP - WIN4_BASE - 4u, RETURN_PC);
    w32(r->shadow[3], STACK_TOP - WIN4_BASE - 8u, 0x12345678u);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = ACTOR;               /* (unused as an argument; r14 is) */
    s->v[5] = ACTOR + 0x300u;      /* the caller's argument -> r12 */
    s->v[14] = ACTOR;              /* r14: the actor */
    s->v[15] = STACK_TOP;          /* r15 */
    s->v[16] = RETURN_PC;          /* pr: the return target */
    s->v[19] = 0x12345678u;        /* macl: saved and restored */
    s->v[17] = 0x60000000u;        /* sr, T clear */
    s->v[18] = 0x00040001u;        /* fpscr: the chain's FPU gate */
    s->budget = 4000000u;
    for (unsigned i = 0; i < 16; ++i) s->v[37 + i] = 0u;
    s->v[37] = s->v[42] = s->v[47] = s->v[52] = 0x3f800000u;

    r->wins[0].base = WIN1_BASE; r->wins[0].len = WIN1_LEN; r->wins[0].data = r->shadow[0];
    r->wins[1].base = WIN2_BASE; r->wins[1].len = WIN2_LEN; r->wins[1].data = r->shadow[1];
    r->wins[2].base = WIN3_BASE; r->wins[2].len = WIN3_LEN; r->wins[2].data = r->shadow[2];
    r->wins[3].base = WIN4_BASE; r->wins[3].len = WIN4_LEN; r->wins[3].data = r->shadow[3];
    r->wins[4].base = WIN5_BASE; r->wins[4].len = WIN5_LEN; r->wins[4].data = r->shadow[4];
    r->wins[5].base = WIN6_BASE; r->wins[5].len = WIN6_LEN; r->wins[5].data = r->shadow[5];
    r->map.wins = r->wins;
    r->map.n = MAXWIN;
    r->map.oob = 0;
    r->map.device_read = NULL;
    r->map.device_write = NULL;
    r->map.device_context = NULL;
}

static int same(const struct run *a, const struct run *b, const char *what)
{
    if (memcmp(a->state.v, b->state.v, sizeof a->state.v)) {
        unsigned shown = 0;
        for (unsigned i = 0; i < 54 && shown < 12; ++i)
            if (a->state.v[i] != b->state.v[i]) {
                fprintf(stderr, "  %s: v%u %08x != %08x\n", what, i,
                        a->state.v[i], b->state.v[i]);
                ++shown;
            }
        return 0;
    }
    if (a->state.pc != b->state.pc || a->state.failed_pc != b->state.failed_pc) {
        fprintf(stderr, "  %s: pc %08x/%08x failed %08x/%08x\n", what,
                a->state.pc, b->state.pc, a->state.failed_pc, b->state.failed_pc);
        return 0;
    }
    if (a->map.oob != b->map.oob) {
        fprintf(stderr, "  %s: oob %u/%u\n", what, a->map.oob, b->map.oob);
        return 0;
    }
    for (unsigned w = 0; w < MAXWIN; ++w)
        if (memcmp(a->shadow[w], b->shadow[w], win_len(w))) {
            for (unsigned i = 0; i < win_len(w); ++i)
                if (a->shadow[w][i] != b->shadow[w][i]) {
                    fprintf(stderr, "  %s: ram w%u %u %02x != %02x\n",
                            what, w, i, a->shadow[w][i], b->shadow[w][i]);
                    break;
                }
            return 0;
        }
    return 1;
}

static unsigned cases;

static int compare(const struct scenario *sc)
{
    static struct run ref, port, hook;

    setup(&ref, sc);
    setup(&port, sc);
    setup(&hook, sc);

    const int ok_ref = vf3_matrix_family(ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_pose_orchestration_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(ENTRY, &hook.state, &hook.map,
                                              &handled);
    vf3_family_override = NULL;

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "pose_orchestration: %s differs (ok %d/%d/%d; ref pc %08x "
                "failed %08x oob %u)\n", sc->name, ok_ref, ok_port, ok_hook,
                ref.state.pc, ref.state.failed_pc, ref.map.oob);
        return 0;
    }
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "pose_orchestration: %s reads outside a window (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }

    /* the outcome against the fixture itself: the epilogue pops the
     * caller's saved r8..r13 and r14, and the guest's sp ends 28 bytes
     * above the entry sp */
    if (ref.state.pc != RETURN_PC || ref.state.v[15] != STACK_TOP + 28u ||
        ref.state.v[14] != ACTOR || ref.state.v[19] != 0x12345678u) {
        fprintf(stderr, "pose_orchestration: %s: pc/sp/r14/macl wrong "
                "(pc %08x sp %08x want %08x r14 %08x macl %08x)\n",
                sc->name, ref.state.pc, ref.state.v[15], STACK_TOP + 28u,
                ref.state.v[14], ref.state.v[19]);
        return 0;
    }
    for (unsigned i = 0; i < 6; ++i)
        if (ref.state.v[8 + i] != saved_reg(8u + i)) {
            fprintf(stderr, "pose_orchestration: %s: r%u %08x, want %08x\n",
                    sc->name, 8u + i, ref.state.v[8 + i], saved_reg(8u + i));
            return 0;
        }
    /* the matrix stack is back where it started: three pushes balanced
     * by three pops after the initial push/pop pair */
    if ((r32(ref.shadow[4], STACK_CTL - WIN5_BASE) & 0xffffu) != 1u) {
        fprintf(stderr, "pose_orchestration: %s: matrix stack count wrong\n",
                sc->name);
        return 0;
    }

    ++cases;
    return 1;
}

int main(void)
{
    const vf3_readable_entry *reg = vf3_readable_find(ENTRY);
    if (!reg || reg->fn != vf3_pose_orchestration_entry) {
        fprintf(stderr, "pose_orchestration: the port is not registered\n");
        return 1;
    }

    static const struct scenario scenarios[] = {
        { .name = "kind 3", .kind = 3, .selector = 0 },
        { .name = "kind 12", .kind = 12, .selector = 0 },
        { .name = "kind 21", .kind = 21, .selector = 7 },
        { .name = "kind 0", .kind = 0, .selector = 255 },
    };

    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;

    printf("pose_orchestration: %u differential cases - PASS\n", cases);
    return 0;
}
