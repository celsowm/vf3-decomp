#ifndef VF3_SH4_FPU_H
#define VF3_SH4_FPU_H
#include <stdint.h>
/* Single-precision SH-4 operations under FPSCR.RM=0/1. Results agree with
 * the local interpreter oracle. PR=1 and reserved RM values are rejected. */
int vf3_fpu_supported(uint32_t fpscr);
void vf3_fpu_fsca(uint32_t angle, uint32_t result[2]);
int vf3_fpu_fsrra(uint32_t value, uint32_t fpscr, uint32_t *result);
int vf3_fpu_fipr(const uint32_t a[4], const uint32_t b[4], uint32_t fpscr, uint32_t *result);
int vf3_fpu_ftrv(const uint32_t matrix[16], const uint32_t vector[4], uint32_t fpscr, uint32_t result[4]);
uint32_t vf3_fpu_binary(uint32_t a,uint32_t b,uint32_t fpscr,char operation);
uint32_t vf3_fpu_sqrt(uint32_t a,uint32_t fpscr);
uint32_t vf3_fpu_float(uint32_t value,uint32_t fpscr);
uint32_t vf3_fpu_ftrc(uint32_t value);
uint32_t vf3_fpu_mac(uint32_t a,uint32_t b,uint32_t c,uint32_t fpscr);
#endif
