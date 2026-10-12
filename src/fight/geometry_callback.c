/* Refresh both actors and eight geometry blocks. Four transformed corners
 * produce capped depth extents before the original accumulation, decay and
 * block-update callbacks. All scratch pointers retain the original frame. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <string.h>
#define R(n) s->v[(n)]
#define F(n) s->v[21+(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
#define WRITE(a,v,n) vf3_matrix_write(ram,(a),(v),(n))
static float value(uint32_t bits){float result;memcpy(&result,&bits,4);return result;}
static void condition(vf3_matrix_state *s,int yes){R(17)=(R(17)&~1u)|(yes!=0);}
static uint32_t word(const vf3_ram_map *ram,uint32_t a){return (uint32_t)(int32_t)(int16_t)READ(a,2);}
static void move(vf3_matrix_state *s,unsigned dst,unsigned src){vf3_matrix_move(s,dst,src);}
static void binary(vf3_matrix_state *s,unsigned dst,unsigned src,char op){F(dst)=vf3_fpu_binary(F(dst),F(src),R(18),op);}
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t v){R(15)-=4;WRITE(R(15),v,4);}
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram){uint32_t v=READ(R(15),4);R(15)+=4;return v;}
static void save_float(vf3_matrix_state *s,const vf3_ram_map *ram,unsigned fr){R(15)-=(R(18)&0x100000u)?8:4;vf3_matrix_store(s,ram,fr,R(15));}
static void restore_float(vf3_matrix_state *s,const vf3_ram_map *ram,unsigned fr){vf3_matrix_load(s,ram,fr,R(15));R(15)+=(R(18)&0x100000u)?8:4;}
static int call(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t target,uint32_t returned){R(16)=returned;return vf3_matrix_family(target,s,ram);}
static int project_corner(vf3_matrix_state *s,const vf3_ram_map *ram,unsigned corner)
{
    static const uint32_t position_returns[]={0x0c087efc,0x0c087f52,0x0c087fc0,0x0c088036};
    static const uint32_t depth_returns[]={0x0c087f02,0x0c087f58,0x0c087fc6,0x0c08803c};
    R(6)=R(15);R(5)=R(15);
    if(corner==2){F(15)^=0x80000000u;R(0)=52;R(6)+=8;vf3_matrix_store(s,ram,15,R(15)+R(0));R(5)+=4;move(s,6,12);move(s,4,15);move(s,5,13);}
    else if(corner==3){R(0)=52;vf3_matrix_load(s,ram,4,R(15)+R(0));R(5)+=4;move(s,5,13);R(6)+=8;}
    else {move(s,6,12);R(5)+=4;R(6)+=8;move(s,4,15);move(s,5,13);}
    R(4)=R(15);if(!call(s,ram,0x0c0876f2,position_returns[corner]))return 0;
    vf3_matrix_load(s,ram,4,R(15));R(4)=R(13);if(!call(s,ram,0x0c0879da,depth_returns[corner]))return 0;
    R(0)=4;move(s,4,0);vf3_matrix_load(s,ram,3,R(15)+R(0));F(2)=0;binary(s,4,3,'-');condition(s,value(F(2))>value(F(4)));
    if(corner==1)move(s,5,13);else if(corner==2)move(s,15,13);else if(corner==3)move(s,5,15);
    if(R(17)&1){R(0)=12;vf3_matrix_load(s,ram,4,R(15)+R(0));}
    if(corner==1){F(5)^=0x80000000u;move(s,6,5);binary(s,6,4,'-');F(3)=0;condition(s,value(F(3))>value(F(6)));if(R(17)&1)move(s,4,5);}
    else if(corner==2){F(15)^=0x80000000u;move(s,5,15);binary(s,5,4,'-');F(3)=0;condition(s,value(F(3))>value(F(5)));if(R(17)&1)move(s,4,15);}
    else if(corner==3){binary(s,5,4,'-');F(3)=0;condition(s,value(F(3))>value(F(5)));if(R(17)&1)move(s,4,15);}
    return 1;
}
static void scaled_extent(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    R(0)=16;move(s,3,4);vf3_matrix_load(s,ram,4,R(15)+R(0));R(0)=4;binary(s,4,3,'*');
}
int vf3_geometry_callback_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    for(int i=14;i>=8;i--){push(s,ram,R(i));}for(int i=15;i>=12;i--){save_float(s,ram,(unsigned)i);}
    R(1)=READ(0x0c087eac,4);push(s,ram,R(16));R(3)=READ(0x0c087ea8,4);R(2)=READ(R(1),4);R(15)-=104;
    condition(s,(R(2)&R(3))==0);if(!(R(17)&1))goto restore;
    R(3)=READ(0x0c087eb0,4);R(13)=R(4);R(14)=READ(R(3),4);R(4)=R(14);if(!call(s,ram,0x0c087bf8,0x0c087e36))return 0;
    R(0)=40;vf3_matrix_load(s,ram,3,R(14)+R(0));R(0)=word(ram,0x0c087ea2);vf3_matrix_store(s,ram,3,R(14)+R(0));
    R(3)=READ(0x0c087eb4,4);R(14)=READ(R(3),4);R(4)=R(14);if(!call(s,ram,0x0c087bf8,0x0c087e46))return 0;
    R(0)=40;vf3_matrix_load(s,ram,3,R(14)+R(0));R(0)=word(ram,0x0c087ea2);vf3_matrix_store(s,ram,3,R(14)+R(0));
    R(14)=word(ram,0x0c087ea4);R(3)=READ(0x0c087eb8,4);R(14)+=R(13);R(4)=0;if(!call(s,ram,R(3),0x0c087e58))return 0;
    R(7)=R(15);R(6)=R(15);R(5)=R(15);R(5)+=68;R(6)+=92;R(4)=R(15);R(7)+=80;R(1)=R(5);R(2)=R(6);R(3)=R(7);R(4)+=56;
    WRITE(R(15)+20,R(2),4);WRITE(R(15)+24,R(3),4);R(3)=R(6);WRITE(R(15)+36,R(1),4);R(1)=R(7);R(2)=R(4);
    R(10)=R(2);R(11)=R(5);R(8)=R(7);R(9)=R(6);R(1)+=4;R(3)+=4;WRITE(R(15)+40,R(2),4);R(9)+=8;WRITE(R(15)+44,R(3),4);
    R(5)+=8;WRITE(R(15)+48,R(1),4);R(8)+=8;R(12)=8;R(11)+=4;R(10)+=4;R(4)+=8;WRITE(R(15)+32,R(5),4);WRITE(R(15)+28,R(4),4);F(14)=0;
    for(;;){
        condition(s,R(12)==0);if(R(17)&1)break;
        R(3)=READ(0x0c088010,4);R(4)=R(14);if(!call(s,ram,R(3),0x0c087ec2))return 0;
        R(0)=word(ram,0x0c08800e);vf3_matrix_load(s,ram,15,R(14)+R(0));R(0)-=4;vf3_matrix_load(s,ram,13,R(14)+R(0));R(0)+=8;vf3_matrix_load(s,ram,12,R(14)+R(0));
        R(0)=0x0c088014;vf3_matrix_load(s,ram,3,R(0));R(0)=16;vf3_matrix_store(s,ram,3,R(15)+R(0));R(0)=12;vf3_matrix_store(s,ram,14,R(15)+R(0));
        R(0)=0x0c088018;vf3_matrix_load(s,ram,4,R(0));R(0)=R(12);condition(s,R(0)==1);binary(s,15,4,'*');binary(s,12,4,'*');if(R(17)&1)move(s,12,14);
        if(!project_corner(s,ram,0))return 0;
        R(0)=16;move(s,3,4);vf3_matrix_load(s,ram,4,R(15)+R(0));R(0)=4;R(3)=READ(R(15)+20,4);binary(s,4,3,'*');vf3_matrix_load(s,ram,3,R(15));vf3_matrix_store(s,ram,3,R(3));
        vf3_matrix_load(s,ram,3,R(15)+R(0));R(0)=8;R(3)=READ(R(15)+24,4);vf3_matrix_store(s,ram,3,R(3));vf3_matrix_load(s,ram,3,R(15)+R(0));R(0)=R(12);
        R(3)=READ(R(15)+36,4);condition(s,R(0)==1);vf3_matrix_store(s,ram,3,R(3));R(3)=READ(R(15)+40,4);vf3_matrix_store(s,ram,4,R(3));F(12)^=0x80000000u;if(R(17)&1)F(15)^=0x80000000u;
        if(!project_corner(s,ram,1))return 0;
        R(0)=16;move(s,3,4);vf3_matrix_load(s,ram,4,R(15)+R(0));R(0)=4;R(3)=READ(R(15)+44,4);binary(s,4,3,'*');vf3_matrix_load(s,ram,3,R(15));vf3_matrix_store(s,ram,3,R(3));
        vf3_matrix_load(s,ram,3,R(15)+R(0));R(0)=8;R(3)=READ(R(15)+48,4);vf3_matrix_store(s,ram,3,R(3));vf3_matrix_load(s,ram,3,R(15)+R(0));R(0)=R(12);
        condition(s,R(0)==1);vf3_matrix_store(s,ram,3,R(11));vf3_matrix_store(s,ram,4,R(10));
        if(R(17)&1){R(0)=0x0c08801c;move(s,15,14);vf3_matrix_load(s,ram,13,R(0));R(0)=0x0c088020;vf3_matrix_load(s,ram,12,R(0));}
        if(!project_corner(s,ram,2))return 0;
        scaled_extent(s,ram);vf3_matrix_load(s,ram,3,R(15));vf3_matrix_store(s,ram,3,R(9));vf3_matrix_load(s,ram,3,R(15)+R(0));R(0)=8;vf3_matrix_store(s,ram,3,R(8));
        vf3_matrix_load(s,ram,3,R(15)+R(0));R(3)=READ(R(15)+32,4);vf3_matrix_store(s,ram,3,R(3));R(3)=READ(R(15)+28,4);vf3_matrix_store(s,ram,4,R(3));move(s,6,12);F(6)^=0x80000000u;
        if(!project_corner(s,ram,3))return 0;
        R(0)=16;move(s,15,14);vf3_matrix_load(s,ram,8,R(15)+R(0));R(0)=8;vf3_matrix_load(s,ram,6,R(15)+R(0));R(0)=4;binary(s,8,4,'*');vf3_matrix_load(s,ram,4,R(15));
        vf3_matrix_load(s,ram,5,R(15)+R(0));move(s,9,14);move(s,7,14);R(4)=R(14);if(!call(s,ram,0x0c0878e8,0x0c088074))return 0;
        R(3)=READ(R(15)+32,4);R(2)=READ(R(15)+28,4);vf3_matrix_load(s,ram,6,R(3));vf3_matrix_load(s,ram,5,R(8));vf3_matrix_load(s,ram,4,R(9));vf3_matrix_load(s,ram,8,R(2));
        move(s,9,15);move(s,7,15);R(4)=R(14);if(!call(s,ram,0x0c0878e8,0x0c088088))return 0;
        R(2)=READ(R(15)+48,4);R(3)=READ(R(15)+44,4);vf3_matrix_load(s,ram,5,R(2));vf3_matrix_load(s,ram,4,R(3));vf3_matrix_load(s,ram,8,R(10));vf3_matrix_load(s,ram,6,R(11));
        move(s,9,15);move(s,7,15);R(4)=R(14);if(!call(s,ram,0x0c0878e8,0x0c08809c))return 0;
        R(3)=READ(R(15)+36,4);R(2)=READ(R(15)+40,4);vf3_matrix_load(s,ram,6,R(3));vf3_matrix_load(s,ram,8,R(2));R(2)=READ(R(15)+24,4);R(3)=READ(R(15)+20,4);
        vf3_matrix_load(s,ram,5,R(2));vf3_matrix_load(s,ram,4,R(3));move(s,9,15);move(s,7,15);R(4)=R(14);if(!call(s,ram,0x0c0878e8,0x0c0880b4))return 0;
        R(0)=52;vf3_matrix_load(s,ram,15,R(14)+R(0));R(0)=116;vf3_matrix_load(s,ram,4,R(14)+R(0));R(0)=0x0c088140;vf3_matrix_load(s,ram,5,R(0));R(0)=0x0c088144;vf3_matrix_load(s,ram,6,R(0));
        R(0)=116;move(s,0,6);F(5)=vf3_fpu_mac(F(0),F(4),F(5),R(18));move(s,4,5);binary(s,15,4,'+');vf3_matrix_store(s,ram,4,R(14)+R(0));
        R(0)=4;R(4)=word(ram,0x0c08813a);R(4)+=R(14);vf3_matrix_load(s,ram,5,R(4)+R(0));R(0)=8;vf3_matrix_load(s,ram,6,R(4)+R(0));R(5)=R(4);R(5)+=12;
        vf3_matrix_load(s,ram,4,R(4));R(0)=0x0c088144;vf3_matrix_load(s,ram,7,R(5));vf3_matrix_load(s,ram,8,R(0));binary(s,7,8,'*');vf3_matrix_store(s,ram,7,R(5));
        R(4)=R(13);if(!call(s,ram,0x0c08779c,0x0c0880f0))return 0;
        R(4)=R(14);if(!call(s,ram,0x0c0875f0,0x0c0880f4))return 0;
        R(4)=R(14);if(!call(s,ram,0x0c087698,0x0c0880f8))return 0;
        R(0)=52;vf3_matrix_store(s,ram,15,R(14)+R(0));R(12)--;R(3)=word(ram,0x0c08813c);R(14)+=R(3);
    }
    R(3)=READ(0x0c088148,4);R(4)=1;if(!call(s,ram,R(3),0x0c088110))return 0;
    R(0)=word(ram,0x0c08813e);R(4)=READ(R(13)+R(0),4);R(0)-=4;R(5)=READ(R(13)+R(0),4);R(0)+=4;R(4)+=R(5);WRITE(R(13)+R(0),R(4),4);
restore:
    R(15)+=104;R(16)=pop(s,ram);for(unsigned fr=12;fr<16;fr++){restore_float(s,ram,fr);}for(unsigned i=8;i<15;i++){R(i)=pop(s,ram);}
    s->pc=R(16);return ram->oob==0;
}
