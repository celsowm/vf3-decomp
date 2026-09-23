/* fight/task_vm.c — task struct port, r14-based.
 *
 * Traceable to tools/task_vm_map.py output (extract/analysis/task_vm_map.csv,
 * 1,196 r14-window sites over the task/fight dispatch regions of 1ST_READ).
 *
 * The struct itself is position-independent: r14 is hand-fed at call sides
 * (cand_sd_slot_lookup's arg is the task struct base, e.g. 0x0CBEFBE0
 * during the fight attract scene). The named fields below are the union of
 * observed offsets, grouped per the ruled topology in docs/re/task_vm.md.
 */
#include "task_vm.h"

/* The task VM runs selectors; the trace log shows the code dispatches 8
 * helper calls per frame (task_runner pattern) using wasm-friendly slots.
 * Only the names and offsets are authoritative here. */
const char *vf3_task_field_name(uint32_t off)
{
    switch (off) {
    case 0x00: return "state_tag";
    case 0x04: return "frame_stamp";
    case 0x08: return "scene_slot";
    case 0x10: return "task_id_pad";
    case 0x11: return "sub_slot";
    case 0x12: return "strategy_flag";
    case 0x16: return "module_tick";
    case 0x20: return "strategy_a";
    case 0x24: return "strategy_b";
    case 0x28: return "packed_pair";
    case 0x30: return "timer";
    case 0x32: return "instr_slot";
    case 0x36: return "chain_count";
    case 0x40: return "back_ptr";
    case 0x44: return "callback_hook";
    case 0x48: return "ring_counter";
    case 0x52: return "part_counter";
    case 0x56: return "stream_tag";
    default:   return "hdr_spare";
    }
}

/* one-time self-check: struct size does not cover the model well if >0x58 */
_Static_assert(sizeof(VF3_TaskFields) <= 0x58, "task_fields size");
