/* Paired entry-to-tail replay for SH-4 0x8C09D452. */
#include <stdio.h>
#include <string.h>

#include "port_harness.h"
#include "fight/sh4_matrix.h"

static FILE *xf_in_file;
static FILE *xf_out_file;

static int read_xf(FILE *f, unsigned ordinal, uint32_t words[16])
{
    return fseek(f, (long)ordinal * 16L * 4L, SEEK_SET) == 0 &&
           fread(words, sizeof(uint32_t), 16, f) == 16;
}

static int run_case(const vf3_case *c, vf3_harness_mem *m,
                    char *err, size_t errlen)
{
    uint32_t got[VF3H_NVALS];
    uint32_t xf_in[16], xf_want[16], xf_got[16];

    if (!read_xf(xf_in_file, c->ordinal, xf_in) ||
        !read_xf(xf_out_file, c->ordinal, xf_want)) {
        snprintf(err, errlen, "missing XF sidecar row %u", c->ordinal);
        return 0;
    }
    if (!vf3_sh4_d452(c->in, got, xf_in, xf_got, &m->ram)) {
        snprintf(err, errlen, "input outside observed FSCA catalog");
        return 0;
    }
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    if (memcmp(xf_got, xf_want, sizeof(xf_got)) != 0) {
        snprintf(err, errlen, "XF output differs at case %u", c->ordinal + 1);
        return 0;
    }
    return vf3h_mem_ok(m, err, errlen);
}

int main(int argc, char **argv)
{
    const char *default_cases =
        "extract/analysis/goldens_d452_tail/f_0c09d452.cases";
    char cases[1024], sidecar[1100];
    char *suffix;
    int rc;

    snprintf(cases, sizeof(cases), "%s", argc > 1 ? argv[1] : default_cases);
    suffix = strrchr(cases, '.');
    if (!suffix || strcmp(suffix, ".cases") != 0) {
        fprintf(stderr, "d452_replay: expected a .cases path\n");
        return 2;
    }
    *suffix = '\0';
    snprintf(sidecar, sizeof(sidecar), "%s.xfin.bin", cases);
    xf_in_file = fopen(sidecar, "rb");
    snprintf(sidecar, sizeof(sidecar), "%s.xfout.bin", cases);
    xf_out_file = fopen(sidecar, "rb");
    *suffix = '.';
    if (!xf_in_file || !xf_out_file) {
        fprintf(stderr, "d452_replay: missing XF sidecars for %s\n", cases);
        if (xf_in_file) fclose(xf_in_file);
        if (xf_out_file) fclose(xf_out_file);
        return 2;
    }
    rc = vf3h_harness_main(argc, argv, "d452_replay", default_cases,
                           run_case);
    fclose(xf_in_file);
    fclose(xf_out_file);
    return rc;
}
