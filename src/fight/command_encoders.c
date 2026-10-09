/* Original scalar sound-command encoders and enqueue operation. The queue
 * pointer and per-channel enabled bytes remain observable caller state. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
#ifdef VF3_AUDIO_BRIDGE
/* Research clock boundaries; the ordinary portable build has no dependency. */
extern void vf3_audio_queue_step(vf3_matrix_state*,uint32_t);
#define QUEUE_STEP(pc) vf3_audio_queue_step(s,0x8c000000u+(pc))
#else
#define QUEUE_STEP(pc) ((void)0)
#endif
static uint32_t read_word(const vf3_ram_map *ram,uint32_t address)
{ return (uint32_t)(int32_t)(int16_t)vf3_matrix_read(ram,address,2); }
static void condition(vf3_matrix_state *s,int value)
{ R(17)=(R(17)&~1u)|(value!=0); }
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t value)
{ R(15)-=4; vf3_matrix_write(ram,R(15),value,4); }
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram)
{ uint32_t value=vf3_matrix_read(ram,R(15),4); R(15)+=4; return value; }

static int enqueue(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    QUEUE_STEP(0x040f1e); R(15)-=4;
    QUEUE_STEP(0x040f20); vf3_matrix_write(ram,R(15),R(4),4);
    QUEUE_STEP(0x040f22); R(0)=vf3_matrix_read(ram,R(15),4);
    QUEUE_STEP(0x040f24); condition(s,(R(0)&128u)==0);
    QUEUE_STEP(0x040f26);
    if(R(17)&1u) {
        QUEUE_STEP(0x040f28); R(0)=0xfffffffeu;
        QUEUE_STEP(0x040f2a); R(15)+=4;
        QUEUE_STEP(0x040f2c); QUEUE_STEP(0x040f2e);
        s->pc=R(16); return ram->oob==0;
    }
    else {
        QUEUE_STEP(0x040f30); R(3)=0x0c19e218;
        QUEUE_STEP(0x040f32); R(2)=vf3_matrix_read(ram,R(3),4);
        QUEUE_STEP(0x040f34); R(1)=vf3_matrix_read(ram,R(2),4);
        QUEUE_STEP(0x040f36); condition(s,R(1)==0);
        QUEUE_STEP(0x040f38);
        if(!(R(17)&1u)) {
            QUEUE_STEP(0x040f3a); R(0)=0xffffffffu;
            QUEUE_STEP(0x040f3c); R(15)+=4;
            QUEUE_STEP(0x040f3e); QUEUE_STEP(0x040f40);
            s->pc=R(16); return ram->oob==0;
        }
        else {
            QUEUE_STEP(0x040f42); R(3)=0x0c19e218;
            QUEUE_STEP(0x040f44); R(2)=vf3_matrix_read(ram,R(3),4);
            QUEUE_STEP(0x040f46); R(2)+=4;
            QUEUE_STEP(0x040f48); vf3_matrix_write(ram,R(3),R(2),4);
            QUEUE_STEP(0x040f4a); R(2)-=4;
            QUEUE_STEP(0x040f4c); R(3)=vf3_matrix_read(ram,R(15),4);
            QUEUE_STEP(0x040f4e); vf3_matrix_write(ram,R(2),R(3),4);
            QUEUE_STEP(0x040f50); R(2)=0xa0800500;
            QUEUE_STEP(0x040f52); R(3)=0x0c19e218;
            QUEUE_STEP(0x040f54); R(1)=vf3_matrix_read(ram,R(3),4);
            QUEUE_STEP(0x040f56); condition(s,R(1)==R(2));
            QUEUE_STEP(0x040f58);
            if(R(17)&1u) {
                QUEUE_STEP(0x040f5a); R(3)=0xa0800400;
                QUEUE_STEP(0x040f5c); R(0)=0x0c19e218;
                QUEUE_STEP(0x040f5e); vf3_matrix_write(ram,R(0),R(3),4);
            }
            QUEUE_STEP(0x040f60); R(0)=0;
        }
    }
    QUEUE_STEP(0x040f62); R(15)+=4;
    QUEUE_STEP(0x040f64); QUEUE_STEP(0x040f66);
    s->pc=R(16); return ram->oob==0;
}

#ifdef VF3_AUDIO_BRIDGE
int vf3_audio_queue_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{ return enqueue(s,ram); }
#endif

static int send(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t continuation)
{ R(4)=R(14); R(16)=continuation; return enqueue(s,ram); }

