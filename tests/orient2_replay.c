/* orient2_replay — golden-vector test for vf3_orient2_bits (0x8C068F92).
 *
 * Reads the 37-word entry / 37-word exit golden snapshot lines produced by
 * tools/golden_extract.py (r0-r15, pr, sr, fpscr, macl, mach, fr0-fr15),
 * feeds fr4..fr9 through the port, and requires the returned r0 to match
 * every sample.
 *
 * Usage: vf3orient2 [golden.txt]   (exit 0 = PASS)
 */
#include <stdio.h>
#include <string.h>

#include "fight/orient2.h"

#define NVALS 37
#define FR(i) (21 + (i))

static int hex32(const char *s, unsigned long *out)
{
    return sscanf(s, "%lx", out) == 1;
}

int main(int argc, char **argv)
{
    const char *path = argc > 1 ? argv[1]
                                : "extract/analysis/goldens/f_0c068f92.txt";
    FILE *f = fopen(path, "r");
    if (!f) {
        fprintf(stderr, "orient2_replay: cannot open %s\n", path);
        return 2;
    }

    char line[8192];
    int total = 0, pass = 0, line_no = 0;
    while (fgets(line, sizeof(line), f)) {
        unsigned long in[NVALS], out[NVALS];
        char *p = line;
        int i, ok = 1;
        line_no++;
        for (i = 0; i < NVALS && ok; i++) {
            char *tok = strtok(i == 0 ? p : NULL, " \t\r\n");
            ok = tok && hex32(tok, &in[i]);
        }
        for (i = 0; i < NVALS && ok; i++) {
            char *tok = strtok(NULL, " \t\r\n");
            ok = tok && hex32(tok, &out[i]);
        }
        if (!ok)
            continue; /* header/short line */

        float fr[16];
        for (i = 0; i < 16; i++) {
            unsigned long b = in[FR(i)];
            memcpy(&fr[i], &b, sizeof(float));
        }
        int want = (int)out[0];
        int got = vf3_orient2_bits(fr[4], fr[5], fr[6],
                                   fr[7], fr[8], fr[9]);
        total++;
        if (got == want)
            pass++;
        else if (pass + 1 == total && total < 8)
            fprintf(stderr, "  sample %d: got %d want %d (line %d)\n",
                    total, got, want, line_no);
    }
    fclose(f);
    if (total == 0) {
        fprintf(stderr, "orient2_replay: no vectors in %s\n", path);
        return 3;
    }
    printf("orient2_replay: %d/%d samples match%s\n", pass, total,
           pass == total ? " - PASS" : " - FAIL");
    return pass == total ? 0 : 1;
}
