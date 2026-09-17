/* DTPK container loader (clean-room, from docs/formats/DTPK.md).
 * Dreamcast-era AM2 "Data TransPacK" used for all VF3tb audio packs.
 */
#ifndef VF3_DTPK_H
#define VF3_DTPK_H

#include <stddef.h>
#include <stdint.h>

#define DTPK_MAGIC 0x4B505444u /* "DTPK" */
#define DTPK_MAX_SECTIONS 16

typedef struct dtpk_section {
    uint32_t offset; /* absolute offset into the container */
    uint32_t size;   /* byte size of section */
} DtpkSection;

typedef struct dtpk {
    uint32_t serial;  /* production-list ordinal */
    uint32_t size;    /* expected total size */
    uint32_t tag;     /* group classifier */
    int      nsections;
    DtpkSection sections[DTPK_MAX_SECTIONS];
    const uint8_t *data; /* borrowed; parse only keeps a view */
    uint32_t data_size;
} Dtpk;

/* Validate + parse header. Returns 0 on success. No allocation. */
int  dtpk_parse(const void *data, uint32_t size, Dtpk *out);
/* Get i-th section (0 if missing). */
int  dtpk_get(const Dtpk *p, int index, const uint8_t **ptr, uint32_t *size);

#endif
