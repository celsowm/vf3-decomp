#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "terrain_height.h"
#include "aim_math.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int vf3_terrain_height_entry(vf3_matrix_state *, const vf3_ram_map *);
#define BASE 0x0c010000u
#define SIZE 0x2a0000u
#define TABLE 0x0c100000u
#define STACK 0x0c030000u
#define GLOBAL 0x0c020000u
#define OWNER 0x0c021000u
#define REGION 0x0c022000u
#define MATRIX_STACK 0x0c040000u
static void p32(unsigned char *p,uint32_t at,uint32_t v){memcpy(p+at-BASE,&v,4);}
static void p16(unsigned char *p,uint32_t at,uint16_t v){memcpy(p+at-BASE,&v,2);}
static void pf(unsigned char *p,uint32_t at,float v){p32(p,at,vf3_aim_ubits(v));}
static int height_override(uint32_t entry,vf3_matrix_state *s,const vf3_ram_map *ram,int *handled)
{
    if(entry==0x0c068d54u || entry==0x0c068de4u) return vf3_readable_override(entry,s,ram,handled);
    *handled=0;return 0;
}
static int run(int stage,int has_table,int selected,float x,float z,uint32_t fpscr)
{
    unsigned char *g=calloc(1,SIZE),*n=calloc(1,SIZE);if(!g||!n)exit(2);
    g[0x0c29b880u-BASE]=(unsigned char)stage;p32(g,0x0c1b9610u,has_table?TABLE:0);
    pf(g,0x0c068e50,0.769f);pf(g,0x0c068e54,0.1f);pf(g,0x0c068e5c,6);pf(g,0x0c068e60,-0.5f);
    pf(g,0x0c068fd0,-12);pf(g,0x0c068fd4,12);pf(g,0x0c068fd8,5);pf(g,0x0c068fdc,64);
    for(unsigned i=0;i<128u*128u;++i)pf(g,TABLE+4*i,(float)(i%17)/8.0f);
    p32(g,0x0c087b60,GLOBAL);p16(g,0x0c087b56,12);p16(g,0x0c087b58,0);
    p16(g,0x0c087b5a,64);p16(g,0x0c087b5c,128);p16(g,0x0c087b5e,48);
    pf(g,0x0c087b64,0.5f);pf(g,0x0c087b68,0);pf(g,0x0c087b6c,0);
    p32(g,GLOBAL,OWNER);p32(g,OWNER+12,selected?REGION:0);
    for(int i=0;i<16;++i)pf(g,REGION+4*i,i%5==0?1.0f:0.0f);
    pf(g,REGION+64,30);pf(g,REGION+68,30);pf(g,REGION+72,0);pf(g,REGION+80,0);
    p32(g,0x0c087b70,0x0c03c4f0);p32(g,0x0c087b74,0x0c03bd80);p32(g,0x0c087b7c,0x0c03c4a0);
    p32(g,0x0c087794,0x0c03b450);p32(g,0x0c087798,0x0c03b4b0);pf(g,0x0c087b78,1);
    p32(g,0x0c19d2e4,0x00100000);p32(g,0x0c19d2e8,MATRIX_STACK);p32(g,0x0c19d2ec,MATRIX_STACK);
    memcpy(n,g,SIZE);
    vf3_ram_win w[2]={{0}};w[0].base=BASE;w[0].len=SIZE;w[0].data=g;w[1].base=0x8c010000;w[1].len=SIZE;w[1].data=g;
    vf3_ram_map m={0};m.wins=w;m.n=2;vf3_matrix_state s={0};vf3_native_aim a={0};a.ram=(float*)n;a.ram_base=BASE;
    for(int i=0;i<16;++i){s.v[i]=a.r[i]=0x12340000u+i;s.v[VF3_REG_FR0+i]=vf3_aim_ubits(a.fr[i]=(float)i/8);s.v[37+i]=vf3_aim_ubits(a.xm[i]=i%5==0?1.0f:0.0f);}
    s.v[VF3_REG_FR0+4]=vf3_aim_ubits(a.fr[4]=x);s.v[VF3_REG_FR0+5]=vf3_aim_ubits(a.fr[5]=z);
    s.v[15]=a.r[15]=STACK;s.v[16]=a.pr=0x0c012000;s.v[17]=a.sr=0x60000000;s.v[18]=a.fpscr=fpscr;s.budget=1000000;
    vf3_family_override=height_override;int ok=vf3_terrain_height_entry(&s,&m);vf3_family_override=NULL;
    vf3_native_terrain_height(&a);int bad=!ok||m.oob||s.pc!=a.pr||s.v[17]!=a.sr||s.v[53]!=a.fpul;
    if(!ok||m.oob)fprintf(stderr,"reference failed %d oob %u pc %08x fail %08x\n",ok,m.oob,s.pc,s.failed_pc);
    if(s.v[17]!=a.sr||s.v[53]!=a.fpul)fprintf(stderr,"sr %08x %08x fpul %08x %08x\n",s.v[17],a.sr,s.v[53],a.fpul);
    for(int i=0;i<16;++i){if(s.v[i]!=a.r[i]){fprintf(stderr,"r%d %08x %08x\n",i,s.v[i],a.r[i]);bad=1;}
        if(s.v[VF3_REG_FR0+i]!=vf3_aim_ubits(a.fr[i])){fprintf(stderr,"fr%d %08x %08x\n",i,s.v[VF3_REG_FR0+i],vf3_aim_ubits(a.fr[i]));bad=1;}
        if(s.v[37+i]!=vf3_aim_ubits(a.xm[i])){fprintf(stderr,"xf%d %08x %08x\n",i,s.v[37+i],vf3_aim_ubits(a.xm[i]));bad=1;}}
    if(memcmp(g,n,SIZE)){for(size_t i=0;i<SIZE;++i)if(g[i]!=n[i]){fprintf(stderr,"ram %08x %02x %02x\n",BASE+(unsigned)i,g[i],n[i]);break;}bad=1;}
    free(g);free(n);printf("height stage=%d table=%d region=%d x=%g z=%g %s\n",stage,has_table,selected,x,z,bad?"FAIL":"match");return bad;
}
int main(void){int bad=0;for(int i=0;i<2;++i){uint32_t f=i?0x40001:0x240001;bad|=run(0,0,0,2,3,f);bad|=run(0,0,0,8,3,f);bad|=run(0,1,0,1.25f,-0.75f,f);bad|=run(2,1,0,20,-20,f);bad|=run(7,1,0,2,-3,f);bad|=run(13,1,0,18,-17,f);bad|=run(11,1,0,1,2,f);bad|=run(11,1,1,1,2,f);}return bad;}
