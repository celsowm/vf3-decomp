/* lib/sh4rt.c — Hitachi SHC / sh4nlfzz runtime leaves (M32)
 *
 * Names + addresses attributed by M30 masked byte match against the SDK
 * corpus (extract/analysis/libmask_matches.csv). Semantics per ISO/SHC
 * runtime; ported to portable C with unit tests (tests/libutil_replay.c).
 *
 *   0x8c043018 memcpy          (sh4nlfzz memcpy module, 74 B match)
 *   0x8c042fdc memcmp/_umemcmp (60 B match)
 *   0x8c03f5b2 strtol          (strtol module hit inside, 24 B probe)
 *   0x8c03482a memcmp5         (custom 5-byte equal -> 1; hottest fn in
 *                               boot trace, 7.3M hits; verified 2026-09-24
 *                               against true-image disasm)
 */
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

void *vf3_memcpy(void *dst, const void *src, size_t n)
{
    return memcpy(dst, src, n);
}

int vf3_memcmp(const void *a, const void *b, size_t n)
{
    return memcmp(a, b, n);
}

/* 0x8c03482a: cmp/eq loop over 5 bytes; returns 1 when equal, 0 when not.
 * Args arrive in r6/r7 (mid-function custom link). */
int vf3_memcmp5(const uint8_t *a, const uint8_t *b)
{
    for (int i = 0; i < 5; ++i)
        if (a[i] != b[i])
            return 0;
    return 1;
}

long vf3_strtol(const char *s, char **end, int base)
{
    return strtol(s, end, base);
}
