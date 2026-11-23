/* Native terrain height lookup, including the stage-11 correction. */
#include "terrain_height.h"
#include "terrain_wrap.h"
#include "terrain_flat.h"
#include "terrain_ext.h"
#include "aim_math.h"
#include <fenv.h>
#include <math.h>
#include <stdint.h>

#define R(n) (a->r[n])
#define F(n) (a->fr[n])
static float rd(vf3_native_aim *a,uint32_t p) { return vf3_aim_fbits(vf3_aim_u32(a,p)); }
static void wr(vf3_native_aim *a,uint32_t p,float f) { vf3_aim_set_u32(a,p,vf3_aim_ubits(f)); }
static float finish(vf3_native_aim *a,float f)
{
    uint32_t u=vf3_aim_ubits(f);
    if((a->fpscr&0x40000u)&&!(u&0x7f800000u)&&(u&0x7fffffu)) u&=0x80000000u;
    return vf3_aim_fbits(u);
}
static float bin(vf3_native_aim *a,float x,float y,char op)
{
    int old=fegetround();fesetround((a->fpscr&1u)?FE_TOWARDZERO:FE_TONEAREST);
    volatile float z; if(op=='*') z=x*y; else if(op=='+') z=x+y; else z=x-y;
    fesetround(old);return finish(a,z);
}
static float mac(vf3_native_aim *a,float x,float y,float z)
{
    int old=fegetround();fesetround((a->fpscr&1u)?FE_TOWARDZERO:FE_TONEAREST);
    volatile float r=fmaf(x,y,z);fesetround(old);return finish(a,r);
}
static uint32_t trunc_guest(float x)
{
    if(isnan(x)||x < -2147483648.0) return 0x80000000u;
    if((double)x>=2147483648.0) return 0x7fffffffu;
    return (uint32_t)(int32_t)x;
}
static float from_int(vf3_native_aim *a,uint32_t x)
{
    int old=fegetround();fesetround((a->fpscr&1u)?FE_TOWARDZERO:FE_TONEAREST);
    volatile int32_t in=(int32_t)x;volatile float out=(float)in;fesetround(old);return out;
}

void vf3_native_terrain_height(vf3_native_aim *a)
{
    uint32_t sp=R(15),pr=a->pr,f=sp-48,s14=R(14),s13=R(13);
    uint32_t x=f+8,z=f+4,t0=f,t12=f+12,t16=f+16,res=f+20;
    vf3_aim_set_u32(a,sp-4,s14);vf3_aim_set_u32(a,sp-8,s13);vf3_aim_set_u32(a,sp-12,pr);
    R(15)=f;wr(a,x,F(4));wr(a,z,F(5));
    R(5)=x;R(3)=0x0c29b880u;R(6)=z;R(2)=0x0c1b9610u;
    R(0)=vf3_aim_u8(a,R(3));R(14)=vf3_aim_u32(a,R(2));R(13)=R(0)&15u;R(0)&=255u;R(4)=R(13);
    a->pr=0x8c068e38u;vf3_native_terrain_wrap(a);R(15)=f;
    uint32_t table=R(14);
    if (!table) {
        F(5)=rd(a,z);R(4)=f+24;F(4)=rd(a,x);R(0)=8;
        a->pr=0x8c068e4au;vf3_native_terrain_flat(a);R(15)=f;R(0)=20;wr(a,res,F(0));
    } else {
        F(4)=rd(a,0x0c068fd0u);R(0)=8;F(3)=rd(a,x);if(!(F(3)>F(4))) wr(a,x,F(4));
        F(3)=rd(a,z);if(!(F(3)>F(4))) wr(a,z,F(4));
        F(4)=rd(a,0x0c068fd4u);F(3)=rd(a,x);if(!(F(4)>F(3))) wr(a,x,F(4));
        F(3)=rd(a,z);if(!(F(4)>F(3))) wr(a,z,F(4));
        F(5)=rd(a,0x0c068fd8u);F(4)=rd(a,0x0c068fdcu);F(2)=rd(a,x);F(3)=F(4);R(3)=7;F(0)=F(5);
        F(3)=mac(a,F(0),F(2),F(3));R(1)=127;a->fpul=trunc_guest(F(3));wr(a,t0,F(3));
        F(2)=rd(a,z);R(2)=0x3f80;F(4)=mac(a,F(0),F(2),F(4));R(4)=a->fpul;F(6)=F(4);
        a->fpul=trunc_guest(F(6));F(4)=rd(a,t0);R(5)=a->fpul;a->fpul=R(4);R(4)&=R(1);
        F(3)=from_int(a,a->fpul);a->fpul=R(5);R(5)<<=R(3)&31u;R(5)&=R(2);F(2)=from_int(a,a->fpul);R(4)|=R(5);
        F(4)=bin(a,F(4),F(3),'-');F(5)=F(2);R(0)=R(4);F(5)=F(6);F(3)=F(2);R(0)<<=2;
        F(5)=bin(a,F(5),F(3),'-');F(3)=rd(a,table+R(0));R(0)=16;F(6)=1;F(8)=F(6);F(7)=F(6);
        F(7)=bin(a,F(7),F(4),'-');wr(a,t16,F(3));R(0)=R(4)+1;F(8)=bin(a,F(8),F(5),'-');R(0)<<=2;
        F(2)=rd(a,table+R(0));R(0)=12;wr(a,t12,F(2));R(0)=(0x80u+R(4))<<2;F(1)=rd(a,table+R(0));wr(a,t0,F(1));
        R(0)=(0x81u+R(4))<<2;F(6)=rd(a,table+R(0));R(0)=16;F(3)=rd(a,t16);R(0)=16;
        F(3)=bin(a,F(3),F(7),'*');wr(a,t16,F(3));R(0)=12;F(2)=rd(a,t12);R(0)=12;
        F(6)=bin(a,F(6),F(4),'*');F(2)=bin(a,F(2),F(4),'*');wr(a,t12,F(2));R(0)=16;F(1)=rd(a,t0);
        F(1)=bin(a,F(1),F(7),'*');wr(a,t0,F(1));F(3)=rd(a,t16);R(0)=16;F(3)=bin(a,F(3),F(8),'*');wr(a,t16,F(3));
        R(0)=12;F(2)=rd(a,t12);R(0)=12;F(2)=bin(a,F(2),F(8),'*');wr(a,t12,F(2));R(0)=20;F(1)=rd(a,t0);F(0)=F(5);
        F(2)=mac(a,F(0),F(6),F(2));F(3)=mac(a,F(0),F(1),F(3));wr(a,t0,F(3));F(4)=F(2);F(3)=bin(a,F(3),F(4),'+');wr(a,res,F(3));
        R(0)=R(13);a->sr&=~1u;
        if(R(13)==11) {
            a->sr|=1u;vf3_aim_set_u32(a,f-4,f);vf3_aim_set_u32(a,f-8,f+12);
            R(2)=0x0c087aceu;R(3)=f+12;R(15)=f-8;R(4)=f+8;R(5)=f+20;R(6)=f+4;R(7)=f+16;
            a->pr=0x0c068f82u;vf3_native_terrain_ext(a);R(15)=f;
        }
        R(0)=20;
    }
    F(0)=rd(a,res);R(15)=sp;R(14)=s14;R(13)=s13;a->pr=pr;
}
