/* Native point/sphere contact resolution at 0x8c093a9c. */
#include "sphere.h"
#include "aim_math.h"
#include <fenv.h>
#include <math.h>

#define R(n) (a->r[n])
#define F(n) (a->fr[n])

static float arithmetic(vf3_native_aim *a, float x, float y, char op)
{
    int old = fegetround();
    fesetround((a->fpscr & 1u) ? FE_TOWARDZERO : FE_TONEAREST);
    volatile float z;
    switch (op) { case '+': z=x+y; break; case '-': z=x-y; break;
                  case '*': z=x*y; break; default: z=x/y; break; }
    fesetround(old);
    uint32_t u = vf3_aim_ubits(z);
    if ((a->fpscr & 0x40000u) && !(u & 0x7f800000u) && (u & 0x7fffffu)) u &= 0x80000000u;
    return vf3_aim_fbits(u);
}
static float rd(vf3_native_aim *a, uint32_t p) { return vf3_aim_fbits(vf3_aim_u32(a,p)); }
static void wr(vf3_native_aim *a, uint32_t p, float f) { vf3_aim_set_u32(a,p,vf3_aim_ubits(f)); }

/* begin/end of a guest FP sequence: set host rounding + FTZ from fpscr */
static int fbegin(vf3_native_aim *a)
{
    int old = fegetround();
    fesetround((a->fpscr & 1u) ? FE_TOWARDZERO : FE_TONEAREST);
    return old;
}
static void fend(int old) { fesetround(old); }

/* the fipr inner product x . y over four floats (double accum, single flush);
 * exactly as vf3_fpu_fipr does */
static float fipr2(vf3_native_aim *a, const float x[4], const float y[4])
{
    int old = fbegin(a);
    volatile double sum = (double)x[0] * (double)y[0];
    sum += (double)x[1] * (double)y[1];
    sum += (double)x[2] * (double)y[2];
    sum += (double)x[3] * (double)y[3];
    float r = (float)sum;
    fend(old);
    return r;
}
/* fsrra: 1/sqrtf under the guest rounding */
static float fsrra(vf3_native_aim *a, float v)
{
    int old = fbegin(a);
    volatile float root = sqrtf(v);
    volatile float inv = 1.0f / root;
    fend(old);
    return vf3_aim_fbits(vf3_aim_ubits(inv));
}
/* fsqrt under the guest rounding */
static float fsqrt(vf3_native_aim *a, float v)
{
    int old = fbegin(a);
    volatile float r = sqrtf(v);
    fend(old);
    return r;
}

