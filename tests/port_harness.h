/* port_harness.h — shared oracle .cases runner for VF3 port replay tests.
 *
 * Loads .cases lines (either the v2 format written by golden_extract.py /
 * pair_cases.py: in*37 out*37 entryram nwin [base len]* exitram nwin
 * [base len]*, or the legacy fixed-2-window format), materializes writable
 * memory shadows for the RAM windows, calls a per-port callback, and
 * checks registers / whole-window byte-exact memory.
 *
 * A port test becomes:
 *   static int run_case(const vf3_case *c, vf3_harness_mem *m,
 *                       char *err, size_t errlen) { ... return ok; }
 *   int main(int argc, char **argv) {
 *       return vf3_harness_main(argc, argv, "myport", DEF, run_case);
 *   }
 */
#ifndef VF3_PORT_HARNESS_H
#define VF3_PORT_HARNESS_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fight/poly_classify.h"   /* vf3_ram_win / vf3_ram_map */

#define VF3H_NVALS 37
#define VF3H_MAXWIN 8

typedef struct {
    uint32_t in[VF3H_NVALS];
    uint32_t out[VF3H_NVALS];
    char entry[256];
    int nentry;
    uint32_t ebase[VF3H_MAXWIN];
    uint32_t elen[VF3H_MAXWIN];
    char xexit[256];
    int nexit;
    uint32_t xbase[VF3H_MAXWIN];
    uint32_t xlen[VF3H_MAXWIN];
} vf3_case;

typedef struct {
    uint8_t *shadow[VF3H_MAXWIN];
    uint8_t *expect[VF3H_MAXWIN];
    vf3_ram_win wins[VF3H_MAXWIN];
    vf3_ram_map ram;
    int nwin;
    int ncase;              /* case ordinal (1-based) for messages */
} vf3_harness_mem;

typedef int (*vf3_case_fn)(const vf3_case *c, vf3_harness_mem *m,
                           char *err, size_t errlen);

static unsigned long vf3h_parse_hex(const char *s)
{
    return strtoul(s, NULL, 16);
}

static void vf3h_dirname(char *dir, size_t n, const char *path)
{
    snprintf(dir, n, "%s", path);
    char *slash = strrchr(dir, '/');
    if (!slash)
        slash = strrchr(dir, '\\');
    if (slash)
        *slash = '\0';
    else
        snprintf(dir, n, ".");
}

/* Parse a window descriptor after a name token.  Legacy lines start with
 * "0x"-prefixed addresses; v2 lines start with a bare decimal count. */
static int vf3h_parse_wins(char **ptok, const char *name, int *pn,
                           uint32_t *base, uint32_t *len)
{
    char *tok = *ptok;
    int n = 0;
    if (!tok)
        return 0;
    if (strncmp(tok, "0x", 2) == 0 || strncmp(tok, "-", 1) == 0) {
        /* legacy: always two (base,len) pairs */
        n = 2;
        for (int i = 0; i < 2; i++) {
            base[i] = (uint32_t)vf3h_parse_hex(tok);
            tok = strtok(NULL, " \t\r\n");
            if (!tok)
                return 0;
            len[i] = (uint32_t)vf3h_parse_hex(tok);
            tok = strtok(NULL, " \t\r\n");
        }
    } else {
        n = atoi(tok);
        if (n < 0 || n > VF3H_MAXWIN)
            return 0;
        tok = strtok(NULL, " \t\r\n");
        for (int i = 0; i < n; i++) {
            if (!tok)
                return 0;
            base[i] = (uint32_t)vf3h_parse_hex(tok);
            tok = strtok(NULL, " \t\r\n");
            if (!tok)
                return 0;
            len[i] = (uint32_t)vf3h_parse_hex(tok);
            tok = strtok(NULL, " \t\r\n");
        }
    }
    /* drop zero-length/zero-base entries (legacy padding) */
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (len[i] != 0 && base[i] != 0) {
            base[k] = base[i];
            len[k] = len[i];
            k++;
        }
    }
    *pn = k;
    if (strcmp(name, "-") != 0 && k == 0)
        return 0;                    /* named blob but no windows */
    *ptok = tok;
    return 1;
}

