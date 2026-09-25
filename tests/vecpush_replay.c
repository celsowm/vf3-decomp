/* vecpush_replay — piecewise oracle test for vf3_vecpush_sub3_head
 * (SH-4 0x8C071A76 head block, validated at interior point 0x8C071ABE).
 *
 * Reads the paired .cases produced by tools/pair_cases.py:
 *   37 in words, 37 expected-interior words, entry-ram file + its windows,
 *   interior-ram file + its windows.
 * The port runs on a writable shadow of the entry windows; the test then
 * requires (a) the MAIN path, (b) exact register/FPU outputs, and (c) a
 * byte-exact shadow-vs-interior-RAM match over every window (all writes
 * and non-writes), with zero out-of-window accesses.
 *
 * Usage: vf3vecpush [cases_file]   (exit 0 = PASS)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fight/vecpush.h"

#define NVALS 37
#define MAXWIN 8

static unsigned long parse_hex(const char *s)
{
    return strtoul(s, NULL, 16);
}

typedef struct {
    char name[256];
    int nwin;
    uint32_t base[MAXWIN];
    uint32_t len[MAXWIN];
} winlist_t;

int main(int argc, char **argv)
{
    char path[1024];
    const char *arg = argc > 1 ? argv[1]
        : "extract/analysis/goldens_vpb/f_0c071a76_head.cases";
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
        fprintf(stderr, "vecpush_replay: cannot open %s\n", path);
        return 2;
    }

    char line[65536];
    int total = 0, pass = 0, skipped = 0;
    while (fgets(line, sizeof(line), f)) {
        uint32_t in[NVALS], want[NVALS];
        int i;
        winlist_t iw = {{0}, 0}, xw = {{0}, 0};
        char *tok = strtok(line, " \t\r\n");
        for (i = 0; i < NVALS && tok; i++) {
            in[i] = (uint32_t)parse_hex(tok);
            tok = strtok(NULL, " \t\r\n");
        }
        if (i != NVALS || !tok)
            continue;
        for (i = 0; i < NVALS && tok; i++) {
            want[i] = (uint32_t)parse_hex(tok);
            tok = strtok(NULL, " \t\r\n");
        }
        if (i != NVALS || !tok)
            continue;
        snprintf(iw.name, sizeof(iw.name), "%s", tok);
        tok = strtok(NULL, " \t\r\n");
        if (!tok || strcmp(iw.name, "-") == 0) {
            skipped++;
            continue;
        }
        iw.nwin = atoi(tok);
        if (iw.nwin <= 0 || iw.nwin > MAXWIN) {
            skipped++;
            continue;
        }
        for (i = 0; i < iw.nwin; i++) {
            tok = strtok(NULL, " \t\r\n");
            if (tok)
                iw.base[i] = (uint32_t)parse_hex(tok);
            tok = strtok(NULL, " \t\r\n");
            if (tok)
                iw.len[i] = (uint32_t)parse_hex(tok);
        }
        tok = strtok(NULL, " \t\r\n");
        if (!tok || strcmp(tok, "-") == 0) {
            skipped++;
            continue;
        }
        snprintf(xw.name, sizeof(xw.name), "%s", tok);
        tok = strtok(NULL, " \t\r\n");
        if (!tok) {
            skipped++;
            continue;
        }
        xw.nwin = atoi(tok);
        if (xw.nwin <= 0 || xw.nwin > MAXWIN) {
            skipped++;
            continue;
        }
        for (i = 0; i < xw.nwin; i++) {
            tok = strtok(NULL, " \t\r\n");
            if (tok)
                xw.base[i] = (uint32_t)parse_hex(tok);
            tok = strtok(NULL, " \t\r\n");
            if (tok)
                xw.len[i] = (uint32_t)parse_hex(tok);
        }

        /* load entry windows (writable shadow) and interior windows */
        uint8_t *shadow[MAXWIN] = {NULL};
        uint8_t *expect[MAXWIN] = {NULL};
        vf3_ram_win wins[MAXWIN];
        int ok = 1, nw = 0;
        char rp[1200];
        for (i = 0; i < iw.nwin && ok; i++) {
            snprintf(rp, sizeof(rp), "%s/%s", dir, iw.name);
            FILE *rf = i == 0 ? fopen(rp, "rb") : NULL;
            /* entry blob holds all windows concatenated */
            if (i == 0 && !rf)
                ok = 0;
            if (ok && i == 0) {
                long pos = 0;
                int k;
                for (k = 0; k < iw.nwin; k++) {
                    shadow[k] = malloc(iw.len[k]);
                    if (!shadow[k] ||
                        fread(shadow[k], 1, iw.len[k], rf) != iw.len[k])
                        ok = 0;
                    wins[k].data = shadow[k];
                    wins[k].base = iw.base[k];
                    wins[k].len = iw.len[k];
                    pos += iw.len[k];
                    (void)pos;
                }
                fclose(rf);
                nw = iw.nwin;
            }
        }
        if (!ok) {
            for (i = 0; i < MAXWIN; i++)
                free(shadow[i]);
            skipped++;
            continue;
        }
        snprintf(rp, sizeof(rp), "%s/%s", dir, xw.name);
        FILE *xf = fopen(rp, "rb");
        if (!xf) {
            for (i = 0; i < MAXWIN; i++)
                free(shadow[i]);
            skipped++;
            continue;
        }
        for (i = 0; i < xw.nwin && ok; i++) {
            expect[i] = malloc(xw.len[i]);
            if (!expect[i] || fread(expect[i], 1, xw.len[i], xf) != xw.len[i])
                ok = 0;
        }
        fclose(xf);
        if (!ok) {
            for (i = 0; i < MAXWIN; i++) {
                free(shadow[i]);
                free(expect[i]);
            }
            skipped++;
            continue;
        }

        vf3_ram_map ram = {wins, nw, 0};
        float in_fr0;
        memcpy(&in_fr0, &in[21 + 0], 4);
        vf3_vecpush_out o;
        memset(&o, 0, sizeof(o));
        int path = vf3_vecpush_sub3_head(in[4], in[8], in[9], in[11], in[13],
                                         in[14], in[15], in_fr0, &o, &ram);
        total++;
        if (path != VF3_VECPUSH_MAIN) {
            fprintf(stderr, "  case %d: unexpected path %d\n", total, path);
        } else {
            int good = ram.oob == 0;
            int want_r4 = (int)in[13];
            int want_r5 = (int)in[14] + 8;
            int want_r6 = (int)in[11] + 8;
            int want_r8 = (int)in[8] + 24;
            int want_r11 = (int)in[11] + 24;
            int want_r14 = (int)in[11];
            if (o.r4 != (uint32_t)want_r4 || o.r5 != (uint32_t)want_r5 ||
                o.r6 != (uint32_t)want_r6 || o.r8 != (uint32_t)want_r8 ||
                o.r11 != (uint32_t)want_r11 || o.r14 != (uint32_t)want_r14)
                good = 0;
            {
                int k;
                for (k = 0; k < 6 && good; k++) {
                    uint32_t bits;
                    memcpy(&bits, &o.fr[k], 4);
                    if (bits != want[21 + k])
                        good = 0;
                }
            }
            if (in[15] != want[15] || in[9] != want[9] || in[13] != want[13])
                good = 0;
            for (i = 0; i < nw && good; i++)
                if (memcmp(shadow[i], expect[i], wins[i].len) != 0)
                    good = 0;
            if (good)
                pass++;
            else if (total <= 8)
                fprintf(stderr, "  case %d: MISMATCH (oob=%u)\n",
                        total, ram.oob);
        }

        for (i = 0; i < MAXWIN; i++) {
            free(shadow[i]);
            free(expect[i]);
        }
    }
    fclose(f);
    if (total == 0) {
        fprintf(stderr, "vecpush_replay: no RAM cases in %s\n", path);
        return 3;
    }
    printf("vecpush_replay: %d/%d cases match (%d skipped) - %s\n",
           pass, total, skipped, pass == total ? "PASS" : "FAIL");
    return pass == total ? 0 : 1;
}