void vf3_native_sphere_resolve(vf3_native_aim *a)
{
    uint32_t sp = R(15), frame = sp - 28;
    vf3_aim_set_u32(a, sp - 4, R(14));
    R(14)=R(4); R(15)=frame; R(4)=frame+12;
    vf3_aim_set_u32(a, frame+8, R(5)); R(0)=4; R(5)=R(14);
    wr(a, frame+4, F(4)); vf3_aim_set_u32(a, frame, R(6));
    R(6)=vf3_aim_u32(a, frame+8);
    F(0)=rd(a,R(5)); R(5)+=4; F(3)=rd(a,R(6)); R(6)+=4;
    F(1)=rd(a,R(5)); R(5)+=4; F(4)=rd(a,R(6)); R(6)+=4;
    F(0)=arithmetic(a,F(0),F(3),'-');
    F(2)=rd(a,R(5)); F(5)=rd(a,R(6));
    F(1)=arithmetic(a,F(1),F(4),'-'); F(2)=arithmetic(a,F(2),F(5),'-');
    R(4)+=8; wr(a,R(4),F(2)); R(4)-=4; wr(a,R(4),F(1)); R(4)-=4; wr(a,R(4),F(0));
    R(4)=frame+12; F(0)=rd(a,R(4)); R(4)+=4; F(1)=rd(a,R(4)); R(4)+=4;
    F(2)=rd(a,R(4)); R(4)+=4; F(3)=0;
    int old=fegetround(); fesetround((a->fpscr&1u)?FE_TOWARDZERO:FE_TONEAREST);
    volatile double sum=(double)F(0)*F(0); sum+=(double)F(1)*F(1); sum+=(double)F(2)*F(2);
    volatile float dot=(float)sum; F(3)=dot; volatile float root=sqrtf(F(3)); F(0)=root;
    fesetround(old);
    R(0)=4; F(4)=F(0); F(3)=rd(a,frame+4);
    int contact=F(3)>F(4); a->sr=(a->sr&~1u)|contact;
    if (contact) {
        R(0)=4; F(3)=F(4); F(4)=rd(a,frame+4); R(5)=frame+12; R(4)=R(14);
        F(4)=arithmetic(a,F(4),F(3),'/');
        F(0)=rd(a,R(5)); R(5)+=4; F(1)=rd(a,R(5)); R(5)+=4; F(2)=rd(a,R(5)); R(5)+=4;
        R(4)+=12;
        F(2)=arithmetic(a,F(2),F(4),'*'); F(1)=arithmetic(a,F(1),F(4),'*'); F(0)=arithmetic(a,F(0),F(4),'*');
        R(4)-=4; wr(a,R(4),F(2)); R(4)-=4; wr(a,R(4),F(1)); R(4)-=4; wr(a,R(4),F(0));
        R(5)=vf3_aim_u32(a,frame+8); R(4)=R(14);
        F(0)=rd(a,R(4)); R(4)+=4; F(3)=rd(a,R(5)); R(5)+=4;
        F(1)=rd(a,R(4)); R(4)+=4; F(4)=rd(a,R(5)); R(5)+=4;
        F(2)=rd(a,R(4)); R(4)+=4; F(5)=rd(a,R(5)); R(5)+=4;
        F(0)=arithmetic(a,F(0),F(3),'+'); F(2)=arithmetic(a,F(2),F(5),'+'); F(1)=arithmetic(a,F(1),F(4),'+');
        R(4)-=4; wr(a,R(4),F(2)); R(4)-=4; wr(a,R(4),F(1)); R(4)-=4; wr(a,R(4),F(0));
        R(3)=vf3_aim_u32(a,frame); R(2)=(uint32_t)(int32_t)(int16_t)vf3_aim_h16(a,0x0c093c32u);
        R(1)=vf3_aim_u32(a,R(3))|R(2); vf3_aim_set_u32(a,R(3),R(1));
    } else R(3)=vf3_aim_u32(a,0x0c093b0cu);
    R(0)=vf3_aim_u32(a,frame); R(15)=sp; R(0)=vf3_aim_u32(a,R(0)); R(14)=vf3_aim_u32(a,sp-4);
}

/* Inline vector sequences used by the segment routine.  The pointer and FR
 * side effects are part of the interface to the enclosing guest body. */
static void vec_sub(vf3_native_aim *a, uint32_t d, uint32_t p, uint32_t q)
{
    R(4)=d; R(5)=p+8; R(6)=q+8;
    F(0)=rd(a,p); F(3)=rd(a,q); F(1)=rd(a,p+4); F(4)=rd(a,q+4);
    F(0)=arithmetic(a,F(0),F(3),'-'); F(2)=rd(a,p+8); F(5)=rd(a,q+8);
    F(1)=arithmetic(a,F(1),F(4),'-'); F(2)=arithmetic(a,F(2),F(5),'-');
    wr(a,d+8,F(2)); wr(a,d+4,F(1)); wr(a,d,F(0));
}
static void vec_add(vf3_native_aim *a, uint32_t d, uint32_t p, uint32_t q)
{
    R(4)=d; R(5)=p+12; R(6)=q+12;
    F(0)=rd(a,p); F(3)=rd(a,q); F(1)=rd(a,p+4); F(4)=rd(a,q+4);
    F(2)=rd(a,p+8); F(5)=rd(a,q+8);
    F(0)=arithmetic(a,F(0),F(3),'+'); F(2)=arithmetic(a,F(2),F(5),'+');
    F(1)=arithmetic(a,F(1),F(4),'+');
    wr(a,d+8,F(2)); wr(a,d+4,F(1)); wr(a,d,F(0));
}
static void vec_scale(vf3_native_aim *a, uint32_t d, uint32_t p)
{
    R(4)=d; R(5)=p+12; F(0)=rd(a,p); F(1)=rd(a,p+4); F(2)=rd(a,p+8);
    F(2)=arithmetic(a,F(2),F(4),'*'); F(1)=arithmetic(a,F(1),F(4),'*');
    F(0)=arithmetic(a,F(0),F(4),'*');
    wr(a,d+8,F(2)); wr(a,d+4,F(1)); wr(a,d,F(0));
}
static void vec_dot(vf3_native_aim *a, uint32_t p, uint32_t q)
{
    R(4)=p+12; R(5)=q+12;
    F(0)=rd(a,p); F(1)=rd(a,p+4); F(2)=rd(a,p+8); F(3)=0;
    F(4)=rd(a,q); F(5)=rd(a,q+4); F(6)=rd(a,q+8); F(7)=0;
    int old=fegetround(); fesetround((a->fpscr&1u)?FE_TOWARDZERO:FE_TONEAREST);
    volatile double sum=(double)F(0)*F(4); sum+=(double)F(1)*F(5); sum+=(double)F(2)*F(6);
    volatile float value=(float)sum; fesetround(old);
    uint32_t u=vf3_aim_ubits(value);
    if ((a->fpscr & 0x40000u) && !(u & 0x7f800000u) && (u & 0x7fffffu)) u &= 0x80000000u;
    F(7)=vf3_aim_fbits(u); F(0)=F(7); F(3)=0; F(4)=F(0);
}

