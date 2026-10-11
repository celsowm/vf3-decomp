/* Six-joint inward/outward radial corrections around radius eight.
 * Callable 0x8c0cb67a, frozen owner 0x8c0cb69e; original invocation model. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <string.h>
#define R(n) s->v[(n)]
#define F(n) s->v[21+(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
#define WRITE(a,v) vf3_matrix_write(ram,(a),(v),4)
static void push(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t v){R(15)-=4;WRITE(R(15),v);}
static uint32_t pop(vf3_matrix_state*s,const vf3_ram_map*ram){uint32_t v=READ(R(15),4);R(15)+=4;return v;}
static float value(uint32_t b){float f;memcpy(&f,&b,4);return f;}
static void condition(vf3_matrix_state*s,int yes){R(17)=(R(17)&~1u)|(yes!=0);}
static void op(vf3_matrix_state*s,unsigned d,unsigned f,char operation){F(d)=vf3_fpu_binary(F(d),F(f),R(18),operation);}
int vf3_radial_bound_c(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t alias)
{
    if(!vf3_fpu_supported(R(18)) || (R(18)&0x100000u))return 0;
    push(s,ram,R(13));push(s,ram,R(12));R(12)=4;push(s,ram,R(11));R(11)=6;
    push(s,ram,R(10));R(5)=R(11);push(s,ram,R(9));R(0)=0x138c;R(7)=0x16f8;
    R(9)=READ(R(4)+R(0),4);R(0)=alias+0x0cb6c8;F(10)=READ(R(0),4);
    R(0)=alias+0x0cb6cc;F(1)=READ(R(0),4);R(0)=alias+0x0cb6d0;
    R(13)=0x1618;R(7)+=R(4);push(s,ram,R(16));R(10)=READ(alias+0x0cb6c4,4);
    R(13)+=R(4);F(11)=READ(R(0),4);F(8)=0;condition(s,R(5)==0);
    while(!(R(17)&1)){
        if(!s->budget--)return 0;
        R(4)=R(11)-R(5)+R(10);R(2)=READ(alias+0x0cb770,4);R(1)=(uint32_t)(int32_t)(int8_t)READ(R(4),1);
        R(0)=R(12);R(16)=alias+0x0cb6e2;
        if(!vf3_matrix_family(R(2),s,ram)||s->pc!=R(16))return 0;
        R(4)=R(0);R(6)=(uint32_t)(int32_t)(int8_t)R(4);R(3)=R(6);R(6)<<=1;R(6)+=R(3);R(6)<<=2;R(6)+=R(9);
        F(6)=READ(R(6),4);R(0)=8;F(7)=READ(R(6)+R(0),4);F(3)=F(6);op(s,3,6,'*');F(0)=F(7);
        F(3)=vf3_fpu_mac(F(0),F(7),F(3),R(18));F(9)=F(3);condition(s,value(F(11))>value(F(9)));
        if(R(17)&1)F(5)=0;
        else {F(5)=F(9);if(!vf3_fpu_fsrra(F(5),R(18),&F(5)))return 0;}
        F(4)=F(5);op(s,4,6,'*');op(s,5,7,'*');R(1)=(uint32_t)(int32_t)(int8_t)R(4);R(1)<<=1;
        condition(s,value(F(9))>value(F(1)));F(3)=F(4);F(4)=F(10);op(s,4,3,'*');F(3)=F(5);F(5)=F(10);op(s,5,3,'*');R(1)<<=2;
        if(!(R(17)&1)){
            op(s,5,7,'-');R(4)=R(1);op(s,4,6,'-');R(4)+=R(13);R(0)=4;
            WRITE(R(4)+R(0),F(8));WRITE(R(4),F(8));R(4)=R(1);R(4)+=R(7);
        }else{
            R(4)=R(1);R(0)=4;R(4)+=R(7);WRITE(R(4)+R(0),F(8));WRITE(R(4),F(8));
            R(4)=R(1);F(3)=F(4);R(4)+=R(13);F(4)=F(6);op(s,4,3,'-');F(3)=F(5);F(5)=F(7);op(s,5,3,'-');
        }
        R(5)--;WRITE(R(4),F(4));WRITE(R(4)+R(0),F(5));condition(s,R(5)==0);
    }
    R(16)=pop(s,ram);R(9)=pop(s,ram);R(10)=pop(s,ram);R(11)=pop(s,ram);R(12)=pop(s,ram);
    s->pc=R(16);R(13)=pop(s,ram);return ram->oob==0;
}
