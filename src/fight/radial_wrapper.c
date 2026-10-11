/* Original scene-mask guard around radial correction for two actors. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
#define READ(a) vf3_matrix_read(ram,(a),4)
#define WRITE(a,v) vf3_matrix_write(ram,(a),(v),4)
int vf3_radial_wrapper_c(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t alias)
{
    /* Original caller windows execute the relative BSRs through 0x0c. */
    alias=0x0c000000u;
    R(15)-=4;WRITE(R(15),R(16));R(15)-=4;WRITE(R(15),R(5));
    R(1)=READ(alias+0x0cb6c0);R(3)=READ(alias+0x0cb6bc);R(2)=READ(R(1));
    R(17)=(R(17)&~1u)|((R(3)&R(2))==0);
    if(R(17)&1){
        R(16)=alias+0x0cb66e;
        if(!vf3_matrix_family(alias+0x0cb67a,s,ram)||s->pc!=R(16))return 0;
        R(16)=alias+0x0cb672;R(4)=READ(R(15));
        if(!vf3_matrix_family(alias+0x0cb67a,s,ram)||s->pc!=R(16))return 0;
    }
    R(15)+=4;R(16)=READ(R(15));R(15)+=4;s->pc=R(16);
    return ram->oob==0;
}
