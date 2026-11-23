#include "fight/matrix_family.h"
#include "render_callback_stub.h"
#include <stdio.h>
#include <string.h>
int vf3_empty_rts_entry(vf3_matrix_state *,const vf3_ram_map *);
int main(void)
{
    vf3_matrix_state s={0},before;vf3_ram_map ram={0};
    vf3_native_aim a={0},original;
    for(int i=0;i<16;++i){s.v[i]=a.r[i]=0x12340000u+i;a.fr[i]=(float)i/8;a.xm[i]=(float)i/16;}
    s.v[16]=a.pr=0x0c014000;s.v[17]=a.sr=0x60000001;s.v[18]=a.fpscr=0x40001;
    a.fpul=0x12345678;a.macl=0xabcdef01;before=s;original=a;
    int ok=vf3_empty_rts_entry(&s,&ram);vf3_native_render_callback_stub(&a);
    int bad=!ok||s.pc!=before.v[16]||memcmp(s.v,before.v,sizeof s.v)||memcmp(&a,&original,sizeof a);
    puts(bad?"render callback FAIL":"render callback: unchanged state matches");return bad;
}
