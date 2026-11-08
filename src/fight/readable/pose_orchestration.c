/* pose_orchestration.c - SH-4 0x8C09EAF2: the pose orchestration.
 *
 * r14 -> the actor (set by the caller), r5 -> the caller's argument
 * (kept in r12). The function reserves a 228-byte frame under the saved
 * pr/mac l, snapshots XMTRX into the frame at +0xA4/+0x64/+0x24, then:
 *
 *   seven_pass (0x8C09DA72) and root_orientation (0x8C09D9EA) on the
 *     actor;
 *   matrix_set_translation (0x8C03CBD0) with the pose-vectors base at
 *     actor+0x1EFC;
 *   three xf_store (0x8C03B820) copies of the XF translation into the
 *     frame at +0x94/+0xD4/+0x54;
 *   matrix_push (0x8C03C4F0) with 0;
 *   halfword_frame (0x8C09D4B0) with the field at actor+0x1F56 and the
 *     halfword at actor+0x22E4;
 *   three float sums of the actor's 0x208C/0x1F08, 0x2090/0x1F0C and
 *     0x2094/0x1F10 pairs into the frame at +24/+28/+32, then
 *   unit_triple (0x8C09DC34) on that triple;
 *   store_keep_translation (0x8C09D4E6) and matrix_copy (0x8C03B530)
 *     between the frame's +0xA4 snapshot and actor+0x180;
 *   the kind record's first floats (0x0C10D3C4 + kind*108, r13) into
 *     the frame at +12/+16/+20, two xform_point (0x8C03B450) calls
 *     with the caller's r12 (+12 and +0) as destinations;
 *   matrix_push with 0 again;
 *   the kind==12 table branch: r11 is a code pointer from the table
 *     behind the pool at 0x0C09EC40 (entry +8 when the kind byte at
 *     actor+97 is 12, else the entry at actor byte +0x420B * 4),
 *     then facing_update (0x8C09DCDC) on the actor;
 *   three more kind-record floats (+12/+16/+20) into the frame, an
 *     xform_point, matrix_pop with 1 and matrix_push with 0;
 *   aim_frame (0x8C09E060) twice - with output blocks at actor+0x200
 *     and actor+0x300 - with the stack argument lists the guest builds
 *     at actor+0x640/0x1F62/0x680/0x1F74 and the kind record's +24/+36
 *     triples, each followed by matrix_pop with 1;
 *   kind floats +48..+60 shuffled into the frame at +52..+60, an
 *     xform_point, aim_midpoints (0x8C09E428) and matrix_basis
 *     (0x8C09E4C8) on the actor, matrix_push with 0;
 *   aim_frame_b (0x8C09E6B2) twice - with the object at actor+0x480
 *     and actor+0x540 - the first with its full stack list, each
 *     followed by matrix_pop with 1 and matrix_push with 0;
 *   and the epilogue, which pops macl, pr, r8..r13 and finally r14 in
 *     the rts delay slot.
 *
 * Every pool offset and call target is read from the literal pool at
 * run time. Frame offsets, push order and delay-slot argument
 * adjustments follow the guest exactly - the differential test
 * compares every RAM byte, including the frame the guest leaves behind.
 */
#include <stdio.h>
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/vec3_inline.h"
#include "fight/fr_ops.h"

#define R(n) s->v[(n)]
#define F(n) VF3_FR(s, (n))

