/* Round clock update and replay/history scene transitions. The original
 * callback registrations, descriptor stop order and tail transitions remain
 * explicit; no callback result is supplied by this model. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
#define WRITE(a,v,n) vf3_matrix_write(ram,(a),(v),(n))
static void condition(vf3_matrix_state *s,int yes){R(17)=(R(17)&~1u)|(yes!=0);}
static uint32_t word(const vf3_ram_map *ram,uint32_t a){return (uint32_t)(int32_t)(int16_t)READ(a,2);}
static uint32_t byte(const vf3_ram_map *ram,uint32_t a){return (uint32_t)(int32_t)(int8_t)READ(a,1);}
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t v){R(15)-=4;WRITE(R(15),v,4);}
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram){uint32_t v=READ(R(15),4);R(15)+=4;return v;}
static int call(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t target,uint32_t returned){R(16)=returned;return vf3_matrix_family(target,s,ram);}
static void restore_history(vf3_matrix_state *s,const vf3_ram_map *ram){for(unsigned i=8;i<15;i++)R(i)=pop(s,ram);}

/* Secondary scene dispatch: byte 11 selects an immutable table callback.
 * The temporary stack word is restored before the original tail transfer. */
int vf3_scene_secondary_dispatch_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    R(4)=READ(0x0c096e04,4);R(15)-=4;R(0)=byte(ram,R(4)+11);R(5)=R(0)&255u;R(0)=R(5);WRITE(R(4)+9,R(0),1);
    R(2)=READ(0x0c096e08,4);R(3)=0u-R(5);R(5)<<=2;
    if(R(3)&0x80000000u){unsigned count=((~R(3))&31u)+1u;R(2)=count==32?0:R(2)>>count;}
    else R(2)<<=R(3)&31u;
    WRITE(R(4)+4,R(2),4);R(0)=READ(0x0c096e0c,4);R(3)=READ(R(0)+R(5),4);R(2)=R(3);WRITE(R(15),R(3),4);R(15)+=4;
    return vf3_matrix_family(R(2),s,ram);
}

/* Retire the round's UI/actor tasks, start the next delay, and retain the
 * original conditional return into the fight-scene activation predicate. */
int vf3_round_retire_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    push(s,ram,R(14));push(s,ram,R(13));push(s,ram,R(16));R(3)=READ(0x0c09711c,4);R(13)=READ(0x0c097114,4);
    if(!call(s,ram,R(3),0x0c09706c))return 0;
    R(14)=READ(0x0c097120,4);
    static const unsigned offsets[]={28,16,20,72,92,96,100,32,68};
    static const uint32_t returns[]={0x0c097072,0x0c097076,0x0c09707a,0x0c097080,0x0c097086,0x0c09708c,0x0c097092,0x0c097096,0x0c09709c};
    for(unsigned i=0;i<9;i++){
        if(offsets[i]>=64){R(0)=offsets[i];}
        R(4)=READ(R(14)+offsets[i],4);
        if(!call(s,ram,0x0c0968f8,returns[i]))return 0;
    }
    R(4)=READ(R(14)+32,4);R(0)=16;R(3)=word(ram,0x0c09710e);R(2)=READ(R(4),4);R(16)=pop(s,ram);R(2)&=R(3);WRITE(R(4),R(2),4);
    R(2)=11;R(1)=word(ram,0x0c097110);WRITE(R(13)+12,R(1),4);WRITE(R(13)+R(0),R(2),1);R(0)=byte(ram,R(13)+11);R(0)++;WRITE(R(13)+11,R(0),1);
    R(13)=pop(s,ram);R(14)=pop(s,ram);R(4)=READ(0x0c097114,4);R(3)=READ(R(4)+12,4);condition(s,R(3)==0);
    if(R(17)&1){R(0)=byte(ram,R(4)+11);R(0)++;WRITE(R(4)+11,R(0),1);}
    return vf3_matrix_family(0x0c096d5e,s,ram);
}

