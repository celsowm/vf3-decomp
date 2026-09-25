/* poly_classify.h — quad classification, SH-4 0x8C068FF6. */
#ifndef VF3_FIGHT_POLY_CLASSIFY_H
#define VF3_FIGHT_POLY_CLASSIFY_H

#include <stdint.h>

#include "fight/orient2.h"

typedef struct {
    uint8_t *data;       /* window bytes (writable shadow for replay) */
    uint32_t base;       /* canonical P2 address of data[0] */
    uint32_t len;        /* window length in bytes */
} vf3_ram_win;

typedef struct {
    const vf3_ram_win *wins;
    int n;
    uint32_t oob;        /* out-of-window access counter (replay check) */
} vf3_ram_map;

int vf3_poly_classify(uint32_t r4, uint32_t r3, float fr4, float fr5,
                      const vf3_ram_map *ram);

#endif /* VF3_FIGHT_POLY_CLASSIFY_H */
