/* Terrain grid lookup and stage-11 correction at 0x8c06938c. */
#include "terrain_probe.h"
#include "terrain_wrap.h"
#include "terrain_flat.h"
#include "terrain_ext.h"
#include "terrain_plane_hit.h"
#include "quad_node.h"
#include "aim_math.h"
#include <fenv.h>
#include <stdint.h>

#define R(n) (a->r[n])
#define F(n) (a->fr[n])
static float rd(vf3_native_aim *a,uint32_t p){return vf3_aim_fbits(vf3_aim_u32(a,p));}
static void wr(vf3_native_aim *a,uint32_t p,float f){vf3_aim_set_u32(a,p,vf3_aim_ubits(f));}
static float add(vf3_native_aim *a,float x,float y)
{
    int old=fegetround();fesetround((a->fpscr&1u)?FE_TOWARDZERO:FE_TONEAREST);
    volatile float z=x+y;fesetround(old);uint32_t u=vf3_aim_ubits(z);
    if((a->fpscr&0x40000u)&&!(u&0x7f800000u)&&(u&0x7fffffu))u&=0x80000000u;
    return vf3_aim_fbits(u);
}

void vf3_native_terrain_probe(vf3_native_aim *a)
{
    uint32_t sp=R(15),pr=a->pr,f=sp-64,saved[4]={R(14),R(13),R(12),R(11)};
    float f15=F(15);uint32_t out_h=R(4),out_n=R(5),result;
    for(int i=0;i<4;++i)vf3_aim_set_u32(a,sp-4u*(i+1),saved[i]);
    wr(a,sp-20,f15);vf3_aim_set_u32(a,sp-24,pr);
    R(13)=out_h;R(11)=out_n;R(12)=15u&vf3_aim_u8(a,0x0c29b880u);R(15)=f;
    wr(a,f,F(4));wr(a,f+4,F(5));R(4)=R(12);R(5)=f;R(6)=f+4;
    a->pr=0x0c0693b8u;vf3_native_terrain_wrap(a);R(15)=f;
    uint32_t grid=vf3_aim_u32(a,0x0c29beb4u);
    if(!grid){
        R(0)=4;R(4)=R(11);F(5)=rd(a,f+4);F(4)=rd(a,f);
        a->pr=0x0c0693ccu;vf3_native_terrain_flat(a);R(15)=f;wr(a,R(13),F(0));result=0;
        goto done;
    }
    F(15)=0;float x=rd(a,f),z=rd(a,f+4);int found=0;
    if(!(14.0f>x && 14.0f>z && x>-14.0f && z>-14.0f)){
        wr(a,R(13),F(15));R(14)=1;
    }else{
        wr(a,f+12,x);wr(a,f+8,z);F(5)=x;F(4)=16;F(5)=add(a,F(5),F(4));
        F(4)=z;F(3)=16;F(4)=add(a,F(4),F(3));
        uint32_t cell=((uint32_t)(int32_t)F(5)&31u)|(((uint32_t)(int32_t)F(4)&31u)<<5);
        uint32_t list=vf3_aim_u32(a,grid+cell*4);
        if(list==0xffffffffu){wr(a,R(13),F(15));R(14)=2;}
        else{
            R(14)=list+vf3_aim_u32(a,0x0c113a0cu);
            for(;;){
                if(vf3_aim_u32(a,R(14))==0xffffffffu){wr(a,R(13),F(15));R(14)=2;break;}
                R(4)=R(14);F(5)=rd(a,f+8);F(4)=rd(a,f+12);a->pr=0x0c06945eu;
                vf3_native_quad_node(a);R(15)=f;R(7)=R(0);
                if(R(7)){
                    R(6)=f+28;R(5)=R(13);R(4)=R(14);F(5)=rd(a,f+8);F(4)=rd(a,f+12);
                    a->pr=0x0c069476u;vf3_native_terrain_plane_hit(a);R(15)=f;R(14)=R(0);
                    vf3_aim_set_u32(a,f+20,vf3_aim_u32(a,f+28));
                    vf3_aim_set_u32(a,f+24,vf3_aim_u32(a,f+32));
                    vf3_aim_set_u32(a,f+16,vf3_aim_u32(a,f+36));found=1;break;
                }
                R(14)+=8;
            }
        }
    }
    if(!found){wr(a,f+24,1);wr(a,f+16,F(15));wr(a,f+20,F(15));}
    if(R(12)==13)R(14)|=4;
    else if(R(12)==11){
        uint32_t spc=f-8;vf3_aim_set_u32(a,f-4,f+16);vf3_aim_set_u32(a,spc,f+28);
        R(15)=spc;R(5)=R(13);R(6)=spc+16;R(7)=spc+28;R(4)=spc+20;
        a->pr=0x0c0694f0u;vf3_native_terrain_ext(a);R(15)=f;
    }
    vf3_aim_set_u32(a,R(11),vf3_aim_u32(a,f+20));
    vf3_aim_set_u32(a,R(11)+4,vf3_aim_u32(a,f+24));
    vf3_aim_set_u32(a,R(11)+8,vf3_aim_u32(a,f+16));result=R(14);
done:
    R(0)=result;for(int i=0;i<4;++i)R(14-i)=saved[i];F(15)=f15;R(15)=sp;a->pr=pr;
}

