#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "unit_triple.h"
#include "aim_math.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int vf3_unit_triple_entry(vf3_matrix_state *,const vf3_ram_map *);
#define BASE 0x0c010000u
#define SIZE 0x200000u
#define SRC 0x0c020000u
#define OUT 0x0c021000u
#define MSTACK 0x0c040000u
#define STACK 0x0c030000u
static void p32(unsigned char*p,uint32_t at,uint32_t v){memcpy(p+at-BASE,&v,4);}
static void pf(unsigned char*p,uint32_t at,float v){p32(p,at,vf3_aim_ubits(v));}
static int run(int mode,uint32_t fpscr,int transformed)
{
    unsigned char*g=calloc(1,SIZE),*n=calloc(1,SIZE);if(!g||!n)exit(2);
    pf(g,SRC,mode?1.0f:0);pf(g,SRC+4,mode>1?2.0f:0);pf(g,SRC+8,mode>2?-3.0f:0);
    p32(g,0x0c19d2e4,0x00100001);p32(g,0x0c19d2e8,MSTACK);p32(g,0x0c19d2ec,MSTACK+64);
    for(int i=0;i<16;++i)pf(g,MSTACK+4*i,i%5==0?1.0f:0.0f);memcpy(n,g,SIZE);
    vf3_ram_win w={0};w.base=BASE;w.len=SIZE;w.data=g;vf3_ram_map map={0};map.wins=&w;map.n=1;
    vf3_matrix_state s={0};vf3_native_aim a={0};a.ram=(float*)n;a.ram_base=BASE;
    for(int i=0;i<16;++i){s.v[i]=a.r[i]=0x12340000u+i;s.v[VF3_REG_FR0+i]=vf3_aim_ubits(a.fr[i]=(float)i/8);
        float m=i%5==0?1.0f:0.0f;
        if(transformed){if(i==0||i==10)m=0;if(i==2)m=-1;if(i==8)m=1;if(i==12)m=1;if(i==14)m=-2;}
        s.v[VF3_REG_XF0+i]=vf3_aim_ubits(a.xm[i]=m);}
    s.v[4]=a.r[4]=SRC;s.v[5]=a.r[5]=OUT;s.v[6]=a.r[6]=OUT+4;s.v[15]=a.r[15]=STACK;s.v[16]=a.pr=0x0c014000;
    s.v[17]=a.sr=0x60000000;s.v[18]=a.fpscr=fpscr;s.budget=100000;
    vf3_family_override=vf3_readable_override;int ok=vf3_unit_triple_entry(&s,&map);vf3_family_override=NULL;
    vf3_native_unit_triple(&a);int bad=!ok||map.oob||s.pc!=a.pr||s.v[17]!=a.sr||s.v[53]!=a.fpul;
    for(int i=0;i<16;++i){if(s.v[i]!=a.r[i]){fprintf(stderr,"r%d %08x %08x\n",i,s.v[i],a.r[i]);bad=1;}
        float fr=vf3_aim_fbits(s.v[VF3_REG_FR0+i]),xf=vf3_aim_fbits(s.v[VF3_REG_XF0+i]);
        if((isnan(fr)!=isnan(a.fr[i]))||(!isnan(fr)&&fabsf(fr-a.fr[i])>0.002f)||fabsf(xf-a.xm[i])>0.002f){fprintf(stderr,"FR/XF %d %g %g\n",i,fr,a.fr[i]);bad=1;}}
    if(memcmp(g,n,SIZE)){for(size_t i=0;i<SIZE;++i)if(g[i]!=n[i]){fprintf(stderr,"ram %08x %02x %02x\n",BASE+(unsigned)i,g[i],n[i]);break;}bad=1;}
    free(g);free(n);if(bad)fprintf(stderr,"unit triple mode %d fpscr %x matrix %d failed\n",mode,fpscr,transformed);return bad;
}
int main(void){int bad=0;for(int m=0;m<2;++m)for(int i=0;i<4;++i){bad|=run(i,0x240001,m);bad|=run(i,0x40001,m);}puts(bad?"unit triple FAIL":"unit triple: 16 cases match within tolerance");return bad;}
