/* Actor resource registration: apply fixed command-to-field lists to the
 * descriptor's resource pointer table. No opcode decoding is performed. */
#include "fight/matrix_family.h"

typedef struct {
    uint16_t command;
    uint16_t field_offset;
    int16_t index_value; /* -1 keeps R0; nonnegative values set the indexed load. */
    uint32_t return_pc; /* zero denotes the original tail call */
} actor_binding;

static const actor_binding bindings_8c0a3242[] = {
    {0xf1, 0, -1, 0xc0a324eu},
    {0xf2, 64, 64, 0xc0a3256u},
    {0x137, 4, -1, 0xc0a325cu},
    {0x138, 8, -1, 0xc0a3262u},
    {0x139, 60, -1, 0xc0a3268u},
    {0x13a, 36, -1, 0xc0a326eu},
    {0x13b, 40, -1, 0xc0a3274u},
    {0x13c, 44, -1, 0xc0a327au},
    {0x13d, 48, -1, 0xc0a3280u},
    {0x13e, 52, -1, 0xc0a3286u},
    {0x13f, 32, -1, 0xc0a328cu},
    {0x140, 12, -1, 0xc0a3292u},
    {0x141, 16, -1, 0xc0a3298u},
    {0x142, 20, -1, 0xc0a329eu},
    {0x143, 24, -1, 0xc0a32a4u},
    {0x144, 28, -1, 0xc0a32aau},
    {0x149, 56, -1, 0xc0a32b0u},
    {0x148, 68, 68, 0xc0a32b8u},
    {0x100, 72, 72, 0xc0a32c0u},
    {0x102, 76, 76, 0xc0a32c8u},
    {0x103, 80, 80, 0xc0a32d0u},
    {0x104, 84, 84, 0xc0a32d8u},
    {0x106, 88, 88, 0xc0a32e0u},
    {0x107, 92, 92, 0xc0a32e8u},
    {0x108, 96, 96, 0xc0a32f0u},
    {0x109, 100, 100, 0xc0a32f8u},
    {0x10a, 104, 104, 0xc0a3300u},
    {0x10c, 108, 108, 0xc0a3308u},
    {0x10e, 112, 112, 0xc0a3310u},
    {0x10f, 116, 116, 0xc0a3318u},
    {0x110, 120, 120, 0xc0a3320u},
    {0x111, 124, 124, 0xc0a3328u},
    {0x112, 128, 128, 0xc0a3330u},
    {0x114, 132, 132, 0xc0a3338u},
    {0x115, 136, 136, 0xc0a3340u},
    {0x116, 140, 140, 0xc0a3348u},
    {0x117, 144, 144, 0xc0a3350u},
    {0x118, 148, 148, 0xc0a3358u},
    {0x11c, 152, 152, 0xc0a3360u},
    {0x128, 156, 156, 0xc0a33c8u},
    {0x129, 160, 160, 0xc0a33d0u},
    {0x12a, 164, 164, 0xc0a33d8u},
    {0x12b, 168, 168, 0xc0a33e0u},
    {0x12c, 172, 172, 0xc0a33e8u},
    {0x12d, 176, 176, 0xc0a33f0u},
    {0x12e, 180, 180, 0xc0a33f8u},
    {0x145, 184, 184, 0xc0a3400u},
    {0x146, 188, 188, 0xc0a3408u},
    {0x147, 192, 192, 0x0u},
};

