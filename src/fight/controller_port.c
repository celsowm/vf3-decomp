/* Original 0x8c09b006: selected-port button word and disconnected sentinel. */
#include "fight/matrix_family.h"

int vf3_controller_port_c(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t alias)
{
    uint32_t status;
    s->v[15]-=4;
    vf3_matrix_write(ram,s->v[15],s->v[16],4);
    s->v[3]=0x0c0a1282;
    s->v[16]=alias+0x09b00e;
    if(!vf3_matrix_family(s->v[3],s,ram))return 0;
    if(s->pc!=alias+0x09b00e)return vf3_matrix_family(s->pc,s,ram);
    s->v[4]=s->v[0];
    status=vf3_matrix_read(ram,s->v[4],4);
    s->v[17]=(s->v[17]&~1u)|(status==0xfffffffeu);
    s->v[0]=status==0xfffffffeu ? 0x80000000u
        : vf3_matrix_read(ram,s->v[4]+8,4);
    s->v[16]=vf3_matrix_read(ram,s->v[15],4);
    s->v[15]+=4;
    s->pc=s->v[16];
    return ram->oob==0;
}
