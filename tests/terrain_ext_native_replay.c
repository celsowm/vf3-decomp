#include "fight/matrix_family.h"
#include "fight/readable_fp.h"
#include "terrain_ext.h"
#include "aim_math.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_advance_worker_adapter(uint32_t, vf3_matrix_state *, const vf3_ram_map *);
#define BASE 0x0c010000u
#define SIZE 0x200000u
#define GLOBAL 0x0c020000u
#define OWNER 0x0c021000u
#define REGION 0x0c022000u
#define STACK 0x0c030000u
#define MATRIX_STACK 0x0c040000u
#define DATA 0x0c050000u
static void p32(unsigned char *p, uint32_t addr, uint32_t v) { memcpy(p + addr - BASE, &v, 4); }
static void p16(unsigned char *p, uint32_t addr, uint16_t v) { memcpy(p + addr - BASE, &v, 2); }
static void pf(unsigned char *p, uint32_t addr, float f) { p32(p, addr, vf3_aim_ubits(f)); }

static int run(int selected, int variant, uint32_t fpscr)
{
    unsigned char *g = calloc(1, SIZE), *n = calloc(1, SIZE);
    if (!g || !n) exit(2);
    p32(g, 0x0c087b60, GLOBAL); p16(g, 0x0c087b56, 12);
    p16(g, 0x0c087b58, 0); p16(g, 0x0c087b5a, 64);
    p16(g, 0x0c087b5c, 128); p16(g, 0x0c087b5e, 48);
    pf(g, 0x0c087b64, 0.5f); pf(g, 0x0c087b68, 0); pf(g, 0x0c087b6c, 0);
    p32(g, GLOBAL, OWNER); p32(g, OWNER + 12, selected ? REGION : 0);
    pf(g, REGION + 64, 20); pf(g, REGION + 68, 20); pf(g, REGION + 72, 0); pf(g, REGION + 80, 0);
    for (int i = 0; i < 16; ++i) pf(g, REGION + 4*i, i % 5 == 0 ? 1.0f : 0.0f);
    if (variant) {
        pf(g, REGION, 0.75f); pf(g, REGION + 20, 1.25f);
        pf(g, REGION + 40, 0.5f); pf(g, REGION + 48, 0.25f);
        pf(g, REGION + 52, -0.5f); pf(g, REGION + 56, 0.75f);
    }
    p32(g, 0x0c087b70, 0x0c03c4f0); p32(g, 0x0c087b74, 0x0c03bd80);
    p32(g, 0x0c087b7c, 0x0c03c4a0); p32(g, 0x0c087794, 0x0c03b450);
    p32(g, 0x0c087798, 0x0c03b4b0); pf(g, 0x0c087b78, variant ? 0.5f : 1.0f);
    p32(g, 0x0c19d2e4, 0x00100000); p32(g, 0x0c19d2e8, MATRIX_STACK);
    p32(g, 0x0c19d2ec, MATRIX_STACK);
    for (int i=0;i<6;++i) pf(g, DATA + 4*i, (float)i + 0.5f);
    p32(g, STACK, variant == 2 ? DATA + 12 : DATA + 16);
    p32(g, STACK + 4, DATA + 20);
    memcpy(n, g, SIZE);
    vf3_ram_win w = {0}; w.base = BASE; w.len = SIZE; w.data = g;
    vf3_ram_map m = {0}; m.wins = &w; m.n = 1;
    vf3_matrix_state s = {0}; vf3_native_aim a = {0}; a.ram = (float *)n; a.ram_base = BASE;
    for (int i = 0; i < 16; ++i) {
        s.v[i] = a.r[i] = 0x12340000u + i;
        s.v[VF3_REG_FR0+i] = vf3_aim_ubits(a.fr[i] = (float)i / 8);
        s.v[37+i] = vf3_aim_ubits(a.xm[i] = i % 5 == 0 ? 1.0f : 0.0f);
    }
    s.v[4] = a.r[4] = DATA; s.v[5] = a.r[5] = DATA + 4;
    s.v[6] = a.r[6] = DATA + 8; s.v[7] = a.r[7] = DATA + 12;
    s.v[15] = a.r[15] = STACK; s.v[16] = a.pr = 0x0c012000;
    s.v[17] = a.sr = 0x60000000; s.v[18] = a.fpscr = fpscr; s.budget = 100000;
    int ok = vf3_advance_worker_adapter(0x0c087ace, &s, &m);
    vf3_native_terrain_ext(&a);
    int bad = !ok || m.oob || s.pc != a.pr || s.v[17] != a.sr;
    if (!ok || m.oob) fprintf(stderr, "reference failed %d oob %u pc %08x fail %08x\n", ok, m.oob, s.pc, s.failed_pc);
    for (int i=0;i<16;++i) {
        if (s.v[i]!=a.r[i]) { fprintf(stderr,"r%d %08x %08x\n",i,s.v[i],a.r[i]); bad=1; }
        if (s.v[VF3_REG_FR0+i]!=vf3_aim_ubits(a.fr[i])) { fprintf(stderr,"fr%d %08x %08x\n",i,s.v[VF3_REG_FR0+i],vf3_aim_ubits(a.fr[i])); bad=1; }
        if (s.v[37+i]!=vf3_aim_ubits(a.xm[i])) { fprintf(stderr,"xf%d %08x %08x\n",i,s.v[37+i],vf3_aim_ubits(a.xm[i])); bad=1; }
    }
    if (memcmp(g,n,SIZE)) {
        for (size_t i=0;i<SIZE;++i) if(g[i]!=n[i]) { fprintf(stderr,"ram %08x %02x %02x\n",BASE+(unsigned)i,g[i],n[i]); break; }
        bad=1;
    }
    free(g); free(n);
    printf("terrain ext %s variant %d fpscr %x: %s\n",selected?"matched":"empty",variant,fpscr,bad?"FAIL":"match");
    return bad;
}
int main(void) {
    int result=0;
    for (int selected=0;selected<2;++selected)
        for (int variant=0;variant<3;++variant) {
            result |= run(selected,variant,0x240001);
            result |= run(selected,variant,0x40001);
        }
    return result;
}
