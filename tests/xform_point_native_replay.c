#include "fight/matrix_family.h"
#include "fight/readable_fp.h"
#include "xform_point.h"
#include "aim_math.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int vf3_xform_point_entry(vf3_matrix_state *,const vf3_ram_map *);
#define BASE 0x0c010000u
#define SIZE 0x10000u
#define POINT 0x0c012000u
static int run(unsigned variant,uint32_t fpscr)
{
    unsigned char *g=calloc(1,SIZE),*n=calloc(1,SIZE);if(!g||!n)exit(2);
    float point[3]={1.25f,-2.5f,0.75f};memcpy(g+POINT-BASE,point,12);memcpy(n,g,SIZE);
    vf3_ram_win w={0};w.base=BASE;w.len=SIZE;w.data=g;vf3_ram_map map={0};map.wins=&w;map.n=1;
    vf3_matrix_state s={0};vf3_native_aim a={0};a.ram=(float*)n;a.ram_base=BASE;
    for(int i=0;i<16;++i){
        s.v[i]=a.r[i]=0x12340000u+i;
        s.v[VF3_REG_FR0+i]=vf3_aim_ubits(a.fr[i]=(float)i/8.0f);
        float v=variant<2?(i%5==0?1.0f:0.0f):(float)((i*13+(int)variant*7)%23-11)/16.0f;
        s.v[VF3_REG_XF0+i]=vf3_aim_ubits(a.xm[i]=v);
    }
    if(variant==1){s.v[VF3_REG_XF0+12]=vf3_aim_ubits(a.xm[12]=3);s.v[VF3_REG_XF0+13]=vf3_aim_ubits(a.xm[13]=-4);}
    if(variant==10){uint32_t bits=0x7fc01234u;memcpy(g+POINT-BASE,&bits,4);memcpy(n+POINT-BASE,&bits,4);}
    if(variant==11){uint32_t bits=0x00000001u;memcpy(g+POINT-BASE,&bits,4);memcpy(n+POINT-BASE,&bits,4);}
    s.v[4]=a.r[4]=POINT;s.v[5]=a.r[5]=variant%2?POINT:POINT+32;
    s.v[15]=a.r[15]=0x0c013000;s.v[16]=a.pr=0x0c014000;s.v[17]=a.sr=0x60000000;s.v[18]=a.fpscr=fpscr;s.budget=10000;
    int ok=vf3_xform_point_entry(&s,&map);vf3_native_xform_point(&a);
    int bad=!ok||map.oob||s.pc!=a.pr||s.v[17]!=a.sr;
    for(int i=0;i<16;++i){if(s.v[i]!=a.r[i]){fprintf(stderr,"r%d %08x %08x\n",i,s.v[i],a.r[i]);bad=1;}
        if(s.v[VF3_REG_FR0+i]!=vf3_aim_ubits(a.fr[i])){fprintf(stderr,"fr%d %08x %08x\n",i,s.v[VF3_REG_FR0+i],vf3_aim_ubits(a.fr[i]));bad=1;}}
    if(memcmp(g,n,SIZE)){fprintf(stderr,"RAM differs\n");bad=1;}
    free(g);free(n);if(bad)fprintf(stderr,"variant %u fpscr %x failed\n",variant,fpscr);return bad;
}
int main(void){int bad=0;for(unsigned v=0;v<12;++v){bad|=run(v,0x240001u);bad|=run(v,0x40001u);}puts(bad?"xform point FAIL":"xform point: 24 cases match");return bad;}
