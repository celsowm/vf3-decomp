/* Two moving boundary effects over both actors, followed by the independent
 * task lifetime counter. Retain the original flag transitions, voice request
 * ordering and motion helper calls, including the second sweep's countdown. */
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
static uint32_t byte(const vf3_ram_map *ram,uint32_t a){return (uint32_t)(int32_t)(int8_t)READ(a,1);}
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t v){R(15)-=4;WRITE(R(15),v,4);}
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram){uint32_t v=READ(R(15),4);R(15)+=4;return v;}
static int call(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t target,uint32_t returned){R(16)=returned;return vf3_matrix_family(target,s,ram);}
static void save_float(vf3_matrix_state *s,const vf3_ram_map *ram,unsigned reg){R(15)-=(R(18)&0x100000u)?8:4;vf3_matrix_store(s,ram,reg,R(15));}
static void restore_float(vf3_matrix_state *s,const vf3_ram_map *ram,unsigned reg){vf3_matrix_load(s,ram,reg,R(15));R(15)+=(R(18)&0x100000u)?8:4;}
static int enter_boundary(vf3_matrix_state *s,const vf3_ram_map *ram,int second)
{
    R(2)=READ(second?0x0c08afc0:0x0c08ae84,4);if(second)R(9)=R(13);else R(9)|=R(13);WRITE(R(14)+52,R(2),4);
    R(0)=word(ram,second?0x0c08afb2:0x0c08ae74);WRITE(R(14)+30,R(0),2);R(0)=word(ram,second?0x0c08afb4:0x0c08ae76);
    vf3_matrix_store(s,ram,second?14:15,R(14)+R(0));R(0)+=8;vf3_matrix_store(s,ram,second?15:14,R(14)+R(0));
    R(3)=word(ram,second?0x0c08afb6:0x0c08ae78);WRITE(R(15)+4,R(3),4);R(4)=R(3);
    if(!call(s,ram,R(11),second?0x0c08aebc:0x0c08adf0))return 0;
    R(4)=READ(R(15)+4,4);if(!call(s,ram,R(10),second?0x0c08aec0:0x0c08adf4))return 0;
    R(4)=108;if(!call(s,ram,R(11),second?0x0c08aec4:0x0c08adf8))return 0;
    R(4)=108;if(!call(s,ram,R(10),second?0x0c08aec8:0x0c08adfc))return 0;
    R(0)=70;R(5)=READ(R(12)+20,4);R(6)=word(ram,R(14)+R(0));R(3)=READ(second?0x0c08afc4:0x0c08ae88,4);R(6)&=65535u;R(6)--;R(4)=R(14);
    return call(s,ram,R(3),second?0x0c08aed8:0x0c08ae0c);
}
int vf3_timed_boundary_effect_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    for(int i=14;i>=8;i--){push(s,ram,R(i));}
    for(int i=15;i>=12;i--){save_float(s,ram,(unsigned)i);}
    R(1)=READ(0x0c08ada0,4);push(s,ram,R(16));R(3)=READ(0x0c08ad9c,4);R(2)=READ(R(1),4);R(15)-=20;
    condition(s,(R(2)&R(3))==0);if(!(R(17)&1))goto restore;
    R(12)=READ(0x0c08ada4,4);R(0)=116;R(8)=R(4);R(3)=READ(R(12)+R(0),4);WRITE(R(15)+12,R(3),4);
    R(3)=READ(0x0c08ada8,4);R(2)=READ(0x0c08adac,4);R(4)=READ(R(3),4);condition(s,(R(4)&R(2))==0);if(!(R(17)&1))goto restore;
    R(0)=word(ram,R(8)+18);R(2)=word(ram,0x0c08ad84);R(3)=R(0);R(3)++;condition(s,R(3)==R(2));WRITE(R(15),R(3),4);
    if(R(17)&1){R(2)=READ(R(15)+12,4);R(0)=READ(R(2),4);R(0)|=2;WRITE(R(2),R(0),4);}
    R(3)=READ(R(15),4);R(0)=0x0c08adb0;vf3_matrix_load(s,ram,14,R(0));R(0)=0x0c08adb4;R(53)=R(3);R(13)=1;R(2)=READ(R(15),4);
    R(3)=word(ram,0x0c08ad86);F(3)=vf3_fpu_float(R(53),R(18));R(10)=READ(0x0c08adb8,4);vf3_matrix_load(s,ram,15,R(0));
    condition(s,(int32_t)R(2)>=(int32_t)R(3));R(11)=READ(0x0c08adbc,4);vf3_matrix_move(s,12,3);if(R(17)&1)goto second_boundary;
    R(0)=0x0c08adc0;vf3_matrix_move(s,0,12);vf3_matrix_load(s,ram,4,R(0));R(0)=0x0c08adc4;vf3_matrix_load(s,ram,5,R(0));R(0)=48;
    F(4)=vf3_fpu_mac(F(0),F(5),F(4),R(18));vf3_matrix_move(s,13,4);vf3_matrix_store(s,ram,13,R(8)+R(0));R(0)=READ(R(15),4);WRITE(R(8)+18,R(0),2);
    R(0)=0x0c08adc8;vf3_matrix_load(s,ram,3,R(0));R(0)=16;R(14)=READ(R(12)+16,4);vf3_matrix_store(s,ram,3,R(15)+R(0));R(0)=0x0c08adcc;
    vf3_matrix_load(s,ram,3,R(0));F(13)=vf3_fpu_binary(F(13),F(3),R(18),'+');R(3)=2;
    for(;;){
        R(2)=R(3);condition(s,R(2)==0);WRITE(R(15)+8,R(3),4);if(R(17)&1)break;
        R(0)=word(ram,0x0c08ad88);R(9)=byte(ram,R(14)+R(0));R(0)=word(ram,0x0c08ad8a);R(9)&=255u;
        vf3_matrix_load(s,ram,4,R(14)+R(0));R(0)+=8;vf3_matrix_load(s,ram,5,R(14)+R(0));R(0)=16;vf3_matrix_load(s,ram,3,R(15)+R(0));
        condition(s,value(F(3))>value(F(4)));F(5)^=0x80000000u;
        if(!(R(17)&1)){condition(s,value(F(5))>value(F(13)));}
        if(R(17)&1){R(3)=0xfffffffeu;R(9)&=R(3);}
        else {R(1)=R(9);condition(s,(R(1)&R(13))==0);if(R(17)&1){if(!enter_boundary(s,ram,0))return 0;}}
        R(0)=word(ram,0x0c08ae7a);WRITE(R(14)+R(0),R(9),1);R(3)=READ(R(15)+8,4);R(14)=READ(R(12)+20,4);R(3)--;
    }
