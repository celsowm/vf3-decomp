/* Position and orient two indicator resources around the task's object.
 * Resource 0x105e is selected when the real generator's low six bits are nonzero. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#define R(n) s->v[n]
#define FR(n) s->v[21+(n)]
static int call(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t target,uint32_t next)
{
    R(16)=next;
    return vf3_matrix_family(target,s,ram) && s->pc==next;
}
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    uint32_t value=vf3_matrix_read(ram,R(15),4); R(15)+=4; return value;
}
int vf3_scene_indicator(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    R(15)-=4; vf3_matrix_write(ram,R(15),R(16),4);
    R(14)=vf3_matrix_read(ram,R(4)+R(0),4);
    R(0)=0x0c08a6b8; vf3_matrix_load(s,ram,3,R(0));
    R(0)=4; R(15)-=16; vf3_matrix_store(s,ram,3,R(15)+R(0));
    R(0)=8; FR(3)=0x3f800000; vf3_matrix_store(s,ram,3,R(15)+R(0));
    R(0)=0x0c08a6bc; vf3_matrix_load(s,ram,3,R(0));
    R(0)=12; vf3_matrix_store(s,ram,3,R(15)+R(0));
    R(0)=0x438; R(3)=0x0c069624; vf3_matrix_load(s,ram,3,R(14)+R(0));
    R(0)=12; vf3_matrix_load(s,ram,5,R(15)+R(0)); R(0)=0x430;
    FR(5)=vf3_fpu_binary(FR(5),FR(3),R(18),'-');
    vf3_matrix_load(s,ram,3,R(14)+R(0));
    R(0)=4; vf3_matrix_load(s,ram,4,R(15)+R(0));
    FR(4)=vf3_fpu_binary(FR(4),FR(3),R(18),'-');
    if(!call(s,ram,R(3),0x0c08a650)) return 0;
    R(0)=(uint32_t)(int32_t)(int16_t)R(0); vf3_matrix_write(ram,R(15),R(0),2);
    R(3)=0x0c03c4f0; R(4)=0;
    if(!call(s,ram,R(3),0x0c08a65a)) return 0;
    R(2)=0x0c03ccb0; if(!call(s,ram,R(2),0x0c08a660)) return 0;
    R(0)=0x0c08a6cc; R(3)=0x0c03cb70; vf3_matrix_load(s,ram,15,R(0));
    vf3_matrix_move(s,5,15); vf3_matrix_move(s,6,15); vf3_matrix_move(s,4,15);
    if(!call(s,ram,R(3),0x0c08a66e)) return 0;
    R(2)=0x0c03cbd0; R(4)=R(15)+4;
    if(!call(s,ram,R(2),0x0c08a676)) return 0;
    R(2)=0x0c03c880; R(3)=0x8000;
    R(4)=(uint32_t)(int32_t)(int16_t)vf3_matrix_read(ram,R(15),2); R(4)+=R(3);
    if(!call(s,ram,R(2),0x0c08a680)) return 0;
    R(3)=0x0c0a7662; R(4)=0x105d;
    if(!call(s,ram,R(3),0x0c08a688)) return 0;
    R(2)=0x0c0c9cc0; if(!call(s,ram,R(2),0x0c08a68e)) return 0;
    R(17)=(R(17)&~1u)|((R(0)&63u)==0);
    if(!(R(17)&1u)) {
        R(2)=0x0c0a7662; R(4)=0x105e;
        if(!call(s,ram,R(2),0x0c08a69a)) return 0;
    }
    R(3)=0x0c03c4a0; R(4)=1;
    if(!call(s,ram,R(3),0x0c08a6a0)) return 0;
    R(15)+=16; R(16)=pop(s,ram);
    vf3_matrix_load(s,ram,15,R(15)); R(15)+=(R(18)&0x100000u)?8:4;
    R(14)=pop(s,ram); s->pc=R(16); return ram->oob==0;
}
