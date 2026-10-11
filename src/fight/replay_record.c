/* Restore a replay record into an actor, retaining interpolation and motion
 * transitions. Callable 0x8c0a9036; the frozen owner starts at 0x8c0a9040. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
#define WRITE(a,v,n) vf3_matrix_write(ram,(a),(v),(n))
static uint32_t word(const vf3_ram_map*ram,uint32_t a){return (uint32_t)(int32_t)(int16_t)READ(a,2);}
static uint32_t byte(const vf3_ram_map*ram,uint32_t a){return (uint32_t)(int32_t)(int8_t)READ(a,1);}
static void condition(vf3_matrix_state*s,int yes){R(17)=(R(17)&~1u)|(yes!=0);}
static void push(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t v){R(15)-=4;WRITE(R(15),v,4);}
static uint32_t pop(vf3_matrix_state*s,const vf3_ram_map*ram){uint32_t v=READ(R(15),4);R(15)+=4;return v;}
static int call(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t target,uint32_t returned){R(16)=returned;return vf3_matrix_family(target,s,ram);}
int vf3_replay_record_c(vf3_matrix_state*s,const vf3_ram_map*ram)
{
    push(s,ram,R(14));push(s,ram,R(13));R(13)=R(4);push(s,ram,R(12));push(s,ram,R(11));push(s,ram,R(16));
    R(15)-=24;WRITE(R(15)+4,R(6),4);R(11)=READ(0x0c0a9084,4);R(3)=word(ram,0x0c0a9072);
    R(12)=READ(R(11)+8,4);condition(s,(R(3)&R(12))==0);R(14)=R(5);
    if(!(R(17)&1)){
        R(0)=64;R(1)=0;WRITE(R(14)+R(0),R(1),2);R(3)=1;R(0)=word(ram,0x0c0a9074);
        R(12)=word(ram,R(11)+R(0));condition(s,(R(3)&R(12))==0);
        if(!(R(17)&1)){
            R(6)=READ(R(15)+4,4);R(5)=R(14);R(4)=R(13);
            if(!call(s,ram,0x0c0a8f8c,0x0c0a906a))return 0;
            goto restore;
        }
    }
    /* The normal path copies the original packed widths and float bits. */
    R(0)=4;R(4)=READ(R(13),4);R(3)=0xfffffffeu;R(4)&=R(3);WRITE(R(14),R(4),4);
    vf3_matrix_load(s,ram,5,R(13)+R(0));R(0)=8;vf3_matrix_load(s,ram,6,R(13)+R(0));
    R(0)=12;vf3_matrix_load(s,ram,4,R(13)+R(0));R(0)=32;R(0)=word(ram,R(13)+R(0));WRITE(R(15)+8,R(0),2);
    R(0)=36;R(4)=word(ram,R(13)+R(0));R(0)=56;R(2)=READ(R(13)+48,4);R(6)=READ(R(13)+44,4);
    R(5)=READ(R(13)+16,4);R(7)=READ(R(13)+28,4);WRITE(R(15),R(2),4);R(1)=byte(ram,R(13)+R(0));
    R(0)=20;WRITE(R(15)+R(0),R(1),1);R(0)=42;R(0)=word(ram,R(13)+R(0));WRITE(R(15)+16,R(0),2);
    R(0)=58;R(0)=byte(ram,R(13)+R(0));WRITE(R(15)+12,R(0),1);
    R(0)=16;vf3_matrix_store(s,ram,5,R(14)+R(0));R(0)=20;vf3_matrix_store(s,ram,6,R(14)+R(0));
    R(0)=24;vf3_matrix_store(s,ram,4,R(14)+R(0));R(0)=word(ram,R(15)+8);WRITE(R(14)+30,R(0),2);
    R(0)=62;WRITE(R(14)+R(0),R(4),2);R(0)=word(ram,0x0c0a919c);WRITE(R(14)+R(0),R(4),4);
    R(0)=72;WRITE(R(14)+R(0),R(5),4);R(0)=word(ram,0x0c0a919e);WRITE(R(14)+R(0),R(6),4);
    R(0)=word(ram,0x0c0a91a0);WRITE(R(14)+R(0),R(7),4);R(0)=word(ram,0x0c0a91a2);
    R(2)=READ(R(15),4);WRITE(R(14)+R(0),R(2),4);R(0)=20;R(1)=byte(ram,R(15)+R(0));R(2)=70;
    R(0)=word(ram,0x0c0a91a4);R(2)+=R(14);WRITE(R(14)+R(0),R(1),1);R(0)=word(ram,R(15)+16);WRITE(R(2),R(0),2);
    R(1)=word(ram,0x0c0a91a6);R(0)=byte(ram,R(15)+12);R(1)+=R(11);WRITE(R(1),R(0),1);
    R(0)=97;R(4)=byte(ram,R(14)+R(0));R(0)=(uint32_t)(int32_t)(int8_t)R(4);condition(s,R(0)==8);
    if(R(17)&1){R(0)=57;R(4)=byte(ram,R(13)+R(0));R(0)=word(ram,0x0c0a91a8);WRITE(R(14)+R(0),R(4),1);}
    R(4)=READ(R(13)+20,4);condition(s,R(4)==0);
    if(!(R(17)&1)){R(2)=READ(0x0c0a91b0,4);if(!call(s,ram,R(2),0x0c0a9124))return 0;}
    R(4)=READ(R(13)+24,4);condition(s,R(4)==0);
    if(!(R(17)&1)){R(2)=READ(0x0c0a91b0,4);if(!call(s,ram,R(2),0x0c0a9130))return 0;}
    R(0)=60;R(6)=word(ram,R(14)+R(0));R(0)=34;R(4)=word(ram,R(13)+R(0));R(0)=60;
    R(5)=(uint32_t)(int32_t)(int16_t)R(4);condition(s,R(5)==0);WRITE(R(14)+R(0),R(4),2);
    if(R(17)&1)goto restore;
    R(6)=(uint32_t)(int32_t)(int16_t)R(6);condition(s,R(5)==R(6));
    if(R(17)&1){
        R(0)=word(ram,0x0c0a91aa);R(12)-=3;R(3)=R(12);R(5)=3;R(4)=byte(ram,R(11)+R(0));
        condition(s,(int32_t)R(3)>=(int32_t)R(5));WRITE(R(15),R(12),4);
        if(!(R(17)&1)){R(0)=word(ram,0x0c0a91aa);R(4)++;WRITE(R(11)+R(0),R(4),1);}
        R(3)=READ(R(15),4);condition(s,(int32_t)R(3)>=(int32_t)R(5));
        if(!(R(17)&1)){R(0)=word(ram,0x0c0a91ac);R(1)=1;WRITE(R(14)+R(0),R(1),1);goto changed_motion;}
        R(0)=62;R(4)=word(ram,R(14)+R(0));R(0)=R(4)&0xffffu;condition(s,R(0)==1);R(4)=R(0);
        if(R(17)&1)goto initial_frame;
        R(3)=READ(0x0c0a9298,4);R(4)=R(14);if(!call(s,ram,R(3),0x0c0a91c6))return 0;
        goto pose;
    }
changed_motion:
    R(0)=60;R(2)=word(ram,R(14)+R(0));WRITE(R(15),R(2),2);R(5)=READ(R(15)+4,4);
    R(6)=word(ram,R(15));R(3)=READ(0x0c0a91b4,4);R(4)=R(14);if(!call(s,ram,R(3),0x0c0a918c))return 0;
    R(2)=READ(0x0c0a91b8,4);R(4)=R(14);if(!call(s,ram,R(2),0x0c0a9192))return 0;
initial_frame:
    R(3)=READ(0x0c0a91bc,4);R(4)=R(14);if(!call(s,ram,R(3),0x0c0a9198))return 0;
pose:
    R(2)=READ(0x0c0a929c,4);R(4)=R(14);if(!call(s,ram,R(2),0x0c0a91cc))return 0;
restore:
    R(15)+=24;R(16)=pop(s,ram);R(11)=pop(s,ram);R(12)=pop(s,ram);R(13)=pop(s,ram);R(14)=pop(s,ram);
    s->pc=R(16);return ram->oob==0;
}
