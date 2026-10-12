/* Restore the paired replay frame and refresh each actor's peer transform.
 * Development helper; no frozen-owner coverage is credited yet. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
#define WRITE(a,v,n) vf3_matrix_write(ram,(a),(v),(n))
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t v){R(15)-=4;WRITE(R(15),v,4);}
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram){uint32_t v=READ(R(15),4);R(15)+=4;return v;}
static int call(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t target,uint32_t returned){R(16)=returned;return vf3_matrix_family(target,s,ram);}

int vf3_replay_pair_reset_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    push(s,ram,R(14));R(0)=84;push(s,ram,R(13));push(s,ram,R(12));push(s,ram,R(11));
    R(14)=READ(0x0c0a92a0,4);push(s,ram,R(16));R(4)=READ(R(14)+R(0),4);R(13)=READ(R(14)+16,4);
    R(4)=READ(R(4)+20,4);R(4)--;R(17)=(R(17)&~1u)|((int32_t)R(4)>=0);R(11)=READ(R(14)+20,4);
    if(!(R(17)&1))R(4)=(uint32_t)(int32_t)(int16_t)READ(0x0c0a9292,2);
    R(4)<<=2;R(12)=READ(0x0c0a92a4,4);R(4)<<=2;R(5)=R(13);R(4)<<=2;R(6)=R(11);
    R(17)=(R(17)&~1u)|(R(4)>>31);R(4)<<=1;R(12)+=R(4);R(4)=R(12);
    if(!call(s,ram,0x0c0a94d0,0x0c0a920c))return 0;
    R(3)=READ(0x0c0a92a8,4);R(0)=40;R(6)=R(13);R(5)=R(11);vf3_matrix_load(s,ram,4,R(3));R(12)+=64;
    vf3_matrix_store(s,ram,4,R(13)+R(0));R(4)=R(12);
    if(!call(s,ram,0x0c0a94d0,0x0c0a921e))return 0;
    R(3)=READ(0x0c0a92ac,4);R(0)=40;vf3_matrix_load(s,ram,4,R(3));vf3_matrix_store(s,ram,4,R(13)+R(0));
    R(13)=READ(R(14)+16,4);R(14)=READ(R(14)+20,4);R(2)=READ(0x0c0a92b0,4);R(5)=R(14);R(4)=R(13);
    if(!call(s,ram,R(2),0x0c0a9232))return 0;
    R(16)=pop(s,ram);R(5)=R(13);R(3)=READ(0x0c0a92b0,4);R(4)=R(14);
    R(11)=pop(s,ram);R(12)=pop(s,ram);R(13)=pop(s,ram);R(14)=pop(s,ram);
    return vf3_matrix_family(R(3),s,ram);
}
