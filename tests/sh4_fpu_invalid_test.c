/* ROM-free checks for the frozen x86 capture oracle's generated NaN.
 * These expectations describe that oracle, not certified SH-4 hardware. */
#include "fight/sh4_fpu.h"
#include <fenv.h>
#include <stdint.h>
#include <stdio.h>

static unsigned checks, failures;

static void expect(const char *name, uint32_t got, uint32_t want)
{
    ++checks;
    if (got != want) {
        ++failures;
        fprintf(stderr, "%s: %08x != %08x\n", name, got, want);
    }
    ++checks;
    if (fegetround() != FE_UPWARD) {
        ++failures;
        fprintf(stderr, "%s: caller rounding mode changed\n", name);
    }
}

int main(void)
{
    static const struct { uint32_t a, b; char op; } invalid[] = {
        {0, 0x7f800000u, '*'}, {0x80000000u, 0xff800000u, '*'},
        {0x7f800000u, 0, '*'}, {0xff800000u, 0x80000000u, '*'},
        {0, 0, '/'}, {0x80000000u, 0, '/'},
        {0x7f800000u, 0x7f800000u, '/'},
        {0xff800000u, 0x7f800000u, '/'},
        {0x7f800000u, 0xff800000u, '+'},
        {0xff800000u, 0x7f800000u, '+'},
        {0x7f800000u, 0x7f800000u, '-'},
        {0xff800000u, 0xff800000u, '-'}
    };
    fesetround(FE_UPWARD);
    for (unsigned mode = 0; mode < 4; ++mode) {
        const uint32_t fpscr = (mode & 1u) | ((mode & 2u) ? 0x40000u : 0);
        for (unsigned i = 0; i < sizeof invalid / sizeof invalid[0]; ++i)
            expect("binary INVALID", vf3_fpu_binary(invalid[i].a, invalid[i].b,
                   fpscr, invalid[i].op), 0xffc00000u);

        /* A NaN supplied by the guest keeps its sign and payload. */
        const char ops[] = "+-*/";
        for (unsigned i = 0; i < sizeof ops - 1; ++i) {
            expect("left NaN", vf3_fpu_binary(0x7fc12345u, 0x3f800000u,
                   fpscr, ops[i]), 0x7fc12345u);
            expect("right NaN", vf3_fpu_binary(0x3f800000u, 0xffc54321u,
                   fpscr, ops[i]), 0xffc54321u);
            expect("both NaNs", vf3_fpu_binary(0x7fc12345u, 0xffc54321u,
                   fpscr, ops[i]), (ops[i] == '+' || ops[i] == '*') ?
                   0xffc54321u : 0x7fc12345u);
        }
        expect("sqrt INVALID", vf3_fpu_sqrt(0xbf800000u, fpscr), 0xffc00000u);
        expect("sqrt NaN", vf3_fpu_sqrt(0x7fc12345u, fpscr), 0x7fc12345u);
        expect("sqrt negative zero", vf3_fpu_sqrt(0x80000000u, fpscr), 0x80000000u);
        expect("FMAC INVALID product", vf3_fpu_mac(0, 0x7f800000u,
               0x3f800000u, fpscr), 0xffc00000u);
        expect("FMAC INVALID sum", vf3_fpu_mac(0x7f800000u, 0x3f800000u,
               0xff800000u, fpscr), 0xffc00000u);
        expect("FMAC NaN", vf3_fpu_mac(0x3f800000u, 0x3f800000u,
               0x7fc12345u, fpscr), 0x7fc12345u);
        /* Intel SDM vol.1 table 14-17: first NaN in x,y,z wins, even
         * when the remaining product would be 0*infinity. Distinct payloads
         * detect operand selection rather than only the NaN sign. */
        static const struct { uint32_t a, b, c, want; } mac_nans[] = {
            {0xffc12345u, 0x7fc23456u, 0x7fc34567u, 0xffc12345u},
            {0x7fc12345u, 0xffc23456u, 0xffc34567u, 0x7fc12345u},
            {0, 0xffc23456u, 0x7fc34567u, 0xffc23456u},
            {0x3f800000u, 0x7fc23456u, 0xffc34567u, 0x7fc23456u},
            {0, 0xff800000u, 0xffc34567u, 0xffc34567u},
            {0x7f800000u, 0, 0x7fc34567u, 0x7fc34567u},
            {0xff800001u, 0x7fc23456u, 0x7fc34567u, 0xffc00001u},
            {0x3f800000u, 0x7f800002u, 0xffc34567u, 0x7fc00002u},
            {0, 0xff800000u, 0xff800003u, 0xffc00003u}
        };
        for (unsigned i = 0; i < sizeof mac_nans / sizeof mac_nans[0]; ++i)
            expect("FMAC NaN priority", vf3_fpu_mac(mac_nans[i].a,
                   mac_nans[i].b, mac_nans[i].c, fpscr), mac_nans[i].want);
        expect("finite multiply", vf3_fpu_binary(0x40000000u, 0x40400000u,
               fpscr, '*'), 0x40c00000u);
        expect("divide by zero", vf3_fpu_binary(0x3f800000u, 0,
               fpscr, '/'), 0x7f800000u);

        uint32_t got = 0;
        if (!vf3_fpu_fsrra(0xbf800000u, fpscr, &got)) ++failures;
        expect("FSRRA INVALID", got, 0xffc00000u);
        if (!vf3_fpu_fsrra(0x7fc12345u, fpscr, &got)) ++failures;
        expect("FSRRA NaN", got, 0x7fc12345u);

        uint32_t a[4] = {0, 0x3f800000u, 0, 0};
        uint32_t b[4] = {0x7f800000u, 0x7fc12345u, 0, 0};
        if (!vf3_fpu_fipr(a, b, fpscr, &got)) ++failures;
        expect("FIPR INVALID before guest NaN", got, 0xffc00000u);
        a[0] = 0x7fc54321u;
        if (!vf3_fpu_fipr(a, b, fpscr, &got)) ++failures;
        expect("FIPR guest NaN first", got, 0x7fc54321u);
        a[0] = 0x7f800000u; b[0] = 0x3f800000u;
        a[1] = 0xff800000u; b[1] = 0x3f800000u;
        if (!vf3_fpu_fipr(a, b, fpscr, &got)) ++failures;
        expect("FIPR INVALID sum", got, 0xffc00000u);

        uint32_t matrix[16] = {0}, vector[4] = {0x7f800000u, 0, 0, 0}, out[4];
        if (!vf3_fpu_ftrv(matrix, vector, fpscr, out)) ++failures;
        for (unsigned i = 0; i < 4; ++i) expect("FTRV INVALID", out[i], 0xffc00000u);
        for (unsigned i = 0; i < 4; ++i) matrix[i] = 0x7fc12345u;
        vector[0] = 0xffc54321u;
        if (!vf3_fpu_ftrv(matrix, vector, fpscr, out)) ++failures;
        for (unsigned i = 0; i < 4; ++i)
            expect("FTRV supplied NaNs", out[i], i ? 0xffc54321u : 0x7fc12345u);
    }
    fesetround(FE_TONEAREST);
    printf("sh4_fpu_invalid: %u checks, %u failures\n", checks, failures);
    return failures ? 1 : 0;
}
