#ifndef VF3_FIGHT_SH4_MATRIX_H
#define VF3_FIGHT_SH4_MATRIX_H

#include <stdint.h>

#define VF3_SH4_NREGS 37
#define VF3_SH4_NXF 16

#include "fight/poly_classify.h" /* vf3_ram_map */

/* Captured SH-4 matrix-helper boundaries. Return zero for unobserved FSCA
 * angle inputs; these entry points intentionally fail closed outside the
 * coefficient catalog in fsca_angles.inc. */
int vf3_sh4_c940(const uint32_t in[VF3_SH4_NREGS],
                 uint32_t out[VF3_SH4_NREGS],
                 const uint32_t xf_in[VF3_SH4_NXF],
                 uint32_t xf_out[VF3_SH4_NXF]);
int vf3_sh4_c880(const uint32_t in[VF3_SH4_NREGS],
                 uint32_t out[VF3_SH4_NREGS],
                 const uint32_t xf_in[VF3_SH4_NXF],
                 uint32_t xf_out[VF3_SH4_NXF]);
int vf3_sh4_c6c0(const uint32_t in[VF3_SH4_NREGS],
                 uint32_t out[VF3_SH4_NREGS],
                 const uint32_t xf_in[VF3_SH4_NXF],
                 uint32_t xf_out[VF3_SH4_NXF]);
int vf3_sh4_d452(const uint32_t in[VF3_SH4_NREGS],
                 uint32_t out[VF3_SH4_NREGS],
                 const uint32_t xf_in[VF3_SH4_NXF],
                 uint32_t xf_out[VF3_SH4_NXF],
                 const vf3_ram_map *ram);

/* 0x8C0955B0 through its tail-transfer boundary at 0x8C095600. */
int vf3_sh4_0955b0(const uint32_t in[VF3_SH4_NREGS],
                   uint32_t out[VF3_SH4_NREGS],
                   const uint32_t xf_in[VF3_SH4_NXF],
                   uint32_t xf_out[VF3_SH4_NXF],
                   const vf3_ram_map *ram);
int vf3_sh4_0955b0_step(const uint32_t in[VF3_SH4_NREGS],
                        uint32_t out[VF3_SH4_NREGS],
                        const uint32_t xf_in[VF3_SH4_NXF],
                        uint32_t xf_out[VF3_SH4_NXF],
                        const vf3_ram_map *ram, unsigned step);

#endif
