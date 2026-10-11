/* Six-joint squared-distance correction against the original +/-28 bounds.
 * Original callable 0x8c0cb51e, frozen owner 0x8c0cb532. */
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
static void mac(vf3_matrix_state*s,unsigned d,unsigned f){F(d)=vf3_fpu_mac(F(0),F(f),F(d),R(18));}
int vf3_ring_bound_c(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t alias)
{
    if(!vf3_fpu_supported(R(18)) || (R(18)&0x100000u))return 0;
    push(s,ram,R(13));push(s,ram,R(12));R(12)=6;push(s,ram,R(11));R(6)=R(12);
    push(s,ram,R(10));push(s,ram,R(9));push(s,ram,F(15));push(s,ram,F(13));R(0)=0x138c;push(s,ram,R(16));
    R(9)=READ(R(4)+R(0),4);R(0)=alias+0x0cb570;F(3)=READ(R(0),4);R(0)=alias+0x0cb574;
    R(15)-=12;R(7)=READ(R(4),4);R(10)=READ(alias+0x0cb56c,4);WRITE(R(15),F(3));F(7)=READ(R(0),4);
    R(0)=4;F(11)=0;WRITE(R(15)+R(0),F(11));R(0)=8;WRITE(R(15)+R(0),F(11));
    R(13)=READ(alias+0x0cb578,4);R(11)=4;condition(s,R(6)==0);
    while(!(R(17)&1)){
        if(!s->budget--)return 0;
        R(5)=R(12)-R(6)+R(10);R(2)=READ(alias+0x0cb6b8,4);R(1)=(uint32_t)(int32_t)(int8_t)READ(R(5),1);
        R(0)=R(11);R(16)=alias+0x0cb58a;
        if(!vf3_matrix_family(R(2),s,ram)||s->pc!=R(16))return 0;
        R(2)=0x12ac;R(5)=R(0);R(3)=(uint32_t)(int32_t)(int8_t)R(5);F(3)=READ(R(15),4);R(2)+=R(4);
        R(3)<<=2;R(3)+=R(2);R(1)=(uint32_t)(int32_t)(int8_t)R(5);F(4)=READ(R(3),4);R(3)=R(1);R(1)<<=1;
        R(1)+=R(3);F(10)=F(4);R(1)<<=2;R(1)+=R(9);F(6)=READ(R(1),4);R(0)=8;F(5)=READ(R(1)+R(0),4);
        F(9)=F(6);op(s,10,6,'+');F(6)=F(4);op(s,6,5,'+');op(s,9,4,'-');F(8)=F(5);op(s,8,4,'-');
        F(0)=F(10);op(s,0,3,'-');F(15)=F(6);op(s,15,3,'-');F(1)=F(9);op(s,1,7,'-');F(13)=F(8);
        F(3)=0;condition(s,value(F(3))>value(F(0)));op(s,13,7,'-');F(4)=0;F(6)=F(4);F(5)=F(4);
        if(!(R(17)&1)){F(4)=F(0);F(5)=F(0);op(s,4,5,'*');}
        /* Accumulate squared violations on the four sides. */
        F(3)=0;condition(s,value(F(1))>value(F(3)));
        if(!(R(17)&1)){F(3)=F(9);F(9)=F(7);op(s,9,3,'-');F(2)=F(4);F(5)=F(1);F(0)=F(9);mac(s,2,9);F(4)=F(2);}
        F(3)=0;condition(s,value(F(3))>value(F(15)));F(2)=0;
        if(!(R(17)&1)){F(0)=F(15);F(3)=F(4);F(6)=F(15);mac(s,3,6);F(4)=F(3);}
        condition(s,value(F(13))>value(F(2)));
        if(!(R(17)&1)){F(3)=F(8);F(8)=F(7);op(s,8,3,'-');F(2)=F(4);F(6)=F(13);F(0)=F(8);mac(s,2,8);F(4)=F(2);}
        condition(s,value(F(4))>value(F(11)));R(6)--;
        if(R(17)&1){R(0)=8;F(5)^=0x80000000u;WRITE(R(15)+R(0),F(5));R(0)=4;F(6)^=0x80000000u;
            R(7)|=R(13);WRITE(R(15)+R(0),F(6));F(11)=F(4);}
        condition(s,R(6)==0);
    }
    R(0)=8;F(3)=READ(R(15)+R(0),4);R(0)=0x13a8;WRITE(R(4)+R(0),F(3));R(0)=4;F(3)=READ(R(15)+R(0),4);
    R(15)+=12;R(16)=pop(s,ram);R(0)=0x13b0;WRITE(R(4)+R(0),F(3));WRITE(R(4),R(7));
    F(13)=pop(s,ram);F(15)=pop(s,ram);R(9)=pop(s,ram);R(10)=pop(s,ram);R(11)=pop(s,ram);R(12)=pop(s,ram);
    s->pc=R(16);R(13)=pop(s,ram);return ram->oob==0;
}
