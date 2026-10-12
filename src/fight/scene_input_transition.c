/* Scene input predicate: combine paired input banks, delay confirmation and
 * enter the original selection-task transition. Development candidate. */
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
static void restore(vf3_matrix_state *s,const vf3_ram_map *ram)
{R(15)+=4;R(16)=pop(s,ram);for(unsigned n=11;n<=14;n++)R(n)=pop(s,ram);}

int vf3_scene_input_transition_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    for(unsigned n=14;n>=11;n--)push(s,ram,R(n));push(s,ram,R(16));
    R(3)=READ(0x0c0994bc,4);R(14)=READ(0x0c0994b4,4);R(15)-=4;R(12)=READ(0x0c0994b8,4);WRITE(R(15),R(3),4);
    R(1)=READ(0x0c0994c4,4);R(3)=READ(0x0c0994c0,4);R(2)=READ(R(1),4);condition(s,(R(2)&R(3))==0);
    if(!(R(17)&1))goto wait_scene;
    R(0)=word(ram,0x0c0994ac);R(0)=word(ram,R(14)+R(0));condition(s,(int32_t)R(0)>0);
    if(R(17)&1){R(0)=word(ram,0x0c0994ac);R(3)=word(ram,R(14)+R(0));R(3)--;WRITE(R(14)+R(0),R(3),2);}
    R(0)=word(ram,0x0c0994ae);R(3)=0u-8u;R(4)=READ(R(12)+R(0),4);R(0)+=4;R(13)=READ(R(12)+R(0),4);
    R(0)=41;R(0)=byte(ram,R(14)+R(0));R(1)=R(4);R(11)=R(13);R(1)=(uint32_t)((int32_t)R(1)>>8);R(0)&=255;
    condition(s,R(11)&1u);R(11)=(uint32_t)((int32_t)R(11)>>1);condition(s,R(0)==3);
    if(R(17)&1){R(4)|=R(1);R(13)|=R(11);}
    else {condition(s,R(0)==1);if(!(R(17)&1)){R(13)=R(11);R(4)=R(1);}}
    R(3)=word(ram,0x0c0994b0);condition(s,(R(4)&R(3))==0);if(!(R(17)&1))goto check_clock;
    R(3)=READ(0x0c0994c8,4);R(4)=READ(R(15),4);R(11)=READ(R(14)+8,4);R(4)+=19;
    if(!call(s,ram,R(3),0x0c099448))return 0;
    R(4)=R(0)&255;R(0)=41;R(0)=byte(ram,R(14)+R(0))&255;condition(s,R(0)==3);
    if(R(17)&1){
        condition(s,R(4)==0);
        if(!(R(17)&1)){
            R(3)=READ(0x0c0994cc,4);condition(s,(R(3)&R(11))==0);
            if(R(17)&1){R(2)=4;condition(s,(R(11)&R(2))==0);if(!(R(17)&1))goto check_clock;}
        }
    }
    R(3)=16;condition(s,(R(13)&R(3))==0);if(!(R(17)&1))goto transition;
check_clock:
    R(2)=READ(R(12)+12,4);condition(s,(int32_t)R(2)>0);if(R(17)&1)goto current_phase;
transition:
    restore(s,ram);return vf3_matrix_family(0x0c099540,s,ram);
current_phase:
    R(0)=word(ram,0x0c0994b2);R(4)=byte(ram,R(14)+R(0))&255;condition(s,R(4)==0);if(R(17)&1)goto wait_scene;
    R(0)=R(4);condition(s,R(0)==1);if(!(R(17)&1)){restore(s,ram);return vf3_matrix_family(0x0c099504,s,ram);}
    R(2)=READ(0x0c0995b8,4);R(3)=READ(0x0c0995b4,4);R(5)=READ(0x0c0995b0,4);R(4)=READ(R(3),4);
    if(!call(s,ram,R(2),0x0c0994de))return 0;
    R(0)=word(ram,0x0c0995a2);R(1)=byte(ram,R(14)+R(0));condition(s,R(1)==0);
    if(R(17)&1){R(3)=READ(0x0c0995bc,4);if(!call(s,ram,R(3),0x0c0994ec))return 0;}
    restore(s,ram);return vf3_matrix_family(0x0c0994fa,s,ram);
wait_scene:
    R(15)+=4;R(2)=READ(0x0c0994d0,4);R(16)=pop(s,ram);for(unsigned n=11;n<=14;n++)R(n)=pop(s,ram);
    return vf3_matrix_family(R(2),s,ram);
}
