/* strip_vertex_lit.h - native port of the lit vertex-strip transformer
 * 0x8C048F60 on the `vf3_native_aim` context.
 *
 * See strip_vertex_lit.c and docs/re/native_strip_vertex_lit.md. */
#ifndef VF3_NATIVE_STRIP_VERTEX_LIT_H
#define VF3_NATIVE_STRIP_VERTEX_LIT_H

#include "motion_aim.h"

/* Run 0x8C048F60 (strip_vertex_lit).  A self-contained FP leaf (call-free,
 * no stack frame): it reads a strip of 32-byte vertex records (r4), transforms
 * each vertex through XMTRX, folds its lighting (diffuse + the specular
 * ladder selected by r8) and writes 32-byte store-queue vertex blocks at r6
 * (r5 advancing 32 per vertex).  Runs with FPSCR.SZ = 1 (set on entry,
 * cleared in the rts delay slot) so every FRn load or store moves a pair.
 * Returns 1 on success, 0 on a rejected FPSCR (unsupported / SZ or PR already
 * on) or a malformed ladder selector (r8). */
int vf3_native_strip_vertex_lit(vf3_native_aim *a);

#endif /* VF3_NATIVE_STRIP_VERTEX_LIT_H */
