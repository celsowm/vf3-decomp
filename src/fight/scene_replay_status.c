/* Replay readiness and completion transitions, retaining the original
 * status-byte reads, helper calls and scene-end tail transfer. */
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

int vf3_replay_ready_marker_c(uint32_t entry,vf3_matrix_state *s,const vf3_ram_map *ram)
{
    if(entry==0x0c0a9244){
        R(3)=READ(0x0c0a92b4,4);R(7)=1;WRITE(R(3),R(7),1);R(2)=READ(0x0c0a92b8,4);R(5)=READ(R(4),4);condition(s,(R(5)&R(2))==0);
        if(!(R(17)&1))goto first_marker;
        R(3)=READ(0x0c0a92bc,4);R(0)=72;condition(s,(R(5)&R(3))==0);R(6)=READ(R(4)+R(0),4);if(!(R(17)&1))goto first_marker;
        R(4)=READ(0x0c0a92c0,4);condition(s,(R(6)&R(4))==0);if(!(R(17)&1))goto done;
first_marker:
        R(2)=READ(0x0c0a92b4,4);WRITE(R(2),R(7),1);
    }else{
        R(0)=word(ram,0x0c0a9294);R(6)=1;R(7)=READ(0x0c0a92c4,4);WRITE(R(7)+R(0),R(6),1);
        R(5)=READ(R(4),4);R(3)=READ(0x0c0a92b8,4);condition(s,(R(5)&R(3))==0);if(!(R(17)&1))goto second_marker;
        R(0)=72;R(3)=READ(0x0c0a92bc,4);R(4)=READ(R(4)+R(0),4);condition(s,(R(4)&R(3))==0);if(!(R(17)&1))goto second_marker;
        R(5)=READ(0x0c0a92c0,4);condition(s,(R(4)&R(5))==0);if(!(R(17)&1))goto done;
second_marker:
        R(0)=word(ram,0x0c0a9294);WRITE(R(7)+R(0),R(6),1);
    }
done:
    s->pc=R(16);return ram->oob==0;
}

int vf3_replay_completion_status_c(uint32_t entry,vf3_matrix_state *s,const vf3_ram_map *ram)
{
    if(entry==0x0c0994fa){R(0)=word(ram,0x0c0995a4);R(3)=2;R(4)=READ(0x0c0995c0,4);WRITE(R(4)+R(0),R(3),1);}
    push(s,ram,R(14));R(0)=word(ram,0x0c0995a6);R(14)=READ(0x0c0995c0,4);push(s,ram,R(16));R(3)=byte(ram,R(14)+R(0));condition(s,R(3)==0);
    if(R(17)&1){R(3)=READ(0x0c0995c4,4);R(0)=word(ram,0x0c0995a8);R(4)=READ(R(14)+R(0),4);if(!call(s,ram,R(3),0x0c09951a))return 0;}
    R(0)=word(ram,0x0c0995aa);R(2)=byte(ram,R(14)+R(0));condition(s,R(2)==0);
    if(!(R(17)&1)){
        R(0)=word(ram,0x0c0995a6);R(3)=byte(ram,R(14)+R(0));condition(s,R(3)==0);
        if(!(R(17)&1)){R(16)=pop(s,ram);R(14)=pop(s,ram);return vf3_matrix_family(0x0c099560,s,ram);}
    }else{
        R(3)=READ(0x0c0995c8,4);R(0)=word(ram,0x0c0995ac);R(4)=READ(R(14)+R(0),4);if(!call(s,ram,R(3),0x0c099538))return 0;
    }
    R(16)=pop(s,ram);R(2)=READ(0x0c0995cc,4);R(14)=pop(s,ram);return vf3_matrix_family(R(2),s,ram);
}

int vf3_replay_wait_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    push(s,ram,R(14));push(s,ram,R(13));push(s,ram,R(12));push(s,ram,R(11));push(s,ram,R(16));
    R(3)=READ(0x0c0994bc,4);R(14)=READ(0x0c0994b4,4);R(15)-=4;R(12)=READ(0x0c0994b8,4);WRITE(R(15),R(3),4);
    R(1)=READ(0x0c0994c4,4);R(3)=READ(0x0c0994c0,4);R(2)=READ(R(1),4);condition(s,(R(2)&R(3))==0);if(!(R(17)&1))goto scene_return;
    R(0)=word(ram,0x0c0994ac);R(0)=word(ram,R(14)+R(0));condition(s,(int32_t)R(0)>0);
    if(R(17)&1){R(0)=word(ram,0x0c0994ac);R(3)=word(ram,R(14)+R(0));R(3)--;WRITE(R(14)+R(0),R(3),2);}
    R(0)=word(ram,0x0c0994ae);R(3)=0xfffffff8u;R(4)=READ(R(12)+R(0),4);R(0)+=4;R(13)=READ(R(12)+R(0),4);R(0)=41;
    R(0)=byte(ram,R(14)+R(0));R(1)=R(4);R(11)=R(13);R(1)=(uint32_t)((int32_t)R(1)>>8);R(0)&=255u;
    condition(s,(R(11)&1)!=0);R(11)=(uint32_t)((int32_t)R(11)>>1);condition(s,R(0)==3);
    if(R(17)&1){R(4)|=R(1);R(13)|=R(11);}
    else {condition(s,R(0)==1);if(!(R(17)&1)){R(13)=R(11);R(4)=R(1);}}
    R(3)=word(ram,0x0c0994b0);condition(s,(R(4)&R(3))==0);if(!(R(17)&1))goto test_delay;
    R(3)=READ(0x0c0994c8,4);R(4)=READ(R(15),4);R(11)=READ(R(14)+8,4);R(4)+=19;if(!call(s,ram,R(3),0x0c099448))return 0;
    R(4)=R(0)&255u;R(0)=41;R(0)=byte(ram,R(14)+R(0))&255u;condition(s,R(0)==3);if(!(R(17)&1))goto test_input;
    condition(s,R(4)==0);if(R(17)&1)goto test_input;
    R(3)=READ(0x0c0994cc,4);condition(s,(R(11)&R(3))==0);if(!(R(17)&1))goto test_input;
    R(2)=4;condition(s,(R(11)&R(2))==0);if(!(R(17)&1))goto test_delay;
test_input:
    R(3)=16;condition(s,(R(13)&R(3))==0);if(!(R(17)&1))goto start_playback;
test_delay:
    R(2)=READ(R(12)+12,4);condition(s,(int32_t)R(2)>0);if(!(R(17)&1))goto start_playback;
    R(0)=word(ram,0x0c0994b2);R(4)=byte(ram,R(14)+R(0))&255u;condition(s,R(4)==0);if(R(17)&1)goto scene_return;
    R(0)=R(4);condition(s,R(0)==1);R(15)+=4;R(16)=pop(s,ram);
    R(11)=pop(s,ram);R(12)=pop(s,ram);R(13)=pop(s,ram);R(14)=pop(s,ram);
    return vf3_matrix_family((R(17)&1)?0x0c0994d4:0x0c099504,s,ram);
scene_return:
    R(15)+=4;R(2)=READ(0x0c0994d0,4);R(16)=pop(s,ram);R(11)=pop(s,ram);R(12)=pop(s,ram);R(13)=pop(s,ram);R(14)=pop(s,ram);return vf3_matrix_family(R(2),s,ram);
start_playback:
    R(15)+=4;R(16)=pop(s,ram);R(11)=pop(s,ram);R(12)=pop(s,ram);R(13)=pop(s,ram);R(14)=pop(s,ram);return vf3_matrix_family(0x0c099540,s,ram);
}
