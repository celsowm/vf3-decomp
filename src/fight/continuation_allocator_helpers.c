/* Original allocator descriptor selection and doubly linked list removal.
 * Records contain flags at +0, previous/next at +4/+8 and use a 24-byte
 * pool stride. Preserve original rereads for aliased heads and records. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
static void set_t(vf3_matrix_state *s,int value)
{ R(17)=(R(17)&~1u)|(value!=0); }
static uint32_t word(const vf3_ram_map *ram,uint32_t address)
{ return (uint32_t)(int32_t)(int16_t)vf3_matrix_read(ram,address,2); }
static int step(vf3_matrix_state *s,uint32_t pc)
{ if(!s->budget) { s->failed_pc=pc; return 0; } --s->budget; return 1; }

int vf3_continuation_allocator_helpers(uint32_t entry,vf3_matrix_state *s,const vf3_ram_map *ram)
{
    entry&=0x1fffffffu;
    if(entry==0x0c062490) {
        R(5)=vf3_matrix_read(ram,0x0c062590,4); R(7)=0;
        R(0)=word(ram,0x0c06258a); R(4)=R(6)=R(5); R(5)=1;
        do {
            if(!step(s,0x0c06249c)) return 0;
            R(3)=word(ram,R(6))&65535u; set_t(s,(R(3)&R(5))==0);
            if(R(17)&1u) {
                vf3_matrix_write(ram,R(4),R(5),2); R(0)=R(4);
                s->pc=R(16); return ram->oob==0;
            }
            ++R(7); R(4)+=24; set_t(s,(int32_t)R(7)>=(int32_t)R(0)); R(6)+=24;
        } while(!(R(17)&1u));
        R(0)=0;
    } else if(entry==0x0c0624ba) {
        R(7)=0; R(5)=vf3_matrix_read(ram,0x0c062590,4);
        R(15)-=4; vf3_matrix_write(ram,R(15),R(13),4);
        R(13)=vf3_matrix_read(ram,0x0c062594,4); R(6)=R(5);
        R(1)=word(ram,0x0c06258a); R(15)-=4; vf3_matrix_write(ram,R(15),R(5),4);
        do {
            if(!step(s,0x0c0624ca)) return 0;
            set_t(s,R(6)==R(4)); ++R(7);
            if(R(17)&1u) {
                R(2)=word(ram,R(5))&R(13); vf3_matrix_write(ram,R(5),R(2),2);
            }
            R(5)+=24; set_t(s,(int32_t)R(7)>=(int32_t)R(1)); R(6)+=24;
        } while(!(R(17)&1u));
        R(15)+=4; R(13)=vf3_matrix_read(ram,R(15),4); R(15)+=4;
    } else if(entry==0x0c062524) {
        if(!step(s,entry)) return 0;
        R(15)-=8; R(7)=vf3_matrix_read(ram,R(6)+4,4);
        vf3_matrix_write(ram,R(15),R(7),4); set_t(s,R(7)==0);
        R(3)=vf3_matrix_read(ram,R(6)+8,4); vf3_matrix_write(ram,R(15)+4,R(3),4);
        if(R(17)&1u) {
            R(1)=vf3_matrix_read(ram,R(6)+8,4); vf3_matrix_write(ram,R(4),R(1),4);
        } else {
            R(2)=vf3_matrix_read(ram,R(15),4); R(3)=vf3_matrix_read(ram,R(6)+8,4);
            vf3_matrix_write(ram,R(2)+8,R(3),4);
        }
        R(2)=vf3_matrix_read(ram,R(6)+8,4); set_t(s,R(2)==0);
        if(R(17)&1u) {
            R(2)=vf3_matrix_read(ram,R(6)+4,4); vf3_matrix_write(ram,R(5),R(2),4);
        } else {
            R(1)=vf3_matrix_read(ram,R(15)+4,4); R(3)=vf3_matrix_read(ram,R(6)+4,4);
            vf3_matrix_write(ram,R(1)+4,R(3),4);
        }
        R(15)+=8;
    } else { s->failed_pc=entry; return 0; }
    s->pc=R(16); return ram->oob==0;
}
