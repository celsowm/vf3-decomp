/* vmu_cmd_name_replay.c - the readable save-operation name selector
 * (SH-4 0x8C0374B0) against the retained generated translation.
 *
 * The function is a self-contained leaf: no calls, no FPU, no stack frame.
 * It reads the command id in r4 and answers with the address of the string
 * that names that operation, picked out of the literal pool.  So the test
 * needs no stub - the two leaves are the *generated* translation and the
 * readable port, and they are compared against each other.
 *
 * The three arms are:
 *
 *   1. the generated chain - the reference;
 *   2. the readable port, called directly;
 *   3. the readable port, reached through the readable override (which is how
 *      the native tick reaches it).
 *
 * All three compare the whole register file, the return PC, the failed PC,
 * the out-of-window counter and every RAM byte.  The test also checks the
 * outcome **against the fixture itself**: the answer in r0 has to be the
 * fixture's pool word for the given command - a differential alone is not
 * enough, because a fixture that is not where the guest looks makes both
 * sides read the same wrong bytes and agree on them.
 *
 * The pool lives in ROM, so the test supplies it as a window carrying the
 * image's own words - the eight string addresses the selector returns.  Every
 * one of the eight distinct, so a port that reads the wrong offset answers
 * with the wrong string and fails both the differential and the fixture
 * check.
 *
 * The scenarios cover every branch of the guest's tree: the seven known
 * command ids and three unknowns that take the fallback.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_vmu_cmd_name_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define ENTRY 0x0c0374b0u

#define RETURN_PC 0x0cabcdeu

/* ---- the window: the literal pool ---- */
#define POOL_BASE 0x0c037000u   /* covers the selector's pool at +0x54c..+0x568 */
#define POOL_LEN  0x1000u
#define NWIN 1

#define OFF_POOL 0u
#define SHADOW_LEN POOL_LEN

/* The pool words, one per command id, in the order the guest tests them. */
#define P_OFF_0  0x54cu   /* "NOP"              */
#define P_OFF_1  0x550u   /* "CONNECTED"        */
#define P_OFF_2  0x554u   /* "DISCONNECTED"     */
#define P_OFF_3  0x558u   /* "FORMAT DISK"      */
#define P_OFF_7  0x55cu   /* "DELETE FILE"      */
#define P_OFF_B  0x560u   /* "LOAD FILE"        */
#define P_OFF_C  0x564u   /* "SAVE FILE"        */
#define P_OFF_DF 0x568u   /* "UNKNOWN OPERATION" */

/* The image's words at those slots: the address of each string.  They are
 * all distinct, so reading the wrong slot answers with the wrong string. */
#define STR_NOP     0x0c0ccd14u
#define STR_CONN    0x0c0ccd1cu
#define STR_DISC    0x0c0ccd28u
#define STR_FORMAT  0x0c0ccd38u
#define STR_DELETE  0x0c0ccd44u
#define STR_LOAD    0x0c0ccd50u
#define STR_SAVE    0x0c0ccd5cu
#define STR_UNKNOWN 0x0c0ccd68u

