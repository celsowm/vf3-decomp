#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "sphere.h"
#include "aim_math.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int vf3_point_contact_entry(vf3_matrix_state *, const vf3_ram_map *);
#define BASE 0x0c010000u
#define SIZE 0x100000u
#define MOVER 0x0c020000u
#define TARGET 0x0c021000u
#define POINT 0x0c022000u
#define CENTRE 0x0c023000u
#define FLAGS 0x0c024000u
#define SEG 0x0c025000u
#define STACK 0x0c030000u
#define TABLE 0x0c0fc660u
static void p32(unsigned char *p,uint32_t at,uint32_t v){memcpy(p+at-BASE,&v,4);}
static void p16(unsigned char *p,uint32_t at,uint16_t v){memcpy(p+at-BASE,&v,2);}
static void pf(unsigned char *p,uint32_t at,float v){p32(p,at,vf3_aim_ubits(v));}
static int run(int mode,uint32_t fpscr)
{
    unsigned char *g=calloc(1,SIZE),*n=calloc(1,SIZE); if(!g||!n) exit(2);
    pf(g,POINT,0.5f);pf(g,POINT+4,0.5f);pf(g,POINT+8,0.25f);
    pf(g,MOVER+0x88,mode==0?1.0f:0.0f); pf(g,TARGET+36,2.0f);
    p32(g,FLAGS,0x1155);p32(g,STACK,SEG);p32(g,STACK+4,SEG);p32(g,STACK+8,FLAGS);
    if(mode==4) {p16(g,MOVER+16,1);g[TARGET+54-BASE]=5;}
    p16(g,TABLE,0xffff); p16(g,TABLE+3*32,0xffff);
    uint32_t table=TABLE+(mode==4?6*32:0);
    if(mode==2) {p16(g,table,0);p16(g,table+2,0);p16(g,table+4,0xffff);}
    else if(mode==3||mode==4) {p16(g,table,1);p16(g,table+2,0);p16(g,table+4,0xffff);}
    else p16(g,table,0xffff);
    pf(g,SEG+12,2);pf(g,SEG+16,4);pf(g,SEG+24,1);pf(g,SEG+36,2);
    pf(g,SEG+40,4);pf(g,SEG+44,4);pf(g,SEG+48,16);
    p32(g,0x0c093b0c,0x0c093b4a);p32(g,0x0c093c30,0x01000000);
    memcpy(n,g,SIZE);
    vf3_ram_win w={0};w.base=BASE;w.len=SIZE;w.data=g;vf3_ram_map m={0};m.wins=&w;m.n=1;
    vf3_matrix_state s={0};vf3_native_aim a={0};a.ram=(float *)n;a.ram_base=BASE;
    for(int i=0;i<16;++i){s.v[i]=a.r[i]=0x12340000u+i;s.v[VF3_REG_FR0+i]=vf3_aim_ubits(a.fr[i]=(float)i/8);}
    s.v[4]=a.r[4]=MOVER;s.v[5]=a.r[5]=TARGET;s.v[6]=a.r[6]=POINT;s.v[7]=a.r[7]=CENTRE;
    s.v[15]=a.r[15]=STACK;s.v[16]=a.pr=0x0c012000;s.v[17]=a.sr=0x60000000;s.v[18]=a.fpscr=fpscr;s.budget=1000000;
    vf3_family_override=vf3_readable_override;int ok=vf3_point_contact_entry(&s,&m);vf3_family_override=NULL;
    vf3_native_point_contact(&a);int bad=!ok||m.oob||s.pc!=a.pr||s.v[17]!=a.sr;
    if(!ok||m.oob) fprintf(stderr,"reference failed %d oob %u pc %08x fail %08x\n",ok,m.oob,s.pc,s.failed_pc);
    for(int i=0;i<16;++i){if(s.v[i]!=a.r[i]){fprintf(stderr,"r%d %08x %08x\n",i,s.v[i],a.r[i]);bad=1;}
        if(s.v[VF3_REG_FR0+i]!=vf3_aim_ubits(a.fr[i])){fprintf(stderr,"fr%d %08x %08x\n",i,s.v[VF3_REG_FR0+i],vf3_aim_ubits(a.fr[i]));bad=1;}}
    if(memcmp(g,n,SIZE)){for(size_t i=0;i<SIZE;++i)if(g[i]!=n[i]){fprintf(stderr,"ram %08x %02x %02x\n",BASE+(unsigned)i,g[i],n[i]);break;}bad=1;}
    free(g);free(n);printf("point contact mode=%d fpscr=%x %s\n",mode,fpscr,bad?"FAIL":"match");return bad;
}
int main(void){int bad=0;for(int i=0;i<2;++i)for(int mode=0;mode<5;++mode)bad|=run(mode,i?0x40001:0x240001);return bad;}
