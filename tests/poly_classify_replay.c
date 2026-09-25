/* poly_classify_replay — oracle test for vf3_poly_classify (0x8C068FF6).
 *
 * Reads the .cases file produced by tools/golden_extract.py:
 *   37 in words, 37 out words, ram-file ("-" if none), win1_base win1_len
 *   [win2_base win2_len]
 * The ram file is resolved relative to the cases file's directory. Each
 * case with RAM is replayed through the port and the returned r0 is
 * compared with the recorded exit r0.
 *
 * Usage: vf3poly [cases_file]   (exit 0 = PASS)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fight/poly_classify.h"

#define NVALS 37

static uint32_t parse_u32(const char *s)
{
    return (uint32_t)strtoul(s, NULL, 16);
}

int main(int argc, char **argv)
{
    char path[1024];
    const char *arg = argc > 1 ? argv[1]
                               : "extract/analysis/goldens/f_0c068ff6.cases";
    snprintf(path, sizeof(path), "%s", arg);

    char dir[1024];
    snprintf(dir, sizeof(dir), "%s", path);
    char *slash = strrchr(dir, '/');
    if (!slash)
        slash = strrchr(dir, '\\');
    if (slash)
        *slash = '\0';
    else
        snprintf(dir, sizeof(dir), ".");

    FILE *f = fopen(path, "r");
    if (!f) {
        fprintf(stderr, "poly_classify_replay: cannot open %s\n", path);
        return 2;
    }

    char line[16384];
    int total = 0, pass = 0, skipped = 0;
    while (fgets(line, sizeof(line), f)) {
        char *tok;
        uint32_t in[NVALS], out[NVALS];
        int i, ok = 1;
        for (i = 0, tok = strtok(line, " \t\r\n"); i < NVALS && tok;
             i++, tok = strtok(NULL, " \t\r\n"))
            in[i] = parse_u32(tok);
        if (i != NVALS)
            continue;
        for (i = 0; i < NVALS && tok; i++, tok = strtok(NULL, " \t\r\n"))
            out[i] = parse_u32(tok);
        if (i != NVALS || !tok)
            continue;

        char ramname[256];
        snprintf(ramname, sizeof(ramname), "%s", tok);
        uint32_t wb[2] = {0, 0}, wl[2] = {0, 0};
        for (i = 0; i < 2; i++) {
            tok = strtok(NULL, " \t\r\n");
            if (tok)
                wb[i] = parse_u32(tok);
            tok = strtok(NULL, " \t\r\n");
            if (tok)
                wl[i] = parse_u32(tok);
        }

        uint8_t *bufs[2] = {NULL, NULL};
        vf3_ram_win wins[2];
        int nw = 0;
        if (strcmp(ramname, "-") != 0) {
            char rp[1200];
            snprintf(rp, sizeof(rp), "%s/%s", dir, ramname);
            FILE *rf = fopen(rp, "rb");
            if (!rf) {
                skipped++;
                continue;
            }
            for (i = 0; i < 2; i++) {
                if (wl[i] == 0 || wb[i] == 0)
                    continue;
                bufs[i] = malloc(wl[i]);
                size_t got_n = bufs[i] ? fread(bufs[i], 1, wl[i], rf) : 0;
                if (!bufs[i] || got_n != wl[i]) {
                    free(bufs[i]);
                    bufs[i] = NULL;
                    break;
                }
                wins[nw].data = bufs[i];
                wins[nw].base = wb[i];
                wins[nw].len = wl[i];
                nw++;
            }
            fclose(rf);
            if (nw == 0) {
                skipped++;
                continue;
            }
        } else {
            skipped++;
            continue;
        }

        vf3_ram_map ram = {wins, nw};
        float fr4, fr5;
        uint32_t b4 = in[21 + 4], b5 = in[21 + 5];
        memcpy(&fr4, &b4, 4);
        memcpy(&fr5, &b5, 4);

        int got = vf3_poly_classify(in[4], in[3], fr4, fr5, &ram);
        int want = (int)out[0];
        total++;
        if (got == want)
            pass++;
        else if (total <= 8)
            fprintf(stderr, "  case %d: got %d want %d %s\n",
                    total, got, want, ramname);

        for (i = 0; i < 2; i++)
            free(bufs[i]);
        (void)ok;
    }
    fclose(f);
    if (total == 0) {
        fprintf(stderr, "poly_classify_replay: no RAM cases in %s\n", path);
        return 3;
    }
    printf("poly_classify_replay: %d/%d cases match (%d skipped) - %s\n",
           pass, total, skipped, pass == total ? "PASS" : "FAIL");
    return pass == total ? 0 : 1;
}
