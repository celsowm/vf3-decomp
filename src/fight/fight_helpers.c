/* Shared angle and mesh-cell algorithms, with explicit guest ABI residues.
 * Tables and linked records are read from the captured RAM map. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <string.h>
#define R(n) s->v[n]
#define FR(n) s->v[21+(n)]
#define FPSCR s->v[18]
#define FPUL s->v[53]
#define rd vf3_matrix_read
#define wr vf3_matrix_write
static float value(uint32_t u) { float f; memcpy(&f,&u,4); return f; }
static void flag(vf3_matrix_state *s,int v) { R(17)=(R(17)&~1u)|(v!=0); }
static uint32_t literal(const vf3_ram_map *ram,uint32_t pc) { return rd(ram,pc,4); }
static void push(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t v) { R(15)-=4; wr(ram,R(15),v,4); }
static uint32_t pop(vf3_matrix_state*s,const vf3_ram_map*ram) { uint32_t v=rd(ram,R(15),4); R(15)+=4; return v; }
static void load(vf3_matrix_state*s,const vf3_ram_map*ram,unsigned n,uint32_t addr) { vf3_matrix_load(s,ram,n,addr); }
static void store(vf3_matrix_state*s,const vf3_ram_map*ram,unsigned n,uint32_t addr) { vf3_matrix_store(s,ram,n,addr); }
static int call(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t target,uint32_t continuation) {
    R(16)=continuation;
    return vf3_matrix_family(target,s,ram) && (s->pc&0x1fffffffu)==continuation;
}

int vf3_fight_angle(vf3_matrix_state*s,const vf3_ram_map*ram) {
    if(FPSCR&0x100000u) return 0;
    FR(3)=0; flag(s,value(FR(5))==0);
    if(R(17)&1u) {
        flag(s,value(FR(4))==0);
        if(R(17)&1u) { R(0)=0; s->pc=R(16); return ram->oob==0; }
    }
    /* Scale the smaller absolute component, then use the game's atan ramp. */
    FR(3)=0; flag(s,0>value(FR(5))); FR(3)=0;
    FR(6)=FR(5); if(R(17)&1u) FR(6)^=0x80000000u;
    flag(s,0>value(FR(4))); FR(7)=FR(4); if(R(17)&1u) FR(7)^=0x80000000u;
    flag(s,value(FR(6))>value(FR(7)));
    FR(8)=vf3_fpu_binary((R(17)&1u)?FR(7):FR(6),(R(17)&1u)?FR(6):FR(7),FPSCR,'/');
    R(0)=0x0c0696a4u; FR(2)=FR(8); FR(3)=rd(ram,R(0),4);
    R(0)=literal(ram,0x0c0696a8u);
    FR(2)=vf3_fpu_binary(FR(2),FR(3),FPSCR,'*'); FPUL=vf3_fpu_ftrc(FR(2));
    R(4)=FPUL; flag(s,R(4)>>31); R(4)<<=1;
    flag(s,value(FR(7))>value(FR(6)));
    R(4)=(uint32_t)(int32_t)(int16_t)rd(ram,R(0)+R(4),2);
    if(R(17)&1u) { R(2)=0x4000; R(2)-=R(4); R(4)=R(2); }
    /* Reflect the first-quadrant angle into the original signed quadrants. */
    FR(3)=0; flag(s,0>value(FR(5)));
    if(R(17)&1u) {
        flag(s,0>value(FR(4)));
        if(R(17)&1u) { R(1)=0xffff8000u; R(4)+=R(1); }
        else { R(2)=0x8000; R(2)-=R(4); R(4)=R(2); }
    } else {
        FR(3)=0; flag(s,0>value(FR(4))); if(R(17)&1u) R(4)=0u-R(4);
    }
    R(0)=R(4); s->pc=R(16); return ram->oob==0;
}

