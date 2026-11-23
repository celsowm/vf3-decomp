#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "matrix_wrappers.h"
#include "aim_math.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int vf3_xform_axis_entry(vf3_matrix_state *,const vf3_ram_map *);
int vf3_store_keep_translation_entry(vf3_matrix_state *,const vf3_ram_map *);
#define BASE 0x0c010000u
#define SIZE 0x10000u
#define DATA 0x0c012000u
#define STACK 0x0c013000u
static int run(int which,int variant,uint32_t fpscr)
{
    unsigned char*g=malloc(SIZE),*n=malloc(SIZE);if(!g||!n)exit(2);
    memset(g,0x4c,SIZE);
    for(int i=0;i<16;++i){float f=(float)(i-5)/8;memcpy(g+DATA-BASE+4*i,&f,4);}memcpy(n,g,SIZE);
    vf3_ram_win w={0};w.base=BASE;w.len=SIZE;w.data=g;vf3_ram_map map={0};map.wins=&w;map.n=1;
    vf3_matrix_state s={0};vf3_native_aim a={0};a.ram=(float*)n;a.ram_base=BASE;
    for(int i=0;i<16;++i){s.v[i]=a.r[i]=0x12340000u+i;
        s.v[VF3_REG_FR0+i]=vf3_aim_ubits(a.fr[i]=(float)i/8);
        float f=variant?(float)((i*7)%19-9)/8:(i%5==0?1.0f:0.0f);
        s.v[VF3_REG_XF0+i]=vf3_aim_ubits(a.xm[i]=f);}
    s.v[4]=a.r[4]=DATA;s.v[15]=a.r[15]=STACK;s.v[16]=a.pr=0x0c014000;s.v[17]=a.sr=0x60000000;s.v[18]=a.fpscr=fpscr;s.budget=100000;
    vf3_family_override=vf3_readable_override;
    int ok=which?vf3_store_keep_translation_entry(&s,&map):vf3_xform_axis_entry(&s,&map);
    vf3_family_override=NULL;
    if(which)vf3_native_store_keep_translation(&a);else vf3_native_xform_axis(&a);
    int bad=!ok||map.oob||s.pc!=a.pr||s.v[17]!=a.sr;
    for(int i=0;i<16;++i){if(s.v[i]!=a.r[i]){fprintf(stderr,"r%d %08x %08x\n",i,s.v[i],a.r[i]);bad=1;}
        if(s.v[VF3_REG_FR0+i]!=vf3_aim_ubits(a.fr[i])){fprintf(stderr,"fr%d %08x %08x\n",i,s.v[VF3_REG_FR0+i],vf3_aim_ubits(a.fr[i]));bad=1;}}
    if(memcmp(g,n,SIZE)){for(size_t i=0;i<SIZE;++i)if(g[i]!=n[i]){fprintf(stderr,"ram %08x %02x %02x\n",BASE+(unsigned)i,g[i],n[i]);break;}bad=1;}
    free(g);free(n);if(bad)fprintf(stderr,"wrapper %d variant %d fpscr %x failed\n",which,variant,fpscr);return bad;
}
int main(void){int bad=0;for(int w=0;w<2;++w)for(int v=0;v<2;++v){bad|=run(w,v,0x240001);bad|=run(w,v,0x40001);}puts(bad?"matrix wrappers FAIL":"matrix wrappers: 8 cases match");return bad;}
