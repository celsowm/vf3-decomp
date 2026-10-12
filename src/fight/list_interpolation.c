/* Seven-channel cubic interpolation over a circular control-point list.
 * Old head nodes move to the free list in original order. Degenerate time
 * differences become one before the neighboring secants are computed. */
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
static void binary(vf3_matrix_state *s,unsigned dst,unsigned src,char op){F(dst)=vf3_fpu_binary(F(dst),F(src),R(18),op);}
static void move(vf3_matrix_state *s,unsigned dst,unsigned src){vf3_matrix_move(s,dst,src);}
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t v){R(15)-=4;WRITE(R(15),v,4);}
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram){uint32_t v=READ(R(15),4);R(15)+=4;return v;}
static void save_float(vf3_matrix_state *s,const vf3_ram_map *ram,unsigned fr){R(15)-=(R(18)&0x100000u)?8:4;vf3_matrix_store(s,ram,fr,R(15));}
static void restore_float(vf3_matrix_state *s,const vf3_ram_map *ram,unsigned fr){vf3_matrix_load(s,ram,fr,R(15));R(15)+=(R(18)&0x100000u)?8:4;}

int vf3_cubic_channel_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    move(s,10,4);binary(s,10,5,'/');F(11)=0x3f800000;move(s,2,8);move(s,5,10);binary(s,6,10,'*');binary(s,5,11,'-');
    move(s,3,6);move(s,0,5);F(3)=vf3_fpu_mac(F(0),F(7),F(3),R(18));move(s,6,5);binary(s,6,3,'*');move(s,3,5);binary(s,5,3,'+');
    move(s,0,6);F(2)=vf3_fpu_mac(F(0),F(4),F(2),R(18));binary(s,5,11,'-');move(s,6,8);binary(s,6,9,'-');move(s,4,2);
    move(s,3,5);move(s,5,6);binary(s,5,3,'*');move(s,3,5);move(s,5,10);binary(s,5,3,'*');move(s,0,5);F(4)=vf3_fpu_mac(F(0),F(10),F(4),R(18));
    move(s,0,4);s->pc=R(16);return ram->oob==0;
}
int vf3_list_move_head_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    R(6)=READ(R(4)+4,4);R(7)=READ(R(5),4);R(0)=READ(R(6)+4,4);WRITE(R(6),R(7),4);WRITE(R(6)+4,R(5),4);
    WRITE(R(0),R(4),4);WRITE(R(4)+4,R(0),4);WRITE(R(5),R(6),4);WRITE(R(7)+4,R(6),4);s->pc=R(16);return ram->oob==0;
}
static void build_tangents(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    R(0)=4;move(s,3,5);move(s,5,13);binary(s,5,3,'/');move(s,3,4);move(s,4,13);binary(s,4,3,'/');
    vf3_matrix_load(s,ram,6,R(5)+R(0));vf3_matrix_load(s,ram,8,R(4)+R(0));move(s,3,6);move(s,6,8);binary(s,6,3,'-');
    vf3_matrix_load(s,ram,9,R(6)+R(0));vf3_matrix_load(s,ram,7,R(7)+R(0));R(0)=word(ram,0x0c08f816);binary(s,7,9,'-');binary(s,6,5,'*');binary(s,7,4,'*');
    vf3_matrix_store(s,ram,6,R(14)+R(0));R(0)+=4;vf3_matrix_store(s,ram,7,R(14)+R(0));
    for(unsigned channel=1;channel<=4;channel++){
        R(0)=4+channel*4;
        if(channel==4){vf3_matrix_load(s,ram,3,R(5)+R(0));vf3_matrix_load(s,ram,7,R(4)+R(0));vf3_matrix_load(s,ram,6,R(7)+R(0));binary(s,7,3,'-');vf3_matrix_load(s,ram,9,R(6)+R(0));}
        else if(channel==1){vf3_matrix_load(s,ram,7,R(4)+R(0));vf3_matrix_load(s,ram,6,R(7)+R(0));vf3_matrix_load(s,ram,3,R(5)+R(0));vf3_matrix_load(s,ram,9,R(6)+R(0));binary(s,7,3,'-');}
        else {vf3_matrix_load(s,ram,7,R(4)+R(0));vf3_matrix_load(s,ram,3,R(5)+R(0));vf3_matrix_load(s,ram,6,R(7)+R(0));binary(s,7,3,'-');vf3_matrix_load(s,ram,9,R(6)+R(0));}
        R(0)=word(ram,0x0c08f818+(channel-1)*2);binary(s,6,9,'-');binary(s,7,5,'*');binary(s,6,4,'*');
        vf3_matrix_store(s,ram,7,R(14)+R(0));R(0)+=4;vf3_matrix_store(s,ram,6,R(14)+R(0));
    }
    R(0)=24;vf3_matrix_load(s,ram,6,R(4)+R(0));vf3_matrix_load(s,ram,3,R(5)+R(0));vf3_matrix_load(s,ram,7,R(7)+R(0));binary(s,6,3,'-');
    vf3_matrix_load(s,ram,9,R(6)+R(0));R(0)=word(ram,0x0c08f820);binary(s,7,9,'-');binary(s,6,5,'*');binary(s,7,4,'*');
    vf3_matrix_store(s,ram,6,R(14)+R(0));R(0)+=4;vf3_matrix_store(s,ram,7,R(14)+R(0));
    R(0)=28;vf3_matrix_load(s,ram,9,R(4)+R(0));vf3_matrix_load(s,ram,3,R(5)+R(0));move(s,6,9);binary(s,6,3,'-');vf3_matrix_load(s,ram,8,R(6)+R(0));
    vf3_matrix_load(s,ram,7,R(7)+R(0));binary(s,6,5,'*');binary(s,7,8,'-');R(0)=word(ram,0x0c08f822);vf3_matrix_store(s,ram,6,R(14)+R(0));R(0)+=4;
    binary(s,7,4,'*');vf3_matrix_store(s,ram,7,R(14)+R(0));
}
int vf3_list_interpolate_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    push(s,ram,R(14));R(14)=R(4);push(s,ram,R(13));push(s,ram,R(12));save_float(s,ram,15);save_float(s,ram,14);save_float(s,ram,13);
    R(0)=word(ram,0x0c08f69a);push(s,ram,R(16));vf3_matrix_load(s,ram,14,R(14)+R(0));R(0)+=4;vf3_matrix_load(s,ram,15,R(14)+R(0));R(15)-=4;
    condition(s,value(F(15))>value(F(14)));F(13)=0x3f800000;if(!(R(17)&1))goto evaluate;
    R(0)=word(ram,0x0c08f6a2);R(13)=READ(R(14)+R(0),4);R(0)+=4;R(4)=READ(R(14)+R(0),4);