static int vf3h_case_parse(vf3_case *c, char *line)
{
    char *tok = strtok(line, " \t\r\n");
    int i;
    for (i = 0; i < VF3H_NVALS && tok; i++) {
        c->in[i] = (uint32_t)vf3h_parse_hex(tok);
        tok = strtok(NULL, " \t\r\n");
    }
    if (i != VF3H_NVALS || !tok)
        return 0;
    for (i = 0; i < VF3H_NVALS && tok; i++) {
        c->out[i] = (uint32_t)vf3h_parse_hex(tok);
        tok = strtok(NULL, " \t\r\n");
    }
    if (i != VF3H_NVALS || !tok)
        return 0;
    snprintf(c->entry, sizeof(c->entry), "%s", tok);
    tok = strtok(NULL, " \t\r\n");
    if (strcmp(c->entry, "-") == 0) {
        /* no entry blob: still consume window fields */
        if (!vf3h_parse_wins(&tok, c->entry, &c->nentry,
                             c->ebase, c->elen))
            return 0;
    } else {
        if (!vf3h_parse_wins(&tok, c->entry, &c->nentry,
                             c->ebase, c->elen))
            return 0;
    }
    if (!tok)
        return 0;
    snprintf(c->xexit, sizeof(c->xexit), "%s", tok);
    tok = strtok(NULL, " \t\r\n");
    if (!vf3h_parse_wins(&tok, c->xexit, &c->nexit, c->xbase, c->xlen))
        return 0;
    return 1;
}

static int vf3h_read_blob(const char *dir, const char *name,
                          const uint32_t *base, const uint32_t *len, int n,
                          uint8_t *out[VF3H_MAXWIN])
{
    char rp[1400];
    snprintf(rp, sizeof(rp), "%s/%s", dir, name);
    FILE *f = fopen(rp, "rb");
    if (!f)
        return 0;
    for (int i = 0; i < n; i++) {
        out[i] = (uint8_t *)malloc(len[i] ? len[i] : 1);
        if (!out[i] || fread(out[i], 1, len[i], f) != len[i]) {
            fclose(f);
            return 0;
        }
    }
    fclose(f);
    return 1;
}

static void vf3h_mem_free(vf3_harness_mem *m)
{
    for (int i = 0; i < VF3H_MAXWIN; i++) {
        free(m->shadow[i]);
        free(m->expect[i]);
        m->shadow[i] = NULL;
        m->expect[i] = NULL;
    }
    m->nwin = 0;
}

/* Load entry shadows and expected exit windows; 1 on success.  Exit RAM is
 * optional: when the golden has none, only oob is checked (register-level
 * replay), matching pre-tranche-2 captures. */
static int vf3h_mem_load(vf3_harness_mem *m, const char *dir,
                         const vf3_case *c)
{
    memset(m, 0, sizeof(*m));
    if (strcmp(c->entry, "-") == 0 || c->nentry == 0)
        return 0;
    if (!vf3h_read_blob(dir, c->entry, c->ebase, c->elen, c->nentry,
                        m->shadow))
        return 0;
    if (strcmp(c->xexit, "-") != 0 && c->nexit > 0) {
        if (c->nentry != c->nexit) {
            vf3h_mem_free(m);
            return 0;
        }
        if (!vf3h_read_blob(dir, c->xexit, c->xbase, c->xlen, c->nexit,
                            m->expect)) {
            vf3h_mem_free(m);
            return 0;
        }
        for (int i = 0; i < c->nexit; i++) {
            if (c->ebase[i] != c->xbase[i] || c->elen[i] != c->xlen[i]) {
                vf3h_mem_free(m);
                return 0;
            }
        }
    }
    for (int i = 0; i < c->nentry; i++) {
        m->wins[i].data = m->shadow[i];
        m->wins[i].base = c->ebase[i];
        m->wins[i].len = c->elen[i];
    }
    m->nwin = c->nentry;
    m->ram.wins = m->wins;
    m->ram.n = m->nwin;
    m->ram.oob = 0;
    return 1;
}

