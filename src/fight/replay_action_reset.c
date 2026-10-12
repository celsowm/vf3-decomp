/* Replay action choice and actor orientation reset. Development helpers. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
#define WRITE(a,v,n) vf3_matrix_write(ram,(a),(v),(n))
static void condition(vf3_matrix_state *s,int yes){R(17)=(R(17)&~1u)|(yes!=0);}
static uint32_t byte(const vf3_ram_map *ram,uint32_t a){return (uint32_t)(int32_t)(int8_t)READ(a,1);}
static uint32_t word(const vf3_ram_map *ram,uint32_t a){return (uint32_t)(int32_t)(int16_t)READ(a,2);}
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t v){R(15)-=4;WRITE(R(15),v,4);}
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram){uint32_t v=READ(R(15),4);R(15)+=4;return v;}
static int call(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t target,uint32_t returned){R(16)=returned;return vf3_matrix_family(target,s,ram);}

int vf3_replay_orientation_reset_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    push(s,ram,R(14));R(14)=R(4);R(4)=READ(0x0c0a94c4,4);R(0)=word(ram,0x0c0a94aa);
    R(6)=READ(R(4)+20,4);R(5)=READ(R(4)+16,4);R(4)=1;push(s,ram,R(16));WRITE(R(5)+R(0),R(4),1);WRITE(R(6)+R(0),R(4),1);
    R(3)=READ(0x0c0a94c8,4);R(5)=byte(ram,R(3));R(0)=(uint32_t)(int32_t)(int8_t)R(5);condition(s,R(0)==2);
    if(R(17)&1){
        R(0)=97;R(5)=byte(ram,R(14)+R(0));R(0)=READ(0x0c0a94cc,4);R(5)<<=2;R(5)>>=2;R(5)<<=2;R(5)=READ(R(5)+R(0),4);
        R(0)=60;WRITE(R(14)+R(0),R(5),2);R(0)=62;WRITE(R(14)+52,R(5),4);WRITE(R(14)+R(0),R(4),2);
        R(0)=16;vf3_matrix_load(s,ram,4,R(14)+R(0));R(0)=24;R(3)=READ(0x0c0a94c0,4);vf3_matrix_load(s,ram,5,R(14)+R(0));s->v[26]^=0x80000000u;
        if(!call(s,ram,R(3),0x0c0a9488))return 0;
        R(0)=36;s->v[25]=0;s->v[26]=s->v[21];vf3_matrix_store(s,ram,4,R(14)+R(0));R(0)=40;vf3_matrix_store(s,ram,4,R(14)+R(0));
        R(0)=44;vf3_matrix_store(s,ram,4,R(14)+R(0));R(0)=20;vf3_matrix_store(s,ram,5,R(14)+R(0));R(0)=word(ram,0x0c0a94ac);vf3_matrix_store(s,ram,5,R(14)+R(0));
    }
    R(16)=pop(s,ram);R(14)=pop(s,ram);s->pc=R(16);return ram->oob==0;
}

int vf3_replay_action_reset_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    push(s,ram,R(14));R(14)=R(4);push(s,ram,R(13));R(13)=1;push(s,ram,R(12));R(12)=READ(0x0c0a93b8,4);R(0)=word(ram,0x0c0a939e);
    R(6)=READ(R(12)+20,4);R(4)=READ(R(12)+16,4);push(s,ram,R(16));WRITE(R(4)+R(0),R(13),1);WRITE(R(6)+R(0),R(13),1);
    R(0)=byte(ram,R(14)+4);R(15)-=4;R(3)=READ(0x0c0a93bc,4);R(6)=(uint32_t)(int32_t)(int8_t)R(0);condition(s,R(6)==0);R(4)=READ(R(3),4);if(!(R(17)&1))R(4)>>=8;
    R(0)=97;R(3)=byte(ram,R(14)+R(0));WRITE(R(15),R(3),1);R(7)=byte(ram,R(15));R(0)=R(7);condition(s,R(0)==3);R(6)=R(4);
    if(!(R(17)&1)){R(0)=R(7);condition(s,R(0)==1);}
    if(R(17)&1){
        R(3)=READ(0x0c0a93c0,4);R(2)=word(ram,0x0c0a93a0);R(4)&=R(3);condition(s,R(4)==R(2));
        if(R(17)&1){R(0)=word(ram,0x0c0a93a2);R(3)=28;R(4)=READ(R(12)+32,4);WRITE(R(4)+R(0),R(3),4);R(0)=word(ram,0x0c0a939e);WRITE(R(14)+R(0),R(13),1);
            R(0)=R(7);R(4)=word(ram,0x0c0a93a4);condition(s,R(0)==3);if(!(R(17)&1))R(4)=word(ram,0x0c0a93a6);goto install_action;}
    }
    R(7)=READ(0x0c0a93c4,4);R(0)=24;R(4)=byte(ram,R(7)+R(0));condition(s,R(4)==0);
    if(R(17)&1){
        R(4)=R(0);R(0)=word(ram,0x0c0a93a8);R(2)=word(ram,R(14)+R(0));R(0)=70;R(3)=word(ram,R(14)+R(0))&65535;condition(s,R(2)==R(3));
        if(R(17)&1){R(0)=97;R(2)=byte(ram,R(5)+R(0));condition(s,R(2)==0);if(!(R(17)&1))goto publish_choice;
            R(0)=byte(ram,R(14)+R(0))&255;condition(s,R(0)==6);if(!(R(17)&1))goto publish_choice;
            R(0)=word(ram,0x0c0a93a2);R(3)=28;R(4)=READ(R(12)+32,4);WRITE(R(4)+R(0),R(3),4);R(4)=word(ram,0x0c0a93aa);R(0)=word(ram,0x0c0a939e);WRITE(R(14)+R(0),R(13),1);goto install_action;}
    }
    R(4)=word(ram,0x0c0a93ac);R(2)=R(6)&R(4);condition(s,R(2)==R(4));if(R(17)&1){R(4)=16;goto publish_choice;}
    R(4)=word(ram,0x0c0a93ae);R(2)=R(6)&R(4);condition(s,R(2)==R(4));if(R(17)&1){R(4)=20;goto publish_choice;}
    R(3)=word(ram,0x0c0a93b0);condition(s,(R(6)&R(3))==0);if(!(R(17)&1)){R(4)=0;goto publish_choice;}
    R(3)=word(ram,0x0c0a93b2);condition(s,(R(6)&R(3))==0);if(!(R(17)&1)){R(4)=4;goto publish_choice;}
    R(2)=word(ram,0x0c0a93b4);condition(s,(R(6)&R(2))==0);if(!(R(17)&1)){R(4)=8;goto publish_choice;}
    R(2)=word(ram,0x0c0a94a6);condition(s,(R(6)&R(2))==0);if(!(R(17)&1)){R(4)=12;goto publish_choice;}
    R(1)=READ(0x0c0a94b4,4);R(3)=READ(0x0c0a94b0,4);R(4)=READ(R(7)+8,4);condition(s,(R(4)&R(3))==0);
    if(!call(s,ram,R(1),0x0c0a93dc))return 0;
    R(2)=READ(0x0c0a94b8,4);R(1)=R(0);R(0)=6;if(!call(s,ram,R(2),0x0c0a93e4))return 0;R(4)=R(0)<<2;
publish_choice:
    R(0)=word(ram,0x0c0a94a8);R(5)=READ(R(12)+32,4);WRITE(R(5)+R(0),R(4),4);R(4)>>=2;R(0)=word(ram,0x0c0a94aa);R(5)=R(4)<<2;WRITE(R(14)+R(0),R(13),1);
    R(0)=READ(0x0c0a94bc,4);R(5)=READ(R(5)+R(0),4);R(0)=97;R(0)=byte(ram,R(14)+R(0))&255;R(17)=(R(17)&~1u)|(R(0)>>31);R(0)<<=1;R(4)=word(ram,R(5)+R(0))&65535;
install_action:
    R(0)=60;WRITE(R(14)+R(0),R(4),2);R(0)=62;WRITE(R(14)+52,R(4),4);WRITE(R(14)+R(0),R(13),2);
    R(0)=16;vf3_matrix_load(s,ram,4,R(14)+R(0));R(0)=24;R(3)=READ(0x0c0a94c0,4);vf3_matrix_load(s,ram,5,R(14)+R(0));s->v[26]^=0x80000000u;
    if(!call(s,ram,R(3),0x0c0a9420))return 0;
    R(0)=36;s->v[26]=0;R(15)+=4;s->v[25]=s->v[21];vf3_matrix_store(s,ram,5,R(14)+R(0));R(0)=40;vf3_matrix_store(s,ram,5,R(14)+R(0));R(0)=44;R(16)=pop(s,ram);
    vf3_matrix_store(s,ram,5,R(14)+R(0));R(0)=20;vf3_matrix_store(s,ram,4,R(14)+R(0));R(0)=word(ram,0x0c0a94ac);vf3_matrix_store(s,ram,4,R(14)+R(0));
    R(12)=pop(s,ram);R(13)=pop(s,ram);R(14)=pop(s,ram);s->pc=R(16);return ram->oob==0;
}
