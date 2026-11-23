#include "fight/matrix_family.h"
#include "fight/readable_fp.h"
#include "pose_blend.h"
#include "aim_math.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int vf3_pose_blend_entry(vf3_matrix_state *,const vf3_ram_map *);
#define BASE 0x0c010000u
#define SIZE 0x10000u
#define OBJ 0x0c012000u
#define STACK 0x0c013000u
static int run(float weight,float step,uint32_t fpscr)
{
    unsigned char*g=calloc(1,SIZE),*n=calloc(1,SIZE);if(!g||!n)exit(2);
    for(int i=0;i<52;++i){int16_t x=(int16_t)(i*1327-30000);memcpy(g+OBJ-BASE+2*i,&x,2);}
    memcpy(g+OBJ-BASE+0x9c,&weight,4);memcpy(g+OBJ-BASE+0xa0,&step,4);memcpy(n,g,SIZE);
    vf3_ram_win w={0};w.base=BASE;w.len=SIZE;w.data=g;vf3_ram_map map={0};map.wins=&w;map.n=1;
    vf3_matrix_state s={0};vf3_native_aim a={0};a.ram=(float*)n;a.ram_base=BASE;
    for(int i=0;i<16;++i){s.v[i]=a.r[i]=0x12340000u+i;s.v[VF3_REG_FR0+i]=vf3_aim_ubits(a.fr[i]=(float)i/8);}
    s.v[4]=a.r[4]=OBJ;s.v[15]=a.r[15]=STACK;s.v[16]=a.pr=0x0c014000;s.v[17]=a.sr=0x60000000;s.v[18]=a.fpscr=fpscr;
    s.v[VF3_REG_MACL]=a.macl=0x87654321;s.v[VF3_REG_FPUL]=a.fpul=0x12345678;s.budget=100000;
    int ok=vf3_pose_blend_entry(&s,&map);vf3_native_pose_blend(&a);
    int bad=!ok||map.oob||s.pc!=a.pr||s.v[17]!=a.sr||s.v[VF3_REG_FPUL]!=a.fpul||s.v[VF3_REG_MACL]!=a.macl;
    for(int i=0;i<16;++i){if(s.v[i]!=a.r[i]){fprintf(stderr,"r%d %08x %08x\n",i,s.v[i],a.r[i]);bad=1;}
        if(s.v[VF3_REG_FR0+i]!=vf3_aim_ubits(a.fr[i])){fprintf(stderr,"fr%d %08x %08x\n",i,s.v[VF3_REG_FR0+i],vf3_aim_ubits(a.fr[i]));bad=1;}}
    if(memcmp(g,n,SIZE)){for(size_t i=0;i<SIZE;++i)if(g[i]!=n[i]){fprintf(stderr,"ram %08x %02x %02x\n",BASE+(unsigned)i,g[i],n[i]);break;}bad=1;}
    free(g);free(n);if(bad)fprintf(stderr,"weight %g step %g fpscr %x failed\n",weight,step,fpscr);return bad;
}
int main(void){float w[]={0,0.9f,1.1f,-0.5f,0.3333f};float step[]={0,0.05f,0.5f,0.125f,-0.125f};int bad=0;
    for(int i=0;i<5;++i){bad|=run(w[i],step[i],0x240001);bad|=run(w[i],step[i],0x40001);}puts(bad?"full pose blend FAIL":"full pose blend: 10 cases match");return bad;}