struct run {
    uint8_t shadow[SHADOW_LEN];
    vf3_matrix_state state;
    vf3_ram_win wins[NWIN];
    vf3_ram_map map;
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

static void setup(struct run *r, uint32_t cmd)
{
    uint8_t *p = r->shadow;
    /* The pool is one of the game's own ranges; fill it with one pattern so
     * a read of the wrong address is not the value the guest meant. */
    memset(p, 0x11, SHADOW_LEN);

    /* The eight slots the guest can choose, with the image's string
     * addresses - the values the selector actually returns. */
    w32(p, P_OFF_0,  STR_NOP);
    w32(p, P_OFF_1,  STR_CONN);
    w32(p, P_OFF_2,  STR_DISC);
    w32(p, P_OFF_3,  STR_FORMAT);
    w32(p, P_OFF_7,  STR_DELETE);
    w32(p, P_OFF_B,  STR_LOAD);
    w32(p, P_OFF_C,  STR_SAVE);
    w32(p, P_OFF_DF, STR_UNKNOWN);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = cmd;                      /* the command id the caller hands over */
    s->v[16] = RETURN_PC;               /* the caller's return address */
    s->v[17] = 0x60000001u;             /* sr: the corpus' own value */
    /* The dispatcher refuses to run anything when the FPU is unsupported
     * (FPSCR.RM is 2 or 3, or the precision bit is set), and the corpus
     * carries 0x240001 / 0x40001.  The function uses no FP instruction, but
     * the gate stands between the caller and the body. */
    s->v[18] = 0x00024001u;             /* fpscr: the corpus' own value */
    s->budget = 1000000u;

    r->wins[0].base = POOL_BASE;  r->wins[0].len = POOL_LEN;
    r->wins[0].data = p + OFF_POOL;
    r->map.wins = r->wins;
    r->map.n = NWIN;
    r->map.oob = 0;
    r->map.device_read = NULL;
    r->map.device_write = NULL;
    r->map.device_context = NULL;
}

static int same(const struct run *a, const struct run *b, const char *what)
{
    if (memcmp(a->state.v, b->state.v, sizeof a->state.v)) {
        unsigned shown = 0;
        for (unsigned i = 0; i < 54 && shown < 8; ++i)
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
    if (memcmp(a->shadow, b->shadow, SHADOW_LEN)) {
        for (unsigned i = 0; i < SHADOW_LEN; ++i)
            if (a->shadow[i] != b->shadow[i]) {
                fprintf(stderr, "  %s: ram %u %02x != %02x\n", what, i,
                        a->shadow[i], b->shadow[i]);
                break;
            }
        return 0;
    }
    return 1;
}

/* ---- the model of the guest ----
 *
 * The guest tests the id against the seven known values in order and takes
 * the first match, then reads the pool word for it; an id that matches none
 * falls back to the "UNKNOWN OPERATION" slot.  The T bit it leaves is the
 * last test's: set on a match, clear on the fallback.
 */
static uint32_t model(const uint8_t *shadow, uint32_t cmd, int *t)
{
    static const uint32_t keys[7] = { 0u, 1u, 2u, 3u, 7u, 0xbu, 0xcu };
    static const uint32_t offs[7] = { P_OFF_0, P_OFF_1, P_OFF_2, P_OFF_3,
                                      P_OFF_7, P_OFF_B, P_OFF_C };
    uint32_t off = P_OFF_DF;            /* the fallback */
    *t = 0;
    for (unsigned i = 0; i < 7; ++i) {
        *t = (cmd == keys[i]);
        if (*t) {
            off = offs[i];
            break;
        }
    }
    return r32(shadow, off);
}

static unsigned cases;

static int compare(const char *name, uint32_t cmd)
{
    static struct run ref, port, hook;

    setup(&ref, cmd);
    int want_t;
    const uint32_t want_r0 = model(ref.shadow, cmd, &want_t);
    setup(&port, cmd);
    setup(&hook, cmd);

    const int ok_ref = vf3_matrix_family(ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_vmu_cmd_name_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(ENTRY, &hook.state, &hook.map,
                                               &handled);
    vf3_family_override = NULL;

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "vmu_cmd_name: %s (cmd %u) differs (ok %d/%d/%d; "
                "ref pc %08x failed %08x oob %u)\n", name, cmd,
                ok_ref, ok_port, ok_hook,
                ref.state.pc, ref.state.failed_pc, ref.map.oob);
        return 0;
    }
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "vmu_cmd_name: %s reads outside the windows "
                "(oob %u/%u/%u)\n", name, ref.map.oob, port.map.oob,
                hook.map.oob);
        return 0;
    }

    /* the outcome against the fixture itself */
    {
        if (ref.state.v[0] != want_r0) {
            fprintf(stderr, "vmu_cmd_name: %s: r0 is %08x, expected %08x\n",
                    name, ref.state.v[0], want_r0);
            return 0;
        }
        if ((int)(ref.state.v[17] & 1u) != want_t) {
            fprintf(stderr, "vmu_cmd_name: %s: the T bit is %u, expected %d\n",
                    name, ref.state.v[17] & 1u, want_t);
            return 0;
        }
        if (ref.state.pc != RETURN_PC) {
            fprintf(stderr, "vmu_cmd_name: %s: pc is %08x, expected %08x\n",
                    name, ref.state.pc, RETURN_PC);
            return 0;
        }
    }

    ++cases;
    return 1;
}

int main(void)
{
    /* the port has to be registered, or the native tick never reaches it */
    const vf3_readable_entry *reg = vf3_readable_find(ENTRY);
    if (!reg || reg->fn != vf3_vmu_cmd_name_entry) {
        fprintf(stderr, "vmu_cmd_name: the port is not registered\n");
        return 1;
    }

    /* the seven known commands, one per branch of the selector */
    if (!compare("NOP", 0u))            return 1;
    if (!compare("CONNECTED", 1u))      return 1;
    if (!compare("DISCONNECTED", 2u))   return 1;
    if (!compare("FORMAT DISK", 3u))    return 1;
    if (!compare("DELETE FILE", 7u))    return 1;
    if (!compare("LOAD FILE", 0xbu))    return 1;
    if (!compare("SAVE FILE", 0xcu))    return 1;

    /* commands the guest does not know: the fallback, three ways */
    if (!compare("five", 5u))           return 1;
    if (!compare("all bits", 0xffffffffu)) return 1;
    if (!compare("large id", 0x1000u))  return 1;

    printf("vmu_cmd_name: %u differential cases - PASS\n", cases);
    return 0;
}
