/* Readable model of the straight-line table application at 0x8c0a575c.
 * The address/value pairs come from its literal pool and delayed loads.
 * Each setter remains in the already modeled 0x0c0a2e06 helper. */
#include "fight/matrix_family.h"

typedef struct {
    uint16_t command;
    uint16_t field_offset;
    uint32_t return_pc;
} actor_table_call;

static const actor_table_call calls[] = {
    {0x0a16,   0, 0x0c0a5766}, {0x0a17,  64, 0x0c0a5770},
    {0x0a71,   4, 0x0c0a5778}, {0x0a72,   8, 0x0c0a5780},
    {0x0a73,  60, 0x0c0a5788}, {0x0a74,  36, 0x0c0a5790},
    {0x0a75,  40, 0x0c0a5798}, {0x0a76,  44, 0x0c0a57a0},
    {0x0a77,  48, 0x0c0a57a8}, {0x0a78,  52, 0x0c0a57b0},
    {0x0a79,  32, 0x0c0a57b8}, {0x0a7a,  12, 0x0c0a57c0},
    {0x0a7b,  16, 0x0c0a57c8}, {0x0a7c,  20, 0x0c0a57d0},
    {0x0a7d,  24, 0x0c0a57d8}, {0x0a7e,  28, 0x0c0a57e0},
    {0x0a7f,  56, 0x0c0a57e8}, {0x0a2a,  68, 0x0c0a57f2},
    {0x0a2b,  72, 0x0c0a57fc}, {0x0a2c,  76, 0x0c0a5806},
    {0x0a2d,  80, 0x0c0a5810}, {0x0a2e,  84, 0x0c0a581a},
    {0x0a2f,  88, 0x0c0a5824}, {0x0a30,  92, 0x0c0a582e},
    {0x0a31,  96, 0x0c0a5838}, {0x0a32, 100, 0x0c0a5842},
    {0x0a33, 104, 0x0c0a584c}, {0x0a34, 108, 0x0c0a5856},
    {0x0a35, 112, 0x0c0a5860}, {0x0a36, 116, 0x0c0a586a},
    {0x0a37, 120, 0x0c0a5874}, {0x0a38, 124, 0x0c0a587e},
    {0x0a39, 128, 0x0c0a5886}, {0x0a3a, 132, 0x0c0a5892},
    {0x0a3b, 136, 0x0c0a589c}, {0x0a3c, 140, 0x0c0a58a6},
    {0x0a3d, 144, 0x0c0a58b0}, {0x0a3e, 148, 0x0c0a58ba},
    {0x0a3f, 152, 0x0c0a58c4},
    {0x0a40, 156, 0x0c0a5932}, {0x0a41, 160, 0x0c0a593c},
    {0x0a42, 164, 0x0c0a5946}, {0x0a43, 168, 0x0c0a5950},
    {0x0a44, 172, 0x0c0a595a}, {0x0a45, 176, 0x0c0a5964},
    {0x0a5f, 180, 0x0c0a596e}, {0x0a60, 184, 0x0c0a5978},
    {0x0a61, 188, 0x0c0a5982}, {0x0a62, 192, 0x0c0a598c},
    {0x0a64, 196, 0x0c0a5996}, {0x0a65, 200, 0x0c0a59a0},
    {0x0a67, 204, 0x0c0a59aa}, {0x0a68, 208, 0x0c0a59b4},
    {0x0a69, 212, 0x0c0a59be}, {0x0a6a, 216, 0x0c0a59c8},
    {0x0a6b, 220, 0x0c0a59d2}, {0x0a6c, 224, 0x0c0a59dc},
};

int vf3_actor_table_apply_c(vf3_matrix_state *state, const vf3_ram_map *ram)
{
    uint32_t *r = state->v;
    uint32_t object = r[14];
    const uint32_t helper = 0x0c0a2e06u;
    uint32_t saved_pr;

    /* Both discontiguous code spans execute on every invocation. */
    if (state->budget < 279u) {
        state->failed_pc = 0x0c0a575cu;
        return 0;
    }
    state->budget -= 279u;
    r[15] -= 4u;
    vf3_matrix_write(ram, r[15], r[16], 4);

    for (unsigned i = 0; i < sizeof(calls) / sizeof(calls[0]); ++i) {
        /* R0 is explicitly loaded only at indexed field accesses. */
        if (i == 1u || (i >= 17u && i < 39u) || i >= 39u)
            r[0] = calls[i].field_offset;
        r[(i & 1u) ? 2 : 3] = helper;
        r[4] = calls[i].command;
        r[5] = vf3_matrix_read(ram, object + calls[i].field_offset, 4);
        r[16] = calls[i].return_pc;
        if (!vf3_matrix_family(helper, state, ram))
            return 0;
    }

    /* Tail jump to the same helper, which returns to the saved caller PR. */
    r[0] = 0xe4u;
    saved_pr = vf3_matrix_read(ram, r[15], 4);
    r[15] += 4u;
    r[16] = saved_pr;
    r[2] = helper;
    r[5] = vf3_matrix_read(ram, object + r[0], 4);
    r[4] = 0x0a15u;
    r[14] = vf3_matrix_read(ram, r[15], 4);
    r[15] += 4u;
    return vf3_matrix_family(helper, state, ram);
}
