/* Original 0x8c09afc0: merge packet word +16 with the shared port selector.
 * Frozen owner starts at 0x8c09afc6, after the three register saves. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
#define READ(a) vf3_matrix_read(ram,(a),4)
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t value)
{ R(15)-=4;vf3_matrix_write(ram,R(15),value,4); }
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram)
{ uint32_t value=READ(R(15));R(15)+=4;return value; }
static void condition(vf3_matrix_state *s,int value)
{ R(17)=(R(17)&~1u)|(value!=0); }
static int packet(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t port,uint32_t pc)
{ R(4)=port;R(16)=pc;return vf3_matrix_family(R(13),s,ram); }

int vf3_controller_secondary_c(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t alias)
{
    push(s,ram,R(14));push(s,ram,R(13));push(s,ram,R(12));push(s,ram,R(16));
    R(13)=0x0c0a1282;R(12)=0x0c29bcc4;
    if(!packet(s,ram,0,alias+0x09afd0))return 0;
    if(s->pc!=alias+0x09afd0)return vf3_matrix_family(s->pc,s,ram);
    R(4)=R(0);R(14)=READ(R(4)+16);R(3)=READ(R(12)+8);
    R(4)=0x30000000;R(3)&=R(4);condition(s,R(3)==R(4));
    if(R(17)&1u){
        if(!packet(s,ram,1,alias+0x09afe2))return 0;
        if(s->pc!=alias+0x09afe2)return vf3_matrix_family(s->pc,s,ram);
        R(4)=R(0);R(3)=READ(R(4)+16);R(14)|=R(3);
    }else{
        R(2)=READ(R(12)+8);R(3)=0x10000000;condition(s,(R(2)&R(3))==0);
        if(!(R(17)&1u)){
            if(!packet(s,ram,1,alias+0x09aff6))return 0;
            if(s->pc!=alias+0x09aff6)return vf3_matrix_family(s->pc,s,ram);
            R(4)=R(0);R(14)=READ(R(4)+16);
        }
    }
    R(16)=pop(s,ram);R(0)=R(14);
    R(12)=pop(s,ram);R(13)=pop(s,ram);R(14)=pop(s,ram);
    s->pc=R(16);return ram->oob==0;
}
