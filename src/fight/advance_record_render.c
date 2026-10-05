/* Repeated scene record transforms. Original matrix and draw helpers retain
 * their architectural side effects and memory accesses. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <string.h>
#define R(n) s->v[(n)]
#define FR(n) s->v[21+(n)]
#define load(n,a) vf3_matrix_load(s,ram,(n),(a))
#define store(n,a) vf3_matrix_store(s,ram,(n),(a))
#define move(n,m) vf3_matrix_move(s,(n),(m))
#define read(a,z) vf3_matrix_read(ram,(a),(z))
#define write(a,v,z) vf3_matrix_write(ram,(a),(v),(z))

static void condition(vf3_matrix_state *s, int value)
{ R(17) = (R(17)&~1u) | (value != 0); }
static uint32_t signed_word(const vf3_ram_map *ram, uint32_t address)
{ return (uint32_t)(int32_t)(int16_t)read(address,2); }
static uint32_t pop(vf3_matrix_state *s, const vf3_ram_map *ram)
{ uint32_t value=read(R(15),4); R(15)+=4; return value; }
static void save_pr(vf3_matrix_state *s, const vf3_ram_map *ram)
{ R(15)-=4; write(R(15),R(16),4); }
static void restore(vf3_matrix_state *s,const vf3_ram_map *ram,
                    unsigned first_float,unsigned first_gpr)
{
    for(unsigned reg=first_float;reg<16;++reg) {
        load(reg,R(15)); R(15)+=(R(18)&0x100000u)?8:4;
    }
    for(unsigned reg=first_gpr;reg<15;++reg) R(reg)=pop(s,ram);
}
static int call(vf3_matrix_state *s,const vf3_ram_map *ram,
                uint32_t target,uint32_t continuation)
{ R(16)=continuation; return vf3_matrix_family(target,s,ram) && s->pc==continuation; }
static int greater(uint32_t left,uint32_t right)
{ float a,b; memcpy(&a,&left,4); memcpy(&b,&right,4); return a>b; }
static void multiply(vf3_matrix_state *s,unsigned n,unsigned m)
{ FR(n)=vf3_fpu_binary(FR(n),FR(m),R(18),'*'); }

int vf3_advance_record_render(uint32_t entry,vf3_matrix_state *s,
                             const vf3_ram_map *ram)
{
    switch(entry&0x1fffffffu) {
    case 0x0c08559a: /* Draw thirteen optional records for selected scenes. */
        save_pr(s,ram);
        R(4)=(uint32_t)(int32_t)(int8_t)read(R(3),1);
        R(0)=R(4)&255; condition(s,R(0)==9); R(4)=R(0);
        if(!(R(17)&1)) {
            R(0)=R(4); condition(s,R(0)==13);
            if(!(R(17)&1)) { R(0)=R(4); condition(s,R(0)==15); }
        }
        if(!(R(17)&1)) {
            R(16)=pop(s,ram); restore(s,ram,12,8); break;
        }
        R(3)=0x0c03c4f0; R(14)=R(5); R(4)=0;
        if(!call(s,ram,R(3),0x0c0855ba)) return 0;
        R(10)=0x0c0a7662; R(12)=13; R(9)=0x0c03ccb0;
        R(8)=0x0c03cc60; FR(15)=0x3f800000;
        do {
            R(0)=signed_word(ram,R(14)+14); R(4)=R(0);
            R(13)=(uint32_t)(int32_t)(int16_t)R(4);
            R(0)=R(13); condition(s,R(0)==0xffffffffu);
            if(!(R(17)&1)) {
                R(0)=4; load(12,R(14)); load(13,R(14)+R(0));
                R(0)=8; load(3,R(14)+R(0));
                R(0)=signed_word(ram,R(14)+18);
                multiply(s,3,15); move(14,3); FR(14)^=0x80000000;
                R(11)=R(0);
                if(!call(s,ram,R(9),0x0c0855e6)) return 0;
                move(5,13); move(6,14); move(4,12);
                if(!call(s,ram,R(8),0x0c0855ee)) return 0;
                R(3)=0x0c03c880; R(4)=R(11);
                if(!call(s,ram,R(3),0x0c0855f4)) return 0;
                R(4)=R(13);
                if(!call(s,ram,R(10),0x0c0855f8)) return 0;
            }
            --R(12); condition(s,R(12)==0); R(14)+=24;
        } while(!(R(17)&1));
        R(16)=pop(s,ram); R(3)=0x0c03c4a0; R(4)=1;
        restore(s,ram,12,8);
        return vf3_matrix_family(R(3),s,ram);

    case 0x0c086372: /* Eight evenly spaced positions inside the X bounds. */
        save_pr(s,ram); R(15)-=12; write(R(15),R(5),2);
        load(15,R(4)+R(0)); R(0)=28; load(3,R(4)+R(0));
        R(0)=8; store(3,R(15)+R(0)); R(0)=32; load(12,R(4)+R(0));
        R(3)=0x0c03c4f0; FR(12)^=0x80000000; R(4)=0;
        if(!call(s,ram,R(3),0x0c08638e)) return 0;
        R(0)=0x0c0863ec; load(3,R(0)); R(0)=4; R(14)=8;
        store(3,R(15)+R(0)); R(0)=0x0c0863f0; load(13,R(0));
        R(0)=0x0c086400; load(14,R(0)); R(13)=0x0c03cc60;
        R(11)=0x0c03ccb0; R(12)=0x0c0a7662;
        do {
            R(0)=4; load(3,R(15)+R(0)); condition(s,greater(FR(15),FR(3)));
            if(!(R(17)&1)) {
                condition(s,greater(FR(13),FR(15)));
                if(!(R(17)&1)) {
                    if(!call(s,ram,R(11),0x0c0863b6)) return 0;
                    R(0)=8; move(6,12); load(5,R(15)+R(0)); move(4,15);
                    if(!call(s,ram,R(13),0x0c0863c0)) return 0;
                    R(4)=signed_word(ram,R(15));
                    if(!call(s,ram,R(12),0x0c0863c4)) return 0;
                }
            }
            --R(14); condition(s,R(14)==0); move(4,14);
            FR(15)=vf3_fpu_binary(FR(15),FR(4),R(18),'+');
        } while(!(R(17)&1));
        R(15)+=12; R(2)=0x0c03c4a0; R(16)=pop(s,ram); R(4)=1;
        restore(s,ram,12,11);
        return vf3_matrix_family(R(2),s,ram);

    case 0x0c087cf2: /* Initialize eight descriptor pairs from the scene table. */
        save_pr(s,ram); R(13)=0x0c0f5f88; R(14)+=R(12);
        R(3)=0x0c03c4f0; R(4)=0;
        if(!call(s,ram,R(3),0x0c087cfe)) return 0;
        R(10)=0x0c03b620; R(9)=8; R(11)=0x0c03ccb0;
        R(8)=0x0c03cc60; FR(15)=0; FR(14)=0x3f800000;
        do {
            if(!call(s,ram,R(11),0x0c087d0e)) return 0;
            R(0)=4; load(4,R(13)); load(5,R(13)+R(0));
            R(0)=8; load(6,R(13)+R(0));
            R(0)=0xa0; store(4,R(14)+R(0)); R(0)+=4; store(5,R(14)+R(0));
            R(0)+=4; store(6,R(14)+R(0));
            if(!call(s,ram,R(8),0x0c087d26)) return 0;
            R(4)=R(14); if(!call(s,ram,R(10),0x0c087d2a)) return 0;
            if(!call(s,ram,R(11),0x0c087d2e)) return 0;
            R(4)=R(14)+64; if(!call(s,ram,R(10),0x0c087d34)) return 0;
            R(0)=12; load(3,R(13)+R(0)); --R(9); condition(s,R(9)==0);
            R(0)=0x98; store(3,R(14)+R(0));
            R(0)=16; load(3,R(13)+R(0)); R(0)=0x9c; store(3,R(14)+R(0));
            R(0)=20; load(3,R(13)+R(0)); R(0)+=124; store(3,R(14)+R(0));
            R(0)=24; load(3,R(13)+R(0)); R(0)+=124; store(3,R(14)+R(0));
            R(1)=0xac; R(0)=signed_word(ram,R(13)+28); R(13)+=32;
            R(1)+=R(14); write(R(1),R(0),2);
            R(0)=0x80; store(14,R(14)+R(0));
            for(unsigned i=0;i<3;++i) { R(0)+=4; store(15,R(14)+R(0)); }
            R(3)=0xb0; R(14)+=R(3);
        } while(!(R(17)&1));
        R(3)=0x0c03c4a0; R(4)=1;
        if(!call(s,ram,R(3),0x0c087d7c)) return 0;
        R(0)=0x0c087df8; load(3,R(0)); R(3)=68; R(0)=0xc0;
        R(2)=0xfffffff6; R(6)=0; store(3,R(12)+R(0));
        R(0)=0x0c087dfc; load(3,R(0)); R(0)=0xc4;
        R(16)=pop(s,ram); store(3,R(12)+R(0));
        R(0)+=4; write(R(12)+R(0),R(3),4);
        R(0)+=4; write(R(12)+R(0),R(2),4);
        R(0)+=4; write(R(12)+R(0),R(6),4);
        R(5)=0x0c29bb84; R(0)=0x2318; R(4)=read(R(5)+16,4); R(5)=read(R(5)+20,4);
        store(15,R(5)+R(0)); store(15,R(4)+R(0)); R(0)-=4;
        store(15,R(5)+R(0)); store(15,R(4)+R(0)); R(0)+=8;
        write(R(5)+R(0),R(6),4); write(R(4)+R(0),R(6),4);
        restore(s,ram,14,8); break;

    case 0x0c089fa8: /* Compose two record transforms and draw their objects. */
        save_pr(s,ram); R(3)=0x0c03c4f0; R(15)-=12; R(4)=0;
        if(!call(s,ram,R(3),0x0c089fb2)) return 0;
        R(13)=0x0c03cc60; R(12)=2; R(9)=0x0c03ccb0;
        R(8)=0x0c03c880; FR(15)=0x3f800000;
        do {
            R(0)=46; load(3,R(14)); R(10)=signed_word(ram,R(14)+R(0));
            R(0)=40; R(11)=signed_word(ram,R(14)+R(0));
            R(0)=8; store(3,R(15)+R(0)); R(0)=4; load(12,R(14)+R(0));
            R(0)=8; load(3,R(14)+R(0)); R(0)=12; multiply(s,3,15);
            move(13,3); load(3,R(14)+R(0)); R(0)=4; FR(13)^=0x80000000;
            store(3,R(15)+R(0)); R(0)=16; load(3,R(14)+R(0));
            R(0)=20; store(3,R(15)); load(3,R(14)+R(0)); multiply(s,3,15);
            move(14,3); FR(14)^=0x80000000;
            if(!call(s,ram,R(9),0x0c089ff2)) return 0;
            load(5,R(15)); R(0)=4; move(6,14); load(4,R(15)+R(0));
            if(!call(s,ram,R(13),0x0c089ffc)) return 0;
            R(4)=R(11); if(!call(s,ram,R(8),0x0c08a000)) return 0;
            R(0)=8; move(5,12); move(6,13); load(4,R(15)+R(0));
            if(!call(s,ram,R(13),0x0c08a00a)) return 0;
            R(3)=0x0c03c6c0; R(0)=52; R(4)=signed_word(ram,R(14)+R(0));
            if(!call(s,ram,R(3),0x0c08a012)) return 0;
            R(3)=0x0c03c940; R(0)=54; R(4)=signed_word(ram,R(14)+R(0));
            if(!call(s,ram,R(3),0x0c08a01a)) return 0;
            R(2)=0x0c0a7662; R(4)=(uint32_t)(int32_t)(int16_t)R(10);
            if(!call(s,ram,R(2),0x0c08a020)) return 0;
            --R(12); condition(s,R(12)==0); R(14)+=60;
        } while(!(R(17)&1));
        R(15)+=12; R(2)=0x0c03c4a0; R(16)=pop(s,ram); R(4)=1;
        restore(s,ram,12,8);
        return vf3_matrix_family(R(2),s,ram);

    default: s->failed_pc=entry; return 0;
    }
    s->pc=R(16); return ram->oob==0;
}
