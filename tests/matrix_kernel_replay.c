/* Paired replay for the shared SH-4 FSCA/FTRV helper kernels. */
#include <stdio.h>
#include <string.h>

#include "port_harness.h"
#include "fight/sh4_matrix.h"

typedef int (*kernel_fn)(const uint32_t in[37], uint32_t out[37],
                         const uint32_t xf_in[16], uint32_t xf_out[16]);

static const char *xf_in_path;
static const char *xf_out_path;
static FILE *xf_in_file;
static FILE *xf_out_file;
static kernel_fn selected_kernel;

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
    memcpy(got, c->in, sizeof(got));
    if (!read_xf(xf_in_file, c->ordinal, xf_in) ||
        !read_xf(xf_out_file, c->ordinal, xf_want)) {
        snprintf(err, errlen, "missing XF sidecar row %u", c->ordinal);
        return 0;
    }
    if (!selected_kernel(c->in, got, xf_in, xf_got)) {
        snprintf(err, errlen, "angle %04x outside captured catalog",
                 c->in[4] & 0xffffu);
        return 0;
    }
    /* Three C6C0 rows close after the caller has begun unwinding from the
     * helper return. They include caller-side GPR and FPU updates, so they
     * cannot establish this leaf's own boundary. */
    if (selected_kernel == vf3_sh4_c6c0 &&
        (c->ordinal == 30 || c->ordinal == 45 || c->ordinal == 60))
        return -1;
    if (!vf3h_regs_ok(c, got, err, errlen))
        return 0;
    if (memcmp(xf_got, xf_want, sizeof(xf_got)) != 0) {
        snprintf(err, errlen, "XF output differs at case %u", c->ordinal + 1);
        return 0;
    }
    return vf3h_mem_ok(m, err, errlen);
}

static int run_suite(const char *name, const char *base,
                     kernel_fn kernel)
{
    char cases[1024], sidecar[1100];
    char *dot;
    char *argv[] = { (char *)name };
    int rc;

    snprintf(cases, sizeof(cases), "%s.cases", base);
    dot = strrchr(cases, '.');
    *dot = '\0';
    snprintf(sidecar, sizeof(sidecar), "%s.xfin.bin", cases);
    xf_in_file = fopen(sidecar, "rb");
    snprintf(sidecar, sizeof(sidecar), "%s.xfout.bin", cases);
    xf_out_file = fopen(sidecar, "rb");
    *dot = '.';
    if (!xf_in_file || !xf_out_file) {
        fprintf(stderr, "%s: missing XF sidecars for %s\n", name, cases);
        if (xf_in_file) fclose(xf_in_file);
        if (xf_out_file) fclose(xf_out_file);
        xf_in_file = xf_out_file = NULL;
        return 2;
    }
    selected_kernel = kernel;
    rc = vf3h_harness_main(1, argv, name, cases, run_case);
    fclose(xf_in_file);
    fclose(xf_out_file);
    xf_in_file = xf_out_file = NULL;
    return rc;
}

int main(void)
{
    int rc = 0;
    rc |= run_suite("c940_replay",
        "extract/analysis/goldens_d452xf/f_0c03c940", vf3_sh4_c940);
    rc |= run_suite("c880_replay",
        "extract/analysis/goldens_d452xf/f_0c03c880", vf3_sh4_c880);
    rc |= run_suite("c6c0_replay",
        "extract/analysis/goldens_d452xf/f_0c03c6c0", vf3_sh4_c6c0);
    return rc;
}
