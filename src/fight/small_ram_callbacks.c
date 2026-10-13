/* RAM callbacks for motion settling, command retirement, event admission,
 * and size-profile initialization. Guest ABI state is retained for replay. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <string.h>
#define R(n) s->v[(n)]
#define F(n) s->v[21+(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
#define WRITE(a,v,n) vf3_matrix_write(ram,(a),(v),(n))
static uint32_t byte(const vf3_ram_map *ram,uint32_t a){return (uint32_t)(int32_t)(int8_t)READ(a,1);}
static uint32_t word(const vf3_ram_map *ram,uint32_t a){return (uint32_t)(int32_t)(int16_t)READ(a,2);}
static float value(uint32_t bits){float result;memcpy(&result,&bits,4);return result;}
static void condition(vf3_matrix_state *s,int yes){R(17)=(R(17)&~1u)|(yes!=0);}
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t v){R(15)-=4;WRITE(R(15),v,4);}
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram){uint32_t v=READ(R(15),4);R(15)+=4;return v;}
static int call(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t target,uint32_t returned){R(16)=returned;return vf3_matrix_family(target,s,ram);}
static void save_float(vf3_matrix_state *s,const vf3_ram_map *ram,unsigned reg){R(15)-=4;vf3_matrix_store(s,ram,reg,R(15));}
static void restore_float(vf3_matrix_state *s,const vf3_ram_map *ram,unsigned reg){vf3_matrix_load(s,ram,reg,R(15));R(15)+=4;}

int vf3_motion_settle_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    if(R(18)&0x100000u)return 0;
    push(s,ram,R(14));R(14)=R(5);push(s,ram,R(13));push(s,ram,R(12));R(12)=R(4);
    push(s,ram,R(11));R(11)=R(7);push(s,ram,R(10));save_float(s,ram,15);save_float(s,ram,14);push(s,ram,R(16));
    R(0)=byte(ram,R(11));R(15)-=4;R(13)=READ(R(15)+40,4);condition(s,(R(0)&2)==0);R(10)=R(6);
    if(!(R(17)&1))goto restore;
    R(0)=0x0c0887d0;F(15)=READ(R(0),4);R(0)=0x0c0887d4;F(14)=READ(R(0),4);
    R(0)=0x0c0887d8;F(5)=READ(R(0),4);R(0)=0x0c0887dc;F(4)=READ(R(0),4);
    R(0)=0x0c0887e0;F(3)=READ(R(0),4);WRITE(R(15),F(3),4);
    R(0)=byte(ram,R(11));condition(s,(R(0)&1)==0);
    if(!(R(17)&1)){
        R(0)=4;F(3)=READ(R(14)+R(0),4);F(3)=vf3_fpu_binary(F(3),F(5),R(18),'+');F(2)=F(3);
        condition(s,value(F(4))>value(F(2)));WRITE(R(14)+R(0),F(3),4);if(R(17)&1)WRITE(R(14)+R(0),F(4),4);
        R(1)=R(0)+R(14);F(2)=READ(R(12)+R(0),4);F(3)=READ(R(1),4);F(2)=vf3_fpu_binary(F(2),F(3),R(18),'+');WRITE(R(12)+R(0),F(2),4);
        R(0)=8;F(2)=READ(R(12),4);R(1)=R(0)+R(14);F(3)=READ(R(14),4);F(2)=vf3_fpu_binary(F(2),F(3),R(18),'+');WRITE(R(12),F(2),4);
        F(2)=READ(R(12)+R(0),4);F(3)=READ(R(1),4);F(2)=vf3_fpu_binary(F(2),F(3),R(18),'-');WRITE(R(12)+R(0),F(2),4);
        R(3)=READ(0x0c0887e4,4);F(5)=F(2)^0x80000000u;F(4)=READ(R(12),4);
        if(!call(s,ram,R(3),0x0c088642))return 0;
        R(0)=8;WRITE(R(10),F(0),4);F(3)=READ(R(14),4);F(3)=vf3_fpu_binary(F(3),F(15),R(18),'*');WRITE(R(14),F(3),4);
        F(2)=READ(R(14)+R(0),4);F(2)=vf3_fpu_binary(F(2),F(15),R(18),'*');WRITE(R(14)+R(0),F(2),4);
        R(0)=4;F(2)=READ(R(12)+R(0),4);F(3)=READ(R(10),4);condition(s,value(F(2))>value(F(3)));
        if(R(17)&1){
            R(2)=byte(ram,R(13));R(2)++;WRITE(R(13),R(2),1);R(2)=32;R(3)=byte(ram,R(13));condition(s,(int32_t)R(3)>(int32_t)R(2));
            if(R(17)&1){R(1)=0;WRITE(R(13),R(1),1);}
            F(4)=READ(R(14)+R(0),4);F(3)=READ(R(15),4);F(4)&=0x7fffffffu;F(4)=vf3_fpu_binary(F(4),F(3),R(18),'*');
            R(3)=READ(R(15)+36,4);R(2)=word(ram,R(3));R(53)=vf3_fpu_ftrc(F(4));R(4)=R(53);R(2)+=R(4);WRITE(R(3),R(2),2);
            goto restore;
        }
        R(0)=byte(ram,R(11));R(0)&=254u;WRITE(R(11),R(0),1);R(0)=4;F(3)=0;WRITE(R(14)+R(0),F(3),4);
        F(3)=READ(R(10),4);WRITE(R(12)+R(0),F(3),4);
    }
    R(0)=8;F(3)=READ(R(14),4);F(3)=vf3_fpu_binary(F(3),F(14),R(18),'*');WRITE(R(14),F(3),4);
    F(2)=READ(R(14)+R(0),4);F(2)=vf3_fpu_binary(F(2),F(14),R(18),'*');WRITE(R(14)+R(0),F(2),4);
    R(3)=byte(ram,R(13));condition(s,R(3)==0);
    if(!(R(17)&1)){
        R(1)=byte(ram,R(13));R(3)=16;condition(s,(int32_t)R(1)>=(int32_t)R(3));
        if(!(R(17)&1)){R(1)=byte(ram,R(13));R(1)--;WRITE(R(13),R(1),1);goto restore;}
        R(0)=byte(ram,R(13));R(1)=32;R(0)++;WRITE(R(13),R(0),1);R(2)=byte(ram,R(13));condition(s,(int32_t)R(2)>(int32_t)R(1));
        if(R(17)&1){R(0)=0;WRITE(R(13),R(0),1);}
    }else{
        R(0)=READ(R(15)+36,4);R(3)=0xfffffff5u;R(2)=READ(R(15)+44,4);R(0)=word(ram,R(0));R(0)=(uint32_t)((int32_t)R(0)>>11);R(0)&=15u;WRITE(R(2),R(0),1);
        R(0)=byte(ram,R(11));R(0)|=2u;WRITE(R(11),R(0),1);R(0)=8;F(3)=0;WRITE(R(14)+R(0),F(3),4);WRITE(R(14),F(3),4);
    }
restore:
    R(15)+=4;R(16)=pop(s,ram);restore_float(s,ram,14);restore_float(s,ram,15);
    for(int reg=10;reg<=14;reg++)R(reg)=pop(s,ram);
    s->pc=R(16);return 1;
}

int vf3_command_retire_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    push(s,ram,R(16));R(15)-=12;WRITE(R(15),R(4),4);WRITE(R(15)+4,R(5),4);WRITE(R(15)+8,R(7),4);R(7)=0;
    R(3)=READ(R(15)+16,4);push(s,ram,R(3));R(2)=READ(R(15)+12,4);push(s,ram,R(2));R(5)=READ(R(15)+12,4);
    R(3)=READ(0x0c07b730,4);R(2)=READ(0x0c07b72c,4);R(5)|=R(3);R(4)=READ(R(15)+8,4);
    if(!call(s,ram,R(2),0x0c07b714))return 0;
    R(15)+=20;R(16)=pop(s,ram);s->pc=R(16);return 1;
}

int vf3_event_admission_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    push(s,ram,R(16));R(3)=READ(R(5),4);R(7)=READ(R(5)+20,4);R(15)-=4;WRITE(R(15),R(3),4);
    R(2)=0x2000;condition(s,(R(7)&R(2))==0);R(6)=0;
    if(R(17)&1){
        R(0)=READ(R(15),4);condition(s,(R(0)&4)==0);if(!(R(17)&1))goto finish;
        if(!call(s,ram,0x0c08c12e,0x0c08c070))return 0;
        R(6)=R(0);goto finish;
    }
    R(0)=76;R(3)=0x631;R(7)=READ(R(5)+R(0),4);R(0)=60;R(6)=word(ram,R(7)+R(0));R(0)=80;R(6)&=65535u;
    condition(s,R(6)==R(3));R(7)=READ(R(7)+R(0),4);
    if(!(R(17)&1)){
        static const uint32_t types[]={0x338,0x339,0x33a,0x33b,0x33c};
        for(unsigned i=0;i<5;i++){R((i&1)?3:2)=types[i];condition(s,R(6)==types[i]);if(R(17)&1)break;}
        if(!(R(17)&1)){
            if(!call(s,ram,0x0c08c162,0x0c08c0aa))return 0;
            R(6)=R(0);goto finish;
        }
    }
    R(2)=READ(0x0c08c0e0,4);condition(s,(R(7)&R(2))==0);
    if(R(17)&1){R(15)+=4;R(16)=pop(s,ram);R(1)=3;WRITE(R(5)+44,R(1),4);R(0)=1;s->pc=R(16);return 1;}
    if(!call(s,ram,0x0c08c12e,0x0c08c0e8))return 0;
    R(6)=R(0);
finish:
    R(0)=R(6);R(15)+=4;R(16)=pop(s,ram);s->pc=R(16);return 1;
}

int vf3_size_profile_init_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    push(s,ram,R(14));R(14)=R(4);push(s,ram,R(16));R(3)=word(ram,0x0c086156);R(3)+=R(14);R(15)-=4;WRITE(R(15),R(3),4);
    if(!call(s,ram,0x0c085ca4,0x0c0860d2))return 0;
    R(0)=96;R(3)=1;R(2)=50;WRITE(R(14)+4,R(3),4);WRITE(R(14),R(2),2);
    R(5)=READ(0x0c086168,4);R(7)=READ(0x0c08616c,4);R(6)=READ(R(5)+16,4);R(5)=READ(R(5)+20,4);
    R(6)=byte(ram,R(6)+R(0));R(5)=byte(ram,R(5)+R(0));R(6)&=255u;R(4)=word(ram,0x0c086158);
    R(0)=R(6)<<1;R(5)&=255u;R(6)=word(ram,R(7)+R(0));R(0)=R(5)<<1;R(5)=word(ram,R(7)+R(0));
    R(4)-=R(6);F(2)=0x3f800000u;R(4)-=R(5);R(53)=R(4);F(3)=vf3_fpu_float(R(53),R(18));
    F(3)=vf3_fpu_binary(F(3),F(2),R(18),'*');R(53)=vf3_fpu_ftrc(F(3));R(4)=R(53);
    condition(s,(int32_t)R(4)>=0);if(!(R(17)&1))R(4)=0;
    R(3)=R(4);WRITE(R(14)+16,R(4),4);R(2)=READ(R(15),4);R(4)<<=2;R(15)+=4;R(4)+=R(3);R(16)=pop(s,ram);
    R(4)<<=2;R(4)+=R(2);WRITE(R(14)+20,R(4),4);R(14)=pop(s,ram);s->pc=R(16);return 1;
}

/* Original initializer helper: clear 3072 words, retaining the ABI count,
 * pointer and final DT condition. This dependency receives no new credit. */