void vf3_native_sphere_segment(vf3_native_aim *a)
{
    uint32_t sp=R(15), pr=a->pr, f=sp-96;
    uint32_t saved[6]={R(14),R(13),R(12),R(11),R(10),R(9)};
    float f15=F(15), f14=F(14);
    for (int i=0;i<6;++i) vf3_aim_set_u32(a,sp-4u*(i+1),saved[i]);
    wr(a,sp-28,f15); wr(a,sp-32,f14); vf3_aim_set_u32(a,sp-36,pr);
    uint32_t point=R(4), result=R(5), dist=R(6), limit=R(7);
    R(13)=point; R(10)=result; R(11)=dist; R(12)=limit; R(15)=f;
    R(9)=vf3_aim_u32(a,f+104); R(14)=vf3_aim_u32(a,f+96)+vf3_aim_u32(a,f+100);
    uint32_t seg=R(14);
    for(int i=0;i<3;++i) { F(3)=rd(a,seg+4*i); wr(a,f+48+4*i,F(3)); }
    for(int i=0;i<3;++i) { F(3)=rd(a,seg+24+4*i); wr(a,f+12+4*i,F(3)); }
    F(3)=rd(a,seg+36); wr(a,dist,F(3)); F(3)=rd(a,seg+40); wr(a,limit,F(3));
    vec_sub(a,f,point,seg); vec_dot(a,f+12,f); F(15)=F(0); F(4)=F(0);
    vec_scale(a,f+36,f+12); vec_add(a,f+36,f+36,seg);
    vec_sub(a,f+24,point,f+36); vec_dot(a,f+24,f+24); F(14)=F(0);
    F(3)=rd(a,limit);
    if (F(3)>F(14)) {
        F(3)=F(15); F(15)=arithmetic(a,F(15),F(3),'*');
        vec_sub(a,f,f+36,seg); vec_dot(a,f+12,f); F(3)=0;
        if (F(3)>F(4)) {
            F(3)=rd(a,limit);
            if (!(F(15)>F(3))) {
                F(4)=rd(a,dist); F(5)=rd(a,limit);
                R(4)=point; R(5)=f+48; R(6)=R(9); a->pr=0x0c0939c0u;
                vf3_native_sphere_resolve(a); R(15)=f;
            }
        } else {
            F(3)=rd(a,seg+44);
            if (F(3)>F(15)) {
                F(2)=vf3_aim_fbits(0x33d6bf94u); F(4)=rd(a,dist);
                if (F(2)>F(14)) F(3)=0;
                else {
                    int old=fegetround(); fesetround((a->fpscr&1u)?FE_TOWARDZERO:FE_TONEAREST);
                    volatile float root=sqrtf(F(14)); volatile float inv=1.0f/root;
                    F(3)=inv; fesetround(old);
                }
                F(4)=arithmetic(a,F(4),F(3),'*');
                vec_scale(a,point,f+24); vec_add(a,point,point,f+36);
                vf3_aim_set_u32(a,R(9),vf3_aim_u32(a,R(9))|0x100u);
            } else {
                F(3)=rd(a,seg+48);
                if (!(F(15)>F(3))) {
                    for(int i=0;i<3;++i) { F(3)=rd(a,seg+12+4*i); wr(a,f+48+4*i,F(3)); }
                    F(5)=rd(a,limit); F(4)=rd(a,dist);
                    R(4)=point; R(5)=seg+12; R(6)=R(9); a->pr=0x0c093a70u;
                    vf3_native_sphere_resolve(a); R(15)=f;
                }
            }
        }
    }
    for(int i=0;i<3;++i) { F(3)=rd(a,f+48+4*i); wr(a,result+4*i,F(3)); }
    R(0)=8; for(int i=0;i<6;++i) R(14-i)=saved[i];
    F(15)=f15; F(14)=f14; R(15)=sp; a->pr=pr;
}

