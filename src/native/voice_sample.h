/* Decode one bounded AICA ADPCM sample from a VO_* DTPK package. */
#ifndef VF3_NATIVE_VOICE_SAMPLE_H
#define VF3_NATIVE_VOICE_SAMPLE_H

#include <stddef.h>
#include <stdint.h>

/* The VO_* payload descriptors use 16-byte records whose first two words
 * bound contiguous samples in the final DTPK section. The helper validates
 * the whole inferred table before decoding the requested zero-based sample.
 * Returns 0 on success, -1 for invalid arguments, -2 for malformed package
 * or sample bounds, and -3 for allocation failure. The caller owns *pcm. */
int vf3_native_voice_decode_sample(const void *package, uint32_t package_size,
                                   uint32_t sample_index, int16_t **pcm,
                                   size_t *sample_count);

#endif
