/* Closed polygon/segment intersection, callable 0x8c06e056, owner 0x8c06e066.
 * Retain the original cross-product tests and first accepted edge, including
 * the no-hit output convention and the caller's stack output pointers. */
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
int vf3_polygon_hit_c(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t alias)
{
    int i;
    if(!vf3_fpu_supported(R(18)) || (R(18)&0x100000u))return 0;
    push(s,ram,R(14));R(0)=4;push(s,ram,R(13));R(14)=R(5);
    for(i=15;i>=12;i--){push(s,ram,F(i));}
    push(s,ram,R(16));R(15)-=24;
    WRITE(R(15)+20,R(7));WRITE(R(15),F(4));WRITE(R(15)+R(0),F(5));
    R(0)=8;WRITE(R(15)+R(0),F(6));R(0)=12;WRITE(R(15)+R(0),F(7));
    /* Segment line coefficients, using the original multiply order. */
    R(0)=4;F(9)=READ(R(15)+R(0),4);R(0)=8;F(8)=READ(R(15)+R(0),4);
    R(0)=8;F(1)=READ(R(15)+R(0),4);R(0)=4;F(5)=READ(R(15)+R(0),4);
    F(2)=READ(R(15),4);op(s,5,1,'*');F(3)=F(7);op(s,8,2,'-');op(s,2,3,'*');op(s,9,3,'-');
    F(3)=F(5);R(0)=0x3c4;F(5)=F(2);op(s,5,3,'-');R(4)=READ(R(4)+R(0),4);
    R(13)=READ(alias+0x06e0b4,4);R(5)=READ(R(4),4);R(4)+=4;
    F(15)=READ(R(4),4);R(4)+=4;F(14)=READ(R(4),4);R(4)+=4;R(7)=1;
    condition(s,R(5)==0);
    while(!(R(17)&1)){
        if(!s->budget--)return 0;
        F(13)=F(15);R(0)=4;F(15)=READ(R(4),4);R(4)+=4;F(12)=F(14);
        F(4)=F(15);op(s,4,12,'*');F(14)=READ(R(4),4);R(4)+=4;
        F(3)=F(13);op(s,3,14,'*');F(6)=F(12);F(2)=F(4);op(s,6,14,'-');
        F(7)=F(15);op(s,7,13,'-');F(4)=F(3);op(s,4,2,'-');
        /* Both segment endpoints must straddle this polygon edge. */
        F(3)=READ(R(15),4);F(0)=F(6);F(2)=READ(R(15)+R(0),4);R(0)=8;
        F(10)=F(4);mac(s,10,3);F(0)=F(7);F(3)=F(10);mac(s,3,2);
        F(0)=F(6);F(10)=F(4);F(11)=F(3);F(3)=READ(R(15)+R(0),4);R(0)=12;
        mac(s,10,3);F(3)=F(10);F(2)=READ(R(15)+R(0),4);F(0)=F(7);mac(s,3,2);
        F(10)=F(3);op(s,11,10,'*');F(3)=0;condition(s,value(F(11))>value(F(3)));
        if(!(R(17)&1)){
            /* The polygon edge must also straddle the input segment line. */
            F(0)=F(9);F(10)=F(5);mac(s,10,13);F(0)=F(8);F(3)=F(10);mac(s,3,12);
            F(0)=F(9);F(10)=F(5);mac(s,10,15);F(0)=F(8);F(11)=F(3);F(3)=0;
            F(2)=F(10);mac(s,2,14);F(10)=F(2);op(s,11,10,'*');
            condition(s,value(F(11))>value(F(3)));
            if(!(R(17)&1)){
                F(10)=F(5);op(s,10,7,'*');F(3)=F(8);op(s,3,4,'*');op(s,8,6,'*');
                R(0)=16;op(s,5,6,'*');R(14)=R(7);F(2)=F(10);F(10)=F(3);op(s,10,2,'-');
                WRITE(R(15)+R(0),F(8));R(0)=16;F(11)=F(9);op(s,11,7,'*');op(s,9,4,'*');
                F(3)=F(8);F(8)=F(11);op(s,8,3,'-');op(s,10,8,'/');WRITE(R(15),F(10));
                F(3)=F(5);F(5)=F(9);op(s,5,3,'-');F(3)=F(11);F(4)=F(11);
                F(4)=READ(R(15)+R(0),4);R(0)=4;op(s,4,3,'-');op(s,5,4,'/');WRITE(R(15)+R(0),F(5));
                F(5)=F(14);op(s,5,12,'-');F(4)=F(13);op(s,4,15,'-');R(16)=alias+0x06e174;
                if(!vf3_matrix_family(R(13),s,ram) || s->pc!=R(16))return 0;
                R(6)=(uint32_t)(int32_t)(int16_t)R(0);break;
            }
        }
        R(5)--;condition(s,R(5)==0);
    }
    R(3)=READ(R(15)+60,4);R(0)=64;WRITE(R(3),R(14));R(3)=READ(R(15)+R(0),4);
    R(0)=4;WRITE(R(3),R(6));F(3)=READ(R(15),4);R(3)=READ(R(15)+20,4);WRITE(R(3),F(3));
    F(3)=READ(R(15)+R(0),4);R(3)=READ(R(15)+56,4);R(15)+=24;R(16)=pop(s,ram);WRITE(R(3),F(3));
    for(i=12;i<=15;i++){F(i)=pop(s,ram);}
    R(13)=pop(s,ram);s->pc=R(16);R(14)=pop(s,ram);
    return ram->oob==0;
}