int vf3_profile_clear_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    R(5)=word(ram,0x0c085d5e);R(6)=0;
    do {R(5)--;condition(s,R(5)==0);WRITE(R(4),R(6),4);R(4)+=4;} while(!(R(17)&1));
    s->pc=R(16);return 1;
}

/* Two actor-specific registration passes. Types 8 and 21 dispatch the real
 * downstream helper; unsupported downstream state remains a replay failure. */
static int register_actor_profile(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    push(s,ram,R(16));R(0)=96;R(15)-=8;WRITE(R(15)+4,R(5),4);
    R(0)=byte(ram,R(4)+R(0));R(5)=READ(0x0c09525c,4);R(0)&=255u;condition(s,R(0)==8);
    if(R(17)&1){R(2)=word(ram,0x0c09524e);R(6)=15;R(5)+=R(2);WRITE(R(15),R(5),4);R(3)=READ(R(15)+4,4);push(s,ram,R(3));R(7)=READ(R(15)+4,4);R(5)=0;}
    else {condition(s,R(0)==21);if(!(R(17)&1))goto done;
        R(2)=word(ram,0x0c095250);R(6)=15;R(5)+=R(2);WRITE(R(15),R(5),4);R(5)=1;R(3)=READ(R(15)+4,4);push(s,ram,R(3));R(7)=READ(R(15)+4,4);}
    if(!call(s,ram,0x0c0951d2,0x0c0951c8))return 0;
    R(15)+=4;
done:
    R(15)+=8;R(16)=pop(s,ram);s->pc=R(16);return 1;
}
int vf3_actor_profile_pair_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    R(3)=READ(0x0c095254,4);push(s,ram,R(16));R(4)=READ(R(3),4);R(16)=0x0c095182;R(5)=0;
    if(!register_actor_profile(s,ram))return 0;
    R(3)=READ(0x0c095258,4);R(5)=0;R(4)=READ(R(3),4);R(16)=pop(s,ram);
    return register_actor_profile(s,ram);
}
