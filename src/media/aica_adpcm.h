/* AICA 4-bit ADPCM decoder (clean-room, per docs/formats/DTPK.md codec notes,
 * which mirror the documented AICA/Yamaha hardware algorithm).
 *
 * Stream: low nibble first, then high nibble.
 *   x     = (quant * qmul[nib]) >> 3            (signed via sign bit 3)
 *   signal= clip16(signal + x)
 *   quant = clamp(quant * tquant[nib&7] >> 8, 0x7F, 0x6000)
 * init: signal=0, quant=0x7F
 */
#ifndef VF3_AICA_ADPCM_H
#define VF3_AICA_ADPCM_H

#include <stdint.h>
#include <stddef.h>

typedef struct {
    int32_t signal;
    int32_t quant;
} AicaState;

void    aica_adpcm_init(AicaState *st);
int16_t aica_adpcm_step(AicaState *st, uint8_t nib);
/* Decode entire payload; returns samples written (2 per byte). */
size_t  aica_adpcm_decode(AicaState *st, const uint8_t *src, size_t src_len,
                          int16_t *dst, size_t dst_cap);

#endif