static const actor_binding bindings_8c0a3504[] = {
    {0x4, 0, -1, 0xc0a3510u},
    {0x5, 64, 64, 0xc0a3518u},
    {0x5f, 4, -1, 0xc0a351eu},
    {0x60, 8, -1, 0xc0a3524u},
    {0x61, 60, -1, 0xc0a352au},
    {0x62, 36, -1, 0xc0a3530u},
    {0x63, 40, -1, 0xc0a3536u},
    {0x64, 44, -1, 0xc0a353cu},
    {0x65, 48, -1, 0xc0a3542u},
    {0x66, 52, -1, 0xc0a3548u},
    {0x67, 32, -1, 0xc0a354eu},
    {0x68, 12, -1, 0xc0a3554u},
    {0x69, 16, -1, 0xc0a355au},
    {0x6a, 20, -1, 0xc0a3560u},
    {0x6b, 24, -1, 0xc0a3566u},
    {0x6c, 28, -1, 0xc0a356cu},
    {0x72, 56, -1, 0xc0a3572u},
    {0x71, 68, 68, 0xc0a357au},
    {0x16, 72, 72, 0xc0a3582u},
    {0x18, 76, 76, 0xc0a358au},
    {0x19, 80, 80, 0xc0a3592u},
    {0x1a, 84, 84, 0xc0a359au},
    {0x1c, 88, 88, 0xc0a35a2u},
    {0x1d, 92, 92, 0xc0a35aau},
    {0x1e, 96, 96, 0xc0a35b2u},
    {0x1f, 100, 100, 0xc0a35bau},
    {0x20, 104, 104, 0xc0a35c2u},
    {0x22, 108, 108, 0xc0a35cau},
    {0x24, 112, 112, 0xc0a35d2u},
    {0x25, 116, 116, 0xc0a35dau},
    {0x26, 120, 120, 0xc0a35e2u},
    {0x27, 124, 124, 0xc0a35eau},
    {0x28, 128, 128, 0xc0a35f2u},
    {0x2a, 132, 132, 0xc0a35fau},
    {0x2b, 136, 136, 0xc0a3602u},
    {0x2c, 140, 140, 0xc0a360au},
    {0x2d, 144, 144, 0xc0a3612u},
    {0x2e, 148, 148, 0xc0a361au},
    {0x32, 152, 152, 0xc0a3622u},
    {0x42, 156, 156, 0xc0a362au},
    {0x44, 160, 160, 0xc0a3632u},
    {0x46, 164, 164, 0xc0a363au},
    {0x48, 168, 168, 0xc0a3642u},
    {0x4a, 172, 172, 0xc0a364au},
    {0x4c, 176, 176, 0xc0a3652u},
    {0x4e, 180, 180, 0xc0a367au},
    {0x6d, 184, 184, 0xc0a3682u},
    {0x6e, 188, 188, 0xc0a368au},
    {0x6f, 192, 192, 0x0u},
};

static const actor_binding bindings_8c0a38ae[] = {
    {0x1a7, 0, -1, 0xc0a38bau},
    {0x1a8, 64, 64, 0xc0a38c2u},
    {0x1b9, 4, -1, 0xc0a38c8u},
    {0x1ba, 8, -1, 0xc0a38ceu},
    {0x1bb, 60, -1, 0xc0a38d4u},
    {0x1bc, 36, -1, 0xc0a38dau},
    {0x1bd, 40, -1, 0xc0a38e0u},
    {0x1be, 44, -1, 0xc0a38e6u},
    {0x1bf, 48, -1, 0xc0a38ecu},
    {0x1c0, 52, -1, 0xc0a38f2u},
    {0x1c1, 32, -1, 0xc0a38f8u},
    {0x1c2, 12, -1, 0xc0a38feu},
    {0x1c3, 16, -1, 0xc0a3904u},
    {0x1c4, 20, -1, 0xc0a390au},
    {0x1c5, 24, -1, 0xc0a3910u},
    {0x1c6, 28, -1, 0xc0a3916u},
    {0x1c7, 56, -1, 0xc0a391cu},
    {0x1aa, 68, 68, 0xc0a3924u},
    {0x1ab, 72, 72, 0xc0a392cu},
    {0x1ac, 76, 76, 0xc0a3934u},
    {0x1ad, 80, -1, 0x0u},
};

static const actor_binding bindings_8c0a3af2[] = {
    {0x3f3, 0, -1, 0xc0a3afeu},
    {0x3f4, 64, 64, 0xc0a3b06u},
    {0x421, 4, -1, 0xc0a3b0cu},
    {0x422, 8, -1, 0xc0a3b12u},
    {0x423, 60, -1, 0xc0a3b18u},
    {0x424, 36, -1, 0xc0a3b1eu},
    {0x425, 40, -1, 0xc0a3b24u},
    {0x426, 44, -1, 0xc0a3b2au},
    {0x427, 48, -1, 0xc0a3b30u},
    {0x428, 52, -1, 0xc0a3b36u},
    {0x429, 32, -1, 0xc0a3b3cu},
    {0x42a, 12, -1, 0xc0a3b42u},
    {0x42b, 16, -1, 0xc0a3b48u},
    {0x42c, 20, -1, 0xc0a3b4eu},
    {0x42d, 24, -1, 0xc0a3b54u},
    {0x42e, 28, -1, 0xc0a3b5au},
    {0x42f, 56, -1, 0xc0a3b60u},
    {0x401, 68, 68, 0xc0a3b68u},
    {0x40d, 72, 72, 0xc0a3b70u},
    {0x402, 76, 76, 0xc0a3b78u},
    {0x418, 80, 80, 0xc0a3b80u},
    {0x41a, 84, 84, 0xc0a3b88u},
    {0x404, 88, 88, 0xc0a3b90u},
    {0x405, 92, 92, 0xc0a3b98u},
    {0x406, 96, 96, 0xc0a3ba0u},
    {0x407, 100, 100, 0xc0a3ba8u},
    {0x408, 104, 104, 0xc0a3bb0u},
    {0x409, 108, 108, 0xc0a3bb8u},
    {0x40a, 112, 112, 0xc0a3bc0u},
    {0x40b, 116, 116, 0xc0a3bc8u},
    {0x40c, 120, 120, 0xc0a3bd0u},
    {0x40e, 124, 124, 0xc0a3bd8u},
    {0x40f, 128, 128, 0xc0a3be0u},
    {0x410, 132, 132, 0xc0a3be8u},
    {0x411, 136, 136, 0xc0a3bf0u},
    {0x412, 140, 140, 0xc0a3bf8u},
    {0x413, 144, 144, 0xc0a3c00u},
    {0x414, 148, 148, 0xc0a3c08u},
    {0x415, 152, 152, 0xc0a3c10u},
    {0x416, 156, 156, 0xc0a3c78u},
    {0x417, 160, 160, 0xc0a3c80u},
    {0x419, 164, 164, 0x0u},
};

