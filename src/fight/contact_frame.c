/* Eighteen-slot scene contact update, including velocity damping and angles.
 * Original uncached callable 0x0c0a0aec; frozen owner 0x8c0a0b00. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#define R(n) s->v[(n)]
#define F(n) s->v[21+(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
#define WRITE(a,v,n) vf3_matrix_write(ram,(a),(v),(n))
static void push(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t v){R(15)-=4;WRITE(R(15),v,4);}
static uint32_t pop(vf3_matrix_state*s,const vf3_ram_map*ram){uint32_t v=READ(R(15),4);R(15)+=4;return v;}
static void condition(vf3_matrix_state*s,int yes){R(17)=(R(17)&~1u)|(yes!=0);}
static uint32_t word(const vf3_ram_map*ram,uint32_t a){return (uint32_t)(int32_t)(int16_t)READ(a,2);}
static void op(vf3_matrix_state*s,unsigned d,unsigned f,char c){F(d)=vf3_fpu_binary(F(d),F(f),R(18),c);}
static void mac(vf3_matrix_state*s,unsigned d,unsigned f){F(d)=vf3_fpu_mac(F(0),F(f),F(d),R(18));}
static int call(vf3_matrix_state*s,const vf3_ram_map*ram,unsigned r,uint32_t pool,uint32_t ret)
{R(r)=READ(pool,4);R(16)=ret;return vf3_matrix_family(R(r),s,ram)&&s->pc==R(16);}
/* Match the signed half-turn comparison before storing a truncated delta. */
static void angle(vf3_matrix_state*s,const vf3_ram_map*ram,int first)
{
    int positive;
    R(0)=first?148:152;R(4)=word(ram,R(14)+R(0));
    if(first)R(5)=word(ram,0x0c0a0c74);
    condition(s,(int32_t)R(4)>=(int32_t)R(5));
    positive=!(R(17)&1);
    if(!positive){
        condition(s,(int32_t)R(4)>0);
        if(R(17)&1){R(3)=word(ram,first?0x0c0a0c76:0x0c0a0d7a);condition(s,(int32_t)R(4)>=(int32_t)R(3));positive=!(R(17)&1);}
    }
    R(0)=first?154:158;R(3)=word(ram,R(14)+R(0));R(53)=R(3);
    F(3)=vf3_fpu_float(R(53),R(18))&0x7fffffffu;op(s,3,4,'*');
    if(!positive)F(3)^=0x80000000u;
    R(53)=vf3_fpu_ftrc(F(3));R(3)=R(53);WRITE(R(14)+R(0),R(3),2);
}
int vf3_contact_frame_c(vf3_matrix_state*s,const vf3_ram_map*ram)
{
    if(!vf3_fpu_supported(R(18))||(R(18)&0x100000u))return 0;
    for(unsigned i=14;i>=8;i--)push(s,ram,R(i));
    push(s,ram,F(15));push(s,ram,F(14));R(1)=READ(0x0c0a0b54,4);push(s,ram,R(16));
    R(3)=READ(0x0c0a0b50,4);R(2)=READ(R(1),4);R(6)=READ(0x0c0a0b4c,4);R(15)-=32;
    condition(s,(R(2)&R(3))==0);
    if(R(17)&1){
        R(5)=READ(0x0c0a0b58,4);R(0)=68;R(4)=READ(R(5)+R(0),4);
        R(0)=word(ram,0x0c0a0b2c);R(12)=READ(R(4)+R(0),4);R(0)=word(ram,0x0c0a0b2e);
        R(3)=(uint32_t)(int32_t)(int8_t)READ(R(6)+R(0),1);condition(s,R(3)==0);
        R(4)=READ(R(5)+((R(17)&1)?16:20),4);R(9)=word(ram,0x0c0a0c6c);R(8)=18;
        R(11)=READ(0x0c0a0c7c,4);R(9)+=R(4);
        do{
            if(!s->budget--)return 0;
            R(0)=(uint32_t)(int32_t)(int8_t)READ(R(11)+8,1);condition(s,R(0)==1);
            if(R(17)&1){
                R(10)=word(ram,0x0c0a0c70);R(3)=0;R(14)=word(ram,0x0c0a0c6e);R(13)=word(ram,0x0c0a0c72);
                R(10)+=R(12);R(14)+=R(12);WRITE(R(15)+4,R(12),4);R(4)=R(14);
                WRITE(R(10),R(3),4);R(13)+=R(12);R(4)+=16;
                if(!call(s,ram,2,0x0c0a0c80,0x0c0a0b8a))return 0;
                R(0)=64;R(5)=R(15);F(14)=READ(R(14)+R(0),4);R(0)=68;F(3)=READ(R(14)+R(0),4);
                R(0)=72;R(4)=R(15);R(5)+=20;WRITE(R(15),F(3),4);F(15)=READ(R(14)+R(0),4);
                F(5)=F(15)^0x80000000u;F(4)=F(14);
                if(!call(s,ram,3,0x0c0a0c84,0x0c0a0ba8))return 0;
                R(4)=R(15)+20;if(!call(s,ram,2,0x0c0a0c88,0x0c0a0bb0))return 0;
                R(0)=28;F(3)=READ(R(15)+R(0),4)^0x80000000u;WRITE(R(15)+R(0),F(3),4);
                R(0)=0x0c0a0c8c;F(3)=READ(R(15),4);F(4)=READ(R(0),4);R(0)=24;op(s,3,4,'+');WRITE(R(15),F(3),4);
                WRITE(R(13)+R(0),F(14),4);R(0)=28;F(3)=READ(R(15),4);WRITE(R(13)+R(0),F(3),4);
                R(0)=32;WRITE(R(13)+R(0),F(15),4);R(0)=20;F(3)=READ(R(15)+R(0),4);R(0)=24;WRITE(R(13),F(3),4);
                F(3)=READ(R(15)+R(0),4);R(0)=4;WRITE(R(13)+R(0),F(3),4);R(0)=28;F(3)=READ(R(15)+R(0),4);
                R(0)=8;WRITE(R(13)+R(0),F(3),4);R(0)=20;F(3)=READ(R(15)+R(0),4);F(0)=F(4);mac(s,14,3);
                R(0)=12;R(5)=R(13);WRITE(R(13)+R(0),F(14),4);R(0)=24;F(2)=READ(R(15)+R(0),4);
                R(0)=16;F(3)=READ(R(15),4);mac(s,3,2);WRITE(R(13)+R(0),F(3),4);R(0)=28;F(3)=READ(R(15)+R(0),4);
                R(0)=20;mac(s,15,3);WRITE(R(13)+R(0),F(15),4);R(6)=READ(R(15)+4,4);R(4)=R(14);
                if(!call(s,ram,3,0x0c0a0c90,0x0c0a0c14))return 0;
                R(4)=R(15);R(5)=R(0);R(0)=4;R(4)+=8;F(3)=READ(R(4)+R(0),4);condition(s,R(5)==0);WRITE(R(15),F(3),4);
                if(!(R(17)&1)){
                    R(0)=0x0c0a0c94;F(5)=READ(R(0),4);R(0)=0x0c0a0c98;F(4)=READ(R(0),4);
                    R(0)=92;F(3)=READ(R(14)+R(0),4);op(s,3,5,'*');WRITE(R(14)+R(0),F(3),4);
                    R(0)=96;R(1)=READ(0x0c0a0c9c,4);F(2)=READ(R(14)+R(0),4);R(53)=R(1);F(3)=R(53);op(s,2,3,'*');WRITE(R(14)+R(0),F(2),4);
                    R(0)=100;F(2)=READ(R(14)+R(0),4);op(s,2,5,'*');WRITE(R(14)+R(0),F(2),4);
                    angle(s,ram,1);angle(s,ram,0);R(0)=156;R(3)=word(ram,R(14)+R(0));R(53)=R(3);
                    F(3)=vf3_fpu_float(R(53),R(18));op(s,3,4,'*');R(53)=vf3_fpu_ftrc(F(3));R(3)=R(53);WRITE(R(14)+R(0),R(3),2);
                }
                R(5)=R(10);R(4)=R(14);if(!call(s,ram,3,0x0c0a0d88,0x0c0a0d00))return 0;
                R(5)=R(14)+16;R(4)=R(9);if(!call(s,ram,2,0x0c0a0d8c,0x0c0a0d0a))return 0;
                R(3)=word(ram,0x0c0a0d80);R(12)+=R(3);
            }
            R(8)--;condition(s,R(8)==0);R(11)+=12;R(9)+=64;
        }while(!(R(17)&1));
    }
    R(15)+=32;R(16)=pop(s,ram);F(14)=pop(s,ram);F(15)=pop(s,ram);
    for(unsigned i=8;i<=13;i++)R(i)=pop(s,ram);
    s->pc=R(16);R(14)=pop(s,ram);return ram->oob==0;
}
