/* Merge the actual controller packets according to the shared selector.
 * Full callable 0x8c09af6c; frozen owner 0x8c09af72. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
#define READ(a) vf3_matrix_read(ram,(a),4)
#define WRITE(a,v) vf3_matrix_write(ram,(a),(v),4)
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t value)
{ R(15)-=4;WRITE(R(15),value); }
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram)
{ uint32_t value=READ(R(15));R(15)+=4;return value; }
static void condition(vf3_matrix_state *s,int value)
{ R(17)=(R(17)&~1u)|(value!=0); }
static int packet(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t port,uint32_t pc)
{ R(4)=port;R(16)=pc;return vf3_matrix_family(R(13),s,ram); }

int vf3_controller_merge_c(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t alias)
{
    push(s,ram,R(14));push(s,ram,R(13));push(s,ram,R(12));push(s,ram,R(16));
    R(3)=0x0c29b864;R(15)-=4;WRITE(R(15),R(3));
    R(12)=0x0c29bcc4;R(13)=0x0c0a1282;
    if(!packet(s,ram,0,alias+0x09af82))return 0;
    if(s->pc!=alias+0x09af82)return vf3_matrix_family(s->pc,s,ram);
    R(4)=R(0);R(14)=READ(R(4)+8);R(3)=READ(R(12)+8);
    R(4)=0x30000000;R(3)&=R(4);condition(s,R(3)==R(4));
    if(R(17)&1u){
        if(!packet(s,ram,1,alias+0x09af94))return 0;
        if(s->pc!=alias+0x09af94)return vf3_matrix_family(s->pc,s,ram);
        R(4)=R(0);R(3)=READ(R(4)+8);R(14)|=R(3);
    }else{
        R(2)=READ(R(12)+8);R(3)=0x10000000;condition(s,(R(2)&R(3))==0);
        if(!(R(17)&1u)){
            if(!packet(s,ram,1,alias+0x09afa8))return 0;
            if(s->pc!=alias+0x09afa8)return vf3_matrix_family(s->pc,s,ram);
            R(4)=R(0);R(14)=READ(R(4)+8);
        }
    }
    R(3)=READ(R(15));R(15)+=4;R(16)=pop(s,ram);R(0)=0x1ec;
    WRITE(R(3)+R(0),R(14));R(0)=R(14);
    R(12)=pop(s,ram);R(13)=pop(s,ram);R(14)=pop(s,ram);
    s->pc=R(16);return ram->oob==0;
}