static int register_resource(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    uint32_t *r = s->v;
    unsigned instructions;
    r[3] = 0x0c2a1c3cu;
    r[6] = (r[4] << 2) + r[3];
    r[2] = vf3_matrix_read(ram, r[6], 4);
    r[17] = (r[17] & ~1u) | (r[2] == 0);
    instructions = r[2] ? 9u : 17u;
    if (s->budget < instructions) {
        s->failed_pc = 0x0c0a2e06u;
        return 0;
    }
    s->budget -= instructions;
    if (!r[2]) {
        r[0] = vf3_matrix_read(ram, r[6], 4);
        r[17] = (r[17] & ~1u) | (r[0] == 0xffffffffu);
        if (r[0] != 0xffffffffu) {
            r[0] = vf3_matrix_read(ram, r[5] + 4u, 4);
            r[17] = (r[17] & ~1u) | ((r[0] & 1u) == 0);
            if (r[0] & 1u)
                vf3_matrix_write(ram, r[6], r[5], 4);
            else {
                r[1] = vf3_matrix_read(ram, r[5], 4);
                vf3_matrix_write(ram, r[6], r[1], 4);
            }
        }
    }
    s->pc = r[16];
    return 1;
}

int vf3_actor_table_family_c(uint32_t entry, vf3_matrix_state *s,
                            const vf3_ram_map *ram)
{
    const actor_binding *bindings;
    unsigned count, instructions;
    uint32_t *r = s->v;
    uint32_t object;
    switch (entry) {
    case 0xc0a3242u:
        bindings = bindings_8c0a3242;
        count = sizeof(bindings_8c0a3242) / sizeof(*bindings);
        instructions = 187;
        break;
    case 0xc0a3504u:
        bindings = bindings_8c0a3504;
        count = sizeof(bindings_8c0a3504) / sizeof(*bindings);
        instructions = 187;
        break;
    case 0xc0a38aeu:
        bindings = bindings_8c0a38ae;
        count = sizeof(bindings_8c0a38ae) / sizeof(*bindings);
        instructions = 74;
        break;
    case 0xc0a3af2u:
        bindings = bindings_8c0a3af2;
        count = sizeof(bindings_8c0a3af2) / sizeof(*bindings);
        instructions = 159;
        break;
    default:
        return 0;
    }
    if (s->budget < instructions) {
        s->failed_pc = entry;
        return 0;
    }
    s->budget -= instructions;
    r[15] -= 4u;
    vf3_matrix_write(ram, r[15], r[14], 4);
    object = r[14] = vf3_matrix_read(ram, r[4] + 16u, 4);
    r[15] -= 4u;
    vf3_matrix_write(ram, r[15], r[16], 4);
    for (unsigned i = 0; i < count; ++i) {
        const actor_binding *binding = &bindings[i];
        if (binding->index_value >= 0)
            r[0] = (uint32_t)binding->index_value;
        r[4] = binding->command;
        r[5] = vf3_matrix_read(ram, object + binding->field_offset, 4);
        if (binding->return_pc)
            r[16] = binding->return_pc;
        else {
            r[16] = vf3_matrix_read(ram, r[15], 4);
            r[15] += 4u;
            r[14] = vf3_matrix_read(ram, r[15], 4);
            r[15] += 4u;
        }
        if (!register_resource(s, ram))
            return 0;
    }
    return 1;
}

