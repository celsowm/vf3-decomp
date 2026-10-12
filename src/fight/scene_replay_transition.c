/* Replay transition: arm paired actors, clear movement, reset playback and
 * advance the scene phase. Development helper for the input predicate. */
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

int vf3_scene_replay_transition_c(uint32_t entry,vf3_matrix_state *s,const vf3_ram_map *ram)
{
    if(entry==0x0c099540){
        R(0)=word(ram,0x0c0995a2);R(4)=READ(0x0c0995c0,4);push(s,ram,R(16));
        R(3)=byte(ram,R(4)+R(0));condition(s,R(3)==0);
        if(R(17)&1){R(2)=READ(0x0c0995bc,4);if(!call(s,ram,R(2),0x0c099552))return 0;}
        R(2)=READ(0x0c0995b8,4);R(3)=READ(0x0c0995b4,4);R(5)=READ(0x0c0995b0,4);R(4)=READ(R(3),4);
        if(!call(s,ram,R(2),0x0c09955c))return 0;
        R(16)=pop(s,ram);
    }
    push(s,ram,R(14));R(0)=84;push(s,ram,R(13));push(s,ram,R(12));push(s,ram,R(16));
    R(3)=READ(0x0c0995d0,4);R(13)=READ(0x0c0995c0,4);R(15)-=24;WRITE(R(15)+8,R(3),4);
    R(3)=READ(0x0c0995d8,4);R(12)=READ(0x0c0995d4,4);R(4)=READ(R(12)+R(0),4);
    if(!call(s,ram,R(3),0x0c09957a))return 0;
    R(5)=READ(R(12)+16,4);R(4)=1;R(2)=READ(R(5),4);R(2)|=R(4);WRITE(R(5),R(2),4);
    R(5)=READ(R(12)+20,4);R(3)=READ(R(5),4);R(3)|=R(4);WRITE(R(5),R(3),4);
    R(0)=word(ram,0x0c0995ac);R(3)=READ(R(12)+16,4);R(14)=READ(R(13)+R(0),4);condition(s,R(3)==R(14));
    if(R(17)&1){R(0)=word(ram,0x0c0995ae);R(2)=byte(ram,R(13)+R(0));condition(s,(R(2)&R(4))==0);if(!(R(17)&1))goto clear_motion;}
    else {R(0)=word(ram,0x0c0996c4);R(0)=byte(ram,R(13)+R(0));condition(s,(R(0)&2)==0);if(!(R(17)&1))goto clear_motion;}
    R(0)=word(ram,0x0c0996c6);R(0)=byte(ram,R(14)+R(0))&255;condition(s,(R(0)&64)==0);if(!(R(17)&1))goto clear_motion;
    R(0)=24;R(3)=READ(0x0c0996d4,4);vf3_matrix_load(s,ram,5,R(14)+R(0));R(4)=R(15)+12;R(0)=16;vf3_matrix_load(s,ram,4,R(14)+R(0));
    if(!call(s,ram,R(3),0x0c0995fe))return 0;
    condition(s,(R(0)&4)==0);if(!(R(17)&1))goto reset_playback;
clear_motion:
    R(0)=72;R(2)=READ(R(14),4);R(6)=R(15)+4;R(5)=R(15);WRITE(R(15),R(2),4);R(3)=READ(R(14)+R(0),4);WRITE(R(15)+4,R(3),4);
    R(3)=READ(0x0c0996d8,4);R(4)=R(14);if(!call(s,ram,R(3),0x0c099618))return 0;
    R(2)=READ(R(15),4);R(0)=72;R(3)=READ(0x0c0996dc,4);R(2)|=R(3);R(1)=R(2);WRITE(R(15),R(2),4);WRITE(R(14),R(2),4);
    R(2)=READ(R(15)+4,4);WRITE(R(14)+R(0),R(2),4);R(0)=16;R(1)=READ(R(14),4);R(2)=word(ram,0x0c0996c8);R(1)&=R(2);WRITE(R(14),R(1),4);
    s->v[25]=0;vf3_matrix_store(s,ram,4,R(14)+R(0));
    R(0)=24;vf3_matrix_store(s,ram,4,R(14)+R(0));R(0)=36;vf3_matrix_store(s,ram,4,R(14)+R(0));R(0)=44;vf3_matrix_store(s,ram,4,R(14)+R(0));
    R(0)=word(ram,0x0c0996ca);vf3_matrix_store(s,ram,4,R(14)+R(0));R(0)+=8;vf3_matrix_store(s,ram,4,R(14)+R(0));
    R(0)=word(ram,0x0c0996cc);vf3_matrix_store(s,ram,4,R(14)+R(0));R(0)+=8;vf3_matrix_store(s,ram,4,R(14)+R(0));
    R(0)=word(ram,0x0c0996ca);vf3_matrix_store(s,ram,4,R(14)+R(0));R(0)+=8;vf3_matrix_store(s,ram,4,R(14)+R(0));
reset_playback:
    R(0)=word(ram,0x0c0996ce);R(5)=0;WRITE(R(14)+R(0),R(5),4);R(0)+=12;WRITE(R(14)+R(0),R(5),4);
    R(0)=word(ram,0x0c0996d0);R(4)=READ(R(13)+R(0),4);R(0)=24;R(0)=byte(ram,R(13)+R(0))&255;condition(s,R(0)==2);
    if(!(R(17)&1)){R(0)=70;WRITE(R(4)+R(0),R(5),2);R(0)=word(ram,0x0c0996c6);R(0)=byte(ram,R(4)+R(0))&255;condition(s,(R(0)&64)==0);if(!(R(17)&1))goto finish;}
    R(2)=READ(R(4),4);R(3)=READ(0x0c0996e0,4);condition(s,(R(2)&R(3))==0);
    if(R(17)&1){R(3)=READ(0x0c0996e4,4);R(0)=word(ram,0x0c0996d0);R(4)=READ(R(13)+R(0),4);if(!call(s,ram,R(3),0x0c099692))return 0;}
finish:
    R(0)=word(ram,0x0c0996d0);R(3)=READ(0x0c0996e8,4);R(5)=READ(R(13)+R(0),4);R(0)-=4;R(4)=READ(R(13)+R(0),4);
    if(!call(s,ram,R(3),0x0c09969e))return 0;
    R(0)=0x0c0996ec;vf3_matrix_load(s,ram,3,R(0));vf3_matrix_store(s,ram,3,R(13));
    R(2)=READ(R(13)+8,4);R(3)=word(ram,0x0c0996c8);R(2)&=R(3);WRITE(R(13)+8,R(2),4);
    R(1)=READ(R(15)+8,4);R(2)=READ(0x0c0996f0,4);R(0)=byte(ram,R(1)+11);R(0)++;WRITE(R(1)+11,R(0),1);
    if(!call(s,ram,R(2),0x0c0996b8))return 0;
    R(15)+=24;R(16)=pop(s,ram);R(12)=pop(s,ram);R(13)=pop(s,ram);R(14)=pop(s,ram);s->pc=R(16);return ram->oob==0;
}
