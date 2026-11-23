#include "fight/matrix_family.h"
#include "fight/readable_fp.h"
#include "sphere.h"
#include "aim_math.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BASE 0x0c010000u
#define SIZE 0x100000u
#define POINT 0x0c020000u
#define ANCHOR 0x0c020100u
#define FLAGS 0x0c020200u
#define STACK 0x0c030000u
static void put32(unsigned char *p, uint32_t addr, uint32_t v) { memcpy(p+addr-BASE,&v,4); }
static void putf(unsigned char *p, uint32_t addr, float v) { put32(p,addr,vf3_aim_ubits(v)); }

static int run(float distance, float radius, uint32_t fpscr)
{
    unsigned char *g=calloc(1,SIZE), *n=calloc(1,SIZE); if(!g||!n) exit(2);
    putf(g,POINT,distance+0.25f); putf(g,POINT+4,radius==3.0f ? 0.0f : 0.5f); putf(g,POINT+8,(radius==0.5f || radius==3.0f) ? 0.0f : -0.25f);
    putf(g,ANCHOR,0.25f); putf(g,ANCHOR+4,0); putf(g,ANCHOR+8,0);
    put32(g,FLAGS,0x42); put32(g,0x0c093b0c,0x0c093b4a);
    put32(g,0x0c093c30,0x01000000); memcpy(n,g,SIZE);
    vf3_ram_win w={0}; w.base=BASE; w.len=SIZE; w.data=g;
    vf3_ram_map m={0}; m.wins=&w; m.n=1;
    vf3_matrix_state s={0}; vf3_native_aim a={0}; a.ram=(float *)n; a.ram_base=BASE;
    for(int i=0;i<16;++i) {s.v[i]=a.r[i]=0x12340000u+i; s.v[VF3_REG_FR0+i]=vf3_aim_ubits(a.fr[i]=(float)i/8);}
    s.v[4]=a.r[4]=POINT; s.v[5]=a.r[5]=ANCHOR; s.v[6]=a.r[6]=FLAGS;
    s.v[15]=a.r[15]=STACK; s.v[16]=a.pr=0x0c012000; s.v[17]=a.sr=0x60000000;
    s.v[18]=a.fpscr=fpscr; s.v[VF3_REG_FR0+4]=vf3_aim_ubits(a.fr[4]=radius); s.budget=100000;
    int ok=vf3_matrix_family(0x0c093a9c,&s,&m); vf3_native_sphere_resolve(&a);
    int bad=!ok||m.oob||s.pc!=a.pr||s.v[17]!=a.sr;
    if(!ok||m.oob) fprintf(stderr,"reference failed %d oob %u pc %08x fail %08x\n",ok,m.oob,s.pc,s.failed_pc);
    for(int i=0;i<16;++i) {
        if(s.v[i]!=a.r[i]) {fprintf(stderr,"r%d %08x %08x\n",i,s.v[i],a.r[i]); bad=1;}
        if(s.v[VF3_REG_FR0+i]!=vf3_aim_ubits(a.fr[i])) {fprintf(stderr,"fr%d %08x %08x\n",i,s.v[VF3_REG_FR0+i],vf3_aim_ubits(a.fr[i])); bad=1;}
    }
    if(memcmp(g,n,SIZE)) { for(size_t i=0;i<SIZE;++i) if(g[i]!=n[i]) {fprintf(stderr,"ram %08x %02x %02x\n",BASE+(unsigned)i,g[i],n[i]); break;} bad=1; }
    free(g);free(n); printf("sphere distance %.2f radius %.2f fpscr %x: %s\n",distance,radius,fpscr,bad?"FAIL":"match"); return bad;
}
int main(void) {int bad=0; for(int i=0;i<2;++i) {uint32_t fpscr=i?0x40001:0x240001; bad|=run(3,1,fpscr); bad|=run(0,2,fpscr); bad|=run(1,2,fpscr); bad|=run(0,0.5f,fpscr); bad|=run(0,3,fpscr); bad|=run(1,sqrtf(1.3125f),fpscr);} return bad;}
