/* record_kind_oracle.c - the readable record kind against the oracle corpus.
 *
 * tests/record_kind_replay.c proves the readable port against the retained
 * generated translation.  This one proves it against the *oracle*: the
 * captured fight states in extract/analysis/goldens_78044/f_0c078044.cases,
 * eight RAM cases over five windows, the same corpus the tree's gap unit
 * src/fight/g78044.c was proved against.
 *
 * The corpus does not hold the literal pool: the pool is the ROM's, not
 * runtime state, so the oracle's RAM capture never carried it.  The test
 * supplies the six words the guest reads - the same values g78044.c bakes
 * in, which its own oracle replay confirmed against these cases.  They are
 * constants of the image, not part of the captured state.
 */
#include "port_harness.h"

#include "fight/matrix_family.h"
#include "fight/readable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_record_kind_entry(vf3_matrix_state *s, const vf3_ram_map *ram);

/* The literal pool window: 0x8C078158..0x8C078178. */
#define POOL_BASE 0x0c078158u
#define POOL_LEN  0x20u

/* The image's pool: the kind offset 0x1BB0 at 0x8C07815A, the state offset
 * 0x1BB2 at 0x8C07815C, the source offset 0x1B83 at 0x8C07815E, the
 * destination offset 0x1BB4 at 0x8C078160, the extra flag bit 0x0100 at
 * 0x8C078162 and the gate mask 0x40000000 at 0x8C07816C. */
static const uint8_t pool[POOL_LEN] = {
    0x00, 0x00, 0xb0, 0x1b, 0xb2, 0x1b, 0x83, 0x1b,   /* +02 kind, +04 state, */
    0xb4, 0x1b, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,   /* +06 source, +08 dest, */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40,   /* +0a extra, +14 gate */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    vf3_matrix_state s;
    uint32_t got[VF3H_NVALS];
    uint8_t *poolbuf;

    memset(&s, 0, sizeof s);
    for (int i = 0; i < VF3H_NVALS; ++i) s.v[i] = c->in[i];
    s.budget = 1000000u;

    /* the literal pool, as a sixth window the guest can read */
    poolbuf = (uint8_t *)malloc(POOL_LEN);
    if (!poolbuf) return 0;
    memcpy(poolbuf, pool, POOL_LEN);
    m->shadow[m->nwin] = poolbuf;          /* the harness frees it */
    m->wins[m->nwin].data = poolbuf;
    m->wins[m->nwin].base = POOL_BASE;
    m->wins[m->nwin].len = POOL_LEN;
    ++m->nwin;
    m->ram.n = m->nwin;

    if (!vf3_record_kind_entry(&s, &m->ram)) {
        snprintf(err, errlen, "the port failed (oob %u)", m->ram.oob);
        return 0;
    }
    if (m->ram.oob) {
        snprintf(err, errlen, "%u out-of-window accesses", m->ram.oob);
        return 0;
    }

    /* the whole register file: the readable port models the guest's traffic
     * in every register it touches, so all thirty-seven are compared */
    for (int i = 0; i < VF3H_NVALS; ++i) got[i] = s.v[i];
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    return vf3h_harness_main(argc, argv, "record_kind_oracle",
                             "extract/analysis/goldens_78044/"
                             "f_0c078044.cases",
                             run_case);
}