select_segment:
    R(12)=word(ram,0x0c08f696);R(5)=R(13);R(13)=R(4);R(12)+=R(14);R(4)=READ(R(12)+4,4);condition(s,R(5)==R(4));
    if(!(R(17)&1)){R(5)=word(ram,0x0c08f694);R(5)+=R(14);R(4)=R(12);R(16)=0x0c08f674;if(!vf3_matrix_family(0x0c08f4ae,s,ram))return 0;}
    R(4)=READ(R(13)+4,4);condition(s,R(4)==R(12));if(R(17)&1){R(4)=R(13);goto neighbors;}
    R(5)=READ(R(4)+8,4);R(6)=READ(R(13)+8,4);vf3_matrix_load(s,ram,5,R(5));vf3_matrix_load(s,ram,4,R(6));condition(s,value(F(5))>value(F(4)));
    if(!(R(17)&1)){R(5)=READ(R(14)+48,4);R(3)=2;R(5)|=R(3);WRITE(R(14)+48,R(5),4);goto select_segment;}
neighbors:
    R(5)=READ(R(13),4);condition(s,R(5)==R(12));
    if(!(R(17)&1)){R(6)=READ(R(13)+8,4);R(7)=READ(R(5)+8,4);vf3_matrix_load(s,ram,5,R(6));vf3_matrix_load(s,ram,4,R(7));condition(s,value(F(5))>value(F(4)));}
    if(!(R(17)&1)||R(5)==R(12))R(5)=R(4);
    R(7)=READ(R(4)+4,4);condition(s,R(7)==R(12));
    if(!(R(17)&1)){R(3)=READ(R(4)+8,4);WRITE(R(15),R(3),4);R(6)=READ(R(7)+8,4);vf3_matrix_load(s,ram,4,R(3));vf3_matrix_load(s,ram,5,R(6));condition(s,value(F(5))>value(F(4)));}
    if(!(R(17)&1)||R(7)==R(12))R(7)=R(13);
    R(0)=word(ram,0x0c08f812);WRITE(R(14)+R(0),R(13),4);R(0)+=4;WRITE(R(14)+R(0),R(4),4);R(4)=READ(R(4)+8,4);R(6)=READ(R(13)+8,4);
    vf3_matrix_load(s,ram,7,R(4));vf3_matrix_load(s,ram,6,R(6));move(s,14,7);binary(s,14,6,'-');F(3)=0;R(5)=READ(R(5)+8,4);R(7)=READ(R(7)+8,4);vf3_matrix_load(s,ram,5,R(5));
    condition(s,value(F(14))==value(F(3)));move(s,15,13);vf3_matrix_load(s,ram,4,R(7));if(R(17)&1)move(s,14,15);
    move(s,3,5);move(s,5,7);binary(s,5,3,'-');F(2)=0;condition(s,value(F(5))==value(F(2)));binary(s,4,6,'-');if(R(17)&1)move(s,5,15);
    F(3)=0;condition(s,value(F(4))==value(F(3)));if(R(17)&1)move(s,4,15);R(0)=word(ram,0x0c08f814);vf3_matrix_store(s,ram,14,R(14)+R(0));build_tangents(s,ram);
