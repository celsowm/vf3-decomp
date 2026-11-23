/* Native 0x8c03b450: XMTRX times a point with homogeneous coordinate one. */
#include "xform_point.h"
#include "aim_math.h"
#include <fenv.h>
#include <math.h>
#include <stdint.h>

static double product(float matrix, float vector, int choose_vector)
{
    uint32_t m=vf3_aim_ubits(matrix),v=vf3_aim_ubits(vector);
    if((m&0x7fffffffu)>0x7f800000u && (v&0x7fffffffu)>0x7f800000u)
        return (double)vf3_aim_fbits((choose_vector?v:m)|0x00400000u);
    return (double)matrix*(double)vector;
}

void vf3_native_xform_point(vf3_native_aim *a)
{
    float in[4],out[4];
    for(int i=0;i<3;++i)in[i]=vf3_aim_fbits(vf3_aim_u32(a,a->r[4]+4u*i));
    in[3]=1.0f;a->r[4]+=12;
    int old=fegetround();fesetround((a->fpscr&1u)?FE_TOWARDZERO:FE_TONEAREST);
    for(int row=0;row<4;++row){
        volatile double sum=product(a->xm[row],in[0],row!=0);
        for(int col=1;col<4;++col){
            volatile double term=product(a->xm[col*4+row],in[col],row!=0);
            if(!isnan(sum))sum=sum+term;
        }
        volatile float value=(float)sum;uint32_t bits=vf3_aim_ubits(value);
        if((a->fpscr&0x40000u)&&!(bits&0x7f800000u)&&(bits&0x7fffffu))bits&=0x80000000u;
        out[row]=vf3_aim_fbits(bits);
    }
    fesetround(old);
    for(int i=0;i<4;++i)a->fr[4+i]=out[i];
    for(int i=0;i<3;++i)vf3_aim_set_u32(a,a->r[5]+4u*i,vf3_aim_ubits(out[i]));
}