/* the literal pool */
#define POOL_FRAME_OFF 0x0c09ebf4u   /* -228, the frame reservation */
#define POOL_IDENTITY  0x0c09ec10u
#define POOL_OFF_A4    0x0c09ebf6u   /* 0xA4 */
#define POOL_STORE     0x0c09ec14u
#define POOL_KIND_TABLE 0x0c09ec18u
#define POOL_SEVEN     0x0c09ec1cu
#define POOL_ROOT      0x0c09ec20u
#define POOL_SET_TRANSL 0x0c09ec24u
#define POOL_VEC_OFF   0x0c09ebf8u   /* 0x1EFC */
#define POOL_XF_OFF1   0x0c09ebfau   /* 0x94 */
#define POOL_XF_OFF2   0x0c09ebfcu   /* 0xD4 */
#define POOL_XF_STORE  0x0c09ec28u
#define POOL_PUSH      0x0c09ec2cu
#define POOL_HALF      0x0c09ec30u
#define POOL_F_OFF1    0x0c09ec00u   /* 0x1F56 */
#define POOL_ACTOR_OFF 0x0c09ebfeu   /* 0x22E4 */
#define POOL_SUM_OFF1  0x0c09ec02u   /* 0x208C */
#define POOL_SUM_OFF2  0x0c09ec04u   /* 0x1F08 */
#define POOL_SUM_OFF3  0x0c09ec06u   /* 0x2090 */
#define POOL_SUM_OFF4  0x0c09ec08u   /* 0x1F0C */
#define POOL_SUM_OFF5  0x0c09ec0au   /* 0x2094 */
#define POOL_SUM_OFF6  0x0c09ec0cu   /* 0x1F10 */
#define POOL_KEEP      0x0c09ec34u
#define POOL_COPY_OFF  0x0c09ec0eu   /* 0x180 */
#define POOL_COPY      0x0c09ec38u
#define POOL_XFORM     0x0c09ec3cu
#define POOL_KIND_TAB2 0x0c09ec40u
#define POOL_POP       0x0c09edf4u
#define POOL_B_OFF1    0x0c09edb8u   /* 0x2098 */
#define POOL_B_OFF2    0x0c09edb4u   /* 0x1F62 */
#define POOL_B_OFF3    0x0c09edb6u   /* 0x1F20 */
#define POOL_B_OFF4    0x0c09edbau   /* 0x640 */
#define POOL_B_OFF5    0x0c09edbcu
#define POOL_B_OFF6    0x0c09edbeu   /* 0xCC */
#define POOL_C_OFF1    0x0c09edc4u   /* 0x20A4 */
#define POOL_C_OFF2    0x0c09edc0u   /* 0x1F74 */
#define POOL_C_OFF3    0x0c09edc2u   /* 0x1F2C */
#define POOL_C_OFF4    0x0c09edc6u   /* 0x680 */
#define POOL_C_OFF5    0x0c09edc8u   /* 0x300 */
#define POOL_C_OFF6    0x0c09edcau   /* 0xFC */
#define POOL_XPT_OFF1  0x0c09edccu   /* 0x9C */
#define POOL_XPT_OFF2  0x0c09edceu   /* 0x8C */
#define POOL_D_OFF1    0x0c09edd2u   /* 0x1F8C */
#define POOL_D_OFF2    0x0c09edd0u   /* 0x138 */
#define POOL_D_OFF3    0x0c09edd8u   /* 0x22E8 */
#define POOL_D_OFF4    0x0c09edd4u   /* 0x6C0 */
#define POOL_D_OFF5    0x0c09edd6u   /* 0x1F38 */
#define POOL_D_OFF6    0x0c09eddau
#define POOL_D_OFF7    0x0c09eddcu   /* 0xA8 */
#define POOL_D_OFF8    0x0c09eddeu   /* 0x20B4 */
#define POOL_D_OFF9    0x0c09ede0u   /* 0x480 */
#define POOL_E_OFF1    0x0c09ede2u   /* 0x15C */
#define POOL_E_OFF2    0x0c09ede8u   /* 0x1F44 */
#define POOL_E_OFF3    0x0c09ede6u   /* 0x740 */
#define POOL_E_OFF4    0x0c09ede4u   /* 0x1F98 */
#define POOL_E_OFF5    0x0c09edeau   /* 0x22EA */
#define POOL_E_OFF6    0x0c09edecu   /* 0x22F8 */
#define POOL_E_OFF7    0x0c09edeeu   /* 0x20C0 */
#define POOL_E_OFF8    0x0c09edf0u   /* 0x540 */
#define POOL_EXIT_OFF  0x0c09ef2au   /* 0x13C */
#define POOL_KIND12_OFF 0x0c09ef1cu  /* actor byte offset for the branch */

/* direct-call targets */
#define AIM_FRAME  0x8C09E060u
#define AIM_MID    0x8C09E428u
#define BASIS      0x8C09E4C8u
#define AIM_FRAME_B 0x8C09E6B2u
#define FACING     0x8C09DCDCu
#define UNIT_TRIPLE 0x8C09DC34u

