/* Native two-length and orientation helper, 0x8c09dc34. */
#include "unit_triple.h"
#include "aim_math.h"
#include "pass_prep.h"
#include "matrix_rotate_sc.h"
#include "rotation_xmtrx.h"
#include <fenv.h>
#include <math.h>
#include <stdint.h>

#define R(n) (a->r[n])
#define F(n) (a->fr[n])
static float rd(vf3_native_aim*a,uint32_t p){return vf3_aim_fbits(vf3_aim_u32(a,p));}
static void wr(vf3_native_aim*a,uint32_t p,float f){vf3_aim_set_u32(a,p,vf3_aim_ubits(f));}
static float flush(vf3_native_aim*a,float v){uint32_t u=vf3_aim_ubits(v);if((a->fpscr&0x40000u)&&!(u&0x7f800000u)&&(u&0x7fffffu))u&=0x80000000u;return vf3_aim_fbits(u);}
static float mul(vf3_native_aim*a,float x,float y){int old=fegetround();fesetround((a->fpscr&1u)?FE_TOWARDZERO:FE_TONEAREST);volatile float r=x*y;fesetround(old);return flush(a,r);}
static float mac(vf3_native_aim*a,float x,float y,float z){int old=fegetround();fesetround((a->fpscr&1u)?FE_TOWARDZERO:FE_TONEAREST);volatile float r=fmaf(x,y,z);fesetround(old);return flush(a,r);}
static float root(vf3_native_aim*a,float x,int inverse){int old=fegetround();fesetround((a->fpscr&1u)?FE_TOWARDZERO:FE_TONEAREST);volatile float r=sqrtf(x);if(inverse)r=1.0f/r;fesetround(old);return flush(a,r);}

void vf3_native_unit_triple(vf3_native_aim *a)
{
    uint32_t sp=R(15),pr=a->pr,f=sp-40;float saved[4]={F(15),F(14),F(13),F(12)};
    for(int i=0;i<4;++i)wr(a,sp-4u*(i+1),saved[i]);vf3_aim_set_u32(a,sp-20,pr);
    R(15)=f;vf3_aim_set_u32(a,f+4,R(5));R(5)=f+8;vf3_aim_set_u32(a,f,R(6));
    a->pr=0x0c09dc4au;vf3_native_pass_prep(a);R(15)=f;
    F(5)=rd(a,f+8);F(4)=rd(a,f+12);F(0)=F(5);F(3)=F(4);F(3)=mul(a,F(3),F(4));
    F(12)=rd(a,f+16);R(0)=0x0c09dd5cu;F(2)=vf3_aim_fbits(0x33d6bf94u);
    F(3)=mac(a,F(0),F(5),F(3));F(15)=F(3);F(14)=F(15);
    F(6)=F(2)>F(15)?0:root(a,F(15),1);
    F(0)=F(12);F(14)=mac(a,F(0),F(12),F(14));F(3)=vf3_aim_fbits(0x33d6bf94u);
    int tiny=F(3)>F(14);F(3)=F(4);F(13)=tiny?0:root(a,F(14),1);
    F(4)=F(6);F(4)=mul(a,F(4),F(3));F(3)=F(5);F(5)=F(6);F(5)=mul(a,F(5),F(3));
    a->pr=0x0c09dc96u;vf3_native_matrix_rotate_sc(a);R(15)=f;
    F(3)=F(13);F(3)=mul(a,F(3),F(12));R(0)=0x0c09dd5cu;F(4)=F(3);
    F(3)=vf3_aim_fbits(0x33d6bf94u);F(4)=vf3_aim_fbits(vf3_aim_ubits(F(4))^0x80000000u);
    F(2)=F(3)>F(15)?0:root(a,F(15),0);F(5)=F(2);F(5)=mul(a,F(5),F(13));
    R(3)=0x0c03c8b0u;a->pr=0x0c09dcb6u;vf3_native_rotation_xmtrx(a);R(15)=f;
    R(0)=0x0c09dd5cu;R(2)=vf3_aim_u32(a,f+4);F(2)=vf3_aim_fbits(0x33d6bf94u);
    F(3)=F(2)>F(14)?0:root(a,F(14),0);wr(a,R(2),F(3));R(3)=vf3_aim_u32(a,f);wr(a,R(3),F(13));
    for(int i=0;i<4;++i)F(15-i)=saved[i];R(15)=sp;a->pr=pr;
}
