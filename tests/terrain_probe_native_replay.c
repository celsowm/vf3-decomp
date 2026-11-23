#include "fight/matrix_family.h"
#include "fight/readable.h"
#include "fight/readable_fp.h"
#include "fight/family_hooks.h"
#include "terrain_probe.h"
#include "aim_math.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int vf3_terrain_probe_entry(vf3_matrix_state *,const vf3_ram_map *);
int vf3_terrain_probe_flip_entry(vf3_matrix_state *,const vf3_ram_map *);
#define BASE 0x0c010000u
#define SIZE 0x2a0000u
#define GRID 0x0c060000u
#define SHAPEBASE 0x0c100000u
#define STACK 0x0c030000u
#define OUT 0x0c050000u
#define GLOBAL 0x0c020000u
#define OWNER 0x0c021000u
#define REGION 0x0c022000u
#define MSTACK 0x0c040000u
static void p32(unsigned char*p,uint32_t at,uint32_t v){memcpy(p+at-BASE,&v,4);}
static void p16(unsigned char*p,uint32_t at,uint16_t v){memcpy(p+at-BASE,&v,2);}
static void pf(unsigned char*p,uint32_t at,float v){p32(p,at,vf3_aim_ubits(v));}
static int selected_override(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*r,int*handled)
{
    if(entry==0x0c068d54u||entry==0x0c068de4u||entry==0x0c068fe4u||entry==0x0c068f92u||entry==0x0c0692a6u)
        return vf3_readable_override(entry,s,r,handled);
    *handled=0;return 0;
}
static int run(int mode,int stage,uint32_t fpscr,int flip)
{
    unsigned char*g=calloc(1,SIZE),*n=calloc(1,SIZE);if(!g||!n)exit(2);
    g[0x0c29b880u-BASE]=(unsigned char)stage;p32(g,0x0c29beb4,mode?GRID:0);
    pf(g,0x0c068e50,0.769f);pf(g,0x0c068e54,0.1f);pf(g,0x0c068e5c,6);pf(g,0x0c068e60,-0.5f);
    p32(g,0x0c113a0c,SHAPEBASE);
    for(int i=0;i<1024;++i)p32(g,GRID+4*i,0xffffffffu);
    if(mode==3||mode==5||mode==8||mode==9){
        p32(g,GRID+4*(16+16*32),0x1000);p32(g,SHAPEBASE+0x1000,(mode==8||mode==9)?0:1);p32(g,SHAPEBASE+0x1004,0x2000);
        p32(g,SHAPEBASE+0x2000,2);p32(g,SHAPEBASE+0x2004,0x3000);p32(g,SHAPEBASE+0x2008,0x3010);
        p32(g,SHAPEBASE+0x200c,0x3020);p32(g,SHAPEBASE+0x2010,0x3030);
        pf(g,SHAPEBASE+0x2014,0);pf(g,SHAPEBASE+0x2018,1);pf(g,SHAPEBASE+0x201c,0);
        pf(g,SHAPEBASE+0x3000,0);pf(g,SHAPEBASE+0x3004,1);pf(g,SHAPEBASE+0x3008,0);
        pf(g,SHAPEBASE+0x3010,1);pf(g,SHAPEBASE+0x3014,1);pf(g,SHAPEBASE+0x3018,0);
        pf(g,SHAPEBASE+0x3020,0);pf(g,SHAPEBASE+0x3024,1);pf(g,SHAPEBASE+0x3028,1);
        pf(g,SHAPEBASE+0x3030,1);pf(g,SHAPEBASE+0x3034,1);pf(g,SHAPEBASE+0x3038,1);
    }
    if(mode==4){p32(g,GRID+4*(16+16*32),0x1000);p32(g,SHAPEBASE+0x1000,0xffffffffu);}
    p32(g,0x0c087b60,GLOBAL);p16(g,0x0c087b56,12);p16(g,0x0c087b58,0);p16(g,0x0c087b5a,64);p16(g,0x0c087b5c,128);p16(g,0x0c087b5e,48);
    pf(g,0x0c087b64,0.5f);pf(g,0x0c087b68,0);pf(g,0x0c087b6c,0);p32(g,GLOBAL,OWNER);p32(g,OWNER+12,mode==5?REGION:0);
    for(int i=0;i<16;++i)pf(g,REGION+4*i,i%5==0?1.0f:0.0f);
    pf(g,REGION+64,30);pf(g,REGION+68,30);pf(g,REGION+72,0);pf(g,REGION+80,0);
    p32(g,0x0c087b70,0x0c03c4f0);p32(g,0x0c087b74,0x0c03bd80);p32(g,0x0c087b7c,0x0c03c4a0);
    p32(g,0x0c087794,0x0c03b450);p32(g,0x0c087798,0x0c03b4b0);pf(g,0x0c087b78,1);
    p32(g,0x0c19d2e4,0x00100000);p32(g,0x0c19d2e8,MSTACK);p32(g,0x0c19d2ec,MSTACK);memcpy(n,g,SIZE);
    vf3_ram_win w[2]={{0}};w[0].base=BASE;w[0].len=SIZE;w[0].data=g;w[1].base=0x8c010000;w[1].len=SIZE;w[1].data=g;
    vf3_ram_map m={0};m.wins=w;m.n=2;vf3_matrix_state s={0};vf3_native_aim a={0};a.ram=(float*)n;a.ram_base=BASE;
    for(int i=0;i<16;++i){s.v[i]=a.r[i]=0x12340000u+i;s.v[VF3_REG_FR0+i]=vf3_aim_ubits(a.fr[i]=(float)i/8);s.v[37+i]=vf3_aim_ubits(a.xm[i]=i%5==0?1.0f:0.0f);}
    s.v[4]=a.r[4]=OUT;s.v[5]=a.r[5]=OUT+16;s.v[15]=a.r[15]=STACK;s.v[16]=a.pr=0x0c012000;s.v[17]=a.sr=0x60000000;s.v[18]=a.fpscr=fpscr;
    s.v[VF3_REG_FR0+4]=vf3_aim_ubits(a.fr[4]=mode==2?15.0f:mode==6?12.0f:mode==8?0.25f:mode==9?0.75f:0.0f);
    s.v[VF3_REG_FR0+5]=vf3_aim_ubits(a.fr[5]=mode==7?1.25f:(mode==8||mode==9)?(flip?-0.25f:0.25f):0.0f);s.budget=1000000;
    vf3_family_override=selected_override;int ok=flip?vf3_terrain_probe_flip_entry(&s,&m):vf3_terrain_probe_entry(&s,&m);vf3_family_override=NULL;
    if(flip)vf3_native_terrain_probe_flip(&a);else vf3_native_terrain_probe(&a);
    int bad=!ok||m.oob||s.pc!=a.pr||s.v[17]!=a.sr||s.v[53]!=a.fpul;
    if((mode==8||mode==9) && s.v[0]!=(flip?4u:6u)) {
        fprintf(stderr,"geometric fixture did not reach a shape: result=%08x\n",s.v[0]);bad=1;
    }
    if(!ok||m.oob)fprintf(stderr,"reference failed %d oob %u pc %08x fail %08x\n",ok,m.oob,s.pc,s.failed_pc);
    if(s.v[17]!=a.sr||s.v[53]!=a.fpul)fprintf(stderr,"sr %08x %08x fpul %08x %08x\n",s.v[17],a.sr,s.v[53],a.fpul);
    for(int i=0;i<16;++i){if(s.v[i]!=a.r[i]){fprintf(stderr,"r%d %08x %08x\n",i,s.v[i],a.r[i]);bad=1;}
        if(s.v[VF3_REG_FR0+i]!=vf3_aim_ubits(a.fr[i])){fprintf(stderr,"fr%d %08x %08x\n",i,s.v[VF3_REG_FR0+i],vf3_aim_ubits(a.fr[i]));bad=1;}
        if(s.v[37+i]!=vf3_aim_ubits(a.xm[i])){fprintf(stderr,"xf%d %08x %08x\n",i,s.v[37+i],vf3_aim_ubits(a.xm[i]));bad=1;}}
    if(memcmp(g,n,SIZE)){for(size_t i=0;i<SIZE;++i)if(g[i]!=n[i]){fprintf(stderr,"ram %08x %02x %02x\n",BASE+(unsigned)i,g[i],n[i]);break;}bad=1;}
    free(g);free(n);printf("terrain probe flip=%d mode=%d stage=%d %s\n",flip,mode,stage,bad?"FAIL":"match");return bad;
}
int main(void){int bad=0;for(int flip=0;flip<2;++flip)for(int i=0;i<2;++i){uint32_t fpscr=i?0x40001:0x240001;bad|=run(0,0,fpscr,flip);bad|=run(1,0,fpscr,flip);bad|=run(2,0,fpscr,flip);bad|=run(3,0,fpscr,flip);bad|=run(4,0,fpscr,flip);bad|=run(6,0,fpscr,flip);bad|=run(7,0,fpscr,flip);bad|=run(8,0,fpscr,flip);bad|=run(9,0,fpscr,flip);bad|=run(1,13,fpscr,flip);bad|=run(1,11,fpscr,flip);bad|=run(3,11,fpscr,flip);bad|=run(5,11,fpscr,flip);}return bad;}
