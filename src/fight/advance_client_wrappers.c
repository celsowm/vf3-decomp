/* Validated resource-client operations and a state-record copy. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
#define read(a,z) vf3_matrix_read(ram,(a),(z))
#define write(a,v,z) vf3_matrix_write(ram,(a),(v),(z))
static void condition(vf3_matrix_state *s,int value)
{ R(17)=(R(17)&~1u)|(value!=0); }
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t value)
{ R(15)-=4; write(R(15),value,4); }
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram)
{ uint32_t value=read(R(15),4); R(15)+=4; return value; }
static int call(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t target,uint32_t continuation)
{ R(16)=continuation; return vf3_matrix_family(target,s,ram) && s->pc==continuation; }
int vf3_advance_client_wrappers(uint32_t entry,vf3_matrix_state *s,const vf3_ram_map *ram)
{
    uint32_t operation=0;
    entry&=0x1fffffffu;
    switch(entry) {
    case 0x0c045e4e: /* Forward three fields to real command 14, mode 1. */
        push(s,ram,R(16)); R(15)-=12;
        write(R(15)+4,R(6),4); write(R(15)+8,R(7),4);
        R(7)=1; write(R(15),R(5),4);
        R(3)=read(R(15)+8,4); push(s,ram,R(3));
        R(2)=read(R(15)+8,4); push(s,ram,R(2));
        R(6)=R(15)+8; R(3)=0x0c044cc0; R(5)=14;
        if(!call(s,ram,R(3),0x0c045e6c)) return 0;
        R(15)+=20; R(16)=pop(s,ram); s->pc=R(16); return ram->oob==0;
    case 0x0c0801de: /* Prepare the resource, then tail-call its operation. */
        push(s,ram,R(16)); R(15)-=8;
        write(R(15),R(4),4); write(R(15)+4,R(5),4);
        if(!call(s,ram,0x0c08019e,0x0c0801e8)) return 0;
        R(3)=0x0c07ba28; R(4)=read(R(15),4); R(5)=read(R(15)+4,4);
        R(15)+=8; R(16)=pop(s,ram); return vf3_matrix_family(R(3),s,ram);

    case 0x0c04ff62: /* Address a 32-byte slot in a validated client record. */
        R(3)=0x148; R(0)=R(5); push(s,ram,R(19));
        R(19)=(uint32_t)((int32_t)(int16_t)R(3)*(int32_t)(int16_t)R(4));
        R(2)=0x0c1b34d8; R(0)<<=2; R(0)<<=2;
        condition(s,R(0)>>31); R(0)<<=1;
        R(4)=R(19); R(4)=(uint32_t)(int32_t)(int16_t)R(4); R(4)+=R(2);
        R(1)=read(R(4)+40,4); R(0)+=R(1); R(19)=pop(s,ram);
        s->pc=R(16); return ram->oob==0;
    case 0x0c04667a: operation=0x0c04d50c; break;
    case 0x0c0466a8: operation=0x0c04d62c; break;
    case 0x0c046730: operation=0x0c04e4e0; break;
    case 0x0c04675e: operation=0x0c04e600; break;
    case 0x0c04678c: operation=0x0c04ef8c; break;
    case 0x0c046b08:
        push(s,ram,R(16)); R(3)=0x0c04c47c; R(15)-=4; write(R(15),R(4),4);
        if(!call(s,ram,R(3),0x0c046b12)) return 0;
        condition(s,R(0)==0);
        if(!(R(17)&1)) { R(15)+=4; R(16)=pop(s,ram); R(0)=0xffffffffu; }
        else {
            R(0)=read(R(15),4); R(1)=0x0c1b20a0; R(0)<<=2;
            R(0)=read(R(1)+R(0),4); R(15)+=4; R(16)=pop(s,ram);
        }
        s->pc=R(16); return ram->oob==0;
    case 0x0c076aec:
        push(s,ram,R(16)); R(4)+=R(14); R(5)=0x0c10ba5c;
        R(3)=read(R(4)+60,4); R(15)-=4; write(R(15),R(3),4);
        R(3)=0x0c09564e; R(6)=64;
        if(!call(s,ram,R(3),0x0c076afe)) return 0;
        R(0)=0x1070; R(2)=(uint32_t)(int32_t)(int8_t)read(R(14)+R(0),1);
        R(0)+=64; R(3)=(uint32_t)(int32_t)(int8_t)read(R(14)+R(0),1);
        condition(s,R(2)==R(3));
        if(R(17)&1) {
            R(4)=0x1070; R(3)=read(R(15),4); R(4)+=R(14); write(R(4)+60,R(3),4);
        }
        R(15)+=4; R(16)=pop(s,ram); R(14)=pop(s,ram); s->pc=R(16); return ram->oob==0;
    case 0x0c0c5f52:
        push(s,ram,R(16)); condition(s,R(1)==0);
        if(!(R(17)&1)) {
            R(1)=0x0c110598; R(3)=read(R(14),4); R(0)=read(R(1),4);
            condition(s,R(0)==R(3));
            if(!(R(17)&1)) {
                R(3)=0x25d; R(1)=4; push(s,ram,R(3));
                R(2)=0x0c0e9f18; push(s,ram,R(2)); push(s,ram,R(1));
                R(2)=0x0c113a0c; R(3)=0xffee0000; R(5)=read(R(2),4);
                R(2)=0x0c0a81ee; R(7)=0x0c0c6564; R(5)+=R(3);
                R(6)=0x0c2d0174; R(4)=read(R(14),4);
                if(!call(s,ram,R(2),0x0c0c5f80)) return 0;
                R(2)=read(R(14),4); R(15)+=12; R(3)=0x0c110598; write(R(3),R(2),4);
            }
        }
        R(16)=pop(s,ram); R(14)=pop(s,ram); s->pc=R(16); return ram->oob==0;
    default: s->failed_pc=entry; return 0;
    }
    push(s,ram,R(16)); R(15)-=8; write(R(15),R(4),4); write(R(15)+4,R(5),4);
    R(3)=0x0c04c47c; R(4)=read(R(15),4);
    if(!call(s,ram,R(3),entry+14)) return 0;
    condition(s,R(0)==0);
    if(!(R(17)&1)) {
        R(15)+=8; R(16)=pop(s,ram); R(0)=0xffffffffu; s->pc=R(16); return ram->oob==0;
    }
    R(3)=operation; R(4)=read(R(15),4); R(5)=read(R(15)+4,4);
    R(15)+=8; R(16)=pop(s,ram); return vf3_matrix_family(R(3),s,ram);
}