/* the continuations the guest leaves in pr, in order */
#define CONT_IDENTITY 0x0c09eb00u
#define CONT_STORE1   0x0c09eb08u
#define CONT_STORE2   0x0c09eb0eu
#define CONT_STORE3   0x0c09eb14u
#define CONT_SEVEN    0x0c09eb2cu
#define CONT_ROOT     0x0c09eb32u
#define CONT_TRANSL   0x0c09eb3au
#define CONT_XF1      0x0c09eb42u
#define CONT_XF2      0x0c09eb48u
#define CONT_XF3      0x0c09eb4eu
#define CONT_PUSH1    0x0c09eb54u
#define CONT_HALF     0x0c09eb60u
#define CONT_UNIT     0x0c09eb98u
#define CONT_KEEP     0x0c09eba0u
#define CONT_COPY     0x0c09ebacu
#define CONT_XFORM1   0x0c09ebceu
#define CONT_XFORM2   0x0c09ebe0u
#define CONT_PUSH2    0x0c09ebe4u
#define CONT_FACING   0x0c09ec54u
#define CONT_XFORM3   0x0c09ec76u
#define CONT_POP1     0x0c09ec7cu
#define CONT_PUSH3    0x0c09ec80u
#define CONT_AIM1     0x0c09ecb0u
#define CONT_POP2     0x0c09ecb4u
#define CONT_AIM2     0x0c09ece4u
#define CONT_POP3     0x0c09ece8u
#define CONT_XFORM4   0x0c09ed0au
#define CONT_MID      0x0c09ed12u
#define CONT_BASIS    0x0c09ed1au
#define CONT_PUSH4    0x0c09ed1eu
#define CONT_B1       0x0c09ed62u
#define CONT_POP4     0x0c09ed66u
#define CONT_PUSH5    0x0c09ed6au
#define CONT_B2       0x0c09edfcu
#define CONT_POP5     0x0c09ee00u

static uint32_t pool16(const vf3_ram_map *ram, uint32_t pool_addr)
{
    return (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, pool_addr);
}

static void push_word(vf3_matrix_state *s, const vf3_ram_map *ram, uint32_t v)
{
    R(15) -= 4u;
    vf3_mem_set_u32(ram, R(15), v);
}

