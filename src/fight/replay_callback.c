/* Advance a paired history replay, retaining pause, odd-frame interpolation,
 * wraparound, completion and the original actor update order. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
#define WRITE(a,v,n) vf3_matrix_write(ram,(a),(v),(n))
static void condition(vf3_matrix_state*s,int yes){R(17)=(R(17)&~1u)|(yes!=0);}
static uint32_t word(const vf3_ram_map*ram,uint32_t a){return (uint32_t)(int32_t)(int16_t)READ(a,2);}
static void push(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t v){R(15)-=4;WRITE(R(15),v,4);}
static uint32_t pop(vf3_matrix_state*s,const vf3_ram_map*ram){uint32_t v=READ(R(15),4);R(15)+=4;return v;}
static int call(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t target,uint32_t returned){R(16)=returned;return vf3_matrix_family(target,s,ram);}
int vf3_replay_callback_c(vf3_matrix_state*s,const vf3_ram_map*ram)
{
    push(s,ram,R(14));push(s,ram,R(13));push(s,ram,R(12));push(s,ram,R(11));push(s,ram,R(10));push(s,ram,R(16));
    R(3)=READ(0x0c0a8f54,4);R(15)-=4;WRITE(R(15),R(4),4);
    if(!call(s,ram,R(3),0x0c0a8e2c))return 0;
    condition(s,R(0)==0);if(R(17)&1)goto restore;
    R(1)=READ(0x0c0a8f5c,4);R(3)=READ(0x0c0a8f58,4);R(2)=READ(R(1),4);
    condition(s,(R(2)&R(3))==0);if(!(R(17)&1))goto restore;
    R(3)=READ(0x0c0a8f64,4);R(14)=READ(0x0c0a8f60,4);R(12)=READ(R(15),4);R(4)=READ(R(14)+16,4);
    if(!call(s,ram,R(3),0x0c0a8e44))return 0;
    R(2)=READ(0x0c0a8f64,4);R(4)=READ(R(14)+20,4);if(!call(s,ram,R(2),0x0c0a8e4a))return 0;
    R(4)=READ(R(12)+16,4);R(13)=READ(0x0c0a8f68,4);R(4)<<=2;R(3)=READ(0x0c0a8f6c,4);R(4)<<=2;
    R(10)=READ(R(14)+16,4);R(4)<<=2;R(11)=READ(R(14)+20,4);R(4)<<=1;R(5)=R(10);R(13)+=R(4);
    R(6)=R(11);WRITE(R(3),R(13),4);R(4)=R(13);if(!call(s,ram,0x0c0a9036,0x0c0a8e68))return 0;
    R(5)=R(11);R(6)=R(10);R(13)+=64;R(4)=R(13);if(!call(s,ram,0x0c0a9036,0x0c0a8e72))return 0;
    R(5)=READ(0x0c0a8f70,4);R(2)=READ(0x0c0a8f74,4);R(6)=READ(R(5)+8,4);R(4)=READ(R(12)+16,4);
    R(6)<<=16;R(6)<<=2;R(6)<<=2;condition(s,(R(6)&R(2))==0);R(7)=READ(R(12)+20,4);
    if(!(R(17)&1)){
        R(0)=word(ram,0x0c0a8f4c);R(6)=word(ram,R(5)+R(0));R(0)=(uint32_t)(int32_t)(int16_t)R(6);
        condition(s,(R(0)&1)==0);if(!(R(17)&1))goto compare_end;
    }
    R(3)=word(ram,0x0c0a8f4e);R(4)++;condition(s,R(4)>R(3));if(R(17)&1)R(4)=0;
compare_end:
    condition(s,R(4)==R(7));R(13)=0xfffffffeu;
    if(R(17)&1){
        R(0)=word(ram,0x0c0a8f50);R(2)=1;WRITE(R(5)+R(0),R(2),1);R(0)=84;R(4)=READ(R(14)+R(0),4);
        R(3)=READ(R(4),4);R(3)&=R(13);WRITE(R(4),R(3),4);goto restore;
    }
    WRITE(R(12)+16,R(4),4);R(3)=READ(0x0c0a8f78,4);R(4)=READ(R(14)+16,4);R(5)=READ(R(14)+20,4);
    if(!call(s,ram,R(3),0x0c0a8eaa))return 0;
    R(2)=READ(0x0c0a8f78,4);R(4)=READ(R(14)+20,4);R(5)=READ(R(14)+16,4);if(!call(s,ram,R(2),0x0c0a8eb2))return 0;
    R(11)=READ(R(14)+20,4);R(3)=READ(0x0c0a8f7c,4);R(12)=READ(R(14)+16,4);R(5)=R(11);R(4)=R(12);
    if(!call(s,ram,R(3),0x0c0a8ebe))return 0;
    R(2)=READ(0x0c0a8f80,4);R(5)=R(11);R(4)=R(12);if(!call(s,ram,R(2),0x0c0a8ec6))return 0;
    R(3)=READ(0x0c0a8f84,4);R(5)=R(11);R(4)=R(12);if(!call(s,ram,R(3),0x0c0a8ece))return 0;
    R(4)=READ(R(14)+16,4);R(2)=READ(R(4),4);R(2)&=R(13);WRITE(R(4),R(2),4);
    R(4)=READ(R(14)+20,4);R(3)=READ(R(4),4);R(3)&=R(13);WRITE(R(4),R(3),4);
    R(4)=READ(R(14)+28,4);R(2)=READ(R(4),4);R(2)&=R(13);WRITE(R(4),R(2),4);
    R(4)=READ(R(14)+12,4);R(3)=READ(R(4),4);R(3)&=R(13);WRITE(R(4),R(3),4);
restore:
    R(15)+=4;R(16)=pop(s,ram);R(10)=pop(s,ram);R(11)=pop(s,ram);R(12)=pop(s,ram);R(13)=pop(s,ram);R(14)=pop(s,ram);
    s->pc=R(16);return ram->oob==0;
}
