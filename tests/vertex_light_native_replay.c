#include "fight/matrix_family.h"
#include "fight/readable_fp.h"
#include "native/vertex_light.h"
#include "aim_math.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int vf3_vertex_light_entry(vf3_matrix_state *,const vf3_ram_map *);
#define BASE 0x0c010000u
#define SIZE 0x10000u
#define RECORD 0x0c012000u
static void p32(unsigned char*p,uint32_t at,uint32_t u){memcpy(p+at-BASE,&u,4);}
static void pf(unsigned char*p,uint32_t at,float f){p32(p,at,vf3_aim_ubits(f));}
static int run(int indirect,int32_t selector,int variant,uint32_t fpscr)
{
    unsigned char*g=calloc(1,SIZE),*n=calloc(1,SIZE);if(!g||!n)exit(2);
    uint32_t body=indirect?RECORD+40:RECORD;
    if(indirect){p32(g,RECORD,0);p32(g,RECORD+4,32);}
    p32(g,body,0x3f800001u);pf(g,body+4,0.5f);pf(g,body+8,-0.25f);
    pf(g,body+12,0.25f);pf(g,body+16,0.75f);pf(g,body+20,0.5f);
    p32(g,body+24,0x12345678);p32(g,body+28,0xabcdef01);memcpy(n,g,SIZE);
    vf3_ram_win w={0};w.base=BASE;w.len=SIZE;w.data=g;vf3_ram_map map={0};map.wins=&w;map.n=1;
    vf3_matrix_state s={0};vf3_native_aim a={0};a.ram=(float*)n;a.ram_base=BASE;
    for(int i=0;i<16;++i){s.v[i]=a.r[i]=0x12340000u+i;s.v[VF3_REG_FR0+i]=vf3_aim_ubits(a.fr[i]=(float)i/16);
        float m=variant?(float)((i*7)%19-9)/8:(i%5==0?1.0f:0.0f);s.v[VF3_REG_XF0+i]=vf3_aim_ubits(a.xm[i]=m);}
    s.v[4]=a.r[4]=RECORD;s.v[8]=a.r[8]=(uint32_t)selector;s.v[12]=a.r[12]=0x40000000u;
    s.v[15]=a.r[15]=0x0c014000;s.v[16]=a.pr=0x0c015000;s.v[17]=a.sr=0x60000000;s.v[18]=a.fpscr=fpscr;s.v[53]=a.fpul=0x12345678;s.budget=100000;
    int ok=vf3_vertex_light_entry(&s,&map);int native_ok=vf3_native_vertex_light(&a);
    int bad=!ok||!native_ok||map.oob||s.pc!=a.pr||s.v[17]!=a.sr||s.v[53]!=a.fpul;
    for(int i=0;i<16;++i){if(s.v[i]!=a.r[i]){fprintf(stderr,"r%d %08x %08x\n",i,s.v[i],a.r[i]);bad=1;}
        float fr=vf3_aim_fbits(s.v[VF3_REG_FR0+i]);
        if((isnan(fr)!=isnan(a.fr[i]))||(!isnan(fr)&&fr!=a.fr[i]&&fabsf(fr-a.fr[i])>0.00002f)){fprintf(stderr,"fr%d %g %g\n",i,fr,a.fr[i]);bad=1;}}
    if(memcmp(g,n,SIZE)){fprintf(stderr,"RAM differs\n");bad=1;}
    free(g);free(n);if(bad)fprintf(stderr,"vertex indirect=%d selector=%d variant=%d fpscr=%x failed\n",indirect,selector,variant,fpscr);return bad;
}
int main(void){int bad=0;int selectors[]={-1,0,4,8,12,16,20,24,28,32,36,40};
    for(int i=0;i<12;++i)for(int indirect=0;indirect<2;++indirect)for(int v=0;v<2;++v){bad|=run(indirect,selectors[i],v,0x240001);bad|=run(indirect,selectors[i],v,0x40001);}
    puts(bad?"vertex light FAIL":"vertex light: 96 cases match within tolerance");return bad;}
