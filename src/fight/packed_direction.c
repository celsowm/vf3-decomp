/* Packed basis transform and direction encoding, original leaf 0x8c05865c.
 * Packed coordinates retain only the high half of each float. Table values
 * and quantization follow the retail format, including signed-byte lookups. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <string.h>
#define R(n) s->v[(n)]
#define F(n) s->v[21+(n)]
#define X(n) s->v[37+(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
static float value(uint32_t b){float f;memcpy(&f,&b,4);return f;}
static void condition(vf3_matrix_state*s,int yes){R(17)=(R(17)&~1u)|(yes!=0);}
static void add_carry(vf3_matrix_state*s)
{
    uint64_t sum=(uint64_t)R(5)*2+(R(17)&1);
    R(5)=(uint32_t)sum;condition(s,(int)(sum>>32));
}
int vf3_packed_direction_c(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t alias)
{
    unsigned row,k;
    if(!vf3_fpu_supported(R(18)) || !(R(18)&0x100000u))return 0;
    R(5)+=4;
    for(row=0;row<3;row++){
        for(k=0;k<3;k++){
            R(k)=(uint32_t)(int32_t)(int16_t)READ(R(5),2);R(5)+=2;
        }
        F(row*4+3)=0;
        for(k=0;k<3;k++){R(k)<<=16;s->v[53]=R(k);F(row*4+k)=R(k);}
        if(!vf3_fpu_ftrv(&X(0),&F(row*4),R(18),&F(row*4)))return 0;
    }
    vf3_matrix_move(s,12,13);vf3_matrix_move(s,14,15);R(18)^=0x100000u;
    /* Retain the direction through paired bank moves, then transpose the
     * transformed basis using single-register swaps. */
    s->v[53]=F(1);vf3_matrix_move(s,1,4);F(4)=s->v[53];
    s->v[53]=F(2);vf3_matrix_move(s,2,8);F(8)=s->v[53];
    s->v[53]=F(6);vf3_matrix_move(s,6,9);F(9)=s->v[53];
    vf3_matrix_swap(s);F(15)=0;
    if(!vf3_fpu_ftrv(&X(0),&F(12),R(18),&F(12)))return 0;
    R(18)^=0x100000u;vf3_matrix_swap(s);
    vf3_matrix_move(s,4,13);vf3_matrix_move(s,6,15);
    vf3_matrix_move(s,13,12);vf3_matrix_move(s,15,14);R(18)^=0x100000u;
    F(3)=0;condition(s,value(F(3))>value(F(4)));F(4)&=0x7fffffffu;R(5)=R(17)&1;
    condition(s,value(F(3))>value(F(6)));F(6)&=0x7fffffffu;add_carry(s);
    condition(s,value(F(6))>value(F(4)));R(0)=alias+0x058758;s->v[53]=F(6);
    if(R(17)&1){F(6)=F(4);F(4)=s->v[53];}
    add_carry(s);F(6)=vf3_fpu_binary(F(6),F(4),R(18),'/');R(5)+=R(5);
    R(2)=(uint32_t)(int32_t)(int16_t)READ(R(0)+R(5),2);
    R(0)=alias+0x058748;F(0)=READ(R(0),4);R(0)+=4;F(4)=READ(R(0),4);R(0)+=4;
    condition(s,value(F(3))>value(F(5)));F(3)=READ(R(0),4);R(0)+=4;
    R(1)=READ(R(0),4);R(0)-=4;
    if(!(R(17)&1)){
        F(3)=vf3_fpu_binary(F(3),F(5),R(18),'*');R(2)<<=16;
        s->v[53]=vf3_fpu_ftrc(F(3));R(5)=s->v[53];R(5)+=R(5);
        R(2)=(R(2)>>16)|(R(5)<<16);
    }
    F(4)=vf3_fpu_mac(F(0),F(6),F(4),R(18));F(6)=READ(R(0),4);
    F(5)=vf3_fpu_binary(F(5),F(5),R(18),'*');condition(s,R(2)&1);R(2)>>=1;
    s->v[53]=vf3_fpu_ftrc(F(4));F(3)=0x3f800000;
    F(3)=vf3_fpu_binary(F(3),F(5),R(18),'-');R(0)=s->v[53];
    F(3)=vf3_fpu_sqrt(F(3),R(18));R(0)&=255;
    R(1)=(uint32_t)(int32_t)(int8_t)READ(R(1)+R(0),1);
    F(3)=vf3_fpu_binary(F(3),F(6),R(18),'*');
    if(R(17)&1)R(1)=0u-R(1);
    R(2)+=R(1);s->v[53]=vf3_fpu_ftrc(F(3));R(18)^=0x100000u;
    R(0)=s->v[53]<<8;R(0)|=R(2);s->pc=R(16);return 1;
}