static float multiply_add(vf3_native_aim *a, float x, float y, float z)
{
    int old=fbegin(a); volatile float value=fmaf(x,y,z); fend(old);
    uint32_t u=vf3_aim_ubits(value);
    if ((a->fpscr&0x40000u) && !(u&0x7f800000u) && (u&0x7fffffu)) u &= 0x80000000u;
    return vf3_aim_fbits(u);
}

/* The record's list selects either a segment or a point/sphere contact. */
void vf3_native_point_contact(vf3_native_aim *a)
{
    uint32_t sp=R(15), pr=a->pr, f=sp-40;
    uint32_t saved[4]={R(14),R(13),R(12),R(11)};
    for(int i=0;i<4;++i) vf3_aim_set_u32(a,sp-4u*(i+1),saved[i]);
    vf3_aim_set_u32(a,sp-20,pr); R(15)=f;
    uint32_t mover=R(4),target=R(5),point=R(6),centre=R(7);
    R(12)=vf3_aim_u32(a,f+48); uint32_t hit=R(12);
    vf3_aim_set_u32(a,hit,vf3_aim_u32(a,hit)&0xffffeeffu); R(14)=point;
    uint32_t kind;
    if (!(vf3_aim_h16(a,mover+16)&1u)) {
        F(4)=rd(a,mover+0x88); F(3)=rd(a,point+4);
        if (F(4)>F(3)) {
            F(5)=rd(a,centre+4); F(6)=rd(a,target+36); F(9)=vf3_aim_fbits(0x33d6bf94u);
            F(5)=arithmetic(a,F(5),F(4),'-');
            F(3)=F(6); F(3)=arithmetic(a,F(3),F(6),'*');
            F(2)=F(5); F(2)=arithmetic(a,F(2),F(5),'*');
            F(5)=F(3); F(5)=arithmetic(a,F(5),F(2),'-'); F(3)=rd(a,centre);
            if (F(9)>F(5)) F(6)=0; else F(6)=fsqrt(a,F(5));
            F(5)=rd(a,point); F(7)=rd(a,point+8);
            F(5)=arithmetic(a,F(5),F(3),'-'); F(3)=rd(a,centre+8);
            F(7)=arithmetic(a,F(7),F(3),'-');
            F(3)=F(5); F(3)=arithmetic(a,F(3),F(5),'*');
            F(0)=F(7); F(3)=multiply_add(a,F(0),F(7),F(3)); F(8)=F(3);
            if (F(9)>F(3)) F(3)=0; else F(3)=fsrra(a,F(8));
            F(6)=arithmetic(a,F(6),F(3),'*'); F(3)=rd(a,centre);
            F(0)=F(5); F(3)=multiply_add(a,F(0),F(6),F(3)); wr(a,point,F(3));
            F(2)=rd(a,centre+8); F(0)=F(6); F(2)=multiply_add(a,F(0),F(7),F(2));
            wr(a,point+8,F(2)); wr(a,point+4,F(4));
            vf3_aim_set_u32(a,hit,vf3_aim_u32(a,hit)|0x1000u);
            goto done;
        }
        kind=vf3_aim_u8(a,target+54);
    } else {
        kind=vf3_aim_u8(a,target+54);
        if (kind!=9 && kind!=0) kind=6;
    }
    R(11)=0x0c0fc660u+kind*32u;
    for (;;) {
        int32_t count=(int16_t)vf3_aim_h16(a,R(11));
        uint32_t off=vf3_aim_h16(a,R(11)+2); R(11)+=4;
        if (count<0) break;
        if (count) {
            vf3_aim_set_u32(a,f-4,hit); vf3_aim_set_u32(a,f-8,off);
            vf3_aim_set_u32(a,f-12,vf3_aim_u32(a,f+44));
            R(15)=f-12; R(4)=point; R(5)=f+8; R(6)=f; R(7)=f+4;
            a->pr=0x0c09371cu; vf3_native_sphere_segment(a); R(15)=f;
        } else {
            R(13)=vf3_aim_u32(a,f+40)+off;
            F(3)=rd(a,R(13)+12); wr(a,f,F(3)); F(3)=rd(a,R(13)+16); wr(a,f+4,F(3));
            F(4)=rd(a,f); F(5)=F(3); R(4)=point; R(5)=R(13); R(6)=hit;
            a->pr=0x0c093740u; vf3_native_sphere_resolve(a); R(15)=f;
        }
    }
done:
    for(int i=0;i<4;++i) R(14-i)=saved[i];
    R(15)=sp; a->pr=pr;
}
