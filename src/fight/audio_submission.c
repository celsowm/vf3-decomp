/* Submit an immutable mapped sound ID once per generation. Scene 3 checks
 * the configuration byte first. Actor style is a separate immutable lookup.
 * Posting and ARM command consumption are distinct operations. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
#ifdef VF3_AUDIO_BRIDGE
extern void vf3_audio_queue_step(vf3_matrix_state*,uint32_t);
#define STEP(pc) vf3_audio_queue_step(s,alias+(pc))
#define PHYS_STEP(pc) vf3_audio_queue_step(s,0x0c000000u+(pc))
#else
#define STEP(pc) ((void)0)
#define PHYS_STEP(pc) ((void)0)
#endif
extern int vf3_audio_queue_at_c(vf3_matrix_state*,const vf3_ram_map*,uint32_t);
static void condition(vf3_matrix_state *s,int value)
{ R(17)=(R(17)&~1u)|(value!=0); }
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t value)
{ R(15)-=4; vf3_matrix_write(ram,R(15),value,4); }
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram)
{ uint32_t value=vf3_matrix_read(ram,R(15),4); R(15)+=4; return value; }

static int mapped_id(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t alias)
{
    STEP(0x0c5dba); push(s,ram,R(14));
    STEP(0x0c5dbc); condition(s,(int32_t)R(4)>=0);
    STEP(0x0c5dbe); push(s,ram,R(16));
    STEP(0x0c5dc0); R(5)=0x0c1fd758;
    STEP(0x0c5dc2);
    if (!(R(17)&1u)) goto done;
    STEP(0x0c5dc4); R(2)=477;
    STEP(0x0c5dc6); condition(s,(int32_t)R(4)>=(int32_t)R(2));
    STEP(0x0c5dc8);
    if (R(17)&1u) goto done;
    STEP(0x0c5dca); R(0)=0x0c1025f0;
    STEP(0x0c5dcc); R(4)<<=2;
    STEP(0x0c5dce); R(14)=R(4);
    STEP(0x0c5dd0); R(3)=vf3_matrix_read(ram,R(0)+R(14),4);
    STEP(0x0c5dd2); condition(s,(int32_t)R(3)>=0);
    STEP(0x0c5dd4);
    if (!(R(17)&1u)) goto done;
    STEP(0x0c5dd6); R(4)=0x0c2cfa00;
    STEP(0x0c5dd8); R(0)=R(14);
    STEP(0x0c5dda); R(2)=vf3_matrix_read(ram,R(5),4);
    STEP(0x0c5ddc); R(3)=vf3_matrix_read(ram,R(4)+R(0),4);
    STEP(0x0c5dde); condition(s,R(3)==R(2));
    STEP(0x0c5de0);
    if (R(17)&1u) goto done;
    STEP(0x0c5de2); R(3)=vf3_matrix_read(ram,R(5),4);
    STEP(0x0c5de4); R(0)=R(14);
    STEP(0x0c5de6); vf3_matrix_write(ram,R(4)+R(0),R(3),4);
    STEP(0x0c5de8); R(3)=0x0c040f1e;
    STEP(0x0c5dea); R(0)=0x0c1025f0;
    STEP(0x0c5dec); R(16)=alias+0x0c5df0;
    STEP(0x0c5dee); R(4)=vf3_matrix_read(ram,R(0)+R(14),4);
    if (!vf3_audio_queue_at_c(s,ram,0x0c000000)) return 0;
done:
    STEP(0x0c5df0); R(16)=pop(s,ram);
    STEP(0x0c5df2);
    STEP(0x0c5df4); R(14)=pop(s,ram);
    s->pc=R(16); return ram->oob==0;
}

static int submission(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t alias)
{
    STEP(0x0c5d86); push(s,ram,R(16));
    STEP(0x0c5d88); R(15)-=8;
    STEP(0x0c5d8a); vf3_matrix_write(ram,R(15),R(4),4);
    STEP(0x0c5d8c); R(4)=0x0c29b864;
    STEP(0x0c5d8e); R(3)=0x0c11e504;
    STEP(0x0c5d90); vf3_matrix_write(ram,R(15)+4,R(3),4);
    STEP(0x0c5d92); R(0)=(uint32_t)(int32_t)(int8_t)vf3_matrix_read(ram,R(4)+8,1);
    STEP(0x0c5d94); R(0)&=255;
    STEP(0x0c5d96); condition(s,R(0)==3);
    STEP(0x0c5d98); int scene_three=R(17)&1u;
    STEP(0x0c5d9a); R(4)=R(0);
    if (scene_three) {
        STEP(0x0c5d9c); R(3)=0x0c0c66b8;
        STEP(0x0c5d9e); R(4)=vf3_matrix_read(ram,R(15)+4,4);
        STEP(0x0c5da0); R(16)=alias+0x0c5da4;
        STEP(0x0c5da2); R(4)+=3;
        PHYS_STEP(0x0c66b8);
        PHYS_STEP(0x0c66ba); R(0)=(uint32_t)(int32_t)(int8_t)vf3_matrix_read(ram,R(4),1);
        STEP(0x0c5da4); R(4)=R(0)&255;
        STEP(0x0c5da6); condition(s,R(4)==0);
        STEP(0x0c5da8);
        if (!(R(17)&1u)) {
            STEP(0x0c5db2); R(15)+=8;
            STEP(0x0c5db4); R(16)=pop(s,ram);
            STEP(0x0c5db6);
            STEP(0x0c5db8);
            s->pc=R(16); return ram->oob==0;
        }
    }
    STEP(0x0c5daa); R(4)=vf3_matrix_read(ram,R(15),4);
    STEP(0x0c5dac); R(15)+=8;
    STEP(0x0c5dae);
    STEP(0x0c5db0); R(16)=pop(s,ram);
    return mapped_id(s,ram,alias);
}

int vf3_audio_submission_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{ return submission(s,ram,0x8c000000); }

int vf3_audio_submission_at_c(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t alias)
{ return submission(s,ram,alias); }

static int style(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t alias)
{
    STEP(0x0ca05c); R(0)=97;
    STEP(0x0ca05e); R(3)=(uint32_t)(int32_t)(int8_t)vf3_matrix_read(ram,R(4)+R(0),1);
    STEP(0x0ca060); R(0)=0x0c11331c;
    STEP(0x0ca062); R(3)&=255;
    STEP(0x0ca064); R(3)<<=2;
    STEP(0x0ca066); R(4)=vf3_matrix_read(ram,R(0)+R(3),4);
    STEP(0x0ca068); R(3)=0x0c0c5d86;
    STEP(0x0ca06a);
    STEP(0x0ca06c);
    return submission(s,ram,0x0c000000);
}

int vf3_audio_style_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{ return style(s,ram,0x8c000000); }

int vf3_audio_style_at_c(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t alias)
{ return style(s,ram,alias); }
