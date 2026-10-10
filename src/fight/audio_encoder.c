/* General A0 command encoder, callable 0x8c040b7c.
 * Preserves the caller-visible scratch registers,
 * stack bytes, queue accesses and cached/physical return-address alias.
 * Optional research markers charge clock boundaries without executing opcodes. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
#ifdef VF3_AUDIO_BRIDGE
extern void vf3_audio_queue_step(vf3_matrix_state*,uint32_t);
#define STEP(pc) vf3_audio_queue_step(s,alias+(pc))
#else
#define STEP(pc) ((void)0)
#endif
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
    if (save_r14) { STEP(0x040b7c); push(s,ram,R(14)); }
    STEP(0x040b7e); push(s,ram,R(16));
    STEP(0x040b80); R(15)-=16;
    STEP(0x040b82); R(3)=R(15);
    STEP(0x040b84); R(3)+=14;
    STEP(0x040b86); vf3_matrix_write(ram,R(3),R(4),2);
    STEP(0x040b88); vf3_matrix_write(ram,R(15)+8,R(5),4);
    STEP(0x040b8a); vf3_matrix_write(ram,R(15)+4,R(6),4);
    STEP(0x040b8c); R(0)=(uint32_t)(int32_t)(int16_t)vf3_matrix_read(ram,R(15)+14,2);
    STEP(0x040b8e); R(0)&=65535u;
    STEP(0x040b90); R(14)=15;
    STEP(0x040b92); R(14)&=R(0);
    STEP(0x040b94); R(14)<<=16;
    STEP(0x040b96); R(14)<<=8;
    STEP(0x040b98); R(3)=vf3_matrix_read(ram,R(15)+8,4);
    STEP(0x040b9a); R(14)+=R(3);
    STEP(0x040b9c); R(2)=0xff00;
    STEP(0x040b9e); condition(s,(R(3)&R(2))==0);
    STEP(0x040ba0);
    if (!(R(17)&1u)) {
        STEP(0x040ba2); R(0)=vf3_matrix_read(ram,R(15)+8,4);
        int matched=0;
        for (unsigned i=0;i<sizeof(parameter_commands)/sizeof(*parameter_commands);++i) {
            const uint32_t pc=0x040ba4+6*i;
            STEP(pc); R(1)=parameter_commands[i];
            STEP(pc+2); condition(s,R(0)==R(1));
            STEP(pc+4);
            if (R(17)&1u) {
                matched=1;
                if (i==2 || i==3 || i==4 || i==8) {
                    STEP(0x040bea); R(0)=vf3_matrix_read(ram,R(15)+4,4);
                    STEP(0x040bec); R(0)+=64;
                    STEP(0x040bee); R(0)&=127;
                    STEP(0x040bf0); R(0)<<=16;
                    STEP(0x040bf2); R(14)+=R(0);
                    STEP(0x040bf4); STEP(0x040bf6);
                } else {
                    STEP(0x040bde); R(0)=vf3_matrix_read(ram,R(15)+4,4);
                    STEP(0x040be0); R(0)&=127;
                    STEP(0x040be2); R(0)<<=16;
                    STEP(0x040be4); R(14)+=R(0);
                    STEP(0x040be6); STEP(0x040be8);
                }
                break;
            }
        }
        if (!matched) { STEP(0x040bda); STEP(0x040bdc); }
    }
    STEP(0x040c10); R(2)=0x001f00a0;
    STEP(0x040c12); R(3)=vf3_matrix_read(ram,R(15)+8,4);
    STEP(0x040c14); condition(s,R(3)==R(2));
    STEP(0x040c16);
    if (R(17)&1u) {
        /* This command visits all seven channels. A disabled table entry
         * suppresses both requests; enqueue failure does not stop the loop. */
        STEP(0x040c18); R(3)=1;
        STEP(0x040c1a); vf3_matrix_write(ram,R(15),R(3),4);
        STEP(0x040c1c); STEP(0x040c1e);
        for (;;) {
            STEP(0x040c56); R(2)=8;
            STEP(0x040c58); R(1)=vf3_matrix_read(ram,R(15),4);
            STEP(0x040c5a); condition(s,(int32_t)R(1)>=(int32_t)R(2));
            STEP(0x040c5c);
            if (R(17)&1u) break;
            STEP(0x040c20); R(0)=vf3_matrix_read(ram,R(15),4);
            STEP(0x040c22); R(3)=R(0);
            STEP(0x040c24); condition(s,(R(0)&0x80000000u)!=0); R(0)<<=1;
            STEP(0x040c26); R(0)+=R(3);
            STEP(0x040c28); R(0)<<=2;
            STEP(0x040c2a); R(0)=(uint32_t)(int32_t)(int8_t)R(0);
            STEP(0x040c2c); R(1)=0x0c19e310;
            STEP(0x040c2e); R(0)=vf3_matrix_read(ram,R(1)+R(0),4);
            STEP(0x040c30); condition(s,R(0)==0xffffffffu);
            STEP(0x040c32);
            if (!(R(17)&1u)) {
                STEP(0x040c34); R(4)=vf3_matrix_read(ram,R(15),4);
                STEP(0x040c36); R(4)<<=16;
                STEP(0x040c38); R(4)<<=8;
                STEP(0x040c3a); R(3)=0x001100a0;
                STEP(0x040c3c); R(4)+=R(3);
                STEP(0x040c3e); R(16)=alias+0x040c42;
                STEP(0x040c40);
                if (!vf3_audio_queue_at_c(s,ram,alias)) return 0;
                STEP(0x040c42); R(4)=vf3_matrix_read(ram,R(15),4);
                STEP(0x040c44); R(4)<<=16;
                STEP(0x040c46); R(4)<<=8;
                STEP(0x040c48); R(3)=0x04a0;
                STEP(0x040c4a); R(4)+=R(3);
                STEP(0x040c4c); R(16)=alias+0x040c50;
                STEP(0x040c4e);
                if (!vf3_audio_queue_at_c(s,ram,alias)) return 0;
            }
            STEP(0x040c50); R(3)=vf3_matrix_read(ram,R(15),4);
            STEP(0x040c52); R(3)+=1;
            STEP(0x040c54); vf3_matrix_write(ram,R(15),R(3),4);
        }
        STEP(0x040c5e); R(15)+=16;
        STEP(0x040c60); R(16)=pop(s,ram);
        STEP(0x040c62); R(14)=pop(s,ram);
        STEP(0x040c64); STEP(0x040c66);
    } else {
        STEP(0x040c68); R(4)=R(14);
        STEP(0x040c6a); R(16)=alias+0x040c6e;
        STEP(0x040c6c);
        if (!vf3_audio_queue_at_c(s,ram,alias)) return 0;
        STEP(0x040c6e); R(15)+=16;
        STEP(0x040c70); R(16)=pop(s,ram);
        STEP(0x040c72); R(14)=pop(s,ram);
        STEP(0x040c74); STEP(0x040c76);
    }
    s->pc=R(16); return ram->oob==0;
}