/* r4-r15 / pr / fpscr / fr0-fr15 (index 4..36) compare + r0 compare. */
static int vf3h_regs_ok(const vf3_case *c, const uint32_t *got,
                        char *err, size_t errlen)
{
    static const char *names[VF3H_NVALS] = {
        "r0","r1","r2","r3","r4","r5","r6","r7","r8","r9","r10","r11",
        "r12","r13","r14","r15","pr","sr","fpscr","macl","mach",
        "fr0","fr1","fr2","fr3","fr4","fr5","fr6","fr7","fr8","fr9",
        "fr10","fr11","fr12","fr13","fr14","fr15" };
    for (int i = 0; i < VF3H_NVALS; i++) {
        if (got[i] != c->out[i]) {
            snprintf(err, errlen, "reg %s: got %08x want %08x",
                     names[i], got[i], c->out[i]);
            return 0;
        }
    }
    return 1;
}

/* Byte-exact shadow vs expected exit RAM, plus zero out-of-window. */
static int vf3h_mem_ok(const vf3_harness_mem *m, char *err, size_t errlen)
{
    if (m->ram.oob != 0) {
        snprintf(err, errlen, "%u out-of-window accesses", m->ram.oob);
        return 0;
    }
    for (int i = 0; i < m->nwin; i++) {
        if (m->expect[i] == NULL)
            continue;                /* no exit-RAM golden for this case */
        if (memcmp(m->shadow[i], m->expect[i], m->wins[i].len) != 0) {
            for (uint32_t k = 0; k < m->wins[i].len; k++) {
                if (m->shadow[i][k] != m->expect[i][k]) {
                    snprintf(err, errlen,
                             "mem win%d @+0x%x: got %02x want %02x",
                             i, k, m->shadow[i][k], m->expect[i][k]);
                    break;
                }
            }
            return 0;
        }
    }
    return 1;
}

static int vf3h_harness_main(int argc, char **argv, const char *name,
                             const char *defpath, vf3_case_fn fn)
{
    char path[1024];
    snprintf(path, sizeof(path), "%s", argc > 1 ? argv[1] : defpath);
    char dir[1024];
    vf3h_dirname(dir, sizeof(dir), path);
    FILE *f = fopen(path, "r");
    if (!f) {
        fprintf(stderr, "%s: cannot open %s\n", name, path);
        return 2;
    }
    char line[65536];
    int total = 0, pass = 0, skipped = 0, shown = 0;
    while (fgets(line, sizeof(line), f)) {
        vf3_case c;
        vf3_harness_mem m;
        memset(&c, 0, sizeof(c));
        if (!vf3h_case_parse(&c, line)) {
            skipped++;
            continue;
        }
        if (!vf3h_mem_load(&m, dir, &c)) {
            skipped++;
            continue;
        }
        m.ncase = total + 1;
        char err[256] = "";
        int ok = fn(&c, &m, err, sizeof(err));
        total++;
        if (ok) {
            pass++;
        } else if (shown++ < 8) {
            fprintf(stderr, "  case %d: %s\n", total, err);
        }
        vf3h_mem_free(&m);
    }
    fclose(f);
    if (total == 0) {
        fprintf(stderr, "%s: no RAM cases in %s\n", name, path);
        return 3;
    }
    printf("%s: %d/%d cases match (%d skipped) - %s\n",
           name, pass, total, skipped, pass == total ? "PASS" : "FAIL");
    return pass == total ? 0 : 1;
}

/* Convenience: map host float bits from a register word. */
static float vf3h_f32(uint32_t bits)
{
    float f;
    memcpy(&f, &bits, 4);
    return f;
}

static uint32_t vf3h_f32bits(float f)
{
    uint32_t bits;
    memcpy(&bits, &f, 4);
    return bits;
}

#endif /* VF3_PORT_HARNESS_H */