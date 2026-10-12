/* The original result-record callback starts sixteen bytes before the frozen
 * 0698fc body. Preserve its register-save prefix before entering the existing
 * verified record implementation. This prefix grants no new body coverage. */
#include "fight/matrix_family.h"
static void push(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t value)
{s->v[15]-=4;vf3_matrix_write(ram,s->v[15],value,4);}
int vf3_result_record_entry_c(vf3_matrix_state*s,const vf3_ram_map*ram)
{
    push(s,ram,s->v[14]);s->v[0]=120;
    for(unsigned n=13;n>=8;n--)push(s,ram,s->v[n]);
    return vf3_matrix_family(0x0c0698fc,s,ram);
}
