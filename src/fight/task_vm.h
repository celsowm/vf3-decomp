#pragma once
#include <stdint.h>

/* Task-VM struct envelope (docs/re/task_vm.md, M19).
 * r14-based; the 6 hot fields carry the dispatch cycle. */
typedef struct VF3_TaskFields {
    /*0x00*/ uint8_t  state_tag;
    /*0x01*/ uint8_t  hdr_01;
    /*0x02*/ uint16_t hdr_02;
    /*0x04*/ uint32_t frame_stamp;   /* hot rd/wr */
    /*0x08*/ uint32_t scene_slot;
    /*0x0C*/ uint32_t hdr_0C;
    /*0x10*/ uint8_t  task_pad;
    /*0x11*/ uint8_t  sub_slot;
    /*0x12*/ uint16_t strategy_flag;
    /*0x14*/ uint16_t hdr_14;
    /*0x16*/ uint16_t module_tick;   /* hot rd */
    /*0x18*/ uint16_t hdr_18;
    /*0x1A*/ uint16_t hdr_1A;
    /*0x1C*/ uint32_t hdr_1C;
    /*0x20*/ uint32_t strategy_a;
    /*0x24*/ uint32_t strategy_b;
    /*0x28*/ uint32_t packed_pair;
    /*0x2C*/ uint32_t hdr_2C;
    /*0x30*/ uint16_t timer;
    /*0x32*/ uint16_t instr_slot;    /* hot wr */
    /*0x34*/ uint16_t hdr_34;
    /*0x36*/ uint16_t chain_count;
    /*0x38*/ uint32_t hdr_38;
    /*0x3C*/ uint32_t hdr_3C;
    /*0x40*/ uint32_t back_ptr;
    /*0x44*/ uint32_t callback_hook;
    /*0x48*/ uint32_t ring_counter;
    /*0x4C*/ uint16_t hdr_4C;
    /*0x4E*/ uint16_t hdr_4E;
    /*0x50*/ uint16_t hdr_50;
    /*0x52*/ uint16_t part_counter;
    /*0x54*/ uint16_t hdr_54;
    /*0x56*/ uint8_t  stream_tag;
    /*0x57*/ uint8_t  hdr_57;
    /* ... trailing u32s up to 0x600 ... */
} VF3_TaskFields;
