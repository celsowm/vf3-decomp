#ifndef VF3_MATRIX_FAMILY_H
#define VF3_MATRIX_FAMILY_H
#include "fight/poly_classify.h"
typedef struct { uint32_t v[54]; uint32_t pc, failed_pc, gbr, bank[8]; unsigned budget, gbr_known, bank_known; } vf3_matrix_state;
/* Complete helper semantics, with guest state isolated in this adapter.
 * State layout is the existing 37 words, XF[16], then FPUL. */
int vf3_matrix_family(uint32_t entry,vf3_matrix_state *state,const vf3_ram_map *ram);
/* Shared ABI mechanics for statically translated callers. */
uint32_t vf3_matrix_read(const vf3_ram_map*,uint32_t,unsigned);
void vf3_matrix_write(const vf3_ram_map*,uint32_t,uint32_t,unsigned);
void vf3_matrix_load(vf3_matrix_state*,const vf3_ram_map*,unsigned,uint32_t);
void vf3_matrix_store(vf3_matrix_state*,const vf3_ram_map*,unsigned,uint32_t);
void vf3_matrix_move(vf3_matrix_state*,unsigned,unsigned);
void vf3_matrix_swap(vf3_matrix_state*);
int vf3_matrix_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_fight_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_fight_adapter_contains(uint32_t);
int vf3_motion_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_motion_adapter_contains(uint32_t);
int vf3_next_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_next_adapter_contains(uint32_t);
int vf3_fifth_leaf_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_fifth_leaf_adapter_contains(uint32_t);
int vf3_fifth_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_fifth_adapter_contains(uint32_t);
int vf3_sixth_loader_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_sixth_loader_adapter_contains(uint32_t);
int vf3_seventh_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_seventh_adapter_contains(uint32_t);
int vf3_seventh_c_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_seventh_c_adapter_contains(uint32_t);
int vf3_seventh_c3_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_seventh_c3_adapter_contains(uint32_t);
int vf3_seventh_c4_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_seventh_c4_adapter_contains(uint32_t);
int vf3_seventh_c5_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_seventh_c5_adapter_contains(uint32_t);
int vf3_seventh_c6_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_seventh_c6_adapter_contains(uint32_t);
int vf3_seventh_c7_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_seventh_c7_adapter_contains(uint32_t);
int vf3_seventh_c8_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_seventh_c8_adapter_contains(uint32_t);
int vf3_seventh_c9_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_seventh_c9_adapter_contains(uint32_t);
int vf3_seventh_c10_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_seventh_c10_adapter_contains(uint32_t);
int vf3_seventh_c11_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_seventh_c11_adapter_contains(uint32_t);
int vf3_seventh_c12_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_seventh_c12_adapter_contains(uint32_t);
int vf3_seventh_c13_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_seventh_c13_adapter_contains(uint32_t);
int vf3_seventh_c14_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_seventh_c14_adapter_contains(uint32_t);
int vf3_eighth_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_eighth_adapter_contains(uint32_t);
int vf3_phase1_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_phase1_adapter_contains(uint32_t);
int vf3_phase2_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_phase2_adapter_contains(uint32_t);
int vf3_device_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_device_adapter_contains(uint32_t);
int vf3_motion_final_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_motion_final_adapter_contains(uint32_t);
int vf3_fifth_leaf_unowned_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_fifth_leaf_unowned_adapter_contains(uint32_t);
int vf3_motion_unowned_extra_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_motion_unowned_extra_adapter_contains(uint32_t);
int vf3_fifth_leaf_extra_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_fifth_leaf_extra_adapter_contains(uint32_t);
int vf3_ultimate_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_ultimate_adapter_contains(uint32_t);
int vf3_motion_record_init(vf3_matrix_state*,const vf3_ram_map*);
int vf3_fight_angle(vf3_matrix_state*,const vf3_ram_map*);
int vf3_fight_mesh(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
#endif
