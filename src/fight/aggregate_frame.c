/* Integrate the counted vector sum into actor translation/angular state.
 * Original uncached callable 0x0c0a6dba; frozen owner 0x8c0a6dc0. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <string.h>
#define R(n) s->v[(n)]
#define F(n) s->v[21+(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
#define WRITE(a,v,n) vf3_matrix_write(ram,(a),(v),(n))
static void push(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t v){R(15)-=4;WRITE(R(15),v,4);}
static uint32_t pop(vf3_matrix_state*s,const vf3_ram_map*ram){uint32_t v=READ(R(15),4);R(15)+=4;return v;}
static float value(uint32_t b){float f;memcpy(&f,&b,4);return f;}
static void condition(vf3_matrix_state*s,int yes){R(17)=(R(17)&~1u)|(yes!=0);}
static void op(vf3_matrix_state*s,unsigned d,unsigned f,char operation){F(d)=vf3_fpu_binary(F(d),F(f),R(18),operation);}
static void mac(vf3_matrix_state*s,unsigned d,unsigned f){F(d)=vf3_fpu_mac(F(0),F(f),F(d),R(18));}
static int call(vf3_matrix_state*s,const vf3_ram_map*ram,unsigned reg,uint32_t pool,uint32_t ret)
{
    R(reg)=READ(pool,4);R(16)=ret;
    return vf3_matrix_family(R(reg),s,ram) && s->pc==R(16);
}
static uint32_t signed_word(const vf3_ram_map*ram,uint32_t address)
{return (uint32_t)(int32_t)(int16_t)READ(address,2);}
int vf3_aggregate_frame_c(vf3_matrix_state*s,const vf3_ram_map*ram)
{
    if(!vf3_fpu_supported(R(18)) || (R(18)&0x100000u))return 0;
    push(s,ram,R(14));push(s,ram,R(13));push(s,ram,F(15));push(s,ram,R(16));
    R(15)-=56;WRITE(R(15)+24,R(4),4);WRITE(R(15)+28,R(5),4);R(4)=0;
    if(!call(s,ram,3,0x0c0a6ed8,0x0c0a6dce))return 0;
    /* Four additional result pointers join R6/R7 for the vector-sum call. */
    R(3)=R(15)+20;R(14)=READ(R(15)+24,4);push(s,ram,R(3));
    R(2)=R(15)+20;push(s,ram,R(2));R(3)=R(15)+8;push(s,ram,R(3));R(2)=R(15)+24;push(s,ram,R(2));
    R(6)=R(15)+20;R(5)=READ(R(15)+44,4);R(7)=R(15)+24;R(16)=0x0c0a6df6;R(4)=READ(R(15)+40,4);
    if(!vf3_matrix_family(0x0c0a6ff8,s,ram)||s->pc!=R(16))return 0;
    R(0)=124;F(7)=READ(R(14)+R(0),4);R(0)+=4;F(6)=READ(R(14)+R(0),4);R(0)+=4;F(5)=READ(R(14)+R(0),4);
    R(0)+=4;F(4)=READ(R(14)+R(0),4);R(0)+=4;F(9)=READ(R(14)+R(0),4);R(0)+=4;F(8)=READ(R(14)+R(0),4);
    R(0)=16;R(15)+=16;F(3)=READ(R(15),4);op(s,3,4,'+');WRITE(R(15),F(3),4);
    F(2)=READ(R(15)+R(0),4);R(0)=16;op(s,2,9,'+');WRITE(R(15)+R(0),F(2),4);
    R(0)=20;F(1)=READ(R(15)+R(0),4);R(0)=20;op(s,1,8,'+');WRITE(R(15)+R(0),F(1),4);
    R(0)=4;F(3)=READ(R(15)+R(0),4);R(0)=4;op(s,3,7,'+');WRITE(R(15)+R(0),F(3),4);
    R(0)=8;F(2)=READ(R(15)+R(0),4);R(0)=8;op(s,2,6,'+');WRITE(R(15)+R(0),F(2),4);
    R(0)=12;F(1)=READ(R(15)+R(0),4);R(0)=12;op(s,1,5,'+');WRITE(R(15)+R(0),F(1),4);
    /* Apply the three integrated triples in the original arithmetic order. */
    R(0)=64;F(10)=READ(R(14)+R(0),4);R(0)=68;F(9)=READ(R(14)+R(0),4);R(0)=72;F(8)=READ(R(14)+R(0),4);
    R(0)=80;F(6)=READ(R(14)+R(0),4);R(0)=84;F(7)=READ(R(14)+R(0),4);R(0)=88;F(5)=READ(R(14)+R(0),4);
    R(0)=92;F(11)=READ(R(14)+R(0),4);R(0)=96;F(15)=READ(R(14)+R(0),4);R(0)=100;F(4)=READ(R(14)+R(0),4);
    R(0)=4;F(3)=READ(R(15)+R(0),4);R(0)=8;F(2)=READ(R(15)+R(0),4);op(s,11,3,'+');R(0)=16;op(s,15,2,'+');
    F(2)=READ(R(15)+R(0),4);op(s,4,1,'+');R(0)=20;F(3)=READ(R(15),4);F(1)=READ(R(15)+R(0),4);
    R(0)=92;WRITE(R(14)+R(0),F(11),4);R(0)=96;WRITE(R(14)+R(0),F(15),4);op(s,6,3,'+');R(0)=100;op(s,7,2,'+');
    WRITE(R(14)+R(0),F(4),4);R(0)=80;op(s,5,1,'+');WRITE(R(14)+R(0),F(6),4);
    R(0)=84;op(s,10,11,'+');WRITE(R(14)+R(0),F(7),4);R(0)=88;op(s,9,15,'+');WRITE(R(14)+R(0),F(5),4);
    op(s,8,4,'+');R(0)=64;WRITE(R(14)+R(0),F(10),4);R(0)=68;WRITE(R(14)+R(0),F(9),4);R(0)=72;
    F(4)=F(6);op(s,4,6,'*');F(0)=F(7);F(3)=F(4);mac(s,3,7);F(0)=F(5);F(2)=F(3);mac(s,2,5);
    F(3)=0;F(4)=F(2);condition(s,value(F(4))>value(F(3)));WRITE(R(14)+R(0),F(8),4);
    if(R(17)&1){
        R(0)=0x0c0a6edc;F(2)=READ(R(0),4);condition(s,value(F(2))>value(F(4)));
        if(R(17)&1)F(3)=0;
        else {F(3)=F(4);if(!vf3_fpu_fsrra(F(3),R(18),&F(3)))return 0;}
        WRITE(R(15),F(3),4);op(s,3,6,'*');R(0)=4;WRITE(R(15)+R(0),F(3),4);
        R(0)=8;F(3)=READ(R(15),4);op(s,3,7,'*');WRITE(R(15)+R(0),F(3),4);
        R(0)=12;F(2)=READ(R(15),4);op(s,2,5,'*');WRITE(R(15)+R(0),F(2),4);
        R(0)=44;F(1)=READ(R(15),4);op(s,1,4,'*');WRITE(R(15),F(1),4);WRITE(R(15)+R(0),F(10),4);
        R(0)=48;WRITE(R(15)+R(0),F(9),4);R(0)=52;WRITE(R(15)+R(0),F(8),4);
        if(!call(s,ram,3,0x0c0a6fd8,0x0c0a6f12))return 0;
        R(0)=160;F(15)=READ(R(14)+R(0),4);F(5)=F(15);F(6)=F(15);F(4)=F(15);
        if(!call(s,ram,3,0x0c0a6fdc,0x0c0a6f20))return 0;
        R(4)=R(15)+44;if(!call(s,ram,2,0x0c0a6fe0,0x0c0a6f28))return 0;
        R(0)=4;F(3)=READ(R(15)+R(0),4);R(0)=44;WRITE(R(15)+R(0),F(3),4);
        R(0)=8;F(3)=READ(R(15)+R(0),4);R(0)=48;WRITE(R(15)+R(0),F(3),4);
        R(0)=12;F(3)=READ(R(15)+R(0),4);R(0)=52;WRITE(R(15)+R(0),F(3),4);
        R(0)=148;R(3)=R(0)+6+R(14);R(2)=signed_word(ram,R(14)+R(0));R(3)=signed_word(ram,R(3));R(2)+=R(3);WRITE(R(14)+R(0),R(2),2);
        R(0)+=2;R(3)=156+R(14);R(2)=signed_word(ram,R(14)+R(0));R(3)=signed_word(ram,R(3));R(2)+=R(3);WRITE(R(14)+R(0),R(2),2);
        R(0)+=2;R(3)=158+R(14);R(2)=signed_word(ram,R(14)+R(0));R(3)=signed_word(ram,R(3));R(2)+=R(3);WRITE(R(14)+R(0),R(2),2);
        R(0)-=2;R(4)=signed_word(ram,R(14)+R(0));if(!call(s,ram,3,0x0c0a6fe4,0x0c0a6f74))return 0;
        R(0)=148;R(4)=signed_word(ram,R(14)+R(0));if(!call(s,ram,3,0x0c0a6fe8,0x0c0a6f7c))return 0;
        R(0)=152;R(4)=signed_word(ram,R(14)+R(0));if(!call(s,ram,3,0x0c0a6fec,0x0c0a6f84))return 0;
        R(0)=64;R(13)=R(15)+32;F(3)=READ(R(14)+R(0),4);R(0)=68;R(4)=R(14);WRITE(R(13),F(3),4);
        F(3)=READ(R(14)+R(0),4);R(0)=4;WRITE(R(13)+R(0),F(3),4);R(0)=72;F(3)=READ(R(14)+R(0),4);R(0)=8;WRITE(R(13)+R(0),F(3),4);
        R(4)+=16;if(!call(s,ram,3,0x0c0a6ff0,0x0c0a6fa6))return 0;
        F(3)=READ(R(13),4);R(0)=64;WRITE(R(14)+R(0),F(3),4);R(0)=4;F(3)=READ(R(13)+R(0),4);R(0)=68;WRITE(R(14)+R(0),F(3),4);
        R(0)=8;F(3)=READ(R(13)+R(0),4);R(0)=72;WRITE(R(14)+R(0),F(3),4);
    }
    R(4)=1;if(!call(s,ram,3,0x0c0a6ff4,0x0c0a6fc2))return 0;
    R(15)+=56;R(16)=pop(s,ram);F(15)=pop(s,ram);R(13)=pop(s,ram);s->pc=R(16);R(14)=pop(s,ram);
    return ram->oob==0;
}
