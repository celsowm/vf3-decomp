#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "matrix_wrappers.h"
#include "aim_math.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int vf3_vec3_load_entry(vf3_matrix_state *,const vf3_ram_map *);
#define BASE 0x0c010000u
#define SIZE 0x10000u
#define DATA 0x0c012000u
#define STACK 0x0c013000u
static int run(int v,uint32_t fpscr)
{
    unsigned char*g=calloc(1,SIZE),*n=calloc(1,SIZE);if(!g||!n)exit(2);
    float vec[3]={(float)v/8.0f,-0.75f,1.25f};memcpy(g+DATA-BASE,vec,12);memcpy(n,g,SIZE);
    vf3_ram_win w={0};w.base=BASE;w.len=SIZE;w.data=g;vf3_ram_map map={0};map.wins=&w;map.n=1;
    vf3_matrix_state s={0};vf3_native_aim a={0};a.ram=(float*)n;a.ram_base=BASE;
    for(int i=0;i<16;++i){s.v[i]=a.r[i]=0x12340000u+i;s.v[VF3_REG_FR0+i]=vf3_aim_ubits(a.fr[i]=(float)i/8);
        float m=v%2?(float)((i*7)%19-9)/8:(i%5==0?1.0f:0.0f);s.v[VF3_REG_XF0+i]=vf3_aim_ubits(a.xm[i]=m);}
    s.v[4]=a.r[4]=DATA;s.v[15]=a.r[15]=STACK;s.v[16]=a.pr=0x0c014000;s.v[17]=a.sr=0x60000000;s.v[18]=a.fpscr=fpscr;s.budget=100000;
    vf3_family_override=vf3_readable_override;int ok=vf3_vec3_load_entry(&s,&map);vf3_family_override=NULL;
    vf3_native_vec3_load(&a);int bad=!ok||map.oob||s.pc!=a.pr||s.v[17]!=a.sr;
    for(int i=0;i<16;++i){if(s.v[i]!=a.r[i]){fprintf(stderr,"r%d %08x %08x\n",i,s.v[i],a.r[i]);bad=1;}
        float fr=vf3_aim_fbits(s.v[VF3_REG_FR0+i]),xf=vf3_aim_fbits(s.v[VF3_REG_XF0+i]);
        if(fabsf(fr-a.fr[i])>0.002f||fabsf(xf-a.xm[i])>0.002f){fprintf(stderr,"FR/XF %d differs\n",i);bad=1;}}
    if(memcmp(g,n,SIZE)){fprintf(stderr,"RAM differs\n");bad=1;}
    free(g);free(n);if(bad)fprintf(stderr,"vec3 case %d fpscr %x failed\n",v,fpscr);return bad;
}
int main(void){int bad=0;for(int i=0;i<12;++i){bad|=run(i,0x240001);bad|=run(i,0x40001);}puts(bad?"vec3 load FAIL":"vec3 load: 24 cases match within tolerance");return bad;}
