/* Register-complete native entry for 0x8c091de6. */
#include "pose_blend.h"
#include "aim_math.h"
#include <fenv.h>
#include <math.h>

static int32_t shift_q14(uint32_t value)
{
    if(value&0x80000000u){uint32_t magnitude=(~value)+1u;return -(int32_t)((magnitude+0x3fffu)>>14);}
    return (int32_t)(value>>14);
}
static float guest_float(vf3_native_aim *a,float x,float y,int multiply)
{
    int old=fegetround();fesetround((a->fpscr&1u)?FE_TOWARDZERO:FE_TONEAREST);
    volatile float v=multiply?x*y:x+y;fesetround(old);
    uint32_t bits=vf3_aim_ubits(v);
    if((a->fpscr&0x40000u)&&!(bits&0x7f800000u)&&(bits&0x7fffffu))bits&=0x80000000u;
    return vf3_aim_fbits(bits);
}
void vf3_native_pose_blend(vf3_native_aim *a)
{
    uint32_t sp=a->r[15],obj=a->r[4];
    vf3_aim_set_u32(a,sp-4,a->r[14]);
    a->fr[4]=vf3_aim_fbits(vf3_aim_u32(a,obj+0x9c));
    a->fr[5]=vf3_aim_fbits(vf3_aim_u32(a,obj+0xa0));
    a->fr[4]=guest_float(a,a->fr[4],a->fr[5],0);a->fr[5]=1.0f;
    if(a->fr[4]>a->fr[5])a->fr[4]=a->fr[5];
    vf3_aim_set_u32(a,obj+0x9c,vf3_aim_ubits(a->fr[4]));
    vf3_aim_set_u32(a,sp-4,a->r[13]);vf3_aim_set_u32(a,sp-8,a->r[12]);vf3_aim_set_u32(a,sp-12,a->macl);
    a->fr[3]=16384.0f;a->fr[4]=guest_float(a,a->fr[4],a->fr[3],1);
    double f=a->fr[4];int32_t w;
    if(isnan(f)||f< -2147483648.0)w=INT32_MIN;
    else if(f>=2147483648.0)w=INT32_MAX;
    else w=(int32_t)f;
    uint32_t aw=0x4000u-(uint32_t)w,dst=obj+104u;int32_t sum=0,bw=0;
    for(unsigned i=0;i<26;++i){
        int32_t va=(int16_t)vf3_aim_h16(a,obj+2*i),vb=(int16_t)vf3_aim_h16(a,obj+52+2*i);
        bw=(int32_t)((uint32_t)vb*(uint32_t)w);
        sum=shift_q14((uint32_t)va*aw+(uint32_t)bw);
        vf3_aim_set_u16(a,dst,(uint16_t)sum);dst+=2;
    }
    a->r[0]=aw;a->r[1]=dst;a->r[3]=(uint32_t)-14;a->r[4]=(uint32_t)sum;
    a->r[5]=(uint32_t)bw;a->r[6]=0;a->r[7]=(uint32_t)w;a->fpul=(uint32_t)w;a->sr|=1u;
}
