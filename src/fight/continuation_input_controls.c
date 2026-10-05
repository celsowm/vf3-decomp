/* Pack five two-bit control statuses while retaining the original stack ABI,
 * scene overrides and optional all-active notification flag. Field meanings
 * beyond these observed statuses are still under investigation. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
static void set_t(vf3_matrix_state *s,int value)
{ R(17)=(R(17)&~1u)|(value!=0); }
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t value)
{ R(15)-=4; vf3_matrix_write(ram,R(15),value,4); }
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram)
{ uint32_t value=vf3_matrix_read(ram,R(15),4); R(15)+=4; return value; }
static uint32_t literal(const vf3_ram_map *ram,uint32_t address)
{ return vf3_matrix_read(ram,address,4); }

int vf3_continuation_input_controls(uint32_t entry,vf3_matrix_state *s,const vf3_ram_map *ram)
{
    entry&=0x1fffffffu;
    if(entry!=0x0c05d2d0 && entry!=0x0c05d2dc) { s->failed_pc=entry; return 0; }
    if(!s->budget) { s->failed_pc=entry; return 0; }
    --s->budget;
    if(entry==0x0c05d2d0) {
        for(int reg=14;reg>=9;--reg) push(s,ram,R(reg));
    }
    push(s,ram,R(16)); R(15)-=16;
    /* Preserve the original local copy, even though later decisions do not
     * read it: its scratch writes and callee register updates are observable. */
    R(2)=literal(ram,0x0c05d3fc); R(1)=R(15);
    R(3)=literal(ram,0x0c05d400); R(0)=16; R(16)=0x0c05d2ea;
    if(!vf3_matrix_family(R(3),s,ram) || s->pc!=0x0c05d2ea) return 0;
    R(1)=literal(ram,0x0c05d404);
    R(9)=vf3_matrix_read(ram,R(1),4)&255u;
    R(12)=R(10)=R(13)=R(11)=R(14)=0;
    set_t(s,R(5)==0); if(!(R(17)&1u)) R(11)=1;
    set_t(s,R(7)==0); if(!(R(17)&1u)) R(10)=1;
    R(3)=vf3_matrix_read(ram,R(15)+44,4);
    set_t(s,R(3)==0); if(!(R(17)&1u)) R(12)=2;
    R(0)=vf3_matrix_read(ram,R(15)+48,4);
    set_t(s,R(0)==1);
    if(R(17)&1u) {
        set_t(s,R(4)==0); if(!(R(17)&1u)) R(14)=2;
        set_t(s,R(6)==0); if(!(R(17)&1u)) R(13)=2;
    } else {
        set_t(s,R(4)==0); if(!(R(17)&1u)) R(14)=3;
        set_t(s,R(6)==0); if(!(R(17)&1u)) R(13)=3;
        set_t(s,R(4)==0);
        if(!(R(17)&1u)) {
            set_t(s,R(6)==0);
            if(!(R(17)&1u)) {
                set_t(s,R(4)>=R(6));
                if(R(17)&1u) R(13)=2;
                else R(14)=2;
            }
        }
    }
    R(2)=literal(ram,0x0c05d3f0);
    R(0)=vf3_matrix_read(ram,R(2),4); set_t(s,R(0)==1);
    if(R(17)&1u) {
        R(1)=literal(ram,0x0c05d3f4);
        R(0)=vf3_matrix_read(ram,R(1),4); set_t(s,R(0)==32);
        if(R(17)&1u) R(14)=3;
        R(2)=literal(ram,0x0c05d3f4);
        R(0)=vf3_matrix_read(ram,R(2),4); set_t(s,R(0)==33);
        if(R(17)&1u) R(11)=2;
        R(2)=literal(ram,0x0c05d3f4);
        R(0)=vf3_matrix_read(ram,R(2),4); set_t(s,R(0)==34);
        if(R(17)&1u) R(13)=3;
        R(2)=literal(ram,0x0c05d3f4);
        R(0)=vf3_matrix_read(ram,R(2),4); set_t(s,R(0)==35);
        if(R(17)&1u) R(10)=2;
        R(2)=literal(ram,0x0c05d3f4);
        R(0)=vf3_matrix_read(ram,R(2),4); set_t(s,R(0)==36);
        if(R(17)&1u) R(12)=3;
    }
    /* Five status fields occupy bits 17..26, followed by the valid bit. */
    R(14)<<=16; R(2)=literal(ram,0x0c05d408); R(3)=R(11);
    R(1)=literal(ram,0x0c05d40c);
    set_t(s,R(14)>>31); R(14)<<=1; R(14)&=R(2);
    R(3)<<=18; set_t(s,R(3)>>31); R(3)<<=1; R(3)&=R(1); R(14)|=R(3);
    R(3)=21; R(0)=R(13)<<21; R(2)=literal(ram,0x0c05d410);
    R(3)=23; R(0)&=R(2); R(14)|=R(0);
    R(0)=literal(ram,0x0c05d414); R(10)<<=23; R(2)<<=2;
    R(10)&=R(2); R(14)|=R(10); R(3)=R(12)<<24;
    set_t(s,R(3)>>31); R(3)<<=1; R(3)&=R(0); R(14)|=R(3);
    R(3)=literal(ram,0x0c05d418); R(2)=literal(ram,0x0c05d41c);
    R(14)|=R(3); R(0)=vf3_matrix_read(ram,R(2),4);
    set_t(s,(R(0)&32u)==0); R(9)|=R(14);
    if(!(R(17)&1u)) {
        /* Preserve short-circuit tests and their final T bit. */
        set_t(s,R(11)==0);
        if(!(R(17)&1u)) {
            set_t(s,R(13)==0);
            if(!(R(17)&1u)) set_t(s,R(12)==0);
        }
        R(3)=(R(17)&1u)?0:1;
        R(2)=literal(ram,0x0c05d420); vf3_matrix_write(ram,R(2),R(3),4);
    }
    R(0)=R(9); R(15)+=16; R(16)=pop(s,ram);
    for(unsigned reg=9;reg<=14;++reg) R(reg)=pop(s,ram);
    s->pc=R(16); return ram->oob==0;
}