int vf3_scene_activate_predicate_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    push(s,ram,R(14));push(s,ram,R(13));push(s,ram,R(16));R(3)=READ(0x0c096e04,4);R(13)=READ(0x0c096e10,4);R(15)-=4;WRITE(R(15),R(3),4);
    R(2)=READ(R(13)+8,4);R(3)=READ(0x0c096e14,4);condition(s,(R(2)&R(3))==0);if(R(17)&1)goto done;
    R(14)=READ(0x0c096e18,4);R(4)=READ(R(14)+32,4);if(!call(s,ram,0x0c096902,0x0c096d7a))return 0;
    R(0)=68;R(4)=READ(R(14)+R(0),4);if(!call(s,ram,0x0c096902,0x0c096d80))return 0;
    R(2)=READ(R(13)+8,4);R(0)=68;R(3)=READ(0x0c096e1c,4);R(2)|=R(3);WRITE(R(13)+8,R(2),4);R(2)=1;
    R(1)=READ(0x0c096e20,4);R(4)=READ(R(14)+R(0),4);WRITE(R(4),R(2),4);if(!call(s,ram,R(1),0x0c096d94))return 0;
    R(5)=READ(R(14)+20,4);R(4)=0;R(6)=READ(R(14)+16,4);R(0)=97;WRITE(R(6)+R(0),R(4),1);WRITE(R(5)+R(0),R(4),1);
    R(0)=96;WRITE(R(6)+R(0),R(4),1);WRITE(R(5)+R(0),R(4),1);R(0)=22;R(3)=READ(R(15),4);R(15)+=4;R(16)=pop(s,ram);WRITE(R(3)+10,R(0),1);
    R(13)=pop(s,ram);R(14)=pop(s,ram);return vf3_matrix_family(0x0c0968d0,s,ram);
done:
    R(15)+=4;R(16)=pop(s,ram);R(13)=pop(s,ram);R(14)=pop(s,ram);s->pc=R(16);return ram->oob==0;
}

/* Coalesce each actor's successive history bytes into a 32-slot value/run
 * ring. Different values begin a new slot; equal values extend its count. */
int vf3_actor_history_run_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    push(s,ram,R(13));push(s,ram,R(12));R(1)=READ(0x0c091f4c,4);R(15)-=4;
    R(3)=READ(0x0c091f48,4);R(2)=READ(R(1),4);condition(s,(R(2)&R(3))==0);
    if(R(17)&1){
        R(6)=READ(0x0c091f40,4);R(0)=R(4);condition(s,R(0)==1);R(5)=READ(R(6)+16,4);R(6)=READ(R(6)+20,4);if(!(R(17)&1))R(5)=R(6);
        R(0)=byte(ram,R(5)+4)&255u;R(6)=READ(0x0c091f44,4);R(3)=R(0);R(0)<<=1;R(0)+=R(3);R(0)<<=2;R(0)<<=2;R(0)<<=1;R(6)+=R(0);
        R(0)=word(ram,0x0c091f3a);R(13)=R(6);R(13)+=32;R(4)=word(ram,R(5)+R(0));R(0)=word(ram,0x0c091f3c);R(7)=R(4);WRITE(R(5)+R(0),R(4),2);
        R(0)=word(ram,0x0c091f3e);R(12)=byte(ram,R(5)+R(0));R(0)=R(6);R(3)=byte(ram,R(4)+R(0));R(0)=R(7);R(0)<<=1;
        R(3)&=255u;WRITE(R(15),R(3),2);R(12)&=255u;R(3)&=65535u;R(1)=word(ram,R(13)+R(0));R(2)=R(12)&65535u;
        condition(s,R(2)==R(3));R(1)++;
        if(!(R(17)&1)){R(0)=word(ram,0x0c091f3a);R(3)=31;R(4)++;R(4)&=R(3);WRITE(R(5)+R(0),R(4),2);R(0)=R(6);WRITE(R(4)+R(0),R(12),1);R(7)=R(4);R(1)=1;}
        R(0)=R(7);R(0)<<=1;WRITE(R(13)+R(0),R(1),2);
    }
    R(15)+=4;R(12)=pop(s,ram);R(13)=pop(s,ram);s->pc=R(16);return ram->oob==0;
}

int vf3_scene_end_predicate_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    R(4)=READ(0x0c098094,4);R(3)=READ(0x0c09809c,4);R(2)=READ(R(4)+8,4);R(6)=READ(0x0c098098,4);condition(s,(R(2)&R(3))==0);
    if(!(R(17)&1))goto finished;
    R(1)=READ(R(4)+8,4);R(3)=READ(0x0c0980a0,4);condition(s,(R(1)&R(3))==0);if(R(17)&1)goto finished;
    R(2)=READ(R(4)+8,4);R(3)=READ(0x0c0980a4,4);condition(s,(R(2)&R(3))==0);R(7)=0;if(R(17)&1)goto next_scene;
    R(0)=41;R(0)=byte(ram,R(4)+R(0))&255u;condition(s,R(0)==3);if(R(17)&1)goto next_scene;
    R(0)=43;R(3)=byte(ram,R(4)+R(0));R(3)++;WRITE(R(4)+R(0),R(3),1);R(5)=READ(R(4)+52,4);R(3)=READ(R(4)+56,4);R(5)+=R(3);
    WRITE(R(4)+48,R(5),4);WRITE(R(4)+52,R(5),4);WRITE(R(4)+56,R(7),4);
