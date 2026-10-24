/* scale_step_replay.c - the readable motion-VM step against the retained
 * generated translation of SH-4 0x8C0CB8AC.
 *
 * The generated translation is the reference: it is the machine translation the
 * oracle proved against the captured fight states.  The readable port has to
 * leave the same registers, the same RAM and the same return address as that
 * translation.
 *
 * The port is run twice: once called directly and once through the readable
 * override, which is how the native tick reaches it.
 *
 * The function scales two float constants with the VM's step count and writes
 * the result twice.  The test lays the literal pool, the mode byte, the VM's
 * structure, the count, the two destinations out the way the guest expects.
 * The scenarios cover the mode that asks for a step, the modes that do not,
 * the count above and below the bias and the count that is exactly the bias.
 */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"

#include <stdio.h>
#include <string.h>

int vf3_scale_step_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

#define FRAME_ENTRY 0x0c0cb8acu

/* the caller's return address */
#define RETURN_PC 0x0c0abcdeu

/* the literal pool: the offset, the mode, the VM and the two constants */
#define POOL_BASE 0x0c0cb9b0u
#define POOL_LEN  0x20u
#define G_OFFSET (POOL_BASE + 0x04u)
#define G_MODE   (POOL_BASE + 0x08u)
#define G_VM     (POOL_BASE + 0x0cu)
#define G_ONE    (POOL_BASE + 0x10u)
#define G_TWO    (POOL_BASE + 0x14u)

/* the two constants */
#define CONST_ONE 1.5f
#define CONST_TWO 2.5f

/* the mode byte */
#define MODE_BASE 0x0c140000u
#define MODE_LEN  0x04u

/* the VM's structure: the count and the second destination */
#define VM_BASE 0x0c150000u
#define VM_LEN  0x100u
#define COUNT_PTR (VM_BASE + 0x80u)
#define DEST_PTR  (VM_BASE + 0x90u)

/* the caller's structure: the first destination */
#define OBJ_BASE 0x0c160000u
#define OBJ_LEN  0x40u

/* the shadow layout: one byte array per run, cut into the windows */
#define OFF_POOL 0u
#define OFF_MODE (OFF_POOL + POOL_LEN)
#define OFF_VM   (OFF_MODE + MODE_LEN)
#define OFF_OBJ  (OFF_VM + VM_LEN)
#define SHADOW_LEN (OFF_OBJ + OBJ_LEN)

struct scenario {
    const char *name;
    uint8_t mode;      /* the mode byte */
    int16_t count;     /* the step count */
};

/* one run: its own RAM shadow, its own guest state */
struct run {
    uint8_t shadow[SHADOW_LEN];
    vf3_matrix_state state;
    vf3_ram_win wins[4];
    vf3_ram_map map;
};

static void w16(uint8_t *p, uint32_t off, uint16_t v)
{
    p[off + 0] = (uint8_t)v;
    p[off + 1] = (uint8_t)(v >> 8);
}

static void w32(uint8_t *p, uint32_t off, uint32_t v)
{
    p[off + 0] = (uint8_t)v;
    p[off + 1] = (uint8_t)(v >> 8);
    p[off + 2] = (uint8_t)(v >> 16);
    p[off + 3] = (uint8_t)(v >> 24);
}

