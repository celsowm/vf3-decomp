/* Compare the current state record with its saved copy, update its change
 * counter/checksum, and preserve the original copy and notification calls. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t value)
{ R(15)-=4; vf3_matrix_write(ram,R(15),value,4); }
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram)
{ uint32_t value=vf3_matrix_read(ram,R(15),4); R(15)+=4; return value; }
static int call(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t target,uint32_t continuation)
{ R(16)=continuation; return vf3_matrix_family(target,s,ram) && s->pc==continuation; }

static void set_t(vf3_matrix_state *s,int value)
{ R(17)=(R(17)&~1u)|(value!=0); }

/* The comparison returns the unsigned-byte difference at the first mismatch.
 * Preserve both postincremented cursors and the original final byte rereads. */
static int compare_record(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    set_t(s,R(6)==0); R(7)=R(5);
    if(R(6)==0) {
        R(0)=0; s->pc=R(16); return ram->oob==0;
    }
    R(5)=0; R(2)=0; set_t(s,R(2)>=R(6));
    do {
        if(!s->budget) { s->failed_pc=0x0c042ff0; return 0; }
        --s->budget;
        R(3)=(uint32_t)(int32_t)(int8_t)vf3_matrix_read(ram,R(4)++,1);
        R(2)=(uint32_t)(int32_t)(int8_t)vf3_matrix_read(ram,R(7)++,1);
        set_t(s,R(3)==R(2));
        if(!(R(17)&1u)) break;
        ++R(5); set_t(s,R(5)>=R(6));
    } while(!(R(17)&1u));
    R(0)=vf3_matrix_read(ram,R(4)-1,1);
    --R(7); R(3)=vf3_matrix_read(ram,R(7),1);
    R(0)-=R(3); s->pc=R(16);
    return ram->oob==0;
}

/* Table-driven 16-bit checksum. The table has a four-byte stride even though
 * the original reads only a word. A zero length wraps the original countdown;
 * the replay budget bounds that case instead of inventing an early return. */
static int checksum_record(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    R(6)=0; R(15)-=4;
    do {
        if(!s->budget) { s->failed_pc=0x0c076b40; return 0; }
        --s->budget;
        R(3)=vf3_matrix_read(ram,R(4)++,1);
        R(7)=((R(6)>>8)^R(3))&255u;
        vf3_matrix_write(ram,R(15),R(3),4);
        R(0)=vf3_matrix_read(ram,0x0c076b68,4);
        R(7)<<=2;
        R(2)=(uint32_t)(int32_t)(int16_t)vf3_matrix_read(ram,R(0)+R(7),2);
        --R(5); set_t(s,R(5)==0);
        R(6)<<=8; R(7)=R(2)&65535u; R(6)^=R(7);
    } while(!(R(17)&1u));
    R(0)=R(6)&65535u; R(15)+=4; s->pc=R(16);
    return ram->oob==0;
}

int vf3_advance_state_helpers(uint32_t entry,vf3_matrix_state *s,const vf3_ram_map *ram)
{
    if((entry&0x1fffffffu)==0x0c042fdc) return compare_record(s,ram);
    if((entry&0x1fffffffu)==0x0c076b3c) return checksum_record(s,ram);
    if((entry&0x1fffffffu)!=0x0c076aa8) { s->failed_pc=entry; return 0; }
    push(s,ram,R(16)); R(14)=0x0c11e418; R(3)=0x0c042fdc;
    R(5)+=R(14); R(4)+=R(14); R(6)=64;
    if(!call(s,ram,R(3),0x0c076ab6)) return 0;
    R(17)=(R(17)&~1u)|(R(0)==0);
    if(!(R(17)&1)) {
        R(4)=0x1070+R(14); R(5)=vf3_matrix_read(ram,R(4)+60,4)+1;
        vf3_matrix_write(ram,R(4)+60,R(5),4);
        R(4)+=10; R(5)=50;
        if(!call(s,ram,0x0c076b3c,0x0c076aca)) return 0;
        R(5)=0x1070+R(14); R(4)=0x10b0;
        vf3_matrix_write(ram,R(5)+8,R(0),2); R(4)+=R(14);
        R(3)=0x0c09564e; R(6)=64;
        if(!call(s,ram,R(3),0x0c076ada)) return 0;
        R(2)=0x0c0c9c18;
        if(!call(s,ram,R(2),0x0c076ae0)) return 0;
    }
    R(16)=pop(s,ram); R(14)=pop(s,ram); s->pc=R(16);
    return ram->oob==0;
}
