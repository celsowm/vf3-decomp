/* Decode the uncompressed PVR texture forms used by POL descriptors. */
#ifndef VF3_PVR_TEXTURE_H
#define VF3_PVR_TEXTURE_H

#include <stddef.h>
#include <stdint.h>

#include "pol.h"

/* Decode one descriptor from its companion TEX payload to 0xAARRGGBB pixels.
 * Returns 0 on success, -1 for unsupported format or invalid bounds, and -2
 * when the caller's pixel buffer is too small. */
int vf3_pvr_texture_payload_size(const PolTextureDesc *desc, size_t *bytes_out);
int vf3_pvr_texture_decode(const void *tex_data, size_t tex_size,
                           const PolTextureDesc *desc, uint32_t *argb_out,
                           size_t pixel_capacity);

#endif
