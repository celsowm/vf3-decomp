/* Copy a motion descriptor into an actor, select its frame path and publish
 * the real pose update. Full callable 0x8c0a94d0, frozen owner 0x8c0a94d4. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
#define WRITE(a,v,n) vf3_matrix_write(ram,(a),(v),(n))

static uint32_t signed_word(uint32_t value)
{ return (uint32_t)(int32_t)(int16_t)value; }
static uint32_t signed_byte(uint32_t value)
{ return (uint32_t)(int32_t)(int8_t)value; }
static void condition(vf3_matrix_state *s,int value)
{ R(17)=(R(17)&~1u)|(value!=0); }
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t value)
{ R(15)-=4;WRITE(R(15),value,4); }
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram)
{ uint32_t value=READ(R(15),4);R(15)+=4;return value; }
static int call(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t target,uint32_t return_pc)
{ R(16)=return_pc;return vf3_matrix_family(target,s,ram); }

int vf3_motion_frame_c(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t alias)
{
    R(0)=4;
    push(s,ram,R(14));
    push(s,ram,R(16));
    R(14)=R(5);
    R(15)-=20;
    WRITE(R(15)+4,R(6),4);
    s->v[25]=READ(R(4)+R(0),4);
    R(0)=8;s->v[26]=READ(R(4)+R(0),4);
    R(0)=12;s->v[27]=READ(R(4)+R(0),4);
    R(0)=32;R(6)=signed_word(READ(R(4)+R(0),2));
    R(0)=36;R(7)=signed_word(READ(R(4)+R(0),2));
    R(0)=56;
    R(3)=READ(R(4)+16,4);
    R(5)=READ(R(4),4);
    WRITE(R(15),R(3),4);
    R(2)=READ(R(4)+44,4);WRITE(R(15)+16,R(2),4);
    R(3)=READ(R(4)+48,4);WRITE(R(15)+12,R(3),4);
    R(0)=signed_byte(READ(R(4)+R(0),1));WRITE(R(15)+8,R(0),1);

    /* Flags/vector and packed motion/frame fields retain their original
     * widths. The long offsets below are separate descriptor publications. */
    R(0)=16;WRITE(R(14),R(5),4);WRITE(R(14)+R(0),s->v[25],4);
    R(0)=20;WRITE(R(14)+R(0),s->v[26],4);
    R(0)=24;WRITE(R(14)+R(0),s->v[27],4);
    R(0)=R(6);WRITE(R(14)+30,R(0),2);
    R(0)=62;WRITE(R(14)+R(0),R(7),2);
    R(0)=72;R(3)=READ(R(15),4);WRITE(R(14)+R(0),R(3),4);
    R(0)=0x1a04;R(2)=READ(R(15)+16,4);WRITE(R(14)+R(0),R(2),4);
    R(0)=0x14d8;R(3)=READ(R(15)+12,4);WRITE(R(14)+R(0),R(3),4);
    R(1)=0x206b;R(0)=signed_byte(READ(R(15)+8,1));R(1)+=R(14);WRITE(R(1),R(0),1);

    R(0)=60;R(6)=signed_word(READ(R(14)+R(0),2));
    R(0)=34;R(4)=signed_word(READ(R(4)+R(0),2));
    R(0)=60;R(5)=signed_word(R(4));condition(s,R(5)==0);
    WRITE(R(14)+R(0),R(4),2);
    if(R(17)&1u){
        R(15)+=20;R(16)=pop(s,ram);R(14)=pop(s,ram);
        s->pc=R(16);return ram->oob==0;
    }
    R(6)=signed_word(R(6));condition(s,R(6)==R(5));
    if(!(R(17)&1u)){
        /* A changed motion initializes its stream, then decodes the actual
         * loaded motion table before selecting the initial frame. */
        R(2)=signed_word(READ(R(14)+R(0),2));WRITE(R(15),R(2),2);
        R(5)=READ(R(15)+4,4);R(3)=0x0c0ad390;
        R(6)=signed_word(READ(R(15),2));R(4)=R(14);
        if(!call(s,ram,R(3),alias+0x0a9566))return 0;
        R(2)=0x0c09d5ae;R(4)=R(14);
        if(!call(s,ram,R(2),alias+0x0a956c))return 0;
        goto initial_frame;
    }
    R(0)=62;R(4)=signed_word(READ(R(14)+R(0),2));
    R(0)=signed_word(R(4));condition(s,R(0)==1);
    if(R(17)&1u){
initial_frame:
        R(3)=0x0c09f1ac;R(4)=R(14);
        if(!call(s,ram,R(3),alias+0x0a9572))return 0;
    }else{
        R(3)=0x0c09f036;R(4)=R(14);
        if(!call(s,ram,R(3),alias+0x0a957c))return 0;
    }
    R(15)+=20;R(2)=0x0c09ea66;R(16)=pop(s,ram);
    R(4)=R(14);R(14)=pop(s,ram);
    return vf3_matrix_family(R(2),s,ram);
}
