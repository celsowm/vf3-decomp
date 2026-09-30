#ifndef VF3_MATRIX_FAMILY_H
#define VF3_MATRIX_FAMILY_H
#include "fight/poly_classify.h"
typedef struct { uint32_t v[54]; uint32_t pc, failed_pc, gbr; unsigned budget, gbr_known; } vf3_matrix_state;
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
#endif