int vf3_pose_orchestration_entry(vf3_matrix_state *s, const vf3_ram_map *ram)
{
    const uint32_t sp0 = R(15);
    const uint32_t obj = R(14);

    vf3_mem_set_u32(ram, sp0 - 4u, R(16));
    R(15) = sp0 - 4u;
    vf3_mem_set_u32(ram, R(15) - 4u, R(19));
    R(15) -= 4u;
    R(15) += pool16(ram, POOL_FRAME_OFF);   /* -228 */
    R(12) = R(5);
    if (!vf3_guest_call(s, ram, vf3_mem_u32(ram, POOL_IDENTITY),
                        CONT_IDENTITY)) return 0;

    /* snapshot XMTRX at frame +0xA4, +0x64 and +0x24 */
    R(13) = vf3_mem_u32(ram, POOL_STORE);
    R(4) = pool16(ram, POOL_OFF_A4) + R(15);
    if (!vf3_guest_call(s, ram, R(13), CONT_STORE1)) return 0;
    R(4) = R(15) + 0x64u;
    if (!vf3_guest_call(s, ram, R(13), CONT_STORE2)) return 0;
    R(4) = R(15) + 0x24u;
    if (!vf3_guest_call(s, ram, R(13), CONT_STORE3)) return 0;

    /* the kind record: r13 = table + kind * 108 (MACL carries the product) */
    R(2) = vf3_mem_u32(ram, POOL_KIND_TABLE);
    R(13) = (uint32_t)(int32_t)(int8_t)vf3_mem_u8(ram, obj + 97u) & 0xffu;
    R(19) = (uint32_t)((int32_t)(int16_t)R(13) * (int32_t)108);
    R(13) = (uint32_t)(int32_t)(int16_t)R(19) + R(2);

    R(4) = obj;
    if (!vf3_guest_call(s, ram, vf3_mem_u32(ram, POOL_SEVEN), CONT_SEVEN))
        return 0;
    R(4) = obj;
    if (!vf3_guest_call(s, ram, vf3_mem_u32(ram, POOL_ROOT), CONT_ROOT))
        return 0;

    R(4) = pool16(ram, POOL_VEC_OFF) + obj;
    if (!vf3_guest_call(s, ram, vf3_mem_u32(ram, POOL_SET_TRANSL),
                        CONT_TRANSL)) return 0;

    R(11) = vf3_mem_u32(ram, POOL_XF_STORE);
    R(4) = pool16(ram, POOL_XF_OFF1) + R(15);
    if (!vf3_guest_call(s, ram, R(11), CONT_XF1)) return 0;
    R(4) = pool16(ram, POOL_XF_OFF2) + R(15);
    if (!vf3_guest_call(s, ram, R(11), CONT_XF2)) return 0;
    R(4) = R(15) + 0x54u;
    if (!vf3_guest_call(s, ram, R(11), CONT_XF3)) return 0;

    R(9) = vf3_mem_u32(ram, POOL_PUSH);
    R(4) = 0;
    if (!vf3_guest_call(s, ram, R(9), CONT_PUSH1)) return 0;

    R(0) = pool16(ram, POOL_ACTOR_OFF);
    R(4) = pool16(ram, POOL_F_OFF1) + obj;
    R(5) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, obj + R(0));
    if (!vf3_guest_call(s, ram, vf3_mem_u32(ram, POOL_HALF), CONT_HALF))
        return 0;

    /* three float sums into the frame at +24/+28/+32 */
    R(0) = pool16(ram, POOL_SUM_OFF1);
    R(6) = R(15);
    R(5) = R(15) + 4u;
    F(3) = vf3_mem_u32(ram, obj + R(0));
    R(4) = R(15);
    R(0) = pool16(ram, POOL_SUM_OFF2);
    R(6) += 8u;
    F(2) = vf3_mem_u32(ram, obj + R(0));
    R(0) = 24u;
    FADD(2, 3);
    vf3_mem_set_u32(ram, R(15) + 24u, F(2));
    R(0) = pool16(ram, POOL_SUM_OFF3);
    F(3) = vf3_mem_u32(ram, obj + R(0));
    R(0) = pool16(ram, POOL_SUM_OFF4);
    F(2) = vf3_mem_u32(ram, obj + R(0));
    R(0) = 28u;
    FADD(2, 3);
    vf3_mem_set_u32(ram, R(15) + 28u, F(2));
    R(0) = pool16(ram, POOL_SUM_OFF5);
    F(3) = vf3_mem_u32(ram, obj + R(0));
    R(0) = pool16(ram, POOL_SUM_OFF6);
    F(2) = vf3_mem_u32(ram, obj + R(0));
    R(0) = 32u;
    FADD(2, 3);
    vf3_mem_set_u32(ram, R(15) + 32u, F(2));

    R(4) = R(15) + 24u;
    if (!vf3_guest_call(s, ram, UNIT_TRIPLE, CONT_UNIT)) return 0;

    R(4) = pool16(ram, POOL_OFF_A4) + R(15);
    if (!vf3_guest_call(s, ram, vf3_mem_u32(ram, POOL_KEEP), CONT_KEEP))
        return 0;

    R(5) = pool16(ram, POOL_OFF_A4) + R(15);
    R(4) = pool16(ram, POOL_COPY_OFF) + obj;
    if (!vf3_guest_call(s, ram, vf3_mem_u32(ram, POOL_COPY), CONT_COPY))
        return 0;

    /* kind floats +12/+16/+20 into the frame; two xform_point calls */
    F(3) = vf3_mem_u32(ram, R(13));
    R(5) = R(12);
    R(4) = R(15);
    vf3_mem_set_u32(ram, R(15) + 12u, F(3));
    F(3) = vf3_mem_u32(ram, R(13) + 8u);
    R(5) += 12u;
    vf3_mem_set_u32(ram, R(15) + 16u, F(3));
    F(3) = vf3_mem_u32(ram, R(13) + 4u);
    vf3_mem_set_u32(ram, R(15) + 20u, F(3));
    R(8) = vf3_mem_u32(ram, POOL_XFORM);
    R(4) += 12u;
    if (!vf3_guest_call(s, ram, R(8), CONT_XFORM1)) return 0;
    F(3) = vf3_mem_u32(ram, R(13) + 4u);
    R(4) = R(15);
    R(5) = R(12);
    F(3) ^= SIGN;
    vf3_mem_set_u32(ram, R(15) + 20u, F(3));
    R(4) += 12u;
    if (!vf3_guest_call(s, ram, R(8), CONT_XFORM2)) return 0;

    R(4) = 0;
    if (!vf3_guest_call(s, ram, R(9), CONT_PUSH2)) return 0;

    /* the kind==12 branch: r11 is a code pointer from the table behind
     * the pool at 0x0C09EC40 */
    R(0) = 97u;
    R(4) = vf3_mem_u32(ram, POOL_KIND_TAB2);
    R(0) = vf3_mem_u8(ram, obj + R(0)) & 0xffu;
    R(17) = (R(17) & ~1u) | (R(0) == 12u ? 1u : 0u);
    if (R(0) == 12u) {
        R(11) = vf3_mem_u32(ram, R(4) + 8u);
    } else {
        R(0) = pool16(ram, POOL_KIND12_OFF);
        R(0) = vf3_mem_u8(ram, obj + R(0)) & 0xffu;
        R(0) <<= 2;
        R(11) = vf3_mem_u32(ram, R(4) + R(0));
    }
    R(5) = R(11);
    R(4) = obj;
    if (!vf3_guest_call(s, ram, FACING, CONT_FACING)) return 0;

    F(3) = vf3_mem_u32(ram, R(13) + 12u);
    R(5) = R(12);
    R(4) = R(15);
    R(5) += 24u;
    vf3_mem_set_u32(ram, R(15) + 12u, F(3));
    F(3) = vf3_mem_u32(ram, R(13) + 16u);
    vf3_mem_set_u32(ram, R(15) + 16u, F(3));
    F(3) = vf3_mem_u32(ram, R(13) + 20u);
    vf3_mem_set_u32(ram, R(15) + 20u, F(3));
    R(4) += 12u;
    if (!vf3_guest_call(s, ram, R(8), CONT_XFORM3)) return 0;

    R(10) = vf3_mem_u32(ram, POOL_POP);
    R(4) = 1u;
    if (!vf3_guest_call(s, ram, R(10), CONT_POP1)) return 0;
    R(4) = 0;
    if (!vf3_guest_call(s, ram, R(9), CONT_PUSH3)) return 0;

    /* aim_frame #1: output block at actor+0x200 */
    R(3) = pool16(ram, POOL_B_OFF1) + obj;
    R(2) = R(12) + 36u;
    R(4) = pool16(ram, POOL_B_OFF2) + obj;
    R(7) = pool16(ram, POOL_B_OFF3);
    push_word(s, ram, R(3));
    R(3) = R(13);
    push_word(s, ram, R(2));
    R(3) += 24u;
    push_word(s, ram, R(3));
    push_word(s, ram, R(4));
    R(6) = R(11) + 4u;
    R(2) = pool16(ram, POOL_B_OFF4) + obj;
    R(7) += obj;
    push_word(s, ram, R(2));
    R(5) = pool16(ram, POOL_B_OFF5) + obj;
    R(4) = pool16(ram, POOL_B_OFF6) + obj;
    if (!vf3_guest_call(s, ram, AIM_FRAME, CONT_AIM1)) return 0;
    R(4) = 1u;
    if (!vf3_guest_call(s, ram, R(10), CONT_POP2)) return 0;

    /* aim_frame #2: output block at actor+0x300 */
    R(2) = pool16(ram, POOL_C_OFF1) + obj;
    R(3) = R(12) + 96u;
    R(4) = pool16(ram, POOL_C_OFF2) + obj;
    R(7) = pool16(ram, POOL_C_OFF3);
    push_word(s, ram, R(2));
    R(2) = R(13);
    push_word(s, ram, R(3));
    R(2) += 36u;
    push_word(s, ram, R(2));
    push_word(s, ram, R(4));
    R(6) = R(11) + 24u;
    R(3) = pool16(ram, POOL_C_OFF4) + obj;
    R(7) += obj;
    push_word(s, ram, R(3));
    R(5) = pool16(ram, POOL_C_OFF5) + obj;
    R(4) = pool16(ram, POOL_C_OFF6) + obj;
    if (!vf3_guest_call(s, ram, AIM_FRAME, CONT_AIM2)) return 0;
    R(4) = 1u;
    if (!vf3_guest_call(s, ram, R(10), CONT_POP3)) return 0;

    /* kind floats +48..+60 shuffled into the frame at +52..+60 */
    F(3) = vf3_mem_u32(ram, R(13) + 48u);
    vf3_mem_set_u32(ram, R(15) + 52u, F(3));
    F(3) = vf3_mem_u32(ram, R(13) + 52u);
    vf3_mem_set_u32(ram, R(15) + 56u, F(3));
    F(3) = vf3_mem_u32(ram, R(13) + 56u);
    vf3_mem_set_u32(ram, R(15) + 60u, F(3));
    R(5) = pool16(ram, POOL_XPT_OFF1) + R(12);
    R(4) = R(15) + 52u;
    if (!vf3_guest_call(s, ram, R(8), CONT_XFORM4)) return 0;

    R(5) = pool16(ram, POOL_XPT_OFF2) + R(15);
    R(4) = obj;
    if (!vf3_guest_call(s, ram, AIM_MID, CONT_MID)) return 0;
    R(5) = R(15) + 76u;
    R(4) = obj;
    if (!vf3_guest_call(s, ram, BASIS, CONT_BASIS)) return 0;
    R(4) = 0;
    if (!vf3_guest_call(s, ram, R(9), CONT_PUSH4)) return 0;

    /* aim_frame_b #1: object at actor+0x480 */
    R(3) = pool16(ram, POOL_D_OFF1) + obj;
    R(7) = R(11) + 44u;
    R(5) = pool16(ram, POOL_D_OFF2) + obj;
    vf3_mem_set_u32(ram, R(15) + 40u, R(3));
    R(0) = pool16(ram, POOL_D_OFF3);
    R(4) = pool16(ram, POOL_D_OFF4) + obj;
    R(3) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, obj + R(0));
    R(0) -= 2u;
    R(6) = pool16(ram, POOL_D_OFF5) + obj;
    vf3_mem_set_u16(ram, obj + R(0), (uint16_t)R(3));
    R(2) = pool16(ram, POOL_D_OFF6) + obj;
    push_word(s, ram, R(2));
    R(2) = R(13);
    R(3) = pool16(ram, POOL_D_OFF7) + R(12);
    R(2) += 60u;
    push_word(s, ram, R(3));
    push_word(s, ram, R(2));
    R(3) = vf3_mem_u32(ram, R(15) + 52u);
    push_word(s, ram, R(3));
    push_word(s, ram, R(4));
    push_word(s, ram, R(6));
    R(0) = pool16(ram, POOL_D_OFF8);
    F(4) = vf3_mem_u32(ram, obj + R(0));
    R(6) = pool16(ram, POOL_D_OFF9) + obj;
    R(4) = obj;
    if (!vf3_guest_call(s, ram, AIM_FRAME_B, CONT_B1)) return 0;
    R(4) = 1u;
    if (!vf3_guest_call(s, ram, R(10), CONT_POP4)) return 0;
    R(4) = 0;
    if (!vf3_guest_call(s, ram, R(9), CONT_PUSH5)) return 0;

    /* aim_frame_b #2: object at actor+0x540 */
    R(2) = pool16(ram, POOL_E_OFF2) + obj;
    R(7) = R(11) + 60u;
    R(6) = pool16(ram, POOL_E_OFF3) + obj;
    R(4) = pool16(ram, POOL_E_OFF4) + obj;
    R(5) = pool16(ram, POOL_E_OFF1) + obj;
    vf3_mem_set_u32(ram, R(15) + 64u, R(2));
    R(0) = pool16(ram, POOL_E_OFF5);
    R(3) = (uint32_t)(int32_t)(int16_t)vf3_mem_u16(ram, obj + R(0));
    R(0) -= 4u;
    vf3_mem_set_u16(ram, obj + R(0), (uint16_t)R(3));
    R(2) = pool16(ram, POOL_E_OFF6) + obj;
    push_word(s, ram, R(2));
    R(2) = R(13);
    R(3) = pool16(ram, POOL_C_OFF6) + R(12);
    R(2) += 84u;
    push_word(s, ram, R(3));
    push_word(s, ram, R(2));
    push_word(s, ram, R(4));
    push_word(s, ram, R(6));
    R(3) = vf3_mem_u32(ram, R(15) + 84u);
    push_word(s, ram, R(3));
    R(0) = pool16(ram, POOL_E_OFF7);
    F(4) = vf3_mem_u32(ram, obj + R(0));
    R(6) = pool16(ram, POOL_E_OFF8) + obj;
    R(4) = obj;
    if (!vf3_guest_call(s, ram, AIM_FRAME_B, CONT_B2)) return 0;
    R(4) = 1u;
    if (!vf3_guest_call(s, ram, R(10), CONT_POP5)) return 0;

    /* the epilogue: pops macl, pr, r8..r13 and finally r14 */
    R(1) = pool16(ram, POOL_EXIT_OFF);
    R(15) += R(1);
    R(19) = vf3_mem_u32(ram, R(15));
    R(15) += 4u;
    R(16) = vf3_mem_u32(ram, R(15));
    R(15) += 4u;
    for (unsigned r = 8; r <= 13; ++r) {
        R(r) = vf3_mem_u32(ram, R(15));
        R(15) += 4u;
    }
    R(14) = vf3_mem_u32(ram, R(15));
    R(15) += 4u;
    s->pc = R(16);
    return ram->oob == 0;
}