second_boundary:
    R(1)=READ(R(15),4);R(2)=word(ram,0x0c08ae7c);condition(s,R(1)==R(2));
    if(R(17)&1){R(3)=READ(R(15)+12,4);R(0)=READ(R(3),4);R(0)|=2;WRITE(R(3),R(0),4);}
    R(2)=READ(R(15),4);R(3)=word(ram,0x0c08ae7e);condition(s,(int32_t)R(2)>=(int32_t)R(3));if(R(17)&1)goto lifetime;
    R(0)=0x0c08ae8c;vf3_matrix_move(s,0,12);vf3_matrix_load(s,ram,4,R(0));R(0)=0x0c08ae90;vf3_matrix_load(s,ram,5,R(0));R(0)=60;
    F(4)=vf3_fpu_mac(F(0),F(5),F(4),R(18));vf3_matrix_move(s,13,4);vf3_matrix_store(s,ram,13,R(8)+R(0));
    R(0)=0x0c08ae94;vf3_matrix_load(s,ram,12,R(0));R(0)=0x0c08ae98;vf3_matrix_load(s,ram,4,R(0));R(14)=READ(R(12)+16,4);
    F(13)=vf3_fpu_binary(F(13),F(4),R(18),'-');R(3)=2;
    for(;;){
        R(2)=R(3);condition(s,R(2)==0);WRITE(R(15),R(3),4);if(R(17)&1)break;
        R(0)=word(ram,0x0c08ae7a);R(9)=byte(ram,R(14)+R(0));R(0)=word(ram,0x0c08ae80);R(9)&=255u;
        vf3_matrix_load(s,ram,5,R(14)+R(0));R(0)+=8;vf3_matrix_load(s,ram,4,R(14)+R(0));condition(s,value(F(5))>value(F(12)));F(4)^=0x80000000u;
        if(!(R(17)&1)){condition(s,value(F(13))>value(F(4)));}
        if(R(17)&1)R(9)=0;
        else {R(2)=R(9);condition(s,(R(2)&R(13))==0);if(R(17)&1){if(!enter_boundary(s,ram,1))return 0;}}
        R(0)=word(ram,0x0c08afb8);WRITE(R(14)+R(0),R(9),1);R(3)=READ(R(15),4);R(14)=READ(R(12)+20,4);R(3)--;
    }
lifetime:
    R(2)=READ(0x0c08afc8,4);R(0)=byte(ram,R(2))&255u;condition(s,(R(0)&16)==0);if(!(R(17)&1))goto restore;
    R(0)=word(ram,R(8)+16);R(3)=word(ram,0x0c08afba);R(4)=R(0);R(5)=READ(R(15)+12,4);R(4)++;condition(s,R(4)==R(3));R(5)=READ(R(5),4);
    if(R(17)&1){R(1)=8;R(5)|=R(1);}
    R(3)=word(ram,0x0c08afbc);condition(s,(int32_t)R(4)>=(int32_t)R(3));if(R(17)&1){R(1)=4;R(5)|=R(1);R(4)=0;}
    R(0)=0x0c08afcc;R(3)=READ(R(15)+12,4);WRITE(R(3),R(5),4);R(53)=R(4);vf3_matrix_load(s,ram,5,R(0));R(0)=0x0c08afd0;vf3_matrix_load(s,ram,4,R(0));R(0)=32;
    F(3)=vf3_fpu_float(R(53),R(18));vf3_matrix_move(s,0,3);F(5)=vf3_fpu_mac(F(0),F(4),F(5),R(18));vf3_matrix_move(s,6,3);vf3_matrix_move(s,4,5);
    vf3_matrix_store(s,ram,4,R(8)+R(0));R(0)=R(4);WRITE(R(8)+16,R(0),2);
restore:
    R(15)+=20;R(16)=pop(s,ram);for(unsigned fr=12;fr<16;fr++){restore_float(s,ram,fr);}
    for(unsigned i=8;i<15;i++){R(i)=pop(s,ram);}s->pc=R(16);return ram->oob==0;
}
