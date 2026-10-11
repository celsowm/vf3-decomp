/* Three-component angle wrapping at 0x8c09f6fc. Thresholds and increments
 * deliberately retain the retail arithmetic, including the large-value reset. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <string.h>
#define R(n) s->v[(n)]
#define F(n) s->v[21+(n)]
#define READ(a) vf3_matrix_read(ram,(a),4)
#define WRITE(a,v) vf3_matrix_write(ram,(a),(v),4)
static float value(uint32_t bits)
{ float result;memcpy(&result,&bits,4);return result; }
static void condition(vf3_matrix_state *s,int yes)
{ R(17)=(R(17)&~1u)|(yes!=0); }
static void arithmetic(vf3_matrix_state *s,unsigned to,unsigned from,char op)
{ F(to)=vf3_fpu_binary(F(to),F(from),R(18),op); }

int vf3_angle_wrap_c(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t alias)
{
    uint32_t saved_fr13=F(13);
    unsigned axis;
    if(!vf3_fpu_supported(R(18)) || (R(18)&0x100000u))return 0;
    R(0)=alias+0x09f7b8;R(15)-=4;WRITE(R(15),saved_fr13);
    F(9)=READ(R(0));R(0)=alias+0x09f7bc;F(10)=READ(R(0));
    R(0)=alias+0x09f7c0;F(11)=READ(R(0));
    R(0)=alias+0x09f7c4;F(8)=READ(R(0));
    R(0)=alias+0x09f7c8;F(7)=READ(R(0));
    R(0)=4;F(3)=READ(R(4));R(15)-=12;
    R(6)=R(5)+4;WRITE(R(15)+4,F(3));
    F(3)=READ(R(4)+4);R(0)=8;F(5)=READ(R(5));WRITE(R(15),F(3));
    F(3)=READ(R(4)+8);R(4)=R(5)+8;F(6)=READ(R(6));
    WRITE(R(15)+8,F(3));F(4)=READ(R(4));

    /* Each component uses a different set of ABI scratch registers. Keep those
     * assignments while expressing the shared wrap operation as one loop. */
    for(axis=0;axis<3;axis++){
        unsigned difference=axis==0?1:axis==1?5:6;
        unsigned magnitude=axis==0?0:axis==1?1:5;
        unsigned current=axis==0?5:axis==1?6:4;
        unsigned step=axis==0?1:5;
        uint32_t output=axis==0?R(5):axis==1?R(6):R(4);
        for(;;){
            if(!s->budget--)return 0;
            if(axis==0){
                R(0)=4;F(2)=0;F(1)=READ(R(15)+4);R(0)=alias+0x09f7cc;
                arithmetic(s,1,5,'-');F(0)=F(1)&0x7fffffffu;
            }else if(axis==1){
                F(5)=READ(R(15));arithmetic(s,5,6,'-');F(1)=F(5)&0x7fffffffu;
            }else{
                R(0)=8;F(6)=READ(R(15)+8);arithmetic(s,6,4,'-');F(5)=F(6)&0x7fffffffu;
            }
            condition(s,value(F(7))>value(F(magnitude)));
            if(axis==0)F(13)=READ(R(0));
            if(!(R(17)&1)){WRITE(output,F(2));break;}
            condition(s,value(F(8))>value(F(magnitude)));
            if(R(17)&1){
                condition(s,value(F(9))>value(F(magnitude)));
                if(R(17)&1)break;
                F(3)=0;condition(s,value(F(3))>value(F(difference)));
                F(step)=F((R(17)&1)?13:10);
            }else{
                F(3)=0;condition(s,value(F(3))>value(F(difference)));
                if(R(17)&1){
                    R(0)=alias+(axis==2?0x09f8d4:0x09f7d0);F(step)=READ(R(0));
                }else F(step)=F(11);
            }
            F(3)=F(current);F(current)=F(step);arithmetic(s,current,3,'+');
            WRITE(output,F(current));
        }
    }
    R(15)+=12;s->pc=R(16);F(13)=READ(R(15));R(15)+=4;return 1;
}
