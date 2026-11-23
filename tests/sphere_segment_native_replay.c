#include "fight/matrix_family.h"
#include "fight/readable_fp.h"
#include "sphere.h"
#include "aim_math.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vf3_sphere_segment_entry(vf3_matrix_state *, const vf3_ram_map *);
#define BASE 0x0c010000u
#define SIZE 0x100000u
#define POINT 0x0c020000u
#define RESULT 0x0c020100u
#define FLAGS 0x0c020200u
#define SEG 0x0c021000u
#define STACK 0x0c030000u
static void put32(unsigned char *p,uint32_t at,uint32_t u) {memcpy(p+at-BASE,&u,4);}
static void putf(unsigned char *p,uint32_t at,float f) {put32(p,at,vf3_aim_ubits(f));}
static int run(float x,float y,uint32_t fpscr)
{
    unsigned char *g=calloc(1,SIZE),*n=calloc(1,SIZE); if(!g||!n) exit(2);
    putf(g,POINT,x);putf(g,POINT+4,y);putf(g,POINT+8,0.25f);
    putf(g,SEG+12,2); putf(g,SEG+24,1); putf(g,SEG+36,2);
    putf(g,SEG+40,4);putf(g,SEG+44,4);putf(g,SEG+48,16);
    put32(g,FLAGS,0x42);put32(g,STACK,SEG);put32(g,STACK+4,0);put32(g,STACK+8,FLAGS);
    put32(g,0x0c093b0c,0x0c093b4a);put32(g,0x0c093c30,0x01000000);
    memcpy(n,g,SIZE);
    vf3_ram_win w={0};w.base=BASE;w.len=SIZE;w.data=g;
    vf3_ram_map m={0};m.wins=&w;m.n=1;
    vf3_matrix_state s={0};vf3_native_aim a={0};a.ram=(float *)n;a.ram_base=BASE;
    for(int i=0;i<16;++i) {s.v[i]=a.r[i]=0x12340000u+i;s.v[VF3_REG_FR0+i]=vf3_aim_ubits(a.fr[i]=(float)i/8);}
    s.v[4]=a.r[4]=POINT;s.v[5]=a.r[5]=RESULT;s.v[6]=a.r[6]=RESULT+16;s.v[7]=a.r[7]=RESULT+20;
    s.v[15]=a.r[15]=STACK;s.v[16]=a.pr=0x0c012000;s.v[17]=a.sr=0x60000000;s.v[18]=a.fpscr=fpscr;s.budget=100000;
    int ok=vf3_sphere_segment_entry(&s,&m);vf3_native_sphere_segment(&a);
    int bad=!ok||m.oob||s.pc!=a.pr||s.v[17]!=a.sr;
    if(!ok||m.oob) fprintf(stderr,"reference failed ok=%d oob=%u pc=%08x fail=%08x\n",ok,m.oob,s.pc,s.failed_pc);
    for(int i=0;i<16;++i) {
        if(s.v[i]!=a.r[i]) {fprintf(stderr,"r%d %08x %08x\n",i,s.v[i],a.r[i]);bad=1;}
        if(s.v[VF3_REG_FR0+i]!=vf3_aim_ubits(a.fr[i])) {fprintf(stderr,"fr%d %08x %08x\n",i,s.v[VF3_REG_FR0+i],vf3_aim_ubits(a.fr[i]));bad=1;}
    }
    if(memcmp(g,n,SIZE)) {for(size_t i=0;i<SIZE;++i) if(g[i]!=n[i]) {fprintf(stderr,"ram %08x %02x %02x\n",BASE+(unsigned)i,g[i],n[i]);break;}bad=1;}
    free(g);free(n);printf("segment x=%g y=%g fpscr=%x %s\n",x,y,fpscr,bad?"FAIL":"match");return bad;
}
int main(void) {int bad=0;for(int i=0;i<2;++i) {uint32_t fpscr=i?0x40001:0x240001;bad|=run(-0.5f,0.5f,fpscr);bad|=run(0.5f,0.5f,fpscr);bad|=run(3,0.5f,fpscr);bad|=run(8,0.5f,fpscr);bad|=run(0.5f,3,fpscr);}return bad;}
