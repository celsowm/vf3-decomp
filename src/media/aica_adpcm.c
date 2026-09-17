#include "aica_adpcm.h"

/* table-quant constants clamped between 0x7F and 0x6000 */
static const int16_t TABLE_QUANT[8] =
    {230, 230, 230, 230, 307, 409, 512, 614};
static const int8_t QUANT_MUL[16] =
    {1, 3, 5, 7, 9, 11, 13, 15, -1, -3, -5, -7, -9, -11, -13, -15};

void aica_adpcm_init(AicaState *st)
{
    st->signal = 0;
    st->quant = 0x7F;
}

int16_t aica_adpcm_step(AicaState *st, uint8_t nib)
{
    int32_t x = ((int32_t)st->quant * QUANT_MUL[nib]) >> 3;
    st->signal += x;
    if (st->signal > 32767) st->signal = 32767;
    else if (st->signal < -32768) st->signal = -32768;
    st->quant = (st->quant * TABLE_QUANT[nib & 7]) >> 8;
    if (st->quant < 0x7F) st->quant = 0x7F;
    else if (st->quant > 0x6000) st->quant = 0x6000;
    return (int16_t)st->signal;
}

size_t aica_adpcm_decode(AicaState *st, const uint8_t *src, size_t src_len,
                         int16_t *dst, size_t dst_cap)
{
    size_t n = 0;
    for (size_t i = 0; i < src_len && n + 1 < dst_cap; ++i) {
        dst[n++] = aica_adpcm_step(st, src[i] & 0x0F); /* low nibble first */
        dst[n++] = aica_adpcm_step(st, src[i] >> 4);
    }
    return n;
}
