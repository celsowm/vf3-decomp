/* Initialize the paired history ring and interpolate a replay actor between
 * recorded frames. Stack slots and helper order retain the original ABI. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
#define WRITE(a,v,n) vf3_matrix_write(ram,(a),(v),(n))
static void condition(vf3_matrix_state *s,int yes){R(17)=(R(17)&~1u)|(yes!=0);}
static uint32_t word(const vf3_ram_map *ram,uint32_t a){return (uint32_t)(int32_t)(int16_t)READ(a,2);}
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t value){R(15)-=4;WRITE(R(15),value,4);}
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram){uint32_t value=READ(R(15),4);R(15)+=4;return value;}
static int call(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t target,uint32_t returned){R(16)=returned;return vf3_matrix_family(target,s,ram);}

/* Clear the selected round's paired replay block, retaining signed round
 * arithmetic and the caller's MACL across the original eight-word loop. */
int vf3_replay_round_clear_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    R(3)=READ(0x0c0a89ac,4);R(2)=word(ram,0x0c0a89a6);R(4)=(uint32_t)(int32_t)(int8_t)READ(R(3),1);
    push(s,ram,R(19));R(4)--;R(5)=READ(0x0c0a89b0,4);R(4)=(uint32_t)(int32_t)(int8_t)R(4);R(7)=word(ram,0x0c0a89a8);
    R(19)=(uint32_t)((int32_t)(int16_t)R(2)*(int32_t)(int16_t)R(4));R(4)=R(19);R(4)<<=2;R(4)<<=2;R(4)<<=2;R(5)+=R(4);R(4)=0;R(6)=R(4);
    do{
        for(unsigned i=0;i<7;i++){WRITE(R(5),R(4),4);if(i<6)R(5)+=4;}
        R(6)++;R(5)+=4;condition(s,(int32_t)R(6)>=(int32_t)R(7));WRITE(R(5),R(4),4);R(5)+=4;
    }while(!(R(17)&1));
    R(19)=pop(s,ram);s->pc=R(16);return ram->oob==0;
}

int vf3_replay_initializer_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    push(s,ram,R(16));R(3)=READ(0x0c0a8434,4);R(15)-=4;WRITE(R(15),R(4),4);
    if(!call(s,ram,R(3),0x0c0a837a))return 0;
    condition(s,R(0)==0);
    if(!(R(17)&1)){
        R(7)=READ(R(15),4);R(4)=0;WRITE(R(7)+16,R(4),4);
        R(6)=word(ram,0x0c0a842e);R(5)=READ(0x0c0a8438,4);
        do{
            for(unsigned i=0;i<7;i++){WRITE(R(5),R(4),4);if(i<6)R(5)+=4;}
            R(6)--;R(5)+=4;condition(s,(int32_t)R(6)>0);
            WRITE(R(5),R(4),4);R(5)+=4;
        }while(R(17)&1);
        R(2)=READ(0x0c0a843c,4);WRITE(R(7)+12,R(2),4);R(4)=READ(R(15),4);
        R(15)+=4;R(16)=pop(s,ram);
        return vf3_matrix_family(0x0c0a83c2,s,ram);
    }
    R(15)+=4;R(16)=pop(s,ram);s->pc=R(16);return ram->oob==0;
}

int vf3_replay_interpolate_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    push(s,ram,R(14));R(14)=R(5);push(s,ram,R(13));R(13)=R(4);
    R(0)=word(ram,0x0c0a906e);R(7)=0;push(s,ram,R(16));R(4)=READ(R(14)+R(0),4);
    R(0)=36;R(0)=word(ram,R(13)+R(0));R(15)-=16;WRITE(R(15)+12,R(0),2);
    R(0)=62;WRITE(R(14)+R(0),R(4),2);R(0)=word(ram,R(15)+12);R(5)=R(0);
    condition(s,R(4)==R(5));R(6)=R(7);if(!(R(17)&1))R(6)=word(ram,0x0c0a9070);
    condition(s,(int32_t)R(4)>(int32_t)R(5));R(0)=64;WRITE(R(14)+R(0),R(6),2);
    if(R(17)&1)goto reset_blend;
    R(0)=60;R(5)=word(ram,R(14)+R(0));R(0)=34;R(4)=word(ram,R(13)+R(0));
    condition(s,R(5)==R(4));if(!(R(17)&1))goto reset_blend;
    R(6)=READ(0x0c0a9078,4);R(5)=READ(R(13),4);R(4)=READ(R(14),4);R(5)&=R(6);R(4)&=R(6);
    condition(s,R(4)==R(5));if(!(R(17)&1))goto update_actor;
    R(0)=4;R(5)=R(15);vf3_matrix_load(s,ram,3,R(13)+R(0));R(0)=8;R(6)=R(15);R(5)+=8;
    vf3_matrix_store(s,ram,3,R(15)+R(0));R(0)=8;vf3_matrix_load(s,ram,3,R(13)+R(0));
    R(0)=4;R(6)+=4;R(7)=R(15);vf3_matrix_store(s,ram,3,R(15)+R(0));R(0)=12;
    vf3_matrix_load(s,ram,3,R(13)+R(0));vf3_matrix_store(s,ram,3,R(15));R(4)=R(14);
    if(!call(s,ram,0x0c0a8f10,0x0c0a9000))return 0;
    R(0)=8;vf3_matrix_load(s,ram,6,R(15));vf3_matrix_load(s,ram,4,R(15)+R(0));R(0)=4;
    vf3_matrix_load(s,ram,5,R(15)+R(0));R(0)=16;vf3_matrix_store(s,ram,4,R(14)+R(0));
    R(0)=20;vf3_matrix_store(s,ram,5,R(14)+R(0));R(0)=24;vf3_matrix_store(s,ram,6,R(14)+R(0));
    R(0)=32;R(5)=word(ram,R(13)+R(0));R(4)=R(14);
    if(!call(s,ram,0x0c0a8f3e,0x0c0a901e))return 0;
    WRITE(R(14)+30,R(0),2);goto update_actor;
reset_blend:
    R(0)=64;WRITE(R(14)+R(0),R(7),2);
update_actor:
    R(2)=READ(0x0c0a907c,4);R(4)=R(14);if(!call(s,ram,R(2),0x0c0a9026))return 0;
    R(3)=READ(0x0c0a9080,4);R(4)=R(14);if(!call(s,ram,R(3),0x0c0a902c))return 0;
    R(15)+=16;R(16)=pop(s,ram);R(13)=pop(s,ram);R(14)=pop(s,ram);s->pc=R(16);return ram->oob==0;
}
