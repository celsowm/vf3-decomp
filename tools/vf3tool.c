/* vf3tool - dev CLI for the ported modules.
 *   vf3tool adpcm <out.pcm> <in.bin> [skip]
 * Decodes AICA ADPCM payload -> signed 16-bit LE PCM.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "../src/media/aica_adpcm.h"
#include "../src/media/dtpk.h"

int main(int argc, char **argv)
{
    if (argc >= 4 && !strcmp(argv[1], "adpcm")) {
        const char *out = argv[2], *in = argv[3];
        long skip = argc > 4 ? strtol(argv[4], NULL, 0) : 0;

        FILE *f = fopen(in, "rb");
        if (!f) { perror(in); return 2; }
        fseek(f, 0, SEEK_END);
        long len = ftell(f);
        fseek(f, skip, SEEK_SET);
        uint8_t *buf = malloc(len - skip);
        fread(buf, 1, len - skip, f);
        fclose(f);

        int16_t *pcm = malloc((len - skip) * 2 * sizeof(int16_t));
        AicaState st;
        aica_adpcm_init(&st);
        size_t n = aica_adpcm_decode(&st, buf, len - skip, pcm,
                                     (len - skip) * 2);
        FILE *o = fopen(out, "wb");
        fwrite(pcm, sizeof(int16_t), n, o);
        fclose(o);
        printf("%zu samples\n", n);
        free(buf);
        free(pcm);
        return 0;
    }
    fprintf(stderr, "usage: vf3tool adpcm <out.pcm> <in.bin> [skip]\n");
    return 1;
}