next_scene:
    R(0)=16;WRITE(R(6)+R(0),R(7),1);R(0)=10;R(3)=READ(0x0c0980a8,4);WRITE(R(6)+10,R(0),1);return vf3_matrix_family(R(3),s,ram);
finished:
    s->pc=R(16);return ram->oob==0;
}

int vf3_round_clock_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    push(s,ram,R(14));push(s,ram,R(13));push(s,ram,R(16));R(3)=READ(0x0c098bf0,4);
    R(14)=READ(0x0c098bec,4);R(15)-=8;WRITE(R(15)+4,R(3),4);R(2)=READ(0x0c098bf4,4);
    R(4)=R(2);WRITE(R(15),R(2),4);R(3)=READ(0x0c098bf8,4);R(4)+=12;
    if(!call(s,ram,R(3),0x0c098b56))return 0;
    R(4)=R(0)&255u;condition(s,R(4)==0);
    if(R(17)&1){R(0)=word(ram,0x0c098bcc);R(0)=byte(ram,R(14)+R(0));condition(s,R(0)==1);
        if(R(17)&1){R(0)=word(ram,0x0c098bd2);R(3)=READ(0x0c098bfc,4);R(4)=word(ram,0x0c098bd4);R(5)=byte(ram,R(14)+R(0))&255u;
            if(!call(s,ram,R(3),0x0c098b70))return 0;}}
    R(0)=41;R(13)=READ(0x0c098c00,4);R(0)=byte(ram,R(14)+R(0))&255u;condition(s,R(0)==3);
    if(R(17)&1){R(4)=1;if(!call(s,ram,R(13),0x0c098b86))return 0;R(4)=2;}
    else {R(0)=word(ram,0x0c098bd6);R(4)=byte(ram,R(14)+R(0));}
    if(!call(s,ram,R(13),0x0c098b8c))return 0;
    R(4)=READ(0x0c098c04,4);R(6)=READ(0x0c098c08,4);R(5)=READ(R(4)+16,4);R(2)=READ(R(5),4);condition(s,(R(2)&R(6))==0);
    if(!(R(17)&1))goto advance_scene;
    R(4)=READ(R(4)+20,4);R(3)=READ(R(4),4);condition(s,(R(3)&R(6))==0);if(!(R(17)&1))goto advance_scene;
    R(2)=READ(0x0c098c10,4);R(5)=READ(R(14)+20,4);R(1)=READ(0x0c098c14,4);R(3)=READ(0x0c098c0c,4);R(4)=READ(R(2),4);
    condition(s,(int32_t)R(5)>=(int32_t)R(1));R(4)&=R(3);if(R(17)&1)goto tick_clock;
    R(0)=READ(0x0c098c18,4);condition(s,(int32_t)R(5)>(int32_t)R(0));if(!(R(17)&1))goto tick_clock;
    R(0)=41;R(0)=byte(ram,R(14)+R(0))&255u;condition(s,R(0)==3);if(R(17)&1)goto return_scene;
    condition(s,R(4)==0);if(!(R(17)&1))goto return_scene;
    R(2)=READ(R(14)+56,4);R(2)++;WRITE(R(14)+56,R(2),4);goto return_scene;
tick_clock:
    condition(s,R(4)==0);if(!(R(17)&1))goto return_scene;
    R(0)=41;R(0)=byte(ram,R(14)+R(0))&255u;condition(s,R(0)==3);
    if(!(R(17)&1)){R(2)=READ(R(14)+56,4);R(2)++;WRITE(R(14)+56,R(2),4);}
    R(3)=READ(R(14)+20,4);R(3)--;R(2)=R(3);condition(s,(int32_t)R(2)>0);WRITE(R(14)+20,R(3),4);
    if(!(R(17)&1)){R(1)=READ(R(14)+8,4);R(3)=READ(0x0c098d2c,4);R(1)|=R(3);WRITE(R(14)+8,R(1),4);goto advance_scene;}
