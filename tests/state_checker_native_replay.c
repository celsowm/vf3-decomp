#include "fight/matrix_family.h"
#include "fight/readable_fp.h"
#include "state_checker.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int vf3_state_checker_entry(vf3_matrix_state *,const vf3_ram_map *);
#define BASE 0x0c010000u
#define SIZE 0x10000u
#define STATE 0x0c012000u
#define STACK 0x0c013000u
static int run(int mode)
{
    unsigned char*g=calloc(1,SIZE),*n=calloc(1,SIZE);if(!g||!n)exit(2);
    uint16_t busy=mode==1?0xffff:0,state=mode==3?2:3;
    memcpy(g+STATE-BASE+0x48,&busy,2);memcpy(g+STATE-BASE+0x4c,&state,2);memcpy(n,g,SIZE);
    vf3_ram_win w={0};w.base=BASE;w.len=SIZE;w.data=g;vf3_ram_map map={0};map.wins=&w;map.n=1;
    vf3_matrix_state s={0};vf3_native_aim a={0};a.ram=(float*)n;a.ram_base=BASE;
    for(int i=0;i<16;++i)s.v[i]=a.r[i]=0x12340000u+i;
    s.v[4]=a.r[4]=mode?STATE:0;s.v[15]=a.r[15]=STACK;s.v[16]=a.pr=0x0c014000;
    s.v[17]=a.sr=0x60000000;s.v[18]=a.fpscr=0x40001;s.budget=10000;
    int ok=vf3_state_checker_entry(&s,&map);vf3_native_state_checker(&a);
    int bad=!ok||map.oob||s.pc!=a.pr||s.v[17]!=a.sr;
    if(!ok||map.oob)fprintf(stderr,"reference failed ok=%d oob=%u pc=%08x\n",ok,map.oob,s.pc);
    for(int i=0;i<16;++i)if(s.v[i]!=a.r[i]){fprintf(stderr,"r%d %08x %08x\n",i,s.v[i],a.r[i]);bad=1;}
    if(memcmp(g,n,SIZE)){for(size_t i=0;i<SIZE;++i)if(g[i]!=n[i]){fprintf(stderr,"ram %08x %02x %02x\n",BASE+(unsigned)i,g[i],n[i]);break;}bad=1;}
    free(g);free(n);if(bad)fprintf(stderr,"state checker mode %d failed\n",mode);return bad;
}
int main(void){int bad=0;for(int i=0;i<4;++i)bad|=run(i);puts(bad?"state checker FAIL":"state checker: 4 cases match");return bad;}