static int scalar_encoder(uint32_t entry,vf3_matrix_state *s,const vf3_ram_map *ram)
{
    uint32_t parent=entry;
    if(entry==0x0c040c92) parent=0x0c040c90;
    if(entry==0x0c040d20) parent=0x0c040d1c;
    if(entry==0x0c040e28) parent=0x0c040e24;
    if(entry==parent) { push(s,ram,R(14)); if(parent!=0x0c040c90) push(s,ram,R(13)); }
    push(s,ram,R(16));
    unsigned locals=parent==0x0c040c90?16:12;
    R(15)-=locals;
    vf3_matrix_write(ram,R(15)+locals-4,R(4),4);
    vf3_matrix_write(ram,R(15)+locals-8,R(5),4);
    vf3_matrix_write(ram,R(15)+locals-12,R(6),4);
    if(locals==16) vf3_matrix_write(ram,R(15),R(7),4);
    if(parent==0x0c040c90) {
        R(0)=vf3_matrix_read(ram,R(15)+8,4)-1; R(14)=R(0)&15;
        R(0)=(vf3_matrix_read(ram,R(15)+12,4)&15)<<24; R(14)+=R(0);
        R(3)=vf3_matrix_read(ram,R(15)+4,4); R(14)+=R(3); R(0)=R(3);
        const uint32_t selectors[]={0x7b0,0xab0,0x27b0,0x2ab0};
        unsigned selected=4;
        for(unsigned i=0;i<4;++i) { R(1)=selectors[i]; condition(s,R(0)==R(1)); if(R(17)&1u) { selected=i; break; } }
        if(selected==4) R(0)=0xfffffffeu;
        else {
            R(0)=vf3_matrix_read(ram,R(15),4);
            if(selected&1u) R(0)+=64;
            R(0)=(R(0)&127)<<16; R(14)+=R(0);
            if(!send(s,ram,0x0c040d00)) return 0;
        }
    } else {
        int frequency=parent==0x0c040d1c;
        R(0)=(vf3_matrix_read(ram,R(15)+8,4)&15)<<8;
        R(14)=vf3_matrix_read(ram,R(15)+4,4)+R(0);
        R(0)=vf3_matrix_read(ram,R(15)+4,4);
        const uint32_t selectors[]={0xa5,0xa6,0xa7,0x10a5,0x10a7,0x20a5,0x30a5,0x40a5,0x50a5};
        unsigned selected=9;
        for(unsigned i=0;i<(frequency?9u:3u);++i) {
            R(1)=frequency?selectors[i]:(i==0?0xa4:i==1?0x10a4:0x20a4);
            condition(s,R(0)==R(1)); if(R(17)&1u) { selected=i; break; }
        }
        if(selected==9) R(0)=0xfffffffeu;
        else {
            if(selected==0) {
                if(frequency) R(0)=(vf3_matrix_read(ram,R(15)+8,4)&15)<<8;
                R(3)=0x7f00; R(14)=vf3_matrix_read(ram,R(15),4)&R(3); R(14)<<=8;
                if(frequency) R(14)+=R(0);
                R(2)=frequency?0x70a5:0x70a4; R(14)+=R(2);
                if(!send(s,ram,frequency?0x0c040d9c:0x0c040e66)) return 0;
                R(13)=R(0); condition(s,R(0)==0);
                if(!(R(17)&1u)) { R(0)=R(13); goto scalar_done; }
                if(frequency) {
                    R(0)=(vf3_matrix_read(ram,R(15)+8,4)&15)<<8; R(14)=R(0);
                    R(0)=(vf3_matrix_read(ram,R(15),4)&127)<<16; R(14)+=R(0);
                    R(3)=0xa5; R(14)+=R(3);
                } else {
                    R(0)=(vf3_matrix_read(ram,R(15),4)&127)<<16; R(14)=0xa4+R(0);
                }
            } else {
                R(0)=vf3_matrix_read(ram,R(15),4);
                if(frequency && selected==1) {
                    R(0)=(R(0)&127)<<16; R(3)=R(0);
                    R(0)=vf3_matrix_read(ram,R(15),4)&128;
                    condition(s,R(0)>>27); R(0)<<=5; R(3)+=R(0); R(14)+=R(3);
                } else {
                    if(frequency ? selected!=3 && selected!=8 : selected==2) R(0)+=64;
                    R(0)=(R(0)&((frequency?selected==8:selected==1)?15:127))<<16;
                    R(14)+=R(0);
                }
            }
            if(!send(s,ram,frequency?0x0c040e0e:0x0c040ea8)) return 0;
        }
    }
scalar_done:
    R(15)+=locals; R(16)=pop(s,ram);
    if(parent!=0x0c040c90) R(13)=pop(s,ram);
    R(14)=pop(s,ram); s->pc=R(16); return ram->oob==0;
}

