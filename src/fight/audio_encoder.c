/* General A0 command encoder, callable 0x8c040b7c.
 * Native differential model: preserves the caller-visible scratch registers,
 * stack bytes, queue accesses and cached/physical return-address alias.
 * Live device scheduling is not yet accepted for this entry. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
extern int vf3_audio_queue_at_c(vf3_matrix_state*,const vf3_ram_map*,uint32_t);
static void condition(vf3_matrix_state *s,int value)
{ R(17)=(R(17)&~1u)|(value!=0); }
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t value)
{ R(15)-=4; vf3_matrix_write(ram,R(15),value,4); }
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram)
{ uint32_t value=vf3_matrix_read(ram,R(15),4); R(15)+=4; return value; }

int vf3_audio_encoder_c(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t alias,int save_r14)
{
    static const uint16_t parameter_commands[]={
        0x01a0,0x04a0,0x05a0,0x06a0,0x07a0,0x09a0,0x0aa0,0x10a0,0x11a0
    };
    /* The historical fragment begins after the r14 save. Its caller's
     * stack already contains that word; both entries share the epilogue. */
    if (save_r14) push(s,ram,R(14));
    push(s,ram,R(16)); R(15)-=16;
    R(3)=R(15)+14;
    vf3_matrix_write(ram,R(3),R(4),2);
    vf3_matrix_write(ram,R(15)+8,R(5),4);
    vf3_matrix_write(ram,R(15)+4,R(6),4);
    R(0)=vf3_matrix_read(ram,R(15)+14,2)&65535u;
    R(14)=(R(0)&15u)<<24;
    R(3)=vf3_matrix_read(ram,R(15)+8,4); R(14)+=R(3);
    R(2)=0xff00; condition(s,(R(3)&R(2))==0);
    if (!(R(17)&1u)) {
        R(0)=vf3_matrix_read(ram,R(15)+8,4);
        for (unsigned i=0;i<sizeof(parameter_commands)/sizeof(*parameter_commands);++i) {
            R(1)=parameter_commands[i]; condition(s,R(0)==R(1));
            if (R(17)&1u) {
                R(0)=vf3_matrix_read(ram,R(15)+4,4);
                if (i==2 || i==3 || i==4 || i==8) R(0)+=64;
                R(0)=(R(0)&127u)<<16; R(14)+=R(0);
                break;
            }
        }
    }
    R(2)=0x001f00a0; R(3)=vf3_matrix_read(ram,R(15)+8,4);
    condition(s,R(3)==R(2));
    if (R(17)&1u) {
        /* This command visits all seven channels. A disabled table entry
         * suppresses both requests; enqueue failure does not stop the loop. */
        R(3)=1; vf3_matrix_write(ram,R(15),R(3),4);
        for (;;) {
            R(2)=8; R(1)=vf3_matrix_read(ram,R(15),4);
            condition(s,(int32_t)R(1)>=(int32_t)R(2));
            if (R(17)&1u) break;
            R(0)=vf3_matrix_read(ram,R(15),4); R(3)=R(0);
            condition(s,(R(0)&0x80000000u)!=0); R(0)<<=1;
            R(0)+=R(3); R(0)<<=2;
            R(0)=(uint32_t)(int32_t)(int8_t)R(0);
            R(1)=0x0c19e310; R(0)=vf3_matrix_read(ram,R(1)+R(0),4);
            condition(s,R(0)==0xffffffffu);
            if (!(R(17)&1u)) {
                R(4)=vf3_matrix_read(ram,R(15),4)<<24;
                R(3)=0x001100a0; R(4)+=R(3); R(16)=alias+0x040c42;
                if (!vf3_audio_queue_at_c(s,ram,alias)) return 0;
                R(4)=vf3_matrix_read(ram,R(15),4)<<24;
                R(3)=0x04a0; R(4)+=R(3); R(16)=alias+0x040c50;
                if (!vf3_audio_queue_at_c(s,ram,alias)) return 0;
            }
            R(3)=vf3_matrix_read(ram,R(15),4)+1;
            vf3_matrix_write(ram,R(15),R(3),4);
        }
    } else {
        R(4)=R(14); R(16)=alias+0x040c6e;
        if (!vf3_audio_queue_at_c(s,ram,alias)) return 0;
    }
    R(15)+=16; R(16)=pop(s,ram); R(14)=pop(s,ram);
    s->pc=R(16); return ram->oob==0;
}