static void setup(struct run *r, const struct scenario *sc)
{
    uint8_t *p = r->shadow;
    memset(p, 0, SHADOW_LEN);

    /* the literal pool */
    w16(p + OFF_POOL, G_OFFSET - POOL_BASE, 0x0008u);
    w32(p + OFF_POOL, G_MODE - POOL_BASE, MODE_BASE);
    w32(p + OFF_POOL, G_VM - POOL_BASE, VM_BASE);
    w32(p + OFF_POOL, G_ONE - POOL_BASE, vf3_f32_bits(CONST_ONE));
    w32(p + OFF_POOL, G_TWO - POOL_BASE, vf3_f32_bits(CONST_TWO));

    /* the mode byte */
    p[OFF_MODE] = sc->mode;

    /* the VM's structure: the count and the second destination */
    w32(p + OFF_VM, 0x44u, COUNT_PTR);
    w32(p + OFF_VM, 0x20u, DEST_PTR);
    w16(p + OFF_VM, COUNT_PTR - VM_BASE, (uint16_t)sc->count);

    vf3_matrix_state *s = &r->state;
    memset(s, 0, sizeof *s);
    for (unsigned i = 0; i < 37; ++i) s->v[i] = 0x76543210u + i;
    s->v[4] = OBJ_BASE;
    s->v[15] = 0x0c108000u;
    s->v[16] = RETURN_PC;
    s->v[17] = 0x301u;
    s->v[18] = 0;              /* the FPSCR: the loads are four bytes wide */
    s->budget = 1000000u;

    r->wins[0].data = p + OFF_POOL; r->wins[0].base = POOL_BASE; r->wins[0].len = POOL_LEN;
    r->wins[1].data = p + OFF_MODE; r->wins[1].base = MODE_BASE; r->wins[1].len = MODE_LEN;
    r->wins[2].data = p + OFF_VM;   r->wins[2].base = VM_BASE;   r->wins[2].len = VM_LEN;
    r->wins[3].data = p + OFF_OBJ;  r->wins[3].base = OBJ_BASE;  r->wins[3].len = OBJ_LEN;
    r->map.wins = r->wins;
    r->map.n = 4;
    r->map.oob = 0;
    r->map.device_read = NULL;
    r->map.device_write = NULL;
    r->map.device_context = NULL;
}

static unsigned cases;

static int same(const struct run *a, const struct run *b, const char *what)
{
    if (memcmp(a->state.v, b->state.v, sizeof a->state.v)) {
        for (unsigned i = 0; i < 54; ++i)
            if (a->state.v[i] != b->state.v[i])
                fprintf(stderr, "  %s: v%u %08x != %08x\n", what, i,
                        a->state.v[i], b->state.v[i]);
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

static int compare(const struct scenario *sc)
{
    struct run ref, port, hook;
    setup(&ref, sc);
    setup(&port, sc);
    setup(&hook, sc);

    const int ok_ref = vf3_matrix_family(FRAME_ENTRY, &ref.state, &ref.map);
    const int ok_port = vf3_scale_step_entry(&port.state, &port.map);
    int handled = 0;
    const int ok_hook = vf3_readable_override(FRAME_ENTRY, &hook.state, &hook.map, &handled);

    if (ok_ref != ok_port || ok_ref != ok_hook || !handled ||
        !same(&ref, &port, "port") || !same(&ref, &hook, "hook")) {
        fprintf(stderr, "scale step: %s differs (ok %d/%d/%d)\n",
                sc->name, ok_ref, ok_port, ok_hook);
        return 0;
    }
    /* a case that reads outside the windows passes the differential anyway -
     * both sides read the same uncaptured address - so the out-of-window
     * counter is checked on its own */
    if (ref.map.oob || port.map.oob || hook.map.oob) {
        fprintf(stderr, "scale step: %s reads outside the windows (oob %u/%u/%u)\n",
                sc->name, ref.map.oob, port.map.oob, hook.map.oob);
        return 0;
    }

    ++cases;
    return 1;
}

int main(void)
{
    /* the port has to be registered, or the native tick never reaches it */
    const vf3_readable_entry *reg = vf3_readable_find(FRAME_ENTRY);
    if (!reg || reg->fn != vf3_scale_step_entry) {
        fprintf(stderr, "scale step: the port is not registered\n");
        return 1;
    }
    static const struct scenario scenarios[] = {
        /* the mode is not 1: nothing happens */
        { "no step",      0u, 100 },
        /* the mode is 2: nothing happens */
        { "other mode",   2u, 100 },
        /* the mode byte is masked to four bits, so 17 is 1 */
        { "masked mode", 17u, 100 },
        /* and 9 is not: the four-bit mask keeps it out of the step */
        { "mask keeps nine", 9u, 100 },
        /* a step: the count is above the bias */
        { "step",         1u, 100 },
        /* a step: the count is below the bias and is made positive */
        { "short count",  1u, 50 },
        /* a step: the count is exactly the bias */
        { "bias count",   1u, 60 },
    };
    for (unsigned i = 0; i < sizeof scenarios / sizeof scenarios[0]; ++i)
        if (!compare(&scenarios[i])) return 1;
    printf("scale_step: %u differential cases - PASS\n", cases);
    return 0;
}
