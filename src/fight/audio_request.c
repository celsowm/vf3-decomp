/* General request wrapper 0x8c0c5c94 (fragment owner 0x8c0c5ca2).
 * Channel selection and command encoding are separate observable operations. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
#ifdef VF3_AUDIO_BRIDGE
extern void vf3_audio_queue_step(vf3_matrix_state*,uint32_t);
#define STEP(pc) vf3_audio_queue_step(s,alias+(pc))
#else
#define STEP(pc) ((void)0)
#endif
extern int vf3_audio_encoder_c(vf3_matrix_state*,const vf3_ram_map*,uint32_t,int);
static void condition(vf3_matrix_state *s,int value)
{ R(17)=(R(17)&~1u)|(value!=0); }
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t value)
{ R(15)-=4; vf3_matrix_write(ram,R(15),value,4); }
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram)
{ uint32_t value=vf3_matrix_read(ram,R(15),4); R(15)+=4; return value; }
static int encode(vf3_matrix_state *s,const vf3_ram_map *ram)
{ return vf3_audio_encoder_c(s,ram,0x0c000000u,1); }

int vf3_audio_request_c(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t alias,int prefix)
{
    if (prefix) {
        STEP(0x0c5c94); push(s,ram,R(14));
        STEP(0x0c5c96); R(0)=R(4);
        STEP(0x0c5c98); push(s,ram,R(13));
        STEP(0x0c5c9a); condition(s,R(0)==0xffffffffu);
        STEP(0x0c5c9c); push(s,ram,R(12));
        STEP(0x0c5c9e); R(13)=R(4);
        STEP(0x0c5ca0); push(s,ram,R(11));
    }
    STEP(0x0c5ca2); push(s,ram,R(16));
    STEP(0x0c5ca4);
    int rejected=(R(17)&1u)!=0;
    STEP(0x0c5ca6); R(11)=R(5);
    if (!rejected) {
        STEP(0x0c5ca8); R(3)=0x4a0;
        STEP(0x0c5caa); condition(s,R(13)==R(3));
        STEP(0x0c5cac); rejected=(R(17)&1u)!=0;
    }
    if (rejected) {
        STEP(0x0c5cae); STEP(0x0c5cb0); R(0)=0xffffffffu;
        goto done;
    }
    STEP(0x0c5cf4); R(3)=0x5a0;
    STEP(0x0c5cf6); R(14)=0x0c040b7c;
    STEP(0x0c5cf8); condition(s,R(13)==R(3));
    STEP(0x0c5cfa);
    if (!(R(17)&1u)) {
        STEP(0x0c5cfc); R(1)=0x2a0;
        STEP(0x0c5cfe); condition(s,R(13)==R(1));
        STEP(0x0c5d00);
        if (!(R(17)&1u)) {
            STEP(0x0c5d02); R(0)=0x3a0;
            STEP(0x0c5d04); condition(s,R(13)==R(0));
            STEP(0x0c5d06);
        }
    }
    if (R(17)&1u) {
        STEP(0x0c5d08); R(5)=R(13);
        STEP(0x0c5d0a); R(6)=R(11);
        STEP(0x0c5d0c); R(16)=alias+0x0c5d10;
        STEP(0x0c5d0e); R(4)=4;
        if (!encode(s,ram)) return 0;
        STEP(0x0c5d10); R(5)=R(13);
        STEP(0x0c5d12); R(6)=R(11);
        STEP(0x0c5d14); STEP(0x0c5d16); R(4)=3;
        goto last;
    }
    STEP(0x0c5d18); R(3)=0x100a0;
    STEP(0x0c5d1a); R(12)=0x1100a0;
    STEP(0x0c5d1c); condition(s,R(13)==R(3));
    STEP(0x0c5d1e);
    if (R(17)&1u) {
        for (unsigned i=0;i<2;++i) {
            uint32_t pc=0x0c5d20+8*i;
            STEP(pc); R(5)=R(12);
            STEP(pc+2); R(6)=0;
            STEP(pc+4); R(16)=alias+pc+8;
            STEP(pc+6); R(4)=1+i;
            if (!encode(s,ram)) return 0;
        }
        STEP(0x0c5d30); R(5)=R(12);
        STEP(0x0c5d32); R(6)=0;
        STEP(0x0c5d34); STEP(0x0c5d36); R(4)=3;
    } else {
        STEP(0x0c5d38); R(1)=0x300a0;
        STEP(0x0c5d3a); condition(s,R(13)==R(1));
        STEP(0x0c5d3c);
        if (!(R(17)&1u)) {
            STEP(0x0c5d70); R(4)=0;
            STEP(0x0c5d72); R(5)=R(13);
            STEP(0x0c5d74); R(6)=R(11);
            goto last;
        }
        STEP(0x0c5d3e); R(5)=R(12);
        STEP(0x0c5d40); R(6)=0;
        STEP(0x0c5d42); R(16)=alias+0x0c5d46;
        STEP(0x0c5d44); R(4)=1;
        if (!encode(s,ram)) return 0;
        STEP(0x0c5d46); R(4)=2;
        STEP(0x0c5d48); R(5)=R(12);
        STEP(0x0c5d4a); R(6)=0;
    }
    STEP(0x0c5d4c); R(16)=alias+0x0c5d50;
    STEP(0x0c5d4e);
    if (!encode(s,ram)) return 0;
    for (unsigned i=0;i<3;++i) {
        uint32_t pc=0x0c5d50+8*i;
        STEP(pc); R(5)=R(12);
        STEP(pc+2); R(6)=0;
        STEP(pc+4); R(16)=alias+pc+8;
        STEP(pc+6); R(4)=4+i;
        if (!encode(s,ram)) return 0;
    }
    STEP(0x0c5d68); R(5)=R(12);
    STEP(0x0c5d6a); R(6)=0;
    STEP(0x0c5d6c); STEP(0x0c5d6e); R(4)=7;
last:
    STEP(0x0c5d76); R(16)=alias+0x0c5d7a;
    STEP(0x0c5d78);
    if (!encode(s,ram)) return 0;
done:
    STEP(0x0c5d7a); R(16)=pop(s,ram);
    STEP(0x0c5d7c); R(11)=pop(s,ram);
    STEP(0x0c5d7e); R(12)=pop(s,ram);
    STEP(0x0c5d80); R(13)=pop(s,ram);
    STEP(0x0c5d82); STEP(0x0c5d84); R(14)=pop(s,ram);
    s->pc=R(16); return ram->oob==0;
}