static int channel_encoder(uint32_t entry,vf3_matrix_state *s,const vf3_ram_map *ram)
{
    uint32_t parent=entry&~1u;
    if(parent==0x0c041d06||parent==0x0c041d7e||parent==0x0c041de2||parent==0x0c041e5a||parent==0x0c041ebe) parent-=2;
    int triple=parent==0x0c041d04||parent==0x0c041de0;
    if(entry==parent) push(s,ram,R(14));
    push(s,ram,R(16)); unsigned locals=triple?8:4; R(15)-=locals;
    R(3)=R(15)+locals-2; vf3_matrix_write(ram,R(3),R(4),2);
    if(triple) {
        R(2)=R(15)+4; vf3_matrix_write(ram,R(2),R(5),2);
        R(3)=R(15)+2; vf3_matrix_write(ram,R(3),R(6),2);
    } else vf3_matrix_write(ram,R(15),R(5),2);
    R(0)=(uint32_t)(int32_t)(int8_t)vf3_matrix_read(ram,R(15)+locals-2,1); R(3)=R(0);
    condition(s,R(0)>>31); R(0)<<=1; R(0)+=R(3); R(0)<<=2;
    condition(s,R(0)>>31); R(0)<<=1; R(0)&=255;
    R(1)=0x0c19e250;
    R(0)=(uint32_t)(int32_t)(int8_t)vf3_matrix_read(ram,R(1)+R(0),1); condition(s,R(0)==1);
    if(R(17)&1u) {
        uint32_t continuation;
        if(triple) {
            R(0)=read_word(ram,R(15)+6)<<12;
            if(parent==0x0c041d04) {
                R(3)=R(0); R(0)=read_word(ram,R(15)+2)<<16; R(0)|=R(3); R(14)=0xa2|R(0);
            } else {
                R(14)=R(0); R(0)=read_word(ram,R(15)+2)<<16; R(14)|=R(0); R(3)=0x1a2; R(14)|=R(3);
            }
            R(0)=read_word(ram,R(15)+4)<<11; R(14)+=R(0);
            continuation=parent==0x0c041d04?0x0c041d60:0x0c041e3c;
        } else {
            R(14)=(read_word(ram,R(15))+64)<<16; R(0)=read_word(ram,R(15)+2)<<12; R(14)|=R(0);
            R(3)=parent==0x0c041d7c?0xca1:parent==0x0c041e58?0x8a1:0x9a1; R(14)|=R(3);
            continuation=parent==0x0c041d7c?0x0c041dc4:parent==0x0c041e58?0x0c041ea0:0x0c041f04;
        }
        if(!send(s,ram,continuation)) return 0;
    }
    R(15)+=locals; R(16)=pop(s,ram); R(14)=pop(s,ram); s->pc=R(16); return ram->oob==0;
}

static int paired_encoder(uint32_t entry,vf3_matrix_state *s,const vf3_ram_map *ram)
{
    if(entry==0x0c040ec2) { push(s,ram,R(14)); push(s,ram,R(13)); }
    push(s,ram,R(16)); R(15)-=8;
    vf3_matrix_write(ram,R(15)+4,R(4),4); vf3_matrix_write(ram,R(15),R(5),4);
    R(14)=vf3_matrix_read(ram,R(15)+4,4); R(0)=R(14); R(1)=0xa3;
    condition(s,R(0)==R(1));
    if(!(R(17)&1u)) R(0)=0xfffffffeu;
    else {
        R(0)=(vf3_matrix_read(ram,R(15),4)&15)<<16; R(14)+=R(0);
        if(!send(s,ram,0x0c040eec)) return 0;
        R(13)=R(0); condition(s,R(0)==0);
        if(!(R(17)&1u)) R(0)=R(13);
        else { R(3)=256; R(14)+=R(3); if(!send(s,ram,0x0c040f04)) return 0; }
    }
    R(15)+=8; R(16)=pop(s,ram); R(13)=pop(s,ram); R(14)=pop(s,ram);
    s->pc=R(16); return ram->oob==0;
}

#ifndef VF3_AUDIO_BRIDGE
int vf3_command_encoders(uint32_t entry,vf3_matrix_state *s,const vf3_ram_map *ram)
{
    entry&=0x1fffffffu;
    if(!s->budget--) { s->failed_pc=entry; return 0; }
    switch(entry) {
    case 0x0c040f1e: return enqueue(s,ram);
    case 0x0c040ec2: case 0x0c040ec6: return paired_encoder(entry,s,ram);
    case 0x0c040c90: case 0x0c040c92: case 0x0c040d1c: case 0x0c040d20:
    case 0x0c040e24: case 0x0c040e28: return scalar_encoder(entry,s,ram);
    case 0x0c041d04: case 0x0c041d06: case 0x0c041d7c: case 0x0c041d7e:
    case 0x0c041de0: case 0x0c041de2: case 0x0c041e58: case 0x0c041e5a:
    case 0x0c041ebc: case 0x0c041ebe: return channel_encoder(entry,s,ram);
    default: s->failed_pc=entry; return 0;
    }
}
#endif
