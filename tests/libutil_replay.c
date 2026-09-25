/* tests/libutil_replay.c — M32 leaf-util unit checks. */
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

void  *vf3_memcpy(void *dst, const void *src, size_t n);
int    vf3_memcmp(const void *a, const void *b, size_t n);
int    vf3_memcmp5(const uint8_t *a, const uint8_t *b);
long   vf3_strtol(const char *s, char **end, int base);

static int fails = 0;
#define CHK(c) do { if (!(c)) { printf("  FAIL line %d: %s\n", __LINE__, #c); ++fails; } } while (0)

int main(void)
{
    uint8_t src[64], dst[64];
    for (int i = 0; i < 64; ++i) src[i] = (uint8_t)(i * 7 + 1);
    memset(dst, 0, sizeof dst);
    vf3_memcpy(dst, src, 64);
    CHK(!memcmp(dst, src, 64));
    CHK(vf3_memcmp(dst, src, 64) == 0);
    CHK(vf3_memcmp(dst, src, 63) == 0);
    dst[63] ^= 1;
    CHK(vf3_memcmp(dst, src, 64) != 0);

    static const uint8_t k[5] = {0xAB, 0xCD, 0xEF, 0x01, 0x23};
    CHK(vf3_memcmp5(k, k) == 1);
    uint8_t bad[5]; memcpy(bad, k, 5); bad[4] ^= 1;
    CHK(vf3_memcmp5(k, bad) == 0);
    bad[4] ^= 1; bad[0] ^= 0x80;
    CHK(vf3_memcmp5(k, bad) == 0);

    char *e = NULL;
    CHK(vf3_strtol("  -42xyz", &e, 10) == -42 && *e == 'x');
    CHK(vf3_strtol("0x1F", NULL, 0) == 31);
    CHK(vf3_strtol("777", NULL, 8) == 511);

    printf("libutil_replay: %s\n", fails ? "FAIL" : "PASS");
    return fails ? 1 : 0;
}