/* Mirrored-Z version at 0x8c06911c; its normal is read from the shape. */
void vf3_native_terrain_probe_flip(vf3_native_aim *a)
{
    uint32_t sp=R(15),pr=a->pr,f=sp-52,saved[4]={R(14),R(13),R(12),R(11)},result;
    uint32_t out=R(4);
    for(int i=0;i<4;++i)vf3_aim_set_u32(a,sp-4u*(i+1),saved[i]);
    vf3_aim_set_u32(a,sp-20,pr);R(13)=out;R(12)=15u&vf3_aim_u8(a,0x0c29b880u);R(15)=f;
    wr(a,f,F(4));F(5)=vf3_aim_fbits(vf3_aim_ubits(F(5))^0x80000000u);wr(a,f+4,F(5));
    R(4)=R(12);R(5)=f;R(6)=f+4;a->pr=0x0c069146u;vf3_native_terrain_wrap(a);R(15)=f;
    uint32_t grid=vf3_aim_u32(a,0x0c29beb4u);
    if(!grid){
        R(0)=4;R(4)=R(13);F(5)=rd(a,f+4);F(4)=rd(a,f);
        a->pr=0x0c06915au;vf3_native_terrain_flat(a);R(15)=f;result=0;goto done;
    }
    float x=rd(a,f),z=rd(a,f+4);int found=0;
    if(!(14.0f>x && 14.0f>z && x>-14.0f && z>-14.0f))R(14)=1;
    else{
        wr(a,f+24,x);wr(a,f+20,z);F(5)=16;F(3)=x;F(5)=add(a,F(5),F(3));
        F(4)=16;F(2)=z;F(4)=add(a,F(4),F(2));wr(a,f+28,F(4));
        uint32_t cell=((uint32_t)(int32_t)F(5)&31u)|(((uint32_t)(int32_t)F(4)&31u)<<5);
        uint32_t list=vf3_aim_u32(a,grid+4*cell);
        if(list==0xffffffffu)R(14)=2;
        else{
            R(11)=0x0c113a0cu;R(14)=list+vf3_aim_u32(a,R(11));
            for(;;){
                if(vf3_aim_u32(a,R(14))==0xffffffffu){R(14)=2;break;}
                F(5)=rd(a,f+20);F(4)=rd(a,f+24);R(4)=R(14);a->pr=0x0c0691eau;
                vf3_native_quad_node(a);R(15)=f;
                if(R(0)){
                    uint32_t rec=vf3_aim_u32(a,R(14)+4)+vf3_aim_u32(a,R(11));
                    F(4)=rd(a,rec+20);F(5)=rd(a,rec+24);F(6)=rd(a,rec+28);R(4)=vf3_aim_u32(a,rec);
                    wr(a,f+12,F(4));wr(a,f+16,F(5));wr(a,f+8,F(6));R(14)=(R(4)<<1)&0x1fffcu;found=1;break;
                }
                R(14)+=8;
            }
        }
    }
    if(!found){wr(a,f+16,1);wr(a,f+8,0);wr(a,f+12,0);}
    if(R(12)==13)R(14)|=4;
    else if(R(12)==11){
        uint32_t spc=f-8;vf3_aim_set_u32(a,f-4,f+8);vf3_aim_set_u32(a,spc,f+16);
        R(15)=spc;R(5)=spc+36;R(6)=spc+28;R(7)=spc+20;R(4)=spc+32;
        a->pr=0x0c06927eu;vf3_native_terrain_ext(a);R(15)=f;
    }
    vf3_aim_set_u32(a,R(13),vf3_aim_u32(a,f+12));
    vf3_aim_set_u32(a,R(13)+4,vf3_aim_u32(a,f+16));
    vf3_aim_set_u32(a,R(13)+8,vf3_aim_u32(a,f+8));result=R(14);
done:
    R(0)=result;for(int i=0;i<4;++i)R(14-i)=saved[i];R(15)=sp;a->pr=pr;
}
