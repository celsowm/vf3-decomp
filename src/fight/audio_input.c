/* Sound-selection input caller 0x8c0c9f54, frozen owner 0x8c0c9f62.
 * Immutable lookup IDs and control words are preserved without assigning
 * voice/reset meanings to their command values. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
#ifdef VF3_AUDIO_BRIDGE
extern void vf3_audio_queue_step(vf3_matrix_state*,uint32_t);
#define STEP(pc) vf3_audio_queue_step(s,alias+(pc))
#else
#define STEP(pc) ((void)0)
#endif
extern int vf3_audio_request_c(vf3_matrix_state*,const vf3_ram_map*,uint32_t,int);
extern int vf3_audio_submission_at_c(vf3_matrix_state*,const vf3_ram_map*,uint32_t);
extern int vf3_audio_style_at_c(vf3_matrix_state*,const vf3_ram_map*,uint32_t);
static void condition(vf3_matrix_state *s,int value)
{ R(17)=(R(17)&~1u)|(value!=0); }
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t value)
{ R(15)-=4; vf3_matrix_write(ram,R(15),value,4); }
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram)
{ uint32_t value=vf3_matrix_read(ram,R(15),4); R(15)+=4; return value; }

int vf3_audio_input_c(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t alias)
{
    STEP(0x0c9f54); R(7)=0x0c29bcc4;
    STEP(0x0c9f56); R(0)=0xba;
    STEP(0x0c9f58); R(6)=0x0c29b864;
    STEP(0x0c9f5a); R(4)=(uint32_t)(int32_t)(int16_t)vf3_matrix_read(ram,R(7)+R(0),2);
    STEP(0x0c9f5c); R(0)=0x13c;
    STEP(0x0c9f5e); R(3)=0x2000;
    STEP(0x0c9f60); R(6)=vf3_matrix_read(ram,R(6)+R(0),4);
    STEP(0x0c9f62); push(s,ram,R(16));
    STEP(0x0c9f64); condition(s,(R(6)&R(3))==0);
    STEP(0x0c9f66); int unchanged=(R(17)&1u)!=0;
    STEP(0x0c9f68); R(5)=0;
    if (!unchanged) { STEP(0x0c9f6a); R(4)-=1; }
    STEP(0x0c9f6c); R(3)=8;
    STEP(0x0c9f6e); condition(s,(R(6)&R(3))==0);
    STEP(0x0c9f70);
    int increment=!(R(17)&1u);
    if (!increment) {
        STEP(0x0c9f72); R(2)=0x40000000;
        STEP(0x0c9f74); condition(s,(R(6)&R(2))==0);
        STEP(0x0c9f76); increment=!(R(17)&1u);
        if (!increment) {
            STEP(0x0c9f78); R(3)=0x1000;
            STEP(0x0c9f7a); condition(s,(R(6)&R(3))==0);
            STEP(0x0c9f7c); increment=!(R(17)&1u);
        }
    }
    if (increment) { STEP(0x0c9f7e); R(4)+=1; }
    STEP(0x0c9f80); R(3)=0x8000;
    STEP(0x0c9f82); condition(s,(R(6)&R(3))==0);
    STEP(0x0c9f84);
    if (!(R(17)&1u)) { STEP(0x0c9f86); R(4)-=10; }
    STEP(0x0c9f88); R(3)=0x4000;
    STEP(0x0c9f8a); condition(s,(R(6)&R(3))==0);
    STEP(0x0c9f8c);
    if (!(R(17)&1u)) { STEP(0x0c9f8e); R(4)+=10; }
    STEP(0x0c9f90); R(3)=457;
    STEP(0x0c9f92); R(0)=0xfffffe36u;
    STEP(0x0c9f94); condition(s,(int32_t)R(4)>(int32_t)R(3));
    STEP(0x0c9f96);
    int wrap=(R(17)&1u)!=0;
    if (!wrap) {
        STEP(0x0c9f98); R(0)=458;
        STEP(0x0c9f9a); condition(s,(int32_t)R(4)>=0);
        STEP(0x0c9f9c); wrap=!(R(17)&1u);
    }
    if (wrap) { STEP(0x0c9f9e); R(4)+=R(0); }
    STEP(0x0c9fa0); R(3)=423;
    STEP(0x0c9fa2); R(0)=0xba;
    STEP(0x0c9fa4); condition(s,R(4)==R(3));
    STEP(0x0c9fa6); int skip=(R(17)&1u)!=0;
    STEP(0x0c9fa8); vf3_matrix_write(ram,R(7)+R(0),R(4),2);
    if (skip) { STEP(0x0c9faa); R(4)-=1; }
    STEP(0x0c9fac); R(0)=0x0c101708;
    STEP(0x0c9fae); R(4)<<=2;
    STEP(0x0c9fb0); condition(s,(R(4)&0x80000000u)!=0); R(4)<<=1;
    STEP(0x0c9fb2); R(4)=vf3_matrix_read(ram,R(0)+R(4),4);
    STEP(0x0c9fb4); R(0)=R(4);
    STEP(0x0c9fb6); condition(s,R(0)==5);
    STEP(0x0c9fb8);
    if (R(17)&1u) { STEP(0x0c9fba); R(5)=96; }
    STEP(0x0c9fbc); R(2)=0x100;
    STEP(0x0c9fbe); condition(s,(R(6)&R(2))==0);
    STEP(0x0c9fc0);
    if (!(R(17)&1u)) goto request;
    STEP(0x0c9fc2); R(3)=4;
    STEP(0x0c9fc4); condition(s,(R(6)&R(3))==0);
    STEP(0x0c9fc6);
    if (!(R(17)&1u)) goto request;
    STEP(0x0c9fc8); R(2)=0x80000000;
    STEP(0x0c9fca); condition(s,(R(6)&R(2))==0);
    STEP(0x0c9fcc);
    if (!(R(17)&1u)) goto request;
    STEP(0x0c9fce); R(3)=0x200;
    STEP(0x0c9fd0); R(4)=0x200a0;
    STEP(0x0c9fd2); condition(s,(R(6)&R(3))==0);
    STEP(0x0c9fd4);
    if (!(R(17)&1u)) goto request;
    STEP(0x0c9fd6); R(2)=0x400;
    STEP(0x0c9fd8); condition(s,(R(6)&R(2))==0);
    STEP(0x0c9fda);
    if (!(R(17)&1u)) goto styles;
    STEP(0x0c9fdc); R(3)=0x20000;
    STEP(0x0c9fde); R(4)=0x100a0;
    STEP(0x0c9fe0); condition(s,(R(6)&R(3))==0);
    STEP(0x0c9fe2);
    if (R(17)&1u) goto done;
request:
    STEP(0x0c9fe4); R(3)=0x0c0c5c94;
    STEP(0x0c9fe6); R(16)=alias+0x0c9fea;
    STEP(0x0c9fe8);
    if (!vf3_audio_request_c(s,ram,0x0c000000u,1)) return 0;
    STEP(0x0c9fea); R(16)=pop(s,ram);
    STEP(0x0c9fec); STEP(0x0c9fee);
    s->pc=R(16); return ram->oob==0;
styles:
    STEP(0x0c9ff0); R(2)=0x0c0c5d86;
    STEP(0x0c9ff2); R(4)=0x300a0;
    STEP(0x0c9ff4); R(16)=alias+0x0c9ff8;
    STEP(0x0c9ff6);
    if (!vf3_audio_submission_at_c(s,ram,0x0c000000u)) return 0;
    STEP(0x0c9ff8); R(3)=0x0c29bb94;
    STEP(0x0c9ffa); R(16)=alias+0x0c9ffe;
    STEP(0x0c9ffc); R(4)=vf3_matrix_read(ram,R(3),4);
    if (!vf3_audio_style_at_c(s,ram,alias)) return 0;
    STEP(0x0c9ffe); R(3)=0x0c29bb98;
    STEP(0x0ca000); R(4)=vf3_matrix_read(ram,R(3),4);
    STEP(0x0ca002); STEP(0x0ca004); R(16)=pop(s,ram);
    return vf3_audio_style_at_c(s,ram,alias);
done:
    STEP(0x0ca006); R(16)=pop(s,ram);
    STEP(0x0ca008); STEP(0x0ca00a);
    s->pc=R(16); return ram->oob==0;
}