return_scene:
    R(15)+=8;R(16)=pop(s,ram);R(13)=pop(s,ram);R(14)=pop(s,ram);return vf3_matrix_family(0x0c097ff4,s,ram);
advance_scene:
    R(2)=READ(R(15)+4,4);R(15)+=8;R(16)=pop(s,ram);R(0)=byte(ram,R(2)+11);R(0)++;WRITE(R(2)+11,R(0),1);
    R(13)=pop(s,ram);R(3)=READ(0x0c098d30,4);R(14)=pop(s,ram);return vf3_matrix_family(R(3),s,ram);
}

/* Stop the eight scene tasks in the two original transition chains. */
static int stop_history_tasks(vf3_matrix_state *s,const vf3_ram_map *ram,int reset)
{
    static const unsigned offsets[]={24,16,20,60,64,28,52,56};
    static const uint32_t reset_returns[]={0x0c0992b4,0x0c0992ba,0x0c0992c0,0x0c0992c6,0x0c0992ce,0x0c0992d4,0x0c0992da,0x0c0992e0};
    static const uint32_t continue_returns[]={0x0c099328,0x0c09932e,0x0c099334,0x0c09933a,0x0c099342,0x0c099348,0x0c09934e,0x0c099354};
    for(unsigned i=0;i<8;i++){
        unsigned reg=reset?((i&1)?2:3):((i<4)?((i&1)?3:2):((i&1)?2:3));
        R(reg)=READ(0x0c0993c8,4);if(offsets[i]==64)R(0)=64;R(4)=READ(R(13)+offsets[i],4);
        if(!call(s,ram,R(reg),reset?reset_returns[i]:continue_returns[i]))return 0;
    }
    return 1;
}
int vf3_scene_replay_flow_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    for(int i=14;i>=8;i--){push(s,ram,R(i));}
    push(s,ram,R(16));R(3)=READ(0x0c099258,4);R(14)=READ(0x0c099250,4);
    R(15)-=12;R(11)=READ(0x0c099254,4);WRITE(R(15)+8,R(3),4);R(3)=READ(0x0c099260,4);R(2)=READ(R(14)+8,4);R(13)=READ(0x0c09925c,4);
    condition(s,(R(2)&R(3))==0);if(!(R(17)&1))goto reset_actors;
    R(12)=0;R(1)=READ(R(13)+16,4);WRITE(R(15)+4,R(1),4);R(3)=READ(R(13)+20,4);WRITE(R(15),R(3),4);
    R(0)=word(ram,0x0c099246);WRITE(R(14)+R(0),R(12),1);R(0)+=3;WRITE(R(14)+R(0),R(12),1);R(0)-=2;WRITE(R(14)+R(0),R(12),1);
    R(0)=word(ram,0x0c099248);WRITE(R(14)+R(0),R(12),1);R(0)-=10;WRITE(R(14)+R(0),R(12),1);
    R(10)=READ(R(13)+32,4);R(0)=word(ram,0x0c09924a);R(4)=READ(R(10),4);R(3)=READ(0x0c099264,4);WRITE(R(10)+R(0),R(12),1);
    R(0)=41;R(4)&=R(3);WRITE(R(10),R(4),4);R(0)=byte(ram,R(14)+R(0));R(8)=READ(0x0c099268,4);R(0)&=255u;condition(s,R(0)==3);
    if(!(R(17)&1)){
        R(0)=43;R(3)=byte(ram,R(14)+R(0));R(2)=9;condition(s,(int32_t)R(3)>=(int32_t)R(2));
        if(!(R(17)&1)){R(3)=READ(R(14)+8,4);condition(s,(R(3)&R(8))==0);
            if(!(R(17)&1)){R(2)=READ(0x0c09926c,4);if(!call(s,ram,R(2),0x0c099206))return 0;
                R(3)=READ(0x0c099270,4);R(5)=READ(R(15),4);R(4)=READ(R(15)+4,4);if(!call(s,ram,R(3),0x0c09920e))return 0;}}
    }
    R(3)=READ(0x0c099274,4);R(4)=READ(R(15)+8,4);R(9)=READ(R(14)+8,4);R(4)+=19;if(!call(s,ram,R(3),0x0c099218))return 0;
    R(4)=R(0)&255u;R(0)=41;R(0)=byte(ram,R(14)+R(0))&255u;condition(s,R(0)==3);if(!(R(17)&1))goto test_history_state;
    condition(s,R(4)==0);if(R(17)&1)goto test_history_state;
    R(3)=4;condition(s,(R(9)&R(3))==0);if(R(17)&1)goto test_history_state;
    R(2)=R(9);condition(s,(R(2)&R(8))==0);if(!(R(17)&1))goto test_history_state;
    R(0)=25;R(0)=byte(ram,R(14)+R(0))&255u;condition(s,R(0)==2);if(!(R(17)&1))goto continue_history;
    R(3)=word(ram,0x0c09924c);R(9)|=R(3);WRITE(R(14)+8,R(9),4);goto continue_history;