int vf3_fight_mesh(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
    if(FPSCR&0x100000u) return 0;
    if((entry&0x1fffffffu)==0x0c06911cu) {
        push(s,ram,R(14)); R(0)=4; push(s,ram,R(13)); R(13)=R(4);
        push(s,ram,R(12)); R(12)=15; push(s,ram,R(11));
    }
    push(s,ram,R(16)); R(15)-=32; R(6)=R(15)+4; R(5)=R(15);
    store(s,ram,4,R(15)); FR(5)^=0x80000000u; store(s,ram,5,R(15)+R(0));
    R(3)=literal(ram,0x0c069220u); R(0)=rd(ram,R(3),1); R(12)&=R(0); R(4)=R(12);
    if(!call(s,ram,0x0c068d54u,0x0c069146u)) return 0;
    R(0)=0x1f0; R(5)=literal(ram,0x0c069224u); R(3)=rd(ram,R(5)+R(0),4); flag(s,R(3)==0);
    if(R(17)&1u) {
        R(0)=4; R(4)=R(13); load(s,ram,5,R(15)+R(0)); load(s,ram,4,R(15));
        if(!call(s,ram,0x0c068de4u,0x0c06915au)) return 0;
        R(0)=0;
    } else {
        int inside=0;
        R(0)=0x0c069228u; load(s,ram,3,R(15)); load(s,ram,4,R(0)); flag(s,value(FR(4))>value(FR(3)));
        if(R(17)&1u) {
            R(0)=4; load(s,ram,2,R(15)+R(0)); flag(s,value(FR(4))>value(FR(2)));
            if(R(17)&1u) {
                R(0)=0x0c06922cu; load(s,ram,1,R(0)); flag(s,value(FR(3))>value(FR(1)));
                if(R(17)&1u) {
                    R(0)=0x0c06922cu; load(s,ram,3,R(0)); flag(s,value(FR(2))>value(FR(3)));
                    inside=(R(17)&1u)!=0;
                }
            }
        }
        R(14)=1;
        int found=0;
        if(inside) {
            /* A 32x32 periodic grid maps the two coordinates to record offsets. */
            R(0)=0x0c069230u; load(s,ram,3,R(15)); load(s,ram,4,R(0));
            R(0)=24; store(s,ram,3,R(15)+R(0)); R(0)=4; load(s,ram,3,R(15)+R(0));
            R(0)=20; R(7)=31; store(s,ram,3,R(15)+R(0)); R(0)=24; load(s,ram,3,R(15)+R(0));
            R(0)=20; FR(5)=FR(4); FR(5)=vf3_fpu_binary(FR(5),FR(3),FPSCR,'+');
            load(s,ram,2,R(15)+R(0)); R(0)=28; FR(4)=vf3_fpu_binary(FR(4),FR(2),FPSCR,'+');
            FPUL=vf3_fpu_ftrc(FR(5)); store(s,ram,4,R(15)+R(0)); FR(1)=FR(4); R(4)=FPUL;
            FPUL=vf3_fpu_ftrc(FR(1)); R(0)=0x1f0; R(4)&=R(7); R(6)=FPUL; R(6)&=R(7); R(6)<<=4;
            flag(s,R(6)>>31); R(6)<<=1; R(4)|=R(6); R(4)<<=2;
            R(3)=rd(ram,R(5)+R(0),4); R(4)+=R(3); R(4)=rd(ram,R(4),4); R(0)=R(4); flag(s,R(0)==0xffffffffu);
            R(14)=2;
            if(!(R(17)&1u)) {
                R(11)=literal(ram,0x0c069234u); R(3)=rd(ram,R(11),4); R(4)+=R(3); R(14)=R(4);
                /* Walk actual records until the classifier accepts one or a sentinel ends the cell. */
                for(;;) {
                    if(!s->budget--) { s->failed_pc=0x0c0691d8u; return 0; }
                    R(0)=rd(ram,R(14),4); flag(s,R(0)==0xffffffffu);
                    if(R(17)&1u) { R(14)=2; break; }
                    R(0)=20; load(s,ram,5,R(15)+R(0)); R(0)=24; load(s,ram,4,R(15)+R(0)); R(4)=R(14);
                    if(!call(s,ram,0x0c068fe4u,0x0c0691eau)) return 0;
                    R(4)=R(0); flag(s,R(4)==0);
                    if(R(17)&1u) { R(14)+=8; continue; }
                    R(3)=rd(ram,R(11),4); R(0)=20; R(4)=rd(ram,R(14)+4,4); R(5)=literal(ram,0x0c069238u); R(4)+=R(3);
                    load(s,ram,4,R(4)+R(0)); R(0)=24; load(s,ram,5,R(4)+R(0)); R(0)=28; load(s,ram,6,R(4)+R(0));
                    R(0)=12; R(4)=rd(ram,R(4),4); store(s,ram,4,R(15)+R(0)); R(0)=16;
                    flag(s,R(4)>>31); R(4)<<=1; store(s,ram,5,R(15)+R(0)); R(4)&=R(5); R(0)=8; R(14)=R(4);
                    store(s,ram,6,R(15)+R(0)); found=1; break;
                }
            }
        }
        if(!found) {
            R(0)=16; FR(3)=0x3f800000u; store(s,ram,3,R(15)+R(0));
            R(0)=8; FR(3)=0; store(s,ram,3,R(15)+R(0)); R(0)=12; store(s,ram,3,R(15)+R(0));
        }
        R(0)=R(12); flag(s,R(0)==13);
        if(R(17)&1u) { R(2)=4; R(14)|=R(2); }
        else {
            flag(s,R(0)==11);
            if(R(17)&1u) {
                R(3)=R(15)+8; push(s,ram,R(3)); R(2)=R(15)+20; push(s,ram,R(2));
                R(5)=R(15)+36; R(3)=literal(ram,0x0c069380u); R(6)=R(15)+28; R(7)=R(15)+20; R(4)=R(15)+32;
                if(!call(s,ram,R(3),0x0c06927eu)) return 0; R(15)+=8;
            }
        }
        R(0)=12; load(s,ram,3,R(15)+R(0)); store(s,ram,3,R(13)); R(0)=16;
        load(s,ram,3,R(15)+R(0)); R(0)=4; store(s,ram,3,R(13)+R(0)); R(0)=8;
        load(s,ram,3,R(15)+R(0)); R(0)=8; store(s,ram,3,R(13)+R(0)); R(0)=R(14);
    }
    R(15)+=32; R(16)=pop(s,ram); R(11)=pop(s,ram); R(12)=pop(s,ram); R(13)=pop(s,ram); R(14)=pop(s,ram);
    s->pc=R(16); return ram->oob==0;
}