evaluate:
    R(0)=word(ram,0x0c08f812);move(s,5,14);R(5)=READ(R(14)+R(0),4);R(0)+=4;R(4)=READ(R(14)+R(0),4);R(0)=4;R(13)=READ(R(5)+8,4);R(12)=READ(R(4)+8,4);
    static const uint32_t returns[]={0x0c08f7fc,0x0c08f82a,0x0c08f842,0x0c08f85a,0x0c08f872,0x0c08f88a,0x0c08f8a2};
    static const uint32_t output_pools[]={0,0x0c08f980,0x0c08f984,0x0c08f988,0x0c08f98c,0x0c08f990,0x0c08f994};
    static const uint32_t tangent_pools[]={0x0c08f816,0x0c08f818,0x0c08f982,0x0c08f986,0x0c08f98a,0x0c08f98e,0x0c08f992};
    for(unsigned channel=0;channel<7;channel++){
        R(0)=4+channel*4;
        if(channel==0){vf3_matrix_load(s,ram,8,R(13)+R(0));vf3_matrix_load(s,ram,9,R(12)+R(0));}
        else {vf3_matrix_load(s,ram,9,R(12)+R(0));vf3_matrix_load(s,ram,8,R(13)+R(0));}
        R(0)=word(ram,tangent_pools[channel]);if(channel>=2)move(s,5,14);vf3_matrix_load(s,ram,7,R(14)+R(0));R(0)+=4;vf3_matrix_load(s,ram,6,R(14)+R(0));
        if(channel<2){move(s,5,14);}
        R(16)=returns[channel];move(s,4,15);if(!vf3_matrix_family(0x0c08f582,s,ram))return 0;
        if(channel==6){R(15)+=4;R(0)=word(ram,output_pools[channel]);R(16)=pop(s,ram);binary(s,15,13,'+');}
        else R(0)=channel==0?108:word(ram,output_pools[channel]);
        vf3_matrix_store(s,ram,0,R(14)+R(0));
    }
    R(0)=word(ram,0x0c08f996);vf3_matrix_store(s,ram,15,R(14)+R(0));restore_float(s,ram,13);restore_float(s,ram,14);restore_float(s,ram,15);
    R(12)=pop(s,ram);R(13)=pop(s,ram);R(14)=pop(s,ram);s->pc=R(16);return ram->oob==0;
}
