/* word_copy.h - native port of the word copy (0x8C042F08), operating on the
 * `vf3_native_aim` context.
 *
 * See word_copy.c and docs/re/native_word_copy.md. */
#ifndef VF3_NATIVE_WORD_COPY_H
#define VF3_NATIVE_WORD_COPY_H

#include "aim_math.h"

/* Run 0x8C042F08.  Copy r0 bytes (a multiple of 4, at most 64) from r2 to r1,
 * one word at a time.  The original is an unrolled chain entered through a
 * jump table indexed by the byte count; it software-pipelines the copy
 * through two registers (r3 and r0).  r3 is saved to [sp0-4] and restored;
 * r0 ends as the last word loaded into it.  Returns 0 (refuses) when the byte
 * count is not a multiple of 4 or is more than 64.  See
 * docs/re/native_word_copy.md. */
int vf3_native_word_copy(vf3_native_aim *a, uint32_t sp0);

#endif /* VF3_NATIVE_WORD_COPY_H */