test_history_state:
    R(0)=25;R(0)=byte(ram,R(14)+R(0))&255u;condition(s,R(0)==2);if(!(R(17)&1))goto test_secondary_state;
    R(3)=READ(R(14)+8,4);condition(s,(R(3)&R(8))==0);if(!(R(17)&1))goto playback_complete;
reset_actors:
    R(4)=READ(R(13)+16,4);R(0)=16;s->v[25]=0;
    for(unsigned actor=0;actor<2;actor++){
        if(actor){R(0)=16;R(4)=READ(R(13)+20,4);}
        vf3_matrix_store(s,ram,4,R(4)+R(0));R(0)=24;vf3_matrix_store(s,ram,4,R(4)+R(0));R(0)=word(ram,0x0c0993b4);
        vf3_matrix_store(s,ram,4,R(4)+R(0));R(0)+=8;vf3_matrix_store(s,ram,4,R(4)+R(0));
    }
    if(!stop_history_tasks(s,ram,1))return 0;
    R(15)+=12;R(16)=pop(s,ram);R(0)=16;WRITE(R(11)+11,R(0),1);R(8)=pop(s,ram);R(3)=READ(0x0c0993cc,4);
    for(unsigned i=9;i<15;i++){R(i)=pop(s,ram);}
    return vf3_matrix_family(R(3),s,ram);
test_secondary_state:
    R(0)=24;R(0)=byte(ram,R(14)+R(0))&255u;condition(s,R(0)==2);if(!(R(17)&1))goto continue_history;
playback_complete:
    R(15)+=12;R(0)=word(ram,0x0c0993b6);R(16)=pop(s,ram);R(3)=1;WRITE(R(14)+R(0),R(3),1);R(0)=13;WRITE(R(11)+11,R(0),1);
    restore_history(s,ram);return vf3_matrix_family(0x0c0994fa,s,ram);
continue_history:
    if(!stop_history_tasks(s,ram,0))return 0;
    R(3)=READ(0x0c0993d4,4);R(0)=84;R(5)=READ(0x0c0993d0,4);R(4)=READ(R(13)+R(0),4);if(!call(s,ram,R(3),0x0c09935e))return 0;
    R(0)=word(ram,0x0c0993b8);R(3)=4;WRITE(R(14)+R(0),R(12),1);R(0)=word(ram,0x0c0993ba);WRITE(R(10)+R(0),R(3),1);
    R(0)=word(ram,0x0c0993bc);R(3)=READ(0x0c0993d8,4);R(4)=READ(R(13)+48,4);WRITE(R(4)+R(0),R(3),4);
    R(3)=word(ram,0x0c0993c0);R(2)=READ(R(14)+8,4);R(4)=word(ram,0x0c0993be);condition(s,(R(2)&R(3))==0);
    if(!(R(17)&1)){R(3)=READ(R(15),4);R(0)=66;R(1)=READ(R(15)+4,4);WRITE(R(3)+R(0),R(12),2);WRITE(R(1)+R(0),R(12),2);
        R(5)=word(ram,0x0c0993c2);R(0)=word(ram,0x0c0993c4);R(4)=R(5);WRITE(R(14)+R(0),R(4),2);
        R(0)=0x0c0993dc;vf3_matrix_load(s,ram,3,R(0));vf3_matrix_store(s,ram,3,R(14));}
    R(15)+=12;WRITE(R(11)+12,R(4),4);R(16)=pop(s,ram);R(3)=31;R(0)=16;WRITE(R(11)+R(0),R(3),1);
    R(0)=byte(ram,R(11)+11);R(0)++;WRITE(R(11)+11,R(0),1);restore_history(s,ram);return vf3_matrix_family(0x0c0993e0,s,ram);
}
