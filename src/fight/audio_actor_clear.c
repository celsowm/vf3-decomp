/* Fight actor cleanup, callable 0x8c098040 (frozen owner 0x8c098042).
 * Its fixed startup request posts six channel words, submits the two actor
 * styles, then clears the active bit on six referenced task objects.
 * The startup wrapper is specialized to this caller's constant arguments
 * and reuses the independently verified general command encoder. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
#ifdef VF3_AUDIO_BRIDGE
extern void vf3_audio_queue_step(vf3_matrix_state*,uint32_t);
#define STEP(pc) vf3_audio_queue_step(s,alias+(pc))
#else
#define STEP(pc) ((void)0)
#endif
extern int vf3_audio_queue_at_c(vf3_matrix_state*,const vf3_ram_map*,uint32_t);
extern int vf3_audio_style_at_c(vf3_matrix_state*,const vf3_ram_map*,uint32_t);
static void condition(vf3_matrix_state *s,int value)
{ R(17)=(R(17)&~1u)|(value!=0); }
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t value)
{ R(15)-=4; vf3_matrix_write(ram,R(15),value,4); }
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram)
{ uint32_t value=vf3_matrix_read(ram,R(15),4); R(15)+=4; return value; }

extern int vf3_audio_encoder_c(vf3_matrix_state*,const vf3_ram_map*,uint32_t,int);
static int startup_encode(vf3_matrix_state *s,const vf3_ram_map *ram)
{ return vf3_audio_encoder_c(s,ram,0x0c000000u,1); }

static int startup(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    const uint32_t alias=0x0c000000;
    STEP(0x0c5c94); push(s,ram,R(14));
    STEP(0x0c5c96); R(0)=R(4);
    STEP(0x0c5c98); push(s,ram,R(13));
    STEP(0x0c5c9a); condition(s,R(0)==0xffffffff);
    STEP(0x0c5c9c); push(s,ram,R(12));
    STEP(0x0c5c9e); R(13)=R(4);
    STEP(0x0c5ca0); push(s,ram,R(11));
    STEP(0x0c5ca2); push(s,ram,R(16));
    STEP(0x0c5ca4);
    STEP(0x0c5ca6); R(11)=R(5);
    STEP(0x0c5ca8); R(3)=0x4a0;
    STEP(0x0c5caa); condition(s,R(13)==R(3));
    STEP(0x0c5cac);
    STEP(0x0c5cf4); R(3)=0x5a0;
    STEP(0x0c5cf6); R(14)=0x0c040b7c;
    STEP(0x0c5cf8); condition(s,R(13)==R(3));
    STEP(0x0c5cfa);
    STEP(0x0c5cfc); R(1)=0x2a0;
    STEP(0x0c5cfe); condition(s,R(13)==R(1));
    STEP(0x0c5d00);
    STEP(0x0c5d02); R(0)=0x3a0;
    STEP(0x0c5d04); condition(s,R(13)==R(0));
    STEP(0x0c5d06);
    STEP(0x0c5d18); R(3)=0x100a0;
    STEP(0x0c5d1a); R(12)=0x1100a0;
    STEP(0x0c5d1c); condition(s,R(13)==R(3));
    STEP(0x0c5d1e);
    STEP(0x0c5d38); R(1)=0x300a0;
    STEP(0x0c5d3a); condition(s,R(13)==R(1));
    STEP(0x0c5d3c);
    STEP(0x0c5d3e); R(5)=R(12);
    STEP(0x0c5d40); R(6)=0;
    STEP(0x0c5d42); R(16)=alias+0x0c5d46;
    STEP(0x0c5d44); R(4)=1;
    if (!startup_encode(s,ram)) return 0;
    STEP(0x0c5d46); R(4)=2;
    STEP(0x0c5d48); R(5)=R(12);
    STEP(0x0c5d4a); R(6)=0;
    STEP(0x0c5d4c); R(16)=alias+0x0c5d50;
    STEP(0x0c5d4e);
    if (!startup_encode(s,ram)) return 0;
    for (unsigned i=0;i<3;++i) {
        const uint32_t pc=0x0c5d50+i*8;
        STEP(pc); R(5)=R(12);
        STEP(pc+2); R(6)=0;
        STEP(pc+4); R(16)=alias+pc+8;
        STEP(pc+6); R(4)=4+i;
        if (!startup_encode(s,ram)) return 0;
    }
    STEP(0x0c5d68); R(5)=R(12);
    STEP(0x0c5d6a); R(6)=0;
    STEP(0x0c5d6c);
    STEP(0x0c5d6e); R(4)=7;
    STEP(0x0c5d76); R(16)=alias+0x0c5d7a;
    STEP(0x0c5d78);
    if (!startup_encode(s,ram)) return 0;
    STEP(0x0c5d7a); R(16)=pop(s,ram);
    STEP(0x0c5d7c); R(11)=pop(s,ram);
    STEP(0x0c5d7e); R(12)=pop(s,ram);
    STEP(0x0c5d80); R(13)=pop(s,ram);
    STEP(0x0c5d82);
    STEP(0x0c5d84); R(14)=pop(s,ram);
    s->pc=R(16); return ram->oob==0;
}

static int clear_active(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    const uint32_t alias=0x0c000000;
    STEP(0x0968f8); R(1)=vf3_matrix_read(ram,R(4),4);
    STEP(0x0968fa); R(3)=0xfffffffe;
    STEP(0x0968fc); R(1)&=R(3);
    STEP(0x0968fe);
    STEP(0x096900); vf3_matrix_write(ram,R(4),R(1),4);
    s->pc=R(16); return ram->oob==0;
}

int vf3_audio_actor_clear_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    const uint32_t alias=0x8c000000;
    STEP(0x098040); push(s,ram,R(14));
    STEP(0x098042); push(s,ram,R(16));
    STEP(0x098044); R(3)=0x0c0c5c94;
    STEP(0x098046); R(4)=0x300a0;
    STEP(0x098048); R(16)=alias+0x09804c;
    STEP(0x09804a); R(5)=0;
    if (!startup(s,ram)) return 0;
    STEP(0x09804c); R(2)=0x0c0ca05c;
    STEP(0x09804e); R(14)=0x0c29bb84;
    STEP(0x098050); R(16)=alias+0x098054;
    STEP(0x098052); R(4)=vf3_matrix_read(ram,R(14)+16,4);
    if (!vf3_audio_style_at_c(s,ram,0x0c000000)) return 0;
    STEP(0x098054); R(3)=0x0c0ca05c;
    STEP(0x098056); R(16)=alias+0x09805a;
    STEP(0x098058); R(4)=vf3_matrix_read(ram,R(14)+20,4);
    if (!vf3_audio_style_at_c(s,ram,0x0c000000)) return 0;
    STEP(0x09805a); R(2)=0x0c0968f8;
    STEP(0x09805c); R(16)=alias+0x098060;
    STEP(0x09805e); R(4)=vf3_matrix_read(ram,R(14)+16,4);
    if (!clear_active(s,ram)) return 0;
    STEP(0x098060); R(3)=0x0c0968f8;
    STEP(0x098062); R(16)=alias+0x098066;
    STEP(0x098064); R(4)=vf3_matrix_read(ram,R(14)+20,4);
    if (!clear_active(s,ram)) return 0;
    for (unsigned i=0;i<3;++i) {
        const uint32_t pc=0x098066+i*8;
        const unsigned field=i==0?72:i==1?92:96;
        STEP(pc); R(3)=0x0c0968f8;
        STEP(pc+2); R(0)=field;
        STEP(pc+4); R(16)=alias+pc+8;
        STEP(pc+6); R(4)=vf3_matrix_read(ram,R(14)+R(0),4);
        if (!clear_active(s,ram)) return 0;
    }
    STEP(0x09807e); R(16)=pop(s,ram);
    STEP(0x098080); R(0)=100;
    STEP(0x098082); R(3)=0x0c0968f8;
    STEP(0x098084); R(4)=vf3_matrix_read(ram,R(14)+R(0),4);
    STEP(0x098086);
    STEP(0x098088); R(14)=pop(s,ram);
    return clear_active(s,ram);
}
